SilphCo_5F_MapScripts::
	.byte 0


SilphCo_5F_EventScript_Beau::
# 5 "data/maps/SilphCo_5F/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_BEAU, SilphCo_5F_Text_BeauIntro, SilphCo_5F_Text_BeauDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SilphCo_5F/scripts.pory"
	msgbox SilphCo_5F_Text_BeauPostBattle
	return


SilphCo_5F_EventScript_Dalton::
# 10 "data/maps/SilphCo_5F/scripts.pory"
	trainerbattle_double TRAINER_JUGGLER_DALTON, SilphCo_5F_Text_DaltonIntro, SilphCo_5F_Text_DaltonDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SilphCo_5F/scripts.pory"
	msgbox SilphCo_5F_Text_DaltonPostBattle
	return


SilphCo_5F_EventScript_FloorSign::
# 15 "data/maps/SilphCo_5F/scripts.pory"
	msgbox SilphCo_5F_Text_FloorSign, MSGBOX_SIGN
	end


SilphCo_5F_EventScript_Grunt1::
# 20 "data/maps/SilphCo_5F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_28, SilphCo_5F_Text_Grunt1Intro, SilphCo_5F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/SilphCo_5F/scripts.pory"
	msgbox SilphCo_5F_Text_Grunt1PostBattle
	return


SilphCo_5F_EventScript_Grunt2::
# 25 "data/maps/SilphCo_5F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_29, SilphCo_5F_Text_Grunt2Intro, SilphCo_5F_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/SilphCo_5F/scripts.pory"
	msgbox SilphCo_5F_Text_Grunt2PostBattle
	return


SilphCo_5F_EventScript_PokemonReport1::
# 30 "data/maps/SilphCo_5F/scripts.pory"
	msgbox SilphCo_5F_Text_PorygonFirstVRMon, MSGBOX_SIGN
	end


SilphCo_5F_EventScript_PokemonReport2::
# 35 "data/maps/SilphCo_5F/scripts.pory"
	msgbox SilphCo_5F_Text_Over350TechniquesConfirmed, MSGBOX_SIGN
	end


SilphCo_5F_EventScript_PokemonReport3::
# 40 "data/maps/SilphCo_5F/scripts.pory"
	msgbox SilphCo_5F_Text_SomeMonsEvolveWhenTraded, MSGBOX_SIGN
	end


SilphCo_5F_EventScript_WorkerM::
	end


SilphCo_5F_Text_PorygonFirstVRMon::
# 49 "data/maps/SilphCo_5F/scripts.pory"
	.string "It's a POKéMON REPORT!\p"
	.string "POKéMON LAB created PORYGON, the first\n"
	.string "virtual-reality POKéMON.$"

SilphCo_5F_Text_SomeMonsEvolveWhenTraded::
# 53 "data/maps/SilphCo_5F/scripts.pory"
	.string "It's a POKéMON REPORT!\p"
	.string "Some POKéMON have been confirmed to\n"
	.string "evolve when they are traded.$"

SilphCo_5F_Text_Over350TechniquesConfirmed::
# 57 "data/maps/SilphCo_5F/scripts.pory"
	.string "It's a POKéMON REPORT!\p"
	.string "Over 350 POKéMON techniques have been\n"
	.string "confirmed.$"

SilphCo_5F_Text_FloorSign::
# 61 "data/maps/SilphCo_5F/scripts.pory"
	.string "SILPH CO. HEAD OFFICE 5F$"

SilphCo_5F_Text_BeauDefeat::
# 66 "data/maps/SilphCo_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_5F_Text_BeauDefeat$"

SilphCo_5F_Text_BeauIntro::
# 70 "data/maps/SilphCo_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_5F_Text_BeauIntro$"

SilphCo_5F_Text_BeauPostBattle::
# 74 "data/maps/SilphCo_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_5F_Text_BeauPostBattle$"

SilphCo_5F_Text_DaltonDefeat::
# 78 "data/maps/SilphCo_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_5F_Text_DaltonDefeat$"

SilphCo_5F_Text_DaltonIntro::
# 82 "data/maps/SilphCo_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_5F_Text_DaltonIntro$"

SilphCo_5F_Text_DaltonPostBattle::
# 86 "data/maps/SilphCo_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_5F_Text_DaltonPostBattle$"

SilphCo_5F_Text_Grunt1Defeat::
# 90 "data/maps/SilphCo_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_5F_Text_Grunt1Defeat$"

SilphCo_5F_Text_Grunt1Intro::
# 94 "data/maps/SilphCo_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_5F_Text_Grunt1Intro$"

SilphCo_5F_Text_Grunt1PostBattle::
# 98 "data/maps/SilphCo_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_5F_Text_Grunt1PostBattle$"

SilphCo_5F_Text_Grunt2Defeat::
# 102 "data/maps/SilphCo_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_5F_Text_Grunt2Defeat$"

SilphCo_5F_Text_Grunt2Intro::
# 106 "data/maps/SilphCo_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_5F_Text_Grunt2Intro$"

SilphCo_5F_Text_Grunt2PostBattle::
# 110 "data/maps/SilphCo_5F/scripts.pory"
	.string "Placeholder text for\n"
	.string "SilphCo_5F_Text_Grunt2PostBattle$"
