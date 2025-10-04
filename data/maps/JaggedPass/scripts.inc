JaggedPass_MapScripts::
	.byte 0


JaggedPass_EventScript_Autumn::
# 5 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_double TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_AutumnPostBattle
	return


JaggedPass_EventScript_Diana::
# 10 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_double TRAINER_DIANA, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostBattle
	return


JaggedPass_EventScript_Eric::
# 15 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_double TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EricPostBattle
	return


JaggedPass_EventScript_Ethan::
# 20 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_double TRAINER_ETHAN, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostBattle
	return


JaggedPass_EventScript_Julio::
# 25 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_double TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_JulioPostBattle
	return


JaggedPass_EventScript_MagmaHideoutGuard::
	end


JaggedPass_EventScript_OpenMagmaHideout::
# 34 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	end


JaggedPass_Text_AutumnDefeat::
# 40 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_AutumnDefeat$"

JaggedPass_Text_AutumnIntro::
# 44 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_AutumnIntro$"

JaggedPass_Text_AutumnPostBattle::
# 48 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_AutumnPostBattle$"

JaggedPass_Text_DianaDefeat::
# 52 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_DianaDefeat$"

JaggedPass_Text_DianaIntro::
# 56 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_DianaIntro$"

JaggedPass_Text_DianaPostBattle::
# 60 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_DianaPostBattle$"

JaggedPass_Text_EricDefeat::
# 64 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_EricDefeat$"

JaggedPass_Text_EricIntro::
# 68 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_EricIntro$"

JaggedPass_Text_EricPostBattle::
# 72 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_EricPostBattle$"

JaggedPass_Text_EthanDefeat::
# 76 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_EthanDefeat$"

JaggedPass_Text_EthanIntro::
# 80 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_EthanIntro$"

JaggedPass_Text_EthanPostBattle::
# 84 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_EthanPostBattle$"

JaggedPass_Text_JulioDefeat::
# 88 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_JulioDefeat$"

JaggedPass_Text_JulioIntro::
# 92 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_JulioIntro$"

JaggedPass_Text_JulioPostBattle::
# 96 "data/maps/JaggedPass/scripts.pory"
	.string "Placeholder text for\n"
	.string "JaggedPass_Text_JulioPostBattle$"

JaggedPass_Text_DianaRegister::
# 100 "data/maps/JaggedPass/scripts.pory"
	.string "Will you ever be back in this area?\n"
	.string "If you do return, I'd like a rematch.$"

JaggedPass_Text_EthanRegister::
# 104 "data/maps/JaggedPass/scripts.pory"
	.string "When I get more used to this bumpiness,\n"
	.string "I'll be sure to win!\p"
	.string "Can you register me in your POKéNAV?$"

JaggedPass_Text_GoWhereverYouWant::
# 108 "data/maps/JaggedPass/scripts.pory"
	.string "Okay, oh-kay!\n"
	.string "I admit it--you're strong!\p"
	.string "Don't worry about me.\n"
	.string "Go wherever you want!$"

JaggedPass_Text_DianaPostRematch::
# 112 "data/maps/JaggedPass/scripts.pory"
	.string "I'll forget about losing and just\n"
	.string "enjoy this bumpy hike.$"

JaggedPass_Text_EthanPostRematch::
# 116 "data/maps/JaggedPass/scripts.pory"
	.string "I should get an ACRO BIKE from RYDEL\n"
	.string "in MAUVILLE CITY…$"

JaggedPass_Text_BoulderShakingInResponseToEmblem::
# 120 "data/maps/JaggedPass/scripts.pory"
	.string "Oh! This boulder is shaking in response\n"
	.string "to the MAGMA EMBLEM!$"
