SilphCo_2F_MapScripts::
	.byte 0


SilphCo_2F_EventScript_Connor::
# 5 "data/maps/SilphCo_2F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_ConnorPostBattle
	return


SilphCo_2F_EventScript_FloorSign::
# 10 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end


SilphCo_2F_EventScript_Grunt1::
# 15 "data/maps/SilphCo_2F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_Grunt1PostBattle
	return


SilphCo_2F_EventScript_Grunt2::
# 20 "data/maps/SilphCo_2F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_Grunt2PostBattle
	return


SilphCo_2F_EventScript_Jerry::
# 25 "data/maps/SilphCo_2F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_JerryPostBattle
	return


SilphCo_2F_Text_FloorSign::
# 30 "data/maps/SilphCo_2F/scripts.pory"
	.string "SILPH CO. HEAD OFFICE 2F$"

SilphCo_2F_Text_ConnorDefeat::
# 35 "data/maps/SilphCo_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_2F_Text_ConnorDefeat$"

SilphCo_2F_Text_ConnorIntro::
# 39 "data/maps/SilphCo_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_2F_Text_ConnorIntro$"

SilphCo_2F_Text_ConnorPostBattle::
# 43 "data/maps/SilphCo_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_2F_Text_ConnorPostBattle$"

SilphCo_2F_Text_Grunt1Defeat::
# 47 "data/maps/SilphCo_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_2F_Text_Grunt1Defeat$"

SilphCo_2F_Text_Grunt1Intro::
# 51 "data/maps/SilphCo_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_2F_Text_Grunt1Intro$"

SilphCo_2F_Text_Grunt1PostBattle::
# 55 "data/maps/SilphCo_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_2F_Text_Grunt1PostBattle$"

SilphCo_2F_Text_Grunt2Defeat::
# 59 "data/maps/SilphCo_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_2F_Text_Grunt2Defeat$"

SilphCo_2F_Text_Grunt2Intro::
# 63 "data/maps/SilphCo_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_2F_Text_Grunt2Intro$"

SilphCo_2F_Text_Grunt2PostBattle::
# 67 "data/maps/SilphCo_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_2F_Text_Grunt2PostBattle$"

SilphCo_2F_Text_JerryDefeat::
# 71 "data/maps/SilphCo_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_2F_Text_JerryDefeat$"

SilphCo_2F_Text_JerryIntro::
# 75 "data/maps/SilphCo_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_2F_Text_JerryIntro$"

SilphCo_2F_Text_JerryPostBattle::
# 79 "data/maps/SilphCo_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_2F_Text_JerryPostBattle$"
