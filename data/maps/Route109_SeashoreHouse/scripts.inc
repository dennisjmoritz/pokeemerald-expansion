Route109_SeashoreHouse_MapScripts::
	.byte 0


Route109_SeashoreHouse_EventScript_Dwayne::
# 5 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_double TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle
	return


Route109_SeashoreHouse_EventScript_Johanna::
# 10 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_double TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle
	return


Route109_SeashoreHouse_EventScript_Owner::
	end


Route109_SeashoreHouse_EventScript_Simon::
# 19 "data/maps/Route109_SeashoreHouse/scripts.pory"
	trainerbattle_double TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Text_NotEnoughMonsForDoubleBattle
# 20 "data/maps/Route109_SeashoreHouse/scripts.pory"
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle
	return


Route109_SeashoreHouse_Text_DwayneDefeated::
# 25 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route109_SeashoreHouse_Text_DwayneDefeated$"

Route109_SeashoreHouse_Text_DwayneIntro::
# 29 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route109_SeashoreHouse_Text_DwayneIntro$"

Route109_SeashoreHouse_Text_DwaynePostBattle::
# 33 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route109_SeashoreHouse_Text_DwaynePostBattle$"

Route109_SeashoreHouse_Text_JohannaDefeated::
# 37 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route109_SeashoreHouse_Text_JohannaDefeated$"

Route109_SeashoreHouse_Text_JohannaIntro::
# 41 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route109_SeashoreHouse_Text_JohannaIntro$"

Route109_SeashoreHouse_Text_JohannaPostBattle::
# 45 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route109_SeashoreHouse_Text_JohannaPostBattle$"

Route109_SeashoreHouse_Text_SimonDefeated::
# 49 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route109_SeashoreHouse_Text_SimonDefeated$"

Route109_SeashoreHouse_Text_SimonIntro::
# 53 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route109_SeashoreHouse_Text_SimonIntro$"

Route109_SeashoreHouse_Text_SimonPostBattle::
# 57 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Placeholder text for\n"
	.string "Route109_SeashoreHouse_Text_SimonPostBattle$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles::
# 61 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "You're scorching hot!\n"
	.string "Those battles blazed!\l"
	.string "I'm more than just satisfied!\p"
	.string "As thanks for showing me your hot\n"
	.string "streak, I want you to take these.\p"
	.string "It's half a dozen bottles of SODA POP!$"

Route109_SeashoreHouse_Text_BagFull::
# 65 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Oh, but hey, your BAG's jammed full.\n"
	.string "I'll hang on to these for you.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop::
# 69 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Want to buy some SODA POP?\n"
	.string "POKéMON love it!\p"
	.string "Just ¥300 a bottle!\n"
	.string "Buy some!$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches::
# 73 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "Show me some hot matches!\p"
	.string "I run this SEASHORE HOUSE just for\n"
	.string "that reason alone!$"

Route109_SeashoreHouse_Text_NotEnoughMoney::
# 77 "data/maps/Route109_SeashoreHouse/scripts.pory"
	.string "You don't have the money.$"
