// func_800B9E10: 3 differ, toolchain: retail loads the 4-byte EXE global D_800B4D0C with `lui s0; lw s0,lo(s0)` (assembler macro, no $gp). A small extern becomes $gp-relative under tools/maspsx_extern.py; a big one makes GCC split with $v0 as the temp. Needs overlays assembled without the extern-$gp rule. Otherwise matches.
#include "common.h"
#include "capture/capture.h"

struct G_800B4D0C { char *obj; int pad[2]; };
EXTERN_C G_800B4D0C D_800B4D0C;
EXTERN_C void func_8008CD1C(int, int);
EXTERN_C int func_800B9E10(char *a, char b)
{
    char *s = D_800B4D0C.obj;
    if (s == a) {
        func_8008CD1C(0x4400, 0x18);
        *(int *)(s + 0x30) = 0;
        *(int *)(*(char **)(s + 4) + 4) = 0;
        s[0x36] = 1;
        s[0x37] = b;
        return 1;
    }
    return 0;
}
