Route109_MapScripts::
	.byte 0


Route109_EventScript_Alice::
# 5 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_ALICE, Route109_Text_AliceIntro, Route109_Text_AliceDefeated, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_AlicePostBattle
	return


Route109_EventScript_Austina::
# 10 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_AUSTINA, Route109_Text_AustinaIntro, Route109_Text_AustinaDefeated, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_AustinaPostBattle
	return


Route109_EventScript_Carter::
# 15 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_CARTER, Route109_Text_CarterIntro, Route109_Text_CarterDefeated, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_CarterPostBattle
	return


Route109_EventScript_Chandler::
# 20 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_CHANDLER, Route109_Text_ChandlerIntro, Route109_Text_ChandlerDefeated, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_ChandlerPostBattle
	return


Route109_EventScript_David::
# 25 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_DAVID, Route109_Text_DavidIntro, Route109_Text_DavidDefeated, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_DavidPostBattle
	return


Route109_EventScript_Edmond::
# 30 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_EDMOND, Route109_Text_EdmondIntro, Route109_Text_EdmondDefeated, Text_NotEnoughMonsForDoubleBattle
# 31 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_EdmondPostBattle
	return


Route109_EventScript_Elijah::
# 35 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_ELIJAH, Route109_Text_ElijahIntro, Route109_Text_ElijahDefeated, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_ElijahPostBattle
	return


Route109_EventScript_Gwen::
# 40 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_GWEN, Route109_Text_GwenIntro, Route109_Text_GwenDefeated, Text_NotEnoughMonsForDoubleBattle
# 41 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_GwenPostBattle
	return


Route109_EventScript_Hailey::
# 45 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_HAILEY, Route109_Text_HaileyIntro, Route109_Text_HaileyDefeated, Text_NotEnoughMonsForDoubleBattle
# 46 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_HaileyPostBattle
	return


Route109_EventScript_Huey::
# 50 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_HUEY, Route109_Text_HueyIntro, Route109_Text_HueyDefeated, Text_NotEnoughMonsForDoubleBattle
# 51 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_HueyPostBattle
	return


Route109_EventScript_Lola::
# 55 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_LOLA, Route109_Text_LolaIntro, Route109_Text_LolaDefeated, Text_NotEnoughMonsForDoubleBattle
# 56 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_LolaPostBattle
	return


Route109_EventScript_Mel::
# 60 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_MelPostBattle, MSGBOX_AUTOCLOSE
	end


Route109_EventScript_MrBriney::
	end


Route109_EventScript_OldMan::
# 69 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_ZigzagoonPicksUpLitter, MSGBOX_NPC
	end


Route109_EventScript_Paul::
# 74 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end


Route109_EventScript_Ricky::
# 79 "data/maps/Route109/scripts.pory"
	trainerbattle_double TRAINER_RICKY, Route109_Text_RickyIntro, Route109_Text_RickyDefeated, Text_NotEnoughMonsForDoubleBattle
# 80 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_RickyPostBattle
	return


Route109_EventScript_SandCastleBoy::
# 84 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_SandCastleTakingLongTime, MSGBOX_DEFAULT
	end


Route109_EventScript_SeashoreHouseGirl::
# 89 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_ChillAtMyPapasSpot, MSGBOX_NPC
	end


Route109_EventScript_SeashoreHouseSign::
# 94 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_SeashoreHouseSign, MSGBOX_SIGN
	end


Route109_EventScript_SoftSandGirl::
	end


Route109_EventScript_TrainerTipsSign::
# 103 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_TrainerTipsSign, MSGBOX_SIGN
	end


Route109_EventScript_Woman::
# 108 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_LittleKidsDartAround, MSGBOX_NPC
	end


Route109_EventScript_Zigzagoon::
# 113 "data/maps/Route109/scripts.pory"
	msgbox Route109_Text_ZigzagoonCry, MSGBOX_DEFAULT
	end


Route109_Text_TrainerTipsSign::
# 118 "data/maps/Route109/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "POKéMON at the same level may not\n"
	.string "always have identical stats.\p"
	.string "POKéMON raised by TRAINERS are said to\n"
	.string "grow stronger than wild POKéMON.$"

Route109_Text_SeashoreHouseSign::
# 122 "data/maps/Route109/scripts.pory"
	.string "SEASHORE HOUSE\p"
	.string "“May hot battles rage on hot sands! The\n"
	.string "place for hot TRAINERS!”$"

Route109_Text_AliceDefeated::
# 127 "data/maps/Route109/scripts.pory"
	.string "Ouch, ouch, ouch!$"

