SSAnne_2F_Room4_MapScripts::
	.byte 0


SSAnne_2F_Room4_EventScript_Dawn::
# 5 "data/maps/SSAnne_2F_Room4/scripts.pory"
	trainerbattle_double TRAINER_LASS_DAWN, SSAnne_2F_Room4_Text_DawnIntro, SSAnne_2F_Room4_Text_DawnDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SSAnne_2F_Room4/scripts.pory"
	msgbox SSAnne_2F_Room4_Text_DawnPostBattle
	return


SSAnne_2F_Room4_EventScript_ItemXAttack::
	end


SSAnne_2F_Room4_EventScript_Lamar::
# 14 "data/maps/SSAnne_2F_Room4/scripts.pory"
	trainerbattle_double TRAINER_GENTLEMAN_LAMAR, SSAnne_2F_Room4_Text_LamarIntro, SSAnne_2F_Room4_Text_LamarDefeat, Text_NotEnoughMonsForDoubleBattle
# 15 "data/maps/SSAnne_2F_Room4/scripts.pory"
	msgbox SSAnne_2F_Room4_Text_LamarPostBattle
	return


SSAnne_2F_Room4_Text_DawnDefeat::
# 20 "data/maps/SSAnne_2F_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_2F_Room4_Text_DawnDefeat$"

SSAnne_2F_Room4_Text_DawnIntro::
# 24 "data/maps/SSAnne_2F_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_2F_Room4_Text_DawnIntro$"

SSAnne_2F_Room4_Text_DawnPostBattle::
# 28 "data/maps/SSAnne_2F_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_2F_Room4_Text_DawnPostBattle$"

SSAnne_2F_Room4_Text_LamarDefeat::
# 32 "data/maps/SSAnne_2F_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_2F_Room4_Text_LamarDefeat$"

SSAnne_2F_Room4_Text_LamarIntro::
# 36 "data/maps/SSAnne_2F_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_2F_Room4_Text_LamarIntro$"

SSAnne_2F_Room4_Text_LamarPostBattle::
# 40 "data/maps/SSAnne_2F_Room4/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_2F_Room4_Text_LamarPostBattle$"
