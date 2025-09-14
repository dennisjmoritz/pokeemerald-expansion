#!/bin/bash

# Script to stash problematic parts of copied map files
# Removes object_events that reference undefined LOCALID_ from map.json
# And removes Mew-related code from scripts.inc

# Directory of the project
PROJECT_DIR="/home/dj/Documents/Projects/PokemonMultiRegion/pokeemerald-expansion"

# Get list of defined LOCALID_ values from event_objects.h
DEFINED_LOCALID_VALUES=$(grep "^#define LOCALID_" "$PROJECT_DIR/include/constants/event_objects.h" | awk '{print $3}')

# Function to check if LOCALID value is defined
is_localid_value_defined() {
    local value="$1"
    echo "$DEFINED_LOCALID_VALUES" | grep -q "^$value$"
}

# Function to check if a map has Mew-related code
has_mew_code() {
    local scripts_file="$1"
    grep -q "Mew\|MEW\|LOCALID_FARAWAY_ISLAND_MEW" "$scripts_file"
}

# Function to remove Mew-related code from scripts.inc
remove_mew_code() {
    local scripts_file="$1"
    # Simplify the scripts by removing Mew logic
    sed -i '/FarawayIsland_Interior_OnReturnToField/,/end/d' "$scripts_file"
    sed -i '/FarawayIsland_Interior_OnResume/,/end/d' "$scripts_file"
    sed -i '/FarawayIsland_Interior_OnTransition/,/call_if_unset FLAG_CAUGHT_MEW/d' "$scripts_file"
    sed -i '/FarawayIsland_Interior_OnFrame/,/end/d' "$scripts_file"
    sed -i '/FarawayIsland_Interior_EventScript_.*Mew/,/return/d' "$scripts_file"
    sed -i '/FarawayIsland_Interior_Movement_.*Mew/,/step_end/d' "$scripts_file"
    sed -i '/FarawayIsland_Interior_Text_TheFeelingOfBeingWatchedFaded/,/"/d' "$scripts_file"
    # Keep only basic OnTransition
    if grep -q "FarawayIsland_Interior_OnTransition" "$scripts_file"; then
        sed -i 's/call_if_unset FLAG_CAUGHT_MEW.*//g' "$scripts_file"
        sed -i 's/setvar VAR_TEMP_1, 1//g' "$scripts_file"
    fi
}

# Process all map directories
for map_dir in "$PROJECT_DIR/data/maps"/*/; do
    if [[ -d "$map_dir" ]]; then
        map_json="$map_dir/map.json"
        scripts_inc="$map_dir/scripts.inc"
        
        if [[ -f "$map_json" && -f "$scripts_inc" ]]; then
            echo "Processing $map_dir"
            
            # Check if map.json has object_events with undefined LOCALID_ values
            if jq -e '.object_events | length > 0' "$map_json" > /dev/null 2>&1; then
                PROBLEMATIC=false
                for localid_val in $(jq -r '.object_events[].local_id' "$map_json" 2>/dev/null); do
                    if [[ "$localid_val" != "null" && "$localid_val" != "" ]]; then
                        if ! is_localid_value_defined "$localid_val"; then
                            PROBLEMATIC=true
                            break
                        fi
                    fi
                done
                if $PROBLEMATIC; then
                    echo "  Removing object_events from $map_json (undefined LOCALID_ value)"
                    jq '.object_events = []' "$map_json" > "${map_json}.tmp" && mv "${map_json}.tmp" "$map_json"
                fi
            fi
            
            # Check for Mew code in scripts.inc
            if has_mew_code "$scripts_inc"; then
                echo "  Removing Mew code from $scripts_inc"
                remove_mew_code "$scripts_inc"
            fi
        fi
    fi
done

echo "Stashing complete."
