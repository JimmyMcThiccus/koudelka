// func_800CFEF4: NOT MATCHING. 3 instructions: retail schedules `sw ra` before `addiu a2,a0,0x10`, so the beqz delay slot differs.
// Empty array-member destructor loop + `if (flags & 1) delete`; a real ~T() gives the same code.
#include "common.h"
#include "battle/battle.h"
struct T_CFEF4_e { char pad[0x18]; ~T_CFEF4_e() {} };
struct T_CFEF4 { char pad[0x10]; T_CFEF4_e e[41]; };
EXTERN_C void func_800CFEF4(T_CFEF4 *p, int flags) { T_CFEF4_e *b = p->e; if (b) { T_CFEF4_e *e = b + 41; if (b != e) { T_CFEF4_e *s = b; do { (--e)->~T_CFEF4_e(); } while (s != e); } } if (flags & 1) operator delete(p); }
