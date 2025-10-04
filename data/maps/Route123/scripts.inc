Route123_MapScripts::
	.byte 0


Route123_EventScript_Alberto::
# 5 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_ALBERTO, Route123_Text_AlbertoIntro, Route123_Text_AlbertoDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_AlbertoPostBattle
	return


Route123_EventScript_BerryMastersHouseSign::
# 10 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_BerryMastersHouse, MSGBOX_SIGN
	end


Route123_EventScript_Braxton::
# 15 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_BRAXTON, Route123_Text_BraxtonIntro, Route123_Text_BraxtonDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_BraxtonPostBattle
	return


Route123_EventScript_Cameron::
# 20 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_CAMERON, Route123_Text_CameronIntro, Route123_Text_CameronDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostBattle
	return


Route123_EventScript_Davis::
# 25 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_DAVIS, Route123_Text_DavisIntro, Route123_Text_DavisDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_DavisPostBattle
	return


Route123_EventScript_Ed::
# 30 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_ED, Route123_Text_EdIntro, Route123_Text_EdDefeat, Text_NotEnoughMonsForDoubleBattle
# 31 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_EdPostBattle
	return


Route123_EventScript_Fernando::
# 35 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_FERNANDO, Route123_Text_FernandoIntro, Route123_Text_FernandoDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostBattle
	return


Route123_EventScript_Frederick::
# 40 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_FREDRICK, Route123_Text_FrederickIntro, Route123_Text_FrederickDefeat, Text_NotEnoughMonsForDoubleBattle
# 41 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FrederickPostBattle
	return


Route123_EventScript_GigaDrainGirl::
	end


Route123_EventScript_Jacki::
# 49 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_JACKI, Route123_Text_JackiIntro, Route123_Text_JackiDefeat, Text_NotEnoughMonsForDoubleBattle
# 50 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostBattle
	return


Route123_EventScript_Jazmyn::
# 54 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_JAZMYN, Route123_Text_JazmynIntro, Route123_Text_JazmynDefeat, Text_NotEnoughMonsForDoubleBattle
# 55 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JazmynPostBattle
	return


Route123_EventScript_Jonas::
# 59 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_JONAS, Route123_Text_JonasIntro, Route123_Text_JonasDefeat, Text_NotEnoughMonsForDoubleBattle
# 60 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JonasPostBattle
	return


Route123_EventScript_Kayley::
# 64 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_KAYLEY, Route123_Text_KayleyIntro, Route123_Text_KayleyDefeat, Text_NotEnoughMonsForDoubleBattle
# 65 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_KayleyPostBattle
	return


Route123_EventScript_Kindra::
# 69 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_KINDRA, Route123_Text_KindraIntro, Route123_Text_KindraDefeat, Text_NotEnoughMonsForDoubleBattle
# 70 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_KindraPostBattle
	return


Route123_EventScript_Miu::
# 74 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
	end


Route123_EventScript_RouteSign::
# 79 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSign, MSGBOX_SIGN
	end


Route123_EventScript_RouteSignMtPyre::
# 84 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSignMtPyre, MSGBOX_SIGN
	end


Route123_EventScript_Violet::
# 89 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_VIOLET, Route123_Text_VioletIntro, Route123_Text_VioletDefeat, Text_NotEnoughMonsForDoubleBattle
# 90 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_VioletPostBattle
	return


Route123_EventScript_Wendy::
# 94 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_WENDY, Route123_Text_WendyIntro, Route123_Text_WendyDefeat, Text_NotEnoughMonsForDoubleBattle
# 95 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_WendyPostBattle
	return


Route123_EventScript_Yuki::
# 99 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
	end


Route123_Text_RouteSign::
# 104 "data/maps/Route123/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 123 {LEFT_ARROW} ROUTE 118$"

Route123_Text_RouteSignMtPyre::
# 108 "data/maps/Route123/scripts.pory"
	.string "{UP_ARROW} MT. PYRE “Forbidden to the faint of\n"
	.string "heart.”$"

Route123_Text_BerryMastersHouse::
# 112 "data/maps/Route123/scripts.pory"
	.string "BERRY MASTER'S HOUSE$"

