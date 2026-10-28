#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"
#include "game/b2/b2.h"

/* defined in u_800658E0.cpp; reached with lui here */
EXTERN_C void *D_800B4ED8[];

EXTERN_C void func_80071A74(void *self, int b)
{
    func_80076EF8(self, b);
}

EXTERN_C void *func_80071A94(void *self)
{
    func_80076EA8(self);
    FIELD_AT(self, int, 0x54) = 0;
    FIELD_AT(self, int, 0x58) = 0;
    return self;
}

EXTERN_C void *func_80071AC4(void *self)
{
    return func_800751AC(self);
}

EXTERN_C void func_80071AE4(void *self, void *node)
{
    func_8007505C(self, node);
}

EXTERN_C void func_80071B04(void *self, int b)
{
    func_80074F78(self, b);
}

EXTERN_C void *func_80071B24(void *self, void *src)
{
    int *v;
    char *r;
    func_80074E28(self);
    FIELD_AT(self, void *, 0x8) = D_80016270;
    v = (int *)((char *)self + 0x1C);
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    FIELD_AT(self, int, 0xC) = FIELD_AT(src, int, 0xC);
    FIELD_AT(self, int, 0x10) = FIELD_AT(src, int, 0x10);
    FIELD_AT(self, int, 0x14) = FIELD_AT(src, int, 0x14);
    FIELD_AT(self, int, 0x18) = FIELD_AT(src, int, 0x18);
    FIELD_AT(self, B16_B, 0x1C) = FIELD_AT(src, B16_B, 0x1C);
    FIELD_AT(self, int, 0x2C) = FIELD_AT(src, int, 0x2C);
    r = (char *)self;
    FIELD_AT(r, int, 0x30) = FIELD_AT(src, int, 0x30);
    return r;
}

EXTERN_C Obj_80071BDC *func_80071BDC(Obj_80071BDC *self)
{
    func_80074E28(self);
    FIELD_AT(self, void *, 0x8) = D_80016270;
    int *l = self->list;
    l[0] = 0;
    l[1] = 0;
    l[2] = 0;
    l[3] = 0;
    return self;
}

EXTERN_C void func_80071C24(void *self, int b)
{
    func_80074E44(self, b);
}

EXTERN_C void func_80071C44(void *self, int b)
{
    FIELD_AT(self, void *, 0x40) = D_80016280;
    FIELD_AT(self, void *, 0x8) = D_80016298;
    func_800777E8(self, b);
}

EXTERN_C void func_80071C78(void *self, void *b)
{
    if (FIELD_AT(self, short, 0x5D2) != 0 && FIELD_AT(self, int, 0x298) != 0) {
        func_80071D90(self, 0, 1);
    }
    if (FIELD_AT(FIELD_AT(self, char *, 0x550), int, 0x30) != 0 && FIELD_AT(self, short, 0x5D2) != 0) {
        char buf[0x28];
        int r;
        func_80048D54(buf);
        while (func_80046658(buf, FIELD_AT(FIELD_AT(self, char *, 0x550), int, 0x30), FIELD_AT(FIELD_AT(self, char *, 0x550), int, 0x34), b) != 1) {
        }
        r = *func_80049398(buf);
        if (r != 0) {
            FIELD_AT(self, int, 0x298) = r;
            func_80071E90(self);
        }
        func_80048D2C(buf, 2);
    } else {
        func_80071E90(self);
        FIELD_AT(self, short, 0x5D2) = 1;
    }
    if (FIELD_AT(self, char *, 0x550) != 0) {
        FIELD_AT(self, short, 0x1A4) = FIELD_AT(FIELD_AT(self, char *, 0x550), signed char, 0x92);
    }
}

EXTERN_C void func_80071D90(void *self, void *b, int c)
{
    if (FIELD_AT(self, void *, 0x298) != 0) {
        func_80071F08(self);
        if ((short)c != 0) {
            char *p = (char *)__builtin_new(0xC);
            void *x = FIELD_AT(self, void *, 0x298);
            char *q;
            FIELD_AT(p, void *, 0) = D_800127E4;
            FIELD_AT(p, int, 4) = 4;
            void *mg = &D_800A4544;
            FIELD_AT(p, void *, 8) = x;
            q = (char *)__builtin_new(0x14);
            FIELD_AT(q, void *, 0) = D_80010178;
            FIELD_AT(q, int, 4) = 0;
            FIELD_AT(q, void *, 0) = D_80010338;
            FIELD_AT(q, short, 0xC) = 0x80;
            FIELD_AT(q, void *, 8) = p;
            FIELD_AT(q, int, 0x10) = 1;
            func_8001D150(mg, q);
            int n1 = D_800B4D28_w;
            int n2 = D_800B4D30_w;
            FIELD_AT(self, int, 0x298) = 0;
            D_800B4D28_w = n1 + 1;
            D_800B4D30_w = n2 + 1;
        }
        FIELD_AT(self, short, 0x5D2) = c;
    }
}

EXTERN_C void func_80071E90(void *self)
{
    if (FIELD_AT(self, int, 0x298) != 0 && FIELD_AT(self, void *, 0x1B8) != 0) {
        void *r = func_8003912C(FIELD_AT(self, void *, 0x1B8), FIELD_AT(FIELD_AT(self, void *, 0x550), unsigned char, 0x8A) == 8 ? 0x12 : 0xD);
        if (r != 0) {
            func_80039BEC(r, FIELD_AT(self, int, 0x298));
        }
    }
}

EXTERN_C void func_80071F08(void *self)
{
    if (FIELD_AT(self, int, 0x298) != 0) {
        int k = FIELD_AT(FIELD_AT(self, void *, 0x550), unsigned char, 0x8A) == 8 ? 0x12 : 0xD;
        func_80039C88(func_8003912C(FIELD_AT(self, void *, 0x1B8), k), FIELD_AT(self, int, 0x298));
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80071F6C);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80072130);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_800722EC);

EXTERN_C void func_80072508(void)
{
}

EXTERN_C void func_80072510(void *self)
{
    func_80072B84(self, FIELD_AT(self, short, 0x140));
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80072534);

EXTERN_C int func_800725F4(void *self)
{
    if (FIELD_AT(self, short, 0x220) == 0) {
        func_80074564(self);
    } else {
        func_80073960(self);
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80072634);

EXTERN_C int func_800727DC(void *self, void *a1)
{
    FIELD_AT(self, short, 0x5C8) = 1;
    FIELD_AT(self, unsigned short, 0x140) = ~FIELD_AT(a1, unsigned short, 0x1A);
    if (~FIELD_AT(self, unsigned short, 0x140) & 0x4000) {
        func_80043740(self, 4);
    }
    if (FIELD_AT(self, short, 0x220) == 0) {
        if (func_800729E8(self, FIELD_AT(self, short, 0x140)) != 0) {
            func_80044990((char *)self + 0x234, FIELD_AT(FIELD_AT(self, void *, 0x1B8), short, 0x2E), FIELD_AT(self, short, 0x1BC) << 9, 0x14, 1, 0);
        }
        if ((FIELD_AT(self, unsigned short, 0x140) & 0xF0) && (FIELD_AT(self, unsigned short, 0x5DC) & 0xF0)) {
            return 1;
        }
        FIELD_AT(self, int, 0xF8) = 0;
        FIELD_AT(self, unsigned char, 0x120)++;
    }
    FIELD_AT(self, unsigned short, 0x5DC) = FIELD_AT(self, unsigned short, 0x140);
    return 1;
}

EXTERN_C int func_800728C0(void)
{
    return 1;
}

EXTERN_C void func_800728C8(void *self, int a, int b)
{
    View_80072970 *g;
    FIELD_AT(self, short, 0x5CC) = 1;
    FIELD_AT(self, short, 0x142) = 1;
    g = (View_80072970 *)&D_800A4534;
    FIELD_AT(self, int, 0x5D4) = g->p->a;
    FIELD_AT(self, int, 0x5D8) = g->p->b;
    g->p->a = a;
    g->p->b = b;
    func_800230E8((char *)g->p + 0x154, self);
    {
        char *v = (char *)g->p + 0x154;
        int t = FIELD_AT(v, short, 0x104);
        FIELD_AT(v, short, 0x104) = 10;
        FIELD_AT(self, short, 0x5D0) = t;
    }
}

EXTERN_C void func_80072970(void *self)
{
    View_80072970 *g = (View_80072970 *)&D_800A4534;
    int v = FIELD_AT(self, short, 0x5D0);
    FIELD_AT(self, short, 0x5CC) = 0;
    FIELD_AT(self, short, 0x142) = 0;
    g->p->c = v;
    g->p->a = FIELD_AT(self, short, 0x5D4);
    g->p->b = FIELD_AT(self, short, 0x5D8);
    func_800232A0((char *)g->p + 0x154, self);
    FIELD_AT(self, short, 0x140) = 0;
    FIELD_AT(self, short, 0x5DC) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_800729E8);

EXTERN_C void func_80072B84(void *self, int a)
{
    char buf[64];
    if ((a & 0xF0) != 0) {
        short s = a;
        if (FIELD_AT(self, unsigned short, 0x5DC) != s) {
            func_800729E8(self, s);
        }
        void *x = D_800B4D38_w;
        int b = FIELD_AT(self, short, 0x144);
        unsigned short t = FIELD_AT(self, unsigned short, 0x140);
        int c = FIELD_AT(self, short, 0x118);
        FIELD_AT(self, unsigned short, 0x5DC) = t;
        func_8003FA50(self, x, b, c);
        if (FIELD_AT(self, int, 0x13C) != 0) {
            if (FIELD_AT(self, unsigned char, 0x120) != 0) {
                func_8003E198(self, FIELD_AT(self, int, 0x13C), (FIELD_AT(self, short, 0x1BC) << 25) >> 16);
            } else {
                int r = func_8003E170(self);
                func_8003ED90(buf, self);
                if ((short)r != 0) {
                    FIELD_AT(self, short, 0x11E) = 1;
                    func_8003ECFC(self, 0, 0);
                }
            }
        } else {
            func_8003E124(self);
        }
        if (FIELD_AT(self, int, 0x1B8) != 0 && FIELD_AT(self, short, 0x5CC) != 0 && D_800B4EDC != 0) {
            int t = FIELD_AT(self, int, 0x218) - 1;
            FIELD_AT(self, int, 0x218) = t;
            if (FIELD_AT(self, unsigned char, 0x10C) == 0) {
                if (t < 0) {
                    func_800745B0(self);
                    func_80079918(D_800AF470_w);
                    FIELD_AT(self, short, 0x5CC) = 0;
                }
            } else if (t < 0x5A) {
                FIELD_AT(self, int, 0x218) = 0x5A;
            }
        }
    } else {
        func_8003E124(self);
    }
}

EXTERN_C int func_80072CFC(void *self)
{
    if ((unsigned int)(FIELD_AT(self, unsigned short, 0x11C) - 11) < 20 || (unsigned int)(FIELD_AT(self, unsigned short, 0x11C) - 35) < 6) {
        if (!any2_80072CFC(self)) {
            return 1;
        }
        if (FIELD_AT(self, unsigned char, 0x110) == 0x50 && (unsigned int)(FIELD_AT(self, unsigned short, 0x11C) - 35) < 6) {
            func_800437A4(self, FIELD_AT(FIELD_AT(self, char *, 0x13C), unsigned char, 0x12));
        } else if (!((unsigned int)(FIELD_AT(self, unsigned short, 0x11C) - 35) < 6) && ((unsigned int)((FIELD_AT(self, int, 0x10C) & 0xFF) - 0x40) < 0x20 || (FIELD_AT(self, int, 0x10C) & 0xF8) == 0x98)) {
            func_800437A4(self, FIELD_AT(FIELD_AT(self, char *, 0x13C), unsigned char, 0x12));
        } else {
            func_800437A4(self, FIELD_AT(FIELD_AT(self, char *, 0x13C), unsigned char, 0x13));
        }
        func_800437CC(self, 0, 0, 0);
        return 0;
    }
    switch ((short)FIELD_AT(self, unsigned short, 0x11C)) {
    case 7:
    case 9:
        if (FIELD_AT(FIELD_AT(self, char *, 0x13C), unsigned char, 0x13) != 0) {
            func_8003FC48(self);
        }
        break;
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80072E70);

EXTERN_C void func_80073960(void *self)
{
    FIELD_AT(self, short, 0x5C8) = 0;
    FIELD_AT(self, short, 0x140) = 0;
    FIELD_AT(self, short, 0x5DC) = 0;
    FIELD_AT(self, int, 0xF8) = 0;
    FIELD_AT(self, unsigned char, 0x120)++;
}

EXTERN_C void func_80073980(void *self)
{
    FIELD_AT(self, short, 0x5C8) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007398C);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80073C04);

EXTERN_C int func_80074468(void *self)
{
    int ret = 0;
    int r = func_80073C04(self);
    if (r != 0) {
        func_800435E8(self);
        switch (r) {
        case 1:
            func_800437A4(self, 0x1F);
            break;
        case 2:
            func_800437A4(self, 0x20);
            break;
        case 3:
            func_800437A4(self, 0x10);
            break;
        case 4:
            func_800437A4(self, 0xB);
            break;
        case 5:
            func_800437A4(self, 0x15);
            break;
        case 6:
            func_800437A4(self, 0x1A);
            break;
        case 7:
            func_800437A4(self, 0x26);
            break;
        case 8:
            func_800437A4(self, 0x23);
            break;
        }
        func_800437CC(self, 1, 0, 0);
        ret = 1;
    }
    return ret;
}

EXTERN_C void func_80074564(void *self)
{
    if (FIELD_AT(self, short, 0x220) == 2) {
        func_80044590(self);
    }
    FIELD_AT(self, short, 0x220) = 0;
    func_80073960(self);
}

EXTERN_C void func_800745A8(void *self, int b)
{
    FIELD_AT(self, short, 0x5CE) = b;
}

EXTERN_C void func_800745B0(void *self)
{
    if (func_80061E9C(D_800B4DD0_w, 0x87)) {
        FIELD_AT(self, short, 0x5CE) = 0x4B0;
    }
    short s = FIELD_AT(self, short, 0x5CE);
    FIELD_AT(self, int, 0x218) = (short)(int)func_8008B4B4((char *)(s + 0x2F0), (char *)(s + 0x42B));
}

EXTERN_C Vec_8007460C *func_8007460C(Vec_8007460C *out, Vec_8007460C *a, Vec_8007460C *b)
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

EXTERN_C void func_8007464C(void *self)
{
    void *o = func_8001CA10(0x14);
    FIELD_AT(o, void * volatile, 0x0) = D_80010178;
    FIELD_AT(o, int, 0x4) = 0;
    FIELD_AT(o, void * volatile, 0x0) = D_80010300;
    FIELD_AT(o, short, 0x8) = 2;
    FIELD_AT(o, short, 0xA) = 0xC;
    FIELD_AT(o, int, 0xC) = 0;
    FIELD_AT(o, int, 0x10) = 0x65;
    FIELD_AT(o, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, o);
}

EXTERN_C void func_800746C4(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 0xC;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 100;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007473C(void *self, int b)
{
    FIELD_AT(self, short, 0x5CA) = b;
}

EXTERN_C int func_80074744(D_80074744 *self, int b)
{
    int c = b;
    if (c != 0) {
        self->v02(c);
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007479C);

EXTERN_C void func_800749A8(void)
{
}

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800164C8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80016518);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80016528);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800165C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800165E0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800165F8);

EXTERN_C void func_800749B0(void *self)
{
    Rgb_B c;
    switch (FIELD_AT(self, unsigned char, 0x545)) {
    case 1:
        c.v[0] = 0x40;
        c.v[1] = 0;
        c.v[2] = 0;
        break;
    case 2:
        c.v[0] = 0;
        c.v[1] = 0;
        c.v[2] = 0x40;
        break;
    case 3:
        c.v[0] = 0;
        c.v[1] = 0x40;
        c.v[2] = 0;
        break;
    case 4:
        c.v[0] = 0x40;
        c.v[1] = 0x40;
        c.v[2] = 0;
        break;
    case 5:
        c.v[0] = 0x80;
        c.v[1] = 0x80;
        c.v[2] = 0x80;
        break;
    case 6:
        c.v[0] = 0;
        c.v[1] = 0;
        c.v[2] = 0;
        break;
    }
    if (FIELD_AT(self, unsigned char, 0x545) != 0) {
        func_8003D358_c(FIELD_AT(FIELD_AT(self, char *, 0x1B8), void *, 0x68), 1, c);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80074AB4);

EXTERN_C Vec_80074C50 *func_80074C50(Vec_80074C50 *out, Vec_80074C50 *a, Vec_80074C50 *b)
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

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80074C90);

EXTERN_C void *func_80074E28(void *self)
{
    FIELD_AT(self, void *, 0x8) = D_800166A8;
    FIELD_AT(self, void *, 0x4) = self;
    FIELD_AT(self, void *, 0x0) = self;
    return self;
}

// GCC 2.x deleting destructor: bit 0 of flags frees the object.
EXTERN_C void func_80074E44(void *self, int flags)
{
    FIELD_AT(self, void *, 0x8) = D_800166A8;
    if (flags & 1) {
        operator delete(self);
    }
}

EXTERN_C void func_80074E78(Node_80074E78 *a, Node_80074E78 *b)
{
    Node_80074E78 *t;
    a->prev->next = b;
    b->prev->next = a;
    t = a->prev;
    a->prev = b->prev;
    b->prev = t;
}

