Route114_LanettesHouse_MapScripts::
	.byte 0


Route114_LanettesHouse_EventScript_Lanette::
	end


Route114_LanettesHouse_EventScript_Notebook::
# 10 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
# 12 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	end


Route114_LanettesHouse_EventScript_PC::
# 18 "data/maps/Route114_LanettesHouse/scripts.pory"
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end


Route114_LanettesHouse_Text_ClosedTheNotebook::
# 23 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "{PLAYER} closed the notebook.$"

Route114_LanettesHouse_Text_EmailFromBill::
# 27 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "There's an e-mail from someone on the\n"
	.string "PC.\p"
	.string "“… … … … … … …\p"
	.string "“Your Storage System offers more\n"
	.string "convenience than mine.\p"
	.string "“It has a lot of user-friendly features\n"
	.string "that make it fun and useful, too.\p"
	.string "“It makes me proud that I played a part\n"
	.string "in its development.\p"
	.string "“Here's hoping that you'll continue\n"
	.string "research in Storage Systems.\p"
	.string "“From BILL … … … … … … … …”$"

Route114_LanettesHouse_Text_ResearchNotesPage1::
# 31 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "It's LANETTE's research notes. There's\n"
	.string "information about BOXES.\p"
	.string "Design BOXES to hold 30 POKéMON each.\p"
	.string "Each TRAINER should be able to store\n"
	.string "420 POKéMON on the PC system.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage3::
# 35 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "When storing a POKéMON, it should be\n"
	.string "sent to the BOX inspected last.\p"
	.string "If that BOX is full, the received\n"
	.string "POKéMON is stored in the next BOX.\p"
	.string "In other words, when a BOX is examined,\n"
	.string "it is automatically selected as the BOX\l"
	.string "to which POKéMON are sent.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes::
# 39 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "May I offer advice about my POKéMON\n"
	.string "Storage System?\p"
	.string "You should organize your BOXES so you\n"
	.string "can tell which POKéMON are in them.$"

Route114_LanettesHouse_Text_ResearchNotesPage2::
# 43 "data/maps/Route114_LanettesHouse/scripts.pory"
	.string "A marking system should be added to\n"
	.string "make POKéMON easier to organize.\p"
	.string "The name and wallpaper design of each\n"
	.string "BOX will be made changeable to please\l"
	.string "the stored POKéMON.\p"
	.string "Keep reading?$"
