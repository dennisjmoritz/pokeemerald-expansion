Route10_PokemonCenter_1F_MapScripts::
	.byte 0


Route10_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_ROUTE_10_NURSE
	waitmessage
	waitbuttonpress
	release
	end
