#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_80028428.h"

EXTERN_C void func_80028428(void *p, int a)
{
    func_8001DEB8(p, a);
}

EXTERN_C int func_80028448(S_80028448 *p)
{
    return p->unk4;
}

C_80028454::C_80028454(int a, int b, int c) : B_8002860C(&D_800B4C64, a, b, c)
{
    vtC = D_800112F4;
    vt = D_8001126C;
}

EXTERN_C void *func_800284AC(void *p, void *q)
{
    func_80028710(p, q);
    return q;
}

EXTERN_C S_Spr2 *func_800284D4(S_Spr2 *p, S_Spr2 *q)
{
    spr2_copy(p, q);
    p->vtC = D_800112F4;
    p->vt = D_8001126C;
    return p;
}

EXTERN_C void func_800285CC(S_80028FD8 *p, int a)
{
    p->vtC = D_800112F4;
    p->vt = D_8001126C;
    base_28FD8(p, a);
}

EXTERN_C void *func_8002860C(void *a, void *r, int b, int c, void *col)
{
    S_Spr2v *p = (S_Spr2v *)a;
    p->vt = D_80010178;
    p->unk4 = 0;
    p->vt = D_800111BC;
    p->unk8 = 0;
    p->unkA = c;
    p->vt = D_800117D4;
    p->vtC = D_800112F4;
    p->vt = D_80011304;
    SetDrawMode(&p->dm[0], 0, 0, 0, 0);
    SetDrawMode(&p->dm[1], 0, 0, 0, 0);
    ((unsigned char *)&p->sp[0].tag)[3] = 4;
    p->sp[0].code = 0x64;
    ((unsigned char *)&p->sp[1].tag)[3] = 4;
    p->sp[1].code = 0x64;
    func_80028C80((S_Spr2 *)p, r);
    func_80028DC4(p, b);
    func_80028D10((S_Spr2 *)p, col);
    func_80028A24((S_Spr2 *)p);
    return p;
}

EXTERN_C void *func_80028710(void *a, void *b)
{
    S_Spr2 *p = (S_Spr2 *)a;
    S_Spr2 *q = (S_Spr2 *)b;
    func_80027FEC((S_80027FEC *)p, (S_80027FEC *)q);
    {
        S_Sprt *d = q->sp;
        int n = 1;
        S_Sprt *s = p->sp;
        for (; n != -1; n--)
            *d = *s, d++, s++;
    }
    {
        S_DrMode *d = q->dm;
        int n = 1;
        S_DrMode *s = p->dm;
        for (; n != -1; n--)
            *d = *s, d++, s++;
    }
    return q;
}

EXTERN_C S_Spr2 *func_800287C8(S_Spr2 *q)
{
    S_Spr2 *p = (S_Spr2 *)operator new(0x50);
    spr2_copy(p, q);
    return p;
}

EXTERN_C int func_800288D0(S_Spr2 *p)
{
    switch (p->unk8) {
    case 1:
        func_80028AE8(p);
        break;
    case 2:
        p->unk8--;
        break;
    }
    D_800B4CFC->add((P_TAG *)&p->sp[D_800B4CF0], (unsigned short)p->unkA);
    D_800B4CFC->add((P_TAG *)&p->dm[D_800B4CF0], (unsigned short)p->unkA);
    return 2;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028A24);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80028AE8);

EXTERN_C void func_80028B90(S_Spr2 *p, int x, int y)
{
    if (p->unk8 == 1)
        func_80028AE8(p);
    p->sp[D_800B4CF0].x0 = x;
    p->sp[D_800B4CF0].y0 = y;
    p->unk8 = 2;
}

EXTERN_C void func_80028C08(S_Spr2 *p, int w, int h)
{
    if (p->unk8 == 1)
        func_80028AE8(p);
    p->sp[D_800B4CF0].w = w;
    p->sp[D_800B4CF0].h = h;
    p->unk8 = 2;
}

EXTERN_C void func_80028C80(S_Spr2 *p, void *rv)
{
    S_80028C80 *r = (S_80028C80 *)rv;
    if (p->unk8 == 1)
        func_80028AE8(p);
    p->sp[D_800B4CF0].x0 = r->x;
    p->sp[D_800B4CF0].y0 = r->y;
    p->sp[D_800B4CF0].w = r->w;
    p->sp[D_800B4CF0].h = r->h;
    p->unk8 = 2;
}

EXTERN_C void func_80028D10(S_Spr2 *p, void *cv)
{
    if (p->unk8 == 1)
        func_80028AE8(p);
    p->sp[D_800B4CF0].r0 = ((S_80029BF4 *)cv)->unk5;
    p->sp[D_800B4CF0].g0 = ((S_80029BF4 *)cv)->unk6;
    p->sp[D_800B4CF0].b0 = ((S_80029BF4 *)cv)->unk7;
    p->unk8 = 2;
}

