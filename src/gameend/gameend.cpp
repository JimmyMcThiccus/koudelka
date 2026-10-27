#include "common.h"
#include "gameend/gameend.h"

// Overlay id word, read by the EXE through ovl_header. Under -G8 a 4-byte
// const would go to .sdata; it has to be the first word of the overlay.
EXTERN_C const int D_800B6DF0 __attribute__((section(".rodata"))) = 8;

EXTERN_C const int D_80010178[];
EXTERN_C const int D_800104A8[];
EXTERN_C int D_800B4C74[];

EXTERN_C void func_80056364(BaseA *, int, int, int);
EXTERN_C void func_8005652C(BaseA *, int);
EXTERN_C void func_8005BC84(BaseB *, int, int, int);
EXTERN_C void func_8005BDA4(BaseB *, int);
EXTERN_C void func_800537C0(BaseC *);
EXTERN_C void func_800537DC(BaseC *, int);
EXTERN_C void func_8001A610(VBase *, int);
EXTERN_C int func_80053830(BaseC *);
EXTERN_C void func_80055330(int);
EXTERN_C void func_80027948();
EXTERN_C void func_8001FC78(Ev *, int, int);
EXTERN_C void *func_80056E0C(void *, int);
EXTERN_C void func_8002B174(void *, BaseB *, int);
EXTERN_C void func_80056F9C(void *, int, int);
EXTERN_C void func_80056FE0(void *);
EXTERN_C void func_8002972C(Color *, int, int, int, int);
EXTERN_C Item *func_80019F64(List *, int);
EXTERN_C void func_80028D10(Item *, Color *);
EXTERN_C void func_800198AC(Color *, int);
EXTERN_C void func_8005C088(BaseB *, int, int);
EXTERN_C void *func_8002860C(void *, const Rect &, void *, int, int);
EXTERN_C void func_80019A6C(Q *, void *, int);
EXTERN_C void func_8002DA94(int, T94 *);

// Base-class constructors and destructors take the subobject without the
// null check a pointer conversion would add.
inline void construct_b(BaseB &b, int a, int x) { func_8005BC84(&b, 0, a, x); }
inline void construct_c(BaseC &c) { func_800537C0(&c); }
inline void destruct_b(BaseB &b) { func_8005BDA4(&b, 0); }
inline void destruct_c(BaseC &c) { func_800537DC(&c, 0); }

// Converting through Holder first keeps retail's two null checks.
inline List *list_of(Holder *h) { return h; }

inline void add_to(Q *q, void *o) { func_80019A6C(q, o, q->f4); }

// GameEnd::GameEnd(int). in_chrg != 0 when constructing the complete object.
EXTERN_C GameEnd *func_800B6FEC(GameEnd *self, int in_chrg, int arg)
{
    if (in_chrg) {
        self->vb50 = self->vb64 = (VBase *)((char *)self + 0x2C4);
        VBase *v = self->vb64;
        v->vptr = D_80010178;
        v->f4 = 0;
        v->vptr = D_800104A8;
    }
    func_80056364(self, 0, 0, 1);
    construct_b(*self, 2, 0x10);
    construct_c(*self);
    self->vb50->vptr = &D_800B6F9C;
    if (!in_chrg) {
        // GCC 2.x upcast fixup: a stack copy of the virtual base's vtable
        // with the deltas of the overriders adjusted.
        VTable10 vt = D_800B6F9C;
        self->vb50->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B6F9C.e[1].delta + (adj = (char *)self - (full = (char *)self->vb50 - 0x2C4));
        vt.e[5].delta = D_800B6F9C.e[5].delta + adj;
        vt.e[6].delta = D_800B6F9C.e[6].delta + adj;
        vt.e[7].delta = D_800B6F9C.e[7].delta + adj;
        vt.e[9].delta = D_800B6F9C.e[9].delta + adj;
    }
    self->vt54 = D_800B6E14;
    self->vt58 = D_800B6DF4;
    self->vt90 = D_800B6E44;
    self->vtA4 = D_800B6F3C;
    self->vt18 = D_800B6F5C;
    self->f2A8 = arg;
    self->f2AC = 0;
    for (unsigned int i = 0; i < 3; i++)
        self->f2B0[i] = 0;
    self->f2BC = 0;
    return self;
}

EXTERN_C void func_800B7190(GameEnd *self);
INCLUDE_ASM("asm/gameend/nonmatchings/gameend", func_800B7190);

EXTERN_C void func_800B753C(GameEnd *self)
{
    self->f2A8 = 0;
    func_80055330(0);
    func_80027948();
}

EXTERN_C int func_800B7568(GameEnd *self)
{
    if (func_80053830(self))
        return 1;
    self->f2AC = func_80056E0C(operator new(0xB4), 1);
    func_8002B174(self->f2AC, self, -1);
    func_80056F9C(self->f2AC, 0x78, 0);
    func_80056FE0(self->f2AC);
    return 0;
}

