# How to Add Trainers

This tutorial will guide you through adding new trainer battles to your pokeemerald-expansion ROM hack. Trainers are NPCs that battle the player with their Pokémon teams, providing challenge and gameplay variety throughout your game.

## Content
* [Quick Summary](#quick-summary)
* [Understanding the Trainer System](#understanding-the-trainer-system)
* [Trainer Data Format](#trainer-data-format)
* [Adding New Trainers](#adding-new-trainers)
  * [1. Define Trainer Data](#1-define-trainer-data)
  * [2. Add Trainer to Constants](#2-add-trainer-to-constants)
  * [3. Place Trainer in World](#3-place-trainer-in-world)
  * [4. Configure AI and Behavior](#4-configure-ai-and-behavior)
* [Advanced Trainer Features](#advanced-trainer-features)
* [Trainer Classes and Graphics](#trainer-classes-and-graphics)
* [Troubleshooting](#troubleshooting)

## Quick Summary

If you've done this before and just need a quick reference:

1. Add trainer definition to `src/data/trainers.party`
2. Add trainer constant to `include/constants/trainers.h` (if needed)
3. Place trainer in map using `object_events` with `trainer_type` and `trainer_sight_or_berry_tree_id`
4. Optionally add custom trainer class, picture, or AI flags
5. Test the battle in-game

## Understanding the Trainer System

The pokeemerald-expansion trainer system consists of several components:

- **Trainer Data**: Defines name, class, party, AI, and other properties
- **Trainer Constants**: Unique identifiers for each trainer
- **Trainer Classes**: Categories like "Youngster", "Gym Leader", etc.
- **Trainer Graphics**: Battle sprites and overworld sprites
- **Battle AI**: How smart the trainer is during battle
- **Placement**: Where trainers appear in the world

## Trainer Data Format

Trainers are defined using a Pokémon Showdown-compatible syntax in `src/data/trainers.party`. This format is human-readable and supports competitive battling standards.

### Basic Trainer Structure
```
=== TRAINER_YOUR_TRAINER_NAME ===
Name: TRAINER NAME
Class: Youngster
Pic: Boy 1
Gender: Male
Music: Male
Double Battle: No
AI: Check Bad Move

Rattata
Level: 5
IVs: 0 HP / 0 Atk / 0 Def / 0 SpA / 0 SpD / 0 Spe

Pidgey
Level: 7
IVs: 0 HP / 0 Atk / 0 Def / 0 SpA / 0 SpD / 0 Spe
```

### Required Fields

**For the trainer:**
- `Name`: Trainer's display name (up to 10 characters)
- `Class`: Trainer class (affects money given, battle intro text)
- `Pic`: Battle sprite to use

**For each Pokémon:**
- Species name (e.g., `Rattata` or `SPECIES_RATTATA`)
- `Level`: Between 1-100

### Optional Fields

**For the trainer:**
- `Gender`: Male/Female (affects some AI behavior)
- `Music`: Battle music track
- `Double Battle`: Yes/No for double battles
- `AI`: Battle AI flags (see AI section)
- `Items`: Items the trainer uses in battle
- `Mugshot`: Colored portrait during battle intro
- `Starting Status`: Status conditions at battle start

**For each Pokémon:**
- `Ability`: Specific ability (e.g., `Intimidate`)
- `IVs`: Individual Values (0-31 for each stat)
- `EVs`: Effort Values (0-255 for each stat)
- `Moves`: Up to 4 specific moves
- `Ball`: Poké Ball type
- `Happiness`: Friendship level
- `Held Item`: Item the Pokémon carries

## Adding New Trainers

### 1. Define Trainer Data

Add your trainer to `src/data/trainers.party`:

```
=== TRAINER_ROUTE_101_YOUNGSTER ===
Name: TOMMY
Class: Youngster
Pic: Boy 1
Gender: Male
Music: Male
Double Battle: No
AI: Check Bad Move

Poochyena
Level: 4
IVs: 12 HP / 12 Atk / 12 Def / 12 SpA / 12 SpD / 12 Spe
Moves:
- Tackle
- Howl

Zigzagoon
Level: 6
IVs: 12 HP / 12 Atk / 12 Def / 12 SpA / 12 SpD / 12 Spe
Ability: Pickup
Ball: Great Ball
Happiness: 200
Moves:
- Tackle
- Tail Whip
- Headbutt
- Sand Attack
```

### 2. Add Trainer to Constants

If you're adding a completely new trainer (not replacing an existing one), add the constant to `include/constants/trainers.h`:

```c
#define TRAINER_ROUTE_101_YOUNGSTER 1024
```

Choose an unused number or add it to the end of the list. The build system will handle most trainer constants automatically if you follow the naming convention.

### 3. Place Trainer in World

Add the trainer to a map by editing the map's `object_events` in `data/maps/YourMapName/map.json`:

```json
{
  "graphics_id": "OBJ_EVENT_GFX_BOY_1",
  "x": 15,
  "y": 8,
  "elevation": 3,
  "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
  "movement_range_x": 0,
  "movement_range_y": 0,
  "trainer_type": "TRAINER_TYPE_NORMAL",
  "trainer_sight_or_berry_tree_id": "4",
  "script": "Route101_EventScript_Tommy",
  "flag": "FLAG_DEFEATED_ROUTE_101_TOMMY"
}
```

Key trainer-specific fields:
- `trainer_type`: Set to `TRAINER_TYPE_NORMAL` for regular trainers
- `trainer_sight_or_berry_tree_id`: How far the trainer can see (sight range)
- `script`: Battle script function
- `flag`: Game flag set when trainer is defeated

### 4. Create Battle Script

Add the battle script to your map's `scripts.inc`:

```assembly
Route101_EventScript_Tommy::
	trainerbattle_single TRAINER_ROUTE_101_YOUNGSTER, Route101_Text_Tommy_Intro, Route101_Text_Tommy_Defeat
	msgbox Route101_Text_Tommy_PostBattle, MSGBOX_NPC
	end

Route101_Text_Tommy_Intro:
	.string "Hey! I just caught some POKéMON!\n"
	.string "Let's battle!$"

Route101_Text_Tommy_Defeat:
	.string "Wow, you're really strong!$"

Route101_Text_Tommy_PostBattle:
	.string "I need to train my POKéMON more.\p"
	.string "The tall grass is full of wild\n"
	.string "POKéMON. Try looking there!$"
```

## Advanced Trainer Features

### Double Battle Trainers

```
=== TRAINER_TWINS_AMY_LIV ===
Name: AMY & LIV
Class: Twins
Pic: Twins
Gender: Female
Music: Female
Double Battle: Yes
AI: Check Bad Move / Smart

Plusle
Level: 25
Ability: Plus

Minun
Level: 25
Ability: Minus
```

For double battles, use `trainerbattle_double` in scripts:

```assembly
Route103_EventScript_Twins::
	trainerbattle_double TRAINER_TWINS_AMY_LIV, Route103_Text_Twins_Intro, Route103_Text_Twins_Defeat, Route103_Text_Twins_NotEnoughPokemon
	msgbox Route103_Text_Twins_PostBattle, MSGBOX_NPC
	end
```

### Gym Leader Style Trainers

```
=== TRAINER_ROXANNE_1 ===
Name: ROXANNE
Class: Gym Leader
Pic: Roxanne
Gender: Female
Music: Gym Leader
Double Battle: No
AI: Smart / Check Bad Move / Check Viability / Risky
Items: Hyper Potion / Hyper Potion

Geodude (M) @ Oran Berry
Level: 12
Ability: Sturdy
IVs: 24 HP / 24 Atk / 24 Def / 24 SpA / 24 SpD / 24 Spe
Moves:
- Tackle
- Defense Curl
- Rock Throw
- Rock Tomb

Nosepass (M) @ Sitrus Berry  
Level: 14
Ability: Sturdy
IVs: 24 HP / 24 Atk / 24 Def / 24 SpA / 24 SpD / 24 Spe
Moves:
- Tackle
- Harden  
- Rock Throw
- Rock Tomb
```

### Elite Four/Champion Trainers

```
=== TRAINER_SIDNEY ===
Name: SIDNEY
Class: Elite Four
Pic: Sidney
Gender: Male  
Music: Elite Four
Double Battle: No
AI: Smart / Check Bad Move / Check Viability / Risky
Items: Full Restore / Full Restore

Mightyena (M) @ Leftovers
Level: 46
Ability: Intimidate
IVs: 31 HP / 31 Atk / 31 Def / 31 SpA / 31 SpD / 31 Spe
EVs: 252 HP / 252 Atk / 4 Def
Moves:
- Roar
- Double-Edge
- Sand Attack
- Crunch
```

### AI Configuration

AI flags determine how smart trainers are in battle:

```
AI: Check Bad Move / Smart / Check Viability / Risky
```

Common AI flags:
- `Check Bad Move`: Avoids obviously bad moves
- `Smart`: Generally makes good decisions
- `Check Viability`: Considers move effectiveness
- `Risky`: Uses risky moves like Explosion
- `Prefer Strongest Move`: Prefers highest power moves
- `Setup First Turn`: Uses stat moves early
- `Prefer Baton Pass`: AI for Baton Pass strategies

### Rematch Trainers

For trainers that can be battled multiple times:

```assembly
Route103_EventScript_RematchTrainer::
	trainerbattle_rematch TRAINER_ROUTE_103_FISHERMAN, Route103_Text_Fisherman_Intro, Route103_Text_Fisherman_Defeat
	msgbox Route103_Text_Fisherman_PostBattle, MSGBOX_NPC
	end
```

Add multiple trainer definitions with `_1`, `_2`, etc. suffixes for different rematch teams.

### Multi-Battle Trainers

For tag battles (2 vs 2 with partner):

```assembly
Route103_EventScript_TagBattle::
	trainerbattle_two_trainers TRAINER_ENEMY_1, TRAINER_ENEMY_2, Route103_Text_TagIntro, Route103_Text_TagDefeat, Route103_Text_NotEnoughPokemon, TRAINER_PARTNER
	msgbox Route103_Text_TagPostBattle, MSGBOX_NPC  
	end
```

## Trainer Classes and Graphics

### Adding New Trainer Classes

Trainer classes are defined in `src/data/text/trainer_class_names.inc`:

```c
[TRAINER_CLASS_YOUR_NEW_CLASS] = _("NEW CLASS"),
```

And referenced in trainer data:
```
Class: New Class
```

### Trainer Battle Graphics

Available trainer pics (see `include/constants/trainers.h`):
- `TRAINER_PIC_YOUNGSTER`: Basic male trainer  
- `TRAINER_PIC_LASS`: Basic female trainer
- `TRAINER_PIC_BUG_CATCHER`: Bug-type specialist
- `TRAINER_PIC_SWIMMER_M/F`: Water-type trainers
- `TRAINER_PIC_HIKER`: Rock/Ground-type trainer
- `TRAINER_PIC_PICNICKER`: Grass-type trainer

You can also create custom trainer sprites (see the trainer sprite tutorials).

### Overworld Graphics

For overworld sprites, use appropriate `OBJ_EVENT_GFX_*` constants:
- `OBJ_EVENT_GFX_BOY_1/2/3`: Young male trainers
- `OBJ_EVENT_GFX_GIRL_1/2/3`: Young female trainers  
- `OBJ_EVENT_GFX_YOUNGSTER`: Youngster class
- `OBJ_EVENT_GFX_LASS`: Lass class
- `OBJ_EVENT_GFX_FISHERMAN`: Fisherman
- `OBJ_EVENT_GFX_HIKER`: Hiker

## Troubleshooting

### Common Issues

**Trainer doesn't battle:**
- Check that `trainer_type` is set correctly (not `TRAINER_TYPE_NONE`)
- Verify trainer constant exists and is spelled correctly
- Ensure sight range (`trainer_sight_or_berry_tree_id`) is appropriate

**Trainer has wrong team:**
- Check trainer data in `trainers.party` for typos
- Verify species names are spelled correctly
- Ensure the trainer constant matches the data entry

**Battle crashes:**
- Check for invalid moves, abilities, or items
- Verify all Pokémon have valid levels (1-100)
- Ensure IVs/EVs are within valid ranges

**Trainer appears multiple times:**
- Check that the defeat flag is properly set
- Verify the flag name is unique
- Ensure the script uses `trainerbattle_single` correctly

**Wrong battle music/graphics:**
- Check `Music` field in trainer data
- Verify `Pic` field uses correct sprite name
- Ensure trainer class is properly defined

### Debug Tips

1. **Start with simple trainers** - Single Pokémon, basic moves
2. **Use existing trainers as templates** - Copy and modify working examples  
3. **Test sight range** - Make sure trainers see you from appropriate distance
4. **Check battle flags** - Verify trainers are properly defeated
5. **Validate Pokémon data** - Ensure all moves/abilities exist

### Battle Balance Tips

- **Early game trainers** should have 1-2 Pokémon, levels 3-15
- **Mid game trainers** can have 2-4 Pokémon, levels 15-35  
- **Late game trainers** should have 4-6 Pokémon, levels 35-60
- **Elite trainers** can have perfect IVs and competitive movesets
- **Gym leaders** should be 2-5 levels above local wild Pokémon
- **Use type themes** for most trainers (Bug Catcher = Bug types)

## Related Tutorials

- [How to Add NPCs](how_to_add_npcs.md) - For non-battling NPCs
- [How to Add Trainer Sprites](how_to_trainer_front_pic.md) - Custom battle graphics
- [AI System](ai_logic.md) - Advanced AI configuration
- [Move Creation](how_to_new_move.md) - Adding custom moves

---

*Good trainers make for memorable battles! Give them personality and appropriate challenge levels.*