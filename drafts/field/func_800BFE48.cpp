// func_800BFE48: constructor (three vptrs). Logic matches; register use differs:
// retail copies `this` to $v0 right after the base-constructor call and stores the
// vptrs through $v0, this stores through $s0 and moves to $v0 at the end
// (10 instructions differ). Probably needs a real C++ constructor.
#include "field/field.h"

EXTERN_C Unk_800BFE48* func_800BFE48(Unk_800BFE48* p) {
    func_800BD4CC(p);
    p->unk8C = D_800B70B4;
    p->unkF8 = D_800B709C;
    p->vtbl = D_800B70CC;
    return p;
}
