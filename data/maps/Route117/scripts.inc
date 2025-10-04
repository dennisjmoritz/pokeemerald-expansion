Route117_MapScripts::
	.byte 0


Route117_EventScript_Aisha::
# 5 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_AISHA, Route117_Text_AishaIntro, Route117_Text_AishaDefeat, Text_NotEnoughMonsForDoubleBattle
# 6 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AishaPostBattle
	return


Route117_EventScript_Anna::
	end


Route117_EventScript_Brandi::
# 14 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_BRANDI, Route117_Text_BrandiIntro, Route117_Text_BrandiDefeat, Text_NotEnoughMonsForDoubleBattle
# 15 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_BrandiPostBattle
	return


Route117_EventScript_DayCareSign::
# 19 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DayCareSign, MSGBOX_SIGN
	end


Route117_EventScript_Derek::
# 24 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_DEREK, Route117_Text_DerekIntro, Route117_Text_DerekDefeat, Text_NotEnoughMonsForDoubleBattle
# 25 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DerekPostBattle
	return


Route117_EventScript_Dylan::
# 29 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_DYLAN, Route117_Text_DylanIntro, Route117_Text_DylanDefeat, Text_NotEnoughMonsForDoubleBattle
# 30 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DylanPostBattle
	return


Route117_EventScript_Girl::
# 34 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_DayCarePokemonHadNewMove, MSGBOX_NPC
	end


Route117_EventScript_Isaac::
# 39 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_ISAAC, Route117_Text_IsaacIntro, Route117_Text_IsaacDefeat, Text_NotEnoughMonsForDoubleBattle
# 40 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_IsaacPostBattle
	return


Route117_EventScript_LittleBoy::
# 44 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_AirIsTastyHere, MSGBOX_NPC
	end


Route117_EventScript_Lydia::
# 49 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_LYDIA, Route117_Text_LydiaIntro, Route117_Text_LydiaDefeat, Text_NotEnoughMonsForDoubleBattle
# 50 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_LydiaPostBattle
	return


Route117_EventScript_Maria::
# 54 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_MARIA, Route117_Text_MariaIntro, Route117_Text_MariaDefeat, Text_NotEnoughMonsForDoubleBattle
# 55 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MariaPostBattle
	return


Route117_EventScript_Meg::
	end


Route117_EventScript_Melina::
# 63 "data/maps/Route117/scripts.pory"
	trainerbattle_double TRAINER_MELINA, Route117_Text_MelinaIntro, Route117_Text_MelinaDefeat, Text_NotEnoughMonsForDoubleBattle
# 64 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_MelinaPostBattle
	return


Route117_EventScript_RouteSignMauville::
# 68 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_RouteSignMauville, MSGBOX_SIGN
	end


Route117_EventScript_RouteSignVerdanturf::
# 73 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_RouteSignVerdanturf, MSGBOX_SIGN
	end


Route117_EventScript_Woman::
# 78 "data/maps/Route117/scripts.pory"
	msgbox Route117_Text_ArentTheseFlowersPretty, MSGBOX_NPC
	end


Route117_Text_DayCareSign::
# 83 "data/maps/Route117/scripts.pory"
	.string "POKéMON DAY CARE Let us raise your\n"
	.string "POKéMON.$"

Route117_Text_RouteSignVerdanturf::
# 87 "data/maps/Route117/scripts.pory"
	.string "ROUTE 117 {LEFT_ARROW} VERDANTURF TOWN$"

Route117_Text_RouteSignMauville::
# 91 "data/maps/Route117/scripts.pory"
	.string "ROUTE 117 {RIGHT_ARROW} MAUVILLE CITY$"

Route117_Text_AishaDefeat::
# 96 "data/maps/Route117/scripts.pory"
	.string "I don't waste any time being angry over\n"
	.string "a loss--I would rather train.$"

Route117_Text_AishaIntro::
# 100 "data/maps/Route117/scripts.pory"
	.string "Concentrate on getting the win. That's\n"
	.string "how I battle!$"

Route117_Text_AishaPostBattle::
# 104 "data/maps/Route117/scripts.pory"
	.string "I think that if you worry about losing,\n"
	.string "you're more likely to lose.$"

Route117_Text_BrandiDefeat::
# 108 "data/maps/Route117/scripts.pory"
	.string "Astonishing!$"

Route117_Text_BrandiIntro::
# 112 "data/maps/Route117/scripts.pory"
	.string "Let me demonstrate the power hidden\n"
	.string "within a PSYCHIC POKéMON!$"

