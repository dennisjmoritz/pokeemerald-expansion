
OneIsland_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_PokemonCenter_1F_OnTransition
	.byte 0

OneIsland_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_ONE_ISLAND
	end

OneIsland_PokemonCenter_1F_EventScript_Nurse::
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
