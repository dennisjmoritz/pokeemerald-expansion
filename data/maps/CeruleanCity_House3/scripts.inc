CeruleanCity_House3_MapScripts::
	.byte 0

CeruleanCity_House3_EventScript_OldWoman::
	msgbox CeruleanCity_House3_Text_PleaseTradeWithMyHusband, MSGBOX_NPC
	end

CeruleanCity_House3_EventScript_Dontae::
	lock
	faceplayer
// 	setvar VAR_0x8008, INGAME_TRADE_JYNX
// FIXME undefined reference: 	call EventScript_GetInGameTradeSpeciesInfo
	goto_if_set FLAG_TEMP_1, CeruleanCity_House3_EventScript_AlreadyTraded
// Replaced FLAG_DID_ZYNX_TRADE with FLAG_TEMP_1
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House3_EventScript_DeclineTrade
// FIXME undefined reference: 	call EventScript_ChooseMonForInGameTrade
	goto_if_ge VAR_0x8004, PARTY_SIZE, CeruleanCity_House3_EventScript_DeclineTrade
// FIXME undefined reference: 	call EventScript_GetInGameTradeSpecies
// 	goto_if_ne VAR_RESULT, VAR_0x8009, CeruleanCity_House3_EventScript_NotRequestedMon
// FIXME undefined reference: 	call EventScript_DoInGameTrade
	setflag FLAG_TEMP_1
// Replaced FLAG_DID_ZYNX_TRADE with FLAG_TEMP_1
	release
	end

CeruleanCity_House3_EventScript_DeclineTrade::
	release
	end

CeruleanCity_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	release
	end

CeruleanCity_House3_EventScript_AlreadyTraded::
	release
	end

CeruleanCity_House3_Text_PleaseTradeWithMyHusband::
    .string "My husband likes trading POKéMON.\p"
    .string "You're collecting POKéMON for your\n"
    .string "POKéDEX, aren't you?\p"
    .string "Would you please trade with him?$"

