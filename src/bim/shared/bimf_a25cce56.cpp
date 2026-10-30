// Shared by 2 BIM.AR modules: command handler (bimf_e310b46d / bimf_dd77db6b shape): 7818 effect, then bit 1 or bit 0 of *flags picks the 0x421 / 0x121 / 0x21 action.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_a25cce56(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 600, 400, 0, 0, 0, 0, 0, 0);
    func_800D8E64(p, -1);
    func_800D7A20(p, 5);
    func_800D7A20(p, 0);
    unsigned f = *flags;
    if (f & 2) {
        void *q = func_800D7A4C(p, 1, 0x421);
        if (!q)
            return 0;
        func_800D7D64(p, q);
        *flags &= ~2;
        p->f9F0 = 0x10;
        return 1;
    } else if (f & 1) {
        void *q = func_800D7A4C(p, 1, 0x121);
        if (q) {
            int r = 1;
            func_800D7AC4(p, q, 1, 0);
            p->f9F0 = r;
            *flags &= ~1;
            return r;
        }
        q = func_800D7A4C(p, 1, 0x21);
        if (!q)
            return 0;
        func_800D7BB4(p, (int)q, 1, 0);
        *flags &= ~1;
        return 1;
    }
    return 0;
}
