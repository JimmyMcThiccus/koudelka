// Shadow Hearts patch: primitives and the ring transform for the Judgment Ring drawing (src/shpatch/battle/ring_*.cpp).
#ifndef SHPATCH_RING_GFX_H
#define SHPATCH_RING_GFX_H

struct T_OTs { char pad[0x10]; unsigned int len; unsigned int *tbl; };

enum { ABR_HALF = 0, ABR_ADD = 1, ABR_SUB = 2 };
#define R16(r) ((r) * 16)

// frame setup (ring_gfx.cpp)
int gfx_begin(void *ot);         // 0 if this is not the battle layer's table or no buffer is allocated
void gfx_matrix(int ry, int scale16);
unsigned int *prim(int words, int z);
void draw_mode(int z, int abr);
unsigned int rgb(int r, int g, int b, int code);
unsigned int fade(int r, int g, int b, int a);   // premultiplied by alpha 0..128, for additive blending
// ring-local point (1/16 units, 0 deg at the top, clockwise) to a packed screen xy word
unsigned int pt(int x16, int y16);
unsigned int polar(int deg, int r16);
unsigned int ray(int deg, int along16, int side16);

// parts (ring_parts.cpp)
void band(int z, int a0, int a1, int r0, int r1, unsigned int col);
void zone(int z, const ShZone *zn, int alpha);
void needle(int zc, int ze, int deg, int len16, int grow);
void trail(int z, int angle16, int alpha);
void mark(int z, int deg, int kind);

#endif
