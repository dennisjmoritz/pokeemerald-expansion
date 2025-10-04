AbandonedShip_Corridors_B1F_MapScripts::
	.byte 0


AbandonedShip_Corridors_B1F_EventScript_Duncan::
# 5 "data/maps/AbandonedShip_Corridors_B1F/scripts.pory"
	trainerbattle_double TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_DuncanIntro, AbandonedShip_Corridors_B1F_Text_DuncanDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/AbandonedShip_Corridors_B1F/scripts.pory"
	msgbox AbandonedShip_Corridors_B1F_Text_DuncanPostBattle
	return


AbandonedShip_Corridors_B1F_EventScript_StorageRoomDoor::
# 14 "data/maps/AbandonedShip_Corridors_B1F/scripts.pory"
	msgbox AbandonedShip_Corridors_B1F_Text_InsertedStorageKey, MSGBOX_DEFAULT
	end


AbandonedShip_Corridors_B1F_EventScript_TuberM::
# 25 "data/maps/AbandonedShip_Corridors_B1F/scripts.pory"
	msgbox AbandonedShip_Corridors_B1F_Text_YayItsAShip, MSGBOX_NPC
	end


AbandonedShip_Corridors_B1F_Text_InsertedStorageKey::
# 30 "data/maps/AbandonedShip_Corridors_B1F/scripts.pory"
	.string "{PLAYER} inserted and turned the\n"
	.string "STORAGE KEY.\p"
	.string "The inserted KEY stuck fast, but the\n"
	.string "door opened.$"

AbandonedShip_Corridors_B1F_Text_DuncanDefeat::
# 35 "data/maps/AbandonedShip_Corridors_B1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Corridors_B1F_Text_DuncanDefeat$"

AbandonedShip_Corridors_B1F_Text_DuncanIntro::
# 39 "data/maps/AbandonedShip_Corridors_B1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Corridors_B1F_Text_DuncanIntro$"

AbandonedShip_Corridors_B1F_Text_DuncanPostBattle::
# 43 "data/maps/AbandonedShip_Corridors_B1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "AbandonedShip_Corridors_B1F_Text_DuncanPostBattle$"

AbandonedShip_Text_TheDoorIsOpen::
# 47 "data/maps/AbandonedShip_Corridors_B1F/scripts.pory"
	.string "The door is open.$"

AbandonedShip_Corridors_B1F_Text_YayItsAShip::
# 51 "data/maps/AbandonedShip_Corridors_B1F/scripts.pory"
	.string "Yay!\n"
	.string "It's a ship!$"

AbandonedShip_Corridors_B1F_Text_DoorIsLocked::
# 55 "data/maps/AbandonedShip_Corridors_B1F/scripts.pory"
	.string "The door is locked.\p"
	.string "“STORAGE” is painted on the door.$"
