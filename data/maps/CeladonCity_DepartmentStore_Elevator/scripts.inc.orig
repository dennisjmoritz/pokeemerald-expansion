CeladonCity_DepartmentStore_Elevator_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelect::
	lockall
	setvar VAR_0x8004, 3
// FIXME undefined reference: 	call_if_unset FLAG_TEMP_2, EventScript_GetElevatorFloor
	copyvar VAR_0x8005, VAR_TEMP_0
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
// FIXME undefined reference: 	special DrawElevatorCurrentFloorWindow
// FIXME undefined reference: 	message Text_WantWhichFloor
	waitmessage
	setvar VAR_0x8004, 3
// FIXME undefined reference: 	specialvar VAR_RESULT, InitElevatorFloorSelectMenuPos
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom5F
	case 1, CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom4F
	case 2, CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom3F
	case 3, CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom2F
	case 4, CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom1F
	end

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom5F::
// FIXME undefined reference: 	multichoicedefault 0, 0, MULTICHOICE_DEPT_STORE_ELEVATOR, 0, FALSE
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
	end

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom4F::
// FIXME undefined reference: 	multichoicedefault 0, 0, MULTICHOICE_DEPT_STORE_ELEVATOR, 1, FALSE
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
	end

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom3F::
// FIXME undefined reference: 	multichoicedefault 0, 0, MULTICHOICE_DEPT_STORE_ELEVATOR, 2, FALSE
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
	end

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom2F::
// FIXME undefined reference: 	multichoicedefault 0, 0, MULTICHOICE_DEPT_STORE_ELEVATOR, 3, FALSE
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
	end

CeladonCity_DepartmentStore_Elevator_EventScript_FloorSelectFrom1F::
// FIXME undefined reference: 	multichoicedefault 0, 0, MULTICHOICE_DEPT_STORE_ELEVATOR, 4, FALSE
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor
	end

CeladonCity_DepartmentStore_Elevator_EventScript_ChooseFloor::
	switch VAR_RESULT
	case 0, CeladonCity_DepartmentStore_Elevator_EventScript_To5F
	case 1, CeladonCity_DepartmentStore_Elevator_EventScript_To4F
	case 2, CeladonCity_DepartmentStore_Elevator_EventScript_To3F
	case 3, CeladonCity_DepartmentStore_Elevator_EventScript_To2F
	case 4, CeladonCity_DepartmentStore_Elevator_EventScript_To1F
	case 5, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	case 127, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	end

CeladonCity_DepartmentStore_Elevator_EventScript_To1F::
	setvar VAR_0x8006, 4
	setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_1F, 255, 6, 1
	goto_if_eq VAR_TEMP_0, 4, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 4
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	end

CeladonCity_DepartmentStore_Elevator_EventScript_To2F::
	setvar VAR_0x8006, 5
	setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_2F, 255, 6, 1
	goto_if_eq VAR_TEMP_0, 5, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 5
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	end

CeladonCity_DepartmentStore_Elevator_EventScript_To3F::
	setvar VAR_0x8006, 6
	setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_3F, 255, 6, 1
	goto_if_eq VAR_TEMP_0, 6, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 6
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	end

CeladonCity_DepartmentStore_Elevator_EventScript_To4F::
	setvar VAR_0x8006, 7
	setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_4F, 255, 6, 1
	goto_if_eq VAR_TEMP_0, 7, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 7
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	end

CeladonCity_DepartmentStore_Elevator_EventScript_To5F::
	setvar VAR_0x8006, 8
	setdynamicwarp MAP_CELADON_CITY_DEPARTMENT_STORE_5F, 255, 6, 1
	goto_if_eq VAR_TEMP_0, 8, CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	call CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator
	setvar VAR_TEMP_0, 8
// Replaced VAR_ELEVATOR_FLOOR with VAR_TEMP_0
	goto CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect
	end

CeladonCity_DepartmentStore_Elevator_EventScript_ExitFloorSelect::
// FIXME undefined reference: 	special CloseElevatorCurrentFloorWindow
	releaseall
	end

CeladonCity_DepartmentStore_Elevator_EventScript_MoveElevator::
// FIXME undefined reference: 	special CloseElevatorCurrentFloorWindow
	closemessage
	waitse
// FIXME undefined reference: 	special AnimateElevator
	waitstate
	setflag FLAG_TEMP_2
	return
