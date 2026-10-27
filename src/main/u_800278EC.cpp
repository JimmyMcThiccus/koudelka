#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"

EXTERN_C S_8001A294 *func_800278EC(S_8001A294 *p, int a)
{
    p->vtbl = D_80011124;
    p->unk4 = a;
    p->vtbl = D_800110F4;
    return p;
}

EXTERN_C void func_80027910(void *p, int a)
{
    func_80026138(p, a);
}

EXTERN_C S_8001A294 *func_80027930(S_8001A294 *p, int a)
{
    p->vtbl = D_80011124;
    p->unk4 = a;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_80027948);

EXTERN_C void func_8002798C()
{
    if (D_800B4C58)
        D_800B4C58--;
}

EXTERN_C void func_800279A8()
{
    D_800B4C58++;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_800279C0);

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_80027A60);

EXTERN_C int func_80027D90(S_80027D90 *p)
{
    return p->unk14;
}

EXTERN_C void func_80027D9C(S_80027D90 *p)
{
    p->unkC = 3;
}

EXTERN_C void func_80027DA8(S_80027D90 *p)
{
    p->unkC = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_80027DB0);

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_80027DFC);

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_80027E30);

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_80027FB0);

EXTERN_C S_80027FEC *func_80027FEC(S_80027FEC *p, S_80027FEC *q)
{
    q->unk8 = p->unk8;
    q->unkA = p->unkA;
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_80028004);

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_80028064);

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_800280A8);

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_800280F8);

EXTERN_C void func_80028158(void *p, void *q)
{
    func_8002DC34(q, (int)p, 0);
}

EXTERN_C void func_80028184(S_80028184 *p)
{
    p->unk8 = 0;
}

EXTERN_C void func_8002818C(S_80028184 *p, int v)
{
    p->unkA = v;
}

EXTERN_C int func_80028194(S_80028184 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4h *func_800281A0(S_Vobj4h *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800111BC;
    p->unk8 = 0;
    p->unkA = a;
    return p;
}

EXTERN_C void func_800281CC(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_800281EC(S_80028184 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_800281F8);

EXTERN_C S_80027FEC *func_80028230(S_80027FEC *p, S_80027FEC *q)
{
    func_80027FEC(p, q);
    return q;
}

EXTERN_C void func_80028258(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_80028278);

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_800282AC);

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_80028330);

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_80028374);

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_800283AC);
