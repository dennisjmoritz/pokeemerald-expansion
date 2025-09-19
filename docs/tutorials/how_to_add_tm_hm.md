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

1. Add move to TM/HM list in `include/constants/tms_hms.h`
2. Update item constants if needed
3. Add TM/HM description and graphics
4. Update Pokémon learnset compatibility
5. Place TM/HM in world (shops, NPCs, hidden items)
6. Test functionality

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

- `include/constants/tms_hms.h`: Defines which moves are TMs/HMs
- `include/constants/items.h`: TM/HM item constants  
- `src/data/items.h`: TM/HM item data (descriptions, prices, etc.)
- `src/data/graphics/items.h`: TM/HM graphics and icons
- Move compatibility in Pokémon species data
- Distribution through shops, NPCs, and world placement

### TM/HM Numbering

TMs are typically numbered 01-99+ while HMs use 01-08. The system automatically maps these numbers to specific moves based on the definitions in `tms_hms.h`.

## Adding New TMs

### 1. Adding TM to Constants

Edit `include/constants/tms_hms.h` to add your new TM move:

```c
#define FOREACH_TM(F) \
    F(FOCUS_PUNCH) \
    F(DRAGON_CLAW) \
    F(WATER_PULSE) \
    F(CALM_MIND) \
    /* ... existing TMs ... */ \
    F(YOUR_NEW_MOVE) \      // Add your move here
    F(ANOTHER_NEW_MOVE)     // Another example
```

The system will automatically assign TM numbers based on the order in this list.

### 2. Configuring TM Data

The TM items are automatically generated based on the constants. However, you may need to add specific item data in `src/data/items.h`:

```c
[ITEM_TM_YOUR_NEW_MOVE] =
{
    .name = ITEM_NAME("TM95"),
    .pluralName = ITEM_PLURAL_NAME("TM95s"),
    .price = 3000,
    .description = COMPOUND_STRING(
        "Teaches a Pokémon\n"
        "the move Your New\n"
        "Move. Single use."),
    .pocket = POCKET_TM_HM,
    .type = ITEM_USE_PARTY_MENU,
    .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    .secondaryId = ITEM_TM_YOUR_NEW_MOVE - ITEM_TM01 + 1,
    .iconPic = gItemIcon_TM,
    .iconPalette = gItemIconPalette_TMNormal,
},
```

### 3. Adding TM Graphics

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
4. Reference it in your item data

### 4. Updating TM Lists

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

### 1. Adding HM to Constants

Edit `include/constants/tms_hms.h`:

```c
#define FOREACH_HM(F) \
    F(CUT) \
    F(FLY) \
    F(SURF) \
    F(STRENGTH) \
    F(FLASH) \
    F(ROCK_SMASH) \
    F(WATERFALL) \
    F(DIVE) \
    F(YOUR_NEW_HM_MOVE)    // Add your HM here
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

### 3. HM Item Data

```c
[ITEM_HM_YOUR_NEW_MOVE] =
{
    .name = ITEM_NAME("HM09"),
    .pluralName = ITEM_PLURAL_NAME("HM09s"),
    .price = 0,  // HMs are usually not sold
    .description = COMPOUND_STRING(
        "Teaches a Pokémon\n"
        "the move Your New\n"
        "HM Move."),
    .pocket = POCKET_TM_HM,
    .type = ITEM_USE_PARTY_MENU,
    .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    .secondaryId = ITEM_HM_YOUR_NEW_MOVE - ITEM_HM01 + 1,
    .iconPic = gItemIcon_HM,
    .iconPalette = gItemIconPalette_HM,
},
```

### 4. Preventing HM Move Deletion

HM moves require special handling in the move deleter:

```c
// In move deleter code
if (IsHMMove(moveId))
{
    // Prevent deletion or show special message
    return FALSE;
}
```

## Modifying Existing TMs/HMs

### Changing TM Move Assignments

To change which move a TM teaches, simply modify `include/constants/tms_hms.h`:

```c
// Change TM01 from Focus Punch to Mega Punch
#define FOREACH_TM(F) \
    F(MEGA_PUNCH) \    // Was F(FOCUS_PUNCH)
    F(DRAGON_CLAW) \
    // ... rest unchanged
```

### Updating TM Prices

Modify the price in the item data:

```c
[ITEM_TM01] =
{
    // ... other fields ...
    .price = 5000,  // Changed from 3000
    // ... rest unchanged
},
```

### Changing TM Descriptions

Update the description text:

```c
[ITEM_TM01] =
{
    // ... other fields ...
    .description = COMPOUND_STRING(
        "Teaches a powerful\n"
        "punching move to\n"
        "a Pokémon."),
    // ... rest unchanged
},
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
- Check that the TM constant is properly defined
- Verify the item data includes all required fields
- Ensure the TM is actually distributed somewhere (shop, NPC, etc.)

**TM teaches wrong move:**
- Check the order in `tms_hms.h` FOREACH_TM list
- Verify move constants are spelled correctly
- Ensure there are no duplicate entries

**Pokémon can't learn TM:**
- Check the species' teachable learnset
- Verify move compatibility makes sense
- Ensure the move exists and is properly defined

**TM graphics issues:**
- Verify icon graphics are properly referenced
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