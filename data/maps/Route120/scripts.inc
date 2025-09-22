Route120_MapScripts::
# 2 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route120_OnResume
# 3 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route120_OnTransition
# 4 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route120_OnLoad
	.byte 0


Route120_MapScripts::
# 8 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route120_OnResume
# 9 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route120_OnTransition
# 10 "data/maps/Route120/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route120_OnLoad
	return


Route120_Text_StevenGreeting::
# 14 "data/maps/Route120/scripts.pory"
	.string "STEVEN: Hm? {PLAYER}{KUN}, hi. It's been a\n"
	.string "while.\p"
	.string "There's something here that you can't\n"
	.string "see, right?\p"
	.string "Now, if I were to use this device on the\n"
	.string "invisible obstacle…\p"
	.string "No, no. Rather than describing it, I\n"
	.string "should just show you.\l"
	.string "That would be more fun.\p"
	.string "{PLAYER}{KUN}, are your POKéMON ready for\n"
	.string "battle?$"

Route120_Text_StevenIllWaitHere::
# 18 "data/maps/Route120/scripts.pory"
	.string "STEVEN: No?\p"
	.string "I'll wait here, so you can get ready.$"

Route120_Text_StevenReadyForBattle::
# 22 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, are your POKéMON\n"
	.string "ready for battle?$"

Route120_Text_StevenShowMeYourPower::
# 26 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, show me your true\n"
	.string "power as a TRAINER!$"

Route120_Text_StevenUsedDevonScope::
# 30 "data/maps/Route120/scripts.pory"
	.string "STEVEN used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON attacked!$"

Route120_Text_StevenGiveDevonScope::
# 34 "data/maps/Route120/scripts.pory"
	.string "STEVEN: I see… Your battle style is\n"
	.string "intriguing.\p"
	.string "Your POKéMON have obviously grown\n"
	.string "since I first met you in DEWFORD.\p"
	.string "I'd like you to have this DEVON SCOPE.\p"
	.string "Who knows, there may be other\n"
	.string "concealed POKéMON.$"

Route120_Text_StevenGoodbye::
# 38 "data/maps/Route120/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}.\p"
	.string "I enjoy seeing POKéMON and TRAINERS\n"
	.string "who strive together.\p"
	.string "I think you're doing great.\p"
	.string "Well, let's meet again somewhere.$"

Kecleon_Text_SomethingUnseeable::
# 42 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.$"

Kecleon_Text_WantToUseDevonScope::
# 46 "data/maps/Route120/scripts.pory"
	.string "Something unseeable is in the way.\p"
	.string "Want to use the DEVON SCOPE?$"

Kecleon_Text_UseDevonScopeMonAttacked::
# 50 "data/maps/Route120/scripts.pory"
	.string "{PLAYER} used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON attacked!$"

Route120_Text_RouteSignFortree::
# 54 "data/maps/Route120/scripts.pory"
	.string "ROUTE 120 {LEFT_ARROW} FORTREE CITY$"

Route120_Text_RouteSign121::
# 58 "data/maps/Route120/scripts.pory"
	.string "{RIGHT_ARROW} ROUTE 121 {LEFT_ARROW} ROUTE 120$"
