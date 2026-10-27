#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"

EXTERN_C void *func_8005F238(void *self)
{
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, int, 0x0) = 0;
    return self;
}

// GCC 2.x deleting destructor: bit 0 of the second argument frees the object.
EXTERN_C void func_8005F248(void *self, int flags)
{
    func_8005F3E0(self);
    if (flags & 1) {
        __builtin_delete(self);
    }
}

EXTERN_C int func_8005F28C(void *self)
{
    return FIELD_AT(self, int, 0x0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_8005F298);

EXTERN_C void func_8005F3E0(void *self)
{
    VObj0 *p = FIELD_AT(self, VObj0 *, 0x4);
    if (p != 0) {
        p->v02();
        func_80036D8C(FIELD_AT(self, void *, 0x4));
        FIELD_AT(self, int, 0x4) = 0;
        FIELD_AT(self, int, 0x0) = 0;
    }
}

EXTERN_C void func_8005F440(int a, int b)
{
    if (D_800B4DC8 == 0) {
        D_800B4DC8 = a;
        D_800B4DCC = b;
    }
    func_8005F47C();
}

EXTERN_C int func_8005F470(void)
{
    return D_800B4DC4 != 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_8005F47C);

EXTERN_C void *func_8005F50C(Pool_8005F50C *self, int a, int b, unsigned int n)
{
    unsigned int i;
    char *l;
    char *p;
    self->vt = D_80014C38;
    self->a4 = b;
    self->n = n;
    self->data = (int *)func_800A0D2C(n << 2);
    self->data[0] = a;
    for (i = 1; i < self->n; i++) {
        self->data[i] = 0;
    }
    self->a10 = 0;
    D_800B4DC4++;
    l = (char *)&D_800A4544;
    p = (char *)__builtin_new(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010338;
    FIELD_AT(p, short, 0xC) = 0x80;
    FIELD_AT(p, void *, 0x8) = self;
    FIELD_AT(p, int, 0x10) = 1;
    func_8001D150(l, p);
    return self;
}

EXTERN_C void *func_8005F5F4(Pool_8005F50C *self, int a, int b)
{
    char *l;
    char *p;
    self->vt = D_80014C38;
    self->a4 = b + 1;
    self->n = 0;
    self->data = 0;
    self->a10 = a;
    D_800B4DC4++;
    l = (char *)&D_800A4544;
    p = (char *)__builtin_new(0x14);
    FIELD_AT(p, void *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, void *, 0x0) = D_80010338;
    FIELD_AT(p, short, 0xC) = 0x80;
    FIELD_AT(p, void *, 0x8) = self;
    FIELD_AT(p, int, 0x10) = 1;
    func_8001D150(l, p);
    return self;
}

EXTERN_C void func_8005F698(void *self, int b)
{
    void *p;
    FIELD_AT(self, void *, 0x0) = D_80014C38;
    p = FIELD_AT(self, void *, 0xC);
    if (p != 0) {
        func_800A0D0C(p);
    }
    D_800B4DC4--;
    func_8005F47C();
    func_8001D024(self, b);
}

EXTERN_C void func_8005F704(Arr_8005F704 *self, unsigned int i, int v)
{
    if (i < self->count) {
        self->items[i] = v;
    }
}

EXTERN_C int func_8005F730(Pool_8005F50C *self)
{
    unsigned int i;
    VObj0 *p;
    if (self->a4 != 0) {
        self->a4--;
        return 0;
    }
    if (self->data != 0) {
        for (i = 0; i < self->n; i++) {
            p = (VObj0 *)self->data[i];
            if (p != 0) {
                p->v00(3);
            }
            self->data[i] = 0;
        }
    } else {
        p = (VObj0 *)self->a10;
        if (p != 0) {
            p->v00(3);
        }
        self->data = 0;
    }
    return 1;
}

EXTERN_C int func_8005F834(signed char *p)
{
    signed char *t = D_800AE76C;
    if ((p[0] & 0xF0) == 0x60) {
        t = D_800AE66C;
    }
    return t[(p[1] & 0xF) * 16 + (p[0] & 0xF)];
}

EXTERN_C int func_8005F87C(void *self)
{
    int sum = 0;
    unsigned int i;
    Ev_8005F87C e;

    for (i = 0; i < func_80053BB4(self); i++) {
        func_80053AE4(&e, self, i);
        sum += func_8005F834(e.v);
    }
    return sum;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_8005F8EC);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_8005FB04);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_8005FC78);

