LavenderTown_MapScripts::
	.byte 0


LavenderTown_EventScript_Boy::
# 5 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end


LavenderTown_EventScript_LittleGirl::
# 10 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	end


LavenderTown_EventScript_PokemonTowerSign::
# 15 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end


LavenderTown_EventScript_SilphScopeNotice::
# 20 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end


LavenderTown_EventScript_TownSign::
# 25 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end


LavenderTown_EventScript_VolunteerHouseSign::
# 30 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end


LavenderTown_EventScript_WorkerM::
# 35 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end


LavenderTown_Text_TownSign::
# 40 "data/maps/LavenderTown/scripts.pory"
	.string "LAVENDER TOWN The Noble Purple Town$"

LavenderTown_Text_PokemonTowerSign::
# 44 "data/maps/LavenderTown/scripts.pory"
	.string "POKéMON TOWER Becalm the Spirits of\n"
	.string "POKéMON$"

LavenderTown_Text_SilphScopeNotice::
# 48 "data/maps/LavenderTown/scripts.pory"
	.string "New SILPH SCOPE! Make the Invisible\n"
	.string "Plain to See!\p"
	.string "SILPH CO.$"

LavenderTown_Text_VolunteerPokemonHouse::
# 52 "data/maps/LavenderTown/scripts.pory"
	.string "LAVENDER VOLUNTEER POKéMON HOUSE$"

LavenderTown_Text_GhostsAppearedInTower::
# 56 "data/maps/LavenderTown/scripts.pory"
	.string "Ghosts appeared in POKéMON TOWER.\p"
	.string "I think they're the spirits of\n"
	.string "POKéMON that the ROCKETS killed.$"

LavenderTown_Text_DoYouBelieveInGhosts::
# 60 "data/maps/LavenderTown/scripts.pory"
	.string "Do you believe in ghosts?$"

LavenderTown_Text_TownKnownAsMonGraveSite::
# 64 "data/maps/LavenderTown/scripts.pory"
	.string "This town is known as the grave\n"
	.string "site of POKéMON.\p"
	.string "Memorial services are held in\n"
	.string "POKéMON TOWER.$"
