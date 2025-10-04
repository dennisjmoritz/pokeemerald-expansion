AbandonedShip_Rooms_1F_MapScripts::
	.byte 0


AbandonedShip_Rooms_1F_EventScript_Demetrius::
# 5 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	trainerbattle_double TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle
	return


AbandonedShip_Rooms_1F_EventScript_Gentleman::
# 10 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end


AbandonedShip_Rooms_1F_EventScript_Thalia::
# 15 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	trainerbattle_double TRAINER_THALIA, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle
	return


AbandonedShip_Rooms_1F_Text_DemetriusDefeat::
# 20 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Rooms_1F_Text_DemetriusDefeat$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro::
# 24 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Rooms_1F_Text_DemetriusIntro$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle::
# 28 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Rooms_1F_Text_DemetriusPostBattle$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat::
# 32 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Rooms_1F_Text_ThaliaDefeat$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro::
# 36 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Rooms_1F_Text_ThaliaIntro$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle::
# 40 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Rooms_1F_Text_ThaliaPostBattle$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister::
# 44 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "You're such a tough TRAINER!\n"
	.string "Let me register you as a memento!$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch::
# 48 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "I'm sure that man's up to something!\n"
	.string "He just acts so suspiciously!$"

AbandonedShip_Rooms_1F_Text_TakingALookAround::
# 52 "data/maps/AbandonedShip_Rooms_1F/scripts.pory"
	.string "Ships of this sort are rare, so I'm\n"
	.string "taking a look around.\p"
	.string "Hmhm…\n"
	.string "There appear to be other cabins…$"
