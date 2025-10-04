SilphCo_11F_MapScripts::
	.byte 0


SilphCo_11F_EventScript_FloorSign::
# 5 "data/maps/SilphCo_11F/scripts.pory"
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end


SilphCo_11F_EventScript_GiovanniTriggerLeft::
	end


SilphCo_11F_EventScript_GiovanniTriggerRight::
	end


SilphCo_11F_EventScript_Grunt1::
# 18 "data/maps/SilphCo_11F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_40, SilphCo_11F_Text_Grunt1Intro, SilphCo_11F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 19 "data/maps/SilphCo_11F/scripts.pory"
	msgbox SilphCo_11F_Text_Grunt1PostBattle
	return


SilphCo_11F_EventScript_Grunt2::
# 23 "data/maps/SilphCo_11F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_41, SilphCo_11F_Text_Grunt2Intro, SilphCo_11F_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 24 "data/maps/SilphCo_11F/scripts.pory"
	msgbox SilphCo_11F_Text_Grunt2PostBattle
	return


SilphCo_11F_EventScript_President::
	end


SilphCo_11F_EventScript_Secretary::
# 32 "data/maps/SilphCo_11F/scripts.pory"
	msgbox SilphCo_11F_Text_ThanksForRescuingUs, MSGBOX_NPC
	end


SilphCo_11F_Text_FloorSign::
# 37 "data/maps/SilphCo_11F/scripts.pory"
	.string "SILPH CO. HEAD OFFICE 11F$"

SilphCo_11F_Text_Grunt1Defeat::
# 42 "data/maps/SilphCo_11F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_11F_Text_Grunt1Defeat$"

SilphCo_11F_Text_Grunt1Intro::
# 46 "data/maps/SilphCo_11F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_11F_Text_Grunt1Intro$"

SilphCo_11F_Text_Grunt1PostBattle::
# 50 "data/maps/SilphCo_11F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_11F_Text_Grunt1PostBattle$"

SilphCo_11F_Text_Grunt2Defeat::
# 54 "data/maps/SilphCo_11F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_11F_Text_Grunt2Defeat$"

SilphCo_11F_Text_Grunt2Intro::
# 58 "data/maps/SilphCo_11F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_11F_Text_Grunt2Intro$"

SilphCo_11F_Text_Grunt2PostBattle::
# 62 "data/maps/SilphCo_11F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_11F_Text_Grunt2PostBattle$"

SilphCo_11F_Text_ThanksForRescuingUs::
# 65 "data/maps/SilphCo_11F/scripts.pory"
	.string "SECRETARY: Thank you for rescuing\n"
	.string "all of us.\p"
	.string "We, from the PRESIDENT down,\n"
	.string "are indebted to you.$"
