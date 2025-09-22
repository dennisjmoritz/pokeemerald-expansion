import re
import glob

# Get all macro names from event.inc
with open('asm/macros/event.inc', encoding='utf-8', errors='ignore') as f:
    event_macros = set(re.findall(r'\b([A-Z_][A-Z0-9_]+)\b', f.read()))

# For each .pory file, check script blocks
for fname in glob.glob('data/maps/**/*.pory', recursive=True):
    with open(fname, encoding='utf-8', errors='ignore') as f:
        lines = f.readlines()
    in_script = False
    missing = []
    for line in lines:
        if line.strip().startswith('script '):
            in_script = True
            continue
        if in_script:
            if line.strip() == '}':
                in_script = False
                continue
            # Get first word in line
            m = re.match(r'\s*([A-Z_][A-Z0-9_]*)', line)
            if m:
                macro = m.group(1)
                if macro not in event_macros:
                    missing.append((fname, macro, line.strip()))
    if missing:
        print(f"{fname} missing macros:")
        for fname, macro, line in missing:
            print(f"  {macro}: {line}")
