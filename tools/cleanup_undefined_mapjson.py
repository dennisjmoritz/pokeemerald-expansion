#!/usr/bin/env python3
"""Run make, detect undefined references, and disable offending map.json links.

The script builds the project with `make -j24`, parses the linker output for
"undefined reference" errors, then walks every `map.json` in the repository. Any
entry of the form `"script": "SYMBOL"` where `SYMBOL` is undefined is rewritten
as `"script_comment": "SYMBOL"`, effectively disabling that reference while
keeping the original value for later review. Use `--dry-run` to inspect the
symbols without modifying files.
"""

from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path
from typing import Sequence

RE_UNDEFINED = re.compile(r"undefined reference to `([^']+)'")
TARGET_GLOB = "map.json"
SCRIPT_FIELD_PATTERN = re.compile(r'"script"(\s*:\s*")(?P<symbol>[^"\\]+)"')


def run_make(make_args: Sequence[str]) -> tuple[int, str]:
    """Run make with any extra arguments and return (exit_code, combined_output)."""
    cmd = ["make", "-j24", *make_args]
    proc = subprocess.run(
        cmd,
        check=False,
        text=True,
        capture_output=True,
    )
    output = proc.stdout + proc.stderr
    return proc.returncode, output


def parse_undefined_symbols(build_output: str) -> set[str]:
    """Extract undefined symbols from the linker output."""
    return set(RE_UNDEFINED.findall(build_output))


def find_target_files(root: Path) -> list[Path]:
    """Locate all map.json files beneath the project root."""
    return [
        path
        for path in root.rglob(TARGET_GLOB)
        if path.is_file() and not path.is_symlink()
    ]


def rewrite_map_json(content: str, symbols: set[str]) -> tuple[str, bool]:
    """Swap `script` keys for `script_comment` when the value is undefined."""
    modified = False

    def _replacer(match: re.Match[str]) -> str:
        nonlocal modified
        symbol = match.group("symbol")
        if symbol in symbols:
            modified = True
            return '"script_comment"' + match.group(1) + symbol + '"'
        return match.group(0)

    updated = SCRIPT_FIELD_PATTERN.sub(_replacer, content)
    return updated, modified


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Report undefined symbols without touching any map.json files.",
    )
    parser.add_argument(
        "--make-arg",
        action="append",
        default=[],
        help="Extra argument to pass to make (repeatable).",
    )
    args = parser.parse_args()

    print("Running make...", flush=True)
    code, output = run_make(args.make_arg)
    if output:
        sys.stdout.write(output)

    symbols = parse_undefined_symbols(output)
    if not symbols:
        print("No undefined references detected.")
        return code

    print("Undefined symbols detected:")
    for symbol in sorted(symbols):
        print(f"  {symbol}")

    if args.dry_run:
        print("Dry run requested; no files were modified.")
        return code

    project_root = Path(__file__).resolve().parents[1]
    targets = find_target_files(project_root)

    touched: list[Path] = []
    for path in targets:
        try:
            original = path.read_text(encoding="utf-8")
        except UnicodeDecodeError:
            original = path.read_text(encoding="utf-8", errors="ignore")
        updated, modified = rewrite_map_json(original, symbols)
        if modified:
            path.write_text(updated, encoding="utf-8")
            touched.append(path)

    if touched:
        print("Updated map.json files:")
        for path in sorted(touched):
            print(f"  {path}")
    else:
        print("No map.json changes were required.")

    return code


if __name__ == "__main__":
    raise SystemExit(main())
