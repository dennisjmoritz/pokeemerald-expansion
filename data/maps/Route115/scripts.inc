Route115_MapScripts::
	.byte 0


Route115_EventScript_Alix::
# 5 "data/maps/Route115/scripts.pory"
	trainerbattle_double TRAINER_ALIX, Route115_Text_AlixIntro, Route115_Text_AlixDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_AlixPostBattle
	return


Route115_EventScript_Cyndy::
# 10 "data/maps/Route115/scripts.pory"
	trainerbattle_double TRAINER_CYNDY, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_CyndyPostBattle
	return


Route115_EventScript_Hector::
# 15 "data/maps/Route115/scripts.pory"
	trainerbattle_double TRAINER_HECTOR, Route115_Text_HectorIntro, Route115_Text_HectorDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_HectorPostBattle
	return


Route115_EventScript_Helene::
# 20 "data/maps/Route115/scripts.pory"
	trainerbattle_double TRAINER_HELENE, Route115_Text_HeleneIntro, Route115_Text_HeleneDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_HelenePostBattle
	return


Route115_EventScript_Jaiden::
# 25 "data/maps/Route115/scripts.pory"
	trainerbattle_double TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_JaidenPostBattle
	return


Route115_EventScript_Koichi::
# 30 "data/maps/Route115/scripts.pory"
	trainerbattle_double TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_Text_KoichiDefeat, Text_NotEnoughMonsForDoubleBattle
# 31 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_KoichiPostBattle
	return


Route115_EventScript_Kyra::
# 35 "data/maps/Route115/scripts.pory"
	trainerbattle_double TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_KyraPostBattle
	return


Route115_EventScript_Marlene::
# 40 "data/maps/Route115/scripts.pory"
	trainerbattle_double TRAINER_MARLENE, Route115_Text_MarleneIntro, Route115_Text_MarleneDefeat, Text_NotEnoughMonsForDoubleBattle
# 41 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_MarlenePostBattle
	return


Route115_EventScript_MeteorFallsSign::
# 45 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
	end


Route115_EventScript_Nob::
# 50 "data/maps/Route115/scripts.pory"
	trainerbattle_double TRAINER_NOB, Route115_Text_NobIntro, Route115_Text_NobDefeat, Text_NotEnoughMonsForDoubleBattle
# 51 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_NobPostBattle
	return


Route115_EventScript_RouteSignRustboro::
# 55 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
	end


Route115_EventScript_Timothy::
# 60 "data/maps/Route115/scripts.pory"
	trainerbattle_double TRAINER_TIMOTHY, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat, Text_NotEnoughMonsForDoubleBattle
# 61 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_TimothyPostBattle
	return


Route115_EventScript_Woman::
# 65 "data/maps/Route115/scripts.pory"
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
	end


Route115_Text_RouteSignRustboro::
# 70 "data/maps/Route115/scripts.pory"
	.string "ROUTE 115 {DOWN_ARROW} RUSTBORO CITY$"

Route115_Text_MeteorFallsSign::
# 74 "data/maps/Route115/scripts.pory"
	.string "METEOR FALLS FALLARBOR TOWN THROUGH\n"
	.string "HERE$"

Route115_Text_AlixDefeat::
# 79 "data/maps/Route115/scripts.pory"
	.string "Gah! Not bad!$"

Route115_Text_AlixIntro::
# 83 "data/maps/Route115/scripts.pory"
	.string "Our eyes met! There's no getting away\n"
	.string "now!$"

Route115_Text_AlixPostBattle::
# 87 "data/maps/Route115/scripts.pory"
	.string "Oh, well. I think I will TELEPORT home.$"

Route115_Text_CyndyDefeat::
# 91 "data/maps/Route115/scripts.pory"
	.string "I haven't trained enough!$"

Route115_Text_CyndyIntro::
# 95 "data/maps/Route115/scripts.pory"
	.string "This beach is my secret training spot!\n"
	.string "Don't come butting in!$"

Route115_Text_CyndyPostBattle::
# 99 "data/maps/Route115/scripts.pory"
	.string "The sand acts as a cushion to reduce\n"
	.string "impact and prevent injury. This is the\l"
	.string "perfect place to train.$"

Route115_Text_HectorDefeat::
# 103 "data/maps/Route115/scripts.pory"
	.string "You… You want my POKéMON, don't you?$"

