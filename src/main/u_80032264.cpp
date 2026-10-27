#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032264);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_800322C8);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032334);

EXTERN_C void func_800323C0(S_800323C0 *p, S_800323C0_Node *n)
{
    if (p->unk8)
        n->unk4 = p->unk8;
    p->unk8 = n;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_800323DC);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032504);

EXTERN_C int func_80032920(S_80032920 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_8003292C);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032A10);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032A9C);

EXTERN_C void func_80032B14(S_Rgb *a, S_Rgb *b)
{
    *a = *b;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032B2C);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032BD8);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032C80);

EXTERN_C S_Prim *func_80032CBC(S_Prim *p)
{
    ((unsigned char *)&p->tag)[3] = 5;
    p->code = 0x28;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032CD4);

EXTERN_C int func_80032D54()
{
    return 0x2C;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032D5C);

EXTERN_C void func_80032EB0(S_A2_Node4 *n)
{
    if (D_800AC844.unk8)
        n->unk4 = D_800AC844.unk8;
    D_800AC844.unk8 = n;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032ED4);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032F80);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80033404);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_800338A4);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80033D34);

EXTERN_C void func_80033D7C(void *p)
{
    func_8003488C(p ? (char *)p + 0x34 : 0);
}

EXTERN_C void func_80033DAC(void *p)
{
    func_800348E4(p ? (char *)p + 0x34 : 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80033DDC);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80033E40);
