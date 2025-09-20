# FireRed Import Tools

This directory contains tools for importing and converting FireRed (Kanto) maps to pokeemerald standards.

## Tools Overview

### 1. firered_converter.py
Validates and automatically fixes map.json files imported from FireRed.

**Usage:**
```bash
# Scan all maps for FireRed issues (read-only)
python3 tools/firered_converter.py

# Scan and automatically fix issues
python3 tools/firered_converter.py --fix

# Create an example FireRed map for testing
python3 tools/firered_converter.py --create-example /tmp/example_map.json
```

**What it fixes automatically:**
- ✅ Removes `floor_number` field (FireRed-specific)
- ✅ Converts FireRed music constants to Emerald equivalents
- ✅ Fixes invalid `battle_scene` constants
- ⚠️  Warns about unknown map sections and trainer references

### 2. firered_script_validator.py
Scans scripts.inc files for FireRed references that need manual fixing.

**Usage:**
```bash
# Scan all script files for FireRed references
python3 tools/firered_script_validator.py

# Create an example FireRed script for testing  
python3 tools/firered_script_validator.py --create-example /tmp/example_script.inc
```

**What it detects:**
- 🔍 Professor Oak, Team Rocket, and other FireRed NPC references
- 🔍 FireRed-specific items (Silph Scope, Card Key, etc.)
- 🔍 FireRed music references
- 🔍 FireRed story flags and variables
- 🔍 RED/LEAF trainer references

## FireRed vs Emerald Differences

### Automatic Fixes
These issues can be fixed automatically by the converter:

| FireRed | Emerald Equivalent | Status |
|---------|-------------------|--------|
| `"floor_number": 1` | (removed entirely) | ✅ Auto-fixed |
| `"music": "MUS_PALLET_TOWN"` | `"music": "MUS_LITTLEROOT"` | ✅ Auto-fixed |
| `"battle_scene": "MAP_BATTLE_SCENE_ROCKET"` | `"battle_scene": "MAP_BATTLE_SCENE_NORMAL"` | ✅ Auto-fixed |

### Manual Fixes Required
These issues need manual intervention:

| Issue Type | Description | Action Needed |
|------------|-------------|---------------|
| NPC References | Professor Oak, Team Rocket, etc. | Replace with Emerald NPCs or create new ones |
| Items | Silph Scope, Card Key, etc. | Replace with Emerald items or create new ones |
| Story Flags | `FLAG_DEFEATED_GIOVANNI`, etc. | Create new flags or map to existing ones |
| Trainer IDs | Unknown trainer constants | Verify trainer data exists |
| Script Names | Non-existent script references | Create missing scripts or update references |

## Workflow for Importing FireRed Maps

### Step 1: Place FireRed Files
1. Create directory: `data/maps/YourKantoMap/`
2. Add files: `map.json` and `scripts.inc`

### Step 2: Run Automated Fixes
```bash
python3 tools/firered_converter.py --fix
```

### Step 3: Scan for Manual Issues
```bash
python3 tools/firered_script_validator.py
```

### Step 4: Fix Manual Issues
Based on validator output, fix references to:
- Non-existent NPCs, items, flags, variables
- Invalid trainer IDs
- Missing script functions

### Step 5: Add to Map Groups
Update `data/maps/map_groups.json` to include your new map.

### Step 6: Test
1. Build the project: `make`
2. Test in-game functionality

## Available Kanto Map Sections

The following Kanto-specific map sections are available:
- `MAPSEC_ROCKET_HIDEOUT` - Team Rocket Hideout
- `MAPSEC_SILPH_CO` - Silph Co. building
- `MAPSEC_POKEMON_MANSION` - Pokémon Mansion
- `MAPSEC_KANTO_SAFARI_ZONE` - Kanto Safari Zone
- `MAPSEC_KANTO_VICTORY_ROAD` - Kanto Victory Road
- `MAPSEC_DIGLETTS_CAVE` - Diglett's Cave
- `MAPSEC_ROCKET_WAREHOUSE` - Rocket Warehouse

## Available Kanto Trainers

- `TRAINER_RED` (ID: 851) - Red from FireRed
- `TRAINER_LEAF` (ID: 852) - Leaf from FireRed

*Note: Trainer data must be defined separately in trainer files.*

## Common Issues and Solutions

### Issue: "Unknown battle_scene"
**Cause:** FireRed uses battle scenes not available in Emerald
**Solution:** Use `MAP_BATTLE_SCENE_NORMAL` or appropriate Emerald equivalent

### Issue: "FireRed music detected" 
**Cause:** FireRed music constants don't exist in Emerald
**Solution:** Automatically converted by the tool, or manually choose appropriate Emerald music

### Issue: "Contains floor_number field"
**Cause:** FireRed maps include floor numbers, Emerald maps don't
**Solution:** Automatically removed by the tool

### Issue: "Professor Oak references"
**Cause:** Professor Oak doesn't exist in Emerald
**Solutions:**
- Replace with Professor Birch for similar functions
- Create new NPC for Kanto-specific content
- Remove references if not needed

### Issue: "Team Rocket references"
**Cause:** Team Rocket doesn't exist in Emerald
**Solutions:**
- Replace with Team Aqua/Magma for similar evil team functions
- Create generic villain NPCs
- Adapt story to fit Emerald context

## Tips for Manual Fixes

1. **Search and Replace**: Use your editor to find/replace common patterns
   - `Prof. Oak` → `Prof. Birch`
   - `Team Rocket` → `Team Aqua` or `Team Magma`
   - `GIOVANNI` → `ARCHIE` or `MAXIE`

2. **Create New Constants**: For Kanto-specific content, create new constants rather than reusing Hoenn ones
   
3. **Story Consistency**: Consider how Kanto content fits into the Emerald storyline

4. **Test Thoroughly**: FireRed imports may have subtle compatibility issues

## Need Help?

- Check `docs/firered_to_emerald_conversion.md` for detailed conversion guidelines
- Examine existing Emerald maps for reference patterns
- Test changes incrementally to isolate issues