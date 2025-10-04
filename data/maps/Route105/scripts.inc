Route105_MapScripts::
	.byte 0


Route105_EventScript_Andres::
# 5 "data/maps/Route105/scripts.pory"
	trainerbattle_double TRAINER_ANDRES, Route105_Text_AndresIntro, Route105_Text_AndresDefeated, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_AndresPostBattle
	return


Route105_EventScript_Beverly::
# 10 "data/maps/Route105/scripts.pory"
	trainerbattle_double TRAINER_BEVERLY, Route105_Text_BeverlyIntro, Route105_Text_BeverlyDefeated, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_PostBattle
	return


Route105_EventScript_Dominik::
# 15 "data/maps/Route105/scripts.pory"
	trainerbattle_double TRAINER_DOMINIK, Route105_Text_DominikIntro, Route105_Text_DominikDefeated, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_DominikPostBattle
	return


Route105_EventScript_Foster::
# 20 "data/maps/Route105/scripts.pory"
	trainerbattle_double TRAINER_FOSTER, Route105_Text_FosterIntro, Route105_Text_FosterDefeated, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_FosterPostBattle
	return


Route105_EventScript_Imani::
# 25 "data/maps/Route105/scripts.pory"
	trainerbattle_double TRAINER_IMANI, Route105_Text_ImaniIntro, Route105_Text_ImaniDefeated, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_ImaniPostBattle
	return


Route105_EventScript_Josue::
# 30 "data/maps/Route105/scripts.pory"
	trainerbattle_double TRAINER_JOSUE, Route105_Text_JosueIntro, Route105_Text_JosueDefeated, Text_NotEnoughMonsForDoubleBattle
# 31 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_JosuePostBattle
	return


Route105_EventScript_Luis::
# 35 "data/maps/Route105/scripts.pory"
	trainerbattle_double TRAINER_LUIS, Route105_Text_LuisIntro, Route105_Text_LuisDefeated, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route105/scripts.pory"
	msgbox Route105_Text_LuisPostBattle
	return


Route105_Text_AndresDefeated::
# 41 "data/maps/Route105/scripts.pory"
	.string "Yes… I am no good at battling…$"

Route105_Text_AndresIntro::
# 45 "data/maps/Route105/scripts.pory"
	.string "I'm convinced that the sea keeps\n"
	.string "secrets from us.$"

Route105_Text_AndresPostBattle::
# 49 "data/maps/Route105/scripts.pory"
	.string "I'm sure there are many secrets to be\n"
	.string "discovered in the world's seas.\p"
	.string "I mean to find them all!$"

Route105_Text_BeverlyDefeated::
# 53 "data/maps/Route105/scripts.pory"
	.string "I'm floating…$"

Route105_Text_BeverlyIntro::
# 57 "data/maps/Route105/scripts.pory"
	.string "My body feels lighter in the water. It's\n"
	.string "as if I've gotten slimmer!$"

Route105_Text_DominikDefeated::
# 61 "data/maps/Route105/scripts.pory"
	.string "I lost… Now I'm feeling blue…$"

Route105_Text_DominikIntro::
# 65 "data/maps/Route105/scripts.pory"
	.string "Swimming the deep blue sea… It feels\n"
	.string "the greatest!$"

Route105_Text_DominikPostBattle::
# 69 "data/maps/Route105/scripts.pory"
	.string "Why is the sea blue?\p"
	.string "I learned about that at the MUSEUM in\n"
	.string "SLATEPORT, but I forgot.$"

Route105_Text_FosterDefeated::
# 73 "data/maps/Route105/scripts.pory"
	.string "I was thinking too much about that\n"
	.string "rock, while my POKéMON remained weak…$"

Route105_Text_FosterIntro::
# 77 "data/maps/Route105/scripts.pory"
	.string "There's supposed to be a mystical rock\n"
	.string "around here. Do you know anything\l"
	.string "about it?$"

Route105_Text_FosterPostBattle::
# 81 "data/maps/Route105/scripts.pory"
	.string "I can spend hours and hours staring at\n"
	.string "a nice rock without growing bored.$"

Route105_Text_ImaniDefeated::
# 85 "data/maps/Route105/scripts.pory"
	.string "I lost while I was lounging!$"

Route105_Text_ImaniIntro::
# 89 "data/maps/Route105/scripts.pory"
	.string "The blue, blue sky… The vast sea… It's\n"
	.string "so peaceful…$"

Route105_Text_ImaniPostBattle::
# 93 "data/maps/Route105/scripts.pory"
	.string "I want to be told I'm relaxing to be\n"
	.string "with. Giggle.$"

Route105_Text_JosueDefeated::
# 97 "data/maps/Route105/scripts.pory"
	.string "I lost because I battled at sea.$"

Route105_Text_JosueIntro::
# 101 "data/maps/Route105/scripts.pory"
	.string "I'm exhausted from swimming. I'm just\n"
	.string "not used to it.\p"
	.string "I need a battle for a change of pace!$"

Route105_Text_JosuePostBattle::
# 105 "data/maps/Route105/scripts.pory"
	.string "Yeah, for me, the sky is a much better\n"
	.string "match than the sea.$"

Route105_Text_LuisDefeated::
# 109 "data/maps/Route105/scripts.pory"
	.string "Glub… Glub…$"

Route105_Text_LuisIntro::
# 113 "data/maps/Route105/scripts.pory"
	.string "Whew! I was worried that a kid was\n"
	.string "drowning when I saw you.\p"
	.string "You seem to be okay, so what do you say\n"
	.string "to a battle?$"

Route105_Text_LuisPostBattle::
# 117 "data/maps/Route105/scripts.pory"
	.string "If you are drowning, the signal is to\n"
	.string "wave one arm toward the beach.$"

Route105_Text_PostBattle::
# 121 "data/maps/Route105/scripts.pory"
	.string "Your body weight is reduced to just\n"
	.string "one tenth in the water.\p"
	.string "That would make me…\n"
	.string "Whoops! I'm not telling you my weight!$"
