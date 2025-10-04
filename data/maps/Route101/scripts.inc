Route101_MapScripts::
	.byte 0


Route101_EventScript_BirchsBag::
	end


Route101_EventScript_Boy::
# 9 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end


Route101_EventScript_PreventExitNorth::
# 14 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	end


Route101_EventScript_PreventExitSouth::
# 19 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	end


Route101_EventScript_PreventExitWest::
# 24 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	end


Route101_EventScript_RouteSign::
# 29 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end


Route101_EventScript_StartBirchRescue::
# 34 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	end


Route101_EventScript_Youngster::
# 39 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end


Route101_Text_RouteSign::
# 44 "data/maps/Route101/scripts.pory"
	.string "ROUTE 101 {UP_ARROW} OLDALE TOWN$"

Route101_Text_WildPokemonInTallGrass::
# 48 "data/maps/Route101/scripts.pory"
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_HelpMe::
# 52 "data/maps/Route101/scripts.pory"
	.string "H-help me!$"

Route101_Text_TakeTiredPokemonToPokeCenter::
# 56 "data/maps/Route101/scripts.pory"
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"

Route101_Text_DontLeaveMe::
# 60 "data/maps/Route101/scripts.pory"
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"