Route123_Text_AlbertoDefeat::
# 117 "data/maps/Route123/scripts.pory"
	.string "Even in defeat, BIRD POKéMON are cool!$"

Route123_Text_AlbertoIntro::
# 121 "data/maps/Route123/scripts.pory"
	.string "I have to tell you, BIRD POKéMON are my\n"
	.string "obsession!\p"
	.string "Birds are cool! They're the best!$"

Route123_Text_AlbertoPostBattle::
# 125 "data/maps/Route123/scripts.pory"
	.string "I gather BIRD POKéMON feathers that\n"
	.string "scatter during battles.\p"
	.string "I'm going to make a hat with BIRD\n"
	.string "POKéMON feathers.$"

Route123_Text_BraxtonDefeat::
# 129 "data/maps/Route123/scripts.pory"
	.string "Oh, you're worthy, all right!$"

Route123_Text_BraxtonIntro::
# 133 "data/maps/Route123/scripts.pory"
	.string "You seem to have a big collection of GYM\n"
	.string "BADGES.\p"
	.string "Let me see if you're actually worthy of\n"
	.string "those BADGES!$"

Route123_Text_BraxtonPostBattle::
# 137 "data/maps/Route123/scripts.pory"
	.string "You did your BADGES proud in that\n"
	.string "match!$"

Route123_Text_CameronDefeat::
# 141 "data/maps/Route123/scripts.pory"
	.string "I feel sad…$"

Route123_Text_CameronIntro::
# 145 "data/maps/Route123/scripts.pory"
	.string "Being a psychic is about willpower.\p"
	.string "I've willed myself not to lose to\n"
	.string "anyone. That makes me strong!$"

Route123_Text_CameronPostBattle::
# 149 "data/maps/Route123/scripts.pory"
	.string "Being a psychic is about willpower. I\n"
	.string "thought I wouldn't lose to you…$"

Route123_Text_DavisDefeat::
# 153 "data/maps/Route123/scripts.pory"
	.string "Waaaah! You meanie!$"

Route123_Text_DavisIntro::
# 157 "data/maps/Route123/scripts.pory"
	.string "This is my awesome BUG POKéMON! My big\n"
	.string "brother got it for me.$"

Route123_Text_DavisPostBattle::
# 161 "data/maps/Route123/scripts.pory"
	.string "Don't tell my brother I lost. You have to\n"
	.string "keep it a secret!$"

Route123_Text_EdDefeat::
# 165 "data/maps/Route123/scripts.pory"
	.string "I kind of like your POKéMON.$"

Route123_Text_EdIntro::
# 169 "data/maps/Route123/scripts.pory"
	.string "When there are no TRAINERS around, I\n"
	.string "let my POKéMON battle each other. I\l"
	.string "watch them.$"

Route123_Text_EdPostBattle::
# 173 "data/maps/Route123/scripts.pory"
	.string "Hehe, I'm swiping your battling ideas! I\n"
	.string "think they'll make me better.$"

Route123_Text_FernandoDefeat::
# 177 "data/maps/Route123/scripts.pory"
	.string "Hey, hold it! I was still playing the\n"
	.string "intro!$"

Route123_Text_FernandoIntro::
# 181 "data/maps/Route123/scripts.pory"
	.string "I'll turn your lights out while I rip\n"
	.string "through this tune!$"

Route123_Text_FernandoPostBattle::
# 185 "data/maps/Route123/scripts.pory"
	.string "You're rock steady. I'd like to write a\n"
	.string "tune about you.$"

Route123_Text_FrederickDefeat::
# 189 "data/maps/Route123/scripts.pory"
	.string "Ah, a mighty capable child! Let me\n"
	.string "contribute to your allowance.$"

Route123_Text_FrederickIntro::
# 193 "data/maps/Route123/scripts.pory"
	.string "Hello, child! Can you spare some time?$"

Route123_Text_FrederickPostBattle::
# 197 "data/maps/Route123/scripts.pory"
	.string "Contribute to your allowance? Wasn't\n"
	.string "the prize money enough?$"

Route123_Text_JackiDefeat::
# 201 "data/maps/Route123/scripts.pory"
	.string "Overwhelmed!$"

Route123_Text_JackiIntro::
# 205 "data/maps/Route123/scripts.pory"
	.string "Don't be too happy if your POKéMON\n"
	.string "develop psychic powers.\p"
	.string "You need to refine those powers to\n"
	.string "make them really useful.$"

