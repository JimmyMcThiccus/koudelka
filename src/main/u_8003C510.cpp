#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003C510);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003C524);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003CA10);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003CAD0);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003D384);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003E5F8);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003ED10);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003ED90);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003F1C8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003F3DC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003F594);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003F73C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003F7E8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003F850);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003F8CC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003FA50);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003FAEC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003FB88);

EXTERN_C void func_8003FC08(void *p, int a, int b)
{
    void *q = AT(p, void *, 0x1B8);
    if (q && (q = AT(q, void *, 0x68)))
        func_8003D384(q, a, b);
}

EXTERN_C void func_8003FC48(void *p)
{
    AT(p, short, 0x1D8) = 0;
    AT(p, int, 0x114) = func_80041C18((int *)((char *)p + 0x1C0)) - AT(p, int, 0xF8);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003FC84);

EXTERN_C S_A2_V4 func_8003FD30(S_A2_V4 *a, S_A2_V4 *b) return r
{
    int a0 = a->a, b0 = b->a, a1 = a->b, b1 = b->b, a2 = a->c, b2 = b->c, a3 = a->d;
    r.a = a0 + b0;
    r.b = a1 + b1;
    r.c = a2 + b2;
    r.d = a3;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003FD70);

EXTERN_C void *func_8003FD9C(void *p)
{
    void *q = AT(p, void *, 0x1B8);
    if (q && (q = AT(q, void *, 0x68)))
        return func_8003D37C((S_8003D37C *)q);
    return 0;
}

EXTERN_C int func_8003FDDC(S_8003FDDC *p)
{
    return p->unk144;
}

EXTERN_C void *func_8003FDE8(S_8003FDDC *p)
{
    return &p->unk146;
}

EXTERN_C void func_8003FDF0(void *p, S_A2_V4 *v)
{
    S_A2_At34 *q = AT(p, S_A2_At34 *, 0x1B8);
    q->v = *v;
    func_80039DD8(q);
}

EXTERN_C S_A2_V4 func_8003FE34(S_A2_FE34o *p)
{
    return p->q->v;
}

EXTERN_C void func_8003FE64(void *p, S_A2_V4 *v)
{
    S_A2_At34 *q = AT(p, S_A2_At34 *, 0x1B8);
    q->v = *v;
    func_80039DD8(q);
}

EXTERN_C void func_8003FEA8(S_8003FDDC *p, int v)
{
    p->unk138 = v;
}

EXTERN_C void func_8003FEB0()
{
}

EXTERN_C S_A2_FEB8 *func_8003FEB8(S_A2_FEB8 *p)
{
    int i, j;
    for (i = 7; i >= 0; i--)
        p->a[i] = 0;
    for (j = 7; j >= 0; j--)
        p->s[j] = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8003FEF4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004007C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800400D0);

EXTERN_C void *func_800401AC(void *p, short a)
{
    if (a == AT(p, short, 8))
        return p;
    if (AT(p, void *, 4))
        return func_800401AC(AT(p, void *, 4), a);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800401F0);

EXTERN_C char *func_8004025C(void *p, short x, short y)
{
    return AT(p, char *, 0x24) + (AT(p, short, 0xC) * x + y) * 12;
}

EXTERN_C int func_80040294(S_80040294 *p, short a)
{
    return p->unk28 + a * 16;
}

EXTERN_C char *func_800402A8(void *p, short i)
{
    short n = AT(p, short, 0x34);
    if (n && i < n && i >= 0)
        return AT(p, char *, 0x30) + i;
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800402E4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800404C8);

EXTERN_C int func_800406A0(S_800406A0 *p)
{
    return p->unk1C;
}

EXTERN_C int func_800406AC(S_800406A0 *p)
{
    return p->unk13;
}

EXTERN_C int func_800406B8(S_800406A0 *p)
{
    return p->unk12;
}

EXTERN_C int func_800406C4(S_800406A0 *p)
{
    return p->unk14;
}

EXTERN_C int func_800406D0(S_800406A0 *p)
{
    return p->unk10;
}

EXTERN_C int func_800406DC(S_800406A0 *p)
{
    return p->unkE;
}

EXTERN_C int func_800406E8(S_800406A0 *p)
{
    return p->unkC;
}

EXTERN_C int func_800406F4(S_800406A0 *p)
{
    return p->unkA;
}

EXTERN_C int func_80040700(S_800406A0 *p)
{
    return p->unk8;
}

EXTERN_C int func_8004070C(S_800406A0 *p)
{
    return p->unk2C;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80040718);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80040C10);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800410F4);

