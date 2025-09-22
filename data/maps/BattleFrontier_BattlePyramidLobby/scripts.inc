BattleFrontier_BattlePyramidLobby_MapScripts::
# 2 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
# 3 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0


BattleFrontier_BattlePyramidLobby_MapScripts::
# 7 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
# 8 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	return


BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid::
# 12 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Where the courage of TRAINERS is put\n"
	.string "to the test!\p"
	.string "Welcome to the BATTLE PYRAMID!\p"
	.string "I am your guide to the Battle Quest.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge::
# 16 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Have you the courage to embark on the\n"
	.string "Battle Quest challenge?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge::
# 20 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We await your challenge in the future!$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid::
# 24 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The Battle Quest is a battling event in\n"
	.string "which you must explore\l"
	.string "the PYRAMID and try to reach the top.\p"
	.string "In the PYRAMID are seven floors of\n"
	.string "mazes, all of them filled with not only\l"
	.string "skilled TRAINERS but also wild POKéMON.\p"
	.string "You must enter with three POKéMON,\n"
	.string "none of them holding an item.\p"
	.string "On your ascent, you will be provided\n"
	.string "with a BATTLE BAG for items.\p"
	.string "If you fail in your challenge, any item\n"
	.string "placed in the BATTLE BAG disappears.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, you must select “REST”\l"
	.string "and save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode::
# 28 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The PYRAMID offers two courses, Level\n"
	.string "50 and Open Level.\l"
	.string "Which will you enter?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons::
# 32 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Very good. Now, please select the three\n"
	.string "POKéMON you wish to accompany you.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen::
# 36 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "A slight problem, adventurer!\p"
	.string "You seem to not have the three POKéMON\n"
	.string "qualified for the challenge.\p"
	.string "Please also remember to take all items\n"
	.string "from your POKéMON.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you are ready, please have a word\n"
	.string "with me.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50::
# 40 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "A slight problem, adventurer!\p"
	.string "You seem to not have the three POKéMON\n"
	.string "qualified for the challenge.\p"
	.string "The three POKéMON must be different\n"
	.string "and each no higher than Level 50.\p"
	.string "Please also remember to take all items\n"
	.string "from your POKéMON.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you are ready, please have a word\n"
	.string "with me.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge::
# 44 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Before you enter the BATTLE PYRAMID,\n"
	.string "the game must be saved. Is that okay?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid::
# 48 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Very good. I will now show you into the\n"
	.string "BATTLE PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping::
# 52 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We will hold your BAG for safekeeping,\n"
	.string "{PLAYER}, while you are exploring.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag::
# 56 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In exchange, please take this BATTLE\n"
	.string "BAG, the one you used previously.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag::
# 60 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "In exchange, please take this BATTLE\n"
	.string "BAG.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag::
# 64 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} exchanged the BAG for the\n"
	.string "BATTLE BAG.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel::
# 68 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When you step on this floor panel, you\n"
	.string "will be transported to a higher\l"
	.string "floor in the PYRAMID.\p"
	.string "I hope for your sake that your quest\n"
	.string "goes safely!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag::
# 72 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "A major problem, explorer!\p"
	.string "You did not save before ending your\n"
	.string "challenge the last time.\p"
	.string "Consequently, your challenge has been\n"
	.string "disqualified, I'm sorry to say.\p"
	.string "Here is the BAG we've been holding for\n"
	.string "you.\p"
	.string "{PLAYER} got the BAG back.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid::
# 76 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Excellent to see you back!\p"
	.string "You've conquered the PYRAMID! How\n"
	.string "splendid!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake::
# 80 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Ah, a slight problem.\p"
	.string "At least one POKéMON is holding an item.\p"
	.string "I'm sorry to say, items obtained in the\n"
	.string "PYRAMID cannot be taken away.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag::
# 84 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "All items held by your POKéMON will be\n"
	.string "moved to your BATTLE BAG, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep::
# 88 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The BATTLE BAG cannot hold all your\n"
	.string "items, I'm sorry to say.\p"
	.string "Please pick the items you'll keep in the\n"
	.string "BATTLE BAG, and with your POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem::
# 92 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "At least one POKéMON is still holding an\n"
	.string "item.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep::
# 96 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Please pick the items you'll keep in the\n"
	.string "BATTLE BAG, and with your POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld::
# 100 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} returned everything that\n"
	.string "the POKéMON held.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept::
# 104 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The BATTLE BAG you used will be kept in\n"
	.string "readiness for your next challenge.\p"
	.string "{PLAYER} turned the BATTLE BAG over\n"
	.string "for the BAG's return.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait::
# 108 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I must record your results. Please wait.$"

BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis::
# 112 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "As a memento for conquering the BATTLE\n"
	.string "PYRAMID, please take this.$"

BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem::
# 116 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}. …Ah… Your BAG appears\l"
	.string "to be filled.\p"
	.string "Please return after you've organized\n"
	.string "your BAG's contents.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag::
# 120 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "How disappointing for you…\p"
	.string "Here is the BAG we've been holding for\n"
	.string "you.\p"
	.string "{PLAYER} got the BAG back.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge::
# 124 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We look forward to your next challenge!$"

BattleFrontier_BattlePyramidLobby_Text_HereIsPrize::
# 128 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "We have been looking forward to your\n"
	.string "arrival!\p"
	.string "Here is your prize for conquering the\n"
	.string "PYRAMID.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait::
# 132 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Welcome…\p"
	.string "I shall be pleased to tell you what\n"
	.string "misfortunes await in the PYRAMID…$"

BattleFrontier_BattlePyramidLobby_Text_Aah::
# 136 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "… … … … … … … … … … … …\p"
	.string "… … … … … … Aah!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis::
