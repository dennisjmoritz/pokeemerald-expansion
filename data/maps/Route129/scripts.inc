Route129_MapScripts::
	.byte 0


Route129_EventScript_Allison::
# 5 "data/maps/Route129/scripts.pory"
	trainerbattle_double TRAINER_ALLISON, Route129_Text_AllisonIntro, Route129_Text_AllisonDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route129/scripts.pory"
	msgbox Route129_Text_AllisonPostBattle
	return


Route129_EventScript_Chase::
# 10 "data/maps/Route129/scripts.pory"
	trainerbattle_double TRAINER_CHASE, Route129_Text_ChaseIntro, Route129_Text_ChaseDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route129/scripts.pory"
	msgbox Route129_Text_ChasePostBattle
	return


Route129_EventScript_Clarence::
# 15 "data/maps/Route129/scripts.pory"
	trainerbattle_double TRAINER_CLARENCE, Route129_Text_ClarenceIntro, Route129_Text_ClarenceDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route129/scripts.pory"
	msgbox Route129_Text_ClarencePostBattle
	return


Route129_EventScript_Reed::
# 20 "data/maps/Route129/scripts.pory"
	trainerbattle_double TRAINER_REED, Route129_Text_ReedIntro, Route129_Text_ReedDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route129/scripts.pory"
	msgbox Route129_Text_ReedPostBattle
	return


Route129_EventScript_Tisha::
# 25 "data/maps/Route129/scripts.pory"
	trainerbattle_double TRAINER_TISHA, Route129_Text_TishaIntro, Route129_Text_TishaDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route129/scripts.pory"
	msgbox Route129_Text_TishaPostBattle
	return


Route129_Text_AllisonDefeat::
# 31 "data/maps/Route129/scripts.pory"
	.string "I was sure I'd win!$"

Route129_Text_AllisonIntro::
# 35 "data/maps/Route129/scripts.pory"
	.string "I'm in the middle of a triathlon, but,\n"
	.string "sure, why don't we battle?$"

Route129_Text_AllisonPostBattle::
# 39 "data/maps/Route129/scripts.pory"
	.string "Do you know what's the greatest thing\n"
	.string "about triathlons?\p"
	.string "Testing the limits of your own strength\n"
	.string "and endurance against Mother Nature!$"

Route129_Text_ChaseDefeat::
# 43 "data/maps/Route129/scripts.pory"
	.string "Wroooaaar! I failed to win!$"

Route129_Text_ChaseIntro::
# 47 "data/maps/Route129/scripts.pory"
	.string "This is my first triathlon. I'm all tense\n"
	.string "and nervous!$"

Route129_Text_ChasePostBattle::
# 51 "data/maps/Route129/scripts.pory"
	.string "If I'm all tensed up, I won't be able to\n"
	.string "give it my all.$"

Route129_Text_ClarenceDefeat::
# 55 "data/maps/Route129/scripts.pory"
	.string "Winning sure isn't easy.$"

Route129_Text_ClarenceIntro::
# 59 "data/maps/Route129/scripts.pory"
	.string "Surfing isn't as easy as it seems, isn't\n"
	.string "that right?$"

Route129_Text_ClarencePostBattle::
# 63 "data/maps/Route129/scripts.pory"
	.string "You have your sights on the POKéMON\n"
	.string "LEAGUE? Keep at it!$"

Route129_Text_ReedDefeat::
# 67 "data/maps/Route129/scripts.pory"
	.string "Beat, I'm beaten. That's it, done!$"

Route129_Text_ReedIntro::
# 71 "data/maps/Route129/scripts.pory"
	.string "Say hey, hey! Let's get on with it!$"

Route129_Text_ReedPostBattle::
# 75 "data/maps/Route129/scripts.pory"
	.string "There's nothing for a loser. Time for me\n"
	.string "to beat it home.$"

Route129_Text_TishaDefeat::
# 79 "data/maps/Route129/scripts.pory"
	.string "Oh, my. I wanted to relax a little more…$"

Route129_Text_TishaIntro::
# 83 "data/maps/Route129/scripts.pory"
	.string "What's the hurry? Let's take it slow and\n"
	.string "easy.$"

Route129_Text_TishaPostBattle::
# 87 "data/maps/Route129/scripts.pory"
	.string "Don't you hate making mistakes when\n"
	.string "you're in a rush?\p"
	.string "That's why I try to take things slowly.$"
