SecretBase_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SecretBase_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, SecretBase_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SecretBase_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SecretBase_OnResume
	.byte 0

SecretBase_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, SecretBase_EventScript_InitDecorations
	.2byte 0

SecretBase_OnTransition:
	call SecretBase_EventScript_SetDecorationFlags
	special InitSecretBaseVars
	end

SecretBase_OnFrame:
	map_script_2 VAR_INIT_SECRET_BASE, 0, SecretBase_EventScript_FirstEntrance
	.2byte 0

SecretBase_OnResume:
	setstepcallback STEP_CB_SECRET_BASE
	end

SecretBase_EventScript_PC::
	lockall
	playse SE_PC_LOGIN
	msgbox SecretBase_Text_BootUpPC, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_PCTURN_ON
	waitbuttonpress
	playse SE_SELECT
	goto SecretBase_EventScript_PCShowMainMenu
	end

SecretBase_EventScript_PCShowMainMenu::
	message SecretBase_Text_WhatWouldYouLikeToDo
	waitmessage
	goto SecretBase_EventScript_PCMainMenu
	end

SecretBase_EventScript_PCCancel::
	lockall
	goto SecretBase_EventScript_PCShowMainMenu
	end

SecretBase_EventScript_PCMainMenu::
	multichoice 0, 0, MULTI_BASE_PC_NO_REGISTRY, FALSE
	switch VAR_RESULT
	case 0, SecretBase_EventScript_PCDecorationMenu
	case 1, SecretBase_EventScript_PCPackUp
	case 2, SecretBase_EventScript_PCTurnOff
	case MULTI_B_PRESSED, SecretBase_EventScript_PCTurnOff
	end

SecretBase_EventScript_PCPackUp::
	msgbox SecretBase_Text_AllDecorationsWillBeReturned, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SecretBase_EventScript_PCShowMainMenu
	closemessage
	special MoveOutOfSecretBase
	releaseall
	end

SecretBase_EventScript_PCDecorationMenu::
	special ShowSecretBaseDecorationMenu
	end

SecretBase_EventScript_PCTurnOff::
	special DoSecretBasePCTurnOffEffect
	closemessage
	releaseall
	end

SecretBase_EventScript_SandOrnament::
	dofieldeffect FLDEFF_SAND_PILLAR
	waitstate
	end

SecretBase_EventScript_ShieldOrToyTV::
	special InteractWithShieldOrTVDecoration
	goto_if_eq VAR_RESULT, 0, SecretBase_EventScript_BattleTowerShield
	goto_if_eq VAR_RESULT, 1, SecretBase_EventScript_ToyTV
	goto_if_eq VAR_RESULT, 2, SecretBase_EventScript_SeedotTV
	goto_if_eq VAR_RESULT, 3, SecretBase_EventScript_SkittyTV
	end

SecretBase_EventScript_BattleTowerShield::
	msgbox SecretBase_Text_BattleTowerShield, MSGBOX_SIGN
	end

SecretBase_EventScript_ToyTV::
	msgbox SecretBase_Text_ToyTV, MSGBOX_SIGN
	end

SecretBase_EventScript_SeedotTV::
	msgbox SecretBase_Text_SeedotTV, MSGBOX_SIGN
	end

SecretBase_EventScript_SkittyTV::
	msgbox SecretBase_Text_SkittyTV, MSGBOX_SIGN
	end

SecretBase_Text_SmallIndentInWall::
	.string "Look's like it migh be for sale.$"

SecretBase_Text_IndentUseHouseKey::
	.string "Use the HOUSE KEY?$"

SecretBase_Text_DiscoveredSmallCavern::
	.string "Seems like a nice place!$"

SecretBase_Text_WantToMakeYourSecretBaseHere:
	.string "Want to make your HOUSE here?$"

ping:
	.string "ping$"
