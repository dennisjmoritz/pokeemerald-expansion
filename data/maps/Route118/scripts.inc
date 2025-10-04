Route118_MapScripts::
	.byte 0


Route118_EventScript_Barny::
# 5 "data/maps/Route118/scripts.pory"
	trainerbattle_double TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_BarnyPostBattle
	return


Route118_EventScript_Chester::
# 10 "data/maps/Route118/scripts.pory"
	trainerbattle_double TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_ChesterPostBattle
	return


Route118_EventScript_Dalton::
# 15 "data/maps/Route118/scripts.pory"
	trainerbattle_double TRAINER_DALTON, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonPostBattle
	return


Route118_EventScript_Deandre::
# 20 "data/maps/Route118/scripts.pory"
	trainerbattle_double TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DeandrePostBattle
	return


Route118_EventScript_Girl::
# 25 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end


Route118_EventScript_GoodRodFisherman::
	end


Route118_EventScript_Perry::
# 34 "data/maps/Route118/scripts.pory"
	trainerbattle_double TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat, Text_NotEnoughMonsForDoubleBattle
# 35 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_PerryPostBattle
	return


Route118_EventScript_Rose::
# 39 "data/maps/Route118/scripts.pory"
	trainerbattle_double TRAINER_ROSE, Route118_Text_RoseIntro, Route118_Text_RoseDefeat, Text_NotEnoughMonsForDoubleBattle
# 40 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RosePostBattle
	return


Route118_EventScript_RouteSign119::
# 44 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
	end


Route118_EventScript_RouteSignMauville::
# 49 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
	end


Route118_EventScript_StevenTrigger0::
	end


Route118_EventScript_StevenTrigger1::
	end


Route118_EventScript_StevenTrigger2::
	end


Route118_EventScript_Wade::
# 66 "data/maps/Route118/scripts.pory"
	trainerbattle_double TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat, Text_NotEnoughMonsForDoubleBattle
# 67 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_WadePostBattle
	return


Route118_Text_RouteSignMauville::
# 71 "data/maps/Route118/scripts.pory"
	.string "ROUTE 118 {LEFT_ARROW} MAUVILLE CITY$"

Route118_Text_RouteSign119::
# 75 "data/maps/Route118/scripts.pory"
	.string "ROUTE 118 {UP_ARROW} ROUTE 119$"

Route118_Text_BarnyDefeat::
# 80 "data/maps/Route118/scripts.pory"
	.string "I thought I was doing okay in my\n"
	.string "training…$"

Route118_Text_BarnyIntro::
# 84 "data/maps/Route118/scripts.pory"
	.string "I'm a FISHERMAN, but also a TRAINER. I'm\n"
	.string "raising the POKéMON I caught.$"

Route118_Text_BarnyPostBattle::
# 88 "data/maps/Route118/scripts.pory"
	.string "I couldn't win by training POKéMON while\n"
	.string "I fished…\p"
	.string "Was I doing things in half measures?$"

Route118_Text_ChesterDefeat::
# 92 "data/maps/Route118/scripts.pory"
	.string "They did take flight…$"

Route118_Text_ChesterIntro::
# 96 "data/maps/Route118/scripts.pory"
	.string "Take flight! My BIRD POKéMON!$"

Route118_Text_ChesterPostBattle::
# 100 "data/maps/Route118/scripts.pory"
	.string "If they'd get stronger, they'd be able\n"
	.string "to fly more freely…$"

Route118_Text_DaltonDefeat::
# 104 "data/maps/Route118/scripts.pory"
	.string "La-lalala…$"

Route118_Text_DaltonIntro::
# 108 "data/maps/Route118/scripts.pory"
	.string "Let my melody rock your soul!$"

Route118_Text_DaltonPostBattle::
# 112 "data/maps/Route118/scripts.pory"
	.string "An electric guitar doesn't always have\n"
	.string "to be noisy…\p"
	.string "It can be strummed to squeeze out this\n"
	.string "heart-stirring melody…$"

