#include "global.h"
#include "palette.h"
#include "util.h"
#include "decompress.h"
#include "malloc.h"
#include "menu.h"
#include "gpu_regs.h"
#include "task.h"
#include "constants/rgb.h"
#include "constants/map_types.h"
#include "rtc.h"

//Configure palettes to be affected or not by DNS filtering
const struct DnsPalExceptions gOWPalExceptions =
{
    .pal =
    {
        PAL_ACTIVE,     //1
        PAL_ACTIVE,     //2
        PAL_ACTIVE,     //3
        PAL_ACTIVE,     //4
        PAL_ACTIVE,     //5
        PAL_ACTIVE,     //6
        PAL_ACTIVE,     //7
        PAL_ACTIVE,     //8
        PAL_ACTIVE,     //9
        PAL_ACTIVE,     //10
        PAL_ACTIVE,     //11
        PAL_ACTIVE,     //12
        PAL_ACTIVE,     //13
        DNS_EXCEPTION,  //14
        DNS_EXCEPTION,  //15
        DNS_EXCEPTION,  //16
        PAL_ACTIVE,     //17
        PAL_ACTIVE,     //18
        PAL_ACTIVE,     //19
        PAL_ACTIVE,     //20
        PAL_ACTIVE,     //21
        PAL_ACTIVE,     //22
        PAL_ACTIVE,     //23
        PAL_ACTIVE,     //24
        PAL_ACTIVE,     //25
        PAL_ACTIVE,     //26
        PAL_ACTIVE,     //27
        PAL_ACTIVE,     //28
        PAL_ACTIVE,     //29
        PAL_ACTIVE,     //30
        PAL_ACTIVE,     //31
        PAL_ACTIVE,     //32
    },
};

//Configure palettes to be affected or not by DNS while in combat
const struct DnsPalExceptions gCombatPalExceptions =
{
    .pal =
    {
        DNS_EXCEPTION,  //1
        DNS_EXCEPTION,  //2
        PAL_ACTIVE,     //3
        PAL_ACTIVE,     //4
        PAL_ACTIVE,     //5
        DNS_EXCEPTION,  //6
        PAL_ACTIVE,     //7
        PAL_ACTIVE,     //8
        PAL_ACTIVE,     //9
        PAL_ACTIVE,     //10
        PAL_ACTIVE,     //11
        PAL_ACTIVE,     //12
        PAL_ACTIVE,     //13
        PAL_ACTIVE,     //14
        PAL_ACTIVE,     //15
        PAL_ACTIVE,     //16
        PAL_ACTIVE,     //17
        PAL_ACTIVE,     //18
        PAL_ACTIVE,     //19
        PAL_ACTIVE,     //20
        DNS_EXCEPTION,  //21
        DNS_EXCEPTION,  //22
        DNS_EXCEPTION,  //23
        PAL_ACTIVE,     //24
        PAL_ACTIVE,     //25
        PAL_ACTIVE,     //26
        PAL_ACTIVE,     //27
        PAL_ACTIVE,     //28
        PAL_ACTIVE,     //29
        PAL_ACTIVE,     //30
        PAL_ACTIVE,     //31
        PAL_ACTIVE,     //32
    },
};

//MapTypes not affected by DNS
const u8 gDnsMapExceptions[] =
{
    MAP_TYPE_UNKNOWN,
    MAP_TYPE_INDOOR,
    MAP_TYPE_UNDERGROUND,
    MAP_TYPE_SECRET_BASE,
};

/* ***********************************************************
* DNS filters are actual 15bit RGB colours.
* This colours R - G - B channels are substracted from
* the original colour in the palette buffer during the
* transfer from the buffer to the palette RAM.
*
*  [BUFFER] -> (Value - Filter) -> [PAL_RAM]
*
* This means that you shouln't use too high values for RGB
* channels in the filters.
* I Suggest you to not use channels with a value above 16.
*
* Feel free to experiment with your own filters.
* **********************************************************/

//Filters used by DNS at Midnight
const u16 gMidnightFilters[] =
{
    RGB2(14, 14, 6),    //CE19
    RGB2(14, 14, 7),    //CE1D
    RGB2(14, 14, 8),    //CE21
    RGB2(15, 15, 8),    //EF21
    RGB2(15, 15, 9),    //EF25
    RGB2(15, 15, 9),    //EF25
    RGB2(16, 16, 9),    //1026
    RGB2(16, 16, 10),   //102A
};

