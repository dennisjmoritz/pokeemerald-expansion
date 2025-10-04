SSAnne_B1F_Room2_MapScripts::
	.byte 0


SSAnne_B1F_Room2_EventScript_Huey::
# 5 "data/maps/SSAnne_B1F_Room2/scripts.pory"
	trainerbattle_double TRAINER_SAILOR_HUEY, SSAnne_B1F_Room2_Text_HueyIntro, SSAnne_B1F_Room2_Text_HueyDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SSAnne_B1F_Room2/scripts.pory"
	msgbox SSAnne_B1F_Room2_Text_HueyPostBattle
	return


SSAnne_B1F_Room2_EventScript_ItemTM44::
	end


SSAnne_B1F_Room2_Text_HueyDefeat::
# 15 "data/maps/SSAnne_B1F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room2_Text_HueyDefeat$"

SSAnne_B1F_Room2_Text_HueyIntro::
# 19 "data/maps/SSAnne_B1F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room2_Text_HueyIntro$"

SSAnne_B1F_Room2_Text_HueyPostBattle::
# 23 "data/maps/SSAnne_B1F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room2_Text_HueyPostBattle$"
