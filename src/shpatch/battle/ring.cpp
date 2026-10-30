// Shadow Hearts patch: the Judgment Ring (docs/SH_PATCH_DESIGN.md 2). Rules from SH's CCircle (Shadow_Hearts_2001_Decomp
// docs/battle-logic.md section 1): one clockwise needle sweep from the top, press n is judged against zone n, a press
// outside its zone is a miss and ends the ring, a press in the last `strike` degrees of a zone is a strike.
//
// Started by the targeting confirm (input.cpp), ticked by the EXE frame hook, drawn by the EXE draw hook.
#include "common.h"
#include "shpatch/shpatch.h"
#include "shpatch/ring.h"
#include "shpatch/ring_tex.h"

EXTERN_C int VSync(int mode);
EXTERN_C int func_8008EF40(int id);  // menu sound effect

ShRing g_ring;

// Default attack ring until the per-weapon tables land (2.4): three zones with strike areas at their ends.
static const ShZone s_attack[3] = {{50, 100, 6}, {160, 205, 5}, {265, 305, 4}};
// Magic: one main zone, power rising from 40 % (40 + _NRing.param, param 0 here) at its start to 100 % five sixths of
// the way to the strike area. Item: one wide zone, no strike. Defaults until per-spell and per-item tables land (2.4).
static const ShZone s_magic = {60, 300, 10}, s_item = {45, 315, 0};

void ring_start(void *mgr, int pad, int arg, int kind)
{
    int i;
    g_ring.mgr = mgr;
    g_ring.pad = pad;
    for (i = 0; i < 8; i++) g_ring.ev[i] = ((int *)pad)[i];
    g_ring.arg = arg;
    g_ring.kind = kind;
    g_ring.nzones = kind == SH_KIND_ATTACK ? 3 : 1;
    for (i = 0; i < 3; i++) g_ring.zone[i] = s_attack[i];
    if (kind == SH_KIND_MAGIC) g_ring.zone[0] = s_magic;
    if (kind == SH_KIND_ITEM) g_ring.zone[0] = s_item;
    g_ring.power = 0;
    g_shRing.active = 0;
    g_ring.angle16 = 0;
    g_ring.presses = 0;
    g_ring.hits = 0;
    g_ring.strikes = 0;
    g_ring.missed = 0;
    for (i = 0; i < SH_RING_MAX_ZONES; i++) g_ring.mark[i] = -1;
    g_ring.timer = 0;
    g_ring.last_vs = VSync(-1);
    ring_alloc_prims();
    ring_tex_upload();  // effects may have reused the VRAM since the last ring
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
    g_ring.mark_vs[k] = g_ring.last_vs;
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
    if (g_ring.kind == SH_KIND_MAGIC) {  // MakeSprite: 40 + 60 (a - start) / ((end - start - strike) * 5/6), max 100
        int w = (z->end - z->start - z->strike) * 5;
        g_ring.power = 40 + 60 * 6 * (a - z->start) / (w > 0 ? w : 1);
        if (g_ring.power > 100) g_ring.power = 100;
    }
    if (z->strike && a >= z->end - z->strike) {
        g_ring.power = 120;
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
                g_ring.mark_vs[0] = now;
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

