#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"

EXTERN_C void func_80059A84(void *self)
{
    void *p;
    if (FIELD_AT(self, int, 0x5C) != 0 && FIELD_AT(self, void *, 0x30) != 0) {
        FIELD_AT(self, int, 0x5C) = 0;
        FIELD_AT(self, Iter_B *, 0x30)->i = 0;
        for (p = iter_next_B(FIELD_AT(self, Iter_B *, 0x30)); p != 0; p = iter_next_B(FIELD_AT(self, Iter_B *, 0x30))) {
            func_8005B378(p, 5);
        }
    }
}

EXTERN_C void func_80059B5C(void *self, int b)
{
    VObj0 *p;
    if (FIELD_AT(self, int, 0x8) != 0) {
        FIELD_AT(self, Iter_B *, 0x30)->i = 0;
        for (p = (VObj0 *)iter_next_B(FIELD_AT(self, Iter_B *, 0x30)); p != 0; p = (VObj0 *)iter_next_B(FIELD_AT(self, Iter_B *, 0x30))) {
            p->v11(b);
        }
    }
}

EXTERN_C void func_80059C54(void *self, int i, int flag)
{
    if (FIELD_AT(self, int, 0x8) != 0 && (unsigned int)i < (unsigned int)(FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0)->count) {
        char *v = FIELD_AT(self, char *, 0x38) ? FIELD_AT(self, char *, 0x38) + 8 : 0;
        if (func_8005409C(func_80019F64(v ? *(void **)v : 0, i))) {
            VObj0 *o;
            v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
            o = func_80019F64(v ? *(void **)v : 0, i);
            if (flag) {
                func_8005B378(o, 3);
            } else if (FIELD_AT(self, int, 0x5C) == 0) {
                func_8005B378(o, 5);
            } else {
                func_8005B378(o, 1);
            }
        } else {
            VObj0 *o;
            v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
            o = func_80019F64(v ? *(void **)v : 0, i);
            func_8005B378(o, flag ? 4 : 2);
        }
    }
}

EXTERN_C void func_80059D8C(void *self, int b)
{
    FIELD_AT(self, int, 0x38) = b;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_80059D94);

EXTERN_C int func_80059E90(VObj<0x2C> *self, int b)
{
    int r = self->v11();
    if (r != 0) {
        self->v16(r);
    }
    return 1;
}

EXTERN_C void func_80059EF8(void *self, int b)
{
    FIELD_AT(self, int, 0x60) = b;
}

EXTERN_C int func_80059F00(void *self)
{
    return FIELD_AT(self, int, 0x60);
}

EXTERN_C void func_80059F0C(void *self, int b)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        char t[8];
        VObj0 *p;
        unsigned char c = b;
        func_8002972C(t, c, c, c, 1);
        FIELD_AT(self, Iter_B *, 0x30)->i = 0;
        for (p = (VObj0 *)iter_next_B(FIELD_AT(self, Iter_B *, 0x30)); p != 0; p = (VObj0 *)iter_next_B(FIELD_AT(self, Iter_B *, 0x30))) {
            p->v11(t);
        }
        func_800198AC(t, 2);
    }
}

EXTERN_C void func_8005A020(void *self, int x, int y)
{
    int dx, dy, i;
    if (FIELD_AT(self, short, 0xC) == x && FIELD_AT(self, short, 0xE) == y) {
        return;
    }
    dx = x - FIELD_AT(self, short, 0xC);
    dy = y - FIELD_AT(self, short, 0xE);
    FIELD_AT(self, short, 0xC) = x;
    FIELD_AT(self, short, 0xE) = y;
    if (FIELD_AT(self, int, 0x8) != 0) {
        FIELD_AT(FIELD_AT(self, char *, 0x30), int, 0x4) = 0;
        for (i = (FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0)->count - 1; i >= 0; i--) {
            char *h = FIELD_AT(self, char *, 0x30);
            char *v = h ? h + 8 : 0;
            func_80019F64(v ? *(void **)v : 0, i)->v10(dx, dy);
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005A120);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005A31C);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005A518);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005A62C);

