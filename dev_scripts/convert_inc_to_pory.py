import os
import re
import sys

# Usage: python convert_inc_to_pory.py <input.inc.orig> <output.pory>
# If run without arguments, will print usage and exit.

SCRIPT_LABEL_RE = re.compile(r"^(\w+)::")
TEXT_LABEL_RE = re.compile(r"^(\w+):")
STRING_LINE_RE = re.compile(r"^\s*\.string\s+\"(.*)\"$")

# List of event commands to help identify script blocks
EVENT_COMMANDS = [
    'lock', 'lockall', 'release', 'releaseall', 'faceplayer', 'msgbox', 'trainerbattle_single',
    'trainerbattle_no_intro', 'trainerbattle_rematch', 'call', 'goto', 'setflag', 'clearflag',
    'setvar', 'addvar', 'special', 'specialvar', 'giveitem', 'register_matchcall', 'playbgm',
    'closemessage', 'delay', 'applymovement', 'waitmovement', 'end', 'return'
]

# Helper to detect if a line is an event command
def is_event_command(line):
    return any(line.strip().startswith(cmd) for cmd in EVENT_COMMANDS)

# Convert a text block to poryscript
def convert_text_block(label, lines):
    text_content = []
    for line in lines:
        m = STRING_LINE_RE.match(line)
        if m:
            # Remove \n and $ from the string
            cleaned = m.group(1).replace('\\n', ' ').replace('$', '').strip()
            text_content.append(cleaned)
    joined = ' '.join(text_content)
    return f'text {label} {{\n    format("{joined}")\n}}\n\n'

# Convert a script block to poryscript
def convert_script_block(label, lines):
    body = ''.join(lines)
    return f'script {label} {{\n{body}}}\n\n'

# Main conversion logic
def convert_inc_to_pory(inc_path, pory_path):
    with open(inc_path, 'r', encoding='utf-8', errors='ignore') as f:
        lines = f.readlines()

    output = []
    mapscripts_block = None
    other_script_blocks = []
    text_blocks = []
    i = 0
    while i < len(lines):
        line = lines[i]
        script_match = SCRIPT_LABEL_RE.match(line.strip())
        text_match = TEXT_LABEL_RE.match(line.strip())
        # Detect main mapscripts block: label ends with _MapScripts and contains map_script/.byte 0
        if script_match and script_match.group(1).endswith('_MapScripts'):
            label = script_match.group(1)
            block_lines = []
            i += 1
            while i < len(lines) and not SCRIPT_LABEL_RE.match(lines[i].strip()) and not TEXT_LABEL_RE.match(lines[i].strip()):
                block_lines.append(lines[i])
                i += 1
            # Only wrap this block in mapscripts
            mapscripts_block = (label, block_lines)
        elif text_match and not SCRIPT_LABEL_RE.match(line.strip()):
            label = text_match.group(1)
            block_lines = []
            i += 1
            while i < len(lines) and not SCRIPT_LABEL_RE.match(lines[i].strip()) and not TEXT_LABEL_RE.match(lines[i].strip()):
                block_lines.append(lines[i])
                i += 1
            if any(STRING_LINE_RE.match(l) for l in block_lines):
                text_blocks.append(convert_text_block(label, block_lines))
        elif script_match:
            label = script_match.group(1)
            block_lines = []
            i += 1
            while i < len(lines) and not SCRIPT_LABEL_RE.match(lines[i].strip()) and not TEXT_LABEL_RE.match(lines[i].strip()):
                block_lines.append(lines[i])
                i += 1
            other_script_blocks.append(convert_script_block(label, block_lines))
        else:
            i += 1
    # Output mapscripts block first
    if mapscripts_block:
        label, block_lines = mapscripts_block
        # Extract referenced script labels from map_script lines
        referenced = []
        for line in block_lines:
            line = line.strip()
            if line.startswith('map_script'):
                # map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
                parts = line.split(',')
                if len(parts) == 2:
                    ref = parts[1].strip()
                    referenced.append(ref)
            elif line and not line.startswith('.byte'):
                # Also allow direct script references
                referenced.append(line)
        output.append(f"mapscripts {label} {{\n")
        for ref in referenced:
            output.append(f"    {ref}\n")
        output.append("}\n\n")
    # Output all other script blocks
    output.extend(other_script_blocks)
    # Output all text blocks after
    output.extend(text_blocks)
    with open(pory_path, 'w', encoding='utf-8') as f:
        f.writelines(output)
    print(f"Converted {inc_path} -> {pory_path} ({(1 if mapscripts_block else 0) + len(other_script_blocks) + len(text_blocks)} blocks)")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python convert_inc_to_pory.py <input.inc.orig> <output.pory>")
        sys.exit(1)
    convert_inc_to_pory(sys.argv[1], sys.argv[2])
