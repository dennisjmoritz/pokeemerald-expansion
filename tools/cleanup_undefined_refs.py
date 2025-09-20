#!/usr/bin/env python3
"""Run make, detect undefined references, and comment out offending lines.

This blunt instrument compiles the project with `make`, looks for linker errors
that mention `undefined reference to 'symbol'`, and then comments out lines in
scripts (map scripts.inc files) that mention those symbols. Review the resulting diffs carefully
before committing them. A `--dry-run` flag is provided if you only want the
report without modifying files.
"""

from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path
from typing import Sequence

RE_UNDEFINED = re.compile(r"undefined reference to `([^']+)'")
TARGET_GLOB = "scripts.inc"
COMMENT_PREFIX = "// FIXME undefined reference: "


def run_make(make_args: Sequence[str]) -> tuple[int, str]:
    """Run make with any extra arguments and return (exit_code, combined_output)."""
    # Default to a 24-core build for faster detection; callers can still pass
    # additional make flags via --make-arg.
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
    """Extract undefined symbols from the linker output, trimming stray spaces."""
    return {
        match.strip()
        for match in RE_UNDEFINED.findall(build_output)
        if match.strip()
    }


def normalize_symbols(symbols: set[str]) -> set[str]:
    """Remove common prefixes from symbol names for easier matching."""
    return {
        sym[len("SPECIAL_"):] if sym.startswith("SPECIAL_") else sym
        for sym in symbols
    }


def find_target_files(root: Path) -> list[Path]:
    """Gather map scripts that may reference undefined symbols."""
    return [
        path
        for path in root.rglob(TARGET_GLOB)
        if path.is_file() and not path.is_symlink()
    ]


def comment_out_symbol_occurrences(content: str, symbols: set[str]) -> tuple[str, bool]:
    """Comment out lines containing any of the undefined symbols."""
    lines = content.splitlines(keepends=True)
    modified = False

    for idx, line in enumerate(lines):
        stripped = line.lstrip()
        if not stripped or stripped.startswith("//") or stripped.startswith("/*"):
            continue
        if any(symbol in line for symbol in symbols):
            lines[idx] = COMMENT_PREFIX + line
            modified = True

    return ("".join(lines), modified)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Report the offending symbols without modifying any files.",
    )
    parser.add_argument(
        "--make-arg",
        action="append",
        default=[],
        help="Extra argument to pass to make (can be repeated).",
    )
    args = parser.parse_args()

    print("Running make...", flush=True)
    code, output = run_make(args.make_arg)
    if output:
        sys.stdout.write(output)

    symbols = normalize_symbols(parse_undefined_symbols(output))
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
    script_path = Path(__file__).resolve()

    touched: list[Path] = []
    for path in targets:
        if path.resolve() == script_path:
            continue
        try:
            original = path.read_text(encoding="utf-8")
        except UnicodeDecodeError:
            original = path.read_text(encoding="utf-8", errors="ignore")
        if not any(symbol in original for symbol in symbols):
            continue
        updated, modified = comment_out_symbol_occurrences(original, symbols)
        if modified:
            path.write_text(updated, encoding="utf-8")
            touched.append(path)

    if touched:
        print("Commented out undefined references in the following scripts:")
        for path in sorted(touched):
            print(f"  {path}")
    else:
        print("No scripts.inc modifications were required.")

    return code


if __name__ == "__main__":
    raise SystemExit(main())
