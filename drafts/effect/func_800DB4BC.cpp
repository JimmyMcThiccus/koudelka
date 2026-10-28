// func_800DB4BC: MATCHES (0 differing) but can't land: its jump table must sit at 0x800D61C8, which is 8-aligned
// absolutely, while effect.cpp's rodata starts at 0x800D5DAC (4 mod 8); GCC's .align 3 puts it 4 bytes late.
// Needs EFFECT split into units at the original file boundary (rodata 0x800D654C / text 0x800E01B0).
#include "common.h"
#include "effect/effect.h"

EXTERN_C void func_80099C80(int a);
EXTERN_C void func_800DB788(SlotSet *self, SVec4 *ang, Vec4 *pos);

typedef void (*Fn_800DB4BC)(void *, SVec4 *, Vec4 *);

EXTERN_C void func_800DB4BC(SlotSet *self)
{
    Vec4 pos;
    SVec4 ang;
    int code;
    vec4_zero(&pos);
    ang.x = 0;
    ang.y = 0;
    ang.z = 0;
    ang.w = 0;
    if (FIELD_AT(self, signed char, 0x165))
        return;
    FIELD_AT(self, char, 0x165) = 1;
    pos = FIELD_AT(self, Vec4, 0x16C);
    ang.z = 0;
    code = 0x203;
    switch ((short)(FIELD_AT(self, short, 0x166) - 1)) {
    case 0:
    case 9:
        switch (FIELD_AT(self, short, 0x168)) {
        case 1:
            func_800DB788(self, &ang, &pos);
            code = 0x15E;
            break;
        case 2:
            ang.x = -0xA3;
            ang.y = -0x608;
            pos.x += 0x2137;
            pos.y += -0x1019;
            pos.z += 0x2224;
            break;
        case 3:
            ang.x = -0xA3;
            ang.y = -0x664;
            pos.x += 0x2AFE;
            pos.y += -0x18AD;
            pos.z += 0x3896;
            break;
        }
        break;
    case 2:
        switch (FIELD_AT(self, short, 0x168)) {
        case 1:
            func_800DB788(self, &ang, &pos);
            code = 0x15E;
            break;
        case 2:
            goto c7;
        case 3:
            ang.x = -0x15D;
            ang.y = 0x62B;
            pos.x += -0x280A;
            pos.y += -0x2692;
            pos.z += 0x2C99;
            break;
        }
        break;
    case 4:
        ang.x = -0x129;
        ang.y = -0x575;
        pos.x += -0x311B;
        pos.y += 0x1A6F;
        pos.z += 0x18E4;
        break;
    case 5:
        ang.x = -0xFB;
        ang.y = -0x524;
        pos.x += 0x31B4;
        pos.y += -0x158D;
        pos.z += 0x13F9;
        break;
    case 6:
    case 10:
        ang.x = -0x17D;
        ang.y = 0;
        pos.y += -0x3671;
        pos.z += -0x5235;
        break;
    case 7:
    c7:
        ang.x = -0xEB;
        ang.y = 0x659;
        pos.x += -0x1ADD;
        pos.y += -0x1438;
        pos.z += 0x2442;
        break;
    case 1:
    case 3:
    case 8:
        func_800DB788(self, &ang, &pos);
        code = 0x15E;
        break;
    }
    func_80099C80(code);
    void *p = D_800B4ED8[0];
    FIELD_AT(p, int, 0x11C) = code;
    VtEntry *vt = FIELD_AT(p, VtEntry *, 0x2C);
    ((Fn_800DB4BC)vt[34].pfn)((char *)p + vt[34].delta, &ang, &pos);
}
