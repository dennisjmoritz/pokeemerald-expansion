CeladonCity_DepartmentStore_5F_MapScripts::
	.byte 0


CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins::
	end


CeladonCity_DepartmentStore_5F_EventScript_ClerkXItems::
	end


CeladonCity_DepartmentStore_5F_EventScript_FloorSign::
# 13 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	msgbox CeladonCity_DepartmentStore_5F_Text_Drugstore, MSGBOX_SIGN
	end


CeladonCity_DepartmentStore_5F_EventScript_Gentleman::
# 18 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	msgbox CeladonCity_DepartmentStore_5F_Text_ExplainStatEnhancers, MSGBOX_NPC
	end


CeladonCity_DepartmentStore_5F_EventScript_Sailor::
# 23 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	msgbox CeladonCity_DepartmentStore_5F_Text_HereForStatEnhancers, MSGBOX_NPC
	end


CeladonCity_DepartmentStore_5F_Text_Drugstore::
# 28 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.string "5F: DRUGSTORE$"

CeladonCity_DepartmentStore_5F_Text_ExplainStatEnhancers::
# 32 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.string "POKéMON stat enhancers can be\n"
	.string "bought only here.\p"
	.string "HP UP increases the base HP of a\n"
	.string "POKéMON.\p"
	.string "CALCIUM raises the base SP. ATK\n"
	.string "stat of one POKéMON.\p"
	.string "ZINC boosts the base SP. DEF stat\n"
	.string "of one POKéMON.\p"
	.string "CARBOS enhances the base SPEED\n"
	.string "stat.$"

CeladonCity_DepartmentStore_5F_Text_HereForStatEnhancers::
# 36 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.string "I'm here for POKéMON stat\n"
	.string "enhancers.\p"
	.string "PROTEIN increases the base ATTACK\n"
	.string "power.\p"
	.string "IRON increases the base DEFENSE\n"
	.string "stat.$"
