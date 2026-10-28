#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"

/* $gp here: this file defines it (lui with the array form elsewhere) */
EXTERN_C int D_800B4ED8;

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_800658E0);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80065A00);

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

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80065C64);

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

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014C68);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014C7C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014C8C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014C9C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014CAC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014CFC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014D1C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014D5C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014DAC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014DCC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014E0C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014E5C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014E7C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014EAC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014EEC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80014FFC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_8001504C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_8001506C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800150BC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800151B4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_8001521C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_8001526C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015364);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015384);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800153C4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800153FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015414);

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

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80066C7C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80066FB0);

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

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80067450);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_800674C8);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006753C);

EXTERN_C void func_80067ABC(void *self, void *b)
{
    func_80054094((char *)self + 0x64, FIELD_AT(b, unsigned char, 0x18) != 1);
    func_80067B1C(self, FIELD_AT(b, unsigned short, 0xC), (char *)b + 0x80, (char *)b + 0xE, FIELD_AT(b, unsigned char, 0x8A) & 0xF);
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80067B1C);

EXTERN_C void func_800680A0(void *self)
{
    int a = func_8005409C((char *)self + 0x64);
    int b = func_8005409C((char *)self + 0xB4);
    int c = func_8005409C((char *)self + 0x104);
    if (a || b || c) {
        func_800566E4(self);
        SV2C_80055020 pos(0x18, 0x4D);
        if (a) {
            func_80055020((char *)self + 0x64, pos);
            func_80054FC0((char *)self + 0x64);
            pos.y += FIELD_AT(func_80054F28((char *)self + 0x64), short, 0x2) + 2;
        }
        if (b) {
            func_80055020((char *)self + 0xB4, pos);
            func_80054FC0((char *)self + 0xB4);
            pos.y += FIELD_AT(func_80054F28((char *)self + 0xB4), short, 0x2) + 2;
        }
        if (c) {
            func_80055020((char *)self + 0x104, pos);
            func_80054FC0((char *)self + 0x104);
        }
        func_8008EF40(0xC);
    }
}

EXTERN_C void func_8006821C(void *self)
{
    char *p = (char *)self + 0x64;
    if (func_8005409C(p)) {
        func_80054FE0(p);
    }
    p = (char *)self + 0xB4;
    if (func_8005409C(p)) {
        func_80054FE0(p);
    }
    p = (char *)self + 0x104;
    if (func_8005409C(p)) {
        func_80054FE0(p);
    }
    func_80056874(self);
}

EXTERN_C int func_800682A0(VObj<0x18> *self, void *b)
{
    func_8001FC78(b, 0, 0);
    if (FIELD_AT(b, unsigned short, 0x18) & 0x20) {
        self->v02();
    }
    return 1;
}

EXTERN_C int func_80068310(VObj<0x18> *self, void *b)
{
    func_8001FC78(b, 0, 0);
    if (FIELD_AT(b, unsigned short, 0x18) & 0x20) {
        self->v02();
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80068380);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800156B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015700);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015720);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015750);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015790);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800157E0);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015800);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015830);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80068660);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80068770);

EXTERN_C void func_8006897C(void *self, int b, int c)
{
    if (FIELD_AT(self, unsigned short, 0x1D00) != (unsigned short)b) {
        char *h;
        FIELD_AT(self, short, 0x1D00) = b;
        h = (char *)self + 0x1C;
        func_80019D40(h ? FIELD_AT(h, List *, 0x0) : 0);
        FIELD_AT(h, int, 0x4) = 0;
    }
    FIELD_AT(self, int, 0x1CFC) = c;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_800689E0);

EXTERN_C int func_80068A50(void *self)
{
    return FIELD_AT(self, int, 0x1D04);
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80068A5C);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80068B14);

EXTERN_C void func_80068E60(void *self)
{
    FIELD_AT(self, int, 0x1D04) = 0;
    FIELD_AT(self, int, 0x20) = 0;
    ((VObj<0x18> *)self)->v04();
    if (FIELD_AT(self, unsigned short, 0x1D00) != 0 && FIELD_AT(self, int, 0x1CFC) != 0) {
        func_80063714(self, FIELD_AT(self, unsigned short, 0x1CF0) + 1);
    } else {
        func_80063714(self, FIELD_AT(self, unsigned short, 0x1CF0));
    }
    func_800631D4(self);
}

EXTERN_C void func_80068EE8(Obj_80068EE8 *self)
{
    unsigned int i;
    func_8006323C(self);
    for (i = 0; i < 0x31; i++) {
        func_80053CD8(&self->e[i]);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80068F3C);

EXTERN_C int func_800690C8(void *self, void *b)
{
    if (((int (*)(void *))func_8005618C)(b)) {
        return 1;
    }
    unsigned short fl = FIELD_AT(b, unsigned short, 0x18);
    if (fl & 0x4000) {
        if (FIELD_AT(self, int, 0x1CF8)) {
            func_8001FC78(b, 0, 0);
            FIELD_AT(D_800A4578.p, short, 0x1A4) = 3;
            FIELD_AT(self, int, 0x1D04) = 0;
            ((VObj<0x18> *)self)->v02();
            return 1;
        }
    } else if (FIELD_AT(self, int, 0x3C)) {
        if (fl & 0x10) {
            func_8001FC78(b, 0, 0);
            FIELD_AT(D_800A4578.p, short, 0x1A4) = 3;
            FIELD_AT(self, int, 0x20) = func_80058404(FIELD_AT(self, void *, 0x3C), -1);
            FIELD_AT(self, int, 0x1CF8) = 1;
        } else if (fl & 0x40) {
            func_8001FC78(b, 0, 0);
            FIELD_AT(D_800A4578.p, short, 0x1A4) = 3;
            FIELD_AT(self, int, 0x20) = func_80058404(FIELD_AT(self, void *, 0x3C), 1);
            FIELD_AT(self, int, 0x1CF8) = 1;
        }
    }
    return 1;
}

EXTERN_C void func_800691EC(Obj_800691EC *self, int i, int c)
{
    func_80054094(&self->a[i], c);
    func_80054094(&self->b[i], c);
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80069264);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_800694BC);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_800697A4);

EXTERN_C void func_80069914(VObj<0x18> *self)
{
    self->v04();
    func_80054FC0(self);
}

EXTERN_C void func_80069958(void *self)
{
    func_80054FE0(self);
}

