// func_800D1BA4: 13 differing: stack layout of two temporaries (retail frame 0x38, temps at 0x10 and 0x1C).
#include "field/field.h"

struct Hg_Hw { unsigned short a, b; };
struct Hg_Sh { short a, b; };
struct Hg_Pad0C { char pad0[0xC]; };
struct Hg_Pad4 { int pad0; };
struct Hg_Z { Hg_Hw hw; };
struct Hg_Y : Hg_Pad4, Hg_Z { };
struct Hg_1BA4 : Hg_Pad0C, Hg_Y { char pad14[0x28]; void* unk3C; void* unk40; };
struct Hg_1BA4_o1 { void* vtbl; int unk4; short unk8; short unkA; };
struct Hg_1BA4_s { char pad0[0x14]; int unk14; int unk18; int unk1C; Hg_Hw unk20; };
struct Hg_1BA4_o2 { void* vtbl; int unk4; void* vtbl2; void* unkC; Hg_Sh unk10; short unk14; short unk16; int unk18; short unk1C; short unk1E; };
EXTERN_C char D_80010654[];
EXTERN_C char D_80010888[];
EXTERN_C char D_800108A0[];
EXTERN_C char D_800B4C48[];
EXTERN_C void func_80021ACC(void*, int);
EXTERN_C void func_80024BF0(void*, int, short, short);
EXTERN_C void func_80025444(void*, void*, int);
inline void hg_set(Hg_Y& y, Hg_Hw v) { Hg_Z* z = &y; z->hw = v; }

EXTERN_C void func_800D1BA4(void* vp, void* vs) {
    Hg_1BA4* p = (Hg_1BA4*)vp;
    Hg_1BA4_s* s = (Hg_1BA4_s*)vs;
    Hg_1BA4_o1* o;
    if (s->unk18 == 8) {
        o = (Hg_1BA4_o1*)operator new(0x20C);
        int a = s->unk14;
        o->vtbl = D_80010178;
        o->unk4 = 0;
        o->vtbl = D_800106EC;
        o->unk8 = 0;
        o->unkA = 0;
        o->vtbl = D_80010624;
        func_80021F48(o, a);
        p->unk40 = o;
    } else {
        o = (Hg_1BA4_o1*)operator new(0x2C);
        int a = s->unk14;
        o->vtbl = D_80010178;
        o->unk4 = 0;
        o->vtbl = D_800106EC;
        o->unk8 = 0;
        o->unkA = 0;
        o->vtbl = D_80010654;
        func_80021ACC(o, a);
        p->unk40 = o;
    }
    VAt<0x10>* g = (VAt<0x10>*)D_800B4C38[0];
    g->vf00(p->unk40);
    hg_set(*p, s->unk20);
    Hg_1BA4_o2* q = (Hg_1BA4_o2*)operator new(0x20);
    int bb = s->unk1C;
    short ra = p->hw.a;
    short rb = p->hw.b;
    void* pp = p->unk40;
    q->vtbl = D_80010178;
    q->unk4 = 0;
    q->vtbl2 = D_80010888;
    q->vtbl = D_800108A0;
    q->unkC = pp;
    struct { int x, y, z; Hg_Sh h; } L;
    L.h.a = -1;
    L.h.b = -1;
    q->unk10 = L.h;
    q->unk14 = 0;
    q->unk16 = 0;
    q->unk18 = 0;
    q->unk1E = 0;
    func_80024BF0(q, bb, ra, rb);
    p->unk3C = q;
    func_80025444(D_800B4C48, q, 0);
    ((VAt0*)p->unk3C)->vf02();
}
