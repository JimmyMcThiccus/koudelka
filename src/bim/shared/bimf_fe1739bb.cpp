// Shared by 2 BIM.AR modules: selector: 7818 effect, then the f9C8/flag tests and the handler chain.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int bimf_06b4d1a5_c(void *p, unsigned *flags) asm("bimf_06b4d1a5");
EXTERN_C int bimf_050d93e7_c(void *p, unsigned *flags) asm("bimf_050d93e7");
EXTERN_C int bimf_a1b3cda8_c(void *p, unsigned *flags) asm("bimf_a1b3cda8");
EXTERN_C int bimf_b4962b94_c(void *p, unsigned *flags) asm("bimf_b4962b94");
EXTERN_C int bimf_a25cce56_c(void *p, unsigned *flags) asm("bimf_a25cce56");
EXTERN_C int bimf_9421c4d7_c(void *p, unsigned *flags) asm("bimf_9421c4d7");

EXTERN_C int bimf_fe1739bb(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 600, 400, 0, 0, 0, 0, 0, 0);
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (bimf_06b4d1a5_c(p, flags))
        return 1;
    if (func_800D84C8(p)) {
        if (func_800D8350(p, 3)) {
            if ((*flags & 2) && bimf_050d93e7_c(p, flags) && !p->f9F0) {
                p->f9F0 = 0x10;
                return 1;
            }
            if ((*flags & 1) && bimf_a1b3cda8_c(p, flags))
                return 1;
        }
    }
    if (bimf_b4962b94_c(p, flags))
        return 1;
    if (bimf_a25cce56_c(p, flags)) {
        if (p || flags)
            return 1;
        else
            return 1;
    }
    return bimf_9421c4d7_c(p, flags);
}
