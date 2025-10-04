FuchsiaCity_Gym_MapScripts::
	.byte 0


FuchsiaCity_Gym_EventScript_Edgar::
# 5 "data/maps/FuchsiaCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarIntro, FuchsiaCity_Gym_Text_EdgarDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/FuchsiaCity_Gym/scripts.pory"
	msgbox FuchsiaCity_Gym_Text_EdgarPostBattle
	return


FuchsiaCity_Gym_EventScript_GymGuy::
	end


FuchsiaCity_Gym_EventScript_GymStatue::
# 16 "data/maps/FuchsiaCity_Gym/scripts.pory"
	msgbox FuchsiaCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	end


FuchsiaCity_Gym_EventScript_Kayden::
# 22 "data/maps/FuchsiaCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenIntro, FuchsiaCity_Gym_Text_KaydenDefeat, Text_NotEnoughMonsForDoubleBattle
# 23 "data/maps/FuchsiaCity_Gym/scripts.pory"
	msgbox FuchsiaCity_Gym_Text_KaydenPostBattle
	return


FuchsiaCity_Gym_EventScript_Kirk::
# 27 "data/maps/FuchsiaCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkIntro, FuchsiaCity_Gym_Text_KirkDefeat, Text_NotEnoughMonsForDoubleBattle
# 28 "data/maps/FuchsiaCity_Gym/scripts.pory"
	msgbox FuchsiaCity_Gym_Text_KirkPostBattle
	return


FuchsiaCity_Gym_EventScript_Koga::
	end


FuchsiaCity_Gym_EventScript_Nate::
# 36 "data/maps/FuchsiaCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateIntro, FuchsiaCity_Gym_Text_NateDefeat, Text_NotEnoughMonsForDoubleBattle
# 37 "data/maps/FuchsiaCity_Gym/scripts.pory"
	msgbox FuchsiaCity_Gym_Text_NatePostBattle
	return


FuchsiaCity_Gym_EventScript_Phil::
# 41 "data/maps/FuchsiaCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilIntro, FuchsiaCity_Gym_Text_PhilDefeat, Text_NotEnoughMonsForDoubleBattle
# 42 "data/maps/FuchsiaCity_Gym/scripts.pory"
	msgbox FuchsiaCity_Gym_Text_PhilPostBattle
	return


FuchsiaCity_Gym_EventScript_Shawn::
# 46 "data/maps/FuchsiaCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnIntro, FuchsiaCity_Gym_Text_ShawnDefeat, Text_NotEnoughMonsForDoubleBattle
# 47 "data/maps/FuchsiaCity_Gym/scripts.pory"
	msgbox FuchsiaCity_Gym_Text_ShawnPostBattle
	return


FuchsiaCity_Gym_Text_GymStatue::
# 51 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "FUCHSIA POKéMON GYM LEADER: KOGA\p"
	.string "WINNING TRAINERS: {RIVAL}$"

FuchsiaCity_Gym_Text_EdgarDefeat::
# 56 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_EdgarDefeat$"

FuchsiaCity_Gym_Text_EdgarIntro::
# 60 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_EdgarIntro$"

FuchsiaCity_Gym_Text_EdgarPostBattle::
# 64 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_EdgarPostBattle$"

FuchsiaCity_Gym_Text_KaydenDefeat::
# 68 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_KaydenDefeat$"

FuchsiaCity_Gym_Text_KaydenIntro::
# 72 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_KaydenIntro$"

FuchsiaCity_Gym_Text_KaydenPostBattle::
# 76 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_KaydenPostBattle$"

FuchsiaCity_Gym_Text_KirkDefeat::
# 80 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_KirkDefeat$"

FuchsiaCity_Gym_Text_KirkIntro::
# 84 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_KirkIntro$"

FuchsiaCity_Gym_Text_KirkPostBattle::
# 88 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_KirkPostBattle$"

FuchsiaCity_Gym_Text_NateDefeat::
# 92 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_NateDefeat$"

FuchsiaCity_Gym_Text_NateIntro::
# 96 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_NateIntro$"

FuchsiaCity_Gym_Text_NatePostBattle::
# 100 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_NatePostBattle$"

FuchsiaCity_Gym_Text_PhilDefeat::
# 104 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_PhilDefeat$"

FuchsiaCity_Gym_Text_PhilIntro::
# 108 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_PhilIntro$"

FuchsiaCity_Gym_Text_PhilPostBattle::
# 112 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_PhilPostBattle$"

FuchsiaCity_Gym_Text_ShawnDefeat::
# 116 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_ShawnDefeat$"

FuchsiaCity_Gym_Text_ShawnIntro::
# 120 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_ShawnIntro$"

FuchsiaCity_Gym_Text_ShawnPostBattle::
# 124 "data/maps/FuchsiaCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "FuchsiaCity_Gym_Text_ShawnPostBattle$"
