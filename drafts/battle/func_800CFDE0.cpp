// func_800CFDE0: NOT MATCHING. 3 instructions: retail adds index*4 + p, we add p + index*4 (operand order of the element address).
#include "common.h"
#include "battle/battle.h"
struct T_CFDE0 { SVec2 f0[0x23]; int f8C; int f90; };
EXTERN_C SVec2 func_800CFDE0(T_CFDE0 *p) { return p->f0[p->f90]; }
