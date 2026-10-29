// Shared by 14 BIM.AR modules: command handler; bit 1 or bit 0 of *flags picks the 0x421 / 0x121 / 0x21 action.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_0ae2aad9(BimMon *p, unsigned *flags)
{
    func_800D8E64(p, 1);
    func_800D7A20(p, 5);
    func_800D7A20(p, 0);
    unsigned f = *flags;
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
            int r = 1;
            func_800D7AC4(p, q, 0, 0);
            p->f9F0 = r;
            *flags &= ~1;
            return r;
        }
        q = func_800D7A4C(p, 1, 0x21);
        if (!q)
            return 0;
        func_800D7BB4(p, (int)q, 0, 0);
        *flags &= ~1;
        return 1;
    }
    return 0;
}