Route109_Text_AliceIntro::
# 131 "data/maps/Route109/scripts.pory"
	.string "Are you properly protected against the\n"
	.string "sun?$"

Route109_Text_AlicePostBattle::
# 135 "data/maps/Route109/scripts.pory"
	.string "Cheeks are the most prone to burning!$"

Route109_Text_AustinaDefeated::
# 139 "data/maps/Route109/scripts.pory"
	.string "Did I lose because I have an inner\n"
	.string "tube?$"

Route109_Text_AustinaIntro::
# 143 "data/maps/Route109/scripts.pory"
	.string "I can't swim without my inner tube, but\n"
	.string "I won't lose at POKéMON!$"

Route109_Text_AustinaPostBattle::
# 147 "data/maps/Route109/scripts.pory"
	.string "My inner tube is a fashion item. I can't\n"
	.string "be seen without it.$"

Route109_Text_CarterDefeated::
# 151 "data/maps/Route109/scripts.pory"
	.string "This dude just lost one…$"

Route109_Text_CarterIntro::
# 155 "data/maps/Route109/scripts.pory"
	.string "Wahahah! This dude's going to catch\n"
	.string "himself a big one!$"

Route109_Text_CarterPostBattle::
# 159 "data/maps/Route109/scripts.pory"
	.string "This dude thinks you're a big one. No,\n"
	.string "you're a big-one-to-be!$"

Route109_Text_ChandlerDefeated::
# 163 "data/maps/Route109/scripts.pory"
	.string "Oh, oh! Too bad!$"

Route109_Text_ChandlerIntro::
# 167 "data/maps/Route109/scripts.pory"
	.string "Tadaah! See? My inner tube's round!$"

Route109_Text_ChandlerPostBattle::
# 171 "data/maps/Route109/scripts.pory"
	.string "After I showed you my round inner tube,\n"
	.string "too…$"

Route109_Text_DavidDefeated::
# 175 "data/maps/Route109/scripts.pory"
	.string "Aiyah! Flubbed out!$"

Route109_Text_DavidIntro::
# 179 "data/maps/Route109/scripts.pory"
	.string "Hiyah! Look at my chiseled abs! This is\n"
	.string "what you call “cut”!$"

Route109_Text_DavidPostBattle::
# 183 "data/maps/Route109/scripts.pory"
	.string "Hiyah!\p"
	.string "My sculpted abs have nothing to do with\n"
	.string "POKéMON battles!$"

Route109_Text_EdmondDefeated::
# 187 "data/maps/Route109/scripts.pory"
	.string "Urp… Ooooooohhhhhh… Urrrrpppp…$"

Route109_Text_EdmondIntro::
# 191 "data/maps/Route109/scripts.pory"
	.string "Urrrrppp… Battle? With me?$"

Route109_Text_EdmondPostBattle::
# 195 "data/maps/Route109/scripts.pory"
	.string "I'm usually stronger than this! I'm just\n"
	.string "seasick as a dog!\p"
	.string "I'm a SAILOR, but…$"

Route109_Text_ElijahDefeated::
# 199 "data/maps/Route109/scripts.pory"
	.string "I'm cool even in defeat, hey?$"

Route109_Text_ElijahIntro::
# 203 "data/maps/Route109/scripts.pory"
	.string "For a guy as macho as me, this kind of\n"
	.string "POKéMON is the perfect match!$"

Route109_Text_ElijahPostBattle::
# 207 "data/maps/Route109/scripts.pory"
	.string "For a guy as macho as me, a port is the\n"
	.string "perfect setting!\p"
	.string "I guess I'll head for SLATEPORT.$"

Route109_Text_GwenDefeated::
# 211 "data/maps/Route109/scripts.pory"
	.string "Oh, you're strong.$"

Route109_Text_GwenIntro::
# 215 "data/maps/Route109/scripts.pory"
	.string "Hi, big TRAINER. Will you battle with me?$"

Route109_Text_GwenPostBattle::
# 219 "data/maps/Route109/scripts.pory"
	.string "How did you get to be so strong?$"

Route109_Text_HaileyDefeated::
# 223 "data/maps/Route109/scripts.pory"
	.string "I thought so! I didn't think we could\n"
	.string "win.$"

Route109_Text_HaileyIntro::
# 227 "data/maps/Route109/scripts.pory"
	.string "I can't swim, so I'm pretending to swim.$"

Route109_Text_HaileyPostBattle::
# 231 "data/maps/Route109/scripts.pory"
	.string "When I learn how to swim, I think my\n"
	.string "POKéMON will become tougher.$"

