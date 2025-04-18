.set LOCALID_OAK, 1

ProfessorOaksLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ProfessorOaksLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ProfessorOaksLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ProfessorOaksLab_OnFrame
	.byte 0

	@ State descriptions for VAR_OAK_LAB_STATE
	@ 1: Never occurs
	@ 2: Get Pokedex

ProfessorOaksLab_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

ProfessorOaksLab_OnWarp:
	map_script_2 VAR_OAK_LAB_STATE, 2, ProfessorOaksLab_EventScript_SetPlayerPosForReceivePokedex
	.2byte 0

ProfessorOaksLab_EventScript_SetPlayerPosForReceivePokedex::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

ProfessorOaksLab_OnFrame:
	map_script_2 VAR_OAK_LAB_STATE, 2, ProfessorOaksLab_EventScript_GivePokedexEvent
	.2byte 0

ProfessorOaksLab_EventScript_GivePokedexEvent::
	lockall
	msgbox ProfessorOaksLab_Text_GivePokedex, MSGBOX_DEFAULT
	call ProfessorOaksLab_EventScript_ReceivePokedex
	msgbox ProfessorOaksLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	closemessage
	call ProfessorOaksLab_EventScript_GoSeeRival
	end

ProfessorOaksLab_EventScript_GoSeeRival::
	msgbox ProfessorOaksLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ProfessorOaksLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, ProfessorOaksLab_EventScript_DeclineSeeingRival
	end

ProfessorOaksLab_EventScript_AgreeToSeeRival::
	msgbox ProfessorOaksLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_OAK_LAB_STATE, 3
	releaseall
	end

ProfessorOaksLab_EventScript_DeclineSeeingRival::
	msgbox ProfessorOaksLab_Text_DontBeThatWay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ProfessorOaksLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, ProfessorOaksLab_EventScript_DeclineSeeingRival
	end

ProfessorOaksLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_ge VAR_OAK_LAB_STATE, 3, ProfessorOaksLab_EventScript_AideReceivedStarter
	msgbox ProfessorOaksLab_Text_OakAwayOnFieldwork, MSGBOX_DEFAULT
	release
	end

ProfessorOaksLab_EventScript_AideReceivedStarter::
	msgbox ProfessorOaksLab_Text_OakEnjoysRivalsHelpToo, MSGBOX_DEFAULT
	release
	end

ProfessorOaksLab_EventScript_Oak::
	lock
	faceplayer
	msgbox ProfessorOaksLab_Text_OakRivalGoneHome, MSGBOX_DEFAULT
	end

ProfessorOaksLab_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message ProfessorOaksLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

ProfessorOaksLab_EventScript_Machine::
	msgbox ProfessorOaksLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

ProfessorOaksLab_EventScript_PC::
	msgbox ProfessorOaksLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

ProfessorOaksLab_EventScript_Bookshelf::
	msgbox ProfessorOaksLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

ProfessorOaksLab_EventScript_Book::
	msgbox ProfessorOaksLab_Text_BookTooHardToRead, MSGBOX_SIGN
	end

ProfessorOaksLab_Text_OakAwayOnFieldwork:
	.string "Hunh? PROF. OAK?\p"
	.string "The PROF's away on fieldwork.\n"
	.string "Ergo, he isn't here.\p"
	.string "Oh, let me explain what fieldwork is.\p"
	.string "It is to study things in the natural\n"
	.string "environment, like fields and mountains,\l"
	.string "instead of a laboratory.\p"
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"

ProfessorOaksLab_Text_OakEnjoysRivalsHelpToo:
	.string "PROF. OAK is studying the habitats\n"
	.string "and distribution of pokémon.\p"
	.string "The PROF enjoys {RIVAL}'s help, too.\n"
	.string "There's a lot of love there.$"

ProfessorOaksLab_Text_GivePokedex:
	.string "PROF. OAK: So, you're {PLAYER}{KUN}!\p"
	.string "I've heard that we were getting a\n"
	.string "newcomer in town, and I talked to\l"
	.string "your mother earlier today!\p"
	.string "Welcome to Littleroot Town!\p"
	.string "I understand your father is the\n"
	.string "gym leader in Petalburg City.\p"
	.string "The way you battled earlier...\n"
	.string "I guess you have your father's blood\l"
	.string "in your veins after all!\p"
	.string "{PLAYER}{KUN}, now that you're starting\n"
	.string "your own adventure, I think you should\l"
	.string "have this POKéDEX.$"

ProfessorOaksLab_Text_MightBeGoodIdeaToGoSeeRival:
	.string "PROF. OAK: If you work at pokémon\n"
	.string "and gain experience, I think you'll make\l"
	.string "a very fine trainer.\p"
	.string "My kid, {RIVAL}, is also studying\n"
	.string "pokémon while helping me out.\p"
	.string "They live just north of here in\n"
	.string "Oldale Town.\p"
	.string "{PLAYER}{KUN}, don't you think it might be\n"
	.string "a good idea to go see {RIVAL}?$"

ProfessorOaksLab_Text_GetRivalToTeachYou:
	.string "PROF. OAK: Great!\n"
	.string "{RIVAL} should be happy, too.\p"
	.string "Get {RIVAL} to teach you what it\n"
	.string "means to be a trainer!$"

ProfessorOaksLab_Text_DontBeThatWay:
	.string "PROF. OAK: Oh, don't be that way.\n"
	.string "You should go meet my kid.$"

ProfessorOaksLab_Text_OakRivalGoneHome:
	.string "PROF. OAK: {RIVAL}?\n"
	.string "Gone home, I think.\p"
	.string "Or maybe that kid's scrabbling around\n"
	.string "in tall grass again somewhere…\p"
	.string "If you or your pokémon get tired,\n"
	.string "you should get some rest at home.$"

ProfessorOaksLab_Text_ReceivedPokedex:
	.string "{PLAYER} received the POKéDEX!$"

ProfessorOaksLab_Text_ExplainPokedex:
	.string "PROF. OAK: The POKéDEX is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any pokémon you meet or catch.\p"
	.string "My kid, {RIVAL}, goes everywhere\n"
	.string "with it.\p"
	.string "Whenever my kid catches a rare pokémon\n"
	.string "and records its data in the POKéDEX,\l"
	.string "why, {RIVAL} looks for me while I'm out\l"
	.string "doing fieldwork, and shows me.$"

ProfessorOaksLab_Text_SeriousLookingMachine:
	.string "It's a serious-looking machine.\n"
	.string "The PROF must use this for research.$"

ProfessorOaksLab_Text_PCUsedForResearch:
	.string "It's a PC used for research.\n"
	.string "Better not mess around with it.$"

ProfessorOaksLab_Text_CrammedWithBooksOnPokemon:
	.string "It's crammed with books on pokémon.$"

ProfessorOaksLab_Text_BookTooHardToRead:
	.string "It's a book that's too hard to read.$"
