// EXPERIMENT (not for landing): 15 differ, same size. Uses NORMAL split declarations for D_80010888/D_800108A0 plus an
// ADDRESSOF "ghost loop" that vanishes from the final code but sets loop.c's moved_once, halving the sprite loop's
// insn budget: `int zz = 0; touch(zz);` (touch(int&) is an empty inline -> zz becomes ADDRESSOF; cse1 can't fold zz
// across the operator new call), then `for (int k = zz; k; k--) D_ksmall = 5;` after the D_80010178 store. loop.c scans
// it as a real loop and moves `li 5` (moved_once); purge_addressof + cse2 then fold zz == 0 and jump deletes the loop.
// Result: only the D_80010178 pair is hoisted, D_80010888/D_800108A0 stay split in the loop (as in retail).
// The 15 remaining diffs are scheduling: the ghost's leftover LOOP notes + exit label form a sched barrier, so
// `sw s5,0(s0)` (D_80010178 store) and the f2BC load are placed before it instead of after the D_80010888 store.
// D_kdummy/D_ksmall are fake symbols (do not land).
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
EXTERN_C const int D_80010888_s[] asm("D_80010888");
EXTERN_C const int D_800108A0_s[] asm("D_800108A0");
EXTERN_C int D_kdummy[]; EXTERN_C int D_ksmall;
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
inline void touch(int &x) { }
inline void w_init(Obj20C *o) { o->vptr = D_80010178; o->f4 = 0; }
inline void m_init(Obj20C *o) { w_init(o); o->vptr = D_800106EC; o->f8 = 0; o->fA = 0; }
inline void n_init(Obj20C *o, char *p) { m_init(o); o->vptr = D_80010624; func_80021F48(o, p); }
inline Obj20C *n_new(Obj20C *o, char *p) { m_init(o); o->vptr = D_80010624; func_80021F48(o, p); return o; }

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
        int zz = 0; touch(zz);
        Sprite *t = (Sprite *)operator new(0x20);
        void *own = self->f2BC;
        t->vptr = D_80010178;
        for (int k = zz; k; k--) D_ksmall = 5;
        t->f4 = 0;
        t->vptr8 = D_80010888_s;
        t->vptr = D_800108A0_s;
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
