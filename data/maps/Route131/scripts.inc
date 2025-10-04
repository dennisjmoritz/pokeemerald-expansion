Route131_MapScripts::
	.byte 0


Route131_EventScript_Herman::
# 5 "data/maps/Route131/scripts.pory"
	trainerbattle_double TRAINER_HERMAN, Route131_Text_HermanIntro, Route131_Text_HermanDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_HermanPostBattle
	return


Route131_EventScript_Ian::
# 10 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_IanPostBattle, MSGBOX_AUTOCLOSE
	end


Route131_EventScript_Kara::
# 15 "data/maps/Route131/scripts.pory"
	trainerbattle_double TRAINER_KARA, Route131_Text_KaraIntro, Route131_Text_KaraDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_KaraPostBattle
	return


Route131_EventScript_Kevin::
# 20 "data/maps/Route131/scripts.pory"
	trainerbattle_double TRAINER_KEVIN, Route131_Text_KevinIntro, Route131_Text_KevinDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_KevinPostBattle
	return


Route131_EventScript_Reli::
# 25 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_ReliPostBattle, MSGBOX_AUTOCLOSE
	end


Route131_EventScript_Richard::
# 30 "data/maps/Route131/scripts.pory"
	trainerbattle_double TRAINER_RICHARD, Route131_Text_RichardIntro, Route131_Text_RichardDefeat, Text_NotEnoughMonsForDoubleBattle
# 31 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_RichardPostBattle
	return


Route131_EventScript_Susie::
# 35 "data/maps/Route131/scripts.pory"
	trainerbattle_double TRAINER_SUSIE, Route131_Text_SusieIntro, Route131_Text_SusieDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_SusiePostBattle
	return


Route131_EventScript_Talia::
# 40 "data/maps/Route131/scripts.pory"
	trainerbattle_double TRAINER_TALIA, Route131_Text_TaliaIntro, Route131_Text_TaliaDefeat, Text_NotEnoughMonsForDoubleBattle
# 41 "data/maps/Route131/scripts.pory"
	msgbox Route131_Text_TaliaPostBattle
	return


Route131_Text_HermanDefeat::
# 46 "data/maps/Route131/scripts.pory"
	.string "Bleah!$"

Route131_Text_HermanIntro::
# 50 "data/maps/Route131/scripts.pory"
	.string "The sea… The sea… The sea… The sea as\n"
	.string "far as these eyes can see! I'm sick and\l"
	.string "tired of the sea!$"

Route131_Text_HermanPostBattle::
# 54 "data/maps/Route131/scripts.pory"
	.string "Bored I am by the sea, but swim I must.\p"
	.string "I'm a born swimmer! That's what I am.$"

Route131_Text_KaraDefeat::
# 58 "data/maps/Route131/scripts.pory"
	.string "I'm out of my depth!$"

Route131_Text_KaraIntro::
# 62 "data/maps/Route131/scripts.pory"
	.string "Why do men love bathing suits so much?\p"
	.string "They all ogle me!$"

Route131_Text_KaraPostBattle::
# 66 "data/maps/Route131/scripts.pory"
	.string "Maybe it's not my bathing suit that\n"
	.string "makes men look. It must be my beauty!$"

Route131_Text_KevinDefeat::
# 70 "data/maps/Route131/scripts.pory"
	.string "Oops!$"

Route131_Text_KevinIntro::
# 74 "data/maps/Route131/scripts.pory"
	.string "The people of PACIFIDLOG are a\n"
	.string "peaceful bunch.\p"
	.string "They never get angry. That goes for me,\n"
	.string "too.$"

Route131_Text_KevinPostBattle::
# 78 "data/maps/Route131/scripts.pory"
	.string "Tch! …Oh, wait. I'm not angry. Honestly!\p"
	.string "But, boy, you're strong! Hahaha!$"

Route131_Text_RichardDefeat::
# 82 "data/maps/Route131/scripts.pory"
	.string "POKéMON raised by TRAINERS are\n"
	.string "seriously tough…$"

Route131_Text_RichardIntro::
# 86 "data/maps/Route131/scripts.pory"
	.string "The sea is teeming with POKéMON. It's\n"
	.string "not easy swimming, I tell you.$"

Route131_Text_RichardPostBattle::
# 90 "data/maps/Route131/scripts.pory"
	.string "Gasp… Gasp… I'm wiped out…\p"
	.string "The going's easy. It's the leaving\n"
	.string "that's the hard part.\p"
	.string "Will I have any energy left to make the\n"
	.string "return trip?$"

Route131_Text_SusieDefeat::
# 94 "data/maps/Route131/scripts.pory"
	.string "You're tough in spite of the way you\n"
	.string "look!$"

Route131_Text_SusieIntro::
# 98 "data/maps/Route131/scripts.pory"
	.string "Hi, sweetie, wait! We should battle, you\n"
	.string "and I!$"

Route131_Text_SusiePostBattle::
# 102 "data/maps/Route131/scripts.pory"
	.string "Did you see a guy over there who whines\n"
	.string "that he's bored of the sea?\p"
	.string "That's all talk. He's hopelessly in love\n"
	.string "with the sea!$"

Route131_Text_TaliaDefeat::
# 106 "data/maps/Route131/scripts.pory"
	.string "Oh? Did I lose?$"

Route131_Text_TaliaIntro::
# 110 "data/maps/Route131/scripts.pory"
	.string "If you can beat me, I'll give you some\n"
	.string "great information!$"

Route131_Text_TaliaPostBattle::
# 114 "data/maps/Route131/scripts.pory"
	.string "There is an odd place nearby. There's a\n"
	.string "huge tower there. Why don't you go take\l"
	.string "a look?$"

Route131_Text_IanPostBattle::
# 117 "data/maps/Route131/scripts.pory"
	.string "IAN: You know how PACIFIDLOG is a\n"
	.string "floating town?\p"
	.string "So, wherever there is the sea, that's a\n"
	.string "part of PACIFIDLOG!$"

Route131_Text_ReliPostBattle::
# 121 "data/maps/Route131/scripts.pory"
	.string "RELI: The people of PACIFIDLOG are\n"
	.string "together with the sea and POKéMON from\l"
	.string "the time they are born.$"
