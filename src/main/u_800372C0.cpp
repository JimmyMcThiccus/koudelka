#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

EXTERN_C int func_800372C0(S_800372C0 *p)
{
    return p->unk2C + p->unk4->unk4;
}

EXTERN_C int func_800372D4(S_80037258 *p)
{
    return p->unk2C;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800372E0);

EXTERN_C int func_80037380()
{
    return D_800B4D0C;
}

EXTERN_C int func_8003738C(void *p, int a)
{
    return (a & 0x1D) != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037398);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800373F8);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037440);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800374F4);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037524);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037554);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037584);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800375B4);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800375E4);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037688);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800376D0);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037834);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800378A8);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037934);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800379D0);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037A20);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_80037AAC);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800382A4);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_8003831C);

INCLUDE_ASM("asm/main/nonmatchings/u_800372C0", func_800384C4);

EXTERN_C void func_80038508()
{
    func_80037688(&D_800AC86C);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012484);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001252C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001257C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012594);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001260C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001262C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001265C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012674);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800126DC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800126F4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012714);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012724);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001276C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001277C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012794);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800127AC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800127D4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800127E4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800127FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012814);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012864);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001287C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001289C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800128CC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012944);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001295C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012974);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001298C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_8001299C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800129AC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800129C4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_800129FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800372C0", D_80012A18);
