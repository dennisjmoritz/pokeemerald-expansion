SixIsland_OutcastIsland_MapScripts::
	.byte 0


SixIsland_OutcastIsland_EventScript_Rocket::
# 5 "data/maps/SixIsland_OutcastIsland/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_46, SixIsland_OutcastIsland_Text_RocketIntro, SixIsland_OutcastIsland_Text_RocketDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SixIsland_OutcastIsland/scripts.pory"
	msgbox SixIsland_OutcastIsland_Text_RocketPostBattle
	return


SixIsland_OutcastIsland_Text_RocketDefeat::
# 11 "data/maps/SixIsland_OutcastIsland/scripts.pory"
	.string "Placeholder text for\n"
	.string "SixIsland_OutcastIsland_Text_RocketDefeat$"

SixIsland_OutcastIsland_Text_RocketIntro::
# 15 "data/maps/SixIsland_OutcastIsland/scripts.pory"
	.string "Placeholder text for\n"
	.string "SixIsland_OutcastIsland_Text_RocketIntro$"

SixIsland_OutcastIsland_Text_RocketPostBattle::
# 19 "data/maps/SixIsland_OutcastIsland/scripts.pory"
	.string "Placeholder text for\n"
	.string "SixIsland_OutcastIsland_Text_RocketPostBattle$"
