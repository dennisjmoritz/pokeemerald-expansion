SilphCo_3F_MapScripts::
	.byte 0


SilphCo_3F_EventScript_FloorSign::
# 5 "data/maps/SilphCo_3F/scripts.pory"
	msgbox SilphCo_3F_Text_FloorSign, MSGBOX_SIGN
	end


SilphCo_3F_EventScript_Grunt::
# 10 "data/maps/SilphCo_3F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_25, SilphCo_3F_Text_GruntIntro, SilphCo_3F_Text_GruntDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SilphCo_3F/scripts.pory"
	msgbox SilphCo_3F_Text_GruntPostBattle
	return


SilphCo_3F_EventScript_Jose::
# 15 "data/maps/SilphCo_3F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_JOSE, SilphCo_3F_Text_JoseIntro, SilphCo_3F_Text_JoseDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/SilphCo_3F/scripts.pory"
	msgbox SilphCo_3F_Text_JosePostBattle
	return


SilphCo_3F_EventScript_WorkerM::
	end


SilphCo_3F_Text_FloorSign::
# 24 "data/maps/SilphCo_3F/scripts.pory"
	.string "SILPH CO. HEAD OFFICE 3F$"

SilphCo_3F_Text_GruntDefeat::
# 29 "data/maps/SilphCo_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_3F_Text_GruntDefeat$"

SilphCo_3F_Text_GruntIntro::
# 33 "data/maps/SilphCo_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_3F_Text_GruntIntro$"

SilphCo_3F_Text_GruntPostBattle::
# 37 "data/maps/SilphCo_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_3F_Text_GruntPostBattle$"

SilphCo_3F_Text_JoseDefeat::
# 41 "data/maps/SilphCo_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_3F_Text_JoseDefeat$"

SilphCo_3F_Text_JoseIntro::
# 45 "data/maps/SilphCo_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_3F_Text_JoseIntro$"

SilphCo_3F_Text_JosePostBattle::
# 49 "data/maps/SilphCo_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_3F_Text_JosePostBattle$"
