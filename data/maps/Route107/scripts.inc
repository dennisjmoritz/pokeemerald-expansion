Route107_MapScripts::
	.byte 0


Route107_EventScript_Beth::
# 5 "data/maps/Route107/scripts.pory"
	trainerbattle_double TRAINER_BETH, Route107_Text_BethIntro, Route107_Text_BethDefeated, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_BethPostBattle
	return


Route107_EventScript_Camron::
# 10 "data/maps/Route107/scripts.pory"
	trainerbattle_double TRAINER_CAMRON, Route107_Text_CamronIntro, Route107_Text_CamronDefeated, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_CamronPostBattle
	return


Route107_EventScript_Darrin::
# 15 "data/maps/Route107/scripts.pory"
	trainerbattle_double TRAINER_DARRIN, Route107_Text_DarrinIntro, Route107_Text_DarrinDefeated, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_DarrinPostBattle
	return


Route107_EventScript_Denise::
# 20 "data/maps/Route107/scripts.pory"
	trainerbattle_double TRAINER_DENISE, Route107_Text_DeniseIntro, Route107_Text_DeniseDefeated, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_DenisePostBattle
	return


Route107_EventScript_Lisa::
# 25 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end


Route107_EventScript_Ray::
# 30 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end


Route107_EventScript_Tony::
# 35 "data/maps/Route107/scripts.pory"
	trainerbattle_double TRAINER_TONY, Route107_Text_TonyIntro, Route107_Text_TonyDefeated, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route107/scripts.pory"
	msgbox Route107_Text_TonyPostBattle
	return


Route107_Text_BethDefeated::
# 41 "data/maps/Route107/scripts.pory"
	.string "I wasn't good enough for you.$"

Route107_Text_BethIntro::
# 45 "data/maps/Route107/scripts.pory"
	.string "Did you want to battle me? Sure, I'll go\n"
	.string "with you!$"

Route107_Text_BethPostBattle::
# 49 "data/maps/Route107/scripts.pory"
	.string "I think you're going to keep getting\n"
	.string "better. I'll go for it, too!$"

Route107_Text_CamronDefeated::
# 53 "data/maps/Route107/scripts.pory"
	.string "That exhausted me…$"

Route107_Text_CamronIntro::
# 57 "data/maps/Route107/scripts.pory"
	.string "I'm in the middle of a triathlon, but I'm\n"
	.string "nowhere near tired!$"

Route107_Text_CamronPostBattle::
# 61 "data/maps/Route107/scripts.pory"
	.string "I still have swimming and running left\n"
	.string "to do after this.\p"
	.string "Am I going to be okay?$"

Route107_Text_DarrinDefeated::
# 65 "data/maps/Route107/scripts.pory"
	.string "Ahaha, I lost… I'll take a snooze, I\n"
	.string "think…$"

Route107_Text_DarrinIntro::
# 69 "data/maps/Route107/scripts.pory"
	.string "Yawn…\p"
	.string "I must have drifted off to sleep while I\n"
	.string "was drifting in the waves.$"

Route107_Text_DarrinPostBattle::
# 73 "data/maps/Route107/scripts.pory"
	.string "Floating and being rocked by the\n"
	.string "waves--it's like sleeping in a plush,\l"
	.string "comfy bed.$"

Route107_Text_DeniseDefeated::
# 77 "data/maps/Route107/scripts.pory"
	.string "I hate this!$"

Route107_Text_DeniseIntro::
# 81 "data/maps/Route107/scripts.pory"
	.string "Do you know a little town called\n"
	.string "DEWFORD?$"

Route107_Text_DenisePostBattle::
# 85 "data/maps/Route107/scripts.pory"
	.string "A weird saying is getting really trendy\n"
	.string "at DEWFORD HALL.$"

Route107_Text_TonyDefeated::
# 89 "data/maps/Route107/scripts.pory"
	.string "I lost on my home field… I'm in shock!$"

Route107_Text_TonyIntro::
# 93 "data/maps/Route107/scripts.pory"
	.string "The sea is like my backyard. Let's\n"
	.string "battle!$"

Route107_Text_TonyPostBattle::
# 97 "data/maps/Route107/scripts.pory"
	.string "I swim the seas with a heart full of\n"
	.string "dreams…\p"
	.string "It's a song! Anyways, I'm swimming some\n"
	.string "more.$"

Route107_Text_LisaPostBattle::
# 100 "data/maps/Route107/scripts.pory"
	.string "LISA: Do you have any friends who would\n"
	.string "go to the beach with you?$"

Route107_Text_RayPostBattle::
# 104 "data/maps/Route107/scripts.pory"
	.string "RAY: My sister gave me my POKéMON. I\n"
	.string "raised it, and now it's my important\l"
	.string "partner!$"
