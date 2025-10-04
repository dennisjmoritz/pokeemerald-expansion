CeladonCity_DepartmentStore_1F_MapScripts::
	.byte 0


CeladonCity_DepartmentStore_1F_EventScript_FloorSign::
# 5 "data/maps/CeladonCity_DepartmentStore_1F/scripts.pory"
	msgbox CeladonCity_DepartmentStore_1F_Text_ServiceCounter, MSGBOX_SIGN
	end


CeladonCity_DepartmentStore_1F_EventScript_LayoutSign::
# 10 "data/maps/CeladonCity_DepartmentStore_1F/scripts.pory"
	msgbox CeladonCity_DepartmentStore_1F_Text_FloorDescriptions, MSGBOX_SIGN
	end


CeladonCity_DepartmentStore_1F_EventScript_Receptionist::
# 15 "data/maps/CeladonCity_DepartmentStore_1F/scripts.pory"
	msgbox CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end


CeladonCity_DepartmentStore_1F_Text_FloorDescriptions::
# 20 "data/maps/CeladonCity_DepartmentStore_1F/scripts.pory"
	.string "1F: SERVICE COUNTER\p"
	.string "2F: TRAINER'S MARKET\p"
	.string "3F: TV GAME SHOP\p"
	.string "4F: WISE MAN GIFTS\p"
	.string "5F: DRUGSTORE\p"
	.string "ROOFTOP SQUARE: VENDING MACHINES$"

CeladonCity_DepartmentStore_1F_Text_ServiceCounter::
# 24 "data/maps/CeladonCity_DepartmentStore_1F/scripts.pory"
	.string "1F: SERVICE COUNTER$"

CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore::
# 28 "data/maps/CeladonCity_DepartmentStore_1F/scripts.pory"
	.string "Hello!\n"
	.string "Welcome to CELADON DEPT. STORE.\p"
	.string "The board on the right describes\n"
	.string "the store layout.$"
