// r4c: still 4. Retail hoists &p->unk5E0 (first()'s null test) out of BOTH loops; ours only out of the inner one. Tried: 25 decl orders with an explicit q=&p->unk5E0 (11+), for/while/goto/break outer-loop shapes. The permuter can't parse it (undefined struct in C mode).
// func_800BC394: 4 differing: retail schedules addiu s6,s5,0x5E0 before lw s2,4(s0); the build puts it after the beqz s4. Needs asm alias for the (void*) header declaration.
#include "common.h"
#include "shared/exe.h"
#include "field/field.h"

struct Unk_BC394_N { int unk0; Unk_BC394_N* unk4; char pad8[4]; Unk_DualList unkC; char pad18[0x18]; int unk30; };
struct Unk_BC394 { char pad0[0x278]; Unk_800BBE68_r* unk278; char pad27C[0x1D4]; Unk_GrpList unk450; char pad458[0x188]; Unk_DualList unk5E0; };

EXTERN_C int func_BC394_i(Unk_BC394* p, int n) asm("func_800BC394");
EXTERN_C int func_BC394_i(Unk_BC394* p, int n) {
    int i = 0;
    Unk_GrpList* l = &p->unk450;
    int c = ((int (*)(void*))func_8001A6E8)(l->unk4);
    Unk_BC394_N* g = (Unk_BC394_N*)l->unk4;
    while (c != 0) {
        Unk_DualList* d = &g->unkC;
        while (first(d)->unk4 != 0) {
            Unk_Tbl* t = (Unk_Tbl*)first2(d);
            Unk_Deletable* o = t->unk4 ? (Unk_Deletable*)t->unk0[t->unk4 - 1] : 0;
            if (!o) continue;
            func_8002DC34(p->unk278->unk254, (int)o, 0);
            func_80019CFC((List *)first2(d), (int)o);
            Unk_800BFB64_node* m = first(&p->unk5E0);
            func_80019A6C(m, (int)o, m->unk4);
            g->unk30--;
            if (++i == n) return i;
        }
        g = g->unk4;
        c--;
    }
    return i;
}
