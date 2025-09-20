# How to Add NPCs

This tutorial will guide you through adding Non-Player Characters (NPCs) to your pokeemerald-expansion ROM hack. NPCs bring life to your world by providing dialogue, information, items, and interactions that enhance the player experience.

## Content
* [Quick Summary](#quick-summary)
* [Understanding NPCs](#understanding-npcs)
* [Types of NPCs](#types-of-npcs)
* [Adding Basic NPCs](#adding-basic-npcs)
  * [1. Adding to Map Data](#1-adding-to-map-data)
  * [2. Creating NPC Scripts](#2-creating-npc-scripts)
  * [3. NPC Graphics and Animation](#3-npc-graphics-and-animation)
* [Advanced NPC Features](#advanced-npc-features)
* [Common NPC Patterns](#common-npc-patterns)
* [Troubleshooting](#troubleshooting)

## Quick Summary

If you've done this before and just need a quick reference:

1. Add object_event to your map's `map.json` file
2. Set graphics_id, position (x, y), elevation, and movement
3. Create script function in `scripts.inc`
4. Define text strings for dialogue
5. Add any special flags or conditions
6. Test in-game

## Understanding NPCs

NPCs in pokeemerald-expansion are implemented as "object events" that can:

- Display text messages when interacted with
- Move around the map with various patterns
- Give items to the player
- Set game flags and variables
- Trigger complex story events
- Battle the player (as trainers)

Each NPC consists of:
- **Visual representation** (sprite graphics)
- **Position and movement** (coordinates and movement pattern)
- **Behavior script** (what happens when you interact with them)
- **Conditional logic** (when they appear/disappear)

## Types of NPCs

### Basic NPCs
- **Informational NPCs**: Provide hints, lore, or directions
- **Static NPCs**: Stand in one place and never move
- **Walking NPCs**: Move around in patterns

### Functional NPCs
- **Item Givers**: Provide items, TMs, or Pokémon
- **Service NPCs**: Heal Pokémon, change nicknames, etc.
- **Shop NPCs**: Sell items or services
- **Story NPCs**: Advance plot points and trigger events

### Special NPCs
- **Trainers**: Battle NPCs (covered in trainer tutorial)
- **Gym Leaders**: Major story trainers
- **Followers**: NPCs that follow the player

## Adding Basic NPCs

### 1. Adding to Map Data

NPCs are added to maps through the `object_events` array in the map's JSON file. Edit `data/maps/YourMapName/map.json`:

```json
{
  "object_events": [
    {
      "local_id": "LOCALID_NPC_HELPFUL_PERSON",
      "graphics_id": "OBJ_EVENT_GFX_BOY_1",
      "x": 10,
      "y": 8,
      "elevation": 3,
      "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
      "movement_range_x": 0,
      "movement_range_y": 0,
      "trainer_type": "TRAINER_TYPE_NONE",
      "trainer_sight_or_berry_tree_id": "0",
      "script": "YourMapName_EventScript_HelpfulPerson",
      "flag": "0"
    }
  ]
}
```

#### Key Object Event Parameters:

- **local_id**: Optional unique identifier for this NPC on this map
- **graphics_id**: Which sprite to use (see `OBJ_EVENT_GFX_*` constants)
- **x, y**: Position on the map (in tiles)
- **elevation**: Height level (3 is standard ground level)
- **movement_type**: How the NPC moves
- **movement_range_x/y**: How far they can wander
- **trainer_type**: Set to `TRAINER_TYPE_NONE` for non-trainer NPCs
- **script**: Function to call when interacted with
- **flag**: Game flag that controls when NPC appears (0 = always visible)

### 2. Creating NPC Scripts

Add the interaction script to your map's script files. You can use either traditional assembly or modern Poryscript syntax:

#### Assembly Version (`data/maps/YourMapName/scripts.inc`)
```assembly
YourMapName_EventScript_HelpfulPerson::
	msgbox YourMapName_Text_HelpfulPerson_Greeting, MSGBOX_NPC
	end

YourMapName_Text_HelpfulPerson_Greeting:
	.string "Hello there! Welcome to our town!\p"
	.string "The POKéMON CENTER is just north\n"
	.string "of here if you need healing.$"
```

#### Poryscript Version (`data/maps/YourMapName/scripts.pory`)
```poryscript
script YourMapName_EventScript_HelpfulPerson {
    msgbox("Hello there! Welcome to our town!\pThe POKéMON CENTER is just north of here if you need healing.", MSGBOX_NPC)
}
```

#### Basic Message Types:

- `MSGBOX_NPC`: Standard NPC dialogue
- `MSGBOX_YESNO`: Yes/No question
- `MSGBOX_DEFAULT`: Simple message box
- `MSGBOX_SIGN`: For reading signs

### 3. NPC Graphics and Animation

#### Available Graphics
Common NPC graphics include:
- `OBJ_EVENT_GFX_BOY_1`, `OBJ_EVENT_GFX_BOY_2`, `OBJ_EVENT_GFX_BOY_3`
- `OBJ_EVENT_GFX_GIRL_1`, `OBJ_EVENT_GFX_GIRL_2`, `OBJ_EVENT_GFX_GIRL_3`
- `OBJ_EVENT_GFX_MAN_1`, `OBJ_EVENT_GFX_WOMAN_1`
- `OBJ_EVENT_GFX_OLD_MAN`, `OBJ_EVENT_GFX_OLD_WOMAN`
- `OBJ_EVENT_GFX_YOUNGSTER`, `OBJ_EVENT_GFX_LASS`
- `OBJ_EVENT_GFX_POKEFAN_M`, `OBJ_EVENT_GFX_POKEFAN_F`

#### Movement Patterns
- `MOVEMENT_TYPE_NONE`: Doesn't move
- `MOVEMENT_TYPE_FACE_UP/DOWN/LEFT/RIGHT`: Faces one direction
- `MOVEMENT_TYPE_WANDER_AROUND`: Moves randomly within range
- `MOVEMENT_TYPE_WALK_UP_AND_DOWN`: Vertical pacing
- `MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT`: Horizontal pacing
- `MOVEMENT_TYPE_ROTATE_CLOCKWISE`: Rotates through directions

## Advanced NPC Features

### Item-Giving NPCs

#### Assembly Version
```assembly
YourMapName_EventScript_ItemGiver::
	checkflag FLAG_RECEIVED_POTION_FROM_NPC
	goto_if_set YourMapName_EventScript_ItemGiver_AlreadyGave
	msgbox YourMapName_Text_ItemGiver_Offer, MSGBOX_NPC
	giveitem ITEM_POTION
	goto_if_bag_full YourMapName_EventScript_ItemGiver_BagFull
	setflag FLAG_RECEIVED_POTION_FROM_NPC
	msgbox YourMapName_Text_ItemGiver_GaveItem, MSGBOX_NPC
	end

YourMapName_EventScript_ItemGiver_AlreadyGave::
	msgbox YourMapName_Text_ItemGiver_AlreadyGave, MSGBOX_NPC
	end

YourMapName_EventScript_ItemGiver_BagFull::
	msgbox YourMapName_Text_ItemGiver_BagFull, MSGBOX_NPC
	end

YourMapName_Text_ItemGiver_Offer:
	.string "You look like you could use this\n"
	.string "POTION. Take it!$"

YourMapName_Text_ItemGiver_GaveItem:
	.string "Use it wisely!$"

YourMapName_Text_ItemGiver_AlreadyGave:
	.string "I hope that POTION served you well!$"

YourMapName_Text_ItemGiver_BagFull:
	.string "Oh, your BAG is full. Come back when\n"
	.string "you have space!$"
```

#### Poryscript Version  
```poryscript
script YourMapName_EventScript_ItemGiver {
    if (flag(FLAG_RECEIVED_POTION_FROM_NPC)) {
        msgbox("I hope that POTION served you well!", MSGBOX_NPC)
    } else {
        msgbox("You look like you could use this POTION. Take it!", MSGBOX_NPC)
        if (giveitem(ITEM_POTION)) {
            setflag(FLAG_RECEIVED_POTION_FROM_NPC)
            msgbox("Use it wisely!", MSGBOX_NPC)
        } else {
            msgbox("Oh, your BAG is full. Come back when you have space!", MSGBOX_NPC)
        }
    }
}
```

### Conditional NPCs

NPCs that appear/disappear based on story progress:

```json
{
  "graphics_id": "OBJ_EVENT_GFX_SCIENTIST_1",
  "x": 5,
  "y": 12,
  "elevation": 3,
  "movement_type": "MOVEMENT_TYPE_FACE_UP",
  "movement_range_x": 0,
  "movement_range_y": 0,
  "trainer_type": "TRAINER_TYPE_NONE",
  "trainer_sight_or_berry_tree_id": "0",
  "script": "YourMapName_EventScript_Scientist",
  "flag": "FLAG_HIDE_SCIENTIST_UNTIL_QUEST_DONE"
}
```

When `FLAG_HIDE_SCIENTIST_UNTIL_QUEST_DONE` is set, the NPC will be invisible.

### Interactive Yes/No NPCs

#### Assembly Version
```assembly
YourMapName_EventScript_QuestionNPC::
	msgbox YourMapName_Text_QuestionNPC_Question, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq YourMapName_EventScript_QuestionNPC_Yes
	msgbox YourMapName_Text_QuestionNPC_No, MSGBOX_NPC
	end

YourMapName_EventScript_QuestionNPC_Yes::
	msgbox YourMapName_Text_QuestionNPC_Yes, MSGBOX_NPC
	# Do something when player says yes
	end

YourMapName_Text_QuestionNPC_Question:
	.string "Would you like to hear about\n"
	.string "type effectiveness?$"

YourMapName_Text_QuestionNPC_Yes:
	.string "Great! Fire is super effective\n"
	.string "against Grass-type POKéMON!$"

YourMapName_Text_QuestionNPC_No:
	.string "Okay, maybe another time!$"
```

#### Poryscript Version
```poryscript
script YourMapName_EventScript_QuestionNPC {
    if (msgbox("Would you like to hear about type effectiveness?", MSGBOX_YESNO) == YES) {
        msgbox("Great! Fire is super effective against Grass-type POKéMON!", MSGBOX_NPC)
        // Do something when player says yes
    } else {
        msgbox("Okay, maybe another time!", MSGBOX_NPC)
    }
}
```

### Moving NPCs with Scripts

Make NPCs move during cutscenes:

```assembly
YourMapName_EventScript_MovingNPC::
	msgbox YourMapName_Text_MovingNPC_Before, MSGBOX_NPC
	closemessage
	applymovement LOCALID_NPC_HELPER, YourMapName_Movement_WalkToPlayer
	waitmovement LOCALID_NPC_HELPER
	msgbox YourMapName_Text_MovingNPC_After, MSGBOX_NPC
	end

YourMapName_Movement_WalkToPlayer:
	walk_down
	walk_down
	walk_right
	face_player
	step_end
```

## Common NPC Patterns

### Healing NPCs
```assembly
YourMapName_EventScript_NurseNPC::
	msgbox YourMapName_Text_NurseNPC_Offer, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq YourMapName_EventScript_NurseNPC_Heal
	msgbox YourMapName_Text_NurseNPC_Declined, MSGBOX_NPC
	end

YourMapName_EventScript_NurseNPC_Heal::
	msgbox YourMapName_Text_NurseNPC_Healing, MSGBOX_NPC
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox YourMapName_Text_NurseNPC_Healed, MSGBOX_NPC
	end
```

### Information NPCs
```assembly
YourMapName_EventScript_InfoNPC::
	checkflag FLAG_BADGE01_GET
	goto_if_set YourMapName_EventScript_InfoNPC_HasBadge
	msgbox YourMapName_Text_InfoNPC_NoBadge, MSGBOX_NPC
	end

YourMapName_EventScript_InfoNPC_HasBadge::
	msgbox YourMapName_Text_InfoNPC_HasBadge, MSGBOX_NPC
	end
```

### Trading NPCs
```assembly
YourMapName_EventScript_Trader::
	msgbox YourMapName_Text_Trader_Offer, MSGBOX_NPC
	checkitem ITEM_RARE_CANDY
	compare VAR_RESULT, FALSE
	goto_if_eq YourMapName_EventScript_Trader_NoItem
	msgbox YourMapName_Text_Trader_MakeOffer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq YourMapName_EventScript_Trader_Declined
	removeitem ITEM_RARE_CANDY
	giveitem ITEM_PROTEIN
	msgbox YourMapName_Text_Trader_Traded, MSGBOX_NPC
	end
```

### Directional NPCs
NPCs that give directions:

```assembly
YourMapName_EventScript_DirectionGiver::
	faceplayer
	msgbox YourMapName_Text_DirectionGiver, MSGBOX_NPC
	closemessage
	applymovement LOCALID_NPC_DIRECTION_GIVER, Common_Movement_FaceOriginalDirection
	waitmovement LOCALID_NPC_DIRECTION_GIVER
	end

YourMapName_Text_DirectionGiver:
	.string "The GYM is to the north, past the\n"
	.string "POKéMON CENTER.\p"
	.string "Good luck with your challenge!$"
```

## Troubleshooting

### Common Issues

**NPC doesn't appear:**
- Check that the flag isn't set to hide them
- Verify coordinates are within map bounds
- Ensure elevation matches walkable areas
- Check that graphics_id is valid

**NPC appears but has no dialogue:**
- Verify script name matches exactly
- Check that scripts.inc is included in event_scripts.s
- Ensure text labels are properly formatted

**NPC appears as wrong sprite:**
- Check graphics_id against available constants
- Verify sprite exists in the graphics data
- Some sprites may be version-specific

**Movement issues:**
- Check movement_range values aren't too large
- Verify movement_type is appropriate for location
- Ensure NPC has room to move (no collision blocks)

**Script errors:**
- Check for typos in script commands
- Verify all labels end with double colons (::)
- Ensure proper indentation and syntax
- Check that referenced flags/variables exist

### Debug Tips

1. **Start with simple static NPCs** - Add movement and complexity later
2. **Use existing NPCs as templates** - Copy and modify working examples
3. **Test dialogue thoroughly** - Check all text fits in message boxes
4. **Verify flag logic** - Use debug mode to check flag states
5. **Check movement paths** - Ensure NPCs don't get stuck on collision

### Performance Notes

- Too many moving NPCs on one map can impact performance
- Complex scripts with many conditions may cause slowdown
- Large amounts of text can use significant ROM space

## Related Tutorials

- [How to Add Maps](how_to_add_maps.md) - Creating areas for your NPCs
- [How to Add Trainers](how_to_add_trainers.md) - NPCs that battle the player
- [Scripting System](scripting_basics.md) - Advanced scripting techniques

---

*Remember: Good NPCs make your world feel alive! Give them personality and purpose.*