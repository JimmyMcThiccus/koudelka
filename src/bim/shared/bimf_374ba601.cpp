// Shared by 3 BIM.AR modules: pick a state pair for the sub-object at +0x2A4 from func_800D8E64's result; returns it.
#include "common.h"
#include "bim/shared.h"

EXTERN_C int bimf_374ba601(char *p)
{
    int r = func_800D8E64_a(p);
    switch (r) {
    case 1:
        func_80082670(p + 0x2A4, 0x10, 7);
        func_80082670(p + 0x2A4, 0x11, 8);
        break;
    case 2:
        func_80082670(p + 0x2A4, 0x10, 7);
        func_80082670(p + 0x2A4, 0x11, 8);
        break;
    case 3:
        func_80082670(p + 0x2A4, 0x10, 0xD);
        func_80082670(p + 0x2A4, 0x11, 0xE);
        break;
    }
    return r;
}