//Filters used by DNS at Dawn
const u16 gDawnFilters[] =
{
    RGB2(15, 15, 10),
    RGB2(15, 15, 10),   //1
    RGB2(14, 14, 10),   //2
    RGB2(13, 13, 10),   //3
    RGB2(12, 12, 10),   //4
    RGB2(11, 11, 10),   //5
    RGB2(10, 10, 10),   //6
    RGB2(9, 9, 10),     //7
    RGB2(8, 8, 10),     //8
    RGB2(8, 8, 11),     //9
    RGB2(7, 7, 11),     //10
    RGB2(6, 6, 11),     //11
    RGB2(5, 5, 11),     //12
    RGB2(4, 4, 11),     //13
    RGB2(3, 3, 11),     //14
    RGB2(2, 2, 11),     //15
    RGB2(1, 1, 11),     //16
    RGB2(0, 0, 11),     //17
    RGB2(0, 0, 10),     //18
    RGB2(0, 0, 9),      //19
    RGB2(0, 0, 8),      //20
    RGB2(0, 0, 7),      //21
    RGB2(0, 0, 6),      //22
    RGB2(0, 0, 5),      //23
    RGB2(0, 0, 4),      //24
    RGB2(0, 0, 3),      //0003
    RGB2(0, 0, 2),      //0002
    RGB2(0, 0, 1),      //0001
    RGB2(0, 0, 0),      //0000
    RGB2(0, 0, 0),      //0000
};

//DNS Day filter (no filter actually lul)
const u16 gDayFilter = RGB2(0, 0, 0);   //0000

//DNS Sunset filters
const u16 gSunsetFilters[] =
{
    RGB2(0, 0, 1),      //0004
    RGB2(0, 1, 1),      //2004
    RGB2(0, 1, 2),      //2008
    RGB2(0, 1, 3),      //200C
    RGB2(0, 2, 3),      //400C
    RGB2(0, 2, 4),      //4010
    RGB2(0, 2, 5),      //4014
    RGB2(0, 3, 5),      //6014
    RGB2(0, 3, 6),      //6018
    RGB2(0, 3, 7),      //601C
    RGB2(0, 4, 7),      //801C
    RGB2(0, 4, 8),      //8020
    RGB2(0, 4, 9),      //8024
    RGB2(0, 5, 9),      //A024
    RGB2(0, 5, 10),     //A028
    RGB2(0, 5, 11),     //A02C
    RGB2(0, 6, 11),     //C02C
    RGB2(0, 6, 12),     //C030
    RGB2(0, 6, 13),     //C034
    RGB2(0, 7, 13),     //E034
    RGB2(0, 7, 14),     //E038
    RGB2(0, 7, 14),     //E038
    RGB2(0, 8, 14),     //0039
    RGB2(0, 9, 14),     //2039
    RGB2(0, 10, 14),    //4039
    RGB2(0, 11, 14),    //6039
    RGB2(0, 12, 14),    //8039
    RGB2(0, 13, 14),    //A039
    RGB2(0, 14, 14),    //C039
    RGB2(0, 14, 14),    //C039
};

//DNS NightFall Filters
const u16 gNightfallFilters[] =
{
    RGB2(0, 14, 14),    //39C0
    RGB2(0, 14, 14),    //39C0
    RGB2(0, 14, 13),    //35C0
    RGB2(0, 14, 12),    //31C0
    RGB2(0, 14, 11),    //2DC0
    RGB2(0, 14, 10),    //29C0
    RGB2(1, 14, 10),    //29C1
    RGB2(1, 14, 9),     //25C1
    RGB2(0, 14, 8),     //21C0
    RGB2(1, 14, 7),     //1DC1
    RGB2(1, 14, 6),     //19C1
    RGB2(2, 14, 6),     //19C2
    RGB2(2, 14, 5),     //15C2
    RGB2(2, 14, 4),     //11C2
    RGB2(2, 14, 3),     //0DC2
    RGB2(2, 14, 2),     //09C2
    RGB2(2, 14, 2),     //09C2
    RGB2(3, 14, 3),     //0DC3
    RGB2(4, 14, 4),     //11C4
    RGB2(5, 14, 5),     //15C5
    RGB2(6, 14, 6),     //19C6
    RGB2(7, 14, 6),     //19C7
    RGB2(8, 14, 6),     //19C8
    RGB2(9, 14, 6),     //19C9
    RGB2(10, 14, 6),    //19CA
    RGB2(11, 14, 6),    //19CB
    RGB2(12, 14, 6),    //19CC
    RGB2(13, 14, 6),    //19CD
    RGB2(14, 14, 6),    //19CE
    RGB2(14, 14, 6),    //19CE
};

//DNS Night filter
const u16 gNightFilter = RGB2(14, 14, 6);   //19CE

enum
{
    NORMAL_FADE,
    FAST_FADE,
    HARDWARE_FADE,
};