EXTERN_C void func_8005A784(void *self, int b)
{
    if (FIELD_AT(self, int, 0x8) != 0 && (FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0)->count == 5) {
        char t1[8];
        char t2[8];
        unsigned char k = b;
        char *v;
        VObj0 *o;
        func_8002972C(t1, k, k, k, 1);
        v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
        func_80019F64(v ? *(void **)v : 0, 0)->v11(t1);
        func_8002972C(t2, k * 2 - 1, k * 2 - 1, k * 2 - 1, 1);
        v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
        o = func_80019F64(v ? *(void **)v : 0, 1);
        func_800536F0(o, t2);
        o->v06();
        v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
        o = func_80019F64(v ? *(void **)v : 0, 3);
        func_80059888(o, (unsigned char *)t2);
        o->v06();
        func_800198AC(t2, 2);
        func_800198AC(t1, 2);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005A934);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005ABE0);

EXTERN_C void func_8005AF70(VObj<0x2C> *self)
{
    void *p = FIELD_AT(self, void *, 0x4);
    if (p != 0) {
        C4_8005AF70 t = FIELD_AT(p, C4_8005AF70, 0x10);
        char *h = (char *)self + 0xC;
        char *g = h ? (char *)self + 0x10 : 0;
        FIELD_AT(g, C4_8005AF70, 0x0) = t;
    }
    self->v14();
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005AFF0);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005B0F8);

EXTERN_C void func_8005B2F0(void *self, int b)
{
    FIELD_AT(self, void *, 0x0) = D_80014548;
    if (FIELD_AT(self, void *, 0x1C) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x1C));
    }
    FIELD_AT(self, void *, 0x1C) = 0;
    if (FIELD_AT(self, void *, 0x14) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x14));
    }
    FIELD_AT(self, void *, 0x14) = 0;
    if (FIELD_AT(self, void *, 0x10) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x10));
    }
    FIELD_AT(self, void *, 0x10) = 0;
    func_8005F120(self, b);
}

struct Ent16d { char p[0xE]; unsigned short h; };
EXTERN_C void func_8005B378(void *self, int n)
{
    unsigned i;
    int idx = D_800B4CF0_w;
    int v = func_80060118_i(&D_800AE640, n);
    int w = func_800600A4_i(&D_800AE640, 0xB);
    for (i = 0; i < FIELD_AT(self, unsigned, 0x18); i += 2) {
        if (FIELD_AT(self, Ent16d *, 0x14)[i + idx].h != (unsigned short)w) {
            FIELD_AT(self, Ent16d *, 0x14)[i + idx].h = v;
        }
    }
    func_8005F1D8(self);
}

EXTERN_C Pair_8005B424 *func_8005B424(Pair_8005B424 *out, Obj_8005B424 *self)
{
    int i = D_800B4CF0.value;
    short a = self->ents[i].a;
    short b = self->ents[i].b;
    out->a = a;
    out->b = b;
    return out;
}

struct Ent16 { char p0[4]; unsigned char r, g, b; char p7[9]; };
EXTERN_C void func_8005B450(void *self, unsigned char *c)
{
    unsigned i;
    int idx = D_800B4CF0_w;
    unsigned char r = c[5];
    unsigned char g = c[6];
    unsigned char b = c[7];
    for (i = 0; i < FIELD_AT(self, unsigned, 0x18); i += 2) {
        FIELD_AT(self, Ent16 *, 0x14)[i + idx].r = r;
        FIELD_AT(self, Ent16 *, 0x14)[i + idx].g = g;
        FIELD_AT(self, Ent16 *, 0x14)[i + idx].b = b;
    }
    func_8005F1D8(self);
}

struct Ent16b { char p0[8]; unsigned short x, y; char pc[4]; };
EXTERN_C void func_8005B4D8(void *self, int a, int b)
{
    unsigned i;
    int idx = D_800B4CF0_w;
    for (i = 0; i < FIELD_AT(self, unsigned, 0x18); i += 2) {
        FIELD_AT(self, Ent16b *, 0x14)[i + idx].x += a;
        FIELD_AT(self, Ent16b *, 0x14)[i + idx].y += b;
    }
    func_8005F1D8(self);
}

EXTERN_C void func_8005B560(Obj_8005B560 *self, int b, int c)
{
    VEnt_8005B560 *vt = self->vt;
    int i = D_800B4CF0.value;
    vt[11].pfn((char *)self + vt[11].delta, b - self->ents[i].a, c - self->ents[i].b);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005B5B4);

