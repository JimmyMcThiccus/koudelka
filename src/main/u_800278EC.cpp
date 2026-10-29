#include "common.h"
#define EXE_H_IN_u_800278EC
#include "shared/exe.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_800278EC.h"

EXTERN_C S_8001A294 *func_800278EC(S_8001A294 *p, int a)
{
    p->vtbl = D_80011124;
    p->unk4 = a;
    p->vtbl = D_800110F4;
    return p;
}

EXTERN_C void func_80027910(void *p, int a)
{
    func_80026138(p, a);
}

EXTERN_C S_8001A294 *func_80027930(S_8001A294 *p, int a)
{
    p->vtbl = D_80011124;
    p->unk4 = a;
    return p;
}

EXTERN_C void func_80027948()
{
    if (!D_800B4C5C && !D_800B4C58)
        D_800B4C5C = new C_800279C0;
}

EXTERN_C void func_8002798C()
{
    if (D_800B4C58)
        D_800B4C58--;
}

EXTERN_C void func_800279A8()
{
    D_800B4C58++;
}

C_800279C0::C_800279C0()
{
    vt = D_80010348;
    vt4 = D_8001116C;
    vt = D_800111A4;
    void *m = D_800A4544;
    func_8001D150(m, new S_N338(this));
    unkC = 1;
}

EXTERN_C int func_80027A60(S_80027A60 *s)
{
    int st = s->state;
    switch (st) {
    case 0: {
        VObj *o = s->unk10;
        VEnt *e = &o->vt[3];
        ((void (*)(void *))e->f)((char *)o + e->d);
        s->unk14 = 0x18000;
        s->unk18 = 0;
        func_80035CF8();
        if (!func_80036FC0(s->unk10, 0x17F, 0x18000)) {
            func_8001B1C8(s->unk1C);
            if (s) {
                VEnt *e = &s->vt[1];
                ((void (*)(void *, int))e->f)((char *)s + e->d, 3);
            }
            D_800B4C5C = 0;
            return 1;
        }
        func_8003546C(s->unk10, s ? (char *)s + 4 : 0);
        func_8003714C(s->unk10);
        s->state = 2;
        break;
    }
    case 1: {
        char *buf = (char *)func_8001B134(0x18000);
        s->unk1C = buf;
        if (buf) {
            S_80027A60_O *o = (S_80027A60_O *)operator new(0x44);
            S_80027A60_VB *vb = &o->vbase;
            o->vb = vb;
            vb->unk0 = 0x10;
            vb->unk4 = -1;
            vb->unk2 = st;
            o->vt = D_80012154;
            o->vt8 = D_8001201C;
            o->vt = D_80012034;
            o->p = o->data;
            func_800198E0(o->data, 4, 0);
            o->vt8 = D_80012294;
            o->vt = D_80012224;
            o->unk28 = 0;
            o->unk2C = 0;
            s->unk10 = (VObj *)o;
            s->unk14 = 0x18000;
            s->unk18 = 0;
            func_80035CF8();
            if (func_80036FC0(s->unk10, 0x17F, 0x18000)) {
                func_8003546C(s->unk10, s ? (char *)s + 4 : 0);
                func_8003714C(s->unk10);
                s->state = 2;
                break;
            }
            s->state = 0;
            break;
        }
        DrawSync(0);
        StopRCnt(0xF2000000);
        StopRCnt(0xF2000001);
        StopRCnt(0xF2000002);
        StopRCnt(0xF2000003);
        EnterCriticalSection();
        func_8008B888();
        SpuQuit();
        PadStopCom();
        ResetGraph(0);
        StopCallback();
        _96_init();
        LoadExec(D_80011154, 0x80018000, 0x1000);
        return 1;
    }
    case 2:
        break;
    case 3:
        DrawSync(0);
        VSync(0);
        SetDispMask(0);
        StopRCnt(0xF2000000);
        StopRCnt(0xF2000001);
        StopRCnt(0xF2000002);
        StopRCnt(0xF2000003);
        EnterCriticalSection();
        func_8008B888();
        SpuQuit();
        PadStopCom();
        func_80035C28();
        ResetGraph(0);
        StopCallback();
        EnterCriticalSection();
        func_8001A8F0((void *)0x8009D000, (int)s->unk1C, 0x6000);
        start();
        break;
    default:
        return 0;
    }
    return 0;
}

EXTERN_C int func_80027D90(S_80027D90 *p)
{
    return p->unk14;
}

EXTERN_C void func_80027D9C(S_80027D90 *p)
{
    p->unkC = 3;
}

