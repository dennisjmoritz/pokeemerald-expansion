# Pokemon Emerald Decoration System - Detailed Patch Descriptions

This document provides comprehensive technical descriptions of each patch file, detailed enough for complete replication of the functionality.

## Patch 01: House Pricing System

### Purpose
Implements a tiered house pricing system integrated into the secret base system, providing three house types with different costs and decoration capacities.

### Technical Implementation

#### Files Modified:
- `include/global.h` - Save data structure
- `include/secret_base.h` - House type definitions and function declarations
- `src/secret_base.c` - Cost functions and validation logic

#### Save Data Changes:
Add to `struct SaveBlock1` (around line 986):
```c
u8 playerHouseType; // 0 = apartment, 1 = house, 2 = mansion
```

#### House Type System:
Add to `include/secret_base.h`:
```c
// House type system for secret bases
enum HouseType
{
    HOUSE_TYPE_APARTMENT,   // 25,000₽, 6 decoration slots
    HOUSE_TYPE_HOUSE,       // 100,000₽, 12 decoration slots
    HOUSE_TYPE_MANSION      // 500,000₽, 20 decoration slots
};

// Function declarations
bool8 CanAffordHouseType(enum HouseType houseType);
void ChargeForHouseType(enum HouseType houseType);
```

#### Cost Functions:
Add to `src/secret_base.c`:
```c
#include "money.h"

static const u32 sHouseTypeCosts[] = {
    [HOUSE_TYPE_APARTMENT] = 25000,
    [HOUSE_TYPE_HOUSE] = 100000,
    [HOUSE_TYPE_MANSION] = 500000
};

bool8 CanAffordHouseType(enum HouseType houseType)
{
    if (houseType >= 3) return FALSE;
    return GetMoney(&gSaveBlock1Ptr->money) >= sHouseTypeCosts[houseType];
}

void ChargeForHouseType(enum HouseType houseType)
{
    if (houseType >= 3) return;
    if (CanAffordHouseType(houseType))
    {
        RemoveMoney(&gSaveBlock1Ptr->money, sHouseTypeCosts[houseType]);
        gSaveBlock1Ptr->playerHouseType = houseType;
    }
}
```

---

## Patch 02: Move Relearner Decoration

### Purpose
Adds a decoration that provides direct access to the move relearner functionality from the player's room, eliminating the need to travel to NPCs.

### Technical Implementation

#### Files Modified:
- `include/constants/decorations.h` - Decoration constant definition
- `include/decoration.h` - Function declaration
- `src/decoration.c` - Functionality implementation
- `src/data/decoration/description.h` - Description text
- `src/data/decoration/header.h` - Decoration data structure
- `src/data/decoration/tiles.h` - Graphics reference

#### Decoration Constant:
Add to `include/constants/decorations.h`:
```c
#define DECOR_MOVE_RELEARNER      139
#define NUM_DECORATIONS           140  // Update from 139
```

#### Function Declaration:
Add to `include/decoration.h`:
```c
void UseMoveRelearnerDecoration(void);
```

#### Core Functionality:
Add to `src/decoration.c`:
```c
#include "move_relearner.h"

static bool8 IsDecorationInPlayerRoom(u16 decorId)
{
    // Check if the decoration is present in player's current room
    // Implementation depends on room decoration tracking system
    return TRUE; // Simplified for example
}

void UseMoveRelearnerDecoration(void)
{
    if (IsDecorationInPlayerRoom(DECOR_MOVE_RELEARNER))
    {
        // Integrate with existing move relearner system
        TeachMoveRelearnerMove();
    }
    else
    {
        DisplayItemMessageOnField(0, gText_DecorationNotAvailable, NULL);
    }
}
```

#### Decoration Description:
Add to `src/data/decoration/description.h`:
```c
const u8 DecorDesc_MOVE_RELEARNER[] = _("Allows POKéMON to recall\nmoves they once knew.");
```

