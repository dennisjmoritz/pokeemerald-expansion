#!/usr/bin/env python3
"""
Script to update Pokemon Center map.json files to use generic layouts
instead of specific city layouts.

This script finds all map.json files that reference specific Pokemon Center
layouts (like LAYOUT_PEWTER_CITY_POKEMON_CENTER_1F) and updates them to
use the generic layouts (LAYOUT_POKEMON_CENTER_1F or LAYOUT_POKEMON_CENTER_2F).
"""

import os
import json
import glob
import re

def update_pokemon_center_layouts():
    """Update all Pokemon Center map.json files to use generic layouts."""

    # Find all map.json files
    map_files = glob.glob('data/maps/*/map.json')
    print(f'Found {len(map_files)} map.json files')

    updated_count = 0

    for map_file in map_files:
        try:
            with open(map_file, 'r') as f:
                data = json.load(f)

            original_layout = data.get('layout', '')

            # Check if it's a specific Pokemon Center layout
            if '_POKEMON_CENTER_' in original_layout:
                if original_layout.endswith('_1F'):
                    new_layout = 'LAYOUT_POKEMON_CENTER_1F'
                elif original_layout.endswith('_2F'):
                    new_layout = 'LAYOUT_POKEMON_CENTER_2F'
                else:
                    continue  # Skip if it doesn't match expected pattern

                if original_layout != new_layout:
                    data['layout'] = new_layout
                    with open(map_file, 'w') as f:
                        json.dump(data, f, indent=2)
                    print(f'Updated {map_file}: {original_layout} -> {new_layout}')
                    updated_count += 1

        except Exception as e:
            print(f'Error processing {map_file}: {e}')

    print(f'\nTotal files updated: {updated_count}')
    return updated_count

if __name__ == '__main__':
    update_pokemon_center_layouts()
