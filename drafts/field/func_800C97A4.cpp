// func_800C97A4: matches under try_compile (0 differing) but contains a jump table: the compiled table shifts rodata in matching mode (field.bin differs), so it is not landed. Needs the unit/rodata arrangement for its jump table.
#include "field/field.h"

struct Unk_800C97A4 { Unk_VBase* vb0; char pad4[8]; Unk_Short4 unkC; char pad14[0x18]; void* vt2C; char pad30[8]; short unk38; short unk3A; Unk_800BCFD0 unk3C; };

EXTERN_C Unk_800C97A4* func_800C97A4(Unk_800C97A4* self, int in_chrg, Unk_Short2 a, int kind, unsigned short b) {
    Unk_VTbl10 vt;
    if (in_chrg) {
        Unk_800BCFD0* v = &self->unk3C;
        self->vb0 = (Unk_VBase*)v;
        v->vtbl = D_80010178;
        v->unk4 = 0;
        v->vtbl = D_800104A8;
    }
    func_8005BC84(self, 0, b, 0x10);
    self->vb0->vptr = (Unk_VTbl10*)&D_800B7F1C;
    if (!in_chrg) {
        vt = D_800B7F1C;
        char* full;
        int adj;
        self->vb0->vptr = &vt;
        vt.e[1].delta = D_800B7F1C.e[1].delta + (adj = (char*)self - (full = (char*)self->vb0 - 0x3C));
        vt.e[5].delta = D_800B7F1C.e[5].delta + adj;
        vt.e[7].delta = D_800B7F1C.e[7].delta + adj;
        vt.e[9].delta = D_800B7F1C.e[9].delta + adj;
    }
    self->vt2C = D_800B7F6C;
    self->unk38 = 0;
    self->unk3A = 0;
    short x = a.x, y = a.y;
    Unk_Short4 r;
    r.z = 0x20; r.w = 0x10; r.x = x; r.y = y;
    self->unkC = r;
    switch (kind) {
    case 9:
        self->unk38 = 0x20;
        break;
    case 10:
        self->unk3A = 0x10;
        break;
    case 11:
        self->unk38 = 0x20;
        self->unk3A = 0x10;
        break;
    case 12:
        self->unkC.z = 0x10;
        self->unk3A = 0x20;
        break;
    case 13:
        self->unkC.z = 0x10;
        self->unk38 = 0x10;
        self->unk3A = 0x20;
        break;
    case 14:
        self->unkC.z = 0x10;
        self->unk38 = 0x20;
        self->unk3A = 0x20;
        break;
    case 15:
        self->unkC.z = 0x10;
        self->unk38 = 0x30;
        self->unk3A = 0x20;
        break;
    }
    return self;
}
