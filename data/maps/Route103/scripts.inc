Route103_MapScripts::
	.byte 0


Route103_EventScript_Amy::
	end


Route103_EventScript_Andrew::
# 9 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated, Text_NotEnoughMonsForDoubleBattle
# 10 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_AndrewPostBattle
	return


Route103_EventScript_Boy::
# 14 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end


Route103_EventScript_Daisy::
# 19 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated, Text_NotEnoughMonsForDoubleBattle
# 20 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_DaisyPostBattle
	return


Route103_EventScript_Isabelle::
# 24 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated, Text_NotEnoughMonsForDoubleBattle
# 25 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_IsabellePostBattle
	return


Route103_EventScript_Liv::
	end


Route103_EventScript_Man::
# 33 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end


Route103_EventScript_Marcos::
# 38 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated, Text_NotEnoughMonsForDoubleBattle
# 39 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MarcosPostBattle
	return


Route103_EventScript_Miguel::
# 43 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_MIGUEL, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Text_NotEnoughMonsForDoubleBattle
# 44 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_MiguelPostBattle
	return


Route103_EventScript_Pete::
# 48 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated, Text_NotEnoughMonsForDoubleBattle
# 49 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_PetePostBattle
	return


Route103_EventScript_Rhett::
# 53 "data/maps/Route103/scripts.pory"
	trainerbattle_double TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated, Text_NotEnoughMonsForDoubleBattle
# 54 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RhettPostBattle
	return


Route103_EventScript_Rival::
	end


Route103_EventScript_RouteSign::
# 62 "data/maps/Route103/scripts.pory"
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end


Route103_Text_RouteSign::
# 67 "data/maps/Route103/scripts.pory"
	.string "ROUTE 103 {DOWN_ARROW} OLDALE TOWN$"

Route103_Text_AndrewDefeated::
# 72 "data/maps/Route103/scripts.pory"
	.string "Gah! Lost it! I'm even more annoyed now!$"

Route103_Text_AndrewIntro::
# 76 "data/maps/Route103/scripts.pory"
	.string "Gah! My fishing line's all snarled up! I'm\n"
	.string "getting frustrated and mean! That's it!\l"
	.string "Battle me!$"

Route103_Text_AndrewPostBattle::
# 80 "data/maps/Route103/scripts.pory"
	.string "Gah, I'm still boiling mad… Grrrrr…$"

Route103_Text_DaisyDefeated::
# 84 "data/maps/Route103/scripts.pory"
	.string "You weren't led astray by our aroma…$"

Route103_Text_DaisyIntro::
# 88 "data/maps/Route103/scripts.pory"
	.string "Did you feel the tug of our\n"
	.string "soul-soothing fragrance?$"

Route103_Text_DaisyPostBattle::
# 92 "data/maps/Route103/scripts.pory"
	.string "Aromatherapy is a form of mental\n"
	.string "healing that works with fragrances.$"

Route103_Text_IsabelleDefeated::
# 96 "data/maps/Route103/scripts.pory"
	.string "Groan…$"

Route103_Text_IsabelleIntro::
# 100 "data/maps/Route103/scripts.pory"
	.string "Watch where you're going! We're going to\n"
	.string "crash!$"

Route103_Text_IsabellePostBattle::
# 104 "data/maps/Route103/scripts.pory"
	.string "I'm a poor swimmer so I was practicing…\n"
	.string "Sorry for almost crashing into you.$"

Route103_Text_MarcosDefeated::
# 108 "data/maps/Route103/scripts.pory"
	.string "My one-man show is ruined…$"

Route103_Text_MarcosIntro::
# 112 "data/maps/Route103/scripts.pory"
	.string "Did my guitar's wailing draw you in?$"

Route103_Text_MarcosPostBattle::
# 116 "data/maps/Route103/scripts.pory"
	.string "I was playing my guitar where few\n"
	.string "people were around, but a lot of fans\l"
	.string "have gathered.\p"
	.string "Heh, maybe I should turn pro.$"

Route103_Text_MiguelDefeated::
# 120 "data/maps/Route103/scripts.pory"
	.string "Oh, my gosh! My darling POKéMON!$"

Route103_Text_MiguelIntro::
# 124 "data/maps/Route103/scripts.pory"
	.string "My POKéMON is delightfully adorable!\n"
	.string "Don't be shy--I'll show you!$"

Route103_Text_MiguelPostBattle::
# 128 "data/maps/Route103/scripts.pory"
	.string "My delightful POKéMON looks darling\n"
	.string "even when it's fainted!$"

Route103_Text_PeteDefeated::
# 132 "data/maps/Route103/scripts.pory"
	.string "Oh, that's good going!$"

Route103_Text_PeteIntro::
# 136 "data/maps/Route103/scripts.pory"
	.string "This sort of distance… You should just\n"
	.string "swim it!$"

Route103_Text_PetePostBattle::
# 140 "data/maps/Route103/scripts.pory"
	.string "Oh, I understand where you're coming\n"
	.string "from now.\p"
	.string "If I had a POKéMON that trusty, I'd\n"
	.string "want to SURF on it, too!$"

Route103_Text_RhettDefeated::
# 144 "data/maps/Route103/scripts.pory"
	.string "Whoa! The kid can rock!$"

Route103_Text_RhettIntro::
# 148 "data/maps/Route103/scripts.pory"
	.string "Whoa! How'd you get into a space this\n"
	.string "small?$"

Route103_Text_RhettPostBattle::
# 152 "data/maps/Route103/scripts.pory"
	.string "Do you like cramped quarters like this?$"

Route103_Text_MayRoute103Pokemon::
# 156 "data/maps/Route103/scripts.pory"
	.string "MAY: Let's see… The POKéMON found\n"
	.string "on ROUTE 103 include…$"

Route103_Text_ShouldHaveBroughtPotion::
# 160 "data/maps/Route103/scripts.pory"
	.string "My POKéMON is staggeringly tired…\n"
	.string "I should have brought a POTION…$"

Route103_Text_ShortcutToOldale::
# 164 "data/maps/Route103/scripts.pory"
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route103_Text_BrendanTimeToHeadBack::
# 168 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your POKéMON already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any POKéMON with ease.\p"
	.string "We should head back to the LAB.$"

Route103_Text_MayTimeToHeadBack::
# 172 "data/maps/Route103/scripts.pory"
	.string "MAY: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that POKéMON,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of POKéMON easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the LAB.$"

Route103_Text_BrendanRoute103Pokemon::
# 176 "data/maps/Route103/scripts.pory"
	.string "BRENDAN: Okay, so it's this one and\n"
	.string "that one that live on ROUTE 103…$"
