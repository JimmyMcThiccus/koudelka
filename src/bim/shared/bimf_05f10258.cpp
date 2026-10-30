// Shared by 3 BIM.AR modules: bit 1 of *flags: 7818 effect; unless func_800D8350(p, 2), try vcall 21(3) + move
// (f9C8 % 3 + 1) / 0x421 action / (bit 0) 0x21 action; then vcall 21(1) + move / 0x421 (arg 2) / 0x21 action.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_05f10258(BimCnt *p, unsigned *flags)
{
    void *s;
    if (!(*flags & 2))
        return 0;
    func_800D7818(p, 500, 0, 500, 0, 0, 0, 0, 0);
    if (!func_800D8350_b(p, 2)) {
        ((BimV *)p)->v21(3);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        s = (void *)func_800D7ECC(p, p->f9C8 % 3 + 1);
        if (!s) {
            s = func_800D7A4C(p, 1, 0x421);
            if (s) {
                if (!(func_800D7A78(p, s) & 0x10))
                    goto second;
                if (!func_800D7D64(p, s))
                    goto second;
                goto clear2;
            } else if (*flags & 1) {
                s = func_800D7A4C(p, 1, 0x21);
                if (func_800D8064(p)) {
                    *flags &= ~1;
                    return 1;
                }
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
second:
    ((BimV *)p)->v21(1);
    func_800D7A20(p, 5);
    func_800D7A20(p, 0);
    s = (void *)func_800D7ECC(p, p->f9C8 % 3 + 1);
    if (!s) {
        s = func_800D7A4C(p, 2, 0x421);
        if (!s) {
            if (!(*flags & 1))
                return 0;
            s = func_800D7A4C(p, 1, 0x21);
            if (!s)
                return 0;
            func_800D7BB4(p, (int)s, 0, 0);
            *flags &= ~1;
            return 1;
        }
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
