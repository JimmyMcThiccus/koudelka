#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"
#include "game/a2b/a2b.h"

extern "C++" void *func_8003C510_(void *p) asm("func_8003C510");
void *func_8003C510_(void *p)
{
    AT(p, void **, 0) = D_80012714;
    return p;
}

EXTERN_C int func_8003C524(void *p)
{
    void *q = AT(p, void *, 0x48);
    if (q) {
        A2VObj0 *o = AT(q, A2VObj0 *, 8);
        if (o)
            return o->v10();
        return -1;
    }
    return -1;
}

EXTERN_C int func_8003C584(S_8003C584 *p)
{
    if (p->unk48 != 0) {
        return p->unk48->unk14;
    } else {
        return 0;
    }
}

EXTERN_C void *func_8003C5A8(void *p, void *a, int b, int c)
{
    AT(p, void **, 0) = D_80010178;
    AT(p, int, 4) = 0;
    AT(p, void **, 0) = D_8001276C;
    AT(p, int, 0x10) = AT(AT(a, void *, 0), int, 0x24);
    AT(p, void *, 8) = a;
    AT(p, int, 0xC) = c;
    AT(p, int, 0x14) = 0;
    AT(p, int, 0x18) = b;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003C5EC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003C764);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003C908);

EXTERN_C void *func_8003CA10(void *p, void *q)
{
    if (AT(p, int, 0x10) == AT(AT(q, void *, 8), int, 0x24)) {
        char *e = AT(p, char *, 8);
        char *r = (char *)((void *(*)(void *, void *))func_8001A744)(e ? e - 8 : 0, q);
        void *n;
        void *v = r ? r + 8 : 0;
        AT(p, void *, 8) = v;
        if (v)
            return p;
        n = AT(p, void *, 4);
        AT(p, void *, 4) = 0;
        if (p)
            ((A2VObj0 *)p)->v00(3);
        return n;
    }
    if (AT(p, void *, 4))
        AT(p, void *, 4) = func_8003CA10(AT(p, void *, 4), q);
    return p;
}

EXTERN_C void func_8003CAD0(void *p)
{
    int c = AT(p, int, 0xC);
    if (c) {
        char *q = AT(p, char *, 8);
        S_A2_VEnt *e = (S_A2_VEnt *)(AT(q, char *, 0) + 0x28);
        p = q + e->delta;
        e->pfn(p, c);
    } else
        AT(p, A2VObj0 *, 8)->v03();
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003CB50);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003CC78);

EXTERN_C void func_8003CE00(void *p, int a)
{
    AT(p, A2VObj<4> *, 0x18)->v01(a);
}

EXTERN_C int func_8003CE44(void *p)
{
    void *q = AT(p, void *, 8);
    if (q) {
        S_A2_VE *e = VENT(q, 0x58);
        return e->pfn((char *)q + e->delta);
    }
    return -1;
}

EXTERN_C int func_8003CE88(S_8003CE88 *p)
{
    return p->unk8;
}

EXTERN_C int func_8003CE94(S_8003CE88 *p)
{
    return p->unk14;
}

EXTERN_C void func_8003CEA0(S_8003CE88 *p, int v)
{
    p->unk14 = v;
}

EXTERN_C int func_8003CEA8(S_8003CE88 *p)
{
    return p->unk4;
}

EXTERN_C void *func_8003CEB4(void *p, int a)
{
    AT(p, void **, 0) = D_8001277C;
    AT(p, short, 0xC) = 0;
    AT(p, short, 4) = 0;
    AT(p, char, 0xE) = 0;
    AT(p, char, 0xF) = 0;
    AT(p, char, 0x10) = 0;
    AT(p, short, 0x18) = 0;
    AT(p, int, 0x14) = a;
    AT(p, short, 0x20) = 0;
    AT(p, short, 0x22) = 0;
    return p;
}

EXTERN_C void func_8003CEEC(void *p, int a)
{
    void *q = AT(p, void *, 0x14);
    AT(p, void **, 0) = D_8001277C;
    if (q)
        AT(q, int, 0x68) = 0;
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003CF24);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003D00C);

EXTERN_C void func_8003D358(S_8003D358 *p, int a, S_Rgb c)
{
    p->unkC = a;
    p->unkE = c;
}

EXTERN_C void *func_8003D37C(S_8003D37C *p)
{
    return &p->unkE;
}

EXTERN_C void func_8003D384(void *p, int a, int b)
{
    S_A2B_B4ED8 *g = D_800B4ED8;
    AT(p, short, 4) = a; AT(p, int, 8) = b; g->unk94 = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003D3A0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003D68C);

EXTERN_C int func_8003D9F0(S_8003D9F0 *p)
{
    return p->unkC;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003D9FC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003DB1C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003DC54);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003DEA8);

EXTERN_C void func_8003E124(void *p)
{
    if (func_8003E658(p, AT(p, int, 0x138))) {
        AT(p, short, 0x11E) = 1;
        func_8003ECFC((S_8003ECFC *)p, 0, 0);
    }
}

EXTERN_C int func_8003E170(S_8003E170 *p)
{
    return func_8003E658(p, p->unk13C);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003E198);

EXTERN_C void func_8003E5F8(void *p)
{
    int *t = (int *)((char *)p + 0x1C0);
    AT(p, short, 0x11E) = 1;
    func_8003ECFC((S_8003ECFC *)p, 0, func_80041C18(t));
    AT(p, int, 0x1C8) = func_80041C18(t);
    AT(p, int, 0x1CC) = 0;
    AT(p, short, 0x1A2) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003E658);

EXTERN_C void func_8003EBC4(S_8003EBC4 *p, int v)
{
    p->unk1B8 = v;
}

EXTERN_C void func_8003EBCC()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003EBD4);

EXTERN_C void func_8003ECE4(S_8003ECE4 *p, int *a, int *b)
{
    *a = p->unk100;
    *b = p->unk104;
}

EXTERN_C void func_8003ECFC(S_8003ECFC *p, int a, int b)
{
    p->unk100 = a;
    if (b)
        p->unk104 = b;
}

EXTERN_C int func_8003ED10(void *p, int b, int c, int d, int e)
{
    int neg = 0;
    if (!d)
        return neg;
    b -= c;
    if (b < 0) {
        neg = 1;
        b = ~b + neg;
    }
    b <<= 4;
    b *= e;
    b /= d;
    b >>= 4;
    if (neg)
        b = ~b + 1;
    return b;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003ED90);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003F1C8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003F3DC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003F594);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003F73C);
