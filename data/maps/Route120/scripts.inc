Route120_MapScripts::
	.byte 0


Route120_EventScript_Angelica::
# 5 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_ANGELICA, Route120_Text_AngelicaIntro, Route120_Text_AngelicaDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_AngelicaPostBattle
	return


Route120_EventScript_BerryBeauty::
	end


Route120_EventScript_Callie::
# 15 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_CALLIE, Route120_Text_CallieIntro, Route120_Text_CallieDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_CalliePostBattle
	return


Route120_EventScript_Chip::
# 20 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_CHIP, Route120_Text_ChipIntro, Route120_Text_ChipDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ChipPostBattle
	return


Route120_EventScript_Clarissa::
# 25 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_CLARISSA, Route120_Text_ClarissaIntro, Route120_Text_ClarissaDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ClarissaPostBattle
	return


Route120_EventScript_Colin::
# 30 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_COLIN, Route120_Text_ColinIntro, Route120_Text_ColinDefeat, Text_NotEnoughMonsForDoubleBattle
# 31 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_ColinPostBattle
	return


Route120_EventScript_Jeffrey::
# 35 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_JEFFREY, Route120_Text_JeffreyIntro, Route120_Text_JeffreyDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JeffreyPostBattle
	return


Route120_EventScript_Jenna::
# 40 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_JENNA, Route120_Text_JennaIntro, Route120_Text_JennaDefeat, Text_NotEnoughMonsForDoubleBattle
# 41 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JennaPostBattle
	return


Route120_EventScript_Jennifer::
# 45 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_JENNIFER, Route120_Text_JenniferIntro, Route120_Text_JenniferDefeat, Text_NotEnoughMonsForDoubleBattle
# 46 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_JenniferPostBattle
	return


Route120_EventScript_Keigo::
# 50 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_KEIGO, Route120_Text_KeigoIntro, Route120_Text_KeigoDefeat, Text_NotEnoughMonsForDoubleBattle
# 51 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_KeigoPostBattle
	return


Route120_EventScript_Leonel::
# 55 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_LEONEL, Route120_Text_LeonelIntro, Route120_Text_LeonelDefeat, Text_NotEnoughMonsForDoubleBattle
# 56 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_LeonelPostBattle
	return


Route120_EventScript_Lorenzo::
# 60 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_LORENZO, Route120_Text_LorenzoIntro, Route120_Text_LorenzoDefeat, Text_NotEnoughMonsForDoubleBattle
# 61 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_LorenzoPostBattle
	return


Route120_EventScript_Riley::
# 65 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_RILEY, Route120_Text_RileyIntro, Route120_Text_RileyDefeat, Text_NotEnoughMonsForDoubleBattle
# 66 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RileyPostBattle
	return


Route120_EventScript_Robert::
# 70 "data/maps/Route120/scripts.pory"
	trainerbattle_double TRAINER_ROBERT, Route120_Text_RobertIntro, Route120_Text_RobertDefeat, Text_NotEnoughMonsForDoubleBattle
# 71 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RobertPostBattle
	return


Route120_EventScript_RouteSign121::
# 75 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSign121, MSGBOX_SIGN
	end


Route120_EventScript_RouteSignFortree::
# 80 "data/maps/Route120/scripts.pory"
	msgbox Route120_Text_RouteSignFortree, MSGBOX_SIGN
	end


Route120_EventScript_Steven::
	end


Route120_Text_RouteSign121::
# 89 "data/maps/Route120/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 121 {LEFT_ARROW} ROUTE 120$"

Route120_Text_RouteSignFortree::
# 93 "data/maps/Route120/scripts.pory"
	.string "ROUTE 120 {LEFT_ARROW} FORTREE CITY$"

Route120_Text_AngelicaDefeat::
# 98 "data/maps/Route120/scripts.pory"
	.string "You've completely ruined my beauty…$"

Route120_Text_AngelicaIntro::
# 102 "data/maps/Route120/scripts.pory"
	.string "Me, POKéMON, and my parasol…\p"
	.string "If any one of them is missing, the\n"
	.string "picture of beauty will be ruined.$"

