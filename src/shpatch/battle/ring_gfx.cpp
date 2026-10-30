// Shadow Hearts patch: primitives and the ring transform (see ring_draw.cpp for the SH sources).
//
// SH draws the ring in screen space, no perspective: a ring-local point (x = r sin a, y = -r cos a) is rotated by
// RotX(-20) RotZ(30) RotY(ry) and placed at (480, 160) on its 640x448 display, ring radius 120 units. Here that becomes
// (240, 86) on Koudelka's 320x240: x / 2, y * 240 / 448.
#include "common.h"
#include "shpatch/ring.h"
#include "shpatch/ring_gfx.h"

// Three tables are submitted per frame: the 3D battle layer (0x2000 entries), then two 5-entry ones; D_800B4CFC[0]
// already points at the last of those by then (read live), so the battle layer is told apart by its length.
#define SH_BATTLE_OT_LEN 0x2000
#define BUF_BYTES 0x1400

static unsigned char *s_mem;  // two primitive buffers, on the heap for the ring's lifetime
static int s_buf, s_used;
static unsigned char *s_cur;
static T_OTs *s_ot;
static int m_xx, m_xy, m_yx, m_yy;  // Q12: RotX(-20) RotZ(30) RotY(ry), restricted to the ring plane
static int s_scale;                 // Q4, 16 = 1.0

void ring_alloc_prims(void)
{
    if (!s_mem) s_mem = (unsigned char *)operator new(2 * BUF_BYTES);
}

// Freed by the turn driver, which runs well after the GPU has drawn the last frame that used the primitives.
void ring_free_prims(void)
{
    if (s_mem) {
        operator delete(s_mem);
        s_mem = 0;
    }
}

int gfx_begin(void *ot)
{
    s_ot = (T_OTs *)ot;
    if (s_ot->len != SH_BATTLE_OT_LEN || !s_mem) return 0;
    s_cur = s_mem + s_buf * BUF_BYTES;
    s_buf ^= 1;
    s_used = 0;
    return 1;
}

void gfx_matrix(int ry, int scale16)
{
    int cx = ring_cos(-20), sx = ring_sin(-20), cz = ring_cos(30), sz = ring_sin(30), cy = ring_cos(ry), sy = ring_sin(ry);
    m_xx = cz * cy >> 12;
    m_xy = -sz;
    m_yx = ((cx * sz >> 12) * cy >> 12) + (sx * sy >> 12);
    m_yy = cx * cz >> 12;
    s_scale = scale16;
}

unsigned int *prim(int words, int z)
{
    unsigned int *p;
    if (s_used + 4 * words > BUF_BYTES) return 0;
    p = (unsigned int *)(s_cur + s_used);
    s_used += 4 * words;
    p[0] = ((unsigned int)(words - 1) << 24) | (s_ot->tbl[z] & 0xFFFFFF);
    s_ot->tbl[z] = (unsigned int)p & 0xFFFFFF;
    return p;
}

// GPU E1 draw mode: blend `abr`, dither on. Added last at a depth, so it is drawn first there (reverse-linked OT).
void draw_mode(int z, int abr)
{
    unsigned int *p = prim(3, z);
    if (!p) return;
    p[1] = 0xE1000000 | (1 << 9) | (abr << 5);
    p[2] = 0xE2000000;
}

unsigned int rgb(int r, int g, int b, int code)
{
    if (r > 255) r = 255;
    if (g > 255) g = 255;
    if (b > 255) b = 255;
    return (unsigned int)code << 24 | b << 16 | g << 8 | r;
}

unsigned int fade(int r, int g, int b, int a)
{
    return rgb(r * a >> 7, g * a >> 7, b * a >> 7, 0);
}

unsigned int pt(int x16, int y16)
{
    int X, Y;
    x16 = x16 * s_scale >> 4;
    y16 = y16 * s_scale >> 4;
    X = (m_xx * x16 + m_xy * y16) >> 12;      // SH display pixels, Q4
    Y = (m_yx * x16 + m_yy * y16) >> 12;
    X = SH_RING_X + (X >> 5);                 // / 2 (640 -> 320), / 16
    Y = SH_RING_Y + ((Y * 2194 >> 12) >> 4);  // * 240 / 448
    return (unsigned short)Y << 16 | (unsigned short)X;
}

unsigned int polar(int deg, int r16)
{
    return pt(r16 * ring_sin(deg) >> 12, -(r16 * ring_cos(deg)) >> 12);
}

// A point `along` units out on the ray at `deg`, moved `side` units to its clockwise side.
unsigned int ray(int deg, int along16, int side16)
{
    int s = ring_sin(deg), c = ring_cos(deg);
    return pt((along16 * s + side16 * c) >> 12, (-along16 * c + side16 * s) >> 12);
}
