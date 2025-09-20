# FireRed to Emerald Map Conversion Guide

## Overview
This document outlines the differences between FireRed (Kanto) maps and pokeemerald standards, and provides guidelines for converting imported FireRed maps to work correctly in the pokeemerald-expansion project.

## Key Differences Between FireRed and Emerald Map Formats

### 1. Floor Number Field
**FireRed maps include a `floor_number` field that doesn't exist in Emerald:**
- FireRed: `"floor_number": 1`
- Emerald: This field should be **removed** entirely

### 2. Map Battle Scenes
FireRed may use different battle scene constants that don't exist in Emerald:
- Check `battle_scene` field and convert to valid Emerald constants
- Default to `"MAP_BATTLE_SCENE_NORMAL"` if uncertain

### 3. Music References
FireRed uses different music constants than Emerald:
- Common FireRed music that needs conversion:
  - `MUS_PALLET_TOWN` → Use appropriate Emerald equivalent
  - `MUS_VIRIDIAN_CITY` → Use appropriate Emerald equivalent
  - Rocket-related music → `MUS_AQUA_MAGMA_HIDEOUT` or similar

### 4. Map Type Constants
Verify map type constants are valid for Emerald:
- `MAP_TYPE_TOWN`, `MAP_TYPE_CITY`, `MAP_TYPE_ROUTE`, etc.

### 5. Region Map Sections
FireRed imports should use the Kanto-specific map sections defined in pokeemerald-expansion:
- `MAPSEC_ROCKET_HIDEOUT`
- `MAPSEC_SILPH_CO` 
- `MAPSEC_POKEMON_MANSION`
- `MAPSEC_KANTO_SAFARI_ZONE`
- `MAPSEC_KANTO_VICTORY_ROAD`
- `MAPSEC_DIGLETTS_CAVE`
- `MAPSEC_ROCKET_WAREHOUSE`

### 6. Trainer References
FireRed maps may reference trainers that don't exist in Emerald:
- Convert Team Rocket trainers to use appropriate constants
- RED and LEAF trainers are available as `TRAINER_RED` (851) and `TRAINER_LEAF` (852)

### 7. Script References
FireRed script files may contain references to:
- **Non-existent NPCs**: Professor Oak, Team Rocket members, etc.
- **Non-existent items**: FireRed-specific items
- **Non-existent flags**: FireRed story flags
- **Non-existent variables**: FireRed-specific variables

## Conversion Checklist

When importing a FireRed map, check and fix the following:

### Map JSON (`map.json`)
- [ ] Remove `floor_number` field if present
- [ ] Verify `battle_scene` uses valid Emerald constant
- [ ] Update `music` to valid Emerald music constant
- [ ] Ensure `region_map_section` uses appropriate Kanto section
- [ ] Check all trainer IDs in `object_events` are valid
- [ ] Verify all script names in `object_events` exist
- [ ] Check all flag names are defined in pokeemerald-expansion

### Script Files (`scripts.inc`)
- [ ] Replace references to non-existent NPCs with Emerald equivalents
- [ ] Update item constants to Emerald standards
- [ ] Replace story flags with appropriate Emerald flags or create new ones
- [ ] Update variable references to use Emerald standards
- [ ] Replace Team Rocket references with Team Aqua/Magma or generic equivalents
- [ ] Ensure all referenced text strings exist

### Common Script Fixes Needed
1. **Professor Oak references** → Professor Birch or create new NPC
2. **Team Rocket** → Team Aqua/Magma or create generic villains  
3. **FireRed-specific items** → Convert to Emerald equivalents
4. **Kanto gym badges** → Create new badge system or adapt
5. **FireRed story flags** → Map to Emerald story progression

## Tools for Conversion

### 1. Map JSON Validator
A Python script to validate FireRed imports and suggest fixes.

### 2. Script Analyzer  
A tool to scan script files for non-existent references.

### 3. Automated Fixes
Scripts to automatically fix common issues like removing `floor_number`.

## Testing Converted Maps

After conversion:
1. Build the project to check for compilation errors
2. Test in-game to ensure:
   - Maps load correctly
   - Scripts execute without errors
   - NPCs behave as expected
   - All referenced content exists

## Notes for Developers

- When adding new Kanto content, prefer creating new constants over repurposing Hoenn ones
- Document any new flags, variables, or constants added for Kanto content
- Consider the story implications of adding Kanto content to the Hoenn region
- Maintain consistency with pokeemerald-expansion coding standards