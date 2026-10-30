// Shared by 2 BIM.AR modules: bit 1 of *flags: 7818 effect, then the 0x421 action when 8E64 gave 1 (or 2, with
// func_800D81FC(p, 3) first); bit 0: the 0x121 / 0x21 actions as in bimf_dd77db6b. One q for both halves keeps it in $s0.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void func_800D81FC_t(void *p, int a) asm("func_800D81FC");

EXTERN_C int bimf_8b808450(BimMon *p, unsigned *flags)
{
    void *q;
    unsigned f = *flags;
    if (f & 2) {
        func_800D7818(p, 0x2BC, 0x12C, 0, 0, 0, 0, 0, 0);
        int r = func_800D8E64(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        q = func_800D7A4C(p, 1, 0x421);
        if (q) {
            switch (r) {
            case 1:
                func_800D7D64(p, q);
                *flags &= ~2;
                return 1;
            case 2:
                func_800D81FC_t(p, 3);
                func_800D7D64(p, q);
                *flags &= ~2;
                return 1;
            }
            return 0;
        }
    } else if (f & 1) {
        q = func_800D7A4C(p, 1, 0x121);
        if (q) {
            if (func_800D7AC4(p, q, 0, 0)) {
                int r = 1;
                p->f9F0 = r;
                *flags &= ~1;
                return r;
            }
        }
        q = func_800D7A4C(p, 1, 0x21);
        if (q) {
            if (func_800D7BB4(p, (int)q, 0, 0)) {
                *flags &= ~1;
                return 1;
            }
        }
    }
    return 0;
}
