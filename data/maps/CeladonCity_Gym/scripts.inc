CeladonCity_Gym_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Bridget::
# 5 "data/maps/CeladonCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetIntro, CeladonCity_Gym_Text_BridgetDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/CeladonCity_Gym/scripts.pory"
	msgbox CeladonCity_Gym_Text_BridgetPostBattle
	return


CeladonCity_Gym_EventScript_Erika::
	end


CeladonCity_Gym_EventScript_GymStatue::
# 16 "data/maps/CeladonCity_Gym/scripts.pory"
	msgbox CeladonCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	end


CeladonCity_Gym_EventScript_Kay::
# 22 "data/maps/CeladonCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_LASS_KAY, CeladonCity_Gym_Text_KayIntro, CeladonCity_Gym_Text_KayDefeat, Text_NotEnoughMonsForDoubleBattle
# 23 "data/maps/CeladonCity_Gym/scripts.pory"
	msgbox CeladonCity_Gym_Text_KayPostBattle
	return


CeladonCity_Gym_EventScript_Lisa::
# 27 "data/maps/CeladonCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_LASS_LISA, CeladonCity_Gym_Text_LisaIntro, CeladonCity_Gym_Text_LisaDefeat, Text_NotEnoughMonsForDoubleBattle
# 28 "data/maps/CeladonCity_Gym/scripts.pory"
	msgbox CeladonCity_Gym_Text_LisaPostBattle
	return


CeladonCity_Gym_EventScript_Lori::
# 32 "data/maps/CeladonCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_BEAUTY_LORI, CeladonCity_Gym_Text_LoriIntro, CeladonCity_Gym_Text_LoriDefeat, Text_NotEnoughMonsForDoubleBattle
# 33 "data/maps/CeladonCity_Gym/scripts.pory"
	msgbox CeladonCity_Gym_Text_LoriPostBattle
	return


CeladonCity_Gym_EventScript_Mary::
# 37 "data/maps/CeladonCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_COOLTRAINER_MARY, CeladonCity_Gym_Text_MaryIntro, CeladonCity_Gym_Text_MaryDefeat, Text_NotEnoughMonsForDoubleBattle
# 38 "data/maps/CeladonCity_Gym/scripts.pory"
	msgbox CeladonCity_Gym_Text_MaryPostBattle
	return


CeladonCity_Gym_EventScript_Tamia::
# 42 "data/maps/CeladonCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaIntro, CeladonCity_Gym_Text_TamiaDefeat, Text_NotEnoughMonsForDoubleBattle
# 43 "data/maps/CeladonCity_Gym/scripts.pory"
	msgbox CeladonCity_Gym_Text_TamiaPostBattle
	return


CeladonCity_Gym_EventScript_Tina::
# 47 "data/maps/CeladonCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_PICNICKER_TINA, CeladonCity_Gym_Text_TinaIntro, CeladonCity_Gym_Text_TinaDefeat, Text_NotEnoughMonsForDoubleBattle
# 48 "data/maps/CeladonCity_Gym/scripts.pory"
	msgbox CeladonCity_Gym_Text_TinaPostBattle
	return


CeladonCity_Gym_Text_GymStatue::
# 51 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "CELADON POKéMON GYM LEADER: ERIKA\p"
	.string "WINNING TRAINERS: {RIVAL}$"

CeladonCity_Gym_Text_BridgetDefeat::
# 56 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_BridgetDefeat$"

CeladonCity_Gym_Text_BridgetIntro::
# 60 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_BridgetIntro$"

CeladonCity_Gym_Text_BridgetPostBattle::
# 64 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_BridgetPostBattle$"

CeladonCity_Gym_Text_KayDefeat::
# 68 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_KayDefeat$"

CeladonCity_Gym_Text_KayIntro::
# 72 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_KayIntro$"

CeladonCity_Gym_Text_KayPostBattle::
# 76 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_KayPostBattle$"

CeladonCity_Gym_Text_LisaDefeat::
# 80 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_LisaDefeat$"

CeladonCity_Gym_Text_LisaIntro::
# 84 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_LisaIntro$"

CeladonCity_Gym_Text_LisaPostBattle::
# 88 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_LisaPostBattle$"

CeladonCity_Gym_Text_LoriDefeat::
# 92 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_LoriDefeat$"

CeladonCity_Gym_Text_LoriIntro::
# 96 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_LoriIntro$"

CeladonCity_Gym_Text_LoriPostBattle::
# 100 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_LoriPostBattle$"

CeladonCity_Gym_Text_MaryDefeat::
# 104 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_MaryDefeat$"

CeladonCity_Gym_Text_MaryIntro::
# 108 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_MaryIntro$"

CeladonCity_Gym_Text_MaryPostBattle::
# 112 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_MaryPostBattle$"

CeladonCity_Gym_Text_TamiaDefeat::
# 116 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_TamiaDefeat$"

CeladonCity_Gym_Text_TamiaIntro::
# 120 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_TamiaIntro$"

CeladonCity_Gym_Text_TamiaPostBattle::
# 124 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_TamiaPostBattle$"

CeladonCity_Gym_Text_TinaDefeat::
# 128 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_TinaDefeat$"

CeladonCity_Gym_Text_TinaIntro::
# 132 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_TinaIntro$"

CeladonCity_Gym_Text_TinaPostBattle::
# 136 "data/maps/CeladonCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_Gym_Text_TinaPostBattle$"
