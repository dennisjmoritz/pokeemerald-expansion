import os
import glob
import sys


# Remove any non-ASCII (atypical) characters
def clean_atypical_chars(text):
    return ''.join(c for c in text if ord(c) < 128)

# Directory containing .pory files
POKE_DIR = os.path.join(os.path.dirname(__file__), '../data/maps')

# Clean all .pory and .inc files in data/maps

for ext in ('*.pory', '*.inc'):
    for file_path in glob.glob(os.path.join(POKE_DIR, '**', ext), recursive=True):
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
        cleaned = clean_atypical_chars(content)
        if cleaned != content:
            with open(file_path, 'w', encoding='utf-8') as f:
                f.write(cleaned)
            print(f"Removed atypical (non-ASCII) characters from: {file_path}")

print('Unicode cleaning complete.')