EXTERN_C Node_80074EA4 *func_80074EA4(Node_80074EA4 *head)
{
    Node_80074EA4 *n = head->next;
    if (n == head) {
        return 0;
    }
    head->prev->next = n;
    head->next->prev = head->prev;
    head->prev = head;
    head->next = head;
    return n;
}

EXTERN_C int func_80074EE8(Node_80074EE8 *a)
{
    int n = 1;
    Node_80074EE8 *p;
    for (p = a; p->next != a; p = p->next) {
        n++;
    }
    return n;
}

EXTERN_C void func_80074F1C(void *self, Node_80074E78 *b)
{
    func_80074E78(FIELD_AT(self, Node_80074E78 *, 0x0), b);
}

EXTERN_C int func_80074F40(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_80074F4C(void *self)
{
    return FIELD_AT(self, int, 0x0);
}

EXTERN_C void *func_80074F58(void *self)
{
    FIELD_AT(self, void *, 0xC) = D_800166B8;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, int, 0x8) = 0;
    return self;
}

EXTERN_C void func_80074F78(void *self, int b)
{
    FIELD_AT(self, void *, 0xC) = D_800166B8;
    if (b & 1) {
        operator delete(self);
    }
}

EXTERN_C int func_80074FAC(List_80074FAC *self, Node_80074FAC *n)
{
    Node_80074FAC *p;
    if (self->head == 0) {
        return 0;
    }
    p = self->head;
    do {
        if (p == n) {
            self->cur = p;
            return 1;
        }
        if (p == self->head->prev) {
            break;
        }
        p = p->next;
    } while (1);
    return 0;
}

EXTERN_C void func_80075004(List_80075004 *self, Node_80074E78 *n)
{
    self->count += func_80074EE8((Node_80074EE8 *)n);
    if (self->head != 0) {
        func_80074E78(n, self->head);
    }
    self->head = n;
    self->cur = n;
}

EXTERN_C void func_8007505C(void *self, void *node)
{
    FIELD_AT(self, int, 0x8) += func_80074EE8((Node_80074EE8 *)node);
    if (FIELD_AT(self, void *, 0x0) == 0) {
        FIELD_AT(self, void *, 0x0) = node;
    } else {
        func_80074E78(FIELD_AT(self, Node_80074E78 *, 0x0), (Node_80074E78 *)node);
    }
    FIELD_AT(self, void *, 0x4) = node;
}

EXTERN_C void func_800750B8(void *self, void *node)
{
    if (FIELD_AT(self, void *, 0x0) == 0) {
        func_8007505C(self, node);
    } else {
        FIELD_AT(self, int, 0x8) += func_80074EE8((Node_80074EE8 *)node);
        func_80074E78(FIELD_AT(self, Node_80074E78 *, 0x4)->next, (Node_80074E78 *)node);
        FIELD_AT(self, void *, 0x4) = node;
    }
}

EXTERN_C void func_80075128(LList_B *l, LNode_B *n)
{
    if (l->head == 0) {
        func_8007505C(l, n);
    } else {
        l->count += func_80074EE8((Node_80074EE8 *)n);
        func_80074E78((Node_80074E78 *)n, (Node_80074E78 *)l->cur);
        if (l->head == l->cur) {
            l->head = n;
        }
        l->cur = n;
    }
}

EXTERN_C void *func_800751AC(void *self)
{
    Node_80074EA4 *n = FIELD_AT(self, Node_80074EA4 *, 0x0);
    Node_80074EA4 *r;
    if (n == 0) {
        return 0;
    }
    r = func_80074EA4(n);
    FIELD_AT(self, Node_80074EA4 *, 0x0) = r;
    if (FIELD_AT(self, Node_80074EA4 *, 0x4) == n) {
        FIELD_AT(self, Node_80074EA4 *, 0x4) = r;
    }
    if (--FIELD_AT(self, int, 0x8) == 0) {
        FIELD_AT(self, void *, 0x4) = 0;
        FIELD_AT(self, void *, 0x0) = 0;
    }
    return n;
}

EXTERN_C LNode_B *func_80075220(LList_B *l)
{
    LNode_B *n;
    if (l->head == 0) {
        return 0;
    }
    n = l->head->prev;
    func_80074EA4((Node_80074EA4 *)n);
    if (l->cur == n && l->head != 0) {
        l->cur = l->head->prev;
    }
    if (--l->count == 0) {
        l->cur = 0;
        l->head = 0;
    }
    return n;
}

EXTERN_C void *func_800752B8(void *self)
{
    if (((List_8007AB78 *)self)->head == ((List_8007AB78 *)self)->cur) {
        return func_800751AC(self);
    }
    if (((List_8007AB78 *)self)->IsLast()) {
        return func_80075220((LList_B *)self);
    }
    LNode_B *c = ((List_8007AB78 *)self)->cur;
    ((List_8007AB78 *)self)->cur = (LNode_B *)func_80074EA4((Node_80074EA4 *)c);
    FIELD_AT(self, int, 8)--;
    return c;
}

EXTERN_C void *func_80075358(void *self)
{
    if (((List_8007AB78 *)self)->IsLast()) {
        return 0;
    }
    ((List_8007AB78 *)self)->Next();
    return func_800752B8(self);
}

EXTERN_C void *func_800753F8(void *self)
{
    Node_800753F8 *h = FIELD_AT(self, Node_800753F8 *, 0x0);
    Node_800753F8 *c = FIELD_AT(self, Node_800753F8 *, 0x4);
    if (h == c) {
        return 0;
    }
    if (h != 0) {
        FIELD_AT(self, Node_800753F8 *, 0x4) = c->prev;
    }
    return func_800752B8(self);
}

EXTERN_C int func_80075448(void *self, void *x)
{
    LNode_B *p;
    if (((List_8007AB78 *)self)->IsEmpty()) {
        return 0;
    }
    if (x == ((List_8007AB78 *)self)->head) {
        return (int)func_800751AC(self);
    }
    p = ((List_8007AB78 *)self)->head;
    while (1) {
        if (p == x) {
            if (p == ((List_8007AB78 *)self)->cur) {
                if (((List_8007AB78 *)self)->IsLast()) {
                    if (((List_8007AB78 *)self)->head != 0 && ((List_8007AB78 *)self)->head != ((List_8007AB78 *)self)->cur) {
                        ((List_8007AB78 *)self)->cur = ((List_8007AB78 *)self)->cur->prev;
                    }
                } else {
                    ((List_8007AB78 *)self)->Next();
                }
            }
            func_80074EA4((Node_80074EA4 *)p);
            if (--FIELD_AT(self, int, 0x8) == 0) {
                ((List_8007AB78 *)self)->cur = 0;
                ((List_8007AB78 *)self)->head = 0;
            }
            return (int)p;
        }
        if (p == ((List_8007AB78 *)self)->head->prev) {
            return 0;
        }
        p = p->next;
    }
}

EXTERN_C int func_800755AC(void *self)
{
    void *p = FIELD_AT(self, void *, 0x0);
    if (p == 0) {
        return 0;
    }
    return FIELD_AT(p, int, 0x4);
}

EXTERN_C int func_800755C8(void *self)
{
    return FIELD_AT(self, int, 0x0);
}

EXTERN_C int func_800755D4(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800755E0(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

EXTERN_C void func_800755EC(void *self)
{
    void *p = FIELD_AT(self, void *, 0x0);
    if (p != 0) {
        void *c = FIELD_AT(self, void *, 0x4);
        if (p != c) {
            FIELD_AT(self, void *, 0x4) = FIELD_AT(c, void *, 0x4);
        }
    }
}

struct List_80075620 {
    Node_80075620 *head;
    Node_80075620 *cur;
    bool IsEmpty() { return head == 0; }
    bool IsLast() { return IsEmpty() ? false : head->prev == cur; }
};

EXTERN_C void func_80075620(List_80075620 *self)
{
    if (!self->IsEmpty()) {
        if (!self->IsLast()) {
            self->cur = self->cur->next;
        }
    }
}

EXTERN_C void func_80075674(void *self)
{
    void *p = FIELD_AT(self, void *, 0x0);
    if (p != 0) {
        FIELD_AT(self, void *, 0x4) = FIELD_AT(p, void *, 0x4);
    }
}

EXTERN_C void func_80075698(void *self)
{
    FIELD_AT(self, int, 0x4) = FIELD_AT(self, int, 0x0);
}

EXTERN_C int func_800756A4(void *self)
{
    void *p = FIELD_AT(self, void *, 0x0);
    if (p == 0) {
        return 0;
    }
    return FIELD_AT(p, int, 0x4) == FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800756D4(void *self)
{
    return FIELD_AT(self, int, 0x0) == FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800756EC(void *self)
{
    return FIELD_AT(self, int, 0x0) == 0;
}

EXTERN_C void *func_800756F8(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80016808;
    return self;
}

EXTERN_C void *func_8007570C(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800167F8;
    FIELD_AT(self, int, 0x10) = 0;
    FIELD_AT(self, int, 0x18) = 0;
    FIELD_AT(self, int, 0x1C) = 0;
    FIELD_AT(self, int, 0x20) = 1;
    return self;
}

EXTERN_C Obj_80075744 *func_80075744(Obj_80075744 *self, int b, int c, int d, int e)
{
    self->vtable = D_80010178;
    self->unk4 = 0;
    self->vtable = D_800167F8;
    self->unk8 = b;
    self->unkC = c;
    self->unk10 = 0;
    self->unk14 = d;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = e;
    return self;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80075788);

EXTERN_C void func_80075828(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_800167F8;
    if (FIELD_AT(self, int, 0x10) != 0 && FIELD_AT(self, void *, 0xC) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0xC));
    }
    func_8007589C(self);
    func_8001A610(self, flags);
}

EXTERN_C void func_80075894(void *self, int b)
{
    FIELD_AT(self, int, 0x18) = b;
}

EXTERN_C void func_8007589C(void *self)
{
    char *p = FIELD_AT(self, char *, 0x18);
    if (p != 0) {
        ((VObj0 *)(p + 0x8))->v00(3);
        FIELD_AT(self, int, 0x18) = 0;
        FIELD_AT(self, int, 0x1C) = 0;
    }
}

EXTERN_C void *func_800758F8(void *self, int b, void *c, void *d)
{
    char *s;
    char *r;
    if (b) {
        S_800758F8 *v = (S_800758F8 *)((char *)self + 0x1C0);
        FIELD_AT(self, S_800758F8 *, 0xFC) = v;
        v->a = 0x10;
        v->b = 0;
        v->c = -1;
    }
    func_8001E40C(self, (int)c, 2, 0x400, 0);
    FIELD_AT(self, void *, 0xF8) = D_80012154;
    s = (char *)self + 0xF8;
    FIELD_AT(self, void *, 0x100) = D_80010348;
    FIELD_AT(s, void *, 0x8) = D_8001201C;
    FIELD_AT(self, void *, 0xF8) = D_80012034;
    FIELD_AT(self, void *, 0x104) = (char *)self + 0x108;
    func_800198E0((char *)self + 0x108, 4, 0);
    FIELD_AT(s, void *, 0x8) = D_80012294;
    FIELD_AT(self, void *, 0xF8) = D_80012224;
    FIELD_AT(s, int, 0x28) = 0;
    FIELD_AT(s, int, 0x2C) = 0;
    FIELD_AT(self, void *, 0x134) = D_80011FE4;
    FIELD_AT(self, void *, 0x8C) = D_800167C8;
    FIELD_AT(self, void *, 0x100) = D_80016740;
    FIELD_AT(self, void *, 0xF8) = D_80016758;
    FIELD_AT(self, void *, 0x134) = D_80016708;
    FIELD_AT(self, void *, 0x0) = D_800167E0;
    FIELD_AT(self, void *, 0x148) = d;
    func_8007570C((char *)self + 0x150);
    func_8007570C((char *)self + 0x174);
    func_8007570C((char *)self + 0x198);
    r = (char *)self;
    FIELD_AT(r, int, 0x13C) = 0;
    FIELD_AT(r, int, 0x14C) = 0;
    FIELD_AT(r, int, 0x1BC) = 0;
    return r;
}

EXTERN_C void func_80075A40(void *self, int flags)
{
    char *b;
    FIELD_AT(self, void *, 0x8C) = D_800167C8;
    FIELD_AT(self, void *, 0x100) = D_80016740;
    FIELD_AT(self, void *, 0xF8) = D_80016758;
    FIELD_AT(self, void *, 0x134) = D_80016708;
    FIELD_AT(self, void *, 0x0) = D_800167E0;
    if (FIELD_AT(self, char *, 0x14C) != 0) {
        func_80035EB4(FIELD_AT(self, char *, 0x14C) + 4);
        if (FIELD_AT(self, VObj0 *, 0x14C) != 0) {
            FIELD_AT(self, VObj0 *, 0x14C)->v00(3);
        }
    }
    func_80075828((char *)self + 0x198, 2);
    func_80075828((char *)self + 0x174, 2);
    func_80075828((char *)self + 0x150, 2);
    b = (char *)self + 0xF8;
    FIELD_AT(b, void *, 0x8) = D_80012294;
    FIELD_AT(self, void *, 0xF8) = D_80012224;
    func_80035304(b, 0);
    func_8001E508(self, 0);
    if (flags & 1) {
        __builtin_delete(self);
    }
}

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800166A8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800166B8);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80075B4C);

