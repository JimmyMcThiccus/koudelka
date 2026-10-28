// func_800DDB7C: 28 differing: virtual-base dtor with two inlined sub-object dtors; retail puts `addu a0,s0` right before jal func_8005652C, the build hoists it.
#include "field/field.h"

struct Unk_800DDB7C { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; };
EXTERN_C void func_800DDB7C_i(Unk_800DDB7C* self, int in_chrg) asm("func_800DDB7C");
EXTERN_C char D_800B99BC[];
EXTERN_C char D_800B999C[];
EXTERN_C char D_800B99EC[];
EXTERN_C const Unk_VTbl10 D_800B994C;
EXTERN_C char D_80013BD0[];
EXTERN_C char D_80014DAC[];
EXTERN_C char D_80014DCC[];
EXTERN_C const Unk_VTbl10 D_80014D5C;
EXTERN_C void func_80062A90(void*, int);
EXTERN_C void func_80069B2C(void*, int);

EXTERN_C void func_800DDB7C_i(Unk_800DDB7C* self, int in_chrg) {
    Unk_800DDB7C* s;
    self->vt54 = D_800B99BC;
    self->vt58 = D_800B999C;
    self->vt18 = D_800B99EC;
    self->vb->vptr = (Unk_VTbl10*)&D_800B994C;
    if (!in_chrg) {
        Unk_VTbl10 vt = D_800B994C;
        self->vb->vptr = &vt;
        char* full;
        int adj;
        vt.e[1].delta = D_800B994C.e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x8F4));
        vt.e[6].delta = D_800B994C.e[6].delta + adj;
    }
    func_80062A90((char*)self + 0x658, 2);
    s = (Unk_800DDB7C*)((char*)self + 0x5EC);
    s->vt54 = D_80013BD0;
    s->vt58 = D_80014DAC;
    s->vt18 = D_80014DCC;
    *(Unk_VTbl10* volatile*)&s->vb->vptr = (Unk_VTbl10*)&D_80014D5C;
    func_8005652C(s, 0);
    func_8001A610(s->vb, 0);
    s = (Unk_800DDB7C*)((char*)self + 0x57C);
    s->vt54 = D_80014E7C;
    s->vt58 = D_80014E5C;
    s->vt18 = D_80014EAC;
    *(Unk_VTbl10* volatile*)&s->vb->vptr = (Unk_VTbl10*)&D_80014E0C;
    func_8005652C(s, 0);
    func_8001A610(s->vb, 0);
    func_80053964((char*)self + 0x54C, 2);
    func_80053964((char*)self + 0x524, 2);
    func_80053964((char*)self + 0x4FC, 2);
    func_80053964((char*)self + 0x4D4, 2);
    func_80053964((char*)self + 0x4AC, 2);
    func_80053964((char*)self + 0x490, 2);
    func_80053964((char*)self + 0x474, 2);
    func_80053964((char*)self + 0x458, 2);
    func_80053964((char*)self + 0x43C, 2);
    func_80053964((char*)self + 0x420, 2);
    func_80053964((char*)self + 0x404, 2);
    ((void (*)(void*, int))func_80054C34)((char*)self + 0x38C, 2);
    func_80053964((char*)self + 0x370, 2);
    ((void (*)(void*, int))func_80054C34)((char*)self + 0x320, 2);
    func_80053964((char*)self + 0x2E4, 2);
    func_80053964((char*)self + 0x2C8, 2);
    func_80069B2C(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}
