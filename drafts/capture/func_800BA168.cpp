// func_800BA168: 1-2 differ: retail `addu a1, v0, a1` (sum into the parameter register, field first); every C form tried gives `addu a1, a1, v0` or `addu v0, v0, a1`.
#include "common.h"

struct S3 { int a, b; char *c; };
EXTERN_C void func_800BA168(S3 *p, int v) { p->c += v; }
