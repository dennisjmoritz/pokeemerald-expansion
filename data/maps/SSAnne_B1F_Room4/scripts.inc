SSAnne_B1F_Room4_MapScripts::
	.byte 0


SSAnne_B1F_Room4_EventScript_Duncan::
# 5 "data/maps/SSAnne_B1F_Room4/scripts.pory"
	trainerbattle_double TRAINER_SAILOR_DUNCAN, SSAnne_B1F_Room4_Text_DuncanIntro, SSAnne_B1F_Room4_Text_DuncanDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SSAnne_B1F_Room4/scripts.pory"
	msgbox SSAnne_B1F_Room4_Text_DuncanPostBattle
	return


SSAnne_B1F_Room4_EventScript_Leonard::
# 10 "data/maps/SSAnne_B1F_Room4/scripts.pory"
	trainerbattle_double TRAINER_SAILOR_LEONARD, SSAnne_B1F_Room4_Text_LeonardIntro, SSAnne_B1F_Room4_Text_LeonardDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SSAnne_B1F_Room4/scripts.pory"
	msgbox SSAnne_B1F_Room4_Text_LeonardPostBattle
	return


SSAnne_B1F_Room4_Text_DuncanDefeat::
# 16 "data/maps/SSAnne_B1F_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room4_Text_DuncanDefeat$"

SSAnne_B1F_Room4_Text_DuncanIntro::
# 20 "data/maps/SSAnne_B1F_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room4_Text_DuncanIntro$"

SSAnne_B1F_Room4_Text_DuncanPostBattle::
# 24 "data/maps/SSAnne_B1F_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room4_Text_DuncanPostBattle$"

SSAnne_B1F_Room4_Text_LeonardDefeat::
# 28 "data/maps/SSAnne_B1F_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room4_Text_LeonardDefeat$"

SSAnne_B1F_Room4_Text_LeonardIntro::
# 32 "data/maps/SSAnne_B1F_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room4_Text_LeonardIntro$"

SSAnne_B1F_Room4_Text_LeonardPostBattle::
# 36 "data/maps/SSAnne_B1F_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room4_Text_LeonardPostBattle$"