EXTERN_C void *func_800419A8(void *p)
{
    func_80040718(p);
    return p;
}

EXTERN_C S_800419D0 *func_800419D0(S_800419D0 *p)
{
    p->unk4 = 0x1000;
    p->unk0 = 0x1000;
    p->unk10 = 0;
    p->unk12 = 0;
    p->unk14 = 0x2000;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800419F4);

EXTERN_C int func_80041B44(int a)
{
    D_800B4D30 = 0;
    D_800B4D2C = a;
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80041B54);

EXTERN_C void func_80041BF8(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C unsigned int func_80041C18(int *p)
{
    if (p[0])
        return D_800A4534.unkC & ~1;
    p[1] += 2;
    return p[1];
}

EXTERN_C void func_80041C50(int *p)
{
    if (p[0]) p[0] = 0; else p[0] = 1;
    p[1] = D_800A4534.unkC & ~1;
}

EXTERN_C void func_80041C88(int *p, int a)
{
    if (a) p[0] = 1; else p[0] = 0;
    p[1] = D_800A4534.unkC & ~1;
}

EXTERN_C S_80041CB8 *func_80041CB8(S_80041CB8 *p)
{
    p->unk4 = 0;
    p->unk0 = 1;
    return p;
}

EXTERN_C int func_80041CCC(S_80041CCC *p)
{
    return p->unk0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80041CD8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80041D84);

EXTERN_C S_80041E28 *func_80041E28(S_80041E28 *p, int a, int b, int c, int d)
{
    p->vtbl = D_800127FC;
    p->unk4 = a;
    p->unk14 = 0;
    p->unk8 = b;
    p->unkC = c;
    p->unk10 = d;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80041E54);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80042140);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800423A8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80042430);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800424B0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004252C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800425A8);

EXTERN_C void func_80042818()
{
}

EXTERN_C void func_80042820()
{
}

EXTERN_C void func_80042828()
{
}

EXTERN_C void func_80042830()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80042838);

EXTERN_C void func_8004296C()
{
}

EXTERN_C void func_80042974()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004297C);

EXTERN_C int func_80042A74()
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80042A7C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80042D3C);

EXTERN_C int func_80042E08()
{
    return 1;
}

EXTERN_C int func_80042E10()
{
    return 1;
}

EXTERN_C int func_80042E18()
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80042E20);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80042EF0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80043060);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800433CC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80043460);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80043540);

EXTERN_C void func_800435AC(void *p, int a, int b)
{
    func_80044990((char *)p + 0x234, AT(AT(p, void *, 0x1B8), short, 0x2E), a, b, 0, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800435E8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80043680);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800436C0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80043700);

EXTERN_C void func_80043740(void *p, short a)
{
    if (AT(p, short, 0x118) != a) {
        AT(p, short, 0x118) = a;
        if (!AT(p, short, 0x220)) {
            AT(p, int, 0xF8) = 0;
            AT(p, unsigned char, 0x120)++;
        }
    }
}

EXTERN_C void func_8004377C(S_8004377C *p, int a)
{
    p->unk11A = a;
    if (p->unk220 == 0) {
        p->unkF8 = 0;
        p->unk120++;
    }
    p->unk138 = 0;
}

EXTERN_C void func_800437A4(S_8004377C *p, int a)
{
    p->unk11C = a;
    if (p->unk220 == 0) {
        p->unkF8 = 0;
        p->unk120++;
    }
}

EXTERN_C void func_800437CC(void *p, short a, char b, short c)
{
    AT(p, int, 0x208) = 0;
    AT(p, short, 0x220) = 2;
    AT(p, int, 0xF8) = 0;
    AT(p, char, 0x1A0) = b;
    AT(p, short, 0x21C) = c;
    if (a)
        AT(p, unsigned char, 0x120)++;
    else
        AT(p, unsigned char, 0x120) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80043808);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004387C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80043A94);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80043D38);

EXTERN_C S_80043D94_V func_80043D94(S_80043D94 *p)
{
    return p->unk284;
}

EXTERN_C void func_80043DC0(S_80043DC0 *p)
{
    p->unk26C = 0;
    p->unk26E = 0;
    p->unk270 = 0;
    p->unk20C = D_800A4534.unkC + 20;
}

EXTERN_C int func_80043DE8()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80043DF0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80044590);

