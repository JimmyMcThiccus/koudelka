// Shadow Hearts battle patch: shared declarations (docs/SH_PATCH_DESIGN.md).
#ifndef SHPATCH_H
#define SHPATCH_H

#include "common.h"

#define SH_MAX_TARGETS 6

// The ring result, read by the EXE's HP/MP choke points (src/shpatch/exe/hooks.cpp). Lives in .shexe.
struct ShRingCtx {
    int active;                     // set when a ring finishes, cleared at the end of the action
    int scale;                      // Q8: 256 = 1.0
    void *caster;                   // attacker's stat block (fighter + 0x400)
    void *targets[SH_MAX_TARGETS];  // stat blocks of mgr->f84C[0..f848)
};
EXTERN_C ShRingCtx g_shRing;
// Called once per game frame from the EXE's buffer swap while non-null (src/shpatch/exe/hooks.cpp). BATTLE sets it
// only while it needs a tick and clears it before the overlay can be unloaded.
EXTERN_C void (*g_shFrameHook)(void);

// Call counts per patch entry point, for checking in DuckStation that the detours run (index = SH_TRACE_*).
enum { SH_TRACE_HP, SH_TRACE_MP, SH_TRACE_SEQ, SH_TRACE_TURN, SH_TRACE_PAD, SH_TRACE_N = 8 };
EXTERN_C int g_shTrace[SH_TRACE_N];
// Call counts from `@count` detours (src/shpatch/detours.txt), for finding which entry points run when.
EXTERN_C int g_shCount[16];

EXTERN_C void func_80086B70_sh(void *self, int v);
EXTERN_C void func_80086CAC_sh(void *self, int v);

#endif