static u32 UpdateNormalPaletteFade(void);
static void BeginFastPaletteFadeInternal(u32);
static u32 UpdateFastPaletteFade(void);
static u32 UpdateHardwarePaletteFade(void);
static void UpdateBlendRegisters(void);
static bool32 IsSoftwarePaletteFadeFinishing(void);
static void Task_BlendPalettesGradually(u8 taskId);

// palette buffers require alignment with agbcc because
// unaligned word reads are issued in BlendPalette otherwise
ALIGNED(4) EWRAM_DATA u16 gPlttBufferUnfaded[PLTT_BUFFER_SIZE] = {0};
ALIGNED(4) EWRAM_DATA u16 gPlttBufferFaded[PLTT_BUFFER_SIZE] = {0};
EWRAM_DATA struct PaletteFadeControl gPaletteFade = {0};
static EWRAM_DATA u32 sPlttBufferTransferPending = 0;

static const u8 sRoundedDownGrayscaleMap[] = {
     0,  0,  0,  0,  0,
     5,  5,  5,  5,  5,
    11, 11, 11, 11, 11,
    16, 16, 16, 16, 16,
    21, 21, 21, 21, 21,
    27, 27, 27, 27, 27,
    31, 31
};

void LoadCompressedPalette(const u32 *src, u32 offset, u32 size)
{
    void *buffer = malloc_and_decompress(src, NULL);
    LoadPalette(buffer, offset, size);
    Free(buffer);
}

void LoadPalette(const void *src, u32 offset, u32 size)
{
    CpuCopy16(src, &gPlttBufferUnfaded[offset], size);
    CpuCopy16(src, &gPlttBufferFaded[offset], size);
}

void FillPalette(u32 value, u32 offset, u32 size)
{
    CpuFill16(value, &gPlttBufferUnfaded[offset], size);
    CpuFill16(value, &gPlttBufferFaded[offset], size);
}

void TransferPlttBuffer(void)
{
    if (!gPaletteFade.bufferTransferDisabled)
    {
        void *src = gPlttBufferFaded;
        void *dest = (void *)PLTT;
        DmaCopy16(3, src, dest, PLTT_SIZE);
        sPlttBufferTransferPending = FALSE;
        if (gPaletteFade.mode == HARDWARE_FADE && gPaletteFade.active)
            UpdateBlendRegisters();
    }
}

u32 UpdatePaletteFade(void)
{
    u32 result;

    if (sPlttBufferTransferPending)
        return PALETTE_FADE_STATUS_LOADING;

    if (gPaletteFade.mode == NORMAL_FADE)
        result = UpdateNormalPaletteFade();
    else if (gPaletteFade.mode == FAST_FADE)
        result = UpdateFastPaletteFade();
    else
        result = UpdateHardwarePaletteFade();

    sPlttBufferTransferPending = gPaletteFade.multipurpose1;

    return result;
}

void ResetPaletteFade(void)
{
    ResetPaletteFadeControl();
}

bool32 BeginNormalPaletteFade(u32 selectedPalettes, s8 delay, u8 startY, u8 targetY, u32 blendColor)
{
    u8 temp;

    if (gPaletteFade.active)
    {
        return FALSE;
    }
    else
    {
        gPaletteFade.deltaY = 2;

        if (delay < 0)
        {
            gPaletteFade.deltaY += (delay * -1);
            delay = 0;
        }

        gPaletteFade_selectedPalettes = selectedPalettes;
        gPaletteFade.delayCounter = delay;
        gPaletteFade_delay = delay;
        gPaletteFade.y = startY;
        gPaletteFade.targetY = targetY;
        gPaletteFade.blendColor = blendColor;
        gPaletteFade.active = TRUE;
        gPaletteFade.mode = NORMAL_FADE;

        if (startY < targetY)
            gPaletteFade.yDec = 0;
        else
            gPaletteFade.yDec = 1;

        UpdatePaletteFade();

        temp = gPaletteFade.bufferTransferDisabled;
        gPaletteFade.bufferTransferDisabled = FALSE;
        CpuCopy32(gPlttBufferFaded, (void *)PLTT, PLTT_SIZE);
        sPlttBufferTransferPending = FALSE;
        if (gPaletteFade.mode == HARDWARE_FADE && gPaletteFade.active)
            UpdateBlendRegisters();
        gPaletteFade.bufferTransferDisabled = temp;
        return TRUE;
    }
}

