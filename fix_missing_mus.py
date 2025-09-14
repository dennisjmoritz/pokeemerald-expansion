#!/usr/bin/env python3
import subprocess
import re
import os
import json

def run_make():
    """Run make -j24 and capture undefined MUS references."""
    cmd = r"make -j24 2>&1 | grep 'undefined reference to `MUS_'"
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True, cwd="/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion")
    return result.stdout

def extract_missing_mus(output):
    """Extract unique MUS_XXX from the output."""
    mus_set = set()
    for line in output.split('\n'):
        match = re.search(r"undefined reference to `(MUS_\w+)'", line)
        if match:
            mus_set.add(match.group(1))
    return mus_set

def find_maps_with_mus(mus):
    """Find map.json files that have the given MUS."""
    cmd = f"grep -r '\"music\": \"{mus}\"' data/maps/ --include=*.json"
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True, cwd="/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion")
    files = []
    for line in result.stdout.split('\n'):
        if line:
            file_path = line.split(':')[0]
            files.append(file_path)
    return files

def replace_mus_in_file(file_path, old_mus, new_mus):
    """Replace MUS in map.json file."""
    with open(file_path, 'r') as f:
        data = json.load(f)
    if data.get('music') == old_mus:
        data['music'] = new_mus
        with open(file_path, 'w') as f:
            json.dump(data, f, indent=4)
        print(f"Replaced {old_mus} with {new_mus} in {file_path}")

def main():
    new_mus = "MUS_OLDALE"  # Known good MUS
    output = run_make()
    missing_mus = extract_missing_mus(output)
    print(f"Missing MUS: {missing_mus}")
    for mus in missing_mus:
        files = find_maps_with_mus(mus)
        for file in files:
            replace_mus_in_file(file, mus, new_mus)

if __name__ == "__main__":
    main()
