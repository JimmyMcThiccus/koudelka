// 41 differ (was ~150): '&D_800102D0' as int (not hoisted), type-2 as switch(case 0 falls into case 100), 'found += 0xB10' before the info copy. Left: p/found swapped (s2/s3; found=0 placed just before the loop fixes it but moves the store), switch(m->arg) for cases 1/10/11 lacks retail's index copy (addu a0,v1), 0x13 const ordering, movstr scratch regs.
#include "common.h"
#include "capture/capture.h"

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C int D_800102D0;
EXTERN_C char D_800127FC[];
EXTERN_C char D_800AC86C[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C void *func_8001ED2C(void *, int, int);
EXTERN_C char *func_800382A4(void *, int, void *);
EXTERN_C void func_800B870C(void *);
EXTERN_C char *func_800B8BDC(void *, int, int, void *);
EXTERN_C void func_800B9020(void *, int);

struct T_800BB838 {
    void *vt;
    void *f4;
    int f8, fC, f10;
    char f14;
    T_800BB838(void *a)
    {
        vt = D_800127FC;
        f8 = 5;
        f4 = a;
        f14 = 0;
        fC = 0;
        f10 = 0;
    }
};
struct MB0_800BB838 {
    void *vt;
    int f4;
    MB0_800BB838()
    {
        vt = D_80010178;
        f4 = 0;
    }
};
struct MB1_800BB838 : MB0_800BB838 {
    short f8, fA;
    void *fC;
    int f10;
    MB1_800BB838(short a, short b, int c, void *d)
    {
        vt = D_80010300;
        f8 = a;
        fA = b;
        f10 = c;
        fC = d;
    }
};
struct M_800BB838 : MB1_800BB838 {
    M_800BB838(short a, short b, int c, void *d) : MB1_800BB838(a, b, c, d) { vt = &D_800102D0; }
    static void *operator new(unsigned int n) { return func_8001CA10(n); }
};
struct Msg_800BB838 {
    VtblEntry *vt;
    char pad[6];
    unsigned short type;
    int pad2;
    int arg;
};
struct Blk_800BB838 {
    int w[16];
};

EXTERN_C void func_800BB838(char *p)
{
    T_800BB838 *t = new T_800BB838(p);
    char *found = 0;
    Blk_800BB838 info;
    *(short *)(p + 0x104) = 1;
    func_8001EFE4(p, new M_800BB838(2, 7, 0, 0));
    while (*(short *)(p + 0x104)) {
        Msg_800BB838 *m = (Msg_800BB838 *)func_8001ED2C(p, 1, 1);
        if (!m)
            continue;
        if (m->type == 6) {
            switch (m->arg) {
            case 1:
                func_8001EFE4(*(void **)(p + 0x100), new M_800BB838(2, 0x14, 0, 0));
                break;
            case 10:
            case 11:
                func_800B870C(*(void **)(p + 0x108));
                if (!*(int *)(*(char **)(p + 0x108) + 0x22C)) {
                    func_8001EFE4(p, new M_800BB838(2, 0x13, 100, 0));
                }
                break;
            }
        }
        if (m->type == 7) {
            do
                found = func_800382A4(D_800AC86C, 4, t);
            while (!found);
        }
        if (m->type == 2) {
            switch (m->arg) {
            case 0:
                delete t;
                *(char **)(p + 0x108) = func_800B8BDC(operator new(0x23C), info.w[0], 0x6013, p);
                if (*(int *)(*(char **)(p + 0x108) + 0x22C))
                    break;
            case 100:
                func_800B9020(*(void **)(p + 0x108), 0x100);
                break;
            }
        }
        if (m->type == 5 && m->arg == 0) {
            found += 0xB10;
            info = *(Blk_800BB838 *)found;
            func_8001EFE4(p, new M_800BB838(2, 2, 0, 0));
        }
        if (m) {
            VtblEntry *e = &m->vt[2];
            ((void (*)(void *))e->pfn)((char *)m + e->delta);
        }
    }
}