EXTERN_C S_A2_V4 func_8004463C(S_A2_V4 *a, S_A2_V4 *b) return r
{
    int a0 = a->a, b0 = b->a, a1 = a->b, b1 = b->b, a2 = a->c, b2 = b->c, a3 = a->d;
    r.a = a0 + b0;
    r.b = a1 + b1;
    r.c = a2 + b2;
    r.d = a3;
}

EXTERN_C void func_8004467C(S_8004467C *p)
{
    p->unk214 = 0;
}

EXTERN_C void func_80044684(S_8004467C *p)
{
    p->unk214 = 1;
}

EXTERN_C void func_80044690(S_80044690 *p)
{
    p->unkF8 = 0;
    p->unk220 = 0;
    p->unk120++;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800446A8);

EXTERN_C int func_80044730()
{
    return 1;
}

EXTERN_C void func_80044738()
{
}

EXTERN_C int func_80044740(S_80044740 *p)
{
    func_80043DF0(p->unk4);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80044764);

EXTERN_C void func_800447D8(int a)
{
    func_8001D324(D_800A4544, func_8001D25C(D_800A4544, a));
}

EXTERN_C void func_80044814(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80044834);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80044890);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80044990);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80044A3C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80044BE4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80044C7C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80044CE0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80044F18);

EXTERN_C int func_800450E4(void *p, short a, short b)
{
    int r = 0;
    void *q = AT(p, void *, 0x328);
    if (q)
        r = func_800401F0(q, a, b);
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80045120);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800451A8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80045264);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004561C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800456F4);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80045850);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800459D4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80045B38);

EXTERN_C void func_80045C88(S_80045C88 *p, int a)
{
    p->unk1C[p->unk44++] = a;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80045CAC);

EXTERN_C int func_80045D18(S_80045D18 *p)
{
    return p->unk30;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80045D24);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80045DC8);

EXTERN_C char *func_80045E6C(void *p, int n)
{
    char *r = 0;
    char *b = AT(p, char *, 0x38);
    if (b && AT(p, unsigned int, 0x34) < AT(p, unsigned int, 0x30)) {
        r = b + AT(p, unsigned int, 0x34);
        AT(p, unsigned int, 0x34) += n;
        if (AT(p, unsigned int, 0x34) > AT(p, unsigned int, 0x30))
            AT(p, unsigned int, 0x34) = AT(p, unsigned int, 0x30);
    }
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80045EB8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80045F84);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004600C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80046078);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800460E4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004616C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800461F4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004637C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800464E4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80046658);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800467CC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80046844);

EXTERN_C void func_800468D0()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800468D8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80046948);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80046998);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80048C30);

EXTERN_C void func_80048D2C(void *p, int a)
{
    if (a & 1)
        operator delete(p);
}

EXTERN_C void *func_80048D54(void *p)
{
    return p;
}

EXTERN_C void func_80048D5C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80048D64);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004921C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80049250);

EXTERN_C void *func_80049398(void *p)
{
    return p;
}

EXTERN_C S_1F80000C *func_800493A0(void *p, int i)
{
    return &D_1F80000C[i];
}

EXTERN_C int func_800493BC(S_800493BC *p)
{
    return p->unkB;
}

EXTERN_C void func_800493C8(S_800493C8 *p, int a)
{
    p->unk8 = (a << 24) | (p->unk8 & 0xFFFFFF);
}

EXTERN_C void *func_800493E8(void *p, int a)
{
    AT(p, void **, 4) = D_80011B5C;
    AT(p, int, 0) = 0;
    AT(p, void **, 4) = D_80012BC8;
    AT(p, int, 8) = (a << 24) | 0x808080;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80049420);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80049488);

EXTERN_C void *func_80049594(void *p, int a)
{
    AT(p, void **, 4) = D_80011B5C;
    AT(p, int, 0) = 0;
    AT(p, void **, 4) = D_80012BC8;
    AT(p, int, 8) = (a << 24) | 0x808080;
    AT(p, void **, 4) = D_80012BF8;
    return p;
}

EXTERN_C S_A2_SvList *func_800495D8(S_A2_SvList *p, S_A2_Sv *v)
{
    p->v[p->n++] = *v;
    return p;
}

EXTERN_C S_1F800010 *func_80049618(void *p, int i)
{
    return &D_1F800010[i];
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004962C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80049680);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80049748);

EXTERN_C unsigned int *func_800497A8(unsigned int *p)
{
    int i;
    unsigned int c = 0x30808080;
    for (i = 2; i >= 0; i--)
        p[i] = c;
    return p;
}

EXTERN_C void func_800497D4(int *a, int *b)
{
    int i;
    for (i = 0; i < 3; i++)
        *a++ = *b++;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80012BC8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80012BF8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80012C28);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80012C58);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800497FC);