EXTERN_C void func_80069978(O_80069978 *self, SV2C_80055020 *pp, int dx, int dy, int step)
{
    SV2C_80055020 p = *pp;
    unsigned int i = 0;
    while (1) {
        if (!(i < 8)) break;
        func_8005457C(&self->a[i], 0);
        func_80053F48(&self->a[i], p);
        func_8005457C(&self->a[i + 1], 0);
        func_80053F48(&self->a[i + 1], SV2C_80055020(p.x + dy, p.y));
        func_8005457C(&self->b[i], 0);
        func_80053F48(&self->b[i], SV2C_80055020(p.x + dx, p.y));
        func_8005457C(&self->b[i + 1], 0);
        func_80053F48(&self->b[i + 1], SV2C_80055020(p.x + dx + dy, p.y));
        p.y += step;
        i += 2;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80069B2C);

EXTERN_C void *func_80069D1C(void *self, int a, int b)
{
    char r[8];
    FIELD_AT(self, int, 0x18) = -1;
    FIELD_AT(self, short, 0x20) = 0;
    FIELD_AT(self, short, 0x22) = 0;
    FIELD_AT(self, int, 0x1C) = 0;
    FIELD_AT(self, int, 0x14) = 0;
    func_8005F238(r);
    func_8005F298(r, a, b);
    char *p = (char *)func_8005F28C(r);
    FIELD_AT(self, B16c_658, 0x0) = *(B16c_658 *)p;
    p += 0x10;
    if (FIELD_AT(self, unsigned char, 0xC) == 4) {
        func_80069ECC(self, 4, (int)p);
        f69F74_658(self, 4, SV2C_80055020(FIELD_AT(self, short, 0x8), FIELD_AT(self, short, 0xA)), p + 0x20);
    } else {
        func_80069ECC(self, 8, (int)p);
        f69F74_658(self, 8, SV2C_80055020(FIELD_AT(self, short, 0x8), FIELD_AT(self, short, 0xA)), p + 0x200);
    }
    func_8005F3E0(r);
    func_8005F248(r, 2);
    return self;
}

EXTERN_C void func_80069E60(void *self, int flags)
{
    if (FIELD_AT(self, void *, 0x14) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x14));
    }
    FIELD_AT(self, void *, 0x14) = 0;
    if (FIELD_AT(self, void *, 0x1C) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x1C));
    }
    FIELD_AT(self, void *, 0x1C) = 0;
    if (flags & 1) {
        __builtin_delete(self);
    }
}

EXTERN_C int func_80069ECC(void *self, int a, int b)
{
    int n;
    void *p;
    if (FIELD_AT(self, int, 0x18) > 0 && FIELD_AT(self, int, 0x18) != a) {
        return 0;
    }
    FIELD_AT(self, int, 0x18) = a;
    if (FIELD_AT(self, void *, 0x14) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x14));
    }
    FIELD_AT(self, void *, 0x14) = 0;
    if (b) {
        n = a == 4 ? 0x10 : 0x100;
        n *= 2;
        p = func_800A0D2C(n);
        FIELD_AT(self, void *, 0x14) = p;
        func_80025CE0(p, b, n);
    }
    return 1;
}

EXTERN_C int func_80069F74(void *self, int n, SV2_80069F74 s, void *src)
{
    int m = FIELD_AT(self, int, 0x18);
    if (m != n) {
        return 0;
    }
    FIELD_AT(self, SV2_80069F74, 0x20) = s;
    int sz = (s.w * s.h * m + 15) / 16;
    if (FIELD_AT(self, void *, 0x1C) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x1C));
    }
    FIELD_AT(self, void *, 0x1C) = func_800A0D2C(sz * 2);
    func_80025CE0(FIELD_AT(self, void *, 0x1C), (int)src, sz * 2);
}

EXTERN_C int func_8006A040(void *self)
{
    return FIELD_AT(self, int, 0x1C);
}

EXTERN_C Word_8006A04C func_8006A04C(Obj_8006A04C *self)
{
    return self->w;
}

EXTERN_C int func_8006A06C(void *self)
{
    return FIELD_AT(self, int, 0x14);
}

EXTERN_C int func_8006A078(void *self)
{
    return FIELD_AT(self, int, 0x18);
}

struct Obj_8006A084 { void *vt; int f4; short f8, fA; char pad[0x38]; int f44; int f48; };
EXTERN_C void *func_8006A084(Obj_8006A084 *self, void *b, short c, short d, int e)
{
    self->vt = D_80010178;
    self->f4 = 0;
    self->vt = D_800111BC;
    self->f8 = 0;
    self->fA = d;
    self->vt = D_800159C4;
    self->f48 = 1;
    self->f44 = e;
    func_8006A3C0((VObj0 *)self, b);
    func_8006A588((VObj0 *)self, b);
    func_8006A440(self, b);
    func_80098DF0((char *)self + 0x24);
    func_80098DF0((char *)self + 0x34);
    if (c == -1) {
        func_80098DC0((char *)self + 0x24, 0);
        func_80098DC0((char *)self + 0x34, 0);
    } else {
        func_80098DC0((char *)self + 0x24, 1);
        func_80098DC0((char *)self + 0x34, 1);
        func_8006A608(self, c);
    }
    func_8006A6D4(self);
    return self;
}

EXTERN_C void func_8006A194(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_800159C4;
    func_8001A610(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006A1BC);

EXTERN_C void func_8006A3C0(VObj0 *self, void *b)
{
    char *p;
    if (FIELD_AT(self, short, 0x8) == 1) {
        self->v08();
    }
    p = (char *)self + D_800B4CF0.value * 16;
    FIELD_AT(p, short, 0x2C) = FIELD_AT(b, short, 0x8);
    FIELD_AT(p, short, 0x2E) = FIELD_AT(b, short, 0xA);
    FIELD_AT(self, short, 0x8) = 2;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006A440);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006A4E4);

EXTERN_C void func_8006A588(VObj0 *self, void *b)
{
    char *p;
    if (FIELD_AT(self, short, 0x8) == 1) {
        self->v08();
    }
    p = (char *)self + D_800B4CF0.value * 16;
    FIELD_AT(p, short, 0x30) = FIELD_AT(b, short, 0xC);
    FIELD_AT(p, short, 0x32) = FIELD_AT(b, short, 0xE);
    FIELD_AT(self, short, 0x8) = 2;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006A608);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006A6D4);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006A784);

EXTERN_C void func_8006A80C(void *self)
{
    FIELD_AT(self, int, 0x48) = 1;
}

EXTERN_C void func_8006A818(void *self)
{
    FIELD_AT(self, int, 0x48) = 0;
}

EXTERN_C int func_8006A820(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006A82C);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006AB18);

EXTERN_C void func_8006AD40(void *self)
{
    while (1) {
        VObj0 *msg = (VObj0 *)func_8001ED2C(self ? (char *)self + 0x124 : 0, (void *)1, 1);
        if (FIELD_AT(self, int, 0x230) && FIELD_AT(self, void *, 0x2DC)) {
            func_800665C8(FIELD_AT(self, void *, 0x2DC));
            FIELD_AT(self, int, 0x230) = 0;
        }
        func_8006AE68(self);
        if (msg) {
            if (FIELD_AT(msg, unsigned short, 0xA) == 2) {
                switch (FIELD_AT(msg, int, 0x10)) {
                case 7: {
                    FIELD_AT(self, int, 0x228) = 0;
                    FIELD_AT(self, int, 0x22C) = 0;
                    void *o = func_800663EC(__builtin_new(0x6C), 1, self ? (char *)self + 0x124 : 0, 7, 0x169AA, 0x2C800);
                    FIELD_AT(self, void *, 0x2DC) = o;
                    func_800665C8(o);
                    break;
                }
                case 8:
                    func_8006BA1C(self);
                    func_8006BA64(self);
                    break;
                case 9: break;
                }
            }
            msg->v01();
        }
        func_8006AF94(self);
    }
}

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015914);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015964);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015984);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800159C4);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015A14);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015B34);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015B84);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015B9C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015BB4);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006AE68);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006AF94);

EXTERN_C void func_8006B024(void *self, int b)
{
    FIELD_AT(self, int, 0x260) = b;
    if (b < -30000) {
        FIELD_AT(self, int, 0x260) = -30000;
    }
    if (FIELD_AT(self, int, 0x260) > -5000) {
        FIELD_AT(self, int, 0x260) = -5000;
    }
}

EXTERN_C void func_8006B058(void *self, int b)
{
    int v = FIELD_AT(self, int, 0x28C);
    v += b;
    if (v > 800) {
        v = 800;
    }
    if (v < 450) {
        v = 450;
    }
    FIELD_AT(self, int, 0x28C) = v;
}

