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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7524);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D75D4);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7CB0);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D80D8);

EXTERN_C void func_800D8354(KeyInt *self, int flags)
{
    self->vptr = D_800D6138;
    func_800D7C50(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D837C);

EXTERN_C void func_800D85AC(KeyInt *self, int flags)
{
    self->vptr = D_800D6110;
    func_800D7C50(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D85D4);

EXTERN_C void func_800D8804(KeyInt *self, int flags)
{
    self->vptr = D_800D60E8;
    func_800D7C50(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D882C);

EXTERN_C void func_800D8A44(KeyInt *self, int flags)
{
    self->vptr = D_800D60C0;
    func_800D7C50(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D8A6C);

EXTERN_C void func_800D8DC0(KeyInt *self, int flags)
{
    self->vptr = D_800D6098;
    func_800D7C50(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D8DE8);

EXTERN_C void func_800D8FF0(KeyVec *self, int flags)
{
    self->vptr = D_800D6070;
    func_800D8050(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9018);

EXTERN_C void func_800D9324(KeyVec *self, int flags)
{
    self->vptr = D_800D6048;
    func_800D8050(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D934C);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9928);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DA03C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DA170);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DA35C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DA494);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DA514);

EXTERN_C int func_800DA584(SlotSet *self)
{
    int i;
    for (i = 0; i < 8; i++)
        if (self->slots[i] == 0)
            return i;
    return -1;
}

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D5DAC);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D5DB0);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D5DC0);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D5E18);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D5E70);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D5EC8);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D5F20);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D5F78);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D5FD0);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6038);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6048);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6070);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6098);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D60C0);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D60E8);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6110);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6138);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6160);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6188);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAD80);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB0FC);

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
EXTERN_C void func_800DEA54(void *self, int arg);
EXTERN_C void func_800DEB64(void *self, short i);