EXTERN_C void func_80027DA8(S_80027D90 *p)
{
    p->unkC = 0;
}

EXTERN_C char *func_80027DB0(S_80027DB0 *p, int n)
{
    char *r = 0;
    if (p->unk1C && p->unk18 < p->unk14) {
        r = p->unk1C + p->unk18;
        p->unk18 += n;
        if (p->unk14 < p->unk18)
            p->unk18 = p->unk14;
    }
    return r;
}

EXTERN_C void func_80027DFC(S_80027DFC *p, int a)
{
    p->vt4 = D_8001116C;
    p->vt = D_800111A4;
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_800278EC", func_80027E30);

EXTERN_C void func_80027FB0()
{
    if (D_800B4C60) {
        D_800EA8A4 = D_800B4C60;
        func_80018C1C(D_800EA8A8);
        D_800B4C60 = 0;
    }
}

EXTERN_C S_80027FEC *func_80027FEC(S_80027FEC *p, S_80027FEC *q)
{
    q->unk8 = p->unk8;
    q->unkA = p->unkA;
    return q;
}

EXTERN_C S_Vobj4h *func_80028004(S_Vobj4h *p)
{
    S_Vobj4h *o = (S_Vobj4h *)operator new(0xC);
    o->vtbl = D_80010178;
    o->unk4 = p->unk4;
    o->vtbl = D_800111BC;
    o->unk8 = p->unk8;
    o->unkA = p->unkA;
    return o;
}

EXTERN_C int func_80028064(S_80028064 *p)
{
    VObj *o = p->unk4;
    if (o) {
        VEnt *e = &o->vt[3];
        return ((int (*)(void *))e->f)((char *)o + e->d);
    }
    return 0;
}

EXTERN_C void func_800280A8(S_800280A8 *p)
{
    if (p) {
        do {
            VEnt *e = &p->vt[3];
            ((void (*)(void *))e->f)((char *)p + e->d);
            p = p->next;
        } while (p);
    }
}

EXTERN_C void func_800280F8(S_800280F8 *p, S_800280F8b *q)
{
    void *s = q->unk64;
    if (s) {
        if (p->unk4)
            func_8001A864(s, p->unk4);
        p->unk4 = s;
    }
    q->unk64 = p;
}

EXTERN_C void func_80028158(void *p, void *q)
{
    func_8002DC34(q, (int)p, 0);
}

EXTERN_C void func_80028184(S_80028184 *p)
{
    p->unk8 = 0;
}

EXTERN_C void func_8002818C(S_80028184 *p, int v)
{
    p->unkA = v;
}

EXTERN_C int func_80028194(S_80028184 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4h *func_800281A0(S_Vobj4h *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800111BC;
    p->unk8 = 0;
    p->unkA = a;
    return p;
}

EXTERN_C void func_800281CC(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_800281EC(S_80028184 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4h *func_800281F8(S_Vobj4h *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800111BC;
    p->unk8 = 0;
    p->unkA = a;
    p->vtbl = D_800111FC;
    return p;
}

EXTERN_C S_80027FEC *func_80028230(S_80027FEC *p, S_80027FEC *q)
{
    func_80027FEC(p, q);
    return q;
}

EXTERN_C void func_80028258(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C void *func_80028278(void *a)
{
    return func_800284D4(operator new(0x50), a);
}

EXTERN_C S_800282AC *func_800282AC(S_800282AC *p)
{
    p->vt = D_80011254;
    void *m = D_800A4554;
    func_8001E03C(m, new S_N3D0(p));
    return p;
}

EXTERN_C int func_80028330()
{
    S_80028330 *o = *(S_80028330 **)&D_800B4C38;
    VEnt *e = &o->vt[1];
    ((void (*)(void *, void *))e->f)((char *)o + e->d, D_800AC6E4);
    return 1;
}

EXTERN_C void func_80028374()
{
    func_8001DEB8(D_800B4C6C, 2);
    func_80020DB0(D_800AC6E4, 2);
}

EXTERN_C void func_800283AC()
{
    S_Vobj4h *o = (S_Vobj4h *)D_800AC6E4;
    D_800B4C64.x = 0;
    D_800B4C64.y = 0;
    D_800B4C68.x = 8;
    D_800B4C68.y = 8;
    o->vtbl = D_80010178;
    o->unk4 = 0;
    o->vtbl = D_800106EC;
    o->unk8 = 0;
    o->unkA = 0;
    o->vtbl = D_80010654;
    func_80021ACC(o, D_800112D4);
    func_800282AC((S_800282AC *)D_800B4C6C);
}
