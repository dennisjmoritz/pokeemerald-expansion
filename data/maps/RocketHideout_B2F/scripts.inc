RocketHideout_B2F_MapScripts::
	.byte 0


RocketHideout_B2F_EventScript_Grunt::
# 5 "data/maps/RocketHideout_B2F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_13, RocketHideout_B2F_Text_GruntIntro, RocketHideout_B2F_Text_GruntDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/RocketHideout_B2F/scripts.pory"
	msgbox RocketHideout_B2F_Text_GruntPostBattle
	return


RocketHideout_B2F_Text_GruntDefeat::
# 11 "data/maps/RocketHideout_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "RocketHideout_B2F_Text_GruntDefeat$"

RocketHideout_B2F_Text_GruntIntro::
# 15 "data/maps/RocketHideout_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "RocketHideout_B2F_Text_GruntIntro$"

RocketHideout_B2F_Text_GruntPostBattle::
# 19 "data/maps/RocketHideout_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "RocketHideout_B2F_Text_GruntPostBattle$"
