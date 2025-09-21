.equ SIGN_LADY_READY, VAR_TEMP_2

PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
	.byte 0

PalletTown_OnTransition::
	setworldmapflag FLAG_TEMP_1
// Replaced FLAG_WORLD_MAP_PALLET_TOWN with FLAG_TEMP_1
	call_if_set FLAG_TEMP_1, PalletTown_EventScript_TryReadySignLady
// Replaced FLAG_PALLET_LADY_NOT_BLOCKING_SIGN with FLAG_TEMP_1
	call_if_eq VAR_TEMP_0, 0, PalletTown_EventScript_SetSignLadyPos
// Replaced VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY with VAR_TEMP_0
	call_if_eq VAR_TEMP_0, 1, PalletTown_EventScript_SetSignLadyDone
// Replaced VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY with VAR_TEMP_0
	end

PalletTown_EventScript_TryReadySignLady::
// Replaced FLAG_OPENED_START_MENU with FLAG_TEMP_1
// Replaced VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY with VAR_TEMP_0
	setvar VAR_TEMP_0, 1
// Replaced VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY with VAR_TEMP_0
	return

PalletTown_EventScript_SetSignLadyDone::
	setvar VAR_TEMP_0, 2
// Replaced VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY with VAR_TEMP_0
	return

PalletTown_EventScript_SetSignLadyPos::
	goto_if_set FLAG_TEMP_1, PalletTown_EventScript_MoveSignLadyToRouteEntrance
// Replaced FLAG_PALLET_LADY_NOT_BLOCKING_SIGN with FLAG_TEMP_1
	setobjectxyperm LOCALID_PALLET_SIGN_LADY, 5, 15
	setobjectmovementtype LOCALID_PALLET_SIGN_LADY, MOVEMENT_TYPE_FACE_UP
	return

PalletTown_EventScript_MoveSignLadyToRouteEntrance::
	setobjectxyperm LOCALID_PALLET_SIGN_LADY, 12, 2
	setobjectmovementtype LOCALID_PALLET_SIGN_LADY, MOVEMENT_TYPE_FACE_DOWN
	setvar SIGN_LADY_READY, TRUE
	return

PalletTown_OnFrame::
	map_script_2 VAR_TEMP_0, 2, PalletTown_EventScript_OakRatingScene
// Replaced VAR_MAP_SCENE_PALLET_TOWN_OAK with VAR_TEMP_0
	.2byte 0

@ Oak approaches player after exiting their house post Elite Four to check if they should receieve the National Dex
PalletTown_EventScript_OakRatingScene::
	lockall
	setobjectxyperm LOCALID_PALLET_PROF_OAK, 14, 14
	setobjectmovementtype LOCALID_PALLET_PROF_OAK, MOVEMENT_TYPE_FACE_LEFT
	addobject LOCALID_PALLET_PROF_OAK
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToPlayersDoor
	waitmovement 0
	goto_if_unset FLAG_TEMP_1, PalletTown_EventScript_NotBeenToOneIslandYet
// Replaced FLAG_WORLD_MAP_ONE_ISLAND with FLAG_TEMP_1
	msgbox PalletTown_Text_OakLetMeSeePokedex
	setvar VAR_0x8004, 0
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring STR_VAR_1, VAR_0x8008
	buffernumberstring STR_VAR_2, VAR_0x8009
	goto_if_lt VAR_0x8009, 60, PalletTown_EventScript_NotEnoughMonsForNationalDex
	msgbox PalletTown_Text_CaughtXImpressiveFollowMe
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabFromHouse
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabFromHouse
	waitmovement 0
	opendoor 16, 13
	waitdooranim
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLab
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerEnterLab
	waitmovement 0
	closedoor 16, 13
	waitdooranim
	setvar VAR_TEMP_0, 7
// Replaced VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB with VAR_TEMP_0
	setvar VAR_TEMP_0, 3
// Replaced VAR_MAP_SCENE_PALLET_TOWN_OAK with VAR_TEMP_0
	setflag FLAG_TEMP_1
// Replaced FLAG_HIDE_OAK_IN_PALLET_TOWN with FLAG_TEMP_1
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
	waitstate
	releaseall
	end

PalletTown_EventScript_EndOakRatingScene::
	closemessage
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakExit
	waitmovement 0
	removeobject LOCALID_PALLET_PROF_OAK
	setvar VAR_TEMP_0, 3
// Replaced VAR_MAP_SCENE_PALLET_TOWN_OAK with VAR_TEMP_0
	releaseall
	end

