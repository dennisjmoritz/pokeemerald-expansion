BattleFrontier_BattlePalaceCorridor_MapScripts::
	end

BattleFrontier_BattlePalaceCorridor_EventScript_WalkThroughCorridor::
	end

BattleFrontier_BattlePalaceCorridor_EventScript_WalkToOpenBattleRoom::
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom
	waitmovement 0
	opendoor 10, 3
	waitdooranim
	applymovement LOCALID_PALACE_CORRIDOR_ATTENDANT, BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom
	waitmovement 0
	closedoor 10, 3
	waitdooranim
BattleFrontier_BattlePalaceCorridor_EventScript_WarpToBattleRoom::
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM, 7, 4
	waitstate
	end

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment1::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment2::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_RandomComment3::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_StreakComment::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_EventScript_LongStreakComment::
	msgbox BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceCorridor_Movement_EnterCorridor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkTo50BattleRoom:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkTo50BattleRoom:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_AttendantWalkToOpenBattleRoom:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerWalkToOpenBattleRoom:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom:
	walk_up
BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceCorridor_Text_PeopleAndMonAreSame:
	.string "People and POKéMON, they are but\n"
	.string "the same…\p"
	.string "Their individual nature makes them\n"
	.string "good at certain things, and not good\l"
	.string "at others.$"

BattleFrontier_BattlePalaceCorridor_Text_LetMonDoWhatItLikes:
	.string "Rather than trying to make a POKéMON\n"
	.string "do what it dislikes, try to let it do\l"
	.string "what it likes and is good at doing.\p"
	.string "Put yourself in the POKéMON's position\n"
	.string "and consider what moves it would like.$"

BattleFrontier_BattlePalaceCorridor_Text_MonDifferentWhenCornered:
	.string "A POKéMON's nature is a remarkable\n"
	.string "thing…\p"
	.string "Some POKéMON behave in a completely\n"
	.string "different way when they are cornered.$"

BattleFrontier_BattlePalaceCorridor_Text_BeginningToUnderstandNature:
	.string "Are you beginning to understand how\n"
	.string "a POKéMON's nature makes it behave?$"

BattleFrontier_BattlePalaceCorridor_Text_HeartfeltBondBetweenYouAndMons:
	.string "Ah… I see a strong, heartfelt bond\n"
	.string "between you and your POKéMON…$"

