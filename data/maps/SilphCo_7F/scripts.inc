SilphCo_7F_MapScripts::
	.byte 0


SilphCo_7F_EventScript_FloorSign::
# 5 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end


SilphCo_7F_EventScript_Grunt1::
# 10 "data/maps/SilphCo_7F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_Grunt1PostBattle
	return


SilphCo_7F_EventScript_Grunt2::
# 15 "data/maps/SilphCo_7F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_Grunt2PostBattle
	return


SilphCo_7F_EventScript_Grunt3::
# 20 "data/maps/SilphCo_7F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_Grunt3PostBattle
	return


SilphCo_7F_EventScript_Joshua::
# 25 "data/maps/SilphCo_7F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/SilphCo_7F/scripts.pory"
	msgbox SilphCo_7F_Text_JoshuaPostBattle
	return


SilphCo_7F_EventScript_LaprasGuy::
	end


SilphCo_7F_EventScript_RivalTriggerBottom::
	end


SilphCo_7F_EventScript_RivalTriggerTop::
	end


SilphCo_7F_EventScript_WorkerF::
	end


SilphCo_7F_EventScript_WorkerM1::
	end


SilphCo_7F_EventScript_WorkerM2::
	end


SilphCo_7F_Text_FloorSign::
# 54 "data/maps/SilphCo_7F/scripts.pory"
	.string "SILPH CO. HEAD OFFICE 7F$"

SilphCo_7F_Text_Grunt1Defeat::
# 59 "data/maps/SilphCo_7F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_7F_Text_Grunt1Defeat$"

SilphCo_7F_Text_Grunt1Intro::
# 63 "data/maps/SilphCo_7F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_7F_Text_Grunt1Intro$"

SilphCo_7F_Text_Grunt1PostBattle::
# 67 "data/maps/SilphCo_7F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_7F_Text_Grunt1PostBattle$"

SilphCo_7F_Text_Grunt2Defeat::
# 71 "data/maps/SilphCo_7F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_7F_Text_Grunt2Defeat$"

SilphCo_7F_Text_Grunt2Intro::
# 75 "data/maps/SilphCo_7F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_7F_Text_Grunt2Intro$"

SilphCo_7F_Text_Grunt2PostBattle::
# 79 "data/maps/SilphCo_7F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_7F_Text_Grunt2PostBattle$"

SilphCo_7F_Text_Grunt3Defeat::
# 83 "data/maps/SilphCo_7F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_7F_Text_Grunt3Defeat$"

SilphCo_7F_Text_Grunt3Intro::
# 87 "data/maps/SilphCo_7F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_7F_Text_Grunt3Intro$"

SilphCo_7F_Text_Grunt3PostBattle::
# 91 "data/maps/SilphCo_7F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_7F_Text_Grunt3PostBattle$"

SilphCo_7F_Text_JoshuaDefeat::
# 95 "data/maps/SilphCo_7F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_7F_Text_JoshuaDefeat$"

SilphCo_7F_Text_JoshuaIntro::
# 99 "data/maps/SilphCo_7F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_7F_Text_JoshuaIntro$"

SilphCo_7F_Text_JoshuaPostBattle::
# 103 "data/maps/SilphCo_7F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_7F_Text_JoshuaPostBattle$"
