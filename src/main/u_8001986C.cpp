#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_8001986C.h"

EXTERN_C void func_8001986C(void *p, int a)
{
    func_8001D024(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", printf);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019894);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", puts);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_800198A4);

EXTERN_C void func_800198AC(void *p, int a)
{
    *(void ***)p = D_800100F8;
    if (a & 1)
        operator delete(p);
}

EXTERN_C void *func_800198E0(void *v, int n, int grow)
{
    S_Array *a = (S_Array *)v;
    a->grow = grow;
    a->cap = n;
    a->count = 0;
    a->unk10 = 0;
    a->data = (int *)func_800A0D2C(n * 4);
    return a;
}

EXTERN_C void func_80019920(List *l, int flags)
{
    S_Array *a = (S_Array *)l;
    if (a->data)
        func_800A0D0C(a->data);
    if (flags & 1)
        operator delete(a);
}

EXTERN_C void func_80019974(S_Array *a, int n)
{
    if (a->cap < n) {
        int c = a->grow ? a->cap + a->grow : a->cap * 2;
        if (c < n)
            c = n;
        int *d = (int *)func_800A0D2C(c * 4);
        func_8001A8F0(d, (int)a->data, a->count);
        if (a->data)
            func_800A0D0C(a->data);
        a->data = d;
        a->cap = c;
    }
}

EXTERN_C int func_80019A18(S_80019A18 *p, int v)
{
    int old = p->unk10;
    p->unk10 = v;
    return old;
}

EXTERN_C void func_80019A24(S_Array *a, int v, int i)
{
    if (i < 0)
        i += a->count;
    if (i < a->count && i >= 0)
        a->data[i] = v;
}

EXTERN_C void func_80019A6C(void *p, int v, int i)
{
    S_Array *a = (S_Array *)p;
    if (i < 0)
        i += a->count;
    if (i <= a->count && i >= 0 && !a->unk10) {
        func_80019974(a, a->count + 1);
        func_8001A970(&a->data[i] + 1, &a->data[i], a->count - i);
        a->data[i] = v;
        a->count++;
    }
}

EXTERN_C int func_80019B2C(void *p, int v, int i)
{
    S_Array *a = (S_Array *)p;
    if (i < 0) {
        i += a->count;
        if (i < 0)
            return -1;
    }
    int n = a->count;
    for (; i < n; i++)
        if (v == a->data[i])
            return i;
    return -1;
}

EXTERN_C int func_80019BA0(S_Array *a, int v, int i)
{
    if (i < 0) {
        i += a->count;
        if (i < 0)
            return -1;
    }
    if (i >= a->count)
        i = a->count - 1;
    for (i--; i != -1; i--)
        if (v == a->data[i])
            return i;
    return -1;
}

EXTERN_C int func_80019C24(S_Array *a, int v)
{
    int i;
    for (i = 0; i < a->count; i++)
        if (v == a->data[i])
            return 1;
    return 0;
}

EXTERN_C int func_80019C68(void *p, int i)
{
    S_Array *a = (S_Array *)p;
    if (i < 0)
        i += a->count;
    if (i < a->count && i >= 0 && !a->unk10) {
        int r = a->data[i];
        func_8001A8F0(&a->data[i], (int)(&a->data[i] + 1), a->count - i - 1);
        a->count--;
        return r;
    }
    return 0;
}

EXTERN_C int func_80019CFC(S_Array *a, int v)
{
    int i = func_80019B2C(a, v, 0);
    if (i < 0)
        return 0;
    return func_80019C68(a, i);
}

EXTERN_C void func_80019D40(S_80019D40 *p)
{
    if (p->unk10 == 0)
        p->unk4 = 0;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_80019D5C);

EXTERN_C int func_80019F0C(S_Array *a, int v, int x)
{
    int i = func_80019B2C(a, v, 0);
    if (i < 0)
        return 0;
    func_80019D5C(a, i, x, 1);
    return 1;
}

