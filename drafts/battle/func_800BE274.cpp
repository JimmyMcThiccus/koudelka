// func_800BE274: NOT MATCHING. Exact match with -O2 -G0; with -G8 the %hi register differs (a0 vs v0). Lands with a -G0 override.
#include "common.h"
#include "battle/battle.h"
EXTERN_C void *D_800B4ED8 LUI_DATA;
EXTERN_C void func_8006B850(void *p);
EXTERN_C void func_800BE274() { func_8006B850(D_800B4ED8); }