# 140 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see a shower of sparks…\p"
	.string "…And in it, I see your POKéMON\n"
	.string "struggling with paralysis…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison::
# 144 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see poison…\p"
	.string "…And, I see your POKéMON suffering from\n"
	.string "the effects of poison…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn::
# 148 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see bright red flames…\p"
	.string "…And, I see your POKéMON suffering from\n"
	.string "burns…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste::
# 152 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I sense the tremendous pressure of\n"
	.string "unrequited anger…\p"
	.string "It is a curse…\p"
	.string "…And, I see your POKéMON drained of\n"
	.string "Power Points and having no recourse\l"
	.string "but to use STRUGGLE…$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate::
# 156 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see POKéMON loftily airborne…\p"
	.string "…And, I see your POKéMON frustrated by\n"
	.string "powerless GROUND-type moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility::
# 160 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I sense terrific energy rising from the\n"
	.string "ground below…\p"
	.string "…And, I see your POKéMON unable to\n"
	.string "escape the power's clutches…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce::
# 164 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see ICE-type POKéMON…\p"
	.string "…And, I see your POKéMON fighting the\n"
	.string "freezing effects of ice…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion::
# 168 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see a flurry of moves that imperil the\n"
	.string "user…\p"
	.string "…And, I see your POKéMON falling to\n"
	.string "them…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic::
# 172 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see PSYCHIC-type POKéMON…\p"
	.string "…And, I see your POKéMON in torment\n"
	.string "from PSYCHIC moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock::
# 176 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see ROCK-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering from\n"
	.string "ROCK moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting::
# 180 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see FIGHTING-type POKéMON…\p"
	.string "…And, I see your POKéMON pummeled by\n"
	.string "FIGHTING moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather::
# 184 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "RAIN DANCE… SUNNY DAY… SANDSTORM…\n"
	.string "HAIL…\p"
	.string "I see POKéMON that become stronger\n"
	.string "with the weather…\p"
	.string "…And, I see your POKéMON confounded by\n"
	.string "different types of moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug::
# 188 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see BUG-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering from\n"
	.string "different kinds of attacks…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark::
# 192 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see DARK-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering from\n"
	.string "DARK-type moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater::
# 196 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see WATER-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering from\n"
	.string "WATER-type moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost::
# 200 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see GHOST-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering from\n"
	.string "GHOST-type moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel::
# 204 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see STEEL-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering from\n"
	.string "enormously powerful moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon::
# 208 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see flying POKéMON…\p"
	.string "…And, I see your POKéMON suffering from\n"
	.string "enormously powerful moves…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve::
# 212 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see those that have evolved from the\n"
	.string "power of stones…\p"
	.string "I also sense fire, water, and\n"
	.string "electricity…\p"
	.string "…And, I see your POKéMON suffering from\n"
	.string "those three powers…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal::
# 216 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "I see NORMAL-type POKéMON…\p"
	.string "…And, I see your POKéMON suffering from\n"
	.string "enormously powerful moves…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot::
# 220 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Whether you believe my fortunes or not,\n"
	.string "the choice is yours…\p"
	.string "The future can be changed anytime… I\n"
	.string "wish you safe passage…$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning::
# 224 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Did you know?\p"
	.string "If you run fast, TRAINERS may notice\n"
	.string "and come after you for a battle.\p"
	.string "So, if you want to avoid TRAINERS, don't\n"
	.string "catch their eyes, but sneak\l"
	.string "cautiously and quietly past them.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems::
# 228 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Awaaaaaaarrrrgh!\p"
	.string "I had a whole lot of items, but I lost\n"
	.string "them all when I lost!\p"
	.string "Awaaaaaaarrrrgh!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing::
# 232 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Welcome back! You've done the\n"
	.string "unthinkable!\p"
	.string "You've defeated the PYRAMID KING and\n"
	.string "conquered the BATTLE PYRAMID!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints::
# 236 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Young explorer! In commendation of\n"
	.string "your courage,\l"
	.string "we give you these Battle Point(s)!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed::
# 240 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The Battle Quest rules are listed.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading::
# 244 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "Which heading do you want to read?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules::
# 248 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "When the PYRAMID is conquered, the wild\n"
	.string "POKéMON that appear in it\l"
	.string "are replaced by different kinds.\p"
	.string "Explore, observe, and learn what kinds\n"
	.string "of wild POKéMON you may encounter.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules::
# 252 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "TRAINERS are lying in wait for you\n"
	.string "inside the PYRAMID.\p"
	.string "On each floor, there are up to eight\n"
	.string "TRAINERS.\p"
	.string "When you defeat a TRAINER, you will get\n"
	.string "a helpful hint for your adventure.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules::
# 256 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The mazes in the PYRAMID rearrange\n"
	.string "themselves every time you enter it.\p"
	.string "The mazes are poorly lit. You must\n"
	.string "advance with caution.\p"
	.string "The light grows brighter whenever you\n"
	.string "defeat a wild POKéMON or a TRAINER.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules::
# 260 "data/maps/BattleFrontier_BattlePyramidLobby/scripts.pory"
	.string "The BATTLE BAG serves as your BAG while\n"
	.string "in the PYRAMID.\p"
	.string "There are two separate BATTLE BAGS--\n"
	.string "one each for the Level 50 and\l"
	.string "Open Level adventures.\p"
	.string "They each can hold up to 99 pieces of\n"
	.string "ten kinds of items.\p"
	.string "The contents of the BATTLE BAG are\n"
	.string "lost if you fail in your quest.$"
