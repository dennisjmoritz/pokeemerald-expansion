SkyPillar_4F_MapScripts::
	end

SkyPillar_4F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_SKY_PILLAR_4F_CLEAN
	return

SkyPillar_4F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SKY_PILLAR_3F
	end

