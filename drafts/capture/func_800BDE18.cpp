// func_800BDE18: 3 differ: register choice for the cached pointer (retail loads into v0 and copies to v1).
#include "common.h"
#include "capture/capture.h"

EXTERN_C int func_800B7728(void *);
EXTERN_C int func_800BDE18(char *p, int n)
{
    int r = 0;
    if (n) {
        if (*(int *)(p + 0x144))
            r = *(int *)(p + 0x144);
        else
            *(int *)(p + 0x140) = r = func_800B7728(p);
        *(int *)(p + 0x144) = r + n;
    }
    return r;
}
