#include "common.h"
#define EXE_H_IN_u_80068770
#include "shared/exe.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"
#include "game/b2/b2.h"

EXTERN_C int D_800B4ED8; // defined in this file: reached through $gp here (func_8006BF94)

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_80068770);

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

EXTERN_C void *func_800689E0(void *self)
{
    int i = FIELD_AT(self, int, 0x20);
    if (i < FIELD_AT(self, unsigned short, 0x1CF0)) {
        return func_80061188((Obj_80061188 *)D_800B4DD0_w, FIELD_AT((char *)self + i, signed char, 0x68));
    } else {
        int j = FIELD_AT(self, unsigned short, 0x1D00);
        return func_80061164(D_800B4DD0_w, j ? j - 1 : 0);
    }
}

EXTERN_C int func_80068A50(void *self)
{
    return FIELD_AT(self, int, 0x1D04);
}

EXTERN_C int func_80068A5C(void *self)
{
    int ok = 1;
    int n = func_800619F4((Obj_800619F4 *)D_800B4DD0_w);
    unsigned i;
    if (n > 0) {
        if (FIELD_AT(self, unsigned short, 0x1D00) == 0) {
            ok = 0;
        } else {
            for (i = 0; i < n; i++) {
                if (ok == 0) {
                    break;
                }
                if (FIELD_AT(func_80061188((Obj_80061188 *)D_800B4DD0_w, i), unsigned char, 0x18) == FIELD_AT(self, unsigned short, 0x1D00)) {
                    ok = 0;
                }
            }
        }
    }
    return ok;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_80068B14);

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

EXTERN_C int func_80068F3C(void *self, void *m)
{
    if (func_8005618C(m)) {
        return 1;
    }
    if (FIELD_AT(self, int, 0x1CF8) == 0) {
        return 1;
    }
    func_8001FC78(m, 0, 0);
    unsigned k = FIELD_AT(m, unsigned short, 0x18);
    if (k & 0x2000) {
        char *t = FIELD_AT(self, char *, 0x3C);
        if (!func_80053880(t ? t + 0x50 : 0)) {
            return 1;
        }
        void *p = func_800550BC(self);
        if (func_8005409C(p)) {
            FIELD_AT(self, int, 0x1D04) = 1;
            ((VObj<0x18> *)p)->v01();
        } else {
            func_8008EF40(0xE);
        }
        return 1;
    }
    if (k & 0x20) {
        int b;
        if (FIELD_AT(self, unsigned short, 0x1D00) >= 4) {
            return 1;
        }
        b = FIELD_AT((char *)self + FIELD_AT(self, int, 0x20), signed char, 0x68);
        if (b == -1) {
            return 1;
        }
        char *s = (char *)self + 0x1D08;
        func_80067ABC(s, func_80061188((Obj_80061188 *)D_800B4DD0_w, b));
        func_800680A0(s);
        return 1;
    }
    if (k & 0x400) {
        FIELD_AT(self, int, 0x20) = func_80058488(FIELD_AT(self, void *, 0x3C), -1);
    } else if (k & 0x800) {
        FIELD_AT(self, int, 0x20) = func_80058488(FIELD_AT(self, void *, 0x3C), 1);
    } else {
        func_80063340(self, m);
    }
    return 1;
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_80069264);

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_800694BC);

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_800697A4);

EXTERN_C void func_80069914(VObj<0x18> *self)
{
    self->v04();
    func_80054FC0(self);
}

EXTERN_C void func_80069958(void *self)
{
    func_80054FE0(self);
}

// func_80053F48 takes its 4-byte struct by value as S_A2_Pt (defined in main_a2b); main_b passes the same two shorts as SV2C_80055020.
EXTERN_C void func_80053F48_v(void *self, SV2C_80055020 v) asm("func_80053F48");

EXTERN_C void func_80069978(O_80069978 *self, SV2C_80055020 *pp, int dx, int dy, int step)
{
    SV2C_80055020 p = *pp;
    unsigned int i = 0;
    while (1) {
        if (!(i < 8)) break;
        func_8005457C(&self->a[i], 0);
        func_80053F48_v(&self->a[i], p);
        func_8005457C(&self->a[i + 1], 0);
        func_80053F48_v(&self->a[i + 1], SV2C_80055020(p.x + dy, p.y));
        func_8005457C(&self->b[i], 0);
        func_80053F48_v(&self->b[i], SV2C_80055020(p.x + dx, p.y));
        func_8005457C(&self->b[i + 1], 0);
        func_80053F48_v(&self->b[i + 1], SV2C_80055020(p.x + dx + dy, p.y));
        p.y += step;
        i += 2;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_80069B2C);

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
        __builtin_vec_delete(FIELD_AT(self, void *, 0x14));
    }
    FIELD_AT(self, void *, 0x14) = 0;
    if (FIELD_AT(self, void *, 0x1C) != 0) {
        __builtin_vec_delete(FIELD_AT(self, void *, 0x1C));
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
        __builtin_vec_delete(FIELD_AT(self, void *, 0x14));
    }
    FIELD_AT(self, void *, 0x14) = 0;
    if (b) {
        n = a == 4 ? 0x10 : 0x100;
        n *= 2;
        p = __builtin_vec_new(n);
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
        __builtin_vec_delete(FIELD_AT(self, void *, 0x1C));
    }
    FIELD_AT(self, void *, 0x1C) = __builtin_vec_new(sz * 2);
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
    SetTile((char *)self + 0x24);
    SetTile((char *)self + 0x34);
    if (c == -1) {
        SetSemiTrans((char *)self + 0x24, 0);
        SetSemiTrans((char *)self + 0x34, 0);
    } else {
        SetSemiTrans((char *)self + 0x24, 1);
        SetSemiTrans((char *)self + 0x34, 1);
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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006A1BC);

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

