SSAnne_Deck_MapScripts::
	.byte 0


SSAnne_Deck_EventScript_BaldingMan::
# 5 "data/maps/SSAnne_Deck/scripts.pory"
	msgbox SSAnne_Deck_Text_FeelSeasick, MSGBOX_NPC
	end


SSAnne_Deck_EventScript_Edmond::
# 10 "data/maps/SSAnne_Deck/scripts.pory"
	trainerbattle_double TRAINER_SAILOR_EDMOND, SSAnne_Deck_Text_EdmondIntro, SSAnne_Deck_Text_EdmondDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/SSAnne_Deck/scripts.pory"
	msgbox SSAnne_Deck_Text_EdmondPostBattle
	return


SSAnne_Deck_EventScript_Sailor::
# 15 "data/maps/SSAnne_Deck/scripts.pory"
	msgbox SSAnne_Deck_Text_ScrubbingDecksHardWork, MSGBOX_NPC
	end


SSAnne_Deck_EventScript_Trevor::
# 20 "data/maps/SSAnne_Deck/scripts.pory"
	trainerbattle_double TRAINER_SAILOR_TREVOR, SSAnne_Deck_Text_TrevorIntro, SSAnne_Deck_Text_TrevorDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/SSAnne_Deck/scripts.pory"
	msgbox SSAnne_Deck_Text_TrevorPostBattle
	return


SSAnne_Deck_EventScript_Youngster::
# 25 "data/maps/SSAnne_Deck/scripts.pory"
	msgbox SSAnne_Deck_Text_ShipDepartingSoon, MSGBOX_NPC
	end


SSAnne_Deck_Text_EdmondDefeat::
# 31 "data/maps/SSAnne_Deck/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_Deck_Text_EdmondDefeat$"

SSAnne_Deck_Text_EdmondIntro::
# 35 "data/maps/SSAnne_Deck/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_Deck_Text_EdmondIntro$"

SSAnne_Deck_Text_EdmondPostBattle::
# 39 "data/maps/SSAnne_Deck/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_Deck_Text_EdmondPostBattle$"

SSAnne_Deck_Text_TrevorDefeat::
# 43 "data/maps/SSAnne_Deck/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_Deck_Text_TrevorDefeat$"

SSAnne_Deck_Text_TrevorIntro::
# 47 "data/maps/SSAnne_Deck/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_Deck_Text_TrevorIntro$"

SSAnne_Deck_Text_TrevorPostBattle::
# 51 "data/maps/SSAnne_Deck/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_Deck_Text_TrevorPostBattle$"

SSAnne_Deck_Text_FeelSeasick::
# 54 "data/maps/SSAnne_Deck/scripts.pory"
	.string "Urf… I feel ill…\p"
	.string "I got seasick, so I stepped out to\n"
	.string "get some air…$"

SSAnne_Deck_Text_ScrubbingDecksHardWork::
# 58 "data/maps/SSAnne_Deck/scripts.pory"
	.string "Whew!\n"
	.string "Scrubbing decks is hard work!$"

SSAnne_Deck_Text_ShipDepartingSoon::
# 62 "data/maps/SSAnne_Deck/scripts.pory"
	.string "The party's over.\n"
	.string "The ship will be departing soon.$"
