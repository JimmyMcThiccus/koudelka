// Shared by 2 BIM.AR modules: bit 1 of *flags: kick off a 0x2BC/0x12C effect, start the 0x421 action; ids 1 and 2 qualify.
// The redundant `p || q` test (both arms return 0; q may be unset there) only changes register allocation (permuter).
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_72fa68c8(void *p, unsigned *flags)
{
    int id;
    void *q;
    if (*flags & 2) {
        func_800D7818(p, 0x2BC, 0x12C, 0, 0, 0, 0, 0, 0);
        id = func_800D8E64(p, -1);
        func_800D7A20(p, 5);
        func_800D7A20(p, 0);
        q = func_800D7A4C(p, 1, 0x421);
        if (q) {
            if (id != 1) {
                if (id != 2)
                    return 0;
                func_800D81FC(p, 3);
            }
            if (func_800D7D64(p, q)) {
                *flags &= ~2;
                return 1;
            }
        }
    }
    if (p || q)
        return 0;
    else
        return 0;
}
