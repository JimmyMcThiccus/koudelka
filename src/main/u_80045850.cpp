#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"
#include "game/a2b/a2b.h"

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80045850);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_800459D4);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80045B38);

EXTERN_C void func_80045C88(S_80045C88 *p, int a)
{
    p->unk1C[p->unk44++] = a;
}

EXTERN_C void *func_80045CAC(void *p, short a, short b)
{
    if (a == AT(p, short, 0xA) && b == AT(p, short, 0xC))
        return p;
    if (AT(p, void *, 4))
        return func_80045CAC(AT(p, void *, 4), a, b);
    return 0;
}

EXTERN_C int func_80045D18(S_80045D18 *p)
{
    return p->unk30;
}

EXTERN_C void func_80045D24(void *p)
{
    if (AT(p, void *, 0x1C)) {
        int a = AT(p, int, 0x24);
        int b = AT(p, int, 0x2C);
        unsigned short s = AT(p, unsigned short, 0x20);
        void *o = func_8001CA10(0x14);
        AT(o, void **, 0) = D_80010178;
        AT(o, int, 4) = 0;
        AT(o, void **, 0) = D_80010300;
        AT(o, short, 8) = 2;
        AT(o, void **, 0) = D_800102D0;
        AT(o, short, 0xA) = s;
        AT(o, int, 0x10) = a;
        AT(o, int, 0xC) = b;
        func_8001EFE4(AT(p, void *, 0x1C), o);
    }
}

EXTERN_C void func_80045DC8(void *p)
{
    if (AT(p, void *, 0x1C)) {
        int a = AT(p, int, 0x28);
        int b = AT(p, int, 0x2C);
        unsigned short s = AT(p, unsigned short, 0x20);
        void *o = func_8001CA10(0x14);
        AT(o, void **, 0) = D_80010178;
        AT(o, int, 4) = 0;
        AT(o, void **, 0) = D_80010300;
        AT(o, short, 8) = 2;
        AT(o, void **, 0) = D_800102D0;
        AT(o, short, 0xA) = s;
        AT(o, int, 0x10) = a;
        AT(o, int, 0xC) = b;
        func_8001EFE4(AT(p, void *, 0x1C), o);
    }
}

EXTERN_C char *func_80045E6C(void *p, int n)
{
    char *r = 0;
    char *b = AT(p, char *, 0x38);
    if (b && AT(p, unsigned int, 0x34) < AT(p, unsigned int, 0x30)) {
        r = b + AT(p, unsigned int, 0x34);
        AT(p, unsigned int, 0x34) += n;
        if (AT(p, unsigned int, 0x34) > AT(p, unsigned int, 0x30))
            AT(p, unsigned int, 0x34) = AT(p, unsigned int, 0x30);
    }
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80045EB8);

EXTERN_C void func_80045F84(void *p, int flags)
{
    char *b = (char *)p + 8;
    AT(p, void **, 0xC) = D_800129AC;
    AT(p, void **, 8) = D_8001299C;
    AT(p, void **, 0) = D_800129C4;
    AT(b, void **, 4) = D_800101C0;
    AT(b, void **, 0) = D_800101B0;
    func_800198AC(b, 0);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C int func_8004600C(void *p, int a, int b, void *q)
{
    if (func_800464E4(p, a, b, q) != 1)
        return 0;
    AT(q, int, 0x1D4) = AT(p, int, 0x1C);
    AT(q, int, 0x1D0) = AT(p, int, 0x10);
    AT(q, int, 0x1A8) = AT(p, int, 0x14);
    AT(q, int, 0x1AC) = AT(p, int, 0x18);
    return 1;
}

EXTERN_C int func_80046078(void *p, int a, int b, void *q)
{
    if (func_800461F4(p, a, b, q) != 1)
        return 0;
    AT(q, int, 0x1D4) = AT(p, int, 0x1C);
    AT(q, int, 0x1D0) = AT(p, int, 0x10);
    AT(q, int, 0x1A8) = AT(p, int, 0x14);
    AT(q, int, 0x1AC) = AT(p, int, 0x18);
    return 1;
}

EXTERN_C int func_800460E4(void *p, int i, void *q)
{
    if (func_800464E4(p, D_800AE598[i].a, D_800AE598[i].b, q) != 1)
        return 0;
    AT(q, int, 0x1D4) = AT(p, int, 0x1C);
    AT(q, int, 0x1D0) = AT(p, int, 0x10);
    AT(q, int, 0x1A8) = AT(p, int, 0x14);
    AT(q, int, 0x1AC) = AT(p, int, 0x18);
    return 1;
}

EXTERN_C int func_8004616C(void *p, int i, void *q)
{
    if (func_800461F4(p, D_800AE538[i].a, D_800AE538[i].b, q) != 1)
        return 0;
    AT(q, int, 0x1D4) = AT(p, int, 0x1C);
    AT(q, int, 0x1D0) = AT(p, int, 0x10);
    AT(q, int, 0x1A8) = AT(p, int, 0x14);
    AT(q, int, 0x1AC) = AT(p, int, 0x18);
    return 1;
}

EXTERN_C int func_800461F4(void *p, int a, int b, void *cc)
{
    void *o1 = func_80048D64(p, a, b, (int)cc, 0, 0);
    AT(p, void *, 4) = o1;
    { void *t = AT(o1, void *, 4); AT(p, int, 8) = AT(p, int, 0xC) = AT(o1, int, 0x2C) + AT(t, int, 4); }
    while (AT(AT(p, int *, 8), int, 0) != 0x32313130) {
        void *q = AT(p, void *, 4);
        void *o;
        ((A2VObj0 *)q)->v02();
        func_80036D8C(AT(p, void *, 4));
        o = func_80048D64(p, a, b, (int)cc, 0, 0);
        AT(p, void *, 4) = o;
        AT(p, int, 8) = AT(p, int, 0xC) = AT(o, int, 0x2C) + AT(AT(o, void *, 4), int, 4);
    }
    int ret;
    AT(p, int, 0) = func_80046998(p, p);
    if (AT(p, int, 0)) {
        AT(cc, int, 0x138) = func_80046948(p, p, AT(cc, short, 0x144));
        ((A2VObj0 *)AT(p, void *, 4))->v02();
        func_80036D8C(AT(p, void *, 4));
        ret = 1;
    } else {
        ((A2VObj0 *)AT(p, void *, 4))->v02();
        func_80036D8C(AT(p, void *, 4));
        ret = 0;
    }
    return ret;
}

EXTERN_C int func_8004637C(void *p, int a, int b, int c)
{
    void *o1 = func_80048D64(p, a, b, c, 0, 0);
    AT(p, void *, 4) = o1;
    { void *t = AT(o1, void *, 4); AT(p, int, 8) = AT(p, int, 0xC) = AT(o1, int, 0x2C) + AT(t, int, 4); }
    while (AT(AT(p, int *, 8), int, 0) != 0x32313130) {
        void *q = AT(p, void *, 4);
        void *o;
        ((A2VObj0 *)q)->v02();
        func_80036D8C(AT(p, void *, 4));
        o = func_80048D64(p, a, b, c, 0, 0);
        AT(p, void *, 4) = o;
        AT(p, int, 8) = AT(p, int, 0xC) = AT(o, int, 0x2C) + AT(AT(o, void *, 4), int, 4);
    }
    int ret;
    AT(p, int, 0) = func_80046998(p, p);
    if (AT(p, int, 0)) {
        ((A2VObj0 *)AT(p, void *, 4))->v02();
        func_80036D8C(AT(p, void *, 4));
        ret = 1;
    } else {
        ((A2VObj0 *)AT(p, void *, 4))->v02();
        ret = 0;
    }
    return ret;
}

EXTERN_C int func_800464E4(void *p, int a, int b, void *cc)
{
    void *o1 = func_80048D64(p, a, b, (int)cc, 0, 0);
    AT(p, void *, 4) = o1;
    { void *t = AT(o1, void *, 4); AT(p, int, 8) = AT(p, int, 0xC) = AT(o1, int, 0x2C) + AT(t, int, 4); }
    while (AT(AT(p, int *, 8), int, 0) != 0x32313130) {
        void *q = AT(p, void *, 4);
        void *o;
        ((A2VObj0 *)q)->v02();
        func_80036D8C(AT(p, void *, 4));
        o = func_80048D64(p, a, b, (int)cc, 0, 0);
        AT(p, void *, 4) = o;
        AT(p, int, 8) = AT(p, int, 0xC) = AT(o, int, 0x2C) + AT(AT(o, void *, 4), int, 4);
    }
    int ret;
    AT(p, int, 0) = func_80046998(p, p);
    if (AT(p, int, 0)) {
        ((A2VObj0 *)AT(p, void *, 4))->v02();
        func_80036D8C(AT(p, void *, 4));
        ret = 1;
    } else {
        ((A2VObj0 *)AT(p, void *, 4))->v02();
        func_80036D8C(AT(p, void *, 4));
        ret = 0;
    }
    return ret;
}

EXTERN_C int func_80046658(void *p, int a, int b, int c)
{
    void *o1 = func_80048D64(p, a, b, c, 0, 0);
    AT(p, void *, 4) = o1;
    { void *t = AT(o1, void *, 4); AT(p, int, 8) = AT(p, int, 0xC) = AT(o1, int, 0x2C) + AT(t, int, 4); }
    while (AT(AT(p, int *, 8), int, 0) != 0x32313130) {
        void *q = AT(p, void *, 4);
        void *o;
        ((A2VObj0 *)q)->v02();
        func_80036D8C(AT(p, void *, 4));
        o = func_80048D64(p, a, b, c, 0, 0);
        AT(p, void *, 4) = o;
        AT(p, int, 8) = AT(p, int, 0xC) = AT(o, int, 0x2C) + AT(AT(o, void *, 4), int, 4);
    }
    int ret;
    AT(p, int, 0) = func_80046998(p, p);
    if (AT(p, int, 0)) {
        ((A2VObj0 *)AT(p, void *, 4))->v02();
        func_80036D8C(AT(p, void *, 4));
        ret = 1;
    } else {
        ((A2VObj0 *)AT(p, void *, 4))->v02();
        func_80036D8C(AT(p, void *, 4));
        ret = 0;
    }
    return ret;
}

EXTERN_C int func_800467CC(void *p, int a, void *q)
{
    int r;
    AT(p, int, 8) = a;
    r = func_80046998(p, p);
    AT(p, int, 0) = r;
    if (!r)
        return 0;
    AT(q, int, 0x1D4) = AT(p, int, 0x1C);
    AT(q, int, 0x1D0) = AT(p, int, 0x10);
    AT(q, int, 0x1A8) = AT(p, int, 0x14);
    AT(q, int, 0x1AC) = AT(p, int, 0x18);
    return 1;
}

EXTERN_C int func_80046844(void *p, int a, void *q)
{
    int r;
    AT(p, int, 0xC) = a;
    AT(p, int, 8) = a;
    r = func_80046998(p, p);
    AT(p, int, 0) = r;
    if (!r)
        return 0;
    AT(q, int, 0x1D4) = AT(p, int, 0x1C);
    AT(q, int, 0x1D0) = AT(p, int, 0x10);
    AT(q, int, 0x1A8) = AT(p, int, 0x14);
    AT(q, int, 0x1AC) = AT(p, int, 0x18);
    AT(q, int, 0x138) = func_80046948(p, p, AT(q, short, 0x144));
    return 1;
}

EXTERN_C void func_800468D0()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_800468D8);

