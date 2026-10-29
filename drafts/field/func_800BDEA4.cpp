// r4c: still 5. Global-alloc priority: o (3 refs) beats e->a (2 refs); retail is the reverse. Tried: 36 statement orders x 3 types, 48 declaration orders (block and function scope), permuter ~5k iterations. Header now returns int (retail returns r).
// func_800BDEA4: 5 differing: o and the ushort are in swapped s1/s0. Needs asm alias for the header declaration.
#include "common.h"
#include "shared/exe.h"
#include "field/field.h"

struct Unk_BDEA4_e { unsigned short a; };
struct Unk_BDEA4_n { void* vtbl; Unk_BDEA4_n* unk4; unsigned short unk8; char padA[0xA]; Unk_BDEA4_e* unk14; };
EXTERN_C int func_800BE7EC(void*, int, Unk_800C0344*);
EXTERN_C Unk_800C0344* func_800C0344(Unk_800C0344*);
EXTERN_C int func_800BDEA4_i(Unk_800BF204* p, void* a) asm("func_800BDEA4");

EXTERN_C int func_800BDEA4_i(Unk_800BF204* p, void* a) {
    Unk_BDEA4_n* n = (Unk_BDEA4_n*)p->unk3EC;
    int r = 0;
    for (int i = ((int (*)(void*))func_8001A6E8)(n); i != 0; i--) {
        Unk_800C0344* o = func_800C0344((Unk_800C0344*)operator new(0x3C));
        Unk_BDEA4_e* e = n->unk14;
        unsigned short s2 = n->unk8;
        unsigned short s0 = e->a;
        r = func_800BE7EC(p, *(signed char*)e, o);
        o->unk8 = s0;
        o->unk2C = s2;
        func_8001A678(a, o);
        n = n->unk4;
    }
    return r;
}
