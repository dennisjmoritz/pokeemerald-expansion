NewMauville_Entrance_MapScripts::
# 2 "data/maps/NewMauville_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Entrance_OnLoad
# 3 "data/maps/NewMauville_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
	.byte 0


NewMauville_Entrance_MapScripts::
# 7 "data/maps/NewMauville_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Entrance_OnLoad
# 8 "data/maps/NewMauville_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
	return


NewMauville_Entrance_Text_DoorIsLocked::
# 12 "data/maps/NewMauville_Entrance/scripts.pory"
	.string "The door is locked.$"

NewMauville_Entrance_Text_UseBasementKey::
# 16 "data/maps/NewMauville_Entrance/scripts.pory"
	.string "Use the BASEMENT KEY?$"

NewMauville_Entrance_Text_UsedBasementKey::
# 20 "data/maps/NewMauville_Entrance/scripts.pory"
	.string "{PLAYER} used the BASEMENT KEY.\p"
	.string "The door opened!$"
