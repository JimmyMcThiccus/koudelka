#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"
#include "game/a2b/a2b.h"

C_80044BE4::C_80044BE4() : C_8001E40C((int)(D_800A4578_p ? D_800A4578_p + 0x50 : 0), 2, 0x200, 0)
{
    int i;
    AT(this, void **, 0x8C) = D_8001295C;
    AT(this, void **, 0) = D_80012974;
    AT(this, int, 0x328) = 0;
    AT(this, int, 0x32C) = 0;
    D_800B4D38 = this;
    for (i = 2; i >= 0; i--)
        AT(this, S_A2B_988 *, 0xF8 + i * 4) = &D_800AC8A0[i];
}

EXTERN_C void func_80044C7C(void *p, void *a)
{
    if (!AT(p, void *, 0x328)) {
        AT(p, void *, 0x328) = a;
    } else {
        void *q = AT(p, void *, 0x328);
        if (AT(q, void *, 4) && a)
            func_8001A864(a, AT(q, void *, 4));
        AT(q, void *, 4) = a;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80044BE4", func_80044CE0);

INCLUDE_ASM("asm/main/nonmatchings/u_80044BE4", func_80044F18);

EXTERN_C int func_800450E4(void *p, short a, short b)
{
    int r = 0;
    void *q = AT(p, void *, 0x328);
    if (q)
        r = func_800401F0(q, a, b);
    return r;
}

EXTERN_C int func_80045120(void *p, short a, short b)
{
    A2VObj0 *o = (A2VObj0 *)func_800450E4(p, a, b);
    if (o) {
        void *r = ((void *(*)(void *, void *))func_8001A744)(AT(p, void *, 0x328), o);
        if (o == AT(p, A2VObj0 *, 0x328))
            AT(p, void *, 0x328) = r;
        o->v00(3);
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80044BE4", func_800451A8);

INCLUDE_ASM("asm/main/nonmatchings/u_80044BE4", func_80045264);

EXTERN_C void func_8004561C(void *p, void *q)
{
    if (!AT(q, void *, 0x4C)) {
        void *o = operator new(0x3C);
        int r = AT(q, A2VObj0 *, 0x18)->v03();
        AT(q, int, 0x4C) = func_80045EB8(o, p, r, q, 0, 2, 1, 0, 5);
    }
    func_8003546C(AT(q, void *, 0x18), AT(q, int, 0x4C));
    func_8003714C(AT(q, void *, 0x18));
    AT(q, unsigned short, 0x10)++;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80044BE4", func_800456F4);

EXTERN_C void func_8004580C(S_8004580C *p, int v, int i)
{
    p->unkF8[i] = v;
}

EXTERN_C void func_8004581C(void *p, int a)
{
    AT(p, void **, 0x8C) = D_8001295C;
    AT(p, void **, 0) = D_80012974;
    func_8001E508(p, a);
}
