// func_800CEFE8: NOT MATCHING. 34 instructions, 8 bytes short: retail copies params a1->t0 and a3->a2 at entry and keeps r in a1, g in v1; we use the params in place.
#include "common.h"
#include "battle/battle.h"
struct T_AFA58 { char pad[0x1B8]; int f1B8; char pad1BC[0x58]; short s214; };
struct T_CEFE8_g { char pad[0x328]; char *f328; void *f32C; };
EXTERN_C void func_800CF080(void *p);
EXTERN_C void func_8007C070(void *p, int a);
struct T_CEFE8 { char pad[0x808]; char *f808[1]; };
EXTERN_C void func_800CEFE8(T_CEFE8 *p, char *q, int x, int i) { if (q) p->f808[i] = q + 0x48C; T_AFA58 *r = (T_AFA58 *)D_800AFA58[i]; T_CEFE8_g *g = (T_CEFE8_g *)D_800AF470[0]; r->s214 = 0; if (q) { if (!r->f1B8) func_800CF080(g->f32C); else func_8007C070(g->f328 ? g->f328 + 0xB8 : 0, i + 3); } }
