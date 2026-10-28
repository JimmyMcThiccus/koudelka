// func_800CA1CC: 36 differing: move order of addu s0,a2,zero and double first(&self->unk84) in the loop append.
#include "field/field.h"

struct Unk_Pt2 { short x, y; };
struct Unk_800CA1CC { Unk_VBase* vb; char pad4[0x28]; void* vt2C; Unk_800BFB64_list unk30; char pad34[0x24]; void* vt58; int unk5C; int unk60; int unk64; Unk_Pt2 unk68; Unk_Pt2 unk6C; int unk70; int unk74; int unk78; short unk7C; short unk7E; int unk80; Unk_DualList unk84; char unk90[0x14]; char unkA4[8]; char unkAC[8]; char unkB4[8]; int unkBC; int unkC0; Unk_VbObj vobj; };
EXTERN_C VAt<0x2C>* func_800D03B0_x(void*, int, int, unsigned short) asm("func_800D03B0");
EXTERN_C void* func_800CA1CC_i(Unk_800CA1CC* self, int in_chrg, Unk_Pt pt) asm("func_800CA1CC");

EXTERN_C void* func_800CA1CC_i(Unk_800CA1CC* self, int in_chrg, Unk_Pt pt) {
    if (in_chrg) {
        self->vb = (Unk_VBase*)&self->vobj;
        Unk_VbObj* v = (Unk_VbObj*)self->vb;
        v->vptr = D_80010178;
        v->unk4 = 0;
        v->vptr = D_800104A8;
    }
    func_80057368(self, 0);
    self->vb->vptr = (Unk_VTbl10*)&D_800B825C;
    Unk_VTbl10 vt;
    if (!in_chrg) {
        vt = (*(const Unk_VTbl10*)&D_800B825C);
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B825C).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xC4));
        vt.e[5].delta = (*(const Unk_VTbl10*)&D_800B825C).e[5].delta + adj;
        vt.e[7].delta = (*(const Unk_VTbl10*)&D_800B825C).e[7].delta + adj;
        vt.e[9].delta = (*(const Unk_VTbl10*)&D_800B825C).e[9].delta + adj;
    }
    self->vt58 = D_800B82AC;
    self->vt2C = D_800B814C;
    self->unk60 = 0x10;
    self->unk5C = 1;
    self->unk64 = 0;
    struct { int pad; Unk_Pt2 a, b; } tt;
    tt.a = *(Unk_Pt2*)&pt;
    tt.b.x = 0x35;
    tt.b.y = 0x61;
    self->unk68 = tt.a;
    self->unk6C = tt.b;
    self->unk7C = 0;
    self->unk7E = 0;
    self->unk80 = 0;
    short* s3 = (short*)((char*)self + 0x68);
    Unk_DualList* l = &self->unk84;
    ((char**)l)[2] = self->unk90;
    *(char**)((char*)self + 0x84) = self->unk90;
    func_800198E0(((void**)l)[2], 3, 1);
    ((int*)l)[1] = 0;
    func_8002972C(self->unkA4, 0x80, 0x80, 0x80, 1);
    func_8002972C(self->unkAC, 0x78, 0x74, 0x70, 1);
    func_8002972C(self->unkB4, 0x68, 0x60, 0x58, 1);
    self->unkBC = 8;
    self->unkC0 = 0x22;
    ((VAt<0x2C>*)self)->vf07(0, 0);
    ((VAt<0x2C>*)self)->vf08(0x140, 0xF0);
    VAt<0x2C>* o = func_800D03B0_x(operator new(0x44), 1, 3, 2);
    o->vf07(self->unk68.x, s3[1]);
    o->vf08(s3[2], s3[3]);
    func_8002B174(self, o, -1);
    {
        Unk_800BFB64_node* n = first(l);
        func_80019A6C(n, (int)o, n->unk4);
    }
    for (unsigned i = 0; i < (unsigned)((Unk_800B4DD0*)D_800B4DD0[0])->unk1FB; i++) {
        o = func_800D03B0_x(operator new(0x44), 1, (unsigned char)i, 2);
        o->vf07(self->unk68.x, s3[1]);
        o->vf08(s3[2], s3[3]);
        func_8002B174(self, o, -1);
        func_80019A6C(first(&self->unk84), (int)o, first(&self->unk84)->unk4);
    }
    if (first(&self->unk84)->unk4 < 4) {
        self->unk70 = 0;
        self->unk74 = -0x50;
    } else {
        self->unk74 = -0x3C;
        self->unk70 = 0;
        self->unk78 = -0x60;
    }
    return self;
}