EXTERN_C int func_80046948(void *p, void *q, int a)
{
    char buf[16];
    int r = func_80048C30(p, AT(q, void *, 0xC), buf, (short)a, -1);
    func_80044C7C(D_800B4D38, (void *)r);
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80046998);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80048C30);

EXTERN_C void func_80048D2C(void *p, int a)
{
    if (a & 1)
        operator delete(p);
}

EXTERN_C void *func_80048D54(void *p)
{
    return p;
}

EXTERN_C void func_80048D5C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80048D64);

EXTERN_C int func_8004921C(void *a, void *b, short c, short d)
{
    char buf[16];
    return func_80048C30(a, b, buf, c, d);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80049250);

EXTERN_C void *func_80049398(void *p)
{
    return p;
}

EXTERN_C S_1F80000C *func_800493A0(void *p, int i)
{
    return &D_1F80000C[i];
}

EXTERN_C int func_800493BC(S_800493BC *p)
{
    return p->unkB;
}

EXTERN_C void func_800493C8(S_800493C8 *p, int a)
{
    p->unk8 = (a << 24) | (p->unk8 & 0xFFFFFF);
}

EXTERN_C void *func_800493E8(void *p, int a)
{
    AT(p, void **, 4) = D_80011B5C;
    AT(p, int, 0) = 0;
    AT(p, void **, 4) = D_80012BC8;
    AT(p, int, 8) = (a << 24) | 0x808080;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80049420);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80049488);

EXTERN_C void *func_80049594(void *p, int a)
{
    AT(p, void **, 4) = D_80011B5C;
    AT(p, int, 0) = 0;
    AT(p, void **, 4) = D_80012BC8;
    AT(p, int, 8) = (a << 24) | 0x808080;
    AT(p, void **, 4) = D_80012BF8;
    return p;
}

EXTERN_C S_A2_SvList *func_800495D8(S_A2_SvList *p, S_A2_Sv *v)
{
    p->v[p->n++] = *v;
    return p;
}

EXTERN_C S_1F800010 *func_80049618(void *p, int i)
{
    return &D_1F800010[i];
}

C_8004962C::C_8004962C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80049680);

C_80049748::C_80049748()
{
    vt = D_80012C58;
}

EXTERN_C unsigned int *func_800497A8(unsigned int *p)
{
    int i;
    unsigned int c = 0x30808080;
    for (i = 2; i >= 0; i--)
        p[i] = c;
    return p;
}

EXTERN_C void func_800497D4(int *a, int *b)
{
    int i;
    for (i = 0; i < 3; i++)
        *a++ = *b++;
}

C_800497FC::C_800497FC()
{
    vt = D_80012C88;
    func_8001AA28(unkC, 3);
}

EXTERN_C void func_80049858()
{
}

EXTERN_C int func_80049860()
{
    return 0;
}

EXTERN_C int func_80049868(void *p, short a)
{
    if (AT(p, short, 6) > 0) {
    int s = func_80026014(a);
    int c = func_800260A4(a);
    return ratan2((AT(p, short, 4) * s - AT(p, short, 8) * c) / AT(p, short, 6), 0x1000);
    }
    return 0x400;
}

EXTERN_C int func_8004991C(void *p, short a)
{
    if (AT(p, short, 6) > 0) {
    int s = func_800260A4(a);
    int c = func_80026014(a);
    return ratan2((AT(p, short, 4) * s - AT(p, short, 8) * c) / AT(p, short, 6), 0x1000);
    }
    return 0x400;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_800499D0);

EXTERN_C int func_80049A7C(void *p, int i)
{
    return D_800B4D3C[i];
}

EXTERN_C void func_80049A94(void *p, int a)
{
    func_800198AC(p, a);
}