EXTERN_C void func_8006A440(void *self, void *m)
{
    if (FIELD_AT(self, short, 8) == 1) {
        ((VObj0 *)self)->v08();
    }
    FIELD_AT(IDX16(self), unsigned char, 0x28) = FIELD_AT(m, unsigned char, 4);
    FIELD_AT(IDX16(self), unsigned char, 0x29) = FIELD_AT(m, unsigned char, 5);
    FIELD_AT(IDX16(self), unsigned char, 0x2A) = FIELD_AT(m, unsigned char, 6);
    FIELD_AT(self, short, 8) = 2;
}

EXTERN_C void func_8006A4E4(void *self, int v)
{
    if (FIELD_AT(self, short, 8) == 1) {
        ((VObj0 *)self)->v08();
    }
    FIELD_AT(IDX16(self), unsigned char, 0x28) = v;
    FIELD_AT(IDX16(self), unsigned char, 0x29) = v;
    FIELD_AT(IDX16(self), unsigned char, 0x2A) = v;
    FIELD_AT(self, short, 8) = 2;
}

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

EXTERN_C void func_8006A608(void *self, int v)
{
    if (FIELD_AT(self, short, 8) == 1) {
        ((VObj0 *)self)->v08();
    }
    if ((short)v >= 0) {
        SetSemiTrans((char *)self + 0x24, 1);
        SetSemiTrans((char *)self + 0x34, 1);
        SetDrawMode((char *)self + (D_800B4CF0_w * 12 + 0xC), 0, 1, (v << 21) >> 16, 0);
    } else {
        SetSemiTrans((char *)self + 0x24, 0);
        SetSemiTrans((char *)self + 0x34, 0);
    }
    FIELD_AT(self, short, 8) = 2;
}

EXTERN_C void func_8006A6D4(void *self)
{
    int *p = &D_800B4CF0_w;
    if (FIELD_AT(self, short, 8) != 0) {
        char *d = (char *)self + ((*p ^ 1) * 12);
        char *s = (char *)self + (*p * 12);
        *(W3_B *)(d + 0xC) = *(W3_B *)(s + 0xC);
        char *s2 = (char *)self + (*p * 16 + 0x24);
        int k = xor_8006A6D4(*p, 1) * 16 + 0x24;
        int x = FIELD_AT(s2, int, 4);
        int y = FIELD_AT(s2, int, 8);
        int z = FIELD_AT(s2, int, 0xC);
        FIELD_AT((char *)self + k, int, 4) = x;
        FIELD_AT((char *)self + k, int, 8) = y;
        FIELD_AT((char *)self + k, int, 0xC) = z;
    }
    func_80028184(self);
}

EXTERN_C void func_8006A784(char *self)
{
    int i = D_800B4CF0_w;
    char *d = self + i * 12;
    char *s = self + (i ^ 1) * 12;
    *(W3_B *)(d + 0xC) = *(W3_B *)(s + 0xC);
    int j = D_800B4CF0_w;
    char *s2 = self + ((j ^ 1) * 16 + 0x24);
    int k = j * 16 + 0x24;
    int x = FIELD_AT(s2, int, 4);
    int y = FIELD_AT(s2, int, 8);
    int z = FIELD_AT(s2, int, 0xC);
    FIELD_AT(self + k, int, 4) = x;
    FIELD_AT(self + k, int, 8) = y;
    FIELD_AT(self + k, int, 0xC) = z;
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006A82C);

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006AB18);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006AE68);

EXTERN_C void func_8006AF94(void *self_)
{
    char *self = (char *)self_;
    if (FIELD_AT(self, int, 0x26C) != 0) {
        int x = FIELD_AT(self, int, 0x28C);
        FIELD_AT(self, int, 0x11C) = x;
        func_80099C80(x);
        FIELD_AT(self, int, 0x84) = FIELD_AT(self, int, 0x27C);
        FIELD_AT(self, int, 0x88) = FIELD_AT(self, int, 0x280);
        FIELD_AT(self, int, 0x8C) = FIELD_AT(self, int, 0x284);
        FIELD_AT(self, short, 0x7C) = FIELD_AT(self, unsigned short, 0x290);
        FIELD_AT(self, short, 0x7E) = FIELD_AT(self, unsigned short, 0x292);
        FIELD_AT(self, short, 0x80) = FIELD_AT(self, unsigned short, 0x294);
        ((VObj<0x2C> *)self)->v33(self + 0x7C, self + 0x84);
        FIELD_AT(self, int, 0x26C) = 0;
    }
}

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

EXTERN_C void func_8006B180(void *self, int d)
{
    short s = FIELD_AT(self, unsigned short, 0x2A0);
    short r = s + d;
    s = r;
    if (r > 0xF6E) s = 0xF6E;
    if (s < 0xE42) s = 0xE42;
    FIELD_AT(self, short, 0x2A0) = s;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006B1C8);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", SsGetMute);

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

// func_8003B310 takes one argument and returns an S_A2_V4; retail passes none here and leaves $a1 as it is.
EXTERN_C V_8006B928 func_8003B310_0() asm("func_8003B310");

EXTERN_C void func_8006B928(void *self, int b)
{
    FIELD_AT(self, V_8006B928, 0x2C8) = func_8003B310_0();
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
    p = __builtin_vec_new(FIELD_AT(self, int, 0x238));
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
        __builtin_vec_delete(p);
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
