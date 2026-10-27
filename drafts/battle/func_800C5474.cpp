// func_800C5474: NOT MATCHING. 3 instructions: the shared `return 0` lands in s0 instead of v0.
#include "common.h"
#include "battle/battle.h"
struct T_C5474 { S_800D00B8 *f0; S_800D00B8 *f4; char pad8[0x124]; int f12C; };
EXTERN_C S_800D00B8 *func_800752B8(void *p, S_800D00B8 *x);
EXTERN_C int func_800C5474(T_C5474 *p) { S_800D00B8 *x = p->f0; int r = 0; if (x) { p->f4 = x; if (x->f10 <= p->f12C) { r = x->f14; S_800D00B8 *n = func_800752B8(p, x); n->prev = n; n->next = n; n->fC = 0; } } return r; }
