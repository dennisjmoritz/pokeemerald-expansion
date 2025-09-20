#!/usr/bin/env python3
"""
FireRed Import Validator and Fixer

This script validates and fixes map.json files imported from FireRed to ensure
they follow pokeemerald standards.
"""

import json
import os
import sys
import glob
import argparse
from typing import Dict, List, Any, Tuple

class FireRedConverter:
    def __init__(self):
        # Define valid constants for pokeemerald-expansion
        self.valid_battle_scenes = [
            "MAP_BATTLE_SCENE_NORMAL",
            "MAP_BATTLE_SCENE_GYM", 
            "MAP_BATTLE_SCENE_MAGMA",
            "MAP_BATTLE_SCENE_AQUA",
            "MAP_BATTLE_SCENE_SIDNEY",
            "MAP_BATTLE_SCENE_PHOEBE", 
            "MAP_BATTLE_SCENE_GLACIA",
            "MAP_BATTLE_SCENE_DRAKE",
            "MAP_BATTLE_SCENE_CHAMPION",
            "MAP_BATTLE_SCENE_FRONTIER"
        ]
        
        self.kanto_map_sections = [
            "MAPSEC_ROCKET_HIDEOUT",
            "MAPSEC_SILPH_CO",
            "MAPSEC_POKEMON_MANSION", 
            "MAPSEC_KANTO_SAFARI_ZONE",
            "MAPSEC_KANTO_VICTORY_ROAD",
            "MAPSEC_DIGLETTS_CAVE",
            "MAPSEC_ROCKET_WAREHOUSE"
        ]
        
        # Music conversion mappings
        self.music_conversions = {
            "MUS_PALLET_TOWN": "MUS_LITTLEROOT",
            "MUS_VIRIDIAN_CITY": "MUS_OLDALE", 
            "MUS_PEWTER_CITY": "MUS_DEWFORD",
            "MUS_CERULEAN_CITY": "MUS_SLATEPORT",
            "MUS_LAVENDER_TOWN": "MUS_MT_PYRE",
            "MUS_ROCKET_HIDEOUT": "MUS_AQUA_MAGMA_HIDEOUT",
            "MUS_SILPH_CO": "MUS_DEVON_CORP",
            "MUS_POKEMON_MANSION": "MUS_ABANDONED_SHIP"
        }
        
    def analyze_map(self, map_file: str) -> Tuple[Dict[str, Any], List[str], List[str]]:
        """
        Analyze a map file for FireRed characteristics
        Returns: (map_data, issues, fixes_applied)
        """
        issues = []
        fixes_applied = []
        
        try:
            with open(map_file, 'r') as f:
                map_data = json.load(f)
        except Exception as e:
            issues.append(f"Failed to load JSON: {e}")
            return {}, issues, fixes_applied
            
        # Check for FireRed-specific floor_number field
        if 'floor_number' in map_data:
            issues.append("Contains FireRed-specific 'floor_number' field")
            
        # Check battle_scene
        battle_scene = map_data.get('battle_scene', '')
        if battle_scene and battle_scene not in self.valid_battle_scenes:
            issues.append(f"Unknown battle_scene: {battle_scene}")
            
        # Check music
        music = map_data.get('music', '')
        if music in self.music_conversions:
            issues.append(f"FireRed music detected: {music}")
            
        # Check map section
        region_section = map_data.get('region_map_section', '')
        if region_section and 'KANTO' in region_section and region_section not in self.kanto_map_sections:
            issues.append(f"Unknown Kanto map section: {region_section}")
            
        return map_data, issues, fixes_applied
        
    def fix_map(self, map_data: Dict[str, Any]) -> Tuple[Dict[str, Any], List[str]]:
        """
        Apply automatic fixes to a map
        Returns: (fixed_map_data, fixes_applied)
        """
        fixes_applied = []
        
        # Remove floor_number field
        if 'floor_number' in map_data:
            del map_data['floor_number']
            fixes_applied.append("Removed 'floor_number' field")
            
        # Fix music references
        music = map_data.get('music', '')
        if music in self.music_conversions:
            map_data['music'] = self.music_conversions[music]
            fixes_applied.append(f"Converted music: {music} → {map_data['music']}")
            
        # Fix battle_scene if unknown
        battle_scene = map_data.get('battle_scene', '')
        if battle_scene and battle_scene not in self.valid_battle_scenes:
            map_data['battle_scene'] = 'MAP_BATTLE_SCENE_NORMAL'
            fixes_applied.append(f"Fixed battle_scene: {battle_scene} → MAP_BATTLE_SCENE_NORMAL")
            
        return map_data, fixes_applied
        
    def validate_directory(self, maps_dir: str, fix: bool = False) -> None:
        """Validate all maps in a directory"""
        map_files = glob.glob(os.path.join(maps_dir, '*/map.json'))
        
        print(f"Scanning {len(map_files)} map files in {maps_dir}")
        
        total_issues = 0
        maps_with_issues = 0
        total_fixes = 0
        
        for map_file in map_files:
            map_data, issues, _ = self.analyze_map(map_file)
            
            if issues:
                maps_with_issues += 1
                total_issues += len(issues)
                rel_path = os.path.relpath(map_file, maps_dir)
                print(f"\n📍 {rel_path}")
                for issue in issues:
                    print(f"  ⚠️  {issue}")
                    
                if fix:
                    fixed_data, fixes = self.fix_map(map_data)
                    if fixes:
                        total_fixes += len(fixes)
                        print(f"  🔧 Applied fixes:")
                        for fix_msg in fixes:
                            print(f"    ✅ {fix_msg}")
                            
                        # Save fixed file
                        try:
                            with open(map_file, 'w') as f:
                                json.dump(fixed_data, f, indent=2)
                            print(f"    💾 Saved fixed file")
                        except Exception as e:
                            print(f"    ❌ Failed to save: {e}")
                            
        print(f"\n📊 Summary:")
        print(f"  Maps scanned: {len(map_files)}")
        print(f"  Maps with issues: {maps_with_issues}")
        print(f"  Total issues found: {total_issues}")
        if fix:
            print(f"  Total fixes applied: {total_fixes}")
            
    def create_example_firered_map(self, output_file: str) -> None:
        """Create an example FireRed map with issues to demonstrate fixing"""
        example_map = {
            "id": "MAP_EXAMPLE_KANTO_MAP",
            "name": "ExampleKantoMap",
            "layout": "LAYOUT_EXAMPLE_KANTO_MAP", 
            "music": "MUS_PALLET_TOWN",  # FireRed music - should be converted
            "region_map_section": "MAPSEC_ROCKET_HIDEOUT",
            "requires_flash": False,
            "weather": "WEATHER_NONE",
            "map_type": "MAP_TYPE_INDOOR",
            "allow_cycling": False,
            "allow_escaping": True,
            "allow_running": True,
            "show_map_name": True,
            "floor_number": 1,  # FireRed-specific field - should be removed
            "battle_scene": "MAP_BATTLE_SCENE_ROCKET",  # Invalid - should be fixed
            "connections": None,
            "object_events": [
                {
                    "graphics_id": "OBJ_EVENT_GFX_TEAM_ROCKET_GRUNT_M",
                    "x": 5,
                    "y": 5,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
                    "movement_range_x": 0,
                    "movement_range_y": 0,
                    "trainer_type": "TRAINER_TYPE_NORMAL",
                    "trainer_sight_or_berry_tree_id": "3",
                    "script": "ExampleKantoMap_EventScript_RocketGrunt",
                    "flag": "0"
                }
            ],
            "warp_events": [],
            "coord_events": [],
            "bg_events": []
        }
        
        os.makedirs(os.path.dirname(output_file), exist_ok=True)
        with open(output_file, 'w') as f:
            json.dump(example_map, f, indent=2)
        print(f"Created example FireRed map: {output_file}")

def main():
    parser = argparse.ArgumentParser(description='Validate and fix FireRed map imports')
    parser.add_argument('--maps-dir', default='data/maps', 
                       help='Directory containing map files (default: data/maps)')
    parser.add_argument('--fix', action='store_true',
                       help='Apply automatic fixes to issues found')
    parser.add_argument('--create-example', metavar='FILE',
                       help='Create an example FireRed map with issues')
    
    args = parser.parse_args()
    
    converter = FireRedConverter()
    
    if args.create_example:
        converter.create_example_firered_map(args.create_example)
        return
        
    if not os.path.exists(args.maps_dir):
        print(f"Error: Maps directory not found: {args.maps_dir}")
        sys.exit(1)
        
    converter.validate_directory(args.maps_dir, fix=args.fix)

if __name__ == '__main__':
    main()