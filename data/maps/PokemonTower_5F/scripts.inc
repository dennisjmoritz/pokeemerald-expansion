PokemonTower_5F_MapScripts::
	.byte 0


PokemonTower_5F_EventScript_Channeler::
# 5 "data/maps/PokemonTower_5F/scripts.pory"
	msgbox PokemonTower_5F_Text_RestHereInPurifiedSpace, MSGBOX_NPC
	end


PokemonTower_5F_EventScript_ExitPurifiedZone::
	end


PokemonTower_5F_EventScript_Janae::
# 14 "data/maps/PokemonTower_5F/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_JANAE, PokemonTower_5F_Text_JanaeIntro, PokemonTower_5F_Text_JanaeDefeat, Text_NotEnoughMonsForDoubleBattle
# 15 "data/maps/PokemonTower_5F/scripts.pory"
	msgbox PokemonTower_5F_Text_JanaePostBattle
	return


PokemonTower_5F_EventScript_Karina::
# 19 "data/maps/PokemonTower_5F/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_KARINA, PokemonTower_5F_Text_KarinaIntro, PokemonTower_5F_Text_KarinaDefeat, Text_NotEnoughMonsForDoubleBattle
# 20 "data/maps/PokemonTower_5F/scripts.pory"
	msgbox PokemonTower_5F_Text_KarinaPostBattle
	return


PokemonTower_5F_EventScript_PurifiedZone::
	end


PokemonTower_5F_EventScript_Ruth::
# 28 "data/maps/PokemonTower_5F/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_RUTH, PokemonTower_5F_Text_RuthIntro, PokemonTower_5F_Text_RuthDefeat, Text_NotEnoughMonsForDoubleBattle
# 29 "data/maps/PokemonTower_5F/scripts.pory"
	msgbox PokemonTower_5F_Text_RuthPostBattle
	return


PokemonTower_5F_EventScript_Tammy::
# 33 "data/maps/PokemonTower_5F/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_TAMMY, PokemonTower_5F_Text_TammyIntro, PokemonTower_5F_Text_TammyDefeat, Text_NotEnoughMonsForDoubleBattle
# 34 "data/maps/PokemonTower_5F/scripts.pory"
	msgbox PokemonTower_5F_Text_TammyPostBattle
	return


PokemonTower_5F_Text_JanaeDefeat::
# 39 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_5F_Text_JanaeDefeat$"

PokemonTower_5F_Text_JanaeIntro::
# 43 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_5F_Text_JanaeIntro$"

PokemonTower_5F_Text_JanaePostBattle::
# 47 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_5F_Text_JanaePostBattle$"

PokemonTower_5F_Text_KarinaDefeat::
# 51 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_5F_Text_KarinaDefeat$"

PokemonTower_5F_Text_KarinaIntro::
# 55 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_5F_Text_KarinaIntro$"

PokemonTower_5F_Text_KarinaPostBattle::
# 59 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_5F_Text_KarinaPostBattle$"

PokemonTower_5F_Text_RuthDefeat::
# 63 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_5F_Text_RuthDefeat$"

PokemonTower_5F_Text_RuthIntro::
# 67 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_5F_Text_RuthIntro$"

PokemonTower_5F_Text_RuthPostBattle::
# 71 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_5F_Text_RuthPostBattle$"

PokemonTower_5F_Text_TammyDefeat::
# 75 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_5F_Text_TammyDefeat$"

PokemonTower_5F_Text_TammyIntro::
# 79 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_5F_Text_TammyIntro$"

PokemonTower_5F_Text_TammyPostBattle::
# 83 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_5F_Text_TammyPostBattle$"

PokemonTower_5F_Text_RestHereInPurifiedSpace::
# 86 "data/maps/PokemonTower_5F/scripts.pory"
	.string "Come, child!\n"
	.string "I have purified this space.\l"
	.string "You can rest here.$"
