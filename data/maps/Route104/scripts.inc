Route104_MapScripts::
	.byte 0


Route104_EventScript_Billy::
# 5 "data/maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_BILLY, Route104_Text_BillyIntro, Route104_Text_BillyDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BillyPostBattle
	return


Route104_EventScript_Boy1::
# 10 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_ThrowBallAtWeakenedPokemon, MSGBOX_NPC
	end


Route104_EventScript_Boy2::
	end


Route104_EventScript_BrineysCottageSign::
# 19 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MrBrineysCottage, MSGBOX_SIGN
	end


Route104_EventScript_BugCatcher::
# 24 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WhatsItLikeAtBottomOfSea, MSGBOX_SIGN
	end


Route104_EventScript_Cindy::
# 29 "data/maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_CINDY, Route104_Text_CindyIntro, Route104_Text_CindyDefeat, Text_NotEnoughMonsForDoubleBattle
# 30 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_CindyPostBattle
	return


Route104_EventScript_Darian::
# 34 "data/maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_DARIAN, Route104_Text_DarianIntro, Route104_Text_DarianDefeat, Text_NotEnoughMonsForDoubleBattle
# 35 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_DarianPostBattle
	return


Route104_EventScript_ExpertF::
	end


Route104_EventScript_FlowerShopSign::
# 43 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
	end


Route104_EventScript_Gina::
# 48 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
	end


Route104_EventScript_Girl1::
# 53 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_BrineyLivesInSeasideCottage, MSGBOX_NPC
	end


Route104_EventScript_Girl2::
# 58 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_ImNotATrainer, MSGBOX_NPC
	end


Route104_EventScript_Haley::
# 63 "data/maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_HALEY, Route104_Text_HaleyIntro, Route104_Text_HaleyDefeat, Text_NotEnoughMonsForDoubleBattle
# 64 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_HaleyPostBattle
	return


Route104_EventScript_Ivan::
# 68 "data/maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_IVAN, Route104_Text_IvanIntro, Route104_Text_IvanDefeat, Text_NotEnoughMonsForDoubleBattle
# 69 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_IvanPostBattle
	return


Route104_EventScript_Mia::
# 73 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
	end


Route104_EventScript_Rival::
	end


Route104_EventScript_RivalTrigger::
	end


Route104_EventScript_RouteSignPetalburg::
# 86 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
	end


Route104_EventScript_RouteSignRustboro::
# 91 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
	end


Route104_EventScript_TrainerTipsDoubleBattles::
# 96 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
	end


Route104_EventScript_WhiteHerbFlorist::
	end


Route104_EventScript_Winston::
# 105 "data/maps/Route104/scripts.pory"
	trainerbattle_double TRAINER_WINSTON, Route104_Text_WinstonIntro, Route104_Text_WinstonDefeat, Text_NotEnoughMonsForDoubleBattle
# 106 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_WinstonPostBattle
	return


Route104_EventScript_Woman::
# 110 "data/maps/Route104/scripts.pory"
	msgbox Route104_Text_OnlyThrowBallAtWildPokemon, MSGBOX_NPC
	end


Route104_Text_TrainerTipsDoubleBattles::
# 115 "data/maps/Route104/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "In the HOENN region there are pairs of\n"
	.string "TRAINERS who challenge others\l"
	.string "for 2-on-2 POKéMON battles called\l"
	.string "DOUBLE BATTLES.\p"
	.string "In a DOUBLE BATTLE, the TRAINER must\n"
	.string "send out two POKéMON, the one at the\l"
	.string "left of the list and the top one.\l"
	.string "Watch how POKéMON are lined up.$"

Route104_Text_PrettyPetalFlowShop::
# 119 "data/maps/Route104/scripts.pory"
	.string "PRETTY PETAL FLOWER SHOP$"

Route104_Text_MrBrineysCottage::
# 123 "data/maps/Route104/scripts.pory"
	.string "MR. BRINEY'S COTTAGE$"

Route104_Text_RouteSignRustboro::
# 127 "data/maps/Route104/scripts.pory"
	.string "ROUTE 1O4 {UP_ARROW} RUSTBORO CITY$"

Route104_Text_RouteSignPetalburg::
# 131 "data/maps/Route104/scripts.pory"
	.string "ROUTE 1O4 {RIGHT_ARROW} PETALBURG CITY$"

Route104_Text_BillyDefeat::
# 136 "data/maps/Route104/scripts.pory"
	.string "Waah! I got sand in my runners! They're\n"
	.string "all gritty!$"

Route104_Text_BillyIntro::
# 140 "data/maps/Route104/scripts.pory"
	.string "Leaving footprints in the sand is so\n"
	.string "fun!$"

Route104_Text_BillyPostBattle::
# 144 "data/maps/Route104/scripts.pory"
	.string "I want to leave my footprints in the\n"
	.string "sand everywhere, but they disappear\l"
	.string "quickly…$"

Route104_Text_CindyDefeat::
# 148 "data/maps/Route104/scripts.pory"
	.string "Oh, my!$"

Route104_Text_CindyIntro::
# 152 "data/maps/Route104/scripts.pory"
	.string "We must have been fated to meet. May I\n"
	.string "ask you for a battle?$"

Route104_Text_CindyPostBattle::
# 156 "data/maps/Route104/scripts.pory"
	.string "“Hello” is the beginning of “good-bye.”\n"
	.string "I hope we meet again.$"

Route104_Text_DarianDefeat::
# 160 "data/maps/Route104/scripts.pory"
	.string "What the…$"

Route104_Text_DarianIntro::
# 164 "data/maps/Route104/scripts.pory"
	.string "I fished up a tough-looking POKéMON!\p"
	.string "It has this magical quality to it! It\n"
	.string "surely looks tough, yes it does!$"

