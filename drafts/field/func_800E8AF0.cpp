// func_800E8AF0: 23 differing: same as func_800DBF0C.
#include "field/field.h"

struct Unk_800E8AF0 { char pad0[0x20]; int unk20; char pad24[0x18]; void* unk3C; };
struct Unk_800A4578_b { char pad0[0x1A4]; short unk1A4; };

EXTERN_C int func_800E8AF0(Unk_800E8AF0* p, Unk_FlagArg* q) {
    if (func_8005618C(q)) {
        return 1;
    }
    ((Unk_800A4578_b*)D_800A4578[0])->unk1A4 = 3;
    func_8001FC78((int)q, 0, 0);
    unsigned short f = q->unk18;
    int d;
    void* o;
    if ((f & 0x80) && (o = p->unk3C)) {
        d = -1;
    } else if ((f & 0x20) && (o = p->unk3C)) {
        d = 1;
    } else {
        return 1;
    }
    p->unk20 = func_80058404(o, d);
    return 1;
}