EXTERN_C void func_80028DC4(void *pv, int a)
{
    S_Spr2 *p = (S_Spr2 *)pv;
    S_80028DC4 *t = (S_80028DC4 *)a;
    int u;
    if (p->unk8 == 1)
        func_80028AE8(p);
    int tp = t->unk1C;
    SetDrawMode(&p->dm[D_800B4CF0], 0, 1, tp, 0);
    if (!t->unkC)
        u = (unsigned short)t->unk10 & 0x3F;
    else if (((int (*)(void *))t->unkC->vt[3].pfn)((char *)t->unkC + t->unkC->vt[3].delta))
        u = (t->unk10 << 1) & 0x7F;
    else
        u = t->unk10 << 2;
    S_UV28 uv(u, t->unk12);
    p->sp[D_800B4CF0].u0 = uv.u;
    p->sp[D_800B4CF0].v0 = uv.v;
    p->sp[D_800B4CF0].clut = t->unkC->unk8;
    p->unk8 = 2;
}

EXTERN_C int func_80028F10(S_80028F10 *p)
{
    return p->e[p->unk8 == 1 ? D_800B4CF0 ^ 1 : D_800B4CF0].unk38;
}

EXTERN_C int func_80028F58(S_80028F10 *p)
{
    return p->e[p->unk8 == 1 ? D_800B4CF0 ^ 1 : D_800B4CF0].unk3A;
}

EXTERN_C void func_80028FA0(void *p, int a)
{
    func_80028DC4(p, a);
}

EXTERN_C int func_80028FC0(S_80028FC0 *p)
{
    return p->unk4;
}

EXTERN_C void func_80028FCC()
{
    D_800B4C70 = 0;
}

EXTERN_C void func_80028FD8(S_80028FD8 *p, int a)
{
    p->vtC = D_800112F4;
    p->vt = D_80011304;
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_8002900C);

INCLUDE_ASM("asm/main/nonmatchings/u_80028428", func_80029414);

EXTERN_C void func_8002970C(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C S_8002972C *func_8002972C(S_8002972C *p, int a, int b, int c, int d)
{
    p->vtbl = D_80011384;
    p->unk5 = a;
    p->unk6 = b;
    p->unk7 = c;
    p->unk4 = d & 1;
    return p;
}

EXTERN_C S_8002972C *func_80029758(S_8002972C *p, S_8002972C *c)
{
    int t;
    int r = 0xFF;
    t = c->unk5 * 10 / 7;
    if (t < r)
        r = t;
    int g = 0xFF;
    t = c->unk6 * 10 / 7;
    if (t < g)
        g = t;
    int b = 0xFF;
    t = c->unk7 * 10 / 7;
    if (t < b)
        b = t;
    func_8002972C(p, r, g, b, 1);
    return p;
}

EXTERN_C S_8002972C *func_80029850(S_8002972C *p, S_8002972C *c)
{
    int t;
    int r = 0;
    t = c->unk5 * 7 / 10;
    if (t > 0)
        r = t;
    int g = 0;
    t = c->unk6 * 7 / 10;
    if (t > 0)
        g = t;
    t = c->unk7 * 7 / 10;
    int pos = t > 0;
    func_8002972C(p, r, g, t & -pos, 1);
    return p;
}

EXTERN_C void func_8002991C()
{
    func_800198AC(D_800B4CE0, 2);
    func_800198AC(D_800B4CD8, 2);
    func_800198AC(D_800B4CD0, 2);
    func_800198AC(D_800B4CC8, 2);
    func_800198AC(D_800B4CC0, 2);
    func_800198AC(D_800B4CB8, 2);
    func_800198AC(D_800B4CB0, 2);
    func_800198AC(D_800B4CA8, 2);
    func_800198AC(D_800B4CA0, 2);
    func_800198AC(D_800B4C98, 2);
    func_800198AC(D_800B4C90, 2);
    func_800198AC(D_800B4C88, 2);
    func_800198AC(D_800B4C80, 2);
    func_800198AC(D_800B4C78, 2);
}

EXTERN_C void func_80029A14()
{
    func_8002972C((S_8002972C *)D_800B4C78, 255, 255, 255, 1);
    func_8002972C((S_8002972C *)D_800B4C80, 191, 191, 191, 1);
    func_8002972C((S_8002972C *)D_800B4C88, 127, 127, 127, 1);
    func_8002972C((S_8002972C *)D_800B4C90, 63, 63, 63, 1);
    func_8002972C((S_8002972C *)D_800B4C98, 0, 0, 0, 1);
    func_8002972C((S_8002972C *)D_800B4CA0, 255, 0, 0, 1);
    func_8002972C((S_8002972C *)D_800B4CA8, 255, 191, 191, 1);
    func_8002972C((S_8002972C *)D_800B4CB0, 255, 191, 0, 1);
    func_8002972C((S_8002972C *)D_800B4CB8, 255, 255, 0, 1);
    func_8002972C((S_8002972C *)D_800B4CC0, 0, 255, 0, 1);
    func_8002972C((S_8002972C *)D_800B4CC8, 255, 0, 255, 1);
    func_8002972C((S_8002972C *)D_800B4CD0, 0, 255, 255, 1);
    func_8002972C((S_8002972C *)D_800B4CD8, 0, 0, 255, 1);
    func_8002972C((S_8002972C *)D_800B4CE0, 0, 0, 0, 0);
}
