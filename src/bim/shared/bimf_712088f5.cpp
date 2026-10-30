// Shared by 2 BIM.AR modules: selector: 7818 effect, then the f9C8/flag tests and the handler chain.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int bimf_06b4d1a5_c(void *p, unsigned *flags) asm("bimf_06b4d1a5");
EXTERN_C int bimf_67916de8_c(void *p, unsigned *flags) asm("bimf_67916de8");
EXTERN_C int bimf_4379dd60_c(void *p, unsigned *flags) asm("bimf_4379dd60");
EXTERN_C int bimf_7209819a_c(void *p, unsigned *flags) asm("bimf_7209819a");
EXTERN_C int bimf_6eb48601_c(void *p, unsigned *flags) asm("bimf_6eb48601");

EXTERN_C int bimf_712088f5(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 1000, 0, 0, 0, 0, 0, 0, 0);
    if (!(p->f9C8 > 0) && (*flags & 1) && func_800D8CC0(p, flags))
        return 1;
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (bimf_06b4d1a5_c(p, flags))
        return 1;
    if (func_800D84C8(p)) {
        if (func_800D8350(p, 3)) {
            if ((*flags & 2) && bimf_67916de8_c(p, flags) && !p->f9F0) {
                p->f9F0 = 0x10;
                return 1;
            }
            if ((*flags & 1) && bimf_4379dd60_c(p, flags))
                return 1;
        }
    }
    if (bimf_7209819a_c(p, flags))
        return 1;
    bimf_6eb48601_c(p, flags);
    return 1;
}