Route117_Text_BrandiPostBattle::
# 116 "data/maps/Route117/scripts.pory"
	.string "PSYCHIC POKéMON are complex. You\n"
	.string "should try catching some.$"

Route117_Text_DerekDefeat::
# 120 "data/maps/Route117/scripts.pory"
	.string "My ineptitude also remains unchanged…$"

Route117_Text_DerekIntro::
# 124 "data/maps/Route117/scripts.pory"
	.string "Once a BUG CATCHER! And now a BUG\n"
	.string "MANIAC!\p"
	.string "But my love for POKéMON remains\n"
	.string "unchanged!$"

Route117_Text_DerekPostBattle::
# 128 "data/maps/Route117/scripts.pory"
	.string "All I did was follow my heart, and now\n"
	.string "they call me a BUG MANIAC…\p"
	.string "Still, I am an expert on BUG POKéMON, so\n"
	.string "it's only natural that they call me a BUG\l"
	.string "MANIAC.$"

Route117_Text_DylanDefeat::
# 132 "data/maps/Route117/scripts.pory"
	.string "I ran out of energy!$"

Route117_Text_DylanIntro::
# 136 "data/maps/Route117/scripts.pory"
	.string "I'm in the middle of a triathlon, but,\n"
	.string "whatever, let's have a battle!$"

Route117_Text_DylanPostBattle::
# 140 "data/maps/Route117/scripts.pory"
	.string "I may have blown it…\p"
	.string "I might have dropped to last during\n"
	.string "that battle…$"

Route117_Text_IsaacDefeat::
# 144 "data/maps/Route117/scripts.pory"
	.string "You've raised yours superbly…$"

Route117_Text_IsaacIntro::
# 148 "data/maps/Route117/scripts.pory"
	.string "Listen, could I get you to battle the\n"
	.string "POKéMON I'm raising?$"

Route117_Text_IsaacPostBattle::
# 152 "data/maps/Route117/scripts.pory"
	.string "POKéMON isn't all about power.\p"
	.string "Polishing a unique aspect of one's\n"
	.string "character is another way of enjoying\l"
	.string "POKéMON.$"

Route117_Text_LydiaDefeat::
# 156 "data/maps/Route117/scripts.pory"
	.string "Yes, they are growing properly.$"

Route117_Text_LydiaIntro::
# 160 "data/maps/Route117/scripts.pory"
	.string "Please, allow me to evaluate if you have\n"
	.string "raised your POKéMON properly.$"

Route117_Text_LydiaPostBattle::
# 164 "data/maps/Route117/scripts.pory"
	.string "Try raising POKéMON with more attention\n"
	.string "to their character traits.$"

Route117_Text_MariaDefeat::
# 168 "data/maps/Route117/scripts.pory"
	.string "I need to get more practices in, I\n"
	.string "guess.$"

Route117_Text_MariaIntro::
# 172 "data/maps/Route117/scripts.pory"
	.string "I do my triathlon training with POKéMON,\n"
	.string "so I'm pretty confident about my speed.$"

Route117_Text_MariaPostBattle::
# 176 "data/maps/Route117/scripts.pory"
	.string "Training is meaningful only if you keep\n"
	.string "it up regularly.\p"
	.string "Okay! I'll resume my training! Tomorrow!$"

Route117_Text_MelinaDefeat::
# 180 "data/maps/Route117/scripts.pory"
	.string "Oh, that's quite impressive!$"

Route117_Text_MelinaIntro::
# 184 "data/maps/Route117/scripts.pory"
	.string "Isn't it nice? To battle while looking at\n"
	.string "pretty flowers?$"

Route117_Text_MelinaPostBattle::
# 188 "data/maps/Route117/scripts.pory"
	.string "It feels wonderful to go for a jog while\n"
	.string "looking at flowers.$"

Route117_Text_ArentTheseFlowersPretty::
# 192 "data/maps/Route117/scripts.pory"
	.string "What do you think?\n"
	.string "Aren't these flowers pretty?\p"
	.string "I planted them all!$"

Route117_Text_AirIsTastyHere::
# 196 "data/maps/Route117/scripts.pory"
	.string "The air is tasty here!$"

Route117_Text_DayCarePokemonHadNewMove::
# 200 "data/maps/Route117/scripts.pory"
	.string "I left my POKéMON at the DAY CARE.\p"
	.string "When I got it back, it had a new move\n"
	.string "that I didn't teach it.\l"
	.string "I was really, really surprised.$"
