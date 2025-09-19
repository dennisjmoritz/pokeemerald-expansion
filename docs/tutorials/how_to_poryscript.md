# Scripting with Poryscript

This tutorial will introduce you to Poryscript, a high-level scripting language that compiles to pokeemerald-expansion's native scripting format. Poryscript provides modern programming features while maintaining compatibility with the existing scripting system.

## Content
* [Quick Summary](#quick-summary)
* [What is Poryscript](#what-is-poryscript)
* [Setting Up Poryscript](#setting-up-poryscript)
* [Basic Poryscript Syntax](#basic-poryscript-syntax)
  * [1. Variables and Constants](#1-variables-and-constants)
  * [2. Control Flow](#2-control-flow)
  * [3. Functions and Scripts](#3-functions-and-scripts)
* [Advanced Features](#advanced-features)
* [Converting Existing Scripts](#converting-existing-scripts)
* [Best Practices](#best-practices)
* [Troubleshooting](#troubleshooting)

## Quick Summary

If you're already familiar with programming and just need the basics:

1. Poryscript is a higher-level language that compiles to pokeemerald assembly scripts
2. Uses modern syntax with variables, functions, and control structures
3. Files use `.pory` extension and compile to `.inc` files
4. Provides cleaner, more maintainable code than raw assembly scripting
5. Fully compatible with existing pokeemerald-expansion features
6. Install Poryscript compiler and integrate with your build process

## What is Poryscript

Poryscript is a domain-specific programming language designed specifically for Pokémon ROM hacking. It provides:

### Key Benefits
- **Readable syntax**: Clean, modern programming constructs
- **Variable management**: Automatic temporary variable allocation
- **Error checking**: Compile-time validation of scripts
- **Maintainability**: Easier to update and debug than assembly
- **Compatibility**: Compiles to standard pokeemerald assembly

### Comparison: Assembly vs Poryscript

#### Traditional Assembly Scripting
```assembly
Route101_EventScript_NPC::
    msgbox Route101_Text_NPC_Greeting, MSGBOX_NPC
    checkflag FLAG_RECEIVED_POTION
    goto_if_set Route101_EventScript_NPC_AlreadyGave
    giveitem ITEM_POTION
    goto_if_bag_full Route101_EventScript_NPC_BagFull
    setflag FLAG_RECEIVED_POTION
    msgbox Route101_Text_NPC_GavePotion, MSGBOX_NPC
    end

Route101_EventScript_NPC_AlreadyGave::
    msgbox Route101_Text_NPC_AlreadyGave, MSGBOX_NPC
    end

Route101_EventScript_NPC_BagFull::
    msgbox Route101_Text_NPC_BagFull, MSGBOX_NPC
    end
```

#### Equivalent Poryscript
```poryscript
script Route101_EventScript_NPC {
    msgbox("Hello! You look like you could use this POTION.", MSGBOX_NPC)
    
    if (flag(FLAG_RECEIVED_POTION)) {
        msgbox("I hope that POTION served you well!")
    } else {
        if (giveitem(ITEM_POTION)) {
            setflag(FLAG_RECEIVED_POTION)
            msgbox("Use it wisely in your adventures!")
        } else {
            msgbox("Oh, your BAG is full. Come back when you have space!")
        }
    }
}
```

## Setting Up Poryscript

### Installation

1. **Download Poryscript**: Get the latest version from the official repository
2. **Install compiler**: Place poryscript executable in your PATH
3. **Configure build system**: Integrate with your project's Makefile

### Build Integration

Add Poryscript compilation to your build process:

```makefile
# In your Makefile
PORYSCRIPT := poryscript

# Rule to compile .pory files to .inc files
%.inc: %.pory
	$(PORYSCRIPT) $< -o $@

# Add .pory files as dependencies
data/maps/%/scripts.inc: data/maps/%/scripts.pory
	$(PORYSCRIPT) $< -o $@
```

### Project Structure

Organize your Poryscript files:

```
data/maps/YourMap/
├── scripts.pory          # Poryscript source
├── scripts.inc           # Compiled output (auto-generated)
└── map.json             # Map configuration

shared/
├── common_scripts.pory   # Shared script functions
└── constants.pory        # Script constants and definitions
```

## Basic Poryscript Syntax

### 1. Variables and Constants

#### Declaring Variables
```poryscript
// Temporary variables (auto-managed)
var questStage = 0
var itemCount = 5
var playerChoice = false

// Using game flags and variables directly
if (flag(FLAG_BADGE01_GET)) {
    var badgeCount = var(VAR_BADGE_COUNT)
}
```

#### Constants and Text
```poryscript
// Text constants
const GREETING_TEXT = "Welcome to our town!"
const ITEM_OFFER_TEXT = "Would you like this POTION?"

// Numeric constants
const MAX_ITEMS = 10
const QUEST_STAGE_COMPLETE = 5

script SampleNPC {
    msgbox(GREETING_TEXT, MSGBOX_NPC)
}
```

### 2. Control Flow

#### If/Else Statements
```poryscript
script ConditionalNPC {
    if (flag(FLAG_STORY_COMPLETE)) {
        msgbox("Congratulations on saving the world!")
    } elif (flag(FLAG_BADGE01_GET)) {
        msgbox("I see you have your first GYM BADGE!")
    } else {
        msgbox("You're just starting your journey, aren't you?")
    }
}
```

#### Switch Statements
```poryscript
script StoryProgressionNPC {
    switch (var(VAR_STORY_PROGRESSION)) {
        case 1:
            msgbox("You just got your first POKéMON!")
        case 2:
            msgbox("I heard you're collecting GYM BADGES.")
        case 3:
            msgbox("The POKéMON LEAGUE is waiting for you!")
        default:
            msgbox("Hello there, young trainer!")
    }
}
```

#### Loops
```poryscript
script CountingExample {
    var count = 0
    while (count < 3) {
        msgbox(format("Count is: {}", count))
        count += 1
    }
    
    // For loop equivalent
    for (var i = 0; i < 3; i += 1) {
        msgbox(format("Loop iteration: {}", i))
    }
}
```

### 3. Functions and Scripts

#### Defining Functions
```poryscript
// Helper function for common item giving pattern
function giveItemSafely(item, amount, successText, failText) {
    if (giveitem(item, amount)) {
        msgbox(successText)
        return true
    } else {
        msgbox(failText)
        return false
    }
}

// Using the function
script ItemGiverNPC {
    msgbox("Take this POTION!")
    giveItemSafely(
        ITEM_POTION, 
        1,
        "Use it well!",
        "Your bag is full!"
    )
}
```

#### Script Parameters and Return Values
```poryscript
// Function with parameters
function checkBadgeCount() {
    var count = 0
    if (flag(FLAG_BADGE01_GET)) count += 1
    if (flag(FLAG_BADGE02_GET)) count += 1
    if (flag(FLAG_BADGE03_GET)) count += 1
    // ... check all badges
    return count
}

// Using the function
script GymGuide {
    var badges = checkBadgeCount()
    if (badges >= 8) {
        msgbox("You're ready for the POKéMON LEAGUE!")
    } else {
        msgbox(format("You have {} BADGES. Keep going!", badges))
    }
}
```

## Advanced Features

### Complex Event Scripting

#### Multi-Stage Quests
```poryscript
const QUEST_NOT_STARTED = 0
const QUEST_FIND_ITEM = 1
const QUEST_RETURN_ITEM = 2
const QUEST_COMPLETE = 3

script QuestGiver {
    switch (var(VAR_SAMPLE_QUEST)) {
        case QUEST_NOT_STARTED:
            msgbox("I've lost my RARE CANDY in the tall grass. Can you help me find it?")
            if (msgbox("Will you help me?", MSGBOX_YESNO) == YES) {
                setvar(VAR_SAMPLE_QUEST, QUEST_FIND_ITEM)
                msgbox("Thank you! Look in the tall grass on Route 101.")
            }
            
        case QUEST_FIND_ITEM:
            if (checkitem(ITEM_RARE_CANDY)) {
                msgbox("You found my RARE CANDY! Thank you so much!")
                removeitem(ITEM_RARE_CANDY, 1)
                giveitem(ITEM_MASTER_BALL, 1)
                setvar(VAR_SAMPLE_QUEST, QUEST_COMPLETE)
            } else {
                msgbox("Please look for my RARE CANDY in the tall grass.")
            }
            
        case QUEST_COMPLETE:
            msgbox("Thanks again for finding my RARE CANDY!")
    }
}
```

#### Dynamic Battle Configuration
```poryscript
script DynamicTrainer {
    var playerLevel = getMonData(MON_DATA_LEVEL, 0)  // Get first Pokemon's level
    var trainerLevel = playerLevel + 2  // Scale difficulty
    
    // Set trainer's Pokemon levels dynamically
    setvar(VAR_TRAINER_LEVEL, trainerLevel)
    
    if (flag(FLAG_HARD_MODE)) {
        trainerbattle_single(
            TRAINER_DYNAMIC_BOSS_HARD,
            "Prepare for a real challenge!",
            "Incredible skill!"
        )
    } else {
        trainerbattle_single(
            TRAINER_DYNAMIC_BOSS_NORMAL,
            "Let's have a fair battle!",
            "Well battled!"
        )
    }
}
```

### Advanced NPC Behaviors

#### Time-Based Events
```poryscript
script TimeBasedNPC {
    var currentHour = getTimeOfDay()
    
    if (currentHour >= 6 && currentHour < 12) {
        msgbox("Good morning! The POKéMON are very active today.")
    } elif (currentHour >= 12 && currentHour < 18) {
        msgbox("Good afternoon! Perfect weather for training.")
    } elif (currentHour >= 18 && currentHour < 22) {
        msgbox("Good evening! The sunset is beautiful from here.")
    } else {
        msgbox("It's quite late. You should rest at the POKéMON CENTER.")
    }
}
```

#### Achievement System
```poryscript
function checkAchievements() {
    var newAchievements = 0
    
    // Check catching achievement
    if (var(VAR_POKEMON_CAUGHT) >= 50 && !flag(FLAG_ACHIEVEMENT_CATCHER)) {
        setflag(FLAG_ACHIEVEMENT_CATCHER)
        giveitem(ITEM_PREMIER_BALL, 10)
        msgbox("Achievement unlocked: Pokémon Catcher!")
        newAchievements += 1
    }
    
    // Check battle achievement
    if (var(VAR_BATTLES_WON) >= 100 && !flag(FLAG_ACHIEVEMENT_BATTLER)) {
        setflag(FLAG_ACHIEVEMENT_BATTLER)
        giveitem(ITEM_PP_MAX, 3)
        msgbox("Achievement unlocked: Battle Master!")
        newAchievements += 1
    }
    
    return newAchievements
}

script AchievementChecker {
    var newAchievements = checkAchievements()
    if (newAchievements > 0) {
        playse(SE_SUCCESS)
        msgbox(format("You earned {} new achievement(s)!", newAchievements))
    }
}
```

## Converting Existing Scripts

### Migration Strategy

1. **Start with simple scripts**: Convert basic NPCs first
2. **Test incrementally**: Verify each converted script works
3. **Maintain backups**: Keep original assembly scripts as reference
4. **Update gradually**: Convert entire maps at once for consistency

### Common Conversion Patterns

#### Basic NPC Conversion
```assembly
# Assembly version
OldTown_EventScript_NPC::
    msgbox OldTown_Text_NPC_Greeting, MSGBOX_NPC
    end

OldTown_Text_NPC_Greeting:
    .string "Welcome to our town!$"
```

```poryscript
// Poryscript version
script OldTown_EventScript_NPC {
    msgbox("Welcome to our town!", MSGBOX_NPC)
}
```

#### Complex Conditional Logic
```assembly
# Assembly version (verbose)
ComplexNPC_EventScript::
    checkflag FLAG_STORY_FLAG_1
    goto_if_unset ComplexNPC_NoFlag1
    checkflag FLAG_STORY_FLAG_2
    goto_if_unset ComplexNPC_HasFlag1Only
    msgbox ComplexNPC_Text_BothFlags, MSGBOX_NPC
    end

ComplexNPC_NoFlag1::
    msgbox ComplexNPC_Text_NoFlags, MSGBOX_NPC
    end

ComplexNPC_HasFlag1Only::
    msgbox ComplexNPC_Text_OneFlag, MSGBOX_NPC
    end
```

```poryscript
// Poryscript version (concise)
script ComplexNPC_EventScript {
    if (flag(FLAG_STORY_FLAG_1) && flag(FLAG_STORY_FLAG_2)) {
        msgbox("You've made great progress in your journey!")
    } elif (flag(FLAG_STORY_FLAG_1)) {
        msgbox("You're on the right track. Keep going!")
    } else {
        msgbox("You're just getting started!")
    }
}
```

## Best Practices

### Code Organization

1. **Use meaningful names**: `script TownGuide_EventScript` instead of `script NPC1`
2. **Group related scripts**: Keep map scripts together, shared functions separate
3. **Comment your code**: Explain complex logic and game mechanics
4. **Consistent formatting**: Use standard indentation and spacing

### Error Handling

```poryscript
script SafeItemGiver {
    if (!checkitem(ITEM_POKEDEX)) {
        msgbox("You need a POKéDEX first!")
        return
    }
    
    if (!giveitem(ITEM_RARE_CANDY, 1)) {
        msgbox("Your bag is full!")
        return
    }
    
    msgbox("Here's a RARE CANDY for your POKéDEX!")
    setflag(FLAG_RECEIVED_RARE_CANDY)
}
```

### Performance Considerations

1. **Minimize flag/variable checks**: Cache frequently used values
2. **Use early returns**: Exit scripts quickly when conditions aren't met
3. **Avoid deep nesting**: Break complex logic into functions
4. **Reuse common patterns**: Create helper functions for repeated code

### Debugging and Testing

```poryscript
// Debug mode features
script DebugNPC {
    #ifdef DEBUG
        if (msgbox("Enable debug mode?", MSGBOX_YESNO) == YES) {
            setvar(VAR_STORY_PROGRESSION, 10)
            setflag(FLAG_DEBUG_MODE)
            msgbox("Debug mode enabled!")
        }
    #endif
    
    msgbox("Hello, trainer!")
}
```

## Troubleshooting

### Common Issues

**Compilation errors:**
- Check syntax carefully - Poryscript is case-sensitive
- Ensure proper bracket matching and semicolons
- Verify function names and parameters are correct

**Runtime errors:**
- Test scripts thoroughly in-game
- Check that compiled .inc files are included properly
- Verify game constants are available and spelled correctly

**Performance issues:**
- Monitor script complexity and execution time
- Use profiling tools to identify bottlenecks
- Optimize frequently-called scripts

### Debug Tips

1. **Use simple test scripts** to verify Poryscript setup
2. **Check compiled output** - examine generated .inc files
3. **Test incrementally** - convert and test small pieces at a time
4. **Use logging** - add debug messages to track script execution

### Integration with Existing Code

1. **Maintain compatibility** - ensure Poryscript scripts work with assembly scripts
2. **Update gradually** - don't convert everything at once
3. **Document changes** - note which scripts have been converted
4. **Keep backups** - maintain original scripts until conversion is complete

## Related Tutorials

- [How to Add NPCs](how_to_add_npcs.md) - Creating NPCs that use Poryscript
- [Flags and Variables](how_to_flags_vars.md) - Understanding game state management
- [How to Add Maps](how_to_add_maps.md) - Map scripting with Poryscript
- [Scripting Reference](scripting_reference.md) - Complete scripting command reference

---

*Poryscript makes complex scripting more manageable and maintainable. Start with simple conversions and gradually work up to more complex event programming!*