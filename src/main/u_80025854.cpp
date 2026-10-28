#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_80025854.h"

EXTERN_C void func_80025854(void *p, int a)
{
    func_8001DEB8(p, a);
}

EXTERN_C int func_80025874(S_80025874 *p)
{
    return p->unk24;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80025880);

EXTERN_C S_UV2 func_80025960(S_Tex *p)
{
    int x;
    VObj *o = p->unkC;
    if (!o)
        x = p->unk10 & 0x3F;
    else if (vcall3(o))
        x = (p->unk10 << 1) & 0x7F;
    else
        x = p->unk10 << 2;
    return S_UV2(x, p->unk12);
}

EXTERN_C int func_800259F8(S_800259F8 *p)
{
    return p->unk1C;
}

EXTERN_C int func_80025A04(S_80025A04 *p)
{
    int r;
    VObj *o = p->unkC;
    if (o) {
        VEnt *e = &o->vt[3];
        if (((int (*)(void *))e->f)((char *)o + e->d))
            r = 8;
        else
            r = 4;
    } else
        r = 0x10;
    return r;
}

EXTERN_C void *func_80025A5C(S_800259F8 *p)
{
    return &p->unk10;
}

EXTERN_C S_Rgb func_80025A64(S_80025A64 *p)
{
    return p->unk10;
}

EXTERN_C S_XYc func_80025A84(S_Tex *p)
{
    int x = p->unk14;
    int r;
    VObj *o = p->unkC;
    if (o) {
        if (vcall3(o))
            r = x >> 1;
        else
            r = x >> 2;
    } else
        r = x;
    return S_XYc(r, p->unk16);
}

EXTERN_C S_Rgb func_80025B0C(S_80025A64 *p)
{
    return p->unk14;
}

EXTERN_C int func_80025B2C(S_800259F8 *p)
{
    return p->unkC;
}

EXTERN_C int func_80025B38(S_800259F8 *p)
{
    return p->unk4;
}

EXTERN_C S_Img *func_80025B44(S_Img *p, int x, short y, short z, int a, int b)
{
    p->vt = D_80010178;
    p->unk4 = 0;
    p->unk8 = D_80010888;
    p->vt = D_800108A0;
    p->unkC = a;
    setPos_80025BE0(p, S_XYc(-1, -1));
    p->unk14.x = 0;
    p->unk14.y = 0;
    p->unk18 = 0;
    p->unk1E = b;
    func_80024BF0(p, x, y, z);
    return p;
}

EXTERN_C S_Img *func_80025BE0(S_Img *p, int a, int b)
{
    p->vt = D_80010178;
    p->unk4 = 0;
    p->unk8 = D_80010888;
    p->vt = D_800108A0;
    p->unkC = a;
    setPos_80025BE0(p, S_XYc(-1, -1));
    p->unk14.x = 0;
    p->unk14.y = 0;
    p->unk18 = 0;
    p->unk1E = b;
    return p;
}

EXTERN_C void func_80025C50(unsigned short *a, unsigned short *b)
{
    *a = *b;
}

EXTERN_C S_80025C5C *func_80025C5C(S_80025C5C *p, int v)
{
    p->unk0 = v;
    return p;
}

EXTERN_C S_80025C5C *func_80025C68(S_80025C5C *p, int v)
{
    p->unk0 = v;
    return p;
}

EXTERN_C int func_80025C74(S_80025C5C *p)
{
    return p->unk0;
}

EXTERN_C void *func_80025C80(void *p)
{
    return p;
}

EXTERN_C S_80025C88 *func_80025C88(S_80025C88 *p, int a, int b, int c, int d)
{
    p->unk0 = c;
    p->unk2 = a;
    p->unk4 = b;
    p->unk1 = d;
    return p;
}

EXTERN_C void *func_80025CA4(void *p)
{
    return p;
}

EXTERN_C void func_80025CAC(unsigned short *a, unsigned short *b)
{
    *a = *b;
}

