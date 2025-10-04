SilphCo_9F_MapScripts::
	.byte 0


SilphCo_9F_EventScript_Ed::
# 5 "data/maps/SilphCo_9F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_ED, SilphCo_9F_Text_EdIntro, SilphCo_9F_Text_EdDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SilphCo_9F/scripts.pory"
	msgbox SilphCo_9F_Text_EdPostBattle
	return


SilphCo_9F_EventScript_FloorSign::
# 10 "data/maps/SilphCo_9F/scripts.pory"
	msgbox SilphCo_9F_Text_FloorSign, MSGBOX_SIGN
	end


SilphCo_9F_EventScript_Grunt1::
# 15 "data/maps/SilphCo_9F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_37, SilphCo_9F_Text_Grunt1Intro, SilphCo_9F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/SilphCo_9F/scripts.pory"
	msgbox SilphCo_9F_Text_Grunt1PostBattle
	return


SilphCo_9F_EventScript_Grunt2::
# 20 "data/maps/SilphCo_9F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_38, SilphCo_9F_Text_Grunt2Intro, SilphCo_9F_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/SilphCo_9F/scripts.pory"
	msgbox SilphCo_9F_Text_Grunt2PostBattle
	return


SilphCo_9F_EventScript_HealWoman::
	end


SilphCo_9F_Text_FloorSign::
# 29 "data/maps/SilphCo_9F/scripts.pory"
	.string "SILPH CO. HEAD OFFICE 9F$"

SilphCo_9F_Text_EdDefeat::
# 34 "data/maps/SilphCo_9F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_9F_Text_EdDefeat$"

SilphCo_9F_Text_EdIntro::
# 38 "data/maps/SilphCo_9F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_9F_Text_EdIntro$"

SilphCo_9F_Text_EdPostBattle::
# 42 "data/maps/SilphCo_9F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_9F_Text_EdPostBattle$"

SilphCo_9F_Text_Grunt1Defeat::
# 46 "data/maps/SilphCo_9F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_9F_Text_Grunt1Defeat$"

SilphCo_9F_Text_Grunt1Intro::
# 50 "data/maps/SilphCo_9F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_9F_Text_Grunt1Intro$"

SilphCo_9F_Text_Grunt1PostBattle::
# 54 "data/maps/SilphCo_9F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_9F_Text_Grunt1PostBattle$"

SilphCo_9F_Text_Grunt2Defeat::
# 58 "data/maps/SilphCo_9F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_9F_Text_Grunt2Defeat$"

SilphCo_9F_Text_Grunt2Intro::
# 62 "data/maps/SilphCo_9F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_9F_Text_Grunt2Intro$"

SilphCo_9F_Text_Grunt2PostBattle::
# 66 "data/maps/SilphCo_9F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_9F_Text_Grunt2PostBattle$"
