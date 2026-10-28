#include "common.h"
#include "effect/effect.h"

EXTERN_C void func_8001A610(IdNode *self, int flags);

EXTERN_C void func_800D67CC(IdNode *self, int flags)
{
    self->vptr = D_800D5DB0;
    func_8001A610(self, flags);
}

EXTERN_C IdNode *func_800D67F4(IdNode *self, short id)
{
    IdNode *found = 0;
    if (self->id == id)
        return self;
    if (self->next)
        found = func_800D67F4(self->next, id);
    return found;
}

EXTERN_C int func_800D6848(IdNode *self)
{
    return self->id;
}

EXTERN_C IdNode *func_800D6854(IdNode *self, short id)
{
    self->vptr = D_80010178;
    self->next = 0;
    self->vptr = D_800D5DB0;
    self->id = id;
    return self;
}

EXTERN_C void func_800D687C(Cond *self, int flags)
{
    self->vptr = D_800D5F20;
    if (flags & 1)
        operator delete(self);
}

EXTERN_C void func_800D68B0(CondMin *self, int flags)
{
    self->vptr = D_800D5EC8;
    func_800D687C(self, flags);
}

EXTERN_C int func_800D68D8(CondMin *self, short value)
{
    return value >= self->min;
}

EXTERN_C void func_800D68F0(Cond *self, int flags)
{
    self->vptr = D_800D5E70;
    func_800D687C(self, flags);
}

EXTERN_C int func_800D6918(Cond *self)
{
    return FIELD_AT(self->owner, short, 0x10) != 0;
}

EXTERN_C void func_800D692C(Cond *self, int flags)
{
    self->vptr = D_800D5E18;
    func_800D687C(self, flags);
}

EXTERN_C int func_800D6954(Cond *self)
{
    return FIELD_AT(self->owner, short, 0x10) == 2;
}

EXTERN_C void func_800D6970(CondList *self, int flags)
{
    self->vptr = D_800D5DC0;
    func_80019920(self->ref.list, 0);
    func_800D687C(self, flags);
}

EXTERN_C void func_800D69C0(CondList *self, CondEntry *src)
{
    CondEntry *entry = new CondEntry(*src);
    List *l = list_of(&self->ref);
    func_80019A6C(l, entry, l->count);
}

EXTERN_C void func_800D6A8C(ListRef *ref);

EXTERN_C void func_800D6A38(CondList *self)
{
    func_800D6A8C(&self->ref);
}

EXTERN_C CondEntry *func_800D6A58(CondList *self, int index)
{
    return (CondEntry *)func_80019F64(list_of(&self->ref), index);
}

EXTERN_C void func_800D6A8C(ListRef *ref)
{
    int i;
    while ((i = list_of(ref)->count) != 0) {
        i--;
        delete (CondEntry *)func_80019F64(list_of(ref), i);
        func_80019C68(list_of(ref), i);
    }
}

EXTERN_C int func_800D6B0C(CondList *self)
{
    return list_of(&self->ref)->count;
}

EXTERN_C int func_800D6B2C(Cond *self)
{
    return 1;
}

EXTERN_C int func_800D6B34(Cond *self)
{
    return 0;
}

EXTERN_C CondList *func_800D6B3C(CondList *self, short id, void *owner)
{
    self->vptr = D_800D5F20;
    self->id = id;
    self->owner = owner;
    self->vptr = D_800D5DC0;
    self->ref.list = &self->list;
    func_800198E0(&self->list, 0x10, 0);
    return self;
}

EXTERN_C Cond *func_800D6B94(Cond *self, short id, void *owner)
{
    self->vptr = D_800D5F20;
    self->owner = owner;
    self->id = id;
    self->vptr = D_800D5E18;
    return self;
}

EXTERN_C Cond *func_800D6BBC(Cond *self, short id, void *owner)
{
    self->vptr = D_800D5F20;
    self->owner = owner;
    self->id = id;
    self->vptr = D_800D5E70;
    return self;
}

EXTERN_C int func_800D6BE4(CondMin *self)
{
    return self->min;
}

EXTERN_C void func_800D6BF0(CondMin *self, CondMin *other)
{
    self->min = other->min;
}

EXTERN_C CondMin *func_800D6BFC(CondMin *self, short id, short min, void *owner)
{
    self->vptr = D_800D5F20;
    self->owner = owner;
    self->id = id;
    self->vptr = D_800D5EC8;
    self->min = min;
    return self;
}

EXTERN_C int func_800D6C28(Cond *self)
{
    return self->id;
}

EXTERN_C int func_800D6C34(Cond *self)
{
    return 0;
}

EXTERN_C int func_800D6C3C(Cond *self)
{
    return 0;
}

EXTERN_C int func_800D6C44(Cond *self)
{
    return 0;
}

EXTERN_C void func_800D6C4C(Cond *self)
{
}

EXTERN_C void func_800D6C54(Cond *self)
{
}

EXTERN_C void func_800D6C5C(Cond *self)
{
}

EXTERN_C int func_800D6C64(Cond *self)
{
    return 0;
}

EXTERN_C void *func_800D6C6C(Cond *self)
{
    return self->owner;
}

EXTERN_C Cond *func_800D6C78(Cond *self, short id, void *owner)
{
    self->vptr = D_800D5F20;
    self->owner = owner;
    self->id = id;
    return self;
}

EXTERN_C int D_80011A44[];
EXTERN_C int D_80011AAC[];
EXTERN_C int D_80011B14[];
EXTERN_C int D_80011D04[];
EXTERN_C int D_80011D6C[];
EXTERN_C int D_80011E8C[];
EXTERN_C int D_80011EF4[];

struct P_800D6C94 {
    unsigned char tag[3], len;
    unsigned char r0, g0, b0, code;
    int pad[8];
};

struct S_800D6C94 {
    unsigned int rgbc;
    int uv[4];
    P_800D6C94 poly[2];
};

struct C_800D6C94 {
    int *vt0;
    int f4;
    int *vt8;
    SVec4 v;
    SVec4 arr[4];
    S_800D6C94 spr;
    short s98, s9A, s9C, s9E;
    SVec4 vA0;
};

inline void vec4z_800D6C94(SVec4 *v) { v->x = 0; v->y = 0; v->z = 0; v->w = 0; }

inline void spr_init_800D6C94(S_800D6C94 *s)
{
    int n;
    P_800D6C94 *p;
    s->rgbc = 0x2C808080;
    n = 3;
    do {
        n--;
    } while (n != -1);
    int m;
    p = s->poly;
    m = 1;
    do {
        p->len = 9;
        p->code = 0x2C;
        p++;
        m--;
    } while (m != -1);
}

EXTERN_C C_800D6C94 *func_800D6C94(C_800D6C94 *self)
{
    int n;
    SVec4 *a;
    self->vt0 = D_80010178;
    self->vt8 = D_80011A44;
    self->f4 = 0;
    vec4z_800D6C94(&self->v);
    self->vt8 = D_80011AAC;
    self->vt0 = D_80011B14;
    a = self->arr;
    n = 3;
    do {
        vec4z_800D6C94(a);
        a++;
        n--;
    } while (n != -1);
    self->vt8 = D_80011D04;
    self->vt0 = D_80011D6C;
    spr_init_800D6C94(&self->spr);
    self->vt8 = D_80011E8C;
    self->vt0 = D_80011EF4;
    self->vt8 = D_800D5FD0;
    self->vt0 = D_800D5F78;
    vec4z_800D6C94(&self->vA0);
    ((unsigned char *)&self->spr.rgbc)[3] = 0x2C;
    self->spr.poly[0].len = 9;
    self->spr.poly[0].code = 0x2C;
    self->spr.poly[1].len = 9;
    self->spr.poly[1].code = 0x2C;
    self->s98 = 1;
    self->s9C = 0;
    self->s9A = 0;
    return self;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D6DE8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7170);

struct S_800D7524_Scratch {
    unsigned short uv;
    volatile unsigned short tpage;
    volatile unsigned short clut;
    short pad[5];
};
#define SCR_800D7524 (*(S_800D7524_Scratch *)&D_1F800000)

struct S_800D7524_UV {
    unsigned char u, v;
    unsigned short w;
};

EXTERN_C char *func_800D7524(char *self, char *src, int *out)
{
    int i;
    unsigned short uv;
    unsigned char u, v;
    char *s;
    S_800D7524_UV *d;
    unsigned short tp;
    i = 0;
    *out = (signed char)src[1];
    d = (S_800D7524_UV *)(self + 0x38);
    uv = SCR_800D7524.uv;
    u = uv;
    v = uv >> 8;
    s = src;
    FIELD_AT(self, SVec4, 0xC) = FIELD_AT(src, SVec4, 0x4);
    FIELD_AT(self, Color, 0x34) = FIELD_AT(src, Color, 0x38);
    while (1) {
        unsigned short t;
        if (!(i < 4))
            break;
        i++;
        t = *(unsigned short *)(s + 0x30);
        d->u = t;
        d->u += u;
        s += 2;
        d->v = (t >> 8) + v;
        d++;
    }
    tp = SCR_800D7524.tpage;
    ((S_800D7524_UV *)(self + 0x38))[0].w = SCR_800D7524.clut;
    ((S_800D7524_UV *)(self + 0x38))[1].w = tp;
    return src + 0x3C;
}

#define gte_ldv0_800D75D4(r0) __asm__ volatile("lwc2 $0, %0\n\tlwc2 $1, %1" : : "m"(((int *)(r0))[0]), "m"(((int *)(r0))[1]))
#define gte_rtps_800D75D4() __asm__ volatile("nop\n\tnop\n\t.word 0x4A180001")
#define gte_mfsxy2_800D75D4(r0) __asm__ volatile("mfc2 %0, $14\n\tnop" : "=r"(r0))
#define gte_mfsz3_800D75D4(r0) __asm__ volatile("mfc2 %0, $19\n\tnop" : "=r"(r0))

struct Tag_800D75D4 {
    unsigned addr : 24;
    unsigned len : 8;
};

struct FT4_800D75D4 {
    Tag_800D75D4 tag;
    unsigned int rgbc;
    short x0, y0;
    unsigned int uv0;
    short x1, y1;
    unsigned int uv1;
    short x2, y2;
    unsigned int uv2;
    short x3, y3;
    unsigned int uv3;
};

/* Tag_800DF0C4, OT_800DF0C4, D_800B4CF0 and D_800B4D00: copied verbatim from src/effect/effect.cpp
   (func_800DF0C4) for a standalone build; drop them when pasting into the unit. */
struct Tag_800DF0C4 {
    unsigned addr : 24;
    unsigned len : 8;
};

struct OT_800DF0C4 {
    char pad[0x10];
    unsigned int size;
    Tag_800DF0C4 *ot;
};

struct Head_800D75D4 {
    char pad[0x34];
};

struct Tex_800D75D4 {
    unsigned int rgbc;
    unsigned int uv[4];
};

struct Obj_800D75D4 : Head_800D75D4, Tex_800D75D4 {
    FT4_800D75D4 prim[2];
    short scale, a, b, c;
    SVec4 pos;
};

EXTERN_C int D_800B4CF0[];
EXTERN_C OT_800DF0C4 *D_800B4D00[];
EXTERN_C int func_800260A4(int a);
EXTERN_C int func_80026014(int a);

inline int add_800D75D4(unsigned int o, OT_800DF0C4 *d, FT4_800D75D4 *p)
{
    if (o && o < d->size) {
        p->tag.addr = *(unsigned int *)&d->ot[o];
        *(unsigned int *)&d->ot[o] = (unsigned int)p & 0x00FFFFFF;
        return 1;
    }
    return 0;
}

EXTERN_C int func_800D75D4(Obj_800D75D4 *self)
{
    FT4_800D75D4 *p;
    int sxy, sy, sz;
    int dx1, dy1, dx2, dy2;
    Tex_800D75D4 *t;
    unsigned int o;
    OT_800DF0C4 *d;
    gte_ldv0_800D75D4(&self->pos);
    gte_rtps_800D75D4();
    p = &self->prim[D_800B4CF0[0]];
    p->rgbc = self->rgbc;
    gte_mfsxy2_800D75D4(sxy);
    sy = sxy >> 16;
    gte_mfsz3_800D75D4(sz);
    if (sz <= 0)
        return 0;
    dx1 = FIELD_AT((void *)D_800E583C[0], int, 0x11C) * (short)((self->scale * func_800260A4(self->c + self->b + self->a) + 0x800) >> 12) / sz;
    dy1 = FIELD_AT((void *)D_800E583C[0], int, 0x11C) * (short)((self->scale * func_80026014(self->c + self->b + self->a) + 0x800) >> 12) / sz;
    dx2 = FIELD_AT((void *)D_800E583C[0], int, 0x11C) * (short)((self->scale * func_800260A4(self->c + self->b - (self->a - 0x1000)) + 0x800) >> 12) / sz;
    dy2 = FIELD_AT((void *)D_800E583C[0], int, 0x11C) * (short)((self->scale * func_80026014(self->c + self->b - (self->a - 0x1000)) + 0x800) >> 12) / sz;
    p->x0 = sxy + dx1;
    p->x3 = sxy - dx1;
    p->y0 = sy + dy1;
    p->y3 = sy - dy1;
    p->x1 = sxy + dx2;
    p->x2 = sxy - dx2;
    p->y1 = sy + dy2;
    p->y2 = sy - dy2;
    t = self;
    {
        unsigned int a = t->uv[0], b = t->uv[1], c = t->uv[2], e = t->uv[3];
        p->uv0 = a;
        p->uv1 = b;
        p->uv2 = c;
        p->uv3 = e;
    }
    return add_800D75D4(sz >> 2, D_800B4D00[0], p);
}

