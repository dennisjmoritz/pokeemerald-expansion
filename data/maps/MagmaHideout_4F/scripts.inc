MagmaHideout_4F_MapScripts::
	.byte 0


MagmaHideout_4F_EventScript_Grunt11::
# 5 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle
	return


MagmaHideout_4F_EventScript_Grunt12::
# 10 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle
	return


MagmaHideout_4F_EventScript_Grunt13::
# 15 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle
	return


MagmaHideout_4F_EventScript_Maxie::
# 20 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	end


MagmaHideout_4F_EventScript_Tabitha::
# 25 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_double TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_TabithaPostBattle
	return


MagmaHideout_4F_Text_Grunt11Defeat::
# 31 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_4F_Text_Grunt11Defeat$"

MagmaHideout_4F_Text_Grunt11Intro::
# 35 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_4F_Text_Grunt11Intro$"

MagmaHideout_4F_Text_Grunt11PostBattle::
# 39 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_4F_Text_Grunt11PostBattle$"

MagmaHideout_4F_Text_Grunt12Defeat::
# 43 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_4F_Text_Grunt12Defeat$"

MagmaHideout_4F_Text_Grunt12Intro::
# 47 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_4F_Text_Grunt12Intro$"

MagmaHideout_4F_Text_Grunt12PostBattle::
# 51 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_4F_Text_Grunt12PostBattle$"

MagmaHideout_4F_Text_Grunt13Defeat::
# 55 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_4F_Text_Grunt13Defeat$"

MagmaHideout_4F_Text_Grunt13Intro::
# 59 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_4F_Text_Grunt13Intro$"

MagmaHideout_4F_Text_Grunt13PostBattle::
# 63 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_4F_Text_Grunt13PostBattle$"

MagmaHideout_4F_Text_TabithaDefeat::
# 67 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_4F_Text_TabithaDefeat$"

MagmaHideout_4F_Text_TabithaIntro::
# 71 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_4F_Text_TabithaIntro$"

MagmaHideout_4F_Text_TabithaPostBattle::
# 75 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MagmaHideout_4F_Text_TabithaPostBattle$"

MagmaHideout_4F_Text_MaxieAwakenGroudon::
# 79 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE: GROUDON…\p"
	.string "Nothing could awaken you from your\n"
	.string "sleep bathed in magma…\p"
	.string "This BLUE ORB is what you sought.\n"
	.string "Wasn't it?\p"
	.string "I have brought you the BLUE ORB.\n"
	.string "Let its shine awaken you!\p"
	.string "And show me…\n"
	.string "Show me the full extent of your power!$"
