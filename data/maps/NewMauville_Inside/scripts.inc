NewMauville_Inside_MapScripts::
# 2 "data/maps/NewMauville_Inside/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Inside_OnResume
# 3 "data/maps/NewMauville_Inside/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Inside_OnTransition
# 4 "data/maps/NewMauville_Inside/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Inside_OnLoad
	.byte 0


NewMauville_Inside_Text_GeneratorRadiatingHeat::
# 8 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator is radiating heat that\n"
	.string "can be felt even at a distance.\p"
	.string "It looks like it should be turned off as\n"
	.string "soon as possible.$"

NewMauville_Inside_Text_GeneratorQuietedDown::
# 12 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator quieted down.$"

NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped::
# 16 "data/maps/NewMauville_Inside/scripts.pory"
	.string "{PLAYER} stepped on the switch.\p"
	.string "Click\p"
	.string "\p"
	.string "The generator appears to have stopped$"