EXTERN_C void func_80049AB4(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x44;
        while (p != q) {
            q -= 0x44;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_80049B2C(S_80049B2C *p)
{
    return &p->unk44;
}

EXTERN_C int func_80049B34()
{
    return 0x20;
}

EXTERN_C int func_80049B3C()
{
    return 0;
}

EXTERN_C void func_80049B44()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80049B4C);

EXTERN_C char *func_80049CE4(S_A2_At18 *p, char *src)
{
    func_800499D0(p, src);
    p->c = *(S_Rgb *)(src + 0x10);
    return src + 0x14;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80049D2C);

C_80049E98::C_80049E98()
{
    vt = D_80012CF8;
}

EXTERN_C void func_80049F00(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012CF8;
    func_800198AC(p, a);
}

EXTERN_C void func_80049F28(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x44;
        while (p != q) {
            q -= 0x44;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_80049FA0(S_80049FA0 *p)
{
    return &p->unk44;
}

EXTERN_C int func_80049FA8()
{
    return 0;
}

EXTERN_C void func_80049FB0()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80049FB8);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004A16C);

C_8004A2F4::C_8004A2F4()
{
    vt = D_80012D70;
}

EXTERN_C void func_8004A35C(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012CF8;
    func_800198AC(p, a);
}

EXTERN_C void func_8004A384(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x68;
        while (p != q) {
            q -= 0x68;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004A404(S_8004A404 *p)
{
    return &p->unk68;
}

EXTERN_C int func_8004A40C()
{
    return 0x24;
}

EXTERN_C int func_8004A414()
{
    return 0;
}

EXTERN_C void func_8004A41C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004A424);

EXTERN_C char *func_8004A5C8(void *p, char *src)
{
    func_800499D0(p, src);
    func_8004A954(p ? (char *)p + 0x18 : 0, src + 0x10);
    return src + 0x1C;
}

EXTERN_C void func_8004A610(void *p, int a)
{
    func_8004A98C(p ? (char *)p + 0x18 : 0, a);
}

EXTERN_C void func_8004A640(void *p)
{
    func_8004A9E4(p ? (char *)p + 0x18 : 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004A670);

C_8004A7F0::C_8004A7F0()
{
    vt = D_80012DE8;
}

EXTERN_C void func_8004A874(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012DE8;
    func_800198AC(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004A89C);

EXTERN_C void func_8004A954(void *p, void *q)
{
    AT(p, int, 0) = AT(q, int, 0);
    func_8004AE24(p ? (char *)p + 4 : 0, (char *)q + 4);
}

EXTERN_C void func_8004A98C(void *p, int a)
{
    func_80034B84((S_A2_Flags *)p, a != -1);
    if (a != -1)
        func_8004AE8C((S_80034F24 *)(p ? (char *)p + 4 : 0), a);
}

EXTERN_C int func_8004A9E4(void *p)
{
    if ((AT(p, unsigned char, 3) >> 1) & 1) {
        char *q = p ? (char *)p + 4 : 0;
        return (AT(q, unsigned short, 6) >> 5) & 3;
    }
    return -1;
}

EXTERN_C S_8004AA24_B *func_8004AA24(S_8004AA24_A *p, S_8004AA24_B *q)
{
    int a = p->unk4, b = p->unk8, c = p->unkC;
    q->unkC = a;
    q->unk14 = b;
    q->unk1C = c;
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004AA44);

EXTERN_C int func_8004AAF0(char *p, short *q)
{
    short *s = (short *)(p + 8);
    int minx, miny, maxx = 0, maxy = 0, n = 3;
    minx = q[2];
    miny = q[3];
    do {
        int x = s[0];
        if (x < minx) minx = x;
        if (maxx < x) maxx = x;
        int y = s[1];
        if (y < miny) miny = y;
        if (maxy < y) maxy = y;
        s += 4;
    } while (--n);
    int r = 0;
    if (minx == q[2] || !maxx || miny == q[3] || !maxy)
        r = 1;
    return r;
}

C_8004AB98::C_8004AB98()
{
    int i;
    S_A2_PolyFT3 *q = p;
    i = 2;
    while (i--) {
        q->len = 7;
        q->code = 0x24;
        q++;
    }
}

EXTERN_C S_Prim *func_8004ABEC(S_Prim *p)
{
    ((unsigned char *)&p->tag)[3] = 7;
    p->code = 0x24;
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004AC04);

EXTERN_C void func_8004AE24(void *d, void *s)
{
    int i = 0;
    unsigned short b = *(unsigned short *)0x1F800000;
    unsigned char *q = (unsigned char *)d;
    unsigned short *v = (unsigned short *)s;
    unsigned short v4, v2;
    for (; i < 3; i++) {
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

EXTERN_C void func_8004AE8C(S_80034F24 *p, int a)
{
    p->unk6 = (p->unk6 & 0xFF9F) | ((a & 3) << 5);
}

EXTERN_C int func_8004AEA8(S_80034F40 *p)
{
    return (p->unk6 >> 5) & 3;
}

EXTERN_C void func_8004AEBC(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x68;
        while (p != q) {
            q -= 0x68;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004AF3C(S_8004AF3C *p)
{
    return &p->unk68;
}

EXTERN_C int func_8004AF44()
{
    return 0;
}

EXTERN_C void func_8004AF4C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004AF54);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004B124);

C_8004B2C4::C_8004B2C4()
{
    vt = D_80012E60;
}

EXTERN_C void func_8004B348(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012DE8;
    func_800198AC(p, a);
}

EXTERN_C void func_8004B370(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x68;
        while (p != q) {
            q -= 0x68;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004B3F0(S_8004B3F0 *p)
{
    return &p->unk68;
}

EXTERN_C int func_8004B3F8()
{
    return 0;
}

EXTERN_C void func_8004B400()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004B408);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004B690);

C_8004B83C::C_8004B83C()
{
    vt = D_80012ED8;
    AT(this, short, 0x26) = 4;
}

EXTERN_C void func_8004B8C8(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012DE8;
    func_800198AC(p, a);
}

EXTERN_C int func_8004B8F0()
{
    return 0x30;
}

C_8004B8F8::C_8004B8F8()
{
    S_A2B_PolyG3 *r;
    S_A2B_PolyG3 *q;
    int i;
    r = m.p; q = r; i = 2;
    while (i--) { q->len = 6; q->code = 0x30; q++; }
    r[0].len = 6;
    r[0].code = 0x30;
    r[1].code = 0x30;
    r[1].len = 6;
    vt = D_80012F50;
}

EXTERN_C void func_8004B970(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012F50;
    func_800198AC(p, a);
}

EXTERN_C void func_8004B998(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x5C;
        while (p != q) {
            q -= 0x5C;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004BA18(S_8004BA18 *p)
{
    return &p->unk5C;
}

EXTERN_C int func_8004BA20()
{
    return 0;
}

EXTERN_C void func_8004BA28()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004BA30);

EXTERN_C char *func_8004BBCC(void *p, char *src)
{
    func_800499D0(p, src);
    func_800497D4((int *)(p ? (char *)p + 0x50 : 0), (int *)(src + 0x10));
    return src + 0x1C;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004BC14);

C_8004BD84::C_8004BD84()
{
    vt = D_80012FC0;
}

EXTERN_C void func_8004BE10(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012F50;
    func_800198AC(p, a);
}

EXTERN_C void func_8004BE38(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x58;
        while (p != q) {
            q -= 0x58;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004BEB8(S_8004BEB8 *p)
{
    return &p->unk58;
}

EXTERN_C int func_8004BEC0()
{
    return 0;
}

EXTERN_C void func_8004BEC8()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004BED0);

EXTERN_C char *func_8004C08C(S_A2_At54 *p, char *src)
{
    func_800499D0(p, src);
    p->c = *(S_Rgb *)(src + 0x10);
    return src + 0x14;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004C0D4);

C_8004C254::C_8004C254()
{
    rgb = 0x30808080;
    vt = D_80013038;
}

EXTERN_C void func_8004C2E4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80012F50;
    func_800198AC(p, a);
}

EXTERN_C int func_8004C30C()
{
    return 0x34;
}

extern "C++" char *func_8004C314_(void *p, char *src) asm("func_8004C314");
char *func_8004C314_(void *p, char *src)
{
    func_800499D0(p, src);
    func_8004AE24(p ? (char *)p + 0x18 : 0, src + 0x10);
    return src + 0x18;
}

C_8004C35C::C_8004C35C()
{
    vt = D_800130B0;
}

EXTERN_C void func_8004C3D4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800130B0;
    func_800198AC(p, a);
}

EXTERN_C void func_8004C3FC(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x78;
        while (p != q) {
            q -= 0x78;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004C474(S_8004C474 *p)
{
    return &p->unk78;
}

EXTERN_C int func_8004C47C()
{
    return 0;
}

EXTERN_C void func_8004C484()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004C48C);

EXTERN_C char *func_8004C660(void *p, char *q)
{
    func_8004C314(p, q);
    return q + 0x18;
}

EXTERN_C void func_8004C688(void *p, int a)
{
    func_80034B84((S_A2_Flags *)(p ? (char *)p + 0x74 : 0), a != -1);
    if (a != -1)
        func_8004AE8C((S_80034F24 *)(p ? (char *)p + 0x18 : 0), a);
}

EXTERN_C int func_8004C6EC(void *p)
{
    char *b = p ? (char *)p + 0x74 : 0;
    if ((AT(b, unsigned char, 3) >> 1) & 1) {
        char *q = p ? (char *)p + 0x18 : 0;
        return (AT(q, unsigned short, 6) >> 5) & 3;
    }
    return -1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004C738);

C_8004C8D0::C_8004C8D0()
{
    vt = D_800130B0;
    AT(this, int, 0x74) = 0x34FFFFFF;
    vt = D_80013120;
}

EXTERN_C void func_8004C960(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800130B0;
    func_800198AC(p, a);
}

EXTERN_C void func_8004C988(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x78;
        while (p != q) {
            q -= 0x78;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004CA00(S_8004CA00 *p)
{
    return &p->unk78;
}

EXTERN_C int func_8004CA08()
{
    return 0;
}

EXTERN_C void func_8004CA10()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004CA18);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004CC7C);

C_8004CE14::C_8004CE14()
{
    vt = D_800130B0;
    AT(this, int, 0x74) = 0x34FFFFFF;
    vt = D_80013198;
}

EXTERN_C void func_8004CEA4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800130B0;
    func_800198AC(p, a);
}

EXTERN_C unsigned int *func_8004CECC(unsigned int *p)
{
    int i;
    unsigned int c = 0x38808080;
    for (i = 3; i >= 0; i--)
        p[i] = c;
    return p;
}

EXTERN_C void func_8004CEF8(int *a, int *b)
{
    int i;
    for (i = 0; i < 4; i++)
        *a++ = *b++;
}

C_8004CF20::C_8004CF20()
{
    vt = D_80013210;
    func_8001AA28(unkC, 4);
}

EXTERN_C void func_8004CF7C()
{
}

EXTERN_C int func_8004CF84()
{
    return 0;
}

EXTERN_C int func_8004CF8C(void *p, short a)
{
    if (AT(p, short, 6) > 0) {
    int s = func_80026014(a);
    int c = func_800260A4(a);
    return ratan2((AT(p, short, 4) * s - AT(p, short, 8) * c) / AT(p, short, 6), 0x1000);
    }
    return 0x400;
}

EXTERN_C int func_8004D040(void *p, short a)
{
    if (AT(p, short, 6) > 0) {
    int s = func_800260A4(a);
    int c = func_80026014(a);
    return ratan2((AT(p, short, 4) * s - AT(p, short, 8) * c) / AT(p, short, 6), 0x1000);
    }
    return 0x400;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004D0F4);

EXTERN_C int func_8004D1A0(void *p, int a)
{
    return (a + 1) & 3;
}

EXTERN_C void func_8004D1AC(void *p, int a)
{
    func_800198AC(p, a);
}

EXTERN_C void func_8004D1CC(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x50;
        while (p != q) {
            q -= 0x50;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004D244(S_8004D244 *p)
{
    return &p->unk50;
}

EXTERN_C int func_8004D24C()
{
    return 0x28;
}

EXTERN_C int func_8004D254()
{
    return 0;
}

EXTERN_C void func_8004D25C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004D264);

EXTERN_C char *func_8004D464(S_A2_At1C *p, char *src)
{
    func_8004D0F4(p, src);
    p->c = *(S_Rgb *)(src + 0x14);
    return src + 0x18;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004D4AC);

C_8004D678::C_8004D678()
{
    vt = D_80013280;
}

EXTERN_C void func_8004D6E0(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013280;
    func_800198AC(p, a);
}

EXTERN_C void func_8004D708(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x50;
        while (p != q) {
            q -= 0x50;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004D780(S_8004D780 *p)
{
    return &p->unk50;
}

EXTERN_C int func_8004D788()
{
    return 0;
}

EXTERN_C void func_8004D790()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004D798);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004D9AC);

C_8004DB8C::C_8004DB8C()
{
    vt = D_800132F8;
}

EXTERN_C void func_8004DBF4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013280;
    func_800198AC(p, a);
}

EXTERN_C void func_8004DC1C(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x80;
        while (p != q) {
            q -= 0x80;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004DC8C(S_8004DC8C *p)
{
    return &p->unk80;
}

EXTERN_C int func_8004DC94()
{
    return 0x2C;
}

EXTERN_C int func_8004DC9C()
{
    return 0;
}

EXTERN_C void func_8004DCA4()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004DCAC);

EXTERN_C char *func_8004DEDC(void *p, char *src)
{
    func_8004D0F4(p, src);
    func_80034854(p ? (char *)p + 0x1C : 0, src + 0x14);
    return src + 0x20;
}

EXTERN_C void func_8004DF24(void *p, int a)
{
    func_8003488C(p ? (char *)p + 0x1C : 0, a);
}

EXTERN_C void func_8004DF54(void *p)
{
    func_800348E4(p ? (char *)p + 0x1C : 0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004DF84);

C_8004E17C::C_8004E17C()
{
    vt = D_80013370;
}

EXTERN_C void func_8004E200(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013370;
    func_800198AC(p, a);
}

EXTERN_C void func_8004E228(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x80;
        while (p != q) {
            q -= 0x80;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004E298(S_8004E298 *p)
{
    return &p->unk80;
}

EXTERN_C int func_8004E2A0()
{
    return 0;
}

EXTERN_C void func_8004E2A8()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004E2B0);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004E4FC);

C_8004E700::C_8004E700()
{
    vt = D_800133E8;
}

EXTERN_C void func_8004E784(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013370;
    func_800198AC(p, a);
}

EXTERN_C void func_8004E7AC(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x80;
        while (p != q) {
            q -= 0x80;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004E81C(S_8004E81C *p)
{
    return &p->unk80;
}

EXTERN_C int func_8004E824()
{
    return 0;
}

EXTERN_C void func_8004E82C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004E834);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004EB28);

C_8004ED40::C_8004ED40()
{
    vt = D_80013460;
    AT(this, short, 0x2A) = 4;
}

EXTERN_C void func_8004EDCC(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013370;
    func_800198AC(p, a);
}

EXTERN_C int func_8004EDF4()
{
    return 0x38;
}

C_8004EDFC::C_8004EDFC()
{
        S_A2B_PolyG4 *r; S_A2B_PolyG4 *q; int i;
        r = m.p; q = r; i = 2;
        while (i--) { q->len = 8; q->code = 0x38; q++; }
        r[0].len = 8; r[0].code = 0x38; r[1].code = 0x38; r[1].len = 8;
        vt = D_800134D8;
}

EXTERN_C void func_8004EE74(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800134D8;
    func_800198AC(p, a);
}

EXTERN_C void func_8004EE9C(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x74;
        while (p != q) {
            q -= 0x74;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004EF1C(S_8004EF1C *p)
{
    return &p->unk74;
}

EXTERN_C int func_8004EF24()
{
    return 0;
}

EXTERN_C void func_8004EF2C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004EF34);

EXTERN_C char *func_8004F144(void *p, char *src)
{
    func_8004D0F4(p, src);
    func_8004CEF8((int *)(p ? (char *)p + 0x64 : 0), (int *)(src + 0x14));
    return src + 0x24;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004F18C);

C_8004F368::C_8004F368()
{
    vt = D_80013548;
}

EXTERN_C void func_8004F3F4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800134D8;
    func_800198AC(p, a);
}

EXTERN_C void func_8004F41C(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x68;
        while (p != q) {
            q -= 0x68;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004F49C(S_8004F49C *p)
{
    return &p->unk68;
}

EXTERN_C int func_8004F4A4()
{
    return 0;
}

EXTERN_C void func_8004F4AC()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004F4B4);

EXTERN_C char *func_8004F6F0(S_A2_At64 *p, char *src)
{
    func_8004D0F4(p, src);
    p->c = *(S_Rgb *)(src + 0x14);
    return src + 0x18;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004F738);

C_8004F924::C_8004F924()
{
    rgb = 0x38808080;
    vt = D_800135C0;
}

EXTERN_C void func_8004F9B4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800134D8;
    func_800198AC(p, a);
}

EXTERN_C int func_8004F9DC()
{
    return 0x3C;
}

extern "C++" char *func_8004F9E4_(void *p, char *src) asm("func_8004F9E4");
char *func_8004F9E4_(void *p, char *src)
{
    func_8004D0F4(p, src);
    func_80034EBC(p ? (char *)p + 0x1C : 0, src + 0x14);
    return src + 0x1C;
}

C_8004FA2C::C_8004FA2C()
{
    vt = D_80013638;
}

EXTERN_C void func_8004FAA4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013638;
    func_800198AC(p, a);
}

EXTERN_C void func_8004FACC(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x98;
        while (p != q) {
            q -= 0x98;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_8004FB4C(S_8004FB4C *p)
{
    return &p->unk98;
}

EXTERN_C int func_8004FB54()
{
    return 0;
}

EXTERN_C void func_8004FB5C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004FB64);

EXTERN_C char *func_8004FDC8(void *p, char *q)
{
    func_8004F9E4(p, q);
    return q + 0x1C;
}

EXTERN_C void func_8004FDF0(void *p, int a)
{
    func_80034B84((S_A2_Flags *)(p ? (char *)p + 0x94 : 0), a != -1);
    if (a != -1)
        func_80034F24((S_80034F24 *)(p ? (char *)p + 0x1C : 0), a);
}

EXTERN_C int func_8004FE54(void *p)
{
    char *b = p ? (char *)p + 0x94 : 0;
    if ((AT(b, unsigned char, 3) >> 1) & 1) {
        char *q = p ? (char *)p + 0x1C : 0;
        return (AT(q, unsigned short, 6) >> 5) & 3;
    }
    return -1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8004FEA0);

C_800500B4::C_800500B4()
{
    vt = D_80013638;
    AT(this, int, 0x94) = 0x3CFFFFFF;
    vt = D_800136A8;
}

EXTERN_C void func_80050144(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013638;
    func_800198AC(p, a);
}

EXTERN_C void func_8005016C(char *p)
{
    if (p) {
        char *q = p + AT(p, int, -8) * 0x98;
        while (p != q) {
            q -= 0x98;
            ((A2VObj0 *)q)->v00(2);
        }
        func_800A0D0C(p - 8);
    }
}

EXTERN_C void *func_800501EC(S_800501EC *p)
{
    return &p->unk98;
}

EXTERN_C int func_800501F4()
{
    return 0;
}

EXTERN_C void func_800501FC()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80050204);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_800504E0);

C_800506F4::C_800506F4()
{
    vt = D_80013638;
    AT(this, int, 0x94) = 0x3CFFFFFF;
    vt = D_80013720;
}

EXTERN_C void func_80050784(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80013638;
    func_800198AC(p, a);
}

EXTERN_C void *func_800507AC(void *p, int a)
{
    AT(p, void **, 0) = D_80010178;
    AT(p, int, 4) = 0;
    AT(p, void **, 0) = D_80013798;
    AT(p, int, 8) = a;
    return p;
}

EXTERN_C void func_800507D4(void *p, void *a)
{
    if (!AT(p, void *, 0)) {
        AT(p, void *, 0) = a;
    } else {
        void *q = AT(p, void *, 0);
        if (AT(q, void *, 4) && a)
            func_8001A864(a, AT(q, void *, 4));
        AT(q, void *, 4) = a;
    }
}

EXTERN_C S_80050838 *func_80050838(S_80050838 *p)
{
    p->unk0 = 0;
    return p;
}

EXTERN_C void func_80050844(void **p, int a)
{
    if (*p)
        func_8001A744(*p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80050874);

EXTERN_C void func_80050E38(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_80050E58(void *p, unsigned short a, unsigned short b)
{
    int r;
    if (!a || !b)
        return 0;
    r = func_80050EA4(p, a, b);
    if (!r)
        return 0;
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80050EA4);

EXTERN_C void *func_800514C0(void *p)
{
    return p;
}

C_800514C8::C_800514C8()
{
    vt = D_80010178;
    unk4 = 0;
    vt = D_80013808;
    func_80051A2C(D_800B4D40, this);
}

EXTERN_C void func_80051514(void *p, int a)
{
    void *g = D_800B4D40;
    AT(p, void **, 0) = D_80013808;
    func_80051AA4(g, p);
    func_8001A610(p, a);
}

C_80051564::C_80051564()
{
    vt = D_800137F0;
    func_80051A7C((S_80051A7C *)D_800B4D40, (int)this);
}

EXTERN_C void func_800515A4(void *p, int a)
{
    void *g = D_800B4D40;
    AT(p, void **, 0) = D_800137F0;
    func_80051B70(g, p);
    func_80051514(p, a);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80012BC8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80012BF8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80012C28);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80012C58);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80012C88);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80012CF8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80012D70);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80012DE8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80012E60);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80012ED8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80012F50);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80012FC0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013038);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800130B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013120);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013198);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013210);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013280);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800132F8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013370);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800133E8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013460);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800134D8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013548);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800135C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013638);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800136A8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013720);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013798);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_800515F4);

