// func_800BB8F8: NOT MATCHING. 15 instructions differ: only s4/s5/s6 roles of the loop-invariant 0x80 / h8 / hv (retail s4=0x80, s5=h8, s6=hv; ours s5=0x80, s4=h8) and a0/a1 swap for the lui of D_1F800000 vs hv. Structure, loop and vcalls match.
#include "common.h"
#include "battle/battle.h"
struct VB8_o { virtual int v1(); virtual int v2(); virtual int v3(); };
struct VB8_m { short s0; short s2; short s4; short s6; unsigned short h8; };
struct VB8_c { char pad[8]; unsigned short h8; };
struct VB8_a { char pad8[0xC]; VB8_c *fC_unused; };
struct T_BB8F8_o { char pad[0xC]; VB8_o *fC; unsigned short h10; short s12; char pad14[8]; unsigned short h1C; };
struct T_BB8F8_oc { char pad[8]; unsigned short h8; };
struct T_BB8F8_o2 { char pad[0xC]; T_BB8F8_oc *fC; unsigned short h10; short s12; char pad14[8]; unsigned short h1C; };
struct VB8_x { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(void *a); };
struct VB8_y { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); };
struct T_BB8F8 { char pad[8]; T_BB8F8_o2 *f8; char padC[4]; VB8_x *f10; int f14; int f18[35]; };
struct T_BB8F8_n { char pad[0x34]; unsigned char b34, b35, b36; char pad37[3]; unsigned short h3A; short pad3C; unsigned short h3E; short pad40; short h42; };
//@ func_800BB8F8 best
EXTERN_C int func_800BB8F8(T_BB8F8 *p) {
    for (int i = 0; i < 35; i++) p->f18[i] = -1;
    func_800BBC04((T_BB118 *)p, p->f18);
    T_BB8F8_o2 *a = p->f8;
    int u;
    if (!a->fC) u = a->h10 & 0x3F;
    else if (((VB8_o *)a->fC)->v3()) u = (short)a->h10 << 1 & 0x7F;
    else u = (short)a->h10 << 2;
    unsigned char uv[2];
    int hh = a->s12;
    uv[0] = u;
    uv[1] = hh;
    unsigned short hv = p->f8->h1C;
    D_1F800000[0].s2 = hv;
    unsigned short h8 = p->f8->fC->h8;
    D_1F800000[0].uv = *(unsigned short *)uv;
    D_1F800000[0].s4 = h8;
    unsigned short hv2 = hv, h82 = h8;
    int i = 0;
    do {
        T_BB8F8_n *n = (T_BB8F8_n *)func_800BD164((T_BB190 *)operator new(0xA0));
        p->f10->v5(n);
        n->b36 = 0x80; n->b35 = 0x80; n->b34 = 0x80;
        n->h3A = h82; n->h3E = hv2; n->h42 = 1;
        func_800BBAD4(p, (T_BAFEC *)n, i);
        ((T_BB190 *)n)->f9C = i;
        if (p->f18[i] != -1) ((T_BB190 *)n)->f98 = 1; else ((T_BB190 *)n)->f98 = 0;
        ((VB8_y *)((char *)n + 8))->v6();
    } while (++i < 35);
    return 1;
}
