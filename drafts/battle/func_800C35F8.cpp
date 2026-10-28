// WIP: same log-byte problem as func_800C30F0 (156 differing; rest of the body matches)
#include "common.h"
#include "battle/battle.h"
struct VB35 { char pad[0x9C]; virtual ~VB35(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual int m11(void *); };
struct G35 { char pad[0x3B0]; W4 t[0x20]; char pad430[0x138]; int f568; };
EXTERN_C G35 *D_AF470_35[] __asm__("D_800AF470");
struct S35F8 {
    char pad0[0x2A0]; B2A0 b2A0; char pad2A4[0x16C];
    short s410; char pad412[0x9B]; char b4AD; char b4AE; char pad4AF[0xD]; signed char b4BC; signed char b4BD; char pad4BE[0x24]; short s4E2; char pad4E4; signed char b4E5; char pad4E6[0x10];
    short a4F6[5]; short s500; short s502; short s504; signed char b506; char pad507; unsigned short h508; signed char b50A; char pad50B; short s50C; char pad50E[8]; signed char b516;
};
inline B2A0 *base_of(S35F8 *s) { return s ? &s->b2A0 : 0; }
//@ func_800C35F8 v1
EXTERN_C int func_800C35F8(S35F8 *self, S35F8 *other) {
    if (self->s4E2 != 2 || !other) return 0;
    if (other == self) {
        if (self->b4E5) return ((VB35 *)((char *)self + 0x400))->m11(other);
        self->b50A = 0;
    }
    G35 *g = D_AF470_35[0];
    int d = self->b506 != 0;
    int a = (self->b4BC << 4) | 3;
    int e = (self->s502 + 1 == self->s500);
    int b = other ? other->b4BC : 0xFF;
    int c = e ? 0x83 : 3;
    for (int i = 0x1F; i > 0; i--) g->t[i] = g->t[i - 1];
    g->t[0].b[0] = a; g->t[0].b[1] = b; g->t[0].b[2] = c; g->t[0].b[3] = d;
    int code = 6;
    if (!self->s410) {
        self->b4AD = 0; self->b4AE = 0;
        if (self->b4BD == 2) {
            code = 0x32;
            if (D_AF470_35[0]->f568 == 3) self->b506 = 0;
        }
    }
    func_80085C00(self);
    if (!self->b506) func_8008299C(base_of(self), code, (self->s502 + 1) != self->s500, 0, 0, 0, 0);
    else func_8008299C(base_of(self), code, 1, 0, 0, 0, 0);
    if (self->b4BD == 1) {
        if (self->s410) func_8008299C(base_of(self), 0x18, 0x15, 0, 0, 0, 0);
        else func_8008299C(base_of(self), 0, 2, 0, 0, 0, 0);
    }
    self->a4F6[self->s502] = 3;
    if (other->s50C != 1) func_80082C68(base_of(self), 0x21, D_AF470_35[0], 0x2035, 2);
    else func_80082D44(base_of(self), 0x22, base_of(other), 0, 0);
    func_80082E14(base_of(self), 0);
    if (self->s504) self->h508++;
    self->s502++;
    return 0;
}
