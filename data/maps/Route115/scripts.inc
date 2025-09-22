Route115_MapScripts::
# 2 "data/maps/Route115/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route115_OnLoad
# 3 "data/maps/Route115/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
# 4 "data/maps/Route115/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
	.byte 0


Route115_MapScripts::
# 8 "data/maps/Route115/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route115_OnLoad
# 9 "data/maps/Route115/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
# 10 "data/maps/Route115/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
	return


Route115_Text_NeverKnowWhenCavePokemonWillAppear::
# 14 "data/maps/Route115/scripts.pory"
	.string "Exploring a cave isn't like walking on a\n"
	.string "road.\p"
	.string "You never know when wild POKéMON will\n"
	.string "appear. It's full of suspense.$"

Route115_Text_RouteSignRustboro::
# 18 "data/maps/Route115/scripts.pory"
	.string "ROUTE 115 {DOWN_ARROW} RUSTBORO CITY$"

Route115_Text_MeteorFallsSign::
# 22 "data/maps/Route115/scripts.pory"
	.string "METEOR FALLS FALLARBOR TOWN THROUGH\n"
	.string "HERE$"
