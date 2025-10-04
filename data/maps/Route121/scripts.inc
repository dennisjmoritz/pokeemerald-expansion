Route121_MapScripts::
	.byte 0


Route121_EventScript_AquaGruntsMoveOut::
# 5 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_OkayMoveOutToMtPyre, MSGBOX_DEFAULT
	end


Route121_EventScript_Cale::
# 10 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_CALE, Route121_Text_CaleIntro, Route121_Text_CaleDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CalePostBattle
	return


Route121_EventScript_Cristin::
# 15 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_CRISTIN, Route121_Text_CristinIntro, Route121_Text_CristinDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_CristinPostBattle
	return


Route121_EventScript_Jessica::
# 20 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_JESSICA, Route121_Text_JessicaIntro, Route121_Text_JessicaDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JessicaPostBattle
	return


Route121_EventScript_Joy::
# 25 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
	end


Route121_EventScript_Kate::
# 30 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_KatePostBattle, MSGBOX_AUTOCLOSE
	end


Route121_EventScript_Marcel::
# 35 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_MARCEL, Route121_Text_MarcelIntro, Route121_Text_MarcelDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MarcelPostBattle
	return


Route121_EventScript_MtPyrePierSign::
# 40 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MtPyrePierSign, MSGBOX_SIGN
	end


Route121_EventScript_Myles::
# 45 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_MYLES, Route121_Text_MylesIntro, Route121_Text_MylesDefeat, Text_NotEnoughMonsForDoubleBattle
# 46 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_MylesPostBattle
	return


Route121_EventScript_Pat::
# 50 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_PAT, Route121_Text_PatIntro, Route121_Text_PatDefeat, Text_NotEnoughMonsForDoubleBattle
# 51 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_PatPostBattle
	return


Route121_EventScript_SafariZoneSign::
# 55 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_SafariZoneSign, MSGBOX_SIGN
	end


Route121_EventScript_Tammy::
# 60 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_TAMMY, Route121_Text_TammyIntro, Route121_Text_TammyDefeat, Text_NotEnoughMonsForDoubleBattle
# 61 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_TammyPostBattle
	return


Route121_EventScript_Vanessa::
# 65 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_VANESSA, Route121_Text_VanessaIntro, Route121_Text_VanessaDefeat, Text_NotEnoughMonsForDoubleBattle
# 66 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_VanessaPostBattle
	return


Route121_EventScript_Walter::
# 70 "data/maps/Route121/scripts.pory"
	trainerbattle_double TRAINER_WALTER, Route121_Text_WalterIntro, Route121_Text_WalterDefeat, Text_NotEnoughMonsForDoubleBattle
# 71 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_WalterPostBattle
	return


Route121_EventScript_Woman::
# 75 "data/maps/Route121/scripts.pory"
	msgbox Route121_Text_AheadLoomsMtPyre, MSGBOX_NPC
	end


Route121_Text_SafariZoneSign::
# 80 "data/maps/Route121/scripts.pory"
	.string "“Filled with rare POKéMON!” SAFARI ZONE$"

Route121_Text_MtPyrePierSign::
# 84 "data/maps/Route121/scripts.pory"
	.string "MT. PYRE PIER\p"
	.string "…The sign is old and worn out. The words\n"
	.string "are barely legible…$"

Route121_Text_CaleDefeat::
# 89 "data/maps/Route121/scripts.pory"
	.string "Of course I lost! I'm holding stuff in\n"
	.string "both hands!$"

Route121_Text_CaleIntro::
# 93 "data/maps/Route121/scripts.pory"
	.string "Can't you see that I have all this stuff\n"
	.string "with me?\p"
	.string "Despite that, you still insist that we\n"
	.string "battle?$"

Route121_Text_CalePostBattle::
# 97 "data/maps/Route121/scripts.pory"
	.string "I bought too much stuff at the\n"
	.string "LILYCOVE DEPT. STORE.\p"
	.string "It's up the road from here. I wish I had\n"
	.string "a BAG like yours.$"

Route121_Text_CristinDefeat::
# 101 "data/maps/Route121/scripts.pory"
	.string "No! You're horrid!$"

Route121_Text_CristinIntro::
# 105 "data/maps/Route121/scripts.pory"
	.string "I have this routine. Defeat five\n"
	.string "TRAINERS a day. Guess what? You're\l"
	.string "number five!$"

Route121_Text_CristinPostBattle::
# 109 "data/maps/Route121/scripts.pory"
	.string "I didn't expect to lose this easily… I'll\n"
	.string "win next time!$"

