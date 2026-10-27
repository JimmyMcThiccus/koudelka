#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

EXTERN_C void func_80025854(void *p, int a)
{
    func_8001DEB8(p, a);
}

EXTERN_C int func_80025874(S_80025874 *p)
{
    return p->unk24;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80025880);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80025960);

EXTERN_C int func_800259F8(S_800259F8 *p)
{
    return p->unk1C;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80025A04);

EXTERN_C void *func_80025A5C(S_800259F8 *p)
{
    return &p->unk10;
}

EXTERN_C S_Rgb func_80025A64(S_80025A64 *p)
{
    return p->unk10;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80025A84);

EXTERN_C S_Rgb func_80025B0C(S_80025A64 *p)
{
    return p->unk14;
}

EXTERN_C int func_80025B2C(S_800259F8 *p)
{
    return p->unkC;
}

EXTERN_C int func_80025B38(S_800259F8 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80025B44);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80025BE0);

EXTERN_C void func_80025C50(unsigned short *a, unsigned short *b)
{
    *a = *b;
}

EXTERN_C S_80025C5C *func_80025C5C(S_80025C5C *p, int v)
{
    p->unk0 = v;
    return p;
}

EXTERN_C S_80025C5C *func_80025C68(S_80025C5C *p, int v)
{
    p->unk0 = v;
    return p;
}

EXTERN_C int func_80025C74(S_80025C5C *p)
{
    return p->unk0;
}

EXTERN_C void *func_80025C80(void *p)
{
    return p;
}

EXTERN_C S_80025C88 *func_80025C88(S_80025C88 *p, int a, int b, int c, int d)
{
    p->unk0 = c;
    p->unk2 = a;
    p->unk4 = b;
    p->unk1 = d;
    return p;
}

EXTERN_C void *func_80025CA4(void *p)
{
    return p;
}

EXTERN_C void func_80025CAC(unsigned short *a, unsigned short *b)
{
    *a = *b;
}

EXTERN_C unsigned short *func_80025CB8(unsigned short *a, unsigned short *b)
{
    *a = *b;
    return a;
}

EXTERN_C S_80025CC8 *func_80025CC8(S_80025CC8 *p, int a, int b)
{
    p->unk0 = a;
    p->unk1 = b;
    return p;
}

EXTERN_C void *func_80025CD8(void *p)
{
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80025CE0);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80026014);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_800260A4);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80026138);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80026190);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_800261B4);

EXTERN_C int func_800261D4()
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_800261DC);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80026214);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80026274);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_800262E4);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_800263C0);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80026420);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80026558);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_8002673C);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80026920);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_800269B8);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80027408);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_8002758C);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80027754);

EXTERN_C void func_800278D8()
{
    D_800B4C50 = -1;
    D_800B4C52 = -1;
}
