// Shared by 3 BIM.AR modules: bit 1 of *flags: 7818 effect, then up to three tries (8E64 2 / 3 / 1) at move
// (f9C8 % 3 + 1) or a 0x421 action, the first two only while !func_800D8350(p, 2) and falling back to 0x21 on bit 0.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_f35df0eb(BimCnt *p, unsigned *flags)
{
    void *s;
    if (!(*flags & 2))
        return 0;
    func_800D7818(p, 400, 300, 300, 0, 0, 0, 0, 0);
    if (!func_800D8350_b(p, 2)) {
        func_800D8E64(p, 2);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        s = (void *)func_800D7ECC(p, p->f9C8 % 3 + 1);
        if (!s) {
            s = func_800D7A4C(p, 1, 0x421);
            if (s) {
                if (!(func_800D7A78(p, s) & 0x10))
                    goto try3;
                if (!func_800D7D64(p, s))
                    goto try3;
                goto clear2;
            } else if (*flags & 1) {
                s = func_800D7A4C(p, 1, 0x21);
                if (s) {
                    func_800D7BB4(p, (int)s, 0, 0);
                    *flags &= ~1;
                    return 1;
                }
            }
        } else if (func_800D7A78(p, s) & 0x10) {
            if (func_800D7D64(p, s))
                goto clear2;
        }
    }
try3:
    if (!func_800D8350_b(p, 2)) {
        func_800D8E64(p, 3);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        s = (void *)func_800D7ECC(p, p->f9C8 % 3 + 1);
        if (!s) {
            s = func_800D7A4C(p, 2, 0x421);
            if (s) {
                if (!(func_800D7A78(p, s) & 0x10))
                    goto try1;
                if (!func_800D7D64(p, s))
                    goto try1;
                goto clear2;
            } else if (*flags & 1) {
                s = func_800D7A4C(p, 1, 0x21);
                if (s) {
                    func_800D7BB4(p, (int)s, 0, 0);
                    *flags &= ~1;
                    return 1;
                }
            }
        } else if (func_800D7A78(p, s) & 0x10) {
            if (func_800D7D64(p, s))
                goto clear2;
        }
    }
try1:
    func_800D8E64(p, 1);
    func_800D7A20(p, 5);
    func_800D7A20(p, 0);
    s = (void *)func_800D7ECC(p, p->f9C8 % 3 + 1);
    if (!s) {
        s = func_800D7A4C(p, 2, 0x421);
        if (!s)
            return 0;
    }
    if (func_800D7A78(p, s) & 0x10) {
        if (func_800D7D64(p, s)) {
clear2:
            *flags &= ~2;
            return 1;
        }
    }
    return 0;
}
