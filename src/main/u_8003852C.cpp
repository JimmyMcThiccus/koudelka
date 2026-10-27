#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a2/a2.h"

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003852C);

EXTERN_C int func_800385E4(S_800385E4 *p)
{
    return p->unk10;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_800385F0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038654);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_800386B8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038764);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_800387D0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038834);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038898);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_800388FC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038938);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038978);

EXTERN_C int func_800389B8()
{
    return 1;
}

EXTERN_C int func_800389C0()
{
    return 1;
}

EXTERN_C int func_800389C8()
{
    return 1;
}

EXTERN_C int func_800389D0()
{
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_800389D8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038B0C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038C20);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038C64);

EXTERN_C void func_80038D14(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038D34);

EXTERN_C void func_80038E2C()
{
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038E34);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038E98);

EXTERN_C int func_80038EF0(S_80038EF0 *p)
{
    return p->unk24;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038EFC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80038FB8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003906C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003912C);

EXTERN_C void func_800391DC(S_800391DC *p, int a, int b)
{
    p->unk64 = b;
    p->unk48->unk14 = a;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_800391EC);

EXTERN_C int func_800392C8(S_800392C8 *p)
{
    return p->unk24;
}

EXTERN_C void func_800392D4(void *p)
{
    func_8003C320(p, 1);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_800392F4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039388);

EXTERN_C void func_80039444(S_80039444 *p, int v)
{
    p->unk50 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003944C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003950C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039610);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039710);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039824);

EXTERN_C void *func_80039928(S_A2_Stack *p)
{
    if (p->n <= 0)
        return 0;
    p->n--;
    return p->arr->items[p->n];
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039960);

EXTERN_C int func_800399A4(S_800399A4 *p)
{
    return p->unk4;
}

EXTERN_C void func_800399B0(S_800399B0 *p)
{
    p->unk4 = p->unk0->unk4;
}

EXTERN_C void func_800399C4(S_800399A4 *p)
{
    p->unk4 = 0;
}

EXTERN_C void func_800399CC(S_800399A4 *p, int v)
{
    p->unk4 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_800399D4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039A14);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039A88);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039BEC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039C88);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039D38);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039D94);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039DD8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039E80);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_80039F80);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A010);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A150);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A214);

EXTERN_C void *func_8003A318(S_A2_Stack *p)
{
    if (p->n <= 0)
        return 0;
    p->n--;
    return p->arr->items[p->n];
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A350);

EXTERN_C void func_8003A394(void *p, int a)
{
    func_80039824(p, a);
}

EXTERN_C void func_8003A3B4(void *p, int a)
{
    func_80039710(p, a);
}

EXTERN_C void func_8003A3D4(void *p, int a)
{
    func_80039610(p, a);
}

EXTERN_C void func_8003A3F4(void *p, int a)
{
    func_8003950C(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A414);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A454);

EXTERN_C void func_8003A490(void *p, int a)
{
    func_80019C68(p ? AT(p, void *, 0) : 0, a);
}

EXTERN_C void func_8003A4C0(void *p, int a)
{
    func_80019CFC(p ? AT(p, void *, 0) : 0, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A4F0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A538);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A574);

EXTERN_C Item *func_8003A624(void *p, int a)
{
    return func_80019F64(p ? AT(p, List *, 0) : 0, a);
}

EXTERN_C void func_8003A654(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A674);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A6B4);

EXTERN_C void *func_8003A6F4(S_8003A6F4 *p)
{
    return &p->unk34;
}

EXTERN_C void *func_8003A6FC(S_8003A6F4 *p)
{
    return &p->unk2C;
}

EXTERN_C int func_8003A704(void *p, int a)
{
    void **q = AT(p, void **, 0x28);
    if (q)
        return func_80019C24(*q, a);
    return 0;
}

EXTERN_C int func_8003A738(S_8003A6F4 *p)
{
    return p->unk24;
}

EXTERN_C void func_8003A744(S_8003A6F4 *p)
{
    p->unk24 = 0;
}

