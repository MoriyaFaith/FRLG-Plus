#include "global.h"
#include "script.h"
#include "quest_log.h"

u8 gUnknown_3005E88;

struct UnkStruct_203AE94
{
    u8 unk_0_0:4;
    u8 unk_0_4:2;
    u8 unk_0_6:2;
    u8 unk_1;
};

EWRAM_DATA u8 gUnknown_203ADF8 = 0;
EWRAM_DATA u8 gUnknown_203ADFA = 0;
EWRAM_DATA void * gUnknown_203AE04 = NULL;
EWRAM_DATA void * gUnknown_203AE08 = NULL;
EWRAM_DATA void * gUnknown_203AE0C[32] = {NULL};
EWRAM_DATA void (* gUnknown_203AE8C)(void) = 0;
EWRAM_DATA struct UnkStruct_203AE94 gUnknown_203AE94 = {0};
EWRAM_DATA u8 gUnknown_203AE98[0x100] = {0};

void sub_8110A00(void);
u8 sub_8110E68(void *);
void sub_8110A3C(void);
void sub_8110E3C(void);
void sub_8111AD8(void);
void sub_81118F4(s8);
void sub_8113BD8(void);
void sub_81138F8(void);

void sub_8110840(void * a0)
{
    size_t r1 = (void *)gSaveBlock1Ptr - a0;
    if (gUnknown_203AE04)
        gUnknown_203AE04 += r1;
    if (gUnknown_203ADFA != 0)
    {
        if (gUnknown_203AE08)
            gUnknown_203AE08 += r1;
        if (gUnknown_203ADFA == 2)
        {
            int r3;
            for (r3 = 0; r3 < 0x20; r3++)
                if (gUnknown_203AE0C[r3])
                    gUnknown_203AE0C[r3] += r1;
        }
    }
}

void sub_811089C(void)
{
    memset(gSaveBlock1Ptr->questLog, 0, sizeof(gSaveBlock1Ptr->questLog));
    gUnknown_203ADF8 = 0;
    gUnknown_203ADFA = 0;
    gUnknown_203AE8C = 0;
    gUnknown_203AE08 = 0;
    gUnknown_203AE04 = 0;
    sub_8113BD8();
    sub_81138F8();
}

void sub_81108F0(u8 a0)
{
    memset(gSaveBlock1Ptr->questLog + a0, 0, sizeof(struct QuestLog));
    gUnknown_203AE04 = NULL;
}

void sub_8110920(void)
{
    gUnknown_203AE04 = NULL;
}

void sub_811092C(void)
{
    if (gUnknown_203AE8C)
        gUnknown_203AE8C();
}

bool8 sub_8110944(u8 * a0, size_t a1)
{
    u8 * r2 = gSaveBlock1Ptr->questLog[gUnknown_203ADF8].filler_568;
    u8 * r0 = gSaveBlock1Ptr->questLog[gUnknown_203ADF8].end;
    r0 -= a1;
    if (a0 < r2 || a0 > r0)
        return FALSE;
    return TRUE;
}

bool8 sub_8110988(u8 * a0, size_t a1)
{
    u8 * r2 = gSaveBlock1Ptr->questLog[gUnknown_203ADF8].filler_568;
    u8 * r0 = gSaveBlock1Ptr->questLog[gUnknown_203ADF8].end;
    r0 -= a1;
    if (a0 < r2 || a0 > r0)
        return FALSE;
    return TRUE;
}

void sub_81109CC(u8 a0)
{
    gUnknown_203ADFA = a0;
    if (a0 == 1)
        gUnknown_203AE8C = sub_8110A00;
    else
        gUnknown_203AE8C = sub_8110A3C;
}

void sub_8110A00(void)
{
    if (sub_8110E68(gUnknown_203AE98) != 1)
    {
        gUnknown_3005E88 = 0;
        sub_8110E3C();
        gUnknown_203ADFA = 0;
        gUnknown_203AE8C = NULL;
    }
}

void sub_8110A3C(void)
{
    if (gUnknown_203AE94.unk_0_0 == 2)
        gUnknown_203AE94.unk_0_0 = 0;

    if (gUnknown_203AE94.unk_0_6 == 0)
    {
        if (gUnknown_3005E88 || gUnknown_203AE94.unk_0_0 == 1 || (gUnknown_203AE94.unk_1 < 32 && gUnknown_203AE0C[gUnknown_203AE94.unk_1]))
            sub_8111AD8();
        else
        {
            gUnknown_203AE94.unk_0_6 = 2;
            ScriptContext2_Enable();
            sub_81118F4(0);
        }
    }
}