EXTERN_C unsigned short func_800600A4(void *self, int b)
{
    char *h;
    if (b < 6 || b == 11) {
        h = self ? (char *)self + 0x8 : 0;
        return FIELD_AT(func_80019F64(h ? FIELD_AT(h, List *, 0x0) : 0, 0), unsigned short, 0x8);
    }
    h = self ? (char *)self + 0x8 : 0;
    return FIELD_AT(func_80019F64(h ? FIELD_AT(h, List *, 0x0) : 0, 1), unsigned short, 0x8);
}

EXTERN_C unsigned short func_80060118(void *self, int b)
{
    char *h = self ? (char *)self + 0x8 : 0;
    return FIELD_AT(func_80019F64(h ? FIELD_AT(h, List *, 0x0) : 0, b), unsigned short, 0x8);
}

EXTERN_C unsigned short func_80060154(void *self, int b)
{
    if (b < 0x40) {
        return FIELD_AT(FIELD_AT(self, void *, 0x24), unsigned short, 0x1C);
    }
    return FIELD_AT(FIELD_AT(self, void *, 0x20), unsigned short, 0x1C);
}

EXTERN_C Pair_80060188 *func_80060188(Pair_80060188 *out, void *self, unsigned int i)
{
    if (i < 10) {
        *out = FIELD_AT(self, Pair_80060188 *, 0x28)[i];
    } else {
        out->a = 0;
        out->b = 0;
    }
    return out;
}

EXTERN_C void *func_800601C8(void *self)
{
    FIELD_AT(self, char, 0x1) = 0;
    FIELD_AT(self, char, 0x0) = 0;
    return self;
}

EXTERN_C void *func_800601D8(void *self, void *src)
{
    func_80060218(self, src);
    return self;
}

EXTERN_C void *func_80060200(void *self, void *src)
{
    FIELD_AT(self, char, 0x0) = FIELD_AT(src, char, 0x0);
    FIELD_AT(self, char, 0x1) = FIELD_AT(src, char, 0x1);
    return self;
}

EXTERN_C void func_80060218(void *self, void *src)
{
    FIELD_AT(self, char, 0x0) = FIELD_AT(src, char, 0x0);
    FIELD_AT(self, char, 0x1) = FIELD_AT(src, char, 0x1);
}

EXTERN_C int func_80060230(signed char *a, signed char *b)
{
    return a[0] == b[0] && a[1] == b[1];
}

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_80060260);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_80060378);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_80060588);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_800609D0);

EXTERN_C int func_80060D6C(void *self)
{
    return func_80060D9C(self) == FIELD_AT(self, int, 0x220);
}

EXTERN_C int func_80060D9C(void *self)
{
    int sum = 0;
    unsigned int i;
    signed char *p = ((Obj_80060D9C *)self)->a;
    signed char *q;

    for (i = 0; i < 0x80; i++) {
        sum += p[i];
    }
    q = ((Obj_80060D9C *)self)->b;
    for (i = 0; i < 0x7C; i++) {
        sum += q[i];
    }
    return sum;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_80060DF0);

EXTERN_C int func_80061030(void *self, unsigned int i)
{
    return (((unsigned int *)((char *)self + 0x124))[i >> 5] & (1 << (i & 0x1F))) != 0;
}

EXTERN_C void func_80061058(void *self)
{
    *FIELD_AT(self, Blk32 *, 0x120) = FIELD_AT(self, Blk32, 0x1D4);
}

EXTERN_C void func_800610E4(Obj_800610E4 *self, int i, int j)
{
    self->out[i] = (j == 16) ? 0 : self->vals[j];
}

EXTERN_C void func_80061114(Obj_80061114 *self, int i, int j)
{
    short t = self->vals[i];
    self->vals[i] = self->vals[j];
    self->vals[j] = t;
}

