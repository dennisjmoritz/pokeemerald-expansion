import os
import json
import re
import argparse

def find_sign_events(map_json_path):
    with open(map_json_path, 'r') as f:
        data = json.load(f)
    return [obj for obj in data.get('bg_events', []) if obj.get('type') == 'sign']

def find_msgbox_label(scripts_inc_path, script_name):
    # Find the msgbox line in the event script
    with open(scripts_inc_path, 'r') as f:
        content = f.read()
    match = re.search(rf'{re.escape(script_name)}::(.*?)(?=^[\w_]+::|\Z)', content, re.DOTALL | re.MULTILINE)
    if not match:
        return None, None
    script_body = match.group(1)
    msgbox_match = re.search(r'msgbox\s+([\w_]+)', script_body)
    # Find other function calls (excluding msgbox)
    other_calls = re.findall(r'(call|goto|goto_if_set|goto_if_unset|call_if_set|call_if_unset)\s+([\w_]+)', script_body)
    other_refs = [f'{func} {target}' for func, target in other_calls]
    if msgbox_match:
        return msgbox_match.group(1), other_refs
    return None, other_refs

def add_sign_scripts_to_pory(map_dir, dry_run=False):
    map_json_path = os.path.join(map_dir, 'map.json')
    scripts_inc_path = os.path.join(map_dir, 'scripts.inc.orig')
    pory_path = os.path.join(map_dir, 'scripts.pory')
    if not (os.path.exists(map_json_path) and os.path.exists(scripts_inc_path) and os.path.exists(pory_path)):
        return
    sign_events = find_sign_events(map_json_path)
    entries = []
    for obj in sign_events:
        script_name = obj.get('script')
        label, other_refs = find_msgbox_label(scripts_inc_path, script_name)
        if not label:
            continue
        comment = ''
        if other_refs:
            comment = '\n    // Also calls: ' + ', '.join(other_refs)
        entry = f'script {script_name} {{{comment}\n    lockall\n    msgbox({label})\n    releaseall\n}}\n'
        entries.append(entry)
    if dry_run:
        print(f'--- DRY RUN: Would add the following sign scripts to {pory_path} ---')
        for entry in entries:
            print(entry)
    else:
        with open(pory_path, 'a') as f:
            for entry in entries:
                f.write(entry + '\n')
        print(f'Added {len(entries)} sign scripts to {pory_path}')

def batch_add_sign_scripts(maps_dir, dry_run=False):
    for map_name in os.listdir(maps_dir):
        map_dir = os.path.join(maps_dir, map_name)
        if not os.path.isdir(map_dir):
            continue
        add_sign_scripts_to_pory(map_dir, dry_run)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Batch add sign event scripts to scripts.pory for all maps.")
    parser.add_argument('--dry-run', action='store_true', help='Show output without writing files')
    args = parser.parse_args()
    maps_dir = os.path.join(os.path.dirname(__file__), 'data', 'maps')
    batch_add_sign_scripts(maps_dir, args.dry_run)
