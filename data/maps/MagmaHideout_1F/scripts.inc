MagmaHideout_1F_MapScripts::
	.byte 0


MagmaHideout_1F_EventScript_Grunt1::
# 5 "data/maps/MagmaHideout_1F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_MAGMA_HIDEOUT, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/MagmaHideout_1F/scripts.pory"
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle
	return


MagmaHideout_1F_EventScript_Grunt2::
# 10 "data/maps/MagmaHideout_1F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/MagmaHideout_1F/scripts.pory"
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle
	return


MagmaHideout_1F_Text_Grunt1Defeat::
# 16 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_1F_Text_Grunt1Defeat$"

MagmaHideout_1F_Text_Grunt1Intro::
# 20 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_1F_Text_Grunt1Intro$"

MagmaHideout_1F_Text_Grunt1PostBattle::
# 24 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_1F_Text_Grunt1PostBattle$"

MagmaHideout_1F_Text_Grunt2Defeat::
# 28 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_1F_Text_Grunt2Defeat$"

MagmaHideout_1F_Text_Grunt2Intro::
# 32 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_1F_Text_Grunt2Intro$"

MagmaHideout_1F_Text_Grunt2PostBattle::
# 36 "data/maps/MagmaHideout_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_1F_Text_Grunt2PostBattle$"