EXTERN_C int func_8005B66C(void *self)
{
    int cur = D_800B4CF0_w;
    int oth = cur ^ 1;
    int i;
    unsigned u;
    if (func_8005F1B4(self)) {
        for (u = 0; u < FIELD_AT(self, unsigned, 0x18); u += 2) {
            int *s = (int *)(FIELD_AT(self, char *, 0x14) + ((u + oth) << 4));
            int a = s[1];
            int b = s[2];
            int c = s[3];
            int *d = (int *)(FIELD_AT(self, char *, 0x14) + ((u + cur) << 4));
            d[1] = a;
            d[2] = b;
            d[3] = c;
        }
    }
    for (i = FIELD_AT(self, int, 0x18) + FIELD_AT(self, int, 0x20) - 2; i >= 0; i -= 2) {
        P_TAG_B *pr = FIELD_AT(self, P_TAG_B **, 0x10)[i + cur];
        unsigned z = FIELD_AT(self, unsigned short, 0xA);
        S_OtB *ot = D_800B4CFC;
        if (z && z < ot->count) {
            *(unsigned *)pr = (*(unsigned *)pr & 0xFF000000) | (ot->tab[z] & 0xFFFFFF);
            ot->tab[z] = (unsigned long)pr & 0xFFFFFF;
        }
    }
    return (unsigned)(FIELD_AT(self, int, 0x18) + FIELD_AT(self, int, 0x20)) >> 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005B7A8);

EXTERN_C void func_8005BC7C(void)
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005BC84);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005BDA4);

EXTERN_C void func_8005BF04(void *self, int a, int b)
{
    VE_B *vt = FIELD_AT(self, VE_B *, 0x2C);
    vt[8].pfn((char *)self + vt[8].delta, FIELD_AT(self, short, 0xC) + a, FIELD_AT(self, short, 0xE) + b);
}

EXTERN_C void func_8005BF48(void)
{
}

EXTERN_C void func_8005BF50(void *self)
{
    if (FIELD_AT(self, void *, 0x8) == 0) {
        FIELD_AT(self, void *, 0x8) = func_8005C26C(operator new(0x34), self, FIELD_AT(self, int, 0x34));
    }
    func_8002A110(self);
}

EXTERN_C void func_8005BFA4(void *self)
{
    func_8005C1E8(self);
}

EXTERN_C void func_8005BFC4(void *self, int b)
{
    func_8005C088(self, b, 1);
}

EXTERN_C void func_8005BFE4(void *self)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        if ((FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0)->count > 0) {
            void *r = (void *)((VObj<0x2C> *)self)->v11();
            if (r != 0) {
                func_8002DD34(r, FIELD_AT(self, void *, 0x30), 0);
                func_8002DA94(r, FIELD_AT(self, void *, 0x30));
            }
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005C088);

EXTERN_C void func_8005C1E8(void *self)
{
    int r = ((VObj<0x2C> *)self)->v11();
    if (r != 0) {
        func_8005C088(self, r, 1);
    }
}

EXTERN_C void func_8005C238(V_8005C238 *self)
{
    self->v14();
}

EXTERN_C void *func_8005C26C(void *self, void *b, int c)
{
    ((int (*)(void *, void *, int))func_80038654)(self, b, c);
    FIELD_AT(self, void *, 0x0) = D_800145B0;
    FIELD_AT(self, void *, 0x30) = b;
    FIELD_AT(b, void *, 0x30) = (char *)self + 0x10;
    return self;
}

EXTERN_C void func_8005C2B8(void *self, int b)
{
    char *h;
    FIELD_AT(self, void *, 0x0) = D_800145B0;
    h = (char *)self + 0x10;
    if ((h ? FIELD_AT(h, List *, 0x0) : 0)->count > 0) {
        func_8005C088(FIELD_AT(self, void *, 0x30), func_8002EB68(self), 1);
    }
    FIELD_AT(FIELD_AT(self, void *, 0x30), void *, 0x30) = 0;
    FIELD_AT(self, void *, 0x30) = 0;
    func_800386B8(self, b);
}

EXTERN_C void func_8005C344(void *self)
{
    FIELD_AT(self, V_8005C344 *, 0x30)->v14();
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005C380);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005C3C4);

struct Pt4 { short x, y; };
EXTERN_C void func_8005C570(void *self, Pt4 a, Pt4 b, Pt4 c, Pt4 d)
{
    Pt4 *p = (Pt4 *)((char *)self + D_800B4CF0_w * 36);
    p[6].x = a.x; p[6].y = a.y;
    p[8].x = b.x; p[8].y = b.y;
    p[10].x = c.x; p[10].y = c.y;
    p[12].x = d.x; p[12].y = d.y;
    func_8005F1D8(self);
}

