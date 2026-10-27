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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D6C94);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7970);

EXTERN_C char *func_800D7A14(RandVal *self, char *src)
{
    self->base = FIELD_AT(src, short, 0x4);
    self->step = FIELD_AT(src, short, 0x6);
    self->range = FIELD_AT(src, short, 0x8);
    self->spread = FIELD_AT(src, short, 0xA);
    return src + 1;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7A4C);

EXTERN_C void func_800D7B64(RandVal *self)
{
    self->phase = 0;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7B6C);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7F94);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9A68);

EXTERN_C void func_800D9AEC(Poly *p)
{
    if (p)
        p->vptr[1].pfn((char *)p + p->vptr[1].delta, 3);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9B28);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9BB8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9C48);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9CA8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9D08);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DA84C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DA8E8);

EXTERN_C void func_800DAA64(void *self)
{
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAA6C);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DABA8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAC88);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAD28);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAD80);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DADF8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAE48);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAE98);

EXTERN_C void *D_800B4ED8[];

EXTERN_C void func_800DAFD4(void *self)
{
    void *p;
    FIELD_AT(self, char, 0x164) = 0;
    p = D_800B4ED8[0];
    FIELD_AT(p, int, 0x278) = 6;
    FIELD_AT(p, int, 0x26C) = 0;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAFF0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB054);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB0FC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB4BC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB788);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB978);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBC98);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBDC0);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC0CC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC150);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC1BC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC264);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC670);

EXTERN_C void *func_800DBE44(void *self);

EXTERN_C void *func_800DC7C8(void *self)
{
    func_800DBE44(self);
    FIELD_AT(self, int *, 0x28) = D_800D6310;
    FIELD_AT(self, int, 0x2C) = 0;
    FIELD_AT(self, int, 0x30) = 0;
    return self;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC804);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC870);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC8DC);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DCCB4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DCD54);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DCE84);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD0C4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD13C);

EXTERN_C int func_800DD1B4(void)
{
    return D_800E5844[0] != 0;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD1C4);

EXTERN_C void func_8001D024(void *self);

EXTERN_C void func_800DD260(void *self)
{
    func_8001D024(self);
}

EXTERN_C int func_800DD280(void)
{
    return D_800E5840[0] != 0;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD290);

EXTERN_C void func_800DD32C(void *self)
{
    func_8001D024(self);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD34C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD440);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD680);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD6F8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD7A8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD878);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD8D8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD9A8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD9FC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDA4C);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDB58);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDC98);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDF08);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDF58);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDFC0);

EXTERN_C void func_800DE0E4(void *self, int i, Color c)
{
    func_800DE108(self, i, &c);
}

EXTERN_C void func_800DE108(void *self, int i, Color *c)
{
    FIELD_AT(self, Color *, 0xC)[i] = *c;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE12C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE180);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE1E8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE310);

EXTERN_C void func_800DE364(void *self, int i, SVec4 v)
{
    func_800DE38C(self, i, &v);
}

EXTERN_C void func_800DE38C(void *self, int i, SVec4 *v)
{
    FIELD_AT(self, SVec4 *, 0xC)[i] = *v;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE3BC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE5B0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE6E8);

EXTERN_C void func_800DE780(void *self, int i, Color c)
{
    func_800DE7A4(self, i, &c);
}

EXTERN_C void func_800DE7A4(void *self, int i, Color *c)
{
    FIELD_AT(self, Color *, 0x1C)[i] = *c;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE7C8);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEB64);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEC88);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEDE0);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEF14);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF0C4);

EXTERN_C int func_800DF1D4(void *self)
{
    return 1;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF1DC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF27C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF2D8);

EXTERN_C void func_800DF3EC(void *self)
{
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF3F4);

EXTERN_C void *func_800DF498(void *self)
{
    func_800E3EB4(self);
    FIELD_AT(self, int, 0x0) = 0;
    FIELD_AT(self, short, 0x10) = 0;
    FIELD_AT(self, int, 0x4) = 0;
    return self;
}

EXTERN_C void func_800E3ED4(void *self);

EXTERN_C void func_800DF4CC(void *self)
{
    func_800E3ED4(self);
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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E02F4);

EXTERN_C void *func_800E037C(void *self)
{
    return self;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0384);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0468);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0638);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E07E0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0AEC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0B60);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0BD8);

EXTERN_C int func_800E0D2C(void *self)
{
    int r = 0;
    if (FIELD_AT(self, int, 0x18) != 0)
        r = FIELD_AT(self, int, 0x1C) == 0;
    return r;
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0D50);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0DAC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0E20);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0E70);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0FDC);

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

EXTERN_C void func_800E1B24(void *self)
{
    Poly *p = FIELD_AT(self, Poly *, 0x54);
    VtEntry *vt = FIELD_AT(p, VtEntry *, 0x8);
    ((void (*)(void *))vt[2].pfn)((char *)p + vt[2].delta);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1B60);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1C5C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E21B8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E22E0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2348);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E23A0);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E266C);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2704);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E28D8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2944);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2D20);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2F2C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E31B0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E343C);

EXTERN_C void *func_800E2704(void *self, int arg);

EXTERN_C void *func_800E3518(void *self)
{
    func_800E2704(self, 0);
    FIELD_AT(self, int *, 0x0) = D_800D6644;
    return self;
}

EXTERN_C void func_800E28D8(void *self, int flags);

EXTERN_C void func_800E3550(void *self, int flags)
{
    FIELD_AT(self, int *, 0x0) = D_800D6644;
    func_800E28D8(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3578);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3770);

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

EXTERN_C void func_800E382C(void *self, int flags)
{
    FIELD_AT(self, int *, 0x0) = D_800D6614;
    func_800E28D8(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3854);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3A4C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3AA4);

EXTERN_C Vec4 func_800E3DC4(Vec4 *a, Vec4 *b)
{
    return Vec4(a->x - b->x, a->y - b->y, a->z - b->z, a->w);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3E04);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3ED4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3FB8);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4058);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E41FC);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E42F4);

EXTERN_C void *func_8008D1F4(void *data, int arg);
EXTERN_C void func_8008C928(int arg);

EXTERN_C char *func_800E4354(void *self, char *data)
{
    FIELD_AT(self, void *, 0x4) = func_8008D1F4(data, 0);
    func_8008C928(0x10);
    return data + FIELD_AT(data, int, 0x8);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E43A0);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4458);

EXTERN_C void func_800E44E0(IdNode *self, int flags)
{
    self->vptr = D_800D67A4;
    func_800D67CC(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4508);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E45CC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4674);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E47AC);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6604);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6614);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6644);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6674);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E49D8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4B88);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E5254);

EXTERN_C void func_800E5290(IdNode *self, int flags)
{
    self->vptr = D_800D672C;
    func_800E44E0(self, flags);
}

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E52B8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E5450);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E5798);

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

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6704);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D672C);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6754);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D677C);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D67A4);
