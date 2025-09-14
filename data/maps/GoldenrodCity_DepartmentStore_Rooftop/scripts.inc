GoldenrodCity_DepartmentStore_Rooftop_MapScripts::
	.byte 0

GoldenrodCity_DepartmentStore_Rooftop_EventScript_VendingMachine::
	lockall
	message GoldenrodCity_DepartmentStore_Rooftop_Text_VendingMachineWhatDoesItHave
	waitmessage
	showmoneybox 0, 0
	goto GoldenrodCity_DepartmentStore_Rooftop_EventScript_ChooseDrink
	end

GoldenrodCity_DepartmentStore_Rooftop_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, GoldenrodCity_DepartmentStore_Rooftop_EventScript_BuyFreshWater
	case 1, GoldenrodCity_DepartmentStore_Rooftop_EventScript_BuySodaPop
	case 2, GoldenrodCity_DepartmentStore_Rooftop_EventScript_BuyLemonade
	msgbox GoldenrodCity_DepartmentStore_Rooftop_Text_NotThirsty
	goto GoldenrodCity_DepartmentStore_Rooftop_EventScript_ExitVendingMachine
	end

GoldenrodCity_DepartmentStore_Rooftop_EventScript_BuyFreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	checkmoney 200
	goto GoldenrodCity_DepartmentStore_Rooftop_EventScript_TryBuyDrink
	end

GoldenrodCity_DepartmentStore_Rooftop_EventScript_BuySodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	checkmoney 300
	goto GoldenrodCity_DepartmentStore_Rooftop_EventScript_TryBuyDrink
	end

GoldenrodCity_DepartmentStore_Rooftop_EventScript_BuyLemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	checkmoney 350
	goto GoldenrodCity_DepartmentStore_Rooftop_EventScript_TryBuyDrink
	end

GoldenrodCity_DepartmentStore_Rooftop_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

GoldenrodCity_DepartmentStore_Rooftop_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

GoldenrodCity_DepartmentStore_Rooftop_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

GoldenrodCity_DepartmentStore_Rooftop_EventScript_TryBuyDrink::
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_DepartmentStore_Rooftop_EventScript_NotEnoughMoney
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_DepartmentStore_Rooftop_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, GoldenrodCity_DepartmentStore_Rooftop_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, GoldenrodCity_DepartmentStore_Rooftop_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, GoldenrodCity_DepartmentStore_Rooftop_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox GoldenrodCity_DepartmentStore_Rooftop_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64
	goto_if_ne VAR_RESULT, 0, GoldenrodCity_DepartmentStore_Rooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_DepartmentStore_Rooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox GoldenrodCity_DepartmentStore_Rooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64
	goto_if_ne VAR_RESULT, 0, GoldenrodCity_DepartmentStore_Rooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, GoldenrodCity_DepartmentStore_Rooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox GoldenrodCity_DepartmentStore_Rooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto GoldenrodCity_DepartmentStore_Rooftop_EventScript_ChooseNewDrink
	end

GoldenrodCity_DepartmentStore_Rooftop_EventScript_ChooseNewDrink::
	message GoldenrodCity_DepartmentStore_Rooftop_Text_VendingMachineWhatDoesItHave
	waitmessage
	goto GoldenrodCity_DepartmentStore_Rooftop_EventScript_ChooseDrink
	end

GoldenrodCity_DepartmentStore_Rooftop_EventScript_NotEnoughMoney::
	msgbox GoldenrodCity_DepartmentStore_Rooftop_Text_NotEnoughMoney
	goto GoldenrodCity_DepartmentStore_Rooftop_EventScript_ExitVendingMachine
	end

GoldenrodCity_DepartmentStore_Rooftop_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto GoldenrodCity_DepartmentStore_Rooftop_EventScript_ExitVendingMachine
	end

GoldenrodCity_DepartmentStore_Rooftop_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

GoldenrodCity_DepartmentStore_Rooftop_Text_VendingMachineWhatDoesItHave::
    .string "It's a VENDING MACHINE.\n"
    .string "Which drink would you like?$"

GoldenrodCity_DepartmentStore_Rooftop_Text_NotEnoughMoney::
    .string "Not enough money…$"

GoldenrodCity_DepartmentStore_Rooftop_Text_CanOfDrinkDroppedDown::
    .string "Clang!\p"
    .string "A can of {STR_VAR_1} dropped down.$"

GoldenrodCity_DepartmentStore_Rooftop_Text_NoMoreRoomForStuff::
    .string "The BAG is full…$"

GoldenrodCity_DepartmentStore_Rooftop_Text_NotThirsty::
    .string "Decided against buying a drink.$"

GoldenrodCity_DepartmentStore_Rooftop_Text_ExtraCanOfDrinkDroppedDown::
    .string "Clang!\p"
    .string "Score! An extra can of {STR_VAR_1}\n"
    .string "dropped down!$"
