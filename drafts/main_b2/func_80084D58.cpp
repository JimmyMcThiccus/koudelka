// func_80084D58 (twin: func_80084F58 = same plus func_8007F4F4(D_800AF470, self) after case 10): 19 differing instructions.
// Switch shapes match (switch(t) {8,2,0x16}; inner switch case order 2,5,10,default; k kept in a1). Remaining: p (the func_8001CA10 result) lands in $v0 here but in $a1 in retail, and the 0x16-case k loads into $v1 (retail $a1), default's k-0xF is computed into a new reg.
#include "common.h"
EXTERN_C void func_80083268(void *self);
EXTERN_C void func_800832B0(void *self);
EXTERN_C void func_80082F5C(void *self);
EXTERN_C void func_80083360(void *self);
EXTERN_C void func_800832D0(void *self);
EXTERN_C int func_80084D58_d(void *self, void *m) asm("func_80084D58"); // exe.h has (void *, int) returning void
//HDR_END
EXTERN_C int func_80084D58_d(void *self, void *m)
{
    int t = FIELD_AT(m, unsigned short, 0xA);
    switch (t) {
    case 8: {
        int k = FIELD_AT(m, int, 0x10);
        switch (k) {
        case 2:
            func_80083268(self ? (char *)self + 0x2A0 : 0);
            break;
        case 3:
        case 4:
        case 6:
            break;
        case 5:
            func_8008316C(self ? (char *)self + 0x2A0 : 0);
            break;
        case 10:
            if (FIELD_AT(self, signed char, 0x4E0) != 0) {
                FIELD_AT(self, signed char, 0x4E0) = 0;
                func_800832B0(self ? (char *)self + 0x2A0 : 0);
            }
            break;
        default:
            if ((unsigned int)(k - 0xF) < 0x1F5) {
                func_80082F5C(self ? (char *)self + 0x2A0 : 0);
            }
            break;
        }
        break;
    }
    case 2: {
        int k = FIELD_AT(m, int, 0x10);
        switch (k) {
        case 0x1000:
            func_80083360(self ? (char *)self + 0x2A0 : 0);
            break;
        case 0xE: {
            int b = (FIELD_AT(self, signed char, 0x4BC) + 0x12) | 0x2000;
            MsgArg_B *p = new (func_8001CA10(0x14)) MsgArg_B(t, t, 0, b);
            func_8001EFE4(D_800AF470_w, p);
            break;
        }
        }
        break;
    }
    case 0x16: {
        int k = FIELD_AT(m, int, 0x10);
        if (k == 1) {
            if (FIELD_AT(self, signed char, 0x4E1) != 0) {
                FIELD_AT(self, signed char, 0x4E1) = 0;
                func_800832D0(self ? (char *)self + 0x2A0 : 0);
            }
        }
        break;
    }
    }
    return 0;
}
