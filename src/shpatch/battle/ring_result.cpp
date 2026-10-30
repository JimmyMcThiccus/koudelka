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
    // magic: power % (a strike is 120); item: all or nothing; attack: the combo above
    g_shRing.scale = g_ring.kind == SH_KIND_ATTACK ? attack_scale()
                   : g_ring.hits == 0 ? 0 : g_ring.kind == SH_KIND_MAGIC ? g_ring.power * 256 / 100 : 256;
    g_shRing.caster = actor ? actor + 0x400 : 0;
    g_shRing.any_side = g_ring.kind != SH_KIND_ATTACK;
    // SH spends no MP on a failed magic ring. Here the spell still plays (at no effect), so its cost is refunded
    // once the action is over (turn.cpp).
    g_shRing.refund_mp = g_ring.kind == SH_KIND_MAGIC && g_ring.hits == 0 && actor ? *(short *)(actor + 0x420) : -1;
    g_shRing.active = 1;  // cleared by the turn driver (turn.cpp) once the action has resolved
    g_ring.result = g_shRing.scale;
    ring_replay(g_ring.mgr, (int)g_ring.ev, g_ring.arg);
}


// Called at every entry to the turn driver with its current actor. The ring's scale covers one action. Melee applies
// its damage inside the replayed confirm; spells and items apply theirs in the action sequencer, while the driver keeps
// being called with the caster's action latch (fighter b4AD/b4AE) set. The context ends once the driver runs with any
// other actor or with the latches clear; a failed spell gets its MP back then.
void ring_turn(void *actor)
{
    char *a = (char *)actor;
    if (!g_shRing.active) return;
    if (a && a + 0x400 == g_shRing.caster && (a[0x4AD] || a[0x4AE])) return;
    g_shRing.active = 0;
    if (g_shRing.refund_mp >= 0 && g_shRing.caster) {
        *(short *)((char *)g_shRing.caster + 0x20) = g_shRing.refund_mp;
        g_shRing.refund_mp = -1;
    }
}
