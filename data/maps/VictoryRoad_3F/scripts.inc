VictoryRoad_3F_MapScripts::
	.byte 0


VictoryRoad_3F_EventScript_Alexa::
# 5 "data/maps/VictoryRoad_3F/scripts.pory"
	trainerbattle_double TRAINER_COOLTRAINER_ALEXA, VictoryRoad_3F_Text_AlexaIntro, VictoryRoad_3F_Text_AlexaDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/VictoryRoad_3F/scripts.pory"
	msgbox VictoryRoad_3F_Text_AlexaPostBattle
	return


VictoryRoad_3F_EventScript_Caroline::
# 10 "data/maps/VictoryRoad_3F/scripts.pory"
	trainerbattle_double TRAINER_COOLTRAINER_CAROLINE, VictoryRoad_3F_Text_CarolineIntro, VictoryRoad_3F_Text_CarolineDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/VictoryRoad_3F/scripts.pory"
	msgbox VictoryRoad_3F_Text_CarolinePostBattle
	return


VictoryRoad_3F_EventScript_Colby::
# 15 "data/maps/VictoryRoad_3F/scripts.pory"
	trainerbattle_double TRAINER_COOLTRAINER_COLBY, VictoryRoad_3F_Text_ColbyIntro, VictoryRoad_3F_Text_ColbyDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/VictoryRoad_3F/scripts.pory"
	msgbox VictoryRoad_3F_Text_ColbyPostBattle
	return


VictoryRoad_3F_EventScript_FloorSwitch::
	end


VictoryRoad_3F_EventScript_George::
# 24 "data/maps/VictoryRoad_3F/scripts.pory"
	trainerbattle_double TRAINER_COOLTRAINER_GEORGE, VictoryRoad_3F_Text_GeorgeIntro, VictoryRoad_3F_Text_GeorgeDefeat, Text_NotEnoughMonsForDoubleBattle
# 25 "data/maps/VictoryRoad_3F/scripts.pory"
	msgbox VictoryRoad_3F_Text_GeorgePostBattle
	return


VictoryRoad_3F_EventScript_ItemMaxRevive::
	end


VictoryRoad_3F_EventScript_ItemTM50::
	end


VictoryRoad_3F_EventScript_Ray::
# 37 "data/maps/VictoryRoad_3F/scripts.pory"
	msgbox VictoryRoad_3F_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end


VictoryRoad_3F_EventScript_Tyra::
# 42 "data/maps/VictoryRoad_3F/scripts.pory"
	msgbox VictoryRoad_3F_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end


VictoryRoad_3F_Text_AlexaDefeat::
# 48 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "VictoryRoad_3F_Text_AlexaDefeat$"

VictoryRoad_3F_Text_AlexaIntro::
# 52 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "VictoryRoad_3F_Text_AlexaIntro$"

VictoryRoad_3F_Text_AlexaPostBattle::
# 56 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "VictoryRoad_3F_Text_AlexaPostBattle$"

VictoryRoad_3F_Text_CarolineDefeat::
# 60 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "VictoryRoad_3F_Text_CarolineDefeat$"

VictoryRoad_3F_Text_CarolineIntro::
# 64 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "VictoryRoad_3F_Text_CarolineIntro$"

VictoryRoad_3F_Text_CarolinePostBattle::
# 68 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "VictoryRoad_3F_Text_CarolinePostBattle$"

VictoryRoad_3F_Text_ColbyDefeat::
# 72 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "VictoryRoad_3F_Text_ColbyDefeat$"

VictoryRoad_3F_Text_ColbyIntro::
# 76 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "VictoryRoad_3F_Text_ColbyIntro$"

VictoryRoad_3F_Text_ColbyPostBattle::
# 80 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "VictoryRoad_3F_Text_ColbyPostBattle$"

VictoryRoad_3F_Text_GeorgeDefeat::
# 84 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "VictoryRoad_3F_Text_GeorgeDefeat$"

VictoryRoad_3F_Text_GeorgeIntro::
# 88 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "VictoryRoad_3F_Text_GeorgeIntro$"

VictoryRoad_3F_Text_GeorgePostBattle::
# 92 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "Placeholder text for\n"
	.string "VictoryRoad_3F_Text_GeorgePostBattle$"

VictoryRoad_3F_Text_RayPostBattle::
# 95 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "RAY: You've beaten us.\n"
	.string "Greatness remains elusive…$"

VictoryRoad_3F_Text_TyraPostBattle::
# 99 "data/maps/VictoryRoad_3F/scripts.pory"
	.string "TYRA: You've taught me that power\n"
	.string "can be infinite in shape and form.$"
