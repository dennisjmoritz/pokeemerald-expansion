SilphCo_8F_MapScripts::
	.byte 0


SilphCo_8F_EventScript_Door::
	end


SilphCo_8F_EventScript_FloorSign::
# 9 "data/maps/SilphCo_8F/scripts.pory"
	msgbox SilphCo_8F_Text_FloorSign, MSGBOX_SIGN
	end


SilphCo_8F_EventScript_Grunt1::
# 14 "data/maps/SilphCo_8F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_32, SilphCo_8F_Text_Grunt1Intro, SilphCo_8F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 15 "data/maps/SilphCo_8F/scripts.pory"
	msgbox SilphCo_8F_Text_Grunt1PostBattle
	return


SilphCo_8F_EventScript_Grunt2::
# 19 "data/maps/SilphCo_8F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_36, SilphCo_8F_Text_Grunt2Intro, SilphCo_8F_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 20 "data/maps/SilphCo_8F/scripts.pory"
	msgbox SilphCo_8F_Text_Grunt2PostBattle
	return


SilphCo_8F_EventScript_ItemIron::
	end


SilphCo_8F_EventScript_Parker::
# 28 "data/maps/SilphCo_8F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_PARKER, SilphCo_8F_Text_ParkerIntro, SilphCo_8F_Text_ParkerDefeat, Text_NotEnoughMonsForDoubleBattle
# 29 "data/maps/SilphCo_8F/scripts.pory"
	msgbox SilphCo_8F_Text_ParkerPostBattle
	return


SilphCo_8F_EventScript_Scientist::
	end


SilphCo_8F_EventScript_WorkerM::
	end


SilphCo_8F_Text_FloorSign::
# 41 "data/maps/SilphCo_8F/scripts.pory"
	.string "SILPH CO. HEAD OFFICE 8F$"

SilphCo_8F_Text_Grunt1Defeat::
# 46 "data/maps/SilphCo_8F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_8F_Text_Grunt1Defeat$"

SilphCo_8F_Text_Grunt1Intro::
# 50 "data/maps/SilphCo_8F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_8F_Text_Grunt1Intro$"

SilphCo_8F_Text_Grunt1PostBattle::
# 54 "data/maps/SilphCo_8F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_8F_Text_Grunt1PostBattle$"

SilphCo_8F_Text_Grunt2Defeat::
# 58 "data/maps/SilphCo_8F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_8F_Text_Grunt2Defeat$"

SilphCo_8F_Text_Grunt2Intro::
# 62 "data/maps/SilphCo_8F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_8F_Text_Grunt2Intro$"

SilphCo_8F_Text_Grunt2PostBattle::
# 66 "data/maps/SilphCo_8F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_8F_Text_Grunt2PostBattle$"

SilphCo_8F_Text_ParkerDefeat::
# 70 "data/maps/SilphCo_8F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_8F_Text_ParkerDefeat$"

SilphCo_8F_Text_ParkerIntro::
# 74 "data/maps/SilphCo_8F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_8F_Text_ParkerIntro$"

SilphCo_8F_Text_ParkerPostBattle::
# 78 "data/maps/SilphCo_8F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_8F_Text_ParkerPostBattle$"
