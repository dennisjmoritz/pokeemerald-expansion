Route119_WeatherInstitute_1F_MapScripts::
	.byte 0


Route119_WeatherInstitute_1F_EventScript_Bed::
# 6 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	end


Route119_WeatherInstitute_1F_EventScript_Grunt1::
# 14 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_WEATHER_INST, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 15 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle
	return


Route119_WeatherInstitute_1F_EventScript_Grunt4::
# 19 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat, Text_NotEnoughMonsForDoubleBattle
# 20 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle
	return


Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	end


Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
# 28 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end


Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	end


Route119_WeatherInstitute_1F_Text_TakeRestInBed::
# 37 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "There's a bed… Let's take a rest.$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat::
# 42 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_1F_Text_Grunt1Defeat$"

Route119_WeatherInstitute_1F_Text_Grunt1Intro::
# 46 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_1F_Text_Grunt1Intro$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle::
# 50 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_1F_Text_Grunt1PostBattle$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat::
# 54 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_1F_Text_Grunt4Defeat$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro::
# 58 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_1F_Text_Grunt4Intro$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle::
# 62 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_1F_Text_Grunt4PostBattle$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs::
# 66 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "While I was sleeping, everyone went\n"
	.string "upstairs!$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo::
# 70 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Hello!\n"
	.string "We've been saved by your actions!\p"
	.string "What I don't understand is what on\n"
	.string "earth the AQUAS were up to.$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain::
# 74 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "The PROFESSOR loves rain.\n"
	.string "That's a fact.\p"
	.string "But if it keeps raining, people will be in\n"
	.string "trouble. That's another fact.\p"
	.string "And thus, the PROFESSOR is studying\n"
	.string "if the rain can be put to good use.$"
