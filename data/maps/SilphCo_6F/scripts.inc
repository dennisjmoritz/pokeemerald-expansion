SilphCo_6F_MapScripts::
	.byte 0


SilphCo_6F_EventScript_FloorSign::
# 5 "data/maps/SilphCo_6F/scripts.pory"
	msgbox SilphCo_6F_Text_FloorSign, MSGBOX_SIGN
	end


SilphCo_6F_EventScript_Grunt1::
# 10 "data/maps/SilphCo_6F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_30, SilphCo_6F_Text_Grunt1Intro, SilphCo_6F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SilphCo_6F/scripts.pory"
	msgbox SilphCo_6F_Text_Grunt1PostBattle
	return


SilphCo_6F_EventScript_Grunt2::
# 15 "data/maps/SilphCo_6F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_31, SilphCo_6F_Text_Grunt2Intro, SilphCo_6F_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/SilphCo_6F/scripts.pory"
	msgbox SilphCo_6F_Text_Grunt2PostBattle
	return


SilphCo_6F_EventScript_Taylor::
# 20 "data/maps/SilphCo_6F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_TAYLOR, SilphCo_6F_Text_TaylorIntro, SilphCo_6F_Text_TaylorDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/SilphCo_6F/scripts.pory"
	msgbox SilphCo_6F_Text_TaylorPostBattle
	return


SilphCo_6F_EventScript_WorkerF1::
	end


SilphCo_6F_EventScript_WorkerF2::
	end


SilphCo_6F_EventScript_WorkerM1::
	end


SilphCo_6F_EventScript_WorkerM2::
	end


SilphCo_6F_EventScript_WorkerM3::
	end


SilphCo_6F_Text_FloorSign::
# 45 "data/maps/SilphCo_6F/scripts.pory"
	.string "SILPH CO. HEAD OFFICE 6F$"

SilphCo_6F_Text_Grunt1Defeat::
# 50 "data/maps/SilphCo_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_6F_Text_Grunt1Defeat$"

SilphCo_6F_Text_Grunt1Intro::
# 54 "data/maps/SilphCo_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_6F_Text_Grunt1Intro$"

SilphCo_6F_Text_Grunt1PostBattle::
# 58 "data/maps/SilphCo_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_6F_Text_Grunt1PostBattle$"

SilphCo_6F_Text_Grunt2Defeat::
# 62 "data/maps/SilphCo_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_6F_Text_Grunt2Defeat$"

SilphCo_6F_Text_Grunt2Intro::
# 66 "data/maps/SilphCo_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_6F_Text_Grunt2Intro$"

SilphCo_6F_Text_Grunt2PostBattle::
# 70 "data/maps/SilphCo_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_6F_Text_Grunt2PostBattle$"

SilphCo_6F_Text_TaylorDefeat::
# 74 "data/maps/SilphCo_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_6F_Text_TaylorDefeat$"

SilphCo_6F_Text_TaylorIntro::
# 78 "data/maps/SilphCo_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_6F_Text_TaylorIntro$"

SilphCo_6F_Text_TaylorPostBattle::
# 82 "data/maps/SilphCo_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_6F_Text_TaylorPostBattle$"