void ResetPaletteFadeControl(void)
{
    gPaletteFade.multipurpose1 = 0;
    gPaletteFade.multipurpose2 = 0;
    gPaletteFade.delayCounter = 0;
    gPaletteFade.y = 0;
    gPaletteFade.targetY = 0;
    gPaletteFade.blendColor = 0;
    gPaletteFade.active = FALSE;
    gPaletteFade.multipurpose2 = 0; // assign same value twice
    gPaletteFade.yDec = 0;
    gPaletteFade.bufferTransferDisabled = FALSE;
    gPaletteFade.shouldResetBlendRegisters = FALSE;
    gPaletteFade.hardwareFadeFinishing = FALSE;
    gPaletteFade.softwareFadeFinishing = FALSE;
    gPaletteFade.softwareFadeFinishingCounter = 0;
    gPaletteFade.objPaletteToggle = 0;
    gPaletteFade.deltaY = 2;
}

static u32 UpdateNormalPaletteFade(void)
{
    u16 paletteOffset;
    u16 selectedPalettes;

    if (!gPaletteFade.active)
        return PALETTE_FADE_STATUS_DONE;

    if (IsSoftwarePaletteFadeFinishing())
    {
        return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
    }
    else
    {
        if (!gPaletteFade.objPaletteToggle)
        {
            if (gPaletteFade.delayCounter < gPaletteFade_delay)
            {
                gPaletteFade.delayCounter++;
                return 2;
            }
            gPaletteFade.delayCounter = 0;
        }

        paletteOffset = 0;

        if (!gPaletteFade.objPaletteToggle)
        {
            selectedPalettes = gPaletteFade_selectedPalettes;
        }
        else
        {
            selectedPalettes = gPaletteFade_selectedPalettes >> 16;
            paletteOffset = OBJ_PLTT_OFFSET;
        }

        while (selectedPalettes)
        {
            if (selectedPalettes & 1)
                BlendPalette(
                    paletteOffset,
                    16,
                    gPaletteFade.y,
                    gPaletteFade.blendColor);
            selectedPalettes >>= 1;
            paletteOffset += 16;
        }

        gPaletteFade.objPaletteToggle ^= 1;

        if (!gPaletteFade.objPaletteToggle)
        {
            if (gPaletteFade.y == gPaletteFade.targetY)
            {
                gPaletteFade_selectedPalettes = 0;
                gPaletteFade.softwareFadeFinishing = TRUE;
            }
            else
            {
                s8 val;

                if (!gPaletteFade.yDec)
                {
                    val = gPaletteFade.y;
                    val += gPaletteFade.deltaY;
                    if (val > gPaletteFade.targetY)
                        val = gPaletteFade.targetY;
                    gPaletteFade.y = val;
                }
                else
                {
                    val = gPaletteFade.y;
                    val -= gPaletteFade.deltaY;
                    if (val < gPaletteFade.targetY)
                        val = gPaletteFade.targetY;
                    gPaletteFade.y = val;
                }
            }
        }

        // gPaletteFade.active cannot change since the last time it was checked. So this
        // is equivalent to `return PALETTE_FADE_STATUS_ACTIVE;`
        return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
    }
}

void InvertPlttBuffer(u32 selectedPalettes)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u32 i;
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteOffset + i] = ~gPlttBufferFaded[paletteOffset + i];
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void TintPlttBuffer(u32 selectedPalettes, s8 r, s8 g, s8 b)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u32 i;
            for (i = 0; i < 16; i++)
            {
                struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[paletteOffset + i];
                data->r += r;
                data->g += g;
                data->b += b;
            }
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void UnfadePlttBuffer(u32 selectedPalettes)
{
    u16 paletteOffset = 0;

    while (selectedPalettes)
    {
        if (selectedPalettes & 1)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                gPlttBufferFaded[paletteOffset + i] = gPlttBufferUnfaded[paletteOffset + i];
        }
        selectedPalettes >>= 1;
        paletteOffset += 16;
    }
}

void BeginFastPaletteFade(u32 submode)
{
    gPaletteFade.deltaY = 2;
    BeginFastPaletteFadeInternal(submode);
}

static void BeginFastPaletteFadeInternal(u32 submode)
{
    gPaletteFade.y = 31;
    gPaletteFade_submode = submode & 0x3F;
    gPaletteFade.active = TRUE;
    gPaletteFade.mode = FAST_FADE;

    if (submode == FAST_FADE_IN_FROM_BLACK)
        CpuFill16(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);

    if (submode == FAST_FADE_IN_FROM_WHITE)
        CpuFill16(RGB_WHITE, gPlttBufferFaded, PLTT_SIZE);

    UpdatePaletteFade();
}