EXTERN_C void func_8006B08C(void *self, int b)
{
    int v = FIELD_AT(self, int, 0x28C);
    v -= b;
    if (v > 800) {
        v = 800;
    }
    if (v < 450) {
        v = 450;
    }
    FIELD_AT(self, int, 0x28C) = v;
}

EXTERN_C void func_8006B0C0(void *self, int b)
{
    int v = FIELD_AT(self, int, 0x260);
    v += b;
    if (v < -18000) {
        v = -18000;
    }
    if (v > -10000) {
        v = -10000;
    }
    FIELD_AT(self, int, 0x260) = v;
    func_8006B3D0(self, (char *)self + 0x2A0);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B120(void *self, int b)
{
    int v = FIELD_AT(self, int, 0x260);
    v -= b;
    if (v < -18000) {
        v = -18000;
    }
    if (v > -10000) {
        v = -10000;
    }
    FIELD_AT(self, int, 0x260) = v;
    func_8006B3D0(self, (char *)self + 0x2A0);
    FIELD_AT(self, int, 0x26C) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006B180);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006B1C8);

EXTERN_C void func_8006B210(void *self)
{
    func_8006B058(self, 14);
    func_8006B180(self, 12);
    func_8006B0C0(self, 1000);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B258(void *self, int b)
{
    func_8006B058(self, 0xE);
    func_8006B180(self, 0xC);
    func_8006B0C0(self, (short)b);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B2B0(void *self)
{
    func_8006B08C(self, 14);
    func_8006B1C8(self, 12);
    func_8006B120(self, 1000);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B2F8(void *self, int b)
{
    func_8006B08C(self, 0xE);
    func_8006B1C8(self, 0xC);
    func_8006B120(self, (short)b);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B350(void *self, int b)
{
    FIELD_AT(self, short, 0x2A2) += b;
    func_8006B3D0(self, (char *)self + 0x2A0);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B390(void *self, int b)
{
    FIELD_AT(self, short, 0x2A2) -= b;
    func_8006B3D0(self, (char *)self + 0x2A0);
    FIELD_AT(self, int, 0x26C) = 1;
}

EXTERN_C void func_8006B3D0(void *self, void *p)
{
    MATRIX_B m;
    SV4_658 r;
    V3_658 v;
    func_8003A754(&m, 0x1000);
    short x = FIELD_AT(p, short, 0x0);
    short y = FIELD_AT(p, short, 0x2);
    short z = FIELD_AT(p, short, 0x4);
    r.x = x;
    r.y = y;
    r.z = z;
    r.w = 0;
    func_8003A7FC(&m, &r);
    v.x = FIELD_AT(self, int, 0x258);
    v.y = FIELD_AT(self, int, 0x25C);
    v.z = FIELD_AT(self, int, 0x260);
    ApplyMatrixLV(&m, &v, (char *)self + 0x27C);
    int k = FIELD_AT(self, int, 0x260) + 0x6400;
    if (k != 0) {
        k = k / 7;
    }
    if (FIELD_AT(self, int, 0x268)) {
        FIELD_AT(self, int, 0x27C) += FIELD_AT(p, int, 0x8) + FIELD_AT(self, int, 0x2B8);
        FIELD_AT(self, int, 0x280) += FIELD_AT(self, int, 0x2BC);
        FIELD_AT(self, int, 0x284) += FIELD_AT(p, int, 0x10) + FIELD_AT(self, int, 0x2C0);
    } else {
        FIELD_AT(self, int, 0x27C) += FIELD_AT(p, int, 0x8);
        int t = FIELD_AT(self, int, 0x280) + 0x398;
        FIELD_AT(self, int, 0x280) = t - (FIELD_AT(p, int, 0xC) + k / 2);
        FIELD_AT(self, int, 0x284) += FIELD_AT(p, int, 0x10);
    }
    FIELD_AT(self, short, 0x290) = FIELD_AT(p, short, 0x0);
    FIELD_AT(self, short, 0x292) = FIELD_AT(p, short, 0x2);
    FIELD_AT(self, short, 0x294) = FIELD_AT(p, short, 0x4);
}

EXTERN_C int func_8006B540(void *self)
{
    void *o;
    func_8008EF40(0x13);
    func_8006BB04(self);
    o = func_8006D344(operator new(0x74), self ? (char *)self + 0x124 : 0, 0xC9, 0, 0xC8);
    FIELD_AT(self, void *, 0x224) = o;
    func_8006D8EC(o);
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", SsGetMute);

EXTERN_C int func_8006B5CC(void)
{
    return 1;
}

EXTERN_C void func_8006B5D4(void *self)
{
    void *p = FIELD_AT(self, void *, 0x224);
    if (p != 0) {
        func_8006DA60(p);
    }
    FIELD_AT(self, int, 0x278) = 5;
    FIELD_AT(self, int, 0x26C) = 0;
}

EXTERN_C void func_8006B618(void *self, int b)
{
    if (FIELD_AT(self, int, 0x274) == 0) {
        void *o;
        FIELD_AT(self, int, 0x278) = 6;
        FIELD_AT(self, int, 0x26C) = 0;
        o = func_8006C95C(operator new(0x20), self ? (char *)self + 0x124 : 0, b);
        FIELD_AT(self, void *, 0x270) = o;
        func_8006CA80(o);
        FIELD_AT(self, int, 0x274) = 1;
    }
}

EXTERN_C void func_8006B690(void *self, int b)
{
    void *p;
    if (FIELD_AT(self, int, 0x274) != 0 && FIELD_AT(self, void *, 0x270) != 0) {
        char *l = (char *)&D_800A4544;
        func_8001D324(l, func_8001D25C(l, FIELD_AT(self, void *, 0x270)));
        FIELD_AT(self, void *, 0x270) = 0;
        FIELD_AT(self, int, 0x274) = 0;
    }
    FIELD_AT(self, int, 0x278) = 6;
    FIELD_AT(self, int, 0x26C) = 0;
    p = func_8006C95C(__builtin_new(0x20), self ? (char *)self + 0x124 : 0, b);
    FIELD_AT(self, void *, 0x270) = p;
    func_8006CA80(p);
    FIELD_AT(self, int, 0x274) = 1;
}

EXTERN_C void func_8006B740(void *self, int b)
{
    if (FIELD_AT(self, int, 0x274) == 0) {
        void *o;
        FIELD_AT(self, int, 0x278) = 4;
        FIELD_AT(self, int, 0x26C) = 0;
        o = func_8006C95C(operator new(0x20), self ? (char *)self + 0x124 : 0, b);
        FIELD_AT(self, void *, 0x270) = o;
        func_8006CA80(o);
        FIELD_AT(self, int, 0x274) = 1;
    }
}

EXTERN_C void func_8006B7B8(void *self)
{
    if (FIELD_AT(self, int, 0x274) != 0) {
        FIELD_AT(self, int, 0x270) = 0;
        FIELD_AT(self, int, 0x274) = 0;
    }
}

EXTERN_C void func_8006B7D8(void *self, int b)
{
    switch (b) {
    case 0:
        func_8006B618(self, 0xC9);
        break;
    case 1:
        func_8006B618(self, 0xCA);
        break;
    }
}

EXTERN_C void func_8006B814(void *self, int b)
{
    switch (b) {
    case 0:
        func_8006B690(self, 0xCB);
        break;
    case 1:
        func_8006B690(self, 0xCC);
        break;
    }
}

EXTERN_C void func_8006B850(void *self)
{
    Tmp_8006B850 t;
    func_800BE09C(&t);
    func_800BE18C(&t, (char *)self + 0x2A0);
}

EXTERN_C void func_8006B884(void *self)
{
    FIELD_AT(self, int, 0x260) = -20000;
    FIELD_AT(self, int, 0x28C) = 500;
    FIELD_AT(self, char, 0x298) = 10;
    FIELD_AT(self, char, 0x299) = 10;
    FIELD_AT(self, char, 0x29A) = 10;
    FIELD_AT(self, int, 0x258) = 0;
    FIELD_AT(self, int, 0x25C) = 0;
    FIELD_AT(self, int, 0x27C) = 0;
    FIELD_AT(self, int, 0x280) = 0;
    FIELD_AT(self, int, 0x284) = 0;
    FIELD_AT(self, short, 0x290) = 0;
    FIELD_AT(self, short, 0x292) = 0;
    FIELD_AT(self, short, 0x294) = 0;
    FIELD_AT(self, int, 0x29C) = 0;
    FIELD_AT(self, short, 0x2A0) = 0xF6E;
    FIELD_AT(self, short, 0x2A2) = 0;
    FIELD_AT(self, short, 0x2A4) = 0;
    FIELD_AT(self, int, 0x2A8) = 0;
    FIELD_AT(self, int, 0x2AC) = 0;
    FIELD_AT(self, int, 0x2B0) = 0;
}

EXTERN_C void func_8006B8E8(void *self, int b, Blk_8006B8E8 *c)
{
    FIELD_AT(self, Blk_8006B8E8, 0x2C8) = *c;
    func_8006C3C8(self, b, c);
}

EXTERN_C void func_8006B928(void *self, int b)
{
    FIELD_AT(self, V_8006B928, 0x2C8) = func_8003B310();
    func_8006C4EC(self, b);
}

EXTERN_C void func_8006B988(void *self)
{
    char *s = self ? (char *)self + 0x124 : 0;
    char *p = (char *)func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0x10) = 8;
    FIELD_AT(p, void *, 0xC) = s;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self ? (char *)self + 0x124 : 0, p);
}

EXTERN_C int func_8006BA1C(void *self)
{
    void *p;

    func_8006BC98(self);
    p = func_800A0D2C(FIELD_AT(self, int, 0x238));
    FIELD_AT(self, void *, 0x24C) = p;
    func_80025CE0(p, FIELD_AT(self, int, 0x234), FIELD_AT(self, int, 0x238));
    return 1;
}

EXTERN_C int func_8006BA64(void *self)
{
    void *p;
    func_8006BCF4(self);
    FIELD_AT(self, int, 0x244) = func_8008D1F4(FIELD_AT(self, int, 0x23C), 0);
    if (FIELD_AT(self, int, 0x22C) != 0) {
        p = func_80066DA4(__builtin_new(0x14), self ? (int)((char *)self + 0x124) : 0, 0x66, 0, 0x64);
    } else {
        p = func_80066DA4(__builtin_new(0x14), self ? (int)((char *)self + 0x124) : 0, 0x65, 0, 0x64);
    }
    func_80066E04(p);
    return 1;
}

extern int f_8006BB04(void *self) __asm__("func_8006BB04");
int f_8006BB04(void *self)
{
    int m = FIELD_AT(func_800787B4(), int, 0x568);
    int a, b;
    if ((unsigned int)m >= 4) {
        m = 0;
    }
    if (FIELD_AT(self, int, 0x228) != m) {
        switch (m) {
        case 0:
            a = 0x169AA;
            b = 0x2C800;
            break;
        case 1:
            a = 0x16A03;
            b = 0x2B800;
            break;
        case 2:
            a = 0x16A5A;
            b = 0x2B800;
            break;
        case 3:
            a = 0x16AB1;
            b = 0x2C800;
            break;
        }
        if (FIELD_AT(self, void *, 0x2DC)) {
            FIELD_AT(FIELD_AT(self, void *, 0x2DC), int, 0x60) = 1;
            func_80036D8C(FIELD_AT(self, void *, 0x2DC));
            FIELD_AT(self, void *, 0x2DC) = 0;
        }
        FIELD_AT(self, int, 0x22C) = 1;
        void *o = func_800663EC(__builtin_new(0x6C), 1, self ? (char *)self + 0x124 : 0, 7, a, b);
        FIELD_AT(self, void *, 0x2DC) = o;
        func_800665C8(o);
        FIELD_AT(self, int, 0x228) = m;
        return 0;
    }
    if (FIELD_AT(self, void *, 0x24C) == 0) {
        return 0;
    }
    if (FIELD_AT(self, void *, 0x248) != 0) {
        return 0;
    }
    FIELD_AT(self, void *, 0x248) = func_8008E360(FIELD_AT(self, void *, 0x24C));
    func_8008E590(FIELD_AT(self, void *, 0x248), 0x60, 0);
    return 1;
}

EXTERN_C int func_8006BC98(void *self)
{
    void *p = FIELD_AT(self, void *, 0x248);
    if (p != 0) {
        func_8008E504(p);
        FIELD_AT(self, void *, 0x248) = 0;
    }
    p = FIELD_AT(self, void *, 0x24C);
    if (p != 0) {
        func_800A0D0C(p);
        FIELD_AT(self, void *, 0x24C) = 0;
    }
    return 1;
}

EXTERN_C int func_8006BCF4(void *self)
{
    void *p = FIELD_AT(self, void *, 0x244);
    if (p != 0) {
        func_8008D4C0(p);
        FIELD_AT(self, void *, 0x244) = 0;
    }
    return 1;
}

EXTERN_C int func_8006BD34(void *self)
{
    if (FIELD_AT(self, int, 0x2E0) == 0) {
        char *o = (char *)((VObj<0x2C> *)D_800A4578.p)->v11();
        char *s = FIELD_AT(self, char *, 0x250);
        char *a = FIELD_AT(o, char *, 0x64);
        if (a != 0) {
            if (FIELD_AT(s, void *, 0x4) != 0) {
                func_8001A864(a, FIELD_AT(s, void *, 0x4));
            }
            FIELD_AT(s, void *, 0x4) = a;
        }
        FIELD_AT(o, void *, 0x64) = s;
        FIELD_AT(self, int, 0x2E0) = 1;
    }
    return 1;
}

EXTERN_C int func_8006BDE0(void *self)
{
    if (FIELD_AT(self, int, 0x2E0) != 0) {
        func_8002DC34((void *)((VObj<0x2C> *)D_800A4578.p)->v11(), FIELD_AT(self, int, 0x250), 0);
        FIELD_AT(self, int, 0x2E0) = 0;
    }
    return 1;
}

EXTERN_C int func_8006BE4C(void *self)
{
    func_800670A4(func_80066FB0(operator new(0x18), self ? (char *)self + 0x124 : 0, 0x6F, 0, 0));
    return 1;
}

EXTERN_C Blk_8006BEA0 *func_8006BEA0(Blk_8006BEA0 *out, void *self)
{
    *out = FIELD_AT(self, Blk_8006BEA0, 0x2C8);
    return out;
}

EXTERN_C int func_8006BECC(void)
{
    return 1;
}

EXTERN_C int func_8006BED4(void)
{
    return 1;
}

EXTERN_C int func_8006BEDC(void *self)
{
    return FIELD_AT(self, int, 0x22C);
}

EXTERN_C void func_8006BEE8(void *self)
{
    FIELD_AT(self, int, 0x22C) = 0;
}

EXTERN_C void func_8006BEF0(void *self)
{
    FIELD_AT(self, int, 0x22C) = 1;
}

EXTERN_C void func_8006BEFC(void *self)
{
    FIELD_AT(self, int, 0x94) = 1;
}

EXTERN_C void func_8006BF08(void *self)
{
    FIELD_AT(self, int, 0x2C0) = 0;
    FIELD_AT(self, int, 0x2BC) = 0;
    FIELD_AT(self, int, 0x2B8) = 0;
}

EXTERN_C void *func_8006BF18(void *self)
{
    return (char *)self + 0x2B8;
}

EXTERN_C void func_8006BF20(void *self, int *v)
{
    FIELD_AT(self, int, 0x2B8) = v[0];
    FIELD_AT(self, int, 0x2BC) = v[1];
    FIELD_AT(self, int, 0x2C0) = v[2];
}

EXTERN_C void func_8006BF44(void *self)
{
    FIELD_AT(self, int, 0x268) = 0;
}

EXTERN_C void func_8006BF4C(void *self)
{
    FIELD_AT(self, int, 0x268) = 1;
}

EXTERN_C int func_8006BF58(void *self)
{
    return FIELD_AT(self, int, 0x278);
}

EXTERN_C void func_8006BF64(void *self, int b)
{
    FIELD_AT(self, int, 0x278) = b;
    FIELD_AT(self, int, 0x26C) = 0;
}

EXTERN_C void func_8006BF70(void *self, int b)
{
    FIELD_AT(self, int, 0x254) = b;
}

EXTERN_C int func_8006BF78(void *self)
{
    return FIELD_AT(self, int, 0x254);
}

EXTERN_C void *func_8006BF84(void *self)
{
    return (char *)self + 0x7C;
}

EXTERN_C void *func_8006BF8C(void *self)
{
    return (char *)self + 0x84;
}

EXTERN_C int func_8006BF94(void)
{
    return D_800B4ED8;
}

EXTERN_C void *func_8006BFA0(void *self)
{
    return (char *)self + 0x2A0;
}

EXTERN_C int func_8006BFA8(void *self)
{
    return FIELD_AT(self, int, 0x260);
}

EXTERN_C void func_8006BFB4(void *self, int b)
{
    FIELD_AT(self, int, 0x28C) = FIELD_AT(b, int, 0x0);
}

EXTERN_C int func_8006BFC0(void *self)
{
    return FIELD_AT(self, int, 0x28C);
}

EXTERN_C void func_8006BFCC(void *self)
{
    FIELD_AT(self, int, 0x28C) = D_800B4ED4;
}

EXTERN_C int func_8006BFD8(void)
{
    return D_800B4ED0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006BFE4);

EXTERN_C void func_8006C204(void *self)
{
    if (FIELD_AT(self, void *, 0x8) == 0) {
        char *p = (char *)__builtin_new(0x18);
        int s = FIELD_AT(self, int, 0x110);
        func_8002EEC4(p, self);
        FIELD_AT(p, void *, 0x0) = D_80015DBC;
        FIELD_AT(p, int, 0x14) = s;
        func_8002EC90(p, &D_800B4C78);
        func_8002EC40(p, &D_800B4C98);
        FIELD_AT(self, void *, 0x8) = p;
    }
    func_8002BA94(self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006C29C);

EXTERN_C void func_8006C310(void *self)
{
    func_8002BD34(self);
    ((VObj0 *)((char *)self + 0x50))->v01();
    if (FIELD_AT(self, void *, 0x78) != 0) {
        func_8003944C(FIELD_AT(self, void *, 0x78), &D_800B4D1C);
    }
}

EXTERN_C void func_8006C36C(void *self, int b, int c)
{
    FIELD_AT(self, int, 0x114) += (b - FIELD_AT(self, short, 0x10)) / 2;
    FIELD_AT(self, int, 0x118) += (c - FIELD_AT(self, short, 0x12)) / 2;
    func_8002B518(self, b, c);
}

EXTERN_C void func_8006C3C8(void *self, int b, Blk_8006B8E8 *c)
{
    MATRIX_B m;
    Vx_658 t;
    Vx_658 u;
    int flag;
    short *r = (short *)b;
    int *p = (int *)c;
    func_8003A754(&m, 0x1000);
    FIELD_AT(self, short, 0x7C) = -r[0];
    FIELD_AT(self, short, 0x7E) = -r[1];
    FIELD_AT(self, short, 0x80) = -r[2];
    func_8003AD78(&m, (char *)self + 0x7C);
    int x = -p[0];
    int y = -p[1];
    int z = -p[2];
    t.x = x;
    t.y = y;
    t.z = z;
    t.w = 0;
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
    FIELD_AT(self, int, 0x84) = t.x;
    FIELD_AT(self, int, 0x88) = t.y;
    FIELD_AT(self, int, 0x8C) = t.z;
    FIELD_AT(self, int, 0x94) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006C4EC);

EXTERN_C Vec_8006C61C *func_8006C61C(Vec_8006C61C *out, Vec_8006C61C *a)
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

EXTERN_C int func_8006C650(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006C65C);

EXTERN_C void func_8006C77C(void *self)
{
    SV2_80069F74 pos;
    if (FIELD_AT(self, void *, 0x10) == 0) {
        char *o = (char *)__builtin_new(0x68);
        VObj<0x2C> *q = FIELD_AT(FIELD_AT(self, void *, 0x4), VObj<0x2C> *, 0x4);
        int v = q ? q->v11() : 0;
        func_8002E714(o, FIELD_AT(self, int, 0x14));
        FIELD_AT(o, void *, 0x0) = D_800117A4;
        FIELD_AT(o, int, 0x18) = v;
        FIELD_AT(o, int, 0x1C) = 0;
        FIELD_AT(o, short, 0x20) = 0;
        FIELD_AT(o, short, 0x22) = 0;
        FIELD_AT(o, short, 0x24) = 0;
        FIELD_AT(o, short, 0x26) = 0;
        FIELD_AT(o, short, 0x28) = 0;
        FIELD_AT(o, short, 0x2A) = 0;
        FIELD_AT(o, int, 0x2C) = 0;
        FIELD_AT(o, int, 0x30) = 1;
        FIELD_AT(o, int, 0x64) = 0;
        FIELD_AT(self, void *, 0x10) = o;
        R8_658 *rp = (R8_658 *)((char *)self + 0x8);
        R8_658 rc = *rp;
        pos = rc.pos;
        func_8002D780(FIELD_AT(self, void *, 0x10), pos);
        func_8002D24C(FIELD_AT(self, void *, 0x10), rp);
    } else {
        func_8002DB50(FIELD_AT(self, void *, 0x10), 1);
    }
    ((VObj0 *)self)->v07(FIELD_AT(self, void *, 0x10));
}

EXTERN_C void *func_8006C8D8(void *self, void *b, int c)
{
    func_8002EEC4(self, b);
    FIELD_AT(self, void *, 0x0) = D_80015DBC;
    FIELD_AT(self, int, 0x14) = c;
    func_8002EC90(self, &D_800B4C78);
    func_8002EC40(self, &D_800B4C98);
    return self;
}

EXTERN_C void func_8006C93C(void *self)
{
    func_8002EEFC(self);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015C0C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015C5C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015C9C);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015DBC);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015E5C);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006C95C);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006C9F8);

EXTERN_C int func_8006CA80(void *self)
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

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006CAF8);

