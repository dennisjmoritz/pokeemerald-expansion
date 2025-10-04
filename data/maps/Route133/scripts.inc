Route133_MapScripts::
	.byte 0


Route133_EventScript_Beck::
# 5 "data/maps/Route133/scripts.pory"
	trainerbattle_double TRAINER_BECK, Route133_Text_BeckIntro, Route133_Text_BeckDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_BeckPostBattle
	return


Route133_EventScript_Conor::
# 10 "data/maps/Route133/scripts.pory"
	trainerbattle_double TRAINER_CONOR, Route133_Text_ConorIntro, Route133_Text_ConorDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_ConorPostBattle
	return


Route133_EventScript_Debra::
# 15 "data/maps/Route133/scripts.pory"
	trainerbattle_double TRAINER_DEBRA, Route133_Text_DebraIntro, Route133_Text_DebraDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_DebraPostBattle
	return


Route133_EventScript_Franklin::
# 20 "data/maps/Route133/scripts.pory"
	trainerbattle_double TRAINER_FRANKLIN, Route133_Text_FranklinIntro, Route133_Text_FranklinDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_FranklinPostBattle
	return


Route133_EventScript_Linda::
# 25 "data/maps/Route133/scripts.pory"
	trainerbattle_double TRAINER_LINDA, Route133_Text_LindaIntro, Route133_Text_LindaDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_LindaPostBattle
	return


Route133_EventScript_Mollie::
# 30 "data/maps/Route133/scripts.pory"
	trainerbattle_double TRAINER_MOLLIE, Route133_Text_MollieIntro, Route133_Text_MollieDefeat, Text_NotEnoughMonsForDoubleBattle
# 31 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_MolliePostBattle
	return


Route133_EventScript_Warren::
# 35 "data/maps/Route133/scripts.pory"
	trainerbattle_double TRAINER_WARREN, Route133_Text_WarrenIntro, Route133_Text_WarrenDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route133/scripts.pory"
	msgbox Route133_Text_WarrenPostBattle
	return


Route133_Text_BeckDefeat::
# 41 "data/maps/Route133/scripts.pory"
	.string "You… You're stunningly cool!$"

Route133_Text_BeckIntro::
# 45 "data/maps/Route133/scripts.pory"
	.string "I came all the way out here with my BIRD\n"
	.string "POKéMON.$"

Route133_Text_BeckPostBattle::
# 49 "data/maps/Route133/scripts.pory"
	.string "I'd like to go back to FORTREE, but I've\n"
	.string "grown to like this place, too.$"

Route133_Text_ConorDefeat::
# 53 "data/maps/Route133/scripts.pory"
	.string "You have a firm sense of purpose.$"

Route133_Text_ConorIntro::
# 57 "data/maps/Route133/scripts.pory"
	.string "Young people are too happy to go with\n"
	.string "the flow. They're without direction.$"

Route133_Text_ConorPostBattle::
# 61 "data/maps/Route133/scripts.pory"
	.string "Don't let others lead you astray. Don't\n"
	.string "lose direction as you grow older.$"

Route133_Text_DebraDefeat::
# 65 "data/maps/Route133/scripts.pory"
	.string "Another loss…$"

Route133_Text_DebraIntro::
# 69 "data/maps/Route133/scripts.pory"
	.string "I've led a life of woe and misery… I've\n"
	.string "been cast away, and this is where I've\l"
	.string "drifted…$"

Route133_Text_DebraPostBattle::
# 73 "data/maps/Route133/scripts.pory"
	.string "A life adrift… I don't want it anymore!$"

Route133_Text_FranklinDefeat::
# 77 "data/maps/Route133/scripts.pory"
	.string "Strong! Too much so!$"

Route133_Text_FranklinIntro::
# 81 "data/maps/Route133/scripts.pory"
	.string "Did the currents carry you here, too?\n"
	.string "This must have been fated. Let's\l"
	.string "battle!$"

Route133_Text_FranklinPostBattle::
# 85 "data/maps/Route133/scripts.pory"
	.string "It's just my luck that a tough TRAINER\n"
	.string "like you would drift here… I must be\l"
	.string "cursed…$"

Route133_Text_LindaDefeat::
# 89 "data/maps/Route133/scripts.pory"
	.string "No! Please!$"

Route133_Text_LindaIntro::
# 93 "data/maps/Route133/scripts.pory"
	.string "Welcome! I've been expecting you!$"

Route133_Text_LindaPostBattle::
# 97 "data/maps/Route133/scripts.pory"
	.string "A strong child TRAINER… That's so\n"
	.string "annoying!$"

Route133_Text_MollieDefeat::
# 101 "data/maps/Route133/scripts.pory"
	.string "I may have lost thousands of times, but\n"
	.string "a loss still stings.$"

Route133_Text_MollieIntro::
# 105 "data/maps/Route133/scripts.pory"
	.string "I must have battled thousands of\n"
	.string "times. I've lost count.$"

Route133_Text_MolliePostBattle::
# 109 "data/maps/Route133/scripts.pory"
	.string "Keep at this, youngster. So you can\n"
	.string "become like my husband and me.$"

Route133_Text_WarrenDefeat::
# 113 "data/maps/Route133/scripts.pory"
	.string "Darn it! My way is still too slack!$"

Route133_Text_WarrenIntro::
# 117 "data/maps/Route133/scripts.pory"
	.string "I want to win like everyone else, but I\n"
	.string "won't raise POKéMON like everyone else.$"

Route133_Text_WarrenPostBattle::
# 121 "data/maps/Route133/scripts.pory"
	.string "It's way more fun to do things the way I\n"
	.string "want than to be like everybody else. I\l"
	.string "mean, that's obvious!$"