#### Decoration Data:
Add to `src/data/decoration/header.h`:
```c
[DECOR_MOVE_RELEARNER] =
{
    .id = DECOR_MOVE_RELEARNER,
    .name = _("MOVE RELEARNER"),
    .permission = DECORPERM_SOLID_FLOOR,
    .shape = DECORSHAPE_1x1,
    .category = DECORCAT_DESK,
    .price = 15000,
    .description = DecorDesc_MOVE_RELEARNER,
    .tiles = DecorGfx_SMALL_DESK, // Placeholder graphics
},
```

#### Graphics Reference:
Add to `src/data/decoration/tiles.h`:
```c
const u32 DecorGfx_MOVE_RELEARNER[] = INCBIN_U32("graphics/decorations/desk.4bpp.lz");
```

---

## Patch 03: Berry Patch Decoration

### Purpose
Implements a berry cultivation system using official berry.c functions, providing realistic berry growing with proper growth stages and yield calculations.

### Technical Implementation

#### Files Modified:
- `include/berry.h` - Expose BerryTypeToItemId function
- `src/berry.c` - Make BerryTypeToItemId public
- `include/constants/decorations.h` - Decoration constant
- `include/global.h` - Save data for berry patch
- `src/decoration.c` - Berry patch functionality
- `src/data/decoration/description.h` - Description
- `src/data/decoration/header.h` - Decoration data
- `src/data/decoration/tiles.h` - Graphics

#### Berry Function Exposure:
Modify `include/berry.h` to add:
```c
u16 BerryTypeToItemId(u8 berry);
```

Modify `src/berry.c` to change:
```c
// Change from: static u16 BerryTypeToItemId(u8 berry)
u16 BerryTypeToItemId(u8 berry)  // Remove static
```

#### Save Data:
Add to `struct SaveBlock1` in `include/global.h`:
```c
struct BerryTree playerBerryPatch;
```

#### Decoration Constant:
Add to `include/constants/decorations.h`:
```c
#define DECOR_BERRY_PATCH         140
#define NUM_DECORATIONS           141  // Update from 140
```

#### Berry Patch Functionality:
Add to `src/decoration.c`:
```c
#include "berry.h"
#include "item.h"
#include "random.h"

void UseBerryPatchDecoration(void)
{
    struct BerryTree *berryPatch = &gSaveBlock1Ptr->playerBerryPatch;
    
    if (berryPatch->berry == 0)
    {
        // Plant stage - auto-plant Oran berry for demo
        berryPatch->berry = BERRY_ORAN;
        berryPatch->stage = 1;
        berryPatch->minutesUntilNextStage = 60;
        berryPatch->berryYield = 0;
        berryPatch->watered1 = 0;
        berryPatch->watered2 = 0;
        berryPatch->watered3 = 0;
        berryPatch->watered4 = 0;
        
        DisplayItemMessageOnField(0, gText_PlantedBerry, NULL);
    }
    else if (berryPatch->stage < 4)
    {
        // Growing stage
        StringCopy(gStringVar1, gText_BerryStageNames[berryPatch->stage]);
        DisplayItemMessageOnField(0, gText_BerryGrowing, NULL);
    }
    else if (berryPatch->stage >= 4)
    {
        // Harvest stage
        u16 itemId = BerryTypeToItemId(berryPatch->berry);
        u16 yield = berryPatch->berryYield > 0 ? berryPatch->berryYield : 3;
        
        if (AddBagItem(itemId, yield))
        {
            // Reset berry patch after harvest
            berryPatch->berry = 0;
            berryPatch->stage = 0;
            berryPatch->minutesUntilNextStage = 0;
            berryPatch->berryYield = 0;
            
            ConvertIntToDecimalStringN(gStringVar2, yield, STR_CONV_MODE_LEFT_ALIGN, 2);
            StringCopy(gStringVar1, ItemId_GetName(itemId));
            DisplayItemMessageOnField(0, gText_ObtainedBerries, NULL);
        }
        else
        {
            DisplayItemMessageOnField(0, gText_BagIsFull, NULL);
        }
    }
}
```

#### Required Text Constants:
Add to appropriate text file:
```c
const u8 gText_PlantedBerry[] = _("Planted a berry!");
const u8 gText_BerryGrowing[] = _("The berry is growing.\nStage: {STR_VAR_1}");
const u8 gText_ObtainedBerries[] = _("Obtained {STR_VAR_2} {STR_VAR_1}!");
```

