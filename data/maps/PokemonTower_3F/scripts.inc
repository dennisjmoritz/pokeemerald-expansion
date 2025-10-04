PokemonTower_3F_MapScripts::
	.byte 0


PokemonTower_3F_EventScript_Carly::
# 5 "data/maps/PokemonTower_3F/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_CARLY, PokemonTower_3F_Text_CarlyIntro, PokemonTower_3F_Text_CarlyDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/PokemonTower_3F/scripts.pory"
	msgbox PokemonTower_3F_Text_CarlyPostBattle
	return


PokemonTower_3F_EventScript_Hope::
# 10 "data/maps/PokemonTower_3F/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_HOPE, PokemonTower_3F_Text_HopeIntro, PokemonTower_3F_Text_HopeDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/PokemonTower_3F/scripts.pory"
	msgbox PokemonTower_3F_Text_HopePostBattle
	return


PokemonTower_3F_EventScript_Patricia::
# 15 "data/maps/PokemonTower_3F/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_PATRICIA, PokemonTower_3F_Text_PatriciaIntro, PokemonTower_3F_Text_PatriciaDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/PokemonTower_3F/scripts.pory"
	msgbox PokemonTower_3F_Text_PatriciaPostBattle
	return


PokemonTower_3F_Text_CarlyDefeat::
# 21 "data/maps/PokemonTower_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_3F_Text_CarlyDefeat$"

PokemonTower_3F_Text_CarlyIntro::
# 25 "data/maps/PokemonTower_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_3F_Text_CarlyIntro$"

PokemonTower_3F_Text_CarlyPostBattle::
# 29 "data/maps/PokemonTower_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_3F_Text_CarlyPostBattle$"

PokemonTower_3F_Text_HopeDefeat::
# 33 "data/maps/PokemonTower_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_3F_Text_HopeDefeat$"

PokemonTower_3F_Text_HopeIntro::
# 37 "data/maps/PokemonTower_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_3F_Text_HopeIntro$"

PokemonTower_3F_Text_HopePostBattle::
# 41 "data/maps/PokemonTower_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_3F_Text_HopePostBattle$"

PokemonTower_3F_Text_PatriciaDefeat::
# 45 "data/maps/PokemonTower_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_3F_Text_PatriciaDefeat$"

PokemonTower_3F_Text_PatriciaIntro::
# 49 "data/maps/PokemonTower_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_3F_Text_PatriciaIntro$"

PokemonTower_3F_Text_PatriciaPostBattle::
# 53 "data/maps/PokemonTower_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonTower_3F_Text_PatriciaPostBattle$"
