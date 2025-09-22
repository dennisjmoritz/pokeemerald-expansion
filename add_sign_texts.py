#!/usr/bin/env python3
import json

import argparse

    Parses the scripts.inc.orig file to find sign scripts and their text.
    """
    Parses the scripts.inc.orig file to find sign scripts and their text.
    Returns a dict: {script_name: sign_text}
    """
    Returns a dict: {script_name: sign_text}
    """
    sign_scripts = {}
    if not os.path.exists(inc_path):
        return sign_scripts
    with open(inc_path, 'r') as f:
        content = f.read()
    # Find all sign event scripts (simple heuristic: EventScript_SignN)
    # Example: EventScript_Sign0:: ... msgbox gText_SomeSignText ...
    for match in re.finditer(r'(EventScript_Sign\d+)::.*?msgbox\s+(gText_\w+)', content, re.DOTALL):
        script_name, text_ref = match.groups()
        # Find the actual text for gText_...
        text_match = re.search(rf'{text_ref}\s*=\s*_(\("([^"]+)"\))', content)
        if text_match:
            sign_text = text_match.group(2)
        else:
            # Fallback: just use the text_ref name
            sign_text = text_ref
        sign_scripts[script_name] = sign_text
    return sign_scripts

def main():
    parser = argparse.ArgumentParser(description="Add sign texts to map scripts.pory from scripts.inc.orig")
    parser.add_argument('--dry-run', action='store_true', help='Show changes without writing files')
    args = parser.parse_args()

    maps_dir = '/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/data/maps'

    for map_dir in os.listdir(maps_dir):
        map_path = os.path.join(maps_dir, map_dir)
        if os.path.isdir(map_path):
            map_json_path = os.path.join(map_path, 'map.json')
            inc_path = os.path.join(map_path, 'scripts.inc.orig')
            if os.path.exists(map_json_path):
                with open(map_json_path, 'r') as f:
                    data = json.load(f)
                sign_scripts = extract_sign_texts_from_inc(inc_path)
                sign_count = 0
                for obj in data.get('object_events', []):
                    if obj.get('graphics_id') == 'OBJ_EVENT_GFX_SIGN':
                        script_name = f"{map_dir}_EventScript_Sign{sign_count}"
                        orig_script_name = f"EventScript_Sign{sign_count}"
                        sign_text = sign_scripts.get(orig_script_name, map_dir.upper().replace('_', ' '))
                        obj['script'] = script_name
                        sign_count += 1

                if sign_count > 0:
                    if args.dry_run:
                        print(f"[DRY RUN] Would update {map_json_path} with {sign_count} sign scripts.")
                        print(json.dumps(data, indent=2))
                    else:
                        with open(map_json_path, 'w') as f:
                            json.dump(data, f, indent=2)

                    pory_file_path = os.path.join(map_path, 'scripts.pory')
                    pory_entries = []
                    for i in range(sign_count):
                        script_name = f"{map_dir}_EventScript_Sign{i}"
                        text_name = f"{map_dir}_SignText{i}"
                        orig_script_name = f"EventScript_Sign{i}"
                        sign_text = sign_scripts.get(orig_script_name, map_dir.upper().replace('_', ' '))
                        entry = f'''
script {script_name} {{
    msgbox({text_name})
}}

text {text_name} {{
    "{sign_text}"
}}
'''
                        pory_entries.append(entry)
                    if args.dry_run:
                        print(f"[DRY RUN] Would append to {pory_file_path}:")
                        for entry in pory_entries:
                            print(entry)
                    else:
                        with open(pory_file_path, 'a') as f:
                            for entry in pory_entries:
                                f.write(entry)

if __name__ == "__main__":
    main()
