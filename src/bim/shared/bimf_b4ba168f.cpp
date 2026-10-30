// Shared by 2 BIM.AR modules: selector: 7818 effect, then the f9C8/flag tests and the handler chain.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int bimf_af99c5b3_3_c(void *p, unsigned *flags) asm("bimf_af99c5b3_3");
EXTERN_C int bimf_72fa68c8_c(void *p, unsigned *flags) asm("bimf_72fa68c8");
EXTERN_C int bimf_0d32b1e3_c(void *p, unsigned *flags) asm("bimf_0d32b1e3");
EXTERN_C int bimf_da437c5e_c(void *p, unsigned *flags) asm("bimf_da437c5e");
EXTERN_C int bimf_8b808450_c(void *p, unsigned *flags) asm("bimf_8b808450");
EXTERN_C int bimf_05e090a7_c(void *p, unsigned *flags) asm("bimf_05e090a7");

EXTERN_C int bimf_b4ba168f(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 700, 300, 0, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    func_800D8C0C(p);
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (bimf_af99c5b3_3_c(p, flags))
        return 1;
    if (func_800D84C8(p)) {
        if (func_800D8350(p, 3)) {
            if ((*flags & 2) && bimf_72fa68c8_c(p, flags) && !p->f9F0) {
                p->f9F0 = 0x10;
                return 1;
            }
            if ((*flags & 1) && bimf_0d32b1e3_c(p, flags))
                return 1;
        }
    }
    if (bimf_da437c5e_c(p, flags))
        return 1;
    if (bimf_8b808450_c(p, flags))
        return 1;
    bimf_05e090a7_c(p, flags);
    return 1;
}
