#include "common.h"
#define EXE_H_IN_u_80033ECC
#include "shared/exe.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"

EXTERN_C int func_80033ECC(void *p)
{
    int a = AT(p, int, 0xC);
    if (a) {
        if (AT(p, void *, 4)) func_8001A678(AT(p, void *, 4), a);
        else AT(p, int, 4) = a;
    }
    int b = AT(p, int, 8);
    AT(p, int, 8) = 0;
    AT(p, int, 0xC) = b;
    return 0;
}

EXTERN_C void func_80033F30(void *p, int a)
{
    AT(p, void **, 0) = D_80011F44;
    func_8001D324(D_800A4544, func_8001D25C(D_800A4544, (int)p));
    func_8001D024(p, a);
}

EXTERN_C void *func_80033F9C(void *p)
{
    void *g;
    AT(p, void **, 0) = D_80011F44;
    AT(p, int, 8) = 0;
    AT(p, int, 4) = 0;
    AT(p, int, 0xC) = 0;
    g = D_800A4544;
    func_8001D150(g, new S_A2_X40(p));
    return p;
}

EXTERN_C void func_80034028(S_800323C0 *p, S_800323C0_Node *n)
{
    if (p->unk8)
        n->unk4 = p->unk8;
    p->unk8 = n;
}

EXTERN_C S_A2_C98 *func_80034044(S_A2_Pool98 *pool)
{
    S_A2_C98 *n = pool->head;
    if (n) {
        pool->head = (S_A2_C98 *)n->unk4;
        n->unk4 = 0;
        return n;
    }
    return a2_init_C98((S_A2_C98 *)operator new(sizeof(S_A2_C98)));
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034184);

EXTERN_C int func_80034608(S_80034608 *p)
{
    return p->unk4;
}

EXTERN_C S_A2_C98 *func_80034614(S_A2_C98 *p)
{
    return a2_init_C98(p);
}

