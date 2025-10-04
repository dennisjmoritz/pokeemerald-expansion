CeladonCity_GameCorner_MapScripts::
	.byte 0


CeladonCity_GameCorner_EventScript_BaldingMan::
	end


CeladonCity_GameCorner_EventScript_CoinsClerk::
	end


CeladonCity_GameCorner_EventScript_Fisher::
	end


CeladonCity_GameCorner_EventScript_Gentleman::
	end


CeladonCity_GameCorner_EventScript_GymGuy::
	end


CeladonCity_GameCorner_EventScript_InfoClerk::
# 25 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_CanExchangeCoinsNextDoor, MSGBOX_NPC
	end


CeladonCity_GameCorner_EventScript_OldMan::
	end


CeladonCity_GameCorner_EventScript_Poster::
# 35 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SwitchBehindPosterPushIt, MSGBOX_DEFAULT
	end


CeladonCity_GameCorner_EventScript_RocketGrunt::
# 42 "data/maps/CeladonCity_GameCorner/scripts.pory"
	trainerbattle_double TRAINER_TEAM_ROCKET_GRUNT_7, CeladonCity_GameCorner_Text_GruntIntro, CeladonCity_GameCorner_Text_GruntDefeat, Text_NotEnoughMonsForDoubleBattle
# 43 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_GruntPostBattle
	return


CeladonCity_GameCorner_EventScript_Scientist::
	end


CeladonCity_GameCorner_EventScript_SlotMachine0::
	end


CeladonCity_GameCorner_EventScript_SlotMachine1::
	end


CeladonCity_GameCorner_EventScript_SlotMachine10::
	end


CeladonCity_GameCorner_EventScript_SlotMachine11::
	end


CeladonCity_GameCorner_EventScript_SlotMachine12::
	end


CeladonCity_GameCorner_EventScript_SlotMachine13::
	end


CeladonCity_GameCorner_EventScript_SlotMachine14::
	end


CeladonCity_GameCorner_EventScript_SlotMachine16::
	end


CeladonCity_GameCorner_EventScript_SlotMachine17::
	end


CeladonCity_GameCorner_EventScript_SlotMachine19::
	end


CeladonCity_GameCorner_EventScript_SlotMachine2::
	end


CeladonCity_GameCorner_EventScript_SlotMachine20::
	end


CeladonCity_GameCorner_EventScript_SlotMachine21::
	end


CeladonCity_GameCorner_EventScript_SlotMachine3::
	end


CeladonCity_GameCorner_EventScript_SlotMachine5::
	end


CeladonCity_GameCorner_EventScript_SlotMachine6::
	end


CeladonCity_GameCorner_EventScript_SlotMachine7::
	end


CeladonCity_GameCorner_EventScript_SlotMachine8::
	end


CeladonCity_GameCorner_EventScript_SlotMachine9::
	end


CeladonCity_GameCorner_EventScript_UnusableSlotMachine1::
# 184 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_OutOfOrder, MSGBOX_SIGN
	end


CeladonCity_GameCorner_EventScript_UnusableSlotMachine2::
# 189 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_OutToLunch, MSGBOX_SIGN
	end


CeladonCity_GameCorner_EventScript_UnusableSlotMachine3::
# 194 "data/maps/CeladonCity_GameCorner/scripts.pory"
	msgbox CeladonCity_GameCorner_Text_SomeonesKeys, MSGBOX_SIGN
	end


CeladonCity_GameCorner_EventScript_Woman1::
	end


CeladonCity_GameCorner_EventScript_Woman2::
	end


CeladonCity_GameCorner_Text_OutOfOrder::
# 206 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "OUT OF ORDER This is broken.$"

CeladonCity_GameCorner_Text_SwitchBehindPosterPushIt::
# 210 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Hey!\p"
	.string "A switch behind the poster!? Let's push\n"
	.string "it!$"

CeladonCity_GameCorner_Text_SomeonesKeys::
# 214 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Someone's keys! They'll be back.$"

CeladonCity_GameCorner_Text_OutToLunch::
# 218 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "OUT TO LUNCH This is reserved.$"

CeladonCity_GameCorner_Text_GruntDefeat::
# 223 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_GameCorner_Text_GruntDefeat$"

CeladonCity_GameCorner_Text_GruntIntro::
# 227 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_GameCorner_Text_GruntIntro$"

CeladonCity_GameCorner_Text_GruntPostBattle::
# 231 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Placeholder text for\n"
	.string "CeladonCity_GameCorner_Text_GruntPostBattle$"

CeladonCity_GameCorner_Text_CanExchangeCoinsNextDoor::
# 234 "data/maps/CeladonCity_GameCorner/scripts.pory"
	.string "Welcome!\p"
	.string "You can exchange your COINS for\n"
	.string "fabulous prizes next door.$"
