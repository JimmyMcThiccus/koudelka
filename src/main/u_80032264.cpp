#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"

EXTERN_C int func_80032264(void *p)
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

EXTERN_C void func_800322C8(void *p, int a)
{
    AT(p, void **, 0) = D_80011E74;
    func_8001D324(D_800A4544, func_8001D25C(D_800A4544, (int)p));
    func_8001D024(p, a);
}

EXTERN_C void *func_80032334(void *p)
{
    void *g;
    AT(p, void **, 0) = D_80011E74;
    AT(p, int, 8) = 0;
    AT(p, int, 4) = 0;
    AT(p, int, 0xC) = 0;
    g = D_800A4544;
    func_8001D150(g, new S_A2_X40(p));
    return p;
}

EXTERN_C void func_800323C0(S_800323C0 *p, S_800323C0_Node *n)
{
    if (p->unk8)
        n->unk4 = p->unk8;
    p->unk8 = n;
}

EXTERN_C S_A2_C28 *func_800323DC(S_A2_Pool *pool)
{
    S_A2_C28 *n = pool->head;
    if (n) {
        pool->head = (S_A2_C28 *)n->unk4;
        n->unk4 = 0;
        return n;
    }
    return a2_init_C28(new S_A2_C28);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032504);

EXTERN_C int func_80032920(S_80032920 *p)
{
    return p->unk4;
}

EXTERN_C S_A2_C28 *func_8003292C(S_A2_C28 *p)
{
    return a2_init_C28(p);
}

EXTERN_C void func_80032A10(void *p, int flags)
{
    AT(p, void **, 8) = D_80011DBC;
    AT(p, void **, 0) = D_80011E24;
    AT(p, void **, 8) = D_80011D04;
    AT(p, void **, 0) = D_80011D6C;
    AT(p, void **, 8) = D_80011AAC;
    AT(p, void **, 0) = D_80011B14;
    func_800198AC((char *)p + 8, 0);
    func_8001A610(p, flags);
}

EXTERN_C int func_80032A9C(S_Rgb *s, S_Rgb *a, S_Rgb *b, S_Rgb *c, S_Rgb *d)
{
    S_Rgb t = *s;
    *a = t;
    *b = t;
    *c = t;
    *d = t;
    return 1;
}

EXTERN_C void func_80032B14(S_Rgb *a, S_Rgb *b)
{
    *a = *b;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032B2C);

EXTERN_C int func_80032BD8(void *p, short *r)
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
        q += 2;
    }
    return minx == r[2] || !maxx || miny == r[3] || !maxy;
}

EXTERN_C S_A2_32C80 *func_80032C80(S_A2_32C80 *p)
{
    int i;
    S_A2_PolyF4 *q = p->p;
    p->rgb = 0x28808080;
    i = 2;
    while (i--) {
        q->len = 5;
        q->code = 0x28;
        q++;
    }
    return p;
}

EXTERN_C S_Prim *func_80032CBC(S_Prim *p)
{
    ((unsigned char *)&p->tag)[3] = 5;
    p->code = 0x28;
    return p;
}

EXTERN_C void func_80032CD4(char *p)
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

EXTERN_C int func_80032D54()
{
    return 0x2C;
}

EXTERN_C void *func_80032D5C()
{
    S_A2_Pool98 *pool = (S_A2_Pool98 *)&D_800AC844;
    S_A2_C98 *n = pool->head;
    if (n) {
        pool->head = (S_A2_C98 *)n->unk4;
        n->unk4 = 0;
    } else
        n = a2_init_C98((S_A2_C98 *)operator new(sizeof(S_A2_C98)));
    return n ? (void *)&n->b : 0;
}

EXTERN_C void func_80032EB0(S_A2_Node4 *n)
{
    if (D_800AC844.unk8)
        n->unk4 = D_800AC844.unk8;
    D_800AC844.unk8 = n;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032ED4);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80032F80);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_80033404);

INCLUDE_ASM("asm/main/nonmatchings/u_80032264", func_800338A4);

EXTERN_C char *func_80033D34(void *p, char *src)
{
    func_80030AA8(p, src);
    func_80034854(p ? (char *)p + 0x34 : 0, src + 0x2C);
    return src + 0x38;
}

EXTERN_C void func_80033D7C(void *p, int a)
{
    func_8003488C(p ? (char *)p + 0x34 : 0, a);
}

EXTERN_C void func_80033DAC(void *p)
{
    func_800348E4(p ? (char *)p + 0x34 : 0);
}

EXTERN_C void func_80033DDC()
{
    AT(&D_800AC844, void **, 0) = D_80011F44;
    func_8001D324(D_800A4544, func_8001D25C(D_800A4544, (int)&D_800AC844));
    func_8001D024(&D_800AC844, 2);
}

EXTERN_C void func_80033E40()
{
    void *g;
    AT(&D_800AC844, void **, 0) = D_80011F44;
    AT(&D_800AC844, int, 8) = 0;
    AT(&D_800AC844, int, 4) = 0;
    AT(&D_800AC844, int, 0xC) = 0;
    g = D_800A4544;
    func_8001D150(g, new S_A2_X40(&D_800AC844));
}
