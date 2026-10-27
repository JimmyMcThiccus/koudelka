// func_800D407C: NOT MATCHING. 2 instructions: retail schedules `sra a1,a1,24` before `li v0,1`; we emit them the other way round. Storing b50 first fixes that but swaps the stores.
#include "common.h"
#include "battle/battle.h"
struct T_D407C { char pad[0x44]; int f44; int f48; int pad4C; char b50; };
EXTERN_C void func_800D407C(T_D407C *p, int a, int b) { p->f44 = 1; p->b50 = a >> 24; p->f48 = b; }
