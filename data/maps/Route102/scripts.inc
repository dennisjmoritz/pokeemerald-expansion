Route102_MapScripts::
	.byte 0


Route102_EventScript_Allen::
# 5 "data/maps/Route102/scripts.pory"
	trainerbattle_double TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_AllenPostBattle
	return


Route102_EventScript_Boy::
# 10 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end


Route102_EventScript_Calvin::
# 15 "data/maps/Route102/scripts.pory"
	trainerbattle_double TRAINER_CALVIN, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_CalvinPostBattle
	return


Route102_EventScript_LittleBoy::
# 20 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end


Route102_EventScript_Rick::
# 25 "data/maps/Route102/scripts.pory"
	trainerbattle_double TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RickPostBattle
	return


Route102_EventScript_RouteSignOldale::
# 30 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end


Route102_EventScript_RouteSignPetalburg::
# 35 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end


Route102_EventScript_Tiana::
# 40 "data/maps/Route102/scripts.pory"
	trainerbattle_double TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated, Text_NotEnoughMonsForDoubleBattle
# 41 "data/maps/Route102/scripts.pory"
	msgbox Route102_Text_TianaPostBattle
	return


Route102_Text_RouteSignPetalburg::
# 45 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102 {LEFT_ARROW} PETALBURG CITY$"

Route102_Text_RouteSignOldale::
# 49 "data/maps/Route102/scripts.pory"
	.string "ROUTE 102 {RIGHT_ARROW} OLDALE TOWN$"

Route102_Text_AllenDefeated::
# 54 "data/maps/Route102/scripts.pory"
	.string "I called you because I thought I could\n"
	.string "beat you…$"

Route102_Text_AllenIntro::
# 58 "data/maps/Route102/scripts.pory"
	.string "Did you just become a TRAINER? We're\n"
	.string "both beginners!$"

Route102_Text_AllenPostBattle::
# 62 "data/maps/Route102/scripts.pory"
	.string "I haven't won once yet… I wish I would\n"
	.string "win soon…$"

Route102_Text_CalvinDefeated::
# 66 "data/maps/Route102/scripts.pory"
	.string "Arrgh, I lost… I should have trained\n"
	.string "mine more…$"

Route102_Text_CalvinIntro::
# 70 "data/maps/Route102/scripts.pory"
	.string "If you have POKéMON with you, then\n"
	.string "you're an official POKéMON TRAINER! You\l"
	.string "can't say no to my challenge!$"

Route102_Text_CalvinPostBattle::
# 74 "data/maps/Route102/scripts.pory"
	.string "Listen, you. If you're strong, you\n"
	.string "should have told me before!$"

Route102_Text_RickDefeated::
# 78 "data/maps/Route102/scripts.pory"
	.string "Ow! Down and out!$"

Route102_Text_RickIntro::
# 82 "data/maps/Route102/scripts.pory"
	.string "Hahah! Our eyes met! I'll take you on\n"
	.string "with my BUG POKéMON!$"

Route102_Text_RickPostBattle::
# 86 "data/maps/Route102/scripts.pory"
	.string "If you lock eyes with a TRAINER, you\n"
	.string "have to challenge! It's a rule!$"

Route102_Text_TianaDefeated::
# 90 "data/maps/Route102/scripts.pory"
	.string "I ended up furthering your career…$"

Route102_Text_TianaIntro::
# 94 "data/maps/Route102/scripts.pory"
	.string "I'm going to keep winning and aim to be\n"
	.string "the best TRAINER.\p"
	.string "Help me further my career!$"

Route102_Text_TianaPostBattle::
# 98 "data/maps/Route102/scripts.pory"
	.string "To keep winning my way up, I see that I\n"
	.string "have to catch more POKéMON.$"

Route102_Text_ImNotVeryTall::
# 102 "data/maps/Route102/scripts.pory"
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon::
# 106 "data/maps/Route102/scripts.pory"
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"
