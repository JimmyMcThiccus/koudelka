// r4c: same stack-slot problem as BATTLE func_800BDEDC (see its draft): a temp after a 0x204-byte buf can't land at sp+0x214.
// func_800C0654: 4 differing: stack slot of the Unk_Short2 temporary (retail sp+0x214, build sp+0x218).
#include "common.h"
#include "shared/exe.h"
#include "field/field.h"

struct Unk_C0654_s { void* vtbl; int unk4; void* vtbl8; void* unkC; Unk_Short2 unk10; short unk14; short unk16; int unk18; unsigned short unk1C; short unk1E; };
struct Unk_C0654_o2 : Unk_800BF520_o { };
struct Unk_C0654_d { virtual int vf00(...); virtual int vf01(...); virtual int vf02(...); };
struct Unk_C0654 { char pad0[0xA]; unsigned short unkA; Unk_C0654_s* unkC; };
EXTERN_C char D_800108A0[];
EXTERN_C char D_80010888[];
EXTERN_C char D_800B4C48[];
EXTERN_C void func_80021F48_p(void*, void*) asm("func_80021F48");
EXTERN_C void func_80024BF0(void*, void*, short, short);
EXTERN_C void func_80025444(void*, void*, int);

EXTERN_C void func_800C0654(Unk_C0654* p, void* a, short b, short c) {
    char buf[0x204];
    Unk_Short2 v;
    Unk_800BF520_o* o = (Unk_800BF520_o*)operator new(0x20C);
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_800106EC;
    o->unk8 = 0;
    o->unkA = 0;
    o->vtbl = D_80010624;
    func_80021F48_p(o, buf);
    Unk_C0654_s* s = (Unk_C0654_s*)operator new(0x20);
    s->vtbl = D_80010178;
    s->vtbl8 = D_80010888;
    s->vtbl = D_800108A0;
    s->unk4 = 0;
    s->unkC = o;
    v.x = -1;
    v.y = -1;
    s->unk10 = v;
    s->unk14 = 0;
    s->unk16 = 0;
    s->unk18 = 0;
    s->unk1E = 0;
    func_80024BF0(s, a, b, c);
    p->unkC = s;
    func_80025444(D_800B4C48, s, 0);
    p->unkA = p->unkC->unk1C;
    ((Unk_C0654_d*)p->unkC)->vf02();
    delete (Unk_Deletable*)o;
}
