#!/usr/bin/env python3
import json
import glob
import re

# Read constants/songs.h to get available MUS_ defines
available_music = set()
with open('include/constants/songs.h', 'r') as f:
    for line in f:
        match = re.match(r'#define\s+(MUS_\w+)', line)
        if match:
            available_music.add(match.group(1))

default_music = "MUS_ROUTE101"

# Process each map.json
for map_file in glob.glob('data/maps/*/map.json'):
    with open(map_file, 'r') as f:
        data = json.load(f)
    
    music = data.get('music')
    if music and music not in available_music:
        old_music = music
        data['music'] = default_music
        data['comment'] = f"Changed music from {old_music} to {default_music} because unavailable"
        
        with open(map_file, 'w') as f:
            json.dump(data, f, indent=2)
        print(f"Updated {map_file}: {old_music} -> {default_music}")