EXTERN_C int func_800D7958(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C void func_800D7964(int value)
{
    D_800E583C[0] = value;
}

EXTERN_C int D_80011E8C[];
EXTERN_C int D_80011EF4[];
EXTERN_C int D_80011D04[];
EXTERN_C int D_80011D6C[];
EXTERN_C int D_80011AAC[];
EXTERN_C int D_80011B14[];
EXTERN_C void func_800198AC(void *, int);

EXTERN_C void func_800D7970(void *self, int flags)
{
    FIELD_AT(self, int *, 0x8) = D_800D5FD0;
    FIELD_AT(self, int *, 0x0) = D_800D5F78;
    FIELD_AT(self, int *, 0x8) = D_80011E8C;
    FIELD_AT(self, int *, 0x0) = D_80011EF4;
    FIELD_AT(self, int *, 0x8) = D_80011D04;
    FIELD_AT(self, int *, 0x0) = D_80011D6C;
    FIELD_AT(self, int *, 0x8) = D_80011AAC;
    FIELD_AT(self, int *, 0x0) = D_80011B14;
    func_800198AC((char *)self + 0x8, 0);
    func_8001A610((IdNode *)self, flags);
}

EXTERN_C char *func_800D7A14(RandVal *self, char *src)
{
    self->base = FIELD_AT(src, short, 0x4);
    self->step = FIELD_AT(src, short, 0x6);
    self->range = FIELD_AT(src, short, 0x8);
    self->spread = FIELD_AT(src, short, 0xA);
    return src + 1;
}

EXTERN_C int rand(void);

EXTERN_C void func_800D7A4C(RandVal *self, short *base, short *phase)
{
    int r = 0;
    self->phase += self->step;
    if (self->range != 0)
        r = rand() / (0x8000 / self->range) - (self->range >> 1);
    if (self->range > 0x1000)
        self->range -= 0x1000;
    else if (self->range < -0x1000)
        self->range += 0x1000;
    *base = self->base;
    *phase = self->phase + r;
}

EXTERN_C void func_800D7B64(RandVal *self)
{
    self->phase = 0;
}

EXTERN_C int rand(void);

EXTERN_C int func_800D7B6C(RandVal *self)
{
    if (self->spread == 0)
        return self->base;
    return self->base + rand() / (0x8000 / self->spread) - (self->spread >> 1);
}

EXTERN_C RandVal *func_800D7C2C(RandVal *self)
{
    self->vptr = D_800D6038;
    self->base = 0;
    self->step = 0;
    self->range = 0;
    self->phase = 0;
    return self;
}

EXTERN_C void func_800D7C50(Key *self, int flags)
{
    self->vptr = D_800D6188;
    if (flags & 1)
        operator delete(self);
}

EXTERN_C char *func_800D7C84(Key *self, char *src)
{
    self->id = FIELD_AT(src, short, 0x2);
    self->s2 = FIELD_AT(src, short, 0x14);
    self->w4 = FIELD_AT(src, int, 0x18);
    return src + 0x1C;
}

EXTERN_C void func_8003A754(void *m, int scale);
EXTERN_C void func_8003A7FC(void *m, SVec4 *rot);
EXTERN_C void ApplyMatrixLV(void *m, Vec4 *v, Vec4 *out);
EXTERN_C int rand(void);

struct Mat_800D7CB0 {
    int m[8];
};

EXTERN_C Vec4 func_800D7CB0(Key *self, Vec4 *v)
{
    Vec4 r = *v;
    int half;
    SVec4 rot;
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    rot.w = 0;
    Mat_800D7CB0 m;
    func_8003A754(&m, 0x1000);
    half = (self->s2 / 2 << 12) / 360;
    if (self->s2) {
        rot.x = ((rand() / (0x8000 / self->s2)) << 12) / 360 - half;
        rot.y = ((rand() / (0x8000 / self->s2)) << 12) / 360 - half;
        rot.z = ((rand() / (0x8000 / self->s2)) << 12) / 360 - half;
        func_8003A7FC(&m, &rot);
        ApplyMatrixLV(&m, v, &r);
    }
    return r;
}

EXTERN_C void func_800D7F94(void *self)
{
    Vec4 z(0, 0, 0, 0);
    FIELD_AT(self, Vec4, 0x0) = z;
    FIELD_AT(self, Vec4, 0x10) = z;
    FIELD_AT(self, Vec4, 0x20) = z;
    FIELD_AT(self, Vec4, 0x40) = z;
    FIELD_AT(self, Vec4, 0x50) = z;
}

EXTERN_C void func_800D8050(KeyVec *self, int flags)
{
    self->vptr = D_800D6160;
    func_800D7C50(self, flags);
}

EXTERN_C char *func_800D8078(KeyVec *self, char *src)
{
    Vec4 v = FIELD_AT(src, Vec4, 0x4);
    self->v = v;
    return func_800D7C84(self, src);
}

EXTERN_C Vec4 func_800D9698(Vec4 *a, Vec4 *b);
EXTERN_C Vec4 func_800D7CB0(Key *self, Vec4 *v);
EXTERN_C int SquareRoot0(int a);
EXTERN_C void func_8003A754(void *m, int scale);
EXTERN_C void func_8003A7FC(void *m, SVec4 *rot);
EXTERN_C void ApplyMatrixLV(void *m, Vec4 *v, Vec4 *out);

struct Mat_800D80D8 {
    int m[8];

};

EXTERN_C Vec4 func_800D80D8(KeyVec2 *self, Vec4 *p)
{
    Vec4 d;
    vec4_zero(&d);
    Vec4 v(0, 0, 0, 0);
    Mat_800D80D8 m;
    func_8003A754(&m, 0x1000);
    int len = 1;
    int flag = (unsigned short)self->v.w & 0x8000;
    v = self->v;
    if (flag && self->extra) {
        func_8003A7FC(&m, (SVec4 *)(self->extra + 0x2C));
        ApplyMatrixLV(&m, &v, &v);
    }
    if (v.x || v.y || v.z)
        len = SquareRoot0(v.x * v.x + v.y * v.y + v.z * v.z);
    d.x = v.x * self->w4 / len;
    d.y = v.y * self->w4 / len;
    d.z = v.z * self->w4 / len;
    Vec4 r = func_800D9698(&func_800D7CB0(self, &d), p);
    return r;
}

EXTERN_C void func_800D8354(KeyInt *self, int flags)
{
    self->vptr = D_800D6138;
    func_800D7C50(self, flags);
}

EXTERN_C Vec4 func_800D9658(Vec4 *a, Vec4 *b);
EXTERN_C Vec4 func_800D9698(Vec4 *a, Vec4 *b);
EXTERN_C Vec4 func_800D7CB0(Key *self, Vec4 *v);
EXTERN_C Vec4 func_8003A150(int h, int n);
EXTERN_C int SquareRoot0(int a);

EXTERN_C Vec4 func_800D837C(KeyInt *self, Vec4 *p)
{
    Vec4 z;
    vec4_zero(&z);
    Vec4 t = func_8003A150(self->value, (int)&z);
    Vec4 d;
    int len;
    d = func_800D9658(p, &t);
    len = 1;
    if (d.x || d.y || d.z)
        len = SquareRoot0(d.x * d.x + d.y * d.y + d.z * d.z);
    d.x = d.x * self->w4 / len;
    d.y = d.y * self->w4 / len;
    d.z = d.z * self->w4 / len;
    Vec4 r = func_800D9698(&func_800D7CB0(self, &d), p);
    return r;
}

EXTERN_C void func_800D85AC(KeyInt *self, int flags)
{
    self->vptr = D_800D6110;
    func_800D7C50(self, flags);
}

EXTERN_C Vec4 func_800D9658(Vec4 *a, Vec4 *b);
EXTERN_C Vec4 func_800D9698(Vec4 *a, Vec4 *b);
EXTERN_C Vec4 func_800D7CB0(Key *self, Vec4 *v);
EXTERN_C Vec4 func_8003A150(int h, int n);
EXTERN_C int SquareRoot0(int a);

EXTERN_C Vec4 func_800D85D4(KeyInt *self, Vec4 *p)
{
    Vec4 z;
    vec4_zero(&z);
    Vec4 t = func_8003A150(self->value, (int)&z);
    Vec4 d;
    int len;
    d = func_800D9658(p, &t);
    len = 1;
    if (d.x || d.y || d.z)
        len = SquareRoot0(d.x * d.x + d.y * d.y + d.z * d.z);
    d.x = d.x * self->w4 / len;
    d.y = d.y * self->w4 / len;
    d.z = d.z * self->w4 / len;
    Vec4 r = func_800D9698(&func_800D7CB0(self, &d), p);
    return r;
}

EXTERN_C void func_800D8804(KeyInt *self, int flags)
{
    self->vptr = D_800D60E8;
    func_800D7C50(self, flags);
}

EXTERN_C Vec4 func_800D9658(Vec4 *a, Vec4 *b);
EXTERN_C Vec4 func_800D9698(Vec4 *a, Vec4 *b);
EXTERN_C Vec4 func_800D7CB0(Key *self, Vec4 *v);
EXTERN_C int SquareRoot0(int a);

EXTERN_C Vec4 func_800D882C(KeyInt *self, Vec4 *p)
{
    Vec4 d;
    int len;
    d = func_800D9658(p, &p[3]);
    len = 1;
    if (d.x || d.y || d.z)
        len = SquareRoot0(d.x * d.x + d.y * d.y + d.z * d.z);
    if (len == 0)
        len = 1;
    d.x = d.x * self->w4 / len;
    d.y = d.y * self->w4 / len;
    d.z = d.z * self->w4 / len;
    Vec4 r = func_800D9698(&func_800D7CB0(self, &d), p);
    return r;
}

EXTERN_C void func_800D8A44(KeyInt *self, int flags)
{
    self->vptr = D_800D60C0;
    func_800D7C50(self, flags);
}

EXTERN_C Vec4 func_800D9658(Vec4 *a, Vec4 *b);
EXTERN_C Vec4 func_800D9698(Vec4 *a, Vec4 *b);
EXTERN_C Vec4 func_800D7CB0(Key *self, Vec4 *v);
EXTERN_C int SquareRoot0(int a);

EXTERN_C Vec4 func_800D8A6C(KeyInt *self, Vec4 *p)
{
    Vec4 d;
    int len;
    d = func_800D9658(&p[1], p);
    Vec4 e = d;
    len = 1;
    if (d.x || d.y || d.z)
        len = SquareRoot0(d.x * d.x + d.y * d.y + d.z * d.z);
    d.x = d.x * self->w4 / len;
    d.y = d.y * self->w4 / len;
    d.z = d.z * self->w4 / len;
    e.x = (e.x * self->w4 - d.x * len) / self->w4;
    e.y = (e.y * self->w4 - d.y * len) / self->w4;
    e.z = (e.z * self->w4 - d.z * len) / self->w4;
    Vec4 r = func_800D9698(&func_800D9698(&func_800D7CB0(self, &d), p), &e);
    return r;
}

EXTERN_C void func_800D8DC0(KeyInt *self, int flags)
{
    self->vptr = D_800D6098;
    func_800D7C50(self, flags);
}

EXTERN_C Vec4 func_800D9658(Vec4 *a, Vec4 *b);
EXTERN_C Vec4 func_800D9698(Vec4 *a, Vec4 *b);
EXTERN_C Vec4 func_800D7CB0(Key *self, Vec4 *v);
EXTERN_C int SquareRoot0(int a);

EXTERN_C Vec4 func_800D8DE8(KeyInt *self, Vec4 *p)
{
    Vec4 d;
    int len;
    d = func_800D9658(&p[3], p);
    len = 1;
    if (d.x || d.y || d.z)
        len = SquareRoot0(d.x * d.x + d.y * d.y + d.z * d.z);
    d.x = d.x * self->w4 / len;
    d.y = d.y * self->w4 / len;
    d.z = d.z * self->w4 / len;
    Vec4 r = func_800D9698(&func_800D7CB0(self, &d), p);
    return r;
}

EXTERN_C void func_800D8FF0(KeyVec *self, int flags)
{
    self->vptr = D_800D6070;
    func_800D8050(self, flags);
}

EXTERN_C Vec4 func_800D9698(Vec4 *a, Vec4 *b);
EXTERN_C int SquareRoot0(int a);
EXTERN_C void func_8003A754(void *m, int scale);
EXTERN_C void func_8003A7FC(void *m, SVec4 *rot);
EXTERN_C void ApplyMatrixLV(void *m, Vec4 *v, Vec4 *out);
EXTERN_C int rand(void);

struct Mat_800D9018 {
    int m[8];
};

EXTERN_C Vec4 func_800D9018(KeyVec *self, Vec4 *p)
{
    Vec4 d;
    int len;
    int half;
    vec4_zero(&d);
    len = 1;
    if (self->v.x || self->v.y || self->v.z)
        len = SquareRoot0(self->v.x * self->v.x + self->v.y * self->v.y + self->v.z * self->v.z);
    d.x = self->v.x * self->w4 / len;
    d.y = self->v.y * self->w4 / len;
    d.z = self->v.z * self->w4 / len;
    SVec4 rot;
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    rot.w = 0;
    Mat_800D9018 m;
    func_8003A754(&m, 0x1000);
    half = (self->s2 / 2 << 12) / 360;
    if (self->s2) {
        rot.x = 0;
        rot.y = ((rand() / (0x8000 / self->s2)) << 12) / 360 - half;
        rot.z = 0;
        func_8003A7FC(&m, &rot);
        ApplyMatrixLV(&m, &d, &d);
    }
    Vec4 r = func_800D9698(&d, p);
    return r;
}

EXTERN_C void func_800D9324(KeyVec *self, int flags)
{
    self->vptr = D_800D6048;
    func_800D8050(self, flags);
}

EXTERN_C Vec4 func_800D9698(Vec4 *a, Vec4 *b);
EXTERN_C int SquareRoot0(int a);
EXTERN_C void func_8003A754(void *m, int scale);
EXTERN_C void func_8003A7FC(void *m, SVec4 *rot);
EXTERN_C void ApplyMatrixLV(void *m, Vec4 *v, Vec4 *out);
EXTERN_C int rand(void);

struct Mat_800D934C {
    int m[8];
};

EXTERN_C Vec4 func_800D934C(KeyVec *self, Vec4 *p)
{
    Vec4 d;
    int len;
    int half;
    vec4_zero(&d);
    len = 1;
    if (self->v.x || self->v.y || self->v.z)
        len = SquareRoot0(self->v.x * self->v.x + self->v.y * self->v.y + self->v.z * self->v.z);
    d.x = self->v.x * self->w4 / len;
    d.y = self->v.y * self->w4 / len;
    d.z = self->v.z * self->w4 / len;
    SVec4 rot;
    rot.x = 0;
    rot.y = 0;
    rot.z = 0;
    rot.w = 0;
    Mat_800D934C m;
    func_8003A754(&m, 0x1000);
    half = (self->s2 / 2 << 12) / 360;
    if (self->s2) {
        rot.x = 0;
        rot.y = 0;
        rot.z = ((rand() / (0x8000 / self->s2)) << 12) / 360 - half;
        func_8003A7FC(&m, &rot);
        ApplyMatrixLV(&m, &d, &d);
    }
    Vec4 r = func_800D9698(&d, p);
    return r;
}

EXTERN_C Vec4 func_800D9658(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x - b->x, a->y - b->y, a->z - b->z, a->w);
}

EXTERN_C Vec4 func_800D9698(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x + b->x, a->y + b->y, a->z + b->z, a->w);
}

EXTERN_C KeyVec *func_800D96D8(KeyVec *self, short id)
{
    keyvec_init(self, id);
    self->vptr = D_800D6048;
    return self;
}

