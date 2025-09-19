Route18_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route18_OnWarp
	.byte 0

Route18_OnTransition::
	call_if_eq VAR_TEMP_0, 1, Route18_OnTransitionCyclingRoad
// Replaced VAR_MAP_SCENE_ROUTE16 with VAR_TEMP_0
	end

Route18_OnTransitionCyclingRoad::
	setflag FLAG_TEMP_1
// Replaced FLAG_SYS_ON_CYCLING_ROAD with FLAG_TEMP_1
	return

Route18_OnWarp::
	map_script_2 VAR_TEMP_0, 1, Route18_OnWarpCyclingRoad
// Replaced VAR_MAP_SCENE_ROUTE16 with VAR_TEMP_0
	.2byte 0

Route18_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route18_EventScript_RouteSign::
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end

Route18_EventScript_CyclingRoadSign::
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route18_Text_WiltonIntro::
    .string "I always check every grassy area\n"
    .string "for new POKéMON.$"

Route18_Text_WiltonDefeat::
    .string "Tch!$"

Route18_Text_WiltonPostBattle::
    .string "I wish I had a BIKE!$"

Route18_Text_RamiroIntro::
    .string "Kurukkoo!\n"
    .string "How do you like my birdcall?$"

Route18_Text_RamiroDefeat::
    .string "I had to bug you!$"

Route18_Text_RamiroPostBattle::
    .string "I collect sea POKéMON on weekends\n"
    .string "because the sea is so close.$"

Route18_Text_JacobIntro::
    .string "This is my turf!\n"
    .string "Get out of here!$"

Route18_Text_JacobDefeat::
    .string "Darn!$"

Route18_Text_JacobPostBattle::
    .string "This is my fave area for catching\n"
    .string "POKéMON.$"

Route18_Text_RouteSign::
    .string "ROUTE 18\n"
    .string "CELADON CITY - FUCHSIA CITY$"

Route18_Text_CyclingRoadSign::
    .string "CYCLING ROAD\n"
    .string "No pedestrians permitted!$"

