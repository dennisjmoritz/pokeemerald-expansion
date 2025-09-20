CeruleanCity_PokemonCenter_1F_MapScripts::
	.byte 0


CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_CERULEAN_NURSE
// FIXME undefined reference: 	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
