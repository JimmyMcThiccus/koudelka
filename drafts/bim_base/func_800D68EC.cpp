// func_800D68EC: 5 differing instructions. D_800B4C18 as a plain pointer gives the macro form (lui $a0; lw $a0); retail wants the split form (lui $v0; lw $a0) un-hoisted from the loop, which the array form hoists.
#include "common.h"
#include "shared/exe.h"
#include "bim/bim.h"
EXTERN_C char *D_800B4C18p asm("D_800B4C18");
EXTERN_C void func_800D68EC(BimF18 *p) {
    if (p->f18) {
        unsigned t = D_800A4534.fC;
        while (D_800A4534.fC - t < 0x3D) {
            BimObj *o = (BimObj *)func_8001ED2C(D_800B4C18p, 1, 3);
            if (o) o->v1();
        }
        func_800D6D08(p->f18);
        p->f18 = 0;
        func_8001ED2C(D_800B4C18p, 1, 3);
    }
}
