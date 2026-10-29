#include "common.h"
#include "bim/shared.h"
EXTERN_C int bimf_131b36e3_c(void *p, unsigned *flags) asm("bimf_131b36e3");
EXTERN_C int bimf_af99c5b3_c(void *p, unsigned *flags) asm("bimf_af99c5b3");
EXTERN_C int bimf_af99c5b3_1_c(void *p, unsigned *flags) asm("bimf_af99c5b3_1");
EXTERN_C int bimf_af99c5b3_2_c(void *p, unsigned *flags) asm("bimf_af99c5b3_2");
EXTERN_C int func_800DB368_c(void *p, unsigned *flags) asm("func_800DB368");

EXTERN_C int func_800DB404(BimMon *p, unsigned *flags)
{
    switch (p->f9F0) {
    case 1:
        if (!bimf_131b36e3_c(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 2:
        if (!bimf_af99c5b3_c(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 4:
        if (!bimf_af99c5b3_1_c(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 8:
        if (!bimf_af99c5b3_2_c(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~1;
        return 1;
    case 16:
        if (!func_800DB368_c(p, flags))
            return 0;
        p->f9F0 = 0;
        return 1;
    }
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}
