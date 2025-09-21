# How to Add/Modify TMs and HMs

This tutorial will guide you through adding new Technical Machines (TMs) and Hidden Machines (HMs) to your pokeemerald-expansion ROM hack. TMs and HMs are essential items that teach moves to Pokémon and provide field utility.

## Content
* [Quick Summary](#quick-summary)
* [Understanding TMs and HMs](#understanding-tms-and-hms)
* [The TM/HM System Structure](#the-tmhm-system-structure)
* [Adding New TMs](#adding-new-tms)
  * [1. Adding TM to Constants](#1-adding-tm-to-constants)
  * [2. Configuring TM Data](#2-configuring-tm-data)
  * [3. Adding TM Graphics](#3-adding-tm-graphics)
  * [4. Updating TM Lists](#4-updating-tm-lists)
* [Adding New HMs](#adding-new-hms)
* [Modifying Existing TMs/HMs](#modifying-existing-tmshms)
* [Distribution and Availability](#distribution-and-availability)
* [Troubleshooting](#troubleshooting)

## Quick Summary

If you've done this before and just need a quick reference:

1. Add TM/HM entry to `src/data/tms_hms.json`
2. Update Pokémon learnset compatibility
3. Place TM/HM in world (shops, NPCs, hidden items)
4. Test functionality

## Understanding TMs and HMs

### Technical Machines (TMs)
- Single-use items that teach moves to compatible Pokémon
- Can be found, purchased, or received from NPCs
- In newer generations, TMs are reusable (configurable)
- Each TM teaches a specific move

### Hidden Machines (HMs)
- Similar to TMs but teach field moves (Surf, Fly, etc.)
- Cannot be deleted from Pokémon movesets normally
- Required for world navigation and puzzle solving
- Usually obtained through story progression

### Key Differences
- HMs teach moves usable outside of battle
- HM moves cannot be easily forgotten
- TMs are typically more numerous than HMs
- Some moves can only be learned via TM/HM

## The TM/HM System Structure

The TM/HM system involves several interconnected files:

- `src/data/tms_hms.json`: JSON configuration defining all TMs and HMs with their moves and item properties
- `include/constants/tms_hms.h`: Auto-generated constants defining which moves are TMs/HMs
- `include/constants/items.h`: Auto-generated TM/HM item constants  
- `src/data/items.h`: Auto-generated TM/HM item data (descriptions, prices, etc.)
- `src/data/graphics/items.h`: TM/HM graphics and icons
- Move compatibility in Pokémon species data
- Distribution through shops, NPCs, and world placement

### TM/HM Numbering

TMs are typically numbered 01-99+ while HMs use 01-08. The system automatically maps these numbers to specific moves based on the order defined in `tms_hms.json`.

## Adding New TMs

### 1. Adding TM to JSON Configuration

Edit `src/data/tms_hms.json` to add your new TM. The JSON structure defines all TM and HM properties in one place:

```json
{
  "tms": [
    {
      "move": "FOCUS_PUNCH",
      "name": "TM01",
      "price": 3000,
      "description": "Powerful, but makes\nthe user flinch if\nhit by the foe.",
      "importance": "I_REUSABLE_TMS",
      "iconPic": "gItemIcon_TM",
      "iconPalette": "gItemIconPalette_TMNormal"
    },
    {
      "move": "DRAGON_CLAW",
      "name": "TM02",
      "price": 3000,
      "description": "Slashes the foe with\nsharp claws.",
      "importance": "I_REUSABLE_TMS",
      "iconPic": "gItemIcon_TM",
      "iconPalette": "gItemIconPalette_TMNormal"
    },
    // ... existing TMs ...
    {
      "move": "YOUR_NEW_MOVE",
      "name": "TM95",
      "price": 3000,
      "description": "Teaches a Pokémon\nthe move Your New\nMove. Single use.",
      "importance": "I_REUSABLE_TMS",
      "iconPic": "gItemIcon_TM",
      "iconPalette": "gItemIconPalette_TMNormal"
    }
  ],
  "hms": [
    // HM definitions here
  ]
}
```

The system will automatically:
- Generate TM constants in `include/constants/tms_hms.h`
- Create item definitions in `src/data/items.h`
- Assign TM numbers based on the order in the JSON array

### 2. Adding TM Graphics

TMs typically use shared graphics with different colored palettes. If you want custom TM graphics:

#### Standard TM Graphics
Most TMs use the standard disc graphic with different type-based colors:
- `gItemIcon_TM`: Standard TM disc
- `gItemIconPalette_TMNormal`: Normal-type TM palette
- `gItemIconPalette_TMFighting`: Fighting-type TM palette
- etc.

#### Custom TM Graphics
To create custom TM graphics:
1. Create your TM icon as a 24x24 pixel image
2. Convert to GBA format using the graphics tools
3. Add the data to `src/data/graphics/items.h`
4. Reference it in your TM's `iconPic` field in the JSON

### 3. Updating TM Lists

#### Mart Availability
Add TMs to shops by editing shop data files:

```c
// In shop data files
static const u16 sShopItems_TM_Shop[] =
{
    ITEM_TM_THUNDERBOLT,
    ITEM_TM_ICE_BEAM,
    ITEM_TM_YOUR_NEW_MOVE,  // Add your TM here
    ITEM_NONE
};
```

#### Game Corner Prizes
Add TMs as game corner prizes:

```c
// In game corner data
static const struct GameCornerPrize sGameCornerTMs[] = 
{
    {ITEM_TM_YOUR_NEW_MOVE, 4000},
    // Other prizes...
};
```

## Adding New HMs

### 1. Adding HM to JSON Configuration

Edit `src/data/tms_hms.json` to add your new HM:

```json
{
  "tms": [
    // TM definitions here
  ],
  "hms": [
    {
      "move": "CUT",
      "name": "HM01",
      "price": 0,
      "description": "Cuts down thin\ntrees and grass.",
      "importance": "I_REUSABLE_TMS",
      "iconPic": "gItemIcon_HM",
      "iconPalette": "gItemIconPalette_HM"
    },
    {
      "move": "FLY",
      "name": "HM02",
      "price": 0,
      "description": "Flies to anywhere\nyou've visited.",
      "importance": "I_REUSABLE_TMS",
      "iconPic": "gItemIcon_HM",
      "iconPalette": "gItemIconPalette_HM"
    },
    // ... existing HMs ...
    {
      "move": "YOUR_NEW_HM_MOVE",
      "name": "HM09",
      "price": 0,
      "description": "Teaches a Pokémon\nthe move Your New\nHM Move.",
      "importance": "I_REUSABLE_TMS",
      "iconPic": "gItemIcon_HM",
      "iconPalette": "gItemIconPalette_HM"
    }
  ]
}
```

### 2. Configuring HM Field Use

For HMs that provide field functionality, you'll need to implement the field use function:

```c
// In appropriate field move files
bool8 FieldMove_YourNewHMMove(void)
{
    // Implementation of the field move
    // Return TRUE if move was used successfully
    return FALSE;
}
```

### 3. Preventing HM Move Deletion

HM moves require special handling in the move deleter:

```c
// In move deleter code
if (IsMoveHM(moveId))
{
    // Prevent deletion or show special message
    return FALSE;
}
```

## Modifying Existing TMs/HMs

### Changing TM Move Assignments

To change which move a TM teaches, modify the `move` field in `src/data/tms_hms.json`:

```json
{
  "move": "MEGA_PUNCH"  // Changed from FOCUS_PUNCH
}
```

### Updating TM Prices

Modify the `price` field in the JSON:

```json
{
  "price": 5000  // Changed from 3000
}
```

### Changing TM Descriptions

Update the `description` field in the JSON:

```json
{
  "description": "Teaches a powerful\npunching move to\na Pokémon."
}
```

## Distribution and Availability

### NPCs Giving TMs

Create NPCs that give TMs as rewards:

```assembly
Route101_EventScript_TMGiver::
    checkflag FLAG_RECEIVED_TM_THUNDERBOLT
    goto_if_set Route101_EventScript_TMGiver_AlreadyGave
    msgbox Route101_Text_TMGiver_Offer, MSGBOX_NPC
    giveitem ITEM_TM_THUNDERBOLT
    goto_if_bag_full Route101_EventScript_TMGiver_BagFull
    setflag FLAG_RECEIVED_TM_THUNDERBOLT
    msgbox Route101_Text_TMGiver_GaveItem, MSGBOX_NPC
    end

Route101_Text_TMGiver_Offer:
    .string "You seem like a promising TRAINER.\n"
    .string "Take this TM!$"

Route101_Text_TMGiver_GaveItem:
    .string "That TM contains THUNDERBOLT!\n"
    .string "It's a powerful Electric-type move!$"
```

### Hidden TM Items

Place TMs as hidden items on maps:

```json
// In map JSON bg_events
{
  "type": "hidden_item",
  "x": 12,
  "y": 8,
  "elevation": 3,
  "item": "ITEM_TM_EARTHQUAKE",
  "flag": "FLAG_HIDDEN_ITEM_TM_EARTHQUAKE"
}
```

### Shop Integration

Add TMs to Poké Mart inventories:

```c
// Department store TM floor
static const u16 sDepartmentStore_TMFloor[] =
{
    ITEM_TM_FIRE_BLAST,
    ITEM_TM_THUNDER,
    ITEM_TM_BLIZZARD,
    ITEM_TM_HYPER_BEAM,
    ITEM_TM_YOUR_NEW_MOVE,
    ITEM_NONE
};
```

### Battle Frontier Prizes

Add TMs as Battle Frontier exchange prizes:

```c
static const struct BattleFrontierPrize sBattleFrontierTMs[] =
{
    {ITEM_TM_YOUR_NEW_MOVE, 48},  // 48 Battle Points
    // Other TMs...
};
```

## Pokémon Compatibility

### Species Learn Lists

Add TM/HM compatibility to Pokémon in their species data:

```c
// In Pokémon species data
static const u16 sPikachuTMHMLearnset[] =
{
    MOVE_THUNDERBOLT,
    MOVE_THUNDER,
    MOVE_DOUBLE_TEAM,
    MOVE_YOUR_NEW_MOVE,  // Add compatibility here
    MOVE_UNAVAILABLE,
};

// In species info structure
.teachableLearnset = sPikachuTMHMLearnset,
```

### Type-Based Compatibility

Many TMs follow type-based compatibility rules. Electric-type TMs typically work on Electric-type Pokémon, etc.

## Troubleshooting

### Common Issues

**TM doesn't appear in game:**
- Check that the TM entry is properly defined in `tms_hms.json`
- Verify all required fields are present (move, name, price, description, etc.)
- Ensure the TM is actually distributed somewhere (shop, NPC, etc.)

**TM teaches wrong move:**
- Check the `move` field in the JSON entry
- Verify move constants are spelled correctly
- Ensure there are no duplicate move assignments

**Pokémon can't learn TM:**
- Check the species' teachable learnset
- Verify move compatibility makes sense
- Ensure the move exists and is properly defined

**TM graphics issues:**
- Verify `iconPic` and `iconPalette` fields reference valid graphics
- Check that palette is appropriate for move type
- Ensure graphics data is included in build

**HM field move doesn't work:**
- Implement proper field use function
- Check that move is recognized as HM
- Verify field move logic is correct

### Debug Tips

1. **Test with common Pokémon** - Use Pokémon known to learn many TMs
2. **Check move data** - Ensure the move being taught actually exists
3. **Verify item pocket** - TMs/HMs should be in TM_HM pocket
4. **Use debug features** - Give yourself TMs directly to test
5. **Check Battle Frontier compatibility** - Some moves may be restricted

### Performance Notes

- Too many TMs can clutter inventories
- Consider organizing TMs by type or power level
- Rare/powerful TMs should be harder to obtain
- Balance TM availability with game progression

## Related Tutorials

- [How to Add New Moves](how_to_new_move.md) - Creating the moves TMs teach
- [Item System](item_system.md) - Understanding the broader item system
- [Shop Management](shop_system.md) - Adding TMs to shops
- [Pokémon Species](how_to_new_pokemon_1_6_0.md) - Adding TM compatibility

---

*TMs and HMs are powerful tools for player customization. Make them meaningful rewards for exploration and progression!*