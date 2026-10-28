// func_800D2254: NOT MATCHING. Only cause: retail re-masks the kind byte with `andi v1,v1,0xFF` in the first branch's delay slot; every variant here lets GCC drop it (44 instructions shift).
#include "common.h"
#include "battle/battle.h"
EXTERN_C void func_80068B14(void *p);
EXTERN_C int func_8008A5C8(void *a, void *b, void *c);
struct T_D2254_x { char pad[0x1B]; unsigned char b1B; char pad1C[0x6F]; unsigned char b8B; };
struct T_D2254_a { char d[0x6C]; };
struct T_D2254_b { char d[0x28]; };
struct T_D2254 { char pad[0x68]; signed char b68[0x34]; T_D2254_a a9C[1]; };
struct T_D2254b { char pad[0x1548]; T_D2254_b b1548[1]; };
struct T_D2254_y { char pad[0x1B]; char b1B; char pad1C[0x6F]; unsigned char b8B; };
struct T_D2254c { char pad[0x1CF0]; unsigned short h1CF0; };
struct T_D2254_B { int pad[2]; void *items[3]; };
struct T_D2254_D : T_D0390_A, T_D2254_B {};
struct T_D2254_G { char pad[0x328]; T_D2254_D *f328; };
EXTERN_C void *func_80061188(void *p, int a);
EXTERN_C void func_800D2254(T_D2254 *p) {
    func_80068B14(p);
    int cnt = ((T_D2254c *)p)->h1CF0;
    for (int i = 0; i < cnt; i++) {
        T_D2254_x *x = (T_D2254_y *)func_80061188(D_800B4DD0[0], ((signed char *)p)[i + 0x68]);
        int ok = 0;
        unsigned char t = x->b1B;
        if ((unsigned)(t - 12) < 4) {
            T_D2254_D *d = ((T_D2254_G *)func_800787B4())->f328; int n = (int)D_800B4D5C[0];
            T_D2254_B *b = d;
            void *s = b->items[n];
            if (!func_8008A5C8(s, s, x)) ok = 1;
        } else { int k = t; if (k == 6 || k == 0xB) {
            if (func_800D0390()) ok = 1;
        } else if (k == 0x87 || (x->b8B >> 7)) ok = 1; }
        if (ok) { func_80054094(&p->a9C[i], 1); func_80054094(&((T_D2254b *)p)->b1548[i], 1); }
    }
    func_80054CE4(p);
}
