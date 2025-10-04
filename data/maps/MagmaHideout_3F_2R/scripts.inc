MagmaHideout_3F_2R_MapScripts::
	.byte 0


MagmaHideout_3F_2R_EventScript_Grunt10::
# 5 "data/maps/MagmaHideout_3F_2R/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/MagmaHideout_3F_2R/scripts.pory"
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle
	return


MagmaHideout_3F_2R_Text_Grunt10Defeat::
# 11 "data/maps/MagmaHideout_3F_2R/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_3F_2R_Text_Grunt10Defeat$"

MagmaHideout_3F_2R_Text_Grunt10Intro::
# 15 "data/maps/MagmaHideout_3F_2R/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_3F_2R_Text_Grunt10Intro$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle::
# 19 "data/maps/MagmaHideout_3F_2R/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_3F_2R_Text_Grunt10PostBattle$"
