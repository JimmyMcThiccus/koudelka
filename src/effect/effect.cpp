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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D6C78);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D6C94);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D6DE8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7170);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7524);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D75D4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7958);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7964);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7970);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7A14);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7A4C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7B64);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7B6C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7C2C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7C50);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7C84);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7CB0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D7F94);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D8050);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D8078);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D80D8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D8354);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D837C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D85AC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D85D4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D8804);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D882C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D8A44);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D8A6C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D8DC0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D8DE8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D8FF0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9018);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9324);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D934C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9658);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9698);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D96D8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9724);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9770);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D979C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D97C8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D97F4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D97FC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D982C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9834);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9864);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D986C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D98A4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D98E4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D98F0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9908);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9928);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9A68);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800D9AEC);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DA584);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAA64);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAA6C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAB3C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAB64);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAB94);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DABA8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAC88);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAD28);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAD80);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DADF8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAE48);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAE98);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAFD4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DAFF0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB054);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB0FC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB4BC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB788);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DB978);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBC98);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBD1C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBD5C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBD9C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBDA8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBDC0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBE30);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBE44);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBE88);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBEBC);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6228);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6240);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6268);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6280);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DBEDC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC08C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC0CC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC150);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC1BC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC264);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC670);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC7C8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC804);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC870);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC8DC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DC99C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DCC58);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DCC8C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DCCB4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DCD54);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DCE28);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DCE5C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DCE84);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD058);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD098);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD0A0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD0AC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD0B8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD0C4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD13C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD1B4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD1C4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD260);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD280);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD290);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DD32C);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDB1C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDB38);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDB58);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDC98);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDD84);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDD90);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDDD8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDE00);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDE3C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDE48);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDE54);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDE7C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDEA8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDED0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDEFC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDF08);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDF58);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DDFC0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE0E4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE108);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE12C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE180);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE1E8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE310);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE364);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE38C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE3BC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE5B0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE6E8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE780);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE7A4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE7C8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE83C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE884);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DE8CC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEA54);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEB64);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEBEC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEC20);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEC2C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEC50);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEC88);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DED48);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DED58);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DED64);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DED78);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DED9C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEDD4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEDE0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEE88);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEE98);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEEA4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEEB8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEEDC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DEF14);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF0C4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF1D4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF1DC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF27C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF2D8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF3EC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF3F4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF498);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800DF4CC);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0188);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E01B0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E02F4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E037C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0384);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0468);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0638);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E07E0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0AEC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0B60);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0BD8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0D2C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0D50);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0DAC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0E20);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0E70);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E0FDC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1090);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1304);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1604);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1AE4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1B24);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1B60);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E1C5C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E21B8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E22E0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2348);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E23A0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2440);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E244C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2458);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2464);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2484);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2490);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E24DC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2528);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2574);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2580);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E258C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E25A0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E25AC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E25B4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E25BC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E25C8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E25EC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2610);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2634);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2644);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2650);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2664);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E266C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E26A4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E26AC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E26B4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E26BC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E26C4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E26E4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2704);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E28D8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2944);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2D20);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E2F2C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E31B0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E343C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3518);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3550);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3578);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3770);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E37C8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E37F4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E382C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3854);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3A4C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3AA4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3DC4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3E04);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3E44);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3E70);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3E9C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3EA8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3EB4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3ED4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E3FB8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4010);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4028);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4050);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4058);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E40BC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E40E4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4110);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4130);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4174);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E41B8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E41FC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E424C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4298);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E42B0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E42F4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4354);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E43A0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4410);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E441C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4428);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4434);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4458);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E44E0);

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

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4CAC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4CE8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E4D10);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E5030);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E506C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E5094);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E5254);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E5290);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E52B8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E5450);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E548C);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E54B4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E5758);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E5798);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E57D8);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E57E4);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E57F0);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E57FC);

INCLUDE_ASM("asm/effect/nonmatchings/effect", func_800E5808);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6704);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D672C);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D6754);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D677C);

INCLUDE_RODATA("asm/effect/nonmatchings/effect", D_800D67A4);
