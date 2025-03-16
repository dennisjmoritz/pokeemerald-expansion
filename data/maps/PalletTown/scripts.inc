PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
	.byte 0

PalletTown_OnTransition:
	setflag FLAG_VISITED_PALLET_TOWN
	end

PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OakPokemonResearchLab
	end

PalletTown_EventScript_PlayersHouseSign::
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
	end

PalletTown_EventScript_OaksHouseSign::
	msgbox PalletTown_Text_OaksHouse, MSGBOX_SIGN
	end

PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
	end

PalletTown_Text_OakPokemonResearchLab::
    .string "OAK POKéMON RESEARCH LAB$"

PalletTown_Text_PlayersHouse::
    .string "{PLAYER}'S HOUSE$"

PalletTown_Text_OaksHouse::
    .string "PROFESSOR OAK'S HOUSE$"

PalletTown_Text_TownSign::
    .string "PALLET TOWN\n"
    .string "Shades of your journey await!$"
