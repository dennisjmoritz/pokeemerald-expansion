SSTidalLowerDeck_MapScripts::
	.byte 0


SSTidalLowerDeck_EventScript_Leonard::
# 5 "data/maps/SSTidalLowerDeck/scripts.pory"
	trainerbattle_double TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SSTidalLowerDeck/scripts.pory"
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle
	return


SSTidalLowerDeck_EventScript_Phillip::
# 10 "data/maps/SSTidalLowerDeck/scripts.pory"
	trainerbattle_double TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SSTidalLowerDeck/scripts.pory"
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle
	return


SSTidalLowerDeck_Text_LeonardDefeat::
# 16 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalLowerDeck_Text_LeonardDefeat$"

SSTidalLowerDeck_Text_LeonardIntro::
# 20 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalLowerDeck_Text_LeonardIntro$"

SSTidalLowerDeck_Text_LeonardPostBattle::
# 24 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalLowerDeck_Text_LeonardPostBattle$"

SSTidalLowerDeck_Text_PhillipDefeat::
# 28 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalLowerDeck_Text_PhillipDefeat$"

SSTidalLowerDeck_Text_PhillipIntro::
# 32 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalLowerDeck_Text_PhillipIntro$"

SSTidalLowerDeck_Text_PhillipPostBattle::
# 36 "data/maps/SSTidalLowerDeck/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalLowerDeck_Text_PhillipPostBattle$"
