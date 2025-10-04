FallarborTown_Mart_MapScripts::
	.byte 0


FallarborTown_Mart_EventScript_Clerk::
	end


FallarborTown_Mart_EventScript_PokefanM::
# 9 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end


FallarborTown_Mart_EventScript_Skitty::
# 14 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	end


FallarborTown_Mart_EventScript_Woman::
# 19 "data/maps/FallarborTown_Mart/scripts.pory"
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end


FallarborTown_Mart_Text_DecidingSkittyEvolve::
# 23 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "I'm having a hard time deciding if I\n"
	.string "should make my SKITTY evolve or not.\p"
	.string "I only have to use this MOON STONE,\n"
	.string "but it's so hard to decide…\p"
	.string "If I make it evolve, it will become\n"
	.string "much stronger.\p"
	.string "But it will look so different, too.$"

FallarborTown_Mart_Text_Skitty::
# 27 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "SKITTY: Miyao?$"

FallarborTown_Mart_Text_SellNuggetIFound::
# 31 "data/maps/FallarborTown_Mart/scripts.pory"
	.string "This NUGGET I found here…\n"
	.string "I suppose I'll have to sell it, seeing\l"
	.string "as how it has no other use.$"
