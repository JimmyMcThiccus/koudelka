// func_800DF9A8: 8 differing: scheduling of the stack-argument stores before the func_80062848 call.
#include "field/field.h"

struct He_G_p { char pad0[0x10]; Unk_800E83B8* unk10; void* unk14[1]; };
struct He_G_n : Unk_Deletable { int unk4; int unk8; int unkC; };
EXTERN_C void func_800E85C4(Unk_800E83B8*, int);
EXTERN_C void* func_80062848(void*, int, int, void*, int, int);

EXTERN_C void func_800DF9A8(He_G_p* p, int a, int b) {
    func_80074564(base(D_800AF470[0]->unk328)->unk8[0]);
    p->unk10 = func_800E7DEC(operator new(0x108), 1, a, 0);
    if (b) {
        func_800E85C4(p->unk10, b);
    }
    int i = 0;
    He_G_n* n;
    while ((n = (He_G_n*)func_800DF6B4((Unk_800DF6B4*)p)) != 0) {
        int f = (n->unkC << 16) | 0x201F;
        void* o = func_80062848(operator new(0x78), 1, n->unk8, D_800AF470[0], f, 0);
        p->unk14[i++] = o;
        func_80054E18(p->unk10, o);
        delete n;
    }
    p->unk14[i] = 0;
    ((VAt<0x18>*)p->unk10)->vf01();
}
