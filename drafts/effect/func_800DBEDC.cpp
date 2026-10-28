// func_800DBEDC:
// MATCHES (0 differing) but can't land yet: its jump table's retail address lies in 0x800D61B0-0x800D6528, where
// tables are 8-aligned absolutely; effect.cpp's rodata starts at 0x800D5DAC (4 mod 8) and GCC aligns compiled
// tables to 8 within the unit, so the table lands 4 bytes off. Needs EFFECT split at the original file boundary.
#include "common.h"
#include "effect/effect.h"

EXTERN_C int func_8003912C(void *p, int n);
EXTERN_C Vec4 func_8003A150(int h, int n);

EXTERN_C void func_800DBEDC(void *self, void *a, void *b)
{
    int h;
    switch (FIELD_AT(self, signed char, 0x2)) {
    case 0:
    case 3:
        break;
    case 1:
    case 4:
        h = func_8003912C(FIELD_AT(a, void *, 0x1B8), 5);
        if (h)
            FIELD_AT(self, Vec4, 0x4) = func_8003A150(h, 0);
        h = func_8003912C(FIELD_AT(b, void *, 0x1B8), 5);
        if (h)
            FIELD_AT(self, Vec4, 0x14) = func_8003A150(h, 0);
        break;
    case 2:
    case 5:
        h = func_8003912C(FIELD_AT(b, void *, 0x1B8), 5);
        if (h)
            FIELD_AT(self, Vec4, 0x4) = func_8003A150(h, 0);
        h = func_8003912C(FIELD_AT(a, void *, 0x1B8), 5);
        if (h)
            FIELD_AT(self, Vec4, 0x14) = func_8003A150(h, 0);
        break;
    }
    if (a == b) {
        if (FIELD_AT(a, signed char, 0x4BC) >= 3)
            FIELD_AT(self, int, 0x1C) -= 0x960;
        else
            FIELD_AT(self, int, 0x1C) += 0x960;
    }
    if (FIELD_AT(self, signed char, 0x2)) {
        VtEntry *vt = FIELD_AT(self, VtEntry *, 0x28);
        ((void (*)(void *))vt[4].pfn)((char *)self + vt[4].delta);
    } else {
        VtEntry *vt = FIELD_AT(self, VtEntry *, 0x28);
        ((void (*)(void *))vt[5].pfn)((char *)self + vt[5].delta);
    }
}