Route123_Text_JackiPostBattle::
# 209 "data/maps/Route123/scripts.pory"
	.string "We all have psychic powers. We've just\n"
	.string "forgotten how to use them.$"

Route123_Text_JazmynDefeat::
# 213 "data/maps/Route123/scripts.pory"
	.string "There goes my confidence…$"

Route123_Text_JazmynIntro::
# 217 "data/maps/Route123/scripts.pory"
	.string "My confidence will get a boost by\n"
	.string "beating someone obviously strong!$"

Route123_Text_JazmynPostBattle::
# 221 "data/maps/Route123/scripts.pory"
	.string "They say that you can't judge a person\n"
	.string "by their appearance.\p"
	.string "But often, their looks don't lie…$"

Route123_Text_JonasDefeat::
# 225 "data/maps/Route123/scripts.pory"
	.string "If you don't lose, how am I supposed to\n"
	.string "have fun playing ninja?$"

Route123_Text_JonasIntro::
# 229 "data/maps/Route123/scripts.pory"
	.string "I lay in ambush, and a TRAINER has\n"
	.string "landed in my trap!$"

Route123_Text_JonasPostBattle::
# 233 "data/maps/Route123/scripts.pory"
	.string "I'm going to ambush a weaker-looking\n"
	.string "TRAINER next time.$"

Route123_Text_KayleyDefeat::
# 237 "data/maps/Route123/scripts.pory"
	.string "You're better than me by about five\n"
	.string "times!$"

Route123_Text_KayleyIntro::
# 241 "data/maps/Route123/scripts.pory"
	.string "I just bought this parasol. My cuteness\n"
	.string "should be up by a third!$"

Route123_Text_KayleyPostBattle::
# 245 "data/maps/Route123/scripts.pory"
	.string "Using accessories effectively is the\n"
	.string "secret behind fashion appeal.$"

Route123_Text_KindraDefeat::
# 249 "data/maps/Route123/scripts.pory"
	.string "Overflowing with vitality…$"

Route123_Text_KindraIntro::
# 253 "data/maps/Route123/scripts.pory"
	.string "MT. PYRE… Where the spirits of POKéMON\n"
	.string "sleep… Will your POKéMON sleep?$"

Route123_Text_KindraPostBattle::
# 257 "data/maps/Route123/scripts.pory"
	.string "MT. PYRE… Where the spirits of POKéMON\n"
	.string "sleep…\p"
	.string "It must overflow with a power that\n"
	.string "soothes spirits…$"

Route123_Text_VioletDefeat::
# 261 "data/maps/Route123/scripts.pory"
	.string "Oh… I smell the bitter scent of misery…$"

Route123_Text_VioletIntro::
# 265 "data/maps/Route123/scripts.pory"
	.string "They say that good times are filled with\n"
	.string "good aromas.$"

Route123_Text_VioletPostBattle::
# 269 "data/maps/Route123/scripts.pory"
	.string "The BERRY MASTER's garden is filled with\n"
	.string "uplifting fragrances.$"

Route123_Text_WendyDefeat::
# 273 "data/maps/Route123/scripts.pory"
	.string "You passed with flying colors!$"

Route123_Text_WendyIntro::
# 277 "data/maps/Route123/scripts.pory"
	.string "Want to determine how strong you are?\n"
	.string "I'll be the test!$"

Route123_Text_WendyPostBattle::
# 281 "data/maps/Route123/scripts.pory"
	.string "To best even me… Your strength is\n"
	.string "marvelous!$"

Route123_Text_CheckTreesWithMyGrassMon::
# 285 "data/maps/Route123/scripts.pory"
	.string "I check trees with my GRASS-type\n"
	.string "POKéMON. I'm like a tree doctor.$"

Route123_Text_MiuPostBattle::
# 289 "data/maps/Route123/scripts.pory"
	.string "MIU: TRAINER, your POKéMON are strong\n"
	.string "because you are friends.$"

Route123_Text_YukiPostBattle::
# 293 "data/maps/Route123/scripts.pory"
	.string "YUKI: Why are you so strong? We've\n"
	.string "never lost before.$"
