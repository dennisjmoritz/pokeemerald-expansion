#ifndef GUARD_PALETTE_H
#define GUARD_PALETTE_H

#define gPaletteFade_selectedPalettes (gPaletteFade.multipurpose1) // normal and fast fade
#define gPaletteFade_blendCnt         (gPaletteFade.multipurpose1) // hardware fade
#define gPaletteFade_delay            (gPaletteFade.multipurpose2) // normal and hardware fade
#define gPaletteFade_submode          (gPaletteFade.multipurpose2) // fast fade

#define PLTT_BUFFER_SIZE (PLTT_SIZE / sizeof(u16))

#define PALETTE_FADE_STATUS_DELAY 2
#define PALETTE_FADE_STATUS_ACTIVE 1
#define PALETTE_FADE_STATUS_DONE 0
#define PALETTE_FADE_STATUS_LOADING 0xFF

#define PALETTES_BG      0x0000FFFF
#define PALETTES_OBJECTS 0xFFFF0000
#define PALETTES_ALL     (PALETTES_BG | PALETTES_OBJECTS)

#define PLTT_ID(n) ((n) * 16)
#define BG_PLTT_OFFSET 0x000
#define OBJ_PLTT_OFFSET 0x100
#define BG_PLTT_ID(n) (BG_PLTT_OFFSET + PLTT_ID(n))
#define OBJ_PLTT_ID(n) (OBJ_PLTT_OFFSET + PLTT_ID(n))
#define OBJ_PLTT_ID2(n) (PLTT_ID((n) + 16))

#define CHECK_MENU_OR_OVERWORLD 0x2021685;
#define CHECK_COMBAT_OR_OVERWORLD 0x2021686;
#define MENU_FLAG 1
#define COMBAT_FLAG 1 << 4

#define RED_CHANNEL_OPERATOR 0x1F;
#define GREEN_CHANNEL_OPERATOR 0x3E0;
#define BLUE_CHANNEL_OPERATOR 0x7C00;

#define DNS_EXCEPTION 0
#define PAL_ACTIVE 1

//Timelapses for DNS
enum
{
    TIME_MIDNIGHT0,
    TIME_DAWN1,
    TIME_DAY2,
    TIME_SUNSET3,
    TIME_NIGHTFALL4,
    TIME_NIGHT5
};

//End hours for timelapses
#define MIDNIGHT_END_HOUR   7       //00 - 07
#define DAWN_END_HOUR       8       //07 - 08
#define DAY_END_HOUR        19      //08 - 19
#define SUNSET_END_HOUR     20      //19 - 20
#define NIGHTFALL_END_HOUR  21      //20 - 21
#define NIGHT_END_HOUR      0       //21 - 00

struct DnsPalExceptions
{
    u8 pal[32];
};

//Dns System
void DNS_System(void *src, void *dest);
void DnsDmaTransfer16(void *src, void *dest);
u16 ApplyDNSFilterToColor(u16 color, u16 filter);
bool8 IsMapDNSException(void);
u16 GetDNSFilter(void);
u8 GetTimeLapse(u8 hour);
void BlacknWhiteDmaTransfer(void);

enum
{
    FAST_FADE_IN_FROM_WHITE,
    FAST_FADE_OUT_TO_WHITE,
    FAST_FADE_IN_FROM_BLACK,
    FAST_FADE_OUT_TO_BLACK,
};

struct PaletteFadeControl
{
    u32 multipurpose1;
    u8 delayCounter:6;
    u16 y:5; // blend coefficient
    u16 targetY:5; // target blend coefficient
    u16 blendColor:15;
    bool16 active:1;
    u16 multipurpose2:6;
    bool16 yDec:1; // whether blend coefficient is decreasing
    bool16 bufferTransferDisabled:1;
    u16 mode:2;
    bool16 shouldResetBlendRegisters:1;
    bool16 hardwareFadeFinishing:1;
    u16 softwareFadeFinishingCounter:5;
    bool16 softwareFadeFinishing:1;
    bool16 objPaletteToggle:1;
    u8 deltaY:4; // rate of change of blend coefficient
};

extern struct PaletteFadeControl gPaletteFade;
extern u32 gPlttBufferTransferPending;
extern u16 ALIGNED(4) gPlttBufferUnfaded[PLTT_BUFFER_SIZE];
extern u16 ALIGNED(4) gPlttBufferFaded[PLTT_BUFFER_SIZE];

void LoadCompressedPalette(const u32 *src, u32 offset, u32 size);
void LoadPalette(const void *src, u32 offset, u32 size);
void FillPalette(u32 value, u32 offset, u32 size);
void TransferPlttBuffer(void);
u32 UpdatePaletteFade(void);
void ResetPaletteFade(void);
bool32 BeginNormalPaletteFade(u32 selectedPalettes, s8 delay, u8 startY, u8 targetY, u32 blendColor);
void ResetPaletteFadeControl(void);
void InvertPlttBuffer(u32 selectedPalettes);
void TintPlttBuffer(u32 selectedPalettes, s8 r, s8 g, s8 b);
void UnfadePlttBuffer(u32 selectedPalettes);
void BeginFastPaletteFade(u32 submode);
void BeginHardwarePaletteFade(u32 blendCnt, u32 delay, u32 y, u32 targetY, u32 shouldResetBlendRegisters);
void BlendPalettes(u32 selectedPalettes, u8 coeff, u32 color);
void BlendPalettesUnfaded(u32 selectedPalettes, u8 coeff, u32 color);
void BlendPalettesGradually(u32 selectedPalettes, s8 delay, u8 coeff, u8 coeffTarget, u16 color, u8 priority, u8 id);
void TintPalette_GrayScale(u16 *palette, u32 count);
void TintPalette_GrayScale2(u16 *palette, u32 count);
void TintPalette_SepiaTone(u16 *palette, u32 count);
void TintPalette_CustomTone(u16 *palette, u32 count, u16 rTone, u16 gTone, u16 bTone);

static inline void SetBackdropFromColor(u32 color)
{
  FillPalette(color, 0, PLTT_SIZEOF(1));
}

static inline void SetBackdropFromPalette(const u16 *palette)
{
  LoadPalette(palette, 0, PLTT_SIZEOF(1));
}

#endif // GUARD_PALETTE_H
