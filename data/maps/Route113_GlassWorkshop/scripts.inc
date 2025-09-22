Route113_GlassWorkshop_MapScripts::
# 2 "data/maps/Route113_GlassWorkshop/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route113_GlassWorkshop_OnLoad
	.byte 0


# 6 "data/maps/Route113_GlassWorkshop/scripts.pory"

# 7 "data/maps/Route113_GlassWorkshop/scripts.pory"
Route113_GlassWorkshop_OnLoad::
# 8 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set BLUE_FLUTE_PRICE,   250
# 9 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set YELLOW_FLUTE_PRICE, 500
# 10 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set RED_FLUTE_PRICE,    500
# 11 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set WHITE_FLUTE_PRICE,  1000
# 12 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set BLACK_FLUTE_PRICE,  1000
# 13 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set PRETTY_CHAIR_PRICE, 6000
# 14 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set PRETTY_DESK_PRICE,  8000
# 15 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.set LOWEST_ASH_PRICE,   BLUE_FLUTE_PRICE

Route113_GlassWorkshop_Text_GoCollectAshWithThis::
# 19 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "This area is covered in volcanic ash,\n"
	.string "huff-puff!\p"
	.string "I'm specially gifted, huff-puff.\p"
	.string "I make glass out of volcanic ash and\n"
	.string "make items, huff-puff.\p"
	.string "Go collect ashes with this, huff-puff.$"

Route113_GlassWorkshop_Text_ExplainSootSack::
# 23 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Just take that SOOT SACK and walk\n"
	.string "through piles of ash, huff-puff.\p"
	.string "And it will fill up with the volcanic ash,\n"
	.string "huff-puff.\p"
	.string "Once you think you've collected a good\n"
	.string "amount, come see me, huff-puff.$"

Route113_GlassWorkshop_Text_LetsSeeCollectedAshes::
# 27 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Have you collected ashes, huff-puff?\n"
	.string "Let me see, huff-puff.$"

Route113_GlassWorkshop_Text_NotEnoughAshNeedX::
# 31 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Hmmm… There's not enough ash here,\n"
	.string "huff-puff.\l"
	.string "I can't make glass with this, huff-puff.\p"
	.string "Let's see… {STR_VAR_1} is the\n"
	.string "number of steps you'll need to walk for\l"
	.string "me to make you\l"
	.string "a BLUE FLUTE, huff-puff.$"

Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike::
# 35 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Oh! You've got a lot of ashes,\n"
	.string "huff-puff!\p"
	.string "I'll make you a glass item, huff-puff!\n"
	.string "Which one would you like, huff-puff?$"

Route113_GlassWorkshop_Text_IsThatTheItemForYou::
# 39 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "A {STR_VAR_1}, huff-puff? Is that\n"
	.string "the one for you, huff-puff?$"

Route113_GlassWorkshop_Text_WhichWouldYouLike::
# 43 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Which one would you like, huff-puff?$"

Route113_GlassWorkshop_Text_IllMakeItemForYou::
# 47 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "A {STR_VAR_1} it is, then,\n"
	.string "huff-puff!\p"
	.string "Okay! I'll make it for you, huff-puff.\n"
	.string "Just wait a little while, huff-puff.$"

Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem::
# 51 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "A {STR_VAR_1}, huff-puff?\p"
	.string "There's not enough ash here to make\n"
	.string "that, though, huff-puff.\p"
	.string "Let's see… {STR_VAR_2} is the\n"
	.string "number of steps you'll need to walk\l"
	.string "through volcanic ash\l"
	.string "for me to make that item, huff-puff.\p"
	.string "Which item would you rather have me\n"
	.string "make instead, huff-puff?$"

Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything::
# 55 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "You've collected all that ash, but you\n"
	.string "don't want anything, huff-puff?$"

Route113_GlassWorkshop_Text_IveFinishedGlassItem::
# 59 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Ah, I've finished your {STR_VAR_1}.\n"
	.string "Take it, huff-puff.$"

Route113_GlassWorkshop_Text_NoRoomInBag::
# 63 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Oh? You've no room in your BAG,\n"
	.string "huff-puff.\p"
	.string "I'll hold on to it, so come back later,\n"
	.string "huff-puff.$"

Route113_GlassWorkshop_Text_NoRoomInPC::
# 67 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Oh? You've no room in your PC,\n"
	.string "huff-puff?\p"
	.string "I'll hold on to it, so come back later,\n"
	.string "huff-puff.$"

Route113_GlassWorkshop_Text_HaventGotYourSootSack::
# 71 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "Hah? You haven't got your SOOT SACK\n"
	.string "with you, huff-puff.\p"
	.string "You have to keep it with you to collect\n"
	.string "volcanic ash, huff-puff.$"

Route113_GlassWorkshop_Text_FunToBlowGlassFlute::
# 75 "data/maps/Route113_GlassWorkshop/scripts.pory"
	.string "It's fun to blow a glass flute while my\n"
	.string "boss is talking.\p"
	.string "Huff-huff! Puff-puff!$"