EXTERN_C int func_8006CBCC(void *self, int id)
{
    switch (id) {
    case 0xC9: {
        int dt = D_800A4534.ticks - FIELD_AT(self, int, 0xC);
        FIELD_AT(self, int, 0xC) = D_800A4534.ticks;
        int rem = FIELD_AT(self, int, 0x14) - dt;
        int rate = 0x400 / FIELD_AT(self, int, 0x10);
        FIELD_AT(self, int, 0x14) = rem;
        if (rem <= 0) {
            dt += rem;
            void *p = FIELD_AT(self, void *, 0x4);
            func_8006B350(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
            return 0;
        }
        void *p = FIELD_AT(self, void *, 0x4);
        func_8006B350(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
        return 1;
    }
    case 0xCA: {
        int dt = D_800A4534.ticks - FIELD_AT(self, int, 0xC);
        FIELD_AT(self, int, 0xC) = D_800A4534.ticks;
        int rem = FIELD_AT(self, int, 0x14) - dt;
        int rate = 0x400 / FIELD_AT(self, int, 0x10);
        FIELD_AT(self, int, 0x14) = rem;
        if (rem <= 0) {
            dt += rem;
            void *p = FIELD_AT(self, void *, 0x4);
            func_8006B390(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
            return 0;
        }
        void *p = FIELD_AT(self, void *, 0x4);
        func_8006B390(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
        return 1;
    }
    }
    return 1;
}

EXTERN_C int func_8006CD98(void *self, int id)
{
    switch (id) {
    case 0xCB: {
        int dt = D_800A4534.ticks - FIELD_AT(self, int, 0xC);
        FIELD_AT(self, int, 0xC) = D_800A4534.ticks;
        int rem = FIELD_AT(self, int, 0x14) - dt;
        short rate = 0x5208 / FIELD_AT(self, int, 0x10);
        FIELD_AT(self, int, 0x14) = rem;
        if (rem <= 0) {
            dt += rem;
            void *p = FIELD_AT(self, void *, 0x4);
            func_8006B2F8(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
            return 0;
        }
        void *p = FIELD_AT(self, void *, 0x4);
        func_8006B2F8(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
        return 1;
    }
    case 0xCC: {
        int dt = D_800A4534.ticks - FIELD_AT(self, int, 0xC);
        FIELD_AT(self, int, 0xC) = D_800A4534.ticks;
        int rem = FIELD_AT(self, int, 0x14) - dt;
        short rate = 0x5208 / FIELD_AT(self, int, 0x10);
        FIELD_AT(self, int, 0x14) = rem;
        if (rem <= 0) {
            dt += rem;
            void *p = FIELD_AT(self, void *, 0x4);
            func_8006B258(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
            return 0;
        }
        void *p = FIELD_AT(self, void *, 0x4);
        func_8006B258(p ? (char *)p - 0x124 : 0, (short)(rate * dt));
        return 1;
    }
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006CF84);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006D290);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006D344);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006D768);

EXTERN_C int func_8006D8EC(void *self)
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

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006D964);

EXTERN_C void func_8006DA60(void *self)
{
    FIELD_AT(self, int, 0x60) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006DA6C);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006DF68);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006E234);

EXTERN_C void *func_8006E73C(Obj_8006E73C *self, int a, int b, int c, int e, short f, int g)
{
    char tmp[8];
    self->vt = D_80010178;
    self->f4 = 0;
    self->vt = D_800111BC;
    self->f8 = 0;
    self->fA = e;
    self->vt = D_80015EB8;
    self->f74 = g;
    SetDrawMode((char *)self + 0xC, 0, 0, 0, 0);
    SetDrawMode((char *)self + 0x18, 0, 0, 0, 0);
    FIELD_AT(self, unsigned char, 0x27) = 9;
    FIELD_AT(self, unsigned char, 0x2B) = 0x2C;
    FIELD_AT(self, unsigned char, 0x4F) = 9;
    FIELD_AT(self, unsigned char, 0x53) = 0x2C;
    if ((unsigned short)f < 4) {
        func_80098DC0((char *)self + 0x24, 1);
        func_80098DC0((char *)self + 0x4C, 1);
    } else {
        func_80098DC0((char *)self + 0x24, 0);
        func_80098DC0((char *)self + 0x4C, 0);
    }
    func_8006EACC(self, c, f);
    func_8006EBB0(self, a);
    func_8006EC70(self, b);
    func_8002972C(tmp, 0x80, 0x80, 0x80, 1);
    func_8006EDD8(self, tmp);
    func_8006EE94(self);
    func_800198AC(tmp, 2);
    return self;
}

EXTERN_C void func_8006E8BC(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_80015EB8;
    func_8001A610(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006E8E4);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006EACC);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006EBB0);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006EC70);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006EDD8);

