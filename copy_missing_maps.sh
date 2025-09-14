#!/bin/bash

# Source directory (pokeemerald-omnis)
SOURCE_DIR="/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/pokeemerald-omnis/data/maps"

# Decomp directory (decomp/pokeemerald-expansion)
DECOMP_DIR="/decomps/pokeemerald-expansion/data/maps"

# Target directory (current repo)
TARGET_DIR="/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/data/maps"

# Log file for problematic entries
LOG_FILE="/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/copy_log.txt"

# Clear log
> "$LOG_FILE"

echo "Starting copy of missing map.json and scripts.inc files from pokeemerald-omnis to pokeemerald-expansion"
echo "Ignoring maps already in decomp/pokeemerald-expansion"
echo "Only including maps where the directory exists in target"
echo "Log of potential issues: $LOG_FILE"

# Find all map.json and scripts.inc in source
find "$SOURCE_DIR" \( -name "map.json" -o -name "scripts.inc" \) -type f | while read -r file; do
    # Get relative path
    relative_path="${file#$SOURCE_DIR/}"
    target_file="$TARGET_DIR/$relative_path"
    decomp_file="$DECOMP_DIR/$relative_path"
    
    # Check if map directory exists in target (to see if map is included)
    map_dir=$(dirname "$relative_path")
    if [ ! -d "$TARGET_DIR/$map_dir" ]; then
        echo "Skipped $relative_path (map not included in target)"
        continue
    fi
    
    # Check if exists in decomp
    if [ -f "$decomp_file" ]; then
        echo "Skipped $relative_path (exists in decomp)"
        continue
    fi
    
    # Copy (replace if exists)
    cp "$file" "$target_file"
    echo "Copied $relative_path"
    
    # Check for potential issues
    if [[ "$file" == *.json ]]; then
        # For map.json, check for flags, vars, maps
        grep -n "FLAG_\|VAR_\|MAP_" "$file" >> "$LOG_FILE" 2>/dev/null || true
    elif [[ "$file" == *scripts.inc ]]; then
        # For scripts.inc, check for flags, vars, maps, specials, etc.
        grep -n "FLAG_\|VAR_\|MAP_\|SPECIAL_\|setflag\|setvar\|setdynamicwarp\|call\|goto" "$file" >> "$LOG_FILE" 2>/dev/null || true
    fi
done

echo "Copy complete. Check $LOG_FILE for potential issues."
