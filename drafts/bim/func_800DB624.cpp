// NEAR (8 differing, w0_fb98fcc327): falls off the end like bimf_e310b46d on two paths; retail's f9E4 == 0
// 'return 0' is an out-of-line 'j END; v0 = 0' block after the handler call. Permuter: 30 min, best 200.
#include "common.h"
#include "bim/shared.h"

EXTERN_C BimMon *func_800D8464_t() asm("func_800D8464");
EXTERN_C int bimf_af99c5b3_3_t(BimMon *p, int a) asm("bimf_af99c5b3_3");

// No return on two paths (handler refused; no f9E8 / rand miss): retail returns whatever is left in $v0.
EXTERN_C int func_800DB624(BimMon *p, int a)
{
    BimMon *o = func_800D8464_t();
    if (o && o != p) {
        if (!(rand() & 1))
            return 0;
        if (!p->f9E4)
            return 0;
        if (bimf_af99c5b3_3_t(p, a))
            return 1;
    } else if (p->f9E8 && (rand() & 7) == 7) {
        p->f9EC = 1;
        return 0;
    }
}
