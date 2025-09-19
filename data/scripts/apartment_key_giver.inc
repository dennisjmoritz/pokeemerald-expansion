@ Simple script to give apartment key for testing
ApartmentKeyGiver_Text_GiveKey:
	.string "Here, take this APARTMENT KEY!\p"
	.string "You can use it to set up apartments\n"
	.string "in towns instead of secret bases!$"

ApartmentKeyGiver_Text_NoRoom:
	.string "You don't have room for this!$"

ApartmentKeyGiver_EventScript_GiveKey::
	lock
	faceplayer
	msgbox ApartmentKeyGiver_Text_GiveKey, MSGBOX_DEFAULT
	giveitem ITEM_APARTMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, ApartmentKeyGiver_EventScript_NoRoom
	closemessage
	release
	end

ApartmentKeyGiver_EventScript_NoRoom::
	msgbox ApartmentKeyGiver_Text_NoRoom, MSGBOX_DEFAULT
	release
	end