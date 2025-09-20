CeladonCity_PokemonCenter_1F_MapScripts::
	.byte 0


CeladonCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_CELADON_NURSE
// FIXME undefined reference: 	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
