#!/bin/bash

MAPS_DIR="/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/data/maps"
FLAGS_FILE="/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/include/constants/flags.h"
VARS_FILE="/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/include/constants/vars.h"
OUTPUT_FILE="/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion/check_report.txt"

# Clear output
> "$OUTPUT_FILE"

echo "Checking flags and vars from $MAPS_DIR against $FLAGS_FILE and $VARS_FILE"
echo "Report: $OUTPUT_FILE"

# Check flags
echo "=== FLAGS ===" >> "$OUTPUT_FILE"
find "$MAPS_DIR" -name "*.json" -o -name "*.inc" | xargs grep -h "FLAG_" | grep -o "FLAG_[A-Z0-9_]*" | sort | uniq | while read -r flag; do
    if grep -q "$flag" "$FLAGS_FILE"; then
        echo "OK: $flag" >> "$OUTPUT_FILE"
    else
        echo "MISSING: $flag" >> "$OUTPUT_FILE"
    fi
done

# Check vars
echo "=== VARS ===" >> "$OUTPUT_FILE"
find "$MAPS_DIR" -name "*.json" -o -name "*.inc" | xargs grep -h "VAR_" | grep -o "VAR_[A-Z0-9_]*" | sort | uniq | while read -r var; do
    if grep -q "$var" "$VARS_FILE"; then
        echo "OK: $var" >> "$OUTPUT_FILE"
    else
        echo "MISSING: $var" >> "$OUTPUT_FILE"
    fi
done

echo "Check complete. See $OUTPUT_FILE"