EXTERN_C Item *func_80019F64(List *l, int i)
{
    S_Array *a = (S_Array *)l;
    if (i < 0)
        i += a->count;
    if (i >= a->count || i < 0)
        return 0;
    return (Item *)a->data[i];
}

EXTERN_C int func_80019FB4(S_80019FB4 *p)
{
    return p->unk4;
}

EXTERN_C int func_80019FC0(S_ArrayIt *it)
{
    if (it->idx < it->arr->count)
        return (int)func_80019F64((List *)it->arr, it->idx++);
    return 0;
}

EXTERN_C void func_8001A00C(S_80019FB4 *p, int v)
{
    p->unk8 = v;
}

EXTERN_C S_8001A014 *func_8001A014(S_8001A014 *p, int a, int b)
{
    p->vt = D_80010108;
    p->a = a;
    p->b = b;
    return p;
}

EXTERN_C void func_8001A030(void *p, int a)
{
    func_800198AC(p, a);
}

EXTERN_C int func_8001A050(S_Array *a)
{
    return a->count ? a->data[a->count - 1] : 0;
}

EXTERN_C int func_8001A080(S_8001A080 *p)
{
    return p->unk4 ? *p->unk0 : 0;
}

EXTERN_C void func_8001A0AC(void *p, int a)
{
    func_80019A6C(p, a, 0);
}

EXTERN_C void func_8001A0CC(S_8001A080 *p, int a)
{
    func_80019A6C(p, a, p->unk4);
}

EXTERN_C void func_8001A0F0(S_8001A080 *p, int a)
{
    func_80019A6C(p, a, p->unk4);
}

EXTERN_C int func_8001A114(S_8001A114 *p)
{
    return p->unk8;
}

EXTERN_C int func_8001A120(S_8001A114 *p)
{
    return p->unk4 == 0;
}

EXTERN_C int func_8001A12C(S_8001A114 *p)
{
    return p->unk4;
}

EXTERN_C int func_8001A138(S_8001A138 *p)
{
    if (--p->unk8 <= 0) {
        p->unk4->run(p);
        return 1;
    }
    return 0;
}

EXTERN_C void func_8001A1A0(int a)
{
    Obj_800AC57C *o = &D_800AC57C;
    void *b = o ? (char *)o + 0xF8 : 0;
    func_8001D150(b, new S_8001D684(a, 0x80, 1));
}

EXTERN_C void func_8001A220(int a)
{
    int *o = D_800A4544;
    func_8001D150(o, new S_8001D684(a, 0x80, 1));
}

EXTERN_C S_8001A294 *func_8001A294(S_8001A294 *p, int a, int b)
{
    p->vtbl = D_80010118;
    p->unk4 = a;
    p->unk8 = b;
    return p;
}

