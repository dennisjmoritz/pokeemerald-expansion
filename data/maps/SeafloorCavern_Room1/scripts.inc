SeafloorCavern_Room1_MapScripts::
	.byte 0


SeafloorCavern_Room1_EventScript_Grunt1::
# 5 "data/maps/SeafloorCavern_Room1/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_SEAFLOOR_CAVERN, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SeafloorCavern_Room1/scripts.pory"
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle
	return


SeafloorCavern_Room1_EventScript_Grunt2::
# 10 "data/maps/SeafloorCavern_Room1/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SeafloorCavern_Room1/scripts.pory"
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle
	return


SeafloorCavern_Room1_Text_Grunt1Defeat::
# 16 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "SeafloorCavern_Room1_Text_Grunt1Defeat$"

SeafloorCavern_Room1_Text_Grunt1Intro::
# 20 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "SeafloorCavern_Room1_Text_Grunt1Intro$"

SeafloorCavern_Room1_Text_Grunt1PostBattle::
# 24 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "SeafloorCavern_Room1_Text_Grunt1PostBattle$"

SeafloorCavern_Room1_Text_Grunt2Defeat::
# 28 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "SeafloorCavern_Room1_Text_Grunt2Defeat$"

SeafloorCavern_Room1_Text_Grunt2Intro::
# 32 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "SeafloorCavern_Room1_Text_Grunt2Intro$"

SeafloorCavern_Room1_Text_Grunt2PostBattle::
# 36 "data/maps/SeafloorCavern_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "SeafloorCavern_Room1_Text_Grunt2PostBattle$"
