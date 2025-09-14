
Route28_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route28_PokemonCenter_1F_OnTransition
	.byte 0

Route28_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_ROUTE32
	end

Route28_PokemonCenter_1F_EventScript_Nurse::
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
