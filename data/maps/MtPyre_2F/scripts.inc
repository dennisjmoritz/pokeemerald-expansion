MtPyre_2F_MapScripts::
	.byte 0


MtPyre_2F_EventScript_Dez::
# 5 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end


MtPyre_2F_EventScript_Leah::
# 10 "data/maps/MtPyre_2F/scripts.pory"
	trainerbattle_double TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_LeahPostBattle
	return


MtPyre_2F_EventScript_Luke::
# 15 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end


MtPyre_2F_EventScript_Mark::
# 20 "data/maps/MtPyre_2F/scripts.pory"
	trainerbattle_double TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_MarkPostBattle
	return


MtPyre_2F_EventScript_PokefanM::
# 25 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end


MtPyre_2F_EventScript_Woman::
# 30 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end


MtPyre_2F_EventScript_Zander::
# 35 "data/maps/MtPyre_2F/scripts.pory"
	trainerbattle_double TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/MtPyre_2F/scripts.pory"
	msgbox MtPyre_2F_Text_ZanderPostBattle
	return


MtPyre_2F_Text_LeahDefeat::
# 41 "data/maps/MtPyre_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_2F_Text_LeahDefeat$"

MtPyre_2F_Text_LeahIntro::
# 45 "data/maps/MtPyre_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_2F_Text_LeahIntro$"

MtPyre_2F_Text_LeahPostBattle::
# 49 "data/maps/MtPyre_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_2F_Text_LeahPostBattle$"

MtPyre_2F_Text_MarkDefeat::
# 53 "data/maps/MtPyre_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_2F_Text_MarkDefeat$"

MtPyre_2F_Text_MarkIntro::
# 57 "data/maps/MtPyre_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_2F_Text_MarkIntro$"

MtPyre_2F_Text_MarkPostBattle::
# 61 "data/maps/MtPyre_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_2F_Text_MarkPostBattle$"

MtPyre_2F_Text_ZanderDefeat::
# 65 "data/maps/MtPyre_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_2F_Text_ZanderDefeat$"

MtPyre_2F_Text_ZanderIntro::
# 69 "data/maps/MtPyre_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_2F_Text_ZanderIntro$"

MtPyre_2F_Text_ZanderPostBattle::
# 73 "data/maps/MtPyre_2F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MtPyre_2F_Text_ZanderPostBattle$"

MtPyre_2F_Text_LukePostBattle::
# 77 "data/maps/MtPyre_2F/scripts.pory"
	.string "LUKE: Well, we lost but that's okay!\n"
	.string "I'm right here by your side.\l"
	.string "We'll make it through this dare!$"

MtPyre_2F_Text_DezPostBattle::
# 81 "data/maps/MtPyre_2F/scripts.pory"
	.string "DEZ: We're lovey-dovey, so we don't\n"
	.string "care if we lose!$"

MtPyre_2F_Text_TumbledFromFloorAbove::
# 85 "data/maps/MtPyre_2F/scripts.pory"
	.string "Ooch, ouch… There are holes in the\n"
	.string "ground here and there.\p"
	.string "I didn't notice and took a tumble from\n"
	.string "the floor above.$"

MtPyre_2F_Text_MemoriesOfSkitty::
# 89 "data/maps/MtPyre_2F/scripts.pory"
	.string "Memories of my darling SKITTY…\n"
	.string "My eyes overflow thinking about it.$"