EXTERN_C void func_800518A8(void *p, int a, int b, int c)
{
    void *o;
    AT(p, int, 0x110) = a;
    AT(p, int, 0x11C) = b;
    AT(p, int, 0x120) = c;
    o = func_8001CA10(0x14);
    AT(o, void **, 0) = D_80010178;
    AT(o, int, 4) = 0;
    AT(o, void **, 0) = D_80010300;
    AT(o, short, 8) = 2;
    AT(o, short, 0xA) = 0x10;
    AT(o, int, 0x10) = 0;
    AT(o, int, 0xC) = 0;
    AT(o, void **, 0) = D_800102D0;
    func_8001EFE4(p, o);
    AT(p, short, 0x118) = 99;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80051930);

EXTERN_C void func_80051A2C(void *p, void *a)
{
    if (!AT(p, void *, 0x100))
        AT(p, void *, 0x100) = a;
    else
        func_8001A678(AT(p, void *, 0x100), (int)a);
    AT(p, short, 0x124) = 0;
    AT(p, unsigned short, 0xFA)++;
}

EXTERN_C void func_80051A7C(S_80051A7C *p, int a)
{
    if (p->unk104 == 0)
        p->unk104 = a;
    p->unk124 = 0;
    p->unkFC++;
}

EXTERN_C void func_80051AA4(void *p, void *o)
{
    void *r = ((void *(*)(void *, void *))func_8001A744)(AT(p, void *, 0x100), o);
    if (AT(p, void *, 0x100) == o)
        AT(p, void *, 0x100) = r;
    if (!--AT(p, short, 0xFA)) {
        AT(p, void *, 0x100) = 0;
        if (AT(p, short, 0x124)) {
            void *m = func_8001CA10(0x14);
            AT(m, void **, 0) = D_80010178;
            AT(m, int, 4) = 0;
            AT(m, void **, 0) = D_80010300;
            AT(m, short, 8) = 2;
            AT(m, short, 0xA) = 0x10;
            AT(m, int, 0x10) = 3;
            AT(m, int, 0xC) = 0;
            AT(m, void **, 0) = D_800102D0;
            func_8001EFE4(p, m);
        }
    }
}

