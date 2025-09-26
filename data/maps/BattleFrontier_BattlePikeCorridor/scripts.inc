BattleFrontier_BattlePikeCorridor_MapScripts::
	end

BattleFrontier_BattlePikeCorridor_EventScript_EnterCorridor::
	end

BattleFrontier_BattlePikeCorridor_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeCorridor_Movement_PlayerEnterCorridor:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePikeCorridor_Movement_PlayerExitCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeCorridor_Movement_AttendantEnterCorridor:
	walk_up
	walk_up
	walk_left
	face_down
	step_end

BattleFrontier_BattlePikeCorridor_Text_YourChallengeHasBegun:
	.string "Your Battle Choice challenge\n"
	.string "has now begun…$"

