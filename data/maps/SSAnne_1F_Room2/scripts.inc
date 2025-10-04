SSAnne_1F_Room2_MapScripts::
	.byte 0


SSAnne_1F_Room2_EventScript_Ann::
# 5 "data/maps/SSAnne_1F_Room2/scripts.pory"
	trainerbattle_double TRAINER_LASS_ANN, SSAnne_1F_Room2_Text_AnnIntro, SSAnne_1F_Room2_Text_AnnDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SSAnne_1F_Room2/scripts.pory"
	msgbox SSAnne_1F_Room2_Text_AnnPostBattle
	return


SSAnne_1F_Room2_EventScript_ItemTM31::
	end


SSAnne_1F_Room2_EventScript_Tyler::
# 14 "data/maps/SSAnne_1F_Room2/scripts.pory"
	trainerbattle_double TRAINER_YOUNGSTER_TYLER, SSAnne_1F_Room2_Text_TylerIntro, SSAnne_1F_Room2_Text_TylerDefeat, Text_NotEnoughMonsForDoubleBattle
# 15 "data/maps/SSAnne_1F_Room2/scripts.pory"
	msgbox SSAnne_1F_Room2_Text_TylerPostBattle
	return


SSAnne_1F_Room2_EventScript_Woman::
# 19 "data/maps/SSAnne_1F_Room2/scripts.pory"
	msgbox SSAnne_1F_Room2_Text_CruisingAroundWorld, MSGBOX_NPC
	end


SSAnne_1F_Room2_Text_AnnDefeat::
# 25 "data/maps/SSAnne_1F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_1F_Room2_Text_AnnDefeat$"

SSAnne_1F_Room2_Text_AnnIntro::
# 29 "data/maps/SSAnne_1F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_1F_Room2_Text_AnnIntro$"

SSAnne_1F_Room2_Text_AnnPostBattle::
# 33 "data/maps/SSAnne_1F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_1F_Room2_Text_AnnPostBattle$"

SSAnne_1F_Room2_Text_TylerDefeat::
# 37 "data/maps/SSAnne_1F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_1F_Room2_Text_TylerDefeat$"

SSAnne_1F_Room2_Text_TylerIntro::
# 41 "data/maps/SSAnne_1F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_1F_Room2_Text_TylerIntro$"

SSAnne_1F_Room2_Text_TylerPostBattle::
# 45 "data/maps/SSAnne_1F_Room2/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_1F_Room2_Text_TylerPostBattle$"

SSAnne_1F_Room2_Text_CruisingAroundWorld::
# 48 "data/maps/SSAnne_1F_Room2/scripts.pory"
	.string "We are cruising around the world,\n"
	.string "my children and I.$"