Route104_Text_DarianPostBattle::
# 168 "data/maps/Route104/scripts.pory"
	.string "Hey, MAGIKARP, you sure don't live up to\n"
	.string "your name, do you?$"

Route104_Text_HaleyDefeat::
# 172 "data/maps/Route104/scripts.pory"
	.string "I shouldn't have battled…$"

Route104_Text_HaleyIntro::
# 176 "data/maps/Route104/scripts.pory"
	.string "Should I… Or shouldn't I?\p"
	.string "Okay, sure, I will battle!$"

Route104_Text_HaleyPostBattle::
# 180 "data/maps/Route104/scripts.pory"
	.string "If you're faced with a decision and you\n"
	.string "let someone else choose for you, you\l"
	.string "will regret it, however things turn out.$"

Route104_Text_IvanDefeat::
# 184 "data/maps/Route104/scripts.pory"
	.string "I thought I wasn't too bad, if I may say\n"
	.string "so, but I guess not… Bleah…$"

Route104_Text_IvanIntro::
# 188 "data/maps/Route104/scripts.pory"
	.string "Why keep it a secret? I'm the WATER\n"
	.string "POKéMON expert!\p"
	.string "Huh? You don't know me?$"

Route104_Text_IvanPostBattle::
# 192 "data/maps/Route104/scripts.pory"
	.string "I got too into fishing. I forgot I had\n"
	.string "to raise my POKéMON…$"

Route104_Text_WinstonDefeat::
# 196 "data/maps/Route104/scripts.pory"
	.string "Why couldn't I win?$"

Route104_Text_WinstonIntro::
# 200 "data/maps/Route104/scripts.pory"
	.string "Oh, sure, I'll accept your challenge. I\n"
	.string "have a lot of money.$"

Route104_Text_WinstonPostBattle::
# 204 "data/maps/Route104/scripts.pory"
	.string "There are some things money can't buy.\n"
	.string "That's POKéMON…$"

Route104_Text_BrendanPostBattle::
# 208 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: You've gotten pretty decent\n"
	.string "at handling POKéMON.\p"
	.string "But, you know, you shouldn't just be\n"
	.string "making POKéMON battle.\p"
	.string "Like MR. BRINEY, it's important to\n"
	.string "become friends with your POKéMON.$"

Route104_Text_OnlyThrowBallAtWildPokemon::
# 212 "data/maps/Route104/scripts.pory"
	.string "You're a thief if you try to steal\n"
	.string "someone else's POKéMON.\p"
	.string "You should throw POKé BALLS only at\n"
	.string "wild POKéMON.$"

Route104_Text_TMsAreOneTimeUse::
# 216 "data/maps/Route104/scripts.pory"
	.string "A word of advice!\p"
	.string "A TM, TECHNICAL MACHINE, is good only\n"
	.string "for one-time use.\p"
	.string "Once you use it, it's gone.\n"
	.string "Think twice before using it!$"

Route104_Text_FlowerShopSellingSaplings::
# 220 "data/maps/Route104/scripts.pory"
	.string "This FLOWER SHOP started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping. Where should I put them?$"

Route104_Text_ImNotATrainer::
# 224 "data/maps/Route104/scripts.pory"
	.string "Oh, no, I'm not a TRAINER.\p"
	.string "But that's right, if TRAINERS lock eyes,\n"
	.string "it's a challenge to battle.\p"
	.string "If you don't want to battle, stay out\n"
	.string "of their sight.$"

Route104_Text_BrendanLetsBattle::
# 228 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: What's up?\n"
	.string "Want to have a battle with me?$"

Route104_Text_MayLetsBattle::
# 232 "data/maps/Route104/scripts.pory"
	.string "MAY: So, what do you think?\n"
	.string "How about a little battle here?$"

Route104_Text_WhatsItLikeAtBottomOfSea::
# 236 "data/maps/Route104/scripts.pory"
	.string "The sea, huh?\p"
	.string "I wonder what it's like at the bottom\n"
	.string "of the sea?$"

Route104_Text_ThrowBallAtWeakenedPokemon::
# 240 "data/maps/Route104/scripts.pory"
	.string "If you're going to throw a POKé BALL,\n"
	.string "weaken the wild POKéMON first.\p"
	.string "It will be easier to catch if it's been\n"
	.string "poisoned, burned, or lulled to sleep.$"

Route104_Text_MayIntro::
# 244 "data/maps/Route104/scripts.pory"
	.string "MAY: You just became a TRAINER,\n"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"

Route104_Text_BrendanIntro::
# 248 "data/maps/Route104/scripts.pory"
	.string "BRENDAN: I know you just became\n"
	.string "a TRAINER, but I won't go easy!$"

Route104_Text_MayPostBattle::
# 252 "data/maps/Route104/scripts.pory"
	.string "MAY: I can tell you've gotten pretty\n"
	.string "good with the way you handle POKéMON.\p"
	.string "But instead of only making them\n"
	.string "battle, you should be like MR. BRINEY.\p"
	.string "It's important to become friends with\n"
	.string "POKéMON, too.$"

Route104_Text_BrineyLivesInSeasideCottage::
# 256 "data/maps/Route104/scripts.pory"
	.string "That seaside cottage is where\n"
	.string "MR. BRINEY lives.\p"
	.string "He was once a mighty sailor who never\n"
	.string "feared the sea, however stormy.$"

Route104_Text_GinaPostBattle::
# 260 "data/maps/Route104/scripts.pory"
	.string "GINA: You are strong!\n"
	.string "We have to train lots more!$"

Route104_Text_MiaPostBattle::
# 264 "data/maps/Route104/scripts.pory"
	.string "MIA: We will train our POKéMON more\n"
	.string "and be strong like you.$"
