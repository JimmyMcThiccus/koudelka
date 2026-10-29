// Shared by 3 BIM.AR modules: bit 1 of *flags: kick off a 0x258/0x190 effect, virtual call 21, start the 0x421 action.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_eb1719f4(BimV *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D7818(p, 0x258, 0, 0x190, 0, 0, 0, 0, 0);
        p->v21(-1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        void *q = func_800D7A4C(p, 1, 0x421);
        if (q && func_800D7D64(p, q)) {
            *flags &= ~2;
            return 1;
        }
    }
    return 0;
}
