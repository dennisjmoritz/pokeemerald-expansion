#!/usr/bin/env python3
import os
import glob
import json

# Find all map directories
map_dirs = glob.glob('data/maps/*/')
map_dirs.sort()

# Output the includes
with open('data/maps_includes.inc', 'w') as f:
    for map_dir in map_dirs:
        map_json_path = os.path.join(map_dir, 'map.json')
        scripts_inc_path = os.path.join(map_dir, 'scripts.inc')
        
        if os.path.exists(map_json_path) and os.path.exists(scripts_inc_path):
            with open(map_json_path, 'r') as json_file:
                map_data = json.load(json_file)
                if 'shared_scripts_map' not in map_data:
                    f.write(f'\t.include "{scripts_inc_path}"\n')
