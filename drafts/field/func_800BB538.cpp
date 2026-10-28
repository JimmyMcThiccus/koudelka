// func_800BB538: 5 instructions differ in the inlined iterator next(): retail loads the table pointer (tbl->arr) before computing idx*4; the build computes idx*4 first and fills the beqz delay slot with it. Same difference in func_800BB480 (flag 1), func_800C1AF0/1BB8, func_800D2F48, func_800BB6B4.
#include "field/field.h"

inline void* nx_BB538(Unk_TblIt* it) {
    int i = it->unk4;
    if (i < it->unk0->unk4) {
        void* r = it->unk0->unk0[i];
        it->unk4 = i + 1;
        return r;
    }
    return 0;
}

EXTERN_C int func_800BB538(Unk_GrpOwner* p) {
    Unk_GrpList* l = &p->unk450;
    int c = ((int (*)(void*))func_8001A6E8)(l->unk4);
    Unk_GrpNode* n;
    if (c == 0) {
        return 0;
    }
    for (n = l->unk4; c != 0; c--) {
        Unk_TblIt* it = &n->unkC;
        int k;
        it->unk4 = 0;
        for (k = n->unk30; k != 0; k--) {
            ((Unk_Flag48*)nx_BB538(it))->unk48 = 0;
        }
        n = n->unk4;
    }
    return 1;
}
