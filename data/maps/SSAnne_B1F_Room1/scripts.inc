SSAnne_B1F_Room1_MapScripts::
	.byte 0


SSAnne_B1F_Room1_EventScript_Barny::
# 5 "data/maps/SSAnne_B1F_Room1/scripts.pory"
	trainerbattle_double TRAINER_FISHERMAN_BARNY, SSAnne_B1F_Room1_Text_BarnyIntro, SSAnne_B1F_Room1_Text_BarnyDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SSAnne_B1F_Room1/scripts.pory"
	msgbox SSAnne_B1F_Room1_Text_BarnyPostBattle
	return


SSAnne_B1F_Room1_EventScript_Phillip::
# 10 "data/maps/SSAnne_B1F_Room1/scripts.pory"
	trainerbattle_double TRAINER_SAILOR_PHILLIP, SSAnne_B1F_Room1_Text_PhillipIntro, SSAnne_B1F_Room1_Text_PhillipDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SSAnne_B1F_Room1/scripts.pory"
	msgbox SSAnne_B1F_Room1_Text_PhillipPostBattle
	return


SSAnne_B1F_Room1_Text_BarnyDefeat::
# 16 "data/maps/SSAnne_B1F_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room1_Text_BarnyDefeat$"

SSAnne_B1F_Room1_Text_BarnyIntro::
# 20 "data/maps/SSAnne_B1F_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room1_Text_BarnyIntro$"

SSAnne_B1F_Room1_Text_BarnyPostBattle::
# 24 "data/maps/SSAnne_B1F_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room1_Text_BarnyPostBattle$"

SSAnne_B1F_Room1_Text_PhillipDefeat::
# 28 "data/maps/SSAnne_B1F_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room1_Text_PhillipDefeat$"

SSAnne_B1F_Room1_Text_PhillipIntro::
# 32 "data/maps/SSAnne_B1F_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room1_Text_PhillipIntro$"

SSAnne_B1F_Room1_Text_PhillipPostBattle::
# 36 "data/maps/SSAnne_B1F_Room1/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room1_Text_PhillipPostBattle$"
