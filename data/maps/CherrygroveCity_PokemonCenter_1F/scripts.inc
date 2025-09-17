CherrygroveCity_PokemonCenter_1F_MapScripts::
	.byte 0


CherrygroveCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_CHERRYGROVE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
