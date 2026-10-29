// func_800D81BC: 15 differing instructions. Retail copies $a1 to $a2 first (addu $a2,$a1,$zero), then stores
// 1 to +0x4E5 and $a2 to +0x4E6; every plain form (int/char/unsigned char param, inline helper, local copy) keeps $a1.
#include "common.h"
#include "shared/exe.h"
#include "bim/bim.h"
EXTERN_C void func_800D81BC(BimMon *p, int a) {
    p->b4E5 = 1;
    p->b4E6 = a;
    func_800CDA94(D_800AF470[0]->f32C, p->b4BC - 3);
}
