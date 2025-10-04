AbandonedShip_Corridors_1F_MapScripts::
	.byte 0


AbandonedShip_Corridors_1F_EventScript_Charlie::
# 5 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	trainerbattle_double TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle
	return


AbandonedShip_Corridors_1F_EventScript_Youngster::
# 10 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end


AbandonedShip_Corridors_1F_Text_CharlieDefeat::
# 16 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Corridors_1F_Text_CharlieDefeat$"

AbandonedShip_Corridors_1F_Text_CharlieIntro::
# 20 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Corridors_1F_Text_CharlieIntro$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle::
# 24 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Corridors_1F_Text_CharliePostBattle$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere::
# 28 "data/maps/AbandonedShip_Corridors_1F/scripts.pory"
	.string "Isn't it fun here?\n"
	.string "I get excited just being here!$"
