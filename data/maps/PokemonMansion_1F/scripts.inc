PokemonMansion_1F_MapScripts::
	.byte 0


PokemonMansion_1F_EventScript_Johnson::
# 5 "data/maps/PokemonMansion_1F/scripts.pory"
	trainerbattle_double TRAINER_YOUNGSTER_JOHNSON, PokemonMansion_1F_Text_JohnsonIntro, PokemonMansion_1F_Text_JohnsonDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/PokemonMansion_1F/scripts.pory"
	msgbox PokemonMansion_1F_Text_JohnsonPostBattle
	return


PokemonMansion_1F_EventScript_Statue::
	end


PokemonMansion_1F_EventScript_Ted::
# 21 "data/maps/PokemonMansion_1F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_TED, PokemonMansion_1F_Text_TedIntro, PokemonMansion_1F_Text_TedDefeat, Text_NotEnoughMonsForDoubleBattle
# 22 "data/maps/PokemonMansion_1F/scripts.pory"
	msgbox PokemonMansion_1F_Text_TedPostBattle
	return


PokemonMansion_1F_Text_JohnsonDefeat::
# 27 "data/maps/PokemonMansion_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_JohnsonDefeat$"

PokemonMansion_1F_Text_JohnsonIntro::
# 31 "data/maps/PokemonMansion_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_JohnsonIntro$"

PokemonMansion_1F_Text_JohnsonPostBattle::
# 35 "data/maps/PokemonMansion_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_JohnsonPostBattle$"

PokemonMansion_1F_Text_TedDefeat::
# 39 "data/maps/PokemonMansion_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_TedDefeat$"

PokemonMansion_1F_Text_TedIntro::
# 43 "data/maps/PokemonMansion_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_TedIntro$"

PokemonMansion_1F_Text_TedPostBattle::
# 47 "data/maps/PokemonMansion_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_TedPostBattle$"
