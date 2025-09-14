import json

with open('data/layouts/layouts.json', 'r') as f:
    data = json.load(f)

seen = set()
cleaned = []
for item in data['layouts']:
    if 'id' in item:
        if item['id'] in seen:
            continue
        seen.add(item['id'])
    cleaned.append(item)

data['layouts'] = cleaned

with open('data/layouts/layouts.json', 'w') as f:
    json.dump(data, f, indent=2)
