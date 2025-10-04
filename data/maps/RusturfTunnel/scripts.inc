RusturfTunnel_MapScripts::
	.byte 0


RusturfTunnel_EventScript_AquaGruntBackUp::
# 5 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
	end


RusturfTunnel_EventScript_Grunt::
# 10 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
	end


RusturfTunnel_EventScript_Mike::
# 15 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_double TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat, Text_NotEnoughMonsForDoubleBattle
# 16 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_MikePostBattle
	return


RusturfTunnel_EventScript_Peeko::
# 20 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
	end


RusturfTunnel_EventScript_TunnelBlockagePos1::
	end


RusturfTunnel_EventScript_TunnelBlockagePos2::
	end


RusturfTunnel_EventScript_TunnelBlockagePos3::
	end


RusturfTunnel_EventScript_Wanda::
# 37 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
	end


RusturfTunnel_EventScript_WandasBoyfriend::
	end


RusturfTunnel_Text_MikeDefeat::
# 47 "data/maps/RusturfTunnel/scripts.pory"
	.string "Placeholder text for\n"
	.string "RusturfTunnel_Text_MikeDefeat$"

RusturfTunnel_Text_MikeIntro::
# 51 "data/maps/RusturfTunnel/scripts.pory"
	.string "Placeholder text for\n"
	.string "RusturfTunnel_Text_MikeIntro$"

RusturfTunnel_Text_MikePostBattle::
# 55 "data/maps/RusturfTunnel/scripts.pory"
	.string "Placeholder text for\n"
	.string "RusturfTunnel_Text_MikePostBattle$"

RusturfTunnel_Text_ComeAndGetSome::
# 59 "data/maps/RusturfTunnel/scripts.pory"
	.string "What, are you coming?\n"
	.string "Come and get some, then!$"

RusturfTunnel_Text_GruntIntro::
# 63 "data/maps/RusturfTunnel/scripts.pory"
	.string "Grah, keelhaul it all!\p"
	.string "That hostage POKéMON turned out to\n"
	.string "be worthless!\p"
	.string "And to think I made a getaway…\n"
	.string "In this tunnel to nowhere!\p"
	.string "Hey! You!\n"
	.string "So you want to battle me?$"

RusturfTunnel_Text_Peeko::
# 67 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pii pihyoh!$"

RusturfTunnel_Text_ToGetToVerdanturf::
# 71 "data/maps/RusturfTunnel/scripts.pory"
	.string "To get from RUSTBORO to VERDANTURF,\n"
	.string "you need to go to DEWFORD, then pass\l"
	.string "through SLATEPORT and MAUVILLE…$"

RusturfTunnel_Text_BoyfriendOnOtherSideOfRock::
# 75 "data/maps/RusturfTunnel/scripts.pory"
	.string "On the other side of this rock…\n"
	.string "My boyfriend is there.\p"
	.string "He… He's not just digging the tunnel\n"
	.string "to come see me.\p"
	.string "He works his hands raw and rough\n"
	.string "for the benefit of everyone.$"
