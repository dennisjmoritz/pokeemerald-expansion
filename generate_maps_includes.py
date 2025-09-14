#!/usr/bin/env python3
import os
import glob

# Find all scripts.inc in data/maps/
scripts = glob.glob('data/maps/*/scripts.inc')

# Sort them to have consistent order
scripts.sort()

# Output the includes
with open('data/maps_includes.inc', 'w') as f:
    for script in scripts:
        f.write(f'\t.include "{script}"\n')
