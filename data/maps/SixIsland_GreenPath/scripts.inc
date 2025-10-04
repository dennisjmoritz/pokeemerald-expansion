SixIsland_GreenPath_MapScripts::
	.byte 0


SixIsland_GreenPath_EventScript_LeftRouteSign::
# 5 "data/maps/SixIsland_GreenPath/scripts.pory"
	msgbox SixIsland_GreenPath_Text_RightRouteSign, MSGBOX_SIGN
	end


SixIsland_GreenPath_EventScript_RightRouteSign::
# 10 "data/maps/SixIsland_GreenPath/scripts.pory"
	msgbox SixIsland_GreenPath_Text_LeftRouteSign, MSGBOX_SIGN
	end


SixIsland_GreenPath_Text_LeftRouteSign::
# 15 "data/maps/SixIsland_GreenPath/scripts.pory"
	.string "GREEN PATH PATTERN BUSH AHEAD$"

SixIsland_GreenPath_Text_RightRouteSign::
# 19 "data/maps/SixIsland_GreenPath/scripts.pory"
	.string "GREEN PATH Think Green, Keep Nature\n"
	.string "Clean!$"
