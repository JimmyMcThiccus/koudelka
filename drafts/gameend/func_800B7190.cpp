// func_800B7190 (GameEnd vtable D_800B6F5C slot 2): loads the ending graphics.
// Best attempt: 87 of 235 instructions differ (try_compile, 948 vs 940 bytes; same with -G0 and -G8).
// Everything else lines up, including the inline vptr stores, the 0x200-byte copy
// with its alignment test, and the stack layout of the Point temporary and f2.
//
// What still differs:
// 1. D_800A4534+0xC: GCC folds the load into lui %hi(sym+12) / lw %lo(sym+12).
//    Retail has lui/addiu/lw 0xC with the lui in the beqz delay slot. The EXE never
//    loads D_800A4534+0xC folded (42 uses, all via a base register).
//    A local pointer at function scope gives the unfolded form, but then the address
//    is computed before the branch. Inline functions with a pointer parameter do the same.
// 2. loop.c hoists &D_80010888 and &D_800108A0 (lui/addiu pairs, savings 2,
//    life 2, 53 loop insns) into s6/s7, so the frame saves s0-s7 instead of s0-s5.
//    Retail keeps them in the loop, which needs a higher insn count or unsplit
//    addresses (-mno-split-addresses stops the hoisting but changes other code).
// 3. Retail has 24 bytes of locals, this has 16. The Point temporary sits at
//    sp+0x1C, the second word of an 8-byte slot that f2 reuses at sp+0x18.
//
// Compile with scratch_c-style headers (types below plus include/gameend/gameend.h).

#include "common.h"
#include "gameend/gameend.h"

struct PointP { short x, y; };
struct File { char *data; void *h; };
struct Obj20C { const void *vptr; int f4; short f8, fA; };
struct Sprite { const void *vptr; int f4; const void *vptr8; void *fC; PointP f10; short f14, f16; int f18; short f1C, f1E; };
struct Big { const VEntry *vt0; char pad4[0xC]; const VEntry *vt10; };
struct Item3 { virtual void v1(); virtual void v2(); virtual void v3(); };
struct S800A4534 { int pad0[3]; int fC; };
struct Blk200 { char d[0x200]; };

EXTERN_C S800A4534 D_800A4534;
EXTERN_C Big *D_800B4C38[];
EXTERN_C int D_800B4C48[];
EXTERN_C int D_800B4ED8[];
EXTERN_C const int D_80010178[], D_800106EC[], D_80010624[], D_80010888[], D_800108A0[];
EXTERN_C void func_8005F238(File *);
EXTERN_C void func_8005F248(File *, int);
EXTERN_C char *func_8005F28C(File *);
EXTERN_C void func_8005F298(File *, int, int);
EXTERN_C void func_8005F3E0(File *);
EXTERN_C void func_80021F48(Obj20C *, char *);
EXTERN_C void func_80024BF0(Sprite *, char *, int, int);
EXTERN_C void func_80025444(int *, Sprite *, int);
EXTERN_C void *func_80056E0C(void *, int);
EXTERN_C void func_80056FBC(void *, int, int);
EXTERN_C void func_80056FE0(void *);
EXTERN_C void func_8006BDE0(int);
EXTERN_C void func_8005388C(BaseC *, int);
EXTERN_C void *func_8008D1F4(void *, int);
EXTERN_C void func_8008C928(int);
EXTERN_C void func_8008ECB4(void *);
EXTERN_C void func_8008EF40(int);
EXTERN_C void func_800566E4(BaseA *);

// Nested inline constructors: separate `this` pseudos keep both vptr stores.
inline void w_init(Obj20C *o) { o->vptr = D_80010178; o->f4 = 0; }
inline void m_init(Obj20C *o) { w_init(o); o->vptr = D_800106EC; o->f8 = 0; o->fA = 0; }
inline void n_init(Obj20C *o, char *p) { m_init(o); o->vptr = D_80010624; func_80021F48(o, p); }

EXTERN_C void func_800B7190(GameEnd *self)
{
    int n;
    if (self->f2A8) {
        S800A4534 *g = &D_800A4534;
        n = (g->fC & 3) + 1;
    } else
        n = 0;
    File f;
    func_8005F238(&f);
    func_8005F298(&f, n * 49 + 0x1521F, 0x18800);
    char *p = func_8005F28C(&f);
    p += 0x10;
    Obj20C *o = (Obj20C *)operator new(0x20C);
    n_init(o, p);
    p += 0x200;
    self->f2BC = o;
    Big *b = D_800B4C38[0];
    b->vt10[1].pfn((char *)b + b->vt10[1].delta);
    for (unsigned int i = 0; i < 3; i++) {
        Sprite *t = (Sprite *)operator new(0x20);
        t->vptr8 = D_80010888;
        t->vptr = D_80010178;
        t->f4 = 0;
        t->vptr = D_800108A0;
        t->fC = self->f2BC;
        struct { PointP a, b; } r;
        r.b.x = -1;
        r.b.y = -1;
        t->f10 = r.b;
        t->f14 = 0;
        t->f16 = 0;
        t->f18 = 0;
        t->f1E = 0;
        func_80024BF0(t, p, 0x80, 0x100);
        self->f2B0[i] = t;
        func_80025444(D_800B4C48, t, 0);
        ((Item3 *)self->f2B0[i])->v3();
        p += 0x8000;
    }
    func_8005F3E0(&f);
    self->f2AC = func_80056E0C(operator new(0xB4), 1);
    func_80056FBC(self->f2AC, 0x3C, 1);
    func_80056FE0(self->f2AC);
    func_8006BDE0(D_800B4ED8[0]);
    func_8005388C(self, 0x1C);
    {
        File f2;
        func_8005F238(&f2);
        func_8005F298(&f2, 0x15314, 0x4000);
        self->f2C0 = func_8008D1F4(func_8005F28C(&f2), 0);
        func_8008C928(0x10);
        func_8005F298(&f2, 0x1531C, 0x800);
        *(Blk200 *)self->fA8 = *(Blk200 *)func_8005F28C(&f2);
        func_8005F3E0(&f2);
        func_8008ECB4(self->fA8);
        if (self->f2A8)
            func_8008EF40((self->fBC << 16) | 1);
        func_800566E4(self);
        func_8005F248(&f2, 2);
    }
    func_8005F248(&f, 2);
}