EXTERN_C void func_8005C608(void *self, Pt4 a, Pt4 b, Pt4 c, Pt4 d)
{
    unsigned short *p = (unsigned short *)((char *)self + D_800B4CF0_w * 36);
    p[0xC] += a.x; p[0xD] += a.y;
    p[0x10] += b.x; p[0x11] += b.y;
    p[0x14] += c.x; p[0x15] += c.y;
    p[0x18] += d.x; p[0x19] += d.y;
    func_8005F1D8(self);
}

EXTERN_C void func_8005C6E8(void *self, int dx, int dy)
{
    unsigned short *p = (unsigned short *)((char *)self + D_800B4CF0_w * 36);
    p[0xC] += dx; p[0xD] += dy;
    p[0x10] += dx; p[0x11] += dy;
    p[0x14] += dx; p[0x15] += dy;
    p[0x18] += dx; p[0x19] += dy;
    func_8005F1D8(self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005C77C);

struct Col3 { short r, g, b; };
EXTERN_C void func_8005C7EC(void *self, Col3 a, Col3 b, Col3 c, Col3 d)
{
    unsigned char *p = (unsigned char *)self + D_800B4CF0_w * 36;
    p[0x14] = a.r; p[0x15] = a.g; p[0x16] = a.b;
    p[0x1C] = b.r; p[0x1D] = b.g; p[0x1E] = b.b;
    p[0x24] = c.r; p[0x25] = c.g; p[0x26] = c.b;
    p[0x2C] = d.r; p[0x2D] = d.g; p[0x2E] = d.b;
    func_8005F1D8(self);
}

EXTERN_C void func_8005C8B4(void *self, int a, int b)
{
    short *p = (short *)((char *)self + D_800B4CF0_w * 36);
    int x = p[0xC];
    int y = p[0xD];
    short x2 = x + a;
    p[0x11] = y;
    short y2 = y + b;
    p[0x10] = x2;
    p[0x14] = x;
    p[0x15] = y2;
    p[0x18] = x2;
    p[0x19] = y2;
    func_8005F1D8(self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005C910);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005C968);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005CA4C);

EXTERN_C void func_8005CB68(void *self, int flags)
{
    func_8005F120(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005CB88);

EXTERN_C void func_8005CCB0(void *self, int b)
{
    FIELD_AT(self, SV2_80055020, 0xC) = func_80054054();
    FIELD_AT(self, short, 0x10) = func_8005F87C((void *)b);
    if (func_80054074(b) == 1) {
        FIELD_AT(self, short, 0xC) -= 6;
    } else {
        FIELD_AT(self, short, 0xC) -= FIELD_AT(self, unsigned short, 0x10) + 6;
    }
    ((VObj<0x2C> *)self)->v14();
}

EXTERN_C void func_8005CD5C(void *self, unsigned char c)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        if ((FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0)->count > 0) {
            char t[8];
            char *v;
            func_8002972C(t, c, c, c, 1);
            v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
            func_80019F64(v ? *(void **)v : 0, 0)->v11(t);
            func_800198AC(t, 2);
        }
    }
}

EXTERN_C void func_8005CE1C(void *self, int b)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        List *l;
        void *q;
        func_8005C088(self, b, 1);
        l = FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0;
        q = func_8005D080(__builtin_new(0x88), (char *)self + 0xC, FIELD_AT(self, short, 0x10) - 10, FIELD_AT(self, unsigned short, 0x1C));
        func_80019A6C(l, (int)q, l->count);
        func_8002DA94((void *)b, FIELD_AT(self, void *, 0x30));
    }
}

EXTERN_C void func_8005CEB4(void *self)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        char *h = FIELD_AT(self, char *, 0x30);
        if ((h ? *(List **)h : 0)->count > 0) {
            char *v = h ? h + 8 : 0;
            VObj0 *o = func_80019F64(v ? *(void **)v : 0, 0);
            o->v07(FIELD_AT(self, short, 0xC), FIELD_AT(self, short, 0xE));
            func_8005D228(o, FIELD_AT(self, short, 0x10) < 11 ? 2 : FIELD_AT(self, short, 0x10) - 10);
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005CF78);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005D080);

EXTERN_C void func_8005D228(void *self, int b)
{
    char *p = (char *)self + D_800B4CF0.value * 16;
    FIELD_AT(p, short, 0x74) = b;
    FIELD_AT(p, short, 0x50) = FIELD_AT(p, short, 0x70) + b;
    func_8005F1D8(self);
}