Route120_Text_AngelicaPostBattle::
# 106 "data/maps/Route120/scripts.pory"
	.string "A parasol wouldn't suit you at all.\p"
	.string "Why, something like this would only get\n"
	.string "in your way.$"

Route120_Text_CallieDefeat::
# 110 "data/maps/Route120/scripts.pory"
	.string "Ouch! I was the one to get hurt.$"

Route120_Text_CallieIntro::
# 114 "data/maps/Route120/scripts.pory"
	.string "If you don't pay attention, you could\n"
	.string "get hurt!$"

Route120_Text_CalliePostBattle::
# 118 "data/maps/Route120/scripts.pory"
	.string "I wonder… Should I evolve my POKéMON?\n"
	.string "They're cute the way they are, though.$"

Route120_Text_ChipDefeat::
# 122 "data/maps/Route120/scripts.pory"
	.string "What a disgraceful setback…$"

Route120_Text_ChipIntro::
# 126 "data/maps/Route120/scripts.pory"
	.string "Who might you be?\p"
	.string "Are you perhaps searching for ancient\n"
	.string "ruins that are rumored to possibly\l"
	.string "exist according to legend?$"

Route120_Text_ChipPostBattle::
# 130 "data/maps/Route120/scripts.pory"
	.string "That giant rock… I would like to believe\n"
	.string "it may indeed contain ancient ruins. But\l"
	.string "I see no entrance.$"

Route120_Text_ClarissaDefeat::
# 134 "data/maps/Route120/scripts.pory"
	.string "A parasol can't ward off POKéMON\n"
	.string "attacks…$"

Route120_Text_ClarissaIntro::
# 138 "data/maps/Route120/scripts.pory"
	.string "Why am I carrying this parasol?\p"
	.string "I'll tell you if you can win against me.$"

Route120_Text_ClarissaPostBattle::
# 142 "data/maps/Route120/scripts.pory"
	.string "I don't think strong sunlight is good\n"
	.string "for my POKéMON. So I shield them with my\l"
	.string "parasol.$"

Route120_Text_ColinDefeat::
# 146 "data/maps/Route120/scripts.pory"
	.string "You soared above me!$"

Route120_Text_ColinIntro::
# 150 "data/maps/Route120/scripts.pory"
	.string "Do you have any moves that can strike a\n"
	.string "flying POKéMON?$"

Route120_Text_ColinPostBattle::
# 154 "data/maps/Route120/scripts.pory"
	.string "The move FLY is convenient, don't you\n"
	.string "think?\p"
	.string "While the POKéMON is flying, almost no\n"
	.string "moves can strike it.$"

Route120_Text_JeffreyDefeat::
# 158 "data/maps/Route120/scripts.pory"
	.string "Lost it…$"

Route120_Text_JeffreyIntro::
# 162 "data/maps/Route120/scripts.pory"
	.string "… … … … … … … … … … … … Want to battle?$"

Route120_Text_JeffreyPostBattle::
# 166 "data/maps/Route120/scripts.pory"
	.string "… … … … … … … … … … … … I'll try harder…$"

Route120_Text_JennaDefeat::
# 170 "data/maps/Route120/scripts.pory"
	.string "I'm totally fit, but…$"

Route120_Text_JennaIntro::
# 174 "data/maps/Route120/scripts.pory"
	.string "How's your physical fitness? If you're\n"
	.string "not fit, you could have a rough time in\l"
	.string "critical situations.$"

Route120_Text_JennaPostBattle::
# 178 "data/maps/Route120/scripts.pory"
	.string "Fitness training is in my routine. I\n"
	.string "always run with my POKéMON.$"

Route120_Text_JenniferDefeat::
# 182 "data/maps/Route120/scripts.pory"
	.string "You're obviously thinking.$"

Route120_Text_JenniferIntro::
# 186 "data/maps/Route120/scripts.pory"
	.string "POKéMON have many special abilities. If\n"
	.string "you want to become a first-class\l"
	.string "TRAINER, learn about them.$"

