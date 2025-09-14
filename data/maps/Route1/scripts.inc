
Route1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route1_OnFrame
	.byte 0

Route1_OnFrame:
	map_script_2 VAR_INTRO_BATTLE_STATE, 0, Route1_EventScript_HideMapNamePopup
	.2byte 0

Route1_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_INTRO_BATTLE_STATE, 1
	end


Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end

Route1_Movement_ProfOak_3South:
	walk_down
	walk_down
	walk_down
	step_end

Route1_Text_RouteSign:
    .string "ROUTE 1\n"
    .string "PALLET TOWN - VIRIDIAN CITY$"

