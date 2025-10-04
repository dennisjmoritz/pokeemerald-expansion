Route125_MapScripts::
	.byte 0


Route125_EventScript_Auron::
# 5 "data/maps/Route125/scripts.pory"
	trainerbattle_double TRAINER_AURON, Route125_Text_AuronIntro, Route125_Text_AuronDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_AuronPostBattle
	return


Route125_EventScript_Ernest::
# 10 "data/maps/Route125/scripts.pory"
	trainerbattle_double TRAINER_ERNEST, Route125_Text_ErnestIntro, Route125_Text_ErnestDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_ErnestPostBattle
	return


Route125_EventScript_Iris::
# 15 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_IrisPostBattle, MSGBOX_AUTOCLOSE
	end


Route125_EventScript_Kim::
# 20 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_KimPostBattle, MSGBOX_AUTOCLOSE
	end


Route125_EventScript_Nolen::
# 25 "data/maps/Route125/scripts.pory"
	trainerbattle_double TRAINER_NOLEN, Route125_Text_NolenIntro, Route125_Text_NolenDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_NolenPostBattle
	return


Route125_EventScript_Presley::
# 30 "data/maps/Route125/scripts.pory"
	trainerbattle_double TRAINER_PRESLEY, Route125_Text_PresleyIntro, Route125_Text_PresleyDefeat, Text_NotEnoughMonsForDoubleBattle
# 31 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_PresleyPostBattle
	return


Route125_EventScript_Sharon::
# 35 "data/maps/Route125/scripts.pory"
	trainerbattle_double TRAINER_SHARON, Route125_Text_SharonIntro, Route125_Text_SharonDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_SharonPostBattle
	return


Route125_EventScript_Stan::
# 40 "data/maps/Route125/scripts.pory"
	trainerbattle_double TRAINER_STAN, Route125_Text_StanIntro, Route125_Text_StanDefeat, Text_NotEnoughMonsForDoubleBattle
# 41 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_StanPostBattle
	return


Route125_EventScript_Tanya::
# 45 "data/maps/Route125/scripts.pory"
	trainerbattle_double TRAINER_TANYA, Route125_Text_TanyaIntro, Route125_Text_TanyaDefeat, Text_NotEnoughMonsForDoubleBattle
# 46 "data/maps/Route125/scripts.pory"
	msgbox Route125_Text_TanyaPostBattle
	return


Route125_Text_AuronDefeat::
# 51 "data/maps/Route125/scripts.pory"
	.string "Oh, you weren't throwing trash into the\n"
	.string "sea.$"

Route125_Text_AuronIntro::
# 55 "data/maps/Route125/scripts.pory"
	.string "Hey! Was it you throwing garbage into\n"
	.string "the sea?$"

Route125_Text_AuronPostBattle::
# 59 "data/maps/Route125/scripts.pory"
	.string "I found an unsightly bottle bobbing in\n"
	.string "the waves earlier.\p"
	.string "It angers me that someone would\n"
	.string "pollute the sea!$"

Route125_Text_ErnestDefeat::
# 63 "data/maps/Route125/scripts.pory"
	.string "Gwrroooar! I couldn't win!$"

Route125_Text_ErnestIntro::
# 67 "data/maps/Route125/scripts.pory"
	.string "Ahoy! I'm a buff, tough SAILOR! I've\n"
	.string "braved the world's seas!$"

Route125_Text_ErnestPostBattle::
# 71 "data/maps/Route125/scripts.pory"
	.string "The tide ebbs and flows inside the\n"
	.string "SHOAL CAVE.\p"
	.string "By the way, it's about six hours from\n"
	.string "high tide to low tide. Did you know?$"

Route125_Text_NolenDefeat::
# 75 "data/maps/Route125/scripts.pory"
	.string "I surrender!$"

Route125_Text_NolenIntro::
# 79 "data/maps/Route125/scripts.pory"
	.string "I heard you approaching, so I hung\n"
	.string "around for you!$"

Route125_Text_NolenPostBattle::
# 83 "data/maps/Route125/scripts.pory"
	.string "Sound travels faster in water than it\n"
	.string "does through air.$"

Route125_Text_PresleyDefeat::
# 87 "data/maps/Route125/scripts.pory"
	.string "Okay. I'll tell you why I'm here.$"

Route125_Text_PresleyIntro::
# 91 "data/maps/Route125/scripts.pory"
	.string "Why would a BIRDKEEPER like me come out\n"
	.string "to the sea?$"

Route125_Text_PresleyPostBattle::
# 95 "data/maps/Route125/scripts.pory"
	.string "I put a message in a bottle and put it\n"
	.string "out to sea.\p"
	.string "I'm sure that a girl SWIMMER will find it!$"

Route125_Text_SharonDefeat::
# 99 "data/maps/Route125/scripts.pory"
	.string "Lost it…$"

Route125_Text_SharonIntro::
# 103 "data/maps/Route125/scripts.pory"
	.string "How would you like to take on the\n"
	.string "WATER-type POKéMON I raised?$"

Route125_Text_SharonPostBattle::
# 107 "data/maps/Route125/scripts.pory"
	.string "Your power… You're the real deal. I'm\n"
	.string "amazed!$"

Route125_Text_StanDefeat::
# 111 "data/maps/Route125/scripts.pory"
	.string "I floundered…$"

Route125_Text_StanIntro::
# 115 "data/maps/Route125/scripts.pory"
	.string "Hey, there! Check out my sweet POKéMON!$"

Route125_Text_StanPostBattle::
# 119 "data/maps/Route125/scripts.pory"
	.string "I was blown away by HORSEA's charm, so I\n"
	.string "started swimming, too.$"

Route125_Text_TanyaDefeat::
# 123 "data/maps/Route125/scripts.pory"
	.string "You're too much!$"

Route125_Text_TanyaIntro::
# 127 "data/maps/Route125/scripts.pory"
	.string "I'm tired of swimming. Are you up for a\n"
	.string "battle with me?$"

Route125_Text_TanyaPostBattle::
# 131 "data/maps/Route125/scripts.pory"
	.string "Whew… Which way is it to MOSSDEEP CITY?$"

Route125_Text_IrisPostBattle::
# 134 "data/maps/Route125/scripts.pory"
	.string "IRIS: KIM, are we really going into the\n"
	.string "SHOAL CAVE? We'll get all wet.$"

Route125_Text_KimPostBattle::
# 138 "data/maps/Route125/scripts.pory"
	.string "KIM: A funny old man lives in the SHOAL\n"
	.string "CAVE, doesn't he?\p"
	.string "Let's go see him, IRIS!$"
