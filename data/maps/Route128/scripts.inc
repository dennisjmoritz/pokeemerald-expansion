Route128_MapScripts::
	.byte 0


Route128_EventScript_Alexa::
# 5 "data/maps/Route128/scripts.pory"
	trainerbattle_double TRAINER_ALEXA, Route128_Text_AlexaIntro, Route128_Text_AlexaDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_AlexaPostBattle
	return


Route128_EventScript_Carlee::
# 10 "data/maps/Route128/scripts.pory"
	trainerbattle_double TRAINER_CARLEE, Route128_Text_CarleeIntro, Route128_Text_CarleeDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_CarleePostBattle
	return


Route128_EventScript_Harrison::
# 15 "data/maps/Route128/scripts.pory"
	trainerbattle_double TRAINER_HARRISON, Route128_Text_HarrisonIntro, Route128_Text_HarrisonDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_HarrisonPostBattle
	return


Route128_EventScript_Isaiah::
# 20 "data/maps/Route128/scripts.pory"
	trainerbattle_double TRAINER_ISAIAH, Route128_Text_IsaiahIntro, Route128_Text_IsaiahDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_IsaiahPostBattle
	return


Route128_EventScript_Katelyn::
# 25 "data/maps/Route128/scripts.pory"
	trainerbattle_double TRAINER_KATELYN, Route128_Text_KatelynIntro, Route128_Text_KatelynDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_KatelynPostBattle
	return


Route128_EventScript_Ruben::
# 30 "data/maps/Route128/scripts.pory"
	trainerbattle_double TRAINER_RUBEN, Route128_Text_RubenIntro, Route128_Text_RubenDefeat, Text_NotEnoughMonsForDoubleBattle
# 31 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_RubenPostBattle
	return


Route128_EventScript_Wayne::
# 35 "data/maps/Route128/scripts.pory"
	trainerbattle_double TRAINER_WAYNE, Route128_Text_WayneIntro, Route128_Text_WayneDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route128/scripts.pory"
	msgbox Route128_Text_WaynePostBattle
	return


Route128_Text_AlexaDefeat::
# 41 "data/maps/Route128/scripts.pory"
	.string "Oh! How could this happen?!$"

Route128_Text_AlexaIntro::
# 45 "data/maps/Route128/scripts.pory"
	.string "We've been working so hard to mount a\n"
	.string "POKéMON LEAGUE challenge…\p"
	.string "We can't afford to lose now!$"

Route128_Text_AlexaPostBattle::
# 49 "data/maps/Route128/scripts.pory"
	.string "After all I've done to get here, I won't\n"
	.string "give up after one setback.$"

Route128_Text_CarleeDefeat::
# 53 "data/maps/Route128/scripts.pory"
	.string "I couldn't see very well because of the\n"
	.string "sun's glare.$"

Route128_Text_CarleeIntro::
# 57 "data/maps/Route128/scripts.pory"
	.string "The sunlight seems to be more harsh in\n"
	.string "this area.$"

Route128_Text_CarleePostBattle::
# 61 "data/maps/Route128/scripts.pory"
	.string "I should go back soon. I need to reapply\n"
	.string "my sunscreen.$"

Route128_Text_HarrisonDefeat::
# 65 "data/maps/Route128/scripts.pory"
	.string "Ouch! I guess it was impossible to win.$"

Route128_Text_HarrisonIntro::
# 69 "data/maps/Route128/scripts.pory"
	.string "You're looking awfully tough. I wonder\n"
	.string "if I can win?$"

Route128_Text_HarrisonPostBattle::
# 73 "data/maps/Route128/scripts.pory"
	.string "There are tough TRAINERS galore around\n"
	.string "EVER GRANDE.\p"
	.string "Do you think I may be out of my league?$"

Route128_Text_IsaiahDefeat::
# 77 "data/maps/Route128/scripts.pory"
	.string "My first victory seems to be far away,\n"
	.string "too…$"

Route128_Text_IsaiahIntro::
# 81 "data/maps/Route128/scripts.pory"
	.string "EVER GRANDE CITY is still a long ways\n"
	.string "away…$"

Route128_Text_IsaiahPostBattle::
# 85 "data/maps/Route128/scripts.pory"
	.string "My whole life has been about losing, but\n"
	.string "I will never give up!$"

Route128_Text_KatelynDefeat::
# 89 "data/maps/Route128/scripts.pory"
	.string "A POKéMON battle is grueling, too…$"

Route128_Text_KatelynIntro::
# 93 "data/maps/Route128/scripts.pory"
	.string "You have to swim, cycle, and then run a\n"
	.string "marathon in a triathlon.\p"
	.string "It's a grueling race that consists of\n"
	.string "three events.$"

Route128_Text_KatelynPostBattle::
# 97 "data/maps/Route128/scripts.pory"
	.string "I have to ride a BIKE next, but… I'm\n"
	.string "about to throw in the towel…$"

Route128_Text_RubenDefeat::
# 101 "data/maps/Route128/scripts.pory"
	.string "This can't be!$"

Route128_Text_RubenIntro::
# 105 "data/maps/Route128/scripts.pory"
	.string "There is no stronger TRAINER than I!$"

Route128_Text_RubenPostBattle::
# 109 "data/maps/Route128/scripts.pory"
	.string "There probably is no stronger TRAINER\n"
	.string "than you!$"

Route128_Text_WayneDefeat::
# 113 "data/maps/Route128/scripts.pory"
	.string "I'm crestfallen!$"

Route128_Text_WayneIntro::
# 117 "data/maps/Route128/scripts.pory"
	.string "I want to visit EVER GRANDE, so I\n"
	.string "caught myself a POKéMON that knows the\l"
	.string "move WATERFALL to crest the falls.$"

Route128_Text_WaynePostBattle::
# 121 "data/maps/Route128/scripts.pory"
	.string "Awww, phooey!\p"
	.string "My POKéMON knows WATERFALL, but I\n"
	.string "don't have the SOOTOPOLIS GYM BADGE!$"

Route128_Text_ArchieWhatHappened::
# 125 "data/maps/Route128/scripts.pory"
	.string "ARCHIE: What happened…\n"
	.string "What is this wretched scene…\p"
	.string "Did I…make a horrible mistake?$"
