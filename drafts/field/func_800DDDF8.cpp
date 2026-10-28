// func_800DDDF8: matches as a function (0 differing instructions), but its switch jump table
// (jtbl_800B9A2C) sits at a 4-aligned, not 8-aligned, rodata address; the compiler's table gets
// padded to 8 and FIELD grows by 8 bytes. Needs a rodata layout fix outside field's files.
#include "field/field.h"

EXTERN_C int D_800AF410[];
EXTERN_C int D_800AF40C[];
EXTERN_C void func_8006F154();

EXTERN_C int func_800DDDF8() {
    switch (D_800AF410[0]) {
    case 1:
    case 3:
        func_8006F154();
        return 1;
    case 2:
    case 4:
    case 5:
    case 6:
        D_800AF40C[0] = 0;
        break;
    default:
        return 0;
    }
    return 1;
}
