// Shared by 2 BIM.AR modules: bit 1 of *flags: 7818 effect, then start move (f9C8 % 3 + 1) if usable, else the 0x421
// action (func_800D81FC(p, 3) first when 8E64 gave 2); with neither, on bit 0 and a 0x121 action, func_800D7C7C(p, 3, 0).
#include "common.h"
#include "bim/shared.h"

EXTERN_C void func_800D81FC_t(void *p, int a) asm("func_800D81FC");

EXTERN_C int bimf_da437c5e(BimCnt *p, unsigned *flags)
{
    if (!(*flags & 2))
        return 0;
    func_800D7818(p, 0x2BC, 0x12C, 0, 0, 0, 0, 0, 0);
    int r = func_800D8E64(p, -1);
    func_800D7A20(p, 5);
    func_800D7A20(p, 0);
    void *s = (void *)func_800D7ECC(p, p->f9C8 % 3 + 1);
    if (!s) {
        s = func_800D7A4C(p, 2, 0x421);
        if (!s) {
            if (!func_800D7A4C(p, 2, 0x121))
                return 0;
            if (!(*flags & 1))
                return 0;
            if (!func_800D7C7C_i(p, 3, 0))
                return 0;
            *flags &= ~1;
            return 1;
        }
    } else if (!(func_800D7A78(p, s) & 0x10))
        return 0;
    if (r == 2)
        func_800D81FC_t(p, 3);
    if (!func_800D7D64(p, s))
        return 0;
    *flags &= ~2;
    return 1;
}