PalletTown_EventScript_NotEnoughMonsForNationalDex::
	msgbox PalletTown_Text_CaughtXPuttingInHonestEffort
	goto PalletTown_EventScript_EndOakRatingScene
	end

PalletTown_EventScript_NotBeenToOneIslandYet::
	msgbox PalletTown_Text_OakYouEnjoyingTraveling
	goto PalletTown_EventScript_EndOakRatingScene
	end

PalletTown_Movement_OakWalkToPlayersDoor::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

PalletTown_Movement_OakExit::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PalletTown_Movement_OakWalkToLabFromHouse::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

PalletTown_Movement_PlayerWalkToLabFromHouse::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PalletTown_EventScript_OakTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto PalletTown_EventScript_OakTrigger
	end

PalletTown_EventScript_OakTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto PalletTown_EventScript_OakTrigger
	end

PalletTown_EventScript_OakTrigger::
	delay 30
	message PalletTown_Text_OakDontGoOut
	waitmessage
	delay 85
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	addobject LOCALID_PALLET_PROF_OAK
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakEnterLeft
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakEnterRight
	delay 30
	msgbox PalletTown_Text_OakGrassUnsafeNeedMon
	closemessage
	delay 30
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakLeadPlayerToLabLeft
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakLeadPlayerToLabRight
	opendoor 16, 13
	waitdooranim
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLab
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerEnterLab
	waitmovement 0
	closedoor 16, 13
	waitdooranim
	setvar VAR_TEMP_0, 1
// Replaced VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB with VAR_TEMP_0
	clearflag FLAG_TEMP_1
// Replaced FLAG_HIDE_OAK_IN_HIS_LAB with FLAG_TEMP_1
	setvar VAR_TEMP_0, 1
// Replaced VAR_MAP_SCENE_PALLET_TOWN_OAK with VAR_TEMP_0
	setflag FLAG_TEMP_1
// Replaced FLAG_HIDE_OAK_IN_PALLET_TOWN with FLAG_TEMP_1
	setflag FLAG_DONT_TRANSITION_MUSIC
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
	waitstate
	releaseall
	end

PalletTown_EventScript_OakEnterLeft::
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLeft
	waitmovement 0
	return

PalletTown_EventScript_OakEnterRight::
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterRight
	waitmovement 0
	return

PalletTown_EventScript_OakLeadPlayerToLabLeft::
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabLeft
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabLeft
	waitmovement 0
	return

PalletTown_EventScript_OakLeadPlayerToLabRight::
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabRight
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabRight
	waitmovement 0
	return

PalletTown_Movement_OakEnterLeft::
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

PalletTown_Movement_OakEnterRight::
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

	.macro walk_to_lab
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	.endm

PalletTown_Movement_OakWalkToLabLeft::
	walk_down
	walk_to_lab
	walk_right
	walk_in_place_faster_up
	step_end

PalletTown_Movement_OakWalkToLabRight::
	walk_down
	walk_left
	walk_to_lab
	walk_right
	walk_in_place_faster_up
	step_end

PalletTown_Movement_OakEnterLab::
	walk_up
	set_invisible
	step_end

PalletTown_Movement_PlayerWalkToLabLeft::
	walk_down
	walk_down
	walk_to_lab
	step_end

PalletTown_Movement_PlayerWalkToLabRight::
	walk_down
	walk_down
	walk_left
	walk_to_lab
	step_end

PalletTown_Movement_PlayerEnterLab::
	walk_right
	walk_up
	set_invisible
	step_end

PalletTown_EventScript_SignLady::
	lock
	goto_if_eq VAR_TEMP_0, 2, PalletTown_EventScript_SignLadyDone
// Replaced VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY with VAR_TEMP_0
	goto_if_eq VAR_TEMP_0, 1, PalletTown_EventScript_SignLadyJustShowedSign
// Replaced VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY with VAR_TEMP_0
	goto_if_eq SIGN_LADY_READY, TRUE, PalletTown_EventScript_SignLadyStartShowSign
	goto_if_set FLAG_TEMP_2, PalletTown_EventScript_SignLadyGoReadSign
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_Delay48
	waitmovement 0
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayRight
	call_if_ne VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayLeft
	copyobjectxytoperm LOCALID_PALLET_SIGN_LADY
	setflag FLAG_TEMP_2
	release
	end

PalletTown_EventScript_SignLadyMoveOutOfWayRight::
	applymovement LOCALID_PALLET_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayRight
	waitmovement 0
	return

