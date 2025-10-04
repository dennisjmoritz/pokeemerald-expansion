Route116_MapScripts::
	.byte 0


Route116_EventScript_Briney::
# 5 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	end


Route116_EventScript_BrineyTrigger::
# 10 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	end


Route116_EventScript_Clark::
# 15 "data/maps/Route116/scripts.pory"
	trainerbattle_double TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_ClarkPostBattle
	return


Route116_EventScript_Dawson::
# 20 "data/maps/Route116/scripts.pory"
	trainerbattle_double TRAINER_DAWSON, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DawsonPostBattle
	return


Route116_EventScript_Devan::
# 25 "data/maps/Route116/scripts.pory"
	trainerbattle_double TRAINER_DEVAN, Route116_Text_DevanIntro, Route116_Text_DevanDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_DevanPostBattle
	return


Route116_EventScript_DevonEmployee::
	end


Route116_EventScript_GlassesMan::
	end


Route116_EventScript_Janice::
# 38 "data/maps/Route116/scripts.pory"
	trainerbattle_double TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat, Text_NotEnoughMonsForDoubleBattle
# 39 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JanicePostBattle
	return


Route116_EventScript_Jerry::
# 43 "data/maps/Route116/scripts.pory"
	trainerbattle_double TRAINER_JERRY, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Text_NotEnoughMonsForDoubleBattle
# 44 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JerryPostBattle
	return


Route116_EventScript_Joey::
# 48 "data/maps/Route116/scripts.pory"
	trainerbattle_double TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat, Text_NotEnoughMonsForDoubleBattle
# 49 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JoeyPostBattle
	return


Route116_EventScript_Johnson::
# 53 "data/maps/Route116/scripts.pory"
	trainerbattle_double TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat, Text_NotEnoughMonsForDoubleBattle
# 54 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JohnsonPostBattle
	return


Route116_EventScript_Jose::
# 58 "data/maps/Route116/scripts.pory"
	trainerbattle_double TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat, Text_NotEnoughMonsForDoubleBattle
# 59 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_JosePostBattle
	return


Route116_EventScript_Karen::
# 63 "data/maps/Route116/scripts.pory"
	trainerbattle_double TRAINER_KAREN, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Text_NotEnoughMonsForDoubleBattle
# 64 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_KarenPostBattle
	return


Route116_EventScript_RouteSignRustboro::
# 68 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
	end


Route116_EventScript_RusturfTunnelSign::
# 73 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
	end


Route116_EventScript_Sarah::
# 78 "data/maps/Route116/scripts.pory"
	trainerbattle_double TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat, Text_NotEnoughMonsForDoubleBattle
# 79 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_SarahPostBattle
	return


Route116_EventScript_TrainerTipsBToStopEvolution::
# 83 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
	end


Route116_EventScript_TrainerTipsBagHasPockets::
# 88 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
	end


Route116_EventScript_TunnelersRestHouseSign::
# 93 "data/maps/Route116/scripts.pory"
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
	end


Route116_EventScript_WandasBoyfriend::
	end


Route116_Text_TrainerTipsBagHasPockets::
# 102 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "Your BAG has several POCKETS.\p"
	.string "Items you obtain are automatically\n"
	.string "placed in the appropriate POCKETS.\p"
	.string "No TRAINER can afford to be without a\n"
	.string "BAG of their own.$"

Route116_Text_RusturfTunnelSign::
# 106 "data/maps/Route116/scripts.pory"
	.string "RUSTURF TUNNEL “Linking RUSTBORO and\n"
	.string "VERDANTURF\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"

Route116_Text_TunnelersRestHouse::
# 110 "data/maps/Route116/scripts.pory"
	.string "TUNNELER'S REST HOUSE$"

Route116_Text_TrainerTipsBToStopEvolution::
# 114 "data/maps/Route116/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "If you want to stop a POKéMON from\n"
	.string "evolving, press the B Button while it\l"
	.string "is trying to evolve.\l"
	.string "The startled POKéMON will stop.\p"
	.string "This is called an evolution cancel.$"

