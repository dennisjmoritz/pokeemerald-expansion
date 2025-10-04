Route17_MapScripts::
	.byte 0


Route17_EventScript_BallsNotice::
# 5 "data/maps/Route17/scripts.pory"
	msgbox Route17_Text_DontThrowGameThrowBalls, MSGBOX_SIGN
	end


Route17_EventScript_CyclingRoadSign::
# 10 "data/maps/Route17/scripts.pory"
	msgbox Route17_Text_CyclingRoadSign, MSGBOX_SIGN
	end


Route17_EventScript_ItemsNotice::
# 15 "data/maps/Route17/scripts.pory"
	msgbox Route17_Text_WatchOutForDiscardedItems, MSGBOX_SIGN
	end


Route17_EventScript_RouteSign::
# 20 "data/maps/Route17/scripts.pory"
	msgbox Route17_Text_RouteSign, MSGBOX_SIGN
	end


Route17_EventScript_TrainerTips1::
# 25 "data/maps/Route17/scripts.pory"
	msgbox Route17_Text_SameSpeciesGrowDifferentRates, MSGBOX_SIGN
	end


Route17_EventScript_TrainerTips2::
# 30 "data/maps/Route17/scripts.pory"
	msgbox Route17_Text_PressBToStayInPlace, MSGBOX_SIGN
	end


Route17_Text_CyclingRoadSign::
# 35 "data/maps/Route17/scripts.pory"
	.string "CYCLING ROAD Slope ends here!$"

Route17_Text_RouteSign::
# 39 "data/maps/Route17/scripts.pory"
	.string "ROUTE 17 CELADON CITY - FUCHSIA CITY$"

Route17_Text_PressBToStayInPlace::
# 43 "data/maps/Route17/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "Press the B Button to stay in place\n"
	.string "while on a slope.$"

Route17_Text_SameSpeciesGrowDifferentRates::
# 47 "data/maps/Route17/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "All POKéMON are unique.\p"
	.string "Even POKéMON of the same species and\n"
	.string "level grow at different rates.$"

Route17_Text_WatchOutForDiscardedItems::
# 51 "data/maps/Route17/scripts.pory"
	.string "It's a notice.\p"
	.string "Watch out for discarded items.$"

Route17_Text_DontThrowGameThrowBalls::
# 55 "data/maps/Route17/scripts.pory"
	.string "It's a notice!\p"
	.string "Don't throw the game, throw POKé BALLS\n"
	.string "instead!$"
