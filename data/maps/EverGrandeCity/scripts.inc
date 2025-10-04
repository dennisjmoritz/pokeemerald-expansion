EverGrandeCity_MapScripts::
	.byte 0


EverGrandeCity_EventScript_CitySign::
# 5 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end


EverGrandeCity_EventScript_PokemonLeagueSign::
# 10 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end


EverGrandeCity_EventScript_SetVisitedEverGrande::
	end


EverGrandeCity_EventScript_VictoryRoadSign::
# 19 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end


EverGrandeCity_Text_CitySign::
# 24 "data/maps/EverGrandeCity/scripts.pory"
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea, and\n"
	.string "POKéMON.”$"

EverGrandeCity_Text_EnteringVictoryRoad::
# 28 "data/maps/EverGrandeCity/scripts.pory"
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague::
# 32 "data/maps/EverGrandeCity/scripts.pory"
	.string "ENTERING POKéMON LEAGUE CENTER GATE$"