EXTERN_C void func_800DDA4C(void *self)
{
    if (FIELD_AT(self, void *, 0x8)) {
        if (func_800DE884(FIELD_AT(self, void *, 0x8), FIELD_AT(self, short, 0x6E))) {
            if (FIELD_AT(FIELD_AT(self, void *, 0x8), void *, 0x14))
                func_800DEA54(FIELD_AT(self, void *, 0x8), 0);
        } else if (func_800DE7C8(FIELD_AT(self, void *, 0x8), FIELD_AT(self, short, 0x6E))) {
            func_800DE8CC(FIELD_AT(self, void *, 0x8), FIELD_AT(self, short, 0x6E));
        } else if (func_800DE83C(FIELD_AT(self, void *, 0x8), FIELD_AT(self, short, 0x6E))) {
            func_800DEA54(FIELD_AT(self, void *, 0x8), 0);
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
EXTERN_C void func_800DEA54(void *self, int arg);

EXTERN_C void func_800DE6E8(IdNode *self, int flags)
{
    Poly *p;
    self->vptr = D_800D63E8;
    p = FIELD_AT(self, Poly *, 0x24);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    if (FIELD_AT(self, void *, 0x18))
        func_800DEA54(self, 1);
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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE8CC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEA54);

EXTERN_C void func_800DEA54(void *self, int arg);
EXTERN_C void func_800DF27C(void *self, unsigned char *rgb);

EXTERN_C void func_800DEB64(void *self, short i)
{
    if (i > FIELD_AT(self, short, 0xC)) {
        if (FIELD_AT(self, void *, 0x14))
            func_800DEA54(self, 0);
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

struct Tag_800DF0C4 {
    unsigned addr : 24;
    unsigned len : 8;
};

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

struct OT_800DF0C4 {
    char pad[0x10];
    unsigned int size;
    Tag_800DF0C4 *ot;
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

struct UV_800DF1DC {
    unsigned char u, v;
} __attribute__((aligned(2)));

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF2D8);

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

EXTERN_C void *func_800E0188(void *self, int n)
{
    void *p = FIELD_AT(self, void *, 0x0);
    int i = 0;
    while (i < n) {
        i++;
        p = FIELD_AT(p, void *, 0x4);
    }
    return p;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E01B0);

EXTERN_C void *func_800E01B0(int a, short b, void *c);

EXTERN_C void *func_800E02F4(void *self, void *arg)
{
    int id = FIELD_AT(self, short, 0x4);
    VtEntry *vt = FIELD_AT(self, VtEntry *, 0x8);
    void *p = func_800E01B0(id, ((short (*)(void *))vt[9].pfn)((char *)self + vt[9].delta), arg);
    vt = FIELD_AT(p, VtEntry *, 0x8);
    vt[7].pfn((char *)p + vt[7].delta, (int)self);
    return p;
}

EXTERN_C void *func_800E037C(void *self)
{
    return self;
}

EXTERN_C int D_800D6604[];
EXTERN_C void *func_800E4058(void *self, void *other);

struct RV_800E0384 {
    short base, step, range, phase, spread;
    int *vptr;
    RV_800E0384()
    {
        vptr = D_800D6038;
        base = 0;
        step = 0;
        range = 0;
        phase = 0;
    }
};

struct A_800E0384 {
    int *vptr;
    int next;
    A_800E0384() { vptr = D_80010178; next = 0; }
};

struct B_800E0384 : A_800E0384 {
    short id;
    B_800E0384(short aid) { vptr = D_800D5DB0; id = aid; }
};

struct V_800E0384 : B_800E0384 {
    V_800E0384(short aid) : B_800E0384(aid) { vptr = D_800D6604; }
};

struct C_800E0384 : V_800E0384 {
    short sC, sE, s10, s12, s14;
    short pad16;
    int w18, w1C, w20, w24;
    int pad28;
    int w2C, w30, w34, w38;
    RV_800E0384 rv;
    int w4C, w50, w54, w58;
    char m5C[0x10];
    int w6C, w70;
    short s74, s76, s78, s7A, s7C, s7E;
    C_800E0384(short aid);
};

C_800E0384::C_800E0384(short aid) : V_800E0384(aid), w24(1)
{
    func_800E4058(m5C, 0);
    w2C = 0;
    w30 = 0;
    w34 = 0;
    w38 = 0;
    w4C = 0;
    w58 = 0;
    w50 = 0;
    w54 = 0;
    w6C = 0;
    s74 = 0;
    s76 = 0;
    w70 = 0;
    s78 = 0;
    s7A = 0;
    s7C = 0;
    s7E = 0;
    s10 = 0;
    sC = 0;
    sE = 0;
    s14 = 0;
    w18 = 0;
    w1C = 0;
    w20 = 0;
    s12 = 0;
}

EXTERN_C int D_800D6604[];
EXTERN_C void *func_800E4058(void *self, void *other);
EXTERN_C void *func_800E41B8(void *self, void *other);
EXTERN_C IdArray *func_800DDFC0(IdArray *self, IdArray *other);
EXTERN_C IdArray *func_800DE1E8(IdArray *self, IdArray *other);

/* Copy constructor of the C_800E0384 class (same layout; own type names so it can be
   pasted next to it). */
struct RV_800E0468 {
    short base, step, range, phase, spread;
    int *vptr;
    RV_800E0468()
    {
        vptr = D_800D6038;
        base = 0;
        step = 0;
        range = 0;
        phase = 0;
    }
};

struct A_800E0468 {
    int *vptr;
    int next;
    A_800E0468() { vptr = D_80010178; next = 0; }
};

struct B_800E0468 : A_800E0468 {
    short id;
    B_800E0468(short aid) { vptr = D_800D5DB0; id = aid; }
};

struct V_800E0468 : B_800E0468 {
    V_800E0468(short aid) : B_800E0468(aid) { vptr = D_800D6604; }
};

struct C_800E0468 : V_800E0468 {
    short sC, sE, s10, s12, s14;
    short pad16;
    int w18, w1C, w20, w24;
    int w28;
    void *p2C, *p30;
    IdArray *p34, *p38;
    RV_800E0468 rv;
    int w4C, w50, w54, w58;
    char m5C[0x10];
    int w6C, w70;
    short s74, s76, s78, s7A, s7C, s7E;
    short s80, s82, s84;
    unsigned char c86, c87, c88;
    C_800E0468(const C_800E0468 &o);
};

C_800E0468::C_800E0468(const C_800E0468 &o) : V_800E0468(o.id), w24(0)
{
    func_800E4058(m5C, 0);
    w28 = o.w28;
    p2C = 0;
    p30 = 0;
    p34 = func_800DDFC0((IdArray *)operator new(0x14), o.p34);
    p38 = func_800DE1E8((IdArray *)operator new(0x14), o.p38);
    rv = o.rv;
    w4C = 0;
    w50 = 0;
    w54 = 0;
    w58 = 0;
    w6C = o.w6C;
    s74 = o.s74;
    s76 = o.s76;
    w70 = o.w70;
    s78 = o.s78;
    s7A = o.s7A;
    s7C = o.s7C;
    s7E = o.s7E;
    func_800E41B8(m5C, (void *)o.m5C);
    c86 = o.c86;
    c87 = o.c87;
    c88 = o.c88;
    s10 = 0;
    sC = 0;
    sE = 0;
    s14 = 0;
    w18 = 0;
    w1C = 0;
    w20 = 0;
    s12 = 0;
    s80 = o.s80;
    s82 = o.s82;
    s84 = o.s84;
}

EXTERN_C int D_800D6604[];
EXTERN_C void func_800E40BC(void *self, int flags);

struct P8_800E0638 {
    int pad[2];
    VtEntry *vptr;
};

EXTERN_C void func_800E0638(IdNode *self, int flags)
{
    Poly *p;
    P8_800E0638 *q;
    self->vptr = D_800D6604;
    p = FIELD_AT(self, Poly *, 0x34);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    p = FIELD_AT(self, Poly *, 0x38);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    p = FIELD_AT(self, Poly *, 0x2C);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    p = FIELD_AT(self, Poly *, 0x30);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    p = FIELD_AT(self, Poly *, 0x4C);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    q = FIELD_AT(self, P8_800E0638 *, 0x50);
    if (q)
        q->vptr[1].pfn((char *)q + q->vptr[1].delta, 3);
    q = FIELD_AT(self, P8_800E0638 *, 0x54);
    if (q)
        q->vptr[1].pfn((char *)q + q->vptr[1].delta, 3);
    p = FIELD_AT(self, Poly *, 0x58);
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
    func_800E40BC((char *)self + 0x5C, 2);
    func_800D67CC(self, flags);
}

EXTERN_C int func_800E4130(void *self, short value);
EXTERN_C int func_800E4174(void *self, short value);
EXTERN_C void func_800E41FC(void *self);
EXTERN_C void func_800E424C(void *self);
EXTERN_C void func_800E0BD8(void *self);
EXTERN_C int func_800E0AEC(void *self);
EXTERN_C void func_800E0B60(void *self, int arg);
EXTERN_C void *func_800E0DAC(void *self, void *arg, void *p);
EXTERN_C void func_800E0E20(void *self, void *arg);

inline Vec4 pos_800E07E0(void *n)
{
    return FIELD_AT(n, Vec4, 0x28);
}

EXTERN_C void func_800E07E0(void *self, void *arg, void *owner)
{
    int ok = 0;
    if (FIELD_AT(self, short, 0x10) != 0) {
        ok = 1;
    } else {
        void *p = FIELD_AT(self, void *, 0x54);
        VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
        if (((int (*)(void *))vt[10].pfn)((char *)p + vt[10].delta))
            ok = 1;
    }
    if (ok) {
        void *n;
        if (func_800E4130((char *)self + 0x5C, FIELD_AT(self, short, 0x12)))
            func_800E41FC((char *)self + 0x5C);
        if (func_800E4174((char *)self + 0x5C, FIELD_AT(self, short, 0x12)))
            func_800E424C((char *)self + 0x5C);
        n = FIELD_AT(self, void *, 0x4C);
        Vec4 pos(0, 0, 0, 0);
        func_800E0BD8(self);
        while (n) {
            VtEntry *vt = FIELD_AT(n, VtEntry *, 0x0);
            switch ((short)((int (*)(void *, void *))vt[2].pfn)((char *)n + vt[2].delta, self)) {
            case 0:
                n = FIELD_AT(n, void *, 0x4);
                break;
            case 1:
                if (func_800E0AEC(self)) {
                    pos = pos_800E07E0(n);
                    func_800E0B60(self, (int)&pos);
                }
                n = func_800E0DAC(self, arg, n);
                break;
            case 2:
                if (func_800E0AEC(self)) {
                    pos = pos_800E07E0(n);
                    func_800E0B60(self, (int)&pos);
                }
                if (FIELD_AT(self, signed char, 0x87) == 0) {
                    func_800E0E20(self, arg);
                    n = 0;
                    FIELD_AT(self, int, 0x18) = 0;
                } else {
                    n = func_800E0DAC(self, arg, n);
                }
                goto tail;
            case 3:
                if (func_800E0AEC(self)) {
                    pos = pos_800E07E0(n);
                    func_800E0B60(self, (int)&pos);
                }
            tail:
                FIELD_AT(self, short, 0x10) = 2;
                if (FIELD_AT(self, unsigned char, 0x88) >> 7)
                    FIELD_AT(owner, char, 0x7C) = 1;
                break;
            }
        }
    }
    if (FIELD_AT(self, void *, 0x58))
        func_800E07E0(FIELD_AT(self, void *, 0x58), arg, owner);
    if (FIELD_AT(self, void *, 0x4))
        func_800E07E0(FIELD_AT(self, void *, 0x4), arg, owner);
}

EXTERN_C int func_800E0AEC(void *self)
{
    void *n;
    if (!FIELD_AT(self, void *, 0x58))
        return 0;
    for (n = FIELD_AT(self, void *, 0x58); n; n = FIELD_AT(n, void *, 0x4)) {
        Poly *p = FIELD_AT(n, Poly *, 0x54);
        VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
        if (((int (*)(void *))vt[10].pfn)((char *)p + vt[10].delta))
            return 1;
    }
    return 0;
}

EXTERN_C void func_800E0B60(void *self, int arg)
{
    void *n;
    if (!FIELD_AT(self, void *, 0x58))
        return;
    for (n = FIELD_AT(self, void *, 0x58); n; n = FIELD_AT(n, void *, 0x4)) {
        Poly *p = FIELD_AT(n, Poly *, 0x54);
        VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
        ((void (*)(void *, int))vt[5].pfn)((char *)p + vt[5].delta, arg);
    }
}

EXTERN_C void *func_800E1B24(void *self);

inline int is2_800E0BD8(void *self)
{
    return FIELD_AT(self, short, 0x10) == 2;
}

EXTERN_C void func_800E0BD8(void *self)
{
    Poly *p = FIELD_AT(self, Poly *, 0x54);
    VtEntry *vt;
    FIELD_AT(self, int, 0x18) = 0;
    vt = FIELD_AT(p, VtEntry *, 0x8);
    if (((int (*)(void *))vt[10].pfn)((char *)p + vt[10].delta))
        return;
    FIELD_AT(self, short, 0xC)++;
    FIELD_AT(self, short, 0x12)++;
    switch (FIELD_AT(self, short, 0x80)) {
    case 0:
        if (FIELD_AT(self, short, 0xC) > FIELD_AT(self, short, 0x82)) {
            FIELD_AT(self, int, 0x20) = 1;
            if ((FIELD_AT(self, short, 0xC) = FIELD_AT(self, short, 0x84)) != 0)
                return;
        }
        break;
    case 2:
        if (is2_800E0BD8(self)) {
            FIELD_AT(self, int, 0x20) = 1;
            return;
        }
        break;
    case 1:
    case 3:
    case 4: {
        void *q = func_800E1B24(self);
        if (FIELD_AT(q, int, 0x20) && !FIELD_AT(q, int, 0x4C))
            FIELD_AT(self, int, 0x20) = 1;
        break;
    }
    }
    if (FIELD_AT(self, short, 0xE) == 0)
        FIELD_AT(self, int, 0x18) = 1;
    if (++FIELD_AT(self, short, 0xE) >= FIELD_AT(self, short, 0x7E))
        FIELD_AT(self, short, 0xE) = 0;
}

EXTERN_C int func_800E0D2C(void *self)
{
    int r = 0;
    if (FIELD_AT(self, int, 0x18) != 0)
        r = FIELD_AT(self, int, 0x1C) == 0;
    return r;
}

EXTERN_C short func_800E0D50(void *self)
{
    short step = FIELD_AT(self, short, 0x7A);
    short max = FIELD_AT(self, short, 0x7C);
    if (max == 0)
        return step;
    if (FIELD_AT(self, unsigned short, 0x14) + step >= max) {
        step = max - FIELD_AT(self, unsigned short, 0x14);
        FIELD_AT(self, unsigned short, 0x14) = max;
        FIELD_AT(self, int, 0x1C) = 1;
    } else {
        FIELD_AT(self, unsigned short, 0x14) += step;
    }
    return step;
}

EXTERN_C void func_800E343C(void *self, Poly *p);

EXTERN_C void *func_800E0DAC(void *self, void *arg, void *p)
{
    void *next;
    func_800E343C(p, (Poly *)arg);
    next = FIELD_AT(p, void *, 0x4);
    FIELD_AT(self, Link *, 0x4C) = func_8001A744(FIELD_AT(self, Link *, 0x4C), (Link *)p);
    if (p) {
        Poly *o = (Poly *)p;
        o->vptr[1].pfn((char *)o + o->vptr[1].delta, 3);
    }
    return next;
}

EXTERN_C void *func_800E0DAC(void *self, void *arg, void *p);

EXTERN_C void func_800E0E20(void *self, void *arg)
{
    void *p;
    for (p = FIELD_AT(self, void *, 0x4C); p; p = func_800E0DAC(self, arg, p))
        ;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0E70);

EXTERN_C void *func_800E3518(void *self);
EXTERN_C void *func_800E37F4(void *self);

EXTERN_C void func_800E0FDC(void *self, Poly *p)
{
    void *o;
    if (FIELD_AT(FIELD_AT(self, void *, 0x30), signed char, 0x40))
        o = func_800E37F4(operator new(0x70));
    else
        o = func_800E3518(operator new(0x70));
    ((void (*)(void *, int))p->vptr[5].pfn)((char *)p + p->vptr[5].delta, FIELD_AT(o, int, 0xC));
    if (FIELD_AT(self, Link *, 0x4C))
        func_8001A678(FIELD_AT(self, Link *, 0x4C), (Link *)o);
    else
        FIELD_AT(self, Link *, 0x4C) = (Link *)o;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1090);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1304);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1604);

EXTERN_C void func_800E1AE4(void *self, Link *link)
{
    if (FIELD_AT(self, Link *, 0x58))
        func_8001A678(FIELD_AT(self, Link *, 0x58), link);
    else
        FIELD_AT(self, Link *, 0x58) = link;
}

EXTERN_C void *func_800E1B24(void *self)
{
    Poly *p = FIELD_AT(self, Poly *, 0x54);
    VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
    return ((void *(*)(void *))vt[2].pfn)((char *)p + vt[2].delta);
}

EXTERN_C void func_800E49D8(void *self, void *arg);
EXTERN_C void func_800E4B88(void *self, void *arg);
EXTERN_C int func_8003912C(void *p, int n);

EXTERN_C void func_800E1B60(void *self, void *arg)
{
    void *s;
    func_800E49D8(FIELD_AT(self, void *, 0x2C), arg);
    func_800E4B88(FIELD_AT(self, void *, 0x30), arg);
    s = FIELD_AT(self, void *, 0x50);
    switch (FIELD_AT(s, short, 0x0)) {
    case 0:
        FIELD_AT(s, int, 0x1C) = FIELD_AT(FIELD_AT(self, void *, 0x2C), int, 0x3C);
        break;
    case 1:
        FIELD_AT(FIELD_AT(self, void *, 0x50), int, 0xC) =
            func_8003912C(FIELD_AT(FIELD_AT(arg, void *, 0x4), void *, 0x1B8), 2);
        break;
    case 2:
        FIELD_AT(FIELD_AT(self, void *, 0x50), int, 0xC) =
            func_8003912C(FIELD_AT(FIELD_AT(arg, void *, 0x4), void *, 0x1B8), 5);
        break;
    }
    if (FIELD_AT(self, void *, 0x58))
        func_800E1B60(FIELD_AT(self, void *, 0x58), arg);
    if (FIELD_AT(self, void *, 0x4))
        func_800E1B60(FIELD_AT(self, void *, 0x4), arg);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1C5C);

EXTERN_C void *func_800E1B24(void *self);

EXTERN_C bool func_800E21B8(void *self)
{
    Poly *p;
    VtEntry *vt;
    if (FIELD_AT(self, void *, 0x4) && !func_800E21B8(FIELD_AT(self, void *, 0x4)))
        return false;
    if (FIELD_AT(self, void *, 0x58) && !func_800E21B8(FIELD_AT(self, void *, 0x58)))
        return false;
    p = FIELD_AT(self, Poly *, 0x54);
    vt = FIELD_AT(p, VtEntry *, 0x8);
    if (((int (*)(void *))vt[10].pfn)((char *)p + vt[10].delta)) {
        void *q = func_800E1B24(self);
        if (!FIELD_AT(q, int, 0x20) || FIELD_AT(q, int, 0x4C))
            return false;
        p = FIELD_AT(self, Poly *, 0x54);
        vt = FIELD_AT(p, VtEntry *, 0x8);
        if (((int (*)(void *))vt[4].pfn)((char *)p + vt[4].delta) || FIELD_AT(self, int, 0x4C))
            return false;
        return true;
    }
    if (FIELD_AT(self, int, 0x20) && !FIELD_AT(self, int, 0x4C))
        return true;
    return false;
}

EXTERN_C void func_800E2F2C(void *p);

EXTERN_C void func_800E22E0(void *self)
{
    if (FIELD_AT(self, void *, 0x4C))
        func_800E2F2C(FIELD_AT(self, void *, 0x4C));
    if (FIELD_AT(self, void *, 0x58))
        func_800E22E0(FIELD_AT(self, void *, 0x58));
    if (FIELD_AT(self, void *, 0x4))
        func_800E22E0(FIELD_AT(self, void *, 0x4));
}

EXTERN_C char D_800B4C48[];
EXTERN_C void func_80025444(void *a, void *b, int c);

EXTERN_C void func_800E2348(void *self)
{
    Poly *p;
    func_80025444(D_800B4C48, FIELD_AT(self, void *, 0x28), FIELD_AT(self, short, 0x78));
    p = FIELD_AT(self, Poly *, 0x28);
    ((void (*)(void *))p->vptr[3].pfn)((char *)p + p->vptr[3].delta);
}

EXTERN_C void func_800E23A0(void *self, short arg)
{
    if (FIELD_AT(self, short, 0x10) == 0) {
        Poly *p = FIELD_AT(self, Poly *, 0x54);
        VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
        if (((int (*)(void *, short))vt[3].pfn)((char *)p + vt[3].delta, arg))
            FIELD_AT(self, short, 0x10) = 1;
    }
    if (FIELD_AT(self, void *, 0x58))
        func_800E23A0(FIELD_AT(self, void *, 0x58), arg);
    if (FIELD_AT(self, void *, 0x4))
        func_800E23A0(FIELD_AT(self, void *, 0x4), arg);
}

EXTERN_C int func_800E2440(void *self)
{
    return FIELD_AT(self, int, 0x38);
}

EXTERN_C int func_800E244C(void *self)
{
    return FIELD_AT(self, int, 0x34);
}

EXTERN_C int func_800E2458(void *self)
{
    return FIELD_AT(self, int, 0x4C);
}

EXTERN_C Link *func_800E2464(Link *a, Link *b)
{
    return func_8001A744(a, b);
}

EXTERN_C int func_800E2484(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2490);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E24DC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2528);

EXTERN_C int func_800E2574(void *self)
{
    return FIELD_AT(self, unsigned char, 0x88) >> 7;
}

EXTERN_C int func_800E2580(void *self)
{
    return FIELD_AT(self, int, 0x20);
}

EXTERN_C int func_800E258C(void *self)
{
    return FIELD_AT(self, short, 0x10) == 2;
}

EXTERN_C int func_800E25A0(void *self)
{
    return FIELD_AT(self, short, 0x10) != 0;
}

EXTERN_C void func_800E25AC(void *self, int value)
{
    FIELD_AT(self, int, 0x54) = value;
}

EXTERN_C void func_800E25B4(void *self, int value)
{
    FIELD_AT(self, int, 0x28) = value;
}

EXTERN_C void func_800E25BC(void *self, void *other)
{
    FIELD_AT(self, short, 0x78) = FIELD_AT(other, short, 0x2);
}

EXTERN_C void func_800E25C8(void *self, char *src)
{
    FIELD_AT(self, short, 0x80) = FIELD_AT(src, short, 0x2);
    FIELD_AT(self, short, 0x82) = FIELD_AT(src, short, 0x4);
    FIELD_AT(self, short, 0x84) = FIELD_AT(src, short, 0x6);
}

EXTERN_C void func_800E25EC(void *self, char *src)
{
    FIELD_AT(self, char, 0x86) = FIELD_AT(src, char, 0x4);
    FIELD_AT(self, char, 0x87) = FIELD_AT(src, char, 0x5);
    FIELD_AT(self, char, 0x88) = FIELD_AT(src, char, 0x6);
}

EXTERN_C void func_800E2610(void *self, char *src)
{
    FIELD_AT(self, short, 0x7A) = FIELD_AT(src, short, 0x4);
    FIELD_AT(self, short, 0x7C) = FIELD_AT(src, short, 0x6);
    FIELD_AT(self, short, 0x7E) = FIELD_AT(src, short, 0x8);
}

EXTERN_C void func_800E2634(void *self, short value)
{
    FIELD_AT(self, int, 0x70) = value;
}

EXTERN_C void func_800E2644(void *self, void *other)
{
    FIELD_AT(self, short, 0x76) = FIELD_AT(other, short, 0x4);
}

EXTERN_C void func_800E2650(void *self, short a, short b)
{
    FIELD_AT(self, int, 0x6C) = a;
    FIELD_AT(self, short, 0x74) = b;
}

EXTERN_C void func_800E2664(void *self, int value)
{
    FIELD_AT(self, int, 0x50) = value;
}

EXTERN_C void func_800E266C(void *self, Vec4 *v)
{
    int w = FIELD_AT(self, int, 0x48);
    int *pw = &w;
    FIELD_AT(self, Vec4, 0x3C) = *v;
    FIELD_AT(self, int, 0x48) = *pw;
}

EXTERN_C void func_800E26A4(void *self, int value)
{
    FIELD_AT(self, int, 0x30) = value;
}

EXTERN_C void func_800E26AC(void *self, int value)
{
    FIELD_AT(self, int, 0x2C) = value;
}

EXTERN_C void func_800E26B4(void *self, int value)
{
    FIELD_AT(self, int, 0x38) = value;
}

EXTERN_C void func_800E26BC(void *self, int value)
{
    FIELD_AT(self, int, 0x34) = value;
}

EXTERN_C char *func_800E26C4(void *self, char *src)
{
    return func_800E4110((char *)self + 0x5C, src);
}

EXTERN_C char *func_800E26E4(void *self, char *src)
{
    return func_800E40E4((char *)self + 0x5C, src);
}

EXTERN_C void func_800E2944(void *self);

struct Pair_800E2704 {
    int v;
    int next;
    Pair_800E2704(int a) : v(a), next(0) {}
};

struct Params_800E2704 {
    char pad0[8];
    int a;
    int b;
    RandVal *rv;
    Vec4 v14;
    Vec4 v24;
    Vec4 v34;
    int pad44;
    short s48;
    short s4A;
    short s4C;
    short s4E;
    short s50;
    unsigned char b52;
};

EXTERN_C Params_800E2704 D_1F800000;

struct C_800E2704 : IdNode {
    int fC;
    Pair_800E2704 *p10;
    Pair_800E2704 *p14;
    RandVal rv;
    Vec4 v28, v38, v48;
    int f58;
    int f5C;
    int f60;
    int f64;
    short f68;
    short f6A;
    short f6C;
    char f6E;
};

inline void rv_init_800E2704(RandVal *r)
{
    r->vptr = D_800D6038;
    r->base = 0;
    r->step = 0;
    r->range = 0;
    r->phase = 0;
}

EXTERN_C void *func_800E2704(void *p, short id)
{
    C_800E2704 *self = (C_800E2704 *)p;
    idnode_init(self, id);
    self->vptr = D_800D6674;
    rv_init_800E2704(&self->rv);
    vec4_zero(&self->v28);
    vec4_zero(&self->v38);
    vec4_zero(&self->v48);
    self->p10 = new Pair_800E2704(D_1F800000.a);
    self->p14 = new Pair_800E2704(D_1F800000.b);
    {
        int *vp = self->rv.vptr;
        int **pvp = &vp;
        self->rv = *D_1F800000.rv;
        self->rv.vptr = *pvp;
    }
    self->v28 = D_1F800000.v14;
    self->v38 = D_1F800000.v24;
    self->v48 = D_1F800000.v34;
    self->f6A = D_1F800000.s48;
    self->f5C = D_1F800000.s4A;
    self->f68 = D_1F800000.s4C;
    self->f6E = D_1F800000.b52;
    self->f60 = D_1F800000.s4E;
    self->f64 = D_1F800000.s50;
    self->f6C = 0;
    self->f58 = 0;
    func_800E2944(self);
    return self;
}

EXTERN_C void func_800E28D8(IdNode *self, int flags)
{
    self->vptr = D_800D6674;
    if (FIELD_AT(self, void *, 0x10))
        operator delete(FIELD_AT(self, void *, 0x10));
    if (FIELD_AT(self, void *, 0x14))
        operator delete(FIELD_AT(self, void *, 0x14));
    func_800D67CC(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2944);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2D20);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2F2C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E31B0);

EXTERN_C int D_800D63B8[];
EXTERN_C char D_80010338[];
EXTERN_C char D_800A4544[];
EXTERN_C void func_8001D150(void *, void *);

struct S_800E343C {
    void *vptr;
    int next;
    void *owner;
    short prio;
    int on;
};

inline void *init_800E343C(void *self, int a, int b)
{
    char *l;
    S_800E343C *o;
    FIELD_AT(self, int *, 0x0) = D_800D63B8;
    FIELD_AT(self, int, 0x4) = b;
    FIELD_AT(self, int, 0x8) = a;
    l = D_800A4544;
    o = (S_800E343C *)operator new(0x14);
    o->vptr = D_80010178;
    o->next = 0;
    o->vptr = D_80010338;
    o->owner = self;
    o->prio = 0x80;
    o->on = 1;
    func_8001D150(l, o);
    return self;
}

EXTERN_C void func_800E343C(void *self, Poly *p)
{
    ((void (*)(void *, int))p->vptr[6].pfn)((char *)p + p->vptr[6].delta, FIELD_AT(self, int, 0xC));
    init_800E343C(operator new(0xC), FIELD_AT(self, int, 0xC), 1);
    int n = D_800E5840[0];
    FIELD_AT(self, int, 0xC) = 0;
    D_800E5840[0] = n + 1;
}

EXTERN_C void *func_800E2704(void *self, short id);

EXTERN_C void *func_800E3518(void *self)
{
    func_800E2704(self, 0);
    FIELD_AT(self, int *, 0x0) = D_800D6644;
    return self;
}

EXTERN_C void func_800E3550(IdNode *self, int flags)
{
    self->vptr = D_800D6644;
    func_800E28D8(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3578);

EXTERN_C Vec4 func_800E3770(void *self)
{
    int p = FIELD_AT(self, int, 0x5C);
    if (p == 0)
        return Vec4(0, 0, 0, 0);
    if (FIELD_AT(self, short, 0x6C) < FIELD_AT(self, short, 0x68))
        return Vec4(0, 0, 0, 0);
    return Vec4(0, p, 0, 0);
}

EXTERN_C Vec4 func_800E37C8(void *self)
{
    return FIELD_AT(self, Vec4, 0x38);
}

EXTERN_C void *func_800E37F4(void *self)
{
    func_800E2704(self, 0);
    FIELD_AT(self, int *, 0x0) = D_800D6614;
    return self;
}

EXTERN_C void func_800E382C(IdNode *self, int flags)
{
    self->vptr = D_800D6614;
    func_800E28D8(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3854);

EXTERN_C Vec4 func_800E3A4C(void *self)
{
    int p = FIELD_AT(self, int, 0x5C);
    if (p == 0)
        return Vec4(0, 0, 0, 0);
    if (FIELD_AT(self, short, 0x6C) < FIELD_AT(self, short, 0x68))
        return Vec4(0, 0, 0, 0);
    return Vec4(0, p, 0, 0);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3AA4);

EXTERN_C Vec4 func_800E3DC4(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x - b->x, a->y - b->y, a->z - b->z, a->w);
}

EXTERN_C Vec4 func_800E3E04(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x + b->x, a->y + b->y, a->z + b->z, a->w);
}

EXTERN_C Vec4 func_800E3E44(void *self)
{
    return FIELD_AT(self, Vec4, 0x38);
}

EXTERN_C Vec4 func_800E3E70(void *self)
{
    return FIELD_AT(self, Vec4, 0x28);
}

EXTERN_C int func_800E3E9C(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800E3EA8(void *self)
{
    return FIELD_AT(self, int, 0xC);
}

EXTERN_C void *func_800E3EB4(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, int, 0x8) = 0;
    FIELD_AT(self, int, 0xC) = 0;
    FIELD_AT(self, short, 0x10) = 0;
    FIELD_AT(self, short, 0x12) = 0;
    return self;
}

inline void del_800E3ED4(Poly *o)
{
    if (o)
        o->vptr[1].pfn((char *)o + o->vptr[1].delta, 3);
}

EXTERN_C void func_800E3ED4(void *self, int flags)
{
    int t = FIELD_AT(self, int, 0xC);
    if (t == 0)
        del_800E3ED4(FIELD_AT(self, Poly *, 0x0));
    else if (t != 0x8000)
        goto done;
    del_800E3ED4(FIELD_AT(self, Poly *, 0x4));
    del_800E3ED4(FIELD_AT(self, Poly *, 0x8));
done:
    if (flags & 1)
        operator delete(self);
}

EXTERN_C void func_800E3FB8(void *self, void *other)
{
    FIELD_AT(self, int, 0x0) = FIELD_AT(other, int, 0x0);
    FIELD_AT(self, int, 0x4) = FIELD_AT(other, int, 0x4);
    FIELD_AT(self, int, 0x8) = FIELD_AT(other, int, 0x8);
    FIELD_AT(self, short, 0x10) = FIELD_AT(other, short, 0x10);
    FIELD_AT(self, short, 0x12) = FIELD_AT(other, short, 0x12);
    FIELD_AT(self, short, 0x14) = FIELD_AT(other, short, 0x14);
    FIELD_AT(self, short, 0x16) = FIELD_AT(other, short, 0x16);
    FIELD_AT(self, int, 0xC) = 0;
}

EXTERN_C void *func_800E4010(void *self)
{
    FIELD_AT(self, int, 0xC)++;
    return self;
}

EXTERN_C IdNode *func_800E4028(void *self, short id)
{
    return func_800D67F4(FIELD_AT(self, IdNode *, 0x4), id);
}

EXTERN_C void func_800E4050(void *self, int value)
{
    FIELD_AT(self, int, 0x0) = value;
}

EXTERN_C void *func_800E4058(void *self, void *other)
{
    FIELD_AT(self, char, 0x0) = 0;
    FIELD_AT(self, char, 0x1) = 0;
    FIELD_AT(self, char, 0x2) = 0;
    FIELD_AT(self, short, 0x4) = 0;
    FIELD_AT(self, short, 0x6) = 0;
    FIELD_AT(self, int, 0x8) = 0;
    FIELD_AT(self, int, 0xC) = 0;
    if (other) {
        FIELD_AT(self, char, 0x0) = FIELD_AT(other, char, 0x0);
        FIELD_AT(self, char, 0x1) = FIELD_AT(other, char, 0x1);
        FIELD_AT(self, short, 0x4) = FIELD_AT(other, short, 0x4);
        FIELD_AT(self, char, 0x2) = FIELD_AT(other, char, 0x2);
        FIELD_AT(self, short, 0x6) = FIELD_AT(other, short, 0x6);
    }
    return self;
}

EXTERN_C void func_800E40BC(void *self, int flags)
{
    if (flags & 1)
        operator delete(self);
}

EXTERN_C char *func_800E40E4(void *self, char *src)
{
    FIELD_AT(self, char, 0x0) = FIELD_AT(src, char, 0x2);
    FIELD_AT(self, char, 0x1) = FIELD_AT(src, char, 0x6);
    FIELD_AT(self, short, 0x4) = FIELD_AT(src, short, 0x4);
    return src + 8;
}

EXTERN_C char *func_800E4110(void *self, char *src)
{
    FIELD_AT(self, char, 0x2) = FIELD_AT(src, char, 0x6);
    FIELD_AT(self, short, 0x6) = FIELD_AT(src, short, 0x4);
    return src + 8;
}

EXTERN_C int func_800E4130(void *self, short value)
{
    if (FIELD_AT(self, signed char, 0x0) == 0)
        return 0;
    if (FIELD_AT(self, int, 0x8) == 1)
        return 0;
    if (value >= FIELD_AT(self, short, 0x4)) {
        FIELD_AT(self, int, 0x8) = 1;
        return 1;
    }
    return 0;
}

EXTERN_C int func_800E4174(void *self, short value)
{
    if (FIELD_AT(self, signed char, 0x2) == 0)
        return 0;
    if (FIELD_AT(self, int, 0xC) == 1)
        return 0;
    if (value >= FIELD_AT(self, short, 0x6)) {
        FIELD_AT(self, int, 0xC) = 1;
        return 1;
    }
    return 0;
}

EXTERN_C void *func_800E41B8(void *self, void *other)
{
    FIELD_AT(self, char, 0x0) = FIELD_AT(other, char, 0x0);
    FIELD_AT(self, char, 0x1) = FIELD_AT(other, char, 0x1);
    FIELD_AT(self, short, 0x4) = FIELD_AT(other, short, 0x4);
    FIELD_AT(self, char, 0x2) = FIELD_AT(other, char, 0x2);
    FIELD_AT(self, short, 0x6) = FIELD_AT(other, short, 0x6);
    FIELD_AT(self, int, 0x8) = 0;
    FIELD_AT(self, int, 0xC) = 0;
    return self;
}

EXTERN_C void func_8008EF64(int arg, int a, int b);

EXTERN_C void func_800E41FC(void *self)
{
    void **p = (void **)D_800E5848[0];
    if (p && *p)
        func_8008EF64((FIELD_AT(*p, unsigned short, 0x14) << 16) + FIELD_AT(self, signed char, 0x1), 0x60, 0x40);
}

EXTERN_C void func_8008FAB4(int arg);

EXTERN_C void func_800E424C(void *self)
{
    void **p = (void **)D_800E5848[0];
    if (p && *p)
        func_8008FAB4((FIELD_AT(*p, unsigned short, 0x14) << 16) + FIELD_AT(self, signed char, 0x2));
}

EXTERN_C void *func_800E4298(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, int, 0x4) = 0;
    D_800E5848[0] = self;
    return self;
}

