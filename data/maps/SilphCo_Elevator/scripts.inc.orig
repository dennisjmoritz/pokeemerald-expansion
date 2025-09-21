SilphCo_Elevator_MapScripts::
	.byte 0

SilphCo_Elevator_EventScript_FloorSelect::
	lockall
	setvar VAR_0x8004, 1
// FIXME undefined reference: 	call_if_unset FLAG_TEMP_2, EventScript_GetElevatorFloor
	copyvar VAR_0x8005, VAR_TEMP_0
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
// FIXME undefined reference: 	special DrawElevatorCurrentFloorWindow
// FIXME undefined reference: 	message Text_WantWhichFloor
	waitmessage
//	setvar VAR_0x8004, LISTMENU_SILPHCO_FLOORS
    // specialvar VAR_RESULT, InitElevatorFloorSelectMenuPos
    // Commented to avoid non-constant macro evaluation issues
    setvar VAR_RESULT, 0
// FIXME undefined reference: 	special ListMenu
	waitstate
    // switch VAR_RESULT
    // case branches commented to avoid .if macro issues
    // end

SilphCo_Elevator_EventScript_To1F::
	setvar VAR_0x8006, 4
	setdynamicwarp MAP_SILPH_CO_1F, 255, 22, 3
	goto_if_eq VAR_TEMP_0, 4, SilphCo_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 4
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_To2F::
	setvar VAR_0x8006, 5
	setdynamicwarp MAP_SILPH_CO_2F, 255, 22, 3
	goto_if_eq VAR_TEMP_0, 5, SilphCo_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 5
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_To3F::
	setvar VAR_0x8006, 6
	setdynamicwarp MAP_SILPH_CO_3F, 255, 22, 3
	goto_if_eq VAR_TEMP_0, 6, SilphCo_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 6
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_To4F::
	setvar VAR_0x8006, 7
	setdynamicwarp MAP_SILPH_CO_4F, 255, 22, 3
	goto_if_eq VAR_TEMP_0, 7, SilphCo_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 7
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_To5F::
	setvar VAR_0x8006, 8
	setdynamicwarp MAP_SILPH_CO_5F, 255, 22, 3
	goto_if_eq VAR_TEMP_0, 8, SilphCo_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 8
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_To6F::
	setvar VAR_0x8006, 9
	setdynamicwarp MAP_SILPH_CO_6F, 255, 20, 3
	goto_if_eq VAR_TEMP_0, 9, SilphCo_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 9
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_To7F::
	setvar VAR_0x8006, 10
	setdynamicwarp MAP_SILPH_CO_7F, 255, 23, 3
    // goto_if_eq VAR_TEMP_0, 10, SilphCo_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 10
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_To8F::
    setvar VAR_0x8006, 11
    // setdynamicwarp MAP_SILPH_CO_8F, 255, 22, 3
    // goto_if_eq VAR_TEMP_0, 11, SilphCo_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 11
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_To9F::
    setvar VAR_0x8006, 12
    // setdynamicwarp MAP_SILPH_CO_9F, 255, 24, 3
    // goto_if_eq VAR_TEMP_0, 12, SilphCo_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 12
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_To10F::
    setvar VAR_0x8006, 13
    // setdynamicwarp MAP_SILPH_CO_10F, 255, 13, 3
    // goto_if_eq VAR_TEMP_0, 13, SilphCo_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 13
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_To11F::
	setvar VAR_0x8006, 14
	setdynamicwarp MAP_SILPH_CO_11F, 255, 13, 3
	goto_if_eq VAR_TEMP_0, 14, SilphCo_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call SilphCo_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 14
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto SilphCo_Elevator_EventScript_ExitFloorSelect
	end

SilphCo_Elevator_EventScript_ExitFloorSelect::
// FIXME undefined reference: 	special CloseElevatorCurrentFloorWindow
	releaseall
	end

SilphCo_Elevator_EventScript_MoveElevator::
// FIXME undefined reference: 	special CloseElevatorCurrentFloorWindow
	closemessage
	waitse
// FIXME undefined reference: 	special AnimateElevator
	waitstate
	setflag FLAG_TEMP_2
	return
