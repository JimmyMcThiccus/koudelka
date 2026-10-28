// 4 of 235 differ (try_compile, same size), two scheduling swaps only: before the loop retail has `addu a1,s0` before `addiu s2,s2,0x200`; in the loop retail has `lui %hi(D_80010888)`, `lw v1,0x2BC(s4)`, `addiu` (the lw sits INSIDE the lui/addiu pair).
// k4: the second swap probably can't come from the small-object alias trick: GCC emits `la` as ONE insn (the
// assembler expands it), so the scheduler can't put the lw between lui and addiu. Retail therefore had a split
// HIGH/LO_SUM pair for D_80010888 in the loop that loop.c did not hoist, i.e. the real cause is still the
// threshold (loop insn count) effect. The alias trick reproduces everything else.
// Hoisting: D_80010888/D_800108A0 aliased as small (<= 8 byte) objects -> unsplit `la`, never hoisted.
// Layout: the Point is the 2nd half of an 8-byte block local and a 2nd dead 8-byte local makes 24 bytes of locals
// (retail: point at sp+0x1C, f2 reusing sp+0x18). `r.b.y = r.b.x = -1` keeps the -1 pseudo at life 2 (not hoisted).
#include "common.h"
#include "gameend/gameend.h"

struct PointE { short x, y; };
struct PointC { short x, y; PointC() {} PointC(short a, short b) { x = a; y = b; } };
struct File { char *data; void *h; };
struct Obj20C { const void *vptr; int f4; short f8, fA; };
struct Sprite { const void *vptr; int f4; const void *vptr8; void *fC; PointC f10; short f14, f16; int f18; short f1C, f1E; };
struct Big { const VEntry *vt0; char pad4[0xC]; const VEntry *vt10; };
struct Item3 { virtual void v1(); virtual void v2(); virtual void v3(); };
struct S800A4534 { int pad0[3]; volatile unsigned int fC; };
struct Blk200 { char d[0x200]; };

EXTERN_C S800A4534 D_800A4534;
EXTERN_C Big *D_800B4C38[];
EXTERN_C int D_800B4C48[];
EXTERN_C int D_800B4ED8[];
EXTERN_C const int D_80010178[], D_800106EC[], D_80010624[];
EXTERN_C const int D_80010888_s asm("D_80010888");
EXTERN_C const int D_800108A0_s asm("D_800108A0");
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

inline void setPosE(Sprite *p, PointE v) { *(PointE *)&p->f10 = v; }
inline void setPosXY(Sprite *p, short a, short b) { PointE v; v.x = a; v.y = b; *(PointE *)&p->f10 = v; }
inline void setPosR(Sprite *p, const PointC &v) { p->f10 = v; }
inline void setPos(Sprite *p, PointC v) { p->f10 = v; }
// Nested inline constructors: separate `this` pseudos keep both vptr stores.
inline void w_init(Obj20C *o) { o->vptr = D_80010178; o->f4 = 0; }
inline void m_init(Obj20C *o) { w_init(o); o->vptr = D_800106EC; o->f8 = 0; o->fA = 0; }
inline void n_init(Obj20C *o, char *p) { m_init(o); o->vptr = D_80010624; func_80021F48(o, p); }
inline Obj20C *n_new(Obj20C *o, char *p) { m_init(o); o->vptr = D_80010624; func_80021F48(o, p); return o; }

//@unit gameend
//@func
EXTERN_C void func_800B7190(GameEnd *self)
{
    int n;
    if (self->f2A8)
        n = (D_800A4534.fC & 3) + 1;
    else
        n = 0;
    File f;
    func_8005F238(&f);
    func_8005F298(&f, n * 49 + 0x1521F, 0x18800);
    char *p = func_8005F28C(&f);
    p += 0x10;
    Obj20C *o = (Obj20C *)operator new(0x20C);
    n_init(o, p);
    p += 0x200;
    Big *b = D_800B4C38[0];
    self->f2BC = o;
    ((void (*)(void *, void *))b->vt10[1].pfn)((char *)b + b->vt10[1].delta, o);
    for (unsigned int i = 0; i < 3; i++) {
        Sprite *t = (Sprite *)operator new(0x20);
        void *own = self->f2BC;
        t->vptr = D_80010178;
        t->f4 = 0;
        t->vptr8 = &D_80010888_s;
        t->vptr = &D_800108A0_s;
        t->fC = own;
        struct { PointE a, b; } r; PointE u; r.b.y = r.b.x = -1; *(PointE *)&t->f10 = r.b;
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
