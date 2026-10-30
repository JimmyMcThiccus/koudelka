// Shared by 2 BIM.AR modules: selector: 7818 effect, then the f9C8/flag tests and the handler chain.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int bimf_5bce61f8_c(void *p, unsigned *flags) asm("bimf_5bce61f8");
EXTERN_C int bimf_06b4d1a5_c(void *p, unsigned *flags) asm("bimf_06b4d1a5");
EXTERN_C int bimf_b4962b94_c(void *p, unsigned *flags) asm("bimf_b4962b94");
EXTERN_C int bimf_dd77db6b_c(void *p, unsigned *flags) asm("bimf_dd77db6b");
EXTERN_C int bimf_e310b46d_c(void *p, unsigned *flags) asm("bimf_e310b46d");

EXTERN_C int bimf_6d10f24e(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 700, 300, 0, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    int c = p->f9CC;
    if (c >= 2 && !*(int *)((char *)p + 0x9FC)) {
        *(int *)((char *)p + 0x9FC) = c & 3;
        p->f9CC = 0;
    }
    if (bimf_5bce61f8_c(p, flags))
        return 1;
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (bimf_06b4d1a5_c(p, flags))
        return 1;
    if (bimf_b4962b94_c(p, flags))
        return 1;
    if (bimf_dd77db6b_c(p, flags))
        return 1;
    bimf_e310b46d_c(p, flags);
    return 1;
}
