// func_800C3E34: NOT MATCHING. 5 instructions: retail computes the row as (i<<7) + p + 0x55C, we fold to (i<<7) + 0x55C + p.
#include "common.h"
#include "battle/battle.h"
struct T_C3E34_e { int a; int b; };
struct T_C3E34_r { char pad[0x24]; T_C3E34_e e[11]; char pad7C[4]; };
struct T_C3E34 { char pad[0x55C]; T_C3E34_r r[1]; };
EXTERN_C void func_800C3E34(T_C3E34 *p, int i, int j, int *a, int *b) { T_C3E34_r *r = p->r + i; *a = r->e[j].a; if ((*b = r->e[j].b) == 0) { *a = r->e[0].a; *b = r->e[0].b; } }
