SixIsland_RuinValley_MapScripts::
	.byte 0


SixIsland_RuinValley_EventScript_DottedHoleDoor::
# 7 "data/maps/SixIsland_RuinValley/scripts.pory"
	msgbox SixIsland_RuinValley_Text_CheckDoorMoreThoroughly, MSGBOX_YESNO
# 9 "data/maps/SixIsland_RuinValley/scripts.pory"
	msgbox SixIsland_RuinValley_Text_SeveralDotsOnTheDoor, MSGBOX_DEFAULT
	end


SixIsland_RuinValley_EventScript_Scientist::
	end


SixIsland_RuinValley_Text_CheckDoorMoreThoroughly::
# 21 "data/maps/SixIsland_RuinValley/scripts.pory"
	.string "The door doesn't budge at all. Check it\n"
	.string "more thoroughly?$"

SixIsland_RuinValley_Text_SeveralDotsOnTheDoor::
# 25 "data/maps/SixIsland_RuinValley/scripts.pory"
	.string "On closer inspection, there are several\n"
	.string "dots on the door…$"