EXTERN_C void func_800E43A0(void *self);

EXTERN_C void func_800E42B0(void *self, int flags)
{
    func_800E43A0(self);
    if (flags & 1)
        operator delete(self);
}

EXTERN_C void func_8008ECB4(void *p);

EXTERN_C char *func_800E42F4(void *self, char *data)
{
    FIELD_AT(self, void *, 0x0) = func_800A0D2C(FIELD_AT(data, int, 0x8));
    func_80025CE0(FIELD_AT(self, void *, 0x0), data, FIELD_AT(data, int, 0x8));
    func_8008ECB4(FIELD_AT(self, void *, 0x0));
    return data + FIELD_AT(data, int, 0x8);
}

EXTERN_C void *func_8008D1F4(void *data, int arg);
EXTERN_C void func_8008C928(int arg);

EXTERN_C char *func_800E4354(void *self, char *data)
{
    FIELD_AT(self, void *, 0x4) = func_8008D1F4(data, 0);
    func_8008C928(0x10);
    return data + FIELD_AT(data, int, 0x8);
}

EXTERN_C void func_8008ED44(void *p);
EXTERN_C void func_8008D4C0(void *p);

EXTERN_C void func_800E43A0(void *self)
{
    if (FIELD_AT(self, void *, 0x0)) {
        func_8008ED44(FIELD_AT(self, void *, 0x0));
        if (FIELD_AT(self, void *, 0x0))
            func_800A0D0C(FIELD_AT(self, void *, 0x0));
        FIELD_AT(self, void *, 0x0) = 0;
    }
    if (FIELD_AT(self, void *, 0x4)) {
        func_8008D4C0(FIELD_AT(self, void *, 0x4));
        FIELD_AT(self, void *, 0x4) = 0;
    }
}

