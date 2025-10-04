Route15_WestEntrance_2F_MapScripts::
	.byte 0


Route15_WestEntrance_2F_EventScript_Aide::
	end


Route15_WestEntrance_2F_EventScript_LeftBinoculars::
# 10 "data/maps/Route15_WestEntrance_2F/scripts.pory"
	msgbox Route15_WestEntrance_2F_Text_LargeShiningBird, MSGBOX_DEFAULT
	end


Route15_WestEntrance_2F_EventScript_RightBinoculars::
# 22 "data/maps/Route15_WestEntrance_2F/scripts.pory"
	msgbox Route15_WestEntrance_2F_Text_SmallIslandOnHorizon, MSGBOX_SIGN
	end


Route15_WestEntrance_2F_Text_SmallIslandOnHorizon::
# 27 "data/maps/Route15_WestEntrance_2F/scripts.pory"
	.string "Let's see what the binoculars have to\n"
	.string "show…\p"
	.string "It looks like a small island on the\n"
	.string "horizon!$"

Route15_WestEntrance_2F_Text_LargeShiningBird::
# 31 "data/maps/Route15_WestEntrance_2F/scripts.pory"
	.string "Let's see what the binoculars have to\n"
	.string "show…\p"
	.string "A large, shining bird is flying toward\n"
	.string "the sea.$"