EXTERN_C KeyVec *func_800D9724(KeyVec *self, short id)
{
    keyvec_init(self, id);
    self->vptr = D_800D6070;
    return self;
}

EXTERN_C KeyInt *func_800D9770(KeyInt *self, short id)
{
    key_init(self, id);
    self->vptr = D_800D6098;
    return self;
}

EXTERN_C KeyInt *func_800D979C(KeyInt *self, short id)
{
    key_init(self, id);
    self->vptr = D_800D60C0;
    return self;
}

EXTERN_C KeyInt *func_800D97C8(KeyInt *self, short id)
{
    key_init(self, id);
    self->vptr = D_800D60E8;
    return self;
}

EXTERN_C void func_800D97F4(KeyInt *self, int value)
{
    self->value = value;
}

EXTERN_C KeyInt *func_800D97FC(KeyInt *self, short id)
{
    key_init(self, id);
    self->vptr = D_800D6110;
    self->value = 0;
    return self;
}

EXTERN_C void func_800D982C(KeyInt *self, int value)
{
    self->value = value;
}

EXTERN_C KeyInt *func_800D9834(KeyInt *self, short id)
{
    key_init(self, id);
    self->vptr = D_800D6138;
    self->value = 0;
    return self;
}

EXTERN_C void func_800D9864(KeyVec2 *self, int value)
{
    self->extra = value;
}

EXTERN_C void func_800D986C(KeyVec *self, KeyVec *other)
{
    self->v = other->v;
    key_copy(self, other);
}

EXTERN_C KeyVec *func_800D98A4(KeyVec *self, short id)
{
    keyvec_init(self, id);
    return self;
}

EXTERN_C int func_800D98E4(Key *self)
{
    return self->id;
}

EXTERN_C void func_800D98F0(Key *self, Key *other)
{
    key_copy(self, other);
}

EXTERN_C Key *func_800D9908(Key *self, short id)
{
    key_init(self, id);
    return self;
}

EXTERN_C void func_8001E40C(void *self, void *a, int b, int c, int d);
EXTERN_C void func_80051564(void *self);
EXTERN_C void func_800756F8(void *self);
EXTERN_C void *func_800E4298(void *self);
EXTERN_C int D_800D6228[];
EXTERN_C int D_800D6240[];
EXTERN_C int D_800D6268[];
EXTERN_C int D_800D6280[];

EXTERN_C void *func_800D9928(void *self, void *a)
{
    int j;
    int i;
    int k;
    func_8001E40C(self, a, 2, 0x1000, 0);
    func_80051564((char *)self + 0xF8);
    func_800756F8((char *)self + 0x100);
    FIELD_AT(self, int *, 0x8C) = D_800D6228;
    FIELD_AT(self, int *, 0xF8) = D_800D6268;
    FIELD_AT(self, int *, 0x100) = D_800D6280;
    FIELD_AT(self, int *, 0x0) = D_800D6240;
    func_800E4298((char *)self + 0x134);
    FIELD_AT(self, int, 0x140) = -1;
    FIELD_AT(self, int, 0x13C) = 0;
    FIELD_AT(self, short, 0x148) = 0;
    vec4_zero(&FIELD_AT(self, Vec4, 0x16C));
    FIELD_AT(self, short, 0x166) = 2;
    FIELD_AT(self, int, 0x130) = 0;
    FIELD_AT(self, int, 0x14C) = 0;
    FIELD_AT(self, int, 0x150) = 0;
    FIELD_AT(self, int, 0x154) = 0;
    FIELD_AT(self, char, 0x15F) = 0;
    FIELD_AT(self, int, 0x104) = 0;
    FIELD_AT(self, int, 0x108) = 0;
    FIELD_AT(self, int, 0x10C) = 0;
    FIELD_AT(self, char, 0x161) = 0;
    FIELD_AT(self, char, 0x162) = 0;
    FIELD_AT(self, char, 0x163) = 0;
    FIELD_AT(self, char, 0x165) = 0;
    FIELD_AT(self, short, 0x168) = 1;
    FIELD_AT(self, char, 0x160) = 1;
    for (j = 0; j < 8; j++)
        ((SlotSet *)self)->slots[j] = 0;
    for (i = 0; i < 5; i++)
        FIELD_AT(self, char, 0x15A + i) = 0;
    for (k = 0; k < 2; k++)
        FIELD_AT(self, char, 0x158 + k) = 0;
    FIELD_AT(self, char, 0x164) = 0;
    FIELD_AT(self, int, 0x184) = 0;
    FIELD_AT(self, char, 0x181) = 0;
    FIELD_AT(self, signed char, 0x180) = -1;
    return self;
}

EXTERN_C void func_800D9B28(void *self);
EXTERN_C void func_800515A4(void *p, int arg);
EXTERN_C void func_8001E508(void *self, int flags);
EXTERN_C void func_800E42B0(void *self, int flags);
EXTERN_C int D_800D6228[];
EXTERN_C int D_800D6240[];
EXTERN_C int D_800D6268[];
EXTERN_C int D_800D6280[];

EXTERN_C void func_800D9A68(void *self, int flags)
{
    FIELD_AT(self, int *, 0x8C) = D_800D6228;
    FIELD_AT(self, int *, 0xF8) = D_800D6268;
    FIELD_AT(self, int *, 0x100) = D_800D6280;
    FIELD_AT(self, int *, 0x0) = D_800D6240;
    func_800D9B28(self);
    func_800E42B0((char *)self + 0x134, 2);
    func_800515A4((char *)self + 0xF8, 0);
    func_8001E508(self, flags);
}

EXTERN_C void func_800D9AEC(Poly *p)
{
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
}

EXTERN_C void func_800DAA6C(void *self, int i);
EXTERN_C void func_800D9C48(void *self);
EXTERN_C void func_800D9CA8(void *self);
EXTERN_C void func_800D9D08(void *self);

EXTERN_C void func_800D9B28(void *self)
{
    int i;
    void *p = FIELD_AT(self, void *, 0x130);
    if (p) {
        VtEntry *vt = FIELD_AT(p, VtEntry *, 0x28);
        vt[1].pfn((char *)p + vt[1].delta, 3);
        FIELD_AT(self, void *, 0x130) = 0;
    }
    for (i = 0; i < 8; i++)
        func_800DAA6C(self, i);
    func_800D9C48(self);
    func_800D9D08(self);
    func_800D9CA8(self);
}

EXTERN_C void func_800DAA6C(void *self, int i);
EXTERN_C void func_800D9C48(void *self);
EXTERN_C void func_800D9CA8(void *self);
EXTERN_C void func_800D9D08(void *self);

EXTERN_C void func_800D9BB8(void *self)
{
    int i;
    void *p = FIELD_AT(self, void *, 0x130);
    if (p) {
        VtEntry *vt = FIELD_AT(p, VtEntry *, 0x28);
        vt[1].pfn((char *)p + vt[1].delta, 3);
        FIELD_AT(self, void *, 0x130) = 0;
    }
    for (i = 0; i < 8; i++)
        func_800DAA6C(self, i);
    func_800D9C48(self);
    func_800D9D08(self);
    func_800D9CA8(self);
}

EXTERN_C void func_800D9C48(void *self)
{
    SubNode *n = FIELD_AT(self, SubNode *, 0x104);
    while (1) {
        if (!n)
            break;
        n = static_cast<SubNode *>(func_8001A744(FIELD_AT(self, SubNode *, 0x104), n));
        FIELD_AT(self, SubNode *, 0x104) = n;
    }
}

EXTERN_C void func_800D9CA8(void *self)
{
    SubNode *n = FIELD_AT(self, SubNode *, 0x10C);
    while (1) {
        if (!n)
            break;
        n = static_cast<SubNode *>(func_8001A744(FIELD_AT(self, SubNode *, 0x10C), n));
        FIELD_AT(self, SubNode *, 0x10C) = n;
    }
}

EXTERN_C void func_800D9D08(void *self)
{
    SubNode *n = FIELD_AT(self, SubNode *, 0x108);
    while (1) {
        if (!n)
            break;
        n = static_cast<SubNode *>(func_8001A744(FIELD_AT(self, SubNode *, 0x108), n));
        FIELD_AT(self, SubNode *, 0x108) = n;
    }
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9D68);

EXTERN_C void func_800DB4BC(void *self);

EXTERN_C void func_800DA03C(void *self)
{
    SubNode *n;
    int m;
    if (FIELD_AT(self, signed char, 0x163) && FIELD_AT(self, void *, 0x130) && FIELD_AT(FIELD_AT(self, void *, 0x130), short, 0x24) == 1)
        func_800DB4BC(self);
    n = FIELD_AT(self, SubNode *, 0x104);
    if (n) {
        if (FIELD_AT(self, void *, 0x108))
            return;
        if (FIELD_AT(self, void *, 0x10C)) {
        loop:
            if (!n)
                return;
            m = FIELD_AT(n, signed char, 0x7C);
            if (m == 1) {
                FIELD_AT(self, void *, 0x108) = FIELD_AT(self, void *, 0x10C);
                FIELD_AT(self, void *, 0x10C) = 0;
                if (!(FIELD_AT(self, unsigned int, 0x160) & 0xFFFF0000) && FIELD_AT(self, void *, 0x130)) {
                    if (FIELD_AT(self, signed char, 0x161))
                        FIELD_AT(FIELD_AT(self, void *, 0x130), short, 0x24) = m;
                    func_800DB4BC(self);
                }
                return;
            }
            {
                Link *l = n->next;
                n = static_cast<SubNode *>(l);
            }
            goto loop;
        }
        /* volatile read stops CSE from folding this retest (retail reloads it) */
        if (FIELD_AT(self, void *volatile, 0x104))
            return;
    }
    if (FIELD_AT(self, void *, 0x10C)) {
        FIELD_AT(self, void *, 0x108) = FIELD_AT(self, void *, 0x10C);
        FIELD_AT(self, void *, 0x10C) = 0;
    }
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DA170);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DA35C);

/* C_800DD34C: copied verbatim from src/effect/effect.cpp for a standalone build; drop when pasting */
struct C_800DD34C {
    int w0;
    int w4;
    int w8;
    int wC;
    short s10, s12;
    int pad14;
    int *vp18;
    int w1C;
    int w20;
    int w24;
    int w28;
    int w2C;
    int w30;
    int pad34, pad38;
    short s3C;
    short pad3E;
    int w40;
    short s44, s46;
    int w48;
    Vec4 v4C;
    Vec4 v5C;
    short s6C, s6E, s70;
    short pad72;
    int w74, w78;
    char c7C;
    C_800DD34C(int a, int b, short *c, int d);
};

inline int w98_800DA494(void *p) { return FIELD_AT(p, int, 0x98); }

EXTERN_C int func_800DA514(SlotSet *self, int obj, int slot);

EXTERN_C int func_800DA494(void *self, int a, short *c, int d, int slot)
{
    return func_800DA514((SlotSet *)self, (int)new C_800DD34C(a, w98_800DA494(self), c, d), slot);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DA514);

EXTERN_C int func_800DA584(SlotSet *self)
{
    int i;
    for (i = 0; i < 8; i++)
        if (self->slots[i] == 0)
            return i;
    return -1;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DA5B8);

EXTERN_C void *D_800B4C18[];
EXTERN_C void *func_800758F8(void *self, int b, void *c, void *d);
EXTERN_C void func_8001E848(void *self, void *b);
EXTERN_C int func_8007669C(void *self, int b, int c);

EXTERN_C void func_800DA84C(void *self, int a, int b)
{
    unsigned int t = b - 0x7000;
    void *g;
    void *r;
    FIELD_AT(self, int, 0x184) = a + (t >> 11);
    FIELD_AT(self, char, 0x180) = 0;
    g = D_800B4C18[0];
    r = func_800758F8(operator new(0x1C8), 1, g, self ? (char *)self + 0x100 : 0);
    FIELD_AT(self, void *, 0x17C) = r;
    func_8001E848(g, r);
    func_8007669C(FIELD_AT(self, void *, 0x17C), a, t);
}

EXTERN_C void *D_800B4C18[];
EXTERN_C int D_80010300[];
EXTERN_C int D_800102D0[];
EXTERN_C void *func_800758F8(void *self, int b, void *c, void *d);
EXTERN_C void func_8001E848(void *self, void *b);
EXTERN_C int func_8007669C(void *self, int b, int c);
EXTERN_C void func_800766D8(void *self);
EXTERN_C char *func_800E42F4(void *self, char *data);
EXTERN_C char *func_800E4354(void *self, char *data);
EXTERN_C void *func_800787B4(void);
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *self, void *obj);

typedef void (*Fn_800DA8E8)(void *, char *, void *, int);

EXTERN_C void func_800DA8E8(void *self, char *arg)
{
    switch (FIELD_AT(self, signed char, 0x180)) {
    case 0: {
        VtEntry *vt;
        void *g;
        void *r;
        FIELD_AT(self, char, 0x180) = 1;
        vt = FIELD_AT(self, VtEntry *, 0x0);
        ((Fn_800DA8E8)vt[4].pfn)((char *)self + vt[4].delta, arg, D_800B4ED8[0], 0);
        func_800766D8(FIELD_AT(self, void *, 0x17C));
        g = D_800B4C18[0];
        r = func_800758F8(operator new(0x1C8), 1, g, self ? (char *)self + 0x100 : 0);
        FIELD_AT(self, void *, 0x17C) = r;
        func_8001E848(g, r);
        func_8007669C(FIELD_AT(self, void *, 0x17C), FIELD_AT(self, int, 0x184), 0x7000);
        break;
    }
    case 1: {
        void *g;
        void *o;
        FIELD_AT(self, signed char, 0x180) = -1;
        FIELD_AT(self, int, 0x184) = 0;
        if (FIELD_AT(self, unsigned char, 0x181) & 0x20)
            arg = func_800E42F4((char *)self + 0x134, arg);
        if (FIELD_AT(self, unsigned char, 0x181) & 0x40)
            func_800E4354((char *)self + 0x134, arg);
        func_800766D8(FIELD_AT(self, void *, 0x17C));
        g = func_800787B4();
        o = func_8001CA10(0x14);
        FIELD_AT(o, int *, 0x0) = D_80010178;
        FIELD_AT(o, int, 0x4) = 0;
        FIELD_AT(o, int *, 0x0) = D_80010300;
        FIELD_AT(o, short, 0x8) = 2;
        FIELD_AT(o, short, 0xA) = 2;
        FIELD_AT(o, int, 0x10) = 0x2069;
        FIELD_AT(o, void *, 0xC) = 0;
        FIELD_AT(o, int *, 0x0) = D_800102D0;
        func_8001EFE4(g, o);
        break;
    }
    }
}

EXTERN_C void func_800DAA64(void *self)
{
}

