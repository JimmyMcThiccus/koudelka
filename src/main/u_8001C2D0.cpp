#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_8001C2D0.h"

EXTERN_C S_Vobj *func_8001C2D0(S_Vobj *p)
{
    p->vtbl = D_800101E8;
    return p;
}

EXTERN_C void **func_8001C2E4(void **p, int a)
{
    p[0] = D_800101F8;
    ((int *)p)[1] = a;
    int *o = D_800A4544;
    func_8001D150(o, new S_8001D684b((int)p, 0xC0, 1));
    return p;
}

EXTERN_C void func_8001C36C(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001C38C);

EXTERN_C S_Node *func_8001C580(S_Node *p)
{
    func_800186E8(&D_800A451C);
    S_Node *r = p->next;
    func_8001A744(p, r);
    func_80018788(&D_800A451C);
    return r;
}

EXTERN_C void func_8001C5DC(S_8001C5DC *p, S_8001D6C8 *a, S_8001C5DC *b)
{
    b->unk8 = p->unk8;
    func_800186E8(&D_800A451C);
    func_8001A678((char *)a + 4, (int)b);
    func_80018788(&D_800A451C);
    if (!func_8001D6C8(a))
        func_8001D6E0(a, 1);
}

EXTERN_C int func_8001C658(S_8001C658 *p)
{
    return p->unk4 != 0;
}

EXTERN_C S_Vobj4 *func_8001C664(S_Vobj4 *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800102B0;
    p->unk8 = 0;
    p->unkC = 0;
    p->vtbl = D_800102A0;
    p->unk8 = a;
    return p;
}

EXTERN_C void func_8001C6A0(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_8001C6C0(S_8001C658 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4 *func_8001C6CC(S_Vobj4 *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800102B0;
    p->unk8 = 0;
    p->unkC = a;
    return p;
}

EXTERN_C void func_8001C6F8(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C void *func_8001C718(void *v)
{
    S_Pool14 *p = (S_Pool14 *)v;
    unsigned int bits, mask;
    int i;
loop:
    bits = p->bits;
    if (bits == (unsigned int)-1) {
        p = p->next;
        if (!p)
            p = newpool_8001C718();
        goto loop;
    }
    mask = 1;
    i = 0;
    while (mask & bits) {
        mask <<= 1;
        i++;
    }
    p->bits |= mask;
    return &p->e[i];
}

EXTERN_C void func_8001C7D4(void *v, void *q)
{
    S_Pool14 *p = (S_Pool14 *)v;
    if ((S_Elem14 *)q < p->e) {
        func_8001C7D4(p->next, q);
        return;
    }
    p->bits &= ~(1 << ((S_Elem14 *)q - p->e));
    if (p->bits)
        return;
    if (D_800B4C14 == p)
        return;
    func_8001A744(D_800B4C14, p);
    delete p;
}

EXTERN_C void func_8001C89C(S_VDel *p)
{
    delete p;
}

EXTERN_C void func_8001C8D8(S_8001C8D8 *c, S_8001C8D8 *n)
{
    func_800186E8(&D_800A451C);
    while (1) {
        S_8001C8D8 *a = c->next;
        S_8001C8D8 *nx = a;
        int r = 0;
        if (a)
            r = !(a->key < n->key);
        if (!r)
            break;
        c = nx;
    }
    if (c->next && n)
        func_8001A864((S_Lnk *)n, (S_Lnk *)c->next);
    c->next = n;
    func_80018788(&D_800A451C);
}

EXTERN_C S_Node *func_8001C974(S_Node *p)
{
    func_800186E8(&D_800A451C);
    S_Node *r = p->next;
    func_8001A744(p, r);
    func_80018788(&D_800A451C);
    return r;
}

EXTERN_C void func_8001C9D0()
{
    S_Vobj4 *p = (S_Vobj4 *)operator new(0x28C);
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800102C0;
    p->unk8 = 0;
    D_800B4C14 = p;
}

EXTERN_C void *func_8001CA10(int size)
{
    func_800186E8(&D_800A451C);
    void *r = func_8001C718(D_800B4C14);
    func_80018788(&D_800A451C);
    return r;
}

EXTERN_C void func_8001CA58(void *p, int size)
{
    func_800186E8(&D_800A451C);
    func_8001C7D4(D_800B4C14, p);
    func_80018788(&D_800A451C);
}

EXTERN_C void func_8001CAA4(S_VDel *p)
{
    delete p;
}

EXTERN_C void func_8001CAE0(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C S_8001CDEC *func_8001CB00(int a, int b, short d)
{
    S_8001CDEC *p = (S_8001CDEC *)func_8001CA10(0x14);
    p->vt = D_80010178;
    p->unk4 = 0;
    p->vt = D_80010300;
    p->unk8 = d;
    p->unkA = 2;
    p->unk10 = a;
    p->unkC = b;
    p->vt = D_800102D0;
    return p;
}

EXTERN_C S_8001CDEC *func_8001CB7C(int a, int b, short c, short d)
{
    S_8001CDEC *p = (S_8001CDEC *)func_8001CA10(0x14);
    p->vt = D_80010178;
    p->unk4 = 0;
    p->vt = D_80010300;
    p->unk8 = d;
    p->unkA = c;
    p->unk10 = a;
    p->unkC = b;
    p->vt = D_800102D0;
    return p;
}

EXTERN_C S_8001CDEC *func_8001CC00(int a, int b, short c, short d)
{
    S_8001CDEC *p = (S_8001CDEC *)func_8001CA10(0x14);
    p->vt = D_80010178;
    p->unk4 = 0;
    p->vt = D_80010300;
    p->unk8 = d;
    p->unkA = c;
    p->unk10 = a;
    p->unkC = b;
    p->vt = D_800102D0;
    return p;
}

EXTERN_C S_8001CDEC *func_8001CC84(S_8001CDEC *p, int a, int b, short c, short d)
{
    p->vt = D_80010178;
    p->unk4 = 0;
    p->vt = D_80010300;
    p->unkA = c;
    p->unk10 = a;
    p->unkC = b;
    p->unk8 = d;
    p->vt = D_800102D0;
    return p;
}

EXTERN_C void func_8001CCC8(void *p, int flags)
{
    func_8001A610(p, 0);
    if (flags & 1)
        func_8001CA58(p, 0x14);
}

EXTERN_C int func_8001CD10(S_8001CD10 *p)
{
    return p->unkC;
}

EXTERN_C int func_8001CD1C(S_8001CD10 *p)
{
    return p->unk4 != 0;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800100C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800100D0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800100E0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800100F8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010108);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010118);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010130);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010148);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010160);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010178);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010198);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800101B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800101C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800101D8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800101E8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800101F8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010210);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010260);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010278);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010288);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800102A0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800102B0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800102C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800102D0);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001CD28);

