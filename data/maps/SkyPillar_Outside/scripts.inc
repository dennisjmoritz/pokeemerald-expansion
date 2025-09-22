SkyPillar_Outside_MapScripts::
# 2 "data/maps/SkyPillar_Outside/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Outside_OnTransition
# 3 "data/maps/SkyPillar_Outside/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_Outside_OnLoad
# 4 "data/maps/SkyPillar_Outside/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SkyPillar_Outside_OnFrame
	.byte 0


SkyPillar_Outside_MapScripts::
# 8 "data/maps/SkyPillar_Outside/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Outside_OnTransition
# 9 "data/maps/SkyPillar_Outside/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SkyPillar_Outside_OnLoad
# 10 "data/maps/SkyPillar_Outside/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SkyPillar_Outside_OnFrame
	return


SkyPillar_Outside_Text_DoorIsClosed::
# 14 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "The door is closed.$"

SkyPillar_Outside_Text_OpenedDoorToSkyPillar::
# 18 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "WALLACE: Oh, my, I'm terribly sorry!\p"
	.string "In my haste, I didn't notice that I'd\n"
	.string "left you behind!\p"
	.string "I've opened the locked door of the SKY\n"
	.string "PILLAR.\p"
	.string "{PLAYER}{KUN}, let's be on our way!$"

SkyPillar_Outside_Text_EarthquakeNotMomentToWaste::
# 22 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "WALLACE: It's an earthquake!\p"
	.string "There's not a moment to waste! We've\n"
	.string "got to hurry!$"

SkyPillar_Outside_Text_SituationGettingWorse::
# 26 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "WALLACE: Hmm… The situation is getting\n"
	.string "worse…$"

SkyPillar_Outside_Text_GotToGoBackForSootopolis::
# 30 "data/maps/SkyPillar_Outside/scripts.pory"
	.string "WALLACE: This isn't good…\p"
	.string "The weather distortion is spreading\n"
	.string "even here…\p"
	.string "{PLAYER}{KUN}.\p"
	.string "RAYQUAZA should be farther up from\n"
	.string "here.\p"
	.string "I'm worried about SOOTOPOLIS. I've got\n"
	.string "to go back.\p"
	.string "Everything is in your hands now. Don't\n"
	.string "fail us!$"
