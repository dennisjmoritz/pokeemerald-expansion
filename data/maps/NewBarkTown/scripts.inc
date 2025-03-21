NewBarkTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_OnTransition
	.byte 0

NewBarkTown_OnTransition:
	setflag FLAG_VISITED_NEW_BARK_TOWN
	end

NewBarkTown_EventScript_TownSign::
	msgbox NewBarkTown_Text_TownSign, MSGBOX_SIGN
	end

NewBarkTown_EventScript_ElmsLabSign::
	msgbox NewBarkTown_Text_ElmsLabSign, MSGBOX_SIGN
	end

NewBarkTown_EventScript_ElmsHouseSign::
	msgbox NewBarkTown_Text_ElmsHouseSign, MSGBOX_SIGN
	end

NewBarkTown_EventScript_PlayersHouseSign::
	msgbox NewBarkTown_Text_PlayersHouseSign, MSGBOX_SIGN
	end

NewBarkTown_Text_TownSign::
	.string "NEW BARK TOWN\n"
	.string "Where the winds of a new beginning blow$"

NewBarkTown_Text_ElmsLabSign::
	.string "PROF. ELM'S POKéMON LAB$"

NewBarkTown_Text_ElmsHouseSign::
	.string "PROF. ELM'S HOUSE$"

NewBarkTown_Text_PlayersHouseSign::
	.string "{PLAYER}'s HOUSE$"
