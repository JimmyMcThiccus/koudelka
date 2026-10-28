// NOT CLOSE (34 differing, sizes match 320 bytes): copy-ctor-like clone. Layout/vptr stores/loops are right; remaining diffs are register allocation + scheduling of the two count-down copy loops (retail: dst ptr $a3, count $a2, -1 in $v1 / second loop dst $a0, count $v1, src $v0, -1 in $a2).
#include "common.h"
#include "battle/battle.h"
struct T_D4828_e0 { int a, b, c; };
struct T_D4828_e1 { int a, b, c, d, e; };
struct T_D4828 { VTable *vtbl; int f4; unsigned short s8, sA; int fC; int f10; T_D4828_e0 a14[2]; T_D4828_e1 a2C[2]; SVec4 t54; SVec2 t5C; };
//@ func_800D4828 best
EXTERN_C T_D4828 *func_800D4828(T_D4828 *s) {
    T_D4828 *p = (T_D4828 *)operator new(0x60);
    p->vtbl = D_80010178; p->f4 = s->f4; p->vtbl = D_800111BC; p->s8 = s->s8; p->vtbl = D_80014BD0; p->sA = s->sA; p->vtbl = D_800B7D84; p->fC = s->fC; p->f10 = s->f10;
    { T_D4828_e0 *d = p->a14; T_D4828_e0 *q = s->a14; int i = 1; while (i != -1) { *d = *q; d++; q++; i--; } }
    { T_D4828_e1 *d = p->a2C, *q = s->a2C; int i = 1; while (i != -1) { *d++ = *q++; i--; } }
    p->t54 = s->t54; p->t5C = s->t5C;
    return p;
}
