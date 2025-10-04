Route119_WeatherInstitute_2F_MapScripts::
	.byte 0


Route119_WeatherInstitute_2F_EventScript_Grunt2::
# 5 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle
	return


Route119_WeatherInstitute_2F_EventScript_Grunt3::
# 10 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle
	return


Route119_WeatherInstitute_2F_EventScript_Grunt5::
# 15 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle
	return


Route119_WeatherInstitute_2F_EventScript_Shelly::
# 20 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	trainerbattle_double TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle
	return


Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	end


Route119_WeatherInstitute_2F_Text_Grunt2Defeat::
# 30 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_2F_Text_Grunt2Defeat$"

Route119_WeatherInstitute_2F_Text_Grunt2Intro::
# 34 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_2F_Text_Grunt2Intro$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle::
# 38 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_2F_Text_Grunt2PostBattle$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat::
# 42 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_2F_Text_Grunt3Defeat$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro::
# 46 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_2F_Text_Grunt3Intro$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle::
# 50 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_2F_Text_Grunt3PostBattle$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat::
# 54 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_2F_Text_Grunt5Defeat$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro::
# 58 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_2F_Text_Grunt5Intro$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle::
# 62 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_2F_Text_Grunt5PostBattle$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat::
# 66 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_2F_Text_ShellyDefeat$"

Route119_WeatherInstitute_2F_Text_ShellyIntro::
# 70 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_2F_Text_ShellyIntro$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle::
# 74 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route119_WeatherInstitute_2F_Text_ShellyPostBattle$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather::
# 78 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "That POKéMON changes shape according\n"
	.string "to the weather conditions.\p"
	.string "There're plenty of them in the\n"
	.string "INSTITUTE--go ahead and take it.$"

Route119_WeatherInstitute_2F_Text_KyogreWeather::
# 82 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, heavy rainfall has been\n"
	.string "recorded over {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon::
# 86 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Thanks!\n"
	.string "Thanks to you, we're safe!\p"
	.string "It might be an odd way of thanking you,\n"
	.string "but take this POKéMON.$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather::
# 90 "data/maps/Route119_WeatherInstitute_2F/scripts.pory"
	.string "Abnormal weather conditions are\n"
	.string "no longer being reported.\p"
	.string "The occasional rainfall is a blessing,\n"
	.string "really.$"
