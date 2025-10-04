SSTidalRooms_MapScripts::
	.byte 0


SSTidalRooms_EventScript_Bed::
# 6 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	end


SSTidalRooms_EventScript_Colton::
# 15 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_double TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_ColtonPostBattle
	return


SSTidalRooms_EventScript_Garret::
# 20 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_double TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_GarretPostBattle
	return


SSTidalRooms_EventScript_Jed::
# 25 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end


SSTidalRooms_EventScript_Lea::
# 30 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end


SSTidalRooms_EventScript_Micah::
# 35 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_double TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_MicahPostBattle
	return


SSTidalRooms_EventScript_Naomi::
# 40 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_double TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat, Text_NotEnoughMonsForDoubleBattle
# 41 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_NaomiPostBattle
	return


SSTidalRooms_EventScript_SnatchGiver::
	end


SSTidalRooms_EventScript_Thomas::
# 49 "data/maps/SSTidalRooms/scripts.pory"
	trainerbattle_double TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat, Text_NotEnoughMonsForDoubleBattle
# 50 "data/maps/SSTidalRooms/scripts.pory"
	msgbox SSTidalRooms_Text_ThomasPostBattle
	return


SSTidalRooms_Text_TakeRestOnBed::
# 54 "data/maps/SSTidalRooms/scripts.pory"
	.string "There's a bed… Let's take a rest.$"

SSTidalRooms_Text_ColtonDefeat::
# 59 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_ColtonDefeat$"

SSTidalRooms_Text_ColtonIntro::
# 63 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_ColtonIntro$"

SSTidalRooms_Text_ColtonPostBattle::
# 67 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_ColtonPostBattle$"

SSTidalRooms_Text_GarretDefeat::
# 71 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_GarretDefeat$"

SSTidalRooms_Text_GarretIntro::
# 75 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_GarretIntro$"

SSTidalRooms_Text_GarretPostBattle::
# 79 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_GarretPostBattle$"

SSTidalRooms_Text_MicahDefeat::
# 83 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_MicahDefeat$"

SSTidalRooms_Text_MicahIntro::
# 87 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_MicahIntro$"

SSTidalRooms_Text_MicahPostBattle::
# 91 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_MicahPostBattle$"

SSTidalRooms_Text_NaomiDefeat::
# 95 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_NaomiDefeat$"

SSTidalRooms_Text_NaomiIntro::
# 99 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_NaomiIntro$"

SSTidalRooms_Text_NaomiPostBattle::
# 103 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_NaomiPostBattle$"

SSTidalRooms_Text_ThomasDefeat::
# 107 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_ThomasDefeat$"

SSTidalRooms_Text_ThomasIntro::
# 111 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_ThomasIntro$"

SSTidalRooms_Text_ThomasPostBattle::
# 115 "data/maps/SSTidalRooms/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSTidalRooms_Text_ThomasPostBattle$"

SSTidalRooms_Text_ExplainSnatch::
# 119 "data/maps/SSTidalRooms/scripts.pory"
	.string "SNATCH steals the beneficial effects\n"
	.string "of certain moves before they can be\l"
	.string "used by a foe or ally.$"

SSTidalRooms_Text_LeaPostBattle::
# 123 "data/maps/SSTidalRooms/scripts.pory"
	.string "LEA: I can't believe it!\n"
	.string "Our lovey-dovey power failed…\l"
	.string "You must be an awesome TRAINER!$"

SSTidalRooms_Text_JedPostBattle::
# 127 "data/maps/SSTidalRooms/scripts.pory"
	.string "JED: It's the first time that our lovey-\n"
	.string "dovey power couldn't prevail!\l"
	.string "You must be an awesome TRAINER!$"
