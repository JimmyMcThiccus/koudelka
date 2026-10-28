// func_800CED08: NOT MATCHING. 3 instructions: retail computes D_800D5DAC's address before p+0x7DC; we emit them the other way round.
#include "common.h"
#include "battle/battle.h"
struct T_2C { char d[0x2C]; };
EXTERN_C char D_800D5DAC[];
struct T_CED08 { char pad[0x7DC]; short s7DC; char pad7DE[0x156]; int f934; };
struct T_4DD0d { char pad[0x1FB]; signed char b1FB; };
EXTERN_C int func_800CED08(T_CED08 *p) { char *b = D_800D5DAC; int o = 0x97F0; *(T_2C *)&p->s7DC = *(T_2C *)(b + o); p->f934 = p->s7DC + ((T_4DD0d *)D_800B4DD0[0])->b1FB; return p->s7DC; }
