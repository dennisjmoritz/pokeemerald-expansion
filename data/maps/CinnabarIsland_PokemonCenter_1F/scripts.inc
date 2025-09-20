CinnabarIsland_PokemonCenter_1F_MapScripts::
	.byte 0


CinnabarIsland_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_CINNABAR_ISLAND_NURSE
// FIXME undefined reference: 	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
