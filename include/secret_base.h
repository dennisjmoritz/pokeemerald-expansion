#ifndef GUARD_SECRET_BASE_H
#define GUARD_SECRET_BASE_H

void HideSecretBaseDecorationSprites(void);
void CopyCurSecretBaseOwnerName_StrVar1(void);
void SetPlayerSecretBaseParty(void);
u8 *GetSecretBaseMapName(u8 *dest);
void SetOccupiedSecretBaseEntranceMetatiles(struct MapEvents const *events);
void InitSecretBaseAppearance(bool8 hidePC);
bool8 CurMapIsSecretBase(void);
void SecretBasePerStepCallback(u8 taskId);
bool8 TrySetCurSecretBase(void);
void WarpIntoSecretBase(const struct MapPosition *position, const struct MapEvents *events);
bool8 SecretBaseMapPopupEnabled(void);
void ClearSecretBases(void);
void SetCurSecretBaseIdFromPosition(const struct MapPosition *position, const struct MapEvents *events);
void TrySetCurSecretBaseIndex(void);
void CheckPlayerHasSecretBase(void);
void ToggleSecretBaseEntranceMetatile(void);

// House type system
enum HouseType
{
    HOUSE_APARTMENT,
    HOUSE_HOUSE, 
    HOUSE_MANSION,
    NUM_HOUSE_TYPES
};

// House type cost functions
bool8 CanAffordHouseType(u8 houseType);
void ChargeForHouseType(u8 houseType);

#endif //GUARD_SECRET_BASE_H