EXTERN_C void func_8005D264(void *self, int dx, int dy)
{
    char *p = (char *)self + D_800B4CF0.value * 16;
    FIELD_AT(p, short, 0x30) += dx;
    FIELD_AT(p, short, 0x32) += dy;
    FIELD_AT(p, short, 0x50) += dx;
    FIELD_AT(p, short, 0x52) += dy;
    FIELD_AT(p, short, 0x70) += dx;
    FIELD_AT(p, short, 0x72) += dy;
    func_8005F1D8(self);
}

EXTERN_C void func_8005D2D8(void *self, unsigned char *c)
{
    char *p = (char *)self + D_800B4CF0.value * 16;
    unsigned char r = c[5];
    unsigned char g = c[6];
    unsigned char b = c[7];
    FIELD_AT(p, unsigned char, 0x2C) = r;
    FIELD_AT(p, unsigned char, 0x2D) = g;
    FIELD_AT(p, unsigned char, 0x2E) = b;
    FIELD_AT(p, unsigned char, 0x4C) = r;
    FIELD_AT(p, unsigned char, 0x4D) = g;
    FIELD_AT(p, unsigned char, 0x4E) = b;
    FIELD_AT(p, unsigned char, 0x6C) = r;
    FIELD_AT(p, unsigned char, 0x6D) = g;
    FIELD_AT(p, unsigned char, 0x6E) = b;
    func_8005F1D8(self);
}

EXTERN_C void func_8005D334(void *self, int b, int c)
{
    VEnt_8005D334 *vt = FIELD_AT(self, VEnt_8005D334 *, 0x0);
    char *p = (char *)self + D_800B4CF0.value * 16;
    vt[11].pfn((char *)self + vt[11].delta, b - FIELD_AT(p, short, 0x30), c - FIELD_AT(p, short, 0x32));
}

EXTERN_C void *func_8005D384(void *self)
{
    return func_8005D754(operator new(0x88), self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005D3B8);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005D624);

EXTERN_C void func_8005D734(void *self, int b)
{
    func_8005D228(self, b);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005D754);

EXTERN_C void func_8005D8A4(void *self, int flags)
{
    func_8005F120(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005D8C4);

EXTERN_C void func_8005D9D4(void *self, int b)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        char *h = FIELD_AT(self, char *, 0x30);
        if ((h ? *(List **)h : 0)->count == 1) {
            unsigned int c = b;
            if (c >= 0x100) {
                char *v = h ? h + 8 : 0;
                List *l = v ? *(List **)v : 0;
                VObj0 *o = l->count ? **(VObj0 ***)l : 0;
                o->v11(&D_800B4C98);
                v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
                l = v ? *(List **)v : 0;
                func_8005DEA4(l->count ? **(void ***)l : 0, 0);
            } else {
                char t[8];
                char *v;
                List *l;
                VObj0 *o;
                func_8002972C(t, c, c, c, 1);
                v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
                l = v ? *(List **)v : 0;
                o = l->count ? **(VObj0 ***)l : 0;
                o->v11(t);
                func_800198AC(t, 2);
            }
        }
    }
}

EXTERN_C void func_8005DB68(void *self, void *b)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        void *p;
        void *s0;
        Rc8 r;
        func_8005C088(self, (int)b, 1);
        p = operator new(0x48);
        r.x = 0;
        r.y = 0;
        r.w = 0x140;
        r.h = 0xF0;
        s0 = func_8005DD4C(p, r, 1, FIELD_AT(self, unsigned short, 0x1C));
        func_8005DEA4(s0, 1);
        {
            List *l = FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0;
            func_80019A6C(l, (int)s0, l->count);
        }
        func_8002DA94(b, FIELD_AT(self, void *, 0x30));
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005DC44);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005DD4C);

EXTERN_C void func_8005DEA4(void *self, int b)
{
    if (b != 0) {
        unsigned char *q = (unsigned char *)(D_800B4CF0.value * 16 + (int)self) + 0x28;
        q[7] = q[7] | 2;
    } else {
        unsigned char *q = (unsigned char *)(D_800B4CF0.value * 16 + (int)self) + 0x28;
        q[7] = q[7] & ~2;
    }
    func_8005F1D8(self);
}

EXTERN_C void func_8005DF10(void *self, int dx, int dy)
{
    Entry_8005DF10 *e = (Entry_8005DF10 *)((char *)self + D_800B4CF0.value * 16);
    e->x += dx;
    e->y += dy;
    func_8005F1D8(self);
}

