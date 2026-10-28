// ~180 differ (size 740 vs 724): logic believed right but loop-invariant hoisting differs (retail keeps 2, 0xA, D_80010178 in $s5/$fp/$s7 and 'running' in $s4 with the test 'v0=s4; beqz v0' at the loop top; continues jump there). NOTE: needs func_8001ED2C to return a pointer (unit declares it void).
#include "common.h"
#include "effect/effect.h"

struct S_800D9D68_Clock {
    int pad[3];
    volatile unsigned int ticks;
};
EXTERN_C S_800D9D68_Clock D_800A4534;
EXTERN_C int D_80010300[];
EXTERN_C int D_800102D0[];
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *self, void *obj);
EXTERN_C void *func_8001ED2C(void *self, int a, int b);
EXTERN_C void func_800DAD28(void *self);
EXTERN_C void func_800DA170(SlotSet *self);
EXTERN_C void func_800DB054(void *self);
EXTERN_C int func_800DAD80(SlotSet *self);
EXTERN_C void func_800DBC98(void *self, void *arg, void *one);

inline void *operator new(unsigned int, void *p) { return p; }

struct B0_800D9D68 {
    int *vt;
    int f4;
    B0_800D9D68() { vt = D_80010178; f4 = 0; }
};
struct Msg_800D9D68 : B0_800D9D68 {
    short f8, fA;
    void *fC;
    int f10;
    Msg_800D9D68(short a, short b, void *c, int d) { vt = D_80010300; f8 = a; fA = b; f10 = d; fC = c; vt = D_800102D0; }
};

typedef void (*Fn_800D9D68)(void *);

inline void post_800D9D68(SlotSet *self, int d)
{
    void *g = FIELD_AT(self, void *, 0x98);
    func_8001EFE4(g, new (func_8001CA10(0x14)) Msg_800D9D68(2, 0xA, 0, d));
}

EXTERN_C void func_800D9D68(SlotSet *self)
{
    int running;
    Poly *e;
    void *p;
    FIELD_AT(self, int, 0x14C) = D_800A4534.ticks & ~1;
    FIELD_AT(self, int, 0x144) = FIELD_AT(D_800B4ED8[0], int, 0x278);
    running = 1;
    while (running) {
        e = (Poly *)func_8001ED2C(self, 1, 1);
        if (e) {
            if (FIELD_AT(e, unsigned short, 0xA) == 2 && FIELD_AT(e, int, 0x10) == 0) {
                post_800D9D68(self, 3);
                p = D_800B4ED8[0];
                FIELD_AT(p, int, 0x278) = FIELD_AT(self, int, 0x144);
                FIELD_AT(p, int, 0x26C) = 0;
                running = 0;
            }
            ((Fn_800D9D68)e->vptr[2].pfn)((char *)e + e->vptr[2].delta);
            continue;
        }
        if (FIELD_AT(self, signed char, 0x164)) {
            unsigned int now;
            int n;
            int i;
            int flag;
            now = D_800A4534.ticks & ~1;
            n = (now - FIELD_AT(self, int, 0x14C)) >> 1;
            func_800DAD28(self);
            for (i = 0; i < n; i++)
                func_800DA170(self);
            func_800DB054(self);
            flag = 0;
            if (func_800DAD80(self) && !FIELD_AT(self, int, 0x154) && !D_800E5840[0])
                flag = D_800E5844[0] == 0;
            if (flag) {
                unsigned int t0;
                func_800DBC98(self, 0, 0);
                t0 = D_800A4534.ticks;
                while (D_800A4534.ticks - t0 < 61) {
                    e = (Poly *)func_8001ED2C(self, 1, 1);
                    if (e)
                        ((Fn_800D9D68)e->vptr[2].pfn)((char *)e + e->vptr[2].delta);
                }
                post_800D9D68(self, 0);
                FIELD_AT(self, int, 0x154) = 1;
            }
            FIELD_AT(self, int, 0x14C) = now;
        }
    }
}
