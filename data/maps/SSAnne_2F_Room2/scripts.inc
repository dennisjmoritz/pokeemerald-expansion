SSAnne_2F_Room2_MapScripts::
	.byte 0


SSAnne_2F_Room2_EventScript_Brooks::
# 5 "data/maps/SSAnne_2F_Room2/scripts.pory"
	trainerbattle_double TRAINER_GENTLEMAN_BROOKS, SSAnne_2F_Room2_Text_BrooksIntro, SSAnne_2F_Room2_Text_BrooksDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SSAnne_2F_Room2/scripts.pory"
	msgbox SSAnne_2F_Room2_Text_BrooksPostBattle
	return


SSAnne_2F_Room2_EventScript_Dale::
# 10 "data/maps/SSAnne_2F_Room2/scripts.pory"
	trainerbattle_double TRAINER_FISHERMAN_DALE, SSAnne_2F_Room2_Text_DaleIntro, SSAnne_2F_Room2_Text_DaleDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SSAnne_2F_Room2/scripts.pory"
	msgbox SSAnne_2F_Room2_Text_DalePostBattle
	return


SSAnne_2F_Room2_EventScript_ItemStardust::
	end


SSAnne_2F_Room2_Text_BrooksDefeat::
# 20 "data/maps/SSAnne_2F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_2F_Room2_Text_BrooksDefeat$"

SSAnne_2F_Room2_Text_BrooksIntro::
# 24 "data/maps/SSAnne_2F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_2F_Room2_Text_BrooksIntro$"

SSAnne_2F_Room2_Text_BrooksPostBattle::
# 28 "data/maps/SSAnne_2F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_2F_Room2_Text_BrooksPostBattle$"

SSAnne_2F_Room2_Text_DaleDefeat::
# 32 "data/maps/SSAnne_2F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_2F_Room2_Text_DaleDefeat$"

SSAnne_2F_Room2_Text_DaleIntro::
# 36 "data/maps/SSAnne_2F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_2F_Room2_Text_DaleIntro$"

SSAnne_2F_Room2_Text_DalePostBattle::
# 40 "data/maps/SSAnne_2F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_2F_Room2_Text_DalePostBattle$"
