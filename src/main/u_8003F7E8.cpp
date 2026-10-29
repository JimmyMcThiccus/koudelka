#include "common.h"
#define EXE_H_IN_u_8003F7E8
#include "shared/exe.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"
#include "game/a2b/a2b.h"

EXTERN_C void *func_8003F7E8(void *p, short a)
{
    void *r = 0;
    if (D_800B4D24)
        r = func_80038FB8(D_800B4D24, a);
    if (r || (r = func_80038FB8(AT(p, void *, 0x1B8), a)))
        D_800B4D24 = r;
    return r;
}

EXTERN_C void func_8003F850(void *p, int idx)
{
    idx++;
    if (idx < AT(p, int, 0x1D0)) {
        void *o = func_80024BB0(AT(p, void *, 0x1D4), (unsigned short)idx);
        ((A2VObj0 *)o)->v01(S_A2B_Pt(AT(p, unsigned short, 0x1A8), AT(p, unsigned short, 0x1AC)), 0);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_8003F8CC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_8003FA50);

EXTERN_C void func_8003FAEC(void *p, void *o, short a, short b)
{
    void *s = AT(p, void *, 0x138);
    if (s) {
        int ch = 0;
        if (AT(s, short, 8) != a || AT(s, short, 0xA) != b)
            ch = 1;
        if (ch)
            AT(p, void *, 0x138) = (void *)func_80044F18(o, a, b, 0, 1);
    } else
        AT(p, void *, 0x138) = (void *)func_80044F18(o, a, b, 0, 1);
}

EXTERN_C void func_8003FB88(void *p, int a, S_A2_RgbC c)
{
    void *q = AT(p, void *, 0x1B8);
    if (q && AT(q, void *, 0x68))
        ((void (*)(void *, int, S_A2_RgbC))func_8003D358)(AT(q, void *, 0x68), a, c);
}

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

EXTERN_C void func_8003FC84(void *p)
{
    void *o;
    if (!AT(p, unsigned char, 0x120))
        AT(p, int, 0xF8) = func_80041C18((int *)((char *)p + 0x1C0)) - AT(p, int, 0x114);
    AT(p, short, 0x1D8) = 1;
    AT(p, int, 0x1C8) = AT(p, int, 0xF8);
    o = func_8001CA10(0x14);
    AT(o, void **, 0) = D_80010178;
    AT(o, int, 4) = 0;
    AT(o, void **, 0) = D_80010300;
    AT(o, short, 8) = 2;
    AT(o, short, 0xA) = 0xC;
    AT(o, int, 0x10) = 0;
    AT(o, int, 0xC) = 0;
    AT(o, void **, 0) = D_800102D0;
    func_8001EFE4(p, o);
}

EXTERN_C S_A2_V4 func_8003FD30(S_A2_V4 *a, S_A2_V4 *b) return r
{
    int a0 = a->a, b0 = b->a, a1 = a->b, b1 = b->b, a2 = a->c, b2 = b->c, a3 = a->d;
    r.a = a0 + b0;
    r.b = a1 + b1;
    r.c = a2 + b2;
    r.d = a3;
}

EXTERN_C int func_8003FD70(void *p)
{
    void *q = AT(p, void *, 0x1B8);
    if (q) {
        q = AT(q, void *, 0x68);
        if (q) q = (void *)AT(q, short, 0xC);
    }
    return (int)q;
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_8003FEF4);

EXTERN_C void *func_8004007C(void *p, short a, short b, short c)
{
    AT(p, void **, 0) = D_80010178;
    AT(p, int, 4) = 0;
    AT(p, void **, 0) = D_800127D4;
    AT(p, short, 8) = a;
    AT(p, short, 0xA) = b;
    AT(p, short, 0xC) = 0;
    AT(p, short, 0xE) = 0;
    AT(p, short, 0x10) = 0;
    AT(p, int, 0x18) = 0;
    AT(p, int, 0x24) = 0;
    AT(p, int, 0x28) = 0;
    AT(p, short, 0x2C) = 0;
    AT(p, int, 0x30) = 0;
    AT(p, short, 0x34) = 0;
    AT(p, short, 0x36) = c;
    return p;
}

EXTERN_C void func_800400D0(void *p, int flags)
{
    AT(p, void **, 0) = D_800127D4;
    if (AT(p, void *, 0x24))
        __builtin_vec_delete(AT(p, void *, 0x24));
    if (AT(p, void *, 0x30))
        __builtin_vec_delete(AT(p, void *, 0x30));
    if (AT(p, void *, 0x28))
        __builtin_vec_delete(AT(p, void *, 0x28));
    if (AT(p, void *, 0x18) && AT(p, short, 0x36)) {
        func_8008ED44(AT(p, void *, 0x18));
        if (AT(p, void *, 0x20))
            func_8008D4C0(AT(p, void *, 0x20));
        if (AT(p, void *, 0x18))
            __builtin_vec_delete(AT(p, void *, 0x18));
    }
    func_8001A610(p, flags);
}

EXTERN_C void *func_800401AC(void *p, short a)
{
    if (a == AT(p, short, 8))
        return p;
    if (AT(p, void *, 4))
        return func_800401AC(AT(p, void *, 4), a);
    return 0;
}

EXTERN_C int func_800401F0(void *p, short a, short b)
{
    if (a == AT(p, short, 8) && b == AT(p, short, 0xA))
        return (int)p;
    if (AT(p, void *, 4))
        return func_800401F0(AT(p, void *, 4), a, b);
    return 0;
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_800402E4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_800404C8);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_80040718);

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_80040C10);

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_800410F4);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_800419F4);

