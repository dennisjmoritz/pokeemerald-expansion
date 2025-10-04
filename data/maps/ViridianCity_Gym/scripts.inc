ViridianCity_Gym_MapScripts::
	.byte 0


ViridianCity_Gym_EventScript_Atsushi::
# 5 "data/maps/ViridianCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/ViridianCity_Gym/scripts.pory"
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle
	return


ViridianCity_Gym_EventScript_Cole::
# 10 "data/maps/ViridianCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/ViridianCity_Gym/scripts.pory"
	msgbox ViridianCity_Gym_Text_ColePostBattle
	return


ViridianCity_Gym_EventScript_Giovanni::
	end


ViridianCity_Gym_EventScript_GymGuy::
	end


ViridianCity_Gym_EventScript_GymStatue::
# 25 "data/maps/ViridianCity_Gym/scripts.pory"
	msgbox ViridianCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	end


ViridianCity_Gym_EventScript_Jason::
# 31 "data/maps/ViridianCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat, Text_NotEnoughMonsForDoubleBattle
# 32 "data/maps/ViridianCity_Gym/scripts.pory"
	msgbox ViridianCity_Gym_Text_JasonPostBattle
	return


ViridianCity_Gym_EventScript_Kiyo::
# 36 "data/maps/ViridianCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat, Text_NotEnoughMonsForDoubleBattle
# 37 "data/maps/ViridianCity_Gym/scripts.pory"
	msgbox ViridianCity_Gym_Text_KiyoPostBattle
	return


ViridianCity_Gym_EventScript_Samuel::
# 41 "data/maps/ViridianCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat, Text_NotEnoughMonsForDoubleBattle
# 42 "data/maps/ViridianCity_Gym/scripts.pory"
	msgbox ViridianCity_Gym_Text_SamuelPostBattle
	return


ViridianCity_Gym_EventScript_Takashi::
# 46 "data/maps/ViridianCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat, Text_NotEnoughMonsForDoubleBattle
# 47 "data/maps/ViridianCity_Gym/scripts.pory"
	msgbox ViridianCity_Gym_Text_TakashiPostBattle
	return


ViridianCity_Gym_EventScript_Warren::
# 51 "data/maps/ViridianCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat, Text_NotEnoughMonsForDoubleBattle
# 52 "data/maps/ViridianCity_Gym/scripts.pory"
	msgbox ViridianCity_Gym_Text_WarrenPostBattle
	return


ViridianCity_Gym_EventScript_Yuji::
# 56 "data/maps/ViridianCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat, Text_NotEnoughMonsForDoubleBattle
# 57 "data/maps/ViridianCity_Gym/scripts.pory"
	msgbox ViridianCity_Gym_Text_YujiPostBattle
	return


ViridianCity_Gym_Text_GymStatue::
# 61 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "VIRIDIAN POKéMON GYM LEADER: ?\p"
	.string "WINNING TRAINERS: {RIVAL}$"

ViridianCity_Gym_Text_AtsushiDefeat::
# 66 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_AtsushiDefeat$"

ViridianCity_Gym_Text_AtsushiIntro::
# 70 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_AtsushiIntro$"

ViridianCity_Gym_Text_AtsushiPostBattle::
# 74 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_AtsushiPostBattle$"

ViridianCity_Gym_Text_ColeDefeat::
# 78 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_ColeDefeat$"

ViridianCity_Gym_Text_ColeIntro::
# 82 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_ColeIntro$"

ViridianCity_Gym_Text_ColePostBattle::
# 86 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_ColePostBattle$"

ViridianCity_Gym_Text_JasonDefeat::
# 90 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_JasonDefeat$"

ViridianCity_Gym_Text_JasonIntro::
# 94 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_JasonIntro$"

ViridianCity_Gym_Text_JasonPostBattle::
# 98 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_JasonPostBattle$"

ViridianCity_Gym_Text_KiyoDefeat::
# 102 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_KiyoDefeat$"

ViridianCity_Gym_Text_KiyoIntro::
# 106 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_KiyoIntro$"

ViridianCity_Gym_Text_KiyoPostBattle::
# 110 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_KiyoPostBattle$"

ViridianCity_Gym_Text_SamuelDefeat::
# 114 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_SamuelDefeat$"

ViridianCity_Gym_Text_SamuelIntro::
# 118 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_SamuelIntro$"

ViridianCity_Gym_Text_SamuelPostBattle::
# 122 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_SamuelPostBattle$"

ViridianCity_Gym_Text_TakashiDefeat::
# 126 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_TakashiDefeat$"

ViridianCity_Gym_Text_TakashiIntro::
# 130 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_TakashiIntro$"

ViridianCity_Gym_Text_TakashiPostBattle::
# 134 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_TakashiPostBattle$"

ViridianCity_Gym_Text_WarrenDefeat::
# 138 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_WarrenDefeat$"

ViridianCity_Gym_Text_WarrenIntro::
# 142 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_WarrenIntro$"

ViridianCity_Gym_Text_WarrenPostBattle::
# 146 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_WarrenPostBattle$"

ViridianCity_Gym_Text_YujiDefeat::
# 150 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_YujiDefeat$"

ViridianCity_Gym_Text_YujiIntro::
# 154 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_YujiIntro$"

ViridianCity_Gym_Text_YujiPostBattle::
# 158 "data/maps/ViridianCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianCity_Gym_Text_YujiPostBattle$"
