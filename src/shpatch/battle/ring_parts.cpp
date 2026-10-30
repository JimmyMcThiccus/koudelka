// Shadow Hearts patch: the Judgment Ring's band, trail (MakeBlurPoly) and press marks (MakeRenderMark).
#include "common.h"
#include "shpatch/ring.h"
#include "shpatch/ring_gfx.h"

// Semi-transparent flat quad between two radii over [a0, a1].
void band(int z, int a0, int a1, int r0, int r1, unsigned int col)
{
    unsigned int *p = prim(6, z);
    if (!p) return;
    p[1] = col | 0x2A000000;  // POLY_F4, semi-transparent
    p[2] = (polar(a0, r0)); p[3] = (polar(a0, r1)); p[4] = (polar(a1, r0)); p[5] = (polar(a1, r1));
}

// Trail (MakeBlurPoly): the last 8 needle positions, 1/100 s apart (2.25 degrees at 1.6 s a turn), alpha 96 -> 12.
void trail(int z, int angle16, int alpha)
{
    for (int i = 0; i < 8; i++) {
        int a0 = (angle16 - i * 36) >> 4, a1 = (angle16 - (i + 1) * 36) >> 4;
        if (a1 < 0) break;
        unsigned int *p = prim(5, z);
        if (!p) return;
        p[1] = fade(0x20, 0xFF, 0x80, (8 - i) * 12 * alpha >> 7) | 0x22000000;  // POLY_F3, semi-transparent
        p[2] = (pt(0, 0)); p[3] = (polar(a0, R16(120))); p[4] = (polar(a1, R16(120)));
    }
}

// Press mark (MakeRenderMark): a thin spoke to the rim with an arrow tip at 124.
void mark(int z, int deg, int kind)
{
    static const unsigned int cols[3] = {0x808080, 0xFFFFFF, 0x0040FF};  // miss grey, hit white, strike FF,40,00
    unsigned int c = cols[kind], *p = prim(9, z);
    if (!p) return;
    p[1] = c | 0x38000000; p[2] = (ray(deg, 0, -8));
    p[3] = c;              p[4] = (ray(deg, 0, 8));
    p[5] = c;              p[6] = (ray(deg, R16(120), -16));
    p[7] = c;              p[8] = (ray(deg, R16(124), 0));
}

