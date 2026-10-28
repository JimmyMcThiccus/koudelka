#include "pre.h"
// NONMATCH: ~29 diffs; retail keeps p as the biv in a0 with one reduced giv p+4 (stores 8/4/0(v1) then 0(a0)); GCC here copies p to v1 and reduces p+0xC into a0 (+1 insn)
EXTERN_C void func_8008BF78(char *p, int n)
{
    int *q = (int *)p;
    int z = 0;
    int i;

    for (i = n >> 4; i != 0; i--) {
        q[0] = z;
        q[1] = z;
        q[2] = z;
        q[3] = z;
        q += 4;
    }
    for (i = (n >> 2) & 3; i != 0; i--) {
        *q++ = z;
    }
    p = (char *)q;
    for (i = n & 3; i != 0; i--) {
        *p++ = z;
    }
}
