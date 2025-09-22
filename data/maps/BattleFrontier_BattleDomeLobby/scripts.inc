BattleFrontier_BattleDomeLobby_MapScripts::
# 2 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleDomeLobby_OnResume
# 3 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleDomeLobby_OnFrame
# 4 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0


BattleFrontier_BattleDomeLobby_Text_WelcomeSingleBattle::
# 8 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Where the strategies of TRAINERS are\n"
	.string "put to the test!\p"
	.string "Welcome to the BATTLE DOME!\p"
	.string "I am your guide to the SINGLE BATTLE\n"
	.string "Tournament.$"

BattleFrontier_BattleDomeLobby_Text_TakeSinglesChallenge::
# 12 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Would you like to challenge the SINGLE\n"
	.string "BATTLE Tournament?$"

BattleFrontier_BattleDomeLobby_Text_HopeToSeeYouAgain::
# 16 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "We hope to see you again.$"

BattleFrontier_BattleDomeLobby_Text_ExplainSinglesChallenge::
# 20 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The SINGLE BATTLE Tournament is\n"
	.string "exactly as the name suggests--\l"
	.string "a tournament of SINGLE BATTLES.\p"
	.string "All participating TRAINERS must enter\n"
	.string "three POKéMON each.\p"
	.string "In each battle, one of the three\n"
	.string "POKéMON must be held in reserve.\p"
	.string "The other two POKéMON can battle one\n"
	.string "at a time.\p"
	.string "Choose the two battling POKéMON after\n"
	.string "examining the opponent's trio.\p"
	.string "You win the tournament by defeating\n"
	.string "four TRAINERS.\p"
	.string "Battle Points are awarded to the\n"
	.string "tournament winner.\p"
	.string "If you want to interrupt your\n"
	.string "tournament, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge::
# 24 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Before I show you to the BATTLE DOME, I\n"
	.string "must save the data. Is that okay?$"

BattleFrontier_BattleDomeLobby_Text_WhichLevelMode::
# 28 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The tournament offers two levels of\n"
	.string "challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleFrontier_BattleDomeLobby_Text_SelectThreeMons::
# 32 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Now select the three POKéMON that you\n"
	.string "wish to enter, please.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLvOpen::
# 36 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "Also, the POKéMON must be holding\n"
	.string "different kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleDomeLobby_Text_NotEnoughValidMonsLv50::
# 40 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleDomeLobby_Text_ShowYouToBattleDome::
# 44 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I will now show you to the BATTLE DOME.$"

BattleFrontier_BattleDomeLobby_Text_DidntSaveBeforeQuitting::
# 48 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Excuse me!\p"
	.string "You didn't save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

BattleFrontier_BattleDomeLobby_Text_CongratsForWinningTourney::
# 52 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Congratulations for winning your\n"
	.string "Battle Tournament!$"

BattleFrontier_BattleDomeLobby_Text_HereIsYourPrize::
# 56 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Here is your prize for your Battle\n"
	.string "Tournament victory.$"

BattleFrontier_BattleDomeLobby_Text_ReceivedPrize::
# 60 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleDomeLobby_Text_BagFullMakeRoom::
# 64 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Oh, your BAG appears to be full.\p"
	.string "Please make room in your BAG, then come\n"
	.string "see me.$"

BattleFrontier_BattleDomeLobby_Text_ThankYouForPlaying::
# 68 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Thank you for playing!$"

BattleFrontier_BattleDomeLobby_Text_RecordWillBeSaved::
# 72 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Your record will be saved. Please wait.$"

BattleFrontier_BattleDomeLobby_Text_WeveBeenWaitingForYou::
# 76 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "We've been waiting for you!$"

BattleFrontier_BattleDomeLobby_Text_OkayToSaveBeforeChallenge2::
# 80 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Before I show you to the BATTLE DOME, I\n"
	.string "must save the data. Is that okay?$"

BattleFrontier_BattleDomeLobby_Text_WelcomeDoubleBattle::
# 84 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Where the strategies of TRAINERS are\n"
	.string "put to the test!\p"
	.string "Welcome to the BATTLE DOME!\p"
	.string "I am your guide to the DOUBLE BATTLE\n"
	.string "Tournament.$"

BattleFrontier_BattleDomeLobby_Text_TakeDoublesChallenge::
# 88 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Would you like to challenge the DOUBLE\n"
	.string "BATTLE Tournament?$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoublesChallenge::
# 92 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The DOUBLE BATTLE Tournament is\n"
	.string "exactly as the name suggests--\l"
	.string "a tournament of DOUBLE BATTLES.\p"
	.string "All participating TRAINERS must enter\n"
	.string "three POKéMON each.\p"
	.string "In each battle, one of the three\n"
	.string "POKéMON must be held in reserve.\p"
	.string "The remaining two POKéMON must take\n"
	.string "part in a DOUBLE BATTLE.\p"
	.string "Choose the two battling POKéMON after\n"
	.string "examining the opponent's trio.\p"
	.string "You win the tournament by defeating\n"
	.string "four TRAINERS.\p"
	.string "Battle Points are awarded to the\n"
	.string "tournament winner.\p"
	.string "If you want to interrupt your\n"
	.string "tournament, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLv50::