static u32 UpdateFastPaletteFade(void)
{
    u32 i;
    u16 paletteOffsetStart;
    u16 paletteOffsetEnd;
    s8 r0;
    s8 g0;
    s8 b0;
    s8 r;
    s8 g;
    s8 b;

    if (!gPaletteFade.active)
        return PALETTE_FADE_STATUS_DONE;

    if (IsSoftwarePaletteFadeFinishing())
        return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;


    if (gPaletteFade.objPaletteToggle)
    {
        paletteOffsetStart = OBJ_PLTT_OFFSET;
        paletteOffsetEnd = PLTT_BUFFER_SIZE;
    }
    else
    {
        paletteOffsetStart = 0;
        paletteOffsetEnd = OBJ_PLTT_OFFSET;
    }

    switch (gPaletteFade_submode)
    {
    case FAST_FADE_IN_FROM_WHITE:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *unfaded;
            struct PlttData *faded;

            unfaded = (struct PlttData *)&gPlttBufferUnfaded[i];
            r0 = unfaded->r;
            g0 = unfaded->g;
            b0 = unfaded->b;

            faded = (struct PlttData *)&gPlttBufferFaded[i];
            r = faded->r - 2;
            g = faded->g - 2;
            b = faded->b - 2;

            if (r < r0)
                r = r0;
            if (g < g0)
                g = g0;
            if (b < b0)
                b = b0;

            gPlttBufferFaded[i] = RGB(r, g, b);
        }
        break;
    case FAST_FADE_OUT_TO_WHITE:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[i];
            r = data->r + 2;
            g = data->g + 2;
            b = data->b + 2;

            if (r > 31)
                r = 31;
            if (g > 31)
                g = 31;
            if (b > 31)
                b = 31;

            gPlttBufferFaded[i] = RGB(r, g, b);
        }
        break;
    case FAST_FADE_IN_FROM_BLACK:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *unfaded;
            struct PlttData *faded;

            unfaded = (struct PlttData *)&gPlttBufferUnfaded[i];
            r0 = unfaded->r;
            g0 = unfaded->g;
            b0 = unfaded->b;

            faded = (struct PlttData *)&gPlttBufferFaded[i];
            r = faded->r + 2;
            g = faded->g + 2;
            b = faded->b + 2;

            if (r > r0)
                r = r0;
            if (g > g0)
                g = g0;
            if (b > b0)
                b = b0;

            gPlttBufferFaded[i] = RGB(r, g, b);
        }
        break;
    case FAST_FADE_OUT_TO_BLACK:
        for (i = paletteOffsetStart; i < paletteOffsetEnd; i++)
        {
            struct PlttData *data = (struct PlttData *)&gPlttBufferFaded[i];
            r = data->r - 2;
            g = data->g - 2;
            b = data->b - 2;

            if (r < 0)
                r = 0;
            if (g < 0)
                g = 0;
            if (b < 0)
                b = 0;

            gPlttBufferFaded[i] = RGB(r, g, b);
        }
    }

    gPaletteFade.objPaletteToggle ^= 1;

    if (gPaletteFade.objPaletteToggle)
        // gPaletteFade.active cannot change since the last time it was checked. So this
        // is equivalent to `return PALETTE_FADE_STATUS_ACTIVE;`
        return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;

    if (gPaletteFade.y - gPaletteFade.deltaY < 0)
        gPaletteFade.y = 0;
    else
        gPaletteFade.y -= gPaletteFade.deltaY;

    if (gPaletteFade.y == 0)
    {
        switch (gPaletteFade_submode)
        {
        case FAST_FADE_IN_FROM_WHITE:
        case FAST_FADE_IN_FROM_BLACK:
            CpuCopy32(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_SIZE);
            break;
        case FAST_FADE_OUT_TO_WHITE:
            CpuFill32(0xFFFFFFFF, gPlttBufferFaded, PLTT_SIZE);
            break;
        case FAST_FADE_OUT_TO_BLACK:
            CpuFill32(0x00000000, gPlttBufferFaded, PLTT_SIZE);
            break;
        }

        gPaletteFade.mode = NORMAL_FADE;
        gPaletteFade.softwareFadeFinishing = TRUE;
    }

    // gPaletteFade.active cannot change since the last time it was checked. So this
    // is equivalent to `return PALETTE_FADE_STATUS_ACTIVE;`
    return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
}

void BeginHardwarePaletteFade(u32 blendCnt, u32 delay, u32 y, u32 targetY, u32 shouldResetBlendRegisters)
{
    gPaletteFade_blendCnt = blendCnt;
    gPaletteFade.delayCounter = delay;
    gPaletteFade_delay = delay;
    gPaletteFade.y = y;
    gPaletteFade.targetY = targetY;
    gPaletteFade.active = TRUE;
    gPaletteFade.mode = HARDWARE_FADE;
    gPaletteFade.shouldResetBlendRegisters = shouldResetBlendRegisters & 1;
    gPaletteFade.hardwareFadeFinishing = FALSE;

    if (y < targetY)
        gPaletteFade.yDec = 0;
    else
        gPaletteFade.yDec = 1;
}

