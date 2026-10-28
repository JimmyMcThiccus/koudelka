// func_800E4034: 5 instructions differ: retail sets flags=0x8001 in the bne delay slot and computes a0=&name at the join; the build schedules `ori s3,0x8001` before the compare.
#include "field/field.h"

struct Unk_C26 { char c[26]; };
struct Unk_800E4034_o : VAt0 { char pad4[6]; unsigned short unkA; Unk_Deletable* unkC; };
EXTERN_C int open(void*, int);
EXTERN_C int func_800E4034(Unk_800E4448* p, void* a, int mode) {
    unsigned int i;
    int flags;
    p->unk4->unk0 = 4;
    if (p->unk34 != -1 || D_800EA7B0[0] != 0) {
        return -1;
    }
    func_800E556C((Unk_800E556C*)p, a);
    Unk_C26 name = *(Unk_C26*)D_800EA7C8;
    if (mode == 1) {
        flags = 0x8002;
    } else {
        flags = 0x8001;
    }
    p->unk34 = open(&name, flags);
    for (i = 0; p->unk34 == -1; i++) {
        if (i >= 30) {
            break;
        }
        Unk_800E4034_o* o = (Unk_800E4034_o*)func_8001ED2C(D_800B4C18[0], 2, 1);
        if (o) {
            if (o->unkA == 4) {
                delete o->unkC;
            }
            o->vf01();
        }
        p->unk34 = open(&name, flags);
    }
    int r;
    if (p->unk34 == -1) {
        p->unk4->unk4 = -1;
        p->unk4->unk0 = 2;
        r = 5;
    } else {
        p->unk4->unk4 = 0;
        p->unk4->unk0 = 0;
        r = 0;
    }
    return r;
}
