// func_800DBF0C: 24 differing: retail tests `f&0x10 && unk3C` with a0 loaded straight from p->unk3C and falls into the 0x40 test; the build branches differently.
#include "field/field.h"

struct Unk_800DBF0C { char pad0[0x20]; int unk20; char pad24[0x18]; void* unk3C; };
struct Unk_800A4578_b { char pad0[0x1A4]; short unk1A4; };

EXTERN_C int func_800DBF0C(Unk_800DBF0C* p, Unk_FlagArg* q) {
    func_8001FC78((int)q, 0, 0);
    if (func_8005618C(q)) {
        return 1;
    }
    if (p->unk3C) {
        ((Unk_800A4578_b*)D_800A4578[0])->unk1A4 = 3;
        unsigned short f = q->unk18;
        int d;
        void* o;
        if ((f & 0x10) && (o = p->unk3C)) {
            d = -1;
        } else if ((f & 0x40) && (o = p->unk3C)) {
            d = 1;
        } else {
            return 1;
        }
        p->unk20 = func_80058404(o, d);
    }
    return 1;
}
