# How to Change Character Creation

This tutorial will guide you through customizing the character creation and new game setup process in your pokeemerald-expansion ROM hack. This includes modifying player sprites, starting location, initial items, and the overall new game experience.

## Content
* [Quick Summary](#quick-summary)
* [Understanding Character Creation](#understanding-character-creation)
* [Player Character Customization](#player-character-customization)
  * [1. Player Sprites](#1-player-sprites)
  * [2. Character Selection](#2-character-selection)
  * [3. Naming System](#3-naming-system)
* [Starting Game Setup](#starting-game-setup)
  * [4. Starting Location](#4-starting-location)
  * [5. Initial Items](#5-initial-items)
  * [6. Starting Pokémon](#6-starting-pokémon)
* [Advanced Customization](#advanced-customization)
* [Troubleshooting](#troubleshooting)

## Quick Summary

If you've done this before and just need a quick reference:

1. Modify player sprites in `graphics/players/`
2. Edit character creation logic in `src/new_game.c`
3. Change starting location and items in new game setup
4. Update player constants in header files
5. Test character creation flow
6. Build and verify changes

## Understanding Character Creation

The character creation system in pokeemerald-expansion handles:

- **Player appearance**: Gender selection and sprite assignment
- **Character naming**: Player name input and validation
- **Starting setup**: Initial location, items, and Pokémon
- **Save initialization**: Setting up the new save file
- **Story flags**: Initial story state and progression

The main logic is contained in `src/new_game.c` with support from various data files and graphics.

## Player Character Customization

### 1. Player Sprites

The player character sprites define how your character appears throughout the game.

#### Overworld Sprites
Player overworld sprites are located in `graphics/players/`:

```
graphics/players/
├── brendan/               # Male player sprites
│   ├── walking.png       # Walking animation frames
│   ├── running.png       # Running animation frames
│   ├── biking.png        # Biking sprites
│   └── surfing.png       # Surfing sprites
└── may/                   # Female player sprites
    ├── walking.png
    ├── running.png
    ├── biking.png
    └── surfing.png
```

To add custom player sprites:
1. Create new sprite sheets following the existing format
2. Update the sprite references in the graphics loading code
3. Ensure all animation frames are properly aligned

#### Battle Sprites (Back Sprites)
The player's back sprite appears during battles. See the [trainer back sprite tutorial](how_to_trainer_back_pic.md) for detailed instructions.

### 2. Character Selection

The gender selection process can be customized in `src/new_game.c`:

#### Adding Custom Character Options

```c
// Define new character constants
#define PLAYER_CUSTOM_MALE   2
#define PLAYER_CUSTOM_FEMALE 3

// Update character selection function
static void HandleCharacterSelection(void)
{
    switch (gSaveBlock2Ptr->playerGender)
    {
        case MALE:
            SetPlayerSprite(OBJ_EVENT_GFX_BRENDAN_NORMAL);
            break;
        case FEMALE:
            SetPlayerSprite(OBJ_EVENT_GFX_MAY_NORMAL);
            break;
        case PLAYER_CUSTOM_MALE:
            SetPlayerSprite(OBJ_EVENT_GFX_YOUR_CUSTOM_MALE);
            break;
        case PLAYER_CUSTOM_FEMALE:
            SetPlayerSprite(OBJ_EVENT_GFX_YOUR_CUSTOM_FEMALE);
            break;
    }
}
```

#### Character Selection Menu
Create a custom character selection interface:

```c
static void ShowCharacterSelectionMenu(void)
{
    // Display character options
    DisplayCharacterOption(0, "Male Hero");
    DisplayCharacterOption(1, "Female Hero");
    DisplayCharacterOption(2, "Custom Male");
    DisplayCharacterOption(3, "Custom Female");
    
    // Handle player selection
    CreateTask(Task_HandleCharacterInput, 0);
}

static void Task_HandleCharacterInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        u8 selection = GetMenuCursorPos();
        gSaveBlock2Ptr->playerGender = selection;
        SetupPlayerCharacter();
        DestroyTask(taskId);
    }
}
```

### 3. Naming System

Customize the player naming process:

#### Default Names
Provide default name options:

```c
static const u8 *sDefaultPlayerNames[] = 
{
    [MALE] = _("ALEX"),
    [FEMALE] = _("SARAH"),
    [PLAYER_CUSTOM_MALE] = _("CUSTOM"),
    [PLAYER_CUSTOM_FEMALE] = _("HERO"),
};
```

#### Name Input Validation
Add custom validation rules:

```c
static bool8 ValidatePlayerName(const u8 *name)
{
    // Check minimum length
    if (StringLength(name) < 2)
        return FALSE;
    
    // Check for forbidden words
    if (IsForbiddenName(name))
        return FALSE;
    
    // Check character set
    if (!IsValidCharacterSet(name))
        return FALSE;
    
    return TRUE;
}
```

## Starting Game Setup

### 4. Starting Location

Change where the player begins their journey:

#### Setting Initial Map
Modify the starting location in `src/new_game.c`:

```c
void SetInitialPlayerLocation(void)
{
    // Change starting map and position
    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(YOUR_STARTING_MAP);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(YOUR_STARTING_MAP);
    gSaveBlock1Ptr->location.x = 10;  // Starting X coordinate
    gSaveBlock1Ptr->location.y = 8;   // Starting Y coordinate
    gSaveBlock1Ptr->location.elevation = 3;
}
```

#### Story State Initialization
Set initial story flags and variables:

```c
void InitializeStoryState(void)
{
    // Set starting story flags
    FlagSet(FLAG_ADVENTURE_STARTED);
    FlagClear(FLAG_HIDE_PLAYER_HOUSE_DAD);  // Show/hide NPCs as needed
    
    // Initialize story variables
    VarSet(VAR_STORY_PROGRESSION, 1);
    VarSet(VAR_STARTING_LOCATION, YOUR_TOWN_ID);
}
```

### 5. Initial Items

Configure what items the player starts with:

#### Starting Bag Contents
Edit the initial item setup:

```c
void GiveInitialItems(void)
{
    // Basic starting items
    AddBagItem(ITEM_POTION, 5);
    AddBagItem(ITEM_POKEBALL, 10);
    
    // Key items
    AddBagItem(ITEM_TOWN_MAP, 1);
    AddBagItem(ITEM_POKEDEX, 1);
    
    // Starting money
    SetMoney(&gSaveBlock1Ptr->money, 5000);
    
    // Optional: Give starter items based on character choice
    switch (gSaveBlock2Ptr->playerGender)
    {
        case MALE:
            AddBagItem(ITEM_ORAN_BERRY, 3);
            break;
        case FEMALE:
            AddBagItem(ITEM_PECHA_BERRY, 3);
            break;
    }
}
```

#### Starting PC Contents
Set up the PC storage system:

```c
void InitializePlayerPC(void)
{
    // Initialize PC storage
    InitializePokemonStorageSystem();
    
    // Add starting items to PC
    AddPCItem(ITEM_RARE_CANDY, 1);
    AddPCItem(ITEM_TM01, 1);
}
```

### 6. Starting Pokémon

Customize the starter Pokémon system:

#### Custom Starter Selection
Replace the traditional starter choice:

```c
static const u16 sCustomStarterPokemon[] =
{
    SPECIES_YOUR_STARTER_1,
    SPECIES_YOUR_STARTER_2,
    SPECIES_YOUR_STARTER_3,
    SPECIES_YOUR_STARTER_4,  // Optional fourth starter
};

void ShowStarterSelection(void)
{
    u8 i;
    
    for (i = 0; i < ARRAY_COUNT(sCustomStarterPokemon); i++)
    {
        CreateStarterSelectionSprite(sCustomStarterPokemon[i], i);
    }
    
    DisplayStarterInfo();
}
```

#### Starter Pokémon Data
Configure the starter Pokémon properties:

```c
void CreateStarterPokemon(u16 species, u8 slot)
{
    struct Pokemon *pokemon = &gPlayerParty[slot];
    
    // Create the Pokémon
    CreateMon(pokemon, species, 5, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
    
    // Custom starting moves
    switch (species)
    {
        case SPECIES_YOUR_STARTER_1:
            SetMonMoveSlot(pokemon, MOVE_CUSTOM_MOVE_1, 0);
            break;
        case SPECIES_YOUR_STARTER_2:
            SetMonMoveSlot(pokemon, MOVE_CUSTOM_MOVE_2, 0);
            break;
    }
    
    // Set friendship and other properties
    SetMonData(pokemon, MON_DATA_FRIENDSHIP, &gSpeciesInfo[species].friendship);
    
    // Give held item
    SetMonData(pokemon, MON_DATA_HELD_ITEM, &(u16){ITEM_ORAN_BERRY});
}
```

## Advanced Customization

### Multiple Save File Support
Allow players to have different character types per save:

```c
struct SaveBlock2
{
    // Add custom fields
    u8 characterType;
    u8 startingRegion;
    u16 customFlags;
    // ... existing fields
};

void InitializeSaveFile(u8 characterType)
{
    gSaveBlock2Ptr->characterType = characterType;
    
    switch (characterType)
    {
        case CHARACTER_TRADITIONAL:
            SetupTraditionalStart();
            break;
        case CHARACTER_EXPERIENCED:
            SetupExperiencedStart();
            break;
        case CHARACTER_CUSTOM:
            SetupCustomStart();
            break;
    }
}
```

### Dynamic Starting Stats
Adjust starting stats based on character choice:

```c
void ApplyCharacterBonuses(void)
{
    switch (gSaveBlock2Ptr->playerGender)
    {
        case MALE:
            // Bonus items for male character
            AddBagItem(ITEM_ATTACK_UP, 1);
            break;
        case FEMALE:
            // Bonus items for female character  
            AddBagItem(ITEM_DEFENSE_UP, 1);
            break;
    }
}
```

### Custom Intro Sequence
Link character creation to custom intro:

```c
void StartNewGameSequence(void)
{
    // Play custom intro based on character
    switch (gSaveBlock2Ptr->characterType)
    {
        case CHARACTER_HERO:
            PlayIntroSequence(INTRO_HERO);
            break;
        case CHARACTER_RIVAL:
            PlayIntroSequence(INTRO_RIVAL);
            break;
    }
    
    // Proceed to character setup
    CreateTask(Task_CharacterCreation, 0);
}
```

## Troubleshooting

### Common Issues

**Character sprites not appearing:**
- Check sprite file paths and names
- Verify graphics are properly included in build
- Ensure sprite constants are defined correctly

**Starting location problems:**
- Verify map constants are correct
- Check coordinates are within map bounds
- Ensure starting map has proper player spawn point

**Item giving failures:**
- Check item constants are valid
- Verify bag space availability
- Ensure item giving functions are called in correct order

**Save corruption:**
- Initialize all save data properly
- Don't modify save structure without migration
- Test save/load functionality thoroughly

### Debug Tips

1. **Log character creation steps**:
```c
#ifdef DEBUG
    ConsolePrint("Character creation step: %d", step);
    ConsolePrint("Selected gender: %d", gSaveBlock2Ptr->playerGender);
#endif
```

2. **Test different character combinations** thoroughly

3. **Verify save file integrity** after character creation

4. **Check memory usage** during character creation process

### Testing Checklist

- [ ] All character options work correctly
- [ ] Starting location is accessible
- [ ] Initial items are given properly
- [ ] Starter Pokémon are created correctly
- [ ] Save/load functions work
- [ ] Story progression flows naturally
- [ ] Graphics display properly
- [ ] No memory leaks or crashes

## Related Tutorials

- [How to Add Trainer Sprites](how_to_trainer_back_pic.md) - Custom player battle sprites
- [How to Change the Intro](how_to_change_intro.md) - Customizing opening sequence
- [How to Add Maps](how_to_add_maps.md) - Creating starting areas
- [Flags and Variables](how_to_flags_vars.md) - Managing game state

---

*Character creation is the player's first interaction with your game. Make it memorable and set the tone for their adventure!*