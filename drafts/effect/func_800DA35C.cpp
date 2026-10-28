// NEAR (21 differ): fp now holds D_80010178 like retail (vtable addresses for D_80010300/D_800102D0 taken into locals early). Left: self/giv-offset in $s6/$s5 (retail $s5/$s6; priorities 0.330 vs 0.333 - self needs ~2 fewer live insns, i.e. only D_80010178 hoisted) and v0/v1 swapped in the object-init block.
#include "common.h"
#include "effect/effect.h"

EXTERN_C int D_80010300[];
EXTERN_C int D_800102D0[];
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *self, void *obj);
EXTERN_C int func_800DD7A8(void *self, short n);
EXTERN_C void func_800DBC98(void *self, void *arg, void *one);

EXTERN_C int func_800DA35C(SlotSet *self)
{
    int r = 0;
    int i;
    for (i = 0; i < 5; i++) {
        void *p = (void *)self->slots[2 + i];
        if (p) {
            int m;
            if (func_800DD7A8(p, FIELD_AT(self, short, 0x148)))
                r = 1;
            m = FIELD_AT(p, signed char, 0x7C);
            if (m == 1 && !FIELD_AT(self, signed char, 0x15A + i)) {
                void *g;
                void *o;
                func_800DBC98(self, (void *)1, p);
                int *v300 = D_80010300;
                int *v2d0 = D_800102D0;
                g = FIELD_AT(self, void *, 0x98);
                o = func_8001CA10(0x14);
                FIELD_AT(o, int *, 0x0) = D_80010178;
                FIELD_AT(o, int, 0x4) = 0;
                FIELD_AT(o, int *, 0x0) = v300;
                FIELD_AT(o, short, 0x8) = 2;
                FIELD_AT(o, short, 0xA) = 0xA;
                FIELD_AT(o, int, 0x10) = m;
                FIELD_AT(o, void *, 0xC) = p;
                FIELD_AT(o, int *, 0x0) = v2d0;
                func_8001EFE4(g, o);
                FIELD_AT(self, signed char, 0x15A + i) = m;
            }
        }
    }
    return r;
}
