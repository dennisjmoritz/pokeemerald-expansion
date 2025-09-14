CeladonCity_DepartmentStore_Roof_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_Roof_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_Roof_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_Roof_EventScript_VendingMachine::
	lockall
	message CeladonCity_DepartmentStore_Roof_Text_VendingMachineWhatDoesItHave
	waitmessage
	showmoneybox 0, 0
	goto CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, CeladonCity_DepartmentStore_Roof_EventScript_FreshWater
	case 1, CeladonCity_DepartmentStore_Roof_EventScript_SodaPop
	case 2, CeladonCity_DepartmentStore_Roof_EventScript_Lemonade
	msgbox CeladonCity_DepartmentStore_Roof_Text_NotThirsty
	goto CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine
	end

CeladonCity_DepartmentStore_Roof_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto CeladonCity_DepartmentStore_Roof_EventScript_TryBuyDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto CeladonCity_DepartmentStore_Roof_EventScript_TryBuyDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto CeladonCity_DepartmentStore_Roof_EventScript_TryBuyDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

CeladonCity_DepartmentStore_Roof_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

CeladonCity_DepartmentStore_Roof_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

CeladonCity_DepartmentStore_Roof_EventScript_TryBuyDrink::
	call_if_eq VAR_TEMP_1, 0, CeladonCity_DepartmentStore_Roof_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, CeladonCity_DepartmentStore_Roof_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, CeladonCity_DepartmentStore_Roof_EventScript_CheckMoneyLemonade
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_DepartmentStore_Roof_EventScript_NotEnoughMoney
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, CeladonCity_DepartmentStore_Roof_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox CeladonCity_DepartmentStore_Roof_Text_DrinkCanPoppedOut
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket
	random 64  @ 1/64 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, CeladonCity_DepartmentStore_Roof_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExtraCanOfDrinkDroppedDown
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket
	random 64  @ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
	goto_if_ne VAR_RESULT, 0, CeladonCity_DepartmentStore_Roof_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox CeladonCity_DepartmentStore_Roof_Text_ExtraCanOfDrinkDroppedDown
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket
	goto CeladonCity_DepartmentStore_Roof_EventScript_ChooseNewDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_ChooseNewDrink::
	message CeladonCity_DepartmentStore_Roof_Text_VendingMachineWhatDoesItHave
	waitmessage
	goto CeladonCity_DepartmentStore_Roof_EventScript_ChooseDrink
	end

CeladonCity_DepartmentStore_Roof_EventScript_NotEnoughMoney::
	msgbox CeladonCity_DepartmentStore_Roof_Text_NotEnoughMoney
	goto CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine
	end

CeladonCity_DepartmentStore_Roof_EventScript_NoRoomForDrink::
	msgbox CeladonCity_DepartmentStore_Roof_Text_NoMoreRoomForStuff
	goto CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine
	end

CeladonCity_DepartmentStore_Roof_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

CeladonCity_DepartmentStore_Roof_Text_FloorSign::
    .string "ROOFTOP SQUARE:\n"
    .string "VENDING MACHINES$"

CeladonCity_DepartmentStore_Roof_Text_VendingMachineWhatDoesItHave::
    .string "It's a VENDING MACHINE.\n"
    .string "Which drink would you like?$"

CeladonCity_DepartmentStore_Roof_Text_NotEnoughMoney::
    .string "Not enough money…$"

CeladonCity_DepartmentStore_Roof_Text_DrinkCanPoppedOut::
    .string "Clang!\p"
    .string "A can of {STR_VAR_1} dropped down.$"

CeladonCity_DepartmentStore_Roof_Text_ExtraCanOfDrinkDroppedDown::
    .string "Clang!\p"
    .string "Score! An extra can of {STR_VAR_1}\n"
    .string "dropped down!$"

CeladonCity_DepartmentStore_Roof_Text_NoMoreRoomForStuff::
    .string "There's no more room for stuff!$"

CeladonCity_DepartmentStore_Roof_Text_NotThirsty::
    .string "Decided against buying a drink.$"
