// Shadow Hearts patch: loading the Judgment Ring's textures (docs/SH_PATCH_DESIGN.md 2.3).
//
// tools/patch/build.py appends the texture blob (tools/patch/sh_ring_tex.py) to BATTLE.BIN, so the overlay load puts it
// at the start of the EFFECT/BIM slot, 0x800D5DAC. The battle manager's constructor (func_800C56A8, called once per
// battle right after the load) loads the BIM block over that slot, so its detour uploads the blob to VRAM first.
#include "common.h"
#include "shpatch/shpatch.h"
#include "shpatch/ring_tex.h"

struct ShRect { short x, y, w, h; };
EXTERN_C int LoadImage(ShRect *r, unsigned int *p);
EXTERN_C int DrawSync(int mode);
EXTERN_C int func_800C56A8_orig(void *mgr);

int g_shRingTex;

EXTERN_C int func_800C56A8_sh(void *mgr)
{
    unsigned char *blob = (unsigned char *)0x800D5DAC;
    int i, n;
    g_shRingTex = 0;
    if (*(unsigned int *)blob == 0x47524853) {  // "SHRG"
        n = *(unsigned short *)(blob + 4);
        for (i = 0; i < n; i++) {
            unsigned char *e = blob + 8 + 12 * i;
            LoadImage((ShRect *)e, (unsigned int *)(blob + *(unsigned int *)(e + 8)));
        }
        DrawSync(0);  // the transfer must finish before the BIM block lands on top of the blob
        g_shRingTex = 1;
    }
    return func_800C56A8_orig(mgr);
}
