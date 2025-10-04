FiveIsland_Meadow_MapScripts::
	.byte 0


FiveIsland_Meadow_EventScript_Rocket1::
# 5 "data/maps/FiveIsland_Meadow/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_49, FiveIsland_Meadow_Text_Rocket1Intro, FiveIsland_Meadow_Text_Rocket1Defeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/FiveIsland_Meadow/scripts.pory"
	msgbox FiveIsland_Meadow_Text_Rocket1PostBattle
	return


FiveIsland_Meadow_EventScript_Rocket2::
# 10 "data/maps/FiveIsland_Meadow/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_50, FiveIsland_Meadow_Text_Rocket2Intro, FiveIsland_Meadow_Text_Rocket2Defeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/FiveIsland_Meadow/scripts.pory"
	msgbox FiveIsland_Meadow_Text_Rocket2PostBattle
	return


FiveIsland_Meadow_EventScript_Rocket3::
# 15 "data/maps/FiveIsland_Meadow/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_51, FiveIsland_Meadow_Text_Rocket3Intro, FiveIsland_Meadow_Text_Rocket3Defeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/FiveIsland_Meadow/scripts.pory"
	msgbox FiveIsland_Meadow_Text_Rocket3PostBattle
	return


FiveIsland_Meadow_EventScript_WarehouseDoor::
# 23 "data/maps/FiveIsland_Meadow/scripts.pory"
	msgbox FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded, MSGBOX_DEFAULT
	end


FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded::
# 29 "data/maps/FiveIsland_Meadow/scripts.pory"
	.string "{PLAYER} entered a password.\p"
	.string "“GOLDEEN need log.”\p"
	.string "… … … … … …\p"
	.string "Another password is needed to open the\n"
	.string "door…$"

FiveIsland_Meadow_Text_Rocket1Defeat::
# 34 "data/maps/FiveIsland_Meadow/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_Meadow_Text_Rocket1Defeat$"

FiveIsland_Meadow_Text_Rocket1Intro::
# 38 "data/maps/FiveIsland_Meadow/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_Meadow_Text_Rocket1Intro$"

FiveIsland_Meadow_Text_Rocket1PostBattle::
# 42 "data/maps/FiveIsland_Meadow/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_Meadow_Text_Rocket1PostBattle$"

FiveIsland_Meadow_Text_Rocket2Defeat::
# 46 "data/maps/FiveIsland_Meadow/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_Meadow_Text_Rocket2Defeat$"

FiveIsland_Meadow_Text_Rocket2Intro::
# 50 "data/maps/FiveIsland_Meadow/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_Meadow_Text_Rocket2Intro$"

FiveIsland_Meadow_Text_Rocket2PostBattle::
# 54 "data/maps/FiveIsland_Meadow/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_Meadow_Text_Rocket2PostBattle$"

FiveIsland_Meadow_Text_Rocket3Defeat::
# 58 "data/maps/FiveIsland_Meadow/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_Meadow_Text_Rocket3Defeat$"

FiveIsland_Meadow_Text_Rocket3Intro::
# 62 "data/maps/FiveIsland_Meadow/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_Meadow_Text_Rocket3Intro$"

FiveIsland_Meadow_Text_Rocket3PostBattle::
# 66 "data/maps/FiveIsland_Meadow/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_Meadow_Text_Rocket3PostBattle$"
