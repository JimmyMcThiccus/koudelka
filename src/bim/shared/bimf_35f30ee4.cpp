// Shared by 2 BIM.AR modules: selector (7818 effect, 8CC0 test, vcall 21) whose 84C8 block, on an odd
// rand() * 99 >> 2, tries the 8634-selected move / 0x421 action on bit 1 and the 0x121 action on bit 0.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C int bimf_79606d43_c(void *p, unsigned *flags) asm("bimf_79606d43");
EXTERN_C int bimf_05e090a7_c(void *p, unsigned *flags) asm("bimf_05e090a7");

EXTERN_C int bimf_35f30ee4(BimMon *p, unsigned *flags)
{
    void *s;
    func_800D7818(p, 500, 200, 300, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (func_800D84C8(p)) {
        int x = rand() * 99 >> 2;
        if (x != x / 2 * 2) {
            if (*flags & 2) {
                func_800D8E64(p, 2);
                func_800D7A20(p, 5);
                func_800D7A20(p, 0);
                int a = func_800D8634(p);
                if (a != -1) {
                    s = (void *)func_800D7ECC(p, a);
                    if (!s) {
                        s = func_800D7A4C(p, 1, 0x421);
                        if (s) {
                            if (!func_800D7D64(p, s))
                                goto bit0;
                            *flags &= ~2;
                            return 1;
                        }
                        if (!(*flags & 1))
                            goto rest;
                        if (func_800D8064(p))
                            goto clear1;
                        s = func_800D7A4C(p, 1, 0x121);
                        if (!s)
                            goto bit0;
                        if (!func_800D7BB4(p, (int)s, 0, 0))
                            goto bit0;
                        goto clear1;
                    }
                    if (func_800D7A78(p, s) & 0x10) {
                        if (!func_800D7D64(p, s))
                            goto bit0;
                        *flags &= ~2;
                        return 1;
                    }
                    if (!(*flags & 1))
                        goto rest;
                    s = func_800D7A4C(p, 1, 0x121);
                    if (!s)
                        goto bit0;
                    if (func_800D7BB4(p, (int)s, 0, 0))
                        goto clear1;
                }
            }
        bit0:
            if (*flags & 1) {
                s = func_800D7A4C(p, 1, 0x121);
                if (s) {
                    if (func_800D7BB4(p, (int)s, 0, 0)) {
                    clear1:
                        *flags &= ~1;
                        return 1;
                    }
                }
            }
        }
    }
rest:
    if (bimf_79606d43_c(p, flags))
        return 1;
    bimf_05e090a7_c(p, flags);
    return 1;
}
