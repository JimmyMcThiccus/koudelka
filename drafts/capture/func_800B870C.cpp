// 164 differ, 52 bytes short. The rodata table copy MATCHES with 'EXTERN_C Tbl_800B870C D_800B6E34' (struct of short[16]) + 'tbl = D_800B6E34' (lwl/lwr, no new rodata). Left: stack temp slot layout (Pt temp at sp+3C, getpt temps at sp+40, setrect copy at sp+4C, x spilled to sp+5C), register assignment.
#include "common.h"
#include "capture/capture.h"

EXTERN_C void func_80035EB4(void *);
EXTERN_C void func_80035DE0(void *);
EXTERN_C S_800B9E74 *func_800B94FC(void *, int, int);
EXTERN_C bool func_800B9CF4(char *, int, int);
EXTERN_C int func_800B9E74(S_800B9E74 *p, int v, int i);
EXTERN_C void *func_800A0D2C(int);
EXTERN_C void func_800A0D0C(void *);
EXTERN_C void *memset(void *, int, int);
EXTERN_C char D_80010178[];
EXTERN_C char D_800106EC[];
EXTERN_C char D_80010654[];
EXTERN_C char D_80010888[];
EXTERN_C char D_800108A0[];
EXTERN_C char D_800B4C48[];
EXTERN_C char D_800112F4[];
EXTERN_C char D_800B6E9C[];
EXTERN_C VObj10 *D_800B4C38[];
EXTERN_C char *D_800A4578[];
EXTERN_C void *D_800B4C18[];
EXTERN_C void func_80021ACC(void *, void *);
EXTERN_C void func_80024CA0(void *, void *, int, int);
EXTERN_C void func_80025444(void *, void *, int);
EXTERN_C void func_8002972C(void *, int, int, int, int);
EXTERN_C void func_800198AC(void *, int);
EXTERN_C void func_8001A864(void *, void *);
EXTERN_C void *func_8001ED2C(void *, int, int);

// rodata table copied to the stack (must stay in rodata: force_not_migration)
struct Tbl_800B870C {
    short v[16];
};
EXTERN_C Tbl_800B870C D_800B6E34;

struct Pt_800B870C {
    short x, y;
    Pt_800B870C(short a, short b) : x(a), y(b) {}
};
struct Size_800B870C {
    short w, h;
    Size_800B870C() {}
    Size_800B870C(short a, short b) : w(a), h(b) {}
};
struct Rect_800B870C {
    short x, y;
    Size_800B870C s;
    Rect_800B870C() {}
    Rect_800B870C(short a, short b, short c, short d) : x(a), y(b), s(c, d) {}
};
struct Col_800B870C {
    void *vt;
    unsigned char c[4];
    Col_800B870C(int r, int g, int b, int a) { func_8002972C(this, r, g, b, a); }
    ~Col_800B870C() { func_800198AC(this, 2); }
};
struct Spr_800B870C {
    VtblEntry *vt;
    int f4;
    void *vt2;
    void *o;
    Pt_800B870C pt;
    short f14, f16;
    int f18;
    unsigned short f1C;
    short f1E;
    void setpt(Pt_800B870C p) { pt = p; }
    Pt_800B870C getpt() { return pt; }
};
// base ctor is func_8002860C (EXE)
__asm__(".set __10B_800B870Ciiii, func_8002860C");
struct B_800B870C {
    void *vt;
    char pad4[8];
    B_800B870C(int, int, int, int);
};
struct Box_800B870C : B_800B870C {
    void *vtC;
    char pad10[0x40];
    Rect_800B870C f50;
    int f58;
    int f5C;
    void setrect(Rect_800B870C r) { f50 = r; }
    Box_800B870C(const Rect_800B870C &r, void *s, int k, const Col_800B870C &c)
        : B_800B870C((int)&r, (int)s, k, (int)&c)
    {
        vtC = D_800112F4;
        vt = D_800B6E9C;
        f58 = 0;
    }
};
struct Box4_800B870C {
    char pad[4];
    Box_800B870C *link;
};
struct L_800B870C {
    char pad[0x64];
    Box_800B870C *head;
};
struct VObj2C_800B870C {
    char pad[0x2C];
    VtblEntry *vt;
};
struct S_800B870C {
    char pad0[0x18];
    S_800B9E74 *f18;
    C_800BA258 *f1C;
    char pad20[8];
    Box_800B870C *box[2][31];
    Spr_800B870C *spr[2][31];
    char pad218[0x22C - 0x218];
    int f22C;
    void *f230;
    int f234, f238;
};

