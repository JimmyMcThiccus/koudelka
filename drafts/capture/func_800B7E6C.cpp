// func_800B7E6C (PsyQ 4.1): 18 differ: retail computes p+0x110 and p+0x114 as two separate adds (b+n into $v0, then b+=copy-of-n into $v1, with n copied to $a2); here CSE merges them into one add, which shifts the register allocation of n/q[6]/b.
#include "common.h"
#include "capture/capture.h"

EXTERN_C int D_800B1A5C[];
EXTERN_C void SpuSetIRQ(int);
EXTERN_C void func_800B84E0(void *);
EXTERN_C void func_800B7E6C(char *p, unsigned char *q)
{
    SpuSetIRQ(0);
    if ((int)p == D_800B1A5C[0]) {
        int n = *(unsigned short *)(q + 0x14);
        int sz = n * q[6];
        char *b = *(char **)(p + 0x10) + 0x20;
        *(int *)(p + 0x20) = n;
        *(char **)(p + 0xE0) = b;
        *(char **)(p + 0xE4) = b;
        *(char **)(p + 0x110) = b + n;
        *(char **)(p + 0x114) = b + n;
        *(int *)(p + 0x1C) = sz;
        *(int *)(p + 0x24) = (sz + 0x3F) & ~0x3F;
        func_800B84E0(p + 0xC4);
        func_800B84E0(p + 0xF4);
    }
}