EXTERN_C void func_8003A74C(S_8003A6F4 *p, int v)
{
    p->unk24 = v;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A754);

EXTERN_C void *func_8003A7A4(void *p, int a)
{
    func_8001A8F0(p, a, 8);
    return p;
}

EXTERN_C void *func_8003A7D0(void *p, int a)
{
    func_8001A8F0(p, a, 8);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003A7FC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003ABEC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003AD78);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B168);

EXTERN_C S_8003B2F0 *func_8003B2F0(S_8003B2F0 *p, S_8003B2F0_V *v)
{
    int a = v->unk0, b = v->unk4, c = v->unk8;
    p->unk14.unk0 = a;
    p->unk14.unk4 = b;
    p->unk14.unk8 = c;
    return p;
}

EXTERN_C S_A2_V4 func_8003B310(void *s) return r
{
    int a = AT(s, int, 0x14), b = AT(s, int, 0x18), c = AT(s, int, 0x1C);
    r.d = 0;
    r.a = a;
    r.b = b;
    r.c = c;
}

EXTERN_C MATRIX *func_8003B334(MATRIX *p, MATRIX *q)
{
    MulMatrix(p, q);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B35C);

EXTERN_C MATRIX *func_8003B3C0(MATRIX *p, MATRIX *q)
{
    CompMatrix(p, q, p);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B3EC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B450);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B598);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B68C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B780);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B834);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B8AC);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B960);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003B9D8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003BA78);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003BAD8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003BB78);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003BBD8);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003BC10);

EXTERN_C S_A2_Sv func_8003BC50(short *m, int i) return r
{
    short a, b, c;
    m += i * 3;
    a = m[0]; b = m[1]; c = m[2];
    r.pad = 0; r.x = a; r.y = b; r.z = c;
}

EXTERN_C S_A2_Sv func_8003BC84(short *m, int i) return r
{
    short a, b, c;
    m += i;
    a = m[0]; b = m[3]; c = m[6];
    r.pad = 0; r.x = a; r.y = b; r.z = c;
}

EXTERN_C void func_8003BCB0(short *m, int i, short *v)
{
    m += i * 3;
    m[0] = v[0]; m[1] = v[1]; m[2] = v[2];
}

EXTERN_C void func_8003BCE0(MATRIX *m, int i, SVECTOR *v)
{
    m->m[0][i] = v->vx;
    m->m[1][i] = v->vy;
    m->m[2][i] = v->vz;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003BD08);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003BDB8);

EXTERN_C S_Short func_8003BE68(S_Short *a, S_Short *b)
{
    S_Short r;
    int t = a->v;
    t += b->v;
    r.v = t;
    return r;
}

EXTERN_C S_Int func_8003BE84(S_Int *a, S_Int *b)
{
    S_Int r;
    r.v = a->v + b->v;
    return r;
}

EXTERN_C S_8003BEA0 *func_8003BEA0(S_8003BEA0 *p, int i)
{
    return &p[i];
}

EXTERN_C void *func_8003BEB4(void *p)
{
    return p;
}

EXTERN_C void *func_8003BEBC(void *p)
{
    return p;
}

EXTERN_C void func_8003BEC4(void *p, int a)
{
    S_A2_VEnt *e = (S_A2_VEnt *)(AT(a, char *, 0) + 0x20);
    e->pfn((char *)a + e->delta, a);
}

C_8003BEF8::C_8003BEF8()
{
    AT(this, void **, 0) = D_80012724;
    unk48 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003BF30);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003C01C);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003C0D0);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003C1E4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003C270);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003C2E4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003C320);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003C3E4);

INCLUDE_ASM("asm/main/nonmatchings/u_8003852C", func_8003C434);

EXTERN_C void func_8003C4CC(void *p, int a)
{
    func_8003BEC4(p, a);
}

EXTERN_C void func_8003C4EC()
{
    func_8003C510(&D_800B4D1C);
}
