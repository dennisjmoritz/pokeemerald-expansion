MeteorFalls_1F_2R_MapScripts::
	.byte 0


MeteorFalls_1F_2R_EventScript_Jay::
	end


MeteorFalls_1F_2R_EventScript_John::
	end


MeteorFalls_1F_2R_EventScript_Nicolas::
# 13 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	trainerbattle_double TRAINER_NICOLAS, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, Text_NotEnoughMonsForDoubleBattle
# 14 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle
	return


MeteorFalls_1F_2R_Text_NicolasDefeat::
# 19 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Placeholder text for\n"
	.string "MeteorFalls_1F_2R_Text_NicolasDefeat$"

MeteorFalls_1F_2R_Text_NicolasIntro::
# 23 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Placeholder text for\n"
	.string "MeteorFalls_1F_2R_Text_NicolasIntro$"

MeteorFalls_1F_2R_Text_NicolasPostBattle::
# 27 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "Placeholder text for\n"
	.string "MeteorFalls_1F_2R_Text_NicolasPostBattle$"

MeteorFalls_1F_2R_Text_JohnPostRematch::
# 31 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JOHN: Married for fifty years…\p"
	.string "On reflection, the dear wife and I,\n"
	.string "we battled day in and day out…$"

MeteorFalls_1F_2R_Text_NicolasRegister::
# 35 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "I want to know more about your power.\n"
	.string "Let me register you in my POKéNAV.$"

MeteorFalls_1F_2R_Text_NicolasPostRematch::
# 39 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "You've obviously kept up your\n"
	.string "POKéMON training.\p"
	.string "So long as you remain strong, I, too,\n"
	.string "can become stronger!$"

MeteorFalls_1F_2R_Text_JohnRegister::
# 43 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JOHN: Young TRAINER, if the chance\n"
	.string "arises, will you battle with us again?$"

MeteorFalls_1F_2R_Text_JayPostRematch::
# 47 "data/maps/MeteorFalls_1F_2R/scripts.pory"
	.string "JAY: Fifty years of marriage…\n"
	.string "Many things have happened.\p"
	.string "I hope that we will continue to make\n"
	.string "happy memories together.$"
