#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001DDF4);

EXTERN_C void func_8001DEB8(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800103E0;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001DEE0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001DF58);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001DFC0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E03C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E07C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E15C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E1AC);

EXTERN_C S_8001E23C *func_8001E23C(S_8001E23C *p)
{
    p->unk0 = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E248);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E288);

EXTERN_C void func_8001E2D8(S_8001E23C *p, int v)
{
    p->unk10 = v;
}

EXTERN_C int func_8001E2E0(S_8001E23C *p)
{
    return p->unkC;
}

EXTERN_C int func_8001E2EC(S_8001E23C *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E2F8);

EXTERN_C S_Vobj *func_8001E330(S_Vobj *p)
{
    p->vtbl = D_800103E0;
    return p;
}

EXTERN_C int func_8001E344()
{
    return D_800B4C24++;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E360);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E40C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E508);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E57C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E6AC);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E758);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E7C8);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E804);

EXTERN_C void func_8001E840(S_8001E840 *p)
{
    p->unk98 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E848);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001E9A8);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001EAAC);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001EB60);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001EBD8);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001EC98);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001ED2C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001EE58);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001EEC0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001EFE4);

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001F048);

EXTERN_C void func_8001F074(char *p, int a)
{
    func_8001F094(p + 0xAC, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001F094);

EXTERN_C void func_8001F134()
{
    func_80019920((List *)((S_800186B0 *)&D_800AC688)->p, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001DDF4", func_8001F15C);
