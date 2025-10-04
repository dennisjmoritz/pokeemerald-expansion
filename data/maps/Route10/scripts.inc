Route10_MapScripts::
	.byte 0


Route10_EventScript_NorthRockTunnelSign::
# 5 "data/maps/Route10/scripts.pory"
	msgbox Route10_Text_RockTunnelDetourToLavender, MSGBOX_SIGN
	end


Route10_EventScript_PowerPlantSign::
# 10 "data/maps/Route10/scripts.pory"
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end


Route10_EventScript_SouthRockTunnelSign::
# 15 "data/maps/Route10/scripts.pory"
	msgbox Route10_Text_RockTunnel, MSGBOX_SIGN
	end


Route10_Text_PowerPlant::
# 20 "data/maps/Route10/scripts.pory"
	.string "POWER PLANT$"

Route10_Text_RockTunnel::
# 24 "data/maps/Route10/scripts.pory"
	.string "ROCK TUNNEL$"

Route10_Text_RockTunnelDetourToLavender::
# 28 "data/maps/Route10/scripts.pory"
	.string "ROCK TUNNEL Detour to LAVENDER TOWN$"