EXTERN_C int func_800E4410(void *self)
{
    return FIELD_AT(self, int, 0x4);
}

EXTERN_C int func_800E441C(void *self)
{
    return FIELD_AT(self, int, 0x0);
}

EXTERN_C int func_800E4428(void *self)
{
    return FIELD_AT(self, signed char, 0x1);
}

EXTERN_C void *func_800E4434(void *self)
{
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, int, 0x4) = 0;
    FIELD_AT(self, int, 0x8) = 0;
    FIELD_AT(self, int, 0xC) = 0;
    FIELD_AT(self, int, 0x10) = 0;
    FIELD_AT(self, short, 0x14) = -1;
    return self;
}

struct C_800E4458 : IdNode {
    Vec4 a, b, c;
    int f3C;
    char f40, f41, f42;
    short f44;
};

EXTERN_C void *func_800E4458(void *p, short id)
{
    C_800E4458 *self = (C_800E4458 *)p;
    idnode_init(self, id);
    self->vptr = D_800D67A4;
    vec4_zero(&self->a);
    vec4_zero(&self->b);
    vec4_zero(&self->c);
    self->f3C = 0;
    self->f40 = 0;
    self->f41 = 0;
    self->f42 = 0;
    self->f44 = 0x44C;
    return self;
}

EXTERN_C void func_800E44E0(IdNode *self, int flags)
{
    self->vptr = D_800D67A4;
    func_800D67CC(self, flags);
}

