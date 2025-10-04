FiveIsland_LostCave_Room4_MapScripts::
	.byte 0


FiveIsland_LostCave_Room4_EventScript_Laura::
# 5 "data/maps/FiveIsland_LostCave_Room4/scripts.pory"
	trainerbattle_double TRAINER_PSYCHIC_LAURA, FiveIsland_LostCave_Room4_Text_LauraIntro, FiveIsland_LostCave_Room4_Text_LauraDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/FiveIsland_LostCave_Room4/scripts.pory"
	msgbox FiveIsland_LostCave_Room4_Text_LauraPostBattle
	return


FiveIsland_LostCave_Room4_Text_LauraDefeat::
# 11 "data/maps/FiveIsland_LostCave_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_LostCave_Room4_Text_LauraDefeat$"

FiveIsland_LostCave_Room4_Text_LauraIntro::
# 15 "data/maps/FiveIsland_LostCave_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_LostCave_Room4_Text_LauraIntro$"

FiveIsland_LostCave_Room4_Text_LauraPostBattle::
# 19 "data/maps/FiveIsland_LostCave_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "FiveIsland_LostCave_Room4_Text_LauraPostBattle$"
