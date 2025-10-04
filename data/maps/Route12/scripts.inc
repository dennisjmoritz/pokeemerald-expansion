Route12_MapScripts::
	.byte 0


Route12_EventScript_FishingSign::
# 5 "data/maps/Route12/scripts.pory"
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end


Route12_EventScript_RouteSign::
# 10 "data/maps/Route12/scripts.pory"
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end


Route12_EventScript_Snorlax::
	end


Route12_Text_RouteSign::
# 19 "data/maps/Route12/scripts.pory"
	.string "ROUTE 12 North to LAVENDER$"

Route12_Text_SportfishingArea::
# 23 "data/maps/Route12/scripts.pory"
	.string "SPORTFISHING AREA$"