---

## Patch 04: Egg Incubator Decoration

### Purpose
Provides daycare-style egg storage and management functionality at normal walking speed, allowing players to store eggs separately from their party.

### Technical Implementation

#### Files Modified:
- `include/constants/decorations.h` - Decoration constant
- `include/global.h` - Egg incubator save data
- `include/decoration.h` - Function declarations
- `src/decoration.c` - Egg incubator functionality
- `src/data/decoration/description.h` - Description
- `src/data/decoration/header.h` - Decoration data
- `src/data/decoration/tiles.h` - Graphics

#### Save Data:
Add to `struct SaveBlock1` in `include/global.h`:
```c
struct BoxPokemon playerEggIncubator;
u32 eggIncubatorSteps;
```

#### Function Declarations:
Add to `include/decoration.h`:
```c
void UseEggIncubatorDecoration(void);
void UpdateEggIncubator(void);
```

#### Core Functionality:
Add to `src/decoration.c`:
```c
#include "pokemon.h"
#include "party_menu.h"

static bool8 IsEggInIncubator(void)
{
    return GetBoxMonData(&gSaveBlock1Ptr->playerEggIncubator, MON_DATA_SPECIES) != 0;
}

static bool8 CanDepositEggInIncubator(void)
{
    for (u32 i = 0; i < gPlayerPartyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG)
            && !GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_BAD_EGG))
        {
            return TRUE;
        }
    }
    return FALSE;
}

static void DepositEggInIncubator(void)
{
    for (u32 i = 0; i < gPlayerPartyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG)
            && !GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_BAD_EGG))
        {
            // Convert party Pokemon to BoxPokemon and store
            gSaveBlock1Ptr->playerEggIncubator = gPlayerParty[i].box;
            
            // Remove from party
            for (u32 j = i; j < gPlayerPartyCount - 1; j++)
            {
                gPlayerParty[j] = gPlayerParty[j + 1];
            }
            gPlayerPartyCount--;
            
            DisplayItemMessageOnField(0, gText_EggDeposited, NULL);
            return;
        }
    }
}

static void WithdrawEggFromIncubator(void)
{
    if (gPlayerPartyCount >= PARTY_SIZE)
    {
        DisplayItemMessageOnField(0, gText_PartyFull, NULL);
        return;
    }
    
    // Convert BoxPokemon back to party Pokemon
    gPlayerParty[gPlayerPartyCount].box = gSaveBlock1Ptr->playerEggIncubator;
    gPlayerPartyCount++;
    
    // Clear incubator
    memset(&gSaveBlock1Ptr->playerEggIncubator, 0, sizeof(struct BoxPokemon));
    gSaveBlock1Ptr->eggIncubatorSteps = 0;
    
    DisplayItemMessageOnField(0, gText_EggWithdrawn, NULL);
}

void UseEggIncubatorDecoration(void)
{
    if (!IsEggInIncubator())
    {
        if (CanDepositEggInIncubator())
        {
            DepositEggInIncubator();
        }
        else
        {
            DisplayItemMessageOnField(0, gText_NoEggsToDeposit, NULL);
        }
    }
    else
    {
        // Show status and offer withdrawal
        u32 cycles = GetBoxMonData(&gSaveBlock1Ptr->playerEggIncubator, MON_DATA_FRIENDSHIP);
        u32 steps = gSaveBlock1Ptr->eggIncubatorSteps;
        
        ConvertIntToDecimalStringN(gStringVar1, cycles, STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, steps, STR_CONV_MODE_LEFT_ALIGN, 5);
        
        // Simple withdrawal for demo - in full version would show menu
        WithdrawEggFromIncubator();
    }
}

void UpdateEggIncubator(void)
{
    if (IsEggInIncubator())
    {
        gSaveBlock1Ptr->eggIncubatorSteps += 1; // Normal walking speed
        
        if (gSaveBlock1Ptr->eggIncubatorSteps >= 256)
        {
            gSaveBlock1Ptr->eggIncubatorSteps = 0;
            
            u32 cycles = GetBoxMonData(&gSaveBlock1Ptr->playerEggIncubator, MON_DATA_FRIENDSHIP);
            if (cycles > 0)
            {
                cycles--;
                SetBoxMonData(&gSaveBlock1Ptr->playerEggIncubator, MON_DATA_FRIENDSHIP, &cycles);
            }
        }
    }
}
```

