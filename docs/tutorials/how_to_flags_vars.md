# Flags and Variables System

This tutorial will explain the flags and variables system in pokeemerald-expansion, which is essential for managing game state, tracking progress, and creating conditional logic in your ROM hack.

## Content
* [Quick Summary](#quick-summary)
* [Understanding Flags and Variables](#understanding-flags-and-variables)
* [Game Flags](#game-flags)
  * [1. What are Flags](#1-what-are-flags)
  * [2. Flag Types](#2-flag-types)
  * [3. Using Flags](#3-using-flags)
* [Game Variables](#game-variables)
  * [4. What are Variables](#4-what-are-variables)
  * [5. Variable Types](#5-variable-types)
  * [6. Using Variables](#6-using-variables)
* [Practical Applications](#practical-applications)
* [Advanced Usage](#advanced-usage)
* [Best Practices](#best-practices)

## Quick Summary

If you've done this before and just need a quick reference:

- **Flags**: Boolean values (TRUE/FALSE) for tracking binary states
- **Variables**: 16-bit integers (0-65535) for counting and complex states
- **Temporary flags/vars**: Reset every map transition
- **Permanent flags/vars**: Persist throughout the save file
- Use scripting commands: `setflag`, `clearflag`, `checkflag`, `setvar`, `addvar`, `checkvar`

## Understanding Flags and Variables

The pokeemerald-expansion engine uses two primary systems for tracking game state:

### Flags (Boolean Values)
- **Purpose**: Track binary states (on/off, true/false, happened/not happened)
- **Storage**: 1 bit per flag
- **Range**: Either set (TRUE) or unset (FALSE)
- **Examples**: "Player has Pokedex", "Defeated Gym Leader 1", "Saw cutscene"

### Variables (Integer Values)  
- **Purpose**: Store numeric values and complex states
- **Storage**: 16 bits per variable
- **Range**: 0 to 65,535 (unsigned 16-bit integers)
- **Examples**: Story progression stage, item quantities, counters

Both systems are essential for:
- **Story progression**: Tracking where the player is in the game
- **NPC behavior**: Controlling when NPCs appear and what they say
- **Event scripting**: Creating complex conditional logic
- **World state**: Managing map changes and availability

## Game Flags

### 1. What are Flags

Flags are binary switches that can be either **set** (TRUE) or **cleared** (FALSE). They're the simplest form of game state storage.

#### Flag Examples in Practice
```assembly
# Check if player has received the Pokedex
checkflag FLAG_RECEIVED_POKEDEX
goto_if_set Script_AlreadyHavePokedex
# Give Pokedex logic here
giveitem ITEM_POKEDEX
setflag FLAG_RECEIVED_POKEDEX
```

### 2. Flag Types

The flag system has several categories defined in `include/constants/flags.h`:

#### Temporary Flags (0x0 - 0x1F)
These are cleared every time you enter a new map:

```c
#define TEMP_FLAGS_START 0x0
#define FLAG_TEMP_1      (TEMP_FLAGS_START + 0x1)
#define FLAG_TEMP_2      (TEMP_FLAGS_START + 0x2)
// ...up to FLAG_TEMP_1F
```

**Use cases for temporary flags:**
- NPC dialogue variations within the same map visit
- Short-term event states that reset on map change
- Temporary puzzle states
- One-time map interactions per visit

#### Permanent Game Flags (0x20+)
These persist throughout the save file:

```c
// Story progression flags
#define FLAG_ADVENTURE_STARTED           0x860
#define FLAG_RECEIVED_POKEDEX            0x861
#define FLAG_DEFEATED_NORMAN             0x862

// Item received flags
#define FLAG_RECEIVED_RUNNING_SHOES      0x863
#define FLAG_RECEIVED_ITEMFINDER         0x864

// NPC interaction flags
#define FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE  0x865
#define FLAG_HIDE_ROUTE_101_BIRCH              0x866
```

#### Special Flag Categories

**Badge Flags:**
```c
#define FLAG_BADGE01_GET    0x867  // Stone Badge
#define FLAG_BADGE02_GET    0x868  // Knuckle Badge
// ...continuing through all 8 badges
```

**Trainer Defeat Flags:**
```c  
#define FLAG_DEFEATED_ROUTE_101_YOUNGSTER    0x900
#define FLAG_DEFEATED_ROUTE_102_LASS         0x901
// Individual flag for each trainer
```

**Hide/Show NPC Flags:**
```c
#define FLAG_HIDE_NPC_NAME               0x950
#define FLAG_SHOW_SPECIAL_NPC            0x951
```

### 3. Using Flags

#### Setting and Clearing Flags

**Assembly:**
```assembly
# Set a flag (make it TRUE)
setflag FLAG_RECEIVED_POKEDEX

# Clear a flag (make it FALSE)  
clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM

# Toggle a flag (flip its state)
toggleflag FLAG_TOGGLE_EXAMPLE
```

**Poryscript:**
```poryscript
// Set a flag (make it TRUE)
setflag(FLAG_RECEIVED_POKEDEX)

// Clear a flag (make it FALSE)  
clearflag(FLAG_HIDE_LITTLEROOT_TOWN_MOM)

// Toggle a flag (flip its state)
toggleflag(FLAG_TOGGLE_EXAMPLE)
```

#### Checking Flags

**Assembly:**
```assembly
# Check if flag is set
checkflag FLAG_DEFEATED_ROXANNE
goto_if_set Script_PostGymnBattle
goto_if_unset Script_PreGymBattle

# Multiple flag checks
checkflag FLAG_BADGE01_GET
goto_if_unset Script_NoBadge
checkflag FLAG_BADGE02_GET  
goto_if_unset Script_OneBadge
# Player has at least 2 badges...
```

**Poryscript:**
```poryscript
// Check if flag is set
if (flag(FLAG_DEFEATED_ROXANNE)) {
    // Post-gym battle logic
} else {
    // Pre-gym battle logic
}

// Multiple flag checks
if (!flag(FLAG_BADGE01_GET)) {
    // No badges logic
} elif (!flag(FLAG_BADGE02_GET)) {
    // One badge logic  
} else {
    // Player has at least 2 badges...
}
```

#### Common Flag Patterns

**Item Giving with Flag Protection:**

*Assembly:*
```assembly
Script_GivePotion::
    checkflag FLAG_RECEIVED_FREE_POTION
    goto_if_set Script_AlreadyReceived
    msgbox Text_OfferPotion, MSGBOX_NPC
    giveitem ITEM_POTION
    setflag FLAG_RECEIVED_FREE_POTION
    msgbox Text_GavePotion, MSGBOX_NPC
    end

Script_AlreadyReceived::
    msgbox Text_AlreadyGavePotion, MSGBOX_NPC
    end
```

*Poryscript:*
```poryscript
script Script_GivePotion {
    if (flag(FLAG_RECEIVED_FREE_POTION)) {
        msgbox("I already gave you a POTION!", MSGBOX_NPC)
    } else {
        msgbox("Here, take this POTION!", MSGBOX_NPC)
        giveitem(ITEM_POTION)
        setflag(FLAG_RECEIVED_FREE_POTION)
        msgbox("Use it well!", MSGBOX_NPC)
    }
}
```

**NPC Hide/Show Logic:**
```assembly
# In map JSON object_events:
{
  "graphics_id": "OBJ_EVENT_GFX_SCIENTIST_1",
  "x": 10, "y": 8, "elevation": 3,
  "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
  "script": "Lab_EventScript_Scientist",
  "flag": "FLAG_HIDE_SCIENTIST_AFTER_QUEST"
}

# When quest is complete:
setflag FLAG_HIDE_SCIENTIST_AFTER_QUEST  # Scientist disappears
```

## Game Variables

### 4. What are Variables

Variables store numeric values from 0 to 65,535 and are used for complex game state that can't be represented by simple TRUE/FALSE flags.

#### Variable Examples
```assembly
# Set story progression stage
setvar VAR_STORY_PROGRESSION, 3

# Increment a counter
addvar VAR_WILD_POKEMON_BATTLES, 1

# Check variable value
checkvar VAR_STORY_PROGRESSION
goto_if_eq 1, Script_EarlyGame
goto_if_eq 2, Script_MidGame  
goto_if_eq 3, Script_LateGame
```

### 5. Variable Types

Variables are defined in `include/constants/vars.h`:

#### Temporary Variables (0x4000-0x400F)
Reset every map transition:

```c
#define TEMP_VARS_START            0x4000
#define VAR_TEMP_0                 (TEMP_VARS_START + 0x0)
#define VAR_TEMP_1                 (TEMP_VARS_START + 0x1)
// ...up to VAR_TEMP_F
```

**Use cases:**
- Map-specific counters
- Temporary calculations
- Short-term puzzle states
- NPC interaction tracking per map visit

#### Object Graphics ID Variables (0x4010-0x401F)
Control NPC sprite appearance:

```c
#define VAR_OBJ_GFX_ID_0           0x4010
#define VAR_OBJ_GFX_ID_1           0x4011
// Used to dynamically change NPC sprites
```

#### Permanent Game Variables (0x4020+)
Persist throughout the save file:

```c
// Story and progression
#define VAR_LITTLEROOT_TOWN_STATE           0x4055
#define VAR_OLDALE_TOWN_STATE               0x4056
#define VAR_STORY_PROGRESSION               0x4057

// Counters and statistics  
#define VAR_POKEMON_CAUGHT                  0x4058
#define VAR_WILD_POKEMON_BATTLES           0x4059
#define VAR_TRAINER_BATTLES_WON             0x405A

// Game mechanics
#define VAR_REPEL_STEP_COUNT               0x405B
#define VAR_ICE_STEP_COUNT                 0x405C
```

### 6. Using Variables

#### Setting Variable Values

**Assembly:**
```assembly
# Set variable to specific value
setvar VAR_STORY_PROGRESSION, 5

# Add to variable (increment)
addvar VAR_POKEMON_CAUGHT, 1

# Subtract from variable
subvar VAR_REPEL_STEP_COUNT, 1

# Copy one variable to another
copyvar VAR_TEMP_0, VAR_STORY_PROGRESSION
```

**Poryscript:**
```poryscript
// Set variable to specific value
setvar(VAR_STORY_PROGRESSION, 5)

// Add to variable (increment)
addvar(VAR_POKEMON_CAUGHT, 1)

// Subtract from variable
subvar(VAR_REPEL_STEP_COUNT, 1)

// Copy one variable to another
setvar(VAR_TEMP_0, var(VAR_STORY_PROGRESSION))
```

#### Checking Variable Values  

**Assembly:**
```assembly
# Check if variable equals specific value
checkvar VAR_STORY_PROGRESSION
goto_if_eq 1, Script_StoryStage1
goto_if_ne 1, Script_NotStoryStage1

# Check if variable is greater/less than value
goto_if_gt 5, Script_HighValue      # Greater than 5
goto_if_lt 3, Script_LowValue       # Less than 3
goto_if_ge 10, Script_AtLeast10     # Greater than or equal to 10
goto_if_le 2, Script_AtMost2        # Less than or equal to 2
```

**Poryscript:**
```poryscript
// Check variable values with if statements
if (var(VAR_STORY_PROGRESSION) == 1) {
    // Story stage 1 logic
} elif (var(VAR_STORY_PROGRESSION) != 1) {
    // Not story stage 1 logic
}

// Comparison operators
if (var(VAR_STORY_PROGRESSION) > 5) {
    // High value logic
} elif (var(VAR_STORY_PROGRESSION) < 3) {
    // Low value logic
} elif (var(VAR_STORY_PROGRESSION) >= 10) {
    // At least 10 logic
} elif (var(VAR_STORY_PROGRESSION) <= 2) {
    // At most 2 logic
}
```

#### Variable Comparison with Other Variables
```assembly
# Compare two variables
checkvar VAR_TEMP_0
goto_if_eq VAR_TEMP_1, Script_VariablesEqual

# Mathematical operations
addvar VAR_TEMP_0, VAR_TEMP_1    # VAR_TEMP_0 += VAR_TEMP_1
subvar VAR_TEMP_0, VAR_TEMP_1    # VAR_TEMP_0 -= VAR_TEMP_1
```

## Practical Applications

### Story Progression Management

Use a main story progression variable to track game state:

**Assembly:**
```assembly
# Early in the game
setvar VAR_STORY_PROGRESSION, 1  # Got starter Pokemon

# After first gym
setvar VAR_STORY_PROGRESSION, 2  # Defeated first gym

# Mid-game
setvar VAR_STORY_PROGRESSION, 3  # Reached new city

# NPCs react based on story stage:
NPC_EventScript_ReactToStory::
    checkvar VAR_STORY_PROGRESSION
    goto_if_eq 1, NPC_Text_EarlyGame
    goto_if_eq 2, NPC_Text_AfterFirstGym  
    goto_if_eq 3, NPC_Text_MidGame
    msgbox NPC_Text_DefaultResponse, MSGBOX_NPC
    end
```

**Poryscript:**
```poryscript
// NPCs react based on story stage
script NPC_EventScript_ReactToStory {
    switch (var(VAR_STORY_PROGRESSION)) {
        case 1:
            msgbox("You just started your journey! How exciting!", MSGBOX_NPC)
        case 2:
            msgbox("I heard you defeated the first GYM LEADER!", MSGBOX_NPC)
        case 3:
            msgbox("Welcome to our city! You've come far!", MSGBOX_NPC)
        default:
            msgbox("Hello there, trainer!", MSGBOX_NPC)
    }
}
```

### Achievement and Counter Systems

Track player achievements and statistics:

**Assembly:**
```assembly
# Pokemon catching counter
Script_CaughtPokemon::
    addvar VAR_POKEMON_CAUGHT, 1
    checkvar VAR_POKEMON_CAUGHT
    goto_if_eq 10, Script_Caught10Pokemon
    goto_if_eq 50, Script_Caught50Pokemon
    goto_if_eq 150, Script_CaughtAllPokemon
    end

Script_Caught10Pokemon::
    msgbox Text_Caught10Pokemon, MSGBOX_NPC
    giveitem ITEM_GREAT_BALL, 5
    end
```

**Poryscript:**
```poryscript
// Pokemon catching counter
script Script_CaughtPokemon {
    addvar(VAR_POKEMON_CAUGHT, 1)
    var caught = var(VAR_POKEMON_CAUGHT)
    
    if (caught == 10) {
        msgbox("Congratulations! You've caught 10 POKéMON!", MSGBOX_NPC)
        giveitem(ITEM_GREAT_BALL, 5)
    } elif (caught == 50) {
        msgbox("Amazing! 50 POKéMON caught!", MSGBOX_NPC)
        giveitem(ITEM_ULTRA_BALL, 10)
    } elif (caught == 150) {
        msgbox("Incredible! You're a true POKéMON MASTER!", MSGBOX_NPC)
        giveitem(ITEM_MASTER_BALL, 1)
    }
}
```

### Complex Conditional Logic

Combine flags and variables for sophisticated behavior:

```assembly
Script_ComplexNPC::
    checkflag FLAG_DEFEATED_ELITE_FOUR
    goto_if_unset Script_NotChampion
    
    checkvar VAR_POKEMON_CAUGHT  
    goto_if_ge 100, Script_ExperiencedChampion
    goto Script_NewChampion

Script_ExperiencedChampion::
    msgbox Text_ImpressiveCollection, MSGBOX_NPC
    giveitem ITEM_MASTER_BALL
    end

Script_NewChampion::
    msgbox Text_CongratsChampion, MSGBOX_NPC
    end

Script_NotChampion::
    msgbox Text_KeepTraining, MSGBOX_NPC
    end
```

### Map State Management

Control map variations and accessibility:

```assembly
# Town state progression
Script_AdvanceTownState::
    checkvar VAR_HOMETOWN_STATE
    switch TVAR_TOWNSTATE
    case 0, Script_TownState0
    case 1, Script_TownState1  
    case 2, Script_TownState2
    
Script_TownState0::
    msgbox Text_TownPeaceful, MSGBOX_NPC
    end
    
Script_TownState1::
    msgbox Text_TownBusy, MSGBOX_NPC
    setvar VAR_HOMETOWN_STATE, 2
    setflag FLAG_SHOW_NEW_NPCS
    end

Script_TownState2::
    msgbox Text_TownThriving, MSGBOX_NPC
    end
```

## Advanced Usage

### Variable Arrays and Loops

Use temporary variables for calculations:

```assembly
Script_CalculateBonus::
    setvar VAR_TEMP_0, 0          # Initialize counter
    setvar VAR_TEMP_1, 0          # Initialize sum
    
Script_Loop::
    checkvar VAR_TEMP_0
    goto_if_ge 8, Script_EndLoop  # Loop 8 times
    
    # Add badge bonus if player has this badge
    addvar VAR_TEMP_2, FLAG_BADGE01_GET  
    addvar VAR_TEMP_2, VAR_TEMP_0        # Calculate flag offset
    checkflag VAR_TEMP_2
    goto_if_set Script_AddBonus
    goto Script_ContinueLoop
    
Script_AddBonus::
    addvar VAR_TEMP_1, 100        # Add 100 for each badge
    
Script_ContinueLoop::
    addvar VAR_TEMP_0, 1          # Increment counter
    goto Script_Loop
    
Script_EndLoop::
    # VAR_TEMP_1 now contains total badge bonus
    end
```

### Dynamic Object Graphics

Change NPC appearance based on variables:

```c
// In map JSON
{
  "graphics_id": "OBJ_EVENT_GFX_VAR_0",  # Uses VAR_OBJ_GFX_ID_0
  "x": 10, "y": 8, "elevation": 3,
  "script": "NPC_EventScript_ChangingSprite"
}
```

```assembly
# Change NPC sprite based on story progression
Script_SetNPCSprite::
    checkvar VAR_STORY_PROGRESSION
    goto_if_eq 1, Script_SetSprite1
    goto_if_eq 2, Script_SetSprite2
    goto_if_eq 3, Script_SetSprite3
    end

Script_SetSprite1::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
    end
    
Script_SetSprite2::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAN_1
    end
    
Script_SetSprite3::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN
    end
```

## Best Practices

### Flag Management

1. **Use descriptive names**: `FLAG_RECEIVED_SURF_HM` instead of `FLAG_MISC_001`
2. **Group related flags**: Keep story flags together, item flags together
3. **Document flag purposes**: Comment what each flag tracks
4. **Use appropriate flag types**: Temporary vs permanent based on usage

### Variable Management

1. **Initialize variables**: Always set starting values explicitly
2. **Check bounds**: Ensure variables don't overflow (max 65,535)  
3. **Use meaningful ranges**: 0-100 for percentages, 1-10 for stages
4. **Reset when appropriate**: Clear temporary variables when done

### Performance Optimization

1. **Minimize flag/variable checks**: Cache frequently checked values
2. **Use early returns**: Check most likely conditions first
3. **Group related checks**: Combine multiple flag checks when possible
4. **Avoid excessive temporary usage**: Reuse temporary slots

### Debugging and Testing

1. **Use debug commands** to set flags/variables during testing:
```assembly
#ifdef DEBUG
Script_DebugSetStory::
    setvar VAR_STORY_PROGRESSION, 5
    setflag FLAG_DEFEATED_ELITE_FOUR
    end
#endif
```

2. **Create debug displays** to show current flag/variable states
3. **Test edge cases**: What happens at variable limits?
4. **Verify save/load**: Ensure flags/variables persist correctly

## Related Tutorials

- [How to Add NPCs](how_to_add_npcs.md) - Using flags to control NPC behavior  
- [How to Add Maps](how_to_add_maps.md) - Map state management with variables
- [Scripting with Poryscript](how_to_poryscript.md) - Advanced scripting techniques
- [How to Add Trainers](how_to_add_trainers.md) - Trainer defeat flags

---

*Flags and variables are the foundation of game state management. Master them to create dynamic, responsive worlds that remember the player's actions and adapt accordingly!*