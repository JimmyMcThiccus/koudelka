// func_800D0878: ~12 instructions differ: register allocation swaps p and the constant 2 (s2/s3), and the D_800EA134 lui is scheduled differently.
#include "field/field.h"

struct Unk_PtS { short x, y; Unk_PtS(short a, short b) { x = a; y = b; } void set(short a, short b) { x = a; y = b; } };
struct Unk_800D0878 { char pad0[8]; int unk8; char unkC[0x24]; Unk_800BFB64_list* unk30; char pad34[4]; unsigned char unk38; };
EXTERN_C void func_800CC85C(void*, void*);
EXTERN_C void func_800CC914(void*, void*);
EXTERN_C Unk_Deletable* D_800EA134[];
EXTERN_C Unk_Deletable* D_800EA138[];
EXTERN_C Unk_Deletable* D_800EA140[];
EXTERN_C Unk_Deletable* D_800EA144[];
EXTERN_C void func_800D0878(Unk_800D0878* p, void* a) {
    if (p->unk8) {
        Unk_800CC28C* o;
        Unk_800BFB64_node* n;
        func_8005C088(p, a, 1);
        void* m = operator new(0x64);
        int d = (int)D_800EA134[0];
        Unk_PtS v(0, 0);
        o = (Unk_800CC28C*)func_800CC28C((Unk_800CC28C*)m, p->unkC, d, &v, 2);
        n = first(p->unk30);
        func_80019A6C(n, (int)o, n->unk4);
        switch (p->unk38) {
        case 1:
            v.set(0x40, 0);
            func_800CC85C(o, &v);
            func_800CC914(o, D_800EA140[0]);
            break;
        case 2:
            v.set(0, 0x80);
            func_800CC85C(o, &v);
            func_800CC914(o, D_800EA144[0]);
            break;
        case 3:
            v.set(0x40, 0x80);
            func_800CC85C(o, &v);
            func_800CC914(o, D_800EA138[0]);
            break;
        }
        func_8002DA94(a, p->unk30);
    }
}
