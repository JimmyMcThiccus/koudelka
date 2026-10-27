// func_800B9F48: NOT MATCHING. Same loop shape problem as func_800B9FC4 (loop not rotated in retail; id's sign extension scheduled first).
#include "common.h"
#include "battle/battle.h"
EXTERN_C int func_800B9F48(S_800BA418 *p, signed char id) { S_800BA6B4 *q = p->f3E8.f4; while (p->b101) { if (func_800BA6D0(q) == id) return q->fC; q = (S_800BA6B4 *)q->f4; } exit(1); }
