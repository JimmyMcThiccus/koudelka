// 10 differ (was ~70): fixed by 'short running' (loop test copies it to v0), '&D_800102D0' as int (not hoisted), separate i/j and c/c2 per copy loop. Left: loop 1 swaps i/c regs (a1/a2) and i=0 lands in the blez delay slot instead of the bnez one; retail computes src=p+0x118 after the entry test and copies it to the walker.
#include "common.h"
#include "capture/capture.h"

EXTERN_C char D_80010178[];
EXTERN_C char D_80010300[];
EXTERN_C int D_800102D0;
EXTERN_C char *D_800B4ED8[];
EXTERN_C char *func_8001CA10(int);
EXTERN_C void func_8001EFE4(void *, void *);
EXTERN_C void *func_8001EB60(void *, int);
EXTERN_C void *func_8001ED2C(void *, int, int);
EXTERN_C void func_800232A0(void *, void *);
EXTERN_C void func_8002DC34(void *, void *, int);
EXTERN_C void func_80039C88(void *, int);
EXTERN_C int func_800BD534(char *p, int);
EXTERN_C void func_800BD604(S_800BD604 *p, Short12 *v);
struct S_800BCF18;
EXTERN_C void func_800BCF18(S_800BCF18 *);

// stand-in for the unit's C_800BCE0C (only the ctor and f2918 are used)
struct C_800BCE0C {
    char pad[0x2918];
    int f2918;
    int pad2[2];
    C_800BCE0C(int a, int b, int c);
};

struct MB0_800BC650 {
    void *vt;
    int f4;
    MB0_800BC650()
    {
        vt = D_80010178;
        f4 = 0;
    }
};
struct MB1_800BC650 : MB0_800BC650 {
    short f8, fA;
    void *fC;
    int f10;
    MB1_800BC650(short a, short b, int c, void *d)
    {
        vt = D_80010300;
        f8 = a;
        fA = b;
        f10 = c;
        fC = d;
    }
};
struct M_800BC650 : MB1_800BC650 {
    M_800BC650(short a, short b, int c, void *d) : MB1_800BC650(a, b, c, d) { vt = &D_800102D0; }
    static void *operator new(unsigned int n) { return func_8001CA10(n); }
};
struct Msg_800BC650 {
    VtblEntry *vt;
    char pad[6];
    unsigned short type;
    VObject *from;
    int arg;
};
struct Clock_800BC650 {
    char pad[0x44];
    char *f44;
};
EXTERN_C Clock_800BC650 D_800A4534;

struct E_800BC650 {
    char pad[0x10];
    ShortPair pos;
    ShortPair getPos() { return pos; }
};
struct C2_800BC650 {
    char pad[0x30];
    char *list0[4];
    unsigned short n0;
    char pad2[6];
    char *list1[4];
    unsigned short n1;
};
struct S_800BC650 {
    char pad0[0xF8];
    char *fF8;
    char pad2[0x108 - 0xFC];
    void *f108;
    int f10C, f110;
    C2_800BC650 *f114;
    char *f118[4];
    char *f128[4];
    short f138, f13A;
    void *f13C, *f140, *f144;
    E_800BC650 *f148, *f14C, *f150;
};

static inline void *vfn12_800BC650(char *o)
{
    VtblEntry *e = &(*(VtblEntry **)(o + 0x2C))[12];
    return ((void *(*)(void *))e->pfn)(o + e->delta);
}

EXTERN_C void func_800BC650(S_800BC650 *p)
{
    short running = 1;
    {
        int i;
        for (i = 0; i < p->f138; i++) {
            if (p->f118[i])
                *(short *)(p->f118[i] + 0x1D8) = 0;
        }
    }
    {
        int j = 0;
        while (1) {
            if (!(j < p->f13A))
                break;
            func_80039C88(D_800B4ED8[0] ? D_800B4ED8[0] + 0x50 : 0, *(int *)(p->f128[j] + 0x1B8));
            j++;
        }
    }
    p->f114 = (C2_800BC650 *)new C_800BCE0C(p->f10C, p->f110, (int)p);
    if (!((C_800BCE0C *)p->f114)->f2918)
        func_8001EFE4(p, new M_800BC650(2, 2, 0, 0));
    while (running) {
        Msg_800BC650 *m = (Msg_800BC650 *)func_8001EB60(p, 1);
        if (!m)
            continue;
        if (m->type == 4 && m->arg == 0) {
            VObject *x = m->from;
            char *vb = p ? p->fF8 : 0;
            VtblEntry *e = &(*(VtblEntry **)vb)[3];
            char *self = p ? p->fF8 : 0;
            ((void (*)(void *, void *))e->pfn)(self + e->delta, x);
            if (x) {
                VtblEntry *d = &x->vt[1];
                ((void (*)(void *, int))d->pfn)((char *)x + d->delta, 3);
            }
        }
        if (m->type == 2 && m->arg == 0) {
            Short12 v;
            int i = 0;
            short n = p->f138;
            C2_800BC650 *c = p->f114;
            char **src = p->f118;
            for (; i < n; i++)
                c->list0[(short)c->n0++] = src[i];
            n = p->f13A;
            if (n) {
                int j = 0;
                C2_800BC650 *c2 = p->f114;
                src = p->f128;
                for (; j < n; j++)
                    c2->list1[(short)c2->n1++] = src[j];
            }
            v.v[2] = v.v[6] = v.v[10] = 0x19;
            v.v[3] = v.v[7] = v.v[11] = 0x28;
            v.v[0] = p->f148->getPos().a;
            v.v[1] = p->f148->getPos().b;
            v.v[4] = p->f14C->getPos().a;
            v.v[5] = p->f14C->getPos().b;
            v.v[8] = p->f150->getPos().a;
            v.v[9] = p->f150->getPos().b;
            func_800BD604((S_800BD604 *)p->f114, &v);
            func_800BD534((char *)p->f114, 0x100);
        }
        if (m->type == 6) {
            int a = m->arg;
            switch (a) {
            case 5000:
                func_800232A0(D_800A4534.f44 + 0x154, p);
                func_8001EFE4(p->f108, new M_800BC650(2, 2, a, 0));
                break;
            case 1:
                func_800232A0(D_800A4534.f44 + 0x154, p);
                func_8001EFE4(p->f108, new M_800BC650(2, 2, a, 0));
                func_8002DC34(vfn12_800BC650(D_800A4534.f44), p->f13C, 0);
                func_8002DC34(vfn12_800BC650(D_800A4534.f44), p->f140, 0);
                running = 0;
                func_8002DC34(vfn12_800BC650(D_800A4534.f44), p->f144, 0);
                break;
            case 5:
                func_8001EFE4(p->f108, new M_800BC650(2, 2, 0, 0));
                break;
            case 10:
            case 11:
                func_800BCF18((S_800BCF18 *)p->f114);
                if (!((C_800BCE0C *)p->f114)->f2918)
                    func_8001EFE4(p, new M_800BC650(2, 2, 0, 0));
                break;
            }
        }
        if (m) {
            VtblEntry *e = &m->vt[2];
            ((void (*)(void *))e->pfn)((char *)m + e->delta);
        }
    }
    while (func_8001ED2C(p, 0x3C, 1))
        ;
}
