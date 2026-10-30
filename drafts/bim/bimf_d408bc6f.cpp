// NEAR (2 differing, 3 copies): retail 'beqz s0, <return 0>; j <D64>' after the case 2/3 0x421 fallback; ours inverts
// to 'bnez s0, <D64>; j END; v0 = 0'. goto-fail (which fixed bimf_51caf7a0) swaps the blocks here. Permuter: 30 min, nothing.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_d408bc6f(BimCnt *p, unsigned *flags)
{
    void *s;
    if (!(*flags & 2))
        return 0;
    if (p->fAEC)
        func_800D7818(p, 0x2BC, 0xC8, 0x64, 0, 0, 0, 0, 0);
    else
        func_800D7818(p, 0, 0x1F4, 0x1F4, 0, 0, 0, 0, 0);
    int r = ((BimV *)p)->v21(-1);
    func_800D7A20(p, 5);
    func_800D7A20(p, 0);
    switch (r) {
    case 1: {
        int x = rand() * 99 >> 2;
        if (x != x / 2 * 2) {
        s = (void *)func_800D7ECC(p, p->f9C8 % 3 + 4);
        if (!s) {
            s = func_800D7A4C(p, 2, 0x411);
            if (!s)
                return 0;
            if (!func_800D7D64(p, s))
                return 0;
            p->fAEC = 0;
            *flags &= ~2;
            return 1;
        }
        if (!(func_800D7A78(p, s) & 0x10))
            return 0;
        if (!func_800D7D64(p, s))
            return 0;
        p->fAEC = 0;
            *flags &= ~2;
            return 1;
        }
        s = (void *)func_800D7ECC(p, p->f9C8 % 3 + 1);
        if (!s) {
            s = func_800D7A4C(p, 2, 0x421);
            if (!s)
                return 0;
            if (!func_800D7D64(p, s))
                return 0;
            p->fAEC = 0;
            *flags &= ~2;
            return 1;
        }
        if (!(func_800D7A78(p, s) & 0x10))
            return 0;
        if (!func_800D7D64(p, s))
            return 0;
        p->fAEC = 0;
            *flags &= ~2;
            return 1;
    }
    case 2:
    case 3:
        s = (void *)func_800D7ECC(p, p->f9C8 % 3 + 1);
        if (!s) {
            s = func_800D7A4C(p, 2, 0x421);
            if (!s)
                return 0;
        } else if (!(func_800D7A78(p, s) & 0x10))
            return 0;
        if (!func_800D7D64(p, s))
            return 0;
        *flags &= ~2;
        return 1;
    }
    return 0;
}
