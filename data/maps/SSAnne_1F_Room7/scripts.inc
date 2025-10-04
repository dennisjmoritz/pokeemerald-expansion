SSAnne_1F_Room7_MapScripts::
	.byte 0


SSAnne_1F_Room7_EventScript_Thomas::
# 5 "data/maps/SSAnne_1F_Room7/scripts.pory"
	trainerbattle_double TRAINER_GENTLEMAN_THOMAS, SSAnne_1F_Room7_Text_ThomasIntro, SSAnne_1F_Room7_Text_ThomasDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SSAnne_1F_Room7/scripts.pory"
	msgbox SSAnne_1F_Room7_Text_ThomasPostBattle
	return


SSAnne_1F_Room7_Text_ThomasDefeat::
# 11 "data/maps/SSAnne_1F_Room7/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_1F_Room7_Text_ThomasDefeat$"

SSAnne_1F_Room7_Text_ThomasIntro::
# 15 "data/maps/SSAnne_1F_Room7/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_1F_Room7_Text_ThomasIntro$"

SSAnne_1F_Room7_Text_ThomasPostBattle::
# 19 "data/maps/SSAnne_1F_Room7/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_1F_Room7_Text_ThomasPostBattle$"