EXTERN_C void func_80061138(void *self)
{
    func_8008CC20(FIELD_AT(self, signed char, 0x1F8) != 1);
}

EXTERN_C Ent_80061164 *func_80061164(void *self, int i)
{
    return &D_800AE984[i];
}

EXTERN_C void *func_80061188(Obj_80061188 *self, int i)
{
    if (i < 0 || (self->sel >= 0 && i == self->sel)) {
        return &self->cur;
    }
    return &self->e[i];
}

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_800611D0);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_800614BC);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_800615B4);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_80061758);

EXTERN_C int func_800619F4(Obj_800619F4 *self)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (self->e[i].pad[0] == 0) {
            break;
        }
    }
    return i;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_80061A20);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_80061AAC);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_80061BF0);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_80061CC4);

EXTERN_C int func_80061E9C(void *self, int b)
{
    int found = 0;
    int i;
    for (i = func_800619F4((Obj_800619F4 *)self) - 1; i >= 0 && !found; i--) {
        if (FIELD_AT((char *)self + i * 0x94, unsigned char, 0x23F) == b) {
            found = 1;
        }
    }
    if (!found) {
        unsigned int j = 0;
        Ent_800620D8 *q = func_800620D8(self, 0);
        while (q != 0 && !found) {
            if (FIELD_AT(q, unsigned char, 0x1B) == b) {
                found = 1;
            }
            j++;
            q = func_800620D8(self, j);
        }
    }
    return found;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_80061F80);

EXTERN_C Ent_800620D8 *func_800620D8(void *self, unsigned int i)
{
    if (i < 8 && *((unsigned char *)self + i * 0x94 + 0x1DFC) != 0) {
        return (Ent_800620D8 *)((char *)self + (i * 0x94 + 0x1DE4));
    }
    return 0;
}

EXTERN_C void *func_80062118(void *self)
{
    return (char *)self + 0x1A4;
}

EXTERN_C void func_80062120(void *self, Blk_80062120 *src)
{
    FIELD_AT(self, Blk_80062120, 0x1A4) = *src;
}

EXTERN_C void *func_80062158(void *self)
{
    return self;
}

EXTERN_C void func_80062160(unsigned int *out)
{
    *out = D_800A4534.ticks / 60;
}

EXTERN_C void func_80062188(void *self)
{
    int v = FIELD_AT(self, int, 0x1C4) + (D_800A4534.ticks / 60 - FIELD_AT(self, int, 0x0));
    FIELD_AT(self, int, 0x1C4) = v;
    if (v > 360000) {
        FIELD_AT(self, int, 0x1C4) = 360000;
    }
    func_80062160((unsigned int *)self);
}

EXTERN_C void *func_800621F8(void *self)
{
    void *r = 0;
    if (FIELD_AT(self, signed char, 0xA0) != 0) {
        r = (char *)self + 0xA0;
    }
    return r;
}

EXTERN_C void func_80062214(Obj_80062214 *self)
{
    unsigned int i;

    for (i = 0; i < 0x80; i++) {
        self->a[i] = 0;
    }
}

EXTERN_C int func_80062238(void *self, unsigned int bit)
{
    return ((((signed char *)self + 0x1F9)[bit >> 3] >> (bit & 7)) ^ 1) & 1;
}

EXTERN_C void func_80062258(void *self, unsigned int i)
{
    ((unsigned char *)self + 0x1F9)[i >> 3] &= ~(1 << (i & 7));
}

EXTERN_C int func_80062280(void *self, int b)
{
    int old = FIELD_AT(self, int, 0x4);
    FIELD_AT(self, int, 0x4) = b;
    return old;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_8006228C);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_8006237C);

INCLUDE_ASM("asm/main/nonmatchings/u_8005F238", func_800624A4);

EXTERN_C void func_8006255C(void)
{
    if (D_800AE86C != 0) {
        Ent_800AE86C *p = D_800AE86C + 10;
        while (p != D_800AE86C) {
            p--;
            p->v00(2);
        }
    }
}

EXTERN_C void func_800625C0(void)
{
    Ent_800AE86C *p = D_800AE86C;
    int i = 9;
    do {
        func_80053928(p);
        p++;
    } while (--i != -1);
}
