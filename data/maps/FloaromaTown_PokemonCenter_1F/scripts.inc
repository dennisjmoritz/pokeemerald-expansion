FloaromaTown_PokemonCenter_1F_MapScripts::
	.byte 0


FloaromaTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FLOAROMA_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
