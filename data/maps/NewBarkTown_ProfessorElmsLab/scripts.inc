.set LOCALID_ELM, 1
.set LOCALID_RIVAL, 2

NewBarkTown_ProfessorElmsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_ProfessorElmsLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NewBarkTown_ProfessorElmsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_ProfessorElmsLab_OnFrame
	.byte 0

	@ State descriptions for VAR_ELM_LAB_STATE
	@ 1: Never occurs
	@ 2: Get Pokedex

NewBarkTown_ProfessorElmsLab_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

NewBarkTown_ProfessorElmsLab_OnWarp:
	map_script_2 VAR_ELM_LAB_STATE, 2, NewBarkTown_ProfessorElmsLab_EventScript_SetPlayerPosForReceivePokedex
	.2byte 0

NewBarkTown_ProfessorElmsLab_EventScript_SetPlayerPosForReceivePokedex::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

NewBarkTown_ProfessorElmsLab_OnFrame:
	map_script_2 VAR_ELM_LAB_STATE, 2, NewBarkTown_ProfessorElmsLab_EventScript_GivePokedexEvent
	.2byte 0

NewBarkTown_ProfessorElmsLab_EventScript_GivePokedexEvent::
	lockall
	msgbox NewBarkTown_ProfessorElmsLab_Text_GivePokedex, MSGBOX_DEFAULT
	call NewBarkTown_ProfessorElmsLab_EventScript_ReceivePokedex
	msgbox NewBarkTown_ProfessorElmsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_ELM_LAB_STATE, 3
	releaseall
	end

NewBarkTown_ProfessorElmsLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_ge VAR_ELM_LAB_STATE, 3, NewBarkTown_ProfessorElmsLab_EventScript_AideReceivedStarter
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmAwayOnFieldwork, MSGBOX_DEFAULT
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_AideReceivedStarter::
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmEnjoysRivalsHelpToo, MSGBOX_DEFAULT
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_Elm::
	lock
	faceplayer
	msgbox NewBarkTown_ProfessorElmsLab_Text_ElmRivalGoneHome, MSGBOX_DEFAULT
	release
	end

NewBarkTown_ProfessorElmsLab_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message NewBarkTown_ProfessorElmsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

NewBarkTown_ProfessorElmsLab_EventScript_Machine::
	msgbox NewBarkTown_ProfessorElmsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

NewBarkTown_ProfessorElmsLab_EventScript_PC::
	msgbox NewBarkTown_ProfessorElmsLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

NewBarkTown_ProfessorElmsLab_EventScript_Bookshelf::
	msgbox NewBarkTown_ProfessorElmsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

NewBarkTown_ProfessorElmsLab_EventScript_Book::
	msgbox NewBarkTown_ProfessorElmsLab_Text_BookTooHardToRead, MSGBOX_SIGN
	end

NewBarkTown_ProfessorElmsLab_Text_ElmAwayOnFieldwork:
	.string "Hunh? Professor Elm?\p"
	.string "He's away on fieldwork.\n"
	.string "Ergo, he isn't here.\p"
	.string "Oh, let me explain what fieldwork is.\p"
	.string "It is to study things in the natural\n"
	.string "environment, like fields and mountains,\l"
	.string "instead of a laboratory.\p"
	.string "Elm isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"

NewBarkTown_ProfessorElmsLab_Text_ElmEnjoysRivalsHelpToo:
	.string "Professor Elm is studying the habitats\n"
	.string "and distribution of pokémon.\p"
	.string "The professor enjoys {RIVAL}'s help, too.\n"
	.string "There's a lot of love there.$"

NewBarkTown_ProfessorElmsLab_Text_GivePokedex:
	.string "PROF. ELM: So, you're {PLAYER}{KUN}!\p"
	.string "I've heard that we were getting a\n"
	.string "newcomer in town, and I talked to\l"
	.string "your mother earlier today!\p"
	.string "Welcome to New Bark Town!\p"
	.string "I understand your father is the\n"
	.string "gym leader in Violet City.\p"
	.string "The way you battled earlier...\n"
	.string "I guess you have your father's blood\l"
	.string "in your veins after all!\p"
	.string "{PLAYER}{KUN}, now that you're starting\n"
	.string "your own adventure, I think you should\l"
	.string "have this pokédex.$"

NewBarkTown_ProfessorElmsLab_Text_ElmRivalGoneHome:
	.string "PROF. ELM: {RIVAL}?\n"
	.string "Gone home, I think.\p"
	.string "Or maybe that kid's scrabbling around\n"
	.string "in tall grass again somewhere…\p"
	.string "If you or your pokémon get tired,\n"
	.string "you should get some rest at home.$"

NewBarkTown_ProfessorElmsLab_Text_ReceivedPokedex:
	.string "{PLAYER} received the POKéDEX!$"

NewBarkTown_ProfessorElmsLab_Text_ExplainPokedex:
	.string "PROF. ELM: The pokédex is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any pokémon you meet or catch.\p"
	.string "My kid, {RIVAL}, goes everywhere\n"
	.string "with it.\p"
	.string "Whenever my kid catches a rare pokémon\n"
	.string "and records its data in the pokédex,\l"
	.string "why, {RIVAL} looks for me while I'm out\l"
	.string "doing fieldwork, and shows me.$"

NewBarkTown_ProfessorElmsLab_Text_SeriousLookingMachine:
	.string "It's a serious-looking machine.\n"
	.string "The professor must use this for research.$"

NewBarkTown_ProfessorElmsLab_Text_PCUsedForResearch:
	.string "It's a PC used for research.\n"
	.string "Better not mess around with it.$"

NewBarkTown_ProfessorElmsLab_Text_CrammedWithBooksOnPokemon:
	.string "It's crammed with books on pokémon.$"

NewBarkTown_ProfessorElmsLab_Text_BookTooHardToRead:
	.string "It's a book that's too hard to read.$"
