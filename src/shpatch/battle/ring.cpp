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

struct T_OTs { char pad[0x10]; unsigned int len; unsigned int *tbl; };
// Three tables are submitted per frame: the 3D battle layer (0x2000 entries), then two 5-entry ones; D_800B4CFC[0]
// already points at the last of those by then (read live), so the battle layer is told apart by its length.
#define SH_BATTLE_OT_LEN 0x2000

ShRing g_ring;

// sin(d) for d = 0..90 degrees, Q12
static const short s_sin[91] = {
    0, 71, 143, 214, 286, 357, 428, 499, 570, 641, 711, 782, 852, 921, 991, 1060, 1129, 1198, 1266, 1334, 1401,
    1468, 1534, 1600, 1666, 1731, 1796, 1860, 1923, 1986, 2048, 2110, 2171, 2231, 2290, 2349, 2408, 2465, 2522,
    2578, 2633, 2687, 2741, 2793, 2845, 2896, 2946, 2996, 3044, 3091, 3138, 3183, 3228, 3271, 3314, 3355, 3396,
    3435, 3474, 3511, 3547, 3582, 3617, 3650, 3681, 3712, 3742, 3770, 3798, 3824, 3849, 3873, 3896, 3917, 3937,
    3956, 3974, 3991, 4006, 4021, 4034, 4046, 4056, 4065, 4074, 4080, 4086, 4090, 4094, 4095, 4096,
};

static int isin(int d)
{
    d %= 360;
    if (d < 0) d += 360;
    if (d <= 90) return s_sin[d];
    if (d <= 180) return s_sin[180 - d];
    if (d <= 270) return -s_sin[d - 180];
    return -s_sin[360 - d];
}

static int icos(int d) { return isin(d + 90); }

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

// ---- drawing: flat POLY_F4 quads, double buffered, in front of the 3D scene ----

struct PolyF4 { unsigned int tag; unsigned char r, g, b, code; short x0, y0, x1, y1, x2, y2, x3, y3; };

#define SEG_DEG 5
#define NSEG (360 / SEG_DEG)
#define NPRIM (NSEG + 1 + SH_RING_MAX_ZONES)
static PolyF4 s_prim[2][NPRIM];
static int s_buf;

static void quad(PolyF4 *p, int cx, int cy, int a0, int a1, int r0, int r1, int r, int g, int b)
{
    p->r = r; p->g = g; p->b = b; p->code = 0x28;
    // angle 0 = top, clockwise: x = sin, y = -cos
    p->x0 = cx + (isin(a0) * r0 >> 12); p->y0 = cy - (icos(a0) * r0 >> 12);
    p->x1 = cx + (isin(a0) * r1 >> 12); p->y1 = cy - (icos(a0) * r1 >> 12);
    p->x2 = cx + (isin(a1) * r0 >> 12); p->y2 = cy - (icos(a1) * r0 >> 12);
    p->x3 = cx + (isin(a1) * r1 >> 12); p->y3 = cy - (icos(a1) * r1 >> 12);
}

static void add(T_OTs *ot, int z, PolyF4 *p)
{
    p->tag = (5u << 24) | (ot->tbl[z] & 0xFFFFFF);
    ot->tbl[z] = (unsigned int)p & 0xFFFFFF;
}

void ring_draw(void *otp)
{
    T_OTs *ot = (T_OTs *)otp;
    PolyF4 *p;
    int i, k, n = 0, grow, ri, ro, a;
    if (ot->len != SH_BATTLE_OT_LEN || g_ring.phase == SH_RING_OFF) return;
    p = s_prim[s_buf];
    s_buf ^= 1;
    grow = g_ring.phase == SH_RING_INTRO ? g_ring.timer * 16 / SH_RING_INTRO_VS : 16;
    ri = SH_RING_R_IN * grow >> 4;
    ro = SH_RING_R_OUT * grow >> 4;
    a = g_ring.angle16 >> 4;
    // needle (front)
    quad(&p[n], SH_RING_X, SH_RING_Y, a - 3, a + 3, 4, ro + 3, 255, 255, 255);
    add(ot, SH_RING_Z, &p[n++]);
    // press marks
    for (k = 0; k < SH_RING_MAX_ZONES; k++) {
        if (g_ring.mark[k] < 0) continue;
        if (g_ring.mark_kind[k] == 2) quad(&p[n], SH_RING_X, SH_RING_Y, g_ring.mark[k] - 2, g_ring.mark[k] + 2, ro, ro + 5, 255, 60, 60);
        else if (g_ring.mark_kind[k] == 1) quad(&p[n], SH_RING_X, SH_RING_Y, g_ring.mark[k] - 2, g_ring.mark[k] + 2, ro, ro + 5, 255, 255, 255);
        else quad(&p[n], SH_RING_X, SH_RING_Y, g_ring.mark[k] - 2, g_ring.mark[k] + 2, ro, ro + 5, 110, 110, 110);
        add(ot, SH_RING_Z, &p[n++]);
    }
    // track: zone colour per segment, flash on the ending
    for (i = 0; i < NSEG; i++) {
        int s = i * SEG_DEG, mid = s + SEG_DEG / 2, r = 50, g = 50, b = 60;
        for (k = 0; k < g_ring.nzones; k++) {
            const ShZone *z = &g_ring.zone[k];
            if (mid >= z->start && mid <= z->end) {
                if (z->strike && mid >= z->end - z->strike) { r = 220; g = 40; b = 30; }
                else { r = 230; g = 140; b = 30; }
            }
        }
        if (g_ring.phase == SH_RING_OUTRO && (g_ring.timer & 4)) {
            if (g_ring.missed) { r = 70; g = 70; b = 70; }
            else if (g_ring.hits == g_ring.nzones && g_ring.strikes == 7) { r = 255; g = 255; b = 255; }
            else { r = 60; g = 220; b = 90; }
        }
        quad(&p[n], SH_RING_X, SH_RING_Y, s, s + SEG_DEG, ri, ro, r, g, b);
        add(ot, SH_RING_Z + 1, &p[n++]);
    }
}
