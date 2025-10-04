FiveIsland_RocketWarehouse_MapScripts::
	.byte 0


FiveIsland_RocketWarehouse_EventScript_Admin1::
# 5 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_Text_Admin1Intro, FiveIsland_RocketWarehouse_Text_Admin1Defeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough
	return


FiveIsland_RocketWarehouse_EventScript_Admin2::
# 10 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_ADMIN_2, FiveIsland_RocketWarehouse_Text_Admin2Intro, FiveIsland_RocketWarehouse_Text_Admin2Defeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle
	return


FiveIsland_RocketWarehouse_EventScript_Admin2Trigger::
	end


FiveIsland_RocketWarehouse_EventScript_Cage::
# 21 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen, MSGBOX_DEFAULT
	end


FiveIsland_RocketWarehouse_EventScript_Computer::
# 27 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText, MSGBOX_SIGN
	end


FiveIsland_RocketWarehouse_EventScript_Gideon::
# 32 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	trainerbattle_double TRAINER_SCIENTIST_GIDEON, FiveIsland_RocketWarehouse_Text_GideonIntro, FiveIsland_RocketWarehouse_Text_GideonDefeat, Text_NotEnoughMonsForDoubleBattle
# 33 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe
	return


FiveIsland_RocketWarehouse_EventScript_Grunt1::
# 37 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_42, FiveIsland_RocketWarehouse_Text_Grunt1Intro, FiveIsland_RocketWarehouse_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 38 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_Grunt1PostBattle
	return


FiveIsland_RocketWarehouse_EventScript_Grunt2::
# 42 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_47, FiveIsland_RocketWarehouse_Text_Grunt2Intro, FiveIsland_RocketWarehouse_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 43 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_Grunt2PostBattle
	return


FiveIsland_RocketWarehouse_EventScript_Grunt3::
# 47 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_48, FiveIsland_RocketWarehouse_Text_Grunt3Intro, FiveIsland_RocketWarehouse_Text_Grunt3Defeat, Text_NotEnoughMonsForDoubleBattle
# 48 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	msgbox FiveIsland_RocketWarehouse_Text_Grunt3PostBattle
	return


FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText::
# 52 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "A report with graphs and text is on the\n"
	.string "PC monitor.\p"
	.string "“The Influence of Magnetic Waves on\n"
	.string "POKéMON Evolution”…\p"
	.string "… … … … … …\p"
	.string "It's too difficult to understand…$"

FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen::
# 56 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "There are many POKéMON locked away in\n"
	.string "the pen…$"

FiveIsland_RocketWarehouse_Text_Admin1Defeat::
# 61 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Admin1Defeat$"

FiveIsland_RocketWarehouse_Text_Admin1Intro::
# 65 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Admin1Intro$"

FiveIsland_RocketWarehouse_Text_Admin2Defeat::
# 69 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Admin2Defeat$"

FiveIsland_RocketWarehouse_Text_Admin2Intro::
# 73 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Admin2Intro$"

FiveIsland_RocketWarehouse_Text_Admin2PostBattle::
# 77 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Admin2PostBattle$"

FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe::
# 81 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe$"

FiveIsland_RocketWarehouse_Text_GideonDefeat::
# 85 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_GideonDefeat$"

FiveIsland_RocketWarehouse_Text_GideonIntro::
# 89 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_GideonIntro$"

FiveIsland_RocketWarehouse_Text_Grunt1Defeat::
# 93 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Grunt1Defeat$"

FiveIsland_RocketWarehouse_Text_Grunt1Intro::
# 97 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Grunt1Intro$"

FiveIsland_RocketWarehouse_Text_Grunt1PostBattle::
# 101 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Grunt1PostBattle$"

FiveIsland_RocketWarehouse_Text_Grunt2Defeat::
# 105 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Grunt2Defeat$"

FiveIsland_RocketWarehouse_Text_Grunt2Intro::
# 109 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Grunt2Intro$"

FiveIsland_RocketWarehouse_Text_Grunt2PostBattle::
# 113 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Grunt2PostBattle$"

FiveIsland_RocketWarehouse_Text_Grunt3Defeat::
# 117 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Grunt3Defeat$"

FiveIsland_RocketWarehouse_Text_Grunt3Intro::
# 121 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Grunt3Intro$"

FiveIsland_RocketWarehouse_Text_Grunt3PostBattle::
# 125 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_Grunt3PostBattle$"

FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough::
# 129 "data/maps/FiveIsland_RocketWarehouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough$"
