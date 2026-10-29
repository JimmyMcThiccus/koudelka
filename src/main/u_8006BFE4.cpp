#include "common.h"
#define EXE_H_IN_u_8006BFE4
#include "shared/exe.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"
#include "game/b2/b2.h"

INCLUDE_ASM("asm/main/nonmatchings/u_8006BFE4", func_8006BFE4);

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
    SetGeomOffset(FIELD_AT(self, int, 0x114), FIELD_AT(self, int, 0x118));
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
    TransRot_32(&u, &t, (long *)&flag);
    FIELD_AT(self, int, 0x84) = t.x;
    FIELD_AT(self, int, 0x88) = t.y;
    FIELD_AT(self, int, 0x8C) = t.z;
    FIELD_AT(self, int, 0x94) = 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8006BFE4", func_8006C4EC);

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

INCLUDE_ASM("asm/main/nonmatchings/u_8006BFE4", func_8006C65C);

// func_8002D780 takes its 4-byte point by value as S_Pt2 (defined in main_a); main_b2 passes SV2_80069F74.
EXTERN_C void func_8002D780_v(void *self, SV2_80069F74 p) asm("func_8002D780");

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
        func_8002D780_v(FIELD_AT(self, void *, 0x10), pos);
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

// func_8002EEFC takes two arguments; retail passes one here and leaves $a1 as it is.
EXTERN_C void func_8002EEFC_1(void *p) asm("func_8002EEFC");

EXTERN_C void func_8006C93C(void *self)
{
    func_8002EEFC_1(self);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8006BFE4", D_80015C0C);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006BFE4", D_80015C5C);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006BFE4", D_80015C9C);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006BFE4", D_80015DBC);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006BFE4", D_80015E5C);

INCLUDE_ASM("asm/main/nonmatchings/u_8006BFE4", func_8006C95C);

EXTERN_C void func_8006C9F8(void *self, int b)
{
    char tmp[8];
    FIELD_AT(self, void *, 0) = D_80015E5C;
    if (FIELD_AT(self, int, 0x1C) == 0) {
        func_8006B7B8((void *)D_800B4ED8_p);
    }
    if (FIELD_AT(self, int, 8) != 0xCD) {
        func_800BE09C(tmp);
        func_800BE18C(tmp, (char *)D_800B4ED8_p + 0x2A0);
    }
    func_8001D024(self, b);
}

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

INCLUDE_ASM("asm/main/nonmatchings/u_8006BFE4", func_8006CAF8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006BFE4", D_80015EA0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8006BFE4", D_80015EB8);