EXTERN_C int func_80041B44(int a)
{
    D_800B4D30 = 0;
    D_800B4D2C = a;
    return 0;
}

EXTERN_C void *func_80041B54(void *p, int a, int b)
{
    void *g;
    AT(p, void **, 0) = D_800127E4;
    AT(p, int, 4) = b;
    AT(p, int, 8) = a;
    g = D_800A4544;
    func_8001D150(g, new S_A2_X1(p));
    D_800B4D28++;
    D_800B4D30++;
    return p;
}

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

EXTERN_C void func_80041CD8(void *p)
{
    if (AT(p, void *, 4)) {
        int a = AT(p, int, 0xC);
        int b = AT(p, int, 0x10);
        unsigned short s = AT(p, unsigned short, 8);
        void *o = func_8001CA10(0x14);
        AT(o, void **, 0) = D_80010178;
        AT(o, int, 4) = 0;
        AT(o, void **, 0) = D_80010300;
        AT(o, short, 8) = 3;
        AT(o, void **, 0) = D_800102D0;
        AT(o, short, 0xA) = s;
        AT(o, int, 0x10) = a;
        AT(o, int, 0xC) = b;
        func_8001EFE4(AT(p, void *, 4), o);
    }
    AT(p, char, 0x14) = 1;
}

EXTERN_C void func_80041D84(void *p)
{
    if (AT(p, void *, 4)) {
        int n = AT(p, int, 0xC) + 1;
        int a = AT(p, int, 0x10);
        unsigned short s = AT(p, unsigned short, 8);
        void *o = func_8001CA10(0x14);
        AT(o, void **, 0) = D_80010178;
        AT(o, int, 4) = 0;
        AT(o, void **, 0) = D_80010300;
        AT(o, short, 8) = 3;
        AT(o, short, 0xA) = s;
        AT(o, int, 0x10) = n;
        AT(o, int, 0xC) = a;
        AT(o, void **, 0) = D_800102D0;
        func_8001EFE4(AT(p, void *, 4), o);
    }
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_80041E54);

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_80042140);

EXTERN_C void func_800423A8(void *p, int a, int b, int c, short e)
{
    void *o;
    AT(p, int, 0x1EC) = a;
    AT(p, int, 0x1F4) = b;
    AT(p, int, 0x1F8) = c;
    AT(p, short, 0x222) = e;
    o = func_8001CA10(0x14);
    AT(o, void **, 0) = D_80010178;
    AT(o, int, 4) = 0;
    AT(o, void **, 0) = D_80010300;
    AT(o, short, 8) = 2;
    AT(o, short, 0xA) = 2;
    AT(o, int, 0x10) = 0xB;
    AT(o, int, 0xC) = 0;
    AT(o, void **, 0) = D_800102D0;
    func_8001EFE4(p, o);
}

