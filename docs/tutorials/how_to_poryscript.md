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

1. **Download Poryscript**: Get the latest version from the [official repository](https://github.com/huderlem/poryscript/releases)
2. **Install compiler**: Create a `tools/poryscript/` directory and add the executable:
   - `pokeemerald/tools/poryscript/poryscript.exe` (Windows)
   - `pokeemerald/tools/poryscript/poryscript` (Linux/Mac)
3. **Copy config files**: Also copy `command_config.json` and `font_config.json` to the same location
4. **Update .gitignore**: Add the poryscript binary to your `.gitignore` (but not the config files)

### Build Integration

Update your Makefile with these changes:

```makefile
# Add these lines to your Makefile
PORYSCRIPT := $(TOOLS_DIR)/poryscript/poryscript$(EXE)

# Add this rule for automatic compilation
%.inc: %.pory
	$(PORYSCRIPT) -i $< -o $@ -cc $(TOOLS_DIR)/poryscript/command_config.json -fc $(TOOLS_DIR)/poryscript/font_config.json

# Add dependency for map scripts
data/maps/%/scripts.inc: data/maps/%/scripts.pory
	$(PORYSCRIPT) -i $< -o $@ -cc $(TOOLS_DIR)/poryscript/command_config.json -fc $(TOOLS_DIR)/poryscript/font_config.json
```

### Project Structure

Organize your Poryscript files:

```
data/maps/YourMap/
├── scripts.pory          # Poryscript source
├── scripts.inc           # Compiled output (auto-generated)
└── map.json             # Map configuration

tools/poryscript/
├── poryscript            # Poryscript compiler executable
├── command_config.json   # Command configuration
└── font_config.json      # Font configuration
```

### Using VS Code Extension

For the best development experience, install the [VS Code Poryscript extension](https://marketplace.visualstudio.com/items?itemName=karathan.poryscript) which provides:
- Syntax highlighting
- Autocomplete
- Error diagnostics
- Code formatting

You can also test Poryscript online at the [Poryscript Playground](http://www.huderlem.com/poryscript-playground/).

## Basic Poryscript Syntax

### 1. Script Structure

A `.pory` file contains top-level statements. The main types are:
- `script` - Contains script commands and logic
- `text` - Defines text strings
- `movement` - Defines movement patterns
- `mart` - Defines shop inventories
- `mapscripts` - Defines map event scripts
- `raw` - Includes raw assembly code

#### Basic Script Example
```poryscript
script SampleNPC {
    lock
    faceplayer
    msgbox("Welcome to our town!")
    release
    end
}
```

### 2. Control Flow and Conditions

#### If/Else Statements
```poryscript
script ConditionalNPC {
    lock
    faceplayer
    if (flag(FLAG_STORY_COMPLETE)) {
        msgbox("Congratulations on saving the world!")
    } elif (flag(FLAG_BADGE01_GET)) {
        msgbox("I see you have your first GYM BADGE!")
    } else {
        msgbox("You're just starting your journey, aren't you?")
    }
    release
    end
}
```

#### Boolean Expressions
You can use logical operators `&&` (AND) and `||` (OR):
```poryscript
script ComplexConditions {
    # Basic AND of two conditions
    if (!defeated(TRAINER_MISTY) && var(VAR_TIME) != DAY) {
        msgbox("The Cerulean Gym's doors don't open until morning.")
    }
    
    # Nested conditions with grouping
    if (flag(FLAG_IS_CHAMPION) && !(flag(FLAG_SYS_TOWER_GOLD) || flag(FLAG_SYS_DOME_GOLD))) {
        msgbox("You should try to beat the Battle Tower or Battle Dome!")
    }
}
```

#### Conditional Operators
Different types support different operators:

| Type | Valid Operators | Valid Values |
|------|-----------------|--------------|
| `flag()` | `==` | `true`, `false`, `TRUE`, `FALSE` |
| `var()` | `==`, `!=`, `>`, `>=`, `<`, `<=` | Any numeric value |
| `defeated()` | `==` | `true`, `false`, `TRUE`, `FALSE` |

Examples with implicit truthiness:
```poryscript
# These are equivalent:
if (flag(FLAG_RECEIVED_POKEDEX))
if (flag(FLAG_RECEIVED_POKEDEX) == true)

# These are equivalent:
if (!flag(FLAG_RECEIVED_POKEDEX))
if (flag(FLAG_RECEIVED_POKEDEX) == false)

# These are equivalent:
if (var(VAR_STORY_STAGE))
if (var(VAR_STORY_STAGE) != 0)
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

#### While Loops
```poryscript
script PersistentNPC {
    # Force player to answer "Yes"
    msgbox("Do you agree to the quest?", MSGBOX_YESNO)
    while (var(VAR_RESULT) != YES) {
        msgbox("...How about now?", MSGBOX_YESNO)
    }
    setvar(VAR_QUEST_ACCEPTED, 1)
    msgbox("Great! Let's begin!")
}
```

#### Do-While Loops
```poryscript
script DoWhileExample {
    # Always executes at least once
    do {
        msgbox("Can you help me solve the puzzle?", MSGBOX_YESNO)
    } while (var(VAR_RESULT) == NO)
}
```

#### Loop Control
```poryscript
script LoopControlExample {
    while {  # Infinite loop
        msgbox("Want to see this message again?", MSGBOX_YESNO)
        if (var(VAR_RESULT) != YES) {
            break  # Exit the loop
        }
        # continue would return to start of loop
    }
}
```

### 3. Text and Formatting

#### Inline Text
Text can be included directly in scripts without separate text definitions:
```poryscript
script SimpleNPC {
    msgbox("Hello! Welcome to our town!")
    msgbox("The POKéMON CENTER is just north of here.")
}
```

#### Text Statements
For reusable text, use `text` statements:
```poryscript
text WelcomeMessage {
    "Hello, welcome to our town!\p"
    "Feel free to look around!"
}

script WelcomingNPC {
    msgbox(WelcomeMessage)
}
```

#### Automatic Text Formatting
Use `format()` to automatically wrap text to fit message boxes:
```poryscript
text LongMessage {
    format("Hello, are you the real-live legendary {PLAYER} that everyone talks about? Amazing! So glad to meet you!")
}
```

#### Custom Text Encoding
Specify different text encoders:
```poryscript
text DebugMessage {
    ascii"This is ASCII text for debugging."
}
```

### 4. Movement Statements

#### Movement Definitions
```poryscript
movement WalkToPlayer {
    walk_left
    walk_up * 3
    face_down
}

script MovingNPC {
    lock
    applymovement(2, WalkToPlayer)
    waitmovement(0)
    msgbox("I walked over to talk to you!")
    release
}
```

#### Inline Movement
Movement can be inlined using `moves()`:
```poryscript
script InlineMovementNPC {
    lock
    applymovement(2, moves(
        walk_left
        walk_up * 3
        face_down
    ))
    waitmovement(0)
    msgbox("I used inline movement!")
    release
}
```

### 5. Mart Statements

Define shop inventories easily:
```poryscript
mart TownMart {
    ITEM_POTION
    ITEM_ANTIDOTE
    ITEM_POKEBALL
    ITEM_GREAT_BALL
}

script ShopKeeper {
    lock
    faceplayer
    message("Welcome to our shop!")
    waitmessage
    pokemart(TownMart)
    msgbox("Come back anytime!")
    release
}
```

### 6. Map Scripts

Use `mapscripts` to organize map event scripts:
```poryscript
mapscripts MyTown_MapScripts {
    MAP_SCRIPT_ON_TRANSITION: MyTown_OnTransition
    MAP_SCRIPT_ON_RESUME {
        # Inline script
        if (flag(FLAG_JUST_ARRIVED)) {
            setweather(WEATHER_SUNNY)
        }
    }
    MAP_SCRIPT_ON_FRAME_TABLE [
        VAR_TEMP_0, 0: MyTown_FirstFrame
        VAR_TEMP_0, 1 {
            lock
            msgbox("This happens on frame 1.")
            setvar(VAR_TEMP_0, 2)
            release
        }
    ]
}

script MyTown_OnTransition {
    # Transition logic here
}

script MyTown_FirstFrame {
    # Frame logic here
}
```

For maps with no scripts:
```poryscript
mapscripts EmptyMap_MapScripts {}
```

### 7. Raw Assembly

Include raw assembly code when needed:
```poryscript
raw `
MyCustomData:
    .byte 0x01, 0x02, 0x03, 0x04
    .string "Custom string$"
`
```

## Advanced Features

### AutoVar Commands

Some commands automatically store results in variables. Poryscript can use these directly in conditions:

#### Without AutoVar (traditional):
```poryscript
script TraditionalCheck {
    checkitem(ITEM_ROOT_FOSSIL)
    if (var(VAR_RESULT) == TRUE) {
        msgbox("You have the Root Fossil!")
    }
}
```

#### With AutoVar (simplified):
```poryscript
script AutoVarCheck {
    if (checkitem(ITEM_ROOT_FOSSIL) == TRUE) {
        msgbox("You have the Root Fossil!")
    }
}
```

#### AutoVar in Complex Conditions:
```poryscript
script ComplexAutoVar {
    if (checkitem(ITEM_POKEBLOCK_CASE)) {
        if (specialvar(VAR_RESULT, GetFirstFreePokeblockSlot) != -1 && 
            specialvar(VAR_RESULT, PlayerHasBerries)) {
            msgbox("Great! You can use the Berry Blender!")
        }
    } else {
        msgbox("You don't have a Pokeblock case!")
    }
}
```

Common AutoVar commands:
- `checkitem()` - stores result in `VAR_RESULT`
- `random()` - stores result in `VAR_RESULT`
- `getpartysize()` - stores result in `VAR_RESULT`
- `specialvar()` - stores in specified variable

### Compile-Time Switches

Use `poryswitch` to create version-specific content:

#### Basic Switch Usage:
```poryscript
script VersionSpecificNPC {
    lock
    faceplayer
    poryswitch(GAME_VERSION) {
        RUBY {
            msgbox("Here, take this Ruby Orb.")
            giveitem(ITEM_RUBY_ORB)
        }
        SAPPHIRE {
            msgbox("Here, take this Sapphire Orb.")
            giveitem(ITEM_SAPPHIRE_ORB)
        }
        _: msgbox("This is the default case.")
    }
    release
}
```

#### Switches in Text:
```poryscript
text LanguageText {
    poryswitch(LANGUAGE) {
        GERMAN:  "Hallo. Ich spreche Deutsch."
        ENGLISH: "Hello. I speak English."
        _:       "Default language text."
    }
}
```

#### Switches in Movement:
```poryscript
movement VersionMovement {
    face_player
    walk_down
    poryswitch(GAME_VERSION) {
        RUBY: walk_left * 2
        SAPPHIRE {
            walk_right * 2
            walk_left * 4
        }
    }
}
```

To use switches, define them when compiling:
```bash
poryscript -i script.pory -o script.inc -s GAME_VERSION=RUBY -s LANGUAGE=ENGLISH
```

### Scope Modifiers

Different statement types have default scopes:

| Type | Default Scope | Description |
|------|---------------|-------------|
| `script` | Global | Accessible from C code |
| `text` | Global | Accessible from C code |
| `movement` | Local | Only accessible within the file |
| `mart` | Local | Only accessible within the file |
| `mapscripts` | Global | Accessible from C code |

Change scope with `local` and `global` keywords:
```poryscript
local script MyLocalScript {
    # Only accessible within this file
}

global movement MyGlobalMovement {
    # Accessible from C code
    walk_up
    walk_down
}
```

## Converting Existing Scripts

### Automatic Conversion

Use the provided conversion script to convert existing `.inc` files:

1. Create `convert_inc.sh` in your project root:
```bash
#!/bin/bash
for directory in data/maps/*/; do
    if [ -f "$directory/scripts.inc" ] && [ ! -f "$directory/scripts.pory" ]; then
        echo "Converting $directory"
        echo 'raw `' > "$directory/scripts.pory"
        cat "$directory/scripts.inc" >> "$directory/scripts.pory"
        echo '`' >> "$directory/scripts.pory"
    fi
done
```

2. Make it executable: `chmod 777 convert_inc.sh`
3. Run: `./convert_inc.sh`

This wraps existing assembly scripts in `raw` statements, allowing gradual conversion.

### Manual Conversion Examples

#### Assembly to Poryscript - Basic NPC:
```assembly
# Assembly
OldTown_EventScript_NPC::
    msgbox OldTown_Text_NPC_Greeting, MSGBOX_NPC
    end

OldTown_Text_NPC_Greeting:
    .string "Welcome to our town!$"
```

```poryscript
// Poryscript
script OldTown_EventScript_NPC {
    msgbox("Welcome to our town!", MSGBOX_NPC)
}
```
#### Assembly to Poryscript - Complex Logic:
```assembly
# Assembly (verbose)
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
// Poryscript (concise)
script ComplexNPC_EventScript {
    lock
    faceplayer
    if (flag(FLAG_STORY_FLAG_1) && flag(FLAG_STORY_FLAG_2)) {
        msgbox("You've made great progress in your journey!")
    } elif (flag(FLAG_STORY_FLAG_1)) {
        msgbox("You're on the right track. Keep going!")
    } else {
        msgbox("You're just getting started!")
    }
    release
}
```

#### Assembly to Poryscript - Item Giving:
```assembly
# Assembly
Route101_EventScript_ItemGiver::
    checkflag FLAG_RECEIVED_POTION
    goto_if_set Route101_EventScript_ItemGiver_AlreadyGave
    msgbox Route101_Text_ItemGiver_Offer, MSGBOX_NPC
    giveitem ITEM_POTION
    goto_if_bag_full Route101_EventScript_ItemGiver_BagFull
    setflag FLAG_RECEIVED_POTION
    msgbox Route101_Text_ItemGiver_GaveItem, MSGBOX_NPC
    end

Route101_EventScript_ItemGiver_AlreadyGave::
    msgbox Route101_Text_ItemGiver_AlreadyGave, MSGBOX_NPC
    end

Route101_EventScript_ItemGiver_BagFull::
    msgbox Route101_Text_ItemGiver_BagFull, MSGBOX_NPC
    end
```

```poryscript
// Poryscript
script Route101_EventScript_ItemGiver {
    lock
    faceplayer
    if (flag(FLAG_RECEIVED_POTION)) {
        msgbox("I hope that POTION served you well!")
    } else {
        msgbox("You look like you could use this POTION!")
        if (giveitem(ITEM_POTION)) {
            setflag(FLAG_RECEIVED_POTION)
            msgbox("Use it wisely!")
        } else {
            msgbox("Your bag is full! Come back later.")
        }
    }
    release
}
```

### Migration Strategy

1. **Start with simple scripts**: Convert basic NPCs first
2. **Use raw blocks initially**: Wrap existing assembly in `raw` statements
3. **Convert gradually**: Replace `raw` blocks with native Poryscript
4. **Test frequently**: Verify each conversion works correctly
5. **Update build system**: Ensure Makefile handles `.pory` files

## Best Practices

### Code Organization

1. **Use meaningful names**: `script TownGuide_EventScript` instead of `script NPC1`
2. **Group related content**: Keep map scripts, text, and movement together
3. **Use scope appropriately**: Make scripts `local` when they don't need external access
4. **Comment complex logic**: Use `#` for single-line comments
5. **Consistent formatting**: Use proper indentation and spacing

### Leveraging Poryscript Features

1. **Use inline text**: Embed simple messages directly in scripts
2. **Leverage AutoVars**: Simplify condition checks with direct command usage
3. **Use compile-time switches**: Create version-specific or configurable content
4. **Inline movement**: Use `moves()` for simple movement patterns
5. **Format long text**: Use `format()` for automatic text wrapping

### Error Prevention

```poryscript
script SafeItemGiver {
    lock
    faceplayer
    if (!checkitem(ITEM_POKEDEX)) {
        msgbox("You need a POKéDEX first!")
        release
        return
    }
    
    if (flag(FLAG_RECEIVED_ITEM)) {
        msgbox("I already gave you the item!")
    } else {
        if (giveitem(ITEM_RARE_CANDY)) {
            setflag(FLAG_RECEIVED_ITEM)
            msgbox("Here's a RARE CANDY!")
        } else {
            msgbox("Your bag is full!")
        }
    }
    release
}
```

### Performance Considerations

1. **Use early returns**: Exit scripts quickly when conditions aren't met
2. **Minimize nested conditions**: Break complex logic into smaller scripts
3. **Optimize text formatting**: Use appropriate line lengths
4. **Cache frequently used values**: Store complex calculations in variables

## Troubleshooting

### Common Issues

**Compilation errors:**
- Check syntax carefully - Poryscript uses specific operator rules
- Ensure proper bracket/brace matching
- Verify command names and parameters are correct
- Check that referenced flags/variables exist

**Runtime errors:**
- Test scripts thoroughly in-game
- Verify compiled `.inc` files are included in the build
- Check that game constants are spelled correctly
- Ensure movement commands are valid

**Text formatting issues:**
- Verify font configuration is correct
- Check line length settings
- Ensure text encoding matches expectations
- Test long messages in actual game

### Debug Tips

1. **Use the VS Code extension** for syntax highlighting and error detection
2. **Test with simple scripts** to verify Poryscript setup works
3. **Check compiled output** - examine generated `.inc` files
4. **Enable line markers** for better error messages (default enabled)
5. **Use the online playground** to test syntax

### Configuration Issues

**Font configuration problems:**
- Verify `font_config.json` is in the correct location
- Check that font IDs match your game's fonts
- Ensure character widths are properly configured
- Test text formatting with different line lengths

**Command configuration issues:**
- Verify `command_config.json` is properly formatted
- Check that AutoVar commands are correctly defined
- Ensure command names match your game's script commands

## Related Tutorials

- [How to Add NPCs](how_to_add_npcs.md) - Creating NPCs that use Poryscript
- [Flags and Variables](how_to_flags_vars.md) - Understanding game state management
- [How to Add Maps](how_to_add_maps.md) - Map scripting with Poryscript
- [Scripting Reference](scripting_reference.md) - Complete scripting command reference

---

*Poryscript makes complex scripting more manageable and maintainable. Start with simple conversions and gradually work up to more complex event programming!*