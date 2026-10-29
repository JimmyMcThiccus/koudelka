// Shared by 3 BIM.AR modules: command handler (bit 1 starts a counted move; bit 0 picks a random slot, 0x21 or 0x421 action).
// The redundant `p || flags` test only keeps two `return 0` exits as separate blocks (found with the permuter).
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_7209819a(BimCnt *p, unsigned *flags)
{
    void *s;
    if (!(*flags & 2))
        return 0;
    func_800D8E64(p, 1);
    func_800D7A20(p, 5);
    func_800D7A20(p, 0);
    if (!(*flags & 1))
        s = func_800D7A4C(p, 2, 0x421);
    else
        s = (void *)func_800D7ECC(p, (p->f9C8 + rand()) % 3 + 1);
    if (!s) {
        if (!(*flags & 1))
            return 0;
        s = func_800D7A4C(p, 1, 0x21);
        if (!s) {
            if (p || flags)
                return 0;
            else
                return 0;
        }
        func_800D7BB4(p, (int)s, 0, 0);
        *flags &= ~1;
        return 1;
    }
    int r = func_800D7A78(p, s);
    if (r & 0x10) {
        if (!func_800D7D64(p, s))
            return 0;
        *flags &= ~2;
        return 1;
    }
    if (!(*flags & 1))
        return 0;
    if (!(r & 4))
        return 0;
    func_800D7BB4(p, (int)s, 0, 0);
    *flags &= ~1;
    return 1;
}