EXTERN_C void func_8001A2B0(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C int func_8001A2D0(S_8001A2D0 *p)
{
    S_8001A2D0_N *c = p->unk8;
    if (!c)
        return 1;
    if (p->unk4) {
        p->unk4--;
    } else {
        p->unk8 = c->next;
        c->next = 0;
        delete c;
        return p->unk8 == 0;
    }
    return 0;
}

EXTERN_C int func_8001A354(S_8001A2D0 *p)
{
    if (p->unk4) {
        p->unk4--;
    } else {
        delete p->unk8;
        return 1;
    }
    return 0;
}

EXTERN_C S_8001A3BC *func_8001A3BC(S_8001A3BC *p, int a, int b)
{
    p->vt = D_80010160;
    p->unk4 = b;
    Obj_800AC57C *o = &D_800AC57C;
    void *base = o ? (char *)o + 0xF8 : 0;
    func_8001D150(base, new S_8001D684((int)p, 0x80, 1));
    p->vt = D_80010130;
    p->unk8 = a;
    return p;
}

EXTERN_C void func_8001A46C(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C S_8001A3BC *func_8001A48C(S_8001A3BC *p, int a, int b)
{
    p->vt = D_80010160;
    p->unk4 = b;
    Obj_800AC57C *o = &D_800AC57C;
    void *base = o ? (char *)o + 0xF8 : 0;
    func_8001D150(base, new S_8001D684((int)p, 0x80, 1));
    p->vt = D_80010148;
    p->unk8 = a;
    return p;
}

EXTERN_C void func_8001A53C(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C S_8001A3BC *func_8001A55C(S_8001A3BC *p, int b)
{
    p->vt = D_80010160;
    p->unk4 = b;
    Obj_800AC57C *o = &D_800AC57C;
    void *base = o ? (char *)o + 0xF8 : 0;
    func_8001D150(base, new S_8001D684((int)p, 0x80, 1));
    return p;
}

EXTERN_C void func_8001A5F0(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C void func_8001A610(void *v, int flags)
{
    S_8001A610 *p = (S_8001A610 *)v;
    p->vt = D_80010178;
    delete p->unk4;
    func_800198AC(p, flags);
}

EXTERN_C int func_8001A678(void *v, int a)
{
    S_Link *p = (S_Link *)v;
    if (!a)
        return 0;
    while (p->next)
        p = p->next;
    p->next = (S_Link *)a;
    return a;
}

EXTERN_C int func_8001A6A8(void *v, int a)
{
    S_Link *p = (S_Link *)v;
    if (!a)
        return 0;
    while (p) {
        if (p == (S_Link *)a)
            return 1;
        p = p->next;
    }
    return 0;
}

EXTERN_C int func_8001A6E8(S_8001A6E8 *p)
{
    int n = 0;
    while (p) {
        p = p->unk4;
        n++;
    }
    return n;
}

EXTERN_C S_Link *func_8001A708(S_Link *p, S_Link *a)
{
    if (!a)
        return 0;
    for (S_Link *q = p; q->next; q = q->next)
        if (q->next == a)
            return q;
    return 0;
}

EXTERN_C S_Link *func_8001A744(S_Link *head, S_Link *n)
{
    if (n) {
        S_Link *prev;
        if (head == n) {
            prev = head->next;
            head->next = 0;
            return prev;
        }
        prev = func_8001A708(head, n);
        if (prev) {
            prev->next = n->next;
            n->next = 0;
        }
    }
    return head;
}

EXTERN_C S_Link *func_8001A7B4(S_Link *list, S_8001A7B4_P *pred)
{
    S_Link *head = list;
    S_Link *r = 0;
    for (S_Link *cur = head; cur; ) {
        S_Link *nxt = r ? 0 : cur->next;
        r = pred->test(r, cur);
        if (r)
            cur = r->next;
        else
            cur = head = nxt;
    }
    return head;
}

EXTERN_C void func_8001A844(void *p, int a)
{
    func_8001A678(p, a);
}

EXTERN_C S_Link *func_8001A864(S_Link *p, S_Link *a)
{
    if (p->next && a)
        func_8001A864(a, p->next);
    p->next = a;
    return a;
}

EXTERN_C int func_8001A8B8(S_8001A8B8 *p, int v)
{
    p->unk4 = v;
    return v;
}

EXTERN_C void func_8001A8C4(S_8001A8B8 *p)
{
    p->unk4 = 0;
}

EXTERN_C int func_8001A8CC(S_8001A8B8 *p)
{
    return p->unk4;
}

EXTERN_C S_8001A294 *func_8001A8D8(S_8001A294 *p)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    return p;
}

EXTERN_C void *func_8001A8F0(void *dst, int src, int n)
{
    int *d = (int *)dst;
    int *s = (int *)src;
    unsigned int k;
    int a, b, c, e;
    k = (unsigned int)n >> 2;
    while (k) {
        a = s[0];
        b = s[1];
        c = s[2];
        e = s[3];
        s += 4;
        k--;
        d[0] = a;
        d[1] = b;
        d[2] = c;
        d[3] = e;
        d += 4;
    }
    k = n & 3;
    while (k) {
        *d++ = *s++;
        k--;
    }
    return dst;
}

EXTERN_C void *func_8001A970(void *dst, void *src, int n)
{
    int *d;
    int *s;
    unsigned int k;
    int a, b, c, e;
    if ((int *)src < (int *)dst && (int *)dst < (int *)src + n) {
        d = (int *)dst + n;
        s = (int *)src + n;
        k = (unsigned int)n >> 2;
        while (k) {
            s -= 4;
            d -= 4;
            a = s[0];
            b = s[1];
            c = s[2];
            e = s[3];
            k--;
            d[0] = a;
            d[1] = b;
            d[2] = c;
            d[3] = e;
        }
        k = n & 3;
        while (k) {
            d--;
            s--;
            *d = *s;
            k--;
        }
        return dst;
    }
    return func_8001A8F0(dst, (int)src, n);
}

EXTERN_C int *func_8001AA28(int *p, int n)
{
    int *q = p;
    while (n--)
        *q++ = 0;
    return p;
}

EXTERN_C S_Vobj *func_8001AA54(S_Vobj *p)
{
    p->vtbl = D_80010198;
    return p;
}

EXTERN_C void func_8001AA68(S_8001AA68 *p, void *q)
{
    if (!p->unk8)
        return;
    int a = p->unkC;
    void *o = q;
    if (!q)
        o = p;
    unsigned short b = p->unk10;
    unsigned short c = p->unk12;
    S_8001AA68_N *n = (S_8001AA68_N *)func_8001CA10(0x14);
    n->vt = D_80010178;
    n->unk4 = 0;
    n->vt = D_80010300;
    n->unk10 = a;
    n->unkC = o;
    n->vt = D_800102D0;
    n->unk8 = c;
    n->unkA = b;
    func_8001EFE4(p->unk8, n);
    if (q)
        delete (S_VDel *)p;
}

EXTERN_C void func_8001AB50(S_8001AA68 *p, void *q)
{
    if (!p->unk8)
        return;
    int a = p->unkE;
    void *o = q;
    if (!q)
        o = p;
    unsigned short b = p->unk10;
    unsigned short c = p->unk12;
    S_8001AA68_N *n = (S_8001AA68_N *)func_8001CA10(0x14);
    n->vt = D_80010178;
    n->unk4 = 0;
    n->vt = D_80010300;
    n->unk10 = a;
    n->unkC = o;
    n->vt = D_800102D0;
    n->unk8 = c;
    n->unkA = b;
    func_8001EFE4(p->unk8, n);
    if (q)
        delete (S_VDel *)p;
}

EXTERN_C S_8001AC38 *func_8001AC38(S_8001AC38 *p, int a, short b, short c, short d, short e)
{
    p->vt = D_800100F8;
    p->vt4 = D_800101C0;
    p->vt = D_800101B0;
    p->unk8 = a;
    p->unkC = b;
    p->unkE = c;
    p->unk10 = d;
    p->unk12 = e;
    return p;
}

EXTERN_C void func_8001AC80(void *p, int a)
{
    ((void ***)p)[1] = D_800101C0;
    ((void ***)p)[0] = D_800101B0;
    func_800198AC(p, a);
}

EXTERN_C void func_8001ACB4()
{
    D_800B4C04 = func_8001ACDC(operator new(0x4008));
}

EXTERN_C void *func_8001ACDC(void *v)
{
    S_8001ACDC *p = (S_8001ACDC *)v;
    p->vt = D_80010178;
    p->unk4 = 0;
    p->vt = D_800101D8;
    p->unk8 = 1;
    p->unkA = 0;
    p->unkC = 0;
    p->unkE = 0xFFF;
    return p;
}

EXTERN_C void func_8001AD18(S_Heap *h, S_HeapE *b)
{
    if (b + b->size == &h->e[b->next]) {
        b->size += h->e[b->next].size;
        b->next = h->e[b->next].next;
    }
}

EXTERN_C void func_8001AD68(S_Heap *h)
{
    if (h->e[1].size == 0xFFF) {
        D_800B4C04 = func_8001A744((S_Link *)D_800B4C04, (S_Link *)h);
        if (D_800B4C04)
            delete (S_VDel *)h;
        else
            D_800B4C04 = h;
    }
}

EXTERN_C void func_8001ADE0(S_Heap *h, S_HeapE *p)
{
    S_HeapE *prev, *n;
    if (p <= h->e) {
        if (h->unk4) {
            func_8001ADE0((S_Heap *)h->unk4, p);
            return;
        }
        func_80018C1C(p);
        return;
    }
    if ((S_HeapE *)((char *)h + 0x4008) < p) {
        func_80018C1C(p);
        return;
    }
    p--;
    prev = h->e;
    if (prev->next) {
        do {
            n = &h->e[prev->next];
            if (p < n) {
                link_8001ADE0(h, p, n);
                link_8001ADE0(h, prev, p);
                func_8001AD68(h);
                return;
            }
            prev = n;
        } while (prev->next);
    }
    p->next = 0;
    link_8001ADE0(h, prev, p);
    func_8001AD68(h);
}

EXTERN_C S_Link *func_8001AEFC(S_Link *head, S_Link *n)
{
    if (head < n) {
        n->next = head;
        return n;
    }
    S_Link *c = head;
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

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001AF8C);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B0C0);

EXTERN_C void *func_8001B134(unsigned int size)
{
    void *r;
    func_800186E8(&D_800A451C);
    r = size > 0xBFFF ? func_80027E30(size) : 0;
    if (!r) {
        if (size >= 0x400)
            r = func_80018C90(size);
        else
            r = func_8001AF8C((S_Heap *)D_800B4C04, size);
    }
    func_80018788(&D_800A451C);
    return r;
}

EXTERN_C void func_8001B1C8(void *p)
{
    func_800186E8(&D_800A451C);
    if ((char *)p < (char *)D_800EA8A0) {
        func_80027FB0(p);
    } else {
        S_Heap *h = (S_Heap *)D_800B4C04;
        while (!above_8001B1C8(h, p))
            h = (S_Heap *)h->unk4;
        if (h)
            func_8001ADE0(h, (S_HeapE *)p);
        else
            func_80018C1C(p);
    }
    func_80018788(&D_800A451C);
}

EXTERN_C void *func_8001B26C(unsigned int size)
{
    void *r;
    func_800186E8(&D_800A451C);
    r = func_80018D80(size);
    if (!r)
        r = func_80018C90(size);
    func_80018788(&D_800A451C);
    return r;
}

EXTERN_C void func_8001B2D8(void *p)
{
    func_8001B0C0(D_800B4C04, p);
}

EXTERN_C int func_8001B300(char *a, char *b)
{
    return a + 8 < b;
}

EXTERN_C int func_8001B30C(S_8001B30C *p)
{
    return p->unk4;
}

EXTERN_C void func_8001B318(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B338);

EXTERN_C void func_8001B394(S_8001B394 *p)
{
    ResetRCnt(0xF2000001);
    if (!p->unk14C && DrawSync(1))
        return;
    if (p->unk150) {
        func_8002D1E0();
        char *g = (char *)D_800A4578[0];
        func_8001EFE4(g ? g + 0x50 : 0, p->unk150);
        p->unk150 = 0;
        p->unk14C = 0;
    }
}

EXTERN_C void func_8001B424()
{
    func_8001C9D0();
    func_8009DDC0(0);
    ResetGraph(0);
    InitGeom();
    InitCARD(0);
    StartCARD();
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B46C);

EXTERN_C int func_8001B8C8(S_Link *p)
{
    if (p->next)
        func_8001B910(D_800A4578[0]);
    else
        func_8001BBBC(D_800A4578[0]);
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001B910);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001BBBC);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001BE20);

INCLUDE_ASM("asm/main/nonmatchings/u_8001986C", func_8001BE9C);

EXTERN_C void func_8001C2AC()
{
    func_8001C2D0((S_Vobj *)&D_800B4C10);
}