EXTERN_C void func_80075DD8(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 5;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 6;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_80075E50(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 5;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 4;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80075EC8);

EXTERN_C void func_80075FB4(void *self)
{
    func_80075EC8(self, 1);
}

EXTERN_C void func_80075FD4(void *self)
{
    FIELD_AT(self, int, 0x13C) = 3;
    if (FIELD_AT(self, int, 0x1BC) == 0) {
        func_8003546C(self ? (char *)self + 0xF8 : 0, self ? (char *)self + 0x134 : 0);
    }
    func_8003714C(self ? (char *)self + 0xF8 : 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80076038);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80076370);

EXTERN_C int func_8007669C(void *self, int b, int c)
{
    if (FIELD_AT(self, int, 0x13C) != 0) {
        return 0;
    }
    FIELD_AT(self, int, 0x140) = b;
    FIELD_AT(self, int, 0x144) = c;
    func_80075EC8(self, 0);
    return 1;
}

EXTERN_C void func_800766D8(void *self)
{
    func_80076370(self);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_800766F8);

EXTERN_C void func_80076848(void *self, int a1, int a2, int a3)
{
    char *n;
    char *m;
    char *s;
    int x;
    int y;
    FIELD_AT(self, int, 0x1BC) = 1;
    n = (char *)func_80075788(__builtin_new(0x24), a1, a2, a3, 0);
    m = (char *)__builtin_new(0x28);
    x = FIELD_AT(n, int, 0x8);
    y = FIELD_AT(n, int, 0xC);
    s = m + 8;
    FIELD_AT(m, void *, 0x0) = D_80011FE4;
    FIELD_AT(m, void *, 0x8) = D_800100F8;
    FIELD_AT(m, void *, 0xC) = D_80010198;
    FIELD_AT(s, void *, 0x4) = D_800101C0;
    FIELD_AT(m, void *, 0x8) = D_800101B0;
    FIELD_AT(s, short, 0xC) = 6;
    FIELD_AT(s, short, 0xE) = 4;
    FIELD_AT(s, short, 0x10) = 5;
    FIELD_AT(s, short, 0x12) = 2;
    FIELD_AT(s, void *, 0x8) = self;
    FIELD_AT(m, void *, 0xC) = D_80012104;
    FIELD_AT(m, void *, 0x8) = D_800120F4;
    FIELD_AT(m, void *, 0x0) = D_8001211C;
    FIELD_AT(m, int, 0x20) = 0;
    FIELD_AT(m, int, 0x1C) = x;
    FIELD_AT(m, int, 0x24) = y;
    func_80075894(n, (int)m);
    func_8001A678((char *)self + 0x150, n);
    func_8003546C(self ? (char *)self + 0xF8 : 0, m);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007698C);

EXTERN_C void func_80076AEC(void *self)
{
    if (FIELD_AT(self, int, 0x1BC) == 0) {
        VObj0 *o = FIELD_AT(self, VObj0 *, 0x148);
        if (o != 0) {
            char *b = self ? (char *)self + 0xF8 : 0;
            o->v00(FIELD_AT(b, int, 0x2C), FIELD_AT(self, int, 0x120), 0);
        }
    } else {
        char *l = (char *)self + 0x150;
        char *n = FIELD_AT(l, char *, 0x4);
        if (n != 0) {
            VObj0 *o2;
            func_8001A744(l, n);
            FIELD_AT(n, int, 0x4) = 0;
            func_8007589C(n);
            func_8001A678((char *)self + 0x174, n);
            FIELD_AT(self, int, 0x140) += 1 + (FIELD_AT(n, unsigned int, 0x8) >> 10);
            FIELD_AT(self, int, 0x144) -= FIELD_AT(n, int, 0x8);
            o2 = FIELD_AT(self, VObj0 *, 0x148);
            if (o2 != 0) {
                o2->v00(FIELD_AT(n, int, 0xC), FIELD_AT(n, int, 0x8), FIELD_AT(n, int, 0x14));
            }
        }
    }
}

EXTERN_C int func_80076BE8(void *self)
{
    return FIELD_AT(self, int, 0x144);
}

EXTERN_C int func_80076BF4(void *self, int b)
{
    unsigned v = FIELD_AT(self, unsigned, 0x20) + b;
    FIELD_AT(self, unsigned, 0x20) = v;
    if (FIELD_AT(self, unsigned, 0x1C) < v) {
        FIELD_AT(self, unsigned, 0x20) = FIELD_AT(self, unsigned, 0x1C);
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80076C1C);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80076CD0);

EXTERN_C void func_80076D70(void *self, int flags)
{
    void *p;
    FIELD_AT(self, void *, 0x8) = D_80016878;
    p = FIELD_AT(self, void *, 0x10);
    if (p != 0) {
        operator delete(p);
    }
    func_80074E44(self, flags);
}

EXTERN_C void *func_80076DC4(void *self)
{
    func_80074F58(self);
    FIELD_AT(self, void *, 0xC) = D_80016868;
    return self;
}

static inline int empty_80076DF8(void *self)
{
    return FIELD_AT(self, int, 0x0) == 0;
}

EXTERN_C void func_80076DF8(void *self, int flags)
{
    FIELD_AT(self, void *, 0xC) = D_80016868;
    FIELD_AT(self, int, 0x4) = FIELD_AT(self, int, 0x0);
    while (!empty_80076DF8(self)) {
        func_80076E60(self);
    }
    func_80074F78(self, flags);
}

EXTERN_C void func_80076E60(void *self)
{
    VObj<0x8> *p = (VObj<0x8> *)func_800752B8(self);
    if (p != 0) {
        p->v00(3);
    }
}

EXTERN_C void *func_80076EA8(void *self)
{
    func_800785DC(self);
    func_800785DC((char *)self + 0x10);
    func_800785DC((char *)self + 0x24);
    func_80076DC4((char *)self + 0x34);
    FIELD_AT(self, int, 0x20) = 0;
    FIELD_AT(self, int, 0x44) = 0;
    FIELD_AT(self, int, 0x48) = 0;
    FIELD_AT(self, int, 0x4C) = 0;
    return self;
}

EXTERN_C void func_80076EF8(void *self, int flags)
{
    VObj<8> *p;
    func_800786A0(self);
    func_800786A0((char *)self + 0x10);
    p = FIELD_AT(self, VObj<8> *, 0x20);
    if (p != 0) {
        p->v00(3);
    }
    func_800786A0((char *)self + 0x24);
    clear_80076EF8((char *)self + 0x34);
    func_80076DF8((char *)self + 0x34, 2);
    func_80078610((char *)self + 0x24, 2);
    func_80078610((char *)self + 0x10, 2);
    func_80078610(self, 2);
    if (flags & 1) {
        __builtin_delete(self);
    }
}

EXTERN_C int func_80076FD8(void *self)
{
    if (FIELD_AT(self, void *, 0x20) == 0) {
        return 0;
    }
    if (FIELD_AT(self, int, 0x44) != 0) {
        return 0;
    }
    FIELD_AT(self, int, 0x44) = 1;
    switch (func_800785A8(FIELD_AT(self, void *, 0x20))) {
    case 1:
        func_800773B0(self, 1);
        break;
    case 2:
        func_80077444(self, 1);
        break;
    case 3:
        func_80077538(self, 1);
        break;
    case 0:
        FIELD_AT(self, int, 0x44) = 0;
        return 1;
    }
    FIELD_AT(self, int, 0x44) = 0;
    return 0;
}

EXTERN_C void func_800770B4(void *self, int a1, int a2)
{
    char *n = (char *)__builtin_new(0x14);
    func_80074E28(n);
    FIELD_AT(n, void *, 0x8) = D_80016878;
    FIELD_AT(n, int, 0xC) = a1;
    FIELD_AT(n, int, 0x10) = a2;
    func_8007505C((char *)self + 0x34, n);
    if (idle_800770B4(self)) {
        FIELD_AT(self, int, 0x50) = 0;
        if (FIELD_AT(self, int, 0x20) == 0) {
            FIELD_AT(self, int, 0x50) = 4;
        }
        if (FIELD_AT(self, int, 0x24) == 0) {
            FIELD_AT(self, int, 0x50) |= 2;
        }
        if (FIELD_AT(self, int, 0x10) == 0) {
            FIELD_AT(self, int, 0x50) |= 1;
        }
        func_80077254(self);
    } else {
        FIELD_AT(self, int, 0x4C)++;
    }
}

EXTERN_C int func_800771D4(void *self)
{
    return FIELD_AT(self, int, 0x20) != 0 || FIELD_AT(self, int, 0x24) != 0 || FIELD_AT(self, int, 0x10) != 0;
}

EXTERN_C void func_80077210(void *self, void *b)
{
    FIELD_AT(b, int, 0x1C) = 2;
    func_8007505C(self, b);
}

EXTERN_C int func_80077234(void *self, void *b)
{
    return func_80075448(self, b);
}

EXTERN_C void *func_80077254(void *self)
{
    char *n;
    if (FIELD_AT(self, void *, 0x20) != 0) {
        return 0;
    }
    while ((n = (char *)func_800751AC((char *)self + 0x34)) != 0) {
        char *r = (char *)func_80075448(self, FIELD_AT(n, void *, 0xC));
        void *k = FIELD_AT(n, void *, 0x10);
        FIELD_AT(n, void *, 0x10) = 0;
        ((VObj<8> *)n)->v00(3);
        if (r != 0) {
            func_80078520(r, k);
            FIELD_AT(r, int, 0x1C) = 3;
            FIELD_AT(r, int, 0x14) = FIELD_AT(r, int, 0x28) + FIELD_AT(r, int, 0x2C) * 4;
            FIELD_AT(r, int, 0x10) = FIELD_AT(r, int, 0x20);
            func_8007505C((char *)self + 0x10, r);
            if (FIELD_AT(self, void *, 0x20) == 0) {
                func_80077478(self);
            }
            return r;
        }
    }
    return 0;
}

EXTERN_C void *func_80077334(void *self, void *b)
{
    void *p = (void *)func_80075448((char *)self + 0x10, b);
    if (p == 0) {
        p = (void *)func_80075448((char *)self + 0x24, b);
    }
    if (p != 0) {
        FIELD_AT(p, int, 0x1C) = 2;
        func_80078564(p);
        func_8007505C(self, p);
    }
    return p;
}

EXTERN_C void *func_800773B0(void *self, int b)
{
    char *n = FIELD_AT(self, char *, 0x20);
    if (n != 0) {
        FIELD_AT(n, int, 0x1C) = 2;
        func_80078564(n);
        func_8007505C(self, n);
        FIELD_AT(self, void *, 0x20) = 0;
        if (b) {
            func_80077478(self);
        }
    }
    if (FIELD_AT(self, void *, 0x20) == 0) {
        FIELD_AT(self, int, 0x48)++;
        func_80077254(self);
    }
    return n;
}

EXTERN_C void func_80077444(void *self, int b)
{
    void *p = func_800773B0(self, b);
    if (p != 0) {
        func_80077234(self, p);
    }
}

EXTERN_C void *func_80077478(void *self)
{
    void *p;
    if (FIELD_AT(self, void *, 0x20) != 0) {
        func_800774D0(self, 0);
    }
    p = func_800751AC((char *)self + 0x10);
    if (p != 0) {
        FIELD_AT(p, int, 0x1C) = 4;
        FIELD_AT(self, void *, 0x20) = p;
    }
    return p;
}

EXTERN_C void *func_800774D0(void *self, int b)
{
    void *p = FIELD_AT(self, void *, 0x20);
    if (p != 0) {
        FIELD_AT(p, int, 0x1C) = 3;
        func_8007505C((char *)self + 0x10, p);
        FIELD_AT(self, void *, 0x20) = 0;
        if (b != 0) {
            func_80077478(self);
        }
    }
    return p;
}

EXTERN_C void *func_80077538(void *self, int b)
{
    void *p = FIELD_AT(self, void *, 0x20);
    if (p != 0) {
        FIELD_AT(p, int, 0x1C) = 5;
        func_8007505C((char *)self + 0x24, p);
        FIELD_AT(self, void *, 0x20) = 0;
        if (b != 0) {
            func_80077478(self);
        }
    }
    return p;
}

EXTERN_C void *func_800775A0(void *self, void *b)
{
    void *p = (void *)func_80075448((char *)self + 0x24, b);
    void *r = p;
    if (p != 0) {
        FIELD_AT(p, int, 0x1C) = 3;
        func_8007505C((char *)self + 0x10, p);
    }
    return r;
}

EXTERN_C void *func_800775F0(void *self)
{
    void *p = func_800751AC((char *)self + 0x24);
    void *r = p;
    if (p != 0) {
        FIELD_AT(p, int, 0x1C) = 3;
        func_8007505C((char *)self + 0x10, p);
    }
    return r;
}

EXTERN_C void func_80077640(void *self)
{
    FIELD_AT(self, int, 0x4) = FIELD_AT(self, int, 0x0);
}

EXTERN_C void *func_8007764C(void *self)
{
    return func_800751AC(self);
}

EXTERN_C void func_8007766C(void *self, void *node)
{
    func_8007505C(self, node);
}

EXTERN_C void func_8007768C(void *self)
{
    FIELD_AT(self, int, 0x4) = FIELD_AT(self, int, 0x0);
    while (!empty_8007768C(self)) {
        func_80076E60(self);
    }
}

EXTERN_C int func_800776D8(void *self)
{
    int old = FIELD_AT(self, int, 0x10);
    FIELD_AT(self, int, 0x10) = 0;
    return old;
}

EXTERN_C int func_800776E4(void *self)
{
    return FIELD_AT(self, int, 0x10);
}

EXTERN_C int func_800776F0(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

EXTERN_C void *func_800776FC(void *self, int b, int c)
{
    func_80074E28(self);
    FIELD_AT(self, void *, 0x8) = D_80016878;
    FIELD_AT(self, int, 0xC) = b;
    FIELD_AT(self, int, 0x10) = c;
    return self;
}

EXTERN_C void *func_80077750(void *self)
{
    func_80074E28(self);
    FIELD_AT(self, void *, 0x8) = D_80016878;
    FIELD_AT(self, int, 0xC) = 0;
    FIELD_AT(self, int, 0x10) = 0;
    return self;
}

EXTERN_C void *func_8007778C(void *self)
{
    func_80074E28(self);
    FIELD_AT(self, void *, 0x8) = D_80016BD0;
    FIELD_AT(self, int, 0x10) = 0;
    FIELD_AT(self, int, 0x14) = 0;
    FIELD_AT(self, int, 0x18) = 0;
    FIELD_AT(self, int, 0x1C) = 0;
    FIELD_AT(self, int, 0x20) = 0;
    FIELD_AT(self, int, 0x24) = 0;
    FIELD_AT(self, int, 0x28) = 0;
    FIELD_AT(self, int, 0x2C) = 0;
    FIELD_AT(self, int, 0xC) = 0;
    FIELD_AT(self, int, 0x3C) = 0;
    return self;
}

EXTERN_C void func_800777E8(void *self, int b)
{
    void *p;
    FIELD_AT(self, void *, 0x8) = D_80016BD0;
    p = FIELD_AT(self, void *, 0xC);
    if (p != 0) {
        func_800A0D0C(p);
    }
    p = FIELD_AT(self, void *, 0x3C);
    if (p != 0) {
        operator delete(p);
    }
    func_80074E44(self, b);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80016708);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80016740);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80016758);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800167C8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800167E0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800167F8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80016808);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80016820);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80016830);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80016868);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80016878);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80077854);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80077A44);

EXTERN_C int func_80077BF8(void *self, unsigned char *p)
{
    int v = *p++;
    v += *p++ << 8;
    v += *p << 16;
    return v + (p[1] << 24);
}

EXTERN_C int func_80077C2C(void *self, unsigned char *p)
{
    return p[0] | (p[1] << 8);
}

EXTERN_C void func_80077C40(void *self, unsigned char *p, int n, unsigned v)
{
    int i;
    for (i = 0; i < n; i++) {
        *p++ = v;
        v >>= 8;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80077C68);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80077EA8);

EXTERN_C void func_80078520(void *self, void *p)
{
    void *old = FIELD_AT(self, void *, 0x3C);
    if (old != 0) {
        __builtin_delete(old);
    }
    FIELD_AT(self, void *, 0x3C) = p;
}

EXTERN_C void func_80078564(void *self)
{
    if (FIELD_AT(self, void *, 0x3C) != 0) {
        operator delete(FIELD_AT(self, void *, 0x3C));
        FIELD_AT(self, void *, 0x3C) = 0;
    }
}

EXTERN_C int func_800785A0(void)
{
    return 0;
}

EXTERN_C int func_800785A8(void *self)
{
    if (func_80077C68(self) < 0) {
        return -1;
    }
    return func_80077EA8(self);
}

EXTERN_C void *func_800785DC(void *self)
{
    func_80074F58(self);
    FIELD_AT(self, void *, 0xC) = D_80016BC0;
    return self;
}

EXTERN_C void func_80078610(void *self, int b)
{
    FIELD_AT(self, void *, 0xC) = D_80016BC0;
    func_800786A0(self);
    func_80074F78(self, b);
}

EXTERN_C void func_80078658(void *self)
{
    VObj<0x8> *p = (VObj<0x8> *)func_800752B8(self);
    if (p != 0) {
        p->v00(3);
    }
}

EXTERN_C void func_800786A0(void *self)
{
    FIELD_AT(self, int, 0x4) = FIELD_AT(self, int, 0x0);
    while (!empty_8007768C(self)) {
        func_80078658(self);
    }
}

EXTERN_C void func_800786EC(void)
{
}

EXTERN_C void func_800786F4(void)
{
}

EXTERN_C void func_800786FC(void *self)
{
    FIELD_AT(self, int, 0x1C) = 5;
}

EXTERN_C void func_80078708(void *self)
{
    FIELD_AT(self, int, 0x1C) = 4;
}

EXTERN_C void func_80078714(void *self)
{
    FIELD_AT(self, int, 0x1C) = 3;
}

EXTERN_C void func_80078720(void *self)
{
    FIELD_AT(self, int, 0x1C) = 2;
}

EXTERN_C int func_8007872C(void *self)
{
    return FIELD_AT(self, int, 0x1C) == 1;
}

EXTERN_C void func_80078740(void *self)
{
    FIELD_AT(self, int, 0x1C) = 1;
}

EXTERN_C void func_8007874C(void *self)
{
    FIELD_AT(self, int *, 0x14) = FIELD_AT(self, int *, 0x28) + FIELD_AT(self, int, 0x2C);
    FIELD_AT(self, int, 0x10) = FIELD_AT(self, int, 0x20);
}

EXTERN_C int func_8007876C(void *self, int i)
{
    return FIELD_AT(self, int *, 0x14)[i];
}

EXTERN_C int func_80078784(void *self)
{
    return *FIELD_AT(self, int *, 0x14)++;
}

EXTERN_C void func_8007879C(void *self, int value)
{
    *--FIELD_AT(self, int *, 0x14) = value;
}

EXTERN_C void *func_800787B4(void)
{
    return D_800AF470.p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_800787C4);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80078A30);

EXTERN_C int func_80078C38(void)
{
    return 0;
}

EXTERN_C void func_80078C40(void)
{
}

EXTERN_C void func_80078C48(void)
{
}

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80016BC0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80016BD0);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80078C50);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80078FD4);

EXTERN_C int func_8007908C(void *self, int b)
{
    void *p = FIELD_AT(self, void *, 0x32C);
    if (p != 0) {
        func_800CB174(p, b, 1);
    }
    return 1;
}

EXTERN_C int func_800790BC(void *self, void *b)
{
    void *p = FIELD_AT(self, void *, 0x32C);
    if (p != 0) {
        func_800CB8EC(p);
    }
    func_8001FC78(b, 0, 0);
    return 1;
}

EXTERN_C int func_80079104(D_80079104 *self, int b)
{
    int c = b;
    if (c != 0) {
        return self->v02(c);
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80079168);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_800792C8);

EXTERN_C void func_800797FC(void *self)
{
    func_8007A1F4(self, 0);
}

EXTERN_C void func_8007981C(void)
{
}

EXTERN_C void func_80079824(void *self)
{
    func_8007B538((Base1_80079824 *)FIELD_AT(self, Derived_80079824 *, 0x328), 1, 1, 0, 0, 0);
}

EXTERN_C void func_80079868(void *self)
{
    char *p;
    func_8007E5B0(FIELD_AT(self, void *, 0x328));
    p = FIELD_AT(self, char *, 0x328);
    func_8007B538(p ? p + 0xB8 : 0, 1, 1, 0, 0, 0);
}

EXTERN_C void func_800798C0(void)
{
    func_8007EDAC(D_800AF470.p, 0x10000, 1);
}

EXTERN_C void func_800798EC(void *self, int b)
{
    FIELD_AT(self, int, 0x338) = b;
    func_8007A1F4(self, 5);
}

EXTERN_C void func_80079910(void)
{
}

