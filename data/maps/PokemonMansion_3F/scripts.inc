PokemonMansion_3F_MapScripts::
	.byte 0


PokemonMansion_3F_EventScript_Braydon::
# 5 "data/maps/PokemonMansion_3F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_BRAYDON, PokemonMansion_1F_Text_BraydonIntro, PokemonMansion_1F_Text_BraydonDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/PokemonMansion_3F/scripts.pory"
	msgbox PokemonMansion_1F_Text_BraydonPostBattle
	return


PokemonMansion_3F_EventScript_DiaryFeb6th::
# 10 "data/maps/PokemonMansion_3F/scripts.pory"
	msgbox PokemonMansion_1F_Text_MewGaveBirthToMewtwo, MSGBOX_SIGN
	end


PokemonMansion_3F_EventScript_Simon::
# 15 "data/maps/PokemonMansion_3F/scripts.pory"
	trainerbattle_double TRAINER_BURGLAR_SIMON, PokemonMansion_1F_Text_SimonIntro, PokemonMansion_1F_Text_SimonDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/PokemonMansion_3F/scripts.pory"
	msgbox PokemonMansion_1F_Text_SimonPostBattle
	return


PokemonMansion_3F_EventScript_Statue::
	end


PokemonMansion_1F_Text_MewGaveBirthToMewtwo::
# 31 "data/maps/PokemonMansion_3F/scripts.pory"
	.string "Diary: Feb. 6 MEW gave birth.\p"
	.string "We named the newborn MEWTWO.$"

PokemonMansion_1F_Text_BraydonDefeat::
# 36 "data/maps/PokemonMansion_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_BraydonDefeat$"

PokemonMansion_1F_Text_BraydonIntro::
# 40 "data/maps/PokemonMansion_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_BraydonIntro$"

PokemonMansion_1F_Text_BraydonPostBattle::
# 44 "data/maps/PokemonMansion_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_BraydonPostBattle$"

PokemonMansion_1F_Text_SimonDefeat::
# 48 "data/maps/PokemonMansion_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_SimonDefeat$"

PokemonMansion_1F_Text_SimonIntro::
# 52 "data/maps/PokemonMansion_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_SimonIntro$"

PokemonMansion_1F_Text_SimonPostBattle::
# 56 "data/maps/PokemonMansion_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_SimonPostBattle$"
