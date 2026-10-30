// Shadow Hearts patch: the Judgment Ring's hit zones, after SH's CCircle::MakeZonePoly and RenderZone: additive Gouraud
// fans from the centre (alpha / 4) to radius 120.5, 5-degree steps with feathered ends, the strike area at 2-degree
// steps tapering by 0.5 + 0.5 cos.
#include "common.h"
#include "shpatch/ring.h"
#include "shpatch/ring_gfx.h"

// Gouraud triangle centre -> rim, additive (zones, MakeZonePoly).
static void wedge(int z, int a0, int a1, unsigned int c0, unsigned int c1, unsigned int c2)
{
    unsigned int *p = prim(7, z);
    if (!p) return;
    p[1] = c0 | 0x32000000; p[2] = (pt(0, 0));
    p[3] = c1;              p[4] = (polar(a0, R16(120) + 8));
    p[5] = c2;              p[6] = (polar(a1, R16(120) + 8));
}

// One zone: main part at 5-degree steps with feathered ends, then the strike area at 2-degree steps tapering.
void zone(int z, const ShZone *zn, int alpha)
{
    static const unsigned char kind_rgb[3][3] = {{0xE0, 0x98, 0x40}, {0x30, 0xFF, 0x04}, {0x20, 0xC8, 0xFA}};
    static const unsigned char strike_rgb[3] = {0xFF, 0x20, 0x18};
    const unsigned char *main_rgb = kind_rgb[g_ring.kind];
    int a[48], nk = 0, i, w = zn->end - zn->start - zn->strike, f = w / 5 < 5 ? w / 5 : 5;
    unsigned int col[48], centre;
    a[nk++] = zn->start;
    a[nk++] = zn->start + f;
    for (i = zn->start + 5; i < zn->start + w - f && nk < 40; i += 5) a[nk++] = i;
    a[nk++] = zn->start + w - f;
    a[nk++] = zn->start + w;
    for (i = 0; i < nk; i++) col[i] = fade(main_rgb[0], main_rgb[1], main_rgb[2], alpha);
    col[0] = 0;                                   // both ends feathered to alpha 0
    if (zn->strike) {
        int s0 = zn->end - zn->strike, g = zn->strike / 2 < 10 ? zn->strike / 2 : 10, m = (zn->strike - g + 1) / 2, k;
        for (k = 1; k <= m && nk < 46; k++) {
            int t = 2048 + (ring_cos(k * 90 / (m ? m : 1)) >> 1);  // 0.5 + 0.5 cos, Q12
            a[nk] = s0 + 2 * k;
            col[nk++] = fade(strike_rgb[0] * t >> 12, strike_rgb[1] * t >> 12, strike_rgb[2] * t >> 12, alpha);
        }
        a[nk] = zn->end;
        col[nk++] = 0;
    } else {
        col[nk - 1] = 0;
    }
    centre = fade(main_rgb[0], main_rgb[1], main_rgb[2], alpha >> 2);
    for (i = 0; i + 1 < nk; i++) wedge(z, a[i], a[i + 1], centre, col[i], col[i + 1]);
}