EXTERN_C void func_80034710(void *p, int flags)
{
    AT(p, void **, 8) = D_80011E8C;
    AT(p, void **, 0) = D_80011EF4;
    AT(p, void **, 8) = D_80011D04;
    AT(p, void **, 0) = D_80011D6C;
    AT(p, void **, 8) = D_80011AAC;
    AT(p, void **, 0) = D_80011B14;
    func_800198AC((char *)p + 8, 0);
    func_8001A610(p, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003479C);

EXTERN_C void func_80034854(void *p, void *q)
{
    AT(p, int, 0) = AT(q, int, 0);
    func_80034EBC(p ? (char *)p + 4 : 0, (char *)q + 4);
}

EXTERN_C void func_8003488C(void *p, int a)
{
    func_80034B84((S_A2_Flags *)p, a != -1);
    if (a != -1)
        func_80034F24((S_80034F24 *)(p ? (char *)p + 4 : 0), a);
}

EXTERN_C int func_800348E4(void *p)
{
    if ((AT(p, unsigned char, 3) >> 1) & 1) {
        char *q = p ? (char *)p + 4 : 0;
        return (AT(q, unsigned short, 6) >> 5) & 3;
    }
    return -1;
}

EXTERN_C S_80034924_B *func_80034924(S_80034924_A *p, S_80034924_B *q)
{
    int a = p->unk4, b = p->unk8, c = p->unkC, d = p->unk10;
    q->unkC = a;
    q->unk14 = b;
    q->unk1C = c;
    q->unk24 = d;
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003494C);

EXTERN_C int func_800349F8(void *p, short *r)
{
    short *q = (short *)((char *)p + 8);
    int maxx = 0, maxy = 0;
    int minx = r[2], miny = r[3];
    int i, x, y;
    for (i = 4; i; i--) {
        x = q[0];
        if (x < minx) minx = x;
        if (maxx < x) maxx = x;
        y = q[1];
        if (y < miny) miny = y;
        if (maxy < y) maxy = y;
        q += 4;
    }
    return minx == r[2] || !maxx || miny == r[3] || !maxy;
}

C_80034AA0::C_80034AA0()
{
    int i;
    S_A2_PolyFT4 *q = p;
    i = 2;
    while (i--) {
        q->len = 9;
        q->code = 0x2C;
        q++;
    }
}

EXTERN_C S_Prim *func_80034AF4(S_Prim *p)
{
    ((unsigned char *)&p->tag)[3] = 9;
    p->code = 0x2C;
    return p;
}

EXTERN_C int func_80034B0C(S_Rgb *s, S_Rgb *a, S_Rgb *b, S_Rgb *c, S_Rgb *d)
{
    S_Rgb t = *s;
    *a = t;
    *b = t;
    *c = t;
    *d = t;
    return 1;
}

EXTERN_C void func_80034B84(S_A2_Flags *p, int on)
{
    unsigned char v = p->f;
    if (on) p->f = v | 2; else p->f = v & ~2;
}

EXTERN_C S_80034BA8 *func_80034BA8(S_80034BA8 *p, int v)
{
    p->unk0 = v;
    return p;
}

EXTERN_C int func_80034BB4(S_80034BB4 *p)
{
    return (p->unk3 >> 1) & 1;
}

EXTERN_C void func_80034BC8(int *a, int *b)
{
    *a = *b;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034BD4);

EXTERN_C void func_80034EBC(void *d, void *s)
{
    int i = 0;
    unsigned short b = *(unsigned short *)0x1F800000;
    unsigned char *q = (unsigned char *)d;
    unsigned short *v = (unsigned short *)s;
    unsigned short v4, v2;
    for (; i < 4; i++) {
        unsigned short x = *v++;
        q[0] = x + b;
        q[1] = (x >> 8) + (b >> 8);
        q += 4;
    }
    v4 = *(unsigned short *)0x1F800004;
    v2 = *(unsigned short *)0x1F800002;
    AT(d, unsigned short, 2) = v4;
    AT(d, unsigned short, 6) = v2;
}

EXTERN_C void func_80034F24(S_80034F24 *p, int a)
{
    p->unk6 = (p->unk6 & 0xFF9F) | ((a & 3) << 5);
}

EXTERN_C int func_80034F40(S_80034F40 *p)
{
    return (p->unk6 >> 5) & 3;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034F54);

EXTERN_C void *func_800351A4(void *p, int vb)
{
    if (vb) {
        char *b = (char *)p + 0x3C;
        AT(p, void *, 4) = b;
        AT(p, short, 0x3C) = 16;
        AT(b, short, 2) = 1;
        AT(b, int, 4) = -1;
    }
    AT(p, void **, 0) = D_80012154;
    AT(p, void **, 8) = D_8001201C;
    AT(p, void **, 0) = D_80012034;
    AT(p, void *, 0xC) = (char *)p + 0x10;
    ((int (*)(void *, int, int))func_800198E0)((char *)p + 0x10, 4, 0);
    AT(p, void **, 8) = D_80012294;
    AT(p, void **, 0) = D_80012224;
    AT(p, void **, 8) = D_80011F5C;
    AT(p, int, 0x28) = 0;
    AT(p, int, 0x2C) = 0;
    AT(p, void **, 0) = D_80011F74;
    return p;
}

EXTERN_C void func_8003525C(void *p, int flags)
{
    AT(p, void **, 8) = D_80011F5C;
    AT(p, void **, 0) = D_80011F74;
    AT(p, void **, 8) = D_80012294;
    AT(p, void **, 0) = D_80012224;
    func_80035304(p, 0);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C int func_800352D4()
{
    return 0;
}

EXTERN_C int func_800352DC(S_800352DC *p)
{
    return p->unk4;
}

EXTERN_C void func_800352E8(S_800352DC *p, int v)
{
    p->unk4 = v;
}

EXTERN_C S_Vobj *func_800352F0(S_Vobj *p)
{
    p->vtbl = D_80011FE4;
    return p;
}

EXTERN_C void func_80035304(void *p, int flags)
{
    AT(p, void **, 8) = D_8001201C;
    AT(p, void **, 0) = D_80012034;
    func_80035384(p);
    func_80019920(AT(p, List *, 0xC), 0);
    func_8001D024((char *)p + 8, 0);
    func_80035AB0(p, 0);
    if (flags & 1)
        operator delete(p);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035384);


EXTERN_C int func_8003546C(void *vp, void *vo)
{
    S_A2_VH0C *p = (S_A2_VH0C *)vp;
    A2VObj0 *o = (A2VObj0 *)vo;
    int r = p->v05(o->v05());
    AT(o, int, 4) = r;
    List *l = &p->h;
    func_80019A6C(l, (int)o, l->count);
    char *g = D_800A4544;
    int key = (int)(p ? (char *)p + 8 : 0);
    if (!func_8001D25C(g, key)) {
        void *k = p ? (char *)p + 8 : 0;
        func_8001D150(g, new S_A2_X44764(k));
    }
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003556C);

EXTERN_C void *func_80035678(void *p, int vb, short c)
{
    if (vb) {
        char *b = (char *)p + 0x24;
        AT(p, void *, 4) = b;
        AT(p, short, 0x24) = 16;
        AT(b, short, 2) = c;
        AT(b, int, 4) = -1;
    }
    AT(p, void **, 0) = D_80012154;
    AT(p, void **, 8) = D_8001201C;
    AT(p, void **, 0) = D_80012034;
    AT(p, void *, 0xC) = (char *)p + 0x10;
    func_800198E0((char *)p + 0x10, 4, 0);
    return p;
}

EXTERN_C void func_800356F4(void *p)
{
    func_80035384(p);
    ((void (*)(void *))func_80035B5C)(p ? (char *)p + 0x24 : 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003572C);

EXTERN_C void func_800357E0(void *p, int flags)
{
    AT(p, void **, 8) = D_80012074;
    AT(p, void **, 0x24) = D_8001208C;
    AT(p, void **, 0) = D_800120B4;
    func_80035B28((char *)p + 0x24, 0);
    func_80035304(p, 0);
    if (flags & 1)
        operator delete(p);
}

extern "C++" int f3585C(S_A2_Strm *p, unsigned int n) asm("func_8003585C");
int f3585C(S_A2_Strm *p, unsigned int n)
{
    unsigned int avail = p->end;
    unsigned int c = p->cur;
    avail = avail - c;
    void *r;
    if (n >= avail)
        n = avail;
    r = (void *)p->v04(n);
    if (r) {
        CdGetSector(r, n >> 2);
        return 1;
    }
    return 0;
}

EXTERN_C int func_800358D4(S_800358D4 *p)
{
    return p->unk1C;
}

EXTERN_C void func_800358E0(void *p)
{
    func_8001AA68(p ? (char *)p + 8 : 0, 0);
}

EXTERN_C void func_80035910(void *p)
{
    func_8001AB50(p ? (char *)p + 8 : 0, 0);
}

EXTERN_C char *func_80035940(void *p, int n)
{
    char *r = 0;
    char *b = AT(p, char *, 0x24);
    if (b && AT(p, unsigned int, 0x20) < AT(p, unsigned int, 0x1C)) {
        r = b + AT(p, unsigned int, 0x20);
        AT(p, unsigned int, 0x20) += n;
        if (AT(p, unsigned int, 0x20) > AT(p, unsigned int, 0x1C))
            AT(p, unsigned int, 0x20) = AT(p, unsigned int, 0x1C);
    }
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003598C);

EXTERN_C void func_80035A28(void *p, int flags)
{
    char *b = (char *)p + 8;
    AT(p, void **, 0xC) = D_80012104;
    AT(p, void **, 8) = D_800120F4;
    AT(p, void **, 0) = D_8001211C;
    AT(b, void **, 4) = D_800101C0;
    AT(b, void **, 0) = D_800101B0;
    func_800198AC(b, 0);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C void func_80035AB0(void *p, int a)
{
    AT(p, void **, 0) = D_80012154;
    if (a & 1)
        operator delete(p);
}

EXTERN_C void func_80035AE4()
{
}

EXTERN_C int func_80035AEC()
{
    return 0;
}

EXTERN_C void *func_80035AF4(void *p, int a, short c)
{
    if (a) {
        char *b = (char *)p + 8;
        AT(p, void *, 4) = b;
        AT(p, short, 8) = 16;
        AT(b, short, 2) = c;
        AT(b, int, 4) = -1;
    }
    AT(p, void **, 0) = D_80012154;
    return p;
}

EXTERN_C void func_80035B28(void *p, int a)
{
    AT(p, void **, 0) = D_800121AC;
    if (a & 1)
        operator delete(p);
}

EXTERN_C void func_80035B5C()
{
}

EXTERN_C void *func_80035B64(void *p, int a, short c)
{
    if (a) {
        char *b = (char *)p + 8;
        AT(p, void *, 4) = b;
        AT(p, short, 8) = 16;
        AT(b, short, 2) = c;
        AT(b, int, 4) = -1;
    }
    AT(p, void **, 0) = D_800121AC;
    return p;
}

EXTERN_C int func_80035B98(A2VObj0 *p, unsigned int n)
{
    void *r = (void *)p->v04(n);
    if (r) {
        CdGetSector(r, n >> 2);
        return 1;
    }
    return 0;
}

EXTERN_C void func_80035BF0()
{
}

EXTERN_C void func_80035BF8()
{
    CdInit();
    func_80035CD8();
    func_800375E4();
}

EXTERN_C void func_80035C28()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035C30);

EXTERN_C int func_80035CA8()
{
    int a = 0xFF;
    int i;
    for (i = 0; i < 3; i++) a &= D_800B4D10[i];
    return a != 0;
}

EXTERN_C void func_80035CD8()
{
    int i = 3;
    unsigned char *p = &D_800B4D10[3];
    do { *p-- = 0; } while (--i >= 0);
}

EXTERN_C void func_80035CF8()
{
    if (D_800B4D0C) {
        func_80036674((S_A2_H0C *)D_800B4D0C);
        ((A2VObj0 *)D_800B4D0C)->v07(2);
    }
}

EXTERN_C void func_80035D4C(int a)
{
    if (!D_800B4D0C) {
        List *l = &D_800AC854;
        int v = l->count ? *AT(l, int *, 0) : 0;
        if (v == a)
            ((A2VObj0 *(*)(void *, int))func_80019C68)((List *)&D_800AC854, 0)->v00(0);
    }
}

EXTERN_C void func_80035DE0(int a)
{
    List *l;
    func_800186E8(&D_800A451C);
    l = &D_800AC854;
    func_80019A6C(l, a, l->count);
    func_80035D4C(a);
    func_80018788(&D_800A451C);
}

EXTERN_C void func_80035E4C(int a)
{
    func_800186E8(&D_800A451C);
    func_80019A6C((List *)&D_800AC854, a, 0);
    func_80035D4C(a);
    func_80018788(&D_800A451C);
}

EXTERN_C void func_80035EB4(int a)
{
    func_800186E8(&D_800A451C);
    func_80019CFC((List *)&D_800AC854, a);
    func_80035D4C(a);
    func_80018788(&D_800A451C);
}

EXTERN_C void func_80035F18()
{
    func_800188D4(&D_800A451C);
    CdDataCallback(0);
    if (D_800B4D0C)
        ((A2VObj0 *)D_800B4D0C)->v08();
    func_80018970(&D_800A451C);
}

EXTERN_C void func_80035F80(unsigned char a, int b)
{
    func_800188D4(&D_800A451C);
    if (D_800B4D0C)
        ((A2VObj0 *)D_800B4D0C)->v09(a, b);
    else
        CdReadyCallback(0);
    func_80018970(&D_800A451C);
}

EXTERN_C void func_80036000(unsigned char a, int b, int c)
{
    func_800188D4(&D_800A451C);
    if (D_800B4D0C)
        ((A2VObj0 *)D_800B4D0C)->v10(a, b, c);
    else
        func_8009D030(0);
    func_80018970(&D_800A451C);
}

EXTERN_C void func_80036090(unsigned char a, int b)
{
    func_800188D4(&D_800A451C);
    CdSyncCallback(0);
    if (D_800B4D0C)
        ((A2VObj0 *)D_800B4D0C)->v11(a, b);
    func_80018970(&D_800A451C);
}

EXTERN_C void func_80036110(void *p, int a)
{
    unsigned short *q = AT(p, unsigned short *, 4);
    AT(p, char, 0x34) = 0;
    AT(p, char, 0x35) = 0x15;
    int cur = D_800B4D0C;
    *q |= 1;
    if (cur == (int)p) {
        CdReadyCallback(0);
        D_800B4D0C = 0;
        if (!(unsigned char)func_80035C30(a & 0xFF)) {
            List *l = &D_800AC854;
            if (l->count)
                ((A2VObj0 *(*)(void *, int))func_80019C68)((List *)&D_800AC854, 0)->v00(0);
        }
    }
}

extern "C++" void f361C8(S_A2_VH0C *p) asm("func_800361C8");
void f361C8(S_A2_VH0C *p)
{
    AT(p, int, 0x30) += 0x800;
    if (!((unsigned)AT(p, int, 0x30) < (unsigned)AT(p, int, 0x28)))
        p->v07(2);
    if (AT(p, int, 0x2C)) return;
    List *l = &p->h;
    A2VObj0 *s = l->count ? AT(l, A2VObj0 **, 0)[0] : 0;
    if (!s) return;
    s->v03();
    if (!p->v06(AT(s, int, 4))) return;
    s->v00(p ? (char *)p + 8 : 0);
    func_80019C68((List *)&p->h, 0);
    AT(AT(p, int *, 4), int, 4) = AT(p, int, 0x30);
    if (!count_of(&p->h) && (unsigned)AT(p, int, 0x30) < (unsigned)AT(p, int, 0x28)) {
        p->v07(2);
        AT(p, int, 0x28) = AT(p, int, 0x30);
    }
}

EXTERN_C void func_8003635C()
{
}

extern "C++" void f36364(S_A2_St *p, int t, unsigned char *buf) asm("func_80036364");
void f36364(S_A2_St *p, int t, unsigned char *buf)
{
    unsigned char loc[16];
    t &= 0xFF;
    switch (t) {
    case 1: {
        int b0 = buf[0];
        if (b0 & 0x1D) goto fin;
        if (AT(p, signed char, 0x34) != 5) return;
        if (AT(p, unsigned, 0x30) < AT(p, unsigned, 0x28)) {
            CdGetSector(loc, 3);
            int pos = CdPosToInt(loc);
            if (pos == AT(p, unsigned, 0x24)) {
                AT(p, unsigned, 0x24) = AT(p, unsigned, 0x24) + 1;
                if (AT(p, unsigned, 0x2C)) {
                    CdGetSector((void *)(AT(p, unsigned, 0x2C) + AT(p, unsigned, 0x30)), 0x200);
                } else {
                    if (!count_of(&p->h)) goto zero;
                    List *l = &p->h;
                    A2VObj0 *s = l->count ? AT(l, A2VObj0 **, 0)[0] : 0;
                    s->v02(0x800);
                }
                p->v08();
                return;
            zero:
                p->v07(buf[0]);
                AT(p, unsigned, 0x28) = AT(p, unsigned, 0x30);
                return;
            }
            if (pos + 1 == AT(p, unsigned, 0x24)) return;
            AT(p, signed char, 0x34) = 0xE;
            CdReadyCallback(0);
            return;
        }
        p->v07(b0);
        return;
    }
    case 5:
    fin:
        CdReadyCallback(0);
        p->v12(buf);
        return;
    default:
        return;
    }
}

EXTERN_C void func_80036554(A2VObj0 *p, unsigned char t, unsigned char *buf)
{
    if (t == 2) {
        switch ((signed char)(AT(p, unsigned char, 0x34) - 1)) {
        case 0:
            if (AT(p, signed char, 0x35) == 4)
                AT(p, signed char, 0x35) = 5;
            break;
        case 2:
            if (AT(p, signed char, 0x35) == 0xF)
                AT(p, signed char, 0x35) = 0x10;
            break;
        case 5:
            if (AT(p, signed char, 0x35) == 0x14)
                p->v07(buf[0]);
            break;
        case 1:
        case 3:
            if (AT(p, signed char, 0x35) == 0xA) {
                AT(p, char, 0x34) = 5;
                AT(p, signed char, 0x35) = 0xB;
                AT(p, short, 0x38) = ((unsigned)(AT(p, int, 0x28) - AT(p, int, 0x30)) >> 12) + 0x78;
                CdReadyCallback((int)func_80035F80);
            }
            break;
        }
    } else
        p->v12(buf);
}

EXTERN_C void func_80036674(S_A2_H0C *p)
{
    while (count_of(&p->h))
        ((A2VObj0 *(*)(void *, int))func_80019C68)((List *)&p->h, 0)->v01(0);
}

EXTERN_C int func_800366F8(A2VObj0 *p)
{
    unsigned char buf[8];
    switch (CdSync(1, buf)) {
    case 2:
        return 1;
    case 5:
        p->v12(buf);
        return 0;
    default:
        if (!(buf[0] & 0x1D)) return 0;
        p->v12(buf);
        return 0;
    }
}

EXTERN_C void func_80036780(A2VObj0 *p, unsigned char *b)
{
    if ((b[0] & 0x10) || ((b[0] & 1) && (b[1] & 0x40))) {
        p->v07(b[0]);
        func_80036674((S_A2_H0C *)p);
        func_8003831C(&D_800AC86C, b[0] ^ 2);
    } else {
        void *q = p ? AT(p, void *, 4) : 0;
        AT(p, char, 0x35) = (((AT(q, unsigned short, 0) >> 4) ^ 1) & 1) ? 0xD : 0x12;
    }
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036850);

EXTERN_C void func_80036D8C(A2VObj0 *p)
{
    void *q = p ? AT(p, void *, 4) : 0;
    if (((AT(q, unsigned short, 0) >> 4) ^ 1) & 1)
        p->v02();
    if (D_800B4D0C == (int)p) {
        int key = (int)(p ? (char *)p + 8 : 0);
        char *g = D_800A4544;
        func_8001D324(g, func_8001D25C(g, key));
        void *k = p ? (char *)p + 8 : 0;
        func_8001D150(g, new S_A2_X1(k));
    } else if (p)
        p->v04(3);
}

EXTERN_C void *func_80036EB8(void *p, void *q)
{
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036EC0);

EXTERN_C int func_80036F14(void *p)
{
    int r;
    void *s = AT(p, void *, 4);
    int v = AT(s, int, 4);
    if (v >= 0) {
        r = AT(p, unsigned char *, 0x2C)[v];
        AT(s, int, 4) = v + 1;
    } else
        r = -1;
    return r;
}

EXTERN_C int func_80036F54(void *p, int a, int b)
{
    int pos = AT(AT(p, void *, 4), int, 4);
    if (pos < 0)
        return 0;
    func_80025CE0(a, AT(p, char *, 0x2C) + pos, b);
    AT(AT(p, void *, 4), int, 4) += b;
    return b;
}

EXTERN_C int func_80036FC0(void *p, int a, int b)
{
    if (D_800B4D0C) return 0;
    if ((unsigned char)func_80035C30((unsigned char)func_8009C9C0())) return 0;
    unsigned short *q = AT(p, unsigned short *, 4);
    AT(p, int, 0x24) = a;
    AT(p, int, 0x28) = b;
    *q = 0;
    AT(p, short, 0x3A) = 0x10;
    AT(p, char, 0x36) = 0;
    AT(p, char, 0x35) = func_8009C9E0() != 9 ? 3 : 5;
    char *g = D_800A4544;
    int key = (int)(p ? (char *)p + 8 : 0);
    if (!func_8001D25C(g, key)) {
        void *k = p ? (char *)p + 8 : 0;
        func_8001D150(g, new S_A2_X44764(k));
    }
    D_800B4D0C = (int)p;
    return 1;
}

EXTERN_C void func_800370D0(void *p)
{
    int t;
    void *g;
    func_80035384(p);
    t = AT(p, int, 0x30);
    g = (void *)D_800B4D0C;
    AT(p, int, 0x28) = t;
    if (g == p) {
        AT(p, char, 0x35) = 0x12;
        AT(p, char, 0x34) = 0;
        CdSyncCallback(0);
        CdReadyCallback(0);
    }
    AT(AT(p, void *, 4), int, 4) = -1;
    if (AT(p, void *, 0x2C))
        __builtin_vec_delete(AT(p, void *, 0x2C));
    AT(p, void *, 0x2C) = 0;
}

EXTERN_C int func_8003714C(void *vp)
{
    S_A2_VH0C *p = (S_A2_VH0C *)vp;
    if (D_800B4D0C != (int)p) return 0;
    int s = 0;
    List *l;
    if (count_of(&p->h)) {
        l = &p->h;
        A2VObj0 *o = l->count ? AT(l, A2VObj0 **, 0)[0] : 0;
        if (!o->v04(0) && !AT(p, int, 0x2C)) s = 1;
    } else
        s = 1;
    if (s) AT(p, void *, 0x2C) = __builtin_vec_new((((unsigned)AT(p, int, 0x28) + 0x7FF) >> 11) << 11);
    int *q = AT(p, int *, 4);
    AT(p, int, 0x30) = 0;
    q[1] = 0;
    AT(p, char, 0x36) = 1;
    return 1;
}

EXTERN_C int func_80037258(S_80037258 *p)
{
    return p->unk28;
}

EXTERN_C void func_80037264()
{
    func_80019920((List *)((S_800186B0 *)&D_800AC854)->p, 0);
}

EXTERN_C void func_8003728C()
{
    AT(&D_800AC854, void *, 0) = (char *)&D_800AC854 + 4;
    func_800198E0((char *)&D_800AC854 + 4, 4, 0);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_8001231C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_8001232C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_80012354);

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_80012364);

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_8001237C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_800123EC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80033ECC", D_80012404);
