PewterCity_Gym_MapScripts::
	.byte 0


PewterCity_Gym_EventScript_Brock::
	end


PewterCity_Gym_EventScript_GymGuy::
	end


PewterCity_Gym_EventScript_GymStatue::
# 15 "data/maps/PewterCity_Gym/scripts.pory"
	msgbox PewterCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	end


PewterCity_Gym_EventScript_Liam::
# 21 "data/maps/PewterCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_CAMPER_LIAM, PewterCity_Gym_Text_LiamIntro, PewterCity_Gym_Text_LiamDefeat, Text_NotEnoughMonsForDoubleBattle
# 22 "data/maps/PewterCity_Gym/scripts.pory"
	msgbox PewterCity_Gym_Text_LiamPostBattle
	return


PewterCity_Gym_Text_GymStatue::
# 26 "data/maps/PewterCity_Gym/scripts.pory"
	.string "PEWTER POKéMON GYM LEADER: BROCK\p"
	.string "WINNING TRAINERS: {RIVAL}$"

PewterCity_Gym_Text_LiamDefeat::
# 31 "data/maps/PewterCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "PewterCity_Gym_Text_LiamDefeat$"

PewterCity_Gym_Text_LiamIntro::
# 35 "data/maps/PewterCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "PewterCity_Gym_Text_LiamIntro$"

PewterCity_Gym_Text_LiamPostBattle::
# 39 "data/maps/PewterCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "PewterCity_Gym_Text_LiamPostBattle$"