EXTERN_C void func_80049858()
{
}

EXTERN_C int func_80049860()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80049868);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004991C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800499D0);

EXTERN_C int func_80049A7C(void *p, int i)
{
    return D_800B4D3C[i];
}

EXTERN_C void func_80049A94(void *p, int a)
{
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80049AB4);

EXTERN_C void *func_80049B2C(S_80049B2C *p)
{
    return &p->unk44;
}

EXTERN_C int func_80049B34()
{
    return 0x20;
}

EXTERN_C int func_80049B3C()
{
    return 0;
}

EXTERN_C void func_80049B44()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80049B4C);

EXTERN_C char *func_80049CE4(S_A2_At18 *p, char *src)
{
    func_800499D0(p, src);
    p->c = *(S_Rgb *)(src + 0x10);
    return src + 0x14;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80049D2C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80049E98);

EXTERN_C void func_80049F00(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012CF8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80049F28);

EXTERN_C void *func_80049FA0(S_80049FA0 *p)
{
    return &p->unk44;
}

EXTERN_C int func_80049FA8()
{
    return 0;
}

EXTERN_C void func_80049FB0()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80049FB8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004A16C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004A2F4);

EXTERN_C void func_8004A35C(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012CF8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004A384);

EXTERN_C void *func_8004A404(S_8004A404 *p)
{
    return &p->unk68;
}

EXTERN_C int func_8004A40C()
{
    return 0x24;
}

EXTERN_C int func_8004A414()
{
    return 0;
}

EXTERN_C void func_8004A41C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004A424);

EXTERN_C char *func_8004A5C8(void *p, char *src)
{
    func_800499D0(p, src);
    func_8004A954(p ? (char *)p + 0x18 : 0, src + 0x10);
    return src + 0x1C;
}

EXTERN_C void func_8004A610(void *p)
{
    func_8004A98C(p ? (char *)p + 0x18 : 0);
}

EXTERN_C void func_8004A640(void *p)
{
    func_8004A9E4(p ? (char *)p + 0x18 : 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004A670);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004A7F0);

EXTERN_C void func_8004A874(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012DE8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004A89C);

EXTERN_C void func_8004A954(void *p, void *q)
{
    AT(p, int, 0) = AT(q, int, 0);
    func_8004AE24(p ? (char *)p + 4 : 0, (char *)q + 4);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004A98C);

EXTERN_C int func_8004A9E4(void *p)
{
    if ((AT(p, unsigned char, 3) >> 1) & 1) {
        char *q = p ? (char *)p + 4 : 0;
        return (AT(q, unsigned short, 6) >> 5) & 3;
    }
    return -1;
}

EXTERN_C S_8004AA24_B *func_8004AA24(S_8004AA24_A *p, S_8004AA24_B *q)
{
    int a = p->unk4, b = p->unk8, c = p->unkC;
    q->unkC = a;
    q->unk14 = b;
    q->unk1C = c;
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004AA44);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004AAF0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004AB98);

EXTERN_C S_Prim *func_8004ABEC(S_Prim *p)
{
    ((unsigned char *)&p->tag)[3] = 7;
    p->code = 0x24;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004AC04);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004AE24);

EXTERN_C void func_8004AE8C(S_80034F24 *p, int a)
{
    p->unk6 = (p->unk6 & 0xFF9F) | ((a & 3) << 5);
}

EXTERN_C int func_8004AEA8(S_80034F40 *p)
{
    return (p->unk6 >> 5) & 3;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004AEBC);

EXTERN_C void *func_8004AF3C(S_8004AF3C *p)
{
    return &p->unk68;
}

EXTERN_C int func_8004AF44()
{
    return 0;
}

EXTERN_C void func_8004AF4C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004AF54);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004B124);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004B2C4);

EXTERN_C void func_8004B348(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012DE8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004B370);

EXTERN_C void *func_8004B3F0(S_8004B3F0 *p)
{
    return &p->unk68;
}

EXTERN_C int func_8004B3F8()
{
    return 0;
}

EXTERN_C void func_8004B400()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004B408);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004B690);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004B83C);

EXTERN_C void func_8004B8C8(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012DE8;
    func_800198AC(p, a);
}

EXTERN_C int func_8004B8F0()
{
    return 0x30;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004B8F8);

EXTERN_C void func_8004B970(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012F50;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004B998);

EXTERN_C void *func_8004BA18(S_8004BA18 *p)
{
    return &p->unk5C;
}