EXTERN_C void func_80051B70(void *p, void *o)
{
    void *r = ((void *(*)(void *, void *))func_8001A744)(AT(p, void *, 0x104), o);
    if (AT(p, void *, 0x104) == o)
        AT(p, void *, 0x104) = r;
    if (!--AT(p, short, 0xFC)) {
        AT(p, void *, 0x104) = 0;
        if (AT(p, short, 0x124)) {
            void *m = func_8001CA10(0x14);
            AT(m, void **, 0) = D_80010178;
            AT(m, int, 4) = 0;
            AT(m, void **, 0) = D_80010300;
            AT(m, short, 8) = 2;
            AT(m, short, 0xA) = 0x10;
            AT(m, int, 0x10) = 3;
            AT(m, int, 0xC) = 0;
            AT(m, void **, 0) = D_800102D0;
            func_8001EFE4(p, m);
        }
    }
}

C_80051C3C::C_80051C3C(int a) : C_8001E40C(a, 2, 0x1000, 0)
{
    AT(this, void **, 0x8C) = D_800137C0;
    AT(this, void **, 0) = D_800137D8;
    AT(this, short, 0xF8) = 0;
    AT(this, short, 0xFA) = 0;
    AT(this, int, 0x100) = 0;
    AT(this, short, 0xFC) = 0;
    AT(this, int, 0x104) = 0;
    AT(this, int, 0x110) = 0;
    AT(this, short, 0x118) = 0;
    AT(this, int, 0x108) = 0;
    AT(this, short, 0x10C) = 0;
    D_800B4D40 = this;
}

EXTERN_C void func_80051CB0(void *p, int a)
{
    A2VObj0 *o;
    AT(p, int, 0x114) = a;
    o = AT(p, A2VObj0 *, 0x100);
    if (!o) {
        void *m = func_8001CA10(0x14);
        AT(m, void **, 0) = D_80010178;
        AT(m, int, 4) = 0;
        AT(m, void **, 0) = D_80010300;
        AT(m, short, 8) = 2;
        AT(m, short, 0xA) = 0x10;
        AT(m, int, 0x10) = 3;
        AT(m, int, 0xC) = 0;
        AT(m, void **, 0) = D_800102D0;
        func_8001EFE4(p, m);
        AT(p, short, 0x124) = 0;
    } else {
        AT(p, short, 0x124) = 1;
        while (o) {
            A2VObj0 *n;
            o->v01();
            n = AT(o, A2VObj0 *, 4);
            o = n;
        }
    }
}

