// func_800BF9D8: 7 differing: retail sets a1=0x10 in the first call's delay-slot area (before the vptr lui/addiu); the build keeps it next to its use.
#include "field/field.h"

EXTERN_C void* func_800198E0(void*, int, int);
struct Unk_Hld3 { void* vb; int unk4; void* unk8; };
EXTERN_C void* func_800BFE48(void*);
struct Unk_800BF9D8 : Unk_800BFE48 { char pad100[0x514]; Unk_Hld3 unk610; char list[0x14]; void* unk630; };

EXTERN_C Unk_800BF9D8* func_800BF9D8(Unk_800BF9D8* p) {
    Unk_Hld3* h = &p->unk610;
    func_800BFE48(p);
    p->unk8C = D_800B706C;
    p->unkF8 = D_800B7054;
    p->vtbl = D_800B7084;
    h->unk8 = p->list;
    h->vb = p->list;
    func_800198E0(h->unk8, 0x10, 0);
    h->unk4 = 0;
    p->unk630 = 0;
    return p;
}
