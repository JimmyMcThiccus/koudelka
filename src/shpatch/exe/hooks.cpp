// Shadow Hearts patch, EXE part (docs/SH_PATCH_DESIGN.md 2.5). Linked over dead EXE code (func_80033F9C..) by
// tools/patch/build.py; func_80086B70 and func_80086CAC detour here (src/shpatch/detours.txt).
//
// Both are the u_80085168.cpp originals plus one step: while a Judgment Ring result is live, a change to one of
// the action's targets is scaled. With g_shRing.active == 0 they behave exactly like the originals.
#include "shpatch/shpatch.h"

ShRingCtx g_shRing;
void (*g_shFrameHook)(void);
void (*g_shDrawHook)(void *ot);

#define S16(p, o) (*(short *)((char *)(p) + (o)))
#define U16(p, o) (*(unsigned short *)((char *)(p) + (o)))
#define U8(p, o) (*(unsigned char *)((char *)(p) + (o)))
#define S8(p, o) (*(signed char *)((char *)(p) + (o)))

// An attack's targets are the fighters on the other side from the caster (stat + 0xBD = fighter b4BD, 1 party /
// 2 monsters), so counters and reflections stay unscaled. Magic and items scale every HP change (heals land on the
// caster's side), and every MP change but the caster's own (the cost).
static int is_target(void *stat)
{
    return g_shRing.caster && (g_shRing.any_side || U8(stat, 0xBD) != U8(g_shRing.caster, 0xBD));
}

static int ring_scale(void *stat, int v, int mp)
{
    int s;
    if (!g_shRing.active || v == 0 || !is_target(stat)) {
        return v;
    }
    if (mp && stat == g_shRing.caster) {
        return v;  // the spell's own MP cost
    }
    s = v * g_shRing.scale;
    s = s < 0 ? -(-s >> 8) : s >> 8;
    if (s == 0 && g_shRing.scale != 0) {
        s = v < 0 ? -1 : 1;
    }
    return s;
}

EXTERN_C void func_80086B70_sh(void *self, int v)
{
    int n;
    short *h;
    g_shTrace[SH_TRACE_HP]++;
    v = ring_scale(self, v, 0);
    if (v < -0x7FFF) {
        v = -0x7FFF;
    } else if (v > 0x7FFF) {
        v = 0x7FFF;
    }
    if (U16(self, 0x14) & 0x200) {
        v /= 2;
        if (!(-v < S16(self, 0x10))) {
            v = -S16(self, 0x10) + 1;
        }
    }
    if (U8(self, 0x6D) & 1) {
        if (!(-v < S16(self, 0x10))) {
            v = -S16(self, 0x10) + 1;
        }
    }
    h = (short *)((char *)self + 0x6) + S8(self, 0x76);
    n = v;
    if (*h != -0x8000) {
        n = v + *h;
        if (n < -0x7FFF) {
            n = -0x7FFF;
        } else if (n > 0x7FFF) {
            n = 0x7FFF;
        }
    }
    *h = n;
    if ((U8(self, 0x6D) & 2) && v > 0) {
        v = 0;
    }
    v += S16(self, 0x10);
    if (v < 0) {
        v = 0;
    } else if (v > S16(self, 0x12)) {
        v = S16(self, 0x12);
    }
    S16(self, 0x10) = v;
}

EXTERN_C void func_80086CAC_sh(void *self, int v)
{
    int n;
    short *h;
    g_shTrace[SH_TRACE_MP]++;
    v = ring_scale(self, v, 1);
    if (v < -0x7FFF) {
        v = -0x7FFF;
    } else if (v > 0x7FFF) {
        v = 0x7FFF;
    }
    if (U16(self, 0x14) & 0x100) {
        if (S16(self, 0x20) < -v) {
            v = -S16(self, 0x20);
        }
    }
    h = (short *)((char *)self + 0x16) + S8(self, 0x76);
    n = v;
    if (*h != -0x8000) {
        n = v + *h;
        if (n < -0x7FFF) {
            n = -0x7FFF;
        } else if (n > 0x7FFF) {
            n = 0x7FFF;
        }
    }
    *h = n;
    if ((U8(self, 0x6D) & 2) && v > 0) {
        v = 0;
    }
    v += S16(self, 0x20);
    if (v < 0) {
        v = 0;
    } else if (v > S16(self, 0x22)) {
        v = S16(self, 0x22);
    }
    S16(self, 0x20) = v;
}

// The once-per-frame buffer swap (u_8002C90C.cpp), plus the patch's frame hook. In battle the game logic is event
// driven, so nothing in BATTLE runs every frame while a menu waits; the ring needs a tick, and this is it. It runs in
// the main loop after the swap, outside any list traversal, so the hook may start actions and create objects.
EXTERN_C int D_800B4CF0;
EXTERN_C char D_800AC7F8[];  // DISPENV[2], 0x14 bytes each
EXTERN_C char D_800AC740[];  // DRAWENV[2], 0x5C bytes each
EXTERN_C void *PutDispEnv(void *env);
EXTERN_C void *PutDrawEnv(void *env);

EXTERN_C void func_8002D1E0_sh()
{
    PutDispEnv(D_800AC7F8 + D_800B4CF0 * 0x14);
    PutDrawEnv(D_800AC740 + D_800B4CF0 * 0x5C);
    if (g_shFrameHook) {
        g_shFrameHook();
    }
}

// The OT submit (u_8002DED8.cpp): the patch's draw hook may add primitives to the table just before DrawOTag.
EXTERN_C void func_8002E814_orig(void *ot);

EXTERN_C void func_8002E814_sh(void *ot)
{
    if (g_shDrawHook) {
        g_shDrawHook(ot);
    }
    func_8002E814_orig(ot);
}
