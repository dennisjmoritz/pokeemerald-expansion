Route13_MapScripts::
	.byte 0


Route13_EventScript_RouteSign::
# 5 "data/maps/Route13/scripts.pory"
	msgbox Route13_Text_RouteSign, MSGBOX_SIGN
	end


Route13_EventScript_TrainerTips1::
# 10 "data/maps/Route13/scripts.pory"
	msgbox Route13_Text_LookToLeftOfThatPost, MSGBOX_SIGN
	end


Route13_EventScript_TrainerTips2::
# 15 "data/maps/Route13/scripts.pory"
	msgbox Route13_Text_SelectToSwitchItems, MSGBOX_SIGN
	end


Route13_Text_LookToLeftOfThatPost::
# 20 "data/maps/Route13/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "Look, look! Look to the left of that\n"
	.string "post!$"

Route13_Text_SelectToSwitchItems::
# 24 "data/maps/Route13/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "Use SELECT to switch items in the ITEMS\n"
	.string "window.$"

Route13_Text_RouteSign::
# 28 "data/maps/Route13/scripts.pory"
	.string "ROUTE 13 North to SILENCE BRIDGE$"
