#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"

/* $gp here: this file defines it (lui with the array form elsewhere) */
EXTERN_C int D_800B4ED8;

EXTERN_C void func_800658E0(S_DtorB *p, int flags)
{
    FIELD_AT(p, void **, 0x40) = D_80015364;
    p->vt2C = D_8001526C;
    p->vb->vt = (VEntB *)D_8001521C.e;
    if (!flags) {
        VTabB50 tmp = D_8001521C;
        p->vb->vt = tmp.e;
        char *q = (char *)p->vb - 0x50;
        int adj = (char *)p - q;
        tmp.e[1].d = D_8001521C.e[1].d + adj;
        tmp.e[5].d = D_8001521C.e[5].d + adj;
        tmp.e[7].d = D_8001521C.e[7].d + adj;
        tmp.e[9].d = D_8001521C.e[9].d + adj;
    }
    func_800537DC((char *)p + 0x38, 0);
    func_8005BDA4(p, 0);
    if (flags & 2)
        func_8001A610(p->vb, 0);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C void *func_80065A00(void *self)
{
    char *m;
    func_80039A14(self);
    FIELD_AT(self, void *, 0x0) = D_80015384;
    func_8003A754((char *)self + 0x48, 0x1000);
    m = (char *)self + 0x78;
    {
        int s = 0x1000;
        V4_B *v = (V4_B *)((char *)self + 0x68);
        v->x = s;
        v->y = s;
        v->z = s;
        v->w = 0;
        func_8003A754(m, s);
    }
    func_8003A754((char *)self + 0x98, 0x1000);
    ((int (*)(void *, int))func_8001AA28)(m, 0x10);
    FIELD_AT(self, int, 0xB8) = 0x808080;
    FIELD_AT(self, int, 0x44) = 1;
    FIELD_AT(self, int, 0xBC) = 1;
    return self;
}

EXTERN_C void func_80065AA0(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80015384;
    func_80039A88(self);
}

EXTERN_C void func_80065AC8(void)
{
}

EXTERN_C void func_80065AD0(void *self)
{
    MATRIX_B m;
    if (FIELD_AT(self, int, 0x44) != 0) {
        func_8003AD78((char *)self + 0x48, (char *)self + 0x2C);
        func_8003B2F0((char *)self + 0x48, (char *)self + 0x34);
        FIELD_AT(self, int, 0x44) = 0;
    }
    if (FIELD_AT(self, int, 0xBC) != 0) {
        func_8003BC10(&m, (char *)self + 0x98);
        SetColorMatrix(&m);
        SetBackColor(FIELD_AT(self, unsigned char, 0xB8), FIELD_AT(self, unsigned char, 0xB9), FIELD_AT(self, unsigned char, 0xBA));
        FIELD_AT(self, int, 0xBC) = 0;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80065B5C);

EXTERN_C void func_80065C64_def(void *self, int b) asm("func_80065C64");
EXTERN_C void func_80065C64_def(void *self, int b)
{
    MATRIX_B m;
    MATRIX_B m2;
    MATRIX_B *mp;
    func_8003B35C(&m, (char *)self + 0x78, b);
    mp = &m;
    SetLightMatrix(mp);
    func_8003B3EC(&m2, (char *)self + 0x48, b);
    *mp = m2;
    SetRotMatrix(ScaleMatrix(mp, (char *)self + 0x68));
    SetTransMatrix(mp);
}

EXTERN_C void func_80065D20(void *self, int i, short a, short b, short c, int d, int e, int f)
{
    V_8006B928 t;
    SV3_80065E10 *r = (SV3_80065E10 *)((char *)self + 0x78);
    int o = i * 6;
    short *p = (short *)((char *)r + o); char *bb = (char *)self + 0x98; short *q = (short *)(bb + o); p[0] = a; p[1] = b; p[2] = c; q[0] = d << 4; q[1] = e << 4; q[2] = f << 4;
    V_8006B928 v = ((V_8006B928 (*)(void *))func_8003B310)(r);
    t = v;
    t.v[i] = 1;
    v = t;
    func_8003B2F0(r, &v);
}

EXTERN_C void func_80065E10(void *self, int i)
{
    V_8006B928 t;
    SV3_80065E10 *r = (SV3_80065E10 *)((char *)self + 0x78);
    int o = i * 6; SV3_80065E10 *a = (SV3_80065E10 *)((char *)r + o); char *bb = (char *)self + 0x98; SV3_80065E10 *b = (SV3_80065E10 *)(bb + o);
    a->x = 0;
    a->y = 0;
    a->z = 0;
    b->x = 0;
    b->y = 0;
    b->z = 0;
    V_8006B928 v = ((V_8006B928 (*)(void *))func_8003B310)(r);
    t = v;
    t.v[i] = 0;
    v = t;
    func_8003B2F0(r, &v);
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80065EE0);

extern Vr_658 f_80066054(void *self, Vr_658 *c) __asm__("func_80066054");
Vr_658 f_80066054(void *self, Vr_658 *c)
{
    MATRIX_B m;
    func_8003A754(&m, 0x1000);
    m_rot_658(&m, sv_neg_658((SVr_658 *)((char *)self + 0x2C)));
    return m_apply_658(&m, c ? v_sub_658(c, (Vr_658 *)((char *)self + 0x34)) : v_neg_658((Vr_658 *)((char *)self + 0x34)));
}

extern Vr_658 v_addr_658(const Vr_658 &a, const Vr_658 *b) __asm__("func_80066220");
extern void m_rotp_658(MATRIX_B *m, const void *r) __asm__("func_8003A7FC");
extern Vr_658 m_applyp_658(MATRIX_B *m, const Vr_658 *v) __asm__("func_8003B450");
extern Vp_658 f_80066128(void *self, Vr_658 *c) __asm__("func_80066128");
Vp_658 f_80066128(void *self, Vr_658 *c)
{
    if (c) {
        MATRIX_B m;
        func_8003A754(&m, 0x1000);
        m_rotp_658(&m, (char *)self + 0x2C);
        return v_addr_658(m_applyp_658(&m, c), (Vr_658 *)((char *)self + 0x34));
    }
    return *(Vr_658 *)((char *)self + 0x34);
}

EXTERN_C void *func_800661F4(void *self, int b)
{
    func_80066054(self, b, 0);
    return self;
}

EXTERN_C Vec_80066220 *func_80066220(Vec_80066220 *out, Vec_80066220 *a, Vec_80066220 *b)
{
    int x = a->x + b->x;
    int y = a->y + b->y;
    int z = a->z + b->z;
    int w = a->w;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
    return out;
}

EXTERN_C Vec_80066260 *func_80066260(Vec_80066260 *out, Vec_80066260 *a)
{
    int x = -a->x;
    int y = -a->y;
    int z = -a->z;
    int w = a->w;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
    return out;
}

EXTERN_C Vec_80066294 *func_80066294(Vec_80066294 *out, Vec_80066294 *a, Vec_80066294 *b)
{
    int x = a->x - b->x;
    int y = a->y - b->y;
    int z = a->z - b->z;
    int w = a->w;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
    return out;
}

EXTERN_C SVec_800662D4 *func_800662D4(SVec_800662D4 *out, SVec_800662D4 *a)
{
    short x = -a->x;
    short y = -a->y;
    short z = -a->z;
    short w = a->w;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = w;
    return out;
}

EXTERN_C void *func_80066308(void *self, int b)
{
    func_80066128(self, b);
    return self;
}

EXTERN_C void *func_80066330(void *self, int b, int c)
{
    func_80066054(self, b, c);
    return self;
}

EXTERN_C void *func_80066358(void *self)
{
    return (char *)self + 0xB8;
}

EXTERN_C void func_80066360(void *self, Word_80066360 *src)
{
    FIELD_AT(self, Word_80066360, 0xB8) = *src;
    FIELD_AT(self, int, 0xBC) = 1;
}

EXTERN_C void *func_80066380(void *self)
{
    return (char *)self + 0x68;
}

EXTERN_C void func_80066388(void *self, Quad_80066388 *src)
{
    Quad_80066388 q = *src;
    FIELD_AT(self, Quad_80066388, 0x68) = q;
}

EXTERN_C void *func_800663D4(void *self)
{
    return (char *)self + 0x48;
}

EXTERN_C void *func_800663DC(void *self)
{
    return (char *)self + 0x98;
}

EXTERN_C void *func_800663E4(void *self)
{
    return (char *)self + 0x78;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_800663EC);

EXTERN_C void func_800664F8(void *self, int flags)
{
    FIELD_AT(self, void *, 0x8) = D_800153FC;
    FIELD_AT(self, void *, 0x3C) = D_800153C4;
    FIELD_AT(self, void *, 0x0) = D_80015414;
    if (FIELD_AT(self, void *, 0x44) != 0) {
        func_80035EB4(FIELD_AT(self, void *, 0x44));
        VObj0 *o = FIELD_AT(self, VObj0 *, 0x44);
        if (o != 0) {
            o->v02(3);
        }
    }
    FIELD_AT(self, void *, 0x8) = D_80012294;
    FIELD_AT(self, void *, 0x0) = D_80012224;
    func_80035304(self, 0);
    if (flags & 1) {
        __builtin_delete(self);
    }
}

EXTERN_C int func_800665BC(void *self)
{
    return FIELD_AT(self, int, 0x28);
}

EXTERN_C int func_800665C8(void *self)
{
    if (FIELD_AT(self, void *, 0x44) != 0) {
        func_80035EB4(FIELD_AT(self, void *, 0x44));
        VObj0 *o = FIELD_AT(self, VObj0 *, 0x44);
        if (o != 0) {
            o->v02(3);
        }
        FIELD_AT(self, void *, 0x44) = 0;
    }
    if (func_80036FC0(self, FIELD_AT(self, int, 0x58), FIELD_AT(self, int, 0x5C))) {
        func_8003546C(self, self ? (char *)self + 0x3C : 0);
        func_8003714C(self);
        return 1;
    }
    void *p = func_80066D2C(__builtin_new(8), (int)self);
    FIELD_AT(self, void *, 0x44) = p;
    func_80035DE0(p);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80066690);

EXTERN_C void func_80066798(void *self)
{
    if (FIELD_AT(self, int, 0x60) == 0) {
        func_80066C7C(self);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_800667C8);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006692C);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80066A54);

EXTERN_C int func_80066AF0(void *self)
{
    char *o = 0;
    char *h = FIELD_AT(self, char *, 0x2C);
    void *p = FIELD_AT(self, void *, 0x48);
    char *base = h;
    if (p) o = (char *)p - 0x124;
    if (h[0] != 'b' || h[1] != 'g' || h[2] != 'm' || h[3] != '0') {
        func_80066C7C(self);
        return 0;
    }
    if (h[8] != 2) {
        return 0;
    }
    h += 0xC;
    FIELD_AT(o, int, 0x234) = (int)base + ((int *)h)[0];
    FIELD_AT(o, int, 0x238) = ((int *)h)[1];
    h += 8;
    FIELD_AT(o, int, 0x23C) = (int)base + ((int *)h)[0];
    FIELD_AT(o, int, 0x240) = ((int *)h)[1];
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80066BC0);

EXTERN_C int func_80066C7C(void *self)
{
    switch (FIELD_AT(self, int, 0x4C)) {
    case 2:
        FIELD_AT(FIELD_AT(self, char *, 0x48), int, 0x670) = 1;
        break;
    case 4:
        FIELD_AT(FIELD_AT(self, char *, 0x48), int, 0x56C) = 1;
        break;
    case 7: {
        char *g = FIELD_AT(self, char *, 0x48);
        char *o = g ? g - 0x124 : 0;
        FIELD_AT(o, int, 0x230) = 1;
        break;
    }
    case 6:
        FIELD_AT(FIELD_AT(self, char *, 0x48), int, 0x678) = 1;
        break;
    case 3:
        FIELD_AT(FIELD_AT(self, char *, 0x48), int, 0x628) = 1;
        break;
    }
    return 1;
}

EXTERN_C void func_80066D14(void *self)
{
    FIELD_AT(self, int, 0x60) = 1;
}

EXTERN_C int func_80066D20(void *self)
{
    return FIELD_AT(self, int, 0x48);
}

EXTERN_C void *func_80066D2C(void *self, int b)
{
    FIELD_AT(self, void *, 0x0) = D_800154B4;
    FIELD_AT(self, int, 0x4) = b;
    return self;
}

EXTERN_C void func_80066D44(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_800154B4;
    if (flags & 1) {
        operator delete(self);
    }
}

EXTERN_C void func_80066D78(void *self)
{
    func_80066C7C(FIELD_AT(self, void *, 0x4));
}

EXTERN_C void func_80066D9C(void)
{
}

EXTERN_C void *func_80066DA4(void *self, int b, int c, int d, int e)
{
    FIELD_AT(self, void *, 0x0) = D_800154D4;
    FIELD_AT(self, int, 0x4) = b;
    FIELD_AT(self, int, 0xC) = c;
    FIELD_AT(self, int, 0x8) = d;
    if (d == 0) {
        FIELD_AT(self, int, 0x8) = FIELD_AT(self, int, 0x4);
    }
    FIELD_AT(self, int, 0x10) = e;
    return self;
}

EXTERN_C void func_80066DDC(void *self, int b)
{
    FIELD_AT(self, void *, 0x0) = D_800154D4;
    func_8001D024(self, b);
}

EXTERN_C int func_80066E04(void *self)
{
    Mgr_800A4544 *m = &D_800A4544;
    void *o;
    func_8001D150(m, (o = operator new(0x14),
                                FIELD_AT(o, void * volatile, 0x0) = D_80010178,
                                FIELD_AT(o, int, 0x4) = 0,
                                FIELD_AT(o, void * volatile, 0x0) = D_80010338,
                                FIELD_AT(o, void *, 0x8) = self,
                                FIELD_AT(o, short, 0xC) = 0x80,
                                FIELD_AT(o, int, 0x10) = 1,
                                o));
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80066E7C);

EXTERN_C int func_80066F8C(void)
{
    return func_8008C928(0) == 0;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800154B4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800154D4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800154EC);

EXTERN_C void *func_80066FB0_def(void *self, int a, int b, int c, int d)
{
    FIELD_AT(self, void *, 0x0) = D_800154EC;
    FIELD_AT(self, int, 0x8) = a;
    FIELD_AT(self, int, 0x10) = b;
    FIELD_AT(self, int, 0xC) = c;
    if (c == 0) {
        FIELD_AT(self, int, 0xC) = FIELD_AT(self, int, 0x8);
    }

    FIELD_AT(self, int, 0x14) = d;
    switch (b) {
    case 0x65:
    case 0x6B:
    case 0x6C:
        FIELD_AT(self, int, 0x4) = 0xFF;
        break;
    case 0x6F:
        func_8008E70C_v(FIELD_AT((char *)D_800B4ED8, void *, 0x248), 0xF0);
    case 0x66:
    case 0x69:
    case 0x6A:
    case 0x6D:
    case 0x6E:
        FIELD_AT(self, int, 0x4) = 0;
        break;
    }
    char *g = (char *)D_800B4ED8;
    func_8006A4E4_v(FIELD_AT(g, void *, 0x250), FIELD_AT(self, unsigned char, 0x4));
    func_8006BD34_v(g);
    return self;
}

EXTERN_C void func_8006707C(void *self, int b)
{
    FIELD_AT(self, void *, 0x0) = D_800154EC;
    func_8001D024(self, b);
}

EXTERN_C int func_800670A4(void *self)
{
    char *l;
    char *p;
    if (FIELD_AT(self, int, 0x14) == 0x70) {
        func_800C0920();
    }
    l = (char *)&D_800A4544;
    p = (char *)__builtin_new(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010338;
    FIELD_AT(p, short, 0xC) = 0x80;
    FIELD_AT(p, void *, 0x8) = self;
    FIELD_AT(p, int, 0x10) = 1;
    func_8001D150(l, p);
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80067134);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015560);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015570);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015580);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015594);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800155AC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800155BC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800155CC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800155D8);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800155E4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800155F0);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800155FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015608);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015614);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015620);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_8001562C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015640);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015654);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015668);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015678);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015688);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015694);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800156B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015700);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015720);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015750);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015790);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800157E0);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015800);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015830);
