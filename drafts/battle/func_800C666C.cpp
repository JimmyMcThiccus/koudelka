// func_800C666C: NOT MATCHING. 4 instructions differ: retail keeps (st==1)<<3 in a0 and copies it to a2 in the bne delay slot (ori a2,a0,0x10), with 'sb zero,0x50E' in the lh load-delay slot; ours coalesces both into a2 and schedules the sb later.
#include "common.h"
#include "shared/exe.h"
#include "battle/battle.h"
struct V666C { virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(int a, int b); };
struct T_C666C_o : V666C { char pad[0x410 - 4]; short s410; char pad412[0xDE]; signed char b4F0; char pad4F1[0x1B]; short s50C; signed char b50E; char pad50F; short s510; signed char b512; signed char b513; char pad514[0x1C]; char f2A0_dummy; };
struct T_C666C_o2 { char pad[0x2A0]; char f2A0[1]; };
struct T_C666C { char pad[1]; };
EXTERN_C T_C666C_o *D_800AFA58o[] __asm__("D_800AFA58");
EXTERN_C void func_800CF2D0(void *p, int i);
EXTERN_C void func_800CFB08(void *p, void *o);
EXTERN_C int func_800C666C(T_C666C *self);
//@ func_800C666C best
EXTERN_C int func_800C666C(T_C666C *self) {
    signed char *g = (signed char *)D_800AF470g[0]->f328;
    int ret = 0;
    T_C666C_o *first = 0;
    int fl[3];
    for (int i = 0; i < 3; i++) {
        fl[i] = 0;
        T_C666C_o *o = D_800AFA58o[i];
        if (o) {
            if (o->b50E) {
                int st = o->s50C;
                o->b50E = 0;
                int t = (st == 1) << 3;
                int f;
                if (st == 2) f = t | 0x10; else f = t;
                if (o->b512) f |= 0x20;
                if (o->b513) f |= 0x40;
                int a1 = o->s510;
                o->s50C = 0; o->b512 = 0; o->b513 = 0;
                o->v18(a1, f & 0xFF);
            }
            if (!o->b4F0 && !o->s410) {
                if (!first) first = o;
                ret = 1;
                o->b4F0 = ret;
                fl[i] = ret;
                func_8008EF40(0x16);
                char *base = (char *)o + 0x2A0;
                func_8008299C(base, 0x29, 0, 0, 0, 0, 0);
                func_8008299C(base, 0x2C, 0x2D, 0, 0, 0, 0);
                func_8008299C(base, 0x2F, ret, 0, 0, 0, 0);
                (g + i)[0xD7] = -1;
                func_800CF2D0(self, i);
            }
        }
    }
    if (first) func_800CFB08(self, first);
    for (int i = 0; i < 3; i++) {
        if (fl[i]) {
            char *base = (char *)D_800AFA58o[i] + 0x2A0;
            func_8008299C(base, 0x2A, 0, 0, 0, 0, 0);
            func_80082E14(base, 0);
        }
    }
    return ret;
}