Route109_Text_HueyDefeated::
# 235 "data/maps/Route109/scripts.pory"
	.string "You're the best!$"

Route109_Text_HueyIntro::
# 239 "data/maps/Route109/scripts.pory"
	.string "I've laid anchor in ports around the\n"
	.string "world, but SLATEPORT's the best.$"

Route109_Text_HueyPostBattle::
# 243 "data/maps/Route109/scripts.pory"
	.string "In the best port was the best TRAINER…$"

Route109_Text_LolaDefeated::
# 247 "data/maps/Route109/scripts.pory"
	.string "Mommy!$"

Route109_Text_LolaIntro::
# 251 "data/maps/Route109/scripts.pory"
	.string "Doesn't a beach umbrella look like a\n"
	.string "giant flower?$"

Route109_Text_LolaPostBattle::
# 255 "data/maps/Route109/scripts.pory"
	.string "If you look at the beach from the sky,\n"
	.string "it looks like a big flower garden!$"

Route109_Text_RickyDefeated::
# 259 "data/maps/Route109/scripts.pory"
	.string "Groan…$"

Route109_Text_RickyIntro::
# 263 "data/maps/Route109/scripts.pory"
	.string "I'm thirsty… I could go for a SODA POP\n"
	.string "at the SEASHORE HOUSE…$"

Route109_Text_RickyPostBattle::
# 267 "data/maps/Route109/scripts.pory"
	.string "I'm getting famished… My inner tube\n"
	.string "looks like a giant doughnut…$"

Route109_Text_ChillAtMyPapasSpot::
# 271 "data/maps/Route109/scripts.pory"
	.string "Yo, TRAINERS!\n"
	.string "Whether you're hot to trot,\l"
	.string "or cool cat not,\l"
	.string "chill at my papa's spot!$"

Route109_Text_ZigzagoonPicksUpLitter::
# 275 "data/maps/Route109/scripts.pory"
	.string "The water around these parts is clean.\p"
	.string "But, I get my ZIGZAGOON to pick up\n"
	.string "litter from the shoreline at times.\p"
	.string "Dirty water becomes rain and joins our\n"
	.string "rivers, which we drink from…\p"
	.string "If we pollute the sea, it all comes\n"
	.string "back to haunt us eventually.$"

Route109_Text_BrineySailToDewfordQuestion::
# 279 "data/maps/Route109/scripts.pory"
	.string "MR. BRINEY: I thought you're supposed\n"
	.string "to deliver the DEVON GOODS.\p"
	.string "Would you like to sail back to\n"
	.string "DEWFORD, then?$"

Route109_Text_WereGoingToMakeBigCastle::
# 283 "data/maps/Route109/scripts.pory"
	.string "We're going to get all the sand from\n"
	.string "the beach and make a big castle!\p"
	.string "And then we're going to be a king and\n"
	.string "queen.\p"
	.string "We'll let you be a servant.$"

Route109_Text_BrineyTellMeWhenYouNeedToSail::
# 287 "data/maps/Route109/scripts.pory"
	.string "MR. BRINEY: You just tell me whenever\n"
	.string "you need to set sail again!$"

Route109_Text_BrineyDeliverDevonGoods::
# 291 "data/maps/Route109/scripts.pory"
	.string "MR. BRINEY: Then you go on and deliver\n"
	.string "the DEVON GOODS. I'll be waiting.$"

Route109_Text_BrineyDewfordItIs::
# 295 "data/maps/Route109/scripts.pory"
	.string "MR. BRINEY: DEWFORD it is, then!\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"

Route109_Text_SandCastleTakingLongTime::
# 299 "data/maps/Route109/scripts.pory"
	.string "Our sand castle's taking a long time\n"
	.string "to make.$"

Route109_Text_LittleKidsDartAround::
# 303 "data/maps/Route109/scripts.pory"
	.string "Little kids can dart around so quickly…\p"
	.string "You don't dare take your eyes off them\n"
	.string "for an instant. It's very taxing.\p"
	.string "Mine are with my POKéMON, so they\n"
	.string "should be okay, but…$"

Route109_Text_ZigzagoonCry::
# 307 "data/maps/Route109/scripts.pory"
	.string "ZIGZAGOON: Guguu?$"

Route109_Text_MelPostBattle::
# 311 "data/maps/Route109/scripts.pory"
	.string "MEL: Um, PAUL, are you angry with me?\n"
	.string "Please don't be angry.$"

Route109_Text_PaulPostBattle::
# 315 "data/maps/Route109/scripts.pory"
	.string "PAUL: Well, don't tell anyone that we're\n"
	.string "here. This is just our private world of\l"
	.string "two!$"
