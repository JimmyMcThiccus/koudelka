// func_800E2844: matches under try_compile (0 differing) but contains a jump table: the compiled table shifts rodata in matching mode (field.bin differs), so it is not landed. Needs the unit/rodata arrangement for its jump table.
#include "field/field.h"

struct Unk_800E2844 { char pad0[0x18]; void* vt18; char pad1C[0x6C]; VAt0* unk88; };
EXTERN_C void func_800E2A6C(void*, void*, int, void*, int);
EXTERN_C void func_800E1288(void*);
EXTERN_C void func_800E1898(void*);
EXTERN_C void func_800E1BA0(void*);
EXTERN_C void func_800E2C08(void*);
EXTERN_C void func_800E2D88(void*);
EXTERN_C void func_800E59E4(void*);
EXTERN_C void func_800E1F28(void*);

EXTERN_C int func_800E2844(Unk_800E2844* p, int a) {
    int r = func_80063744(p, a);
    if (r == 0) {
        switch (a) {
        case 3:
            p->unk88->vf02();
            func_800553D8(0);
            ((VAt<0x18>*)p)->vf02();
            break;
        case 4:
            p->unk88->vf02();
            func_800E2A6C(p, D_800B9EC0, 0xF, D_800B9BB4, 0);
            func_80054CE4((char*)p + 0x1BC);
            break;
        case 5:
            func_800E2D88(p);
            break;
        case 6:
            func_800E1288(p);
            break;
        case 7:
            func_800E1898(p);
            break;
        case 8:
            func_800E1BA0(p);
            break;
        case 9:
            func_800E2C08(p);
            break;
        case 10:
            switch (*(int*)((char*)p + 0x158)) {
            case 0:
                func_800E2D88(p);
                break;
            case 1:
                func_80055330(0);
                func_80053CD8((char*)p + 0x114);
                func_80053CD8((char*)p + 0x130);
                func_80053CD8((char*)p + 0xF8);
                func_80054CE4((char*)p + 0x8C);
                func_80054FE0((char*)p + 0x1BC);
                *(int*)((char*)p + 0x158) = 0;
                func_800553D8(0);
                *(int*)((char*)p + 0x2BB8) = -1;
                *(int*)((char*)p + 0x281C) = 0;
                func_800E59E4((char*)p + 0x27FC);
                break;
            case 2:
                *(int*)((char*)p + 0x2BB8) = 2;
                *(int*)((char*)p + 0x2CC8) = 0;
                func_80062978((char*)p + 0x2E80);
                func_800631D4((char*)p + 0x2CA8);
                break;
            case 3:
                func_800E1F28(p);
                break;
            }
            break;
        }
    }
    return r;
}
