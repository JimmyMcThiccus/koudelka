// Shadow Hearts patch: loading the Judgment Ring's textures (docs/SH_PATCH_DESIGN.md 2.3).
//
// tools/patch/build.py appends the texture blob (tools/patch/sh_ring_tex.py) to BATTLE.BIN, so the overlay load puts it
// at the start of the EFFECT/BIM slot, 0x800D5DAC. The battle manager's constructor (func_800C56A8, called once per
// battle right after the load) loads the BIM block over that slot, so its detour copies the blob to the heap first.
//
// The VRAM the textures go to is free at a battle's first menu, but effects load their own texture pages there later
// (a Heal overwrote all of x 640..703, y 256..511). So the copy stays for the whole battle and every ring re-uploads it;
// no effect runs during a ring. The copy is freed when the battle is won or lost (turn.cpp), or else when the next battle
// starts; the heap is set up once at boot (func_80018B88), so a copy left from the last battle is still valid then.
#include "common.h"
#include "shpatch/shpatch.h"
#include "shpatch/ring_tex.h"

struct ShRect { short x, y, w, h; };
EXTERN_C int LoadImage(ShRect *r, unsigned int *p);
EXTERN_C int func_800C56A8_orig(void *mgr);

int g_shRingTex;
unsigned char *g_shRingTexCopy;  // the battle's copy of the blob (tools/patch/build.py --inject sets it too)

void ring_tex_free(void)
{
    g_shRingTex = 0;
    if (g_shRingTexCopy) {
        operator delete(g_shRingTexCopy);
        g_shRingTexCopy = 0;
    }
}

// Queue every rectangle of the blob for upload. The GPU runs the transfers before the frame's drawing.
void ring_tex_upload(void)
{
    int i, n;
    if (!g_shRingTexCopy) return;
    n = *(unsigned short *)(g_shRingTexCopy + 4);
    for (i = 0; i < n; i++) {
        unsigned char *e = g_shRingTexCopy + 8 + 12 * i;
        LoadImage((ShRect *)e, (unsigned int *)(g_shRingTexCopy + *(unsigned int *)(e + 8)));
    }
}

EXTERN_C int func_800C56A8_sh(void *mgr)
{
    unsigned int *blob = (unsigned int *)0x800D5DAC;
    int i, n, size = 0;
    ring_tex_free();
    if (blob[0] == 0x47524853) {  // "SHRG"
        n = *(unsigned short *)((char *)blob + 4);
        for (i = 0; i < n; i++) {  // the blob ends where its last rectangle's data ends
            short *e = (short *)((char *)blob + 8 + 12 * i);
            int end = *(int *)(e + 4) + e[2] * e[3] * 2;
            if (end > size) size = end;
        }
        g_shRingTexCopy = (unsigned char *)operator new(size);
        if (g_shRingTexCopy) {
            for (i = 0; i < size / 4; i++) ((unsigned int *)g_shRingTexCopy)[i] = blob[i];
            ring_tex_upload();
            g_shRingTex = 1;
        }
    }
    return func_800C56A8_orig(mgr);
}