EXTERN_C void *D_800B4ED8[];
EXTERN_C void func_8007CC14(Derived_8007CC14 *self);
EXTERN_C void func_8007CCB4(void *self);
EXTERN_C int func_8006B540(void *self);
EXTERN_C void func_8007FC90(void *self, int k);
EXTERN_C void func_80079918(void *p)
{
    Arr_8007F434 *self = (Arr_8007F434 *)p;
    int i;
    if (!((bool (*)(void *))func_8006F630)(FIELD_AT(self, void *, 0x328))) {
        return;
    }
    if (FIELD_AT(D_800AF470.p, int, 0x540) != 0) {
        return;
    }
    if (func_8007E658(FIELD_AT(D_800AF470.p, Obj_8007E658 *, 0x328)) == 0) {
        return;
    }
    for (i = 15; i > 0; i--) {
        self->a[i] = self->a[i - 1];
    }
    self->a[0].w[0] = 4;
    self->a[0].w[1] = -1;
    self->a[0].w[2] = -1;
    self->a[0].w[3] = -1;
    if (func_800771D4(&D_800AF414)) {
        self->a[0].w[0] = 0x44444444;
        return;
    }
    func_8007F434(D_800AF470.p);
    func_80080828((char *)D_800AF470.p + 0x4F0);
    {
        char *dd = (char *)D_800B4DD0.p;
        FIELD_AT(D_800AF470.p, int, 0x568) = 0;
        FIELD_AT(dd, unsigned short, 0x1F6)++;
    }
    {
        char *b = FIELD_AT(self, char *, 0x328) ? FIELD_AT(self, char *, 0x328) + 0xB8 : 0;
        void *o = FIELD_AT(b, void *, 0x8);
        func_80043DC0(o);
        func_80072970(o);
        func_80074564(o);
    }
    func_8007E214(FIELD_AT(self, void *, 0x328));
    func_8007CC14(FIELD_AT(self, Derived_8007CC14 *, 0x328));
    {
        void *g = D_800AF470.p;
        FIELD_AT(self, int, 0x33C) = 0;
        FIELD_AT(self, int, 0x344) = 1;
        FIELD_AT(self, int, 0x348) = 0;
        func_8007FC90(g, -1);
    }
    func_8007CCB4(FIELD_AT(self, void *, 0x328));
    ((int (*)(void *, int))func_8006B540)(D_800B4ED8[0], 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80079ABC);

EXTERN_C void func_80079C18(void *self)
{
    func_8007A1F4(self, 1);
}

EXTERN_C void func_80079C38(void *self, int a1)
{
    int k;
    if (!((bool (*)(void *))func_8006F630)(FIELD_AT(self, void *, 0x328))) {
        return;
    }
    func_8007F434(D_800AF470.p);
    func_80080828((char *)D_800AF470.p + 0x4F0);
    FIELD_AT(self, int, 0x334) = a1 + 1;
    k = FIELD_AT(self, int, 0x370);
    FIELD_AT(self, int, 0x3AC) = 3;
    if (k == 1) {
        char *b = FIELD_AT(self, char *, 0x328) ? FIELD_AT(self, char *, 0x328) + 0xB8 : 0;
        void *o = FIELD_AT(b, void *, 0x8);
        func_80043DC0(o);
        func_80072970(o);
        func_80074564(o);
        if (FIELD_AT(self, int, 0x3A4) == 0) {
            Msg_8007EF90 *m = (Msg_8007EF90 *)func_8001CA10(0x14);
            m->vt = D_80010178;
            m->next = 0;
            m->vt = D_80010300;
            m->type = 2;
            m->sub = 2;
            m->d = 6;
            m->c = 0;
            m->vt = D_800102D0;
            func_8001EFE4(FIELD_AT(self, void *, 0x380), m);
            FIELD_AT(self, int, 0x3A8) = k;
            return;
        }
    }
    FIELD_AT(self, int, 0x3A4) = 0;
    func_8007A1F4(self, 3);
}

EXTERN_C void func_80079D64(void *self, int a1)
{
    int k;
    if (!((bool (*)(void *))func_8006F630)(FIELD_AT(self, void *, 0x328))) {
        return;
    }
    func_8007F434(D_800AF470.p);
    func_80080828((char *)D_800AF470.p + 0x4F0);
    FIELD_AT(self, int, 0x334) = a1;
    k = FIELD_AT(self, int, 0x370);
    FIELD_AT(self, int, 0x3AC) = 4;
    if (k == 1) {
        char *b = FIELD_AT(self, char *, 0x328) ? FIELD_AT(self, char *, 0x328) + 0xB8 : 0;
        void *o = FIELD_AT(b, void *, 0x8);
        func_80043DC0(o);
        func_80072970(o);
        func_80074564(o);
        if (FIELD_AT(self, int, 0x3A4) == 0) {
            Msg_8007EF90 *m = (Msg_8007EF90 *)func_8001CA10(0x14);
            m->vt = D_80010178;
            m->next = 0;
            m->vt = D_80010300;
            m->type = 2;
            m->sub = 2;
            m->d = 6;
            m->c = 0;
            m->vt = D_800102D0;
            func_8001EFE4(FIELD_AT(self, void *, 0x380), m);
            FIELD_AT(self, int, 0x3A8) = k;
            return;
        }
    }
    FIELD_AT(self, int, 0x3A4) = 0;
    func_8007A1F4(self, 4);
}

EXTERN_C void func_80079E8C(void *self)
{
    int m = D_800AF410.state;
    if (m == 4 || m == 1 || m == 2 || m == 5 || m == 6) {
        return;
    }
    if (FIELD_AT(D_800AF470.p, int, 0x540) != 0) {
        return;
    }
    if (func_800771D4(&D_800AF414)) {
        return;
    }
    if (FIELD_AT(self, signed char, 0x360) != 0) {
        return;
    }
    VObj<0x18> *p = FIELD_AT(self, VObj<0x18> *, 0x330);
    if (p != 0) {
        p->v01();
    }
}

EXTERN_C int func_80079F48(void *self)
{
    void *p = FIELD_AT(self, void *, 0x32C);
    if (p != 0) {
        return FIELD_AT(p, int, 0x1D0);
    }
    return 0;
}

EXTERN_C void *func_800DBFC4(void *p, int a, void *b, int c, int d);
EXTERN_C void *func_800D9EE0(void *p, int a, void *b, int c, int d);
EXTERN_C void func_800894AC(void *out, void *a, int b, int c);
EXTERN_C void func_800DA204(void *self, void *b);
EXTERN_C void *func_80062610(void *self);
EXTERN_C void func_800627E8(Entry_800627E8 *out, int i);
EXTERN_C void *func_80062834(void *self);
EXTERN_C int func_8006283C(void);
EXTERN_C void func_80062764(void *self, int flags);
EXTERN_C void func_8007CE64(void *self);
EXTERN_C int func_80079F6C(void *self, int k)
{
    if (FIELD_AT(self, int, 0x344) == 0) {
        return 0;
    }
    switch (k) {
    case 0: {
        VObj<0x18> *p = (VObj<0x18> *)func_800DBFC4(__builtin_new(0x8FC), 1, self, 0x4000, 4);
        FIELD_AT(self, VObj<0x18> *, 0x358) = p;
        p->v01();
        return 1;
    }
    case 1:
        if (FIELD_AT(self, int, 0x348) != 0) {
            char buf[0xA0];
            char tmp[0x98];
            int i;
            void *a;
            FIELD_AT(self, void *, 0x35C) = func_800D9EE0(__builtin_new(0x25D8), 1, self, 0x5000, FIELD_AT(self, int, 0x348));
            func_80062610(buf);
            for (i = 0; i < FIELD_AT(self, int, 0x348); i++) {
                func_800627E8((Entry_800627E8 *)buf, ((int *)((char *)self + 0x34C))[i]);
                a = func_80062834(buf);
                func_800894AC(tmp, a, 0, ((int (*)(void *))func_8006283C)(buf));
                func_800DA204(FIELD_AT(self, void *, 0x35C), tmp);
            }
            FIELD_AT(self, VObj<0x18> *, 0x35C)->v01();
            func_80062764(buf, 2);
            return 1;
        }
    case 2:
        FIELD_AT(self, int, 0x344) = 0;
        func_8007CE64(FIELD_AT(self, void *, 0x328));
        return 1;
    }
    return 0;
}

EXTERN_C void func_8007A13C(void *self)
{
    VObj<0x18> *p = FIELD_AT(self, VObj<0x18> *, 0x358);
    if (p != 0) {
        p->v00(3);
        FIELD_AT(self, void *, 0x358) = 0;
    }
    func_80079F6C(self, 1);
}

EXTERN_C void func_8007A198(void *self)
{
    VObj<0x18> *p = FIELD_AT(self, VObj<0x18> *, 0x35C);
    if (p != 0) {
        p->v00(3);
        FIELD_AT(self, void *, 0x35C) = 0;
    }
    func_80079F6C(self, 2);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007A1F4);

EXTERN_C void func_8007A3CC(void *self)
{
    FIELD_AT(self, int, 0x370) = -1;
    FIELD_AT(self, int, 0x39C)++;
    func_8007A1F4(self, FIELD_AT(self, int, 0x368));
}

EXTERN_C void func_8007A400(void *self, int b)
{
    FIELD_AT(self, int, 0x364) = 2;
    FIELD_AT(self, int, 0x36C) = b;
}

EXTERN_C void func_8007A410(void *self)
{
    func_8007A1F4(self, FIELD_AT(self, int, 0x3AC));
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007A434);

EXTERN_C void *func_8007A960(void *self)
{
    func_80074F58(self);
    FIELD_AT(self, void *, 0xC) = D_80017370;
    return self;
}

EXTERN_C void func_8007A994(void *self, int b)
{
    FIELD_AT(self, void *, 0xC) = D_80017370;
    func_8007AF04(self);
    func_80074F78(self, b);
}

EXTERN_C void *func_8007A9DC(List_8007AB78 *l, int x)
{
    Ent_8007AB78 *c;
    if (l->IsEmpty()) {
        return 0;
    }
    l->First();
    do {
        c = l->Cur();
        if (c->idC == x) {
            return c;
        }
        if (l->IsLast()) {
            break;
        }
        l->Next();
    } while (1);
    return 0;
}

EXTERN_C void *func_8007AA9C(List_8007AB78 *l, int x)
{
    Ent_8007AB78 *c;
    if (l->IsEmpty()) {
        return 0;
    }
    if (l->IsLast()) {
        return 0;
    }
    l->Next();
    do {
        c = l->Cur();
        if (c->idC == x) {
            return c;
        }
        if (l->IsLast()) {
            break;
        }
        l->Next();
    } while (1);
    return 0;
}

EXTERN_C void *func_8007AB78(List_8007AB78 *l, int x)
{
    Ent_8007AB78 *c;
    if (l->IsEmpty()) {
        return 0;
    }
    l->First();
    do {
        c = l->Cur();
        if (c->id10 == x) {
            return c;
        }
        if (l->IsLast()) {
            break;
        }
        l->Next();
    } while (1);
    return 0;
}

EXTERN_C void *func_8007AC38(List_8007AB78 *l, int x)
{
    Ent_8007AB78 *c;
    if (l->IsEmpty()) {
        return 0;
    }
    if (l->IsLast()) {
        return 0;
    }
    l->Next();
    do {
        c = l->Cur();
        if (c->id10 == x) {
            return c;
        }
        if (l->IsLast()) {
            break;
        }
        l->Next();
    } while (1);
    return 0;
}

EXTERN_C void func_8007AD14(void *self, int a1, int a2, int a3, int a4, int a5, int a6)
{
    char *p = (char *)__builtin_new(0x24);
    func_80074E28(p);
    FIELD_AT(p, void *, 0x8) = D_80017380;
    FIELD_AT(p, int, 0xC) = a1;
    FIELD_AT(p, int, 0x10) = a2;
    FIELD_AT(p, int, 0x14) = a3;
    FIELD_AT(p, int, 0x18) = a4;
    FIELD_AT(p, int, 0x1C) = a5;
    FIELD_AT(p, int, 0x20) = a6;
    if (p != 0) {
        func_80075004((List_80075004 *)self, (Node_80074E78 *)p);
    }
}

EXTERN_C int func_8007ADCC(void *self, int b)
{
    VObj<8> *p = (VObj<8> *)func_8007A9DC((List_8007AB78 *)self, b);
    if (p == 0) {
        return 0;
    }
    func_80075448(self, p);
    p->v00(3);
    return 1;
}

EXTERN_C int func_8007AE34(List_8007AB78 *self, int a1, int a2, int a3, int a4)
{
    char *p = (char *)func_8007AB78(self, a1);
    while (p != 0) {
        if ((FIELD_AT(p, int, 0x14) == -1 || FIELD_AT(p, int, 0x14) == a2) &&
            (FIELD_AT(p, int, 0x18) == -1 || FIELD_AT(p, int, 0x18) == a3)) {
            if (FIELD_AT(p, int, 0x1C) & a4) {
                return FIELD_AT(p, int, 0x20);
            }
            return -1;
        }
        p = (char *)func_8007AC38(self, a1);
    }
    return 0;
}

EXTERN_C void func_8007AF04(void *self)
{
    VObj<8> *p;
    while ((p = (VObj<8> *)func_800751AC(self)) != 0) {
        p->v00(3);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007AF5C);

EXTERN_C void func_8007AFD0(Set_8007AFD0 *self, int item)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (self->items[i] == 0) {
            self->items[i] = item;
            self->count++;
            return;
        }
    }
}

EXTERN_C int func_8007B014(Set_8007B014 *self, int item)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (self->items[i] == item) {
            self->items[i] = 0;
            self->count--;
            return item;
        }
    }
    return 0;
}

EXTERN_C void *func_8007B058(Obj_8007B058 *self, int i)
{
    void *p = self->items[i];
    if (p != 0) {
        self->items[i] = 0;
        self->count--;
    }
    return p;
}

EXTERN_C void func_8007B08C(void *self)
{
    void *p = FIELD_AT(self, void *, 0x8);
    if (p != 0) {
        func_800BFABC(FIELD_AT(D_800AF470.p, void *, 0x380), p);
    }
}

EXTERN_C void func_8007B0C8(void *self)
{
    char *h = FIELD_AT(D_800AF470.p, char *, 0x380) + 0x610;
    func_80019D40(h ? FIELD_AT(h, List *, 0x0) : 0);
}

EXTERN_C void *D_800B4ED8[];
EXTERN_C void func_8007B108(void *self, int flag)
{
    char *o = FIELD_AT(self, char *, 0x8);
    if (o == 0) {
        return;
    }
    if (flag) {
        if (FIELD_AT(o, int, 0x1B8) == 0) {
            return;
        }
        func_80039BEC(D_800B4ED8[0] ? (char *)D_800B4ED8[0] + 0x50 : 0, FIELD_AT(o, int, 0x1B8));
        if (FIELD_AT(o, int, 0x1B4) == 0) {
            return;
        }
        func_80039BEC(D_800B4ED8[0] ? (char *)D_800B4ED8[0] + 0x50 : 0, FIELD_AT(o, int, 0x1B4));
    } else {
        if (FIELD_AT(o, int, 0x1B8) == 0) {
            return;
        }
        func_80039C88(D_800B4ED8[0] ? (char *)D_800B4ED8[0] + 0x50 : 0, FIELD_AT(o, int, 0x1B8));
        if (FIELD_AT(o, int, 0x1B4) == 0) {
            return;
        }
        func_80039C88(D_800B4ED8[0] ? (char *)D_800B4ED8[0] + 0x50 : 0, FIELD_AT(o, int, 0x1B4));
    }
}

EXTERN_C int func_8007B1FC(void *self, int v, int kind)
{
    int i;
    switch (kind) {
    case 1:
        for (i = 0; i < 3; i++) {
            if (D_800AFA64[i] == 0) {
                D_800AFA64[i] = v;
                FIELD_AT(self, int, 0x14) += 1;
                return 1;
            }
        }
        return 0;
    case 2:
        for (i = 0; i < 3; i++) {
            if (D_800AFA58[i] == 0) {
                D_800AFA58[i] = v;
                FIELD_AT(self, int, 0x18) += 1;
                return 2;
            }
        }
        break;
    }
    return 0;
}

EXTERN_C void func_8007B2B0(void *self)
{
    FIELD_AT(self, int, 0x14) = 0;
    D_800AFA64[0] = 0;
    D_800AFA64[1] = 0;
    D_800AFA64[2] = 0;
    FIELD_AT(self, int, 0x18) = 0;
    D_800AFA58[0] = 0;
    D_800AFA58[1] = 0;
    D_800AFA58[2] = 0;
}

EXTERN_C int func_8007B2E4(void *self, int x)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (D_800AFA58[i] == x) {
            D_800AFA58[i] = 0;
            FIELD_AT(self, int, 0x18)--;
            return x;
        }
    }
    for (i = 0; i < 3; i++) {
        if (D_800AFA64[i] == x) {
            D_800AFA64[i] = 0;
            FIELD_AT(self, int, 0x14)--;
            return x;
        }
    }
    return 0;
}

