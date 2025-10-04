ViridianForest_MapScripts::
	.byte 0


ViridianForest_EventScript_Anthony::
# 5 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_double TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_AnthonyPostBattle
	return


ViridianForest_EventScript_Boy::
# 10 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end


ViridianForest_EventScript_Charlie::
# 15 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_double TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_CharliePostBattle
	return


ViridianForest_EventScript_Doug::
# 20 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_double TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_DougPostBattle
	return


ViridianForest_EventScript_ExitSign::
# 25 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end


ViridianForest_EventScript_Rick::
# 30 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_double TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat, Text_NotEnoughMonsForDoubleBattle
# 31 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_RickPostBattle
	return


ViridianForest_EventScript_Sammy::
# 35 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_double TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SammyPostBattle
	return


ViridianForest_EventScript_TrainerTips1::
# 40 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end


ViridianForest_EventScript_TrainerTips2::
# 45 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end


ViridianForest_EventScript_TrainerTips3::
# 50 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end


ViridianForest_EventScript_TrainerTips4::
# 55 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end


ViridianForest_EventScript_TrainerTips5::
# 60 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end


ViridianForest_EventScript_Youngster::
# 65 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end


ViridianForest_Text_WeakenMonsBeforeCapture::
# 70 "data/maps/ViridianForest/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "Weaken POKéMON before attempting\n"
	.string "capture!\p"
	.string "When healthy, they may escape!$"

ViridianForest_Text_CantCatchOwnedMons::
# 74 "data/maps/ViridianForest/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "You can't catch a POKéMON that belongs\n"
	.string "to someone else.\p"
	.string "Throw POKé BALLS only at wild POKéMON\n"
	.string "to catch them!$"

ViridianForest_Text_ContactOakViaPCToRatePokedex::
# 78 "data/maps/ViridianForest/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "Contact PROF. OAK via a PC to get your\n"
	.string "POKéDEX evaluated!$"

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
# 82 "data/maps/ViridianForest/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "If your POKéMON are weak and you want\n"
	.string "to avoid battles, stay away\l"
	.string "from grassy areas!$"

ViridianForest_Text_UseAntidoteForPoison::
# 86 "data/maps/ViridianForest/scripts.pory"
	.string "For poison, use ANTIDOTE! Get it at\n"
	.string "POKéMON MARTS!$"

ViridianForest_Text_LeavingViridianForest::
# 90 "data/maps/ViridianForest/scripts.pory"
	.string "LEAVING VIRIDIAN FOREST PEWTER CITY\n"
	.string "AHEAD$"

ViridianForest_Text_AnthonyDefeat::
# 95 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_AnthonyDefeat$"

ViridianForest_Text_AnthonyIntro::
# 99 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_AnthonyIntro$"

ViridianForest_Text_AnthonyPostBattle::
# 103 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_AnthonyPostBattle$"

ViridianForest_Text_CharlieDefeat::
# 107 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_CharlieDefeat$"

ViridianForest_Text_CharlieIntro::
# 111 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_CharlieIntro$"

ViridianForest_Text_CharliePostBattle::
# 115 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_CharliePostBattle$"

ViridianForest_Text_DougDefeat::
# 119 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_DougDefeat$"

ViridianForest_Text_DougIntro::
# 123 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_DougIntro$"

ViridianForest_Text_DougPostBattle::
# 127 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_DougPostBattle$"

ViridianForest_Text_RickDefeat::
# 131 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_RickDefeat$"

ViridianForest_Text_RickIntro::
# 135 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_RickIntro$"

ViridianForest_Text_RickPostBattle::
# 139 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_RickPostBattle$"

ViridianForest_Text_SammyDefeat::
# 143 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_SammyDefeat$"

ViridianForest_Text_SammyIntro::
# 147 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_SammyIntro$"

ViridianForest_Text_SammyPostBattle::
# 151 "data/maps/ViridianForest/scripts.pory"
	.string "Placeholder text for\n"
	.string "ViridianForest_Text_SammyPostBattle$"

ViridianForest_Text_RanOutOfPokeBalls::
# 154 "data/maps/ViridianForest/scripts.pory"
	.string "I was throwing POKé BALLS to\n"
	.string "catch POKéMON, and I ran out.\p"
	.string "That's why you can never have too\n"
	.string "many POKé BALLS.$"

ViridianForest_Text_FriendsItchingToBattle::
# 158 "data/maps/ViridianForest/scripts.pory"
	.string "I came here with some friends to\n"
	.string "catch us some BUG POKéMON!\p"
	.string "They're all itching to get into\n"
	.string "some POKéMON battles!$"
