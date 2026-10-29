#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_e310b46d(BimMon *p, unsigned *flags)
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
            func_800D7AC4(p, q, 0, 0);
            p->f9F0 = 1;
            *flags &= ~1;
            return 1;
        }
        q = func_800D7A4C(p, 1, 0x21);
        if (q) {
            func_800D7BB4(p, (int)q, 0, 0);
            *flags &= ~1;
            return 1;
        }
    }
    unsigned f = *flags;
    int ret;
    if (f & 2) {
        *flags = f & ~2;
        ret = 1;
    } else {
        ret = f & 1;
        if (ret) {
            *flags = f & ~1;
            ret = 1;
        }
    }
    return ret;
}