EXTERN_C int func_8007B36C(void *self, int kind, int idx)
{
    int old;
    switch (kind) {
    case 1:
        old = D_800AFA64[idx];
        if (old != 0) {
            D_800AFA64[idx] = 0;
            FIELD_AT(self, int, 0x14) -= 1;
            return old;
        }
        break;
    case 2:
        old = D_800AFA58[idx];
        if (old != 0) {
            D_800AFA58[idx] = 0;
            FIELD_AT(self, int, 0x18) -= 1;
            return old;
        }
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007B404);

EXTERN_C void func_8007B538(void *self, int mask, int a2, int a3, int a4, int a5)
{
    int i;
    FIELD_AT(self, int, 0x34) = mask;
    FIELD_AT(self, int, 0x3C) = a2;
    FIELD_AT(self, int, 0x44) = a3;
    FIELD_AT(self, int, 0x38) = 0;
    FIELD_AT(self, int, 0x48) = a4;
    FIELD_AT(self, int, 0x4C) = a5;
    for (i = 0; i < 3; i++) {
        if ((mask >> i) & 1) {
            FIELD_AT(self, int, 0x38)++;
        }
    }
    if (mask & 1) {
        func_8007BDB4(self, 2, 0x13EDA, 0x10000);
    } else if (mask & 2) {
        func_8007BDB4(self, 3, 0x13EBB, 0xF800);
    } else if (mask & 4) {
        func_8007BDB4(self, 4, 0x13E9D, 0xF000);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007B5F8);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007B738);

EXTERN_C void func_8007BB48(void *p, int b, int c)
{
    Arr_8007BB48 *self = (Arr_8007BB48 *)p;
    int i;
    for (i = 0; i < 3; i++) {
        if (b & 1) {
            ((VObj<0x15C> *)(self->o[i] + 0x2A0))->v07(0, 0);
            ((VObj<0x15C> *)(self->o[i] + 0x2A0))->v21(c ? -1 : 0);
            func_8003DEA8(self->o[i]);
            ((VObj<0x15C> *)(self->o[i] + 0x2A0))->v01(-1, 0);
        }
        b >>= 1;
    }
}

EXTERN_C void func_8007BC3C(void *self, int mask)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (mask & 1) {
            ((VObj<0x15C> *)((char *)D_800AFA58[i] + 0x2A0))->v07(0, 0);
            func_8003DEA8((void *)D_800AFA58[i]);
            ((VObj<0x15C> *)((char *)D_800AFA58[i] + 0x2A0))->v01(-1, 0);
        }
        mask >>= 1;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007BCF0);

EXTERN_C void func_8007BDAC(void)
{
}

EXTERN_C void func_8007BDB4(void *self_, int a, int b, int c)
{
    char *self = (char *)self_;
    FIELD_AT(self, int, 0x30) = a;
    void *n = __builtin_new(0x1C8);
    void *p = func_800758F8(n, 1, D_800A4578.p ? (char *)D_800A4578.p + 0x50 : 0, self);
    void *d = D_800B4C18.p;
    FIELD_AT(self, void *, 0x40) = p;
    func_8001E848(d, p);
    func_8007669C(FIELD_AT(self, void *, 0x40), b, c);
}

EXTERN_C void func_8007BE44(void *self)
{
    void *o = operator new(0x1C8);
    char *h = (char *)D_800A4578.p;
    void *r = func_800758F8(o, 1, h ? h + 0x50 : 0, self);
    void *g = D_800B4C18.p;
    FIELD_AT(self, void *, 0x40) = r;
    func_8001E848(g, r);
}

EXTERN_C void func_8007BEA8(void *self, int b, int c, int d, int e)
{
    if (FIELD_AT(self, void *, 0x40) != 0) {
        func_800766F8(FIELD_AT(self, void *, 0x40), b, c, d, e);
    }
}

EXTERN_C void func_8007BEE8(void *self, int b, int c, int d)
{
    void *p = FIELD_AT(self, void *, 0x40);
    if (p != 0) {
        func_80076848(p, b, c, d);
    }
}

EXTERN_C void func_8007BF18(void *self, int b, int c)
{
    void *p = FIELD_AT(self, void *, 0x40);
    if (p != 0) {
        func_8007698C(p, b, c, 0);
    }
}

EXTERN_C void func_8007BF48(void *self, int b, int c, int d)
{
    if (FIELD_AT(self, void *, 0x40) != 0) {
        FIELD_AT(self, int, 0x30) = b;
        func_8007669C(FIELD_AT(self, void *, 0x40), c, d);
    }
}

EXTERN_C void func_8007BF84(void *self)
{
    func_800766D8(FIELD_AT(self, void *, 0x40));
}

EXTERN_C void func_8007BFA8(Obj_8007BFA8 *self, int b, int c, int d)
{
    void *it = self->items[d];
    if (FIELD_AT(it, int, 0x1B8) == 0) {
        func_80042430(it, it, b, 1);
    } else {
        func_8007C070(self, d);
    }
}

EXTERN_C void func_8007C008(void *self, int b)
{
    void *it = (void *)D_800AFA58[b];
    if (FIELD_AT(it, int, 0x1B8) == 0) {
        func_800CF080(FIELD_AT(D_800AF470.p, void *, 0x32C), it, b);
    } else {
        func_8007C070(self, b + 3);
    }
}

EXTERN_C void func_8007C070(void *self, int b)
{
    if (b < 3) {
        func_8007C0A8(self, b);
    } else {
        func_8007C3C8(self, b - 3);
    }
}

EXTERN_C int func_8007B1FC(void *self, int x, int kind);
EXTERN_C void func_80085C00(void *self);
EXTERN_C void func_80085E14(void *self);
EXTERN_C void func_8007BF84(void *self);
EXTERN_C void func_8008478C(void *self);

EXTERN_C int func_8007C0A8(void *self, int i)
{
    int k = FIELD_AT(self, int, 0x3C);
    switch (k) {
    case 1:
        func_80084824(((Arr_8007BB48 *)self)->o[i], 1);
        func_8008478C(((Arr_8007BB48 *)self)->o[i]);
        break;
    case 2: {
        char *o;
        char *o2;
        char *o3;
        char *s;
        int n;
        if (D_800AFA64[i] == 0) {
            func_8007B1FC(self, (int)((Arr_8007BB48 *)self)->o[i], 1);
        }
        o = ((Arr_8007BB48 *)self)->o[i];
        s = o + 0x2A4;
        n = FIELD_AT(FIELD_AT(o, char *, 0x550), unsigned char, 0x8A) - 1;
        FIELD_AT(o, char, 0x4BD) = 1;
        ((void (*)(void *, int))func_800824C8)(s, 1);
        func_800825FC((short *)s, n);
        func_80085C00(((Arr_8007BB48 *)self)->o[i]);
        func_80085E14(((Arr_8007BB48 *)self)->o[i]);
        func_80084824(((Arr_8007BB48 *)self)->o[i], 2);
        o2 = ((Arr_8007BB48 *)self)->o[i];
        if (FIELD_AT(o2, short, 0x52A) != k) {
            func_8008299C(o2 + 0x2A0, 0x1F, (FIELD_AT(o2, unsigned char, 0x54A) - 2) * 2400, 0, (3 - FIELD_AT(o2, unsigned char, 0x54B)) * 2400, 0x800, 0);
            func_8008299C(((Arr_8007BB48 *)self)->o[i] + 0x2A0, 0x1C, 1, 1, 0, 0, 0);
        } else {
            func_8008299C(o2 + 0x2A0, 0x1C, 1, 0, 0, 0, 0);
        }
        o3 = ((Arr_8007BB48 *)self)->o[i];
        if ((FIELD_AT(o3, int, 0x4AC) & 0xFFFF00) == 0) {
            func_8008299C(o3 + 0x2A0, 0, 2, 0, 0, 0, 0);
        }
        func_80082E14(((Arr_8007BB48 *)self)->o[i] + 0x2A0, 0);
        break;
    }
    }
    func_8007BF84(self);
    switch (i) {
    case 0: {
        int m;
        FIELD_AT(self, char, 0x1C) = 1;
        m = FIELD_AT(self, int, 0x34);
        if (m & 2) {
            func_8007BDB4(self, 3, 0x13EBB, 0xF800);
        } else if (m & 4) {
            func_8007BDB4(self, 4, 0x13E9D, 0xF000);
        }
        break;
    }
    case 1:
        FIELD_AT(self, char, 0x1D) = 1;
        if (FIELD_AT(self, int, 0x34) & 4) {
            func_8007BDB4(self, 4, 0x13E9D, 0xF000);
        }
        break;
    case 2:
        FIELD_AT(self, char, 0x1E) = 1;
        break;
    }
    if (--FIELD_AT(self, int, 0x38) <= 0) {
        switch (FIELD_AT(self, int, 0x3C)) {
        case 1:
            break;
        case 2:
            return ((VObj0 *)self)->v02();
        }
    }
}

struct St_8007C3C8 {
    char pad[0x1F];
    signed char st[3];
};
EXTERN_C int func_8007C3C8(void *p, int i)
{
    int j;
    signed char c;
    c = ((St_8007C3C8 *)p)->st[i];
    if (c == 0 || c == 2) {
    if (c == 0) {
        char *o = (char *)D_800AFA58[i];
        FIELD_AT(o, char, 0x4BD) = 2;
        ((void (*)(void *, int))func_800824C8)(o + 0x2A4, 2);
        func_800825FC((short *)(o + 0x2A4), 0);
    }
    {
        char *o;
        ((St_8007C3C8 *)p)->st[i] = 1;
        func_80085C00((void *)D_800AFA58[i]);
        func_80085E14((void *)D_800AFA58[i]);
        func_80084824((void *)D_800AFA58[i], 2);
        o = (char *)D_800AFA58[i];
        if (FIELD_AT(o, short, 0x52A) != 2) {
            func_8008299C(o + 0x2A0, 0x1C, 1, 1, 0, 0, 0);
        } else {
            func_8008299C(o + 0x2A0, 0x1C, 1, 0, 0, 0, 0);
        }
        func_80082E14((char *)D_800AFA58[i] + 0x2A0, 0);
    }
    }
    for (j = 0; j < 3; j++) {
        c = ((St_8007C3C8 *)p)->st[j];
        if (c == 0 || c == 2) {
            return 1;
        }
    }
    func_8007BF84(p);
    ((VObj0 *)p)->v03();
    return 0;
}

EXTERN_C void *func_8007C55C(void *self, int a1)
{
    char *r;
    func_8006F04C(self);
    func_8007A960((char *)self + 0xA8);
    func_8007AF5C((char *)self + 0xB8);
    r = (char *)self;
    FIELD_AT(r, void *, 0xB4) = D_800172E8;
    FIELD_AT(r, void *, 0xB8) = D_800172B0;
    FIELD_AT(r, void *, 0xA4) = D_800172F8;
    {
        Q4_8007C55C *q = (Q4_8007C55C *)(r + 0x130);
        q->a = 0; q->b = 0; q->c = 0; q->d = 0;
    }
    {
        Q4_8007C55C *q = (Q4_8007C55C *)(r + 0x154);
        q->a = 0; q->b = 0; q->c = 0; q->d = 0;
    }
    {
        Q4_8007C55C *q = (Q4_8007C55C *)(r + 0x180);
        q->a = 0; q->b = 0; q->c = 0; q->d = 0;
    }
    FIELD_AT(r, int, 0x14C) = -1;
    FIELD_AT(r, int, 0x10C) = a1;
    FIELD_AT(r, int, 0x11C) = 0;
    FIELD_AT(r, int, 0x170) = -2;
    FIELD_AT(r, int, 0x1AC) = 0;
    FIELD_AT(r, int, 0x198) = 0x12E47;
    FIELD_AT(r, int, 0x19C) = 0x19000;
    FIELD_AT(r, int, 0x114) = 0;
    FIELD_AT(r, int, 0x110) = 0;
    FIELD_AT(r, int, 0x240) = 0;
    return r;
}

EXTERN_C void func_8007C640(void *self, int flags)
{
    FIELD_AT(self, void *, 0xB4) = D_800172E8;
    FIELD_AT(self, void *, 0xB8) = D_800172B0;
    FIELD_AT(self, void *, 0xA4) = D_800172F8;
    func_8007A994((char *)self + 0xA8, 0);
    func_8006F0B0(self, flags);
}