EXTERN_C int func_8001CD6C(S_8001CD10 *p)
{
    return p->unk4;
}

EXTERN_C void func_8001CD78(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C int func_8001CD98(S_8001CD10 *p)
{
    return p->unkC;
}

EXTERN_C int func_8001CDA4(S_8001CD10 *p)
{
    return p->unkC;
}

EXTERN_C int func_8001CDB0(S_8001CD10 *p)
{
    return p->unkC;
}

EXTERN_C int func_8001CDBC(S_8001CD10 *p)
{
    return p->unk8;
}

EXTERN_C int func_8001CDC8(S_8001CD10 *p)
{
    return p->unkA;
}

EXTERN_C int func_8001CDD4(S_8001CD10 *p)
{
    return p->unk10;
}

EXTERN_C int func_8001CDE0(S_8001CD10 *p)
{
    return p->unk4;
}

EXTERN_C S_8001CDEC *func_8001CDEC(S_8001CDEC *p, int a, int b, short c, short d)
{
    p->vt = D_80010178;
    p->unk4 = 0;
    p->vt = D_80010300;
    p->unkA = c;
    p->unk10 = a;
    p->unkC = b;
    p->unk8 = d;
    return p;
}

EXTERN_C S_8001CDEC *func_8001CE24(S_8001CDEC *p, int a, int b, short d)
{
    p->vt = D_80010178;
    p->unk4 = 0;
    p->vt = D_80010300;
    p->unk8 = d;
    p->unkA = 2;
    p->unk10 = a;
    p->unkC = b;
    return p;
}

EXTERN_C S_8001CDEC *func_8001CE5C(S_8001CDEC *p, int a, int b, short c, short d)
{
    p->vt = D_80010178;
    p->unk4 = 0;
    p->vt = D_80010300;
    p->unkA = c;
    p->unk10 = a;
    p->unkC = b;
    p->unk8 = d;
    return p;
}

EXTERN_C S_Vobj4 *func_8001CE94(S_Vobj4 *p)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_80010300;
    return p;
}

