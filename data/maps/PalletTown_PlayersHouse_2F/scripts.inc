PalletTown_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	.byte 0

PalletTown_PlayersHouse_2F_OnTransition::
	call_if_eq VAR_TEMP_0, 0, PalletTown_PlayersHouse_2F_EventScript_SetRespawn
// Replaced VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F with VAR_TEMP_0
	end

PalletTown_PlayersHouse_2F_EventScript_SetRespawn::
// FIXME undefined reference: 	setrespawn HEAL_LOCATION_PALLET_TOWN
	return

PalletTown_PlayersHouse_2F_OnWarp::
	map_script_2 VAR_TEMP_0, 0, PalletTown_PlayersHouse_2F_FirstWarpIn
// Replaced VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F with VAR_TEMP_0
	.2byte 0

PalletTown_PlayersHouse_2F_FirstWarpIn::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar VAR_TEMP_0, 1
// Replaced VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F with VAR_TEMP_0
	end

PalletTown_PlayersHouse_2F_EventScript_NES::
	msgbox PalletTown_PlayersHouse_2F_Text_PlayedWithNES, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_Sign::
	msgbox PalletTown_PlayersHouse_2F_Text_PressLRForHelp, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_PC::
@	goto_if_questlog EventScript_ReleaseEnd
	lockall
// 	setvar VAR_0x8004, HELPCONTEXT_BEDROOM_PC
// FIXME undefined reference: 	special Script_SetHelpContext
	setvar VAR_0x8004, 1
// FIXME undefined reference: 	special AnimatePcTurnOn
	playse SE_PC_ON
// FIXME undefined reference: 	msgbox Text_PlayerBootedUpPC
	special BedroomPC
	waitstate
// FIXME undefined reference: 	special SetHelpContextForMap
	releaseall
	end

EventScript_PalletTown_PlayersHouse_2F_ShutDownPC::
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
// FIXME undefined reference: 	special AnimatePcTurnOff
// FIXME undefined reference: 	special SetHelpContextForMap
	releaseall
	end

PalletTown_PlayersHouse_2F_Text_PlayedWithNES::
    .string "{PLAYER} played with the NES.\p"
    .string "…Okay!\n"
    .string "It's time to go!$"

PalletTown_PlayersHouse_2F_Text_PressLRForHelp::
    .string "It's a posted notice…\p"
    .string "If you're confused, ask for HELP!\n"
    .string "Press the L or R Button!$"

