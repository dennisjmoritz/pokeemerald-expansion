#!/usr/bin/env python3
"""
FireRed Script Validator

This script checks scripts.inc files imported from FireRed for references
that don't exist in pokeemerald-expansion and suggests fixes.
"""

import os
import re
import glob
import argparse
from typing import List, Dict, Tuple

class FireRedScriptValidator:
    def __init__(self):
        # Common FireRed references that need to be replaced or checked
        self.firered_npcs = [
            "PROF_OAK", "Professor Oak", "Prof. Oak", "OAK",
            "BILL", "TEAM_ROCKET", "Team Rocket", "ROCKET",
            "GARY", "Gary", "RIVAL", 
            "GIOVANNI", "Giovanni"
        ]
        
        self.firered_items = [
            "ITEM_SILPH_SCOPE", "SILPH_SCOPE",
            "ITEM_CARD_KEY", "CARD_KEY", 
            "ITEM_LIFT_KEY", "LIFT_KEY",
            "ITEM_BIKE_VOUCHER", "BIKE_VOUCHER"
        ]
        
        self.firered_music = [
            "MUS_PALLET_TOWN", "MUS_VIRIDIAN_CITY", "MUS_PEWTER_CITY",
            "MUS_CERULEAN_CITY", "MUS_LAVENDER_TOWN", "MUS_VERMILION_CITY",
            "MUS_CELADON_CITY", "MUS_FUCHSIA_CITY", "MUS_CINNABAR_ISLAND",
            "MUS_INDIGO_PLATEAU", "MUS_VICTORY_ROAD_KANTO",
            "MUS_ROCKET_HIDEOUT", "MUS_SILPH_CO", "MUS_POKEMON_MANSION"
        ]
        
        self.firered_flags = [
            "FLAG_DEFEATED_BROCK", "FLAG_DEFEATED_MISTY", "FLAG_DEFEATED_SURGE",
            "FLAG_DEFEATED_ERIKA", "FLAG_DEFEATED_KOGA", "FLAG_DEFEATED_SABRINA", 
            "FLAG_DEFEATED_BLAINE", "FLAG_DEFEATED_GIOVANNI",
            "FLAG_ROCKET_HIDEOUT_", "FLAG_SILPH_CO_", "FLAG_POKEMON_MANSION_"
        ]
        
        self.firered_vars = [
            "VAR_KANTO_", "VAR_ROCKET_", "VAR_OAK_", "VAR_BILL_"
        ]
        
    def scan_script_file(self, script_file: str) -> Dict[str, List[str]]:
        """Scan a script file for FireRed references"""
        issues = {
            'npcs': [],
            'items': [],
            'music': [], 
            'flags': [],
            'vars': [],
            'trainers': [],
            'other': []
        }
        
        try:
            with open(script_file, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
        except Exception as e:
            issues['other'].append(f"Failed to read file: {e}")
            return issues
            
        lines = content.split('\n')
        
        for line_num, line in enumerate(lines, 1):
            line = line.strip()
            if not line or line.startswith('@') or line.startswith('//'):
                continue
                
            # Check for FireRed NPCs
            for npc in self.firered_npcs:
                if npc in line:
                    issues['npcs'].append(f"Line {line_num}: {npc} - {line[:60]}")
                    
            # Check for FireRed items
            for item in self.firered_items:
                if item in line:
                    issues['items'].append(f"Line {line_num}: {item} - {line[:60]}")
                    
            # Check for FireRed music
            for music in self.firered_music:
                if music in line:
                    issues['music'].append(f"Line {line_num}: {music} - {line[:60]}")
                    
            # Check for FireRed flags
            for flag in self.firered_flags:
                if flag in line:
                    issues['flags'].append(f"Line {line_num}: {flag} - {line[:60]}")
                    
            # Check for FireRed variables
            for var in self.firered_vars:
                if var in line:
                    issues['vars'].append(f"Line {line_num}: {var} - {line[:60]}")
                    
            # Check for specific trainer references
            if 'TRAINER_RED' in line or 'TRAINER_LEAF' in line:
                issues['trainers'].append(f"Line {line_num}: RED/LEAF trainer - {line[:60]}")
                
        return issues
        
    def suggest_fixes(self, issues: Dict[str, List[str]]) -> Dict[str, List[str]]:
        """Suggest fixes for identified issues"""
        suggestions = {}
        
        if issues['npcs']:
            suggestions['NPCs'] = [
                "Replace Professor Oak references with Professor Birch or create new NPC",
                "Replace Team Rocket with Team Aqua/Magma or generic villains",
                "Replace Gary/Rival with Brendan/May or create new rival character",
                "Replace Giovanni with Archie/Maxie or create new villain"
            ]
            
        if issues['items']:
            suggestions['Items'] = [
                "Replace SILPH_SCOPE with emerald equivalent or create new item",
                "Replace CARD_KEY/LIFT_KEY with generic key items",
                "Replace BIKE_VOUCHER with emerald bike shop system"
            ]
            
        if issues['music']:
            suggestions['Music'] = [
                "Convert Kanto town music to appropriate Hoenn equivalents",
                "Use MUS_AQUA_MAGMA_HIDEOUT for Rocket Hideout music",
                "Use MUS_DEVON_CORP for Silph Co music",
                "Use MUS_ABANDONED_SHIP for Pokemon Mansion music"
            ]
            
        if issues['flags']:
            suggestions['Flags'] = [
                "Create new flags for Kanto gym leaders if needed",
                "Map Rocket-related flags to Aqua/Magma equivalents",
                "Ensure all referenced flags are defined in constants"
            ]
            
        if issues['vars']:
            suggestions['Variables'] = [
                "Create new variables for Kanto-specific progression",
                "Map to existing Hoenn variables where appropriate",
                "Ensure all referenced variables are defined"
            ]
            
        if issues['trainers']:
            suggestions['Trainers'] = [
                "TRAINER_RED (851) and TRAINER_LEAF (852) are available",
                "Ensure trainer data is defined for these IDs",
                "Consider story implications of Red/Leaf in Hoenn"
            ]
            
        return suggestions
        
    def validate_script_directory(self, maps_dir: str) -> None:
        """Validate all script files in maps directory"""
        script_files = glob.glob(os.path.join(maps_dir, '*/scripts.inc'))
        
        print(f"Scanning {len(script_files)} script files in {maps_dir}")
        
        total_issues = 0
        files_with_issues = 0
        
        for script_file in script_files:
            issues = self.scan_script_file(script_file)
            
            # Count total issues
            file_issues = sum(len(issue_list) for issue_list in issues.values())
            
            if file_issues > 0:
                files_with_issues += 1
                total_issues += file_issues
                
                rel_path = os.path.relpath(script_file, maps_dir)
                print(f"\n📍 {rel_path}")
                
                for category, issue_list in issues.items():
                    if issue_list:
                        print(f"  {category.upper()}:")
                        for issue in issue_list[:3]:  # Limit to first 3 per category
                            print(f"    ⚠️  {issue}")
                        if len(issue_list) > 3:
                            print(f"    ... and {len(issue_list) - 3} more")
                            
                # Show suggestions
                suggestions = self.suggest_fixes(issues)
                if suggestions:
                    print(f"  🔧 SUGGESTED FIXES:")
                    for category, fixes in suggestions.items():
                        print(f"    {category}:")
                        for fix in fixes:
                            print(f"      ✅ {fix}")
                            
        print(f"\n📊 Summary:")
        print(f"  Script files scanned: {len(script_files)}")
        print(f"  Files with issues: {files_with_issues}")
        print(f"  Total issues found: {total_issues}")
        
    def create_example_script(self, output_file: str) -> None:
        """Create an example FireRed script with issues"""
        example_script = '''@ Example FireRed script with issues that need fixing

ExampleKantoMap_EventScript_RocketGrunt::
    lock
    faceplayer
    checkflag FLAG_DEFEATED_GIOVANNI
    goto_if_set ExampleKantoMap_EventScript_RocketGrunt_Defeated
    msgbox ExampleKantoMap_Text_RocketGrunt_Challenge, MSGBOX_DEFAULT
    trainerbattle_single TRAINER_ROCKET_GRUNT_1, ExampleKantoMap_Text_RocketGrunt_Intro, ExampleKantoMap_Text_RocketGrunt_Defeat
    msgbox ExampleKantoMap_Text_RocketGrunt_After, MSGBOX_DEFAULT
    release
    end

ExampleKantoMap_EventScript_RocketGrunt_Defeated::
    msgbox ExampleKantoMap_Text_RocketGrunt_Defeated, MSGBOX_DEFAULT
    release
    end

ExampleKantoMap_EventScript_ProfOak::
    lock
    faceplayer
    checkitem ITEM_SILPH_SCOPE
    goto_if_has ExampleKantoMap_EventScript_HasSilphScope
    msgbox ExampleKantoMap_Text_ProfOak_NeedScope, MSGBOX_DEFAULT
    release
    end

ExampleKantoMap_EventScript_HasSilphScope::
    msgbox ExampleKantoMap_Text_ProfOak_HasScope, MSGBOX_DEFAULT
    playfanfare MUS_OBTAIN_ITEM
    message ExampleKantoMap_Text_ReceivedCardKey
    waitfanfare
    giveitem ITEM_CARD_KEY
    setflag FLAG_ROCKET_HIDEOUT_CARD_KEY
    release
    end

@ Text strings (these would also need reviewing)
ExampleKantoMap_Text_RocketGrunt_Challenge:
    .string "Team Rocket will take over the world!$"

ExampleKantoMap_Text_ProfOak_NeedScope:
    .string "Prof. Oak: You need the SILPH SCOPE\\n"
    .string "to see the ghosts in Lavender Tower!$"

ExampleKantoMap_Text_ReceivedCardKey:
    .string "{PLAYER} received the CARD KEY!$"
'''
        
        os.makedirs(os.path.dirname(output_file), exist_ok=True)
        with open(output_file, 'w') as f:
            f.write(example_script)
        print(f"Created example FireRed script: {output_file}")

def main():
    parser = argparse.ArgumentParser(description='Validate FireRed script imports')
    parser.add_argument('--maps-dir', default='data/maps',
                       help='Directory containing map script files (default: data/maps)')
    parser.add_argument('--create-example', metavar='FILE',
                       help='Create an example FireRed script with issues')
    
    args = parser.parse_args()
    
    validator = FireRedScriptValidator()
    
    if args.create_example:
        validator.create_example_script(args.create_example)
        return
        
    if not os.path.exists(args.maps_dir):
        print(f"Error: Maps directory not found: {args.maps_dir}")
        exit(1)
        
    validator.validate_script_directory(args.maps_dir)

if __name__ == '__main__':
    main()