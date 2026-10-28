#include "pre.h"
// NONMATCH: ~25 diffs; loop shapes right, but retail byte loop uses fresh copies of dst/src made after its guard and the 16-byte loop has dst/src in t3/t2 (here swapped)
EXTERN_C void func_8008BECC(char *d, char *s, int n)
{
    int i;
    int a, b, c, e;

    for (i = n >> 4; i != 0; i--) {
        a = ((int *)s)[0];
        b = ((int *)s)[1];
        c = ((int *)s)[2];
        e = ((int *)s)[3];
        ((int *)d)[0] = a;
        ((int *)d)[1] = b;
        ((int *)d)[2] = c;
        ((int *)d)[3] = e;
        d += 16;
        s += 16;
    }
    for (i = (n >> 2) & 3; i != 0; i--) {
        *(int *)d = *(int *)s;
        d += 4;
        s += 4;
    }
    for (i = n & 3; i != 0; i--) {
        *d++ = *s++;
    }
}
