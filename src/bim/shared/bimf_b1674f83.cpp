// Shared by 3 BIM.AR modules: selector: 7818 effect, then the f9C8/flag tests and the handler chain.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int func_800D8CC0(void *p, unsigned *flags);
EXTERN_C void func_800D8C0C(void *p);
EXTERN_C int bimf_1393ddd0_c(void *p, unsigned *flags) asm("bimf_1393ddd0");
EXTERN_C int bimf_51caf7a0_c(void *p, unsigned *flags) asm("bimf_51caf7a0");
EXTERN_C int bimf_ad7de1b4_c(void *p, unsigned *flags) asm("bimf_ad7de1b4");
EXTERN_C int bimf_6eb48601_c(void *p, unsigned *flags) asm("bimf_6eb48601");

EXTERN_C int bimf_b1674f83(BimMon *p, unsigned *flags)
{
    func_800D7818(p, 400, 200, 400, 0, 0, 0, 0, 0);
    if (((BimV *)p)->v21((int)flags))
        return 1;
    if (func_800D84C8(p)) {
        if (func_800D8350(p, 2)) {
            if (bimf_1393ddd0_c(p, flags))
                return 1;
        }
    }
    if (bimf_51caf7a0_c(p, flags))
        return 1;
    if (bimf_ad7de1b4_c(p, flags))
        return 1;
    bimf_6eb48601_c(p, flags);
    return 1;
}
