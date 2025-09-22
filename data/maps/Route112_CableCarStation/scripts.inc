Route112_CableCarStation_MapScripts::
# 2 "data/maps/Route112_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_CableCarStation_OnTransition
# 3 "data/maps/Route112_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route112_CableCarStation_OnFrame
	.byte 0


Route112_CableCarStation_MapScripts::
# 7 "data/maps/Route112_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_CableCarStation_OnTransition
# 8 "data/maps/Route112_CableCarStation/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route112_CableCarStation_OnFrame
	return


Route112_CableCarStation_Text_CableCarReadyGetOn::
# 12 "data/maps/Route112_CableCarStation/scripts.pory"
	.string "The CABLE CAR is ready to go up. Would\n"
	.string "you like to be on it?$"

Route112_CableCarStation_Text_StepThisWay::
# 16 "data/maps/Route112_CableCarStation/scripts.pory"
	.string "Please step this way.$"

Route112_CableCarStation_Text_RideAnotherTime::
# 20 "data/maps/Route112_CableCarStation/scripts.pory"
	.string "Please ride with us another time.$"
