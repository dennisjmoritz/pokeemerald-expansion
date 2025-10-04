OneIsland_MapScripts::
	.byte 0


OneIsland_EventScript_BaldingMan::
# 5 "data/maps/OneIsland/scripts.pory"
	msgbox OneIsland_Text_IsntWarmClimateHereGreat, MSGBOX_NPC
	end


OneIsland_EventScript_IslandSign::
# 10 "data/maps/OneIsland/scripts.pory"
	msgbox OneIsland_Text_IslandSign, MSGBOX_SIGN
	end


OneIsland_EventScript_OldMan::
	end


OneIsland_EventScript_PokemonNetCenterSign::
# 19 "data/maps/OneIsland/scripts.pory"
	msgbox OneIsland_Text_PokemonNetCenterSign, MSGBOX_SIGN
	end


OneIsland_Text_IslandSign::
# 24 "data/maps/OneIsland/scripts.pory"
	.string "ONE ISLAND Friends Gather at Knot\n"
	.string "Island$"

OneIsland_Text_PokemonNetCenterSign::
# 28 "data/maps/OneIsland/scripts.pory"
	.string "Expanding the POKéMON World! POKéMON\n"
	.string "NET CENTER$"

OneIsland_Text_IsntWarmClimateHereGreat::
# 32 "data/maps/OneIsland/scripts.pory"
	.string "Hi, sight-seeing, are you?\n"
	.string "Isn't the warm climate here great?$"
