#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80033ECC);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034044);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034184);

EXTERN_C int func_80034608(S_80034608 *p)
{
    return p->unk4;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80034614);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_800349F8);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003546C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003585C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035CA8);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035CD8);

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
    func_8009D000(0);
    if (D_800B4D0C)
        ((A2VObj0 *)D_800B4D0C)->v08();
    func_80018970(&D_800A451C);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80035F80);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036000);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036090);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036110);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_800361C8);

EXTERN_C void func_8003635C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036364);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036554);

EXTERN_C void func_80036674(S_A2_H0C *p)
{
    while (count_of(&p->h))
        ((A2VObj0 *(*)(void *, int))func_80019C68)((List *)&p->h, 0)->v01(0);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_800366F8);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036780);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036850);

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036D8C);

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

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_80036FC0);

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
        func_8009CAC0(0);
        func_8009CAE0(0);
    }
    AT(AT(p, void *, 4), int, 4) = -1;
    if (AT(p, void *, 0x2C))
        func_800A0D0C(AT(p, void *, 0x2C));
    AT(p, void *, 0x2C) = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80033ECC", func_8003714C);

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
