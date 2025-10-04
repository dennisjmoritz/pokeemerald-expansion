Route2_MapScripts::
	.byte 0


Route2_EventScript_DiglettsCaveSign::
# 5 "data/maps/Route2/scripts.pory"
	msgbox Route2_Text_DiglettsCave, MSGBOX_SIGN
	end


Route2_EventScript_RouteSign::
# 10 "data/maps/Route2/scripts.pory"
	msgbox Route2_Text_RouteSign, MSGBOX_SIGN
	end


Route2_Text_DiglettsCave::
# 15 "data/maps/Route2/scripts.pory"
	.string "DIGLETT'S CAVE$"

Route2_Text_RouteSign::
# 19 "data/maps/Route2/scripts.pory"
	.string "ROUTE 2 VIRIDIAN CITY - PEWTER CITY$"
