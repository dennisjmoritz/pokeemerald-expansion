#!/usr/bin/env python3
"""Restore disabled map.json scripts to use Common_EventScript_ShowBagIsFull.

Scans every map.json, looks for entries where a `"script_comment"` is present but
no adjacent `"script"` field remains (as produced by cleanup_undefined_mapjson),
and inserts `"script": "Common_EventScript_ShowBagIsFull"` alongside the existing
comment. Use `--dry-run` to see which files would change.
"""

from __future__ import annotations

import argparse
import re
from pathlib import Path

TARGET_GLOB = "map.json"
SCRIPT_COMMENT_RE = re.compile(
    r"(?P<indent>\s*)\"script_comment\":\s*\"(?P<symbol>[^\"\\]+)\"(?P<trailing>,?)"
)
DEFAULT_SCRIPT = "Common_EventScript_ShowBagIsFull"


def find_map_files(root: Path) -> list[Path]:
    return [
        path
        for path in root.rglob(TARGET_GLOB)
        if path.is_file() and not path.is_symlink()
    ]


def needs_script(full_text: str, match_start: int) -> bool:
    """Return False if the previous line already contains a script field."""
    prev_newline = full_text.rfind("\n", 0, match_start)
    if prev_newline == -1:
        prev_line = ""
    else:
        prev_prev_newline = full_text.rfind("\n", 0, prev_newline)
        prev_line = full_text[prev_prev_newline + 1 : prev_newline]
    return '"script"' not in prev_line


def restore_scripts(content: str) -> tuple[str, bool]:
    modified = False

    def replacer(match: re.Match[str]) -> str:
        nonlocal modified
        if not needs_script(match.string, match.start()):
            return match.group(0)
        indent = match.group("indent")
        symbol = match.group("symbol")
        trailing = match.group("trailing")
        modified = True
        return (
            f'{indent}"script": "{DEFAULT_SCRIPT}",\n'
            f'{indent}"script_comment": "{symbol}"{trailing}'
        )

    updated = SCRIPT_COMMENT_RE.sub(replacer, content)
    return updated, modified


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Report files needing restoration without modifying them.",
    )
    args = parser.parse_args()

    project_root = Path(__file__).resolve().parents[1]
    targets = find_map_files(project_root)

    touched: list[Path] = []
    for path in targets:
        original = path.read_text(encoding="utf-8", errors="ignore")
        updated, modified = restore_scripts(original)
        if modified:
            if args.dry_run:
                touched.append(path)
            else:
                path.write_text(updated, encoding="utf-8")
                touched.append(path)

    if touched:
        if args.dry_run:
            print("Files needing script restoration:")
        else:
            print("Restored script fields in the following map.json files:")
        for path in sorted(touched):
            print(f"  {path}")
    else:
        print("No map.json files required script restoration.")


if __name__ == "__main__":
    main()