EXTERN_C void func_8001CEB8(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C S_Lnk *func_8001CED8(S_Lnk *head, S_Lnk *n)
{
    if (n < head) {
        n->next = head;
        return n;
    }
    S_Lnk *c = head;
    while (1) {
        if (!(c->next < n))
            break;
        c = c->next;
    }
    if (c->next && n)
        func_8001A864(n, c->next);
    c->next = n;
    return head;
}

EXTERN_C S_Lnk *func_8001CF68(S_Lnk *head, S_Lnk *n)
{
    if (head < n) {
        n->next = head;
        return n;
    }
    S_Lnk *c = head;
    while (1) {
        if (!(n < c->next))
            break;
        c = c->next;
    }
    if (c->next && n)
        func_8001A864(n, c->next);
    c->next = n;
    return head;
}

EXTERN_C int func_8001CFF8(S_8001CFF8 *p)
{
    return p->unk4;
}

EXTERN_C void func_8001D004(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C void func_8001D024(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_80010348;
    func_800198AC(p, a);
}

EXTERN_C void func_8001D04C(S_8001D04C *p, int flags)
{
    p->vt = D_80010338;
    if (p->unk10) {
        func_80018788(&D_800A451C);
        delete p->unk8;
        func_800186E8(&D_800A451C);
    }
    func_8001A610(p, flags);
}

EXTERN_C S_Node *func_8001D0E4(S_Node *p, int key)
{
    func_800186E8(&D_800A451C);
    while (1) {
        if (!p || p->key == key)
            break;
        p = p->next;
    }
    func_80018788(&D_800A451C);
    return p;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D150);

EXTERN_C S_Node *func_8001D25C(void *v, int key)
{
    func_800186E8(&D_800A451C);
    S_Node *r = ((S_Node *)v)->next ? func_8001D0E4(((S_Node *)v)->next, key) : 0;
    func_80018788(&D_800A451C);
    return r;
}

EXTERN_C int func_8001D2C0(S_Node *p, int a)
{
    func_800186E8(&D_800A451C);
    int r = p->next ? func_8001A6A8(p->next, a) : 0;
    func_80018788(&D_800A451C);
    return r;
}

EXTERN_C void func_8001D324(void *v, S_Node *q)
{
    S_Node *p = (S_Node *)v;
    func_800186E8(&D_800A451C);
    if (p->next && q) {
        p->next = (S_Node *)func_8001A744(p->next, q);
        delete (S_VDel *)q;
    }
    func_80018788(&D_800A451C);
}

EXTERN_C void func_8001D3A8(S_8001D3A8 *list)
{
    S_8001D3A8_N *n, *nx;
    func_800186E8(&D_800A451C);
    for (n = list->next; n; n = nx) {
        func_80018788(&D_800A451C);
        int r = n->unk8->f1();
        func_800186E8(&D_800A451C);
        nx = n->next;
        if (r) {
            list->next = (S_8001D3A8_N *)func_8001A744(list->next, n);
            delete n;
        }
    }
    func_80018788(&D_800A451C);
}

EXTERN_C void func_8001D490(void *p, int key)
{
    func_8001D324(p, func_8001D25C(p, key));
}

EXTERN_C void func_8001D4C0(void *self, int a, short b, int c)
{
    S_8001D684 *p = (S_8001D684 *)operator new(0x14);
    p->vt = D_80010178;
    p->unk4 = 0;
    p->vt = D_80010338;
    p->unk8 = a;
    p->unkC = b;
    p->unk10 = c;
    func_8001D150(self, p);
}

EXTERN_C void func_8001D540(S_Node *p, int flags)
{
    p->vt = D_80010328;
    delete (S_VDel *)p->next;
    func_800198AC(p, flags);
}

EXTERN_C S_8001A294 *func_8001D5A8(S_8001A294 *p)
{
    p->vtbl = D_80010328;
    p->unk4 = 0;
    return p;
}

EXTERN_C int func_8001D5C0(S_8001D5C0 *p)
{
    func_80018788(&D_800A451C);
    int r = p->unk8->f1();
    func_800186E8(&D_800A451C);
    return r;
}

EXTERN_C int func_8001D62C(S_8001D62C *p)
{
    return p->unk10;
}

EXTERN_C void func_8001D638(S_8001D62C *p, int v)
{
    p->unk10 = v;
}

EXTERN_C int func_8001D640(S_8001D62C *p)
{
    return p->unkC;
}

EXTERN_C int func_8001D64C(S_8001D62C *p)
{
    return p->unk8;
}

EXTERN_C void func_8001D658(void *p, int a)
{
    func_8001A6A8(p, a);
}

EXTERN_C int func_8001D678(S_8001D62C *p)
{
    return p->unk4;
}

EXTERN_C S_8001D684 *func_8001D684(S_8001D684 *p, int a, short b, int c)
{
    p->vt = D_80010178;
    p->unk4 = 0;
    p->vt = D_80010338;
    p->unk8 = a;
    p->unkC = b;
    p->unk10 = c;
    return p;
}

EXTERN_C S_Vobj *func_8001D6B4(S_Vobj *p)
{
    p->vtbl = D_80010348;
    return p;
}

EXTERN_C bool func_8001D6C8(S_8001D6C8 *p)
{
    return D_800A4534.unkC < p->unk14;
}

EXTERN_C void func_8001D6E0(S_8001D6C8 *p, int a)
{
    unsigned int t = D_800A4534.unkC;
    p->unk18 = t;
    p->unk14 = t + a;
}

EXTERN_C void func_8001D700(S_8001D6C8 *p, int a)
{
    unsigned int t = D_800A4534.unkC;
    p->unk14 = t;
    p->unk18 = t + a;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010300);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010328);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010338);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010348);

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D720);

