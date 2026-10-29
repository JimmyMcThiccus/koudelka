// Shared by 3 BIM.AR modules: finish the 'pending 1' state at +0x9F0 via bimf_096f4279, else reset the state.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_096f4279_c(void *p, unsigned *flags) asm("bimf_096f4279");

EXTERN_C int bimf_fddfe66d(BimMon *p, unsigned *flags)
{
    if (p->f9F0 == 1) {
        if (bimf_096f4279_c(p, flags)) {
            p->f9F0 = 0;
            *flags &= ~2;
            return 1;
        }
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}