struct C_800B8BDC;
EXTERN_C void func_800B870C(C_800B8BDC *pc)
{
    S_800B870C *p = (S_800B870C *)pc;
    Tbl_800B870C tbl;
    void *buf;
    int i, x;
    if (p->f22C)
        func_80035EB4(p->f230);
    if (!p->f18)
        p->f18 = func_800B94FC(operator new(0xA8), 1, 1);
    if (!func_800B9CF4((char *)p->f18, p->f234, p->f238)) {
        func_80035DE0(p->f230);
        p->f22C = 1;
        return;
    }
    p->f22C = 0;
    p->f1C = new C_800BA258(0x5000, 5, 0);
    i = 0;
    x = 0;
    func_800B9E74(p->f18, (int)p->f1C, 1);
    tbl = D_800B6E34;
    buf = func_800A0D2C(0x280);
    memset(buf, i, 0x280);
    while (1) {
        int j;
        if (!(i < 2))
            break;
        j = 0;
        while (1) {
            if (!(j < 31))
                break;
            char *o = (char *)operator new(0x2C);
            *(char **)o = D_80010178;
            *(int *)(o + 4) = 0;
            *(char **)o = D_800106EC;
            *(short *)(o + 8) = 0;
            *(short *)(o + 0xA) = 0;
            *(char **)o = D_80010654;
            func_80021ACC(o, &tbl);
            {
                VObj10 *m = D_800B4C38[0];
                VtblEntry *e = &m->vt[1];
                ((void (*)(void *, void *))e->pfn)((char *)m + e->delta, o);
            }
            Spr_800B870C *t = (Spr_800B870C *)operator new(0x20);
            t->vt2 = D_80010888;
            t->vt = (VtblEntry *)D_80010178;
            t->f4 = 0;
            t->vt = (VtblEntry *)D_800108A0;
            t->o = o;
            t->setpt(Pt_800B870C(-1, -1));
            t->f14 = 0;
            t->f16 = 0;
            t->f18 = 0;
            t->f1E = 0x32;
            func_80024CA0(p->spr[i][j] = t, buf, 0xA0, 8);
            func_80025444(D_800B4C48, p->spr[i][j], 0);
            p->box[i][j] = new Box_800B870C(Rect_800B870C(x, j * 8, 0xA0, 8), p->spr[i][j], 1, Col_800B870C(0x80, 0x80, 0x80, 1));
            p->box[i][j]->setrect(Rect_800B870C(p->spr[i][j]->getpt().x, p->spr[i][j]->getpt().y, 0x28, 8));
            p->box[i][j]->f5C = j * 8;
            {
                VObj2C_800B870C *a = (VObj2C_800B870C *)D_800A4578[0];
                VtblEntry *e = &a->vt[12];
                L_800B870C *l = ((L_800B870C * (*)(void *))e->pfn)((char *)a + e->delta);
                Box_800B870C *h = l->head;
                Box_800B870C *b = p->box[i][j];
                if (h) {
                    if (((Box4_800B870C *)b)->link)
                        func_8001A864(h, ((Box4_800B870C *)b)->link);
                    ((Box4_800B870C *)b)->link = h;
                }
                l->head = b;
            }
            j++;
        }
        i++;
        x += 0xA0;
    }
    func_8001ED2C(D_800B4C18[0], 5, 3);
    if (buf)
        func_800A0D0C(buf);
}
