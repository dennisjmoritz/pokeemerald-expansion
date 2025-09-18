#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
convert_scripts_inc_to_poryscript.py

Walks data/maps/*/scripts.inc and emits data/maps/*/scripts.pory with as much
content lifted to native Poryscript as possible:

- mapscripts <Map>_MapScripts { ... } from the header callbacks
- MAP_SCRIPT_*_TABLE blocks parsed from map_script_2 rows
- movement <Label> { ... } from Movement_*: sequences (ending in step_end)
- text <Label> { "..." } from Text_*: .string blocks (ending with $)
- script <Label> { ... } from event script labels (::<global> or :<local>)
  * converts "cmd arg1, arg2" -> "cmd(arg1, arg2)"
  * preserves bare commands (lock, faceplayer, end, return, etc.)
  * tries to inline short applymovement(...) with moves(...)

Any content that is not confidently lifted is appended once in a trailing
`raw` block (without the already-lifted sections) to keep builds working.

Usage:
  python3 convert_scripts_inc_to_poryscript.py
  # optional: python3 convert_scripts_inc_to_poryscript.py --root data/maps
"""

import argparse
import re
from pathlib import Path
from datetime import datetime
from typing import List, Tuple, Dict, Set

# ----------- Regexes (tuned for pokeemerald scripts.inc conventions) ---------

RE_LABEL_GLOBAL = re.compile(r'^\s*([A-Za-z0-9_]+)::\s*$')           # MyScriptLabel::
RE_LABEL_LOCAL  = re.compile(r'^\s*([A-Za-z0-9_]+):\s*$')             # MyLabel:
RE_MAPSCRIPTS   = re.compile(r'^\s*([A-Za-z0-9_]+)_MapScripts::\s*$') # MapName_MapScripts::
RE_BYTE_0       = re.compile(r'^\s*\.byte\s+0\s*$')                   # header terminator
RE_2BYTE_0      = re.compile(r'^\s*\.2byte\s+0\s*$')                  # table terminator
RE_CALLBACK     = re.compile(r'^\s*map_script\s+(MAP_SCRIPT_[A-Z0-9_]+)\s*,\s*([A-Za-z0-9_]+)\s*$')
RE_TABLE_ROW    = re.compile(r'^\s*map_script_2\s+([A-Za-z0-9_]+)\s*,\s*([^,]+)\s*,\s*([A-Za-z0-9_]+)\s*$')
RE_STRING_LINE  = re.compile(r'^\s*\.string\s+"(.*)"\s*$')            # capture inside quotes
RE_CMD_ARGS     = re.compile(r'^\s*([A-Za-z_][A-Za-z0-9_]*)\s+(.+?)\s*$')  # cmd a, b, c
RE_MOVEMENT_CMD = re.compile(r'^\s*([A-Za-z0-9_]+)\s*(?:\*\s*(\d+))?\s*$') # walk_up * 3
RE_APPLYMOV     = re.compile(r'\bapplymovement\s*\(\s*([^,]+)\s*,\s*([A-Za-z0-9_]+)\s*\)')

# Commands that are "bare" (no parentheses) in Poryscript.
BARE_COMMANDS: Set[str] = {
    "lock", "lockall", "release", "releaseall", "end", "return",
    "waitmessage", "waitmovement", "closemessage", "faceplayer",
    "hidebox", "showbox"
}

# Some script commands require parentheses if they have args; we’ll also
# parenthesize unknown commands that clearly have arguments.
def to_pory_command(line: str) -> str:
    s = line.strip()
    if not s or s.startswith(('.', 'align', 'var', 'word', 'byte', '2byte')):
        return line  # leave raw for safety

    # If it's already a comment or a label, just return it.
    if s.startswith('#') or s.startswith('//') or s.startswith('@') or s.endswith(':') or s.endswith('::'):
        if s.startswith('@'):
            return '#' + s[1:]
        return line

    # Bare commands (no args)
    toks = s.split(None, 1)
    if len(toks) == 1:
        cmd = toks[0]
        if cmd in BARE_COMMANDS:
            return cmd
        # Unknown single token: keep raw
        return line

    # Commands with arguments: turn "cmd a, b" into "cmd(a, b)"
    m = RE_CMD_ARGS.match(s)
    if not m:
        return line
    cmd, args = m.group(1), m.group(2)

    if cmd == 'case':
        return f"case {args}"

    # Avoid re-wrapping lines already in porystyle "cmd(args)"
    if args.startswith('(') and args.endswith(')'):
        return f"{cmd}{args}"

    return f"{cmd}({args})"

# ---------- Simple containers -------------------------------------------------

class TableEntry:
    __slots__ = ("var", "value", "script")
    def __init__(self, var: str, value: str, script: str):
        self.var = var.strip()
        self.value = value.strip()
        self.script = script.strip()

# ---------- Parsing helpers ---------------------------------------------------

def find_mapscripts_header(lines: List[str]) -> Tuple[int, int, str]:
    """
    Return (start_idx, end_idx, header_label) for <Map>_MapScripts:: block where
    end_idx points at the '.byte 0' terminator. If not found, return (-1, -1, "").
    """
    start = -1
    header_label = ""
    for i, ln in enumerate(lines):
        m = RE_MAPSCRIPTS.match(ln)
        if m:
            start = i
            header_label = f"{m.group(1)}_MapScripts"
            break
    if start == -1:
        return -1, -1, ""

    # Find the .byte 0 that terminates the callback list
    end = -1
    for j in range(start + 1, min(start + 2000, len(lines))):
        if RE_BYTE_0.match(lines[j]):
            end = j
            break
    if end == -1:
        return -1, -1, ""
    return start, end, header_label

def parse_callbacks(lines: List[str], s: int, e: int) -> Tuple[List[Tuple[str, str]], List[str]]:
    callbacks = []
    table_labels = []
    for i in range(s + 1, e):
        m = RE_CALLBACK.match(lines[i])
        if not m:
            continue
        kind, label = m.group(1), m.group(2)
        callbacks.append((kind, label))
        if kind.endswith("_TABLE"):
            table_labels.append(label)
    return callbacks, table_labels

def parse_table(lines: List[str], label: str) -> List[TableEntry]:
    # Find "label:" local (tables tend to be single-colon)
    lbl_re = re.compile(rf'^\s*{re.escape(label)}:\s*$')
    start = next((i for i, ln in enumerate(lines) if lbl_re.match(ln)), -1)
    if start == -1:
        return []
    out = []
    for i in range(start + 1, len(lines)):
        ln = lines[i]
        if RE_2BYTE_0.match(ln):
            break
        m = RE_TABLE_ROW.match(ln)
        if m:
            out.append(TableEntry(m.group(1), m.group(2), m.group(3)))
    return out

def collect_blocks(lines: List[str]) -> Dict[str, Tuple[int, int, bool]]:
    """
    Collect label-defined blocks and return a map:
      label -> (start_index (label line), end_index (exclusive), is_global)
    The block spans from label line to just before the next label (global or local) or EOF.
    """
    labels = []
    for i, ln in enumerate(lines):
        mg = RE_LABEL_GLOBAL.match(ln)
        ml = RE_LABEL_LOCAL.match(ln)
        if mg:
            labels.append((i, mg.group(1), True))
        elif ml:
            labels.append((i, ml.group(1), False))

    labels.sort(key=lambda x: x[0])
    blocks: Dict[str, Tuple[int, int, bool]] = {}
    for idx, (i, name, is_global) in enumerate(labels):
        j = labels[idx + 1][0] if idx + 1 < len(labels) else len(lines)
        blocks[name] = (i, j, is_global)
    return blocks

def is_movement_block(block_lines: List[str]) -> bool:
    # Heuristic: ends with step_end and contains only movement mnemonics
    if not block_lines:
        return False
    if not any('step_end' in ln for ln in block_lines[-3:]):
        return False
    # Don’t be overly strict—just avoid obvious non-movement markers
    bad = ('.string', 'msgbox', 'trainerbattle', 'if ', 'while', 'call ')
    return not any(b in ' '.join(block_lines[:5]).lower() for b in bad)

def parse_text_block(block_lines: List[str]) -> Tuple[bool, List[str]]:
    """
    Return (is_text, parts). parts is list of .string payloads (without quotes).
    We keep capturing until a line that ends with a terminating '$' is found.
    """
    parts = []
    saw_string = False
    for ln in block_lines:
        m = RE_STRING_LINE.match(ln)
        if m:
            saw_string = True
            parts.append(m.group(1))
            if m.group(1).rstrip().endswith("$"):
                return True, parts
        elif saw_string:
            # Sometimes text has blank/comment lines—stop on first non-string after strings start
            break
    return (saw_string and parts and parts[-1].rstrip().endswith("$")), parts

def convert_movement_lines(block_lines: List[str]) -> List[str]:
    """Return a poryscript movement body from asm movement lines, minus trailing step_end."""
    body = []
    for ln in block_lines:
        s = ln.strip()
        # Strip comments starting with @
        if '@' in s:
            s = s.split('@')[0].strip()
        if not s or s.startswith('.') or s.endswith(':') or s.startswith('#'):
            continue
        if s.startswith('step_end'):
            break
        m = RE_MOVEMENT_CMD.match(s)
        if not m:
            # Keep raw if unknown
            body.append(s)
            continue
        cmd, times = m.group(1), m.group(2)
        if times:
            body.append(f"{cmd} * {times}")
        else:
            body.append(cmd)
    return body

def convert_script_lines(block_lines: List[str], known_movements: Dict[str, List[str]]) -> List[str]:
    """
    Convert event-script-ish block lines into poryscript inside 'script { ... }'.
    - Converts "cmd a, b" to "cmd(a, b)"
    - Leaves bare commands as-is
    - Inlines short movements in applymovement(..., Label) when Label is known
    - Handles switch statements
    """
    out = []
    in_switch = False
    switch_line = ""
    switch_emitted = False
    for ln in block_lines:
        s = ln.strip()
        # Strip @ comments
        if '@' in s:
            s = s.split('@')[0].strip()
        if not s or s.startswith('.') or s.startswith('#') or s.endswith(':') or s.endswith('::'):
            continue

        # Basic conversion to cmd(args) style
        pline = to_pory_command(s)

        if pline.startswith('switch'):
            in_switch = True
            # Extract the variable from switch(var)
            args = pline.split('(', 1)[1].rstrip(')')
            switch_var = args
            switch_emitted = False
        elif pline.startswith('case ') and in_switch:
            if not switch_emitted:
                switch_emitted = True
            parts = pline[5:].split(',')
            value = parts[0].strip()
            label = parts[1].strip()
            out.append(f"call_if_eq({switch_var}, {value}, {label})")
        else:
            if in_switch and switch_emitted:
                in_switch = False
                switch_emitted = False
            # Try to inline movements referenced by applymovement
            def _inline_apply(m):
                obj, movelabel = m.group(1).strip(), m.group(2).strip()
                moves = known_movements.get(movelabel)
                if not moves:
                    return f"applymovement({obj}, {movelabel})"
                # Inline if short for readability
                if len(moves) <= 5 and all('*' not in mv for mv in moves):
                    inlined = " ".join(moves)
                    return f"applymovement({obj}, moves({inlined}))"
                return f"applymovement({obj}, {movelabel})"

            pline = RE_APPLYMOV.sub(_inline_apply, pline)

            out.append(pline)
    if in_switch and switch_emitted:
        out.append('}')
    return out

# ---------- Emission helpers --------------------------------------------------

def emit_mapscripts(label: str,
                    callbacks: List[Tuple[str, str]],
                    tables: Dict[str, List[TableEntry]]) -> str:
    lines = [f"mapscripts {label} {{"]

    for kind, tgt in callbacks:
        if kind.endswith("_TABLE"):
            entries = tables.get(tgt, [])
            lines.append(f"    {kind} [")
            for e in entries:
                lines.append(f"        {e.var}, {e.value}: {e.script}")
            lines.append("    ]")
        else:
            # Simple reference (we could inline later if desired)
            lines.append(f"    {kind}: {tgt}")
    lines.append("}")
    return "\n".join(lines)

def emit_movement(name: str, body: List[str], is_global: bool) -> str:
    scope = "global" if is_global else "local"
    lines = [f"movement({scope}) {name} {{"] + [f"    {ln}" for ln in body] + ["}"]
    return "\n".join(lines)

def emit_text(name: str, parts: List[str], is_global: bool) -> str:
    scope = "global" if is_global else "local"
    # Join contiguous .string pieces into Poryscript text lines.
    # Strip a trailing '$' because Poryscript adds it automatically.
    def strip_dollar(s: str) -> str:
        return s[:-1] if s.endswith("$") else s
    pieces = [strip_dollar(p) for p in parts]
    body = []
    for p in pieces:
        # Preserve escape sequences already in source
        body.append(f'    "{p}"')
    return "\n".join([f"text({scope}) {name} {{"] + body + ["}"])

def emit_script(name: str, body_lines: List[str], is_global: bool) -> str:
    scope = "global" if is_global else "local"
    body = [f"    {ln}" for ln in body_lines] or ["    end"]
    return "\n".join([f"script({scope}) {name} {{"] + body + ["}"])

# ---------- File-level conversion --------------------------------------------

def convert_one_scripts_inc(path_inc: Path) -> Path:
    map_dir = path_inc.parent
    out_pory = map_dir / "scripts.pory"
    lines = path_inc.read_text(encoding="utf-8", errors="ignore").splitlines()

    # Build mapscripts
    ms_start, ms_end, ms_label = find_mapscripts_header(lines)
    callbacks, table_labels = ([], [])
    if ms_label:
        callbacks, table_labels = parse_callbacks(lines, ms_start, ms_end)
    tables: Dict[str, List[TableEntry]] = {t: parse_table(lines, t) for t in table_labels}

    # Collect labeled blocks
    blocks = collect_blocks(lines)

    # Identify blocks we will lift to avoid duplicating them in raw
    consumed_ranges: List[Tuple[int, int]] = []
    emitted_sections: List[str] = []

    # Emit mapscripts first (either real or empty)
    if ms_label:
        emitted_sections.append(emit_mapscripts(ms_label, callbacks, tables))
        consumed_ranges.append((ms_start, ms_end + 1))  # include '.byte 0'
    else:
        # derive a sensible label from folder name
        label_guess = f"{map_dir.name}_MapScripts"
        emitted_sections.append(f"mapscripts {label_guess} {{}}")

    # Movement + Text + Script passes
    known_movements: Dict[str, List[str]] = {}
    text_blocks: Dict[str, List[str]] = {}

    # First pass: lift movement and text
    for name, (s, e, is_global) in blocks.items():
        if s >= 0 and e > s:
            block_lines = lines[s:e]
            # Movement?
            if is_movement_block(block_lines[1:]):  # skip label line itself
                body = convert_movement_lines(block_lines[1:])
                emitted_sections.append(emit_movement(name, body, is_global))
                known_movements[name] = body
                consumed_ranges.append((s, e))
                continue
            # Text?
            is_text, parts = parse_text_block(block_lines[1:])
            if is_text:
                emitted_sections.append(emit_text(name, parts, is_global))
                text_blocks[name] = parts
                consumed_ranges.append((s, e))
                continue

    # Second pass: lift likely event scripts (heuristic: block contains script commands)
    for name, (s, e, is_global) in blocks.items():
        # Skip if we already consumed this range (movement/text/mapscripts/table labels)
        if any(s >= a and e <= b for (a, b) in consumed_ranges):
            continue

        # Skip the mapscripts label itself to avoid duplicate script blocks
        if name == ms_label:
            continue

        block_lines = lines[s:e]
        # Don’t try to lift simple data labels (tables, mart, etc.)
        if name in tables or name in text_blocks or name in known_movements:
            continue
        # Avoid tiny or obviously data-only blocks
        payload = [ln for ln in block_lines[1:] if ln.strip() and not ln.strip().startswith('.')]
        if not payload:
            continue

        # Convert lines
        script_body = convert_script_lines(block_lines, known_movements)
        # Heuristic sanity: ensure we produced at least one recognizable command word
        if any(re.match(r'^[A-Za-z_][A-Za-z0-9_]*\s*(\(|$)', ln.strip()) for ln in script_body):
            emitted_sections.append(emit_script(name, script_body, is_global))
            consumed_ranges.append((s, e))

    # Compose RAW remainder (only the lines not inside consumed ranges)
    # Merge and invert the consumed ranges.
    consumed_ranges.sort()
    merged = []
    for r in consumed_ranges:
        if not merged or r[0] > merged[-1][1]:
            merged.append(list(r))
        else:
            merged[-1][1] = max(merged[-1][1], r[1])

    raw_chunks = []
    cursor = 0
    for a, b in merged:
        if cursor < a:
            raw_chunks.extend(lines[cursor:a])
        cursor = b
    if cursor < len(lines):
        raw_chunks.extend(lines[cursor:])

    # Convert @ comments to # comments in raw
    raw_chunks = [ln if not ln.strip().startswith('@') else '#' + ln.strip()[1:] + '\n' for ln in raw_chunks]

    # Filter out invalid lines in raw (e.g., stray braces or parens that break parsing)
    raw_chunks = [ln for ln in raw_chunks if not (ln.strip() == '}' or ln.strip().startswith('(') or ln.strip().startswith('#'))]

    # Remove empty raw (whitespace only)
    raw_chunks_stripped = [ln for ln in raw_chunks if ln.strip()]
    if raw_chunks_stripped:
        emitted_sections.append("raw `")
        emitted_sections.extend(raw_chunks)
        emitted_sections.append("`")

    header = []

    out_pory.write_text("\n".join(header + emitted_sections) + "\n", encoding="utf-8")
    return out_pory

# ---------- Main --------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default="data/maps", help="Root directory containing map subfolders")
    args = ap.parse_args()

    root = Path(args.root)
    if not root.exists():
        print(f"[WARN] Root not found: {root}")
        return

    inc_paths = sorted(root.glob("*/scripts.inc"))
    if not inc_paths:
        print(f"[INFO] No scripts.inc found under {root}/*")
        return

    print(f"[INFO] Converting {len(inc_paths)} scripts...")
    for p in inc_paths:
        try:
            outp = convert_one_scripts_inc(p)
            print(f"[OK]  {p} -> {outp}")
        except Exception as e:
            print(f"[ERR] {p}: {e}")

if __name__ == "__main__":
    main()
