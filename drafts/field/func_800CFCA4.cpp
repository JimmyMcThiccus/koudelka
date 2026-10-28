// func_800CFCA4: 7 differing: third call loads D_800B4C74 early in retail.
#include "field/field.h"

struct Unk_800CFCA4 { char pad0[8]; int unk8; char padC[0x10]; unsigned short unk1C; char pad1E[0x12]; Unk_DualList* unk30; };
EXTERN_C int D_B4C74_a[] asm("D_800B4C74");

EXTERN_C void func_800CFCA4(Unk_800CFCA4* p, void* a) {
    if (p->unk8) {
        func_8005C088(p, a, 1);
        Unk_800BFB64_node* m = first(p->unk30);
        void* o = operator new(0x50);
        void* t = (void*)D_800EA11C[0];
        func_80019A6C(m, (int)func_8002860C(o, Unk_RectP(0x80, 0x30, 0x20, 0xC0), t, p->unk1C, D_B4C74_a[0]), m->unk4);
        Unk_800BFB64_node* n = first(p->unk30);
        o = operator new(0x50);
        t = D_800EA120[0];
        func_80019A6C(n, (int)func_8002860C(o, Unk_RectP(0xA0, 0x30, 0x60, 0xC0), t, p->unk1C, D_B4C74_a[0]), n->unk4);
        Unk_800BFB64_node* q = first(p->unk30);
        o = operator new(0x50);
        t = D_800EA124[0];
        int u = D_B4C74_a[0];
        func_80019A6C(q, (int)func_8002860C(o, Unk_RectP(0x100, 0x30, 0x20, 0xC0), t, p->unk1C, u), q->unk4);
        func_8002DA94(a, p->unk30);
    }
}
