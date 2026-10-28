// func_800DB978:
// MATCHES (0 differing) but can't land yet: its jump table's retail address lies in 0x800D61B0-0x800D6528, where
// tables are 8-aligned absolutely; effect.cpp's rodata starts at 0x800D5DAC (4 mod 8) and GCC aligns compiled
// tables to 8 within the unit, so the table lands 4 bytes off. Needs EFFECT split at the original file boundary.
#include "common.h"
#include "effect/effect.h"

EXTERN_C Vec4 func_800DBD1C(Vec4 *a, Vec4 *b);

EXTERN_C void func_800DB978(void *self, short kind, short sub, void *a, void *b)
{
    Vec4 pa;
    Vec4 pb;
    Vec4 t;
    if (a)
        pa = FIELD_AT(FIELD_AT(a, void *, 0x1B8), Vec4, 0x34);
    else
        vec4_zero(&pa);
    if (b) {
        pb = FIELD_AT(FIELD_AT(b, void *, 0x1B8), Vec4, 0x34);
    } else {
        pb.x = 0;
        pb.y = 0;
        pb.z = 0;
        pb.w = 0;
    }
    FIELD_AT(self, short, 0x166) = kind;
    FIELD_AT(self, short, 0x168) = sub + 1;
    switch (FIELD_AT(self, short, 0x166)) {
    case 1:
    case 2:
    case 3:
    case 10:
        FIELD_AT(self, Vec4, 0x16C) = pb;
        break;
    case 4: {
        t = func_800DBD1C(&pa, &Vec4(0, 0, -0x2EE0, 0));
        pa = t;
        if (pa.z < -0x1C20)
            pa.z = -0x1C20;
        FIELD_AT(self, Vec4, 0x16C) = pa;
        break;
    }
    case 5: {
        t = func_800DBD1C(&pa, &Vec4(0x960, 0, -0x960, 0));
        pa = t;
        if (pa.x > 0x12C0)
            pa.x = 0x12C0;
        if (pa.z < -0x1C20)
            pa.z = -0x1C20;
        FIELD_AT(self, Vec4, 0x16C) = pa;
        break;
    }
    case 6: {
        t = func_800DBD1C(&pa, &Vec4(-0x960, 0, -0x960, 0));
        pa = t;
        if (pa.x < -0x12C0)
            pa.x = -0x12C0;
        if (pa.z < -0x1C20)
            pa.z = -0x1C20;
        FIELD_AT(self, Vec4, 0x16C) = pa;
        break;
    }
    case 7:
        t.x = 0;
        t.y = 0;
        t.z = 0;
        t.w = 0;
        FIELD_AT(self, Vec4, 0x16C) = t;
        break;
    case 8:
        FIELD_AT(self, Vec4, 0x16C) = pa;
        break;
    case 9: {
        t = func_800DBD1C(&pa, &Vec4(0, 0, -0x2EE0, 0));
        pa = t;
        if (pa.z < -0x1C20)
            pa.z = -0x1C20;
        FIELD_AT(self, Vec4, 0x16C) = pa;
        break;
    }
    case 11: {
        t = func_800DBD1C(&pa, &Vec4(0, 0, -0x960, 0));
        pa = t;
        if (pa.z < -0x1C20)
            pa.z = -0x1C20;
        FIELD_AT(self, Vec4, 0x16C) = pa;
        break;
    }
    }
}
