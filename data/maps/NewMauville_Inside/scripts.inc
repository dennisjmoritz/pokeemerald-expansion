NewMauville_Inside_MapScripts::
	.byte 0


NewMauville_Inside_EventScript_BlueButton::
	end


NewMauville_Inside_EventScript_Generator::
# 11 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_GeneratorRadiatingHeat, MSGBOX_DEFAULT
	end


NewMauville_Inside_EventScript_GreenButton::
	end


NewMauville_Inside_EventScript_RedButton::
# 21 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped, MSGBOX_DEFAULT
	end


NewMauville_Inside_EventScript_Voltorb1::
	end


NewMauville_Inside_EventScript_Voltorb2::
	end


NewMauville_Inside_EventScript_Voltorb3::
	end


NewMauville_Inside_Text_GeneratorRadiatingHeat::
# 38 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator is radiating heat that\n"
	.string "can be felt even at a distance.\p"
	.string "It looks like it should be turned off as\n"
	.string "soon as possible.$"

NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped::
# 42 "data/maps/NewMauville_Inside/scripts.pory"
	.string "{PLAYER} stepped on the switch.\p"
	.string "Click…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "The generator appears to have\n"
	.string "stopped…$"

NewMauville_Inside_Text_GeneratorQuietedDown::
# 46 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator quieted down.$"
