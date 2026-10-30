// Shadow Hearts patch: the Judgment Ring's textured layers, after SH's CCircle::Render, RenderShadow and RenderLight.
//
// SH draws each art layer as a square of half-size `sizetbl` units centred on texel `centertbl`, through the ring
// matrix (the shadow and light at twice the scale): shadow subtractive, the four ring layers blended, the light
// additive (success endings only). The transform is affine, so one textured quad per layer maps exactly.
#include "common.h"
#include "shpatch/ring.h"
#include "shpatch/ring_gfx.h"
#include "shpatch/ring_tex.h"

struct Layer { unsigned char page_b, u, v, size, centre, clut, abr, twice; };
static const Layer s_layers[] = {
    {0, 0, 144, 78, 80, 1, ABR_SUB, 1},     // shadow (raster 4)
    {0, 144, 112, 68, 72, 0, ABR_ADD, 0},   // ring0
    {0, 144, 0, 104, 112, 0, ABR_ADD, 0},   // ring1
    {1, 0, 0, 124, 128, 0, ABR_ADD, 0},     // ring2
    {0, 0, 0, 140, 144, 0, ABR_ADD, 0},     // ring3
    {1, 128, 0, 72, 72, 2, ABR_ADD, 1},     // light (raster 5)
};
static const unsigned short s_clut_x[3] = {SH_CLUT_RING, SH_CLUT_SHADOW, SH_CLUT_LIGHT};

static unsigned int tpage(int page_b, int abr) { return (abr << 5) | ((SH_TEX_Y & 256) >> 4) | ((page_b ? SH_TEX_PAGE_B : SH_TEX_PAGE_A) >> 6); }
static unsigned int clut(int x) { return (SH_CLUT_Y << 6) | (x >> 4); }

static void layer(int z, const Layer *l, int r, int g, int b)
{
    int s = R16(l->size) << l->twice, u0 = l->u + ((l->centre - l->size) >> 1), u1 = l->u + ((l->centre + l->size) >> 1);
    int v0 = l->v + ((l->centre - l->size) >> 1), v1 = l->v + ((l->centre + l->size) >> 1);
    unsigned int *p = prim(10, z);
    if (!p) return;
    p[1] = rgb(r, g, b, 0x2E);  // POLY_FT4, semi-transparent
    p[2] = pt(-s, -s); p[3] = clut(s_clut_x[l->clut]) << 16 | v0 << 8 | u0;
    p[4] = pt(s, -s);  p[5] = tpage(l->page_b, l->abr) << 16 | v0 << 8 | u1;
    p[6] = pt(-s, s);  p[7] = v1 << 8 | u0;
    p[8] = pt(s, s);   p[9] = v1 << 8 | u1;
}

void ring_tex_layers(int z, int alpha, int light)
{
    int i;
    layer(z + 1, &s_layers[0], 0x80 * alpha >> 7, 0x80 * alpha >> 7, 0x80 * alpha >> 7);
    for (i = 1; i <= 4; i++) layer(z, &s_layers[i], 0x70 * alpha >> 7, 0x80 * alpha >> 7, 0x70 * alpha >> 7);
    if (light) {  // SH cycles the light through hsvtbl; one pale gold here
        layer(z, &s_layers[5], 0x80 * light >> 7, 0x70 * light >> 7, 0x40 * light >> 7);
    }
}

