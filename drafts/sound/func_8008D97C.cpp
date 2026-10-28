#include "pre.h"
// NONMATCH: 9 diffs; only the final size sum: retail keeps the *0xE4 product in v0 and the (a+0xE0)+b sum in v1
EXTERN_C int func_8008D97C(unsigned char *h)
{
    unsigned char *p = h;
    int a;
    int b;
    int r;

    if (FIELD_AT(h, int, 0x0) != 0x6D646D73) {
        r = -1;
    } else {
        b = 0;
        a = h[0x16] * 0x160;
        if (h[0x17] != 0) {
            b = h[0x17] * 4 + 0x10;
        }
        r = p[0x18] * 0xE4 + (a + 0xE0 + b);
        r += 0x50;
    }
    return r;
}