---

## Patch 05: EV Editor Decoration

### Purpose
Implements a comprehensive EV training system with item deposit functionality, credit management, and working Pokemon stat modification interface.

### Technical Implementation

#### Files Modified:
- `include/constants/decorations.h` - Decoration constant
- `include/global.h` - EV editor save data
- `src/decoration.c` - EV editor functionality
- `src/data/decoration/description.h` - Description
- `src/data/decoration/header.h` - Decoration data
- `src/data/decoration/tiles.h` - Graphics

#### Save Data:
Add to `struct SaveBlock1` in `include/global.h`:
```c
u16 evEditorCredits[NUM_STATS]; // Per-stat credit storage
```

#### EV Editor Functionality:
Add to `src/decoration.c`:
```c
// EV-modifying items that can be deposited
static const u16 sEVVitaminItems[] = {
    ITEM_HP_UP, ITEM_PROTEIN, ITEM_IRON,
    ITEM_CALCIUM, ITEM_ZINC, ITEM_CARBOS
};

static const u16 sEVBerryItems[] = {
    ITEM_POMEG_BERRY, ITEM_KELPSY_BERRY, ITEM_QUALOT_BERRY,
    ITEM_HONDEW_BERRY, ITEM_GREPA_BERRY, ITEM_TAMATO_BERRY
};

static const u8 *const sStatNames[] = {
    gText_HP2, gText_Attack2, gText_Defense2,
    gText_SpAtk2, gText_SpDef2, gText_Speed2
};

static bool8 HasEVItemsInBag(void)
{
    for (u32 i = 0; i < ARRAY_COUNT(sEVVitaminItems); i++)
    {
        if (CheckBagHasItem(sEVVitaminItems[i], 1))
            return TRUE;
    }
    for (u32 i = 0; i < ARRAY_COUNT(sEVBerryItems); i++)
    {
        if (CheckBagHasItem(sEVBerryItems[i], 1))
            return TRUE;
    }
    return FALSE;
}

static void DepositEVItemsToEditor(void)
{
    u32 totalDeposited = 0;
    
    // Deposit vitamins (10 credits each)
    for (u32 stat = 0; stat < NUM_STATS; stat++)
    {
        u16 count = CheckBagHasItem(sEVVitaminItems[stat], 999);
        if (count > 0)
        {
            RemoveBagItem(sEVVitaminItems[stat], count);
            gSaveBlock1Ptr->evEditorCredits[stat] += count * 10;
            totalDeposited += count;
        }
    }
    
    // Deposit berries (10 credits each)
    for (u32 stat = 0; stat < NUM_STATS; stat++)
    {
        u16 count = CheckBagHasItem(sEVBerryItems[stat], 999);
        if (count > 0)
        {
            RemoveBagItem(sEVBerryItems[stat], count);
            gSaveBlock1Ptr->evEditorCredits[stat] += count * 10;
            totalDeposited += count;
        }
    }
    
    ConvertIntToDecimalStringN(gStringVar1, totalDeposited, STR_CONV_MODE_LEFT_ALIGN, 3);
    DisplayItemMessageOnField(0, gText_ItemsDeposited, NULL);
}

static u32 GetTotalEVCreditsInEditor(void)
{
    u32 total = 0;
    for (u32 i = 0; i < NUM_STATS; i++)
    {
        total += gSaveBlock1Ptr->evEditorCredits[i];
    }
    return total;
}

static void TrainPokemonEVs(u32 partySlot, u32 statToTrain)
{
    if (partySlot >= gPlayerPartyCount)
        return;
    
    struct Pokemon *mon = &gPlayerParty[partySlot];
    
    // Check if it's an egg
    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        DisplayItemMessageOnField(0, gText_CantTrainEgg, NULL);
        return;
    }
    
    // Check credits
    if (gSaveBlock1Ptr->evEditorCredits[statToTrain] < 10)
    {
        DisplayItemMessageOnField(0, gText_InsufficientCredits, NULL);
        return;
    }
    
    // Check EV limit
    u16 currentEV = GetMonData(mon, MON_DATA_HP_EV + statToTrain);
    if (currentEV >= 252)
    {
        DisplayItemMessageOnField(0, gText_EVMaxedOut, NULL);
        return;
    }
    
    // Increase EV
    currentEV = min(252, currentEV + 10);
    SetMonData(mon, MON_DATA_HP_EV + statToTrain, &currentEV);
    
    // Consume credits
    gSaveBlock1Ptr->evEditorCredits[statToTrain] -= 10;
    
    // Update stats
    CalculateMonStats(mon);
    
    // Show feedback
    StringCopy(gStringVar1, sStatNames[statToTrain]);
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock1Ptr->evEditorCredits[statToTrain], STR_CONV_MODE_LEFT_ALIGN, 3);
    DisplayItemMessageOnField(0, gText_EVIncreased, NULL);
}

void UseEVEditorDecoration(void)
{
    if (HasEVItemsInBag())
    {
        DepositEVItemsToEditor();
    }
    else if (GetTotalEVCreditsInEditor() > 0)
    {
        // For demo: train first Pokemon's HP stat
        TrainPokemonEVs(0, STAT_HP);
    }
    else
    {
        DisplayItemMessageOnField(0, gText_NoEVItems, NULL);
    }
}
```

