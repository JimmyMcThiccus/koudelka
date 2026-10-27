#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

EXTERN_C void func_80028428(void *p, int a)
{
    func_8001DEB8(p, a);
}

EXTERN_C int func_80028448(S_80028448 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028454);

EXTERN_C void *func_800284AC(void *p, void *q)
{
    func_80028710(p, q);
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_800284D4);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_800285CC);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_8002860C);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028710);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_800287C8);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_800288D0);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028A24);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028AE8);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028B90);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028C08);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028C80);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028D10);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028DC4);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028F10);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028F58);

EXTERN_C void func_80028FA0(void *p, int a)
{
    func_80028DC4(p, a);
}

EXTERN_C int func_80028FC0(S_80028FC0 *p)
{
    return p->unk4;
}

EXTERN_C void func_80028FCC()
{
    D_800B4C70 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028FD8);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_8002900C);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80029414);

EXTERN_C void func_8002970C(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C S_8002972C *func_8002972C(S_8002972C *p, int a, int b, int c, int d)
{
    p->vtbl = D_80011384;
    p->unk5 = a;
    p->unk6 = b;
    p->unk7 = c;
    p->unk4 = d & 1;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80029758);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80029850);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_8002991C);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80029A14);
