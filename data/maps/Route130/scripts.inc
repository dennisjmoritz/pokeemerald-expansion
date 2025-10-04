Route130_MapScripts::
	.byte 0


Route130_EventScript_Katie::
# 5 "data/maps/Route130/scripts.pory"
	trainerbattle_double TRAINER_KATIE, Route130_Text_KatieIntro, Route130_Text_KatieDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route130/scripts.pory"
	msgbox Route130_Text_KatiePostBattle
	return


Route130_EventScript_Rodney::
# 10 "data/maps/Route130/scripts.pory"
	trainerbattle_double TRAINER_RODNEY, Route130_Text_RodneyIntro, Route130_Text_RodneyDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route130/scripts.pory"
	msgbox Route130_Text_RodneyPostBattle
	return


Route130_EventScript_Santiago::
# 15 "data/maps/Route130/scripts.pory"
	trainerbattle_double TRAINER_SANTIAGO, Route130_Text_SantiagoIntro, Route130_Text_SantiagoDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route130/scripts.pory"
	msgbox Route130_Text_SantiagoPostBattle
	return


Route130_Text_KatieDefeat::
# 21 "data/maps/Route130/scripts.pory"
	.string "Like the vast blue sea, the world of\n"
	.string "POKéMON spans depths beyond belief.$"

Route130_Text_KatieIntro::
# 25 "data/maps/Route130/scripts.pory"
	.string "In the deep blue sea, my shattered blue\n"
	.string "heart finds comfort among waves.$"

Route130_Text_KatiePostBattle::
# 29 "data/maps/Route130/scripts.pory"
	.string "The world's children dream of one day\n"
	.string "becoming the POKéMON CHAMPION.$"

Route130_Text_RodneyDefeat::
# 33 "data/maps/Route130/scripts.pory"
	.string "This kid's awfully tough…$"

Route130_Text_RodneyIntro::
# 37 "data/maps/Route130/scripts.pory"
	.string "What a surprise! I didn't expect to see\n"
	.string "a TRAINER out in the sea.\p"
	.string "I think we should battle!$"

Route130_Text_RodneyPostBattle::
# 41 "data/maps/Route130/scripts.pory"
	.string "Your eyes have that look of someone\n"
	.string "who's experienced harsh challenges and\l"
	.string "won. It suits you well!$"

Route130_Text_SantiagoDefeat::
# 45 "data/maps/Route130/scripts.pory"
	.string "I needed to be a little less peaceful!$"

Route130_Text_SantiagoIntro::
# 49 "data/maps/Route130/scripts.pory"
	.string "Floating on the open sea like this… It's\n"
	.string "peaceful.$"

Route130_Text_SantiagoPostBattle::
# 53 "data/maps/Route130/scripts.pory"
	.string "Swimming and battling like this… I'm one\n"
	.string "happy guy…$"
