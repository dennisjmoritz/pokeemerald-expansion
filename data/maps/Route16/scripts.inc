Route16_MapScripts::
	.byte 0


Route16_EventScript_CyclingRoadSign::
# 5 "data/maps/Route16/scripts.pory"
	msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
	end


Route16_EventScript_RouteSign::
# 10 "data/maps/Route16/scripts.pory"
	msgbox Route16_Text_RouteSign, MSGBOX_SIGN
	end


Route16_EventScript_Snorlax::
	end


Route16_Text_RouteSign::
# 19 "data/maps/Route16/scripts.pory"
	.string "ROUTE 16 CELADON CITY - FUCHSIA CITY$"

Route16_Text_CyclingRoadSign::
# 23 "data/maps/Route16/scripts.pory"
	.string "Enjoy the slope! CYCLING ROAD$"