EXTERN_C void func_80042430(void *p, int a, int b, short c)
{
    void *o;
    AT(p, short, 0x222) = c;
    AT(p, int, 0x1EC) = a;
    AT(p, int, 0x1F0) = b;
    o = func_8001CA10(0x14);
    AT(o, void **, 0) = D_80010178;
    AT(o, int, 4) = 0;
    AT(o, void **, 0) = D_80010300;
    AT(o, short, 8) = 2;
    AT(o, short, 0xA) = 2;
    AT(o, int, 0x10) = 0xB;
    AT(o, int, 0xC) = 0;
    AT(o, void **, 0) = D_800102D0;
    func_8001EFE4(p, o);
}

EXTERN_C void func_800424B0(void *p, int a, short b)
{
    void *o;
    AT(p, short, 0x222) = b;
    AT(p, int, 0x1EC) = a;
    o = func_8001CA10(0x14);
    AT(o, void **, 0) = D_80010178;
    AT(o, int, 4) = 0;
    AT(o, void **, 0) = D_80010300;
    AT(o, short, 8) = 2;
    AT(o, short, 0xA) = 2;
    AT(o, int, 0x10) = 0xC;
    AT(o, int, 0xC) = 0;
    AT(o, void **, 0) = D_800102D0;
    func_8001EFE4(p, o);
}

EXTERN_C void func_8004252C(void *p, int a, short b)
{
    void *o;
    AT(p, short, 0x222) = b;
    AT(p, int, 0x1EC) = a;
    o = func_8001CA10(0x14);
    AT(o, void **, 0) = D_80010178;
    AT(o, int, 4) = 0;
    AT(o, void **, 0) = D_80010300;
    AT(o, short, 8) = 2;
    AT(o, short, 0xA) = 2;
    AT(o, int, 0x10) = 0xD;
    AT(o, int, 0xC) = 0;
    AT(o, void **, 0) = D_800102D0;
    func_8001EFE4(p, o);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_800425A8);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_80042838);

EXTERN_C void func_8004296C()
{
}

EXTERN_C void func_80042974()
{
}

EXTERN_C void func_8004297C(void *p)
{
    if ((AT(p, unsigned short, 0x140) & 0xF0) == 0) {
        func_8003FAEC(p, D_800B4D38, AT(p, short, 0x144), AT(p, short, 0x11A));
        if (AT(p, unsigned char, 0x120))
            func_8003E198(p, AT(p, void *, 0x138), AT(p, short, 0x11A));
        else
            func_8003E124(p);
        if (AT(p, short, 0x214) == 0)
            ((A2VObj0 *)p)->v06();
    } else {
        if (AT(p, short, 0x214) == 0)
            ((A2VObj0 *)p)->v07();
    }
    if (AT(p, int, 0x208) && AT(p, void *, 0x1B8))
        func_8004387C(p);
}

EXTERN_C int func_80042A74()
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_80042A7C);

EXTERN_C void func_80042D3C(void *p)
{
    if (AT(p, void *, 0x1B4) && AT(p, void *, 0x1B8)) {
        S_A2_V4 v = ((S_A2_At34 *)AT(p, void *, 0x1B8))->v;
        v.b = AT(p, int, 0x108);
        S_A2_At34 *q = AT(p, S_A2_At34 *, 0x1B4);
        q->v = v;
        func_80039DD8(q);
        S_A2_At2C *r = AT(p, S_A2_At2C *, 0x1B4);
        r->v = AT(p, S_A2_At2C *, 0x1B8)->v;
        func_80039DD8(r);
    }
}

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

EXTERN_C int func_80042E20(void *p, int x, int y)
{
    int r;
    if (x > 0) {
        if (y > 0) {
            r = 5;
            if (y < x) {
                if (y * 2 < x)
                    r = 6;
            } else if (x * 2 < y)
                r = 4;
        } else {
            y = -y;
            r = 7;
            if (y < x) {
                if (y * 2 < x)
                    r = 6;
            } else if (x * 2 < y)
                r = 0;
        }
    } else {
        x = -x;
        if (y > 0) {
            r = 3;
            if (y < x) {
                if (y * 2 < x)
                    r = 2;
            } else if (x * 2 < y)
                r = 4;
        } else {
            y = -y;
            r = 1;
            if (y < x) {
                if (y * 2 < x)
                    r = 2;
            } else
                r = !(x * 2 < y);
        }
    }
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_80042EF0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_80043060);

