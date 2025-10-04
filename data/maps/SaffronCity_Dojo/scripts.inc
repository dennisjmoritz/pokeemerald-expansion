SaffronCity_Dojo_MapScripts::
	.byte 0


SaffronCity_Dojo_EventScript_Aaron::
# 5 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_double TRAINER_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronIntro, SaffronCity_Dojo_Text_AaronDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_AaronPostBattle
	return


SaffronCity_Dojo_EventScript_Hideki::
# 10 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_double TRAINER_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiIntro, SaffronCity_Dojo_Text_HidekiDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle
	return


SaffronCity_Dojo_EventScript_HitmonchanBall::
	end


SaffronCity_Dojo_EventScript_HitmonleeBall::
	end


SaffronCity_Dojo_EventScript_Hitoshi::
# 23 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_double TRAINER_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiIntro, SaffronCity_Dojo_Text_HitoshiDefeat, Text_NotEnoughMonsForDoubleBattle
# 24 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle
	return


SaffronCity_Dojo_EventScript_LeftScroll::
# 28 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
	end


SaffronCity_Dojo_EventScript_MasterKoichi::
# 33 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_double TRAINER_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiIntro, SaffronCity_Dojo_Text_MasterKoichiDefeat, Text_NotEnoughMonsForDoubleBattle
# 34 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon
	return


SaffronCity_Dojo_EventScript_Mike::
# 38 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_double TRAINER_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeIntro, SaffronCity_Dojo_Text_MikeDefeat, Text_NotEnoughMonsForDoubleBattle
# 39 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_MikePostBattle
	return


SaffronCity_Dojo_EventScript_RightScroll::
# 43 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
	end


SaffronCity_Dojo_EventScript_Statue::
# 48 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end


SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft::
	end


SaffronCity_Dojo_EventScript_TriggerMasterBattleRight::
	end


SaffronCity_Dojo_Text_GoesAroundComesAround::
# 61 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "What goes around comes around.$"

SaffronCity_Dojo_Text_FightingDojo::
# 65 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "FIGHTING DOJO$"

SaffronCity_Dojo_Text_EnemiesOnEverySide::
# 69 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Enemies on every side!$"

SaffronCity_Dojo_Text_AaronDefeat::
# 74 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_AaronDefeat$"

SaffronCity_Dojo_Text_AaronIntro::
# 78 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_AaronIntro$"

SaffronCity_Dojo_Text_AaronPostBattle::
# 82 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_AaronPostBattle$"

SaffronCity_Dojo_Text_ChoosePrizedFightingMon::
# 86 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_ChoosePrizedFightingMon$"

SaffronCity_Dojo_Text_HidekiDefeat::
# 90 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_HidekiDefeat$"

SaffronCity_Dojo_Text_HidekiIntro::
# 94 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_HidekiIntro$"

SaffronCity_Dojo_Text_HidekiPostBattle::
# 98 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_HidekiPostBattle$"

SaffronCity_Dojo_Text_HitoshiDefeat::
# 102 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_HitoshiDefeat$"

SaffronCity_Dojo_Text_HitoshiIntro::
# 106 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_HitoshiIntro$"

SaffronCity_Dojo_Text_HitoshiPostBattle::
# 110 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_HitoshiPostBattle$"

SaffronCity_Dojo_Text_MasterKoichiDefeat::
# 114 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_MasterKoichiDefeat$"

SaffronCity_Dojo_Text_MasterKoichiIntro::
# 118 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_MasterKoichiIntro$"

SaffronCity_Dojo_Text_MikeDefeat::
# 122 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_MikeDefeat$"

SaffronCity_Dojo_Text_MikeIntro::
# 126 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_MikeIntro$"

SaffronCity_Dojo_Text_MikePostBattle::
# 130 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Placeholder text for\n"
	.string "SaffronCity_Dojo_Text_MikePostBattle$"