static u32 UpdateHardwarePaletteFade(void)
{
    if (!gPaletteFade.active)
        return PALETTE_FADE_STATUS_DONE;

    if (gPaletteFade.delayCounter < gPaletteFade_delay)
    {
        gPaletteFade.delayCounter++;
        return PALETTE_FADE_STATUS_DELAY;
    }

    gPaletteFade.delayCounter = 0;

    if (!gPaletteFade.yDec)
    {
        gPaletteFade.y++;
        if (gPaletteFade.y > gPaletteFade.targetY)
        {
            gPaletteFade.hardwareFadeFinishing++;
            gPaletteFade.y--;
        }
    }
    else
    {
        s32 y = gPaletteFade.y--;
        if (y - 1 < gPaletteFade.targetY)
        {
            gPaletteFade.hardwareFadeFinishing++;
            gPaletteFade.y++;
        }
    }

    if (gPaletteFade.hardwareFadeFinishing)
    {
        if (gPaletteFade.shouldResetBlendRegisters)
        {
            gPaletteFade_blendCnt = 0;
            gPaletteFade.y = 0;
        }
        gPaletteFade.shouldResetBlendRegisters = FALSE;
    }

    // gPaletteFade.active cannot change since the last time it was checked. So this
    // is equivalent to `return PALETTE_FADE_STATUS_ACTIVE;`
    return gPaletteFade.active ? PALETTE_FADE_STATUS_ACTIVE : PALETTE_FADE_STATUS_DONE;
}

static void UpdateBlendRegisters(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, (u16)gPaletteFade_blendCnt);
    SetGpuReg(REG_OFFSET_BLDY, gPaletteFade.y);
    if (gPaletteFade.hardwareFadeFinishing)
    {
        gPaletteFade.hardwareFadeFinishing = FALSE;
        gPaletteFade.mode = 0;
        gPaletteFade_blendCnt = 0;
        gPaletteFade.y = 0;
        gPaletteFade.active = FALSE;
    }
}

