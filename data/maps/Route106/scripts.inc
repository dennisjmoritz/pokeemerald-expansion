Route106_MapScripts::
	.byte 0


Route106_EventScript_Douglas::
# 5 "data/maps/Route106/scripts.pory"
	trainerbattle_double TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_DouglasPostBattle
	return


Route106_EventScript_Elliot::
# 10 "data/maps/Route106/scripts.pory"
	trainerbattle_double TRAINER_ELLIOT, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_ElliotPostBattle
	return


Route106_EventScript_Kyla::
# 15 "data/maps/Route106/scripts.pory"
	trainerbattle_double TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_KylaPostBattle
	return


Route106_EventScript_Ned::
# 20 "data/maps/Route106/scripts.pory"
	trainerbattle_double TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_NedPostBattle
	return


Route106_EventScript_TrainerTipsSign::
# 25 "data/maps/Route106/scripts.pory"
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end


Route106_Text_TrainerTips::
# 30 "data/maps/Route106/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

Route106_Text_DouglasDefeated::
# 35 "data/maps/Route106/scripts.pory"
	.string "I give up!$"

Route106_Text_DouglasIntro::
# 39 "data/maps/Route106/scripts.pory"
	.string "Hahahah! I'm a lousy runner, but in the\n"
	.string "water you can't catch me!$"

Route106_Text_DouglasPostBattle::
# 43 "data/maps/Route106/scripts.pory"
	.string "I wouldn't lose in a swim race…$"

Route106_Text_ElliotDefeated::
# 47 "data/maps/Route106/scripts.pory"
	.string "Like in deep-sea fishing, I lost\n"
	.string "spectacularly!$"

Route106_Text_ElliotIntro::
# 51 "data/maps/Route106/scripts.pory"
	.string "Which do you prefer, fishing in the sea\n"
	.string "or a stream?$"

Route106_Text_ElliotPostBattle::
# 55 "data/maps/Route106/scripts.pory"
	.string "Fishing is the greatest whether it's in\n"
	.string "the sea or a stream. You agree with me,\l"
	.string "right?$"

Route106_Text_KylaDefeated::
# 59 "data/maps/Route106/scripts.pory"
	.string "Did you take it easy on me by any\n"
	.string "chance?$"

Route106_Text_KylaIntro::
# 63 "data/maps/Route106/scripts.pory"
	.string "The sea is my backyard. I'm not going to\n"
	.string "take it easy because you're a kid!$"

Route106_Text_KylaPostBattle::
# 67 "data/maps/Route106/scripts.pory"
	.string "Drifting along with the waves… I love\n"
	.string "it! Why don't you give it a try?$"

Route106_Text_NedDefeated::
# 71 "data/maps/Route106/scripts.pory"
	.string "I lost because I'm trying to not go to\n"
	.string "the washroom…$"

Route106_Text_NedIntro::
# 75 "data/maps/Route106/scripts.pory"
	.string "What do people do if they need to go to\n"
	.string "a washroom?\p"
	.string "What if my ROD hooks a big one while I'm\n"
	.string "in the washroom? I just can't go…$"

Route106_Text_NedPostBattle::
# 79 "data/maps/Route106/scripts.pory"
	.string "Oh, no! I've got this feeling I'll hook a\n"
	.string "big one!$"
