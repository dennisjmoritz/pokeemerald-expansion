SilphCo_1F_MapScripts::
	.byte 0


SilphCo_1F_EventScript_FloorSign::
# 5 "data/maps/SilphCo_1F/scripts.pory"
	msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
	end


SilphCo_1F_EventScript_Receptionist::
# 10 "data/maps/SilphCo_1F/scripts.pory"
	msgbox SilphCo_1F_Text_WelcomePresidentInBoardroom, MSGBOX_NPC
	end


SilphCo_1F_Text_FloorSign::
# 15 "data/maps/SilphCo_1F/scripts.pory"
	.string "SILPH CO. HEAD OFFICE 1F$"

SilphCo_1F_Text_WelcomePresidentInBoardroom::
# 19 "data/maps/SilphCo_1F/scripts.pory"
	.string "Welcome.\p"
	.string "The PRESIDENT is in the boardroom\n"
	.string "on 11F.$"
