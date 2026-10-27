// func_800BFA5C / func_800BFAE8: 8 differ each. The 16-byte struct copy uses $a1,$a3,$t0,$t1 here;
// retail avoids $a1 ($a3,$t0,$t1,$t2), as if the second parameter were still live.
#include "common.h"
#include "capture/capture.h"

// func_800BFA5C
struct Int4 { int v[4]; };
EXTERN_C void *func_80019F64(void *);
EXTERN_C int func_800BFA5C(char *p, int unused, Int4 *out)
{
    char *a = p + 0x5E0;
    void **b = a ? (void **)(p + 0x5E8) : 0;
    char *r = (char *)func_80019F64(b ? *b : 0);
    *(char **)(p + 0x600) = r;
    if (!r)
        return 0;
    *out = *(Int4 *)(*(char **)(r + 0x1B8) + 0x34);
    return 1;
}
// func_800BFAE8
struct Int4 { int v[4]; };
EXTERN_C void *func_80019F64(void *);
EXTERN_C void func_80039DD8(void *);
EXTERN_C int func_800BFAE8(char *p, int unused, Int4 *in)
{
    char *a = p + 0x5E0;
    void **b = a ? (void **)(p + 0x5E8) : 0;
    char *r = (char *)func_80019F64(b ? *b : 0);
    *(char **)(p + 0x600) = r;
    if (!r)
        return 0;
    char *o = *(char **)(r + 0x1B8);
    *(Int4 *)(o + 0x34) = *in;
    func_80039DD8(o);
    return 1;
}