Route116_Text_RouteSignRustboro::
# 118 "data/maps/Route116/scripts.pory"
	.string "ROUTE 116 {LEFT_ARROW} RUSTBORO CITY$"

Route116_Text_ClarkDefeat::
# 123 "data/maps/Route116/scripts.pory"
	.string "Gasp… Gasp… Losing made me tired…$"

Route116_Text_ClarkIntro::
# 127 "data/maps/Route116/scripts.pory"
	.string "If the tunnel doesn't go through, then\n"
	.string "I'll just go over the top.$"

Route116_Text_ClarkPostBattle::
# 131 "data/maps/Route116/scripts.pory"
	.string "It's no big deal if there's no tunnel. To\n"
	.string "a HIKER, mountains are roads!$"

Route116_Text_DawsonDefeat::
# 135 "data/maps/Route116/scripts.pory"
	.string "Oh, baby, say it isn't so!$"

Route116_Text_DawsonIntro::
# 139 "data/maps/Route116/scripts.pory"
	.string "When you lay your eyes on my POKéMON's\n"
	.string "gorgeous fur, their beauty will render\l"
	.string "you helpless!$"

Route116_Text_DawsonPostBattle::
# 143 "data/maps/Route116/scripts.pory"
	.string "Oh, no, no, no! You've mussed up my\n"
	.string "POKéMON's fur! You've ruined my hairdo,\l"
	.string "too! I'll have to call my stylist now!$"

Route116_Text_DevanDefeat::
# 147 "data/maps/Route116/scripts.pory"
	.string "Aiyiyi! No contest at all!$"

Route116_Text_DevanIntro::
# 151 "data/maps/Route116/scripts.pory"
	.string "We'll rock you hard!$"

Route116_Text_DevanPostBattle::
# 155 "data/maps/Route116/scripts.pory"
	.string "I should try different POKéMON types,\n"
	.string "that's what I ought to do.$"

Route116_Text_JaniceDefeat::
# 159 "data/maps/Route116/scripts.pory"
	.string "You're a notch above me…$"

Route116_Text_JaniceIntro::
# 163 "data/maps/Route116/scripts.pory"
	.string "Let me teach you how strong my\n"
	.string "adorable POKéMON is!$"

Route116_Text_JanicePostBattle::
# 167 "data/maps/Route116/scripts.pory"
	.string "POKéMON that possess cuteness and\n"
	.string "power, that's ideal, I think.$"

Route116_Text_JerryDefeat::
# 171 "data/maps/Route116/scripts.pory"
	.string "I slacked off in school… That's why I\n"
	.string "lost.$"

Route116_Text_JerryIntro::
# 175 "data/maps/Route116/scripts.pory"
	.string "We learn all sorts of things at the\n"
	.string "TRAINER'S SCHOOL.\p"
	.string "I want to test things out for real!$"

Route116_Text_JerryPostBattle::
# 179 "data/maps/Route116/scripts.pory"
	.string "I'll have to redo some courses at the\n"
	.string "TRAINER'S SCHOOL. If I don't, ROXANNE\l"
	.string "will be steamed.$"

Route116_Text_JoeyDefeat::
# 183 "data/maps/Route116/scripts.pory"
	.string "Ouch! A scrape! I have to put on a\n"
	.string "bandage!$"

Route116_Text_JoeyIntro::
# 187 "data/maps/Route116/scripts.pory"
	.string "My POKéMON rule! Check them out!$"

Route116_Text_JoeyPostBattle::
# 191 "data/maps/Route116/scripts.pory"
	.string "Bandages are signs of toughness! I've\n"
	.string "got another one!$"

Route116_Text_JohnsonDefeat::
# 195 "data/maps/Route116/scripts.pory"
	.string "That was fun even though I lost.$"

Route116_Text_JohnsonIntro::
# 199 "data/maps/Route116/scripts.pory"
	.string "It's a dead end up here. I'm bored, so\n"
	.string "can we battle?$"

Route116_Text_JohnsonPostBattle::
# 203 "data/maps/Route116/scripts.pory"
	.string "Want to stay here and keep me company?$"

