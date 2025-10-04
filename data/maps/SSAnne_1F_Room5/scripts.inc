SSAnne_1F_Room5_MapScripts::
	.byte 0


SSAnne_1F_Room5_EventScript_Arthur::
# 5 "data/maps/SSAnne_1F_Room5/scripts.pory"
	trainerbattle_double TRAINER_GENTLEMAN_ARTHUR, SSAnne_1F_Room5_Text_ArthurIntro, SSAnne_1F_Room5_Text_ArthurDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SSAnne_1F_Room5/scripts.pory"
	msgbox SSAnne_1F_Room5_Text_ArthurPostBattle
	return


SSAnne_1F_Room5_Text_ArthurDefeat::
# 11 "data/maps/SSAnne_1F_Room5/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_1F_Room5_Text_ArthurDefeat$"

SSAnne_1F_Room5_Text_ArthurIntro::
# 15 "data/maps/SSAnne_1F_Room5/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_1F_Room5_Text_ArthurIntro$"

SSAnne_1F_Room5_Text_ArthurPostBattle::
# 19 "data/maps/SSAnne_1F_Room5/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_1F_Room5_Text_ArthurPostBattle$"