Route121_Text_JessicaDefeat::
# 113 "data/maps/Route121/scripts.pory"
	.string "Oh, how dare you! Don't take it so\n"
	.string "seriously!$"

Route121_Text_JessicaIntro::
# 117 "data/maps/Route121/scripts.pory"
	.string "Stop! Have a good look at my precious\n"
	.string "POKéMON!$"

Route121_Text_JessicaPostBattle::
# 121 "data/maps/Route121/scripts.pory"
	.string "Maybe I'll go catch more POKéMON at the\n"
	.string "SAFARI.$"

Route121_Text_MarcelDefeat::
# 125 "data/maps/Route121/scripts.pory"
	.string "Oh, now what happened here?$"

Route121_Text_MarcelIntro::
# 129 "data/maps/Route121/scripts.pory"
	.string "My POKéMON have never tasted defeat!\n"
	.string "On their next win, I'm entering them in\l"
	.string "CONTESTS.$"

Route121_Text_MarcelPostBattle::
# 133 "data/maps/Route121/scripts.pory"
	.string "I may have to train my gang some more\n"
	.string "before entering any CONTEST.$"

Route121_Text_MylesDefeat::
# 137 "data/maps/Route121/scripts.pory"
	.string "Super awesome!$"

Route121_Text_MylesIntro::
# 141 "data/maps/Route121/scripts.pory"
	.string "There's nothing I love more than\n"
	.string "checking out other people's POKéMON!$"

Route121_Text_MylesPostBattle::
# 145 "data/maps/Route121/scripts.pory"
	.string "They're great, your POKéMON! How do you\n"
	.string "raise them?$"

Route121_Text_PatDefeat::
# 149 "data/maps/Route121/scripts.pory"
	.string "Wow! Spectacular!$"

Route121_Text_PatIntro::
# 153 "data/maps/Route121/scripts.pory"
	.string "I want everybody to see the POKéMON\n"
	.string "I've raised!$"

Route121_Text_PatPostBattle::
# 157 "data/maps/Route121/scripts.pory"
	.string "I raise every POKéMON with the same\n"
	.string "love and care--I don't pick favorites.$"

Route121_Text_TammyDefeat::
# 161 "data/maps/Route121/scripts.pory"
	.string "I have lost…$"

Route121_Text_TammyIntro::
# 165 "data/maps/Route121/scripts.pory"
	.string "There are powers beyond our\n"
	.string "understanding in the world…$"

Route121_Text_TammyPostBattle::
# 169 "data/maps/Route121/scripts.pory"
	.string "MT. PYRE… There is a mysterious power\n"
	.string "at work there…$"

Route121_Text_VanessaDefeat::
# 173 "data/maps/Route121/scripts.pory"
	.string "This isn't what I meant!$"

Route121_Text_VanessaIntro::
# 177 "data/maps/Route121/scripts.pory"
	.string "Will you play with my delightfully\n"
	.string "pretty POKéMON?$"

Route121_Text_VanessaPostBattle::
# 181 "data/maps/Route121/scripts.pory"
	.string "I'm going to a CONTEST in LILYCOVE.\p"
	.string "My POKéMON should have no problem\n"
	.string "sweeping the MASTER CLASS.$"

Route121_Text_WalterDefeat::
# 185 "data/maps/Route121/scripts.pory"
	.string "Ah, well played.$"

Route121_Text_WalterIntro::
# 189 "data/maps/Route121/scripts.pory"
	.string "With my POKéMON, I have traveled to the\n"
	.string "world's four corners.\p"
	.string "You might say I have some confidence in\n"
	.string "my abilities.$"

Route121_Text_WalterPostBattle::
# 193 "data/maps/Route121/scripts.pory"
	.string "I would like to circle the globe once\n"
	.string "again with my POKéMON.$"

Route121_Text_OkayMoveOutToMtPyre::
# 197 "data/maps/Route121/scripts.pory"
	.string "Okay!\n"
	.string "We're to move out to MT. PYRE!$"

Route121_Text_AheadLoomsMtPyre::
# 201 "data/maps/Route121/scripts.pory"
	.string "Ahead looms MT. PYRE…\p"
	.string "It is a natural monument to the spirits\n"
	.string "of departed POKéMON…$"

Route121_Text_JoyPostBattle::
# 205 "data/maps/Route121/scripts.pory"
	.string "JOY: Ehehe, I'll have to train with KATE,\n"
	.string "my senior student partner, again.$"

Route121_Text_KatePostBattle::
# 209 "data/maps/Route121/scripts.pory"
	.string "KATE: When someone's relying on me, I\n"
	.string "get this urge to look cool in front of\l"
	.string "them…$"
