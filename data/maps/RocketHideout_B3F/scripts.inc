RocketHideout_B3F_MapScripts::
	.byte 0


RocketHideout_B3F_EventScript_Grunt1::
# 5 "data/maps/RocketHideout_B3F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_14, RocketHideout_B3F_Text_Grunt1Intro, RocketHideout_B3F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/RocketHideout_B3F/scripts.pory"
	msgbox RocketHideout_B3F_Text_Grunt1PostBattle
	return


RocketHideout_B3F_EventScript_Grunt2::
# 10 "data/maps/RocketHideout_B3F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_15, RocketHideout_B3F_Text_Grunt2Intro, RocketHideout_B3F_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/RocketHideout_B3F/scripts.pory"
	msgbox RocketHideout_B3F_Text_Grunt2PostBattle
	return


RocketHideout_B3F_Text_Grunt1Defeat::
# 16 "data/maps/RocketHideout_B3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "RocketHideout_B3F_Text_Grunt1Defeat$"

RocketHideout_B3F_Text_Grunt1Intro::
# 20 "data/maps/RocketHideout_B3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "RocketHideout_B3F_Text_Grunt1Intro$"

RocketHideout_B3F_Text_Grunt1PostBattle::
# 24 "data/maps/RocketHideout_B3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "RocketHideout_B3F_Text_Grunt1PostBattle$"

RocketHideout_B3F_Text_Grunt2Defeat::
# 28 "data/maps/RocketHideout_B3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "RocketHideout_B3F_Text_Grunt2Defeat$"

RocketHideout_B3F_Text_Grunt2Intro::
# 32 "data/maps/RocketHideout_B3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "RocketHideout_B3F_Text_Grunt2Intro$"

RocketHideout_B3F_Text_Grunt2PostBattle::
# 36 "data/maps/RocketHideout_B3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "RocketHideout_B3F_Text_Grunt2PostBattle$"