EXTERN_C void func_800433CC(void *p)
{
    AT(p, short, 0x1BC) = func_80042E20(p, AT(p, short, 0x258) - AT(AT(p, void *, 0x1B8), int, 0x34), AT(p, short, 0x25A) - AT(AT(p, void *, 0x1B8), int, 0x3C));
    AT(p, int, 0x1FC) = ratan2(AT(p, short, 0x258) - AT(AT(p, void *, 0x1B8), int, 0x34), AT(p, short, 0x25A) - AT(AT(p, void *, 0x1B8), int, 0x3C)) + 0x800;
    func_80044990((char *)p + 0x234, AT(AT(p, void *, 0x1B8), short, 0x2E), AT(p, int, 0x1FC), 0, AT(p, short, 0x220), 1);
}

EXTERN_C void func_80043460(void *p, S_A2_Pt a, int b, int c)
{
    AT(p, short, 0x226) = 0xB4;
    AT(p, S_A2_Pt, 0x258) = a;
    AT(p, short, 0x1BC) = func_80042E20(p, AT(p, short, 0x258) - AT(AT(p, void *, 0x1B8), int, 0x34), AT(p, short, 0x25A) - AT(AT(p, void *, 0x1B8), int, 0x3C));
    AT(p, int, 0x1FC) = ratan2(AT(p, short, 0x258) - AT(AT(p, void *, 0x1B8), int, 0x34), AT(p, short, 0x25A) - AT(AT(p, void *, 0x1B8), int, 0x3C)) + 0x800;
    func_80044990((char *)p + 0x234, AT(AT(p, void *, 0x1B8), short, 0x2E), AT(p, int, 0x1FC), 0x14, 1, 0);
    AT(p, short, 0x220) = 1;
    if (!c) {
        AT(p, int, 0xF8) = 0;
        AT(p, unsigned char, 0x120)++;
    }
    AT(p, short, 0x224) = 0;
}

EXTERN_C void func_80043540(S_A2_At3540 *p, S_A2_Pt v, int t)
{
    int now;
    p->unk220 = 4;
    p->unk226 = 180;
    p->unk258 = v;
    now = D_800A4534.unkC;
    p->unk200 = now;
    p->unk204 = t + now;
    p->unk25C = p->q->v;
}

EXTERN_C void func_800435AC(void *p, int a, int b)
{
    func_80044990((char *)p + 0x234, AT(AT(p, void *, 0x1B8), short, 0x2E), a, b, 0, 0);
}

EXTERN_C void func_800435E8(void *p)
{
    AT(p, short, 0x1BC) = func_80044890((char *)p + 0x234, AT(AT(p, void *, 0x1B8), short, 0x2E));
    S_A2_Sv v = AT(p, S_A2_At2C *, 0x1B8)->v;
    v.y = AT(p, short, 0x1BC) * 512;
    S_A2_At2C *q = AT(p, S_A2_At2C *, 0x1B8);
    q->v = v;
    func_80039DD8(q);
}

EXTERN_C int func_80043680(void *p, short a, int b)
{
    return func_80044F18(D_800B4D38, AT(p, short, 0x144), a, b, 1) != 0;
}

EXTERN_C int func_800436C0(void *p, short a, int b)
{
    return func_80044F18(D_800B4D38, AT(p, short, 0x144), a, b, 1) != 0;
}

EXTERN_C int func_80043700(void *p, short a, int b, int c)
{
    return func_80044F18(D_800B4D38, AT(p, short, 0x144), a, b, c) != 0;
}

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

EXTERN_C void func_80043808(void *p)
{
    void *o = func_8001CA10(0x14);
    AT(o, void **, 0) = D_80010178;
    AT(o, int, 4) = 0;
    AT(o, void **, 0) = D_80010300;
    AT(o, short, 8) = 2;
    AT(o, short, 0xA) = 2;
    AT(o, int, 0x10) = 7;
    AT(o, int, 0xC) = 0;
    AT(o, void **, 0) = D_800102D0;
    func_8001EFE4(p, o);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_8004387C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_80043A94);

EXTERN_C void func_80043D38(S_A2_At284 *p, S_A2_Sv v)
{
    S_A2_V4 *t;
    int x, y, z, w;
    p->unk208 = 1;
    x = v.x; y = v.y; z = v.z; w = v.pad;
    p->v.a = x;
    t = &p->v;
    t->b = y;
    t->c = z;
    t->d = w;
    p->unk26C = 1;
    p->unk26E = 1;
    p->unk270 = 1;
    p->unk20C = D_800A4534.unkC + 300;
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_80043DF0);

