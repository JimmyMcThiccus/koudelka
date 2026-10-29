#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_dd77db6b(BimMon *p, unsigned *flags)
{
    func_800D8E64(p, -1);
    func_800D7A20(p, 5);
    func_800D7A20(p, 0);
    unsigned f = *flags;
    int ret;
    if (f & 2) {
        void *q = func_800D7A4C(p, 1, 0x421);
        if (!q)
            return 0;
        func_800D7D64(p, q);
        *flags &= ~2;
        return 1;
    } else if (f & 1) {
        void *q = func_800D7A4C(p, 1, 0x121);
        if (q) {
            func_800D7AC4(p, q, 0, 0);
            int t = 1; ret = t; p->f9F0 = t;
        } else {
            q = func_800D7A4C(p, 1, 0x21);
            if (!q)
                return 0;
            func_800D7BB4(p, (int)q, 0, 0);
            ret = 1;
        }
        *flags &= ~1;
        return ret;
    }
    return 0;
}
