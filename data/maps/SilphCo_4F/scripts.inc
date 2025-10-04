SilphCo_4F_MapScripts::
	.byte 0


SilphCo_4F_EventScript_FloorSign::
# 5 "data/maps/SilphCo_4F/scripts.pory"
	msgbox SilphCo_4F_Text_FloorSign, MSGBOX_SIGN
	end


SilphCo_4F_EventScript_Grunt1::
# 10 "data/maps/SilphCo_4F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_26, SilphCo_4F_Text_Grunt1Intro, SilphCo_4F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SilphCo_4F/scripts.pory"
	msgbox SilphCo_4F_Text_Grunt1PostBattle
	return


SilphCo_4F_EventScript_Grunt2::
# 15 "data/maps/SilphCo_4F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_27, SilphCo_4F_Text_Grunt2Intro, SilphCo_4F_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/SilphCo_4F/scripts.pory"
	msgbox SilphCo_4F_Text_Grunt2PostBattle
	return


SilphCo_4F_EventScript_Rodney::
# 20 "data/maps/SilphCo_4F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_RODNEY, SilphCo_4F_Text_RodneyIntro, SilphCo_4F_Text_RodneyDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/SilphCo_4F/scripts.pory"
	msgbox SilphCo_4F_Text_RodneyPostBattle
	return


SilphCo_4F_EventScript_WorkerM::
	end


SilphCo_4F_Text_FloorSign::
# 29 "data/maps/SilphCo_4F/scripts.pory"
	.string "SILPH CO. HEAD OFFICE 4F$"

SilphCo_4F_Text_Grunt1Defeat::
# 34 "data/maps/SilphCo_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_4F_Text_Grunt1Defeat$"

SilphCo_4F_Text_Grunt1Intro::
# 38 "data/maps/SilphCo_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_4F_Text_Grunt1Intro$"

SilphCo_4F_Text_Grunt1PostBattle::
# 42 "data/maps/SilphCo_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_4F_Text_Grunt1PostBattle$"

SilphCo_4F_Text_Grunt2Defeat::
# 46 "data/maps/SilphCo_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_4F_Text_Grunt2Defeat$"

SilphCo_4F_Text_Grunt2Intro::
# 50 "data/maps/SilphCo_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_4F_Text_Grunt2Intro$"

SilphCo_4F_Text_Grunt2PostBattle::
# 54 "data/maps/SilphCo_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_4F_Text_Grunt2PostBattle$"

SilphCo_4F_Text_RodneyDefeat::
# 58 "data/maps/SilphCo_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_4F_Text_RodneyDefeat$"

SilphCo_4F_Text_RodneyIntro::
# 62 "data/maps/SilphCo_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_4F_Text_RodneyIntro$"

SilphCo_4F_Text_RodneyPostBattle::
# 66 "data/maps/SilphCo_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_4F_Text_RodneyPostBattle$"
