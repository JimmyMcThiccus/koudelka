// Shadow Hearts patch: the Judgment Ring's textures in VRAM, uploaded from the blob tools/patch/sh_ring_tex.py builds
// (SH's TEXTURE/BT/BTLDATA.BIN art at half size). Keep in step with the layout in that script.
#ifndef SHPATCH_RING_TEX_H
#define SHPATCH_RING_TEX_H

#define SH_TEX_PAGE_A 640  // 4 bpp texture pages, y 256
#define SH_TEX_PAGE_B 704
#define SH_TEX_Y 256
#define SH_CLUT_Y 511
#define SH_CLUT_RING 640   // additive, x0.75
#define SH_CLUT_SHADOW 656 // subtractive, x7/8
#define SH_CLUT_LIGHT 672  // additive alpha ramp
#define SH_CLUT_LABEL_RED 688   // label colours (rows of SH's label CLUT): Miss
#define SH_CLUT_LABEL_BLUE 704  // Good, Great, Nice, Cool, Perfect, Hit
#define SH_CLUT_LABEL_CYAN 720  // Strike
#define SH_LABEL_U 128     // labels: 60x12 cels stacked in page B from (128, 72)
#define SH_LABEL_V 72
#define SH_LABEL_W 60
#define SH_LABEL_H 12
enum { SH_LBL_MISS, SH_LBL_GOOD, SH_LBL_GREAT, SH_LBL_NICE, SH_LBL_COOL, SH_LBL_PERFECT, SH_LBL_HIT, SH_LBL_STRIKE };

EXTERN_C int g_shRingTex;  // nonzero once the textures are in VRAM (otherwise the ring draws a flat band)
void ring_tex_layers(int z, int alpha, int light);
void ring_labels(int z);

#endif
