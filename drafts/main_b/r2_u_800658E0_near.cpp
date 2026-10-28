/* main_b round 2: near misses in u_800658E0 (helper attempts). Not built.
   func_8006C29C  2 diffs  final store `D_800B4D00 = vcall()` is emitted by retail as the `lui $at; sw %lo` assembler macro (store flavour of the LUI block); code otherwise exact
   func_8006C4EC  7 diffs  s0/s1 swapped (arg b vs &v temp at sp+0x50); everything else exact
   func_8006692C  21 diffs  a1/a2 swapped: retail keeps the loaded header ptr in a1 (magic checks, h[8], +0x10) and the copy in a2 (all other entry loads); mine allocates them the other way
   func_800667C8  88 diffs  same pattern as 8006692C (8 entries, o=self->0x48 loaded early); not tuned further
   func_80065B5C  32 diffs  structure/stack layout exact using asm-label struct-returning aliases (temps reuse slots); only the block-copy scratch regs differ (mine uses v0,v1,a3,t0; retail v1,a3,t0,t1)
   func_80065EE0  39 diffs  layout exact (SVq/Vq conversion classes, temps); remaining: retail keeps &x(sp+0x68) in s0 and reads x/result through pointers, mine folds to sp offsets and hoists &m
   func_800663EC  34 diffs  vbase ctor; retail copies this into v0 right after func_800198E0 and does all later stores via v0; `r = self` / inline-base-returns-this tricks did not reproduce it
   func_80070038  6 diffs  script VM op. Needs `register int result asm("$2")` (otherwise result goes to v1 and the body shifts 8 bytes / 97 diffs); remaining 6 = loop counter i and &args[i] swapped (a3<->a0) in the arg-pop loop
   skipped (vbase ctor/dtor with on-stack vtable fixup copies): func_800658E0 func_8006C65C func_80069B2C func_80068770 func_8006BFE4 func_8006AB18 func_80069264 func_80068380 func_800694BC func_8006A82C
*/
// near misses for u_800658E0; each section lists the prelude file it was tested with.

// ---- prelude from b1.cpp ----
extern "C" void func_80065AD0(void *self);
extern "C" void func_80099C60(int a, int b);
struct GW_800B4D00 { int v; int pad[2]; };
extern "C" GW_800B4D00 D_800B4D00;
extern "C" char D_800153FC[];
extern "C" char D_800153C4[];
extern "C" char D_80015414[];
extern "C" char D_80012294[];
extern "C" char D_80012224[];
extern "C" void func_80035EB4(void *p);
extern "C" void func_80035304(void *self, int b);
extern "C" int func_80036FC0(void *self, int a, int b);
extern "C" void func_80035DE0(void *p);
extern "C" void *func_80066D2C(void *self, int b);
extern "C" Vec_80066220 *func_80066220(Vec_80066220 *out, Vec_80066220 *a, Vec_80066220 *b);
extern "C" void func_8003A7FC(void *m, void *b);
extern "C" void func_8003B450(void *out, void *m, void *v);
struct SV3_80065E10 { short x, y, z; };
struct SV2_80069F74 { short w, h; };


// (prelude: b1.cpp)
//// func_8006C29C
extern "C" void func_8006C29C(void *self)
{
    func_80065AD0(self ? (char *)self + 0x50 : 0);
    func_80099C60(FIELD_AT(self, int, 0x114), FIELD_AT(self, int, 0x118));
    func_80099C80(FIELD_AT(self, int, 0x11C));
    D_800B4D00.v = ((VObj<0x2C> *)self)->v11();
}