EXTERN_C void func_800DDB1C(void *self);
EXTERN_C void func_800E43A0(void *self);

EXTERN_C void func_800DAA6C(void *pv, int i)
{
    SlotSet *self = (SlotSet *)pv;
    if (self->slots[i]) {
        void *p;
        if (i >= 3)
            func_800DDB1C((void *)self->slots[i]);
        func_800D9C48(self);
        func_800D9CA8(self);
        func_800D9D08(self);
        p = (void *)self->slots[i];
        if (p) {
            Poly *b = (Poly *)((char *)p + 0x18);
            b->vptr[1].pfn((char *)b + b->vptr[1].delta, 3);
        }
        self->slots[i] = 0;
        p = FIELD_AT(self, void *, 0x130);
        if (p) {
            VtEntry *vt = FIELD_AT(p, VtEntry *, 0x28);
            vt[1].pfn((char *)p + vt[1].delta, 3);
            FIELD_AT(self, void *, 0x130) = 0;
        }
        func_800E43A0((char *)self + 0x134);
    }
}

EXTERN_C int func_800DAB3C(SlotSet *self)
{
    int r = 0;
    if (self->cur < 8)
        r = self->slots[self->cur];
    return r;
}

EXTERN_C int func_800DAB64(void *self)
{
    int i;
    for (i = 0; i < 8; i++)
        if (((int *)((char *)self + 0x110))[i])
            return 0;
    return 1;
}

EXTERN_C int func_800DAB94(SlotSet *self, int i)
{
    return self->slots[i];
}

struct S_800DABA8 {
    int w[6];
};

EXTERN_C void func_800DD8D8(void *self, void *arg);

EXTERN_C int func_800DABA8(SlotSet *self, S_800DABA8 *arg)
{
    int i;
    int last;
    S_800DABA8 tmp = *arg;
    tmp.w[2] = 0;
    last = self->slots[2] ? 2 : 0;
    for (i = 0; i < 3; i++) {
        if (self->slots[i]) {
            if (i == last)
                tmp.w[2] = arg->w[2];
            func_800DD8D8((void *)self->slots[i], arg);
        }
    }
    return self->slots[2] ? self->slots[2] : self->slots[0];
}

EXTERN_C void *func_800DD9A8(void *a, void *b, void *c);
EXTERN_C void func_800DAE48(void *self, SubNode *node);

EXTERN_C void *func_800DAC88(SlotSet *self, void *arg)
{
    void *r;
    int i;
    if (!self->slots[2])
        return 0;
    r = 0;
    for (i = 0; i < 5; i++) {
        if (self->slots[3 + i] == 0) {
            r = func_800DD9A8((void *)self->slots[2], arg, (void *)(i + 1));
            self->slots[3 + i] = (int)r;
            func_800DAE48(self, (SubNode *)r);
            return r;
        }
    }
    return r;
}

EXTERN_C void func_800DAD28(void *self)
{
    if (FIELD_AT(self, signed char, 0x160)) {
        void *p = FIELD_AT(self, void *, 0x130);
        if (p) {
            VtEntry *vt = FIELD_AT(p, VtEntry *, 0x28);
            vt[3].pfn((char *)p + vt[3].delta, FIELD_AT(self, short, 0x148));
        }
    }
}

EXTERN_C int func_800DD9FC(void *self);

/* func_800DD9FC returns bool (xori at the call site); the unit defines it returning int */
typedef bool (*Pred_800DAD80)(void *);

EXTERN_C int func_800DAD80(SlotSet *self)
{
    int i;
    void *p;
    if (FIELD_AT(self, int, 0x150))
        return 1;
    for (i = 0; i < 8; i++) {
        p = (void *)func_800DAB94(self, i);
        if (p && !((Pred_800DAD80)func_800DD9FC)(p))
            return 0;
    }
    FIELD_AT(self, int, 0x150) = 1;
    return 1;
}

EXTERN_C void func_800DADF8(void *self, SubNode *node)
{
    if (FIELD_AT(self, SubNode *, 0x104))
        func_8001A678(FIELD_AT(self, SubNode *, 0x104), node);
    else
        FIELD_AT(self, SubNode *, 0x104) = node;
}

EXTERN_C void func_800DAE48(void *self, SubNode *node)
{
    if (FIELD_AT(self, SubNode *, 0x10C))
        func_8001A678(FIELD_AT(self, SubNode *, 0x10C), node);
    else
        FIELD_AT(self, SubNode *, 0x10C) = node;
}

EXTERN_C int func_8003912C(void *p, int n);
EXTERN_C Vec4 func_8003A150(int h, int n);
EXTERN_C void func_800DBEDC(void *self, void *a, void *b);

EXTERN_C void func_800DAE98(void *self, void *obj, void *b, void *a, int flag)
{
    Vec4 v;
    vec4_zero(&v);
    if (FIELD_AT(self, void *, 0x130) && flag)
        func_800DBEDC(FIELD_AT(self, void *, 0x130), b, a);
    if (a) {
        int h = func_8003912C(FIELD_AT(a, void *, 0x1B8), 5);
        if (h) {
            v = func_8003A150(h, 0);
            FIELD_AT(obj, Vec4, 0x4C) = v;
        }
    }
    if (b) {
        int h = func_8003912C(FIELD_AT(b, void *, 0x1B8), 5);
        if (h) {
            v = func_8003A150(h, 0);
            FIELD_AT(obj, Vec4, 0x5C) = v;
        }
    }
}

EXTERN_C void func_800DAFD4(void *self)
{
    void *p;
    FIELD_AT(self, char, 0x164) = 0;
    p = D_800B4ED8[0];
    FIELD_AT(p, int, 0x278) = 6;
    FIELD_AT(p, int, 0x26C) = 0;
}

struct S_800DAFF0_Clock {
    int pad[3];
    volatile unsigned int ticks;
};
EXTERN_C S_800DAFF0_Clock D_800A4534;
EXTERN_C void func_800DB0FC(void *self);

EXTERN_C void func_800DAFF0(void *self)
{
    void *p;
    FIELD_AT(self, char, 0x164) = 1;
    FIELD_AT(self, int, 0x14C) = D_800A4534.ticks & ~1;
    p = D_800B4ED8[0];
    FIELD_AT(p, int, 0x278) = 4;
    FIELD_AT(p, int, 0x26C) = 0;
    if (FIELD_AT(self, void *, 0x130) == 0)
        func_800DB0FC(self);
}

EXTERN_C void func_800DDB58(SubNode *n, int v);

inline SubNode *next_800DB054(SubNode *n) { return static_cast<SubNode *>(n->next); }

EXTERN_C void func_800DB054(void *self)
{
    SubNode *n;
    if (FIELD_AT(self, SubNode *, 0x104)) {
        n = FIELD_AT(self, SubNode *, 0x104);
        while (1) {
            if (!n)
                break;
            func_800DDB58(n, FIELD_AT(self, short, 0x148));
            n = next_800DB054(n);
        }
    }
    if (FIELD_AT(self, SubNode *, 0x108)) {
        n = FIELD_AT(self, SubNode *, 0x108);
        while (1) {
            if (!n)
                break;
            func_800DDB58(n, FIELD_AT(self, short, 0x148));
            n = next_800DB054(n);
        }
    }
}

EXTERN_C Vec4 func_800DBD5C(Vec4 *a, Vec4 *b);
EXTERN_C void func_8003A754(void *m, int scale);
EXTERN_C void func_8003A7FC(void *m, SVec4 *rot);
EXTERN_C int ratan2(int y, int x);
EXTERN_C int SquareRoot0(int a);
EXTERN_C void ApplyMatrixLV(void *m, Vec4 *v, Vec4 *out);
EXTERN_C void func_80099C80(int a);

struct Mat_800DB0FC {
    int m[8];
};

typedef void (*Fn_800DB0FC)(void *, SVec4 *, Vec4 *);

EXTERN_C void func_800DB0FC(void *pv)
{
    SlotSet *self = (SlotSet *)pv;
    Vec4 tbl[6] = {
        Vec4(0x202D, -0x1E77, -0x1644, 0),
        Vec4(0x1F7E, -0x1250, 0x29D3, 0),
        Vec4(0x1DF0, -0x1607, -0x3767, 0),
        Vec4(0x130B, -0xED4, -0x460D, 0),
        Vec4(0x1423, -0xB54, -0x4A12, 0),
        Vec4(0x1423, -0xB54, 0x4A12, 0),
    };
    void *o = (void *)(self->slots[2] ? self->slots[2] : self->slots[0]);
    Vec4 to = FIELD_AT(o, Vec4, 0x5C);
    Vec4 from = FIELD_AT(o, Vec4, 0x4C);
    Vec4 dir;
    dir = func_800DBD5C(&to, &from);
    Vec4 v(0, 0, 0, 0);
    Vec4 w(0, 0, 0, 0);
    SVec4 ang;
    ang.x = 0;
    ang.y = 0;
    ang.z = 0;
    ang.w = 0;
    short i;
    if (to.x == from.x)
        i = dir.z / 2400;
    else if (to.z == from.z)
        i = dir.x / 2400;
    else
        i = SquareRoot0(dir.x * dir.x + dir.z * dir.z) / 2400;
    i = i < 0 ? -i : i;
    if (i > 5)
        i = 5;
    v = tbl[i];
    Mat_800DB0FC m;
    func_8003A754(&m, 0x1000);
    SVec4 rot;
    int ra = ratan2(dir.x, dir.z);
    rot.x = 0;
    rot.y = ra - 0x800;
    rot.z = 0;
    rot.w = 0;
    func_8003A7FC(&m, &rot);
    ApplyMatrixLV(&m, &v, &w);
    ang.x = ratan2(w.y, SquareRoot0(w.x * w.x + w.z * w.z));
    ang.y = ratan2(w.x, w.z) - 0x800;
    ang.z = 0;
    w.x += to.x + (-dir.x >> 1);
    w.y += to.y + (-dir.y >> 1);
    w.z += to.z + (-dir.z >> 1);
    func_80099C80(0x203);
    void *p = D_800B4ED8[0];
    FIELD_AT(p, int, 0x11C) = 0x203;
    VtEntry *vt = FIELD_AT(p, VtEntry *, 0x2C);
    ((Fn_800DB0FC)vt[34].pfn)((char *)p + vt[34].delta, &ang, &w);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB4BC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB788);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB978);

EXTERN_C void func_800DDC98(void *p, int on);

EXTERN_C void func_800DBC98(void *self, void *arg, void *one)
{
    int i;
    if (one) {
        func_800DDC98(one, (int)arg);
        return;
    }
    for (i = 0; i < 8; i++) {
        void *p = FIELD_AT(self, void *, 0x110 + i * 4);
        if (p)
            func_800DDC98(p, (int)arg);
    }
}

EXTERN_C Vec4 func_800DBD1C(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x + b->x, a->y + b->y, a->z + b->z, a->w);
}

EXTERN_C Vec4 func_800DBD5C(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x - b->x, a->y - b->y, a->z - b->z, a->w);
}

EXTERN_C int func_800DBD9C(void *self)
{
    return FIELD_AT(self, short, 0x148);
}

EXTERN_C void func_800DBDA8(void *self, int on)
{
    if (on)
        FIELD_AT(self, char, 0x160) = 1;
    else
        FIELD_AT(self, char, 0x160) = 0;
}

EXTERN_C int D_80010300[];
EXTERN_C int D_800102D0[];
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *self, void *obj);

EXTERN_C void func_800DBDC0(void *self)
{
    void *p = func_8001CA10(0x14);
    FIELD_AT(p, int *, 0x0) = D_80010178;
    FIELD_AT(p, int, 0x4) = 0;
    FIELD_AT(p, int *, 0x0) = D_80010300;
    FIELD_AT(p, short, 0x8) = 2;
    FIELD_AT(p, short, 0xA) = 2;
    FIELD_AT(p, int, 0x10) = 0;
    FIELD_AT(p, int, 0xC) = 0;
    FIELD_AT(p, int *, 0x0) = D_800102D0;
    func_8001EFE4(self, p);
}

EXTERN_C void func_800DBE30(void *self)
{
    FIELD_AT(self, short, 0x148)++;
}

EXTERN_C void *func_800DBE44(void *self)
{
    FIELD_AT(self, int *, 0x28) = D_800D6370;
    FIELD_AT(self, short, 0x0) = 0;
    vec4_zero(&FIELD_AT(self, Vec4, 0x4));
    vec4_zero(&FIELD_AT(self, Vec4, 0x14));
    FIELD_AT(self, short, 0x24) = 0;
    return self;
}

EXTERN_C void func_800DBE88(void *self, int flags)
{
    FIELD_AT(self, int *, 0x28) = D_800D6370;
    if (flags & 1)
        operator delete(self);
}

EXTERN_C char *func_800DBEBC(void *self, char *src)
{
    FIELD_AT(self, short, 0x0) = FIELD_AT(src, short, 0x0);
    FIELD_AT(self, char, 0x2) = FIELD_AT(src, char, 0x2);
    return src + 4;
}

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6228);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6240);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6268);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6280);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBEDC);

EXTERN_C void *func_800DC08C(void *self)
{
    func_800DBE44(self);
    FIELD_AT(self, int *, 0x28) = D_800D6340;
    FIELD_AT(self, int, 0x2C) = 0;
    FIELD_AT(self, int, 0x30) = 0;
    FIELD_AT(self, int, 0x34) = 0;
    return self;
}

EXTERN_C void func_800DC0CC(void *self, int flags)
{
    FIELD_AT(self, int *, 0x28) = D_800D6340;
    if (FIELD_AT(self, void *, 0x2C))
        func_800A0D0C(FIELD_AT(self, void *, 0x2C));
    if (FIELD_AT(self, void *, 0x30))
        func_800A0D0C(FIELD_AT(self, void *, 0x30));
    if (FIELD_AT(self, void *, 0x34))
        func_800A0D0C(FIELD_AT(self, void *, 0x34));
    func_800DBE88(self, flags);
}

struct Rec28 {
    int w[7];
};

EXTERN_C char *func_800DC150(void *self, char *src)
{
    char *p = func_800DBEBC(self, src);
    void *buf = func_800A0D2C(FIELD_AT(self, short, 0x0) * sizeof(Rec28));
    int size;
    FIELD_AT(self, void *, 0x2C) = buf;
    size = FIELD_AT(self, short, 0x0) * sizeof(Rec28);
    func_80025CE0(buf, p, size);
    return p + size;
}

#define gte_SetGeomScreen(r0) __asm__ volatile("ctc2 %0, $26" : : "r"(r0))

struct S_800DC1BC {
    char pad[0x20];
};

