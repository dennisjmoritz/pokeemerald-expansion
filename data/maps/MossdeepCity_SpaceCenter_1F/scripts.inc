MossdeepCity_SpaceCenter_1F_MapScripts::
	.byte 0


MossdeepCity_SpaceCenter_1F_EventScript_Grunt1::
# 5 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_SPACE_CENTER, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle
	return


MossdeepCity_SpaceCenter_1F_EventScript_Grunt2::
	end


MossdeepCity_SpaceCenter_1F_EventScript_Grunt3::
# 14 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_SPACE_CENTER_3, MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat, Text_NotEnoughMonsForDoubleBattle
# 15 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle
	return


MossdeepCity_SpaceCenter_1F_EventScript_Grunt4::
# 19 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	trainerbattle_double TRAINER_GRUNT_SPACE_CENTER_4, MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat, Text_NotEnoughMonsForDoubleBattle
# 20 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle
	return


MossdeepCity_SpaceCenter_1F_EventScript_MagmaNote::
# 24 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice, MSGBOX_DEFAULT
	end


MossdeepCity_SpaceCenter_1F_EventScript_OldMan::
	end


MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter::
	end


MossdeepCity_SpaceCenter_1F_EventScript_Scientist::
	end


MossdeepCity_SpaceCenter_1F_EventScript_Steven::
# 41 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	msgbox MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel, MSGBOX_DEFAULT
	end


MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan::
	end


MossdeepCity_SpaceCenter_1F_EventScript_Woman::
	end


MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat::
# 55 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro::
# 59 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle::
# 63 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat::
# 67 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro::
# 71 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle::
# 75 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat::
# 79 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro::
# 83 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle::
# 87 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Placeholder text for\n"
	.string "MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle$"

MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream::
# 91 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "A giant chunk of metal bursts through\n"
	.string "the skies and flies into space…\p"
	.string "But TEAM MAGMA wants to spoil\n"
	.string "that dream of mine!\p"
	.string "I'm not having any of that!$"

MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber::
# 95 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket launched safely!\n"
	.string "That's successful launch no.\l"
	.string "{STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel::
# 99 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "STEVEN: {PLAYER}{KUN}, have you read that\n"
	.string "proclamation already?\p"
	.string "TEAM MAGMA is coming after the rocket\n"
	.string "fuel on this island.\p"
	.string "I don't know what they'd need it for,\n"
	.string "but they can't be allowed to take it.\p"
	.string "I'll keep an eye on things for\n"
	.string "a while longer.\p"
	.string "In the meantime, why don't you go\n"
	.string "check out the town?$"

MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma::
# 103 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "With TEAM MAGMA around, I guess\n"
	.string "strolls on the beach aren't safe.$"

MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers::
# 107 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The HOENN region has been famous for\n"
	.string "its meteor showers for a long time.$"

MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma::
# 111 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "TEAM AQUA should take care of\n"
	.string "TEAM MAGMA!\p"
	.string "But if they did that, TEAM AQUA will\n"
	.string "become bold and brazen, won't they?$"

MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice::
# 115 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "This is…\n"
	.string "An intent-to-steal notice?\p"
	.string "“To the staff of the SPACE CENTER:\n"
	.string "How are you? We are doing fine.\p"
	.string "“We will soon visit you to take your\n"
	.string "rocket fuel.\p"
	.string "“Please don't try to stop us.\n"
	.string "We will take the fuel no matter what.\p"
	.string "“Let there be more land!\n"
	.string "TEAM MAGMA”$"

MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter::
# 119 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Those MAGMA thugs have their sights\n"
	.string "set on our SPACE CENTER.\p"
	.string "But we can't allow anything that minor\n"
	.string "to interfere with our rocket launch!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber::
# 123 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I know that things are a little\n"
	.string "haywire right now, but…\p"
	.string "The rocket launched safely!\n"
	.string "That's successful launch no.\l"
	.string "{STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle::
# 127 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Please, tell our leader that\n"
	.string "I never abandoned my post.\l"
	.string "That I stayed to the bitter end…$"

MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace::
# 131 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "Some people claim that POKéMON came\n"
	.string "from space. Could it be true?$"

MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind::
# 135 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "A giant chunk of metal bursts through\n"
	.string "the skies and flies into space…\p"
	.string "It boggles my mind!$"

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent::
# 139 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "The rocket's launch is imminent!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent::
# 143 "data/maps/MossdeepCity_SpaceCenter_1F/scripts.pory"
	.string "I know that things are a little\n"
	.string "haywire right now, but…\p"
	.string "The rocket's launch is imminent!$"
