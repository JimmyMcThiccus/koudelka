// Shared by 3 BIM.AR modules: bit 1 of *flags: kick off a 0/0x1F4 effect, virtual call 21 must not answer 4, start the 0x421 action.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_096f4279(BimV *p, unsigned *flags)
{
    if (*flags & 2) {
        func_800D7818(p, 0, 0x1F4, 0x1F4, 0, 0, 0, 0, 0);
        int id = p->v21(-1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        switch (id) {
        case 1:
        case 2:
        case 3:
            break;
        case 4:
            return 0;
        }
        void *q = func_800D7A4C(p, 2, 0x421);
        if (q && func_800D7D64(p, q)) {
            *flags &= ~2;
            return 1;
        }
    }
    return 0;
}