EXTERN_C void func_8007C6A8(void *self, void *m)
{
    if (FIELD_AT(m, unsigned short, 0xA) == 2) {
        switch (FIELD_AT(m, int, 0x10) & 0xFFF) {
        case 0:
            func_8006F2A8(self);
            break;
        case 1:
            func_8006F2E8(self);
            break;
        case 2:
            func_8006F31C(self);
            break;
        case 3:
            func_8006F35C(self);
            break;
        case 4:
            func_800DDFB0_c(self, 0, FIELD_AT(self, int, 0x168), FIELD_AT(self, int, 0x16C), FIELD_AT(self, int, 0x170), FIELD_AT(self, int, 0x174), FIELD_AT(self, int, 0x178), FIELD_AT(self, int, 0x17C), FIELD_AT(self, B16_B, 0x180), FIELD_AT(self, int, 0x190));
            break;
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007C7B0);

EXTERN_C void func_8007C9A4(void *self)
{
    func_8007DEE8(self, 3);
}

EXTERN_C void func_8007C9C4(void *self)
{
    func_8007DEE8(self, 2);
}

EXTERN_C void func_8007C9E4(void *self, int b, int c)
{
    func_8007A400(D_800AF470.p, 0);
    func_800518A8(D_800B4D40.p, FIELD_AT(self, int, 0x10C), b, c);
}

EXTERN_C void func_8007CA44(void *self)
{
    char *p = self ? (char *)self + 0xB8 : 0;
    if (FIELD_AT(p, int, 0x2C) == 0) {
        func_800CEE18(FIELD_AT(D_800AF470.p, void *, 0x32C));
    } else {
        func_800CEFE8(FIELD_AT(D_800AF470.p, void *, 0x32C));
    }
}

EXTERN_C int func_8007CAA8(void *self, int b)
{
    int old = FIELD_AT(self, int, 0x11C);
    FIELD_AT(self, int, 0x11C) = b;
    return old;
}

EXTERN_C void func_8007CAB4(void *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, B16_B s, int a12)
{
    func_8007CAA8(self, 1);
    if (a2 <= 0) {
        a2 = -1;
    }
    FIELD_AT(self, int, 0x168) = a2;
    FIELD_AT(self, int, 0x16C) = a3;
    FIELD_AT(self, int, 0x170) = a4;
    FIELD_AT(self, int, 0x174) = a5;
    FIELD_AT(self, int, 0x178) = a6;
    FIELD_AT(self, int, 0x17C) = a7;
    FIELD_AT(self, B16_B, 0x180) = s;
    FIELD_AT(self, int, 0x190) = a12;
}

EXTERN_C void func_8007CB64(void *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, B16_B s, int a12)
{
    func_8007CAA8(self, 1);
    if (a2 <= 0) {
        a2 = -1;
    }
    FIELD_AT(self, int, 0x168) = a2;
    FIELD_AT(self, int, 0x16C) = a3;
    FIELD_AT(self, int, 0x170) = a4;
    FIELD_AT(self, int, 0x174) = a5;
    FIELD_AT(self, int, 0x178) = a6;
    FIELD_AT(self, int, 0x17C) = a7;
    FIELD_AT(self, B16_B, 0x180) = s;
    FIELD_AT(self, int, 0x190) = a12;
}

EXTERN_C void func_8007CC14(Derived_8007CC14 *self)
{
    func_8007B0C8((Base1_8007CC14 *)self);
    func_8007BB48((Base1_8007CC14 *)self, 1, 1);
}

EXTERN_C void func_8007CC60(void *self, int b, int c, int d)
{
    func_8007CAA8(self, 2);
    if (c <= 0) {
        c = -1;
    }
    FIELD_AT(self, int, 0x168) = c;
    FIELD_AT(self, int, 0x16C) = d;
}

EXTERN_C void func_8007CCB4(void *self)
{
    func_8007CC60(self, 0, FIELD_AT(self, int, 0x198), FIELD_AT(self, int, 0x19C));
}

EXTERN_C void func_8007CCDC(void *self, int a1)
{
    VObj0 *o;
    char *g;
    char *b;
    if (FIELD_AT(self, void *, 0x110) != 0) {
        func_800D6740(FIELD_AT(self, void *, 0x110), 3);
    }
    o = FIELD_AT(self, VObj0 *, 0x114);
    if (o != 0) {
        o->v02(3);
    }
    FIELD_AT(self, void *, 0x110) = 0;
    FIELD_AT(self, void *, 0x114) = 0;
    b = self ? (char *)self + 0xB8 : 0;
    func_80084824(FIELD_AT(b, void *, 0xC), 0);
    b = self ? (char *)self + 0xB8 : 0;
    func_80084824(FIELD_AT(b, void *, 0x10), 0);
    b = FIELD_AT(D_800AF470.p, char *, 0x328);
    func_8007B2B0(b ? b + 0xB8 : 0);
    g = (char *)D_800AF470.p;
    o = FIELD_AT(g, VObj0 *, 0x32C);
    if (o != 0) {
        o->v02(3);
        FIELD_AT(g, void *, 0x32C) = 0;
    }
    func_80094908();
    if (FIELD_AT(D_800AF470.p, int, 0x33C) != 0) {
        func_8007EDAC(D_800AF470.p, a1, 0x26);
    } else if (a1 == 0) {
        func_800798EC(D_800AF470.p, 0);
    } else {
        func_8007E30C(self);
        func_8007B538(self ? (char *)self + 0xB8 : 0, 1, 1, 0, 0, 0);
    }
}

EXTERN_C void func_8007CE64(void *self)
{
    char *b = self ? (char *)self + 0xB8 : 0;
    func_8006F0E4(self, FIELD_AT(b, int, 0x8));
    switch (FIELD_AT(self, int, 0x11C)) {
    case 3:
        break;
    case 1:
        func_8006F0F4(self, 5, 7, 3, 4);
        FIELD_AT(self, int, 0x1A4) = 2;
        if (FIELD_AT(self, int, 0x170) != FIELD_AT(self, int, 0x14C)) {
            func_8006F67C(self, 0, FIELD_AT(self, int, 0x168), FIELD_AT(self, int, 0x16C), FIELD_AT(self, int, 0x170), FIELD_AT(self, int, 0x174),
                          FIELD_AT(self, int, 0x178), FIELD_AT(self, int, 0x17C), FIELD_AT(self, V4_80085578, 0x180), FIELD_AT(self, int, 0x190));
        } else {
            func_8006F8B4(self, 0, FIELD_AT(self, int, 0x168), FIELD_AT(self, int, 0x16C), FIELD_AT(self, int, 0x174), FIELD_AT(self, int, 0x178),
                          FIELD_AT(self, int, 0x17C), FIELD_AT(self, V4_80085578, 0x180), FIELD_AT(self, int, 0x190));
        }
        func_8007B08C(self ? (char *)self + 0xB8 : 0);
        break;
    case 2: {
        char *c;
        func_8006F0F4(self, 0xB, 0, 9, 0xA);
        func_8006FCC0(self, 0, FIELD_AT(self, int, 0x168), FIELD_AT(self, int, 0x16C));
        c = self ? (char *)self + 0xB8 : 0;
        func_80084B78(FIELD_AT(c, void *, 0x8), 1);
        break;
    }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007D024);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007D24C);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007D498);

EXTERN_C void func_8007D6D0(void *self)
{
    func_8006FAC0(self, (char *)self + 0x168, (char *)self + 0x16C, (char *)self + 0x170, (char *)self + 0x174,
                  (char *)self + 0x178, (char *)self + 0x17C, FIELD_AT(self, Blk_8007D6D0, 0x154), FIELD_AT(self, int, 0x164));
    FIELD_AT(self, int, 0x1AC) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007D744);

EXTERN_C void func_8007D824(void *self, int a1, int a2, int a3)
{
    char *b = self ? (char *)self + 0xB8 : 0;
    char *o = FIELD_AT(b, char *, 0x8);
    short *v;
    short d;
    {
        V4_80085578 t = FIELD_AT(FIELD_AT(o, char *, 0x1B8), V4_80085578, 0x34);
        FIELD_AT(self, V4_80085578, 0x154) = t;
    }
    v = (short *)(FIELD_AT(o, char *, 0x1B8) + 0x2C);
    d = SquareRoot0(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    FIELD_AT(self, int, 0x164) = ((d + 0x100) / 512) & 7;
    func_8006F67C(self, a1, a2, a3, -1, -1, 0, 0, V4_80085578(0, 0, 0, 0), 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007D994);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007DB04);

EXTERN_C void func_8007DC00(void *self, int k)
{
    func_8007F434(D_800AF470.p);
    switch (k) {
    case 6:
        break;
    case 0:
    case 5: {
        B8_B t10;
        B8_B t18;
        void *o;
        func_800BCBE8(FIELD_AT(D_800AF470.p, void *, 0x380), (int *)&t10);
        o = func_8006FEEC(__builtin_new(0x6C));
        FIELD_AT(self, void *, 0x1B4) = o;
        func_80077854(o, *(int *)&t10, 0x100);
        func_800BCC00(FIELD_AT(D_800AF470.p, void *, 0x380), (int *)&t18);
        func_80025CE0((char *)self + 0x1B8, *(int *)&t18, 0x78);
        func_8007FF58((char *)D_800AF470.p + 0x498, 0x3C0, 0x20, FIELD_AT(self, int, 0x1B8));
        func_8007FF58((char *)D_800AF470.p + 0x498, 0x3E0, 0x20, FIELD_AT(self, int, 0x1BC));
        if (k == 0) {
            func_800BCC30(FIELD_AT(D_800AF470.p, void *, 0x380), (char *)self + 0x230);
            func_800BCC18(FIELD_AT(D_800AF470.p, void *, 0x380), (char *)self + 0x238);
            if (FIELD_AT(self, int, 0x230) != 0 && FIELD_AT(self, int, 0x238) != 0) {
                if (FIELD_AT(D_800AF470.p, int, 0x548) != 0) {
                    void *s1 = func_800A0D2C(FIELD_AT(self, int, 0x234));
                    void *s0 = func_800A0D2C(FIELD_AT(self, int, 0x23C));
                    func_80025CE0(s1, FIELD_AT(self, int, 0x230), FIELD_AT(self, int, 0x234));
                    func_80025CE0(s0, FIELD_AT(self, int, 0x238), FIELD_AT(self, int, 0x23C));
                    func_80080990((char *)D_800AF470.p + 0x4F0, (int)s1, (int)s0, FIELD_AT(D_800AF470.p, int, 0x548));
                } else {
                    func_80080828((char *)D_800AF470.p + 0x4F0);
                }
            }
        }
        func_8007FC90(D_800AF470.p, -1);
        break;
    }
    }
}

EXTERN_C void func_8007DDCC(char *p)
{
    char *q = 0;
    if (p != 0) {
        q = p + 0xB8;
    }
    func_80084B78(FIELD_AT(q, void *, 0x8), 1);
}

EXTERN_C void func_8007DDFC(void *self, int b)
{
    func_8007FE1C(D_800AF470.p, 0);
    switch (FIELD_AT(self, int, 0x11C)) {
    case 1:
        func_800DE97C(self, b);
        break;
    case 2:
        func_8007DE74(self, b);
        break;
    case 3:
        break;
    }
}

EXTERN_C void func_8007DE74(void *self, int b)
{
    Derived_8007DE74 *d = (Derived_8007DE74 *)self;
    func_80084674(((Base1_8007DE74 *)d)->unk8);
    func_80084674(((Base1_8007DE74 *)d)->unkC);
    func_80084674(((Base1_8007DE74 *)d)->unk10);
    func_8007DEE8(self, 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007DEE8);

EXTERN_C void func_8007E214(void *self)
{
    char *t;
    char *o;
    short *v;
    short d;
    FIELD_AT(self, int, 0x120) = FIELD_AT(self, int, 0x14C);
    FIELD_AT(self, int, 0x124) = FIELD_AT(self, int, 0x150);
    FIELD_AT(self, int, 0x128) = FIELD_AT(self, int, 0x168);
    FIELD_AT(self, int, 0x12C) = FIELD_AT(self, int, 0x16C);
    FIELD_AT(self, int, 0x144) = FIELD_AT(self, int, 0x178);
    FIELD_AT(self, int, 0x148) = FIELD_AT(self, int, 0x17C);
    t = self ? (char *)self + 0xB8 : 0;
    o = FIELD_AT(t, char *, 0x8);
    FIELD_AT(self, B16_B, 0x130) = FIELD_AT(FIELD_AT(o, char *, 0x1B8), B16_B, 0x34);
    v = (short *)(FIELD_AT(o, char *, 0x1B8) + 0x2C);
    d = SquareRoot0(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    FIELD_AT(self, int, 0x140) = ((d + 0x100) / 512) & 7;
}

EXTERN_C void func_8007E30C(void *self)
{
    if (FIELD_AT(self, int, 0x11C) == 1) {
        func_8007D24C(self, 0, FIELD_AT(self, int, 0x128), FIELD_AT(self, int, 0x12C), FIELD_AT(self, int, 0x120), FIELD_AT(self, int, 0x124),
                      FIELD_AT(self, int, 0x144), FIELD_AT(self, int, 0x148), FIELD_AT(self, B16_B, 0x130), FIELD_AT(self, int, 0x140));
    } else {
        func_8007CAB4(self, 0, FIELD_AT(self, int, 0x128), FIELD_AT(self, int, 0x12C), FIELD_AT(self, int, 0x120), FIELD_AT(self, int, 0x124),
                      FIELD_AT(self, int, 0x144), FIELD_AT(self, int, 0x148), FIELD_AT(self, B16_B, 0x130), FIELD_AT(self, int, 0x140));
    }
}

EXTERN_C void func_8007E414(void *self)
{
    void *g = D_800AF470.p;
    FIELD_AT(g, int, 0x3A4) = 0;
    switch (FIELD_AT(self, int, 0x11C)) {
    case 1:
        func_8007EDAC(g, 0, 0xF);
        break;
    case 2:
        func_8007DEE8(self, 0xA);
        break;
    case 3:
        break;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007E47C);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007E5B0);

EXTERN_C int func_8007E658(Obj_8007E658 *self)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (self->slots[i].p == 0) {
            break;
        }
    }
    return i;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007E684);

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007E8C0);

EXTERN_C int func_8007EAC8(void *p, int a1, int a2, int a3, int a4)
{
    int r;
    int i;
    if (a1 == 0xFF || a1 == 0x40 || a1 == 0x50 || a1 == 0x92 || a1 == 0x9A) {
        return 0;
    }
    if (FIELD_AT(p, int, 0x344) != 0) {
        for (i = 15; i > 0; i--) {
            ((Arr_8007F434 *)p)->a[i] = ((Arr_8007F434 *)p)->a[i - 1];
        }
        ((Arr_8007F434 *)p)->a[0].w[0] = 6;
        ((Arr_8007F434 *)p)->a[0].w[1] = a1;
        ((Arr_8007F434 *)p)->a[0].w[2] = a2;
        ((Arr_8007F434 *)p)->a[0].w[3] = 1;
        func_8007F434(p);
        return 0;
    }
    if (func_800771D4(&D_800AF414)) {
        for (i = 15; i > 0; i--) {
            ((Arr_8007F434 *)p)->a[i] = ((Arr_8007F434 *)p)->a[i - 1];
        }
        ((Arr_8007F434 *)p)->a[0].w[0] = 1;
        ((Arr_8007F434 *)p)->a[0].w[1] = a1;
        ((Arr_8007F434 *)p)->a[0].w[2] = a2;
        ((Arr_8007F434 *)p)->a[0].w[3] = 1;
        if (a2 == 7) {
            ((Arr_8007F434 *)p)->a[0].w[0] = 0x11;
            return 0;
        }
        func_8007F0A8(p, a1, a2, a4, 1);
        return 0;
    }
    if (FIELD_AT(p, int, 0x434) != 0) {
        func_8007F0A8(p, a1, a2, a4, 1);
        func_8007F138(p);
        return 0;
    }
    r = func_8007D024(FIELD_AT(p, void *, 0x328), a1, a2, a4);
    for (i = 15; i > 0; i--) {
        ((Arr_8007F434 *)p)->a[i] = ((Arr_8007F434 *)p)->a[i - 1];
    }
    ((Arr_8007F434 *)p)->a[0].w[0] = 1;
    ((Arr_8007F434 *)p)->a[0].w[1] = a1;
    ((Arr_8007F434 *)p)->a[0].w[2] = a2;
    ((Arr_8007F434 *)p)->a[0].w[3] = -1;
    if (r < 0) {
        ((Arr_8007F434 *)p)->a[0].w[0] |= 0x80000000;
        return 0;
    }
    func_800715B0(&D_800AF414, a1, a2, a4);
    while (func_80076FD8(&D_800AF414)) {
    }
    if (!((bool (*)(void *))func_800771D4)(&D_800AF414)) {
        Msg_8007EF90 *m = (Msg_8007EF90 *)func_8001CA10(0x14);
        m->vt = D_80010178;
        m->next = 0;
        m->vt = D_80010300;
        m->type = 2;
        m->sub = 2;
        m->d = 0x2034;
        m->c = 0;
        m->vt = D_800102D0;
        func_8001EFE4(p, m);
    }
    return r;
}

EXTERN_C void func_8007EDAC(void *p, int a1, int a2)
{
    int i;
    if (func_800771D4(&D_800AF414)) {
        for (i = 15; i > 0; i--) {
            ((Arr_8007F434 *)p)->a[i] = ((Arr_8007F434 *)p)->a[i - 1];
        }
        ((Arr_8007F434 *)p)->a[0].w[0] = 2;
        ((Arr_8007F434 *)p)->a[0].w[1] = a1;
        ((Arr_8007F434 *)p)->a[0].w[2] = a2;
        ((Arr_8007F434 *)p)->a[0].w[3] = 2;
        func_8007F0A8(p, a1, a2, 0, 2);
        return;
    }
    if (FIELD_AT(p, int, 0x434) != 0) {
        func_8007F0A8(p, a1, a2, 0, 2);
        func_8007F138(p);
        return;
    }
    for (i = 15; i > 0; i--) {
        ((Arr_8007F434 *)p)->a[i] = ((Arr_8007F434 *)p)->a[i - 1];
    }
    ((Arr_8007F434 *)p)->a[0].w[0] = 2;
    ((Arr_8007F434 *)p)->a[0].w[1] = a1;
    ((Arr_8007F434 *)p)->a[0].w[2] = a2;
    ((Arr_8007F434 *)p)->a[0].w[3] = -1;
    func_800715B0(&D_800AF414, a1, a2, 0);
    while (func_80076FD8(&D_800AF414)) {
    }
    if (!((bool (*)(void *))func_800771D4)(&D_800AF414)) {
        Msg_8007EF90 *m = (Msg_8007EF90 *)func_8001CA10(0x14);
        m->vt = D_80010178;
        m->next = 0;
        m->vt = D_80010300;
        m->type = 2;
        m->sub = 2;
        m->d = 0x2034;
        m->c = 0;
        m->vt = D_800102D0;
        func_8001EFE4(p, m);
    }
}

EXTERN_C void func_8007EF90(void *p)
{
    Arr_8007F434 *self = (Arr_8007F434 *)p;
    int i;
    for (i = 15; i > 0; i--) {
        self->a[i] = self->a[i - 1];
    }
    self->a[0].w[0] = 3;
    self->a[0].w[1] = -1;
    self->a[0].w[2] = -1;
    self->a[0].w[3] = -1;
    func_800775F0(&D_800AF414);
    func_80077478(&D_800AF414);
    while (func_80076FD8(&D_800AF414)) {
    }
    if (!((bool (*)(void *))func_800771D4)(&D_800AF414)) {
        Msg_8007EF90 *m = (Msg_8007EF90 *)func_8001CA10(0x14);
        m->vt = D_80010178;
        m->next = 0;
        m->vt = D_80010300;
        m->type = 2;
        m->sub = 2;
        m->d = 0x2034;
        m->c = 0;
        m->vt = D_800102D0;
        func_8001EFE4(self, m);
    }
}

EXTERN_C void func_8007F0A8(void *self, int a, int b, int c, int d)
{
    char *p = (char *)__builtin_new(0x18);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80017360;
    FIELD_AT(p, int, 0x8) = a;
    FIELD_AT(p, int, 0xC) = b;
    FIELD_AT(p, int, 0x10) = c;
    FIELD_AT(p, int, 0x14) = d;
    func_8001A678((char *)self + 0x430, p);
}

EXTERN_C void func_8007F138(void *p)
{
    char *l = (char *)p + 0x430;
    while (1) {
        char *n = FIELD_AT(l, char *, 0x4);
        int a;
        int b;
        int c;
        int d;
        if (n == 0) {
            return;
        }
        func_8001A744(l, n);
        a = FIELD_AT(n, int, 0x8);
        b = FIELD_AT(n, int, 0xC);
        c = FIELD_AT(n, int, 0x10);
        d = FIELD_AT(n, int, 0x14);
        FIELD_AT(n, int, 0x4) = 0;
        ((VObj0 *)n)->v00(3);
        shift_8007F138((Arr_8007F434 *)p);
        ((Arr_8007F434 *)p)->a[0].w[0] = 5;
        ((Arr_8007F434 *)p)->a[0].w[1] = a;
        ((Arr_8007F434 *)p)->a[0].w[2] = b;
        ((Arr_8007F434 *)p)->a[0].w[3] = d;
        if (d == 1) {
            int r;
            char *t;
            char *u;
            if (FIELD_AT(p, int, 0x344) != 0) {
                shift_8007F138((Arr_8007F434 *)p);
                ((Arr_8007F434 *)p)->a[0].w[0] = 7;
                ((Arr_8007F434 *)p)->a[0].w[1] = a;
                ((Arr_8007F434 *)p)->a[0].w[2] = b;
                ((Arr_8007F434 *)p)->a[0].w[3] = 1;
                continue;
            }
            r = func_8007D024(FIELD_AT(p, void *, 0x328), a, b, c);
            if (r < 0) {
                ((Arr_8007F434 *)p)->a[0].w[0] |= 0x80000000;
                continue;
            }
            func_800715B0(&D_800AF414, a, b, c);
            while (func_80076FD8(&D_800AF414)) {
            }
            if (r != 0) {
                if (b == 5) {
                    goto l74564;
                }
                if (b == 7) {
                    t = FIELD_AT(p, char *, 0x328);
                    u = t ? t + 0xB8 : 0;
                    func_80043740(FIELD_AT(u, void *, 0x8), 4);
                l74564:
                    t = FIELD_AT(p, char *, 0x328);
                    u = t ? t + 0xB8 : 0;
                    func_80074564(FIELD_AT(u, void *, 0x8));
                }
            }
        } else {
            if (FIELD_AT(p, int, 0x344) != 0) {
                shift_8007F138((Arr_8007F434 *)p);
                ((Arr_8007F434 *)p)->a[0].w[0] = 8;
                ((Arr_8007F434 *)p)->a[0].w[1] = a;
                ((Arr_8007F434 *)p)->a[0].w[2] = b;
                ((Arr_8007F434 *)p)->a[0].w[3] = 1;
                continue;
            }
            func_800715B0(&D_800AF414, a, b, c);
            while (func_80076FD8(&D_800AF414)) {
            }
        }
        if (!((bool (*)(void *))func_800771D4)(&D_800AF414)) {
            short t2 = 2;
            int dd = 0x2034;
            Msg_8007EF90 *m = (Msg_8007EF90 *)func_8001CA10(0x14);
            m->vt = D_80010178;
            m->next = 0;
            m->vt = D_80010300;
            m->type = t2;
            m->sub = t2;
            m->d = dd;
            m->c = 0;
            m->vt = D_800102D0;
            func_8001EFE4(p, m);
        }
        if (0) {
            Msg_8007EF90 *m = (Msg_8007EF90 *)func_8001CA10(0x14);
            m->vt = D_80010178;
            m->next = 0;
            m->vt = D_80010300;
            m->type = 2;
            m->sub = 2;
            m->d = 0x2034;
            m->c = 0;
            m->vt = D_800102D0;
            func_8001EFE4(p, m);
        }
        return;
    }
}

EXTERN_C void func_8007F434(void *p)
{
    Arr_8007F434 *self = (Arr_8007F434 *)p;
    int i;
    char *l;
    char *n;
    for (i = 15; i > 0; i--) {
        self->a[i] = self->a[i - 1];
    }
    l = (char *)self + 0x430;
    self->a[0].w[0] = -1;
    self->a[0].w[1] = -1;
    self->a[0].w[2] = -1;
    self->a[0].w[3] = -1;
    while (1) {
        n = FIELD_AT(l, char *, 0x4);
        if (n == 0) {
            break;
        }
        func_8001A744(l, n);
        FIELD_AT(n, int, 0x4) = 0;
        ((VObj0 *)n)->v00(3);
    }
}

EXTERN_C void func_8007F4F4(void *self)
{
    if (FIELD_AT(self, int, 0x378) == 1 && FIELD_AT(self, int, 0x370) == 1) {
        func_8007D994(FIELD_AT(self, void *, 0x328));
    }
}

EXTERN_C int func_8007F538(void *self, int *a, int *b)
{
    return func_8006F52C(FIELD_AT(self, void *, 0x328), a, b);
}

EXTERN_C int func_8007F55C(void *self, int *a, int *b, int *c)
{
    return func_8006F5B4(FIELD_AT(self, void *, 0x328), a, b, c);
}

EXTERN_C int func_8007F580(void *self, int *a, int *b)
{
    return func_8006F570(FIELD_AT(self, void *, 0x328), a, b);
}

EXTERN_C int func_8007F5A4(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x240);
}