EXTERN_C void func_800B75F4(GameEnd *self, unsigned char c)
{
    if (self->f6C) {
        Color col;
        func_8002972C(&col, c, c, c, 1);
        for (unsigned int i = 0; i < 3; i++) {
            Item *it = func_80019F64(list_of(self->f94), i);
            func_80028D10(it, &col);
            it->v7();
        }
        func_800198AC(&col, 2);
    }
}

EXTERN_C void func_800B76C0(GameEnd *self, int a1)
{
    if (self->f6C) {
        func_8005C088(self, a1, 1);
        add_to(self->f94, func_8002860C(operator new(0x50), Rect(0, 0, 0x80, 0xF0), self->f2B0[0], ((BaseB *)self)->f1C, D_800B4C74[0]));
        add_to(self->f94, func_8002860C(operator new(0x50), Rect(0x80, 0, 0x80, 0xF0), self->f2B0[1], ((BaseB *)self)->f1C, D_800B4C74[0]));
        add_to(self->f94, func_8002860C(operator new(0x50), Rect(0x100, 0, 0x40, 0xF0), self->f2B0[2], ((BaseB *)self)->f1C, D_800B4C74[0]));
        func_8002DA94(a1, self->f94);
    }
}

EXTERN_C int func_800B789C(GameEnd *self, Ev *e)
{
    func_8001FC78(e, 0, 0);
    if (self->f2A8 == 0 || (e->flags & 8))
        self->vt18[3].pfn((char *)self + self->vt18[3].delta);
    return 1;
}

EXTERN_C int func_800B791C(GameEnd *self, Ev *e)
{
    func_8001FC78(e, 0, 0);
    return 1;
}

// GameEnd::~GameEnd(). in_chrg bit 1: destroy the virtual base, bit 0: delete.
EXTERN_C void func_800B7944(GameEnd *self, int in_chrg)
{
    self->vt54 = D_800B6E14;
    self->vt58 = D_800B6DF4;
    self->vt90 = D_800B6E44;
    self->vtA4 = D_800B6F3C;
    self->vt18 = D_800B6F5C;
    self->vb50->vptr = &D_800B6F9C;
    if (!in_chrg) {
        VTable10 vt = D_800B6F9C;
        self->vb50->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = D_800B6F9C.e[1].delta + (adj = (char *)self - (full = (char *)self->vb50 - 0x2C4));
        vt.e[5].delta = D_800B6F9C.e[5].delta + adj;
        vt.e[6].delta = D_800B6F9C.e[6].delta + adj;
        vt.e[7].delta = D_800B6F9C.e[7].delta + adj;
        vt.e[9].delta = D_800B6F9C.e[9].delta + adj;
    }
    destruct_c(*self);
    destruct_b(*self);
    func_8005652C(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb50, 0);
    if (in_chrg & 1)
        operator delete(self);
}

// The vtables. Data is output in source order ahead of all functions, so
// these follow D_800B6DF0. Slot 0 holds the offset to the complete object.
EXTERN_C void func_8001FD00();
EXTERN_C void func_8001FD90();
EXTERN_C void func_8001FE20();
EXTERN_C void func_8001FF40();
EXTERN_C void func_800201DC();
EXTERN_C void func_800202C4();
EXTERN_C void func_800202CC();
EXTERN_C void func_800202D4();
EXTERN_C void func_80029EC0();
EXTERN_C void func_80029EC8();
EXTERN_C void func_80029F30();
EXTERN_C void func_80029FC0();
EXTERN_C void func_8002A004();
EXTERN_C void func_8002A09C();
EXTERN_C void func_8002A0D0();
EXTERN_C void func_8002A118();
EXTERN_C void func_8002A168();
EXTERN_C void func_8002A1BC();
EXTERN_C void func_8002A210();
EXTERN_C void func_8002A37C();
EXTERN_C void func_8002A400();
EXTERN_C void func_8002A484();
EXTERN_C void func_8002A4C8();
EXTERN_C void func_8002A55C();
EXTERN_C void func_8002A65C();
EXTERN_C void func_8002A698();
EXTERN_C void func_8002A728();
EXTERN_C void func_8002A7B8();
EXTERN_C void func_8002A864();
EXTERN_C void func_8002A910();
EXTERN_C void func_8002A9BC();
EXTERN_C void func_8002AA8C();
EXTERN_C void func_8002AB5C();
EXTERN_C void func_8002AC2C();
EXTERN_C void func_80053848();
EXTERN_C void func_80054CE4();
EXTERN_C void func_80055020();
EXTERN_C void func_80056B3C();
EXTERN_C void func_80056B44();
EXTERN_C void func_80056D60();
EXTERN_C void func_80056D9C();
EXTERN_C void func_8005BF04();
EXTERN_C void func_8005BF50();
EXTERN_C void func_8005BFA4();
EXTERN_C void func_8005BFE4();
EXTERN_C void func_8005C238();