Route115_Text_HectorIntro::
# 107 "data/maps/Route115/scripts.pory"
	.string "I have a rare POKéMON! Would you like me\n"
	.string "to show you?$"

Route115_Text_HectorPostBattle::
# 111 "data/maps/Route115/scripts.pory"
	.string "I have this rare POKéMON. It's enough\n"
	.string "to keep me satisfied.$"

Route115_Text_HeleneDefeat::
# 115 "data/maps/Route115/scripts.pory"
	.string "This is too humiliating!$"

Route115_Text_HeleneIntro::
# 119 "data/maps/Route115/scripts.pory"
	.string "My POKéMON have black belt-level\n"
	.string "strength!$"

Route115_Text_HelenePostBattle::
# 123 "data/maps/Route115/scripts.pory"
	.string "I rarely meet anyone who's better than\n"
	.string "me…\p"
	.string "I get it now! You're a GYM LEADER, aren't\n"
	.string "you?$"

Route115_Text_JaidenDefeat::
# 127 "data/maps/Route115/scripts.pory"
	.string "Waaah! Our strategy failed!$"

Route115_Text_JaidenIntro::
# 131 "data/maps/Route115/scripts.pory"
	.string "Take that! Ultra POKéMON ninja attack!$"

Route115_Text_JaidenPostBattle::
# 135 "data/maps/Route115/scripts.pory"
	.string "But my POKéMON were ultra, weren't\n"
	.string "they?$"

Route115_Text_KoichiDefeat::
# 139 "data/maps/Route115/scripts.pory"
	.string "Ouch, ouch, ouch!$"

Route115_Text_KoichiIntro::
# 143 "data/maps/Route115/scripts.pory"
	.string "You!\p"
	.string "My MACHOP!\p"
	.string "Demand a battle!$"

Route115_Text_KoichiPostBattle::
# 147 "data/maps/Route115/scripts.pory"
	.string "My MACHOP crew!\p"
	.string "So long as they seek power, I will grow\n"
	.string "strong with them!$"

Route115_Text_KyraDefeat::
# 151 "data/maps/Route115/scripts.pory"
	.string "Gasp, gasp…$"

Route115_Text_KyraIntro::
# 155 "data/maps/Route115/scripts.pory"
	.string "I'll battle while I'm running! Try to\n"
	.string "keep up with me!$"

Route115_Text_KyraPostBattle::
# 159 "data/maps/Route115/scripts.pory"
	.string "I made the mistake of trying to battle\n"
	.string "while running!\p"
	.string "I should take a run to calm down…$"

Route115_Text_MarleneDefeat::
# 163 "data/maps/Route115/scripts.pory"
	.string "You've broken my concentration!$"

Route115_Text_MarleneIntro::
# 167 "data/maps/Route115/scripts.pory"
	.string "You've disturbed my meditation… You'll\n"
	.string "be punished for it.$"

Route115_Text_MarlenePostBattle::
# 171 "data/maps/Route115/scripts.pory"
	.string "I was meditating with my POKéMON. But\n"
	.string "this place isn't very peaceful…$"

Route115_Text_NobDefeat::
# 175 "data/maps/Route115/scripts.pory"
	.string "Ugwaaaah! My head is busted!$"

Route115_Text_NobIntro::
# 179 "data/maps/Route115/scripts.pory"
	.string "My strongest skill is busting bricks\n"
	.string "with my forehead!$"

Route115_Text_NobPostBattle::
# 183 "data/maps/Route115/scripts.pory"
	.string "I've been teaching my POKéMON karate.\p"
	.string "It looks like they'll get a lot better\n"
	.string "than me. I'm excited about that.$"

Route115_Text_TimothyDefeat::
# 187 "data/maps/Route115/scripts.pory"
	.string "You're much stronger than I'd imagined!$"

Route115_Text_TimothyIntro::
# 191 "data/maps/Route115/scripts.pory"
	.string "Hm… You seem rather capable… Let me\n"
	.string "keep you company!$"

Route115_Text_TimothyPostBattle::
# 195 "data/maps/Route115/scripts.pory"
	.string "There is no such thing as a born genius.\n"
	.string "It all depends on effort! That is what I\l"
	.string "believe…$"

Route115_Text_NeverKnowWhenCavePokemonWillAppear::
# 199 "data/maps/Route115/scripts.pory"
	.string "Exploring a cave isn't like walking\n"
	.string "on a road.\p"
	.string "You never know when wild POKéMON will\n"
	.string "appear. It's full of suspense.$"