EXTERN_C void func_8006EE8C(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006EE94);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006EF84);

EXTERN_C int func_8006F040(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C void *func_8006F04C(void *self)
{
    FIELD_AT(self, void *, 0xA4) = D_80015FD0;
    func_8006FDD8((Obj_8006FDD8 *)((char *)self + 0x4));
    func_8006FDD8((Obj_8006FDD8 *)((char *)self + 0x34));
    func_8006FDD8((Obj_8006FDD8 *)((char *)self + 0x64));
    FIELD_AT(self, int, 0x0) = 0;
    D_800AF410.state = 0;
    D_800AF40C.v = 0;
    D_800AF408.v = 0;
    return self;
}

EXTERN_C void func_8006F0B0(void *self, int flags)
{
    FIELD_AT(self, void *, 0xA4) = D_80015FD0;
    if (flags & 1) {
        operator delete(self);
    }
}

EXTERN_C void func_8006F0E4(void *self, int b)
{
    FIELD_AT(self, int, 0x0) = b;
}

EXTERN_C void func_8006F0EC(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
}

EXTERN_C void func_8006F0F4(void *self, int b, int c, int d, int e)
{
    FIELD_AT(self, int, 0x94) = b;
    FIELD_AT(self, int, 0x98) = c;
    FIELD_AT(self, int, 0x9C) = d;
    FIELD_AT(self, int, 0xA0) = e;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006F10C);

EXTERN_C void func_8006F154(void *self)
{
    VEnt_8006F154 *vt = FIELD_AT(self, VEnt_8006F154 *, 0xA4);
    D_800AF410.state = 2;
    vt[2].pfn((char *)self + vt[2].delta, FIELD_AT(self, int, 0x98));
}

EXTERN_C void func_8006F194(void *self)
{
    D_800AF410.state = 4;
    FIELD_AT(self, B48_658, 0x64) = FIELD_AT(self, B48_658, 0x34);
    FIELD_AT(self, B48_658, 0x34) = FIELD_AT(self, B48_658, 0x4);
    ((VObj<0xA4> *)self)->v02(FIELD_AT(self, int, 0x4));
    ((VObj<0xA4> *)self)->v01(FIELD_AT(self, int, 0x9C));
}

EXTERN_C void func_8006F268(void *self)
{
    VEnt_8006F268 *vt = FIELD_AT(self, VEnt_8006F268 *, 0xA4);
    D_800AF410.state = 6;
    vt[2].pfn((char *)self + vt[2].delta, FIELD_AT(self, int, 0xA0));
}

EXTERN_C void func_8006F2A8(void *self)
{
    D_800AF410.state = 3;
    if (D_800AF408.v != 0) {
        D_800AF408.v = 0;
        func_8006F194(self);
    }
}

EXTERN_C void func_8006F2E8(void *self)
{
    D_800AF410.state = 0;
    if (D_800AF40C.v != 0) {
        D_800AF40C.v = 0;
        func_8006F10C(self);
    }
}

EXTERN_C void func_8006F31C(Obj_8006F31C *self)
{
    int *mode = &D_800AF410.state;
    *mode = 5;
    self->f3(self->b);
}

EXTERN_C void func_8006F35C(void *self)
{
    if (D_800AF40C.v != 0) {
        D_800AF40C.v = 0;
        func_8006F10C(self);
    } else if (D_800AF408.v != 0) {
        D_800AF408.v = 0;
        func_8006F194(self);
    } else {
        VEnt_8006F35C *vt = FIELD_AT(self, VEnt_8006F35C *, 0xA4);
        int a = FIELD_AT(self, int, 0x4);
        D_800AF410.state = 0;
        vt[5].pfn((char *)self + vt[5].delta, a);
    }
}

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015EA0);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015EB8);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006F3DC);

