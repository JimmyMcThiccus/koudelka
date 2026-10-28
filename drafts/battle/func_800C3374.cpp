// WIP: same log-byte problem as func_800C30F0 (125 differing)
#include "common.h"
#include "battle/battle.h"
struct VB30 { char pad[0x9C]; virtual ~VB30(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual int m11(void *); };
struct S30F0 {
    char pad0[0x2A0]; B2A0 b2A0; char pad2A4[0x16C];
    short s410; char pad412[0x9B]; char b4AD; char b4AE; char pad4AF[0xD]; signed char b4BC; char pad4BD[0x25]; short s4E2; char pad4E4; signed char b4E5; char pad4E6[0x10];
    short a4F6[5]; short s500; short s502; short s504; signed char b506; char pad507; unsigned short h508; signed char b50A; char pad50B; short s50C; char pad50E[8]; signed char b516;
};
inline B2A0 *base_of(S30F0 *s) { return s ? &s->b2A0 : 0; }

//@ func_800C3374 wip
EXTERN_C int func_800C3374(S30F0 *self, S30F0 *other) {
    if (self->s4E2 != 2 || !other) return 0;
    {
        if (other == self) {
            if (self->b4E5) return ((VB30 *)((char *)self + 0x400))->m11(other);
            self->b50A = 0;
        }
        G2ECC *g = D_AF470_2ECC[0];
        int d = self->b506 != 0;
        int a = (self->b4BC << 4) | 3;
        int e = (self->s502 + 1 == self->s500);
        int b = other ? other->b4BC : 0xFF;
        int c = e ? 0x82 : 2;
        for (int i = 0x1F; i > 0; i--) g->t[i] = g->t[i - 1];
        g->t[0].b[0] = a; g->t[0].b[1] = b; g->t[0].b[2] = c; g->t[0].b[3] = d;
        if (!self->s410) { self->b4AD = 0; self->b4AE = 0; }
        if (self->s502 + 1 == self->s500) func_80085C00(self);
        if (!self->b506) func_8008299C(base_of(self), 5, (self->s502 + 1) != self->s500, 0, 0, 0, 0);
        else func_8008299C(base_of(self), 5, 1, 0, 0, 0, 0);
        self->a4F6[self->s502] = 2;
        if (other->s50C != 1) func_80082C68(base_of(self), 0x21, D_AF470_2ECC[0], 0x2035, 2);
        else func_80082D44(base_of(self), 0x22, base_of(other), 0, 0);
        func_80082E14(base_of(self), 0);
        if (self->s504) self->h508++;
        self->s502++;
    }
    return 0;
}
