SlateportCity_House_MapScripts::
	.byte 0


SlateportCity_House_EventScript_Girl::
# 5 "data/maps/SlateportCity_House/scripts.pory"
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end


SlateportCity_House_EventScript_PokefanM::
# 10 "data/maps/SlateportCity_House/scripts.pory"
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end


SlateportCity_House_Text_MustBeGoingToBattleTent::
# 14 "data/maps/SlateportCity_House/scripts.pory"
	.string "You're a TRAINER, aren't you?\p"
	.string "Since you came to SLATEPORT CITY,\n"
	.string "you must be going to the BATTLE TENT.$"

SlateportCity_House_Text_NatureToDoWithStatGains::
# 18 "data/maps/SlateportCity_House/scripts.pory"
	.string "My POKéMON has a HASTY nature.\p"
	.string "It has higher SPEED compared to\n"
	.string "my other POKéMON.\p"
	.string "Maybe their nature has something to\n"
	.string "do with the stat gains of POKéMON.$"
