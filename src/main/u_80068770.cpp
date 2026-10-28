#include "common.h"
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

EXTERN_C void func_800689E0(void *self)
{
    int i = FIELD_AT(self, int, 0x20);
    if (i < FIELD_AT(self, unsigned short, 0x1CF0)) {
        func_80061188((Obj_80061188 *)D_800B4DD0_w, FIELD_AT((char *)self + i, signed char, 0x68));
    } else {
        int j = FIELD_AT(self, unsigned short, 0x1D00);
        func_80061164(D_800B4DD0_w, j ? j - 1 : 0);
    }
}

EXTERN_C int func_80068A50(void *self)
{
    return FIELD_AT(self, int, 0x1D04);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_80068A5C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_80068F3C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006A440);

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006A4E4);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006A608);

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006A6D4);

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006A784);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006AF94);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006B180);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006BFE4);

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

// D_800B4D00 is defined in another file, so ASPSX reached it with lui here: a plain small extern
// (the unit's $gp list leaves it off $gp). decls_b.h declares it as a struct, hence the alias.
EXTERN_C int D_800B4D00_word asm("D_800B4D00");
EXTERN_C void func_8006C29C(void *self)
{
    func_80065AD0(self ? (char *)self + 0x50 : 0);
    func_80099C60(FIELD_AT(self, int, 0x114), FIELD_AT(self, int, 0x118));
    func_80099C80(FIELD_AT(self, int, 0x11C));
    D_800B4D00_word = (int)((VObj<0x2C> *)self)->v11();
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006C4EC);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006C65C);

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

INCLUDE_RODATA("asm/main/nonmatchings/u_80068770", D_80015C0C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80068770", D_80015C5C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80068770", D_80015C9C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80068770", D_80015DBC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80068770", D_80015E5C);

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006C95C);

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006C9F8);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80068770", func_8006CAF8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80068770", D_80015EA0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80068770", D_80015EB8);
