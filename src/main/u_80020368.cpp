#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_80020368);

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_8002042C);

EXTERN_C void func_80020510(S_80020510 *p, int v)
{
    p->unk1A = v;
}

EXTERN_C void func_80020518(S_80020510 *p, int v)
{
    p->unk18 = v;
}

EXTERN_C int func_80020520(S_80020510 *p)
{
    return p->unk1A;
}

EXTERN_C int func_8002052C(S_80020510 *p)
{
    return p->unk18;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_80020538);

EXTERN_C void func_800205B4(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_800205D4);

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_8002068C);

EXTERN_C void func_8002072C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_80020734);

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_800207C4);

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_80020884);

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_800208D4);

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_80020948);

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_80020984);

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_800209F4);

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_80020A30);

EXTERN_C void func_80020B08()
{
    func_80019920((List *)((S_800186B0 *)&D_800AC6C4)->p, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020368", func_80020B30);