// ---- prelude from b3.cpp ----
struct B48_658 { int w[12]; };
struct SV3_80065E10 { short x, y, z; };
extern "C" char D_80012154[];
extern "C" char D_8001201C[];
extern "C" char D_80012034[];
extern "C" char D_80011FE4[];
extern "C" char D_80012294[];
extern "C" char D_80012224[];
extern "C" char D_800153FC[];
extern "C" char D_800153C4[];
extern "C" char D_80015414[];
extern "C" void func_8006A3C0(VObj0 *self, void *b);
extern "C" void func_8006A588(VObj0 *self, void *b);
extern "C" void func_8006A440(void *self, void *b);
extern "C" void func_80098DF0(void *p);
extern "C" void func_80098DC0(void *p, int b);
extern "C" void func_8006A608(void *self, int b);
extern "C" void func_8006A6D4(void *self);
struct Sub_8007192C { int a, b, c; void *vt; };
static inline void sub_copy_8007192C(Sub_8007192C *d, const Sub_8007192C *s, void *vt)
{
    d->vt = D_800166B8;
    d->a = s->a;
    d->b = s->b;
    d->c = s->c;
    d->vt = vt;
}


// (prelude: b3.cpp)
//// func_800663EC
struct VB_800663EC { short a, b; int c; };
struct O_800663EC {
    void *vt0; void *vb; void *vt8; void *pC; char p10[0x18]; int f28; int f2C; char p30[0xC];
    void *vt3C; int p40; int f44; int f48; int f4C; int p50; int f54; int f58; int f5C; int f60;
};
extern "C" O_800663EC *func_800663EC(O_800663EC *self, int vb, int a, int b, int c, int d)
{
    if (vb) {
        VB_800663EC *v = (VB_800663EC *)((char *)self + 0x64);
        v->a = 0x10;
        self->vb = v;
        v->b = 0;
        v->c = -1;
    }
    self->vt0 = D_80012154;
    self->vt8 = D_8001201C;
    self->vt0 = D_80012034;
    self->pC = self->p10;
    func_800198E0(self->p10, 4, 0);
    O_800663EC *r = self;
    r->vt8 = D_80012294;
    r->vt0 = D_80012224;
    r->vt3C = D_80011FE4;
    r->vt8 = D_800153FC;
    r->vt3C = D_800153C4;
    r->f28 = 0;
    r->f2C = 0;
    r->vt0 = D_80015414;
    r->f44 = 0;
    r->f48 = a;
    r->f4C = b;
    r->f54 = 0;
    r->f58 = c;
    r->f5C = d;
    r->f60 = 0;
    return r;
}


// ---- prelude from b4.cpp ----
struct V4_658 { int x, y, z, w; };
extern "C" int func_80058404(void *self, int b);
extern "C" void TransRot_32(void *v0, void *v1, int *flag);
extern "C" void *func_8001ED2C(void *p, int a, int b);
extern "C" int func_800665C8(void *self);
extern "C" void func_8006AE68(void *self);
extern "C" int func_8006BA1C(void *self);
extern "C" int func_8006BA64(void *self);
extern "C" void func_8006AF94(void *self);
extern "C" void *func_800663EC(void *self, int vb, void *a, int b, int c, int d);
extern "C" void func_8003A7A4(MATRIX_B *m);
extern "C" void func_8003BBD8(MATRIX_B *m);
extern "C" Vec_8006C61C *func_8006C61C(Vec_8006C61C *out, Vec_8006C61C *a);
static inline void setm_658(MATRIX_B *m) { SetRotMatrix(m); SetTransMatrix(m); }


// (prelude: b4.cpp)
//// func_8006C4EC
extern "C" void func_8006C4EC(void *self, int b)
{
    MATRIX_B m;
    V4_658 t;
    Vec_8006C61C u;
    int flag;
    func_8003A7A4(&m);
    func_8003BBD8(&m);
    FIELD_AT(self, MATRIX_B, 0x98) = m;
    char *q = (char *)self + 0x98;
    Vec_8006C61C v = ((Vec_8006C61C (*)(void *))func_8003B310)((void *)b);
    func_8006C61C(&u, &v);
    t = *(V4_658 *)&u;
    func_8003B2F0(&m, &t);
    setm_658(&m);
    t.x = 0;
    t.y = 0;
    t.z = 0;
    t.w = 0;
    u.x = 0;
    u.y = 0;
    u.z = 0;
    u.w = 0;
    TransRot_32(&u, &t, &flag);
    func_8003B2F0(q, &t);
}

// ---- prelude from b5.cpp ----
struct Ent_658 { int off; int size; };


