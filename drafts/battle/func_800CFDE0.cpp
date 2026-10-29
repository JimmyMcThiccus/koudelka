// r4c: still 3. Tried 30 forms (pointer/char/short casts, locals, member fn, const, out-pointer signature, register $3 hint). Any form going through a pointer loses the 2-byte alignment (memcpy). The permuter's only gain cheats: it takes &p and reads an uninitialised variable.
// NEAR (3 differing): `return p->f0[p->f90]` gives `addu $a1,$a1,$v1` (+ lwl/lwr off $a1); retail has `addu $v1,$v1,$a1` (result kept in $v1). Every other form tried (inline method, int*/char* indexing, locals) breaks the lwl/lwr copy (memcpy call) or keeps the 3 diffs.
#include "common.h"
#include "shared/exe.h"
#include "battle/battle.h"
//@ func_800CFDE0 best
SVec2 func_800CFDE0(T_CFE8C *p) { return p->f0[p->f90]; }