EXTERN_C char *func_800E4508(void *self, char *src)
{
    Vec4 *v;
    FIELD_AT(self, unsigned char, 0x40) = src[2];
    FIELD_AT(self, unsigned char, 0x41) = FIELD_AT(src, unsigned short, 0x2) >> 8;
    FIELD_AT(self, Vec4, 0xC) = FIELD_AT(src, Vec4, 0x4);
    v = &FIELD_AT(src, Vec4, 0x14);
    FIELD_AT(self, Vec4, 0x1C) = Vec4(*v);
    FIELD_AT(self, Vec4, 0x2C) = Vec4(0, 0, 0, 0);
    FIELD_AT(self, unsigned char, 0x42) = src[0x10];
    return src + 0x24;
}

EXTERN_C void func_800E45CC(void *self, void *other)
{
    FIELD_AT(self, short, 0x8) = FIELD_AT(other, short, 0x8);
    FIELD_AT(self, char, 0x40) = FIELD_AT(other, char, 0x40);
    FIELD_AT(self, char, 0x41) = FIELD_AT(other, char, 0x41);
    FIELD_AT(self, Vec4, 0xC) = FIELD_AT(other, Vec4, 0xC);
    FIELD_AT(self, Vec4, 0x1C) = FIELD_AT(other, Vec4, 0x1C);
    FIELD_AT(self, Vec4, 0x2C) = Vec4(0, 0, 0, 0);
    FIELD_AT(self, char, 0x42) = FIELD_AT(other, char, 0x42);
}

