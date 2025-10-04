Route114_MapScripts::
	.byte 0


Route114_EventScript_Angelina::
# 5 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_ANGELINA, Route114_Text_AngelinaIntro, Route114_Text_AngelinaDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_AngelinaPostBattle
	return


Route114_EventScript_Bernie::
# 10 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_BERNIE, Route114_Text_BernieIntro, Route114_Text_BernieDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_BerniePostBattle
	return


Route114_EventScript_Charlotte::
# 15 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_CHARLOTTE, Route114_Text_CharlotteIntro, Route114_Text_CharlotteDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_CharlottePostBattle
	return


Route114_EventScript_Claude::
# 20 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_CLAUDE, Route114_Text_ClaudeIntro, Route114_Text_ClaudeDefeat, Text_NotEnoughMonsForDoubleBattle
# 21 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ClaudePostBattle
	return


Route114_EventScript_FossilManiacsHouseSign::
# 25 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_FossilManiacsHouseSign, MSGBOX_SIGN
	end


Route114_EventScript_Ivy::
# 30 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_IvyPostBattle, MSGBOX_AUTOCLOSE
	end


Route114_EventScript_Kai::
# 35 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_KAI, Route114_Text_KaiIntro, Route114_Text_KaiDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_KaiPostBattle
	return


Route114_EventScript_LanettesHouseSign::
# 40 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LanettesHouse, MSGBOX_SIGN
	end


Route114_EventScript_Lenny::
# 45 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_LENNY, Route114_Text_LennyIntro, Route114_Text_LennyDefeat, Text_NotEnoughMonsForDoubleBattle
# 46 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LennyPostBattle
	return


Route114_EventScript_Lucas::
# 50 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_LUCAS, Route114_Text_LucasIntro, Route114_Text_LucasDefeat, Text_NotEnoughMonsForDoubleBattle
# 51 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_LucasPostBattle
	return


Route114_EventScript_Man::
	end


Route114_EventScript_MeteorFallsSign::
# 59 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_MeteorFallsSign, MSGBOX_SIGN
	end


Route114_EventScript_Nancy::
# 64 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_NANCY, Route114_Text_NancyIntro, Route114_Text_NancyDefeat, Text_NotEnoughMonsForDoubleBattle
# 65 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_NancyPostBattle
	return


Route114_EventScript_Nolan::
# 69 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_NOLAN, Route114_Text_NolanIntro, Route114_Text_NolanDefeat, Text_NotEnoughMonsForDoubleBattle
# 70 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_NolanPostBattle
	return


Route114_EventScript_Poochyena::
# 74 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_Poochyena, MSGBOX_DEFAULT
	end


Route114_EventScript_RoarGentleman::
	end


Route114_EventScript_Shane::
# 83 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_SHANE, Route114_Text_ShaneIntro, Route114_Text_ShaneDefeat, Text_NotEnoughMonsForDoubleBattle
# 84 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_ShanePostBattle
	return


Route114_EventScript_Steve::
# 88 "data/maps/Route114/scripts.pory"
	trainerbattle_double TRAINER_STEVE, Route114_Text_SteveIntro, Route114_Text_SteveDefeat, Text_NotEnoughMonsForDoubleBattle
# 89 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_StevePostBattle
	return


Route114_EventScript_Tyra::
# 93 "data/maps/Route114/scripts.pory"
	msgbox Route114_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end


Route114_Text_MeteorFallsSign::
# 98 "data/maps/Route114/scripts.pory"
	.string "METEOR FALLS RUSTBORO CITY THROUGH\n"
	.string "HERE$"

Route114_Text_LanettesHouse::
# 102 "data/maps/Route114/scripts.pory"
	.string "LANETTE'S HOUSE$"

Route114_Text_FossilManiacsHouseSign::
# 106 "data/maps/Route114/scripts.pory"
	.string "FOSSIL MANIAC'S HOUSE “Fossils\n"
	.string "gratefully accepted!”$"

Route114_Text_AngelinaDefeat::
# 111 "data/maps/Route114/scripts.pory"
	.string "Oh, I see. That's good to know.$"

Route114_Text_AngelinaIntro::
# 115 "data/maps/Route114/scripts.pory"
	.string "Have you made your POKéMON evolve very\n"
	.string "much?$"

Route114_Text_AngelinaPostBattle::
# 119 "data/maps/Route114/scripts.pory"
	.string "Some POKéMON change so much when they\n"
	.string "evolve, it's startling!$"

Route114_Text_BernieDefeat::
# 123 "data/maps/Route114/scripts.pory"
	.string "Thanks for dousing my fire!$"

Route114_Text_BernieIntro::
# 127 "data/maps/Route114/scripts.pory"
	.string "If you're lighting a campfire, make sure\n"
	.string "you have water handy.$"

Route114_Text_BerniePostBattle::
# 131 "data/maps/Route114/scripts.pory"
	.string "You really do have to be careful with\n"
	.string "any sort of fire in a forest.\p"
	.string "Don't ever underestimate the power of\n"
	.string "fire.$"

Route114_Text_CharlotteDefeat::
# 135 "data/maps/Route114/scripts.pory"
	.string "That wasn't cute in the least!$"

Route114_Text_CharlotteIntro::
# 139 "data/maps/Route114/scripts.pory"
	.string "Me! I'm not just a pretty face!$"

Route114_Text_CharlottePostBattle::
# 143 "data/maps/Route114/scripts.pory"
	.string "I don't want a POKéMON that's just\n"
	.string "cute.\p"
	.string "I adore cute ones that have a quirk or\n"
	.string "two!$"

