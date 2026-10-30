// Shadow Hearts patch: the Judgment Ring (docs/SH_PATCH_DESIGN.md 2). Rules from SH's CCircle (Shadow_Hearts_2001_Decomp
// docs/battle-logic.md section 1): one clockwise needle sweep from the top, press n is judged against zone n, a press
// outside its zone is a miss and ends the ring, a press in the last `strike` degrees of a zone is a strike.
//
// Started by the targeting confirm (input.cpp), ticked by the EXE frame hook, drawn by the EXE draw hook.
#include "common.h"
#include "shpatch/shpatch.h"
#include "shpatch/ring.h"

EXTERN_C int VSync(int mode);
EXTERN_C int func_8008EF40(int id);  // menu sound effect

ShRing g_ring;

// Default attack ring until the per-weapon tables land (2.4): three zones with strike areas at their ends.
static const ShZone s_attack[3] = {{50, 100, 6}, {160, 205, 5}, {265, 305, 4}};

void ring_start(void *mgr, int pad, int arg)
{
    int i;
    g_ring.mgr = mgr;
    g_ring.pad = pad;
    for (i = 0; i < 8; i++) g_ring.ev[i] = ((int *)pad)[i];
    g_ring.arg = arg;
    g_ring.nzones = 3;
    for (i = 0; i < 3; i++) g_ring.zone[i] = s_attack[i];
    g_ring.angle16 = 0;
    g_ring.presses = 0;
    g_ring.hits = 0;
    g_ring.strikes = 0;
    g_ring.missed = 0;
    for (i = 0; i < SH_RING_MAX_ZONES; i++) g_ring.mark[i] = -1;
    g_ring.timer = 0;
    g_ring.last_vs = VSync(-1);
    ring_alloc_prims();
    g_ring.phase = SH_RING_INTRO;
    g_shFrameHook = ring_tick;
    g_shDrawHook = ring_draw;
}

void ring_press(void)
{
    int a, k;
    const ShZone *z;
    if (g_ring.phase != SH_RING_SWEEP || g_ring.presses >= g_ring.nzones) return;
    a = g_ring.angle16 >> 4;
    k = g_ring.presses;
    z = &g_ring.zone[k];
    g_ring.mark[k] = a;
    g_ring.presses++;
    if (a < z->start || a > z->end) {
        g_ring.missed = 1;
        g_ring.mark_kind[k] = 0;
        func_8008EF40(0xE);  // buzz
        g_ring.phase = SH_RING_OUTRO;
        g_ring.timer = 0;
        return;
    }
    g_ring.hits++;
    if (z->strike && a >= z->end - z->strike) {
        g_ring.strikes |= 1 << k;
        g_ring.mark_kind[k] = 2;
    } else {
        g_ring.mark_kind[k] = 1;
    }
    func_8008EF40(g_ring.mark_kind[k] == 2 ? 0x2 : 0x1);
    if (g_ring.presses >= g_ring.nzones) {
        g_ring.phase = SH_RING_OUTRO;
        g_ring.timer = 0;
    }
}

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

static void ring_finish(void)
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

void ring_tick(void)
{
    int now = VSync(-1);
    int dv = now - g_ring.last_vs;
    g_ring.last_vs = now;
    if (dv < 0 || dv > 8) dv = 2;
    switch (g_ring.phase) {
    case SH_RING_INTRO:
        g_ring.timer += dv;
        if (g_ring.timer >= SH_RING_INTRO_VS) g_ring.phase = SH_RING_SWEEP;
        break;
    case SH_RING_SWEEP:
        g_ring.angle16 += 360 * 16 * dv / SH_RING_PERIOD_VS;
        if (g_ring.angle16 >= 360 * 16) {
            g_ring.angle16 = 360 * 16;
            if (g_ring.presses == 0) {
                g_ring.missed = 1;  // never pressed: one miss
                g_ring.mark[0] = 360;
                g_ring.mark_kind[0] = 0;
                g_ring.presses = 1;
            }
            g_ring.phase = SH_RING_OUTRO;
            g_ring.timer = 0;
        }
        break;
    case SH_RING_OUTRO:
        g_ring.timer += dv;
        if (g_ring.timer >= SH_RING_OUTRO_VS) ring_finish();
        break;
    }
}

