SeafloorCavern_Room3_MapScripts::
	.byte 0


SeafloorCavern_Room3_EventScript_Grunt5::
# 5 "data/maps/SeafloorCavern_Room3/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SeafloorCavern_Room3/scripts.pory"
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle
	return


SeafloorCavern_Room3_EventScript_Shelly::
# 10 "data/maps/SeafloorCavern_Room3/scripts.pory"
	trainerbattle_double TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SeafloorCavern_Room3/scripts.pory"
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle
	return


SeafloorCavern_Room3_Text_Grunt5Defeat::
# 16 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Placeholder text for\n"
	.string "SeafloorCavern_Room3_Text_Grunt5Defeat$"

SeafloorCavern_Room3_Text_Grunt5Intro::
# 20 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Placeholder text for\n"
	.string "SeafloorCavern_Room3_Text_Grunt5Intro$"

SeafloorCavern_Room3_Text_Grunt5PostBattle::
# 24 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Placeholder text for\n"
	.string "SeafloorCavern_Room3_Text_Grunt5PostBattle$"

SeafloorCavern_Room3_Text_ShellyDefeat::
# 28 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Placeholder text for\n"
	.string "SeafloorCavern_Room3_Text_ShellyDefeat$"

SeafloorCavern_Room3_Text_ShellyIntro::
# 32 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Placeholder text for\n"
	.string "SeafloorCavern_Room3_Text_ShellyIntro$"

SeafloorCavern_Room3_Text_ShellyPostBattle::
# 36 "data/maps/SeafloorCavern_Room3/scripts.pory"
	.string "Placeholder text for\n"
	.string "SeafloorCavern_Room3_Text_ShellyPostBattle$"
