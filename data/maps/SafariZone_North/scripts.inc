SafariZone_North_MapScripts::
	.byte 0


SafariZone_North_EventScript_AreaSign::
# 5 "data/maps/SafariZone_North/scripts.pory"
	msgbox SafariZone_North_Text_Area2, MSGBOX_SIGN
	end


SafariZone_North_EventScript_RestHouseSign::
# 10 "data/maps/SafariZone_North/scripts.pory"
	msgbox SafariZone_North_Text_RestHouse, MSGBOX_SIGN
	end


SafariZone_North_EventScript_TrainerTips1::
# 15 "data/maps/SafariZone_North/scripts.pory"
	msgbox SafariZone_North_Text_SecretHouseStillAhead, MSGBOX_SIGN
	end


SafariZone_North_EventScript_TrainerTips2::
# 20 "data/maps/SafariZone_North/scripts.pory"
	msgbox SafariZone_North_Text_ZigzagThroughTallGrass, MSGBOX_SIGN
	end


SafariZone_North_EventScript_TrainerTips3::
# 25 "data/maps/SafariZone_North/scripts.pory"
	msgbox SafariZone_North_Text_WinFreeHMFindSecretHouse, MSGBOX_SIGN
	end


SafariZone_North_Text_RestHouse::
# 30 "data/maps/SafariZone_North/scripts.pory"
	.string "REST HOUSE$"

SafariZone_North_Text_SecretHouseStillAhead::
# 34 "data/maps/SafariZone_North/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "The SECRET HOUSE is still ahead.$"

SafariZone_North_Text_WinFreeHMFindSecretHouse::
# 38 "data/maps/SafariZone_North/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "Win a free HM for finding the SECRET\n"
	.string "HOUSE.$"

SafariZone_North_Text_Area2::
# 42 "data/maps/SafariZone_North/scripts.pory"
	.string "AREA 2$"

SafariZone_North_Text_ZigzagThroughTallGrass::
# 46 "data/maps/SafariZone_North/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "POKéMON hide in tall grass.\p"
	.string "Zigzag through grassy areas to flush\n"
	.string "them out.$"
