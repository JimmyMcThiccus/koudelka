// Shadow Hearts patch: the per-turn driver (docs/SH_PATCH_DESIGN.md 2.5, 4.1). func_800C6194 detours here.
// A copy of battle_b.cpp's func_800C6194 that also ends the ring context; turn flow (section 4) goes here later.
#include "common.h"
#include "shared/exe.h"
#include "battle/battle.h"
#include "shpatch/shpatch.h"
#include "shpatch/ring.h"

EXTERN_C void func_800C6194_sh(T_C6194 *p) {
    g_shTrace[SH_TRACE_TURN]++;
    // The ring's scale covers one action. Melee applies its damage inside the replayed confirm, and the driver runs
    // again only once the action has finished, so the context ends here.
    g_shRing.active = 0;
    if (g_ring.phase == SH_RING_OFF) ring_free_prims();
    if (empty_C6194(p)) return;
    if (cf_666C(p)) return;
    if (((T_C6194_x *)p)->s7DC == 0) { cf_68D8(p, -1); return; }
    if (cf_7528(p)) { cf_6DF4(p, 0); return; }
    goto start;
neg:
    cf_65C8(p, -1);
    return;
start:
    for (;;) {
        T_C6194_d *c = p->fA0;
        if (!c) { cf_65C8(p, 1); continue; }
        if (c->b46D & 0x80) {
            func_800D8FF8((char *)c + 0x400);
            int h = c->h480;
            int n = c->f4B4;
            c->f4B4 = 0;
            cf_65C8(p, n + h);
            continue;
        }
        int n;
        if (c->f4B0 == 0) {
            if (!(c->s4B8 & 0x6B)) { func_800D8FF8((char *)c + 0x400); c->f4B4 += c->h480; }
            n = c->f4B4;
            c->f4B0 = 3;
            c->s4B8 = 0;
            c->f4B4 = 0;
            cf_65C8(p, n);
            continue;
        }
        if (c->s410 == 0) {
            c->f4B0 = 3;
            c->s4B8 = 0;
            c->f4B4 = 0;
            cf_65C8(p, 1);
            continue;
        }
        {
            int r; char *s0;
            if (c->b4BC < 3) func_800538B4(c->b4BC);
            c->v15();
            cf_CA7D4(p, 0, 0, 0, 0);
            if (c->b4AD) {
                c->f4B0 &= ~2;
                r = !cf_CACD8(p, 1);
            } else if (c->b4AE) {
                c->f4B0 &= ~2;
                r = !cf_CAD5C(p);
            } else goto other;
            if (!r) return;
            c->b4AE = 0;
            c->b4AD = 0;
            func_80085E14(c);
            s0 = (char *)c + 0x2A0;
            func_8008299C(s0, 0x1A, 0, 0, 0, 0, 0);
            if (c->b4BD == 1) func_8008299C(s0, 0, 1, 0, 0, 0, 0);
            func_80082E14(s0, 0);
            cf_65C8(p, c->f4B4);
            continue;
        other:
            if (D_800B4ED8[0]->f278 != 5) cf_CFB08(p, 0);
            if (c->b4BC < 3) {
                cf_CA7D4(p, 1, -1, -1, 1);
                ((T_C6194_x *)p)->f3D0 = 1;
                int s = 0;
                if (c->f4B0 & 1) { func_800C78EC(p, s); s = cf_CA75C(p) < 2; }
                if (c->f4B0 & 2) { cf_CA9D0(p, c->f550->b16, c->f550->b17); if (!cf_CA75C(p)) s |= 2; }
                cf_CBA80(p, ((T_C6194_x *)p)->f7D8, c->f4B0, s);
                return;
            }
            func_8008299C((char *)c + 0x2A0, 0x29, 0, 0, 0, 0, 0);
            c->v16(&c->f4B0);
            func_8008299C((char *)c + 0x2A0, 0x2A, 0, 0, 0, 0, 0);
            func_80082E14((char *)c + 0x2A0, 0);
            if (c->b4AD) {
                c->f4B0 |= 2;
                if (c->b4E5) goto neg;
                cf_65C8(p, c->f4B4);
            }
            return;
        }
    }
}
