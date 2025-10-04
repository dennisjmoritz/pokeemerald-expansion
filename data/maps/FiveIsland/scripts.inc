FiveIsland_MapScripts::
	.byte 0


FiveIsland_EventScript_BugCatcher::
# 5 "data/maps/FiveIsland/scripts.pory"
	msgbox FiveIsland_Text_WeirdBuildingInMeadow, MSGBOX_NPC
	end


FiveIsland_EventScript_Fisher::
# 10 "data/maps/FiveIsland/scripts.pory"
	msgbox FiveIsland_Text_BeenGettingBusierAroundHere, MSGBOX_NPC
	end


FiveIsland_EventScript_IslandSign::
# 15 "data/maps/FiveIsland/scripts.pory"
	msgbox FiveIsland_Text_IslandSign, MSGBOX_SIGN
	end


FiveIsland_Text_IslandSign::
# 20 "data/maps/FiveIsland/scripts.pory"
	.string "FIVE ISLAND Chrono Island: Where Time\n"
	.string "Goes$"

FiveIsland_Text_WeirdBuildingInMeadow::
# 24 "data/maps/FiveIsland/scripts.pory"
	.string "Oh, this stinks. I wanted to play in\n"
	.string "the MEADOW.\p"
	.string "But they put up a weird building\n"
	.string "on it, so I can't play there.$"

FiveIsland_Text_BeenGettingBusierAroundHere::
# 28 "data/maps/FiveIsland/scripts.pory"
	.string "It's been getting busier around\n"
	.string "these parts lately.\p"
	.string "I haven't been catching many good\n"
	.string "fish lately, either.$"
