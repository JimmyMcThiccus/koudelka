// Shadow Hearts patch: drawing the Judgment Ring (docs/SH_PATCH_DESIGN.md 2.3). The EXE draw hook calls ring_draw
// with each ordering table just before it is submitted.
#include "common.h"
#include "shpatch/shpatch.h"
#include "shpatch/ring.h"

struct T_OTs { char pad[0x10]; unsigned int len; unsigned int *tbl; };
// Three tables are submitted per frame: the 3D battle layer (0x2000 entries), then two 5-entry ones; D_800B4CFC[0]
// already points at the last of those by then (read live), so the battle layer is told apart by its length.
#define SH_BATTLE_OT_LEN 0x2000

struct PolyF4 { unsigned int tag; unsigned char r, g, b, code; short x0, y0, x1, y1, x2, y2, x3, y3; };

#define SEG_DEG 5
#define NSEG (360 / SEG_DEG)
#define NPRIM (NSEG + 1 + SH_RING_MAX_ZONES)
// On the heap for the ring's lifetime (allocated by ring_start, freed by ring_free_prims from the turn driver, which
// runs well after the GPU has drawn the last frame that used them).
static PolyF4 (*s_prim)[NPRIM];
static int s_buf;

void ring_free_prims(void)
{
    if (s_prim) {
        operator delete(s_prim);
        s_prim = 0;
    }
}


void ring_alloc_prims(void)
{
    if (!s_prim) s_prim = (PolyF4 (*)[NPRIM])operator new(sizeof(PolyF4) * 2 * NPRIM);
}

static void quad(PolyF4 *p, int cx, int cy, int a0, int a1, int r0, int r1, int r, int g, int b)
{
    p->r = r; p->g = g; p->b = b; p->code = 0x28;
    // angle 0 = top, clockwise: x = sin, y = -cos
    p->x0 = cx + (ring_sin(a0) * r0 >> 12); p->y0 = cy - (ring_cos(a0) * r0 >> 12);
    p->x1 = cx + (ring_sin(a0) * r1 >> 12); p->y1 = cy - (ring_cos(a0) * r1 >> 12);
    p->x2 = cx + (ring_sin(a1) * r0 >> 12); p->y2 = cy - (ring_cos(a1) * r0 >> 12);
    p->x3 = cx + (ring_sin(a1) * r1 >> 12); p->y3 = cy - (ring_cos(a1) * r1 >> 12);
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
    if (!s_prim) return;
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