EXTERN_C void func_8007F5B8(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x1000;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007F62C(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x1001;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007F6A0(void *self)
{
    func_8007DDCC(FIELD_AT(self, char *, 0x328));
}

EXTERN_C void func_8007F6C4(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x1002;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007F738(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x1002;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007F7AC(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x1002;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007F820(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x1003;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_8007F894(void)
{
}

EXTERN_C void func_8007F89C(void *self)
{
    func_8007A1F4(self, 2);
}

EXTERN_C void func_8007F8BC(void *self)
{
    char *o = FIELD_AT(self, char *, 0x32C);
    switch (FIELD_AT(o, int, 0x824)) {
    case 1:
        func_800C68D8(o, 2);
        break;
    case 2:
        func_800C6DF4(o, 2);
        break;
    case 3:
        func_800C7158(o, 4);
        break;
    }
}

EXTERN_C void func_8007F940(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int, 0x10) = 0x2008;
    FIELD_AT(p, void *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007F9B4);

EXTERN_C void func_8007FA58(void *self, int a1, int a2, int a3, int a4, int a5, int a6, int a7, B16_B s, int a12)
{
    char *t = FIELD_AT(self, char *, 0x328);
    func_8007B538(t ? t + 0xB8 : 0, 1, 1, 0, 0, 0);
    func_8007CAB4(FIELD_AT(self, void *, 0x328), a1, a2, a3, a4, a5, a6, a7, s, a12);
}

EXTERN_C void func_8007FB30(void *self, int b)
{
    Base1_8007FB30 *p = FIELD_AT(self, Derived_8007FB30 *, 0x328);
    void *q = p->unk8;
    if (q != 0) {
        FIELD_AT(q, short, 0x5CA) = (b + 4) % 8;
    }
}

EXTERN_C void func_8007FB78(void *self, int k, V4_80085578 s, int e)
{
    char *n = FIELD_AT(self, char *, 0x550);
    while (1) {
        if (n == 0) {
            break;
        }
        if (FIELD_AT(n, int, 0x8) + 1 == k) {
            func_800DF604(n, s, e);
            return;
        }
        n = FIELD_AT(n, char *, 0x4);
    }
    func_8001A678((char *)self + 0x54C, func_800DF37C(__builtin_new(0x10), k, s, e));
}

EXTERN_C void func_8007FC90(void *self, int k)
{
    char *n;
    if (k >= 0) {
        n = FIELD_AT(self, char *, 0x550);
        while (1) {
            if (n == 0) {
                return;
            }
            if (FIELD_AT(n, int, 0x8) + 1 == k) {
                func_8001A744((char *)self + 0x54C, n);
                FIELD_AT(n, int, 0x4) = 0;
                ((VObj0 *)n)->v00(3);
                return;
            }
            n = FIELD_AT(n, char *, 0x4);
        }
    } else {
        char *l = (char *)self + 0x54C;
        while (1) {
            n = FIELD_AT(l, char *, 0x4);
            if (n == 0) {
                break;
            }
            func_8001A744(l, n);
            FIELD_AT(n, int, 0x4) = 0;
            ((VObj0 *)n)->v00(3);
        }
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007FD60);

EXTERN_C void func_8007FE1C(void *self, int b)
{
    FIELD_AT(self, int, 0x548) = b;
}

EXTERN_C void func_8007FE24(void *self, int b, int c, int d)
{
    FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x198) = c;
    FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x19C) = d;
}

EXTERN_C void func_8007FE3C(void *self, int b)
{
    FIELD_AT(self, int, 0x564) = b;
    FIELD_AT(self, int, 0x560) = 1;
}

EXTERN_C int func_8007FE4C(void *p, int pos, int n)
{
    Bits_8007FE4C *self = (Bits_8007FE4C *)p;
    int b[5];
    int byte;
    int sh;
    unsigned int v;
    if (n <= 0 || self->len < pos + 1) {
        return 0;
    }
    if (n >= 32) {
        n = 32;
    }
    if ((unsigned int)self->len < (unsigned int)(pos + 32)) {
        n = 1 + self->len - pos;
    }
    byte = pos / 8;
    b[0] = self->buf[byte];
    b[1] = self->buf[byte + 1];
    b[2] = self->buf[byte + 2];
    b[3] = self->buf[byte + 3];
    v = b[0] + (b[1] << 8) + (b[2] << 16) + (b[3] << 24);
    sh = pos - byte * 8;
    v >>= sh;
    b[4] = self->buf[byte + 4] >> (8 - sh);
    v += b[4] << 24;
    return v & (0xFFFFFFFFu >> (32 - n));
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_8007FF58);

EXTERN_C int func_80080110(void *self, int b)
{
    return func_8007FE4C(self, b, 1);
}

EXTERN_C int func_80080130(void *self, int b)
{
    int r = func_8007FE4C(self, b, 1);
    func_8007FF58(self, b, 1, 1);
    return r;
}

EXTERN_C int func_80080180(void *self, int b)
{
    int r = func_8007FE4C(self, b, 1);
    func_8007FF58(self, b, 1, 0);
    return r;
}

EXTERN_C int func_800801D0(void *self, int b, int c)
{
    int r = func_8007FE4C(self, b, 1);
    func_8007FF58(self, b, 1, c);
    return r;
}

EXTERN_C void func_8008022C_def(void *self, int a, int b)
{
    unsigned tk = D_800A4534.ticks;
    char *p = (char *)__builtin_new(0x10);
    int g;
    unsigned t = a + tk;
    FIELD_AT(p, void *, 0) = D_80010178;
    FIELD_AT(p, int, 4) = 0;
    FIELD_AT(p, void *, 0) = D_800171C0;
    FIELD_AT(p, int, 0xC) = b;
    FIELD_AT(p, unsigned, 8) = t;
    func_8001A678(self, p);
    g = (int)D_800AF470.p;
    func_80081820(&D_800AFA74, a, (b << 16) | 0x3020, 2, g, g);
}

EXTERN_C void func_800802E0(void *self, int b)
{
    VObj0 *p = FIELD_AT(self, VObj0 *, 0x4);
    for (;;) {
        if (p == 0) {
            return;
        }
        if (FIELD_AT(p, int, 0xC) == b) {
            break;
        }
        p = FIELD_AT(p, VObj0 *, 0x4);
    }
    func_8001A744(self, p);
    FIELD_AT(p, void *, 0x4) = 0;
    p->v00(3);
}

EXTERN_C void func_80080350(void *self, int a)
{
    unsigned now = D_800A4534.ticks;
    char *p = FIELD_AT(self, char *, 4);
    while (p != 0) {
        if (FIELD_AT(p, int, 0xC) == a && !(now < FIELD_AT(p, unsigned, 8))) {
            func_8001A744(self, p);
            FIELD_AT(p, int, 4) = 0;
            ((VObj0 *)p)->v00(3);
            break;
        }
        p = nx_80080350(p);
    }
}

EXTERN_C void *func_800803E8(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171B0;
    FIELD_AT(self, int, 0x10) = 0;
    FIELD_AT(self, int, 0x14) = 0;
    FIELD_AT(self, int, 0x3C) = 0;
    return self;
}

EXTERN_C void func_80080418(void *self, int flags)
{
    func_800DF6F0(self);
    func_8001A610(self, 2);
    if (flags & 1) {
        operator delete(self);
    }
}

EXTERN_C Obj_80080468 *func_80080468(Obj_80080468 *self)
{
    func_800756F8(self);
    self->vtable = D_80017190;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk2C = -1;
    self->unk30 = 0;
    self->unk34 = 0;
    self->unk38 = 0;
    self->unk50 = 0;
    self->unk54 = 0;
    return self;
}

EXTERN_C void func_800804D8(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_80017190;
    func_80080828(self);
    if (flags & 1) {
        operator delete(self);
    }
}

EXTERN_C int func_80080528(void)
{
    return 0;
}

EXTERN_C void func_80080530(void *self, int a, int b, int c)
{
    if (FIELD_AT(self, int, 0x50) != 0) {
        FIELD_AT(self, int, 0x54) += 1;
    }
    FIELD_AT(self, int, 0x50) = 1;
    void *n = __builtin_new(0x1C8);
    void *p = func_800758F8(n, 1, D_800A4578.p ? (char *)D_800A4578.p + 0x50 : 0, self);
    void *d = D_800B4C18.p;
    FIELD_AT(self, void *, 0x3C) = p;
    func_8001E848(d, p);
    void *q = func_800A0D2C(c);
    func_800766F8(FIELD_AT(self, void *, 0x3C), c, q, a, 1);
    func_8007669C(FIELD_AT(self, void *, 0x3C), b, c);
}

EXTERN_C void func_80080614(void *self, void *a1, int a2, int a3)
{
    if (FIELD_AT(self, int, 0x50) != 0) {
        FIELD_AT(self, int, 0x50) = 0;
        switch (a3) {
        case 0:
            func_800766D8(FIELD_AT(self, void *, 0x3C));
            ((void (*)(void *, void *, int))func_80080AE8)(self, a1, a2);
            func_80080530(self, 1, FIELD_AT(self, int, 0x48), FIELD_AT(self, int, 0x4C));
            return;
        case 1:
            func_800766D8(FIELD_AT(self, void *, 0x3C));
            ((void (*)(void *, void *, int))func_80080B60)(self, a1, a2);
            return;
        }
    }
    if (a1 != 0) {
        func_800A0D0C(a1);
    }
    func_800766D8(FIELD_AT(self, void *, 0x3C));
}

EXTERN_C void func_800806EC(void)
{
}

EXTERN_C void func_800806F4(void *self)
{
    if (FIELD_AT(self, int, 0x38) != 0) {
        if (func_8008FD94(FIELD_AT(FIELD_AT(self, char *, 0x34), unsigned short, 0x14)) != 0) {
            return;
        }
        FIELD_AT(self, int, 0x38) = 0;
        func_8008ED44(FIELD_AT(self, void *, 0x34));
        if (FIELD_AT(self, void *, 0x34) != 0) {
            func_800A0D0C(FIELD_AT(self, void *, 0x34));
        }
        FIELD_AT(self, void *, 0x34) = 0;
        func_8008D4C0(FIELD_AT(self, void *, 0x30));
    }
    if (FIELD_AT(self, int, 0x14) != 0) {
        FIELD_AT(self, int, 0x14) = 0;
        FIELD_AT(self, int, 0x8) = func_8008D1F4(FIELD_AT(self, int, 0x4), 0);
        FIELD_AT(self, int, 0x10) = 0;
        FIELD_AT(self, int, 0xC) = 1;
    }
    if (FIELD_AT(self, int, 0x24) != 0) {
        void *g;
        FIELD_AT(self, int, 0x24) = 0;
        func_8008ECB4(FIELD_AT(self, int, 0x1C));
        g = D_800AF470.p;
        FIELD_AT(self, int, 0x20) = 1;
        func_8007EF90(g);
    }
    if (FIELD_AT(self, int, 0xC) != 0) {
        if (func_8008C928(0) != 0) {
            return;
        }
        FIELD_AT(self, int, 0x10) = 1;
        if (FIELD_AT(self, void *, 0x4) != 0) {
            func_800A0D0C(FIELD_AT(self, void *, 0x4));
            FIELD_AT(self, void *, 0x4) = 0;
        }
        FIELD_AT(self, int, 0xC) = 0;
    }
    if (FIELD_AT(self, int, 0x2C) != -1) {
        func_80080BC4(self, FIELD_AT(self, int, 0x2C));
    }
}

EXTERN_C void func_80080828(void *self)
{
    if (FIELD_AT(self, int, 0x38) != 0) {
        func_8008FC38(FIELD_AT(FIELD_AT(self, char *, 0x34), unsigned short, 0x14));
        FIELD_AT(self, int, 0x38) = 0;
        func_8008ED44(FIELD_AT(self, void *, 0x34));
        if (FIELD_AT(self, void *, 0x34) != 0) {
            func_800A0D0C(FIELD_AT(self, void *, 0x34));
        }
        FIELD_AT(self, void *, 0x34) = 0;
        func_8008D4C0(FIELD_AT(self, void *, 0x30));
    }
    func_800808AC(self);
    FIELD_AT(self, int, 0x2C) = -1;
}

EXTERN_C void func_800808AC(void *self)
{
    if (FIELD_AT(self, int, 0x14) != 0) {
        FIELD_AT(self, int, 0x14) = 0;
    }
    if (FIELD_AT(self, int, 0xC) != 0) {
        func_8008C928(0x10);
        FIELD_AT(self, int, 0x10) = 1;
        FIELD_AT(self, int, 0xC) = 0;
    }
    if (FIELD_AT(self, int, 0x24) != 0) {
        FIELD_AT(self, int, 0x24) = 0;
    }
    if (FIELD_AT(self, int, 0x20) != 0) {
        func_8008ED44(FIELD_AT(self, void *, 0x1C));
        FIELD_AT(self, int, 0x20) = 0;
    }
    if (FIELD_AT(self, void *, 0x1C) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x1C));
        FIELD_AT(self, void *, 0x1C) = 0;
    }
    if (FIELD_AT(self, int, 0x10) != 0) {
        func_8008D4C0(FIELD_AT(self, void *, 0x8));
        FIELD_AT(self, int, 0x10) = 0;
    }
    if (FIELD_AT(self, void *, 0x4) != 0) {
        func_800A0D0C(FIELD_AT(self, void *, 0x4));
        FIELD_AT(self, void *, 0x4) = 0;
    }
}

EXTERN_C void func_80080990(void *self, int a, int b, int c)
{
    func_80080828(self);
    FIELD_AT(self, int, 0x30) = func_8008D1F4(a, 0);
    FIELD_AT(self, int, 0x34) = b;
    func_8008ECB4(b);
    func_8008C928(0x10);
    if (a != 0) {
        func_800A0D0C((void *)a);
    }
    {
        unsigned short n = FIELD_AT(FIELD_AT(self, char *, 0x34), unsigned short, 0x14);
        FIELD_AT(self, int, 0x38) = 1;
        func_8008EF40((n << 16) + c);
    }
}

EXTERN_C int func_80080A2C(void *self, int a1, int a2, int a3, int a4)
{
    if (FIELD_AT(self, int, 0x10) != 0 && FIELD_AT(self, int, 0x20) != 0 && FIELD_AT(self, int, 0x40) == a1 && FIELD_AT(self, int, 0x48) == a3) {
        return 0;
    }
    func_800808AC(self);
    FIELD_AT(self, int, 0x40) = a1;
    FIELD_AT(self, int, 0x44) = a2;
    FIELD_AT(self, int, 0x2C) = -1;
    FIELD_AT(self, int, 0x48) = a3;
    FIELD_AT(self, int, 0x4C) = a4;
    func_80080530(self, 0, FIELD_AT(self, int, 0x40), FIELD_AT(self, int, 0x44));
    return 1;
}

EXTERN_C void func_80080AE8(void *self, int b)
{
    if (FIELD_AT(self, int, 0x38) != 0) {
        FIELD_AT(self, int, 0x18) = b;
        FIELD_AT(self, int, 0x14) = 1;
    } else {
        func_800808AC(self);
        FIELD_AT(self, int, 0x4) = b;
        FIELD_AT(self, int, 0x8) = func_8008D1F4(b, 0);
        FIELD_AT(self, int, 0x10) = 0;
        FIELD_AT(self, int, 0xC) = 1;
    }
    func_800806F4(self);
}

EXTERN_C void func_80080B60(void *self, int b)
{
    if (FIELD_AT(self, int, 0x38) != 0) {
        FIELD_AT(self, int, 0x24) = 1;
        FIELD_AT(self, int, 0x28) = b;
    } else {
        void *g;
        FIELD_AT(self, int, 0x1C) = b;
        func_8008ECB4(b);
        g = D_800AF470.p;
        FIELD_AT(self, int, 0x20) = 1;
        func_8007EF90(g);
    }
    func_800806F4(self);
}

EXTERN_C void func_80080BC4(void *self, int b)
{
    if (FIELD_AT(self, int, 0x38) != 0 || FIELD_AT(self, int, 0x10) == 0 || FIELD_AT(self, int, 0x20) == 0) {
        FIELD_AT(self, int, 0x2C) = b;
    } else {
        func_8008EF40((FIELD_AT(FIELD_AT(self, void *, 0x1C), unsigned short, 0x14) << 16) + b);
        FIELD_AT(self, int, 0x2C) = -1;
    }
}

EXTERN_C void func_80080C40(void *self, void *b, int c)
{
    func_800852DC(b, c);
}

EXTERN_C void func_80080C64(void *self, char *b)
{
    char *q = 0;
    if (b != 0) {
        q = b + 0x2A0;
    }
    func_8008316C(q);
}

EXTERN_C void func_80080C90(void *self)
{
    func_800DFB10((char *)self + 0x4B0);
}

EXTERN_C int func_80080CB0(void *self)
{
    return FIELD_AT(self, int, 0x568);
}

EXTERN_C int func_80080CBC(void *self, int b)
{
    return (b & 0x7) << 9;
}

EXTERN_C int func_80080CC8(void *self, int b)
{
    return ((b + 0x100) / 0x200) & 7;
}

EXTERN_C int func_80080CE4(void *self)
{
    return FIELD_AT(self, int, 0x328);
}

EXTERN_C void func_80080CF0(void *self, int b)
{
    func_8007DEE8(FIELD_AT(self, void *, 0x328), b);
}

EXTERN_C int func_80080D14(void *self, int i)
{
    return D_800AFA64[i];
}

EXTERN_C int func_80080D30(void *self, int i)
{
    return D_800AFA58[i];
}

EXTERN_C int func_80080D4C(void *self, int i)
{
    char *p = FIELD_AT(self, char *, 0x328);
    Arr_80080D4C *q = 0;
    if (p != 0) {
        q = (Arr_80080D4C *)(p + 0xB8);
    }
    return q->items[i];
}

EXTERN_C int func_80080D74(void *self)
{
    Base1_80080D74 *b = FIELD_AT(self, Derived_80080D74 *, 0x328);
    return b->unk8;
}

EXTERN_C void func_80080D94(void *self)
{
    char *v = FIELD_AT(self, char *, 0x328) ? FIELD_AT(self, char *, 0x328) + 0xB8 : 0;
    short *q;
    q = (short *)(FIELD_AT(FIELD_AT(v, char *, 0x8), char *, 0x1B8) + 0x2C);
    func_80080CC8(self, (short)SquareRoot0(q[0] * q[0] + q[1] * q[1] + q[2] * q[2]));
}

EXTERN_C int func_80080E28(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x150);
}

EXTERN_C int func_80080E3C(void *self)
{
    return FIELD_AT(FIELD_AT(self, void *, 0x328), int, 0x14C);
}

EXTERN_C void func_80080E50(void *self)
{
    func_80080828(self);
}

EXTERN_C int func_80080E70(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

EXTERN_C int func_80080E7C(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

EXTERN_C void *func_80080E88(void *self, int b, int c)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171B0;
    FIELD_AT(self, int, 0x8) = b;
    FIELD_AT(self, int, 0xC) = c;
    return self;
}

EXTERN_C void *func_80080EB4(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171B0;
    return self;
}

EXTERN_C void func_80080ED8(void *self, int flags)
{
    func_8001A610(self, flags);
}

EXTERN_C void func_80080EF8(void *self, int flags)
{
    char *n;
    while (1) {
        n = FIELD_AT(self, char *, 0x4);
        if (n == 0) {
            break;
        }
        func_8001A744(self, n);
        FIELD_AT(n, int, 0x4) = 0;
        ((VObj0 *)n)->v00(3);
    }
    func_8001A610(self, 2);
    if (flags & 1) {
        __builtin_delete(self);
    }
}

EXTERN_C void *func_80080F88(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171C0;
    return self;
}

EXTERN_C int func_80080FAC(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

EXTERN_C int func_80080FB8(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

EXTERN_C void *func_80080FC4(void *self, int b, int c)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171C0;
    FIELD_AT(self, int, 0x8) = b;
    FIELD_AT(self, int, 0xC) = c;
    return self;
}

EXTERN_C void *func_80080FF0(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171C0;
    return self;
}

EXTERN_C void func_80081014(void *self, int flags)
{
    func_8001A610(self, flags);
}

EXTERN_C void func_80081034(void *self, int b, int c)
{
    FIELD_AT(self, int, 0x0) = b;
    FIELD_AT(self, int, 0x4) = c;
}

EXTERN_C void *func_80081040(void *self, int b, int c)
{
    FIELD_AT(self, int, 0x0) = b;
    FIELD_AT(self, int, 0x4) = c;
    return self;
}

EXTERN_C void *func_80081050(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, int, 0x4) = 0;
    return self;
}

EXTERN_C int func_80081060(void *self, int b)
{
    return (b & 0x7) << 9;
}

EXTERN_C int func_8008106C(void *self, int b)
{
    return ((b + 0x100) / 0x200) & 7;
}

EXTERN_C void *func_80081088(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_800171D0;
    FIELD_AT(self, int, 0x8) = -1;
    FIELD_AT(self, int, 0xC) = 0;
    return self;
}

EXTERN_C void func_800810B8(Obj_800810B8 *self, void *o, int c, int d)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 7;
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = 0xFF;
    self->q[0].c = c;
    self->q[0].d = d;
}

EXTERN_C void func_80081114(Obj_80081114 *self, void *o, void *t, int d, int e)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 6;
    int v;
    if (t == 0) {
        v = 0xFF;
    } else {
        v = FIELD_AT(t, signed char, 0x4BC);
    }
    int i;
    if (e) {
        d |= 0x80;
    }
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = v;
    self->q[0].c = d;
    self->q[0].d = 0xFF;
}

EXTERN_C void func_80081190(Obj_80081190 *self, void *o, void *t, int d)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 5;
    int v;
    if (t == 0) {
        v = 0xFF;
    } else {
        v = FIELD_AT(t, signed char, 0x4BC);
    }
    int f = (d != 0) << 7;
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = v;
    self->q[0].c = f;
    self->q[0].d = 0xFF;
}

