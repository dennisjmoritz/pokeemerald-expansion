SecretBase_Text_UseHouseKey:
	.string "Use the HOUSE KEY?$"

SecretBase_Text_DiscoveredSmallEntrance:
	.string "Discovered a small entrance!$"

SecretBase_Text_UsedHouseKey:
	.string "Used the HOUSE KEY!$"

SecretBase_Text_NoHouseKey:
	.string "You don't have a HOUSE KEY.$"

SecretBase_Text_VineDroppedDown:
	.string "A thick vine dropped down!$"

SecretBase_Text_ClumpOfGrass:
	.string "If this clump of grass can be moved,\n"
	.string "it might be possible to go inside.$"

SecretBase_Text_TreeCanBeClimbed:
	.string "This tree can be climbed.$"

	.include "data/text/secret_base_trainers.inc"

SecretBase_EventScript_CheckEntrance::
	special GetSecretBaseTypeInFrontOfPlayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, TRUE, SecretBase_EventScript_AlreadyHasSecretBase
	checkitem ITEM_HOUSE_KEY
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_NoHouseKey
	setfieldeffectargument 0, 1
	bufferitemname STR_VAR_2, ITEM_HOUSE_KEY
	goto_if_eq VAR_0x8007, SECRET_BASE_APARTMENT, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_HOUSE, SecretBase_EventScript_Tree
	goto_if_eq VAR_0x8007, SECRET_BASE_MANSION, SecretBase_EventScript_Shrub
	end

SecretBase_EventScript_NoHouseKey::
	msgbox SecretBase_Text_NoHouseKey, MSGBOX_DEFAULT
	releaseall
	end

SecretBase_EventScript_Cave::
	lockall
	msgbox SecretBase_Text_UseHouseKey, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox SecretBase_Text_UsedHouseKey, MSGBOX_DEFAULT
	closemessage
	goto SecretBase_EventScript_CaveEnter
	end

SecretBase_EventScript_CaveEnter::
	msgbox SecretBase_Text_DiscoveredSmallCavern, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_Tree::
	lockall
	msgbox SecretBase_Text_UseHouseKey, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox SecretBase_Text_UsedHouseKey, MSGBOX_DEFAULT
	closemessage
	goto SecretBase_EventScript_TreeEnter
	end

SecretBase_EventScript_TreeEnter::
	msgbox SecretBase_Text_VineDroppedDown, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_Shrub::
	lockall
	msgbox SecretBase_Text_UseHouseKey, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox SecretBase_Text_UsedHouseKey, MSGBOX_DEFAULT
	closemessage
	goto SecretBase_EventScript_ShrubEnter
	end

SecretBase_EventScript_ShrubEnter::
	msgbox SecretBase_Text_DiscoveredSmallEntrance, MSGBOX_DEFAULT
	goto SecretBase_EventScript_InitSecretBase
	end

SecretBase_EventScript_InitSecretBase::
	closemessage
	playse SE_EXIT
	setvar VAR_INIT_SECRET_BASE, 0
	setflag FLAG_HIDE_SECRET_BASE_TRAINER
	special SetPlayerSecretBase
	special EnterSecretBase
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	special InitSecretBaseDecorationSprites
	setvar VAR_SECRET_BASE_INITIALIZED, 1
	waitstate
	end

SecretBase_EventScript_FirstEntrance::
	applymovement LOCALID_PLAYER, SecretBase_Movement_EnterBase
	waitmovement 0
	setvar VAR_INIT_SECRET_BASE, 1
	msgbox SecretBase_Text_WantToMakeYourSecretBaseHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SecretBase_EventScript_SetAsBase
	closemessage
	playse SE_EXIT
	special ClearAndLeaveSecretBase
	end

SecretBase_EventScript_SetAsBase::
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	special EnterNewlyCreatedSecretBase
	waitstate
	end

SecretBase_Movement_EnterBase:
	walk_up
	walk_up
	step_end

SecretBase_EventScript_Enter::
	lockall
	setvar VAR_INIT_SECRET_BASE, 1
	playse SE_EXIT
	special IsCurSecretBaseOwnedByAnotherPlayer
	goto_if_eq VAR_RESULT, FALSE, SecretBase_EventScript_EnterPlayersBase
	clearflag FLAG_HIDE_SECRET_BASE_TRAINER
	special EnterSecretBase
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	waitstate
	end

SecretBase_EventScript_EnterPlayersBase::
	setflag FLAG_HIDE_SECRET_BASE_TRAINER
	special EnterSecretBase
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	waitstate
	end