Route114_Text_ClaudeDefeat::
# 147 "data/maps/Route114/scripts.pory"
	.string "If we were fishing, I would've won…$"

Route114_Text_ClaudeIntro::
# 151 "data/maps/Route114/scripts.pory"
	.string "If we were fishing, you wouldn't stand a\n"
	.string "chance against me. So, bring on your\l"
	.string "POKéMON!$"

Route114_Text_ClaudePostBattle::
# 155 "data/maps/Route114/scripts.pory"
	.string "I think I'll try my luck at landing a big\n"
	.string "one at METEOR FALLS.\p"
	.string "There has to be something in there. I\n"
	.string "just know it.$"

Route114_Text_KaiDefeat::
# 159 "data/maps/Route114/scripts.pory"
	.string "What was that about? Did mine lose in\n"
	.string "size?$"

Route114_Text_KaiIntro::
# 163 "data/maps/Route114/scripts.pory"
	.string "I landed a big one! A huge one, I tell\n"
	.string "you!$"

Route114_Text_KaiPostBattle::
# 167 "data/maps/Route114/scripts.pory"
	.string "Okay! I'll just fish me a bigger one!$"

Route114_Text_LennyDefeat::
# 171 "data/maps/Route114/scripts.pory"
	.string "Yodelayhihoo!$"

Route114_Text_LennyIntro::
# 175 "data/maps/Route114/scripts.pory"
	.string "Yodelayhihoo!\p"
	.string "… …\p"
	.string "You're supposed to shout\n"
	.string "“yodelayhihoo” since it doesn't echo\l"
	.string "here!$"

Route114_Text_LennyPostBattle::
# 179 "data/maps/Route114/scripts.pory"
	.string "When I was a wee tyke, I believed there\n"
	.string "was someone copying me and shouting\l"
	.string "back, “Yodelayhihoo.”$"

Route114_Text_LucasDefeat::
# 183 "data/maps/Route114/scripts.pory"
	.string "The mountains are unforgiving…$"

Route114_Text_LucasIntro::
# 187 "data/maps/Route114/scripts.pory"
	.string "If you're not prepared, you shouldn't be\n"
	.string "up in the mountains!$"

Route114_Text_LucasPostBattle::
# 191 "data/maps/Route114/scripts.pory"
	.string "In the winter, mountains turn deadly\n"
	.string "with blizzards and avalanches.$"

Route114_Text_NancyDefeat::
# 195 "data/maps/Route114/scripts.pory"
	.string "Oh, no!$"

Route114_Text_NancyIntro::
# 199 "data/maps/Route114/scripts.pory"
	.string "I need to exercise after a meal. Let's\n"
	.string "have a match!$"

Route114_Text_NancyPostBattle::
# 203 "data/maps/Route114/scripts.pory"
	.string "I just had a tasty meal. I'm getting\n"
	.string "drowsy…$"

Route114_Text_NolanDefeat::
# 207 "data/maps/Route114/scripts.pory"
	.string "I like to battle, but that doesn't mean\n"
	.string "I'm good at it…$"

Route114_Text_NolanIntro::
# 211 "data/maps/Route114/scripts.pory"
	.string "I like to fish. But I also like to battle!\p"
	.string "If anyone challenges me, I'm there, even\n"
	.string "if I'm fishing.$"

Route114_Text_NolanPostBattle::
# 215 "data/maps/Route114/scripts.pory"
	.string "This time I'll do it!\p"
	.string "I always think that, so I can't walk\n"
	.string "away from fishing or POKéMON.$"

Route114_Text_ShaneDefeat::
# 219 "data/maps/Route114/scripts.pory"
	.string "Way too strong!$"

Route114_Text_ShaneIntro::
# 223 "data/maps/Route114/scripts.pory"
	.string "Camping's fun! You can fish, roast\n"
	.string "marshmallows, and tell spooky stories!\p"
	.string "But the best of all are the POKéMON\n"
	.string "battles!$"

Route114_Text_ShanePostBattle::
# 227 "data/maps/Route114/scripts.pory"
	.string "I think it's great that I can go camping\n"
	.string "with my POKéMON.$"

Route114_Text_SteveDefeat::
# 231 "data/maps/Route114/scripts.pory"
	.string "M-My POKéMON…$"

Route114_Text_SteveIntro::
# 235 "data/maps/Route114/scripts.pory"
	.string "Ufufufufufu… Want to battle against\n"
	.string "my POKéMON?$"

Route114_Text_StevePostBattle::
# 239 "data/maps/Route114/scripts.pory"
	.string "A big body that's all lumpy and hard,\n"
	.string "enormous horns, and vicious fangs…\p"
	.string "Ufufufufu… I wish I had a POKéMON like\n"
	.string "that…$"

Route114_Text_ExplainRoar::
# 243 "data/maps/Route114/scripts.pory"
	.string "TM05 contains ROAR.\n"
	.string "A ROAR sends POKéMON scurrying.$"

Route114_Text_Poochyena::
# 247 "data/maps/Route114/scripts.pory"
	.string "Bow! Bowwow!$"

Route114_Text_IvyPostBattle::
# 251 "data/maps/Route114/scripts.pory"
	.string "IVY: I started training POKéMON\n"
	.string "because TYRA, my student mentor,\l"
	.string "taught me!$"

Route114_Text_TyraPostBattle::
# 255 "data/maps/Route114/scripts.pory"
	.string "TYRA: I was teaching my junior IVY\n"
	.string "about POKéMON.$"
