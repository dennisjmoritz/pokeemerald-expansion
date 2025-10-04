SaffronCity_Mart_MapScripts::
	.byte 0


SaffronCity_Mart_EventScript_Clerk::
	end


SaffronCity_Mart_EventScript_Lass::
# 9 "data/maps/SaffronCity_Mart/scripts.pory"
	msgbox SaffronCity_Mart_Text_ReviveIsCostly, MSGBOX_NPC
	end


SaffronCity_Mart_EventScript_Youngster::
# 14 "data/maps/SaffronCity_Mart/scripts.pory"
	msgbox SaffronCity_Mart_Text_MaxRepelMoreEffectiveThanSuper, MSGBOX_NPC
	end


SaffronCity_Mart_Text_ReviveIsCostly::
# 19 "data/maps/SaffronCity_Mart/scripts.pory"
	.string "REVIVE is costly, but it revives\n"
	.string "fainted POKéMON!$"

SaffronCity_Mart_Text_MaxRepelMoreEffectiveThanSuper::
# 23 "data/maps/SaffronCity_Mart/scripts.pory"
	.string "MAX REPEL keeps weaker POKéMON\n"
	.string "from appearing.\p"
	.string "MAX REPEL stays effective longer\n"
	.string "than SUPER REPEL.$"
