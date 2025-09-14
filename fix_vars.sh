#!/bin/bash

# Directory to search
MAPS_DIR="/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/data/maps"

# Find all map.json, scripts.inc, and events.inc files
find "$MAPS_DIR" \( -name "map.json" -o -name "scripts.inc" -o -name "events.inc" \) -type f | while read -r file; do
    # Replace VAR_1 to VAR_9 with VAR_TEMP_1 to VAR_TEMP_9
    sed -i 's/VAR_1/VAR_TEMP_1/g' "$file"
    sed -i 's/VAR_2/VAR_TEMP_2/g' "$file"
    sed -i 's/VAR_3/VAR_TEMP_3/g' "$file"
    sed -i 's/VAR_4/VAR_TEMP_4/g' "$file"
    sed -i 's/VAR_5/VAR_TEMP_5/g' "$file"
    sed -i 's/VAR_6/VAR_TEMP_6/g' "$file"
    sed -i 's/VAR_7/VAR_TEMP_7/g' "$file"
    sed -i 's/VAR_8/VAR_TEMP_8/g' "$file"
    sed -i 's/VAR_9/VAR_TEMP_9/g' "$file"
    echo "Updated $file"
done

echo "Replacement complete."