Route120_Text_JenniferPostBattle::
# 190 "data/maps/Route120/scripts.pory"
	.string "The special abilities of POKéMON will\n"
	.string "make battle styles change.$"

Route120_Text_KeigoDefeat::
# 194 "data/maps/Route120/scripts.pory"
	.string "The creation of new ninja techniques is\n"
	.string "but a distant dream…$"

Route120_Text_KeigoIntro::
# 198 "data/maps/Route120/scripts.pory"
	.string "I will adopt the movements of POKéMON\n"
	.string "and create new ninja techniques.$"

Route120_Text_KeigoPostBattle::
# 202 "data/maps/Route120/scripts.pory"
	.string "Perhaps I ought to apprentice under a\n"
	.string "ninja sensei.$"

Route120_Text_LeonelDefeat::
# 206 "data/maps/Route120/scripts.pory"
	.string "I've seen your policy in action!$"

Route120_Text_LeonelIntro::
# 210 "data/maps/Route120/scripts.pory"
	.string "Your party POKéMON… Do you have\n"
	.string "different types?$"

Route120_Text_LeonelPostBattle::
# 214 "data/maps/Route120/scripts.pory"
	.string "I think it's awesome you're so strong\n"
	.string "battling with your favorite POKéMON.$"

Route120_Text_LorenzoDefeat::
# 218 "data/maps/Route120/scripts.pory"
	.string "With POKéMON that strong, you're in no\n"
	.string "danger of needing rescue!$"

Route120_Text_LorenzoIntro::
# 222 "data/maps/Route120/scripts.pory"
	.string "I'll check your POKéMON and see if\n"
	.string "they're fit for the outdoors.$"

Route120_Text_LorenzoPostBattle::
# 226 "data/maps/Route120/scripts.pory"
	.string "To travel wherever your heart desires\n"
	.string "with POKéMON… That's the joy of being a\l"
	.string "TRAINER.$"

Route120_Text_RileyDefeat::
# 230 "data/maps/Route120/scripts.pory"
	.string "I lost! I should camouflage my shame!$"

Route120_Text_RileyIntro::
# 234 "data/maps/Route120/scripts.pory"
	.string "We ninja conceal ourselves under our\n"
	.string "camouflage cloaks. I bet you didn't\l"
	.string "know where I was!$"

Route120_Text_RileyPostBattle::
# 238 "data/maps/Route120/scripts.pory"
	.string "Our camouflage cloaks are all handmade.$"

Route120_Text_RobertDefeat::
# 242 "data/maps/Route120/scripts.pory"
	.string "Your POKéMON were stronger…$"

Route120_Text_RobertIntro::
# 246 "data/maps/Route120/scripts.pory"
	.string "My POKéMON is strong! How about yours?$"

Route120_Text_RobertPostBattle::
# 250 "data/maps/Route120/scripts.pory"
	.string "A POKéMON that grows steadily is one\n"
	.string "you can count on.$"

Route120_Text_StevenReadyForBattle::
# 254 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, are your POKéMON\n"
	.string "ready for battle?$"

Route120_Text_StevenIllWaitHere::
# 258 "data/maps/Route120/scripts.pory"
	.string "STEVEN: No?\p"
	.string "I'll wait here, so you can get ready.$"

Kecleon_Text_SomethingUnseeable::
# 262 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.$"

Route120_Text_StevenGiveDevonScope::
# 266 "data/maps/Route120/scripts.pory"
	.string "STEVEN: I see…\n"
	.string "Your battle style is intriguing.\p"
	.string "Your POKéMON have obviously grown\n"
	.string "since I first met you in DEWFORD.\p"
	.string "I'd like you to have this\n"
	.string "DEVON SCOPE.\p"
	.string "Who knows, there may be other\n"
	.string "concealed POKéMON.$"

Route120_Text_StevenShowMeYourPower::
# 270 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, show me your true\n"
	.string "power as a TRAINER!$"