EXTERN_C int func_8004BA20()
{
    return 0;
}

EXTERN_C void func_8004BA28()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004BA30);

EXTERN_C char *func_8004BBCC(void *p, char *src)
{
    func_800499D0(p, src);
    func_800497D4((int *)(p ? (char *)p + 0x50 : 0), (int *)(src + 0x10));
    return src + 0x1C;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004BC14);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004BD84);

EXTERN_C void func_8004BE10(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012F50;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004BE38);

EXTERN_C void *func_8004BEB8(S_8004BEB8 *p)
{
    return &p->unk58;
}

EXTERN_C int func_8004BEC0()
{
    return 0;
}

EXTERN_C void func_8004BEC8()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004BED0);

EXTERN_C char *func_8004C08C(S_A2_At54 *p, char *src)
{
    func_800499D0(p, src);
    p->c = *(S_Rgb *)(src + 0x10);
    return src + 0x14;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004C0D4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004C254);

EXTERN_C void func_8004C2E4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012F50;
    func_800198AC(p, a);
}

EXTERN_C int func_8004C30C()
{
    return 0x34;
}

extern "C++" char *func_8004C314_(void *p, char *src) asm("func_8004C314");
char *func_8004C314_(void *p, char *src)
{
    func_800499D0(p, src);
    func_8004AE24(p ? (char *)p + 0x18 : 0, src + 0x10);
    return src + 0x18;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004C35C);

EXTERN_C void func_8004C3D4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800130B0;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004C3FC);

EXTERN_C void *func_8004C474(S_8004C474 *p)
{
    return &p->unk78;
}

EXTERN_C int func_8004C47C()
{
    return 0;
}

EXTERN_C void func_8004C484()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004C48C);

EXTERN_C char *func_8004C660(void *p, char *q)
{
    func_8004C314(p, q);
    return q + 0x18;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004C688);

EXTERN_C int func_8004C6EC(void *p)
{
    char *b = p ? (char *)p + 0x74 : 0;
    if ((AT(b, unsigned char, 3) >> 1) & 1) {
        char *q = p ? (char *)p + 0x18 : 0;
        return (AT(q, unsigned short, 6) >> 5) & 3;
    }
    return -1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004C738);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004C8D0);

EXTERN_C void func_8004C960(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800130B0;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004C988);

EXTERN_C void *func_8004CA00(S_8004CA00 *p)
{
    return &p->unk78;
}

EXTERN_C int func_8004CA08()
{
    return 0;
}

EXTERN_C void func_8004CA10()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004CA18);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004CC7C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004CE14);

EXTERN_C void func_8004CEA4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800130B0;
    func_800198AC(p, a);
}

EXTERN_C unsigned int *func_8004CECC(unsigned int *p)
{
    int i;
    unsigned int c = 0x38808080;
    for (i = 3; i >= 0; i--)
        p[i] = c;
    return p;
}

EXTERN_C void func_8004CEF8(int *a, int *b)
{
    int i;
    for (i = 0; i < 4; i++)
        *a++ = *b++;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80012CF8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80012D70);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80012DE8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80012E60);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80012ED8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80012F50);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80012FC0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013038);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800130B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013120);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013198);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004CF20);

EXTERN_C void func_8004CF7C()
{
}

EXTERN_C int func_8004CF84()
{
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004CF8C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004D040);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004D0F4);

EXTERN_C int func_8004D1A0(void *p, int a)
{
    return (a + 1) & 3;
}

EXTERN_C void func_8004D1AC(void *p, int a)
{
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004D1CC);

EXTERN_C void *func_8004D244(S_8004D244 *p)
{
    return &p->unk50;
}

EXTERN_C int func_8004D24C()
{
    return 0x28;
}

EXTERN_C int func_8004D254()
{
    return 0;
}

EXTERN_C void func_8004D25C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004D264);

EXTERN_C char *func_8004D464(S_A2_At1C *p, char *src)
{
    func_8004D0F4(p, src);
    p->c = *(S_Rgb *)(src + 0x14);
    return src + 0x18;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004D4AC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004D678);

EXTERN_C void func_8004D6E0(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013280;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004D708);

EXTERN_C void *func_8004D780(S_8004D780 *p)
{
    return &p->unk50;
}

EXTERN_C int func_8004D788()
{
    return 0;
}

EXTERN_C void func_8004D790()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004D798);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004D9AC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004DB8C);

EXTERN_C void func_8004DBF4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013280;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004DC1C);

