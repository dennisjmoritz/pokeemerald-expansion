SevenIsland_MapScripts::
	.byte 0


SevenIsland_EventScript_IslandSign::
# 5 "data/maps/SevenIsland/scripts.pory"
	msgbox SevenIsland_Text_IslandSign, MSGBOX_SIGN
	end


SevenIsland_EventScript_OldWoman::
# 10 "data/maps/SevenIsland/scripts.pory"
	msgbox SevenIsland_Text_IslandsMadeInSevenDays, MSGBOX_NPC
	end


SevenIsland_EventScript_Scientist::
# 15 "data/maps/SevenIsland/scripts.pory"
	msgbox SevenIsland_Text_IslandVirtuallyUntouched, MSGBOX_NPC
	end


SevenIsland_Text_IslandSign::
# 20 "data/maps/SevenIsland/scripts.pory"
	.string "SEVEN ISLAND Quest Island of Infinity$"

SevenIsland_Text_IslandsMadeInSevenDays::
# 24 "data/maps/SevenIsland/scripts.pory"
	.string "These islands are called the SEVII\n"
	.string "ISLANDS because there are seven.\p"
	.string "…Or at least that's what the young\n"
	.string "people believe.\p"
	.string "The truth is, these islands are so\n"
	.string "named because they are said to\l"
	.string "have been made in seven days.$"

SevenIsland_Text_IslandVirtuallyUntouched::
# 28 "data/maps/SevenIsland/scripts.pory"
	.string "This island has been left virtually\n"
	.string "untouched in its natural state.\p"
	.string "It could be a little difficult to\n"
	.string "hike around because of that.$"
