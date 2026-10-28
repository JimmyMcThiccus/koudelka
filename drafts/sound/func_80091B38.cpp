#include "pre.h"
// NONMATCH: 6 diffs, a/b registers swapped (a1/v1)
EXTERN_C unsigned char *func_80091B38(void *t, void *drv, unsigned char *p)
{
    short a = p[0];
    short b = p[1];
    short q = 0xC0 / a;

    FIELD_AT(t, short, 0x64) = a;
    FIELD_AT(t, short, 0x60) = b;
    FIELD_AT(t, short, 0x66) = b;
    FIELD_AT(t, short, 0x62) = q;
    FIELD_AT(t, short, 0x5E) = q;
    return p + 2;
}
