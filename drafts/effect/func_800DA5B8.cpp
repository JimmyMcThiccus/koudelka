// func_800DA5B8: 44 differ, all register renaming (retail giv=s0, p=s1, i=s2, src=s3, self=s4); it also has a jump
// table in 0x800D61B0-0x800D6528, so it can't land in the current unit even when matched (see func_800DB978.cpp).
// NEAR (44 differ, all register renaming): retail s0=giv,s1=p,s2=i,s3=src,s4=self; here i/giv/p and self/src allocation order differ. Needs a jump table.
#include "common.h"
#include "effect/effect.h"

EXTERN_C void *D_800B4C18[];
EXTERN_C void func_8001ED2C(void *self, int a, int b);
EXTERN_C void *func_800DC08C(void *self);
EXTERN_C void *func_800DC7C8(void *self);
EXTERN_C void *func_800DCC58(void *self);
EXTERN_C void *func_800DCE28(void *self);
EXTERN_C void func_800DADF8(void *self, SubNode *node);
EXTERN_C void func_800DAE48(void *self, SubNode *node);

typedef void (*Add_800DA5B8)(void *, void *, char *, void *, int);
typedef char *(*Load_800DA5B8)(void *, char *);

#define VT_800DA5B8(o, off) FIELD_AT(o, VtEntry *, off)
#define ADD_800DA5B8(self, a, p, b, i) ((Add_800DA5B8)VT_800DA5B8(self, 0)[3].pfn)((char *)(self) + VT_800DA5B8(self, 0)[3].delta, a, p, b, i)
#define LOAD_800DA5B8(o, off, p) ((Load_800DA5B8)VT_800DA5B8(o, off)[2].pfn)((char *)(o) + VT_800DA5B8(o, off)[2].delta, p)

EXTERN_C void func_800DA5B8(SlotSet *self, char *src, void *a, void *b)
{
    int i;
    char *p;
    void *o;
    FIELD_AT(self, char, 0x181) = src[0];
    FIELD_AT(self, char, 0x161) = (*(unsigned short *)src >> 7) & 1;
    FIELD_AT(self, char, 0x162) = (*(unsigned short *)src >> 8) & 1;
    FIELD_AT(self, char, 0x163) = (*(unsigned short *)src >> 9) & 1;
    p = src + 8;
    for (i = 0; i < (*(unsigned short *)src & 3); i++) {
        ADD_800DA5B8(self, a, p, b, i);
        p = LOAD_800DA5B8((void *)self->slots[i], 0x18, p + 4);
        func_800DADF8(self, (SubNode *)self->slots[i]);
    }
    if (*(unsigned int *)src & 0xC) {
        ADD_800DA5B8(self, a, p, b, 2);
        p = LOAD_800DA5B8((void *)self->slots[2], 0x18, p + 4);
        func_800DAE48(self, (SubNode *)self->slots[2]);
    }
    if (*(unsigned short *)src & 0x10) {
        char *h = p;
        switch ((signed char)h[2]) {
        case 0:
        case 1:
        case 2:
            if (h[3] & 1)
                o = func_800DC7C8(operator new(0x34));
            else
                o = func_800DC08C(operator new(0x38));
            break;
        case 4:
        case 5:
            if (h[3] & 1)
                o = func_800DCE28(operator new(0x34));
            else
                o = func_800DCC58(operator new(0x38));
            break;
        case 3:
            goto end;
        default:
            goto end;
        }
        LOAD_800DA5B8(o, 0x28, p);
        FIELD_AT(self, void *, 0x130) = o;
    }
end:
    func_8001ED2C(D_800B4C18[0], 1, 3);
}
