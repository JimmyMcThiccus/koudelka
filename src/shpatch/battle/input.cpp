// Shadow Hearts patch: battle pad input (docs/SH_PATCH_DESIGN.md 2.1). func_800CB174 detours here; the original
// (asm) is reached through its trampoline func_800CB174_orig, which tools/patch/build.py generates.
//
// The targeting confirm does not reach the original: it starts the Judgment Ring, and the ring replays it when it
// ends. While the ring is up, confirm presses go to the ring and everything else is swallowed.
#include "common.h"
#include "shpatch/shpatch.h"
#include "shpatch/ring.h"

// The pad argument points at the input event; its h18 holds the newly pressed buttons (read live: Up 0x10,
// Cross 0x2000). 0x2000 is the confirm bit the window code tests too, Cross on the US disc.
#define SH_PAD_CONFIRM 0x2000

static int pressed(int ev) { return ev ? *(unsigned short *)(ev + 0x18) : 0; }
#define SH_F3D0_TARGET 4      // mgr+0x3D0 while choosing an attack target (read live: menu 1, target 4, animation 5)

EXTERN_C int func_800CB174_orig(void *mgr, int pad, int a);  // pad: pointer to the input event

void ring_replay(void *mgr, int pad, int arg)
{
    func_800CB174_orig(mgr, pad, arg);
}

EXTERN_C int func_800CB174_sh(void *mgr, int pad, int a)
{
    char *m = (char *)mgr;
    char *actor;
    g_shTrace[SH_TRACE_PAD]++;
    g_shTrace[5] = pressed(pad);
    g_shTrace[6] = *(int *)(m + 0x3D0);
    if (g_ring.phase != SH_RING_OFF) {
        if (pressed(pad) & SH_PAD_CONFIRM) ring_press();
        return 1;
    }
    actor = *(char **)(m + 0xA0);
    if ((pressed(pad) & SH_PAD_CONFIRM) && *(int *)(m + 0x3D0) == SH_F3D0_TARGET && actor && actor[0x4BC] < 3) {
        ring_start(mgr, pad, a);
        return 1;
    }
    return func_800CB174_orig(mgr, pad, a);
}
