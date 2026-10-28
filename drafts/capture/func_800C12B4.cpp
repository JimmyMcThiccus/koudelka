// ~150 differ: structure is right (two record loops, C_800C25B0 built via new + func_800C25B0, list add, virtual delete of the colour object), but retail spills several locals (z, last, c0, &xy temp, (signed char)c1, &o->v) and the hard-register assignment of p/r/cnt/c1/col differs. Needs func_800C25B0's z parameter as int (it still matches that way).
#include "common.h"
#include "capture/capture.h"

// C_800C23F8 / V_800C23F8: identical to the definitions landed with func_800C23F8
struct V_800C23F8 {
    void *p;
    int n;
    void *data;
    int buf[1];
    void init(int cap)
    {
        data = buf;
        p = buf;
        ((void *(*)(void *, int, int))func_800198E0)(data, cap, 0);
        n = 0;
    }
};
struct C_800C23F8 {
    void *vt;
    int f4;
    short f8;
    short pad;
    V_800C23F8 v;
    int pad1C[4];
    short f2C;
    int f30, f34, f38;
    C_800C23F8();
};
// as in func_800C25B0
struct Pt_800C25B0 {
    short x, y;
    Pt_800C25B0(short a, short b) : x(a), y(b) {}
};
struct S_800C25B0;
EXTERN_C S_800C25B0 *func_800C25B0(S_800C25B0 *p, Pt_800C25B0 xy, Pt_800C25B0 uv, char *q1, char *q2, short abr, int z, int unused, int f44);

struct Rec_800C12B4 {
    signed char id;
    unsigned char u, v;
    char pad;
    short x, y;
};
struct F_800C12B4 {
    int pad;
    F_800C12B4 *next;
    short id;
    char pad2[2];
    int fC;
    signed char c10;
    unsigned char c11;
    char pad3[2];
    short n;
    char pad4[2];
    Rec_800C12B4 *recs;
};
EXTERN_C void *func_8002972C(void *, int, int, int, int);
EXTERN_C int func_800C0820(char *p, signed char key);
EXTERN_C int func_800C089C(char *p, signed char key);
EXTERN_C void func_80024FEC(void *, int);
EXTERN_C void func_80019A6C(void *, int, int);
EXTERN_C S_800C25B0 *func_800C12B4(char *p, signed char key, C_800C23F8 *o)
{
    int z = 0;
    signed char last = -1;
    signed char c0 = -1;
    Rec_800C12B4 *r = 0;
    S_800C25B0 *ret = 0;
    int a = 0, b = 0;
    unsigned char c1;
    short cnt;
    VObject *col = (VObject *)func_8002972C(operator new(8), 0xFF, 0xFF, 0xFF, 1);
    F_800C12B4 *f = *(F_800C12B4 **)(p + 0x40C);
    short n = *(short *)(p + 0x3D0);
    while (1) {
        if (!n)
            break;
        if (key == f->id) {
            z = f->fC;
            r = f->recs;
            c0 = f->c10;
            c1 = f->c11;
            cnt = f->n;
            break;
        }
        n--;
        f = f->next;
    }
    if (!r)
        return 0;
    o->f30 = cnt;
    while (1) {
        if (!cnt)
            break;
        if (last != r->id) {
            last = r->id;
            b = func_800C089C(p, r->id);
            a = func_800C0820(p, c0);
            func_80024FEC((void *)b, a);
        }
        if (!ret) {
            ret = func_800C25B0((S_800C25B0 *)operator new(0x4C), Pt_800C25B0(r->x + *(short *)(p + 0x484), r->y + *(short *)(p + 0x488)), Pt_800C25B0(r->u, r->v), (char *)a, (char *)b, (signed char)c1, z, (int)col, 1);
            int **c = (int **)&o->v;
            int *vb = c ? *c : 0;
            func_80019A6C(vb, (int)ret, vb[1]);
        } else {
            S_800C25B0 *s = func_800C25B0((S_800C25B0 *)operator new(0x4C), Pt_800C25B0(r->x + *(short *)(p + 0x484), r->y + *(short *)(p + 0x488)), Pt_800C25B0(r->u, r->v), (char *)a, (char *)b, (signed char)c1, z, (int)col, 1);
            int **c = (int **)&o->v;
            int *vb = c ? *c : 0;
            func_80019A6C(vb, (int)s, vb[1]);
        }
        r++;
        cnt--;
    }
    if (col) {
        VtblEntry *e = &col->vt[1];
        ((void (*)(void *, int))e->pfn)((char *)col + e->delta, 3);
    }
    return ret;
}