# 96 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last Level 50\n"
	.string "SINGLE BATTLE Tournament.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLv50::
# 100 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last Level 50\n"
	.string "DOUBLE BATTLE Tournament.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsSinglesLvOpen::
# 104 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last Open\n"
	.string "Level SINGLE BATTLE Tournament.$"

BattleFrontier_BattleDomeLobby_Text_PrevTourneyResultsDoublesLvOpen::
# 108 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "They're the results of the last Open\n"
	.string "Level DOUBLE BATTLE Tournament.$"

BattleFrontier_BattleDomeLobby_Text_LastWinnerWasTough::
# 112 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Did you see it? The last Battle\n"
	.string "Tournament?\p"
	.string "The winner, {STR_VAR_1}, was\n"
	.string "seriously tough.\p"
	.string "You should check out the results on the\n"
	.string "monitor beside the PC.$"

BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier::
# 116 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The BATTLE FRONTIER… I've long dreamed\n"
	.string "about a place like it.$"

BattleFrontier_OutsideWest_Text_BattleDomeSign2::
# 120 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The BATTLE DOME Become the Unbeatable\n"
	.string "Superstar!$"

BattleFrontier_OutsideWest_Text_QuestionMarkUnderConstruction::
# 124 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The ?????? Under Construction!$"

BattleFrontier_BattleDomeLobby_Text_WinnersGainReputation::
# 128 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "When a TRAINER chains tournament wins\n"
	.string "at the BATTLE DOME, he or she\l"
	.string "gains a reputation as a star.\p"
	.string "Tough TRAINERS are drawn by that\n"
	.string "reputation to the BATTLE DOME.\p"
	.string "A true superstar is a TRAINER who can\n"
	.string "keep winning tournaments.$"

BattleFrontier_BattleDomeLobby_Text_TrashedInFirstRound::
# 132 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I ran into one of the tournament\n"
	.string "favorites in the very first round.\p"
	.string "Of course I got trashed…$"

BattleFrontier_BattleDomeLobby_Text_NeedToCheckOpponentCarefully::
# 136 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "I would've won if I'd kept this POKéMON\n"
	.string "held in reserve.\p"
	.string "You need to check your opponent's\n"
	.string "POKéMON carefully before choosing\l"
	.string "your battling POKéMON.$"

BattleFrontier_BattleDomeLobby_Text_CongratsDefeatedTucker::
# 140 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Congratulations!\p"
	.string "You defeated the DOME ACE and won the\n"
	.string "Battle Tournament!$"

BattleFrontier_BattleDomeLobby_Text_AwardTheseBattlePoints::
# 144 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "In recognition of your strategy-- a\n"
	.string "thing of beauty it was, too--\l"
	.string "we award you these Battle Point(s)!$"

BattleFrontier_BattleDomeLobby_Text_RecordLastMatch::
# 148 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Would you like to record your last\n"
	.string "BATTLE DOME match on your\l"
	.string "FRONTIER PASS?$"

BattleFrontier_BattleDomeLobby_Text_RulesAreListed::
# 152 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The Battle Tournament rules are listed.$"

BattleFrontier_BattleDomeLobby_Text_ReadWhichHeading::
# 156 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "Which heading do you want to read?$"

BattleFrontier_BattleDomeLobby_Text_ExplainMatchupRules::
# 160 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The tournament matchups are drawn up\n"
	.string "based on the toughness of POKéMON\l"
	.string "held by TRAINERS.\p"
	.string "The matchups avoid having tough\n"
	.string "TRAINERS face each other right away.$"

BattleFrontier_BattleDomeLobby_Text_ExplainTourneyTree::
# 164 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "The tournament chart, or as we call it,\n"
	.string "the “Tree,” is available for viewing\l"
	.string "in the Waiting Room from any guide.\p"
	.string "The Tournament Tree will provide\n"
	.string "several kinds of data.\p"
	.string "The data on view includes the previous\n"
	.string "tournament's results, the POKéMON held\l"
	.string "by TRAINERS, and the battle styles of\l"
	.string "TRAINERS.$"

BattleFrontier_BattleDomeLobby_Text_ExplainDoubleKORules::
# 168 "data/maps/BattleFrontier_BattleDomeLobby/scripts.pory"
	.string "If battling POKéMON faint at the same\n"
	.string "time--a double KO--in a tournament\l"
	.string "match, the REFEREES will review\l"
	.string "the match and declare the winner.$"
