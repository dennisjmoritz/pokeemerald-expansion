![Unbound Quest Menu Header](https://user-images.githubusercontent.com/77138753/181390831-38777fa0-9e02-47a6-b205-847f3d777ee8.png)
Copied from psf wiki so I can keep track of how to use the quests with my modifications.
# Introduction
![Demo of all Quest menu features](https://user-images.githubusercontent.com/77138753/178155255-16fa5351-8707-4f80-902e-f74801505cc1.png)

This is a recreation of [Unbound](https://www.pokecommunity.com/showthread.php?t=382178)'s Quest Menu to use in decomp projects. ghoulslash's [Quest Menu](https://www.pokecommunity.com/showthread.php?t=434462) was used as a base and was modified to mimic Unbound's variant. 

**Thank you very much** to Skeli, ghoulslash, HN, Karathan, Mcboy, Greenphx, BSBob, MM, & Tustin2121 who all contributed to this project in some way. [Please read more about their contributions and support their projects!](https://github.com/PokemonSanFran/pokeemerald/wiki/Unbound-Quest-Menu-README-Documentation/_edit#contributions)

# Features 
## Quest States
### Locked / Unlocked
![The cursor is selecting a locked quest.](https://user-images.githubusercontent.com/77138753/178154607-9ccb95f3-83fc-4564-a9b3-9bde3166ee41.png)

If a quest is locked, it appears as "????" in the quest menu. When a quest is unlocked, its name and details will appear in the menu. Once unlocked, quests should always retain this status.

### Active
![The cursor is selecting an active quest.](https://user-images.githubusercontent.com/77138753/178154592-f8b57ce8-dcde-43a3-8bd4-d9ccb678c2a2.png)

Currently in progress. When a quest is set as active, it is automatically unlocked.

### Reward
![The cursor is selecting a reward quest.](https://user-images.githubusercontent.com/77138753/178154614-59ab071d-7d18-4293-a79e-4f6226d324e7.png)

Has been completed, but the player has not received the reward for it yet. Reward state quests are no longer active.

### Complete
![The cursor is selecting a complete quest.](https://user-images.githubusercontent.com/77138753/178154602-8ab220f4-4259-4ac5-9195-53e19a9f66f0.png)

Has been completed and the player has received the reward. Complete quests are no longer in the reward state.

Subquests only have two states - Locked and Complete.

## Subquests
![Demo of the subquest functionality.](https://user-images.githubusercontent.com/77138753/178155037-94102562-40cb-4cb4-8d68-866fd51b42e8.png)

A quest can have children or subquests. This is for long quests with several different parts that you may want to track individually. Quests that have subquests are designed by the A button icon in the list menu. Pressing A will show all of the subquests and the completion of those quests.

### Examples
#### Emerald
* **Parent Quest**: Collect all the Gold Symbols from the Battle Frontier
* **Sub Quest 1**: Gold Knowledge Symbol
* **Sub Quest 2**: Gold Guts Symbol
* **Sub Quest 3**: Gold Tactics Symbol
* **Sub Quest 4**: Gold Luck Symbol
* **Sub Quest 5**: Gold Spirits Symbol
* **Sub Quest 6**: Gold Brave Symbol
* **Sub Quest 7**: Gold Ability Symbol

#### Unbound
* **Parent Quest**: Collect all the Zygarde Cells
* **Sub Quest 1**: Frozen Heights 

et cetera.

## Filter Modes 
![Demo of filter mode.](https://user-images.githubusercontent.com/77138753/178154604-f509680b-9301-4fb6-be9e-f4439bcc40a3.png)

When the player presses the R button while in the Quest Menu, they will enter Filter Mode. Filter mode will show all of the quests of a particular state. Players can cycle through the different quest types by repeatedly pressing the R Button. 

The player's last filter mode is not remembered upon exiting the entire menu, but it is remembered when examining a subquest.

Filter modes do not work when looking at subquests.

## Alphabetical Sort
![Demo of alphabetical mode.](https://user-images.githubusercontent.com/77138753/178154594-6aaa0bb6-b999-4c56-acca-62c8357c1711.png)

If the player presses the Start button while in the Quest Menu, the list of quests within the current view will be sorted alphabetically. 

This sorting will remain if the player changes to a different Filter Mode, will be restored if the player enters and exits a subquest, but will not be remembered upon exiting the entire menu.

Pressing Start will revert to the default sort.

Alphabetical sort does not work when looking at subquests.

## Favorite Quests
![Demo of favoriting functionality.](https://user-images.githubusercontent.com/77138753/178154603-58acecd2-b99e-4b06-b4e2-8551943d3ccf.png)

If the player presses the Select button while their cursor is hovering over a Quest, that quest's title will turn green and be automatically placed at the top of the list. Pressing Select again will return the quest to its original position in the list.

Favorite quests are remembered even after the player exits the quest menu.

Favorite quests do not work when looking at subquests.

# Installation
These instructions assume that you can build [pokeemerald](https://github.com/pret/pokeemerald), have a basic understanding of C, and are familiar with using the in-game scripting language. If you do not, please watch the tutorials series from [Team Aqua's Hideout](https://youtube.com/playlist?list=PLLNv9Lq6kDmTIYfN5NvgQRvfOHTOXl0uU).

## git merge (recommended)

From the root directory of your project, run the following commands in your terminal program of choice:

```bash
git remote add psf-emerald https://github.com/PokemonSanFran/pokeemerald/ # This adds our team's pokeemerald branch as a remote repo.
git pull psf-emerald unbound-quest-menu #This pulls in the unbound-quest-menu feature branch
```

### pokefirered
Greenphx (Greenphx#5428) has ported this to pokefirered. This manual should function similarly.

```bash
git remote greenphx https://github.com/Greenphx9/pokefirered/ # This adds our their pokefirered branch as a remote repo.
git pull greenphx unbound-quest-menu #This pulls in the unbound-quest-menu feature branch
```

## Manual merge
If your project is:
* Too far behind pokeemerald
* Using a different base (pokeemerald-expansion
* Some other reason that I can't think of

You can manually implement the features using [the diff between this branch and vanilla pokeemerald](https://github.com/PokemonSanFran/pokeemerald/compare/unbound-quest-menu/) as a guide. You will need to manually edit or create each of these files in your own project to properly recreate the feature.


## Warnings
### ghoulslash's menu
You cannot use this feature and ghoulslash's quest menu at the same time. You will need to use one or the other. If you have already pulled in ghoulslash's, you will need to do some work merging conflicts after pulling this one in.

### Wrapping menu
![Gif displaying the list menu wrapping functionality in Unbound.](https://user-images.githubusercontent.com/77138753/178154617-059e9915-c8a1-4c35-b45f-a42fe8064b97.png)

Unbound's list menus wrap, meaning that when you press up on the first item of a list, you are brought to the last item (and vice versa). Emerald has this behavior turned off. Pulling in this branch will turn on this functionality for all list menus in your project. If you do not want this functionality, you will need to disable it.

#### Disabling wrapping
To remove this functionality, you'll need to remove some lines from [`src/list_menu.c`](https://github.com/PokemonSanFran/pokeemerald/blob/668853c9f4e37d93800b8edfcbeae8705e8e50fd/src/list_menu.c#L426-L428).

```diff c
-   s32 currentPosition = list->scrollOffset + list->selectedRow;
-    u8 lastPositon = list->template.totalItems - 1;
-
    if (JOY_NEW(A_BUTTON))
    {
        return list->template.items[list->scrollOffset + list->selectedRow].id;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return LIST_CANCEL;
    }
 else if (JOY_REPEAT(DPAD_UP))
    {
-        if (currentPosition == 0)
-            ListMenuChangeSelection(list,TRUE,lastPositon,TRUE);
-        else
            ListMenuChangeSelection(list, TRUE, 1, FALSE);

        return LIST_NOTHING_CHOSEN;
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
-        if (currentPosition == lastPositon)
-            ListMenuChangeSelection(list,TRUE,lastPositon, FALSE);
-        else
            ListMenuChangeSelection(list, TRUE, 1, TRUE);
```
### Saveblock2 space
The 30 parent quests and 30 subquests that come with this branch consume 25 bytes in Saveblock2. Due to the way the feature has been set up, the current system can only support approximately 100 parent quests and 168 subquests. (Parent quests use 5 bits each, and child quests use 1 bit each.) If you want to add more than that, you will need to free up more space on the saveblock.

# Menu Anatomy
## Quests
![Anatomy breakdown of a quest](https://user-images.githubusercontent.com/77138753/178156627-30b43607-00b8-4258-85b3-5dac6cca948c.png)

* A: Current context of the menu
* B: Number of quests relevant to this filter mode/number of total quests
* C: Name of the quest.
* D: Indicates that this quest has subquests.
* E: State of the quest.
* F: Map where the player can go to start the quest.
* G: Quest's sprite. This can be an object (NPC), item, or Pokémon.
* H: Description of the quest. There are two variants - one for when the quest is active, and one for when the quest is complete.

## Subquests
![Anatomy breakdown of a subquest](https://user-images.githubusercontent.com/77138753/178156639-6df9f93e-a5f3-4bf9-9486-d5258e46d6b2.png)

* A: Name of the parent quest for these subquests
* B: Number of completed subquests for this parent quest/ number of total subquests for this parent quest
* C: Name of the subquest.
* D: State of the subquest. Only shows if complete.
* E: Map where the player can go to complete the subquest.
* F: Subquest's sprite. This can be an object (NPC), item, or Pokémon.
* G: Description of the subquest. Only shows if complete.

# Usage
##  Adding New Quests
There are 30 blank parent quests for you to edit. 

### [`include/constants/quests.h`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/include/constants/quests.h)
```c
#define QUEST_29        28
#define QUEST_30        29
#define QUEST_INFINITY_STONES 30
#define QUEST_COUNT     (QUEST_INFINITY_STONES + 1)
```
Add a quest definition at the end of this list. You can name these whatever you want, like `QUEST_INFINITY_STONES`. These are the names you will use when you are scripting to refer to the quests. You will also need to update the value of QUEST\_COUNT to be your last quest in the list, +1.

### [`src/strings.c`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/src/strings.c)
```c
const u8 gText_SideQuestName_31[] = _("Endgame");
const u8 gText_SideQuestDesc_31[] =_("Help fix the balance of the universe!\nGather the Infinity Gems.");
const u8 gText_SideQuestDoneDesc_31[] = _("All in balance, as it should be.");
const u8 gText_SideQuestMap31[] = _("New York City");
```
These are all of the strings being used for your quest. 

### [`include/strings.h`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/include/strings.h)
```c
extern const u8 gText_SideQuestName_31[];
extern const u8 gText_SideQuestDesc_31[];
extern const u8 gText_SideQuestDoneDesc_31[];
extern const u8 gText_SideQuestMap31[];
```
You will also need to define them in the header file.

### [`src/quests.c`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/src/quests.c)
```c
side_quest(
      gText_SideQuestName_31, //side quest name string
      gText_SideQuestDesc_31, //side quest description string 
      gText_SideQuestDoneDesc_31, //side quest complete description string
      gText_SideQuestMap31, //side quest map string
      OBJ_EVENT_GFX_MAXIE, //quest sprite id
      OBJECT, //quest sprite type
      NULL, //subquest struct
      0 //number of subquest
),
```
Add a quest as the last member of the `sSideQuests` struct.

#### Existing strings
If you are using an existing location in your game for your map strings, like the Cave of Origin, you can just use the strings listed in [`src/data/region_map/region_map_entries.h`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/src/data/region_map/region_map_entries.h), but you'll need to remove the `static` at the beginning of the line you want to use. This applies to any of the strings here.

#### Sprites
Quests display a sprite of your choice in the bottom left. You can choose between an item, an NPC (object), or a Pokémon.
* Object / NPC IDs are listed in [`include/constants/event_objects.h`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/include/constants/event_objects.h). In the next field, use `OBJECT`.
* Item IDs are listed in [`include/constants/items.h`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/include/constants/items.h). In the next field, use `ITEM`.
* Species IDs are listed in [`include/constants/species.h`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/include/constants/species.h). In the next field, use `PKMN`.

If this quest has no subquests, then the last two values should be `NULL` and `0`. 

## Add New Subquests
Quest 1 has 10 blank subquests and Quest 2 has 20. You can edit or delete as you see fit.

### [`include/constants/quests.h`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/include/constants/quests.h)
```c
#define QUEST_1_SUB_COUNT 10
#define QUEST_2_SUB_COUNT 20
#define QUEST_INFINITY_SUB_COUNT 6
#define SUB_QUEST_COUNT (QUEST_1_SUB_COUNT + QUEST_2_SUB_COUNT + QUEST_INFINITY_SUB_COUNT)
```
Define the number of subquests that you'll be using. You will also need to update the total number of subquests.

### [`src/strings.c`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/src/strings.c)
```c
const u8 gText_SideQuest31_SubName1[] = _("Space Gem");
const u8 gText_SideQuest31_SubDesc1[] = _("You defeated Tony to get the\nSpace Gem.");
const u8 gText_SideQuest31_SubMap1[] = _("Bulgaria");

const u8 gText_SideQuest31_SubName2[] = _("Mind Gem");
const u8 gText_SideQuest31_SubDesc2[] = _("You defeated Hank to get the\nMind Gem.");
const u8 gText_SideQuest31_SubMap2[] = _("Illonis");

const u8 gText_SideQuest31_SubName3[] = _("Soul Gem");
const u8 gText_SideQuest31_SubDesc3[] = _("You defeated Stephen to get the\nSoul Gem.");
const u8 gText_SideQuest31_SubMap3[] = _("Pennsylvania");

const u8 gText_SideQuest31_SubName4[] = _("Reality Gem");
const u8 gText_SideQuest31_SubDesc4[] = _("You defeated Reed to get the\nReality Gem.");
const u8 gText_SideQuest31_SubMap4[] = _("California");

const u8 gText_SideQuest31_SubName5[] = _("Time Gem");
const u8 gText_SideQuest31_SubDesc5[] = _("You defeated Steve to get the\nTime Gem.");
const u8 gText_SideQuest31_SubMap5[] = _("Manhattan");

const u8 gText_SideQuest31_SubName6[] = _("Power Gem");
const u8 gText_SideQuest31_SubDesc6[] = _("You defeated King to get the\nPower Gem.");
const u8 gText_SideQuest31_SubMap6[] = _("Atlantis");
```
These are all of the strings being used for your subquest. 

### [`include/strings.h`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/include/strings.h)

```c
extern const u8 gText_SideQuest31_SubName1[];
extern const u8 gText_SideQuest31_SubDesc1[];
extern const u8 gText_SideQuest31_SubMap1[];

extern const u8 gText_SideQuest31_SubName2[];
extern const u8 gText_SideQuest31_SubDesc2[];
extern const u8 gText_SideQuest31_SubMap2[];

extern const u8 gText_SideQuest31_SubName3[];
extern const u8 gText_SideQuest31_SubDesc3[];
extern const u8 gText_SideQuest31_SubMap3[];

extern const u8 gText_SideQuest31_SubName4[];
extern const u8 gText_SideQuest31_SubDesc4[];
extern const u8 gText_SideQuest31_SubMap4[];

extern const u8 gText_SideQuest31_SubName5[];
extern const u8 gText_SideQuest31_SubDesc5[];
extern const u8 gText_SideQuest31_SubMap5[];

extern const u8 gText_SideQuest31_SubName6[];
extern const u8 gText_SideQuest31_SubDesc6[];
extern const u8 gText_SideQuest31_SubMap6[];
```
You will also need to define them in the header file.

### [`src/quests.c`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/src/quests.c)
```c
static const struct SubQuest sSubQuests31[QUEST_INFINITY_SUB_COUNT] =
{
    sub_quest(
          30,
          gText_SideQuest31_SubName1,
          gText_SideQuest31_SubDesc1,
          gText_SideQuest31_SubMap1,
          SPECIES_PORYGON2,
          PKMN,
          sText_QuestMenu_Caught
    ),

    sub_quest(
          31,
          gText_SideQuest31_SubName2,
          gText_SideQuest31_SubDesc2,
          gText_SideQuest31_SubMap2,
          SPECIES_URSARING,
          PKMN,
          sText_QuestMenu_Caught
    ),

    sub_quest(
          32,
          gText_SideQuest31_SubName3,
          gText_SideQuest31_SubDesc3,
          gText_SideQuest31_SubMap3,
          OBJ_EVENT_GFX_HEX_MANIAC,
          OBJECT,
          sText_QuestMenu_Found
    ),

    sub_quest(
          33,
          gText_SideQuest31_SubName4,
          gText_SideQuest31_SubDesc4,
          gText_SideQuest31_SubMap4,
          ITEM_PETAYA_BERRY,
          ITEM,
          sText_QuestMenu_Found
    ),

    sub_quest(
          34,
          gText_SideQuest31_SubName5,
          gText_SideQuest31_SubDesc5,
          gText_SideQuest31_SubMap5,
          ITEM_GUARD_SPEC,
          ITEM,
          sText_QuestMenu_Read
    ),

    sub_quest(
          35,
          gText_SideQuest31_SubName6,
          gText_SideQuest31_SubDesc6,
          gText_SideQuest31_SubMap6,
          OBJ_EVENT_GFX_SWIMMER_M,
          OBJECT,
          sText_QuestMenu_Read
    ),
};
```
This new struct should sit above the sSideQuests struct. Each quest that has subquests needs its struct to hold the data for its children's subquests. In the declaration of the struct, you should be using the same number of quests that you previously defined. 

Regardless of their parent, **each subquest needs its own unique ID**. 

```c
static const u8 sText_QuestMenu_Caught[] = _("Caught");
static const u8 sText_QuestMenu_Found[] = _("Found");
static const u8 sText_QuestMenu_Read[] = _("Read");
```
The last member of the struct uses a string that is declared at the top of [`src/strings.c`](https://github.com/PokemonSanFran/pokeemerald/tree/unbound-quest-menu/src/strings.c). Each subquest can have its unique label, much like sprites.

```c
    side_quest(
      gText_SideQuestName_31, //side quest name string
      gText_SideQuestDesc_31, //side quest description string
      gText_SideQuestDoneDesc_31, //side quest complete description string
      gText_SideQuestMap31, //side quest map string
      OBJ_EVENT_GFX_MAXIE, //quest sprite id
      OBJECT, //quest sprite type
      sSubQuests31, //subquest struct
      QUEST_INFINITY_SUB_COUNT //number of subquest
),
```
If you are adding subquests to a quest that previously did not have them, you will need to edit the last two members of that element to properly assign the children to the parent _and_ declare the correct number of subquests.

#### Sprites
Sprites work the same way for subquests as they do for main quests.

## Accessing In-Game
Calling the function 
```c
QuestMenu_Init(0, <callback>)
```
will open the Quest Menu. If the flag `FLAG_SYS_QUEST_MENU_GET` is set, the player will be able to access it from the Start Menu.

## Scripting Commands

### Open Quest Menu
![Demo of QUEST\_MENU\_OPEN.](https://user-images.githubusercontent.com/77138753/178154612-cd3478c8-5550-4617-9a6f-f65686ae1ee9.png)

```c
openquestmenu
```
```c
questmenu QUEST_MENU_OPEN 0
```
Either of these will open the quest menu in-game.

### Set Start Menu Flag
![Demo of FLAG\_SYS\_QUEST\_MENU\_GET.](https://user-images.githubusercontent.com/77138753/178154605-20ef6c19-bb85-428c-9aff-d0bcb85b565f.png)

```c
setflag FLAG_SYS_QUEST_MENU_GET
```
When this flag is set, the option to look at Quest Menu will be added to the Start Menu.

### Change State 
![Demo of SET\_STATE functionality.](https://user-images.githubusercontent.com/77138753/178154598-09fe8d98-cf5d-4f93-8ac2-293ac3890661.png)

```c
questmenu QUEST_MENU_SET_ACTIVE QUEST_INFINITY_STONES
subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_INFINITY_STONES, SUB_QUEST_3

questmenu QUEST_MENU_SET_REWARD QUEST_1 

questmenu QUEST_MENU_COMPLETE_QUEST QUEST_2 
openquestmenu
```
Set `QUEST_INFINITY_STONES`'s state to active, `SUB_QUEST_3` of `QUEST_INFINITY_STONES` to Complete, `QUEST_1`'s state to Reward, and `QUEST_2`'s state to Complete, and then open the menu.

### Announce State Change
![Demo of startquest / completequest functionality.](https://user-images.githubusercontent.com/77138753/183271050-5bf514bb-8304-4b29-88fa-5df70ae4f78a.png)

```c
openquestmenu
startquest QUEST_INFINITY_STONES
openquestmenu
completequest QUEST_INFINITY_STONES
openquestmenu
end
```
Open the quest menu, set `QUEST_INFINITY_STONES`'s state to active & announce the player of this change. Open the quest menu, set `QUEST_INFINITY_STONES`'s state to complete & announce this change, open the quest menu. These do not exist for quest states, but can easily be added.

### Check State
![Demo of CHECK\_STATE functionality.](https://user-images.githubusercontent.com/77138753/178154600-a862c949-ffa9-4e6c-b0d4-930db20bc096.png)

```c
    setflag FLAG_SYS_QUEST_MENU_GET
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_INFINITY_STONES
    questmenu QUEST_MENU_CHECK_COMPLETE QUEST_INFINITY_STONES
    msgbox QuestState, MSGBOX_SIGN
    goto_if_eq VAR_RESULT, TRUE, CelebrateEndgame
    end

CelebrateEndgame::
    special DoDomeConfetti
    return
```
If `QUEST_INFINITY_STONES` is completed,`gSpecialVar_Result` / `VAR_RESULT` will return true. If not, will return false. This also works for `QUEST_MENU_CHECK_INACTIVE`, `QUEST_MENU_CHECK_ACTIVE`, and `QUEST_MENU_CHECK_REWARD`.

In this example, set `QUEST_INFINITY_STONES`'s state to complete, check to see if `QUEST_INFINITY_STONES` has the complete state, and if so, shower confetti.

#### Extra Macros
This branch also comes with a series of macros to provide similar functionality but with shortcuts for easier scripting. They are as follows:

* `returnqueststate`

* `goto_if_quest_inactive`
* `goto_if_quest_active`
* `goto_if_quest_reward`
* `goto_if_quest_complete`

* `goto_if_quest_not_inactive`
* `goto_if_quest_not_active`
* `goto_if_quest_not_reward`
* `goto_if_quest_not_complete`

* `call_if_quest_inactive`
* `call_if_quest_active`
* `call_if_quest_reward`
* `call_if_quest_complete`

* `call_if_quest_not_inactive`
* `call_if_quest_not_active`
* `call_if_quest_not_reward`
* `call_if_quest_not_complete`

The above example can be performed in a number of different ways using these macros.

```c
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_INFINITY_STONES
    goto_if_quest_complete QUEST_INFINITY_STONES, CelebrateEndgame
```

```c
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_INFINITY_STONES
    goto_if_quest_not_reward QUEST_INFINITY_STONES, CelebrateEndgame
```

```c
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_INFINITY_STONES
    call_if_quest_not_reward QUEST_INFINITY_STONES, CelebrateEndgame
```

```c
    questmenu QUEST_MENU_COMPLETE_QUEST,QUEST_INFINITY_STONES
    returnqueststate QUEST_INFINITY_STONES

    switch VAR_RESULT
	case 3, DoSomethingElse
	case 4, CelebrateEndgame
    //case 1: inactive state
    //case 2: active state
    //case 3: reward state
    //case 4: complete state
```

#### Check Subquest State 

```c
    subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INFINITY_STONES, SUB_QUEST_3
```
This can also be used to check the completion of subquests.

### Buffer Quest Name
![Demo of BUFFER\_QUEST\_NAME functionality.](https://user-images.githubusercontent.com/77138753/178154597-d2286aa0-8bb5-4063-8e57-47ed031adb7e.png)

```c
    questmenu QUEST_MENU_BUFFER_QUEST_NAME QUEST_INFINITY_STONES
    msgbox QuestName MSGBOX_SIGN

QuestName: .string "{STR_VAR_1}$"
```
Store the name of `QUEST_INFINITY_STONES` in `gStringVar1` / `{STR_VAR_1}`, or the `QUEST_INFINITY_STONES` sub quest 3's name.

In this example, buffer the name of `QUEST_QUEST_INFINITY_STONES`. This buffer is then called when displaying a sign message box.

#### Buffer Subquest Name
```c
    subquestmenu QUEST_MENU_BUFFER_QUEST_NAME QUEST_INFINITY_STONES SUB_QUEST_3
    msgbox QuestName MSGBOX_SIGN

QuestName: .string "{STR_VAR_1}$"
```
This can also be used for subquests.

### Unlock Quest
```c
questmenu QUEST_MENU_UNLOCK_QUEST QUEST_QUEST_INFINITY_STONES
```
Set `QUEST_INFINITY_STONES`'s state to unlocked. There is no reason for this ever to be used because it will happen automatically when applying to any other state.

# Known Issues

## Artifacting 
![Gif displaying the artifacting bug.](https://user-images.githubusercontent.com/77138753/178154608-5250bfa2-874d-4ad4-b042-a7e3674f59ea.png)

When moving from a quest that displays an object to a quest that displays a non-object, a strange artifact will appear on the screen for a frame or two. This cannot be consistently reproduced, unfortunately.

If you can help resolve this issue, please feel free to reach out!

## Background Image

Fans of Unbound will notice that this is not the same background that is used in Unbound. I was unable to secure permission to use the original background, but several alternatives are provided. You are free to use any variant, as long as the creator is credited.

In order to make the text more accessible, this branch is using a modified version of Skeli's FRLG-themed background. The original is provided below. 

|Theme|FRLG|[Pokedex Plus](https://github.com/TheXaman/pokeemerald/tree/tx_pokedexPlus_hgss)|Dark|
|---|---|---|---|
|Creator|Skeli|missiri|missiri|
|Image|![Skeli's FRLG style Quest Menu background](https://user-images.githubusercontent.com/77138753/178154596-4140cee3-ecb1-4121-8beb-c72431344b65.png)|![missiri's Pokedex Plus style Quest Menu background](https://media.discordapp.net/attachments/1058965040214048788/1058965326504677496/quest_menu.png)|![missiri's Dark style Quest Menu background](https://media.discordapp.net/attachments/1058965040214048788/1058965326722760714/quest_menu10.png)|

# Support

## Frequently Asked Questions (FAQ)

### `too many arguments to function 'CreateMonIcon'`
If you are using any branches from [pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion) and get this error, it is because pokeemerald-expansion uses one less argument in `CreateMonIcon`. Vanilla Emerald has an argument for dealing with Deoxys forms, but Expansion handles forms in a more elegant way and does not use this argument.

#### [`src/quests.c`](https://github.com/PokemonSanFran/pokeemerald/blob/2ee6a3e8a7070ef017def323e86dad73bb75b85e/src/quests.c#L2196)
```diff c
- spriteId = CreateMonIcon(itemId, SpriteCallbackDummy, 20, 132, 0, 1, 1);
+ spriteId = CreateMonIcon(itemId, SpriteCallbackDummy, 20, 132, 0, 1);
```
## Other Questions

If you have read all of the documentation here and still have questions, please [ask a good question](https://www.freecodecamp.org/news/how-to-ask-good-questions-as-a-developer-9f71ff809b63/) in the [pokeemerald channel of the pret Discord server](https://discord.gg/yG8zpMVr8x). You can tag `psf#2983` and we will try to help if we can.

# Donations
If you got some use out of this feature, please consider donating. 
We are currently not taking any donations, so please donate to some of our favorite charities.

* [Centre for Effective Altruism USA Inc.](https://www.charitynavigator.org/ein/471988398)
* [Doctors Without Borders, USA](https://www.charitynavigator.org/ein/133433452)
* [The Climate Reality Project](https://www.charitynavigator.org/ein/870745629)
* [First Nations Development Institute](https://www.charitynavigator.org/ein/541254491)

# Contributors 
## [Skeli#3917](https://www.youtube.com/channel/UCRIShSkz-VJWqQT83KQlNjg)
* Developed the original Unbound menu
* Provided a variant of the current background
* Provided an implementation of fading text
* Suggested ways to reduce the size of quests on saveblock2

## [ghoulslash#3839](https://www.pokecommunity.com/member.php?u=581824)
* [Developed the original Quest Menu](https://www.pokecommunity.com/showthread.php?t=434462)
* Helped debug adding a new macro to vanilla
* Helped debug object priority for sprite creation
* Provided bitwise operation for removing quest status

## HN (PSF Developer)
* A lot of these aren't written down because we meet in voice calls, but HN was instrumental in getting this working.

## [Karathan#1337](https://github.com/SBird1337/)
* Explained printing encoded strings via MgbaPrintf 
* Suggested ways to reduce the size of quests on saveblock2
* Suggested ways to allocate memory for prepending/append of the quest name
* Helped debug adding the UI background and palette

## [MCboy#0891](https://github.com/atasro2/pwaa1)
* Helped debug and refactor the implementation of fading text
* Suggested ways to fix the object fading issue

## [Greenphx#5428](https://github.com/Greenphx9)
* Ported this feature to pokefirered

## [MGriffin#3997](https://www.pokecommunity.com/member.php?u=471077) / [Deokishisu#3251](https://www.pokecommunity.com/member.php?u=22062)
* Suggested ways to reduce the size of quests on saveblock2

## [BSBob#4144](https://github.com/nielsmittertreiner)
* Provided implementation for prepending/append of the quest name

## **MM (PSF Developer)**
* Pointed out that the W stood for Wumbo.
* Proofread this documentation

## [Raymie Humbert](https://twitter.com/raymieX)
* Designed the banner header

## [missiri#4895]()
* Provided two alternate backgrounds

## [Tustin2121](https://github.com/tustin2121)
* Fixed the object fading issue

## [RavePossum](https://github.com/ravepossum)
* Updated branch to properly build when using modern compiler

## [RAP Yogurt](https://steamcommunity.com/profiles/76561198116557987)
* Found a typo in the documentation

# CHANGELOG 
All changes to this project will be documented in this section. The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), and this project tries to adhere to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## Unreleased

* Subquests structs (`sSubQuests1`, `sSubQuests2`) have been merged into a singular struct, and the assignment of subquests to parent quests is now done with the definition of struct elements in `sSideQuests`. ([MeekRhino#2126](https://github.com/meekrhino))
* Magic numbers for subquest ids have been replaced with constants that are relative to the parent quest, allowing for easier addition and removal of subquests. It will no longer be required to renumber every quest to accommodate new or old ones. ([MeekRhino#2126](https://github.com/meekrhino))
* Constants are used for identifying members of the `sSideQuests` struct, making it easier to identify individual quests. ([MeekRhino#2126](https://github.com/meekrhino))
* `QuestMenu_GetSetSubquestState` and `subquestmenu` no longer take the ID of the parent quest, and will now only function using the specific ID  of the subquest. Each subquest can be accessed via an assigned constant, cutting down on the amount of code and memorization required to call subquests.

## [1.1.5] - 2024-04-06
### Added
* Updated branch to properly build when using modern compiler. ([RavePossum](https://github.com/ravepossum)) · ([cd904877d](https://github.com/PokemonSanFran/pokeemerald/commit/cd904877d2c3ecba46eed866c6c813426b8b9b94))

## [1.1.4] - 2023-5-3
### Fixed
* Unbound's Quest Menu has the object in the bottom left corner of the screen fade out when the player enters or leaves a subquest. This feature did not replicate that functionality. ([Tustin2121](https://github.com/tustin2121)) · ([c4938c4](https://github.com/PokemonSanFran/pokeemerald/commit/c4938c48d2789b2599f9e22b135a8de9428de714))

## [1.1.3] - 2023-5-3
### Fixed
* Using `QUEST_MENU_COMPLETE_QUEST` did not properly remove the Active state from a quest. · ([791d13b](https://github.com/PokemonSanFran/pokeemerald/commit/791d13bc79824ac1613b1cb011aff25c045e62b3))

## [1.1.2] - 2022-10-13
### Fixed
* Changed the data type for the member `sprite` within the `SubQuest` and `SideQuest` structs from u8 to u16 to allow sprites with an index higher than 255 to be shown. ([Archie#5000](https://www.youtube.com/channel/UCVVxdZT8jgRHNhmde63G77Q)) · ([74c7e4a](https://github.com/PokemonSanFran/pokeemerald/commit/74c7e4a810ce2c2b1212c8f11248c90ef966f6a3))

## [1.1.1] - 2022-08-07
### Fixed
* Removed the changes from pret's master. There was a rebase on the last set of commits that did not go as intended, and this wasn't noticed until several hours later. This will, unfortunately, mess up the history of the people that pulled in the 11-hour window. My sincerest apologies about that. ([Lunos#4026](https://github.com/LOuroboros))

## [1.1.0] - 2022-08-06
### Added
* Added a pair of macros for the announcement of starting and ending quests. This will make it easier for players to understand the consequences of their actions and provide tighter testing feedback loops for developers. ([Lunos#4026](https://github.com/LOuroboros)) · ([c3c06d5](https://github.com/PokemonSanFran/pokeemerald/commit/c3c06d52221b7ec883bf4e0442831673412d975a))
* Added a series of macros that check if a quest has a specific state, and performs `goto_if_eq` or `call_if_eq`. This will allow developers to perform more complex scripts based on quest state. ([Lunos#4026](https://github.com/LOuroboros)) · ([7b6f345](https://github.com/PokemonSanFran/pokeemerald/commit/7b6f34510f10f508d6f0e42c0a21f82877d489c7))
* Added a script command which looks at a quest and returns a value corresponding to the quest's state. This will allow developers to more easily perform more complex scripts based on quest state. · ([d91a61d](https://github.com/PokemonSanFran/pokeemerald/commit/d91a61d87183b6920216a567d61a9d6e9cb1069b))

### Removed
* Removed `enum SubQuestTypes`, `gSubQuests1`, `gSubQuests2`, and `gSideQuests` from `include/quests.h`. These are old declarations from an unreleased version. ([MeekRhino#2126](https://github.com/meekrhino)) · ([0867a51](https://github.com/PokemonSanFran/pokeemerald/commit/0867a51cb231dbdfae6da0f067984bf08d72c7bb))

### Fixed
* Fixed the Palette Lag issue by freeing the sprite but not the palette until the next item in the list is loaded. ([Skeli#3917](https://www.youtube.com/channel/UCRIShSkz-VJWqQT83KQlNjg)) · ([b1a2b77](https://github.com/PokemonSanFran/pokeemerald/commit/b1a2b77cee8ce32efe8a953566e95838788cda10))
* Fixed the spacing between the parent quest title and the A Button to be more closely aligned with Unbound's Quest Menu. ([Skeli#3917](https://www.youtube.com/channel/UCRIShSkz-VJWqQT83KQlNjg)) · ([147df39](https://github.com/PokemonSanFran/pokeemerald/commit/147df390250eb539af434b82897e3b97490e2ebe))
* Fixed the labeling of `FLAG_UNUSED_0x264`. ([HunarPG#2786](https://github.com/HunarPG/)) · ([4bf0509](https://github.com/PokemonSanFran/pokeemerald/commit/4bf05097a25c96b5b647d8fcad69dda4a3900ee7))
* Restored correct version of tools/mid2agb/agb.cpp. ([HunarPG#2786](https://github.com/HunarPG/)) · ([2ee6a3e](https://github.com/PokemonSanFran/pokeemerald/commit/2ee6a3e8a7070ef017def323e86dad73bb75b85e))

## [1.0.1] - 2022-07-20
### Fixed
* Memory would not be appropriately allocated when the number of subquests being listed was greater than the total number of parent quests ([Lunos#4026](https://github.com/LOuroboros)) · ([6f8422a](https://github.com/PokemonSanFran/pokeemerald/commit/6f8422abf258d384d985c1080b07b95a93154758))
* Number of items in the list was not being refreshed when entering a subquest, causing a visual issue when the number of subquests was greater than the number of previously shown quests ([Lunos#4026](https://github.com/LOuroboros)) · ([953f0c](https://github.com/PokemonSanFran/pokeemerald/commit/953f0ce7bcad317d43f23cbd2b5609961a06cdb9))
* The function generating the list was not looking at all possible quests, causing some filters to appear empty after the previous fix was implemented · ([953f0c](https://github.com/PokemonSanFran/pokeemerald/commit/953f0ce7bcad317d43f23cbd2b5609961a06cdb9))