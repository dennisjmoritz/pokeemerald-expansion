PokemonMansion_2F_MapScripts::
	.byte 0


PokemonMansion_2F_EventScript_Arnie::
# 5 "data/maps/PokemonMansion_2F/scripts.pory"
	trainerbattle_double TRAINER_BURGLAR_ARNIE, PokemonMansion_1F_Text_ArnieIntro, PokemonMansion_1F_Text_ArnieDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/PokemonMansion_2F/scripts.pory"
	msgbox PokemonMansion_1F_Text_ArniePostBattle
	return


PokemonMansion_2F_EventScript_DiaryJuly10th::
# 10 "data/maps/PokemonMansion_2F/scripts.pory"
	msgbox PokemonMansion_1F_Text_ChristenedDiscoveredMonMew, MSGBOX_SIGN
	end


PokemonMansion_2F_EventScript_DiaryJuly5th::
# 15 "data/maps/PokemonMansion_2F/scripts.pory"
	msgbox PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle, MSGBOX_SIGN
	end


PokemonMansion_2F_EventScript_Statue::
	end


PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle::
# 31 "data/maps/PokemonMansion_2F/scripts.pory"
	.string "Diary: July 5 Guyana, South America\p"
	.string "A new POKéMON was discovered deep in\n"
	.string "the jungle.$"

PokemonMansion_1F_Text_ChristenedDiscoveredMonMew::
# 35 "data/maps/PokemonMansion_2F/scripts.pory"
	.string "Diary: July 10 We christened the newly\n"
	.string "discovered\l"
	.string "POKéMON, MEW.$"

PokemonMansion_1F_Text_ArnieDefeat::
# 40 "data/maps/PokemonMansion_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_ArnieDefeat$"

PokemonMansion_1F_Text_ArnieIntro::
# 44 "data/maps/PokemonMansion_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_ArnieIntro$"

PokemonMansion_1F_Text_ArniePostBattle::
# 48 "data/maps/PokemonMansion_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "PokemonMansion_1F_Text_ArniePostBattle$"
