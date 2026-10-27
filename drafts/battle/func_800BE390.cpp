// func_800BE390: NOT MATCHING. Exact match with -O2 -G0 (try_compile --cflags "-O2 -G0"). Under the project's -G8 GCC emits lw/sw macros instead of explicit %hi/%lo, so registers differ. Lands once battle.cpp gets a -G0 override.
#include "common.h"
#include "battle/battle.h"
struct T_BE390 { char pad[0x26C]; int f26C; char pad270[8]; int f278; };
EXTERN_C T_BE390 *D_800B4ED8 LUI_DATA;
EXTERN_C int D_800D5D80 LUI_DATA;
EXTERN_C void func_800BE390() { T_BE390 *p = D_800B4ED8; int old = D_800D5D80; D_800D5D80 = 6; p->f278 = old; p->f26C = 0; }