EXTERN_C int func_8006F52C(void *self, int *a, int *b)
{
    int r;

    if (D_800AF410.state == 0) {
        return 0;
    }
    r = FIELD_AT(self, int, 0x24);
    if (r <= 0) {
        r = -1;
    }
    *a = r;
    *b = FIELD_AT(self, int, 0x28);
    return 1;
}

EXTERN_C int func_8006F570(void *self, int *a, int *b)
{
    int r;

    if (D_800AF410.state == 0) {
        return 0;
    }
    r = FIELD_AT(self, int, 0x2C);
    if (r <= 0) {
        r = -1;
    }
    *a = r;
    *b = FIELD_AT(self, int, 0x30);
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006F5B4);

EXTERN_C int func_8006F630(void)
{
    switch (D_800AF410.state) {
    case 0:
    case 5:
        D_800AF410.state = 0;
        return 1;
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006F67C);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006F8B4);

EXTERN_C int func_8006FA84(void *self)
{
    if (D_800AF410.state == 5) {
        func_8006F268(self);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006FAC0);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006FCC0);

EXTERN_C Obj_8006FDD8 *func_8006FDD8(Obj_8006FDD8 *self)
{
    Sub_8006FDD8 *s;
    self->a = 0;
    self->b = -1;
    self->c = -1;
    s = &self->sub;
    s->a = 0;
    s->b = 0;
    s->c = 0;
    s->d = 0;
    self->d = -1;
    return self;
}

