Route4_MapScripts::
	.byte 0


Route4_EventScript_MtMoonSign::
# 5 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end


Route4_EventScript_RouteSign::
# 10 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end


Route4_EventScript_Woman::
# 15 "data/maps/Route4/scripts.pory"
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end


Route4_Text_RouteSign::
# 20 "data/maps/Route4/scripts.pory"
	.string "ROUTE 4 MT. MOON - CERULEAN CITY$"

Route4_Text_MtMoonEntrance::
# 24 "data/maps/Route4/scripts.pory"
	.string "MT. MOON Tunnel Entrance$"

Route4_Text_TrippedOverGeodude::
# 28 "data/maps/Route4/scripts.pory"
	.string "Ouch! I tripped over a rocky\n"
	.string "POKéMON, GEODUDE!$"
