#include "common.h"
#include "capture/capture.h"

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B758C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B76E4);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7728);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B77D8);

EXTERN_C int D_800B1A5C[];
EXTERN_C void func_800B7B28(unsigned char *p)
{
    if (D_800B1A5C[0]) {
        if (!(*(unsigned short *)p & 0x400)) {
            int c = p[0x49];
            if (c != p[0x48]) {
                c++;
                if (c >= 4)
                    c = 0;
                p[0x49] = c;
            }
        }
        *(unsigned short *)p &= ~0x400;
    }
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7B90);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7C34);

EXTERN_C int D_800B1A5C[];
EXTERN_C void func_800B7DFC(short *p)
{
    *p = 0;
    D_800B1A5C[0] = 0;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7E0C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7E6C);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B7F10);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8048);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B815C);

EXTERN_C char *func_800B8280(char *p, int v)
{
    char *a = *(char **)(p + 0x124);
    *(int *)(a + 0x1C) = v;
    a[0x6A1] = 3;
    a = *(char **)(p + 0x128);
    *(int *)(a + 0x1C) = v;
    a[0x6A1] = 3;
    return *(char **)(p + 0x124);
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B82AC);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8360);

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B8434);

EXTERN_C void func_800B8488(char *p, short a, char b)
{
    *(short *)(p + 0) = a;
    p[2] = b;
    *(short *)(p + 4) = 0x400;
    *(short *)(p + 6) = 0;
    *(short *)(p + 0xC) = 0;
    *(short *)(p + 0xE) = 0;
    *(short *)(p + 0x16) = 0;
    p[0x24] = 1;
    p[0x25] = 3;
    p[0x26] = 3;
    p[0x27] = 0;
    p[0x28] = 0xF;
    p[0x29] = 0x7F;
    p[0x2A] = 6;
    p[0x2B] = 0xF;
}

INCLUDE_ASM("asm/capture/nonmatchings/capture", func_800B84E0);