EXTERN_C void func_8006FE08(void *self, int b, int c, int d)
{
    FIELD_AT(self, int, 0x20) = c;
    FIELD_AT(self, int, 0x24) = d;
}

EXTERN_C void func_8006FE14(void *self, int b, int c, int d, int e, int f)
{
    FIELD_AT(self, int, 0x20) = c;
    FIELD_AT(self, int, 0x24) = d;
    FIELD_AT(self, int, 0x28) = e;
    FIELD_AT(self, int, 0x2C) = f;
}

EXTERN_C int func_8006FE30(void *self, int b, int c, int d)
{
    return FIELD_AT(self, int, 0x20) == c && FIELD_AT(self, int, 0x24) == d;
}

EXTERN_C void func_8006FE58(void *self, int b)
{
    FIELD_AT(self, int, 0x0) = b;
}

EXTERN_C void func_8006FE60(void *self, int b, int c)
{
    FIELD_AT(self, int, 0x0) = b;
    FIELD_AT(self, int, 0x8) = c;
}

EXTERN_C void func_8006FE6C(Obj_8006FE6C *self, int a, int b, Four_8006FE6C s, int h)
{
    self->a = a;
    self->b = b;
    self->s = s;
    self->h = h;
}

EXTERN_C void func_8006FEA4(Obj_8006FEA4 *self, int a, int b, int c, Four_8006FEA4 s, int h)
{
    self->a = a;
    self->b = b;
    self->c = c;
    self->s = s;
    self->h = h;
}

EXTERN_C int func_8006FEDC(void)
{
    return D_800AF410.state;
}

EXTERN_C void *func_8006FEEC(void *p)
{
    Obj_8006FEEC *self = (Obj_8006FEEC *)p;
    int i;
    short v;
    func_8007778C(self);
    func_800756F8((char *)self + 0x40);
    FIELD_AT(self, void *, 0x40) = D_80016280;
    FIELD_AT(self, void *, 0x8) = D_80016298;
    v = -1;
    for (i = 0xF; i >= 0; i--) {
        self->items[i] = v;
    }
    return self;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_8006FF50);

EXTERN_C void func_8006FFDC(void *self, int b)
{
    if (func_80077854(self, b, 0x100) != 0 && FIELD_AT(self, void *, 0x68) != 0) {
        func_80077210(FIELD_AT(self, void *, 0x68), self);
    }
    func_800766D8(FIELD_AT(self, void *, 0x64));
}

EXTERN_C void func_80070030(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80070038);

EXTERN_C int func_8007027C(void)
{
    return 0;
}

EXTERN_C int func_80070284(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x3C), int, 0xC);
}

EXTERN_C int func_80070298(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x3C), int, 0x10);
}

EXTERN_C int func_800702AC(void)
{
    return FIELD_AT(FIELD_AT(D_800AF470.p, void *, 0x328), int, 0x14C);
}

EXTERN_C int func_800702CC(void)
{
    return FIELD_AT(FIELD_AT(D_800AF470.p, void *, 0x328), int, 0x150);
}

EXTERN_C void func_800702EC(void)
{
    char *s = (char *)D_800AF470.p;
    char *v = FIELD_AT(s, char *, 0x328);
    short *q;
    v = v ? v + 0xB8 : 0;
    q = (short *)(FIELD_AT(FIELD_AT(v, char *, 0x8), char *, 0x1B8) + 0x2C);
    func_80080CC8(s, (short)SquareRoot0(q[0] * q[0] + q[1] * q[1] + q[2] * q[2]));
}

EXTERN_C int func_80070384(void)
{
    char *s = (char *)D_800AF470.p;
    char *v = FIELD_AT(s, char *, 0x328);
    short *q;
    v = v ? v + 0xB8 : 0;
    q = (short *)(FIELD_AT(FIELD_AT(v, char *, 0x8), char *, 0x1B8) + 0x2C);
    return 1 << (func_80080CC8(s, (short)SquareRoot0(q[0] * q[0] + q[1] * q[1] + q[2] * q[2])) % 8);
}

EXTERN_C int func_80070440(void)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    char *h = p ? (char *)p + 0xB8 : 0;
    V_80070440 t = FIELD_AT(FIELD_AT(FIELD_AT(h, void *, 0x8), void *, 0x1B8), V_80070440, 0x34);
    return t.a;
}

EXTERN_C int func_8007049C(void)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    char *h = p ? (char *)p + 0xB8 : 0;
    V_8007049C t = FIELD_AT(FIELD_AT(FIELD_AT(h, void *, 0x8), void *, 0x1B8), V_8007049C, 0x34);
    return t.b;
}

EXTERN_C int func_800704F8(void)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    char *h = p ? (char *)p + 0xB8 : 0;
    V_800704F8 t = FIELD_AT(FIELD_AT(FIELD_AT(h, void *, 0x8), void *, 0x1B8), V_800704F8, 0x34);
    return t.c;
}

EXTERN_C int func_80070554(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x3C), int, 0x30);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80015FD0);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80070568);

EXTERN_C int func_80070DA0(int a, int b, int c, int d, int e, int f, int g)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    func_8007AD14(p ? (char *)p + 0xA8 : 0, b, c, d, e, f, g);
    return 0;
}

EXTERN_C int func_80070DF8(int a, int b)
{
    char *p = FIELD_AT(D_800AF470.p, char *, 0x328);
    char *q = 0;
    if (p != 0) {
        q = p + 0xA8;
    }
    func_8007ADCC(q, b);
    return 0;
}

EXTERN_C int func_80070E34(void)
{
    func_8007D744(FIELD_AT(D_800AF470.p, void *, 0x328));
    return 0;
}

