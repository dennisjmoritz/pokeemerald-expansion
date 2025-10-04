Route124_MapScripts::
	.byte 0


Route124_EventScript_Chad::
# 5 "data/maps/Route124/scripts.pory"
	trainerbattle_double TRAINER_CHAD, Route124_Text_ChadIntro, Route124_Text_ChadDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_ChadPostBattle
	return


Route124_EventScript_Declan::
# 10 "data/maps/Route124/scripts.pory"
	trainerbattle_double TRAINER_DECLAN, Route124_Text_DeclanIntro, Route124_Text_DeclanDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_DeclanPostBattle
	return


Route124_EventScript_Grace::
# 15 "data/maps/Route124/scripts.pory"
	trainerbattle_double TRAINER_GRACE, Route124_Text_GraceIntro, Route124_Text_GraceDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_GracePostBattle
	return


Route124_EventScript_HuntersHouseSign::
# 20 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_HuntersHouse, MSGBOX_SIGN
	end


Route124_EventScript_Isabella::
# 25 "data/maps/Route124/scripts.pory"
	trainerbattle_double TRAINER_ISABELLA, Route124_Text_IsabellaIntro, Route124_Text_IsabellaDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_IsabellaPostBattle
	return


Route124_EventScript_Jenny::
# 30 "data/maps/Route124/scripts.pory"
	trainerbattle_double TRAINER_JENNY, Route124_Text_JennyIntro, Route124_Text_JennyDefeat, Text_NotEnoughMonsForDoubleBattle
# 31 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_JennyPostBattle
	return


Route124_EventScript_Lila::
	end


Route124_EventScript_Roland::
# 39 "data/maps/Route124/scripts.pory"
	trainerbattle_double TRAINER_ROLAND, Route124_Text_RolandIntro, Route124_Text_RolandDefeat, Text_NotEnoughMonsForDoubleBattle
# 40 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_RolandPostBattle
	return


Route124_EventScript_Roy::
	end


Route124_EventScript_Spencer::
# 48 "data/maps/Route124/scripts.pory"
	trainerbattle_double TRAINER_SPENCER, Route124_Text_SpencerIntro, Route124_Text_SpencerDefeat, Text_NotEnoughMonsForDoubleBattle
# 49 "data/maps/Route124/scripts.pory"
	msgbox Route124_Text_SpencerPostBattle
	return


Route124_Text_HuntersHouse::
# 53 "data/maps/Route124/scripts.pory"
	.string "HUNTER'S HOUSE$"

Route124_Text_ChadDefeat::
# 58 "data/maps/Route124/scripts.pory"
	.string "Glub, glub, glub… I'm sinking…$"

Route124_Text_ChadIntro::
# 62 "data/maps/Route124/scripts.pory"
	.string "Fufufufu… I dive deep underwater to go\n"
	.string "deep under cover. Plumbing the depths\l"
	.string "is where I excel!$"

Route124_Text_ChadPostBattle::
# 66 "data/maps/Route124/scripts.pory"
	.string "I have it on good authority that\n"
	.string "there's a DIVE spot around here.\p"
	.string "It gives me the urge to go deep again…$"

Route124_Text_DeclanDefeat::
# 70 "data/maps/Route124/scripts.pory"
	.string "I'm feeling blue. Blue as the sky…$"

Route124_Text_DeclanIntro::
# 74 "data/maps/Route124/scripts.pory"
	.string "Here I am swimming by my lonesome on\n"
	.string "this wide, beautiful sea.\p"
	.string "There's no other word for it. This is\n"
	.string "pathetic!$"

Route124_Text_DeclanPostBattle::
# 78 "data/maps/Route124/scripts.pory"
	.string "I should chat up lady SWIMMERS and\n"
	.string "invite them on a long swim.$"

Route124_Text_GraceDefeat::
# 82 "data/maps/Route124/scripts.pory"
	.string "I had no idea that you were this strong!$"

Route124_Text_GraceIntro::
# 86 "data/maps/Route124/scripts.pory"
	.string "I'm growing bored of swimming… How\n"
	.string "about a battle?$"

Route124_Text_GracePostBattle::
# 90 "data/maps/Route124/scripts.pory"
	.string "All the effort you put in must have\n"
	.string "made you this strong.$"

Route124_Text_IsabellaDefeat::
# 94 "data/maps/Route124/scripts.pory"
	.string "I've only got sweat in my eyes! I am not\n"
	.string "crying!$"

Route124_Text_IsabellaIntro::
# 98 "data/maps/Route124/scripts.pory"
	.string "I'm not going to lose to some surfer\n"
	.string "TRAINER.$"

Route124_Text_IsabellaPostBattle::
# 102 "data/maps/Route124/scripts.pory"
	.string "You can find pretty colored shards of\n"
	.string "things around here.$"

Route124_Text_JennyDefeat::
# 106 "data/maps/Route124/scripts.pory"
	.string "Oh, darn. I've gone and lost.$"

Route124_Text_JennyIntro::
# 110 "data/maps/Route124/scripts.pory"
	.string "If you just float in the sea like this,\n"
	.string "POKéMON come around to play.$"

Route124_Text_JennyPostBattle::
# 114 "data/maps/Route124/scripts.pory"
	.string "While swimming, I noticed that some\n"
	.string "POKéMON attack, and some just watch.\p"
	.string "I guess POKéMON have personalities of\n"
	.string "their own.$"

Route124_Text_RolandDefeat::
# 118 "data/maps/Route124/scripts.pory"
	.string "Oh! I can't…$"

Route124_Text_RolandIntro::
# 122 "data/maps/Route124/scripts.pory"
	.string "Hm! You're riding a POKéMON instead of\n"
	.string "swimming yourself…\p"
	.string "I am envious!$"

Route124_Text_RolandPostBattle::
# 126 "data/maps/Route124/scripts.pory"
	.string "I'm getting chilled… I've been in the\n"
	.string "water too long…\p"
	.string "I wish I could ride a POKéMON like you…$"

Route124_Text_SpencerDefeat::
# 130 "data/maps/Route124/scripts.pory"
	.string "I lost my bearings in battle!$"

Route124_Text_SpencerIntro::
# 134 "data/maps/Route124/scripts.pory"
	.string "Hey, are you lost at sea?\p"
	.string "If you can beat my POKéMON, I can serve\n"
	.string "as your pilot.$"

Route124_Text_SpencerPostBattle::
# 138 "data/maps/Route124/scripts.pory"
	.string "Many people lose their bearings at sea.\p"
	.string "If you're that sort, you should refer to\n"
	.string "the POKéNAV's MAP.$"
