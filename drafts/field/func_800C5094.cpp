// func_800C5094: 31 differing (3 real: 0x194 lhu unkA lands in v1 instead of a0 in the 3rd addPrim; src/xori regs in the copy block). Twin of func_800D4DC4. Permuter 5 min: no gain.
#include "common.h"
#include "shared/exe.h"
#include "field/field.h"
struct Unk_800C5094 { char pad0[0xA]; unsigned short unkA; char padC[4]; Unk_Dr12 unk10[2]; Unk_Sprt20 unk28[2]; Unk_Dr16 unk50[2]; };
EXTERN_C int func_800C5094(Unk_800C5094* p) {
    int b = D_800B4CF0[0];
    if (func_8005F1B4(p)) {
        Unk_Sprt20* s = &p->unk28[b ^ 1];
        Unk_Dr16* s2 = &p->unk50[b ^ 1];
        int w0 = s->body.a, w1 = s->body.b, w2 = s->body.c, w3 = s->body.d;
        Unk_Sprt20* d = &p->unk28[b];
        d->body.d = w3;
        d->body.a = w0;
        d->body.b = w1;
        d->body.c = w2;
        int v0 = s2->body.a, v1 = s2->body.b, v2 = s2->body.c;
        Unk_Dr16* d2 = &p->unk50[b];
        d2->body.a = v0;
        d2->body.b = v1;
        d2->body.c = v2;
    }
    addPrimN(p->unkA, &p->unk28[b]);
    addPrimN(p->unkA, &p->unk50[b]);
    addPrimN(p->unkA, &p->unk10[b]);
    return 3;
}
