Route1_MapScripts::
	.byte 0


Route1_EventScript_Boy::
# 5 "data/maps/Route1/scripts.pory"
	msgbox Route1_Text_CanJumpFromLedges, MSGBOX_NPC
	end


Route1_EventScript_MartClerk::
	end


Route1_EventScript_RouteSign::
# 14 "data/maps/Route1/scripts.pory"
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end


Route1_Text_RouteSign::
# 19 "data/maps/Route1/scripts.pory"
	.string "ROUTE 1 PALLET TOWN - VIRIDIAN CITY$"

Route1_Text_CanJumpFromLedges::
# 23 "data/maps/Route1/scripts.pory"
	.string "See those ledges along the road?\p"
	.string "It's a bit scary, but you can jump\n"
	.string "from them.\p"
	.string "You can get back to PALLET TOWN\n"
	.string "quicker that way.$"
