// Shared by 20 BIM.AR modules: like bimf_dd77db6b, but falls back to clearing bit 1 / bit 0 of *flags when nothing started.
#include "common.h"
#include "bim/shared.h"

static inline int bimf_e310b46d_tail(unsigned *flags)
{
    unsigned f = *flags;
    int ret;
    if (f & 2) {
        *flags = f & ~2;
        return 1;
    }
    ret = f & 1;
    if (ret) {
        *flags = f & ~1;
        ret = 1;
    }
    return ret;
}

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
            int r = 1;
            func_800D7AC4(p, q, 0, 0);
            p->f9F0 = r;
            *flags &= ~1;
            return r;
        }
        q = func_800D7A4C(p, 1, 0x21);
        if (q) {
            func_800D7BB4(p, (int)q, 0, 0);
            *flags &= ~1;
            return 1;
        }
    }
    return bimf_e310b46d_tail(flags);
}