PalletTown_EventScript_SignLadyMoveOutOfWayLeft::
	applymovement LOCALID_PALLET_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayLeft
	waitmovement 0
	return

PalletTown_EventScript_SignLadyDone::
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox PalletTown_Text_RaisingMonsToo
	release
	end

PalletTown_EventScript_SignLadyGoReadSign::
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
	waitmovement 0
	release
	end

PalletTown_EventScript_SignLadyJustShowedSign::
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
	waitmovement 0
	release
	end

PalletTown_Movement_SignLadyMoveOutOfWayRight::
	walk_right
	walk_in_place_faster_left
	step_end

PalletTown_Movement_SignLadyMoveOutOfWayLeft::
	walk_left
	walk_in_place_faster_right
	step_end

PalletTown_EventScript_FatMan::
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
	end

PalletTown_EventScript_OaksLabSign::
	lockall
	msgbox PalletTown_Text_OakPokemonResearchLab
	releaseall
	end

PalletTown_EventScript_PlayersHouseSign::
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
	end

PalletTown_EventScript_RivalsHouseSign::
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
	end

PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
	end

PalletTown_EventScript_TrainerTips::
	lockall
	setvar VAR_TEMP_0, 1
// Replaced VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY with VAR_TEMP_0
	releaseall
	end

PalletTown_EventScript_SignLadyTrigger::
	lockall
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call PalletTown_EventScript_SignLadyShowSign
	releaseall
	end

PalletTown_EventScript_SignLadyShowSign::
	closemessage
	delay 20
	setflag FLAG_TEMP_1
// Replaced FLAG_OPENED_START_MENU with FLAG_TEMP_1
	setvar VAR_TEMP_0, 1
// Replaced VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY with VAR_TEMP_0
	setvar SIGN_LADY_READY, FALSE
	signmsg
	normalmsg
	return

PalletTown_EventScript_SignLadyStartShowSign::
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
	waitmovement 0
	call PalletTown_EventScript_SignLadyShowSign
	release
	end

PalletTown_Text_OakDontGoOut::
    .string "OAK: Hey! Wait!\n"
    .string "Don't go out!$"

PalletTown_Text_OakGrassUnsafeNeedMon::
    .string "OAK: It's unsafe!\n"
    .string "Wild POKéMON live in tall grass!\p"
    .string "You need your own POKéMON for\n"
    .string "your protection.\p"
    .string "I know!\n"
    .string "Here, come with me!$"

PalletTown_Text_RaisingMonsToo::
    .string "I'm raising POKéMON, too.\p"
    .string "When they get strong, they can\n"
    .string "protect me.$"

PalletTown_Text_CanStoreItemsAndMonsInPC::
    .string "Technology is incredible!\p"
    .string "You can now store and recall items\n"
    .string "and POKéMON as data via PC.$"

PalletTown_Text_OakPokemonResearchLab::
    .string "OAK POKéMON RESEARCH LAB$"

PalletTown_Text_PlayersHouse::
    .string "{PLAYER}'s house$"

PalletTown_Text_RivalsHouse::
    .string "{RIVAL}'s house$"

PalletTown_Text_TownSign::
    .string "PALLET TOWN\n"
    .string "Shades of your journey await!$"

PalletTown_Text_OakLetMeSeePokedex::
    .string "OAK: Ah, {PLAYER}!\n"
    .string "You're back, are you?\p"
    .string "How much have you filled in your\n"
    .string "POKéDEX?\p"
    .string "May I see it?\p"
    .string "Let's see…$"

PalletTown_Text_CaughtXPuttingInHonestEffort::
    .string "You've caught {STR_VAR_2}…\p"
    .string "Hm, it looks as if you're putting\n"
    .string "in an honest effort.\p"
    .string "When you manage to fill it some\n"
    .string "more, come show me, please.$"

PalletTown_Text_CaughtXImpressiveFollowMe::
    .string "You've caught… {STR_VAR_2}!?\n"
    .string "Now, this is impressive!\p"
    .string "There's something I wanted to ask\n"
    .string "of you, {PLAYER}.\p"
    .string "Come.\n"
    .string "Follow me.$"

PalletTown_Text_OakYouEnjoyingTraveling::
    .string "OAK: Ah, {PLAYER}!\n"
    .string "You seem to be enjoying traveling.\p"
    .string "Knowing you, {PLAYER}, I can easily\n"
    .string "imagine you going out to even more\l"
    .string "exotic locales.\p"
    .string "Good for you, good for you.\n"
    .string "Hohoho.$"

