// func_800D23C0: NOT MATCHING. ~60 instructions: register allocation of the char index (retail keeps it in s0 and a copy in s1) and the order of the second func_80061188 call.
#include "common.h"
#include "battle/battle.h"
EXTERN_C char D_800B7964[];
struct T_D23C0_x { char pad[0x1B]; unsigned char b1B; };
EXTERN_C T_D23C0_x *func_80061188(void *p, int a);
struct T_VE3 { short delta; short index; void (*pfn)(void *, void *, void *, int); };
struct T_D23C0_b4 { char pad[0x9C]; T_VE3 *vt; };
struct T_D23C0_i { char pad[0x400]; T_D23C0_b4 b400; };
struct T_D23C0_B { int pad[2]; T_D23C0_i *items[3]; };
struct T_D23C0_D : T_D0390_A, T_D23C0_B {};
struct T_D23C0_G { char pad[0x328]; T_D23C0_D *f328; };
struct T_D23C0 { char pad[0x20]; int f20; };
struct T_4DD0e { char pad[0x1F4]; short s1F4; };
EXTERN_C int func_800D23C0(T_D23C0 *p) {
    int c = ((signed char *)p)[p->f20 + 0x68]; int c2 = c;
    int k = func_80061188(D_800B4DD0[0], c)->b1B;
    int r = c2;
    if ((unsigned)(k - 12) < 4) {
        T_D23C0_D *d = ((T_D23C0_G *)func_800787B4())->f328; int n = (int)D_800B4D5C[0];
        T_D23C0_B *b = d;
        T_D23C0_i *s = b->items[n];
        T_D23C0_x *e = func_80061188(D_800B4DD0[0], c);
        r = 0x10E7;
        T_D23C0_b4 &bb = s->b400; bb.vt[5].pfn((char *)&bb + bb.vt[5].delta, s, e, 1);
    } else {
        r = (r << 16) + 0x10E6;
        T_4DD0e *t = (T_4DD0e *)D_800B4DD0[0];
        if (t->s1F4 < 3 && (k == 6 || k == 0xB)) { t->s1F4++; func_800C5020(operator new(0x78), D_800B7964, 0x3C); }
    }
    return r;
}