EXTERN_C void func_80051D80(void *p, int a)
{
    A2VObj0 *o;
    AT(p, int, 0x114) = a;
    o = AT(p, A2VObj0 *, 0x104);
    if (!o) {
        void *m = func_8001CA10(0x14);
        AT(m, void **, 0) = D_80010178;
        AT(m, int, 4) = 0;
        AT(m, void **, 0) = D_80010300;
        AT(m, short, 8) = 2;
        AT(m, short, 0xA) = 0x10;
        AT(m, int, 0x10) = 3;
        AT(m, int, 0xC) = 0;
        AT(m, void **, 0) = D_800102D0;
        func_8001EFE4(p, m);
        AT(p, short, 0x124) = 0;
    } else {
        AT(p, short, 0x124) = 1;
        while (o) {
            A2VObj0 *n;
            o->v01();
            n = AT(o, A2VObj0 *, 4);
            o = n;
        }
    }
}

EXTERN_C int func_80051E50(void *p)
{
    if (AT(p, short, 0xFC) && !AT(p, short, 0x10C)) {
        AT(p, short, 0x10C) = AT(p, short, 0xFC);
        AT(p, short, 0xFC) = 0;
        AT(p, int, 0x108) = AT(p, int, 0x104);
        AT(p, int, 0x104) = 0;
        return 0;
    }
    return 1;
}

EXTERN_C int func_80051E90(void *p)
{
    if (!AT(p, short, 0xFC) && AT(p, short, 0x10C)) {
        AT(p, short, 0xFC) = AT(p, short, 0x10C);
        AT(p, short, 0x10C) = 0;
        AT(p, int, 0x104) = AT(p, int, 0x108);
        AT(p, int, 0x108) = 0;
    }
    return 1;
}

EXTERN_C int func_80051ECC(S_80051ECC *p)
{
    return p->unk11A;
}

EXTERN_C void func_80051ED8(void *p, int a)
{
    AT(p, void **, 0x8C) = D_800137C0;
    AT(p, void **, 0) = D_800137D8;
    func_8001E508(p, a);
}

EXTERN_C void func_80051F0C(void *p, void *a)
{
    if (D_800A4534.unkC >= 0x12D) {
        func_8006BDE0(D_800B4ED8);
        if (D_800B4D4C) {
            func_80052640(D_800B4D4C, p);
            func_8008EF40(14);
        } else
            D_800B4D4C = new C_80052100(1, p, (int)a);
    }
    if (p)
        func_800A0D0C(p);
}

EXTERN_C void func_80051FB8(void *p)
{
    if (D_800A4534.unkC >= 0x12D) {
        func_8006BDE0(D_800B4ED8);
        if (D_800B4D4C) {
            func_800525EC(D_800B4D4C, (int)p);
            func_8008EF40(14);
        } else
            D_800B4D4C = new C_8005226C(1, p);
    }
}

EXTERN_C void func_80052044()
{
    void *s;
    if (D_800B4D4C) {
        ((A2VObj<8> *)((char *)D_800B4D4C + 0x38))->v00(3);
        D_800B4D4C = 0;
        s = func_80056E0C(operator new(0xB4), 1);
        func_80056FBC(s, 8, 1);
        func_80056FE0(s);
    }
}

EXTERN_C void func_800520BC(void *p)
{
    void *q = D_800B4D4C;
    if (q && (q = AT(q, void *, 0x58)) && q != p)
        func_80054CA0(q);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80052100);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8005226C);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_800523DC);

EXTERN_C void func_800525EC(void *p, int a)
{
    if (!AT(p, void *, 0x58)) {
        func_80052FB8(p);
        func_80052B60(p);
    }
    func_80052E40(p, a);
}

EXTERN_C void func_80052640(void *p, void *a)
{
    A2VObj<0x18> *o = AT(p, A2VObj<0x18> *, 0x58);
    if (o == 0) {
        func_80052FB8(p);
    } else {
        o->v02();
        o = AT(p, A2VObj<0x18> *, 0x58);
        if (o)
            o->v00(3);
        o = AT(p, A2VObj<0x18> *, 0x5C);
        AT(p, int, 0x58) = 0;
        if (o)
            o->v00(3);
        o = AT(p, A2VObj<0x18> *, 0x64);
        AT(p, int, 0x5C) = 0;
        if (o)
            o->v00(3);
        o = AT(p, A2VObj<0x18> *, 0x60);
        AT(p, int, 0x64) = 0;
        if (o)
            o->v00(3);
        AT(p, int, 0x60) = 0;
    }
    func_800530B8(p, a);
    func_8005388C(p ? (char *)p + 0x38 : 0, 0x30);
}

EXTERN_C void func_80052778(void *p)
{
    char *b = 0;
    int r;
    if (p) b = (char *)p + 0x38;
    if (f53874(b) == 0x10) {
        func_8002B174(D_800A4578_a[0], p, -1);
        ((A2VObj<0x2C> *)p)->v27();
        ((A2VObj<0x2C> *)p)->v03();
        b = 0;
    } else {
        b = 0;
        if (p) b = (char *)p + 0x38;
        if (f53874(b) < 0x10) {
            b = 0;
            if (p) b = (char *)p + 0x38;
            r = f53874(b);
            ((A2VObj<0x2C> *)p)->v28(((0x10 - r) << 3) & 0xF8);
        }
        b = 0;
    }
    if (p) b = (char *)p + 0x38;
    f53830(b);
}

EXTERN_C void func_8005287C(void *p, unsigned char a)
{
    char t[8];
    unsigned int i, j;
    if (!AT(p, void *, 8))
        return;
    func_8002972C(t, a, a, a, 1);
    for (i = 0; i < 3; i = j) {
        char *h = AT(p, char *, 0x30);
        char *h2 = h ? h + 8 : 0;
        A2VObj0 *o;
        j = i + 1;
        o = (A2VObj0 *)func_80019F64(h2 ? AT(h2, List *, 0) : 0, j);
        func_80028D10(o, t);
        o->v06();
    }
    func_800198AC(t, 2);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_8005294C);

EXTERN_C void func_80052B60(void *p)
{
    C_80054AF0 *o = new C_80054AF0(2);
    C_80053928 *q;
    C_80054584b *r;
    C_80053928 *s;
    AT(p, void *, 0x58) = o;
    func_80054EB4(o, 0x130, 0x13);
    ((A2B_V53 *)AT(p, void *, 0x58))->s3(S_A2B_Pt(8, 0x70));
    {
        S_A2_Sv sv;
        sv.x = 0; sv.y = 0; sv.z = 0; sv.pad = 0;
        func_80054F30(AT(p, void *, 0x58), 0, &sv, 0);
    }
    q = new C_80053928;
    AT(p, void *, 0x5C) = q;
    func_80053CD8(q);
    r = new C_80054584b(0);
    AT(p, void *, 0x64) = r;
    func_80053CD8(r);
    s = new C_80053928;
    AT(p, void *, 0x60) = s;
    func_80053CD8(s);
    func_80054E18(AT(p, void *, 0x58), AT(p, void *, 0x5C));
    func_80054E18(AT(p, void *, 0x58), AT(p, void *, 0x64));
    func_80054E18(AT(p, void *, 0x58), AT(p, void *, 0x60));
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80052C8C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800137C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800137D8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800137F0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013808);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80052E40);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80052FB8);

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_800530B8);

EXTERN_C void *func_80053250(void *p, int a, int b, short c)
{
    AT(p, void **, 0) = D_80010178;
    AT(p, int, 4) = 0;
    AT(p, void **, 0) = D_800111BC;
    AT(p, short, 8) = 0;
    AT(p, short, 0xA) = c;
    AT(p, void **, 0) = D_80013AA8;
    func_80098DF0((char *)p + 0xC);
    func_80098DF0((char *)p + 0x1C);
    func_80053658(p, a);
    func_800536F0(p, b);
    func_800534F8(p);
    return p;
}

