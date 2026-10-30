// Shadow Hearts patch: the Judgment Ring's needle, after SH's CCircle::MakeBarPoly and UpdateBarVertex: an opaque centre
// strip with additive soft edges, 3 units wide at the hub and about 6 at the tip, white turning 20,FF,80 as it grows.
#include "common.h"
#include "shpatch/ring.h"
#include "shpatch/ring_gfx.h"

// Needle (MakeBarPoly): opaque centre strip, additive soft edges; length 0..120 as it grows in.
void needle(int zc, int ze, int deg, int len16, int grow)
{
    // white -> 20,FF,80 as it grows (MakeBarPoly colT)
    int r = 255 + ((0x20 - 255) * grow >> 4), g = 255, b = 255 + ((0x80 - 255) * grow >> 4);
    unsigned int *p = prim(9, zc);
    if (p) {
        p[1] = rgb(r, g, b, 0x38); p[2] = (ray(deg, 0, -8));
        p[3] = rgb(r, g, b, 0);    p[4] = (ray(deg, 0, 8));
        p[5] = rgb(r, g, b, 0);    p[6] = (ray(deg, len16, -17));
        p[7] = rgb(r, g, b, 0);    p[8] = (ray(deg, len16, 17));
    }
    for (int side = -1; side <= 1; side += 2) {
        p = prim(9, ze);
        if (!p) return;
        p[1] = rgb(r / 2, g / 2, b / 2, 0x3A); p[2] = (ray(deg, 0, 8 * side));
        p[3] = 0;                               p[4] = (ray(deg, 0, 24 * side));
        p[5] = rgb(r / 2, g / 2, b / 2, 0);    p[6] = (ray(deg, len16, 17 * side));
        p[7] = 0;                               p[8] = (ray(deg, len16, 50 * side));
    }
}