EXTERN_C unsigned short *func_80025CB8(unsigned short *a, unsigned short *b)
{
    *a = *b;
    return a;
}

EXTERN_C S_80025CC8 *func_80025CC8(S_80025CC8 *p, int a, int b)
{
    p->unk0 = a;
    p->unk1 = b;
    return p;
}

EXTERN_C void *func_80025CD8(void *p)
{
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80025CE0);

EXTERN_C int func_80026014(int a)
{
    int r;
    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400)
            r = D_800108C0[a];
        else
            r = D_800108C0[0x800 - a];
    } else if (a < 0xC00)
        r = -D_800108C0[a - 0x800];
    else
        r = -D_800108C0[0x1000 - a];
    return r;
}

EXTERN_C int func_800260A4(int a)
{
    int r;
    a &= 0xFFF;
    if (a < 0x800) {
        if (a < 0x400)
            r = D_800108C0[0x400 - a];
        else
            r = -D_800108C0[a - 0x400];
    } else if (a < 0xC00)
        r = -D_800108C0[0xC00 - a];
    else
        r = D_800108C0[a - 0xC00];
    return r;
}

EXTERN_C void func_80026138(void *q, int a)
{
    S_80026138 *p = (S_80026138 *)q;
    p->vt = D_80011124;
    if (p->unk4) {
        void *o = p->unk4;
        p->unk4 = 0;
        func_80027408(o, p);
    }
    func_800198AC(p, a);
}

EXTERN_C S_Pt16 func_80026190(void *p, S_Pt16 x)
{
    return D_800B4C50_pt;
}

EXTERN_C S_Cc func_800261B4(void *p, S_Cc *s, S_Cc x)
{
    return *s;
}

EXTERN_C int func_800261D4()
{
    return 1;
}

EXTERN_C int func_800261DC(S_800261DC *p, S_4b x)
{
    if (p->unk4)
        func_8002758C(p->unk4, p);
    return 1;
}

EXTERN_C void func_80026214(int a)
{
    VObj *o = D_800B4C54;
    if (o) {
        VEnt *e = &o->vt[1];
        ((void (*)(void *, int))e->f)((char *)o + e->d, 3);
    }
    D_800B4C54 = (VObj *)func_80026274((S_80026274 *)operator new(0x20), (S_8b *)a, 0);
}

EXTERN_C S_80026274 *func_80026274(S_80026274 *p, S_8b *r, int b)
{
    p->vt = D_80011124;
    p->unk4 = b;
    p->vt = D_800110C4;
    p->unk8 = 0;
    p->unkA = 0;
    p->unkC = 0;
    p->unkE = 0;
    p->unk14 = 0;
    p->unk16 = 0;
    p->unk18 = 0;
    p->unk1A = 0;
    p->unk1C = 0;
    p->unk10 = 0;
    *(S_8b *)&p->unk8 = *r;
    return p;
}

EXTERN_C void func_800262E4(S_800262E4 *p, int a)
{
    p->vt = D_800110C4;
    if (p->unk10 && p->unk10->unk4) {
        p->unk10->unk4 = 0;
        vdel(p->unk10);
    }
    if (p->unk1C && p->unk1C->unk4) {
        p->unk1C->unk4 = 0;
        vdel(p->unk1C);
    }
    func_80026138(p, a);
}

EXTERN_C S_XYc func_800263C0(VObj *p, int u, S_XYc x)
{
    VEnt *e = &p->vt[4];
    return ((S_XYc (*)(void *, S_XYc))e->f)((char *)p + e->d, x);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80026420);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80026558);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_8002673C);

EXTERN_C int func_80026920(S_80026920 *p)
{
    return p->unk10 && p->unk1C && vcall3(p->unk10) && vcall3(p->unk1C);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_800269B8);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80027408);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_8002758C);

INCLUDE_ASM("asm/main/nonmatchings/u_80025854", func_80027754);

EXTERN_C void func_800278D8()
{
    D_800B4C50 = -1;
    D_800B4C52 = -1;
}
