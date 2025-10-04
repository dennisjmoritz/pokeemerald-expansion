CeruleanCity_Gym_MapScripts::
	.byte 0


CeruleanCity_Gym_EventScript_Diana::
# 5 "data/maps/CeruleanCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/CeruleanCity_Gym/scripts.pory"
	msgbox CeruleanCity_Gym_Text_DianaPostBattle
	return


CeruleanCity_Gym_EventScript_GymGuy::
	end


CeruleanCity_Gym_EventScript_GymStatue::
# 16 "data/maps/CeruleanCity_Gym/scripts.pory"
	msgbox CeruleanCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	end


CeruleanCity_Gym_EventScript_Luis::
# 22 "data/maps/CeruleanCity_Gym/scripts.pory"
	trainerbattle_double TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat, Text_NotEnoughMonsForDoubleBattle
# 23 "data/maps/CeruleanCity_Gym/scripts.pory"
	msgbox CeruleanCity_Gym_Text_LuisPostBattle
	return


CeruleanCity_Gym_EventScript_Misty::
	end


CeruleanCity_Gym_Text_GymStatue::
# 31 "data/maps/CeruleanCity_Gym/scripts.pory"
	.string "CERULEAN POKéMON GYM LEADER: MISTY\p"
	.string "WINNING TRAINERS: {RIVAL}$"

CeruleanCity_Gym_Text_DianaDefeat::
# 36 "data/maps/CeruleanCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeruleanCity_Gym_Text_DianaDefeat$"

CeruleanCity_Gym_Text_DianaIntro::
# 40 "data/maps/CeruleanCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeruleanCity_Gym_Text_DianaIntro$"

CeruleanCity_Gym_Text_DianaPostBattle::
# 44 "data/maps/CeruleanCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeruleanCity_Gym_Text_DianaPostBattle$"

CeruleanCity_Gym_Text_LuisDefeat::
# 48 "data/maps/CeruleanCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeruleanCity_Gym_Text_LuisDefeat$"

CeruleanCity_Gym_Text_LuisIntro::
# 52 "data/maps/CeruleanCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeruleanCity_Gym_Text_LuisIntro$"

CeruleanCity_Gym_Text_LuisPostBattle::
# 56 "data/maps/CeruleanCity_Gym/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeruleanCity_Gym_Text_LuisPostBattle$"