EXTERN_C const VEntry D_800B6DF4[4] = {
    { -0x58, 0, 0 },
    { -0x58, 0, (void (*)(void *))func_800B7944 },
    { -0x58, 0, (void (*)(void *))func_80056B3C },
    { -0x58, 0, (void (*)(void *))func_80056B44 },
};

EXTERN_C const VEntry D_800B6E14[6] = {
    { -0x50, 0, 0 },
    { -0x50, 0, (void (*)(void *))func_800B789C },
    { -0x50, 0, (void (*)(void *))func_800B791C },
    { 0, 0, (void (*)(void *))func_800202C4 },
    { 0, 0, (void (*)(void *))func_800202CC },
    { 0, 0, (void (*)(void *))func_800202D4 },
};

EXTERN_C const VEntry D_800B6E44[31] = {
    { -0x64, 0, 0 },
    { 0, 0, (void (*)(void *))func_8005C238 },
    { 0, 0, (void (*)(void *))func_8002A168 },
    { 0, 0, (void (*)(void *))func_8002A1BC },
    { 0, 0, (void (*)(void *))func_8002A210 },
    { 0, 0, (void (*)(void *))func_8005BFA4 },
    { 0, 0, (void (*)(void *))func_8002A37C },
    { 0, 0, (void (*)(void *))func_8002A400 },
    { 0, 0, (void (*)(void *))func_8002A4C8 },
    { 0, 0, (void (*)(void *))func_8002A55C },
    { 0, 0, (void (*)(void *))func_80029EC8 },
    { 0, 0, (void (*)(void *))func_80029F30 },
    { 0, 0, (void (*)(void *))func_80029FC0 },
    { 0, 0, (void (*)(void *))func_8002A004 },
    { -0x64, 0, (void (*)(void *))func_800B76C0 },
    { 0, 0, (void (*)(void *))func_8005BFE4 },
    { 0, 0, (void (*)(void *))func_8002A65C },
    { 0, 0, (void (*)(void *))func_8002A698 },
    { 0, 0, (void (*)(void *))func_80029EC0 },
    { 0, 0, (void (*)(void *))func_8002A09C },
    { 0, 0, (void (*)(void *))func_8002A0D0 },
    { 0, 0, (void (*)(void *))func_8002A728 },
    { 0, 0, (void (*)(void *))func_8002A7B8 },
    { 0, 0, (void (*)(void *))func_8002A864 },
    { 0, 0, (void (*)(void *))func_8002A910 },
    { 0, 0, (void (*)(void *))func_8002A484 },
    { 0, 0, (void (*)(void *))func_8005BF50 },
    { 0, 0, (void (*)(void *))func_8002A118 },
    { 0, 0, (void (*)(void *))func_8002AC2C },
    { -0x64, 0, (void (*)(void *))func_800B75F4 },
    { 0, 0, (void (*)(void *))func_8005BF04 },
};

EXTERN_C const VEntry D_800B6F3C[4] = {
    { -0x9C, 0, 0 },
    { -0x9C, 0, (void (*)(void *))func_800B7944 },
    { -0x9C, 0, (void (*)(void *))func_800B7568 },
    { 0, 0, (void (*)(void *))func_80053848 },
};

EXTERN_C const VEntry D_800B6F5C[8] = {
    { 0, 0, 0 },
    { 0, 0, (void (*)(void *))func_800B7944 },
    { 0, 0, (void (*)(void *))func_800B7190 },
    { 0, 0, (void (*)(void *))func_800B753C },
    { 0, 0, (void (*)(void *))func_80055020 },
    { 0, 0, (void (*)(void *))func_80054CE4 },
    { 0, 0, (void (*)(void *))func_80056D60 },
    { 0, 0, (void (*)(void *))func_80056D9C },
};

EXTERN_C const VTable10 D_800B6F9C = { {
    { -0x2C4, 0, 0 },
    { -0x2C4, 0, (void (*)(void *))func_800B7944 },
    { 0, 0, (void (*)(void *))func_8001FD00 },
    { 0, 0, (void (*)(void *))func_8001FD90 },
    { 0, 0, (void (*)(void *))func_8001FE20 },
    { -0x260, 0, (void (*)(void *))func_8002A9BC },
    { -0x274, 0, (void (*)(void *))func_800201DC },
    { -0x260, 0, (void (*)(void *))func_8002AA8C },
    { 0, 0, (void (*)(void *))func_8001FF40 },
    { -0x260, 0, (void (*)(void *))func_8002AB5C },
} };
