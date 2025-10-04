SilphCo_10F_MapScripts::
	.byte 0


SilphCo_10F_EventScript_FloorSign::
# 5 "data/maps/SilphCo_10F/scripts.pory"
	msgbox SilphCo_10F_Text_FloorSign, MSGBOX_SIGN
	end


SilphCo_10F_EventScript_Grunt::
# 10 "data/maps/SilphCo_10F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_39, SilphCo_10F_Text_GruntIntro, SilphCo_10F_Text_GruntDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SilphCo_10F/scripts.pory"
	msgbox SilphCo_10F_Text_GruntPostBattle
	return


SilphCo_10F_EventScript_Travis::
# 15 "data/maps/SilphCo_10F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_TRAVIS, SilphCo_10F_Text_TravisIntro, SilphCo_10F_Text_TravisDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/SilphCo_10F/scripts.pory"
	msgbox SilphCo_10F_Text_TravisPostBattle
	return


SilphCo_10F_EventScript_WorkerF::
	end


SilphCo_10F_Text_FloorSign::
# 24 "data/maps/SilphCo_10F/scripts.pory"
	.string "SILPH CO. HEAD OFFICE 10F$"

SilphCo_10F_Text_GruntDefeat::
# 29 "data/maps/SilphCo_10F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_10F_Text_GruntDefeat$"

SilphCo_10F_Text_GruntIntro::
# 33 "data/maps/SilphCo_10F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_10F_Text_GruntIntro$"

SilphCo_10F_Text_GruntPostBattle::
# 37 "data/maps/SilphCo_10F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_10F_Text_GruntPostBattle$"

SilphCo_10F_Text_TravisDefeat::
# 41 "data/maps/SilphCo_10F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_10F_Text_TravisDefeat$"

SilphCo_10F_Text_TravisIntro::
# 45 "data/maps/SilphCo_10F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_10F_Text_TravisIntro$"

SilphCo_10F_Text_TravisPostBattle::
# 49 "data/maps/SilphCo_10F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_10F_Text_TravisPostBattle$"