EXTERN_C void *func_8004DC8C(S_8004DC8C *p)
{
    return &p->unk80;
}

EXTERN_C int func_8004DC94()
{
    return 0x2C;
}

EXTERN_C int func_8004DC9C()
{
    return 0;
}

EXTERN_C void func_8004DCA4()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004DCAC);

EXTERN_C char *func_8004DEDC(void *p, char *src)
{
    func_8004D0F4(p, src);
    func_80034854(p ? (char *)p + 0x1C : 0, src + 0x14);
    return src + 0x20;
}

EXTERN_C void func_8004DF24(void *p)
{
    func_8003488C(p ? (char *)p + 0x1C : 0);
}

EXTERN_C void func_8004DF54(void *p)
{
    func_800348E4(p ? (char *)p + 0x1C : 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004DF84);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004E17C);

EXTERN_C void func_8004E200(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013370;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004E228);

EXTERN_C void *func_8004E298(S_8004E298 *p)
{
    return &p->unk80;
}

EXTERN_C int func_8004E2A0()
{
    return 0;
}

EXTERN_C void func_8004E2A8()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004E2B0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004E4FC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004E700);

EXTERN_C void func_8004E784(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013370;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004E7AC);

EXTERN_C void *func_8004E81C(S_8004E81C *p)
{
    return &p->unk80;
}

EXTERN_C int func_8004E824()
{
    return 0;
}

EXTERN_C void func_8004E82C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004E834);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004EB28);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004ED40);

EXTERN_C void func_8004EDCC(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013370;
    func_800198AC(p, a);
}

EXTERN_C int func_8004EDF4()
{
    return 0x38;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004EDFC);

EXTERN_C void func_8004EE74(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800134D8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004EE9C);

EXTERN_C void *func_8004EF1C(S_8004EF1C *p)
{
    return &p->unk74;
}

EXTERN_C int func_8004EF24()
{
    return 0;
}

EXTERN_C void func_8004EF2C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004EF34);

EXTERN_C char *func_8004F144(void *p, char *src)
{
    func_8004D0F4(p, src);
    func_8004CEF8((int *)(p ? (char *)p + 0x64 : 0), (int *)(src + 0x14));
    return src + 0x24;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004F18C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004F368);

EXTERN_C void func_8004F3F4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800134D8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004F41C);

EXTERN_C void *func_8004F49C(S_8004F49C *p)
{
    return &p->unk68;
}

EXTERN_C int func_8004F4A4()
{
    return 0;
}

EXTERN_C void func_8004F4AC()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004F4B4);

EXTERN_C char *func_8004F6F0(S_A2_At64 *p, char *src)
{
    func_8004D0F4(p, src);
    p->c = *(S_Rgb *)(src + 0x14);
    return src + 0x18;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004F738);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004F924);

EXTERN_C void func_8004F9B4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800134D8;
    func_800198AC(p, a);
}

EXTERN_C int func_8004F9DC()
{
    return 0x3C;
}

extern "C++" char *func_8004F9E4_(void *p, char *src) asm("func_8004F9E4");
char *func_8004F9E4_(void *p, char *src)
{
    func_8004D0F4(p, src);
    func_80034EBC(p ? (char *)p + 0x1C : 0, src + 0x14);
    return src + 0x1C;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004FA2C);

EXTERN_C void func_8004FAA4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013638;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004FACC);

EXTERN_C void *func_8004FB4C(S_8004FB4C *p)
{
    return &p->unk98;
}

EXTERN_C int func_8004FB54()
{
    return 0;
}

EXTERN_C void func_8004FB5C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004FB64);

EXTERN_C char *func_8004FDC8(void *p, char *q)
{
    func_8004F9E4(p, q);
    return q + 0x1C;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004FDF0);

EXTERN_C int func_8004FE54(void *p)
{
    char *b = p ? (char *)p + 0x94 : 0;
    if ((AT(b, unsigned char, 3) >> 1) & 1) {
        char *q = p ? (char *)p + 0x1C : 0;
        return (AT(q, unsigned short, 6) >> 5) & 3;
    }
    return -1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8004FEA0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800500B4);

EXTERN_C void func_80050144(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013638;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8005016C);

EXTERN_C void *func_800501EC(S_800501EC *p)
{
    return &p->unk98;
}

EXTERN_C int func_800501F4()
{
    return 0;
}

EXTERN_C void func_800501FC()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80050204);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800504E0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800506F4);

EXTERN_C void func_80050784(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013638;
    func_800198AC(p, a);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013280);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800132F8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013370);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800133E8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013460);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800134D8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013548);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800135C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013638);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800136A8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013720);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800507AC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800507D4);

