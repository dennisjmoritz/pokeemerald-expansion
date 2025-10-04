PalletTown_PlayersHouse_2F_MapScripts::
	.byte 0


PalletTown_PlayersHouse_2F_EventScript_NES::
# 5 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_Text_PlayedWithNES, MSGBOX_SIGN
	end


PalletTown_PlayersHouse_2F_EventScript_PC::
	end


PalletTown_PlayersHouse_2F_EventScript_Sign::
# 14 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_Text_PressLRForHelp, MSGBOX_SIGN
	end


PalletTown_PlayersHouse_2F_EventScript_SmithNPC1::
# 28 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_Text_SmithNPC1, MSGBOX_NPC
	end


PalletTown_PlayersHouse_2F_EventScript_SmithNPC2::
# 37 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_Text_SmithNPC2, MSGBOX_NPC
	end


PalletTown_PlayersHouse_2F_Text_PlayedWithNES::
# 19 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} played with the NES.\p"
	.string "…Okay!\n"
	.string "It's time to go!$"

PalletTown_PlayersHouse_2F_Text_PressLRForHelp::
# 23 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.string "It's a posted notice…\p"
	.string "If you're confused, ask for HELP!\n"
	.string "Press the L or R Button!$"

PalletTown_PlayersHouse_2F_Text_SmithNPC1::
# 32 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.string "I've been expecting you, Mr. Anderson.$"

PalletTown_PlayersHouse_2F_Text_SmithNPC2::
# 41 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.string "Human beings are a disease; I'm the\n"
	.string "cure.$"
