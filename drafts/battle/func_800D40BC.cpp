// func_800D40BC: NOT MATCHING. ~46 instructions: same bit-search loop as func_800D2A98; retail reloads p->b50 every iteration and keeps the mask in two registers.
#include "common.h"
#include "battle/battle.h"
EXTERN_C void func_800D401C(T_D401C *p, int n);
struct T_D40BC_b { char pad[0xC]; };
struct T_D40BC { char pad[0x38]; T_D40BC_b f38; char pad44[4]; int f48; int f4C; unsigned char b50; };
EXTERN_C int func_800D40BC(T_D40BC *p) {
    if (!func_80053830(p ? &p->f38 : 0)) {
        int old = p->f4C;
        p->f4C = (old + 1) % 5;
        if (p->f4C < 3) {
            int m = 0x20 << p->f4C;
            while (!(p->b50 & m)) { if (++p->f4C >= 3) break; m <<= 1; }
        }
        if (p->f4C == 3 && !p->f48) p->f4C = 4;
        if (p->f4C != old) func_800D401C((T_D401C *)p, p->f4C);
        func_8005388C(p ? &p->f38 : 0, 0x1E);
    }
    return 1;
}
