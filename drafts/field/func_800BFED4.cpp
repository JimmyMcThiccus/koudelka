// func_800BFED4: 58 differing: loop must be written with goto top; n/best allocation and negative-path tail layout differ.
#include "field/field.h"

struct Hg_FED4_n { int unk0; Hg_FED4_n* unk4; char pad8[0xE]; short unk16; char pad18[0x2C]; int unk44; };
inline Hg_FED4_n* next(Hg_FED4_n* n) { return n->unk4; }
struct Hg_FED4 { char pad0[0x498]; Hg_FED4_n* unk498; char pad49C[0x164]; int unk600; int unk604; int unk608; int unk60C; };
struct Hg_FED4_v { int x, y, z; };

EXTERN_C void* func_800BFED4(Hg_FED4* p, Hg_FED4_v* v) {
    Hg_FED4_n* n = p->unk498;
    int best = 0x7FFFFFFF;
    int node = 0xE0000000;
    if (!n) {
        p->unk608 = 0;
        p->unk60C = 0;
        return &p->unk608;
    }
    Hg_FED4_v* t = (Hg_FED4_v*)0x1F800000;
    int vy = v->y - 0x398;
    int vx = v->x;
    t->y = vy;
    int vz = v->z;
    t->x = vx;
    t->z = vz;
top:
    if (n) {
        if (((VAt0*)((char*)n + 8))->vf06(t->x, t->z) == 1) {
            if (!(best < n->unk16)) {
                if (t->y < n->unk16) {
                    node = n->unk44;
                    best = n->unk16;
                }
            }
        }
        n = next(n);
        goto top;
    }
    int a = best - 10;
    int q;
    if (best < 0) {
        for (q = 0; a < -199; q++) {
            a += 200;
        }
        p->unk604 = -(q * 200);
    } else {
        a += 190;
        for (q = 0; a >= 200; q++) {
            a -= 200;
        }
        p->unk604 = q * 200;
    }
    p->unk600 = node;
    return &p->unk600;
}
