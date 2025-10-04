SafariZone_Center_MapScripts::
	.byte 0


SafariZone_Center_EventScript_AreaSign::
# 5 "data/maps/SafariZone_Center/scripts.pory"
	msgbox SafariZone_Center_Text_CenterArea, MSGBOX_SIGN
	end


SafariZone_Center_EventScript_ItemNugget::
	end


SafariZone_Center_EventScript_RestHouseSign::
# 14 "data/maps/SafariZone_Center/scripts.pory"
	msgbox SafariZone_Center_Text_RestHouse, MSGBOX_SIGN
	end


SafariZone_Center_EventScript_TrainerTips::
# 19 "data/maps/SafariZone_Center/scripts.pory"
	msgbox SafariZone_Center_Text_PressStartToCheckTime, MSGBOX_SIGN
	end


SafariZone_Center_Text_CenterArea::
# 24 "data/maps/SafariZone_Center/scripts.pory"
	.string "CENTER AREA$"

SafariZone_Center_Text_RestHouse::
# 28 "data/maps/SafariZone_Center/scripts.pory"
	.string "REST HOUSE$"

SafariZone_Center_Text_PressStartToCheckTime::
# 32 "data/maps/SafariZone_Center/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "Press START to check remaining time.$"
