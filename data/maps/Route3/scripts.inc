Route3_MapScripts::
	.byte 0


Route3_EventScript_RouteSign::
# 5 "data/maps/Route3/scripts.pory"
	msgbox Route3_Text_RouteSign, MSGBOX_SIGN
	end


Route3_EventScript_Youngster::
# 10 "data/maps/Route3/scripts.pory"
	msgbox Route3_Text_TunnelFromCeruleanTiring, MSGBOX_NPC
	end


Route3_Text_RouteSign::
# 15 "data/maps/Route3/scripts.pory"
	.string "ROUTE 3 MT. MOON AHEAD$"

Route3_Text_TunnelFromCeruleanTiring::
# 19 "data/maps/Route3/scripts.pory"
	.string "Whew… I better take a rest…\n"
	.string "Groan…\p"
	.string "That tunnel from CERULEAN takes a\n"
	.string "lot out of you!$"