EXTERN_C S_80050838 *func_80050838(S_80050838 *p)
{
    p->unk0 = 0;
    return p;
}

EXTERN_C void func_80050844(void **p, int a)
{
    if (*p)
        func_8001A744(*p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80050874);

EXTERN_C void func_80050E38(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80050E58);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80050EA4);

EXTERN_C void *func_800514C0(void *p)
{
    return p;
}

C_800514C8::C_800514C8()
{
    vt = D_80010178;
    unk4 = 0;
    vt = D_80013808;
    func_80051A2C(D_800B4D40, this);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80051514);

C_80051564::C_80051564()
{
    vt = D_800137F0;
    func_80051A7C((S_80051A7C *)D_800B4D40, (int)this);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800515A4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800515F4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800518A8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80051930);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80051A2C);

EXTERN_C void func_80051A7C(S_80051A7C *p, int a)
{
    if (p->unk104 == 0)
        p->unk104 = a;
    p->unk124 = 0;
    p->unkFC++;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80051AA4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80051B70);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80051C3C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80051CB0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80051D80);

EXTERN_C int func_80051E50(void *p)
{
    if (AT(p, short, 0xFC) && !AT(p, short, 0x10C)) {
        AT(p, short, 0x10C) = AT(p, short, 0xFC);
        AT(p, short, 0xFC) = 0;
        AT(p, int, 0x108) = AT(p, int, 0x104);
        AT(p, int, 0x104) = 0;
        return 0;
    }
    return 1;
}

EXTERN_C int func_80051E90(void *p)
{
    if (!AT(p, short, 0xFC) && AT(p, short, 0x10C)) {
        AT(p, short, 0xFC) = AT(p, short, 0x10C);
        AT(p, short, 0x10C) = 0;
        AT(p, int, 0x104) = AT(p, int, 0x108);
        AT(p, int, 0x108) = 0;
    }
    return 1;
}

EXTERN_C int func_80051ECC(S_80051ECC *p)
{
    return p->unk11A;
}

EXTERN_C void func_80051ED8(void *p, int a)
{
    AT(p, void **, 0x8C) = D_800137C0;
    AT(p, void **, 0) = D_800137D8;
    func_8001E508(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80051F0C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80051FB8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80052044);

EXTERN_C void func_800520BC(void *p)
{
    void *q = D_800B4D4C;
    if (q && (q = AT(q, void *, 0x58)) && q != p)
        func_80054CA0(q);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80052100);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8005226C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800523DC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800525EC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80052640);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80052778);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8005287C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8005294C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80052B60);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80052C8C);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800137C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800137D8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800137F0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013808);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80052E40);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80052FB8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800530B8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80053250);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800532EC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80053360);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_8005340C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800534F8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80053568);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800535E0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80053658);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800536F0);

EXTERN_C int func_80053794(S_80053794 *p)
{
    return p->unk4;
}

EXTERN_C void func_800537A0(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C S_800537C0 *func_800537C0(S_800537C0 *p)
{
    p->vtbl = D_80013B00;
    p->unk0 = 0;
    p->unk4 = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800537DC);

EXTERN_C int func_80053830(S_80053830 *p)
{
    return --p->unk4 > 0;
}

EXTERN_C void func_80053848(S_80053830 *p)
{
    if (p->unk4 >= 2)
        p->unk4 = 1;
}

EXTERN_C int func_80053868(S_80053794 *p)
{
    return p->unk0;
}

EXTERN_C int func_80053874(S_80053794 *p)
{
    return p->unk4;
}

EXTERN_C int func_80053880(S_80053794 *p)
{
    return p->unk4 < 1;
}

EXTERN_C void func_8005388C(void *p, int a)
{
    AT(p, int, 0) = a;
    AT(p, int, 4) = a;
    func_80055624(p, 1);
}

EXTERN_C void func_800538B4(int v)
{
    D_800B4D5C = v;
}

EXTERN_C void func_800538C0(int v)
{
    D_800B4D60 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800538CC);

EXTERN_C void *func_80053928(void *p)
{
    AT(p, void **, 0x18) = D_80013B20;
    AT(p, int, 4) = 1;
    AT(p, short, 0xC) = 0xE0;
    AT(p, int, 0) = 0;
    AT(p, int, 8) = 0;
    AT(p, short, 0xE) = 0x1E;
    AT(p, int, 0x14) = 0;
    AT(p, int, 0x10) = 0;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80053964);

EXTERN_C void func_800539C0()
{
}

EXTERN_C void func_800539C8()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800539D0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80053AE4);