static bool32 IsSoftwarePaletteFadeFinishing(void)
{
    if (gPaletteFade.softwareFadeFinishing)
    {
        if (gPaletteFade.softwareFadeFinishingCounter == 4)
        {
            gPaletteFade.active = FALSE;
            gPaletteFade.softwareFadeFinishing = FALSE;
            gPaletteFade.softwareFadeFinishingCounter = 0;
        }
        else
        {
            gPaletteFade.softwareFadeFinishingCounter++;
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void BlendPalettes(u32 selectedPalettes, u8 coeff, u32 color)
{
    u16 paletteOffset;

    for (paletteOffset = 0; selectedPalettes; paletteOffset += 16)
    {
        if (selectedPalettes & 1)
            BlendPalette(paletteOffset, 16, coeff, color);
        selectedPalettes >>= 1;
    }
}

void BlendPalettesUnfaded(u32 selectedPalettes, u8 coeff, u32 color)
{
    void *src = gPlttBufferUnfaded;
    void *dest = gPlttBufferFaded;
    DmaCopy32(3, src, dest, PLTT_SIZE);
    BlendPalettes(selectedPalettes, coeff, color);
}

void TintPalette_GrayScale(u16 *palette, u32 count)
{
    s32 r, g, b;
    u32 i, gray;

    for (i = 0; i < count; i++)
    {
        r = GET_R(*palette);
        g = GET_G(*palette);
        b = GET_B(*palette);

        gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;

        *palette++ = RGB2(gray, gray, gray);
    }
}

void TintPalette_GrayScale2(u16 *palette, u32 count)
{
    s32 r, g, b;
    u32 i, gray;

    for (i = 0; i < count; i++)
    {
        r = GET_R(*palette);
        g = GET_G(*palette);
        b = GET_B(*palette);

        gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;

        if (gray > 31)
            gray = 31;

        gray = sRoundedDownGrayscaleMap[gray];

        *palette++ = RGB2(gray, gray, gray);
    }
}

void TintPalette_SepiaTone(u16 *palette, u32 count)
{
    s32 r, g, b;
    u32 i, gray;

    for (i = 0; i < count; i++)
    {
        r = GET_R(*palette);
        g = GET_G(*palette);
        b = GET_B(*palette);

        gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;

        r = (u16)((Q_8_8(1.2) * gray)) >> 8;
        g = (u16)((Q_8_8(1.0) * gray)) >> 8;
        b = (u16)((Q_8_8(0.94) * gray)) >> 8;

        if (r > 31)
            r = 31;

        *palette++ = RGB2(r, g, b);
    }
}

void TintPalette_CustomTone(u16 *palette, u32 count, u16 rTone, u16 gTone, u16 bTone)
{
    s32 r, g, b;
    u32 i, gray;

    for (i = 0; i < count; i++)
    {
        r = GET_R(*palette);
        g = GET_G(*palette);
        b = GET_B(*palette);

        gray = (r * Q_8_8(0.3) + g * Q_8_8(0.59) + b * Q_8_8(0.1133)) >> 8;

        r = (u16)((rTone * gray)) >> 8;
        g = (u16)((gTone * gray)) >> 8;
        b = (u16)((bTone * gray)) >> 8;

        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;

        *palette++ = RGB2(r, g, b);
    }
}

#define tCoeff       data[0]
#define tCoeffTarget data[1]
#define tCoeffDelta  data[2]
#define tDelay       data[3]
#define tDelayTimer  data[4]
#define tPalettes    5 // data[5] and data[6], set/get via Set/GetWordTaskArg
#define tColor       data[7]
#define tId          data[8]

// Blend the selected palettes in a series of steps toward or away from the color.
// Only used by the Groudon/Kyogre fight scene to flash the screen for lightning.
// One call is used to fade the bg from white, while another fades the duo from black
void BlendPalettesGradually(u32 selectedPalettes, s8 delay, u8 coeff, u8 coeffTarget, u16 color, u8 priority, u8 id)
{
    u8 taskId;

    taskId = CreateTask((void *)Task_BlendPalettesGradually, priority);
    gTasks[taskId].tCoeff = coeff;
    gTasks[taskId].tCoeffTarget = coeffTarget;

    if (delay >= 0)
    {
        gTasks[taskId].tDelay = delay;
        gTasks[taskId].tCoeffDelta = 1;
    }
    else
    {
        gTasks[taskId].tDelay = 0;
        gTasks[taskId].tCoeffDelta = -delay + 1;
    }

    if (coeffTarget < coeff)
        gTasks[taskId].tCoeffDelta *= -1;

    SetWordTaskArg(taskId, tPalettes, selectedPalettes);
    gTasks[taskId].tColor = color;
    gTasks[taskId].tId = id;
    gTasks[taskId].func(taskId);
}

static bool32 UNUSED IsBlendPalettesGraduallyTaskActive(u8 id)
{
    int i;

    for (i = 0; i < NUM_TASKS; i++)
        if ((gTasks[i].isActive == TRUE)
         && (gTasks[i].func == Task_BlendPalettesGradually)
         && (gTasks[i].tId == id))
            return TRUE;

    return FALSE;
}

static void UNUSED DestroyBlendPalettesGraduallyTask(void)
{
    u8 taskId;

    while (1)
    {
        taskId = FindTaskIdByFunc(Task_BlendPalettesGradually);
        if (taskId == TASK_NONE)
            break;
        DestroyTask(taskId);
    }
}

static void Task_BlendPalettesGradually(u8 taskId)
{
    u32 palettes;
    s16 *data;
    s16 target;

    data = gTasks[taskId].data;
    palettes = GetWordTaskArg(taskId, tPalettes);

    if (++tDelayTimer > tDelay)
    {
        tDelayTimer = 0;
        BlendPalettes(palettes, tCoeff, tColor);
        target = tCoeffTarget;
        if (tCoeff == target)
        {
            DestroyTask(taskId);
        }
        else
        {
            tCoeff += tCoeffDelta;
            if (tCoeffDelta >= 0)
            {
                if (tCoeff < target)
                    return;
            }
            else if (tCoeff > target)
            {
                return;
            }
            tCoeff = target;
        }
    }
}

/* ****************************************************
* **************** D&N for pokeemerald ***************
* ****************************************************
* Based on Prime Dialga DNS for Pokemon GBA Games.
* Additional credits to Andrea, Eing & BLAx501!
* Author: Xhyz/Samu
******************************************************/
void DNS_System(void *src, void *dest)
{
    u8* menu_status = (u8*) CHECK_MENU_OR_OVERWORLD;

    //If Player is in a menu regular DMA transfer will be used
    if (*menu_status & MENU_FLAG || IsMapDNSException())
    {
        DmaCopy16(3, src, dest, PLTT_SIZE);
    }
    else    //If Player is in OW or Combat DNS Transfer will be used instead
    {
        DnsDmaTransfer16(src, dest);
    }
}

//Applies filter to colors while doing manual dma transfer from buffer to palettes ram
void DnsDmaTransfer16(void *src, void *dest)
{
    u8 pal_num; u8 col_num; u8 i;
    u16 color; u16 filter;
    u8 palExceptionFlags[32];

    u16* pal_color = (u16*) PLTT;   //pointer to palette ram
    u8* combat_status = (u8*) CHECK_COMBAT_OR_OVERWORLD;  

    //Obtains DNS Filter
    filter = GetDNSFilter();

    //Inits palette exception flags
    for (i = 0; i < 32; i++)
        palExceptionFlags[i] = (*combat_status & COMBAT_FLAG) ? gCombatPalExceptions.pal[i] : gOWPalExceptions.pal[i];


    //Loops through all palettes checking whether they are dns active or not
    for (pal_num = 0; pal_num < 32; pal_num++)
    { 
        if (palExceptionFlags[pal_num] == PAL_ACTIVE)   //Filters de palette
        {
            for (col_num = 0; col_num < 16; col_num++)
            {
                *pal_color = ApplyDNSFilterToColor(gPlttBufferFaded[pal_num * 16 + col_num], filter);
                pal_color++;
            }
        }
        else
        {
            for (col_num = 0; col_num < 16; col_num++)  //Transfers palette without filtering
            {
                *pal_color = gPlttBufferFaded[pal_num * 16 + col_num];
                pal_color++;
            }
        }
    }
}

//Applies filter to a colour. Filters RGB channels are substracted from colour RGB channels.
u16 ApplyDNSFilterToColor(u16 color, u16 filter)
{
    u16 red; u16 green; u16 blue;
    u16 red_filter; u16 green_filter; u16 blue_filter;

    red = color & RED_CHANNEL_OPERATOR;
    green = color & GREEN_CHANNEL_OPERATOR;
    blue = color & BLUE_CHANNEL_OPERATOR;

    red_filter = filter & RED_CHANNEL_OPERATOR;
    green_filter = filter & GREEN_CHANNEL_OPERATOR;
    blue_filter = filter & BLUE_CHANNEL_OPERATOR;

    red = red - red_filter;
    green = (green >> 5) - (green_filter >> 5);
    blue = (blue >> 10) - (blue_filter >> 10);

    return RGB2(red <= 31 ? red : 0, green <= 31 ? green : 0, blue <= 31 ? blue : 0);
}

//returns true if the current mapType is affected by DNS.
bool8 IsMapDNSException()
{
    u8 i;
    for (i=0; i < sizeof(gDnsMapExceptions)/sizeof(gDnsMapExceptions[0]); i++)
        if (gMapHeader.mapType == gDnsMapExceptions[i])
            return TRUE;
    return FALSE;
}

//returns the filter to use depending on RTC time.
u16 GetDNSFilter()
{
    u8 hour = Rtc_GetCurrentHour();
    u8 minutes = Rtc_GetCurrentMinute();

    switch(GetTimeLapse(hour))
    {
        case TIME_MIDNIGHT0:
            if (hour < 1)
                return gMidnightFilters[minutes >> 3];          
            else
                return gMidnightFilters[7];

        case TIME_DAWN1:
            return gDawnFilters[minutes >> 1];

        case TIME_DAY2:
            return gDayFilter;

        case TIME_SUNSET3:
            return gSunsetFilters[minutes >> 1];

        case TIME_NIGHTFALL4:
            return gNightfallFilters[minutes >> 1];

        case TIME_NIGHT5:
            return gNightFilter;
    }

    return 0;
}

//Returns the timeLapse
u8 GetTimeLapse(u8 hour)
{
    if (hour < MIDNIGHT_END_HOUR)
        return TIME_MIDNIGHT0;
    else if (hour < DAWN_END_HOUR)
        return TIME_DAWN1;
    else if (hour < DAY_END_HOUR)
        return TIME_DAY2;
    else if (hour < SUNSET_END_HOUR)
        return TIME_SUNSET3;
    else if (hour < NIGHTFALL_END_HOUR)
        return TIME_NIGHTFALL4;
    else
        return TIME_NIGHT5;
}

//Does Dma palette transfer with a black & white effect
void BlacknWhiteDmaTransfer()
{
    u16* pal_color = (u16*) PLTT;   //pointer to palette ram
    u16 color, red, green, blue, i;

    for (i = 0; i < 512; i++)
    {
        color = gPlttBufferFaded[i];

        red = color & RED_CHANNEL_OPERATOR;
        green = color & GREEN_CHANNEL_OPERATOR;
        blue = color & BLUE_CHANNEL_OPERATOR;

        *pal_color = RGB2(red, green, blue);
        pal_color++;
    }
}
