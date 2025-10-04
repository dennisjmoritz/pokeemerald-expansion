LavenderTown_Mart_MapScripts::
	.byte 0


LavenderTown_Mart_EventScript_BaldingMan::
# 5 "data/maps/LavenderTown_Mart/scripts.pory"
	msgbox LavenderTown_Mart_Text_SearchingForStatRaiseItems, MSGBOX_NPC
	end


LavenderTown_Mart_EventScript_Clerk::
	end


LavenderTown_Mart_EventScript_Rocker::
# 14 "data/maps/LavenderTown_Mart/scripts.pory"
	msgbox LavenderTown_Mart_Text_DidYouBuyRevives, MSGBOX_NPC
	end


LavenderTown_Mart_EventScript_Youngster::
# 19 "data/maps/LavenderTown_Mart/scripts.pory"
	msgbox LavenderTown_Mart_Text_TrainerDuosCanChallengeYou, MSGBOX_NPC
	end


LavenderTown_Mart_Text_SearchingForStatRaiseItems::
# 24 "data/maps/LavenderTown_Mart/scripts.pory"
	.string "I'm searching for items that raise\n"
	.string "the stats of POKéMON.\p"
	.string "They're effective over the course\n"
	.string "of a single battle.\p"
	.string "X ATTACK, X DEFEND, X SPEED,\n"
	.string "and X SPECIAL are what I'm after.\p"
	.string "Do you know where I can get them?$"

LavenderTown_Mart_Text_DidYouBuyRevives::
# 28 "data/maps/LavenderTown_Mart/scripts.pory"
	.string "Did you buy some REVIVES?\n"
	.string "They revive any fainted POKéMON!$"

LavenderTown_Mart_Text_TrainerDuosCanChallengeYou::
# 32 "data/maps/LavenderTown_Mart/scripts.pory"
	.string "Sometimes, a TRAINER duo will\n"
	.string "challenge you with two POKéMON\l"
	.string "at the same time.\p"
	.string "If that happens, you have to send\n"
	.string "out two POKéMON to battle, too.$"
