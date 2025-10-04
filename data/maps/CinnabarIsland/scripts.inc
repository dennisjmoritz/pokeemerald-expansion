CinnabarIsland_MapScripts::
	.byte 0


CinnabarIsland_EventScript_GymDoorLocked::
	end


CinnabarIsland_EventScript_GymSign::
# 11 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end


CinnabarIsland_EventScript_IslandSign::
# 17 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_IslandSign, MSGBOX_SIGN
	end


CinnabarIsland_EventScript_OldMan::
# 22 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_ScientistsExperimentInMansion, MSGBOX_NPC
	end


CinnabarIsland_EventScript_PokemonLabSign::
# 27 "data/maps/CinnabarIsland/scripts.pory"
	msgbox CinnabarIsland_Text_PokemonLab, MSGBOX_SIGN
	end


CinnabarIsland_EventScript_Woman::
	end


CinnabarIsland_Text_PokemonLab::
# 36 "data/maps/CinnabarIsland/scripts.pory"
	.string "POKéMON LAB$"

CinnabarIsland_Text_IslandSign::
# 40 "data/maps/CinnabarIsland/scripts.pory"
	.string "CINNABAR ISLAND The Fiery Town of\n"
	.string "Burning Desire$"

CinnabarIsland_Text_GymSign::
# 44 "data/maps/CinnabarIsland/scripts.pory"
	.string "CINNABAR ISLAND POKéMON GYM LEADER:\n"
	.string "BLAINE\l"
	.string "The Hotheaded Quiz Master!$"

CinnabarIsland_Text_ScientistsExperimentInMansion::
# 48 "data/maps/CinnabarIsland/scripts.pory"
	.string "Scientists conduct experiments\n"
	.string "in the burned-out building.\p"
	.string "You know, the one they call the\n"
	.string "POKéMON MANSION.$"
