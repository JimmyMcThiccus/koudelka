// func_800C2BD0: copy of the other double-buffer entry; retail computes element addresses as (i*12+0xC)+p explicitly. Same pattern blocks func_800C2B28.
#include "common.h"
#include "capture/capture.h"

EXTERN_C int D_800B4CF0[];
EXTERN_C void func_800C2BD0(S_800C2D5C *p)
{
    int i = D_800B4CF0[0];
    p->a[i].b = p->a[i ^ 1].b;
    p->e[i].b = p->e[i ^ 1].b;
}
