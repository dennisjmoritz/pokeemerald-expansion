
import re
import argparse
import os
import textwrap

def convert_inc_to_pory(inc_path, pory_path, dry_run=False):
    with open(inc_path, 'r') as f:
        content = f.read()

    # Find all text label blocks
    blocks = re.findall(r'^([\w_]+)::(.*?)(?=^[\w_]+::|\Z)', content, re.DOTALL | re.MULTILINE)
    pory_entries = []
    for label, block in blocks:
        strings = re.findall(r'\.string\s+"([^"]*)"', block)
        if strings:
            # Remove trailing $ from last string
            if strings[-1].endswith('$'):
                strings[-1] = strings[-1][:-1]
            # Remove all literal \n, \N, \r, and any leftover whitespace artifacts
            text_content = ' '.join(re.sub(r'(\\[nNrR]|\s)+', ' ', s).strip() for s in strings)
            # Escape double quotes for Poryscript compatibility
            text_content = text_content.replace('"', '\"')
            entry = f'text {label} {{\n    format("{text_content}")\n}}\n'
            pory_entries.append(entry)

    if dry_run:
        print(f"--- DRY RUN: Would write the following text blocks to {pory_path} ---")
        for entry in pory_entries:
            print(entry)
    else:
        with open(pory_path, 'w') as f:
            for entry in pory_entries:
                f.write(entry + '\n')
        print(f"Wrote {len(pory_entries)} text blocks to {pory_path}")

def batch_convert_all_maps(maps_dir, dry_run=False):
    for map_name in os.listdir(maps_dir):
        map_path = os.path.join(maps_dir, map_name)
        if not os.path.isdir(map_path):
            continue
        inc_path = os.path.join(map_path, 'scripts.inc.orig')
        pory_path = os.path.join(map_path, 'scripts.pory')
        if os.path.exists(inc_path):
            convert_inc_to_pory(inc_path, pory_path, dry_run)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Convert all scripts.inc.orig text blocks in data/maps/* to poryscript text blocks.")
    parser.add_argument('--dry-run', action='store_true', help='Show output without writing files')
    parser.add_argument('--single', nargs=2, metavar=('inc_path', 'pory_path'), help='Convert a single file (inc_path, pory_path)')
    args = parser.parse_args()
    maps_dir = os.path.join(os.path.dirname(__file__), 'data', 'maps')
    if args.single:
        inc_path, pory_path = args.single
        convert_inc_to_pory(inc_path, pory_path, args.dry_run)
    else:
        batch_convert_all_maps(maps_dir, args.dry_run)