EXTERN_C void func_80044590(void *p)
{
    if (!AT(p, short, 0x214)) {
        void *o = func_8001CA10(0x14);
        AT(o, void **, 0) = D_80010178;
        AT(o, int, 4) = 0;
        AT(o, void **, 0) = D_80010300;
        AT(o, short, 8) = 2;
        AT(o, short, 0xA) = 8;
        AT(o, int, 0x10) = 5;
        AT(o, int, 0xC) = 0;
        AT(o, void **, 0) = D_800102D0;
        func_8001EFE4(p, o);
    } else {
        func_800787B4();
        func_8008316C(p ? (char *)p + 0x2A0 : 0);
    }
}

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

EXTERN_C void func_800446A8(void *p, int a, S_A2_V4 v, int x)
{
    S_A2_At34 *q = AT(p, S_A2_At34 *, 0x1B8);
    q->v = v;
    func_80039DD8(q);
    AT(p, int, 0x108) = v.b;
    func_80042D3C(p);
    func_800435AC(p, a, x);
}

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

EXTERN_C void func_80044764(void *p, int a)
{
    void *g;
    AT(p, int, 4) = a;
    g = D_800A4544;
    func_8001D150(g, new S_A2_X44764(p));
}

EXTERN_C void func_800447D8(int a)
{
    func_8001D324(D_800A4544, func_8001D25C(D_800A4544, a));
}

EXTERN_C void func_80044814(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C void *func_80044834(void *p)
{
    func_80041CB8((S_80041CB8 *)((char *)p + 0x1C));
    AT(p, int, 4) = 0;
    AT(p, int, 0) = 0;
    AT(p, int, 8) = 0;
    AT(p, int, 0x10) = 0;
    AT(p, int, 0xC) = 0;
    AT(p, int, 0x18) = 0;
    func_80041C88((int *)((char *)p + 0x1C), 0);
    return p;
}

EXTERN_C short func_80044890(void *p, int a)
{
    short r;
    if ((unsigned short)(a - 0x101) >= 0xDFF)
        r = 0;
    else if ((unsigned short)(a - 0x100) <= 0x200)
        r = 1;
    else if ((unsigned short)(a - 0x300) <= 0x200)
        r = 2;
    else if ((unsigned short)(a - 0x500) <= 0x200)
        r = 3;
    else if ((unsigned short)(a - 0x700) <= 0x200)
        r = 4;
    else if ((unsigned short)(a - 0x900) <= 0x200)
        r = 5;
    else if ((unsigned short)(a - 0xB00) <= 0x200)
        r = 6;
    else if ((unsigned short)(a - 0xD00) <= 0x200)
        r = 7;
    func_80044990(p, r << 9, r << 9, 0, 0, 0);
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003F7E8", func_80044990);

extern "C++" int f44A3C(int *p, void *q) asm("func_80044A3C");
int f44A3C(int *p, void *q)
{
    int r;
    int c;
    int x;
    int neg;
    int res;
    int new_var;
    if (p[5] == 2) {
        p[5] = 0;
        p[4] = func_80041C18(p + 7);
    }
    r = func_80041C18(p + 7);
    new_var = p[4];
    c = p[3];
    if (r >= new_var + c) {
        if (q != 0 && p[6] == 0) {
            void *m;
            p[6] = 1;
            m = func_8001CA10(0x14);
            AT(m, void **, 0) = D_80010178;
            AT(m, int, 4) = 0;
            AT(m, void **, 0) = D_80010300;
            AT(m, short, 8) = 2;
            AT(m, short, 0xA) = 8;
            AT(m, int, 0x10) = 10;
            AT(m, int, 0xC) = 0;
            AT(m, void **, 0) = D_800102D0;
            func_8001EFE4(q, m);
        }
        res = p[0] + p[1];
        if (res >= 0x1000)
            res -= 0x1000;
        else if (res < 0)
            res += 0x1000;
        return res;
    } else {
        neg = 0;
        x = p[1];
        if (x < 0) {
            neg = 1;
            x = ~x + neg;
        }
        x = (x << 4) * (r - p[4]);
        x /= c;
        x >>= 4;
        if (neg)
            x = ~x + 1;
        res = p[0] + x;
        if (res >= 0x1000)
            res -= 0x1000;
        else if (res < 0)
            res += 0x1000;
        return res;
    }
}
