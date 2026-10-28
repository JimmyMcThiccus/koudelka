// func_800BB480: Same as func_800BB538 (5 instructions, iterator load order).
#include "field/field.h"

EXTERN_C int func_800BB480(Unk_GrpOwner* p) {
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
            ((Unk_Flag48*)next(it))->unk48 = 1;
        }
        n = n->unk4;
    }
    return 1;
}
