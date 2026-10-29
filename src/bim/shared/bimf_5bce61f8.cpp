#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_5bce61f8(BimM9 *p, unsigned *flags)
{
    if (p->f9FC) {
        if (*flags & 2) {
            if (func_800D8E64(p, 1) == 1) {
                func_800D7A20(p, 5);
                func_800D7A20(p, 0);
                void *q = func_800D7A4C(p, 1, 0x421);
                if (q) {
                    func_800D7D64(p, q);
                    if (--p->f9FC == 0) {
                        *flags &= ~2;
                        p->f9F0 = 0x10;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}
