Route113_MapScripts::
	.byte 0


Route113_EventScript_Coby::
# 5 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_COBY, Route113_Text_CobyIntro, Route113_Text_CobyDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_CobyPostBattle
	return


Route113_EventScript_Dillon::
# 10 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_DILLON, Route113_Text_DillonIntro, Route113_Text_DillonDefeat, Text_NotEnoughMonsForDoubleBattle
# 11 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_DillonPostBattle
	return


Route113_EventScript_Gentleman::
# 15 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_AshCanBeFashionedIntoGlass, MSGBOX_NPC
	end


Route113_EventScript_GlassWorkshopSign::
# 20 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_GlassWorkshopSign, MSGBOX_SIGN
	end


Route113_EventScript_Jaylen::
# 25 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_JAYLEN, Route113_Text_JaylenIntro, Route113_Text_JaylenDefeat, Text_NotEnoughMonsForDoubleBattle
# 26 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_JaylenPostBattle
	return


Route113_EventScript_Lao::
# 30 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_LAO, Route113_Text_LaoIntro, Route113_Text_LaoDefeat, Text_NotEnoughMonsForDoubleBattle
# 31 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LaoPostBattle
	return


Route113_EventScript_Lawrence::
# 35 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_LAWRENCE, Route113_Text_LawrenceIntro, Route113_Text_LawrenceDefeat, Text_NotEnoughMonsForDoubleBattle
# 36 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LawrencePostBattle
	return


Route113_EventScript_Lung::
# 40 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_LUNG, Route113_Text_LungIntro, Route113_Text_LungDefeat, Text_NotEnoughMonsForDoubleBattle
# 41 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_LungPostBattle
	return


Route113_EventScript_Madeline::
# 45 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_MADELINE, Route113_Text_MadelineIntro, Route113_Text_MadelineDefeat, Text_NotEnoughMonsForDoubleBattle
# 46 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_MadelinePostBattle
	return


Route113_EventScript_NinjaBoy::
# 50 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_FunWalkingThroughAsh, MSGBOX_NPC
	end


Route113_EventScript_RouteSign111::
# 55 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_RouteSign111, MSGBOX_SIGN
	end


Route113_EventScript_RouteSignFallarbor::
# 60 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_RouteSignFallarbor, MSGBOX_SIGN
	end


Route113_EventScript_Sophie::
# 65 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_SOPHIE, Route113_Text_SophieIntro, Route113_Text_SophieDefeat, Text_NotEnoughMonsForDoubleBattle
# 66 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_SophiePostBattle
	return


Route113_EventScript_Tia::
# 70 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_TiaPostBattle, MSGBOX_AUTOCLOSE
	end


Route113_EventScript_Tori::
# 75 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_ToriPostBattle, MSGBOX_AUTOCLOSE
	end


Route113_EventScript_TrainerTipsRegisterKeyItems::
# 80 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_TrainerTipsRegisterKeyItems, MSGBOX_SIGN
	end


Route113_EventScript_Wyatt::
# 85 "data/maps/Route113/scripts.pory"
	trainerbattle_double TRAINER_WYATT, Route113_Text_WyattIntro, Route113_Text_WyattDefeat, Text_NotEnoughMonsForDoubleBattle
# 86 "data/maps/Route113/scripts.pory"
	msgbox Route113_Text_WyattPostBattle
	return


Route113_Text_RouteSign111::
# 90 "data/maps/Route113/scripts.pory"
	.string "ROUTE 113 {RIGHT_ARROW} ROUTE 111$"

Route113_Text_TrainerTipsRegisterKeyItems::
# 94 "data/maps/Route113/scripts.pory"
	.string "TRAINER TIPS\p"
	.string "You may register one of the KEY ITEMS\n"
	.string "in your BAG as SELECT.\p"
	.string "Simply press SELECT to use the\n"
	.string "registered item conveniently.$"

Route113_Text_GlassWorkshopSign::
# 98 "data/maps/Route113/scripts.pory"
	.string "GLASS WORKSHOP “Turning Volcanic Ash\n"
	.string "into Glass Items”$"

Route113_Text_RouteSignFallarbor::
# 102 "data/maps/Route113/scripts.pory"
	.string "ROUTE 113 {LEFT_ARROW} FALLARBOR TOWN$"

Route113_Text_CobyDefeat::
# 107 "data/maps/Route113/scripts.pory"
	.string "A… What?$"

Route113_Text_CobyIntro::
# 111 "data/maps/Route113/scripts.pory"
	.string "Pfft, with these wings I can flick you\n"
	.string "away!$"

Route113_Text_CobyPostBattle::
# 115 "data/maps/Route113/scripts.pory"
	.string "I don't know what to say when I get\n"
	.string "beaten so easily…$"

Route113_Text_DillonDefeat::
# 119 "data/maps/Route113/scripts.pory"
	.string "You're some kind of strong!$"

Route113_Text_DillonIntro::
# 123 "data/maps/Route113/scripts.pory"
	.string "The volcano's eruption is proof that\n"
	.string "the earth is alive.$"

