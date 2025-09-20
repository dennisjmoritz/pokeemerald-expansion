#ifndef GUARD_EV_EDITOR_H
#define GUARD_EV_EDITOR_H

bool8 EVEditor_HasEVItems(void);
bool8 EVEditor_LoadCreditsFromBag(void);
u16 EVEditor_GetAvailableCredits(void);
void EVEditor_ConsumeCredits(u16 amount);
void EVEditor_OpenFromPartyMenu(u8 monIndex);

#endif // GUARD_EV_EDITOR_H