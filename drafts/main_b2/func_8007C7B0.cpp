// func_8007C7B0: 119 differing instructions (built 436 bytes, retail 500).
// Retail keeps three full copies of the 'func_8007AFD0(self ? self+0xB8 : 0, p)' tail per case and hoists the constant 1 into $s4; we cross-jump the cases together. The 16-byte zero vector is passed by reference (class with ctor, 'const Z4 &').
// needs D_8001705C/D_80017068/D_80017070 kept with force_not_migration if landed.
#include "common.h"
EXTERN_C const char D_8001705C[];
EXTERN_C const char D_80017068[];
EXTERN_C const char D_80017070[];
struct Z4_8007C7B0 {
    int a, b, c, d;
    Z4_8007C7B0() { a = 0; b = 0; c = 0; d = 0; }
};
EXTERN_C char *func_80072130(void *mem, int a, void *b, int id, const char *name, const Z4_8007C7B0 &v, int e);
//HDR_END
EXTERN_C void func_8007C7B0(void *self, int k)
{
    char *p;
    switch (k) {
    case 0:
        p = func_80072130(__builtin_new(0x5E8), 1, FIELD_AT(self, void *, 0x10C), 0, D_8001705C, Z4_8007C7B0(), 0);
        func_8007AFD0((Set_8007AFD0 *)(self ? (char *)self + 0xB8 : 0), (int)p);
        FIELD_AT(p, char, 0x4BC) = 0;
        break;
    case 1:
        p = func_80072130(__builtin_new(0x5E8), 1, FIELD_AT(self, void *, 0x10C), 1, D_80017068, Z4_8007C7B0(), 0);
        func_8007AFD0((Set_8007AFD0 *)(self ? (char *)self + 0xB8 : 0), (int)p);
        FIELD_AT(p, char, 0x4BC) = 1;
        break;
    case 2:
        p = func_80072130(__builtin_new(0x5E8), 1, FIELD_AT(self, void *, 0x10C), 2, D_80017070, Z4_8007C7B0(), 0);
        func_8007AFD0((Set_8007AFD0 *)(self ? (char *)self + 0xB8 : 0), (int)p);
        FIELD_AT(p, char, 0x4BC) = k;
        break;
    default:
        return;
    }
    FIELD_AT(p, char, 0x4BD) = 1;
    func_800824C8(p + 0x2A4, 1);
    func_800825FC(p + 0x2A4, 0);
    func_80084824(p, 0);
    func_8001E848(FIELD_AT(self, void *, 0x10C), p);
}