EXTERN_C void *func_800532EC(void *p, void *q)
{
    S_A2_V4 *s, *d;
    int i;
    func_80027FEC(p, q);
    d = (S_A2_V4 *)((char *)q + 0xC);
    i = 1;
    s = (S_A2_V4 *)((char *)p + 0xC);
    do { *d = *s; d++; s++; } while (--i != -1);
    return q;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80053360);

EXTERN_C int func_8005340C(void *self)
{
    switch (AT(self, short, 8)) {
    case 1: {
        int i = D_800B4CF0;
        ((S_A2B_Q16o *)((char *)self + (i << 4)))->q = ((S_A2B_Q16o *)((char *)self + ((i ^ 1) << 4)))->q;
    }
    case 2:
        AT(self, short, 8) = AT(self, short, 8) - 1;
    }
    D_800B4CFC->add((S_A2B_PTag *)((D_800B4CF0 << 4) + (int)self + 0xC), AT(self, unsigned short, 0xA));
    return 1;
}

EXTERN_C void func_800534F8(void *p)
{
    if (AT(p, short, 8)) {
        int i = D_800B4CF0;
        S_A2_V4 *d = (S_A2_V4 *)((char *)p + (i ^ 1) * 16 + 0xC);
        S_A2_V4 *s = (S_A2_V4 *)((char *)p + i * 16 + 0xC);
        *d = *s;
    }
    func_80028184();
}

EXTERN_C void func_80053568(S_A2B_Buf *p, int a, int b)
{
    S_A2B_Ent *d, *s;
    if (p->mode == 1) {
        d = E_(p, D_800B4CF0);
        s = E_(p, D_800B4CF0 ^ 1);
        *d = *s;
    }
    { char *t = (char *)p + D_800B4CF0 * 16; AT(t, short, 0x14) = a; AT(t, short, 0x16) = b; }
    p->mode = 2;
}

EXTERN_C void func_800535E0(S_A2B_Buf *p, int a, int b)
{
    S_A2B_Ent *d, *s;
    if (p->mode == 1) {
        d = E_(p, D_800B4CF0);
        s = E_(p, D_800B4CF0 ^ 1);
        *d = *s;
    }
    { char *t = (char *)p + D_800B4CF0 * 16; AT(t, short, 0x18) = a; AT(t, short, 0x1A) = b; }
    p->mode = 2;
}

EXTERN_C void func_80053658(void *pv, int qq)
{
    S_A2B_Buf *p = (S_A2B_Buf *)pv;
    unsigned short *q = (unsigned short *)qq;
    S_A2B_Ent *d, *s;
    if (p->mode == 1) {
        d = E_(p, D_800B4CF0);
        s = E_(p, D_800B4CF0 ^ 1);
        *d = *s;
    }
    char *t = (char *)p + D_800B4CF0 * 16;
    AT(t, short, 0x14) = q[0];
    AT(t, short, 0x16) = q[1];
    AT(t, short, 0x18) = q[2];
    AT(t, short, 0x1A) = q[3];
    p->mode = 2;
}

EXTERN_C void func_800536F0(void *pv, int qq)
{
    S_A2B_Buf *p = (S_A2B_Buf *)pv;
    unsigned char *q = (unsigned char *)qq;
    S_A2B_Ent *d, *s;
    char *t;
    if (p->mode == 1) {
        d = E_(p, D_800B4CF0);
        s = E_(p, D_800B4CF0 ^ 1);
        *d = *s;
    }
    t = (char *)p + D_800B4CF0 * 16;
    AT(t, char, 0x10) = q[5];
    t = (char *)p + D_800B4CF0 * 16;
    AT(t, char, 0x11) = q[6];
    t = (char *)p + D_800B4CF0 * 16;
    AT(t, char, 0x12) = q[7];
    p->mode = 2;
}

EXTERN_C int func_80053794(S_80053794 *p)
{
    return p->unk4;
}

