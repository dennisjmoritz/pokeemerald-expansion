//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/quests.json and Inja template src/data/quests.json.txt
//


#define side_quest(n, d, dd, m, s, st, sq, ns) {.name = n, .desc = d, .donedesc = dd, .map = m, .sprite = s, .spritetype = st, .subquests = sq, .numSubquests = ns}
#define sub_quest(i, n, d, m, s, st) {.id = i, .name = n, .desc = d, .map = m, .sprite = s, .spritetype = st}

// Forward declarations
extern const struct SubQuest gSubQuests_QUEST_READ_SIGN[];

// SideQuest array
static const struct SideQuest sSideQuests[QUEST_COUNT] =
{
	side_quest(
	      gText_SideQuestName_0,
	      gText_SideQuestDesc_0,
	      gText_SideQuestDoneDesc_0,
	      gText_SideQuestMap0,
	      OBJ_EVENT_GFX_ITEM_BALL,
	      OBJECT,
	      gSubQuests_QUEST_READ_SIGN,
	      1
	),
};

// SubQuest arrays
const struct SubQuest gSubQuests_QUEST_READ_SIGN[] = {
	sub_quest(
	      0,
	      gText_SideQuestName_QUEST_READ_SIGN_0,
	      gText_SideQuestDesc_QUEST_READ_SIGN_0,
	      gText_SideQuestMap_QUEST_READ_SIGN_0,
	      OBJ_EVENT_GFX_ITEM_BALL,
	      OBJECT
	),
};
