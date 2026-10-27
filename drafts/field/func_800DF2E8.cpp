// func_800DF2E8: same instructions, different scheduling: retail computes the
// D_800AF478 base before the index and stores the 5th argument in the jal delay
// slot; this stores it before loading a1-a3 (16 instructions differ). Passing
// the 16-byte entry by value compiles the same as passing its four words.
#include "field/field.h"

EXTERN_C void func_800DF2E8(Unk_800DF32C* p, int i) {
    Unk_800AF478* e = &D_800AF478[i];
    func_80080A2C(p->unk4F0, e->unk0, e->unk4, e->unk8, e->unkC);
}
