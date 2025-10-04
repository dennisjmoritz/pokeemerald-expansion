MtMoon_B2F_MapScripts::
	.byte 0


MtMoon_B2F_EventScript_DomeFossil::
# 5 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_YouWantDomeFossil, MSGBOX_YESNO
	end


MtMoon_B2F_EventScript_Grunt1::
# 10 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT, MtMoon_B2F_Text_Grunt1Intro, MtMoon_B2F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_Grunt1PostBattle
	return


MtMoon_B2F_EventScript_Grunt2::
# 15 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_2, MtMoon_B2F_Text_Grunt2Intro, MtMoon_B2F_Text_Grunt2Defeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_Grunt2PostBattle
	return


MtMoon_B2F_EventScript_Grunt3::
# 20 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_3, MtMoon_B2F_Text_Grunt3Intro, MtMoon_B2F_Text_Grunt3Defeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_Grunt3PostBattle
	return


MtMoon_B2F_EventScript_Grunt4::
# 25 "data/maps/MtMoon_B2F/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_4, MtMoon_B2F_Text_Grunt4Intro, MtMoon_B2F_Text_Grunt4Defeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_Grunt4PostBattle
	return


MtMoon_B2F_EventScript_HelixFossil::
# 30 "data/maps/MtMoon_B2F/scripts.pory"
	msgbox MtMoon_B2F_Text_YouWantHelixFossil, MSGBOX_YESNO
	end


MtMoon_B2F_EventScript_Miguel::
	end


MtMoon_B2F_EventScript_MiguelTrigger::
	end


MtMoon_B2F_Text_Grunt1Defeat::
# 44 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtMoon_B2F_Text_Grunt1Defeat$"

MtMoon_B2F_Text_Grunt1Intro::
# 48 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtMoon_B2F_Text_Grunt1Intro$"

MtMoon_B2F_Text_Grunt1PostBattle::
# 52 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtMoon_B2F_Text_Grunt1PostBattle$"

MtMoon_B2F_Text_Grunt2Defeat::
# 56 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtMoon_B2F_Text_Grunt2Defeat$"

MtMoon_B2F_Text_Grunt2Intro::
# 60 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtMoon_B2F_Text_Grunt2Intro$"

MtMoon_B2F_Text_Grunt2PostBattle::
# 64 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtMoon_B2F_Text_Grunt2PostBattle$"

MtMoon_B2F_Text_Grunt3Defeat::
# 68 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtMoon_B2F_Text_Grunt3Defeat$"

MtMoon_B2F_Text_Grunt3Intro::
# 72 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtMoon_B2F_Text_Grunt3Intro$"

MtMoon_B2F_Text_Grunt3PostBattle::
# 76 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtMoon_B2F_Text_Grunt3PostBattle$"

MtMoon_B2F_Text_Grunt4Defeat::
# 80 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtMoon_B2F_Text_Grunt4Defeat$"

MtMoon_B2F_Text_Grunt4Intro::
# 84 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtMoon_B2F_Text_Grunt4Intro$"

MtMoon_B2F_Text_Grunt4PostBattle::
# 88 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtMoon_B2F_Text_Grunt4PostBattle$"

MtMoon_B2F_Text_YouWantDomeFossil::
# 91 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Do you want the DOME FOSSIL?$"

MtMoon_B2F_Text_YouWantHelixFossil::
# 95 "data/maps/MtMoon_B2F/scripts.pory"
	.string "Do you want the HELIX FOSSIL?$"
