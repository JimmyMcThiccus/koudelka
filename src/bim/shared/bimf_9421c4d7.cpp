// Shared by 2 BIM.AR modules: as bimf_e310b46d with the 0x121 / 0x21 actions started with argument 1; bit 1 or bit 0 of *flags picks the 0x421 / 0x121 / 0x21 action,
// and failing that the bit is just cleared. With neither bit set it falls off the end (no return
// statement), returning the f & 1 test's 0 in $v0; a final 'return 0' doesn't match.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_9421c4d7(BimMon *p, unsigned *flags)
{
    func_800D8E64(p, -1);
    func_800D7A20(p, 5);
    func_800D7A20(p, 0);
    if (*flags & 2) {
        void *q = func_800D7A4C(p, 1, 0x421);
        if (q) {
            func_800D7D64(p, q);
            *flags &= ~2;
            return 1;
        }
    }
    if (*flags & 1) {
        void *q = func_800D7A4C(p, 1, 0x121);
        if (q) {
            int r = 1;
            func_800D7AC4(p, q, 1, 0);
            p->f9F0 = r;
            *flags &= ~1;
            return r;
        }
        q = func_800D7A4C(p, 1, 0x21);
        if (q) {
            func_800D7BB4(p, (int)q, 1, 0);
            *flags &= ~1;
            return 1;
        }
    }
    unsigned f = *flags;
    if (f & 2) {
        *flags = f & ~2;
        return 1;
    }
    if (f & 1) {
        *flags = f & ~1;
        return 1;
    }
}
