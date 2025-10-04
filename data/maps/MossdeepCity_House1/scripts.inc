MossdeepCity_House1_MapScripts::
	.byte 0


MossdeepCity_House1_EventScript_BlackBelt::
# 5 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	end


MossdeepCity_House1_EventScript_Woman::
# 10 "data/maps/MossdeepCity_House1/scripts.pory"
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end


MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks::
# 14 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "It doesn't appear to like or dislike\n"
	.string "any {POKEBLOCK}S.$"

MossdeepCity_House1_Text_HmmYourPokemon::
# 18 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "Hmm!\n"
	.string "Your {STR_VAR_1}…$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes::
# 22 "data/maps/MossdeepCity_House1/scripts.pory"
	.string "My husband can tell what kind of\n"
	.string "{POKEBLOCK}S a POKéMON likes at a glance.$"
