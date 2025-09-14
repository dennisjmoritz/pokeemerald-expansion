
OlivineCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_1F_OnTransition
	.byte 0

OlivineCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	end

OlivineCity_PokemonCenter_1F_EventScript_Nurse::
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
