// func_800D0C90: NOT MATCHING. Exact match with -O2 -G0; with -G8 the %hi register and a1 setup differ. Lands with a -G0 override.
#include "common.h"
#include "battle/battle.h"
struct T_D0C90 { char pad[0x68]; int f68; };
EXTERN_C void func_80062280(void *p, int a);
EXTERN_C void func_800D0C90(T_D0C90 *p) { p->f68 = 1; func_80062280(D_800B4DD0, 1); }
