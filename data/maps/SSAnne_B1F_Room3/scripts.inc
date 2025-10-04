SSAnne_B1F_Room3_MapScripts::
	.byte 0


SSAnne_B1F_Room3_EventScript_Dylan::
# 5 "data/maps/SSAnne_B1F_Room3/scripts.pory"
	trainerbattle_double TRAINER_SAILOR_DYLAN, SSAnne_B1F_Room3_Text_DylanIntro, SSAnne_B1F_Room3_Text_DylanDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/SSAnne_B1F_Room3/scripts.pory"
	msgbox SSAnne_B1F_Room3_Text_DylanPostBattle
	return


SSAnne_B1F_Room3_EventScript_ItemEther::
	end


SSAnne_B1F_Room3_Text_DylanDefeat::
# 15 "data/maps/SSAnne_B1F_Room3/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room3_Text_DylanDefeat$"

SSAnne_B1F_Room3_Text_DylanIntro::
# 19 "data/maps/SSAnne_B1F_Room3/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room3_Text_DylanIntro$"

SSAnne_B1F_Room3_Text_DylanPostBattle::
# 23 "data/maps/SSAnne_B1F_Room3/scripts.pory"
	.string "Placeholder text for\n"
	.string "SSAnne_B1F_Room3_Text_DylanPostBattle$"
