PokemonMansion_B1F_MapScripts::
	.byte 0


PokemonMansion_B1F_EventScript_DiarySep1st::
# 5 "data/maps/PokemonMansion_B1F/scripts.pory"
	msgbox PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful, MSGBOX_SIGN
	end


PokemonMansion_B1F_EventScript_Ivan::
# 10 "data/maps/PokemonMansion_B1F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_IVAN, PokemonMansion_B1F_Text_IvanIntro, PokemonMansion_B1F_Text_IvanDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/PokemonMansion_B1F/scripts.pory"
	msgbox PokemonMansion_B1F_Text_IvanPostBattle
	return


PokemonMansion_B1F_EventScript_Lewis::
# 15 "data/maps/PokemonMansion_B1F/scripts.pory"
	trainerbattle_double TRAINER_BURGLAR_LEWIS, PokemonMansion_B1F_Text_LewisIntro, PokemonMansion_B1F_Text_LewisDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/PokemonMansion_B1F/scripts.pory"
	msgbox PokemonMansion_B1F_Text_LewisPostBattle
	return


PokemonMansion_B1F_EventScript_Statue::
	end


PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful::
# 31 "data/maps/PokemonMansion_B1F/scripts.pory"
	.string "Diary: Sept. 1 MEWTWO is far too\n"
	.string "powerful.\p"
	.string "We have failed to curb its vicious\n"
	.string "tendencies…$"

PokemonMansion_B1F_Text_IvanDefeat::
# 36 "data/maps/PokemonMansion_B1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_B1F_Text_IvanDefeat$"

PokemonMansion_B1F_Text_IvanIntro::
# 40 "data/maps/PokemonMansion_B1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_B1F_Text_IvanIntro$"

PokemonMansion_B1F_Text_IvanPostBattle::
# 44 "data/maps/PokemonMansion_B1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_B1F_Text_IvanPostBattle$"

PokemonMansion_B1F_Text_LewisDefeat::
# 48 "data/maps/PokemonMansion_B1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_B1F_Text_LewisDefeat$"

PokemonMansion_B1F_Text_LewisIntro::
# 52 "data/maps/PokemonMansion_B1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_B1F_Text_LewisIntro$"

PokemonMansion_B1F_Text_LewisPostBattle::
# 56 "data/maps/PokemonMansion_B1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_B1F_Text_LewisPostBattle$"
