// func_800DAEFC: vbase dtor with 3 inline member dtors. Header/vptr/vtable-copy part matches the E8144 recipe. Open: retail reloads the member vtable constants (lui/addiu) per member and reuses s0 for each member pointer (frame 0x70, s0-s2); ours CSEs the shared constants (D_80013BD0/14DAC/14DCC/14D5C twice) into s1-s4 (frame 0x80). Tried: flat fields, pointer locals, inline helper (with/without in_chrg&2).
#include "common.h"
#include "shared/exe.h"
#include "field/field.h"
EXTERN_C void func_800DB318(void*, int);
EXTERN_C char D_80013BD0[];
EXTERN_C char D_80014DAC[];
EXTERN_C char D_80014DCC[];
EXTERN_C char D_80014D5C[];
struct Unk_800DAEFC_m { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; };
struct Unk_800DAEFC { char pad0[0x18]; void* vt18; char pad1C[0x34]; Unk_VBase* vb; void* vt54; void* vt58; char pad5C[0x2488 - 0x5C]; char m0[0x70]; char m1[0x6C]; char m2[0x6C]; };
static inline void dm_800DAEFC(Unk_800DAEFC_m* m, char* a, char* b, char* c, char* vtbl, int in_chrg) {
    m->vt54 = a;
    m->vt58 = b;
    m->vt18 = c;
    m->vb->vptr = (Unk_VTbl10*)vtbl;
    func_8005652C(m, 0);
    if (in_chrg & 2) {
        func_8001A610(m->vb, 0);
    }
}
EXTERN_C void func_800DAEFC(Unk_800DAEFC* self, int in_chrg) {
    self->vt54 = D_800B972C;
    self->vt58 = D_800B970C;
    self->vt18 = D_800B975C;
    self->vb->vptr = (Unk_VTbl10*)&D_800B96BC;
    if (!in_chrg) {
        Unk_VTbl10 vt = (*(const Unk_VTbl10*)&D_800B96BC);
        char* full;
        int adj;
        self->vb->vptr = &vt;
        vt.e[1].delta = (*(const Unk_VTbl10*)&D_800B96BC).e[1].delta + (adj = (char*)self - (full = (char*)self->vb - 0x25D0));
        vt.e[6].delta = (*(const Unk_VTbl10*)&D_800B96BC).e[6].delta + adj;
    }
    dm_800DAEFC((Unk_800DAEFC_m*)self->m2, D_80013BD0, D_80014DAC, D_80014DCC, (char*)&D_80014D5C, 2);
    dm_800DAEFC((Unk_800DAEFC_m*)self->m1, D_80013BD0, D_80014DAC, D_80014DCC, (char*)&D_80014D5C, 2);
    dm_800DAEFC((Unk_800DAEFC_m*)self->m0, D_80014E7C, D_80014E5C, D_80014EAC, (char*)&D_80014E0C, 2);
    func_800DB318((char*)self + 0x22F0, 2);
    func_80053964((char*)self + 0x22D4, 2);
    ((void (*)(void*, int))func_80054C34)((char*)self + 0x2284, 2);
    func_80069264(self, 0);
    if (in_chrg & 2) {
        func_8001A610(self->vb, 0);
    }
    if (in_chrg & 1) {
        operator delete(self);
    }
}
