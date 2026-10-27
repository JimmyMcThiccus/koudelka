// func_800D596C: NOT MATCHING. 3 instructions differ even with -G0: retail loads p->f20 with lw and the global after it; we get lhu and the other order.
#include "common.h"
#include "battle/battle.h"
EXTERN_C void func_8006323C(void *p);
EXTERN_C void func_800D596C(T_D596C *p) { func_8006323C(p); D_800B4DD0->s1F6 = p->f20; func_8005457C(p, 0); }
