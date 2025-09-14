#!/usr/bin/env python3
import json

with open('src/data/region_map/region_map_sections.json', 'r') as f:
    data = json.load(f)

seen = set()
cleaned = []
for item in data['map_sections']:
    if item['id'] not in seen:
        seen.add(item['id'])
        cleaned.append(item)

data['map_sections'] = cleaned

with open('src/data/region_map/region_map_sections.json', 'w') as f:
    json.dump(data, f, indent=2)
