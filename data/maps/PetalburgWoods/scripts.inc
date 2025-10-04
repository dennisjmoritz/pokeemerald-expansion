PetalburgWoods_MapScripts::
	.byte 0


PetalburgWoods_EventScript_Boy1::
# 5 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end


PetalburgWoods_EventScript_Boy2::
# 10 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end


PetalburgWoods_EventScript_DevonResearcherLeft::
	end


PetalburgWoods_EventScript_DevonResearcherRight::
	end


PetalburgWoods_EventScript_Girl::
	end


PetalburgWoods_EventScript_James::
# 27 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_double TRAINER_JAMES, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, Text_NotEnoughMonsForDoubleBattle
# 28 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou
	return


PetalburgWoods_EventScript_Lyle::
# 32 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_double TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin, Text_NotEnoughMonsForDoubleBattle
# 33 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls
	return


PetalburgWoods_EventScript_Sign1::
# 37 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end


PetalburgWoods_EventScript_Sign2::
# 42 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end


PetalburgWoods_Text_TrainerTipsExperience::
# 47 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "Any POKéMON that appears even once in\n"
	.string "a battle is awarded EXP Points.\p"
	.string "To raise a weak POKéMON, put it at the\n"
	.string "left of the team list.\p"
	.string "As soon as a battle starts, switch it\n"
	.string "out. It will earn EXP Points without\l"
	.string "being exposed to any harm.$"

PetalburgWoods_Text_TrainerTipsPP::
# 51 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "In addition to Hit Points (HP), POKéMON\n"
	.string "have Power Points (PP) that are used to\l"
	.string "make moves during battle.\p"
	.string "If a POKéMON runs out of PP, it must be\n"
	.string "taken to a POKéMON CENTER.$"

PetalburgWoods_Text_CantBePopularIfILose::
# 56 "data/maps/PetalburgWoods/scripts.pory"
	.string "Placeholder text for\n"
	.string "PetalburgWoods_Text_CantBePopularIfILose$"

PetalburgWoods_Text_GoBugPokemonTeam::
# 60 "data/maps/PetalburgWoods/scripts.pory"
	.string "Placeholder text for\n"
	.string "PetalburgWoods_Text_GoBugPokemonTeam$"

PetalburgWoods_Text_ICouldntWin::
# 64 "data/maps/PetalburgWoods/scripts.pory"
	.string "Placeholder text for\n"
	.string "PetalburgWoods_Text_ICouldntWin$"

PetalburgWoods_Text_ImOutOfPokeBalls::
# 68 "data/maps/PetalburgWoods/scripts.pory"
	.string "Placeholder text for\n"
	.string "PetalburgWoods_Text_ImOutOfPokeBalls$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon::
# 72 "data/maps/PetalburgWoods/scripts.pory"
	.string "Placeholder text for\n"
	.string "PetalburgWoods_Text_InstantlyPopularWithBugPokemon$"

PetalburgWoods_Text_PeopleRespectYou::
# 76 "data/maps/PetalburgWoods/scripts.pory"
	.string "Placeholder text for\n"
	.string "PetalburgWoods_Text_PeopleRespectYou$"

PetalburgWoods_Text_YoureLoadedWithItems::
# 80 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"

PetalburgWoods_Text_NotAOneToBeFound::
# 84 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
	.string "Not a one to be found…$"

PetalburgWoods_Text_StayOutOfTallGrass::
# 88 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
	.string "Your POKéMON doing okay?\p"
	.string "If your POKéMON are weak and you want\n"
	.string "to avoid battles, you should stay out\l"
	.string "of tall grass.$"

PetalburgWoods_Text_HiddenItemsExplanation::
# 92 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
	.string "ground even if you can't see them.\p"
	.string "That's why I always check where I'm\n"
	.string "walking.$"

PetalburgWoods_Text_IveBeenTrainingHard::
# 96 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
	.string "strong POKéMON, right?\l"
	.string "So, I've been training hard.$"

PetalburgWoods_Text_IWantRematch2::
# 100 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéNAV!$"

PetalburgWoods_Text_YouveGotSomeNerve::
# 104 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
	.string "meddling with TEAM AQUA!\l"
	.string "Come on and battle me again!\p"
	.string "I wish I could say that, but I'm out of\n"
	.string "POKéMON…\p"
	.string "And, hey, we of TEAM AQUA are also\n"
	.string "after something in RUSTBORO.\p"
	.string "I'll let you go today!$"

PetalburgWoods_Text_IWantRematch1::
# 108 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéNAV!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro::
# 112 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that TEAM AQUA thug say\n"
	.string "they were after something in\l"
	.string "RUSTBORO, too?$"

PetalburgWoods_Text_MiracleSeedExplanation::
# 116 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a MIRACLE SEED.\n"
	.string "If a POKéMON holds that item, its\l"
	.string "GRASS-type moves become stronger.\p"
	.string "Besides MIRACLE SEED, I think there are\n"
	.string "other convenient items for POKéMON\l"
	.string "to hold.$"
