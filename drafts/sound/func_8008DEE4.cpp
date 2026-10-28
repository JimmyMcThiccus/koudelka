#include "pre.h"
// NONMATCH: 4 diffs; only the inner entry loop: retail strength-reduces the entry pointer as p+0xB (offsets -5/-1/0), here as p (6/0xA/0xB)
EXTERN_C void func_8008E024(void *drv);
EXTERN_C void func_80093A40(void *t, int bits);

EXTERN_C void func_8008DEE4(char *drv, int idx)
{
    unsigned char *p;
    int n;
    int off;
    int j;
    int m;
    int k;
    char *t;

    if (drv == 0) {
        return;
    }
    func_8008E024(drv);
    p = FIELD_AT(drv, unsigned char *, 0x18);
    if (p == 0) {
        return;
    }
    n = (FIELD_AT(p, unsigned short, 0x6) >> 8) + ((FIELD_AT(p, unsigned short, 0x6) & 0xFF) << 8);
    if (n == 0) {
        func_8009482C(0x30, 0);
        return;
    }
    if (n - 1 < idx) {
        func_8009482C(0x31, 0);
        return;
    }
    off = *(unsigned short *)((idx << 1) + p + 8);
    if (off == 0) {
        return;
    }
    p += off;
    n = (FIELD_AT(p, unsigned short, 0x2) >> 8) + ((FIELD_AT(p, unsigned short, 0x2) & 0xFF) << 8);
    for (j = 0; j < n; j++) {
        t = FIELD_AT(drv, char *, 0xC) + p[j * 8 + 6] * 0x160;
        FIELD_AT(t, short, 0x70) = p[j * 8 + 10];
        FIELD_AT(t, short, 0x72) = p[j * 8 + 11];
    }
    t = FIELD_AT(drv, char *, 0xC) + 0x160;
    k = FIELD_AT(drv, unsigned char, 0x2A) - 1;
    while (k != 0) {
        k--;
        func_80093A40(t, 4);
        t += 0x160;
    }
}
