Route25_MapScripts::
	.byte 0


Route25_EventScript_Man::
# 5 "data/maps/Route25/scripts.pory"
	msgbox Route25_Text_AreYouHereAlone, MSGBOX_NPC
	end


Route25_EventScript_SeaCottageSign::
# 10 "data/maps/Route25/scripts.pory"
	msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
	end


Route25_Text_SeaCottageSign::
# 15 "data/maps/Route25/scripts.pory"
	.string "SEA COTTAGE BILL lives here!$"

Route25_Text_AreYouHereAlone::
# 19 "data/maps/Route25/scripts.pory"
	.string "Hello, are you here alone?\p"
	.string "If you're out at CERULEAN's cape…\n"
	.string "Well, it should be as a couple.$"
