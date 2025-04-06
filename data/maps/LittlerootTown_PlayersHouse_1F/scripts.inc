.set LOCALID_MOM, 1

LittlerootTown_PlayersHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_PlayersHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_PlayersHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_PlayersHouse_1F_OnFrame
	.byte 0

LittlerootTown_PlayersHouse_1F_OnLoad:
	call_if_lt VAR_INTRO_STATE, 6, LittlerootTown_PlayersHouse_1F_EventScript_SetMovingBoxes
	end

LittlerootTown_PlayersHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_PlayersHouse_1F_OnTransition:
	call_if_eq VAR_INTRO_STATE, 3, LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_INTRO_STATE, 5, LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_INTRO_STATE, 6, LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_PlayersHouse_1F_OnFrame:
	map_script_2 VAR_INTRO_STATE, 3, LittlerootTown_PlayersHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_INTRO_STATE, 5, LittlerootTown_PlayersHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_INTRO_STATE, 6, LittlerootTown_PlayersHouse_1F_EventScript_MomLeaving
	.2byte 0

LittlerootTown_PlayersHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_PlayersHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_PlayersHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_PLAYERS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_PlayersHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_PlayersHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_PlayersHouse_1F_EventScript_MomLeaving::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_MOM
	special TurnOnTVScreen
	goto PlayersHouse_1F_EventScript_PetalburgGymReport
	end

LittlerootTown_PlayersHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "The mover's POKéMON do all the work\n"
	.string "of moving you in and cleaning up after.\l"
	.string "This is so convenient!\p"
	.string "{PLAYER}, DAD bought you a new clock\n"
	.string "as a housewarming gift, it's in your\l"
	.string "room upstairs!\p"
	.string "Go check it out, honey, and don't\n"
	.string "forget to set it!$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MOM: {PLAYER}.\p"
	.string "Go set the clock in your room, honey.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MOM: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Quick! Come quickly!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MOM: Look! It's PETALBURG GYM!\n"
	.string "Maybe DAD will be on!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MOM: Oh… It's over.\p"
	.string "I think DAD was on, but we missed him.\n"
	.string "Too bad.$"

PlayersHouse_1F_Text_ThingsMovedOut:
	.string "Well honey, all of your things have been\n"
	.string "moved in.\p"
	.string "Are you sure that you're going to be ok\n"
	.string "living here alone?\p"
	.string "You're still welcome to continue living\n"
	.string "with us in Petalburg!$"

PlayersHouse_1F_Text_StartYourAdventure:
	.string "Ok ok, I understand you're ready to start\n"
	.string "your own adventure.\p"
	.string "I'm just going to miss you so much!\p"
	.string "Your father and I got you something...\n"
	.string "Please take this.$"

PlayersHouse_1F_Text_ItsAPokemon:
	.string "It's a POKéMON, we thought it would be a\n"
	.string "good idea so you don't get lonely!$"

PlayersHouse_1F_Text_TakeCareOfHouse:
	.string "I'm really going to miss you.\p"
	.string "Please take good care of your home,\n"
	.string "I know you and your new friend will do\l"
	.string "just fine!\p"
	.string "Come and visit us in Petalburg soon,\n"
	.string "honey! I love you!$"

PlayersHouse_1F_Text_AlmostForgot:
	.string "I almost forgot!\p"
	.string "I spoke to a man named Professor Birch\n"
	.string "here in Littleroot earlier today.\p" 
	.string "He wants you to visit him in his lab,\n"
	.string "please go and see him!\p"
	.string "Bye {PLAYER}!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MOM: What is that, honey? A POKéNAV?\n"
	.string "Someone from DEVON gave it to you?\p"
	.string "Well, honey, how about registering\n"
	.string "your mom?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "Registered MOM\n"
	.string "in the POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "INTERVIEWER: …We brought you this\n"
	.string "report from in front of PETALBURG GYM.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "DAD: Hm, a TICKET for a ferry?\p"
	.string "If I recall, there are ferry ports in\n"
	.string "SLATEPORT and LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "I'd better get back to PETALBURG GYM.\p"
	.string "MOM, thanks for looking after the house\n"
	.string "while I'm away.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MOM: That DAD of yours…\p"
	.string "He comes home for the first time in a\n"
	.string "while, but all he talks about is POKéMON.\p"
	.string "He should relax and stay a little longer.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MOM: Is that a breaking news story?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various HOENN locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "POKéMON in flight.\p"
	.string "The identity of this POKéMON is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MOM: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that POKéMON was?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MOM: Well, isn't that something!\n"
	.string "There are still unknown POKéMON.$"

PlayersHouse_1F_Text_PlayerReceivedPichu:
	.string "{PLAYER} received PICHU!$"
