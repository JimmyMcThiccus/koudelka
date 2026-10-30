// Shadow Hearts patch: the Judgment Ring's hit labels ("Good!!", "Perfect!!", ...), after SH's CCircle::MakeSprite,
// UpdateSprite and RenderSprite: each rises 8 SH buffer lines over 0.25 s at 80 units along its press angle, then holds
// for 0.8 s. The cels are SH's own (TEXTURE/BT/BTLDATA.BIN entry 7) at half size, in VRAM (ring_tex.cpp).
#include "common.h"
#include "shpatch/ring.h"
#include "shpatch/ring_gfx.h"
#include "shpatch/ring_tex.h"

static unsigned int tpage(int page_b, int abr) { return (abr << 5) | ((SH_TEX_Y & 256) >> 4) | ((page_b ? SH_TEX_PAGE_B : SH_TEX_PAGE_A) >> 6); }
static unsigned int clut(int x) { return (SH_CLUT_Y << 6) | (x >> 4); }

// The label for press k: SH's marks 1 Miss, 2 Good, and strikes 4 + n: Nice, Cool, Perfect for the n-th strike.
static int label_of(int k)
{
    int n = 0, i;
    if (g_ring.mark_kind[k] == 0) return SH_LBL_MISS;
    if (g_ring.mark_kind[k] == 1) return SH_LBL_GOOD;
    for (i = 0; i <= k; i++) n += (g_ring.strikes >> i) & 1;
    return n >= 3 ? SH_LBL_PERFECT : n == 2 ? SH_LBL_COOL : SH_LBL_NICE;
}

void ring_labels(int z)
{
    int k;
    for (k = 0; k < SH_RING_MAX_ZONES; k++) {
        int age, rise, c, x, y, v, lbl, cx;
        unsigned int at, *p;
        if (g_ring.mark[k] < 0) continue;
        age = g_ring.last_vs - g_ring.mark_vs[k];
        if (age < 0 || age > 63) continue;          // 0.25 s in, 0.8 s held
        rise = age < 15 ? age : 15;
        c = 0x80 * rise / 15;                       // fades in with the rise (opaque prims: darker = fainter)
        at = polar(g_ring.mark[k], R16(80));
        x = (short)(at & 0xFFFF) - SH_LABEL_W / 2;
        y = (short)(at >> 16) - SH_LABEL_H / 2 - rise * 4 / 15 - 4;  // 8 SH buffer lines = about 4 px
        lbl = label_of(k);
        v = SH_LABEL_V + SH_LABEL_H * lbl;
        cx = lbl == SH_LBL_MISS ? SH_CLUT_LABEL_RED : lbl == SH_LBL_STRIKE ? SH_CLUT_LABEL_CYAN : SH_CLUT_LABEL_BLUE;
        p = prim(10, z);
        if (!p) return;
        p[1] = rgb(c, c, c, 0x2C);  // POLY_FT4, opaque
        p[2] = (y << 16) | (x & 0xFFFF);                                   p[3] = clut(cx) << 16 | v << 8 | SH_LABEL_U;
        p[4] = (y << 16) | ((x + SH_LABEL_W) & 0xFFFF);                    p[5] = tpage(1, 0) << 16 | v << 8 | (SH_LABEL_U + SH_LABEL_W - 1);
        p[6] = ((y + SH_LABEL_H) << 16) | (x & 0xFFFF);                    p[7] = (v + SH_LABEL_H - 1) << 8 | SH_LABEL_U;
        p[8] = ((y + SH_LABEL_H) << 16) | ((x + SH_LABEL_W) & 0xFFFF);     p[9] = (v + SH_LABEL_H - 1) << 8 | (SH_LABEL_U + SH_LABEL_W - 1);
    }
}
