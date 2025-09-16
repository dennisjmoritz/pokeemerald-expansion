#!/usr/bin/env python3
"""
Clear events and stub scripts for selected maps.

Two selection modes are supported:
1) Baseline compare: target maps not present in a baseline Emerald repo.
   - python3 tools/clear_maps.py --baseline /path/to/emerald/repo [--dry-run]

2) Pattern match: target maps whose folder name matches patterns.
   - python3 tools/clear_maps.py --patterns PalletTown NewBarkTown Route1 Route29 [--dry-run]

By default, scans under data/maps in the current repo.
"""

import argparse
import fnmatch
import json
import os
import sys
from typing import List, Set


def matches_any(name: str, patterns: List[str]) -> bool:
    for pat in patterns:
        if pat in name or fnmatch.fnmatch(name, pat):
            return True
    return False


def load_json(path: str):
    with open(path, 'r', encoding='utf-8') as f:
        return json.load(f)


def dump_json(path: str, data):
    # Write with 2-space indent and trailing newline
    text = json.dumps(data, indent=2, ensure_ascii=False)
    if not text.endswith("\n"):
        text += "\n"
    with open(path, 'w', encoding='utf-8') as f:
        f.write(text)


def make_stub_scripts(name: str) -> str:
    # Minimal skeleton for a map with no scripts
    # Example: PalletTown_ProfessorOaksLab_MapScripts::\n\t.byte 0\n
    label = f"{name}_MapScripts::\n\t.byte 0\n"
    return label


def process_map_dir(map_dir: str, dry_run: bool = False) -> bool:
    changed = False
    map_json_path = os.path.join(map_dir, 'map.json')
    scripts_inc_path = os.path.join(map_dir, 'scripts.inc')

    map_name = None
    if os.path.isfile(map_json_path):
        try:
            data = load_json(map_json_path)
            map_name = data.get('name')
            new_data = dict(data)
            for key in ('object_events', 'coord_events', 'bg_events'):
                if key in new_data and new_data.get(key) != []:
                    new_data[key] = []
                    changed = True
            if changed and not dry_run:
                dump_json(map_json_path, new_data)
        except Exception as e:
            print(f"[WARN] Failed to process JSON {map_json_path}: {e}")

    if os.path.isfile(scripts_inc_path):
        # If we don't know the name from map.json, fall back to folder basename
        if not map_name:
            map_name = os.path.basename(map_dir)
        stub = make_stub_scripts(map_name)
        # Only change if content differs
        need_write = True
        try:
            with open(scripts_inc_path, 'r', encoding='utf-8') as f:
                if f.read() == stub:
                    need_write = False
        except Exception:
            pass

        if need_write:
            changed = True
            if not dry_run:
                with open(scripts_inc_path, 'w', encoding='utf-8') as f:
                    f.write(stub)

    return changed


def main():
    ap = argparse.ArgumentParser(description='Clear events and stub scripts for selected maps')
    ap.add_argument('--root', default='data/maps', help='Root directory of maps (default: data/maps)')
    sel = ap.add_mutually_exclusive_group(required=True)
    sel.add_argument('--baseline', help='Path to baseline Emerald repo (expects data/maps within) or directly to its data/maps')
    sel.add_argument('--patterns', nargs='+', help='Folder name patterns to target (substring or fnmatch)')
    ap.add_argument('--dry-run', action='store_true', help='Show what would change without writing files')
    args = ap.parse_args()

    if not os.path.isdir(args.root):
        print(f"[ERROR] Root not found: {args.root}")
        return 2

    # Determine targets
    targets: List[str] = []
    cur_entries = [d for d in sorted(os.listdir(args.root)) if os.path.isdir(os.path.join(args.root, d))]

    if args.baseline:
        baseline_path = args.baseline
        # If a repo root is passed, prefer its data/maps
        candidate = os.path.join(baseline_path, 'data', 'maps')
        if os.path.isdir(candidate):
            baseline_maps_root = candidate
        elif os.path.isdir(baseline_path):
            baseline_maps_root = baseline_path
        else:
            print(f"[ERROR] Baseline path not found: {args.baseline}")
            return 2

        baseline_dirs: Set[str] = set(d for d in os.listdir(baseline_maps_root) if os.path.isdir(os.path.join(baseline_maps_root, d)))
        for entry in cur_entries:
            if entry not in baseline_dirs:
                targets.append(os.path.join(args.root, entry))
    else:
        # Pattern selection
        for entry in cur_entries:
            full = os.path.join(args.root, entry)
            if matches_any(entry, args.patterns):
                targets.append(full)

    if not targets:
        msg = '[INFO] No map directories matched baseline difference.' if args.baseline else '[INFO] No map directories matched the provided patterns.'
        print(msg)
        return 0

    any_changed = False
    for d in targets:
        changed = process_map_dir(d, dry_run=args.dry_run)
        status = 'CHANGED' if changed else 'unchanged'
        print(f"[{status}] {d}")
        any_changed = any_changed or changed

    if args.dry_run:
        print('[DRY-RUN] No files were modified.')

    return 0 if any_changed or args.dry_run else 0


if __name__ == '__main__':
    sys.exit(main())