SecretBase_EventScript_AlreadyHasSecretBase::
	lockall
	special GetSecretBaseNearbyMapName
	msgbox SecretBase_Text_WouldYouLikeToMoveBases, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox SecretBase_Text_AllDecorationsWillBeReturned, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	fadescreenswapbuffers FADE_TO_BLACK
	special MoveOutOfSecretBaseFromOutside
	closemessage
	fadescreenswapbuffers FADE_FROM_BLACK
		msgbox SecretBase_Text_MovingCompletedUseHouseKey, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_CancelOnEntrance
	msgbox SecretBase_Text_UsedHouseKey, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_0x8007, SECRET_BASE_APARTMENT, SecretBase_EventScript_Cave
	goto_if_eq VAR_0x8007, SECRET_BASE_HOUSE, SecretBase_EventScript_Tree
	goto_if_eq VAR_0x8007, SECRET_BASE_MANSION, SecretBase_EventScript_Shrub
	releaseall
	end

SecretBase_EventScript_CancelOnEntrance::
	closemessage
	releaseall
	end

SecretBase_EventScript_SetDecorationFlags::
	setflag FLAG_DECORATION_1
	setflag FLAG_DECORATION_2
	setflag FLAG_DECORATION_3
	setflag FLAG_DECORATION_4
	setflag FLAG_DECORATION_5
	setflag FLAG_DECORATION_6
	setflag FLAG_DECORATION_7
	setflag FLAG_DECORATION_8
	setflag FLAG_DECORATION_9
	setflag FLAG_DECORATION_10
	setflag FLAG_DECORATION_11
	setflag FLAG_DECORATION_12
	setflag FLAG_DECORATION_13
	setflag FLAG_DECORATION_14
	return

SecretBase_EventScript_InitDecorations::
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	special InitSecretBaseDecorationSprites
	setvar VAR_SECRET_BASE_INITIALIZED, 1
	end

SecretBase_EventScript_SetDecoration::
	setvar VAR_0x8005, 0
	goto SecretBase_EventScript_SetDecoration2
	end

SecretBase_EventScript_SetDecoration2::
	special SetDecoration
	end

SecretBase_EventScript_PutAwayDecoration::
	setvar VAR_0x8004, 0
	goto SecretBase_EventScript_PutAwayDecorationLoop
	end

SecretBase_EventScript_PutAwayDecorationLoop::
	special PutAwayDecorationIteration
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_PutAwayDecorationEnd
	addvar VAR_0x8004, 1
	goto_if_eq VAR_0x8005, 0, SecretBase_EventScript_PutAwayDecorationLoop
	removeobject VAR_0x8006
	setflag VAR_0x8005  @ UB: VAR_0x8005 is set to a flag by PutAwayDecorationIteration, but ScrCmd_setflag doesn't use VarGet
	goto SecretBase_EventScript_PutAwayDecorationLoop
	end

SecretBase_EventScript_PutAwayDecorationEnd::
	end

SecretBase_EventScript_DollInteract::
	end

SecretBase_EventScript_CushionInteract::
	end

SecretBase_Text_AllDecorationsWillBeReturned:
	.string "All decorations and furniture in your\n"
	.string "HOUSE will be returned to your PC.\p"
	.string "Is that okay?$"

SecretBase_Text_WantToRegisterSecretBase:
	.string "Do you want to register\n"
	.string "{STR_VAR_1}'s HOUSE?$"

SecretBase_Text_AlreadyRegisteredDelete:
	.string "This data is already registered.\n"
	.string "Would you like to delete it?$"

SecretBase_Text_TooManyBasesDeleteSome:
	.string "Up to 10 locations can be registered.\p"
	.string "Delete a location if you want to\n"
	.string "register another location.$"

SecretBase_Text_RegistrationCompleted:
	.string "Registration completed.$"

SecretBase_Text_DataUnregistered:
	.string "Data has been unregistered.$"

SecretBase_Text_BootUpPC:
	.string "{PLAYER} booted up the PC.$"

SecretBase_Text_WhatWouldYouLikeToDo:
	.string "What would you like to do?$"

SecretBase_Text_RegistryInfo:
	.string "Once registered, a HOUSE will not\n"
	.string "disappear unless the other TRAINER\l"
	.string "moves it to a different location.\p"
	.string "If a HOUSE is deleted from the\n"
	.string "registered list, another one may take\l"
	.string "its place.\p"
	.string "Up to ten HOUSE locations\n"
	.string "may be registered.$"

SecretBase_Text_BattleTowerShield:
	.string "A shield of {STR_VAR_2} that marks winning\n"
	.string "{STR_VAR_1} times in a row at the BATTLE TOWER.$"

SecretBase_Text_ToyTV:
	.string "A realistic toy TV. It could be easily\n"
	.string "mistaken for the real thing.$"

SecretBase_Text_SeedotTV:
	.string "A toy TV shaped like a SEEDOT.\n"
	.string "It looks ready to roll away on its own…$"

SecretBase_Text_SkittyTV:
	.string "A toy TV shaped like a SKITTY.\n"
	.string "It looks ready to stroll away…$"

SecretBase_Text_WouldYouLikeToMoveBases:
	.string "You may only make one HOUSE.\p"
	.string "Would you like to move from the HOUSE\n"
	.string "near {STR_VAR_1}?$"

SecretBase_Text_MovingCompletedUseHouseKey:
	.string "Moving completed.\p"
	.string "Would you like to use the HOUSE KEY?$"
