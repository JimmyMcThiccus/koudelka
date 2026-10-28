// func_800BB538: 5 instructions differ in the inlined iterator next(): retail loads the table pointer before computing idx*4 (register allocation/delay-slot fill).
#include "field/field.h"

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
            ((Unk_Flag48*)next(it))->unk48 = 0;
        }
        n = n->unk4;
    }
    return 1;
}
