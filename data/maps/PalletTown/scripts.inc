PalletTown_MapScripts::
	.byte 0


PalletTown_EventScript_FatMan::
# 5 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
	end


PalletTown_EventScript_OakTriggerLeft::
	end


PalletTown_EventScript_OakTriggerRight::
	end


PalletTown_EventScript_OaksLabSign::
# 20 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakPokemonResearchLab, MSGBOX_SIGN
	end


PalletTown_EventScript_PlayersHouseSign::
# 26 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
	end


PalletTown_EventScript_RivalsHouseSign::
# 31 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
	end


PalletTown_EventScript_SignLady::
	end


PalletTown_EventScript_SignLadyTrigger::
	end


PalletTown_EventScript_TownSign::
# 44 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
	end


PalletTown_EventScript_TrainerTips::
# 50 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenu, MSGBOX_DEFAULT
	end


PalletTown_EventScript_AgentSmith::
# 57 "data/maps/PalletTown/scripts.pory"
	trainerbattle_single TRAINER_AGENT_SMITH, PalletTown_Text_AgentSmithIntro, PalletTown_Text_AgentSmithDefeat
# 58 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_AgentSmithPostBattle, MSGBOX_AUTOCLOSE
	end


PalletTown_Text_PressStartToOpenMenu::
# 62 "data/maps/PalletTown/scripts.pory"
	.string "Press START to open the menu.$"

PalletTown_Text_OakPokemonResearchLab::
# 66 "data/maps/PalletTown/scripts.pory"
	.string "OAK POKéMON RESEARCH LAB$"

PalletTown_Text_TownSign::
# 70 "data/maps/PalletTown/scripts.pory"
	.string "PALLET TOWN Shades of your journey\n"
	.string "await!$"

PalletTown_Text_PlayersHouse::
# 74 "data/maps/PalletTown/scripts.pory"
	.string "{PLAYER}'s house$"

PalletTown_Text_RivalsHouse::
# 78 "data/maps/PalletTown/scripts.pory"
	.string "{RIVAL}'s house$"

PalletTown_Text_CanStoreItemsAndMonsInPC::
# 82 "data/maps/PalletTown/scripts.pory"
	.string "Technology is incredible!\p"
	.string "You can now store and recall items\n"
	.string "and POKéMON as data via PC.$"

PalletTown_Text_AgentSmithIntro::
# 86 "data/maps/PalletTown/scripts.pory"
	.string "I am Agent Smith.\p"
	.string "You are not the one.$"

PalletTown_Text_AgentSmithDefeat::
# 90 "data/maps/PalletTown/scripts.pory"
	.string "Interesting...$"

PalletTown_Text_AgentSmithPostBattle::
# 94 "data/maps/PalletTown/scripts.pory"
	.string "The Matrix has you...$"