EXTERN_C void func_800DC1BC(void *self, int i)
{
    if (i >= FIELD_AT(self, short, 0x0) || FIELD_AT(self, short, 0x24) == 1) {
        FIELD_AT(self, short, 0x24) = 1;
    } else {
        void *g = D_800B4ED8[0];
        VtEntry *vt;
        FIELD_AT(g, int, 0x11C) = FIELD_AT(self, int *, 0x34)[i];
        gte_SetGeomScreen(FIELD_AT(self, int *, 0x34)[i]);
        vt = FIELD_AT(g, VtEntry *, 0x2C);
        vt[35].pfn((char *)g + vt[35].delta, (int)&FIELD_AT(self, S_800DC1BC *, 0x30)[i]);
    }
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC264);

inline void *operator new[](unsigned int, void *p) { return p; }

EXTERN_C void func_8003A754(void *m, int scale);
EXTERN_C void func_8003A7FC(void *m, SVec4 *rot);
EXTERN_C void func_8003B2F0(void *m, Vec4 *t);

struct Mat_800DC670 {
    int m[8];
    Mat_800DC670() { func_8003A754(this, 0x1000); }
};

struct Rec_800DC670 {
    int x, y, z;
    int pad;
    SVec4 rot;
    int h;
};

EXTERN_C void func_800DC670(void *self)
{
    if (FIELD_AT(self, void *, 0x2C)) {
        Rec_800DC670 *r;
        int i;
        FIELD_AT(self, Mat_800DC670 *, 0x30) =
            new (func_800A0D2C(FIELD_AT(self, short, 0x0) * sizeof(Mat_800DC670))) Mat_800DC670[FIELD_AT(self, short, 0x0)];
        FIELD_AT(self, int *, 0x34) = (int *)func_800A0D2C(FIELD_AT(self, short, 0x0) * sizeof(int));
        r = FIELD_AT(self, Rec_800DC670 *, 0x2C);
        i = 0;
        while (1) {
            SVec4 rot;
            if (!(i < FIELD_AT(self, short, 0x0)))
                break;
            rot = r->rot;
            func_8003A7FC(&FIELD_AT(self, Mat_800DC670 *, 0x30)[i], &rot);
            Vec4 t(r->x, r->y, r->z, 0);
            func_8003B2F0(&FIELD_AT(self, Mat_800DC670 *, 0x30)[i], &t);
            FIELD_AT(self, int *, 0x34)[i++] = (r++)->h;
        }
        if (FIELD_AT(self, void *, 0x2C))
            func_800A0D0C(FIELD_AT(self, void *, 0x2C));
        FIELD_AT(self, void *, 0x2C) = 0;
    }
}

EXTERN_C void *func_800DBE44(void *self);

EXTERN_C void *func_800DC7C8(void *self)
{
    func_800DBE44(self);
    FIELD_AT(self, int *, 0x28) = D_800D6310;
    FIELD_AT(self, int, 0x2C) = 0;
    FIELD_AT(self, int, 0x30) = 0;
    return self;
}

EXTERN_C void func_800DC804(void *self, int flags)
{
    FIELD_AT(self, int *, 0x28) = D_800D6310;
    if (FIELD_AT(self, void *, 0x2C))
        func_800A0D0C(FIELD_AT(self, void *, 0x2C));
    if (FIELD_AT(self, void *, 0x30))
        func_800A0D0C(FIELD_AT(self, void *, 0x30));
    func_800DBE88(self, flags);
}

struct Rec20 {
    int w[5];
};

EXTERN_C char *func_800DC870(void *self, char *src)
{
    char *p = func_800DBEBC(self, src);
    void *buf = func_800A0D2C(FIELD_AT(self, short, 0x0) * sizeof(Rec20));
    int size;
    FIELD_AT(self, void *, 0x2C) = buf;
    size = FIELD_AT(self, short, 0x0) * sizeof(Rec20);
    func_80025CE0(buf, p, size);
    return p + size;
}

#define gte_SetGeomScreen(r0) __asm__ volatile("ctc2 %0, $26" : : "r"(r0))

struct S_800DC8DC {
    Vec4 v;
    int h;
};

EXTERN_C void func_800DC8DC(void *self, int i)
{
    if (i >= FIELD_AT(self, short, 0x0) || FIELD_AT(self, short, 0x24) == 1) {
        FIELD_AT(self, short, 0x24) = 1;
    } else {
        void *g = D_800B4ED8[0];
        S_800DC8DC *r = &FIELD_AT(self, S_800DC8DC *, 0x2C)[i];
        VtEntry *vt;
        Vec4 v;
        FIELD_AT(g, int, 0x11C) = r->h;
        gte_SetGeomScreen(r->h);
        v = r->v;
        vt = FIELD_AT(g, VtEntry *, 0x2C);
        ((void (*)(void *, SVec4 *, Vec4 *))vt[34].pfn)((char *)g + vt[34].delta, &FIELD_AT(self, SVec4 *, 0x30)[i], &v);
    }
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC99C);

EXTERN_C void *func_800DC08C(void *self);

EXTERN_C void *func_800DCC58(void *self)
{
    func_800DC08C(self);
    FIELD_AT(self, int *, 0x28) = D_800D62E0;
    return self;
}

EXTERN_C void func_800DC0CC(void *self, int flags);

EXTERN_C void func_800DCC8C(void *self, int flags)
{
    FIELD_AT(self, int *, 0x28) = D_800D62E0;
    func_800DC0CC(self, flags);
}

struct S_800DCCB4 {
    int x, y, z;
    int pad[4];
};

EXTERN_C void func_800DCCB4(void *self)
{
    if (FIELD_AT(self, S_800DCCB4 *, 0x2C)) {
        S_800DCCB4 *r = FIELD_AT(self, S_800DCCB4 *, 0x2C);
        Vec4 v = FIELD_AT(self, Vec4, 0x4);
        int i;
        for (i = 0; i < FIELD_AT(self, short, 0x0); i++, r++) {
            r->x += v.x;
            r->y += v.y;
            r->z += v.z;
        }
    }
}

#define gte_SetGeomScreen(r0) __asm__ volatile("ctc2 %0, $26" : : "r"(r0))

struct S_800DCD54 {
    int x, y, z;
    int pad;
    short sx, sy, sz;
    short pad2;
    int h;
};

struct SV_800DCD54 {
    short x, y, z, w;
    SV_800DCD54(short ax, short ay, short az, short aw) : x(ax), y(ay), z(az), w(aw) {}
};

EXTERN_C void func_800DCD54(void *self, int i)
{
    if (i >= FIELD_AT(self, short, 0x0) || FIELD_AT(self, short, 0x24) == 1) {
        FIELD_AT(self, short, 0x24) = 1;
    } else {
        void *g = D_800B4ED8[0];
        S_800DCD54 *r = &FIELD_AT(self, S_800DCD54 *, 0x2C)[i];
        VtEntry *vt;
        FIELD_AT(g, int, 0x11C) = r->h;
        gte_SetGeomScreen(r->h);
        Vec4 v(r->x, r->y, r->z, 0);
        SV_800DCD54 s(r->sx, r->sy, r->sz, 0);
        vt = FIELD_AT(g, VtEntry *, 0x2C);
        ((void (*)(void *, SV_800DCD54 *, Vec4 *))vt[34].pfn)((char *)g + vt[34].delta, &s, &v);
    }
}

EXTERN_C void *func_800DC7C8(void *self);

EXTERN_C void *func_800DCE28(void *self)
{
    func_800DC7C8(self);
    FIELD_AT(self, int *, 0x28) = D_800D62B0;
    return self;
}

EXTERN_C void func_800DC804(void *self, int flags);

EXTERN_C void func_800DCE5C(void *self, int flags)
{
    FIELD_AT(self, int *, 0x28) = D_800D62B0;
    func_800DC804(self, flags);
}

/* PsyQ inline_c.h GTE macros */
#define gte_ldlvl(r0) __asm__ volatile( \
    "lhu $12, 0(%0)\n\t" \
    "lhu $13, 4(%0)\n\t" \
    "lhu $14, 8(%0)\n\t" \
    "mtc2 $12, $9\n\t" \
    "mtc2 $13, $10\n\t" \
    "mtc2 $14, $11" \
    : : "r"(r0) : "$12", "$13", "$14")
#define gte_sqr0() __asm__ volatile("nop\n\tnop\n\t.word 0x4AA00428")
#define gte_stmac1(r0) __asm__ volatile("swc2 $25, 0(%0)" : : "r"(r0) : "memory")
#define gte_stmac3(r0) __asm__ volatile("swc2 $27, 0(%0)" : : "r"(r0) : "memory")


EXTERN_C int ratan2(int y, int x);
EXTERN_C int SquareRoot0(int a);

struct SV_800DCE84 {
    short x, y, z, w;
    SV_800DCE84() { x = 0; y = 0; z = 0; w = 0; }
    SV_800DCE84(short ax, short ay, short az, short aw) : x(ax), y(ay), z(az), w(aw) {}
};

struct Rec_800DCE84 {
    int x, y, z;
    int pad[2];
};

EXTERN_C void func_800DCE84(void *self)
{
    if (FIELD_AT(self, void *, 0x2C)) {
        Rec_800DCE84 *r;
        int i;
        Vec4 base;
        FIELD_AT(self, SV_800DCE84 *, 0x30) =
            new (func_800A0D2C(FIELD_AT(self, short, 0x0) * sizeof(SV_800DCE84))) SV_800DCE84[FIELD_AT(self, short, 0x0)];
        base = FIELD_AT(self, Vec4, 0x4);
        r = FIELD_AT(self, Rec_800DCE84 *, 0x2C);
        i = 0;
        while (1) {
            int ry;
            int a, b;
            if (!(i < FIELD_AT(self, short, 0x0)))
                break;
            Vec4 v(r->x, r->y, r->z, 0);
            gte_ldlvl(&v);
            gte_sqr0();
            ry = ratan2(v.x, v.z) - 0x800;
            gte_stmac1(&a);
            gte_stmac3(&b);
            SV_800DCE84 s(ratan2(v.y, SquareRoot0(a + b)), ry, 0, 0);
            r->x += base.x;
            r->y += base.y;
            r->z += base.z;
            FIELD_AT(self, SV_800DCE84 *, 0x30)[i].x = s.x;
            FIELD_AT(self, SV_800DCE84 *, 0x30)[i].y = s.y;
            FIELD_AT(self, SV_800DCE84 *, 0x30)[i].z = s.z;
            i++;
            r++;
        }
    }
}

EXTERN_C Vec4 func_800DD058(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x - b->x, a->y - b->y, a->z - b->z, a->w);
}

EXTERN_C void func_800DD098(void *self)
{
}

EXTERN_C void func_800DD0A0(void *self)
{
    FIELD_AT(self, short, 0x24) = 1;
}

EXTERN_C int func_800DD0AC(void *self)
{
    return FIELD_AT(self, signed char, 0x2);
}

EXTERN_C int func_800DD0B8(void *self)
{
    return FIELD_AT(self, short, 0x24);
}

EXTERN_C int func_800DD0C4(void *self)
{
    Poly *p;
    if (FIELD_AT(self, int, 0x4) != 0) {
        FIELD_AT(self, int, 0x4)--;
    } else {
        p = FIELD_AT(self, Poly *, 0x8);
        if (p)
            p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
        D_800E5840[0]--;
        return 1;
    }
    return 0;
}

EXTERN_C int func_800DD13C(void *self)
{
    Poly *p;
    if (FIELD_AT(self, int, 0x4) != 0) {
        FIELD_AT(self, int, 0x4)--;
    } else {
        p = FIELD_AT(self, Poly *, 0x8);
        if (p)
            p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
        D_800E5844[0]--;
        return 1;
    }
    return 0;
}

EXTERN_C int func_800DD1B4(void)
{
    return D_800E5844[0] != 0;
}

EXTERN_C int D_800D63A0[];
EXTERN_C char D_80010338[];
EXTERN_C char D_800A4544[];
EXTERN_C void func_8001D150(void *, void *);

struct S_800DD1C4 {
    void *vptr;
    int next;
    void *owner;
    short prio;
    int on;
};

EXTERN_C void *func_800DD1C4(void *self, int a, int b)
{
    char *l;
    S_800DD1C4 *o;
    FIELD_AT(self, int *, 0x0) = D_800D63A0;
    FIELD_AT(self, int, 0x4) = b;
    FIELD_AT(self, int, 0x8) = a;
    l = D_800A4544;
    o = (S_800DD1C4 *)operator new(0x14);
    o->vptr = D_80010178;
    o->next = 0;
    o->vptr = D_80010338;
    o->owner = self;
    o->prio = 0x80;
    o->on = 1;
    func_8001D150(l, o);
    D_800E5844[0]++;
    return self;
}

EXTERN_C void func_8001D024(void *self);

EXTERN_C void func_800DD260(void *self)
{
    func_8001D024(self);
}

EXTERN_C int func_800DD280(void)
{
    return D_800E5840[0] != 0;
}

EXTERN_C int D_800D63B8[];
EXTERN_C char D_80010338[];
EXTERN_C char D_800A4544[];
EXTERN_C void func_8001D150(void *, void *);

struct S_800DD290 {
    void *vptr;
    int next;
    void *owner;
    short prio;
    int on;
};

EXTERN_C void *func_800DD290(void *self, int a, int b)
{
    char *l;
    S_800DD290 *o;
    FIELD_AT(self, int *, 0x0) = D_800D63B8;
    FIELD_AT(self, int, 0x4) = b;
    FIELD_AT(self, int, 0x8) = a;
    l = D_800A4544;
    o = (S_800DD290 *)operator new(0x14);
    o->vptr = D_80010178;
    o->next = 0;
    o->vptr = D_80010338;
    o->owner = self;
    o->prio = 0x80;
    o->on = 1;
    func_8001D150(l, o);
    D_800E5840[0]++;
    return self;
}

EXTERN_C void func_800DD32C(void *self)
{
    func_8001D024(self);
}

EXTERN_C int D_800D63D0[];
EXTERN_C int D_800E583C[];

C_800DD34C::C_800DD34C(int a, int b, short *c, int d)
{
    func_800E3EB4(this);
    vp18 = D_80010178;
    w1C = 0;
    vp18 = D_800D63D0;
    w20 = a;
    w30 = 0;
    w40 = b;
    w24 = d;
    s44 = c[0];
    s46 = c[1];
    w48 = 1;
    vec4_zero(&v4C);
    vec4_zero(&v5C);
    c7C = 0;
    s6E = 0;
    s6C = 0;
    s70 = 0;
    s3C = 0;
    w8 = 0;
    w74 = 0;
    w78 = 0;
    w2C = 0;
    D_800E583C[0] = w20;
}

