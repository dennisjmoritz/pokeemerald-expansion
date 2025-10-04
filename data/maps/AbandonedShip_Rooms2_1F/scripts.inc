AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0


AbandonedShip_Rooms2_1F_EventScript_Dan::
	end


AbandonedShip_Rooms2_1F_EventScript_Garrison::
# 9 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_double TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat, Text_NotEnoughMonsForDoubleBattle
# 10 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle
	return


AbandonedShip_Rooms2_1F_EventScript_Jani::
# 14 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	trainerbattle_double TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat, Text_NotEnoughMonsForDoubleBattle
# 15 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle
	return


AbandonedShip_Rooms2_1F_EventScript_Kira::
	end


AbandonedShip_Rooms2_1F_Text_GarrisonDefeat::
# 23 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Rooms2_1F_Text_GarrisonDefeat$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro::
# 27 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Rooms2_1F_Text_GarrisonIntro$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle::
# 31 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat::
# 35 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Rooms2_1F_Text_JaniDefeat$"

AbandonedShip_Rooms2_1F_Text_JaniIntro::
# 39 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Rooms2_1F_Text_JaniIntro$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle::
# 43 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Rooms2_1F_Text_JaniPostBattle$"

AbandonedShip_Rooms2_1F_Text_KiraRegister::
# 47 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "KIRA: Oh, you make me so angry!\n"
	.string "I'm going to register you for that!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch::
# 51 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "DAN: We can't find any treasures,\n"
	.string "we lose at POKéMON…\p"
	.string "I want to go home… But if I say that,\n"
	.string "she gets all angry with me…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch::
# 55 "data/maps/AbandonedShip_Rooms2_1F/scripts.pory"
	.string "KIRA: We're not leaving until we raise\n"
	.string "our POKéMON some more and we find\l"
	.string "the treasures here!$"