EXTERN_C Vec4 func_800E5798(Vec4 *a, Vec4 *b);

inline void add3_800E4674(Vec4 *a, const Vec4 &b)
{
    int x = a->x + b.x;
    int y = a->y + b.y;
    int z = a->z + b.z;
    a->x = x;
    a->y = y;
    a->z = z;
}

EXTERN_C Vec4 func_800E4674(void *self, Vec4 *off)
{
    Vec4 base;
    Vec4 t;
    if (off)
        base = *off;
    else
        vec4_zero(&base);
    vec4_zero(&t);
    if (FIELD_AT(self, void *, 0x3C))
        t = func_8003A150(FIELD_AT(self, int, 0x3C), (int)&t);
    add3_800E4674(&base, func_800E5798(&func_800E5798(&t, &FIELD_AT(self, Vec4, 0x2C)), &FIELD_AT(self, Vec4, 0xC)));
    return base;
}

EXTERN_C int SquareRoot0(int a);
EXTERN_C Vec4 func_800E5758(Vec4 *a, Vec4 *b);

EXTERN_C Vec4 func_800E47AC(void *self, Vec4 *v)
{
    Vec4 cam;
    Vec4 d;
    int len;
    if (!FIELD_AT(self, int, 0x28))
        return *v;
    cam = FIELD_AT(D_800B4ED8[0], Vec4, 0x2C8);
    d = func_800E5758(&cam, v);
    len = SquareRoot0(d.x * d.x + d.y * d.y + d.z * d.z);
    d.x = d.x * FIELD_AT(self, short, 0x44) / len + v->x;
    d.y = d.y * FIELD_AT(self, short, 0x44) / len + v->y;
    d.z = d.z * FIELD_AT(self, short, 0x44) / len + v->z;
    return d;
}

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6604);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6614);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6644);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6674);

