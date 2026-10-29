#include "common.h"
#include "bim/shared.h"

EXTERN_C void *func_800DAAFC(void *self, int in_chrg, int a, int b, int c, int d, int e);

EXTERN_C void *func_800DAA80(int a, short b, int c, int d, int e)
{
    return func_800DAAFC(operator new(0xAF0), 1, a, b, c, d, e);
}

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DAAFC);

#include "../shared/bimf_3dafacd3.cpp"

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DADF4);

EXTERN_C int func_800DAF88(char *p)
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
        func_80082670(p + 0x2A4, 0x10, 7);
        func_80082670(p + 0x2A4, 0x11, 8);
        break;
    case 4:
        func_80082670(p + 0x2A4, 0x10, 0xE);
        func_80082670(p + 0x2A4, 0x11, 0xF);
        break;
    }
    return r;
}

#include "../shared/bimf_1a38796b.cpp"

#include "../shared/bimf_7434482e.cpp"

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DB134);

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DB1E8);

#include "../shared/bimf_af99c5b3.cpp"

#include "../shared/bimf_0d32b1e3.cpp"

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DB398);

#include "../shared/bimf_05e090a7.cpp"

INCLUDE_ASM("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", func_800DB4D4);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA86C);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA878);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA8C8);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA8E0);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA8F0);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA988);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA9A8);

INCLUDE_RODATA("asm/bim/w0_f6c694b75d/nonmatchings/w0_f6c694b75d", D_800DA9C0);
