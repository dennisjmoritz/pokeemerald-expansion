.set LOCALID_RIVAL_MOM, 1

LittlerootTown_MaysHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_OnFrame
	.byte 0

LittlerootTown_MaysHouse_1F_OnLoad:
	end

LittlerootTown_MaysHouse_1F_OnTransition:
	end

@ Many of the below scripts have no gender check because they assume youre in the correct house
LittlerootTown_MaysHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_HOUSE_STATE, 1, LittlerootTown_MaysHouse_1F_EventScript_CongratsNewHome
	.2byte 0

LittlerootTown_MaysHouse_1F_EventScript_CongratsNewHome::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	goto_if_set FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM, LittlerootTown_MaysHouse_1F_EventScript_CongratsNewHome2
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_CongratsOnHome, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSE_STATE, 2
	releaseall
	end

LittlerootTown_MaysHouse_1F_EventScript_CongratsNewHome2::
	special GetRivalSonDaughterString
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RivalsHouse_1F_EventScript_CongratsOnHome2_Male
	goto_if_eq VAR_RESULT, FEMALE, RivalsHouse_1F_EventScript_CongratsOnHome2_Female
	end

RivalsHouse_1F_EventScript_CongratsOnHome2_Male::
	msgbox RivalsHouse_1F_Text_CongratsOnHome2_Male, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSE_STATE, 2
	releaseall
	end

RivalsHouse_1F_EventScript_CongratsOnHome2_Female::
	msgbox RivalsHouse_1F_Text_CongratsOnHome2_Female, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSE_STATE, 2
	releaseall
	end

LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RivalsHouse_1F_EventScript_RivalMom::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, RivalsHouse_1F_EventScript_VisitParentsEverySoOften
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, RivalsHouse_1F_EventScript_RivalTooBusy
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_LikeChildLikeFather, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_RivalTooBusy::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RivalsHouse_1F_EventScript_RivalTooBusy_Male
	goto_if_eq VAR_RESULT, FEMALE, RivalsHouse_1F_EventScript_RivalTooBusy_Female
	msgbox RivalsHouse_1F_Text_TooBusy_Male, MSGBOX_DEFAULT
	end

RivalsHouse_1F_EventScript_RivalTooBusy_Male::
	msgbox RivalsHouse_1F_Text_TooBusy_Male, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_RivalTooBusy_Female::
	msgbox RivalsHouse_1F_Text_TooBusy_Female, MSGBOX_DEFAULT
	release
	end


RivalsHouse_1F_EventScript_RivalIsOnRoute103::
	msgbox RivalsHouse_1F_Text_WentOutToRoute103, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_VisitParentsEverySoOften::
	msgbox RivalsHouse_1F_Text_ShouldVisitParentsEverySoOften, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_EventScript_RivalSibling::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	msgbox RivalsHouse_1F_Text_DoYouHavePokemon, MSGBOX_DEFAULT
	release
	end

RivalsHouse_1F_Text_CongratsOnHome:
	.string "Oh, hello {PLAYER}{KUN}!\p"
	.string "Congratulations on inheriting your home\n"
	.string "from your parents!\p"
	.string "We are definitely going to miss them.\p"
	.string "{RIVAL} is upstairs, I think, you should\n"
	.string "go say hello!$"

RivalsHouse_1F_Text_CongratsOnHome2_Male:
	.string "Oh, hello {PLAYER}{KUN}!\p"
	.string "Congratulations on inheriting your home\n"
	.string "from your parents!\p"
	.string "We are definitely going to miss them.\p"
	.string "I think {RIVAL} is out helping her\n"
	.string "father with his research.\l"
	.string "They should be home soon!$"

RivalsHouse_1F_Text_CongratsOnHome2_Female:
	.string "Oh, hello {PLAYER}{KUN}!\p"
	.string "Congratulations on inheriting your home\n"
	.string "from your parents!\p"
	.string "We are definitely going to miss them.\p"
	.string "I think {RIVAL} is out helping his\n"
	.string "father with his research.\l"
	.string "They should be home soon!$"

RivalsHouse_1F_Text_LikeChildLikeFather:
	.string "Like child, like father.\p"
	.string "My husband is as wild about POKéMON\n"
	.string "as our child.\p"
	.string "If he's not at his LAB, he's likely\n"
	.string "scrabbling about in grassy places.$"

RivalsHouse_1F_Text_TooBusy_Male:
	.string "That {RIVAL}!\p"
	.string "Our child is always so busy with\n"
	.string "POKéMON, she's just like her father!$"

RivalsHouse_1F_Text_TooBusy_Female:
	.string "That {RIVAL}!\p"
	.string "Our child is always so busy with\n"
	.string "POKéMON... like father like son!$"

RivalsHouse_1F_Text_WentOutToRoute103:
	.string "Oh, {RIVAL} went out to ROUTE 103\n"
	.string "just a little while ago.\p"
	.string "Like father, like child.\n"
	.string "{RIVAL} can't stay quietly at home.$"

RivalsHouse_1F_Text_ShouldVisitParentsEverySoOften:
	.string "I think it's wonderful for people to\n"
	.string "travel with POKéMON.\p"
	.string "But you should should visit your\n"
	.string "parents every so often to let your\l"
	.string "mother know you're okay.\p"
	.string "She might not say it, but I'm sure she\n"
	.string "worries about you, {PLAYER}{KUN}.$"

RivalsHouse_1F_Text_DoYouHavePokemon:
	.string "Hi, neighbor!\p"
	.string "Do you already have your\n"
	.string "own POKéMON?$"
