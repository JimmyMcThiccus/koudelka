#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"

EXTERN_C void *func_80062610(void *self)
{
    if (D_800B4E2C == 0) {
        char o[8];
        D_800B4E30 = (Entry_800627E8 *)func_800A0D2C(0x5780);
        D_800B4E34 = (int)func_800A0D2C(0x690);
        func_8005F238(o);
        func_8005F298(o, 0x15086, 0x5800);
        {
            void *p = D_800B4E30;
            func_80025CE0(p, func_8005F28C(o), 0x5780);
        }
        func_8005F298(o, 0xC3D2, 0x800);
        {
            char *q = (char *)D_800B4E34;
            *(C690_80062610 *)q = *(C690_80062610 *)func_8005F28C(o);
        }
        func_8005F3E0(o);
        func_8005F248(o, 2);
    }
    D_800B4E2C++;
    return self;
}

EXTERN_C void func_80062764(void *self, int flags)
{
    if (--D_800B4E2C == 0) {
        if (D_800B4E34 != 0) {
            func_800A0D0C((void *)D_800B4E34);
        }
        if (D_800B4E30 != 0) {
            func_800A0D0C(D_800B4E30);
        }
    }
    if (flags & 1) {
        __builtin_delete(self);
    }
}

EXTERN_C void func_800627E8(Entry_800627E8 *out, int i)
{
    *out = D_800B4E30[i - 1];
}

EXTERN_C void *func_80062834(void *self)
{
    return self;
}

EXTERN_C int func_8006283C(void)
{
    return D_800B4E34;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062848);

EXTERN_C int func_80062978(void *self)
{
    int old = FIELD_AT(self, int, 0x6C) != 0;
    FIELD_AT(self, int, 0x6C) = 0;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062988);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062A90);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062C3C);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062D60);

EXTERN_C void func_80062E70(void *self)
{
    func_800566E4(self);
    func_80056874(self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062E9C);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80062FA4);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800630BC);

EXTERN_C void func_800631D4(void *self)
{
    func_8008EF40(0xC);
    func_800566E4(self);
    if (FIELD_AT(self, int, 0x64) < 0) {
        char *h = (char *)self + 0x1C;
        FIELD_AT(self, int, 0x64) = (h ? FIELD_AT(h, List *, 0x0) : 0)->count;
    }
    func_800550FC(self, FIELD_AT(self, int, 0x64));
}

EXTERN_C void func_8006323C(void *self)
{
    func_80054FE0(self);
    func_80056874(self);
    func_8008EF40(0xD);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063270);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063340);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063584);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800635FC);

EXTERN_C void func_80063714(void *self, unsigned int b)
{
    void *p = FIELD_AT(self, void *, 0x3C);
    FIELD_AT(self, unsigned int, 0x64) = b;
    if (p != 0) {
        func_800588EC(p, b);
    }
}

EXTERN_C int func_80063744(void *self, int b)
{
    switch (b) {
    case 1:
        FIELD_AT(self, int, 0x20) = func_80058270(FIELD_AT(self, void *, 0x3C), -1);
        return 1;
    case 2:
        FIELD_AT(self, int, 0x20) = func_80058270(FIELD_AT(self, void *, 0x3C), 1);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800637A0);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800638A8);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800639F8);

EXTERN_C void func_80063B14(void *self, short *v, unsigned short c)
{
    VObj<0x2C> *o = func_80063E18(__builtin_new(0x44), 1, c, 2);
    o->v07(v[0], v[1]);
    ((VObj<0x2C> *)self)->v29(o, -1);
    o->v03();
    ((VObj<0x2C> *)self)->v27();
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063BE4);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063CA4);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063D64);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063E18);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80063F3C);

EXTERN_C void func_80063FFC(void *self, void *b)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        List *l;
        void *p;
        func_8005C088(self, (int)b, 1);
        l = FIELD_AT(self, char *, 0x30) ? *FIELD_AT(self, List **, 0x30) : 0;
        p = operator new(0x48);
        {
            int d = FIELD_AT(self, unsigned short, 0x1C);
            Pt4w u;
            U8bw t = *(U8bw *)((char *)self + 0xC);
            u = *(Pt4w *)&t;
            func_80019A6C(l, (int)func_80064290(p, u, FIELD_AT(self, unsigned short, 0x38), d), l->count);
        }
        func_8002DA94(b, FIELD_AT(self, void *, 0x30));
    }
}

