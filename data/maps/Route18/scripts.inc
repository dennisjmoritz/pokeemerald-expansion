Route18_MapScripts::
	.byte 0


Route18_EventScript_CyclingRoadSign::
# 5 "data/maps/Route18/scripts.pory"
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end


Route18_EventScript_RouteSign::
# 10 "data/maps/Route18/scripts.pory"
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end


Route18_Text_RouteSign::
# 15 "data/maps/Route18/scripts.pory"
	.string "ROUTE 18 CELADON CITY - FUCHSIA CITY$"

Route18_Text_CyclingRoadSign::
# 19 "data/maps/Route18/scripts.pory"
	.string "CYCLING ROAD No pedestrians permitted!$"
