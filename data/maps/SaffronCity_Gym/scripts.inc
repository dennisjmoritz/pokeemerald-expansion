SaffronCity_Gym_MapScripts::
	.byte 0


SaffronCity_Gym_EventScript_Amanda::
# 5 "data/maps/SaffronCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SaffronCity_Gym/scripts.pory"
	msgbox SaffronCity_Gym_Text_AmandaPostBattle
	return


SaffronCity_Gym_EventScript_Cameron::
# 10 "data/maps/SaffronCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SaffronCity_Gym/scripts.pory"
	msgbox SaffronCity_Gym_Text_CameronPostBattle
	return


SaffronCity_Gym_EventScript_GymGuy::
	end


SaffronCity_Gym_EventScript_GymStatue::
# 21 "data/maps/SaffronCity_Gym/scripts.pory"
	msgbox SaffronCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	end


SaffronCity_Gym_EventScript_Johan::
# 27 "data/maps/SaffronCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat, Text_NotEnoughMonsForDoubleBattle
# 28 "data/maps/SaffronCity_Gym/scripts.pory"
	msgbox SaffronCity_Gym_Text_JohanPostBattle
	return


SaffronCity_Gym_EventScript_Preston::
# 32 "data/maps/SaffronCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat, Text_NotEnoughMonsForDoubleBattle
# 33 "data/maps/SaffronCity_Gym/scripts.pory"
	msgbox SaffronCity_Gym_Text_PrestonPostBattle
	return


SaffronCity_Gym_EventScript_Sabrina::
	end


SaffronCity_Gym_EventScript_Stacy::
# 41 "data/maps/SaffronCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat, Text_NotEnoughMonsForDoubleBattle
# 42 "data/maps/SaffronCity_Gym/scripts.pory"
	msgbox SaffronCity_Gym_Text_StacyPostBattle
	return


SaffronCity_Gym_EventScript_Tasha::
# 46 "data/maps/SaffronCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat, Text_NotEnoughMonsForDoubleBattle
# 47 "data/maps/SaffronCity_Gym/scripts.pory"
	msgbox SaffronCity_Gym_Text_TashaPostBattle
	return


SaffronCity_Gym_EventScript_Tyron::
# 51 "data/maps/SaffronCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat, Text_NotEnoughMonsForDoubleBattle
# 52 "data/maps/SaffronCity_Gym/scripts.pory"
	msgbox SaffronCity_Gym_Text_TyronPostBattle
	return


SaffronCity_Gym_Text_GymStatue::
# 56 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "SAFFRON POKéMON GYM LEADER: SABRINA\p"
	.string "WINNING TRAINERS: {RIVAL}$"

SaffronCity_Gym_Text_AmandaDefeat::
# 61 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_AmandaDefeat$"

SaffronCity_Gym_Text_AmandaIntro::
# 65 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_AmandaIntro$"

SaffronCity_Gym_Text_AmandaPostBattle::
# 69 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_AmandaPostBattle$"

SaffronCity_Gym_Text_CameronDefeat::
# 73 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_CameronDefeat$"

SaffronCity_Gym_Text_CameronIntro::
# 77 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_CameronIntro$"

SaffronCity_Gym_Text_CameronPostBattle::
# 81 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_CameronPostBattle$"

SaffronCity_Gym_Text_JohanDefeat::
# 85 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_JohanDefeat$"

SaffronCity_Gym_Text_JohanIntro::
# 89 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_JohanIntro$"

SaffronCity_Gym_Text_JohanPostBattle::
# 93 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_JohanPostBattle$"

SaffronCity_Gym_Text_PrestonDefeat::
# 97 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_PrestonDefeat$"

SaffronCity_Gym_Text_PrestonIntro::
# 101 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_PrestonIntro$"

SaffronCity_Gym_Text_PrestonPostBattle::
# 105 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_PrestonPostBattle$"

SaffronCity_Gym_Text_StacyDefeat::
# 109 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_StacyDefeat$"

SaffronCity_Gym_Text_StacyIntro::
# 113 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_StacyIntro$"

SaffronCity_Gym_Text_StacyPostBattle::
# 117 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_StacyPostBattle$"

SaffronCity_Gym_Text_TashaDefeat::
# 121 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_TashaDefeat$"

SaffronCity_Gym_Text_TashaIntro::
# 125 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_TashaIntro$"

SaffronCity_Gym_Text_TashaPostBattle::
# 129 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_TashaPostBattle$"

SaffronCity_Gym_Text_TyronDefeat::
# 133 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_TyronDefeat$"

SaffronCity_Gym_Text_TyronIntro::
# 137 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_TyronIntro$"

SaffronCity_Gym_Text_TyronPostBattle::
# 141 "data/maps/SaffronCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Gym_Text_TyronPostBattle$"