EXTERN_C int func_8003912C(void *p, int n);

EXTERN_C void func_800E49D8(void *self, void *argp)
{
    void **arg = (void **)argp;
    void *who = 0;
    switch (FIELD_AT(self, signed char, 0x40)) {
    case 1:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), 2);
        who = arg[1];
        break;
    case 2:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), 5);
        who = arg[1];
        break;
    case 3:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), 6);
        who = arg[1];
        break;
    case 4:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), 2);
        who = arg[0];
        break;
    case 5:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), 5);
        who = arg[0];
        break;
    case 6:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), 6);
        who = arg[0];
        break;
    case 10:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), FIELD_AT(self, signed char, 0x42));
        who = arg[1];
        break;
    case 11:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), FIELD_AT(self, signed char, 0x42));
        who = arg[0];
        break;
    case 12:
        FIELD_AT(self, Vec4, 0x2C) = *(Vec4 *)arg[3];
        break;
    }
    if (who && FIELD_AT(who, signed char, 0x4BC) >= 3) {
        switch (FIELD_AT(who, unsigned char, 0x94A)) {
        case 0:
            FIELD_AT(self, short, 0x44) = 0x2BC;
            break;
        case 1:
            FIELD_AT(self, short, 0x44) = 0x44C;
            break;
        case 2:
            FIELD_AT(self, short, 0x44) = 0x7D0;
            break;
        }
    }
}

