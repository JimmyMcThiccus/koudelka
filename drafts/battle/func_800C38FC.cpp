// NEAR (21 differing): second normalisation of the bool byte (sltu t0,zero,v1 before the shift loop) missing; reg alloc of e/b/c/d differs
#include "common.h"
#include "battle/battle.h"

struct S38FC;
struct T_38FC_A { char pad[0x10]; short s10; char pad12[0x8A]; };
struct T_38FC_V : T_38FC_A {
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual int v11(S38FC *a); virtual void v12(); virtual void v13(); virtual int v14(S38FC *a);
};
struct G38FC { char pad[0x32C]; void *f32C; char pad330[0x80]; W4 t[0x20]; };
struct T_38FC_E { short delta; short index; int (*pfn)(void *, void *); };
struct T_38FC_VT { T_38FC_E e[16]; };
struct S38FC {
    char pad0[0x2A0]; B2A0 b2A0; char pad2A4[0x15C]; T_38FC_A a400; T_38FC_VT *vt49C;
    char pad4A0[0xD]; char b4AD; char b4AE; char pad4AF[0xD]; signed char b4BC; signed char b4BD; char pad4BE[8];
    short s4C6; short pad4C8; short s4CA; char pad4CC[0x16]; short s4E2; char pad4E4; signed char b4E5; char pad4E6[0x10];
    short a4F6[5]; short s500; short s502; short s504; signed char b506; char pad507; unsigned short h508; signed char b50A; char pad50B; short s50C;
};
EXTERN_C G38FC *D_38FC[] __asm__("D_800AF470");
EXTERN_C int func_800C5F08(void *p, int a, int b);
EXTERN_C int func_800C5CC4(void *p, int a, int b, int c);
inline B2A0 *base_of(S38FC *s) { return s ? &s->b2A0 : 0; }

//@ func_800C38FC best
EXTERN_C int func_800C38FC(S38FC *self, S38FC *other) {
    if (self->s4E2 != 2 || !other) return 0;
    if (self->b4BD == 2 && self->a400.s10 == 0) {
        T_38FC_VT *vt = self->vt49C;
        char *base = (char *)self + 0x400;
        return vt->e[14].pfn(base + vt->e[14].delta, other);
    }
    if (other == self) {
        if (self->b4E5) {
        T_38FC_VT *vt = self->vt49C;
        char *base = (char *)self + 0x400;
            return vt->e[11].pfn(base + vt->e[11].delta, self);
        }
        self->b50A = 0;
    }
    G38FC *g = D_38FC[0];
    int e = self->s502 + 1 == self->s500;
    char d = self->b506 != 0;
    int a = (self->b4BC << 4) | 3;
    int b = other ? other->b4BC : 0xFF;
    int c = e ? 0x84 : 4;
    for (int i = 0x1F; i > 0; i--) g->t[i] = g->t[i - 1];
    g->t[0].b[0] = a; g->t[0].b[1] = b; g->t[0].b[2] = c; g->t[0].b[3] = d != 0;
    if (!self->a400.s10) { self->b4AD = 0; self->b4AE = 0; }
    func_80085C00(self);
    int s1 = self->s4CA;
    int s3 = self->s4C6;
    if (self->b4BD == 1) s1 = s1 + 1; else s1 = s1 - 1;
    if (func_800C5F08(D_38FC[0]->f32C, s3, s1) == 0) {
        if (self->b506 == 0) func_8008299C(base_of(self), 7, self->s502 + 1 != self->s500, 0, 0, 0, 0);
        else func_8008299C(base_of(self), 7, 1, 0, 0, 0, 0);
        func_800C5CC4(D_38FC[0]->f32C, self->b4BC, s3, s1);
        self->a4F6[self->s502] = 4;
    } else {
        if (self->b506 == 0) func_8008299C(base_of(self), 6, self->s502 + 1 != self->s500, 0, 0, 0, 0);
        else func_8008299C(base_of(self), 6, 1, 0, 0, 0, 0);
        self->a4F6[self->s502] = 3;
    }
    if (self->b4BD == 1) {
        if (self->a400.s10 != 0) func_8008299C(base_of(self), 0x18, 0x15, 0, 0, 0, 0);
        else func_8008299C(base_of(self), 0, 2, 0, 0, 0, 0);
    }
    if (other->s50C != 1) func_80082C68(base_of(self), 0x21, D_38FC[0], 0x2035, 2);
    else func_80082D44(base_of(self), 0x22, base_of(other), 0, 0);
    func_80082E14(base_of(self), 0);
    if (self->s504) self->h508++;
    self->s502++;
    return 0;
}
