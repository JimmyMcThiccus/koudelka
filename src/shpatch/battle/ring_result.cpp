// Shadow Hearts patch: the Judgment Ring's result (docs/SH_PATCH_DESIGN.md 2.5): the damage scale it publishes to the
// EXE choke points, and the replayed targeting confirm that lets the game resolve the action.
#include "common.h"
#include "shpatch/shpatch.h"
#include "shpatch/ring.h"

// Attack scale, Q8: SH's combo (first hit full, later hits half, a strike x1.2), normalised so three plain hits = 1.0.
static int attack_scale(void)
{
    static const int w[3] = {256, 128, 128};
    int i, s = 0;
    if (g_ring.missed && g_ring.hits == 0) return 0;
    for (i = 0; i < g_ring.hits; i++) {
        s += (g_ring.strikes & (1 << i)) ? w[i] * 6 / 5 : w[i];
    }
    return s / 2;
}

void ring_finish(void)
{
    char *mgr = (char *)g_ring.mgr;
    char *actor = *(char **)(mgr + 0xA0);
    g_shFrameHook = 0;
    g_shDrawHook = 0;
    g_ring.phase = SH_RING_OFF;
    g_shRing.scale = attack_scale();
    g_shRing.caster = actor ? actor + 0x400 : 0;
    g_shRing.active = 1;  // cleared by the turn driver (turn.cpp) once the action has resolved
    g_ring.result = g_shRing.scale;
    ring_replay(g_ring.mgr, (int)g_ring.ev, g_ring.arg);
}

