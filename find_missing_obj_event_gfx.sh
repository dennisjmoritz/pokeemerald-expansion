#!/bin/bash

# Script to find OBJ_EVENT_GFX constants used in map.json files that are not defined in event_objects.h

# Set the project root directory
PROJECT_ROOT="/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion"

# Path to the event_objects.h file
EVENT_OBJECTS_H="$PROJECT_ROOT/pokeemerald-omnis/include/constants/event_objects.h"

# Function to extract defined OBJ_EVENT_GFX constants from event_objects.h
extract_defined_gfx() {
    grep "^#define OBJ_EVENT_GFX_" "$EVENT_OBJECTS_H" | awk '{print $2}' | sort | uniq
}

# Function to extract OBJ_EVENT_GFX references from all map.json files
extract_used_gfx() {
    find "$PROJECT_ROOT" -name "*.json" -path "*/maps/*" -exec grep -h "OBJ_EVENT_GFX_" {} \; | \
    sed 's/.*"OBJ_EVENT_GFX_\([^"]*\)".*/OBJ_EVENT_GFX_\1/' | \
    sort | uniq
}

# Main script
echo "Finding OBJ_EVENT_GFX constants used in map.json files but not defined in event_objects.h..."
echo

# Get defined constants
echo "Extracting defined OBJ_EVENT_GFX constants from event_objects.h..."
DEFINED_GFX=$(extract_defined_gfx)
DEFINED_COUNT=$(echo "$DEFINED_GFX" | wc -l)
echo "Found $DEFINED_COUNT defined constants"

# Get used constants
echo "Extracting OBJ_EVENT_GFX constants from map.json files..."
USED_GFX=$(extract_used_gfx)
USED_COUNT=$(echo "$USED_GFX" | wc -l)
echo "Found $USED_COUNT used constants"

# Find missing constants
echo
echo "Finding missing constants..."
MISSING_GFX=$(comm -23 <(echo "$USED_GFX") <(echo "$DEFINED_GFX"))

if [ -z "$MISSING_GFX" ]; then
    echo "✅ No missing OBJ_EVENT_GFX constants found!"
else
    MISSING_COUNT=$(echo "$MISSING_GFX" | wc -l)
    echo "❌ Found $MISSING_COUNT missing OBJ_EVENT_GFX constants:"
    echo
    echo "$MISSING_GFX" | while read -r gfx; do
        echo "  - $gfx"
    done
    echo
    echo "These constants are used in map.json files but not defined in event_objects.h"
fi

echo
echo "Summary:"
echo "  - Defined in event_objects.h: $DEFINED_COUNT"
echo "  - Used in map.json files: $USED_COUNT"
echo "  - Missing: $(echo "$MISSING_GFX" | wc -l)"
