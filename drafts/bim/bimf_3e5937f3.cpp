#include "common.h"
EXTERN_C char *D_scalar asm("D_800B4D38");
EXTERN_C char *D_arr[] asm("D_800B4D38");
EXTERN_C void bimf_3e5937f3(char *p, int slot)
{
    int *q = (int *)p;
    *(int *)(p + 2556) = 0x18CE7;
    *(int *)(p + 2560) = 0x1000;
    *(int *)(p + 2564) = 0x18CE9;
    *(int *)(p + 2568) = 0x3800;
    *(int *)(p + 2572) = 0x18CE9;
    *(int *)(p + 2576) = 0x3800;
    *(int *)(p + 2580) = 0x18CF0;
    *(int *)(p + 2584) = 0x4800;
    *(int *)(p + 2588) = 0x18CF9;
    *(int *)(p + 2592) = 0x4800;
    *(int *)(p + 2596) = 0x18D02;
    *(int *)(p + 2600) = 0x6000;
    *(int *)(p + 2604) = 0x18D0E;
    *(int *)(p + 2608) = 0x4800;
    *(int *)(p + 2612) = 0x18D17;
    *(int *)(p + 2616) = 0x1000;
    *(int *)(p + 2620) = 0x18D19;
    *(int *)(p + 2624) = 0x1000;
    *(int *)(p + 2628) = 0x18D1B;
    *(int *)(p + 2632) = 0x5000;
    *(int *)(p + 2636) = 0x18D1B;
    *(int *)(p + 2640) = 0x5000;
    *(int *)(p + 2644) = 0x18D25;
    *(int *)(p + 2648) = 0x4000;
    *(int *)(p + 2652) = 0x18D2D;
    *(int *)(p + 2656) = 0x4800;
    *(int *)(p + 2780) = 0x18D36;
    *(int *)(p + 2784) = 0x4800;
    *(int *)(p + 2788) = 0x18D3F;
    *(int *)(p + 2792) = 0x800;
    ((int **)(D_arr[0] + 0xF8))[(short)slot] = q + 639;
}
