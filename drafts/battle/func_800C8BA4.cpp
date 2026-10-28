// func_800C8BA4: NOT MATCHING. 43 differ: structure right; callee-saved allocation permuted (retail p=s7,k=s3,x=s4,xk=s6; ours p=s6,k=s4,x=s3,xk=s7).
#include "common.h"
#define func_800C8BA4 func_800C8BA4_hdr
#include "battle/battle.h"
#undef func_800C8BA4
EXTERN_C int func_800C9EF4(T_C9A4C *p, int a, int b, int c, int d, int e, int f);
EXTERN_C void func_800C7F74(T_C9A4C *p, int a);
struct P8BA4 { char pad[0x3A3]; signed char b3A3[7][5]; };
//@ func_800C8BA4 best
EXTERN_C void func_800C8BA4(P8BA4 *p, int x1, int y1, int x2, int y2) {
    int k = 10;
    int n = 40;
    int minx = x2; if (x1 < minx) minx = x1;
    int maxx = x2; if (x2 < x1) maxx = x1;
    int miny = y2; if (y1 < miny) miny = y1;
    int maxy = y2; if (y2 < y1) maxy = y1;
    int ax = x1 * k * 8, ay = y1 * k * 8, bx = x2 * k * 8, by = y2 * k * 8;
    func_800C7F74((T_C9A4C *)p, 0);
    for (int x = minx; x <= maxx; x++) {
        int far = k * n * 4;
        for (int y = miny; y <= maxy; y++) {
            int d = func_800C9EF4((T_C9A4C *)p, ax, ay, bx, by, x * k * 8, y * k * 8);
            if (d < k * k) p->b3A3[y][x] = 7;
            else if (d < 400) p->b3A3[y][x] = 3;
            else if (d < far) p->b3A3[y][x] = 1;
        }
    }
}
