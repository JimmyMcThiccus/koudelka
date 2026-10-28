// ~75 differ (mostly shift): only the node loop differs. Retail: single loop tail (Link conversion, beqz->top with a0=0 / j top with a0=v0-0x18) and a copy a0->s0 at the loop top. This form duplicates the conversion tail; adding a block-scope 'Link *l = n;' fixes the tail but then the constant 1 for 0x15F is hoisted into $s1 and the test happens before the copy. Rest of the function matches.
#include "common.h"
#include "effect/effect.h"

EXTERN_C int D_80010300[];
EXTERN_C int D_800102D0[];
EXTERN_C void *func_8001CA10(int size);
EXTERN_C void func_8001EFE4(void *self, void *obj);
EXTERN_C int func_800DD7A8(void *self, short n);
EXTERN_C void func_800DBC98(void *self, void *arg, void *one);
EXTERN_C void *func_800787B4(void);
EXTERN_C void func_800C0EB8(void *p);
EXTERN_C void func_800DA03C(void *self);
EXTERN_C int func_800DA35C(SlotSet *self);

EXTERN_C void func_800DA170(SlotSet *self)
{
    func_800DA03C(self);
    if (FIELD_AT(self, SubNode *, 0x104)) {
        SubNode *n = FIELD_AT(self, SubNode *, 0x104);
        while (1) {
            if (!n)
                break;
            if (func_800DD7A8(n, FIELD_AT(self, short, 0x148)) && !FIELD_AT(self, signed char, 0x15F)) {
                func_800C0EB8(FIELD_AT(FIELD_AT(func_800787B4(), void *, 0x32C), void *, 0xA0));
                FIELD_AT(self, char, 0x15F) = 1;
            }
            n = static_cast<SubNode *>(static_cast<Link *>(n)->next);
        }
        {
            int m = FIELD_AT(FIELD_AT(self, void *, 0x104), signed char, 0x7C);
            if (m == 1 && !FIELD_AT(self, signed char, 0x158) && !FIELD_AT(self, void *, 0x10C) && !FIELD_AT(self, void *, 0x108)) {
                void *g;
                void *p;
                void *o;
                func_800DBC98(self, (void *)1, (void *)self->slots[0]);
                g = FIELD_AT(self, void *, 0x98);
                p = (void *)self->slots[0];
                o = func_8001CA10(0x14);
                FIELD_AT(o, int *, 0x0) = D_80010178;
                FIELD_AT(o, int, 0x4) = 0;
                FIELD_AT(o, int *, 0x0) = D_80010300;
                FIELD_AT(o, short, 0x8) = 2;
                FIELD_AT(o, short, 0xA) = 0xA;
                FIELD_AT(o, int, 0x10) = m;
                FIELD_AT(o, void *, 0xC) = p;
                FIELD_AT(o, int *, 0x0) = D_800102D0;
                func_8001EFE4(g, o);
                FIELD_AT(self, char, 0x158) = m;
            }
        }
    }
    if (FIELD_AT(self, void *, 0x108) && func_800DA35C(self) && !FIELD_AT(self, signed char, 0x15F) && !FIELD_AT(self, void *, 0x104)) {
        func_800C0EB8(FIELD_AT(FIELD_AT(func_800787B4(), void *, 0x32C), void *, 0xA0));
        FIELD_AT(self, char, 0x15F) = 1;
    }
    FIELD_AT(self, short, 0x148)++;
}