EXTERN_C void func_80081204(Obj_80081204 *self, void *o, int c)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 4;
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = 0xFF;
    self->q[0].c = c;
    self->q[0].d = 0xFF;
}

EXTERN_C void func_80081260(Obj_80081190 *self, void *o, void *t, int d, int e, int f)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 3;
    int v;
    if (t == 0) {
        v = 0xFF;
    } else {
        v = FIELD_AT(t, signed char, 0x4BC);
    }
    if (e != 0) {
        d |= 0x80;
    }
    int g = f != 0;
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = v;
    self->q[0].c = d;
    self->q[0].d = g;
}

EXTERN_C void func_800812E4(Obj_800812E4 *self, void *o, void *t)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 1;
    int v;
    if (t == 0) {
        v = 0xFF;
    } else {
        v = FIELD_AT(t, signed char, 0x4BC);
    }
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = v;
    self->q[0].c = 0xFF;
    self->q[0].d = 0xFF;
}

EXTERN_C void func_80081350(Obj_80081350 *self, void *o, void *t, int d)
{
    int k = (FIELD_AT(o, signed char, 0x4BC) << 4) | 1;
    int v;
    if (t == 0) {
        v = 0xFF;
    } else {
        v = FIELD_AT(t, signed char, 0x4BC);
    }
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = k;
    self->q[0].b = v;
    self->q[0].c = d;
    self->q[0].d = 0xFF;
}

EXTERN_C void func_800813BC(Obj_800813BC *self, int a, int b, int c, int d)
{
    int i;
    for (i = 0x1F; i > 0; i--) {
        self->q[i] = self->q[i - 1];
    }
    self->q[0].a = a;
    self->q[0].b = b;
    self->q[0].c = c;
    self->q[0].d = d;
}

EXTERN_C void func_8008140C(void *self)
{
    memset((char *)self + 0x3B0, 0xFF, 0x80);
}

EXTERN_C int func_80081434(void *self, int b)
{
    return (b & 0x7) << 9;
}

EXTERN_C int func_80081440(void *self, int b)
{
    return ((b + 0x100) / 0x200) & 7;
}

EXTERN_C int func_8008145C(void *self)
{
    return FIELD_AT(self, int, 0x384);
}

EXTERN_C int func_80081468(void *self)
{
    return FIELD_AT(self, int, 0x380);
}

EXTERN_C void func_80081474(void *self)
{
    VObj0 *p = FIELD_AT(self, VObj0 *, 0x32C);
    if (p != 0) {
        p->v02(3);
        FIELD_AT(self, void *, 0x32C) = 0;
    }
}

EXTERN_C int func_800814C4(void *self)
{
    return FIELD_AT(self, int, 0x32C);
}

EXTERN_C int func_800814D0(void *self)
{
    return FIELD_AT(self, int, 0x370);
}

EXTERN_C int func_800814DC(void *self)
{
    return FIELD_AT(self, int, 0x378);
}

EXTERN_C void func_800814E8(void)
{
}

EXTERN_C int func_800814F0(void *self)
{
    return FIELD_AT(self, int, 0x150);
}

EXTERN_C int func_800814FC(void *self)
{
    return FIELD_AT(self, int, 0x14C);
}

EXTERN_C int func_80081508(void *self, int b)
{
    return (b & 0x7) << 9;
}

EXTERN_C int func_80081514(void *self, int b)
{
    return ((b + 0x100) / 0x200) & 7;
}

EXTERN_C int func_80081530(void *self)
{
    return FIELD_AT(self, int, 0x2C);
}

EXTERN_C int func_8008153C(void *self, int i)
{
    return D_800AFA58[i];
}

EXTERN_C int *func_80081558(void)
{
    return D_800AFA58;
}

EXTERN_C int func_80081564(void *self)
{
    return FIELD_AT(self, int, 0x18);
}

EXTERN_C int func_80081570(void *self, int i)
{
    return D_800AFA64[i];
}

EXTERN_C int *func_8008158C(void)
{
    return D_800AFA64;
}

EXTERN_C int func_80081598(void *self)
{
    return FIELD_AT(self, int, 0x14);
}

EXTERN_C int func_800815A4(void *self)
{
    return FIELD_AT(self, int, 0x14) + FIELD_AT(self, int, 0x18);
}

EXTERN_C int func_800815B4(Obj_800815B4 *self, int i)
{
    return self->items[i];
}

EXTERN_C int func_800815C8(void *self)
{
    return FIELD_AT(self, int, 0x8);
}

EXTERN_C int func_800815D4(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800815E0(void *self, int b)
{
    return (b + 0x7FF) / 0x800;
}

EXTERN_C void func_800815F8(void *self, int flags)
{
    FIELD_AT(self, void *, 0x0) = D_80017360;
    func_8001A610(self, flags);
}

EXTERN_C Obj_80081620 *func_80081620(Obj_80081620 *self, int b, int c, int d, int e)
{
    self->vtable = D_80010178;
    self->unk4 = 0;
    self->vtable = D_80017360;
    self->unk8 = b;
    self->unkC = c;
    self->unk10 = d;
    self->unk14 = e;
    return self;
}

EXTERN_C void *func_80081658(void *self)
{
    FIELD_AT(self, void *, 0x0) = D_80010178;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, void *, 0x0) = D_80017360;
    FIELD_AT(self, int, 0x8) = 0;
    FIELD_AT(self, int, 0xC) = 0;
    FIELD_AT(self, int, 0x10) = 0;
    FIELD_AT(self, int, 0x14) = 0;
    return self;
}

EXTERN_C void func_8008168C(void *self, int b)
{
    FIELD_AT(self, void *, 0x8) = D_80017380;
    func_80074E44(self, b);
}

EXTERN_C void *func_800816B4(void *self, int a, int b, int c, int d, int e, int f)
{
    char *r;
    func_80074E28(self);
    r = (char *)self;
    FIELD_AT(r, void *, 0x8) = D_80017380;
    FIELD_AT(r, int, 0xC) = a;
    FIELD_AT(r, int, 0x10) = b;
    FIELD_AT(r, int, 0x14) = c;
    FIELD_AT(r, int, 0x18) = d;
    FIELD_AT(r, int, 0x1C) = e;
    FIELD_AT(r, int, 0x20) = f;
    return r;
}

EXTERN_C void *func_80081748(void *self)
{
    func_80074F58(self);
    FIELD_AT(self, void *, 0xC) = D_800173C0;
    FIELD_AT(self, int, 0x10) = 0;
    return self;
}

EXTERN_C void func_80081780(void *self, int b)
{
    FIELD_AT(self, void *, 0xC) = D_800173C0;
    func_800817C8(self);
    func_80074F78(self, b);
}

EXTERN_C void func_800817C8(void *self)
{
    VObj<8> *p;
    while ((p = (VObj<8> *)func_800751AC(self)) != 0) {
        p->v00(3);
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80081820);

EXTERN_C int func_80081970(void *self, void *x)
{
    List_8007AB78 *l = (List_8007AB78 *)self;
    if (l->IsEmpty()) {
        return -1;
    }
    l->First();
    do {
        if (x == l->cur) {
            char *n = (char *)func_800752B8(l);
            int r = FIELD_AT(n, int, 0xC) - FIELD_AT(l, int, 0x10);
            if (n != 0) {
                ((VObj<8> *)n)->v00(3);
            }
            return r;
        }
        if (l->IsLast()) {
            break;
        }
        l->Next();
    } while (1);
    return -1;
}

EXTERN_C void func_80081A74(void *self, int x)
{
    if (x == 0) {
        x = (int)D_800B4C18.p;
    }
    del2_80081A74((List_8007AB78 *)self, x);
}

EXTERN_C void func_80081BA4(void *self, int x)
{
    if (x == 0) {
        x = (int)D_800B4C18.p;
    }
    del_80081A74((List_8007AB78 *)self, x);
}

EXTERN_C void func_80081CB8(void *self, int x)
{
    if (x == 0) {
        x = (int)D_800B4C18.p;
    }
    del3_80081CB8((List_8007AB78 *)self, x);
}

EXTERN_C void func_80081DCC(void *self, int x)
{
    List_8007AB78 *l = (List_8007AB78 *)self;
    if (l->IsEmpty()) {
        return;
    }
    l->First();
    do {
        if (l->Cur()->id10 == x) {
            VObj<8> *n = (VObj<8> *)func_800752B8(l);
            if (n != 0) {
                n->v00(3);
            }
        }
        if (l->IsLast()) {
            break;
        }
        l->Next();
    } while (1);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80071A74", func_80081ED0);

EXTERN_C Obj_80081FF8 *func_80081FF8(Obj_80081FF8 *self, int b, int c)
{
    func_8001E40C(self, b, 2, 0x400, 0);
    self->vt8C = D_80017390;
    self->vtable = D_800173A8;
    D_800AFA88.v = c;
    return self;
}

EXTERN_C void func_80082058(void *self, int flags)
{
    FIELD_AT(self, void *, 0x8C) = D_80017390;
    FIELD_AT(self, void *, 0x0) = D_800173A8;
    func_800817C8(&D_800AFA74);
    func_8001E508(self, flags);
}

EXTERN_C void func_800820B4(void *self)
{
    for (;;) {
        VObj0 *p = (VObj0 *)func_8001ED2C(self, (void *)D_800AFA88.v, 1);
        if (p != 0) {
            p->v01();
        } else {
            func_80081ED0(&D_800AFA74, (void *)D_800AFA88.v);
        }
    }
}

EXTERN_C void func_80082128(void)
{
    func_80081780(&D_800AFA74, 2);
}

EXTERN_C void func_80082150(void)
{
    func_80081748(&D_800AFA74);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800170F0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017140);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017160);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017178);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017190);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800171B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800171C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800171D0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800171E0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017210);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017260);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017280);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017298);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800172B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800172E8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800172F8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017328);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017360);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017370);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017380);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017390);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800173A8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800173C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800173D0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_800173E0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017660);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017674);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017690);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017748);

INCLUDE_RODATA("asm/main/nonmatchings/u_80071A74", D_80017758);