EXTERN_C void func_8005DF54(void *self, unsigned char *src)
{
    unsigned char r = src[5];
    unsigned char g = src[6];
    unsigned char b = src[7];
    Entry_8005DF54 *e = (Entry_8005DF54 *)((char *)self + D_800B4CF0.value * 16);
    e->rgb[0] = r;
    e->rgb[1] = g;
    e->rgb[2] = b;
    func_8005F1D8(self);
}

EXTERN_C void func_8005DF98(void *self, int b, int c)
{
    VEnt_8005DF98 *vt = FIELD_AT(self, VEnt_8005DF98 *, 0x0);
    char *p = (char *)self + D_800B4CF0.value * 16;
    vt[11].pfn((char *)self + vt[11].delta, b - FIELD_AT(p, short, 0x30), c - FIELD_AT(p, short, 0x32));
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005DFE8);

EXTERN_C int func_8005E0E0(void *self)
{
    if (func_8005F1B4(self)) {
        int i = D_800B4CF0_w;
        int *s = (int *)((char *)self + (((i ^ 1) << 4) + 0x28));
        int a = s[1];
        int b = s[2];
        int c = s[3];
        int *d = (int *)((char *)self + ((i << 4) + 0x28));
        d[1] = a;
        d[2] = b;
        d[3] = c;
    }
    D_800B4CFC->add((P_TAG_B *)((D_800B4CF0_w << 4) + (int)self + 0x28), FIELD_AT(self, unsigned short, 0xA));
    D_800B4CFC->add((P_TAG_B *)(D_800B4CF0_w * 12 + (char *)self + 0x10), FIELD_AT(self, unsigned short, 0xA));
    return 2;
}

EXTERN_C void func_8005E244(void)
{
}

EXTERN_C void func_8005E24C(void *self, int flags)
{
    func_8005F120(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005E26C);

EXTERN_C void func_8005E404(void *self, int dx, int dy)
{
    unsigned i;
    int idx = D_800B4CF0_w;
    unsigned short *p;
    for (i = 0; i < FIELD_AT(self, unsigned, 0x110); i += 2) {
        p = (unsigned short *)((char *)self + (idx + i) * 52);
        p[0x24] += dx; p[0x25] += dy;
        p[0x2A] += dx; p[0x2B] += dy;
        p[0x30] += dx; p[0x31] += dy;
        p[0x36] += dx; p[0x37] += dy;
    }
    func_8005F1D8(self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005E4CC);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005E924);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005EA9C);

EXTERN_C void *func_8005EAFC(void *self)
{
    return func_8005EF58(operator new(0x114), self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005EB30);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005EDF4);

INCLUDE_ASM("asm/main/nonmatchings/u_80059A84", func_8005EF58);

EXTERN_C void func_8005F090(void *self, int flags)
{
    func_8005F120(self, flags);
}

EXTERN_C void func_8005F0B0(void)
{
    func_8005FC78(&D_800AE640, 0x1434E, 0x10800);
}

EXTERN_C void *func_8005F0E4(void *self, int b)
{
    FIELD_AT(self, void * volatile, 0x0) = D_80010178;
    FIELD_AT(self, void * volatile, 0x0) = D_800111BC;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, short, 0x8) = 0;
    FIELD_AT(self, short, 0xA) = b;
    FIELD_AT(self, void * volatile, 0x0) = D_80014BD0;
    FIELD_AT(self, int, 0xC) = 0;
    return self;
}

EXTERN_C void func_8005F120(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_80014BD0;
    func_8001A610(self, flags);
}

EXTERN_C void func_8005F148(VObj0 *self, short *v)
{
    self->v07(v[0], v[1]);
    self->v08(v[2], v[3]);
}

EXTERN_C int func_8005F1B4(void *self)
{
    if (FIELD_AT(self, int, 0xC) != 0) {
        FIELD_AT(self, int, 0xC) = 0;
        return 1;
    }
    return 0;
}

EXTERN_C void func_8005F1D8(void *self)
{
    FIELD_AT(self, int, 0xC) = 1;
}

EXTERN_C void func_8005F1E4(void)
{
}

EXTERN_C void func_8005F1EC(void)
{
    func_8005FB04(&D_800AE640, 2);
}

EXTERN_C void func_8005F214(void)
{
    func_8005F8EC(&D_800AE640);
}
