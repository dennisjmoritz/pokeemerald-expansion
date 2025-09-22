import os
import glob
import sys

# Character to remove (U+2025)
BAD_CHAR = '\u2025'

# Directory containing .pory files
POKE_DIR = os.path.join(os.path.dirname(__file__), '../data/maps')

# Clean all .pory and .inc files in data/maps
for ext in ('*.pory', '*.inc'):
    for file_path in glob.glob(os.path.join(POKE_DIR, '**', ext), recursive=True):
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
        if BAD_CHAR in content:
            cleaned = content.replace(BAD_CHAR, '')
            with open(file_path, 'w', encoding='utf-8') as f:
                f.write(cleaned)
            print(f"Removed U+2025 from: {file_path}")

print('Unicode cleaning complete.')
