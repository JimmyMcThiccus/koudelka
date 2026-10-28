// func_800C1AF0: 29 differing: inlined iterator next() on Unk_TblIt at +0x23C. Retail folds the index to 0 for the compare (blez) but reloads it for the array index. Same for func_800C1BB8 (vf02, func_800CE7AC) and func_800BB538/func_800BB480 (same 5-instruction delay-slot issue: retail's first insn after the beqz is the table lw, the build puts the sll there).
#include "field/field.h"

struct Unk_800C1AF0 { char pad0[0xDC]; char unkDC[0x160]; Unk_TblIt unk23C; };
inline void* nx(Unk_TblIt* it) { int i = it->unk4; if (i < it->unk0->unk4) { it->unk4 = i + 1; return it->unk0->unk0[i]; } return 0; }

#define p ((Unk_800C1AF0*)vp)
EXTERN_C void func_800C1AF0(Unk_800C0814* vp) {
    func_800CE758((Unk_Derived50*)p->unkDC);
    p->unk23C.unk4 = 0;
    for (VAt<0x18>* o = (VAt<0x18>*)nx(&p->unk23C); o; o = (VAt<0x18>*)nx(&p->unk23C)) {
        o->vf01();
    }
}
#undef p
