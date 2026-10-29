// func_800D7ECC: 23 differing instructions. Retail computes n-1 / n-4 before the array base address and keeps a separate j-with-nop per arm; GCC merges.
#include "common.h"
#include "shared/exe.h"
#include "bim/bim.h"
EXTERN_C void func_800D7ECC(void *p, int n) {
    void *x;
    if (n) {
        if (n < 4) { int k = n - 1; x = D_800AFA64[k]; }
        else { int k = n - 4; x = D_800AFA58[k]; }
    } else x = p;
    func_800D7E8C(p, (int)x);
}
