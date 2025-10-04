Route119_House_MapScripts::
	.byte 0


Route119_House_EventScript_Wingull::
# 5 "data/maps/Route119_House/scripts.pory"
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	end


Route119_House_EventScript_Woman::
# 10 "data/maps/Route119_House/scripts.pory"
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end


Route119_House_Text_Wingull::
# 14 "data/maps/Route119_House/scripts.pory"
	.string "WINGULL: Pihyoh!$"

Route119_House_Text_RumorAboutCaveOfOrigin::
# 18 "data/maps/Route119_House/scripts.pory"
	.string "I heard about a cave called the CAVE\n"
	.string "OF ORIGIN.\p"
	.string "People rumor that the spirits of\n"
	.string "POKéMON are revived there. Could\l"
	.string "something like that really happen?$"
