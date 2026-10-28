// func_800BE264: 5 differing: delay-slot order of beqz $s3 / addu $v1,$zero / addiu $a1,$s0,-1 around first(y) and func_80019F64; the build hoists cnt-1. Header declares (void*, Unk_Short2) so the draft casts.
#include "field/field.h"

struct He_E_ent { signed char c0; unsigned char c1; unsigned char c2; char pad3; short s4; short s6; };
struct He_E_n1 { int unk0; He_E_n1* unk4; short unk8; char padA[6]; unsigned char unk10; unsigned char unk11; char pad12[2]; unsigned short unk14; He_E_ent* unk18; };
struct He_E_X { int unk0; int unk4; };
struct He_E_Y : He_E_X, Unk_800BFB64_list { };
struct He_E_n2 { int unk0; struct He_E_n2* unk4; char pad8[4]; He_E_Y unkC; char pad_[0x14]; short unk2C; };
inline He_E_n1* next(He_E_n1* n) { return n->unk4; }
inline He_E_n2* next(He_E_n2* n) { return n->unk4; }
struct He_E_p { char pad0[0x3D8]; unsigned short unk3D8; short unk3DA; char pad3DC[0x38]; He_E_n1* unk414; char pad418[0x3C]; He_E_n2* unk454; char pad458[0x34]; int unk48C; int unk490; };
EXTERN_C void func_800BE264_i(He_E_p* p, Unk_Short2 v) asm("func_800BE264");

EXTERN_C void func_800BE264_i(He_E_p* p, Unk_Short2 v) {
    signed char last = -1;
    signed char c10 = last;
    signed char c18;
    He_E_ent* e = 0;
    He_E_Y* y = (He_E_Y*)e;
    short cnt;
    int a0, b0;
    He_E_n1* n = p->unk414;
    for (short i = p->unk3D8; i != 0; i--) {
        if (v.x == n->unk8) {
            e = n->unk18;
            c10 = n->unk10;
            c18 = n->unk11;
            cnt = n->unk14;
            break;
        }
        n = next(n);
    }
    if (e) {
        He_E_n2* m = p->unk454;
        for (int i = ((int (*)(void*))func_8001A6E8)(m); i != 0; i--) {
            if (v.y == m->unk2C) {
                y = &m->unkC;
                break;
            }
            m = next(m);
        }
        if (y) {
            y->unk4 = 0;
            for (; cnt != 0; cnt--) {
                if (last != e->c0) {
                    last = e->c0;
                    a0 = func_800BDE08((Unk_800BF204*)p, e->c0);
                    b0 = func_800BDD8C((Unk_800BDD8C*)p, c10);
                    func_80024FEC((void*)a0, b0);
                }
                int k = cnt - 1;
                void* o = func_80019F64(first(y), k);
                func_800BB1BC((Unk_800BB1BC*)o, (Unk_800BB1BC_arg*)b0);
                func_800BB068(o, a0, c18);
                func_800BB128((Unk_Sprt16_24*)o, e->c1, e->c2);
                ((VAt0*)o)->vf07(e->s4 + p->unk48C, e->s6 + p->unk490);
                e++;
            }
        }
    }
}
