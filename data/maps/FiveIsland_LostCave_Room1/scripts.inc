FiveIsland_LostCave_Room1_MapScripts::
	.byte 0


FiveIsland_LostCave_Room1_EventScript_Lawson::
# 5 "data/maps/FiveIsland_LostCave_Room1/scripts.pory"
	trainerbattle_double TRAINER_RUIN_MANIAC_LAWSON, FiveIsland_LostCave_Room1_Text_LawsonIntro, FiveIsland_LostCave_Room1_Text_LawsonDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/FiveIsland_LostCave_Room1/scripts.pory"
	msgbox FiveIsland_LostCave_Room1_Text_LawsonPostBattle
	return


FiveIsland_LostCave_Room1_Text_LawsonDefeat::
# 11 "data/maps/FiveIsland_LostCave_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_LostCave_Room1_Text_LawsonDefeat$"

FiveIsland_LostCave_Room1_Text_LawsonIntro::
# 15 "data/maps/FiveIsland_LostCave_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_LostCave_Room1_Text_LawsonIntro$"

FiveIsland_LostCave_Room1_Text_LawsonPostBattle::
# 19 "data/maps/FiveIsland_LostCave_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_LostCave_Room1_Text_LawsonPostBattle$"
