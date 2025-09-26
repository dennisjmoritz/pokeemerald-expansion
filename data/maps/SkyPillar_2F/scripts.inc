SkyPillar_2F_MapScripts::
	end

SkyPillar_2F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_SKY_PILLAR_2F_CLEAN
	return

SkyPillar_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SKY_PILLAR_1F
	end