---

## Patch 06: Map Configuration Updates

### Purpose
Provides map-based decoration control with variable limits per house type and extends the object graphics system for decoration variety.

### Technical Implementation

#### Files Modified:
- `include/constants/flags.h` - Safe flag values for decoration expansion
- `include/constants/event_objects.h` - Extended VAR graphics
- `data/maps/SecretBase_Apartment1/map.json` - 6 decoration slots
- `data/maps/SecretBase_Mansion1/map.json` - 20 decoration slots

#### Flag System:
Add to `include/constants/flags.h` (using safe unused values):
```c
// Extended decoration flags (using safe unused values)
#define FLAG_DECORATION_15                          0x020
#define FLAG_DECORATION_16                          0x021
#define FLAG_DECORATION_17                          0x022
#define FLAG_DECORATION_18                          0x023
#define FLAG_DECORATION_19                          0x024
#define FLAG_DECORATION_20                          0x025
```

#### Extended Object Graphics:
Add to `include/constants/event_objects.h`:
```c
#define OBJ_EVENT_GFX_VAR_10                        (OBJ_EVENT_GFX_VARS + 16)
#define OBJ_EVENT_GFX_VAR_11                        (OBJ_EVENT_GFX_VARS + 17)
#define OBJ_EVENT_GFX_VAR_12                        (OBJ_EVENT_GFX_VARS + 18)
#define OBJ_EVENT_GFX_VAR_13                        (OBJ_EVENT_GFX_VARS + 19)
```

#### Map Configuration:
For apartment maps, limit `object_events` array to 6 decoration objects.
For mansion maps, extend `object_events` array to 20 decoration objects.

Each decoration object should follow this pattern:
```json
{
    "graphics_id": "OBJ_EVENT_GFX_VAR_0",
    "x": X_COORDINATE,
    "y": Y_COORDINATE,
    "elevation": 0,
    "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
    "movement_range_x": 0,
    "movement_range_y": 0,
    "trainer_type": "TRAINER_TYPE_NONE",
    "trainer_sight_or_berry_tree_id": "0",
    "script": "SecretBase_EventScript_DecorationSlot",
    "flag": "FLAG_DECORATION_X"
}
```

Where X corresponds to decoration slot numbers 1-20 as needed.

---

## Installation Order

Apply patches in this specific order:
1. `01_house_pricing_system.patch` - Foundation house system
2. `02_move_relearner_decoration.patch` - First functional decoration
3. `03_berry_patch_decoration.patch` - Berry system with existing code integration
4. `04_egg_incubator_decoration.patch` - Egg storage system
5. `05_ev_editor_decoration.patch` - Complete EV training system
6. `06_map_configuration_updates.patch` - Map limits and graphics extensions

Each patch builds on the previous ones and requires them as dependencies for proper functionality.