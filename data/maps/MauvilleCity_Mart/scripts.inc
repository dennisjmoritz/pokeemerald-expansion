MauvilleCity_Mart_MapScripts::
	.byte 0


MauvilleCity_Mart_EventScript_Clerk::
	end


MauvilleCity_Mart_EventScript_ExpertM::
# 9 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats, MSGBOX_NPC
	end


MauvilleCity_Mart_EventScript_Man::
# 14 "data/maps/MauvilleCity_Mart/scripts.pory"
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
	end


MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats::
# 18 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "There are items that temporarily\n"
	.string "elevate the stats of POKéMON.\p"
	.string "The ones I know you use in battle\n"
	.string "are X ATTACK and X DEFEND…\p"
	.string "I do believe that there are others\n"
	.string "like them.$"

MauvilleCity_Mart_Text_DecisionsDetermineBattle::
# 22 "data/maps/MauvilleCity_Mart/scripts.pory"
	.string "Use a certain move, or use an item\n"
	.string "instead…\p"
	.string "The TRAINER's decisions determine how\n"
	.string "battles turn out, I think.$"