EXTERN_C void func_800537A0(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C S_800537C0 *func_800537C0(S_800537C0 *p)
{
    p->vtbl = D_80013B00;
    p->unk0 = 0;
    p->unk4 = 0;
    return p;
}

EXTERN_C void func_800537DC(void *p, int flags)
{
    AT(p, void **, 8) = D_80013B00;
    func_80055624(p, 0);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C int func_80053830(S_80053830 *p)
{
    return --p->unk4 > 0;
}

EXTERN_C void func_80053848(S_80053830 *p)
{
    if (p->unk4 >= 2)
        p->unk4 = 1;
}

EXTERN_C int func_80053868(S_80053794 *p)
{
    return p->unk0;
}

EXTERN_C int func_80053874(S_80053794 *p)
{
    return p->unk4;
}

EXTERN_C int func_80053880(S_80053794 *p)
{
    return p->unk4 < 1;
}

EXTERN_C void func_8005388C(void *p, int a)
{
    AT(p, int, 0) = a;
    AT(p, int, 4) = a;
    func_80055624(p, 1);
}

EXTERN_C void func_800538B4(int v)
{
    D_800B4D5C = v;
}

EXTERN_C void func_800538C0(int v)
{
    D_800B4D60 = v;
}

EXTERN_C void *func_800538CC(void *p, void *q, int a)
{
    AT(p, void **, 0x18) = D_80013B20;
    AT(p, int, 4) = 1;
    AT(p, short, 0xC) = 0xE0;
    AT(p, int, 0) = 0;
    AT(p, int, 8) = 0;
    AT(p, short, 0xE) = 0x1E;
    AT(p, int, 0x14) = 0;
    AT(p, int, 0x10) = 0;
    func_80053BCC(p, q, a);
    return p;
}

EXTERN_C void *func_80053928(void *p)
{
    AT(p, void **, 0x18) = D_80013B20;
    AT(p, int, 4) = 1;
    AT(p, short, 0xC) = 0xE0;
    AT(p, int, 0) = 0;
    AT(p, int, 8) = 0;
    AT(p, short, 0xE) = 0x1E;
    AT(p, int, 0x14) = 0;
    AT(p, int, 0x10) = 0;
    return p;
}

EXTERN_C void func_80053964(void *p, int flags)
{
    AT(p, void **, 0x18) = D_80013B20;
    if (AT(p, void *, 0x10))
        func_800A0D0C(AT(p, void *, 0x10));
    AT(p, void *, 0x10) = 0;
    if (flags & 1)
        operator delete(p);
}

EXTERN_C void func_800539C0()
{
}

EXTERN_C void func_800539C8()
{
}

extern "C++" S_A2B_Str *f539D0(S_A2B_Str *s, S_A2B_Ch2 *c) asm("func_800539D0");
S_A2B_Str *f539D0(S_A2B_Str *s, S_A2B_Ch2 *c)
{
    S_A2B_Ch2 *d, *dd; unsigned i;
    int n = s->len;
    d = new S_A2B_Ch2[n + 2];
    i = 0;
    dd = d;
    if (s->len) {
        dd = d;
        do { *dd = s->p[i]; i++; dd++; } while (i < s->len);
    }
    d[s->len] = *c;
    s->len++;
    if (s->p)
        func_800A0D0C(s->p);
    s->p = d;
    return s;
}

S_A2B_Ch2 f53AE4(S_A2B_Str *s, unsigned i)
{
    if (s->len == 0) {
        S_A2B_Ch2 t;
        t.c[0] = 0x30;
        t.c[1] = 0x30;
        return t;
    }
    if (i < s->len)
        return s->p[i];
    return *(&s->p[s->len] - 1);
}

EXTERN_C void func_80053B68(void *p)
{
    int n = AT(p, int, 0x14) - 1;
    void *s = AT(p, void *, 0x10);
    AT(p, void *, 0x10) = 0;
    AT(p, int, 0x14) = n;
    if (n)
        func_800544AC(p, s);
    if (s)
        func_800A0D0C(s);
}

EXTERN_C int func_80053BB4(S_80053BB4 *p)
{
    return p->unk14;
}

EXTERN_C int func_80053BC0(S_80053BB4 *p)
{
    return p->unk10;
}

EXTERN_C void func_80053BCC(void *p, void *q, int a)
{
    if (AT(p, void *, 0x10))
        func_800A0D0C(AT(p, void *, 0x10));
    AT(p, void *, 0x10) = 0;
    if (a)
        AT(p, int, 0x14) = a;
    else {
        int i = 0;
        while (((signed char *)q)[i])
            i++;
        AT(p, unsigned int, 0x14) = (unsigned int)(i + 1) >> 1;
    }
    func_800544AC(p, q);
}

EXTERN_C void func_80053C6C(void *p, void *q)
{
    int r;
    if (AT(p, void *, 0x10))
        func_800A0D0C(AT(p, void *, 0x10));
    r = func_80053BB4((S_80053BB4 *)q);
    AT(p, int, 0x14) = r;
    AT(p, void *, 0x10) = 0;
    if (r)
        func_800544AC(p, AT(q, void *, 0x10));
    AT(p, int, 0) = AT(q, int, 0);
}

EXTERN_C void func_80053CD8(void *p)
{
    func_80053BCC(p, &D_800B4D64, 1);
}

extern "C++" int f53D00(S_A2B_Str *s, S_A2B_Str *t) asm("func_80053D00");
int f53D00(S_A2B_Str *s, S_A2B_Str *t)
{
    int r = (s->len == f53BB4(t));
    unsigned i;
    for (i = 0; r != 0 && i < s->len; i++) {
        r = s->p[i].c[0] == f53AE4(t, i).c[0] && s->p[i].c[1] == f53AE4(t, i).c[1];
    }
    return r;
}

EXTERN_C void func_80053DDC(S_A2B_Str *s, S_A2B_Str *o)
{
    unsigned i, j, m;
    int n = s->len + f53BB4(o);
    S_A2B_Ch2 *d = new S_A2B_Ch2[n + 1];
    
    for (i = 0; i < s->len; i++)
        d[i] = s->p[i];
    m = f53BB4(o);
    for (j = 0; j < m; j++)
        d[j + s->len] = o->p[j];
    s->len += m;
    if (s->p)
        func_800A0D0C(s->p);
    s->p = d;
}

EXTERN_C void func_80053F28(S_80025A64 *p, S_Rgb c)
{
    p->unkC = c;
}

EXTERN_C void func_80053F48(A2V_53F48 *p, S_A2_Pt v)
{
    p->s3(v);
    AT(p, int, 8) = 1;
}

EXTERN_C void func_80053FB0(void *p, int a, unsigned b)
{
    ((A2B_V53 *)p)->s3(S_A2B_Pt((b - func_8005F87C(p)) >> 1, a));
    AT(p, int, 8) = 1;
}

EXTERN_C void func_8005402C(S_8005402C *p, int a, int b)
{
    p->unkC += a;
    p->unkE += b;
}

EXTERN_C int func_80054048(S_80054048 *p)
{
    return p->unk8;
}

EXTERN_C S_Rgb func_80054054(S_80025A64 *p)
{
    return p->unkC;
}

EXTERN_C int func_80054074(S_80054048 *p)
{
    return p->unk4 & 0x3;
}

EXTERN_C int func_80054080(S_80054048 *p)
{
    return p->unk4;
}

EXTERN_C void func_8005408C(S_80054048 *p, int v)
{
    p->unk4 = v;
}

EXTERN_C void func_80054094(S_80054048 *p, int v)
{
    p->unk0 = v;
}

EXTERN_C int func_8005409C(S_80054048 *p)
{
    return p->unk0 == 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_800540A8);

EXTERN_C void func_80054258(S_A2B_Str *s)
{
    int n = (s->len >> 1) + 1;
    S_A2B_Ch2 *d = new S_A2B_Ch2[(s->len >> 1) + 2];
    unsigned i;
    d[0] = s->p[0];
    for (i = 1; i < n; i++) {
        d[i].c[0] = (PB_(s)[4 * i - 2] & 0xF) + (PB_(s)[4 * i - 1] << 4);
        d[i].c[1] = (PB_(s)[4 * i] & 0xF) + (PB_(s)[4 * i + 1] << 4);
    }
    if (!(s->len & 1))
        ((char *)d)[n * 2 - 1] = 0;
    if (s->p)
        func_800A0D0C(s->p);
    s->len = n;
    s->p = d;
}

EXTERN_C void *func_800543A0(S_A2_543A0 *p, S_A2_543A0 *q)
{
    p->vt = D_80013B20;
    p->a = q->a;
    p->b = q->b;
    p->c = q->c;
    p->d = q->d;
    p->f = 0;
    p->e = 0;
    func_80054414(p, q);
    return p;
}

EXTERN_C void *func_80054414(void *pv, void *qv)
{
    S_A2_543A0 *p = (S_A2_543A0 *)pv, *q = (S_A2_543A0 *)qv;
    int r;
    if (AT(p, void *, 0x10))
        func_800A0D0C(AT(p, void *, 0x10));
    AT(p, void *, 0x10) = 0;
    r = func_80053BB4((S_80053BB4 *)q);
    AT(p, int, 0x14) = r;
    if (r)
        func_800544AC(p, AT(q, void *, 0x10));
    p->a = q->a;
    p->b = q->b;
    p->d = q->d;
    p->c = q->c;
    return p;
}

EXTERN_C void func_800544AC(void *pv, void *qv)
{
    S_A2B_StrC *s = (S_A2B_StrC *)pv;
    S_A2_Ch *q = (S_A2_Ch *)qv;
    if (!s->p) {
        unsigned i;
        S_A2_Ch *r;
        s->p = new S_A2_Ch[s->len + 1];
        i = 0; if (s->len) { r = q; do { s->p[i] = *r; r++; i++; } while (i < s->len); }
    }
}

EXTERN_C void func_8005457C(S_8005457C *p, int v)
{
    p->unk8 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80054584);

C_800545E0::C_800545E0(C_800545E0 *o) : B_800538CC(f53BC0(o), 0)
{
    vt = D_80013B48;
    unk1C = o->unk1C;
    unk20 = o->unk20;
    unk24 = 0;
}

C_8005464C::C_8005464C()
{
    AT(this, void **, 0x18) = D_80013B48;
    unk1C = 0;
    unk20 = 10000;
    unk24 = 0;
}

EXTERN_C void *func_80054690(void *p, void *q)
{
    AT(p, int, 0x1C) = AT(q, int, 0x1C);
    AT(p, int, 0x20) = AT(q, int, 0x20);
    func_80053C6C(p, q);
    return p;
}

EXTERN_C void *func_800546C8(void *p, signed char a)
{
    int v = a;
    if (v >= 0x80)
        v -= 0x100;
    func_80054708(p, v);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80045850", func_80054708);

EXTERN_C void *func_800548F0(void *p, int a)
{
    func_80054708(p, AT(p, int, 0x1C) + a);
    return p;
}

EXTERN_C void *func_80054920(void *p, int a)
{
    func_80054708(p, AT(p, int, 0x1C) - a);
    return p;
}

EXTERN_C void *func_80054950(void *p)
{
    func_80054708(p, AT(p, int, 0x1C) + 1);
    return p;
}

EXTERN_C void *func_80054980(void *p)
{
    func_80054708(p, AT(p, int, 0x1C) - 1);
    return p;
}

EXTERN_C int func_800549B0(S_800549B0 *p, int a)
{
    return p->unk1C == a;
}

EXTERN_C int func_800549C4(S_800549B0 *p, int a)
{
    return p->unk1C != a;
}

EXTERN_C int func_800549D8(S_800549D8 *p)
{
    return p->unk1C;
}

EXTERN_C void func_800549E4(S_800549D8 *p, int v)
{
    p->unk24 = v;
}

EXTERN_C void func_800549EC(S_800549D8 *p, int v)
{
    p->unk20 = v;
}

EXTERN_C void func_800549F4()
{
}

EXTERN_C void func_800549FC()
{
}

EXTERN_C void func_80054A04()
{
    func_800601D8(&D_800B4D6C, D_800B4D78);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013940);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013A38);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013A88);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013AA8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013B00);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013B20);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013B48);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013B70);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013BA0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013BB8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013BD0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013C00);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013C50);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013C70);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013CB0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013D00);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013E10);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013E30);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013F40);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013F90);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80013FB0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800140C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014110);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014130);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014180);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014278);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800142B8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014308);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014400);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014450);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014548);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800145B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014658);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014750);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800147A0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014808);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014858);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014950);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800149B8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014A08);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014B00);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014B68);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014BD0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014C38);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014C50);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014C68);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014C7C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014C8C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014C9C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014CAC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014CFC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014D1C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014D5C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014DAC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014DCC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014E0C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014E5C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014E7C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014EAC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014EEC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80014FFC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_8001504C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_8001506C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800150BC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800151B4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_8001521C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_8001526C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80015364);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80015384);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800153C4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_800153FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80045850", D_80015414);
