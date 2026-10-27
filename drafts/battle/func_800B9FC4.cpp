// func_800B9FC4: NOT MATCHING. 10 instructions: retail keeps the loop test at the top (j back, exit(1) after the loop) and tests the counter with sll 24; we get a rotated loop. func_800B9F48 has the same shape.
#include "common.h"
#include "battle/battle.h"
EXTERN_C int func_800B9FC4(S_800BA418 *p, signed char id) { S_800BA418_3FC *q = p->f3FC; signed char n = p->b100; for (;;) { if (!n) { exit(1); } if (q->b8 == id) break; n--; q = q->f4; } return q->fC; }
