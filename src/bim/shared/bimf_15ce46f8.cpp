// Shared by 3 BIM.AR modules: per-frame counter step; when the countdown at +0xAE8 runs out, reload it with 6..9.
#include "common.h"
#include "bim/shared.h"

EXTERN_C void bimf_15ce46f8(BimCnt *p)
{
    if (func_800D83D4_a(p)) {
        p->f9C8++;
        p->fAE8--;
    }
    if (p->fAE8 <= 0) {
        p->fAEC = 1;
        p->fAE8 = rand() % 4 + 6;
    }
    p->f9CC = 0;
}
