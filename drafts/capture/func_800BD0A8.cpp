// func_800BD0A8: constructor, 12 differ. Retail loads the three stack arguments after the third vtable
// store; GCC here hoists them to the top. Store sequence and offsets are right.
#include "common.h"

// func_800BD0A8
EXTERN_C char D_80010348[];
EXTERN_C char D_800100F8[];
EXTERN_C char D_80010198[];
EXTERN_C char D_800101C0[];
EXTERN_C char D_800101B0[];
EXTERN_C char D_800B7274[];
EXTERN_C char D_800B728C[];
EXTERN_C char D_800B729C[];
// (tried) static inline void init_800BD0A8(char *q, int a, short b, short c, short d, short e)
{
    *(char **)q = D_800100F8;
    *(char **)(q + 4) = D_80010198;
    *(char **)(q + 4) = D_800101C0;
    *(char **)q = D_800101B0;
    *(int *)(q + 8) = a;
    *(short *)(q + 0x12) = b;
    *(short *)(q + 0xC) = c;
    *(short *)(q + 0xE) = d;
    *(short *)(q + 0x10) = e;
}
EXTERN_C char *func_800BD0A8(char *p, int unused, int a, short b, short c, short d, short e)
{
    *(char **)p = D_80010348;
    init_800BD0A8(p + 4, a, b, c, d, e);
    *(char **)(p + 8) = D_800B7274;
    *(char **)(p + 4) = D_800B728C;
    *(char **)p = D_800B729C;
    *(int *)(p + 0x28) = 0;
    *(int *)(p + 0x2C) = 0;
    return p;
}
