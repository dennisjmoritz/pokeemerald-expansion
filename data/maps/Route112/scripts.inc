Route112_MapScripts::
	.byte 0


Route112_EventScript_Brice::
# 5 "data/maps/Route112/scripts.pory"
	trainerbattle_double TRAINER_BRICE, Route112_Text_BriceIntro, Route112_Text_BriceDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_BricePostBattle
	return


Route112_EventScript_Bryant::
# 10 "data/maps/Route112/scripts.pory"
	trainerbattle_double TRAINER_BRYANT, Route112_Text_BryantIntro, Route112_Text_BryantDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_BryantPostBattle
	return


Route112_EventScript_Carol::
# 15 "data/maps/Route112/scripts.pory"
	trainerbattle_double TRAINER_CAROL, Route112_Text_CarolIntro, Route112_Text_CarolDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_CarolPostBattle
	return


Route112_EventScript_Hiker::
# 20 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_NotEasyToGetBackToLavaridge, MSGBOX_NPC
	end


Route112_EventScript_Larry::
# 25 "data/maps/Route112/scripts.pory"
	trainerbattle_double TRAINER_LARRY, Route112_Text_LarryIntro, Route112_Text_LarryDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_LarryPostBattle
	return


Route112_EventScript_MagmaGrunts::
# 30 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_LeaderGoingToAwakenThing, MSGBOX_DEFAULT
	end


Route112_EventScript_MtChimneyCableCarSign::
# 35 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_MtChimneyCableCarSign, MSGBOX_SIGN
	end


Route112_EventScript_MtChimneySign::
# 40 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_MtChimneySign, MSGBOX_SIGN
	end


Route112_EventScript_RouteSignLavaridge::
# 45 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_RouteSignLavaridge, MSGBOX_SIGN
	end


Route112_EventScript_Shayla::
# 50 "data/maps/Route112/scripts.pory"
	trainerbattle_double TRAINER_SHAYLA, Route112_Text_ShaylaIntro, Route112_Text_ShaylaDefeat, Text_NotEnoughMonsForDoubleBattle
# 51 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_ShaylaPostBattle
	return


Route112_EventScript_Trent::
# 55 "data/maps/Route112/scripts.pory"
	trainerbattle_double TRAINER_TRENT, Route112_Text_TrentIntro, Route112_Text_TrentDefeat, Text_NotEnoughMonsForDoubleBattle
# 56 "data/maps/Route112/scripts.pory"
	msgbox Route112_Text_TrentPostBattle
	return


Route112_Text_RouteSignLavaridge::
# 60 "data/maps/Route112/scripts.pory"
	.string "ROUTE 112 {LEFT_ARROW} LAVARIDGE TOWN$"

Route112_Text_MtChimneyCableCarSign::
# 64 "data/maps/Route112/scripts.pory"
	.string "MT. CHIMNEY CABLE CAR “A short walk {UP_ARROW}\n"
	.string "way!”$"

Route112_Text_MtChimneySign::
# 68 "data/maps/Route112/scripts.pory"
	.string "MT. CHIMNEY\p"
	.string "“For LAVARIDGE TOWN or the summit,\n"
	.string "please take the CABLE CAR.”$"

Route112_Text_BriceDefeat::
# 73 "data/maps/Route112/scripts.pory"
	.string "I lost! Hahahaha!$"

Route112_Text_BriceIntro::
# 77 "data/maps/Route112/scripts.pory"
	.string "Hahahaha! How about we have a battle?\n"
	.string "You and me! Hahahaha!$"

Route112_Text_BricePostBattle::
# 81 "data/maps/Route112/scripts.pory"
	.string "Hahahahaha! Something flew up my nose!\n"
	.string "Hahahaha-hatchoo!$"

Route112_Text_BryantDefeat::
# 85 "data/maps/Route112/scripts.pory"
	.string "What a bumpy ride that was!$"

Route112_Text_BryantIntro::
# 89 "data/maps/Route112/scripts.pory"
	.string "I caught hot POKéMON in FIERY PATH!\n"
	.string "Take a look!$"

Route112_Text_BryantPostBattle::
# 93 "data/maps/Route112/scripts.pory"
	.string "I like the way you battle. It has a\n"
	.string "certain flair to it.$"

Route112_Text_CarolDefeat::
# 97 "data/maps/Route112/scripts.pory"
	.string "Oh, you're so strong!$"

Route112_Text_CarolIntro::
# 101 "data/maps/Route112/scripts.pory"
	.string "When you're out on a picnic, why, you\n"
	.string "simply have to sing! Come on, sing with\l"
	.string "me!$"

Route112_Text_CarolPostBattle::
# 105 "data/maps/Route112/scripts.pory"
	.string "It doesn't matter if you're good or bad\n"
	.string "at singing or POKéMON.\p"
	.string "If you have the most fun, you win!$"

Route112_Text_LarryDefeat::
# 109 "data/maps/Route112/scripts.pory"
	.string "Waaaah!$"

Route112_Text_LarryIntro::
# 113 "data/maps/Route112/scripts.pory"
	.string "I'm strong. I won't cry if I lose.$"

Route112_Text_LarryPostBattle::
# 117 "data/maps/Route112/scripts.pory"
	.string "I'm not crying because I miss my mommy!\n"
	.string "Snivel…$"

Route112_Text_ShaylaDefeat::
# 121 "data/maps/Route112/scripts.pory"
	.string "Oh, how strong you are! You've given me\n"
	.string "quite a shock!$"

Route112_Text_ShaylaIntro::
# 125 "data/maps/Route112/scripts.pory"
	.string "Oh, aren't you an adorable TRAINER!\n"
	.string "Please, I need a romantic battle! I'm\l"
	.string "somewhat decent!$"

Route112_Text_ShaylaPostBattle::
# 129 "data/maps/Route112/scripts.pory"
	.string "Are you busy right now? I was thinking\n"
	.string "that maybe we can have a rematch right\l"
	.string "now… But it's all right if you're busy.$"

Route112_Text_TrentDefeat::
# 133 "data/maps/Route112/scripts.pory"
	.string "Ouch! My legs cramped up!$"

Route112_Text_TrentIntro::
# 137 "data/maps/Route112/scripts.pory"
	.string "My legs are solid from pounding up and\n"
	.string "down the mountains.\p"
	.string "They're not going to buckle easily,\n"
	.string "friend!$"

Route112_Text_TrentPostBattle::
# 141 "data/maps/Route112/scripts.pory"
	.string "Try hiking, and I mean really pounding,\n"
	.string "on these mountain trails with a heavy\l"
	.string "pack weighing dozens of pounds.\p"
	.string "That, my friend, will get your body into\n"
	.string "serious shape.$"

Route112_Text_NotEasyToGetBackToLavaridge::
# 145 "data/maps/Route112/scripts.pory"
	.string "Eh, I'd like to get to MAUVILLE, but if\n"
	.string "I went down these ledges, it'd be no\l"
	.string "easy matter to get back to LAVARIDGE.$"

Route112_Text_LeaderGoingToAwakenThing::
# 149 "data/maps/Route112/scripts.pory"
	.string "Hey, man, is our leader really going\n"
	.string "to awaken that thing?$"