EXTERN_C void func_80053B68(void *p)
{
    int n = AT(p, int, 0x14) - 1;
    void *s = AT(p, void *, 0x10);
    AT(p, void *, 0x10) = 0;
    AT(p, int, 0x14) = n;
    if (n)
        func_800544AC(p, s);
    if (s)
        func_800A0D0C(s);
}

EXTERN_C int func_80053BB4(S_80053BB4 *p)
{
    return p->unk14;
}

EXTERN_C int func_80053BC0(S_80053BB4 *p)
{
    return p->unk10;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80053BCC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80053C6C);

EXTERN_C void func_80053CD8(void *p)
{
    func_80053BCC(p, &D_800B4D64, 1);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80053D00);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80053DDC);

EXTERN_C void func_80053F28(S_80025A64 *p, S_Rgb c)
{
    p->unkC = c;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80053F48);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80053FB0);

EXTERN_C void func_8005402C(S_8005402C *p, int a, int b)
{
    p->unkC += a;
    p->unkE += b;
}

EXTERN_C int func_80054048(S_80054048 *p)
{
    return p->unk8;
}

EXTERN_C S_Rgb func_80054054(S_80025A64 *p)
{
    return p->unkC;
}

EXTERN_C int func_80054074(S_80054048 *p)
{
    return p->unk4 & 0x3;
}

EXTERN_C int func_80054080(S_80054048 *p)
{
    return p->unk4;
}

EXTERN_C void func_8005408C(S_80054048 *p, int v)
{
    p->unk4 = v;
}

EXTERN_C void func_80054094(S_80054048 *p, int v)
{
    p->unk0 = v;
}

EXTERN_C int func_8005409C(S_80054048 *p)
{
    return p->unk0 == 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800540A8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80054258);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800543A0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80054414);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800544AC);

EXTERN_C void func_8005457C(S_8005457C *p, int v)
{
    p->unk8 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80054584);

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_800545E0);

C_8005464C::C_8005464C()
{
    AT(this, void **, 0x18) = D_80013B48;
    unk1C = 0;
    unk20 = 10000;
    unk24 = 0;
}

EXTERN_C void *func_80054690(void *p, void *q)
{
    AT(p, int, 0x1C) = AT(q, int, 0x1C);
    AT(p, int, 0x20) = AT(q, int, 0x20);
    func_80053C6C(p, q);
    return p;
}

EXTERN_C void *func_800546C8(void *p, signed char a)
{
    int v = a;
    if (v >= 0x80)
        v -= 0x100;
    func_80054708(p, v);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80054708);

EXTERN_C void *func_800548F0(void *p, int a)
{
    func_80054708(p, AT(p, int, 0x1C) + a);
    return p;
}

EXTERN_C void *func_80054920(void *p, int a)
{
    func_80054708(p, AT(p, int, 0x1C) - a);
    return p;
}

EXTERN_C void *func_80054950(void *p)
{
    func_80054708(p, AT(p, int, 0x1C) + 1);
    return p;
}

EXTERN_C void *func_80054980(void *p)
{
    func_80054708(p, AT(p, int, 0x1C) - 1);
    return p;
}

EXTERN_C int func_800549B0(S_800549B0 *p, int a)
{
    return p->unk1C == a;
}

EXTERN_C int func_800549C4(S_800549B0 *p, int a)
{
    return p->unk1C != a;
}

EXTERN_C int func_800549D8(S_800549D8 *p)
{
    return p->unk1C;
}

EXTERN_C void func_800549E4(S_800549D8 *p, int v)
{
    p->unk24 = v;
}

EXTERN_C void func_800549EC(S_800549D8 *p, int v)
{
    p->unk20 = v;
}

EXTERN_C void func_800549F4()
{
}

EXTERN_C void func_800549FC()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003C510", func_80054A04);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013940);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013A38);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013A88);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013AA8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013B00);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013B20);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013B48);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013B70);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013BA0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013BB8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013BD0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013C00);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013C50);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013C70);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013CB0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013D00);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013E10);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013E30);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013F40);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013F90);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80013FB0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800140C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014110);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014130);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014180);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014278);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800142B8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014308);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014400);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014450);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014548);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800145B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014658);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014750);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800147A0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014808);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014858);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014950);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_800149B8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014A08);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014B00);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014B68);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014BD0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014C38);

INCLUDE_RODATA("asm/main/nonmatchings/u_8003C510", D_80014C50);