EXTERN_C int D_800D63D0[];
EXTERN_C int D_800E583C[];
EXTERN_C Color *func_8003D37C(void *p);
EXTERN_C void *func_800E1C5C(void *src, int a, void *b);
EXTERN_C void *func_800DEBEC(void *arg);
EXTERN_C void *func_8003BEF8(void *p);
EXTERN_C void func_80039BEC(void *self, int b);

inline Color *color_800DD440(void *p)
{
    void *q = FIELD_AT(p, void *, 0x1B8);
    if (q && FIELD_AT(q, void *, 0x68))
        return func_8003D37C(FIELD_AT(q, void *, 0x68));
    return 0;
}

inline short id_800DD440(void *p)
{
    short s;
    void *q = FIELD_AT(p, void *, 0x1B8);
    if (q) {
        q = FIELD_AT(q, void *, 0x68);
        if (q)
            s = FIELD_AT(q, short, 0xC);
    }
    return s;
}

EXTERN_C void *func_800DD440(void *self, void *o, void *b, void *n)
{
    void *p;
    char *g;
    void *m;
    func_800E3EB4(self);
    FIELD_AT(self, int *, 0x18) = D_80010178;
    FIELD_AT(self, int, 0x1C) = 0;
    FIELD_AT(self, int *, 0x18) = D_800D63D0;
    FIELD_AT(self, int, 0x20) = FIELD_AT(o, int, 0x20);
    FIELD_AT(self, int, 0x24) = FIELD_AT(o, int, 0x24);
    FIELD_AT(self, short, 0x44) = -1;
    FIELD_AT(self, short, 0x46) = FIELD_AT(o, short, 0x46);
    FIELD_AT(self, int, 0x48) = 0;
    vec4_zero(&FIELD_AT(self, Vec4, 0x4C));
    vec4_zero(&FIELD_AT(self, Vec4, 0x5C));
    FIELD_AT(self, char, 0x7C) = 0;
    FIELD_AT(self, int, 0x0) = FIELD_AT(o, int, 0x0);
    FIELD_AT(self, void *, 0x4) = func_800E1C5C(FIELD_AT(o, void *, 0x4), 0, b);
    FIELD_AT(self, int, 0xC) = 0x8000;
    FIELD_AT(self, short, 0x10) = FIELD_AT(o, short, 0x10);
    FIELD_AT(self, int, 0x40) = FIELD_AT(o, int, 0x40);
    FIELD_AT(self, void *, 0x8) = FIELD_AT(o, void *, 0x8) ? func_800DEBEC(FIELD_AT(o, void *, 0x8)) : 0;
    FIELD_AT(self, short, 0x12) = FIELD_AT(o, short, 0x12);
    FIELD_AT(self, short, 0x14) = FIELD_AT(o, short, 0x14);
    FIELD_AT(self, short, 0x16) = FIELD_AT(o, short, 0x16);
    FIELD_AT(self, short, 0x6E) = 0;
    FIELD_AT(self, short, 0x6C) = 0;
    FIELD_AT(self, short, 0x70) = FIELD_AT(o, short, 0x44) + FIELD_AT(o, short, 0x46) * (int)n;
    FIELD_AT(self, short, 0x3C) = 0;
    FIELD_AT(self, int, 0x74) = 0;
    FIELD_AT(self, int, 0x78) = 0;
    FIELD_AT(self, int, 0x2C) = FIELD_AT(b, int, 0x4);
    p = FIELD_AT(b, void *, 0x8);
    FIELD_AT(self, void *, 0x30) = p;
    if (p) {
        FIELD_AT(self, Color, 0x38) = *color_800DD440(p);
        FIELD_AT(self, int, 0x34) = id_800DD440(FIELD_AT(self, void *, 0x30));
    }
    D_800E583C[0] = FIELD_AT(self, int, 0x20);
    m = func_8003BEF8(operator new(0x4C));
    g = FIELD_AT(self, char *, 0x20);
    FIELD_AT(self, void *, 0x28) = m;
    func_80039BEC(g ? g + 0x50 : 0, (int)m);
    return self;
}

EXTERN_C int D_800D63D0[];
EXTERN_C void func_800E3ED4(void *self, int flags);

EXTERN_C void func_800DD680(void *self, int flags)
{
    Poly *p;
    FIELD_AT(self, int *, 0x18) = D_800D63D0;
    p = FIELD_AT(self, Poly *, 0x28);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    FIELD_AT(self, int, 0x1C) = 0;
    func_8001A610((IdNode *)((char *)self + 0x18), 0);
    func_800E3ED4(self, flags);
}

EXTERN_C void *func_800DF498(void *self);
EXTERN_C char *func_800DF4EC(void *self, char *src, void *arg);
EXTERN_C void *func_800E4010(void *self);
EXTERN_C void func_800E3FB8(void *self, void *other);
EXTERN_C void func_800DF4CC(void *self, int flags);
EXTERN_C void *func_8003BEF8(void *p);
EXTERN_C void func_80039BEC(void *self, int b);

EXTERN_C char *func_800DD6F8(void *self, char *src)
{
    void *o = func_800DF498(operator new(0x78));
    char *r = func_800DF4EC(o, src, FIELD_AT(self, void *, 0x40));
    void *n;
    char *p;
    func_800E3FB8(self, func_800E4010(o));
    if (o)
        func_800DF4CC(o, 3);
    n = func_8003BEF8(operator new(0x4C));
    FIELD_AT(self, void *, 0x28) = n;
    p = FIELD_AT(self, char *, 0x20);
    func_80039BEC(p ? p + 0x50 : 0, (int)n);
    return r;
}

EXTERN_C void func_800E23A0(void *self, short n);
EXTERN_C void func_800E07E0(void *self, void *arg, void *owner);
EXTERN_C void func_800DD878(void *self);

EXTERN_C int func_800DD7A8(void *self, short n)
{
    if (FIELD_AT(self, short, 0x44) != -1) {
        if (n < FIELD_AT(self, short, 0x44))
            return 0;
    } else {
        if (FIELD_AT(self, short, 0x6C) < FIELD_AT(self, short, 0x70)) {
            FIELD_AT(self, short, 0x6C)++;
            return 0;
        }
    }
    if (FIELD_AT(self, short, 0x12) && FIELD_AT(self, short, 0x12) < FIELD_AT(self, short, 0x6E))
        FIELD_AT(self, char, 0x7C) = 1;
    func_800E23A0(FIELD_AT(self, void *, 0x4), FIELD_AT(self, short, 0x6E));
    FIELD_AT(self, short, 0x6E)++;
    func_800E07E0(FIELD_AT(self, void *, 0x4), FIELD_AT(self, void *, 0x28), self);
    func_800DD878(self);
    return 1;
}

EXTERN_C void func_800E1090(void *p, void *arg);
EXTERN_C void func_800E1304(void *p, void *arg);

EXTERN_C void func_800DD878(void *self)
{
    void *p;
    for (p = FIELD_AT(self, void *, 0x4); p; p = FIELD_AT(p, void *, 0x4)) {
        func_800E1090(p, FIELD_AT(self, void *, 0x28));
        func_800E1304(p, FIELD_AT(self, void *, 0x28));
    }
}

EXTERN_C Color *func_8003D37C(void *p);
EXTERN_C void func_800E1B60(void *self, void *arg);

inline Color *color_800DD8D8(void *p)
{
    void *q = FIELD_AT(p, void *, 0x1B8);
    if (q && FIELD_AT(q, void *, 0x68))
        return func_8003D37C(FIELD_AT(q, void *, 0x68));
    return 0;
}

inline short id_800DD8D8(void *p)
{
    short s;
    void *q = FIELD_AT(p, void *, 0x1B8);
    if (q) {
        q = FIELD_AT(q, void *, 0x68);
        if (q)
            s = FIELD_AT(q, short, 0xC);
    }
    return s;
}

EXTERN_C void func_800DD8D8(void *self, void *arg)
{
    void *p;
    FIELD_AT(self, int, 0x2C) = FIELD_AT(arg, int, 0x4);
    p = FIELD_AT(arg, void *, 0x8);
    FIELD_AT(self, void *, 0x30) = p;
    if (p) {
        FIELD_AT(self, Color, 0x38) = *color_800DD8D8(p);
        FIELD_AT(self, int, 0x34) = id_800DD8D8(FIELD_AT(self, void *, 0x30));
    }
    func_800E1B60(FIELD_AT(self, void *, 0x4), arg);
}

EXTERN_C void *func_800DD440(void *self, void *a, void *b, void *c);

EXTERN_C void *func_800DD9A8(void *a, void *b, void *c)
{
    return func_800DD440(operator new(0x80), a, b, c);
}

EXTERN_C bool func_800E21B8(void *obj);

EXTERN_C int func_800DD9FC(void *self)
{
    if (FIELD_AT(self, int, 0x74) != 0)
        return 1;
    if (!func_800E21B8(FIELD_AT(self, void *, 0x4)))
        return 0;
    return FIELD_AT(self, int, 0x74) = 1;
}

EXTERN_C int func_800DE884(void *self, short i);
EXTERN_C int func_800DE7C8(void *self, short i);
EXTERN_C int func_800DE83C(void *self, short i);
EXTERN_C void func_800DE8CC(void *self, short i);
struct S_800DEA54;
EXTERN_C void func_800DEA54(S_800DEA54 *self, int arg);
EXTERN_C void func_800DEB64(void *self, short i);

EXTERN_C void func_800DDA4C(void *self)
{
    if (FIELD_AT(self, void *, 0x8)) {
        if (func_800DE884(FIELD_AT(self, void *, 0x8), FIELD_AT(self, short, 0x6E))) {
            if (FIELD_AT(FIELD_AT(self, void *, 0x8), void *, 0x14))
                func_800DEA54(FIELD_AT(self, S_800DEA54 *, 0x8), 0);
        } else if (func_800DE7C8(FIELD_AT(self, void *, 0x8), FIELD_AT(self, short, 0x6E))) {
            func_800DE8CC(FIELD_AT(self, void *, 0x8), FIELD_AT(self, short, 0x6E));
        } else if (func_800DE83C(FIELD_AT(self, void *, 0x8), FIELD_AT(self, short, 0x6E))) {
            func_800DEA54(FIELD_AT(self, S_800DEA54 *, 0x8), 0);
        } else {
            func_800DEB64(FIELD_AT(self, void *, 0x8), FIELD_AT(self, short, 0x6E));
        }
    }
}

EXTERN_C void func_800DDB1C(void *self)
{
    void *p = FIELD_AT(self, void *, 0x8);
    if (p)
        FIELD_AT(p, int, 0x24) = 0;
}

EXTERN_C int func_800DDB38(void *self)
{
    if (FIELD_AT(self, int, 0x78) != 0)
        return 0;
    FIELD_AT(self, int, 0x78) = 1;
    return 1;
}

/* Same type and declaration as func_800DDC98 (already landed): drop these when landing,
   or move both into effect.h. */
struct Col_800DDC98 {
    unsigned char r, g, b, a;
    Col_800DDC98() {}
};
EXTERN_C void func_8003FB88(void *self, int mode, Col_800DDC98 c);

EXTERN_C Color *func_8003D37C(void *p);
EXTERN_C void func_800DDA4C(void *self);
EXTERN_C void func_800E22E0(void *self);
EXTERN_C void func_800DDC98(void *self, int on);

inline Col_800DDC98 *color_800DDB58(void *p)
{
    void *q = FIELD_AT(p, void *, 0x1B8);
    if (q && FIELD_AT(q, void *, 0x68))
        return (Col_800DDC98 *)func_8003D37C(FIELD_AT(q, void *, 0x68));
    return 0;
}

EXTERN_C void func_800DDB58(SubNode *self, int n)
{
    Col_800DDC98 c;
    if (FIELD_AT(self, short, 0x44) != -1 ? n < FIELD_AT(self, short, 0x44)
                                           : FIELD_AT(self, short, 0x6C) < FIELD_AT(self, short, 0x70))
        return;
    func_800DDA4C(self);
    if (FIELD_AT(self, void *, 0x4))
        func_800E22E0(FIELD_AT(self, void *, 0x4));
    if (FIELD_AT(self, short, 0x3C)) {
        FIELD_AT(self, short, 0x3C)--;
        c = *color_800DDB58(FIELD_AT(self, void *, 0x2C));
        c.r += 8;
        c.g += 8;
        func_8003FB88(FIELD_AT(self, void *, 0x2C), 1, c);
        if (FIELD_AT(self, short, 0x3C) == 0)
            func_800DDC98(self, 0);
    }
}


EXTERN_C void func_8003FB88(void *self, int mode, Col_800DDC98 c);

EXTERN_C void func_800DDC98(void *self, int on)
{
    Col_800DDC98 c;
    if (on) {
        if (FIELD_AT(self, void *, 0x30)) {
            c.r = 0xD7;
            c.g = 0xD7;
            c.b = 0;
            func_8003FB88(FIELD_AT(self, void *, 0x2C), 1, c);
            FIELD_AT(self, short, 0x3C) = 5;
        }
    } else if (FIELD_AT(self, void *, 0x30)) {
        func_8003FB88(FIELD_AT(self, void *, 0x2C), FIELD_AT(self, int, 0x34), FIELD_AT(self, Col_800DDC98, 0x38));
    }
}

EXTERN_C int func_800DDD84(void *self)
{
    return FIELD_AT(self, int, 0x2C);
}

EXTERN_C SubNode *func_800DDD90(SubNode *a, SubNode *b)
{
    return static_cast<SubNode *>(func_8001A744(a, b));
}

EXTERN_C SubNode *func_800DDDD8(SubNode *self)
{
    Link *l = self;
    return static_cast<SubNode *>(l->next);
}

EXTERN_C void func_800DDE00(SubNode *a, SubNode *b)
{
    func_8001A678(a, b);
}

EXTERN_C int func_800DDE3C(void *self)
{
    return FIELD_AT(self, unsigned short, 0x16);
}

EXTERN_C int func_800DDE48(void *self)
{
    return FIELD_AT(self, unsigned short, 0x14);
}

EXTERN_C void func_800DDE54(void *self, Vec4 *v)
{
    FIELD_AT(self, Vec4, 0x5C) = *v;
}

EXTERN_C Vec4 func_800DDE7C(void *self)
{
    return FIELD_AT(self, Vec4, 0x5C);
}

EXTERN_C void func_800DDEA8(void *self, Vec4 *v)
{
    FIELD_AT(self, Vec4, 0x4C) = *v;
}

EXTERN_C Vec4 func_800DDED0(void *self)
{
    return FIELD_AT(self, Vec4, 0x4C);
}

EXTERN_C void func_800DDEFC(void *self)
{
    FIELD_AT(self, char, 0x7C) = 1;
}

EXTERN_C void func_80039DD8(void *obj);

