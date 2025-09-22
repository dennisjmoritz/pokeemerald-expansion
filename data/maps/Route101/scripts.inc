Route101_MapScripts::
# 2 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
# 3 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0


Route101_MapScripts::
# 7 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
# 8 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	return


Route101_Text_HelpMe::
# 12 "data/maps/Route101/scripts.pory"
	.string "H-help me!$"

Route101_Text_PleaseHelp::
# 16 "data/maps/Route101/scripts.pory"
	.string "Hello! You over there! Please! Help!\p"
	.string "In my BAG! There's a POKé BALL!$"

Route101_Text_DontLeaveMe::
# 20 "data/maps/Route101/scripts.pory"
	.string "Wh-Where are you going?! Don't leave me\n"
	.string "like this!$"

Route101_Text_YouSavedMe::
# 24 "data/maps/Route101/scripts.pory"
	.string "PROF. BIRCH: Whew…\p"
	.string "I was in the tall grass studying wild\n"
	.string "POKéMON when I was jumped.\p"
	.string "You saved me. Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {PLAYER}{KUN}!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my POKéMON LAB later, okay?$"

Route101_Text_TakeTiredPokemonToPokeCenter::
# 28 "data/maps/Route101/scripts.pory"
	.string "If POKéMON get tired, take them to a\n"
	.string "POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"

Route101_Text_WildPokemonInTallGrass::
# 32 "data/maps/Route101/scripts.pory"
	.string "Wild POKéMON will jump out at you in tall\n"
	.string "grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_RouteSign::
# 36 "data/maps/Route101/scripts.pory"
	.string "ROUTE 101 {UP_ARROW} OLDALE TOWN$"
