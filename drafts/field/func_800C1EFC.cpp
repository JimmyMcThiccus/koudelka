// func_800C1EFC: 48 differing, logic matches: register allocation. Retail keeps self=s1, in_chrg=s2 and the 0x68 sub-object pointer in s0 (recomputed in both delay slot and after the call); the build puts self in s0.
#include "field/field.h"

struct Unk_800C1EFC { Unk_VBase* vb; char pad4[0x28]; void* vt2C; char pad30[0x28]; void* vt58; char pad5C[0xC]; Unk_VbDtor2C unk68; char pad98[0x10]; void* unkA8; };
EXTERN_C char D_80014A08[];
EXTERN_C char D_800149B8[];

EXTERN_C void func_800C1EFC(Unk_800C1EFC* self, int in_chrg) {
    self->vt58 = D_800B737C;
    self->vt2C = D_800B721C;
    self->vb->vptr = (Unk_VTbl10*)&D_800B732C;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B732C;
        char* full;
        int adj;
        self->vb->vptr = &vt;
        vt.e[1].delta = D_800B732C.e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0xAC));
        vt.e[5].delta = D_800B732C.e[5].delta + adj;
        vt.e[7].delta = D_800B732C.e[7].delta + adj;
        vt.e[9].delta = D_800B732C.e[9].delta + adj;
    }
    Unk_VbDtor2C* s = &self->unk68;
    if (self->unkA8) {
        func_8002B27C(self, self->unkA8);
        self->unkA8 = 0;
    }
    s->vt2C = D_80014A08;
    s->vb0->vptr = (Unk_VTbl10*)D_800149B8;
    func_8005BDA4(s, 0);
    func_8001A610(s->vb0, 0);
    func_80057558(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}