EXTERN_C int func_8003912C(void *p, int n);

EXTERN_C void func_800E4B88(void *self, void *argp)
{
    void **arg = (void **)argp;
    switch (FIELD_AT(self, signed char, 0x40)) {
    case 2:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), 2);
        break;
    case 3:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), 5);
        break;
    case 4:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), 6);
        break;
    case 5:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), 2);
        break;
    case 6:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), 5);
        break;
    case 7:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), 6);
        break;
    case 10:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[1], void *, 0x1B8), FIELD_AT(self, signed char, 0x42));
        break;
    case 11:
        FIELD_AT(self, int, 0x3C) = func_8003912C(FIELD_AT(arg[0], void *, 0x1B8), FIELD_AT(self, signed char, 0x42));
        break;
    case 12:
        FIELD_AT(self, Vec4, 0x2C) = *(Vec4 *)arg[4];
        break;
    }
}

EXTERN_C void *func_800E4458(void *self, short id);

EXTERN_C void *func_800E4CAC(void *self, short id)
{
    func_800E4458(self, id);
    FIELD_AT(self, int *, 0x0) = D_800D677C;
    return self;
}

EXTERN_C void func_800E4CE8(IdNode *self, int flags)
{
    self->vptr = D_800D677C;
    func_800E44E0(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4D10);

EXTERN_C void *func_800E5030(void *self, short id)
{
    func_800E4458(self, id);
    FIELD_AT(self, int *, 0x0) = D_800D6754;
    return self;
}

EXTERN_C void func_800E506C(IdNode *self, int flags)
{
    self->vptr = D_800D6754;
    func_800E44E0(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E5094);

EXTERN_C void *func_800E4458(void *self, short id);

EXTERN_C void *func_800E5254(void *self, short id)
{
    func_800E4458(self, id);
    FIELD_AT(self, int *, 0x0) = D_800D672C;
    return self;
}

EXTERN_C void func_800E5290(IdNode *self, int flags)
{
    self->vptr = D_800D672C;
    func_800E44E0(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E52B8);

EXTERN_C void *func_800E4458(void *self, short id);

EXTERN_C void *func_800E5450(void *self, short id)
{
    func_800E4458(self, id);
    FIELD_AT(self, int *, 0x0) = D_800D6704;
    return self;
}

EXTERN_C void func_800E548C(IdNode *self, int flags)
{
    self->vptr = D_800D6704;
    func_800E44E0(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E54B4);

EXTERN_C Vec4 func_800E5758(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x - b->x, a->y - b->y, a->z - b->z, a->w);
}

EXTERN_C Vec4 func_800E5798(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x + b->x, a->y + b->y, a->z + b->z, a->w);
}

EXTERN_C int func_800E57D8(void *self)
{
    return FIELD_AT(self, int, 0x3C);
}

EXTERN_C int func_800E57E4(void *self)
{
    return FIELD_AT(self, signed char, 0x40) != 0;
}

EXTERN_C int func_800E57F0(void *self)
{
    return FIELD_AT(self, signed char, 0x41);
}

EXTERN_C int func_800E57FC(void *self)
{
    return FIELD_AT(self, signed char, 0x40);
}

EXTERN_C void func_800E5808(void *self, Vec4 v)
{
    FIELD_AT(self, Vec4, 0x2C) = v;
}

/* Retail has a zero word after func_800E4B88's jump table: the vtables from D_800D6704 on
   are 8-aligned relative to the start of the overlay's rodata. Kept in order like
   INCLUDE_RODATA. */
void __maspsx_include_asm_hack_rodata_pad_800D6700()
{
    __asm__(
        ".section .rodata # maspsx-keep\n"
        "\t.word 0 # maspsx-keep\n"
        ".text # maspsx-keep\n"
    );
}

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6704);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D672C);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6754);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D677C);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D67A4);