// (prelude: b5.cpp)
//// func_8006692C
extern "C" int func_8006692C(void *self)
{
    char *base = FIELD_AT(self, char *, 0x2C);
    char *h = base;
    if (h[0] != 'm' || h[1] != 'd' || h[2] != 't' || h[3] != '0') {
        func_80066C7C(self);
        return 0;
    }
    if (h[8] != 8) {
        return 0;
    }
    char *o = FIELD_AT(self, char *, 0x48);
    FIELD_AT(o, int, 0x4D4) = (int)base + FIELD_AT(base, int, 0xC);
    FIELD_AT(o, int, 0x4D8) = FIELD_AT(h, int, 0x10);
    FIELD_AT(o, int, 0x4DC) = (int)base + FIELD_AT(base, int, 0x14);
    FIELD_AT(o, int, 0x4E0) = FIELD_AT(base, int, 0x18);
    FIELD_AT(o, int, 0x4E4) = (int)base + FIELD_AT(base, int, 0x1C);
    FIELD_AT(o, int, 0x4E8) = FIELD_AT(base, int, 0x20);
    FIELD_AT(o, int, 0x4EC) = (int)base + FIELD_AT(base, int, 0x24);
    FIELD_AT(o, int, 0x4F0) = FIELD_AT(base, int, 0x28);
    FIELD_AT(o, int, 0x4F4) = (int)base + FIELD_AT(base, int, 0x2C);
    FIELD_AT(o, int, 0x4F8) = FIELD_AT(base, int, 0x30);
    FIELD_AT(o, int, 0x4FC) = (int)base + FIELD_AT(base, int, 0x34);
    FIELD_AT(o, int, 0x500) = FIELD_AT(base, int, 0x38);
    return 1;
}


// (prelude: b5.cpp)
//// func_800667C8
extern "C" int func_800667C8(void *self)
{
    char *base = FIELD_AT(self, char *, 0x2C);
    char *o = FIELD_AT(self, char *, 0x48);
    char *h = base;
    if (h[0] != 'm' || h[1] != 'd' || h[2] != 't' || h[3] != '0') {
        func_80066C7C(self);
        return 0;
    }
    if (h[8] != 8) {
        return 0;
    }
    FIELD_AT(o, int, 0x4DC) = (int)base + FIELD_AT(base, int, 0xC);
    FIELD_AT(o, int, 0x4E0) = FIELD_AT(h, int, 0x10);
    FIELD_AT(o, int, 0x4E4) = (int)base + FIELD_AT(base, int, 0x14);
    FIELD_AT(o, int, 0x4E8) = FIELD_AT(base, int, 0x18);
    FIELD_AT(o, int, 0x4EC) = (int)base + FIELD_AT(base, int, 0x1C);
    FIELD_AT(o, int, 0x4F0) = FIELD_AT(base, int, 0x20);
    FIELD_AT(o, int, 0x4F4) = (int)base + FIELD_AT(base, int, 0x24);
    FIELD_AT(o, int, 0x4F8) = FIELD_AT(base, int, 0x28);
    FIELD_AT(o, int, 0x4FC) = (int)base + FIELD_AT(base, int, 0x2C);
    FIELD_AT(o, int, 0x500) = FIELD_AT(base, int, 0x30);
    FIELD_AT(o, int, 0x504) = (int)base + FIELD_AT(base, int, 0x34);
    FIELD_AT(o, int, 0x508) = FIELD_AT(base, int, 0x38);
    FIELD_AT(o, int, 0x50C) = (int)base + FIELD_AT(base, int, 0x3C);
    FIELD_AT(o, int, 0x510) = FIELD_AT(base, int, 0x40);
    FIELD_AT(o, int, 0x514) = (int)base + FIELD_AT(base, int, 0x44);
    FIELD_AT(o, int, 0x518) = FIELD_AT(base, int, 0x48);
    return 1;
}


// ---- prelude from b10.cpp ----
struct V4R_658 { int v[4]; };
struct M_658 { short m[3][3]; short pad; int t[3]; };
extern V4R_658 rotv_658(const void *r) __asm__("func_8003B310");
extern void setv_658(void *a, const V4R_658 &v) __asm__("func_8003B2F0");
extern M_658 m3BC10_658(const M_658 &r) __asm__("func_8003BC10");
extern M_658 m3B35C_658(const M_658 &a, const M_658 &b) __asm__("func_8003B35C");
extern M_658 ident_658(int s) __asm__("func_8003A754");