EXTERN_C int func_80070E60(void *self, int b, int c, int d, int e, int f)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    func_8006F3DC(p, b, c, d, e, f);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80070E98);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80070F30);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80070FC8);

EXTERN_C int func_80071080(void *self, int b, int c, int d, int e, int f, int g)
{
    void *p = FIELD_AT(D_800AF470.p, void *, 0x328);
    func_800DE3B8(p, b, c, d, e, f, g);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_800710C0);

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80071148);

EXTERN_C int func_800711D0(void)
{
    func_8007D6D0(FIELD_AT(D_800AF470.p, void *, 0x328));
    return 0;
}

EXTERN_C int func_800711FC(void *self, int b)
{
    func_8007FB30(D_800AF470.p, b);
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_800658E0", func_80071224);

EXTERN_C int func_80071250(void)
{
    return 0;
}

EXTERN_C int func_80071258(void)
{
    func_8008022C((char *)D_800AF470.p + 0x4A0);
    return 0;
}

EXTERN_C int func_80071280(void *self, int b)
{
    func_800802E0((char *)D_800AF470.p + 0x4A0, b);
    return 0;
}

EXTERN_C int func_800712A8(void *self, int b, int c)
{
    return func_8007FE4C((char *)D_800AF470.p + 0x498, b, c);
}

EXTERN_C void func_800712D0(void *self, int b, int c, int d)
{
    func_8007FF58((char *)D_800AF470.p + 0x498, b, c, d);
}

EXTERN_C void func_800712F8(void *self, int b)
{
    func_80080110((char *)D_800AF470.p + 0x498, b);
}

EXTERN_C int func_80071320(void *self, int b)
{
    return func_80080130((char *)D_800AF470.p + 0x498, b);
}

EXTERN_C int func_80071348(void *self, int b)
{
    return func_80080180((char *)D_800AF470.p + 0x498, b);
}

EXTERN_C int func_80071370(void *self, int b, int c)
{
    return func_800801D0((char *)D_800AF470.p + 0x498, b, c);
}

EXTERN_C int func_80071398(void *self, int b, int c, int d)
{
    func_800DF758((char *)D_800AF470.p + 0x4B0, b, c, d);
    return 0;
}

EXTERN_C int func_800713C0(void *self, int b, int c, int d, int e)
{
    func_800DF758((char *)D_800AF470.p + 0x4B0, b, c, e);
    return 0;
}

EXTERN_C int func_800713EC(void)
{
    func_800DF938((char *)D_800AF470.p + 0x4B0);
    return 0;
}

EXTERN_C int func_80071414(void)
{
    func_800DF9A8((char *)D_800AF470.p + 0x4B0);
    return 0;
}

EXTERN_C int func_8007143C(void)
{
    func_800DFB10((char *)D_800AF470.p + 0x4B0);
    return 0;
}

EXTERN_C int func_80071464(void)
{
    func_8007E214(FIELD_AT(D_800AF470.p, void *, 0x328));
    return 0;
}

EXTERN_C int func_80071490(void)
{
    func_8007E30C(FIELD_AT(D_800AF470.p, void *, 0x328));
    return 0;
}

EXTERN_C int func_800714BC(int a, int b, int c, int d)
{
    V_800714BC t;
    V_800714BC *p = &t;
    p->a = b;
    p->b = c;
    p->c = d;
    p->d = 0;
    func_800DED18(D_800AF470.p, t);
    return 0;
}

EXTERN_C int func_80071510(void)
{
    func_800DED9C(D_800AF470.p);
    return 0;
}

EXTERN_C int func_80071538(void)
{
    func_800DEDD4(D_800AF470.p);
    return 0;
}

EXTERN_C int func_80071560(void)
{
    func_800DEE50(D_800AF470.p);
    return 0;
}

EXTERN_C int func_80071588(void)
{
    func_800DEED4(D_800AF470.p);
    return 0;
}

EXTERN_C void func_800715B0(void *self, int a, int b, int c)
{
    char buf[0x38];
    char *o = buf;
    int *v;
    func_80074E28(o);
    FIELD_AT(o, void *, 0x8) = D_80016270;
    v = (int *)(o + 0x1C);
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    FIELD_AT(buf, int, 0xC) = a;
    FIELD_AT(buf, int, 0x10) = b;
    FIELD_AT(buf, int, 0x30) = c;
    func_8007164C(self, buf);
    func_80074E44(buf, 2);
}

EXTERN_C void func_8007164C(void *self, void *b)
{
    void *o;
    switch (FIELD_AT(b, int, 0xC) & 0xF0000) {
    case 0x10000:
        if (FIELD_AT(self, void *, 0x54) != 0) {
            o = copy_80071B24(__builtin_new(0x34), b);
            func_800770B4(&D_800AF414, FIELD_AT(self, int, 0x54), (int)o);
        }
        break;
    case 0:
        if (FIELD_AT(self, void *, 0x58) != 0) {
            o = copy_80071B24(__builtin_new(0x34), b);
            func_800770B4(&D_800AF414, FIELD_AT(self, int, 0x58), (int)o);
        }
        break;
    case 0x20000:
        break;
    }
}

EXTERN_C void func_80071820(void *self, int b, int c)
{
    void *o = func_8006FEEC(operator new(0x6C));
    FIELD_AT(self, void *, 0x54) = o;
    func_8006FF50(o, b, c, self);
}

EXTERN_C void func_80071880(void *self, void *b)
{
    if (FIELD_AT(self, void *, 0x58) != 0) {
        VObj<8> *o;
        func_80077234(&D_800AF414, FIELD_AT(self, void *, 0x58));
        o = FIELD_AT(self, VObj<8> *, 0x58);
        if (o != 0) {
            o->v00(3);
        }
    }
    FIELD_AT(self, void *, 0x58) = b;
    func_80077210(&D_800AF414, b);
}

EXTERN_C void func_80071904(void)
{
    func_80076EF8(&D_800AF414, 2);
}

EXTERN_C void *func_8007192C(void *d, void *s)
{
    sub_copy_8007192C((Sub_8007192C *)d, (Sub_8007192C *)s, D_80016BC0);
    sub_copy_8007192C((Sub_8007192C *)((char *)d + 0x10), (Sub_8007192C *)((char *)s + 0x10), D_80016BC0);
    FIELD_AT(d, int, 0x20) = FIELD_AT(s, int, 0x20);
    sub_copy_8007192C((Sub_8007192C *)((char *)d + 0x24), (Sub_8007192C *)((char *)s + 0x24), D_80016BC0);
    sub_copy_8007192C((Sub_8007192C *)((char *)d + 0x34), (Sub_8007192C *)((char *)s + 0x34), D_80016868);
    FIELD_AT(d, int, 0x44) = FIELD_AT(s, int, 0x44);
    FIELD_AT(d, int, 0x48) = FIELD_AT(s, int, 0x48);
    FIELD_AT(d, int, 0x4C) = FIELD_AT(s, int, 0x4C);
    FIELD_AT(d, int, 0x50) = FIELD_AT(s, int, 0x50);
    FIELD_AT(d, int, 0x54) = FIELD_AT(s, int, 0x54);
    FIELD_AT(d, int, 0x58) = FIELD_AT(s, int, 0x58);
    return d;
}

EXTERN_C void func_80071A40(void)
{
    func_80076EA8(&D_800AF414);
    D_800AF414.a = 0;
    D_800AF414.b = 0;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80016270);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80016280);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80016298);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800162B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80016300);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80016310);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800163A8);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800163C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_800163E0);

INCLUDE_RODATA("asm/main/nonmatchings/u_800658E0", D_80016410);
