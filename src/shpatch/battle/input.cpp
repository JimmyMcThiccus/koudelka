// Shadow Hearts patch: battle pad input (docs/SH_PATCH_DESIGN.md 2.2). func_800CB174 detours here; the original
// (asm) is reached through its trampoline func_800CB174_orig, which tools/patch/build.py generates.
// Phase 4 step 1: passes everything through (the no-op patch).
#include "common.h"
#include "shpatch/shpatch.h"

EXTERN_C int func_800CB174_orig(void *mgr, int pad, int a);

EXTERN_C int func_800CB174_sh(void *mgr, int pad, int a)
{
    g_shTrace[SH_TRACE_PAD]++;
    return func_800CB174_orig(mgr, pad, a);
}