// (prelude: b10.cpp)
//// func_80065B5C
extern "C" void func_80065B5C(void *self)
{
    setv_658((char *)self + 0x4, rotv_658((char *)self + 0x78));
    FIELD_AT(self, M_658, 0x78) = m3BC10_658(m3B35C_658(FIELD_AT(self, M_658, 0x48), m3BC10_658(FIELD_AT(self, M_658, 0x78))));
    FIELD_AT(self, M_658, 0x48) = ident_658(0x1000);
}

// ---- prelude from b12.cpp ----
static inline void vset_658(int *p, short a, short b, short c, short d) { p[0] = a; p[1] = b; p[2] = c; p[3] = d; }
struct SVq_658 {
    short x, y, z, w;
    SVq_658(const SVr_658 &o) { *(SVr_658 *)this = o; }
    SVq_658(const Vr_658 &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
    SVq_658(const SVq_658 &o) { *(SVr_658 *)this = *(const SVr_658 *)&o; }
};
struct Vq_658 {
    int x, y, z, w;
    Vq_658(const SVr_658 &o) { vset_658(&x, o.x, o.y, o.z, o.w); }
    Vq_658(const Vq_658 &o) { *(Vr_658 *)this = *(const Vr_658 *)&o; }
};
extern void m_rotq_658(MATRIX_B *m, SVq_658 r) __asm__("func_8003A7FC");
extern Vr_658 m_applyq_658(MATRIX_B *m, Vq_658 v) __asm__("func_8003B450");
extern Vr_658 rotvq_658(const void *r) __asm__("func_8003B310");
extern SVr_658 getrot_658(const void *r, int i) __asm__("func_8003BC50");
extern void setrot_658(void *r, int i, SVq_658 v) __asm__("func_8003BCB0");

// (prelude: b12.cpp)
//// func_80065EE0
extern "C" void func_80065EE0(void *self, SVr_658 *r)
{
    if (r) {
        MATRIX_B m;
        func_8003A754(&m, 0x1000);
        m_rotq_658(&m, *r);
        Vp_658 t = rotvq_658((char *)self + 0x78);
        int i = 0;
        while (1) {
            if (!(i < 3)) break;
        if ((&t.x)[i]) {
            setrot_658((char *)self + 0x78, i, m_applyq_658(&m, getrot_658((char *)self + 0x78, i)));
        }
            i++;
        }
    }
}

// ---- prelude from b9.cpp ----
extern "C" int func_8007027C(void);
extern "C" int func_80070554(void *self);
extern "C" int func_80070568(void *self, int *ret, int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13);
typedef int (*F10_80070038)(void *, int, int, int, int, int, int, int, int, int, int);
struct VM_80070038 { char pad[0x14]; int *sp; char pad2[0x2C]; short hist[16]; };


// (prelude: b9.cpp) -- uses a hard-register local (register int result asm("$2")); 6 diffs
//// func_80070038
extern "C" int func_80070038(VM_80070038 *self, int cmd, int n)
{
    int args[14];
    int ret = 0;
    register int result asm("$2");
    int i = 0;
    while (1) {
        if (!(i < n)) break;
        int v = *self->sp++;
        args[i] = v;
        i++;
    }
    switch (cmd) {
    case 0:
        ret = ((F10_80070038)func_8007027C)(self, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9]);
        result = 0;
        break;
    case 0x5A:
        return 2;
    case 0x5B:
        return 1;
    case 0x5C:
        return 3;
    case 0x78:
        ret = func_80070554(self);
        result = 0;
        break;
    case 0x3E7:
        for (i = 15; i > 0; i--) {
            self->hist[i] = self->hist[i - 1];
        }
        self->hist[0] = args[0];
        result = func_80070568(self, &ret, args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13]);
        if (result) break;
        result = 0;
        break;
    default:
        result = 0;
        break;
    }
    *--self->sp = ret;
    return result;
}
