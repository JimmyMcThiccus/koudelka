// func_800D1B68: MATCHES (0 differing instructions) but can't land: its switch jump table (retail jtbl_800B7864,
// only 4-aligned) gets 8-aligned when the compiler emits it, so BATTLE grows by 4 bytes (rodata hazard).
#include "common.h"
#include "battle/battle.h"
EXTERN_C int func_80063744(void *p, int a);
struct T_D1B68_b { int pad[6]; virtual void v1(); virtual void v2(); virtual void v3(); };
struct T_D1B68 : T_D1B68_b { char pad1C[0x5738]; int f5754; };
EXTERN_C int func_800D1B68(T_D1B68 *p, int a) {
    if (func_80063744(p, a)) return 1;
    switch (a) {
    case 3: func_800D1C50((T_D1C50 *)p); return 1;
    case 4: p->f5754 = 4; p->v3(); return 1;
    case 5: p->f5754 = 5; p->v3(); return 1;
    case 6: p->f5754 = 6; p->v3(); return 1;
    case 7: p->f5754 = 7; p->v3(); return 1;
    case 8: p->f5754 = 8; p->v3(); return 1;
    case 9: p->f5754 = 9; p->v3(); return 1;
    case 10: p->f5754 = 10; p->v3(); return 1;
    }
    return 0;
}
