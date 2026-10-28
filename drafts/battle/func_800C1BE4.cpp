// func_800C1BE4: NOT MATCHING. 118 differ, built 20 bytes short: q (param a1) should be copied to a3 at entry with g=D_800AF470 in a1 (ours keeps q in a1, g in a2); jump table switch and the vec/null-check tail follow the func_800C0EB8 recipe (a2=0 hoisted, T_C1BE4v zero ctor, y=0 before x). Needs jtbl_800B73BC rodata check.
#include "common.h"
#include "battle/battle.h"
struct T_C1BE4v { int x, y, z, w; T_C1BE4v() { x = 0; y = 0; z = 0; w = 0; } };
struct T_C1BE4 { char pad0[0x2A0]; char f2A0[0x170]; short s410; char pad412[0xAA]; signed char b4BC; signed char b4BD; char pad4BE[8]; short s4C6; short pad4C8; short s4CA; char pad4CC[0x2A]; short s4F6[5]; short s500; short pad502; short s504; };
EXTERN_C T_C19BC_g *D_800AF470c[] __asm__("D_800AF470");
EXTERN_C void func_800C1F5C(T_C1BE4 *p, T_C1BE4 *q, int i, int last);
EXTERN_C void func_800C220C(T_C1BE4 *p, T_C1BE4 *q, int i, int last);
EXTERN_C void func_800C2538(T_C1BE4 *p, T_C1BE4 *q, int i, int last);
EXTERN_C void func_800C2814(T_C1BE4 *p, T_C1BE4 *q, int i, int last);
EXTERN_C void func_800C2B70(T_C1BE4 *p, T_C1BE4 *q, int i, int last);
EXTERN_C void func_800C1BE4(T_C1BE4 *p, T_C1BE4 *q);
//@ func_800C1BE4 a
EXTERN_C void func_800C1BE4(T_C1BE4 *p, T_C1BE4 *q0) {
    T_C1BE4 *q = q0;
    T_C19BC_g *g = D_800AF470c[0];
    bool last = p->s504 + 1 == p->s500;
    int a = (p->b4BC << 4) | 6;
    int b = q ? q->b4BC : 0xFF;
    int c = p->s4F6[p->s504];
    if (last) c |= 0x80;
    for (int i = 0x1F; i > 0; i--) g->e3B0[i] = g->e3B0[i - 1];
    g->e3B0[0].a = a;
    g->e3B0[0].b = b;
    g->e3B0[0].c = c;
    g->e3B0[0].d = 0xFF;
    int l2 = p->s504 + 1 == p->s500;
    switch (p->s4F6[p->s504]) {
    case 0: func_800C1F5C(p, q, p->s504, l2); break;
    case 1: func_800C220C(p, q, p->s504, l2); break;
    case 2: func_800C2538(p, q, p->s504, l2); break;
    case 3: func_800C2814(p, q, p->s504, l2); break;
    case 4: func_800C2B70(p, q, p->s504, l2); break;
    }
    if (l2) {
        if (p->s410 || p->b4BD != 2) {
            char *base = 0;
            int cx = p->s4C6, cz = p->s4CA;
            T_C1BE4v vec;
            vec.y = 0;
            vec.x = (cx - 2) * 2400;
            int z = (3 - cz) * 2400;
            vec.z = z;
            if (p) base = p->f2A0;
            func_8008299C(base, 0x1D, vec.x, vec.y, z, 0, 0);
            func_80082E14(p ? p->f2A0 : 0, 0);
        }
    }
    p->s504 = (unsigned short)p->s504 + 1;
}
