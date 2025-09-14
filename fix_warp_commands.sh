#!/bin/bash

# Script to scan all scripts.inc files and fix warp commands
# Removes the first numerical argument (typically 255) from warp lines that have 3 numerical arguments

echo "Scanning for warp commands with 3 numerical arguments..."

# Find all scripts.inc files
find /home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/data/maps -name "scripts.inc" | while read -r file; do
    echo "Processing: $file"

    # Use sed to find and replace warp commands that match the pattern:
    # warp MAP_NAME, 255, x, y  ->  warp MAP_NAME, x, y
    # This uses a regex to match the pattern and capture groups
    sed -i 's/\(warp [A-Z_][A-Z0-9_]*,\) 255, \([0-9][0-9]*\), \([0-9][0-9]*\)/\1 \2, \3/g' "$file"

    # Also handle warpsilent commands with the same pattern
    sed -i 's/\(warpsilent [A-Z_][A-Z0-9_]*,\) 255, \([0-9][0-9]*\), \([0-9][0-9]*\)/\1 \2, \3/g' "$file"

done

echo "Warp command cleanup complete!"
echo ""
echo "Summary of changes:"
echo "- Removed '255,' from warp commands that had 3 numerical arguments"
echo "- This affects harbor warp points and similar special warps"
echo "- Both 'warp' and 'warpsilent' commands were processed"