Route116_Text_JoseDefeat::
# 207 "data/maps/Route116/scripts.pory"
	.string "I lost! I thought I had you!$"

Route116_Text_JoseIntro::
# 211 "data/maps/Route116/scripts.pory"
	.string "My BUG POKéMON are tough! Let's battle!$"

Route116_Text_JosePostBattle::
# 215 "data/maps/Route116/scripts.pory"
	.string "BUG POKéMON evolve quickly. So they get\n"
	.string "strong quickly, too.$"

Route116_Text_KarenDefeat::
# 219 "data/maps/Route116/scripts.pory"
	.string "I'm in shock--I lost?$"

Route116_Text_KarenIntro::
# 223 "data/maps/Route116/scripts.pory"
	.string "I study at school, and I study on the\n"
	.string "way home, too!$"

Route116_Text_KarenPostBattle::
# 227 "data/maps/Route116/scripts.pory"
	.string "Awww, I'll never become an elegant\n"
	.string "TRAINER like ROXANNE this way!$"

Route116_Text_SarahDefeat::
# 231 "data/maps/Route116/scripts.pory"
	.string "Oh, my goodness. This is a new\n"
	.string "experience for me.$"

Route116_Text_SarahIntro::
# 235 "data/maps/Route116/scripts.pory"
	.string "Just so you know, I've never once been\n"
	.string "bested by anyone at anything.$"

Route116_Text_SarahPostBattle::
# 239 "data/maps/Route116/scripts.pory"
	.string "My life of luxury affords me all that I\n"
	.string "could possibly desire.\p"
	.string "However, when it comes to POKéMON, my\n"
	.string "wealth has no meaning.$"

Route116_Text_DiggingTunnelWhenGoonOrderedMeOut::
# 243 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\n"
	.string "What's going on?\p"
	.string "I was digging the tunnel without any\n"
	.string "tools when some goon ordered me out!\p"
	.string "That tunnel's filled with POKéMON\n"
	.string "that react badly to loud noises.\l"
	.string "They could cause an uproar.\p"
	.string "That's why we stopped using heavy\n"
	.string "equipment for tunneling…\p"
	.string "I'm worried that the goon will do\n"
	.string "something stupid and startle the\l"
	.string "POKéMON into an uproar.$"

Route116_Text_TokenOfAppreciation::
# 247 "data/maps/Route116/scripts.pory"
	.string "As a token of our appreciation for\n"
	.string "your delivering our package, I have\l"
	.string "a gift of a new kind of POKé BALL\l"
	.string "for our most wonderful TRAINER!$"

Route116_Text_BagIsJamPacked::
# 251 "data/maps/Route116/scripts.pory"
	.string "Your BAG is jam-packed.\n"
	.string "I can't give you this REPEAT BALL.$"

Route116_Text_ScoundrelMadeOffWithPeeko::
# 255 "data/maps/Route116/scripts.pory"
	.string "Ohhh, what am I to do?\p"
	.string "We were on our walk, PEEKO and I, when\n"
	.string "we were jumped by an odd thug…\p"
	.string "The scoundrel made off with my\n"
	.string "darling PEEKO!\p"
	.string "Wrrrooooooaaaar! PEEKO!$"

Route116_Text_NotWhatImLookingForMaybeTheyArentHere::
# 259 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
	.string "These are BLACKGLASSES.\l"
	.string "They're not what I'm looking for…\p"
	.string "Maybe my glasses aren't around\n"
	.string "here…$"

Route116_Text_GoonHightailedItOutOfTunnel::
# 263 "data/maps/Route116/scripts.pory"
	.string "Nnn… Roar!\p"
	.string "That goofy goon hightailed it out of\n"
	.string "the tunnel! I can go back to digging!$"

Route116_Text_CanYouHelpMeFindGlasses::
# 267 "data/maps/Route116/scripts.pory"
	.string "I dropped my glasses…\n"
	.string "Can you help me find them?$"

Route116_Text_CantFindGlassesNotHere::
# 271 "data/maps/Route116/scripts.pory"
	.string "Hmm…\n"
	.string "I can't find my glasses anywhere…\l"
	.string "Maybe they're not around here…$"
