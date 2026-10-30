// Shadow Hearts patch: drawing the Judgment Ring (docs/SH_PATCH_DESIGN.md 2.3), after SH's CCircle (Draw,
// UpdateVertices, MakeZonePoly, MakeBarPoly, UpdateBarVertex, MakeBlurPoly, MakeRenderMark, StartSequence).
//
// The ring spins in like a coin (ry 69 -> 415 = 55 over 0.4 s), then the needle grows in while the zones fade up. The
// EXE draw hook calls ring_draw with each ordering table before it is sent; geometry is in ring_gfx.cpp.
#include "common.h"
#include "shpatch/ring.h"
#include "shpatch/ring_gfx.h"

void ring_draw(void *otp)
{
    int i, k, alpha = 128, ry = 55, grow = 16, t;
    int scale = 16;
    if (g_ring.phase == SH_RING_OFF || !gfx_begin(otp)) return;
    t = g_ring.timer;
    if (g_ring.phase == SH_RING_INTRO) {
        if (t < SH_RING_SPIN_VS) {             // coin spin: ry = 69 + 346 sin(t * 90)
            ry = 69 + (346 * ring_sin(t * 90 / SH_RING_SPIN_VS) >> 12);
            grow = 0;
        } else {
            grow = (t - SH_RING_SPIN_VS) * 16 / SH_RING_GROW_VS;
        }
    } else if (g_ring.phase == SH_RING_OUTRO) {  // fade out; a success also swells to 1.5x (DoSequence state 10)
        alpha = 128 - t * 128 / SH_RING_OUTRO_VS;
        if (alpha < 0) alpha = 0;
        if (!g_ring.missed) scale = 16 + t * 8 / SH_RING_OUTRO_VS;
    }
    gfx_matrix(ry, scale);

    // back to front: ring band (50%), zones (additive), trail (additive), needle, marks; then restore the mode
    draw_mode(SH_RING_Z, ABR_HALF);
    for (k = 0; k < SH_RING_MAX_ZONES; k++) {
        if (g_ring.mark[k] >= 0) mark(SH_RING_Z + 1, g_ring.mark[k], g_ring.mark_kind[k]);
    }
    if (g_ring.phase != SH_RING_OUTRO) {
        needle(SH_RING_Z + 1, SH_RING_Z + 2, g_ring.angle16 >> 4, R16(120) * grow >> 4, grow);
        draw_mode(SH_RING_Z + 2, ABR_ADD);
        if (g_ring.phase == SH_RING_SWEEP) trail(SH_RING_Z + 3, g_ring.angle16, alpha);
    }
    draw_mode(SH_RING_Z + 3, ABR_ADD);
    for (k = 0; k < g_ring.nzones; k++) zone(SH_RING_Z + 4, &g_ring.zone[k], 96 * grow * alpha >> 11);
    draw_mode(SH_RING_Z + 4, ABR_ADD);
    // the ring art (textured in SH: TEXTURE/BT/BTLDATA.BIN rasters 0..3); until then a translucent green band
    for (i = 0; i < 360; i += 10) band(SH_RING_Z + 5, i, i + 10, R16(104), R16(124), rgb(0x18 * alpha >> 7, 0x70 * alpha >> 7, 0x40 * alpha >> 7, 0));
    draw_mode(SH_RING_Z + 5, ABR_HALF);
}