EXTERN_C void func_800DDF08(void *self, Vec4 v)
{
    void *obj = FIELD_AT(self, void *, 0x28);
    FIELD_AT(obj, Vec4, 0x34) = v;
    func_80039DD8(obj);
}

EXTERN_C IdArray *func_800DDF58(IdArray *self, short id, short count, short def)
{
    idnode_init(self, id);
    self->vptr = D_800D6408;
    self->count = count;
    self->def = def;
    self->data = func_800A0D2C(count * sizeof(Color));
    return self;
}

struct Col_800DDFC0 {
    unsigned char x, y, z, w;
    Col_800DDFC0() {}
};

EXTERN_C void func_800DE0E4(void *self, int i, Color c);

inline Col_800DDFC0 *elem_800DDFC0(IdArray *self, int i)
{
    if (i >= self->count)
        return &((Col_800DDFC0 *)self->data)[self->def];
    return &((Col_800DDFC0 *)self->data)[i];
}

EXTERN_C IdArray *func_800DDFC0(IdArray *self, IdArray *other)
{
    int i;
    idnode_init(self, other->id);
    self->vptr = D_800D6408;
    self->def = other->def;
    self->count = other->count;
    self->data = func_800A0D2C(self->count * sizeof(Col_800DDFC0));
    i = 0;
    while (1) {
        if (!(i < self->count))
            break;
        ((void (*)(void *, int, Col_800DDFC0))func_800DE0E4)(self, i, *elem_800DDFC0(other, i));
        i++;
    }
    return self;
}

EXTERN_C void func_800DE0E4(void *self, int i, Color c)
{
    func_800DE108(self, i, &c);
}

EXTERN_C void func_800DE108(void *self, int i, Color *c)
{
    FIELD_AT(self, Color *, 0xC)[i] = *c;
}

EXTERN_C void func_800DE12C(IdNode *self, int flags)
{
    self->vptr = D_800D6408;
    if (FIELD_AT(self, void *, 0xC))
        func_800A0D0C(FIELD_AT(self, void *, 0xC));
    func_800D67CC(self, flags);
}

EXTERN_C IdArray *func_800DE180(IdArray *self, short id, short count, short def)
{
    idnode_init(self, id);
    self->vptr = D_800D63F8;
    self->count = count;
    self->def = def;
    self->data = func_800A0D2C(count * sizeof(SVec4));
    return self;
}

struct SV_800DE1E8 {
    short x, y, z, w;
    SV_800DE1E8() {}
};

EXTERN_C void func_800DE364(void *self, int i, SVec4 c);

inline SV_800DE1E8 *elem_800DE1E8(IdArray *self, int i)
{
    if (i >= self->count)
        return &((SV_800DE1E8 *)self->data)[self->def];
    return &((SV_800DE1E8 *)self->data)[i];
}

EXTERN_C IdArray *func_800DE1E8(IdArray *self, IdArray *other)
{
    int i;
    idnode_init(self, other->id);
    self->vptr = D_800D63F8;
    self->def = other->def;
    self->count = other->count;
    self->data = func_800A0D2C(self->count * sizeof(SV_800DE1E8));
    i = 0;
    while (1) {
        if (!(i < self->count))
            break;
        ((void (*)(void *, int, SV_800DE1E8))func_800DE364)(self, i, *elem_800DE1E8(other, i));
        i++;
    }
    return self;
}

EXTERN_C void func_800DE310(IdNode *self, int flags)
{
    self->vptr = D_800D63F8;
    if (FIELD_AT(self, void *, 0xC))
        func_800A0D0C(FIELD_AT(self, void *, 0xC));
    func_800D67CC(self, flags);
}

EXTERN_C void func_800DE364(void *self, int i, SVec4 v)
{
    func_800DE38C(self, i, &v);
}

EXTERN_C void func_800DE38C(void *self, int i, SVec4 *v)
{
    FIELD_AT(self, SVec4 *, 0xC)[i] = *v;
}

EXTERN_C int D_800D63E8[];
EXTERN_C char D_800106EC[];
EXTERN_C char D_80010624[];
EXTERN_C char D_80010888[];
EXTERN_C char D_800108A0[];
EXTERN_C char D_800B4C48[];
EXTERN_C void *D_800B4C18[];
EXTERN_C Poly *D_800B4C38[];
EXTERN_C void *memset(void *p, int c, unsigned n);
EXTERN_C void func_80021F48(void *, void *);
EXTERN_C void func_80024CA0(void *self, void *buf, int w, int h);
EXTERN_C void func_80025444(void *a, void *b, int c);
EXTERN_C void func_8001ED2C(void *self, int a, int b);

struct Pal_800DE3BC {
    char *vptr;
    int next;
    short a, b;
};

struct Pair_800DE3BC {
    short a, b;
    Pair_800DE3BC(short aa, short ab) : a(aa), b(ab) {}
};

struct Wrap_800DE3BC {
    int pad;
    Pair_800DE3BC p;
    int pad2;
    Wrap_800DE3BC() : p(-1, -1) {}
};

struct Img_800DE3BC {
    char *vptr;
    int next;
    char *vptr8;
    Pal_800DE3BC *pal;
    Pair_800DE3BC xy;
    short w, h;
    int w18;
    short s1C, s1E;
};

EXTERN_C IdNode *func_800DE3BC(IdNode *self, short count, int unused, short c)
{
    void *buf;
    void *buf2;
    Pal_800DE3BC *o;
    Img_800DE3BC *m;
    idnode_init(self, 0);
    self->vptr = D_800D63E8;
    FIELD_AT(self, short, 0xC) = c;
    FIELD_AT(self, short, 0xE) = count;
    FIELD_AT(self, int, 0x10) = 0;
    FIELD_AT(self, short, 0x20) = 0;
    buf = func_800A0D2C(0x200);
    memset(buf, 0xFF, 0x200);
    o = (Pal_800DE3BC *)operator new(0x20C);
    o->vptr = (char *)D_80010178;
    o->next = 0;
    o->vptr = D_800106EC;
    o->a = 0;
    o->b = 0;
    o->vptr = D_80010624;
    func_80021F48(o, buf);
    {
        Poly *p = D_800B4C38[0];
        VtEntry *vt = FIELD_AT(p, VtEntry *, 0x10);
        vt[1].pfn((char *)p + vt[1].delta, (int)o);
    }
    buf2 = func_800A0D2C(0x100);
    memset(buf2, 0, 0x100);
    m = (Img_800DE3BC *)operator new(0x20);
    m->vptr = (char *)D_80010178;
    m->next = 0;
    m->vptr8 = D_80010888;
    m->vptr = D_800108A0;
    m->pal = o;
    m->xy = Wrap_800DE3BC().p;
    m->w = 0;
    m->h = 0;
    m->w18 = 0;
    m->s1E = 0;
    FIELD_AT(self, void *, 0x24) = m;
    func_80024CA0(m, buf2, 16, 16);
    func_80025444(D_800B4C48, FIELD_AT(self, void *, 0x24), 3);
    func_8001ED2C(D_800B4C18[0], 1, 3);
    if (buf)
        func_800A0D0C(buf);
    if (buf2)
        func_800A0D0C(buf2);
    FIELD_AT(self, int, 0x14) = 0;
    FIELD_AT(self, int, 0x18) = 0;
    FIELD_AT(self, void *, 0x1C) = func_800A0D2C(FIELD_AT(self, short, 0xE) * sizeof(Color));
    return self;
}

EXTERN_C int D_800D63E8[];

struct Col_800DE5B0 {
    unsigned char r, g, b, a;
    Col_800DE5B0() {}
};

EXTERN_C void func_800DE780(void *self, int i, Color c);

EXTERN_C void *func_800DE5B0(void *self, void *other)
{
    int i;
    idnode_init((IdNode *)self, 0);
    ((IdNode *)self)->vptr = D_800D63E8;
    FIELD_AT(self, short, 0xC) = FIELD_AT(other, short, 0xC);
    FIELD_AT(self, short, 0xE) = FIELD_AT(other, short, 0xE);
    FIELD_AT(self, int, 0x10) = 0;
    FIELD_AT(self, short, 0x20) = 0;
    FIELD_AT(self, int, 0x24) = FIELD_AT(other, int, 0x24);
    FIELD_AT(self, int, 0x14) = 0;
    FIELD_AT(self, int, 0x18) = 0;
    FIELD_AT(self, void *, 0x1C) = func_800A0D2C(FIELD_AT(self, short, 0xE) * sizeof(Color));
    i = 0;
    while (1) {
        if (!(i < FIELD_AT(self, short, 0xE)))
            break;
        ((void (*)(void *, int, Col_800DE5B0))func_800DE780)(self, i, *(Col_800DE5B0 *)color_at(other, i));
        i++;
    }
    return self;
}

EXTERN_C int D_800D63E8[];
struct S_800DEA54;
EXTERN_C void func_800DEA54(S_800DEA54 *self, int arg);

EXTERN_C void func_800DE6E8(IdNode *self, int flags)
{
    Poly *p;
    self->vptr = D_800D63E8;
    p = FIELD_AT(self, Poly *, 0x24);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    if (FIELD_AT(self, void *, 0x18))
        func_800DEA54((S_800DEA54 *)self, 1);
    if (FIELD_AT(self, void *, 0x1C))
        func_800A0D0C(FIELD_AT(self, void *, 0x1C));
    func_800D67CC(self, flags);
}

EXTERN_C void func_800DE780(void *self, int i, Color c)
{
    func_800DE7A4(self, i, &c);
}

EXTERN_C void func_800DE7A4(void *self, int i, Color *c)
{
    FIELD_AT(self, Color *, 0x1C)[i] = *c;
}

EXTERN_C int func_800DE7C8(void *self, short i)
{
    signed char a;
    if (i > FIELD_AT(self, short, 0xC))
        return 0;
    a = ((signed char *)color_at(self, i))[3];
    if (a == 4 || a == 0x63)
        return 0;
    return FIELD_AT(self, int, 0x10) == 0;
}

EXTERN_C int func_800DE83C(void *self, short i)
{
    return color_at(self, i)->a == 4;
}

EXTERN_C int func_800DE884(void *self, short i)
{
    return color_at(self, i)->a == 0x63;
}

EXTERN_C int D_80011A44[];
EXTERN_C int D_80011AAC[];
EXTERN_C int D_80011B14[];
EXTERN_C int D_80011D04[];
EXTERN_C int D_80011D6C[];
EXTERN_C int D_80011E8C[];
EXTERN_C int D_80011EF4[];
EXTERN_C int D_800D6468[];
EXTERN_C int D_800D6418[];

struct SV_800DEF14 {
    short x, y, z, w;
    SV_800DEF14() { x = 0; y = 0; z = 0; w = 0; }
};

struct UV_800DEF14 {
    unsigned int uv;
    UV_800DEF14() {}
};

struct FT4_800DEF14 {
    unsigned char addr[3], len;
    unsigned char r0, g0, b0, code;
    short x0, y0;
    unsigned int uv0;
    short x1, y1;
    unsigned int uv1;
    short x2, y2;
    unsigned int uv2;
    short x3, y3;
    unsigned int uv3;
    FT4_800DEF14() { len = 9; code = 0x2C; }
};

struct RGBC_800DEF14 {
    unsigned char r, g, b, code;
};

struct Tex_800DEF14 {
    unsigned int word;
    UV_800DEF14 uv[4];
    FT4_800DEF14 prim[2];
    Tex_800DEF14() : word(0x2C808080) {}
};

struct A_800DEF14 {
    int *vptr;
    int next;
    int *vptr8;
    A_800DEF14() { vptr = D_80010178; vptr8 = D_80011A44; next = 0; }
};

struct L1_800DEF14 : A_800DEF14 {
    SV_800DEF14 v;
    L1_800DEF14() {}
};

struct L2v_800DEF14 : L1_800DEF14 {
    L2v_800DEF14() { vptr8 = D_80011AAC; vptr = D_80011B14; }
};

struct L2_800DEF14 : L2v_800DEF14 {
    SV_800DEF14 a[4];
    L2_800DEF14() {}
};

struct L3v_800DEF14 : L2_800DEF14 {
    L3v_800DEF14() { vptr8 = D_80011D04; vptr = D_80011D6C; }
};

struct L3_800DEF14 : L3v_800DEF14 {
    Tex_800DEF14 tex;
    L3_800DEF14() {}
};

struct L4_800DEF14 : L3_800DEF14 {
    L4_800DEF14() { vptr8 = D_80011E8C; vptr = D_80011EF4; }
};

struct L5_800DEF14 : L4_800DEF14 {
    L5_800DEF14() { vptr8 = D_800D6468; vptr = D_800D6418; }
};

struct C_800DEF14 : L5_800DEF14 {
    int otz;
    unsigned short clut, tpage;
    int wA0;
    C_800DEF14(void *g, unsigned short clut, unsigned short tpage);
};

struct UV_800DF1DC {
    unsigned char u, v;
} __attribute__((aligned(2)));

struct UVX_800DE8CC {
    unsigned char u, v;
    UVX_800DE8CC(int au, int av) : u(au), v(av) {}
};

EXTERN_C void *func_8003BEF8(void *p);
EXTERN_C void func_80039BEC(void *self, int b);
EXTERN_C void func_800DF1DC(void *self, UV_800DF1DC *base);
EXTERN_C void func_800DF27C(void *self, unsigned char *rgb);

EXTERN_C void func_800DE8CC(void *self, short i)
{
    Poly *p;
    void *n;
    char *g;
    void *q;
    Poly *t;
    int u;
    FIELD_AT(self, int, 0x10) = 1;
    p = FIELD_AT(self, Poly *, 0x18);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    n = func_8003BEF8(operator new(0x4C));
    g = (char *)D_800B4ED8[0];
    FIELD_AT(self, void *, 0x18) = n;
    func_80039BEC(g ? g + 0x50 : 0, (int)n);
    FIELD_AT(self, void *, 0x14) = new C_800DEF14(D_800B4ED8[0],
                                                 FIELD_AT(FIELD_AT(FIELD_AT(self, void *, 0x24), void *, 0xC), unsigned short, 0x8),
                                                 FIELD_AT(FIELD_AT(self, void *, 0x24), unsigned short, 0x1C));
    q = FIELD_AT(self, void *, 0x24);
    t = FIELD_AT(q, Poly *, 0xC);
    if (!t)
        u = FIELD_AT(q, short, 0x10) & 0x3F;
    else if (((int (*)(void *))t->vptr[3].pfn)((char *)t + t->vptr[3].delta))
        u = (FIELD_AT(q, short, 0x10) << 1) & 0x7F;
    else
        u = FIELD_AT(q, short, 0x10) << 2;
    {
        struct { unsigned char u, v; } uv;
        int v = FIELD_AT(q, short, 0x12);
        uv.u = u;
        uv.v = v;
        func_800DF1DC(FIELD_AT(self, void *, 0x14), (UV_800DF1DC *)&uv);
    }
    func_800DF27C(FIELD_AT(self, void *, 0x14), (unsigned char *)color_at(self, i));
    p = FIELD_AT(self, Poly *, 0x18);
    p->vptr[5].pfn((char *)p + p->vptr[5].delta, (int)FIELD_AT(self, void *, 0x14));
}

