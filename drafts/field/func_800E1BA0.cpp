// func_800E1BA0: 9 differing: r (func_800E4E70 result) lives in s1, retail keeps it in v1; avoiding the cross-jump of the two unk158=1 stores costs an extra sltu.
#include "field/field.h"

EXTERN_C char D_800B9D18[];
EXTERN_C char D_800B9D68[];
EXTERN_C char D_800B9DA4[];
EXTERN_C int func_800E4620(void*);

EXTERN_C void func_800E1BA0(char* p) {
    func_80055330(0);
    func_800E2A6C(p, (int)D_800B9D18, 0x26, (int)D_800B9BB4, 0);
    func_80054CE4(p + 0x1BC);
    for (unsigned i = 0; i < 8; i++) func_8005556C(2, 1);
    int r = func_800E4E70(((Unk_800E1898*)p)->unk88);
    ((Unk_800E1898b*)p)->unk15C = r;
    if (r && r != 4) {
        ((Unk_800E1898*)p)->unk84 = 0;
        for (int i = 0; i < 15; i++) {
            ((Unk_800E1898*)p)->unk244[i].vf02();
        }
        func_80019D40(first(&((Unk_800E1898*)p)->unk1C));
        switch (((Unk_800E1898b*)p)->unk15C) {
        case 3:
            func_800E2A6C(p, (int)D_800B9BB8, 0x1E, (int)D_800B9BB4, 0);
            func_80054CE4(p + 0x1BC);
            for (unsigned i = 0; i < 30; i++) func_8005556C(2, 1);
            ((Unk_800E1898b*)p)->unk158 = 0;
            goto fin;
        case 1:
            func_800E2A6C(p, (int)D_800B9BF8, 0x18, (int)D_800B9BB4, 0);
        default:
            if (((Unk_800E1898b*)p)->unk15C != 1) {
                func_800E2A6C(p, (int)D_800B9CBC, 0x19, (int)D_800B9BB4, 0);
            }
            func_80054CE4(p + 0x1BC);
            for (unsigned i = 0; i < 60; i++) func_8005556C(2, 1);
            ((Unk_800E1898b*)p)->unk158 = 1;
            goto fin2;
        }
    } else {
        if (!func_800E4620(((Unk_800E1898*)p)->unk88)) {
        func_8008EF40(12);
        r = func_800E4E70(((Unk_800E1898*)p)->unk88);
        ((Unk_800E1898b*)p)->unk15C = r;
        if (r == 0) {
            func_800E2A6C(p, (int)D_800B9D68, 0x1C, (int)D_800B9BB4, 0);
            func_80054CE4(p + 0x1BC);
            for (unsigned i = 0; i < 30; i++) func_8005556C(2, 1);
            ((Unk_800E1898b*)p)->unk158 = 0;
            goto fin;
        }
        if (r == 1) {
            func_800E2A6C(p, (int)D_800B9BF8, 0x18, (int)D_800B9BB4, 0);
            func_80054CE4(p + 0x1BC);
            for (unsigned i = 0; i < 40; i++) func_8005556C(2, 1);
            ((Unk_800E1898b*)p)->unk158 = (r != 0);
            goto fin2;
        }
        func_800E2A6C(p, (int)D_800B9BF8, 0x18, (int)D_800B9BB4, 0);
        func_80054CE4(p + 0x1BC);
        for (unsigned i = 0; i < 40; i++) func_8005556C(2, 1);
        ((Unk_800E1898b*)p)->unk158 = 0;
        goto fin;
        }
        func_800E2A6C(p, (int)D_800B9DA4, 0x18, (int)D_800B9BB4, 0);
        ((Unk_800E1898b*)p)->unk158 = 1;
        func_80054CE4(p + 0x1BC);
        for (unsigned i = 0; i < 30; i++) func_8005556C(2, 1);
    }
fin2:
    func_800553D8(0);
fin:
    func_80054FE0(p + 0x1BC);
    func_8005549C(10, p, 0, -1);
}