EXTERN_C void func_800640D0(void *self)
{
    if (FIELD_AT(self, int, 0x8) != 0) {
        char *h = FIELD_AT(self, char *, 0x30);
        if ((h ? FIELD_AT(h, List *, 0x0) : 0)->count == 1) {
            char *v = h ? h + 8 : 0;
            List *l = v ? *(List **)v : 0;
            VObj0 *o = l->count ? **(VObj0 ***)l : 0;
            o->v07(FIELD_AT(self, short, 0xC), FIELD_AT(self, short, 0xE));
        }
    }
}

EXTERN_C void func_80064188(S_DtorB *p, int flags)
{
    p->vt2C = D_800150BC;
    p->vb->vt = (VEntB *)D_8001506C.e;
    if (!flags) {
        VTabB50 tmp = D_8001506C;
        p->vb->vt = tmp.e;
        char *q = (char *)p->vb - 0x3C;
        int adj = (char *)p - q;
        tmp.e[1].d = D_8001506C.e[1].d + adj;
        tmp.e[5].d = D_8001506C.e[5].d + adj;
        tmp.e[7].d = D_8001506C.e[7].d + adj;
        tmp.e[9].d = D_8001506C.e[9].d + adj;
    }
    func_8005BDA4(p, 0);
    if (flags & 2)
        func_8001A610(p->vb, 0);
    if (flags & 1)
        operator delete(p);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80064290);

EXTERN_C void func_800643DC(void *self, int dx, int dy)
{
    Entry_800643DC *e = (Entry_800643DC *)((char *)self + D_800B4CF0.value * 16);
    e->x += dx;
    e->y += dy;
    func_8005F1D8(self);
}

EXTERN_C void func_80064420(void)
{
}

EXTERN_C void func_80064428(void *self, int b, int c)
{
    VEnt_80064428 *vt = FIELD_AT(self, VEnt_80064428 *, 0x0);
    char *p = (char *)self + D_800B4CF0.value * 16;
    vt[11].pfn((char *)self + vt[11].delta, b - FIELD_AT(p, short, 0x30), c - FIELD_AT(p, short, 0x32));
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80064478);

EXTERN_C int func_80064570(void *self)
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

EXTERN_C void func_800646D4(void)
{
}

EXTERN_C void func_800646DC(void *self, int flags)
{
    func_8005F120(self, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800646FC);

EXTERN_C void func_80064884(int *s, int a, int b)
{
    if ((s[0x12] != b || s[0x11] != a) && !(a < b)) {
        int hi;
        s[0x11] = a;
        hi = s[0x13];
        s[0x12] = b;
        if (s[0x11] < hi) {
            s[0x13] = s[0x11];
        } else if (hi < b) {
            s[0x13] = b;
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_800648E8);

EXTERN_C int func_80064B3C(void *self)
{
    char *v;
    char *e;
    void *r;
    if (func_80053830(self ? (char *)self + 0x38 : 0)) {
        ((VObj<0x2C> *)self)->v28(func_80053874(self ? (char *)self + 0x38 : 0) & 0xFF);
        return 1;
    }
    e = (char *)func_80019F64(h8_80064B3C(FIELD_AT(self, char *, 0x30)), 6);
    v = FIELD_AT(self, char *, 0x30) ? FIELD_AT(self, char *, 0x30) + 8 : 0;
    ((void (*)(void *, void *))func_80019CFC)(v ? *(void **)v : 0, e);
    r = (void *)((VObj<0x2C> *)self)->v11();
    func_8002DC34(r, (int)e, 0);
    FIELD_AT(e, int, 0x4) = 0;
    func_8005F50C((Pool_8005F50C *)__builtin_new(0x14), (int)e, 1, 1);
    ((VObj<0x2C> *)self)->v14();
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80064C78);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80064E0C);

INCLUDE_ASM("asm/main/nonmatchings/u_80062610", func_80065458);

EXTERN_C void func_80065870(void)
{
    Col_80065870 *a = &D_800B4E38;
    Col_80065870 *b = &D_800B4E40;
    Col_80065870 *c = &D_800B4E48;
    Col_80065870 *d = &D_800B4E50;
    a->r = 0xFF;
    a->g = 0x40;
    a->b = 0x10;
    D_800B4E38.a = 0;
    b->r = 0xC0;
    b->g = 0xC0;
    b->b = 0xFF;
    D_800B4E40.a = 0;
    c->r = 0x80;
    c->g = 0x20;
    c->b = 0x20;
    D_800B4E48.a = 0;
    d->r = 0xFF;
    d->g = 0xFF;
    d->b = 0xFF;
    D_800B4E50.a = 0;
}