EXTERN_C int D_800D63A0[];
EXTERN_C char D_80010338[];
EXTERN_C char D_800A4544[];
EXTERN_C void func_8001D150(void *, void *);

struct L_800DEA54 {
    void *vptr;
    int next;
    void *owner;
    short prio;
    int on;
};

struct X_800DEA54 {
    int *vptr;
    int b;
    int a;
    X_800DEA54(int aa, int ab)
    {
        char *l;
        L_800DEA54 *o;
        vptr = D_800D63A0;
        b = ab;
        a = aa;
        l = D_800A4544;
        o = (L_800DEA54 *)operator new(0x14);
        o->vptr = D_80010178;
        o->next = 0;
        o->vptr = D_80010338;
        o->owner = this;
        o->prio = 0x80;
        o->on = 1;
        func_8001D150(l, o);
        int *cnt = D_800E5844;
        (*cnt)++;
    }
};

struct O_800DEA54 {
    virtual ~O_800DEA54();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void stop(int id);
};

struct S_800DEA54 {
    char pad[0x10];
    int w10;
    int id;
    O_800DEA54 *obj;
};

EXTERN_C void func_800DEA54(S_800DEA54 *self, int arg)
{
    self->w10 = 0;
    if (self->obj) {
        self->obj->stop(self->id);
        new X_800DEA54(self->id, 1);
        delete self->obj;
        self->obj = 0;
        self->id = 0;
    }
}

struct S_800DEA54;
EXTERN_C void func_800DEA54(S_800DEA54 *self, int arg);
EXTERN_C void func_800DF27C(void *self, unsigned char *rgb);

EXTERN_C void func_800DEB64(void *self, short i)
{
    if (i > FIELD_AT(self, short, 0xC)) {
        if (FIELD_AT(self, void *, 0x14))
            func_800DEA54((S_800DEA54 *)self, 0);
    } else {
        func_800DF27C(FIELD_AT(self, void *, 0x14), (unsigned char *)color_at(self, i));
    }
}

EXTERN_C void *func_800DE5B0(void *self, void *arg);

EXTERN_C void *func_800DEBEC(void *arg)
{
    return func_800DE5B0(operator new(0x28), arg);
}

EXTERN_C int func_800DEC20(void *self)
{
    return FIELD_AT(self, int, 0x14) != 0;
}

EXTERN_C IdNode *func_800DEC2C(IdNode *self, short id)
{
    return func_800D67F4(self, id);
}

EXTERN_C Color *func_800DEC50(void *self, int i)
{
    Color *p;
    if (i < FIELD_AT(self, short, 0xE))
        p = &FIELD_AT(self, Color *, 0x1C)[i];
    else
        p = &FIELD_AT(self, Color *, 0x1C)[FIELD_AT(self, short, 0x20)];
    return p;
}

struct Iter_800DEC88 {
    void *arr;
    int idx;
};

inline bool past_end_800DEC88(void *self, int i)
{
    return i >= FIELD_AT(self, short, 0x12);
}

inline SVec4 *svec_at_800DEC88(void *self, int i)
{
    if (i >= FIELD_AT(self, short, 0x12))
        return &FIELD_AT(self, SVec4 *, 0xC)[FIELD_AT(self, short, 0x10)];
    return &FIELD_AT(self, SVec4 *, 0xC)[i];
}

EXTERN_C SVec4 func_800DEC88(Iter_800DEC88 *it, int step)
{
    SVec4 c;
    if (past_end_800DEC88(it->arr, it->idx))
        it->idx = FIELD_AT(it->arr, short, 0x10);
    c = *svec_at_800DEC88(it->arr, it->idx);
    it->idx += step;
    return c;
}

EXTERN_C void *func_800DED48(void *self, int value)
{
    FIELD_AT(self, int, 0x0) = value;
    FIELD_AT(self, int, 0x4) = 0;
    return self;
}

EXTERN_C int func_800DED58(void *self)
{
    return FIELD_AT(self, short, 0x10);
}

EXTERN_C int func_800DED64(void *self, int value)
{
    return value >= FIELD_AT(self, short, 0x12);
}

EXTERN_C IdNode *func_800DED78(IdNode *self, short id)
{
    return func_800D67F4(self, id);
}

EXTERN_C SVec4 *func_800DED9C(void *self, int i)
{
    SVec4 *p;
    if (i < FIELD_AT(self, short, 0x12))
        p = &FIELD_AT(self, SVec4 *, 0xC)[i];
    else
        p = &FIELD_AT(self, SVec4 *, 0xC)[FIELD_AT(self, short, 0x10)];
    return p;
}

EXTERN_C int func_800DEDD4(void *self)
{
    return FIELD_AT(self, int, 0x0);
}

struct Iter_800DEDE0 {
    void *arr;
    int idx;
};

inline bool past_end_800DEDE0(void *self, int i)
{
    return i >= FIELD_AT(self, short, 0x12);
}

inline Color *colors_at_800DEDE0(void *self, int i)
{
    if (i >= FIELD_AT(self, short, 0x12))
        return &FIELD_AT(self, Color *, 0xC)[FIELD_AT(self, short, 0x10)];
    return &FIELD_AT(self, Color *, 0xC)[i];
}

EXTERN_C Color func_800DEDE0(Iter_800DEDE0 *it, int step)
{
    Color c;
    if (past_end_800DEDE0(it->arr, it->idx))
        it->idx = FIELD_AT(it->arr, short, 0x10);
    c = *colors_at_800DEDE0(it->arr, it->idx);
    it->idx += step;
    return c;
}

EXTERN_C void *func_800DEE88(void *self, int value)
{
    FIELD_AT(self, int, 0x0) = value;
    FIELD_AT(self, int, 0x4) = 0;
    return self;
}

EXTERN_C int func_800DEE98(void *self)
{
    return FIELD_AT(self, short, 0x10);
}

EXTERN_C int func_800DEEA4(void *self, int value)
{
    return value >= FIELD_AT(self, short, 0x12);
}

EXTERN_C IdNode *func_800DEEB8(IdNode *self, short id)
{
    return func_800D67F4(self, id);
}

EXTERN_C Color *func_800DEEDC(void *self, int i)
{
    Color *p;
    if (i < FIELD_AT(self, short, 0x12))
        p = &FIELD_AT(self, Color *, 0xC)[i];
    else
        p = &FIELD_AT(self, Color *, 0xC)[FIELD_AT(self, short, 0x10)];
    return p;
}

C_800DEF14::C_800DEF14(void *g, unsigned short aclut, unsigned short atpage)
{
    VtEntry *vt;
    int z;
    wA0 = 1;
    ((RGBC_800DEF14 *)&tex)->r = 0x80;
    ((RGBC_800DEF14 *)&tex)->g = 0x80;
    ((RGBC_800DEF14 *)&tex)->b = 0x80;
    ((RGBC_800DEF14 *)&tex)->code = 0x2E;
    vt = FIELD_AT(g, VtEntry *, 0x2C);
    z = FIELD_AT(((void *(*)(void *))vt[12].pfn)((char *)g + vt[12].delta), int, 0x10);
    clut = aclut;
    tpage = atpage;
    tex.prim[0].len = 9;
    tex.prim[0].code = 0x2C;
    tex.prim[1].len = 9;
    tex.prim[1].code = 0x2C;
    otz = z - 14;
}

struct FT4_800DF0C4 {
    Tag_800DF0C4 tag;
    unsigned char r0, g0, b0, code;
    short x0, y0;
    unsigned int uv0;
    short x1, y1;
    unsigned int uv1;
    short x2, y2;
    unsigned int uv2;
    short x3, y3;
    unsigned int uv3;
};

struct Head_800DF0C4 {
    char pad[0x34];
};

struct Tex_800DF0C4 {
    unsigned char r, g, b, a;
    unsigned int uv[4];
};

struct Obj_800DF0C4 : Head_800DF0C4, Tex_800DF0C4 {
    FT4_800DF0C4 prim[2];
    unsigned int otz;
};

EXTERN_C int D_800B4CF0[];
EXTERN_C OT_800DF0C4 *D_800B4D00[];

EXTERN_C void func_800DF0C4(Obj_800DF0C4 *self)
{
    FT4_800DF0C4 *p = &self->prim[D_800B4CF0[0]];
    Tex_800DF0C4 *t;
    unsigned int o;
    OT_800DF0C4 *d;
    p->tag.len = 9;
    p->code = 0x2C;
    p->r0 = self->r;
    p->g0 = self->g;
    p->b0 = self->b;
    p->code = 0x2E;
    p->x0 = 0;
    p->y0 = 0;
    p->x1 = 320;
    p->y1 = 0;
    p->x2 = 0;
    p->y2 = 240;
    p->x3 = 320;
    p->y3 = 240;
    t = self;
    {
        unsigned int a = t->uv[0], b = t->uv[1], c = t->uv[2], e = t->uv[3];
        p->uv0 = a;
        p->uv1 = b;
        p->uv2 = c;
        p->uv3 = e;
    }
    o = self->otz;
    d = D_800B4D00[0];
    if (o && o < d->size) {
        p->tag.addr = d->ot[o].addr;
        *(unsigned int *)&d->ot[o] = (unsigned int)p & 0x00FFFFFF;
    }
}

EXTERN_C int func_800DF1D4(void *self)
{
    return 1;
}

struct UVC_800DF1DC : UV_800DF1DC {
    UVC_800DF1DC() {}
};

struct UVE_800DF1DC {
    unsigned char u, v;
    unsigned short extra;
};

EXTERN_C void func_800DF1DC(void *self, UV_800DF1DC *base)
{
    UVC_800DF1DC ofs[4];
    UVE_800DF1DC *out;
    UV_800DF1DC *o;
    int i;
    i = 0;
    out = &FIELD_AT(self, UVE_800DF1DC, 0x38);
    ofs[0].u = 0;
    ofs[0].v = 0;
    ofs[1].u = 14;
    ofs[1].v = 0;
    ofs[2].u = 0;
    ofs[2].v = 14;
    ofs[3].u = 14;
    ofs[3].v = 14;
    UV_800DF1DC b = *base;
    o = ofs;
    for (; i < 4; i++, out++) {
        UV_800DF1DC t = *o++;
        out->u = t.u + b.u;
        out->v = t.v + b.v;
    }
    FIELD_AT(self, unsigned short, 0x3A) = FIELD_AT(self, unsigned short, 0x9C);
    FIELD_AT(self, unsigned short, 0x3E) = FIELD_AT(self, unsigned short, 0x9E);
}

EXTERN_C void func_800DF27C(void *self, unsigned char *rgb)
{
    Poly *p;
    FIELD_AT(self, unsigned char, 0x34) = rgb[0];
    FIELD_AT(self, unsigned char, 0x35) = rgb[1];
    FIELD_AT(self, unsigned char, 0x36) = rgb[2];
    p = (Poly *)((char *)self + 0x8);
    p->vptr[10].pfn((char *)p + p->vptr[10].delta, rgb[3]);
}

/* Tag/FT4/OT/Head/Tex/Obj_800DF0C4 and the two externs: copied verbatim from src/effect/effect.cpp
   (func_800DF0C4) for a standalone build; drop them when pasting into the unit. */
EXTERN_C int D_800B4CF0[];
EXTERN_C OT_800DF0C4 *D_800B4D00[];

inline int add_800DF2D8(OT_800DF0C4 *d, unsigned int o, FT4_800DF0C4 *p)
{
    if (o && o < d->size) {
        p->tag.addr = *(unsigned int *)&d->ot[o];
        *(unsigned int *)&d->ot[o] = (unsigned int)p & 0x00FFFFFF;
        return 1;
    }
    return 0;
}

EXTERN_C int func_800DF2D8(Obj_800DF0C4 *self)
{
    FT4_800DF0C4 *p = &self->prim[D_800B4CF0[0]];
    Tex_800DF0C4 *t;
    p->tag.len = 9;
    p->code = 0x2C;
    p->r0 = self->r;
    p->g0 = self->g;
    p->b0 = self->b;
    p->code = 0x2E;
    p->x0 = 0;
    p->y0 = 0;
    p->x1 = 320;
    p->y1 = 0;
    p->x2 = 0;
    p->y2 = 240;
    p->x3 = 320;
    p->y3 = 240;
    t = self;
    {
        unsigned int a = t->uv[0], b = t->uv[1], c = t->uv[2], e = t->uv[3];
        p->uv0 = a;
        p->uv1 = b;
        p->uv2 = c;
        p->uv3 = e;
    }
    return add_800DF2D8(D_800B4D00[0], self->otz, p);
}

EXTERN_C void func_800DF3EC(void *self)
{
}

EXTERN_C int D_800D6468[];
EXTERN_C int D_800D6418[];
EXTERN_C int D_80011E8C[];
EXTERN_C int D_80011EF4[];
EXTERN_C int D_80011D04[];
EXTERN_C int D_80011D6C[];
EXTERN_C int D_80011AAC[];
EXTERN_C int D_80011B14[];
EXTERN_C void func_800198AC(void *, int);

EXTERN_C void func_800DF3F4(void *self, int flags)
{
    FIELD_AT(self, int *, 0x8) = D_800D6468;
    FIELD_AT(self, int *, 0x0) = D_800D6418;
    FIELD_AT(self, int *, 0x8) = D_80011E8C;
    FIELD_AT(self, int *, 0x0) = D_80011EF4;
    FIELD_AT(self, int *, 0x8) = D_80011D04;
    FIELD_AT(self, int *, 0x0) = D_80011D6C;
    FIELD_AT(self, int *, 0x8) = D_80011AAC;
    FIELD_AT(self, int *, 0x0) = D_80011B14;
    func_800198AC((char *)self + 0x8, 0);
    func_8001A610((IdNode *)self, flags);
}

EXTERN_C void *func_800DF498(void *self)
{
    func_800E3EB4(self);
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, short, 0x10) = 0;
    FIELD_AT(self, int, 0x4) = 0;
    return self;
}

EXTERN_C void func_800DF4CC(void *self, int flags)
{
    func_800E3ED4(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF4EC);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D62B0);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D62E0);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6310);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6340);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6370);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D63A0);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D63B8);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D63D0);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D63E8);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D63F8);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6408);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6418);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6468);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF974);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DFEBC);
