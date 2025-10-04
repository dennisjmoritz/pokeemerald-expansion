CinnabarIsland_Mart_MapScripts::
	.byte 0


CinnabarIsland_Mart_EventScript_Clerk::
	end


CinnabarIsland_Mart_EventScript_Scientist::
# 9 "data/maps/CinnabarIsland_Mart/scripts.pory"
	msgbox CinnabarIsland_Mart_Text_ExtraItemsNeverHurt, MSGBOX_NPC
	end


CinnabarIsland_Mart_EventScript_Woman::
# 14 "data/maps/CinnabarIsland_Mart/scripts.pory"
	msgbox CinnabarIsland_Mart_Text_DontTheyHaveXAttack, MSGBOX_NPC
	end


CinnabarIsland_Mart_Text_ExtraItemsNeverHurt::
# 19 "data/maps/CinnabarIsland_Mart/scripts.pory"
	.string "It never hurts to have extra items.\n"
	.string "You never know what might happen.$"

CinnabarIsland_Mart_Text_DontTheyHaveXAttack::
# 23 "data/maps/CinnabarIsland_Mart/scripts.pory"
	.string "Don't they have X ATTACK?\p"
	.string "I like it because it raises the\n"
	.string "ATTACK stat in battle.$"
