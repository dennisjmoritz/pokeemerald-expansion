import re
import glob

# Collect all macro-like identifiers from .pory files
pory_macros = set()
for fname in glob.glob('data/maps/**/*.pory', recursive=True):
    with open(fname, encoding='utf-8', errors='ignore') as f:
        pory_macros.update(re.findall(r'\b([A-Z_][A-Z0-9_]+)\b', f.read()))

# Collect all macro definitions from event.inc
with open('asm/macros/event.inc', encoding='utf-8', errors='ignore') as f:
    event_macros = set(re.findall(r'\b([A-Z_][A-Z0-9_]+)\b', f.read()))

missing = sorted(pory_macros - event_macros)
if missing:
    print('Missing macros:', missing)
else:
    print('None missing.')