EXTERN_C void func_8001D76C(void *p, int flags)
{
    func_8001A610((char *)p + 4, 2);
    func_8001D024(p, flags);
}

C_8001D7B0::C_8001D7B0() : B_8001E40C(0, 1, 0x400, 0)
{
    vtF8 = D_80010328;
    vt100 = D_80010348;
    vt8C = D_80010388;
    vtF8 = D_80010378;
    vt100 = D_800103A0;
    vt = D_800103B8;
    unkFC = 0;
    unk104 = 0;
    unk108 = 0;
    char *q = (char *)&vt100;
    char *b = this ? q : 0;
    int *o = D_800A4544;
    func_8001D150(o, new S_8001D684b((int)b, 0x80, 0));
}

EXTERN_C void func_8001D8A4(S_8001D8A4 *p)
{
    S_8001D3A8_N *n;
    func_800186E8(&D_800A451C);
    n = 0;
    if (p->list) {
        if (p->cur && func_8001A6A8(p->list, (int)p->cur))
            n = p->cur;
        else if (p->nxt && func_8001A6A8(p->list, (int)p->nxt))
            n = p->nxt;
        else
            n = p->list;
    }
    if (n) {
        func_80018788(&D_800A451C);
        int r = n->unk8->f1();
        func_800186E8(&D_800A451C);
        S_8001D3A8_N *nx = n->next;
        p->cur = nx;
        if (nx)
            p->nxt = nx->next;
        if (r) {
            p->list = (S_8001D3A8_N *)func_8001A744(p->list, n);
            delete n;
        }
    }
    func_80018788(&D_800A451C);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001D9F4);

EXTERN_C void func_8001DB04()
{
    char *o = (char *)&D_800AC57C;
    *(void ***)(o + 0x8C) = D_80010388;
    *(void ***)(o + 0xF8) = D_80010378;
    *(void ***)(o + 0x100) = D_800103A0;
    *(void ***)&D_800AC57C = D_800103B8;
    func_8001D024(o + 0x100, 0);
    S_Own2 *m = (S_Own2 *)(o + 0xF8);
    m->vt = D_80010328;
    delete m->ptr;
    func_800198AC(m, 0);
    func_8001E508(o, 2);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001C2D0", func_8001DBB8);

EXTERN_C void func_8001DDD0()
{
    new (&D_800AC57C) C_8001D7B0;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010378);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_80010388);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800103A0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800103B8);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800103D0);

INCLUDE_RODATA("asm/main/nonmatchings/u_8001C2D0", D_800103E0);