Route113_Text_DillonPostBattle::
# 127 "data/maps/Route113/scripts.pory"
	.string "Ouch! Owww! I can't see! I got ashes in\n"
	.string "my eyelashes!\p"
	.string "Get it? Ashes and eyelashes?\p"
	.string "Okay, that was bad, sorry…$"

Route113_Text_JaylenDefeat::
# 131 "data/maps/Route113/scripts.pory"
	.string "Peeuuw! That stinks!$"

Route113_Text_JaylenIntro::
# 135 "data/maps/Route113/scripts.pory"
	.string "Can you guess why it's so cool around\n"
	.string "here?$"

Route113_Text_JaylenPostBattle::
# 139 "data/maps/Route113/scripts.pory"
	.string "The volcanic ash blocks the sun, so it\n"
	.string "doesn't get very warm.\p"
	.string "That's good for me--I can't stand heat!$"

Route113_Text_LaoDefeat::
# 143 "data/maps/Route113/scripts.pory"
	.string "With honor I admit defeat!$"

Route113_Text_LaoIntro::
# 147 "data/maps/Route113/scripts.pory"
	.string "From out of the ashes I leap! Hiyah! I\n"
	.string "challenge thee!$"

Route113_Text_LaoPostBattle::
# 151 "data/maps/Route113/scripts.pory"
	.string "I must refine the art of concealment. I\n"
	.string "bid thee farewell.$"

Route113_Text_LawrenceDefeat::
# 155 "data/maps/Route113/scripts.pory"
	.string "Ehehe. We got beaten cleanly.$"

Route113_Text_LawrenceIntro::
# 159 "data/maps/Route113/scripts.pory"
	.string "Were you maybe in the middle of\n"
	.string "gathering volcanic ashes?$"

Route113_Text_LawrencePostBattle::
# 163 "data/maps/Route113/scripts.pory"
	.string "I ought to hide under the ashes, too.$"

Route113_Text_LungDefeat::
# 167 "data/maps/Route113/scripts.pory"
	.string "I'll use my ninjutsu on you… “VOLCANIC\n"
	.string "ASH SWIRL CLOAK”!\p"
	.string "…What? It's already over?$"

Route113_Text_LungIntro::
# 171 "data/maps/Route113/scripts.pory"
	.string "Thanks for finding me! But we still have\n"
	.string "to battle!$"

Route113_Text_LungPostBattle::
# 175 "data/maps/Route113/scripts.pory"
	.string "You know what's crummy about hiding?\n"
	.string "It's lonely if no one comes along.$"

Route113_Text_MadelineDefeat::
# 179 "data/maps/Route113/scripts.pory"
	.string "Huff, huff… I am exhausted…$"

Route113_Text_MadelineIntro::
# 183 "data/maps/Route113/scripts.pory"
	.string "I use this parasol to ward off this\n"
	.string "filthy, yucky volcanic ash from my dear\l"
	.string "NUMEL.$"

Route113_Text_MadelinePostBattle::
# 187 "data/maps/Route113/scripts.pory"
	.string "You're very good at this. I must say I'm\n"
	.string "impressed!$"

Route113_Text_SophieDefeat::
# 191 "data/maps/Route113/scripts.pory"
	.string "This is a dream. I'm sure of it…$"

Route113_Text_SophieIntro::
# 195 "data/maps/Route113/scripts.pory"
	.string "The warmth here is making me drowsy.\n"
	.string "Battle with me so I can stay awake.$"

Route113_Text_SophiePostBattle::
# 199 "data/maps/Route113/scripts.pory"
	.string "Losing burns me up… I'm just going to\n"
	.string "sleep right here! Zzz!$"

Route113_Text_WyattDefeat::
# 203 "data/maps/Route113/scripts.pory"
	.string "Y-you're all happy to win? Even though\n"
	.string "it's only me?$"

Route113_Text_WyattIntro::
# 207 "data/maps/Route113/scripts.pory"
	.string "Y-you want to battle with me? Even\n"
	.string "though I just caught my POKéMON?$"

Route113_Text_WyattPostBattle::
# 211 "data/maps/Route113/scripts.pory"
	.string "Oh, so now you want to say a word to the\n"
	.string "loser?\p"
	.string "Aren't you just the coolest? Humph!$"

Route113_Text_FunWalkingThroughAsh::
# 215 "data/maps/Route113/scripts.pory"
	.string "It's fun walking through the volcano's\n"
	.string "ashes on the ground and grass.\p"
	.string "You can see where you walked--it's\n"
	.string "really neat!$"

Route113_Text_AshCanBeFashionedIntoGlass::
# 219 "data/maps/Route113/scripts.pory"
	.string "Wahahaha! Today's technology is a\n"
	.string "wondrous thing!\p"
	.string "Take this volcanic ash here.\n"
	.string "It can be fashioned into glass.$"

Route113_Text_TiaPostBattle::
# 223 "data/maps/Route113/scripts.pory"
	.string "TIA: We have a lot of ashes! I think\n"
	.string "enough for a WHITE FLUTE!$"

Route113_Text_ToriPostBattle::
# 227 "data/maps/Route113/scripts.pory"
	.string "TORI: How much ash do we have? Enough\n"
	.string "for a WHITE FLUTE, I hope.$"
