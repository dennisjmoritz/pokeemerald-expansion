PokemonTower_4F_MapScripts::
	.byte 0


PokemonTower_4F_EventScript_Jody::
# 5 "data/maps/PokemonTower_4F/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_JODY, PokemonTower_4F_Text_JodyIntro, PokemonTower_4F_Text_JodyDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/PokemonTower_4F/scripts.pory"
	msgbox PokemonTower_4F_Text_JodyPostBattle
	return


PokemonTower_4F_EventScript_Laurel::
# 10 "data/maps/PokemonTower_4F/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_LAUREL, PokemonTower_4F_Text_LaurelIntro, PokemonTower_4F_Text_LaurelDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/PokemonTower_4F/scripts.pory"
	msgbox PokemonTower_4F_Text_LaurelPostBattle
	return


PokemonTower_4F_EventScript_Paula::
# 15 "data/maps/PokemonTower_4F/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_PAULA, PokemonTower_4F_Text_PaulaIntro, PokemonTower_4F_Text_PaulaDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/PokemonTower_4F/scripts.pory"
	msgbox PokemonTower_4F_Text_PaulaPostBattle
	return


PokemonTower_4F_Text_JodyDefeat::
# 21 "data/maps/PokemonTower_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_4F_Text_JodyDefeat$"

PokemonTower_4F_Text_JodyIntro::
# 25 "data/maps/PokemonTower_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_4F_Text_JodyIntro$"

PokemonTower_4F_Text_JodyPostBattle::
# 29 "data/maps/PokemonTower_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_4F_Text_JodyPostBattle$"

PokemonTower_4F_Text_LaurelDefeat::
# 33 "data/maps/PokemonTower_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_4F_Text_LaurelDefeat$"

PokemonTower_4F_Text_LaurelIntro::
# 37 "data/maps/PokemonTower_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_4F_Text_LaurelIntro$"

PokemonTower_4F_Text_LaurelPostBattle::
# 41 "data/maps/PokemonTower_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_4F_Text_LaurelPostBattle$"

PokemonTower_4F_Text_PaulaDefeat::
# 45 "data/maps/PokemonTower_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_4F_Text_PaulaDefeat$"

PokemonTower_4F_Text_PaulaIntro::
# 49 "data/maps/PokemonTower_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_4F_Text_PaulaIntro$"

PokemonTower_4F_Text_PaulaPostBattle::
# 53 "data/maps/PokemonTower_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_4F_Text_PaulaPostBattle$"