Route118_Text_DeandreDefeat::
# 116 "data/maps/Route118/scripts.pory"
	.string "Come in, POKéMON! Are you okay? POKéMON\n"
	.string "1, 2, and 3?!$"

Route118_Text_DeandreIntro::
# 120 "data/maps/Route118/scripts.pory"
	.string "Go, go, go! POKéMON 1, 2, and 3!$"

Route118_Text_DeandrePostBattle::
# 124 "data/maps/Route118/scripts.pory"
	.string "Isn't it cool that I have a POKéMON\n"
	.string "battle team?\p"
	.string "You can copy me--I don't mind!$"

Route118_Text_PerryDefeat::
# 128 "data/maps/Route118/scripts.pory"
	.string "Urgh… I crashed…$"

Route118_Text_PerryIntro::
# 132 "data/maps/Route118/scripts.pory"
	.string "BIRD POKéMON that FLY elegantly in the\n"
	.string "sky… They're the best!$"

Route118_Text_PerryPostBattle::
# 136 "data/maps/Route118/scripts.pory"
	.string "You've got great POKéMON. I'll have to\n"
	.string "train mine better.$"

Route118_Text_RoseDefeat::
# 140 "data/maps/Route118/scripts.pory"
	.string "Oh, dear me. I seem to have lost.$"

Route118_Text_RoseIntro::
# 144 "data/maps/Route118/scripts.pory"
	.string "The aroma of flowers has a magical\n"
	.string "power. It cleanses us body and soul.$"

Route118_Text_RosePostBattle::
# 148 "data/maps/Route118/scripts.pory"
	.string "Flowers, POKéMON… I love whatever\n"
	.string "smells nice.\p"
	.string "Stinky things… I'll pass.$"

Route118_Text_WadeDefeat::
# 152 "data/maps/Route118/scripts.pory"
	.string "I was beaten in heart?$"

Route118_Text_WadeIntro::
# 156 "data/maps/Route118/scripts.pory"
	.string "For FISHERMEN, equipment is the key.\p"
	.string "But for TRAINERS, the key ingredients\n"
	.string "are POKéMON and heart, of course!$"

Route118_Text_WadePostBattle::
# 160 "data/maps/Route118/scripts.pory"
	.string "Come to think of it, fishing is a battle\n"
	.string "between a FISHERMAN and a POKéMON.$"

Route118_Text_CanCrossRiversWithSurf::
# 164 "data/maps/Route118/scripts.pory"
	.string "Even if there isn't a boat, you can\n"
	.string "cross rivers and the sea if you have\l"
	.string "a POKéMON that knows SURF.\p"
	.string "POKéMON can be counted on to do so\n"
	.string "much!$"

Route118_Text_TryCatchingMonWithGoodRod::
# 168 "data/maps/Route118/scripts.pory"
	.string "Try catching all sorts of POKéMON\n"
	.string "with your GOOD ROD.$"

Route118_Text_StevenQuestions::
# 172 "data/maps/Route118/scripts.pory"
	.string "STEVEN: Hi, {PLAYER}{KUN}!\p"
	.string "It's me, STEVEN!\n"
	.string "We met in the cave near DEWFORD.\p"
	.string "Have you met many kinds of POKéMON\n"
	.string "since I last saw you?\p"
	.string "There are many, many kinds of POKéMON\n"
	.string "in this wide world of ours.\p"
	.string "If you wanted to raise only your\n"
	.string "favorites, that's fine.\p"
	.string "Perhaps you find it more fun to raise\n"
	.string "all sorts of POKéMON.\p"
	.string "As a TRAINER of POKéMON,\n"
	.string "what do you think?\p"
	.string "Of course, it's not any of my business.\p"
	.string "It would be nice if we were to meet\n"
	.string "again somewhere.$"

Route118_Text_IdenticalMindsTakeThis::
# 176 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
	.string "We're of identical minds!\p"
	.string "Hmm!\n"
	.string "Take this GOOD ROD!$"

Route118_Text_DontYouLikeToFish::
# 180 "data/maps/Route118/scripts.pory"
	.string "Don't you like to fish?$"
