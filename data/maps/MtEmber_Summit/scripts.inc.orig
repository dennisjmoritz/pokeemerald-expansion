MtEmber_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtEmber_Summit_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MtEmber_Summit_OnResume
	.byte 0

MtEmber_Summit_OnResume::
	call_if_set FLAG_TEMP_1, MtEmber_Summit_EventScript_TryRemoveMoltres
// Replaced FLAG_SYS_SPECIAL_WILD_BATTLE with FLAG_TEMP_1
	end

MtEmber_Summit_EventScript_TryRemoveMoltres::
	specialvar VAR_RESULT, GetBattleOutcome
// FIXME undefined reference: 	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
	removeobject VAR_LAST_TALKED
	return

MtEmber_Summit_OnTransition::
	call_if_unset FLAG_TEMP_1, MtEmber_Summit_EventScript_ShowMoltres
// Replaced FLAG_FOUGHT_MOLTRES with FLAG_TEMP_1
	end

MtEmber_Summit_EventScript_ShowMoltres::
	clearflag FLAG_TEMP_1
// Replaced FLAG_HIDE_MOLTRES with FLAG_TEMP_1
	return

MtEmber_Summit_EventScript_Moltres::
@	goto_if_questlog EventScript_ReleaseEnd
// FIXME undefined reference: 	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_MOLTRES, 50
	waitse
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
// FIXME undefined reference: 	message Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_TEMP_1
// Replaced FLAG_SYS_SPECIAL_WILD_BATTLE with FLAG_TEMP_1
// FIXME undefined reference: 	special StartLegendaryBattle
	waitstate
	clearflag FLAG_TEMP_1
// Replaced FLAG_SYS_SPECIAL_WILD_BATTLE with FLAG_TEMP_1
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtEmber_Summit_EventScript_DefeatedMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtEmber_Summit_EventScript_RanFromMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtEmber_Summit_EventScript_RanFromMoltres
	setflag FLAG_TEMP_1
// Replaced FLAG_FOUGHT_MOLTRES with FLAG_TEMP_1
	release
	end

MtEmber_Summit_EventScript_DefeatedMoltres::
	setflag FLAG_TEMP_1
// Replaced FLAG_FOUGHT_MOLTRES with FLAG_TEMP_1
// FIXME undefined reference: 	goto EventScript_RemoveStaticMon
	end

MtEmber_Summit_EventScript_RanFromMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
// FIXME undefined reference: 	goto EventScript_MonFlewAway
	end
