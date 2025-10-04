MossdeepCity_StevensHouse_MapScripts::
	.byte 0


MossdeepCity_StevensHouse_EventScript_BeldumPokeball::
# 5 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum, MSGBOX_YESNO
	end


MossdeepCity_StevensHouse_EventScript_Letter::
# 10 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_LetterFromSteven, MSGBOX_DEFAULT
	end


MossdeepCity_StevensHouse_EventScript_RockDisplay::
# 15 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
	end


MossdeepCity_StevensHouse_EventScript_Steven::
# 20 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	msgbox MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
	end


MossdeepCity_StevensHouse_Text_CollectionOfRareRocks::
# 25 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by STEVEN.$"

MossdeepCity_StevensHouse_Text_TakeBallContainingBeldum::
# 29 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "{PLAYER} checked the POKé BALL.\p"
	.string "It contained the POKéMON\n"
	.string "BELDUM.\p"
	.string "Take the POKé BALL?$"

MossdeepCity_StevensHouse_Text_LeftPokeBallWhereItWas::
# 33 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "{PLAYER} left the POKé BALL where\n"
	.string "it was.$"

MossdeepCity_StevensHouse_Text_UnderwateCavernBetweenMossdeepSootopolis::
# 37 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "STEVEN: Apparently, there's an\n"
	.string "underwater cavern between\l"
	.string "MOSSDEEP and SOOTOPOLIS.\p"
	.string "You know, the one that CAPT. STERN\n"
	.string "found in his submarine.$"

MossdeepCity_StevensHouse_Text_LetterFromSteven::
# 41 "data/maps/MossdeepCity_StevensHouse/scripts.pory"
	.string "It's a letter.\p"
	.string "… … … … … …\p"
	.string "To {PLAYER}{KUN}…\p"
	.string "I've decided to do a little soul-\n"
	.string "searching and train on the road.\p"
	.string "I don't plan to return home for some\n"
	.string "time.\p"
	.string "I have a favor to ask of you.\p"
	.string "I want you to take the POKé BALL on\n"
	.string "the desk.\p"
	.string "Inside it is a BELDUM, my favorite\n"
	.string "POKéMON.\p"
	.string "I'm counting on you.\p"
	.string "May our paths cross someday.\p"
	.string "STEVEN STONE$"
