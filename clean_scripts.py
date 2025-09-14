#!/usr/bin/env python3
import os
import json
import re

def get_map_dirs():
    maps_dir = "data/maps"
    return [d for d in os.listdir(maps_dir) if os.path.isdir(os.path.join(maps_dir, d))]

def main():
    for map_dir in get_map_dirs():
        map_json_path = os.path.join("data/maps", map_dir, "map.json")
        scripts_inc_path = os.path.join("data/maps", map_dir, "scripts.inc")
        
        if not os.path.exists(map_json_path) or not os.path.exists(scripts_inc_path):
            continue
        
        # Read map.json and extract LOCALID
        with open(map_json_path, 'r') as f:
            data = json.load(f)
        
        localids = set()
        for obj in data.get("object_events", []):
            lid = obj.get("local_id")
            if isinstance(lid, str) and lid.startswith("LOCALID_"):
                localids.add(lid)
        
        # Read scripts.inc
        with open(scripts_inc_path, 'r') as f:
            lines = f.readlines()
        
        new_lines = []
        for line in lines:
            # Find all LOCALID_ in line
            matches = re.findall(r'\bLOCALID_\w+\b', line)
            if not matches:
                new_lines.append(line)
                continue
            valid = True
            for m in matches:
                if m not in localids:
                    valid = False
                    break
            if valid:
                new_lines.append(line)
        
        if len(new_lines) != len(lines):
            with open(scripts_inc_path, 'w') as f:
                f.writelines(new_lines)
            print(f"Updated {scripts_inc_path}")

if __name__ == "__main__":
    main()
