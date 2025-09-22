MauvilleCity_GameCorner_MapScripts::
# 2 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_GameCorner_OnLoad
	.byte 0


# 5 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 6 "data/maps/MauvilleCity_GameCorner/scripts.pory"
MauvilleCity_GameCorner_OnLoad::
# 7 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_DOUBLE_TEAM_COINS, 1500
# 8 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_PSYCHIC_COINS, 3500
# 9 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_FLAMETHROWER_COINS, 4000
# 10 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_THUNDERBOLT_COINS, 4000
# 11 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set TM_ICE_BEAM_COINS, 4000
# 12 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set DOLL_COINS, 1000
# 13 "data/maps/MauvilleCity_GameCorner/scripts.pory"

# 14 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_50,  1000
# 15 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.set COINS_PRICE_500, 10000

MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner::
# 19 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This is MAUVILLE GAME CORNER.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins::
# 23 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Okay, you wanted some COINS for the\n"
	.string "games?\p"
	.string "But you don't have a COIN CASE for\n"
	.string "stowing the COINS.$"

MauvilleCity_GameCorner_Text_WereYouLookingForCoins::
# 27 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Were you looking for COINS?\p"
	.string "It's ¥1000 for 50 COINS. Would you like\n"
	.string "some?$"

MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins::
# 31 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you very much! Here are your\n"
	.string "COINS!$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoney::
# 35 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Um… You don't appear to have enough\n"
	.string "money…$"

MauvilleCity_GameCorner_Text_CoinCaseIsFull::
# 39 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh? Your COIN CASE is full.$"

MauvilleCity_GameCorner_Text_DontNeedCoinsThen::
# 43 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh… You don't need COINS, then? Good\n"
	.string "luck on your adventure!$"

MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes::
# 47 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Welcome.\p"
	.string "You can exchange your COINS for prizes\n"
	.string "here.$"

MauvilleCity_GameCorner_Text_WhichPrize::
# 51 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Which prize would you like?$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX::
# 55 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is the {STR_VAR_1}\n"
	.string "{STR_VAR_2}?$"

MauvilleCity_GameCorner_Text_SendToYourHomePC::
# 59 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Thank you! We'll send it to your PC at\n"
	.string "home.$"

MauvilleCity_GameCorner_Text_NotEnoughCoins::
# 63 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You don't have enough COINS.$"

MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor::
# 67 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "There isn't any room available for\n"
	.string "placing {STR_VAR_1}.$"

MauvilleCity_GameCorner_Text_OhIsThatSo::
# 71 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, is that so? You need to save some\n"
	.string "COINS before\l"
	.string "coming back here.$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsX::
# 75 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "So your choice is {STR_VAR_1}?$"

MauvilleCity_GameCorner_Text_HereYouGo::
# 79 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here you go!$"

MauvilleCity_GameCorner_Text_CantCarryAnyMore::
# 83 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, you can't carry any more than that.$"

MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne::
# 87 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "I made a mistake and got two of the\n"
	.string "same DOLLS.\p"
	.string "Would you like one of them?$"

MauvilleCity_GameCorner_Text_HereYouGo2::
# 91 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here you go!$"

MauvilleCity_GameCorner_Text_YouWantItButNotNow::
# 95 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Huh? You want it, but not right now?$"

MauvilleCity_GameCorner_Text_DontBeNegative::
# 99 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Oh, don't be so negative! You can have\n"
	.string "this!$"

MauvilleCity_GameCorner_Text_CantWinJackpot::
# 103 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "There's a prize I want, but I can't win\n"
	.string "the jackpot.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor::
# 107 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Hey, kid, if you want to play here, you\n"
	.string "need a COIN CASE.\p"
	.string "I think the young lady next door had\n"
	.string "one. Go see her!$"

MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins::
# 111 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "My luck can only last so long. This is\n"
	.string "too much for me.\l"
	.string "Here, take some COINS!$"

MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone::
# 115 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "MAUVILLE has something for everyone.\p"
	.string "For me, it's the GAME CORNER.$"

MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates::
# 119 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "The ROULETTE tables have different\n"
	.string "rates.\p"
	.string "Check your COINS if you're going to pick\n"
	.string "a table.$"

MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime::
# 123 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's easy to lose track of time in here.\n"
	.string "I should get back to work.$"

MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay::
# 127 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "COINS are needed to play here in the\n"
	.string "GAME CORNER.$"

MauvilleCity_GameCorner_Text_RouletteOnlyLuck::
# 131 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "This ROULETTE thing… It's rather\n"
	.string "demanding.\p"
	.string "Win or lose, it's only by luck.$"

MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed::
# 135 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Up to three COINS can be used to play\n"
	.string "the SLOTS.$"

MauvilleCity_GameCorner_Text_DifficultToStopOn7::
# 139 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "It's very difficult to make it stop\n"
	.string "right on “7.”\p"
	.string "If it stops on “7” during the REEL TIME\n"
	.string "bonus game, you'll receive extra COINS.$"

MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo::
# 143 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "Here's some information for you about\n"
	.string "the SLOTS.\p"
	.string "The more lightning bolts you stock, the\n"
	.string "more REEL TIME chances you get.\p"
	.string "In a game with the maximum five REEL\n"
	.string "TIME chances…\p"
	.string "It is possible to receive four regular\n"
	.string "bonuses, then a big bonus.\p"
	.string "That would total 660 COINS, but it's\n"
	.string "very difficult to get.$"

MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase::
# 147 "data/maps/MauvilleCity_GameCorner/scripts.pory"
	.string "You can't play if you don't have a COIN\n"
	.string "CASE.$"
