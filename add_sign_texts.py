#!/usr/bin/env python3
import json
import os

maps_dir = '/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/data/maps'

for map_dir in os.listdir(maps_dir):
    map_path = os.path.join(maps_dir, map_dir)
    if os.path.isdir(map_path):
        map_json_path = os.path.join(map_path, 'map.json')
        if os.path.exists(map_json_path):
            with open(map_json_path, 'r') as f:
                data = json.load(f)
            
            sign_count = 0
            for obj in data.get('object_events', []):
                if obj.get('graphics_id') == 'OBJ_EVENT_GFX_SIGN':
                    script_name = f"{map_dir}_EventScript_Sign{sign_count}"
                    obj['script'] = script_name
                    sign_count += 1
            
            if sign_count > 0:
                with open(map_json_path, 'w') as f:
                    json.dump(data, f, indent=2)
                
                pory_file_path = os.path.join(map_path, 'scripts.pory')
                with open(pory_file_path, 'a') as f:
                    for i in range(sign_count):
                        script_name = f"{map_dir}_EventScript_Sign{i}"
                        text_name = f"{map_dir}_SignText{i}"
                        map_name = map_dir.upper().replace('_', ' ')
                        f.write(f'''

script {script_name} {{
    msgbox({text_name})
}}

text {text_name} {{
    "{map_name}"
}}
''')
