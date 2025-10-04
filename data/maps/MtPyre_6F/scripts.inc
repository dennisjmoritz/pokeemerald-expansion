MtPyre_6F_MapScripts::
	.byte 0


MtPyre_6F_EventScript_Cedric::
# 5 "data/maps/MtPyre_6F/scripts.pory"
	trainerbattle_double TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_Text_CedricPostBattle
	return


MtPyre_6F_EventScript_Valerie::
# 10 "data/maps/MtPyre_6F/scripts.pory"
	trainerbattle_double TRAINER_VALERIE, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/MtPyre_6F/scripts.pory"
	msgbox MtPyre_6F_Text_ValeriePostBattle
	return


MtPyre_6F_Text_CedricDefeat::
# 16 "data/maps/MtPyre_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_6F_Text_CedricDefeat$"

MtPyre_6F_Text_CedricIntro::
# 20 "data/maps/MtPyre_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_6F_Text_CedricIntro$"

MtPyre_6F_Text_CedricPostBattle::
# 24 "data/maps/MtPyre_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_6F_Text_CedricPostBattle$"

MtPyre_6F_Text_ValerieDefeat::
# 28 "data/maps/MtPyre_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_6F_Text_ValerieDefeat$"

MtPyre_6F_Text_ValerieIntro::
# 32 "data/maps/MtPyre_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_6F_Text_ValerieIntro$"

MtPyre_6F_Text_ValeriePostBattle::
# 36 "data/maps/MtPyre_6F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_6F_Text_ValeriePostBattle$"

MtPyre_6F_Text_ValeriePostRematch::
# 40 "data/maps/MtPyre_6F/scripts.pory"
	.string "The POKéMON at rest here…\n"
	.string "Sometimes, they play…$"

MtPyre_6F_Text_ValerieRegister::
# 44 "data/maps/MtPyre_6F/scripts.pory"
	.string "Fufufu… I lost the match, but…\n"
	.string "I have this little ability…\p"
	.string "Without ever laying my hands on\n"
	.string "your POKéNAV… Hiyah!$"
