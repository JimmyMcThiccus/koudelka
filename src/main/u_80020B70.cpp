#include "common.h"
#include "shared/vbase.h"
#include "game/a/main_a.h"
#include "game/a/decls_a.h"
#include "game/a/h_u_80020B70.h"

EXTERN_C int func_80020B70(S_80020B70 *p)
{
    return count_of(&p->unk28) == 0;
}

EXTERN_C int func_80020B90(S_80020B90 *p)
{
    return p->unk4;
}

EXTERN_C void func_80020B9C(S_80020B90 *p, int v)
{
    p->unk54 = v;
}

EXTERN_C int func_80020BA4(S_80020B90 *p)
{
    return p->unk52;
}

EXTERN_C void func_80020BB0(S_80020B90 *p, int v)
{
    p->unk52 = v;
}

EXTERN_C int func_80020BB8(S_80020B90 *p)
{
    return p->unk50;
}

EXTERN_C void func_80020BC4(S_80020B90 *p, int v)
{
    p->unk50 = v;
}

EXTERN_C int func_80020BCC(S_80020B90 *p)
{
    return p->unk4A;
}

EXTERN_C void func_80020BD8(S_80020B90 *p, int v)
{
    p->unk4A = v;
}

EXTERN_C void func_80020BE0(char *p, int flags)
{
    char *g;
    *(void ***)p = D_800105B4;
    Holder *h;
    g = (char *)&D_800AC6C4;
    h = g ? (Holder *)(g + 8) : 0;
    func_80019CFC(h, p);
    func_80019920(*(List **)(p + 0x28), 0);
    func_80019920(*(List **)(p + 0x8), 0);
    func_800198AC(p, flags);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80020C64);

EXTERN_C void func_80020D24(S_80020D24 *p, int v)
{
    p->unk14 = v;
}

EXTERN_C int func_80020D2C(S_80020D24 *p)
{
    return p->unk14;
}

EXTERN_C int func_80020D38(S_80020D24 *p)
{
    return p->unk4;
}

EXTERN_C S_80020D44 *func_80020D44(S_80020D44 *p, unsigned short a, int b, unsigned short c, int d)
{
    return new (p) S_80020D44(a, b, c, d);
}

EXTERN_C void func_80020D90(void *p, int a)
{
    func_8001A610(p, a);
}

EXTERN_C void func_80020DB0(void *p, int a)
{
    ((S_Obj178 *)p)->vtbl = D_800106EC;
    func_800215E8(D_800B4C38, p);
    func_8001A610(p, a);
}

EXTERN_C S_IdNode *func_80020E00(S_IdNode *n, unsigned short id)
{
    S_IdNode *r;
    if (id == n->unkA)
        return n;
    if (!n->next)
        return 0;
    r = func_80020E00(n->next, id);
    return r;
}

EXTERN_C void func_80020E40(char *p, int flags)
{
    char *b;
    char *l;
    void *o;
    *(void ***)(p + 0xC) = D_800106A4;
    *(void ***)p = D_800106BC;
    b = p ? p + 0xC : 0;
    l = D_800A4544;
    func_8001D324(l, func_8001D25C(l, b));
    o = *(void **)(p + 0x10);
    if (o)
        VCALL(o, 1, Fn_vi, 3);
    func_8001D024(p + 0xC, 0);
    func_80020DB0(p, flags);
}

EXTERN_C void func_80020EF8(S_800210A4 *p, S_Pt4 pos, int a)
{
    char *l = D_800A4544;
    p->unk20 = pos;
    p->unk24 = a;
    if (!func_8001D25C(l, p ? (char *)p + 0xC : 0)) {
        char *b = p ? (char *)p + 0xC : 0;
        func_8001D150(l, new S_Evt338(b, 0xC0, 0));
    }
    ((S_AnimV *)p->unk10)->f2(pos, a);
    p->unk14 = p->unk10;
    p->unk1C = p->unk18;
}

EXTERN_C int func_8002101C(S_Holder10 *p)
{
    S_IdNode *o = p->unk10;
    if (o)
        return VCALL(o, 3, Fn_i);
    return 1;
}

EXTERN_C void func_80021060(S_Holder10 *p)
{
    S_IdNode *o = p->unk10;
    if (o)
        VCALL(o, 4, Fn_v);
}

EXTERN_C int func_800210A4(S_800210A4 *p)
{
    if (--p->unk1C <= 0) {
        p->unk1C = p->unk18;
        if (!(p->unk14 = p->unk14->next))
            p->unk14 = p->unk10;
        ((S_AnimV *)p->unk14)->f2(p->unk20, p->unk24);
    }
    return 0;
}

EXTERN_C S_80021274 *func_80021144(S_80021274 *p)
{
    int i;
    for (i = 15; i >= 0; i--)
        p->unk0[i] = 0;
    p->unk40 = 0;
    return p;
}

EXTERN_C int func_80021168(S_80021274 *p, int x, int excl)
{
    int i;
    int *q;
    if (excl) {
        if (p->unk40)
            return -1;
        p->unk0[0] = x;
        p->unk40 = 17;
        return 0;
    }
    if (p->unk40 < 16) {
        for (i = 0; i < 16; i++)
            if (p->unk0[i] == 0)
                goto found;
        return -1;
    found:
        p->unk0[i] = x;
        p->unk40++;
        return i;
    }
    return -1;
}

EXTERN_C int func_800211F4(S_80021274 *p, int x)
{
    int i;
    int *q;
    int n = p->unk40;
    if (n != 0) {
        if (n > 16) {
            if (x == p->unk0[0]) {
                p->unk0[0] = 0;
                p->unk40 = 0;
                return 1;
            }
        } else {
            for (i = 0; i < 16; i++)
                if (p->unk0[i] == x)
                    goto found;
        }
        return 0;
    found:
        p->unk0[i] = 0;
        p->unk40--;
        return 1;
    }
    return 0;
}

EXTERN_C void func_80021274(S_80021274 *p)
{
    int i;
    for (i = 15; i >= 0; i--)
        p->unk0[i] = 0;
    p->unk40 = 0;
}

EXTERN_C int func_80021294(S_80021274 *p, int x)
{
    int i;
    int n = p->unk40;
    if (n != 0) {
        if (n < 0) {
            if (x == p->unk0[0])
                return 0;
            return -1;
        }
        for (i = 0; i < 16; i++)
            if (p->unk0[i] == x)
                return i;
        return -1;
    }
    return -1;
}

EXTERN_C void func_80021300(int a, int b)
{
    D_800B4C38 = func_80021348(operator new(0x14), a, b);
}

EXTERN_C void *func_80021348(void *q, int a, int b)
{
    int n, i;
    S_80021274 *arr, *s;
#define P ((S_TexPool *)q)
#define R ((S_Rect8 *)a)
    P->unk10 = D_80010694;
    P->r = *R;
    P->unkC = b;
    n = (R->h * R->w) / 256;
    arr = (S_80021274 *)func_800A0D2C(n * sizeof(S_80021274));
    s = arr;
    i = n - 1;
    if (i >= 0) {
        do {
            func_80021144(s);
            i--;
            s++;
        } while (i != -1);
    }
    P->arr = arr;
    return q;
#undef P
#undef R
}

EXTERN_C void func_8002141C(void *q, int flags)
{
    S_Buf2 *p = (S_Buf2 *)q;
    p->unk10 = D_80010694;
    if (p->data)
        func_800A0D0C(p->data);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C int func_80021478(S_SlotTbl2 *t, S_PlaceV *item)
{
    int base = 0;
    int mode = item->f3();
    S_SlotRef r;
    S_SlotRef *rp = &r;
    S_Pt4 p = t->pos;
    while (p.x < t->pos.x + t->unk8) {
        for (r.b = 0; r.b < t->unkA; r.b++) {
            r.a = func_80021168(&t->arr[r.b + base], (int)item, mode) << 4;
            if (r.a >= 0) {
                item->f2(S_Pt4c(r.a + p.x, rp->b + p.y), 0);
                return 1;
            }
        }
        p.x += 0x100;
        base += t->unkA;
    }
    return 0;
}

EXTERN_C void func_800215E8(void *q, void *x)
{
    int base = 0;
    int k = base;
    while (1) {
        int j;
        if (!(k < ((S_SlotTbl *)q)->unk8))
            break;
        for (j = 0; j < ((S_SlotTbl *)q)->unkA; j++)
            if (func_800211F4(&((S_SlotTbl *)q)->arr[j + base], (int)x))
                break;
        k += 0x100;
        base += ((S_SlotTbl *)q)->unkA;
    }
}

EXTERN_C S_SlotRef func_800216A4(S_SlotTbl *t, int x)
{
    S_SlotRef r;
    for (r.b = 0; r.b < t->unkA; r.b++) {
        r.a = func_80021294(&t->arr[r.b], x);
        if (r.a >= 0)
            break;
    }
    return r;
}

EXTERN_C void func_80021764(S_21764 *p, void **ot, int n)
{
    void **cur = &ot[n] - 1;
    if (p->unkC) {
        S_Rect8 r;
        int i;
        r.x = p->unkC->unk8;
        r.y = p->unkC->unkA + p->unkA * (p->unkC->unk18 - 1);
        r.w = p->unk8;
        r.h = p->unkA;
        i = p->unkC->unk18 - 2;
        while (1) {
            void **next;
            if (!i)
                break;
            MoveImage(&r, p->unkC->x, p->unkC->y);
            {
                void **e = (void **)((p->unkC->unk10 + p->unkC->unk14 * i) * 4 + (unsigned long)ot);
                next = (void **)*e;
                func_80098DA0(e);
            }
            i--;
            DrawOTag(cur);
            r.y -= p->unkA;
            cur = next;
        }
        MoveImage(&r, p->unkC->x, p->unkC->y);
    }
    DrawOTag(cur);
}

EXTERN_C void func_800218B4(int a)
{
    D_800B4C38 = new (operator new(0x1C)) S_80022974(a);
}

EXTERN_C int func_8002190C(S_PalTbl *t, S_PlaceV *item)
{
    if (item->f3()) {
        S_SlotRef r;
        for (r.b = 0; r.b < t->unkA; r.b += 2) {
            r.a = func_80021168(&t->arr[r.b], (int)item, 1);
            if (r.a >= 0) {
                item->f2(S_Pt4c(r.a + t->pos.x, r.b + t->pos.y), t->unkC);
                int k = r.b + 1;
                t->unk18 = k;
                t->unk14 = &t->arr[k];
                return 1;
            }
        }
    } else if (t->unk14) {
        S_SlotRef r;
        S_SlotRef *rp = &r;
        r.b = t->unk18;
        r.a = func_80021168(t->unk14, (int)item, 0);
        if (r.a >= 0) {
            item->f2(S_Pt4c(r.a + t->pos.x, rp->b + t->pos.y), t->unkC);
            return 1;
        }
    }
    return 0;
}

EXTERN_C void func_80021ACC(void *p, int a)
{
    ((S_80021ACC *)p)->m = *(S_80021ACC_D *)a;
}

EXTERN_C int func_80021B54()
{
    return 0;
}

EXTERN_C int func_80021B5C(S_Pal *a, S_Pal *b)
{
    int i;
    if (((S_AnimV *)a)->f3() != ((S_AnimV *)b)->f3())
        return 0;
    for (i = 0; i < 16; i++)
        if (a->unkC[i] != b->unkC[i])
            return 0;
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80021C04);

EXTERN_C void func_80021F48(void *p, int a)
{
    ((S_80021F48 *)p)->m = *(S_Clut *)a;
}

EXTERN_C int func_80021FE4()
{
    return 1;
}

EXTERN_C int func_80021FEC(S_Pal *a, S_Pal *b)
{
    int i;
    if (((S_AnimV *)a)->f3() != ((S_AnimV *)b)->f3())
        return 0;
    for (i = 0; i < 256; i++)
        if (a->unkC[i] != b->unkC[i])
            return 0;
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022094);

EXTERN_C int func_80022438(S_Ref *p)
{
    S_Buf *q;
    if (p->unk4)
        p->unk4--;
    else {
        q = p->unk8;
        if (q) {
            if (q->data)
                func_800A0D0C(q->data);
            operator delete(q);
        }
        return 1;
    }
    return 0;
}

EXTERN_C int func_800224A8(S_Ref *p)
{
    S_Buf *q;
    if (p->unk4)
        p->unk4--;
    else {
        q = p->unk8;
        if (q) {
            if (q->data)
                func_800A0D0C(q->data);
            operator delete(q);
        }
        return 1;
    }
    return 0;
}

EXTERN_C void func_80022518(S_Buf *p, int flags)
{
    if (p->data)
        func_800A0D0C(p->data);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C void func_8002256C(S_Buf *p, int flags)
{
    if (p->data)
        func_800A0D0C(p->data);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C S_800225C0 *func_800225C0(S_800225C0 *p, int a, int b)
{
    return new (p) S_800225C0(a, b);
}

EXTERN_C S_Buf *func_80022670(S_Buf *p, int n)
{
    p->data = func_800A0D2C(n << 9);
    return p;
}

EXTERN_C S_800226A0 *func_800226A0(S_800226A0 *p, int a, short b)
{
    return new (p) S_800226A0(a, b);
}

EXTERN_C S_Obj624 *func_800226F8(S_Obj624 *p, short a)
{
    return new (p) S_Obj624(a);
}

EXTERN_C S_80022730 *func_80022730(S_80022730 *p, int a, int b)
{
    return new (p) S_80022730(a, b);
}

EXTERN_C S_Buf *func_800227E0(S_Buf *p, int n)
{
    p->data = func_800A0D2C(n << 5);
    return p;
}

EXTERN_C S_80022810 *func_80022810(S_80022810 *p, int a, short b)
{
    return new (p) S_80022810(a, b);
}

EXTERN_C S_Obj654 *func_80022868(S_Obj654 *p, short a)
{
    return new (p) S_Obj654(a);
}

EXTERN_C void func_800228A0(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C void func_800228C0(void *p, int a)
{
    func_8001D024(p, a);
}

EXTERN_C void func_800228E0(void *p, int a)
{
    func_80020DB0(p, a);
}

EXTERN_C void func_80022900(void *p, int a)
{
    func_80020DB0(p, a);
}

EXTERN_C void func_80022920(S_Buf2 *p, int flags)
{
    p->unk10 = D_80010684;
    if (p->unkC)
        operator delete(p->unkC);
    func_8002141C(p, flags);
}

EXTERN_C S_80022974 *func_80022974(S_80022974 *p, int a)
{
    return new (p) S_80022974(a);
}

EXTERN_C int func_800229B0(S_800229B0 *p)
{
    if (p->unk10 == 0) {
        return 0;
    } else {
        return p->unk10->unk8;
    }
}

EXTERN_C S_IdNode *func_800229D4(S_Holder10 *p, unsigned short id)
{
    if (p->unk10)
        return func_80020E00(p->unk10, id);
    return 0;
}

EXTERN_C int func_80022A04(S_80022A04 *p)
{
    return p->unk10;
}

EXTERN_C int func_80022A10(S_80022A04 *p)
{
    return p->unk10;
}

EXTERN_C S_80022A1C *func_80022A1C(S_80022A1C *p, int a, int b)
{
    return new (p) S_80022A1C(a, b);
}

EXTERN_C int func_80022A70(S_80022A04 *p)
{
    return p->unk8;
}

EXTERN_C int func_80022A7C(S_80022A04 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4h *func_80022A88(S_Vobj4h *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_800106EC;
    p->unk8 = 0;
    p->unkA = a;
    return p;
}

EXTERN_C S_80022AB4 *func_80022AB4(S_80022AB4 *p, S_Rect8 *r, S_Pt4 *q, int c, int d, int e)
{
    return new (p) S_80022AB4(r, q, c, d, e);
}

EXTERN_C void *func_80022B24(S_HTbl *t, S_KeyV *k)
{
    unsigned int h = k->hash() % t->count;
    S_HNode *n;
    for (n = t->data[h]; n; n = n->next) {
        if (k->eq(n->unk8)) {
            void *v;
            t->data[h] = (S_HNode *)func_8001A744(t->data[h], n);
            v = n->unk8;
            VCALL(n, 1, Fn_vi, 3);
            return v;
        }
    }
    return 0;
}

EXTERN_C void *func_80022C34(S_HTbl *t, S_KeyV *k)
{
    S_HNode *n = t->data[k->hash() % t->count];
    while (n) {
        if (k->eq(n->unk8))
            return n->unk8;
        n = n->next;
    }
    return 0;
}

EXTERN_C S_IntVec *func_80022CF0(S_IntVec *p, unsigned int n)
{
    unsigned int i;
    p->vtbl = D_80010714;
    p->count = n;
    p->data = (int *)func_800A0D2C(n * 4);
    for (i = 0; i < n; i++)
        p->data[i] = 0;
    return p;
}

EXTERN_C void func_80022D64(S_IntVec *p, int flags)
{
    unsigned int i;
    void *o;
    p->vtbl = D_80010714;
    for (i = 0; i < p->count; i++) {
        o = (void *)p->data[i];
        if (o)
            VCALL(o, 1, Fn_vi, 3);
    }
    if (p->data)
        func_800A0D0C(p->data);
    if (flags & 1)
        operator delete(p);
}

EXTERN_C void *func_80022E28(S_HTbl *t, S_KeyV *k)
{
    unsigned int h = k->hash() % t->count;
    S_HNode *n;
    for (n = t->data[h]; n; n = n->next)
        if (k->eq(n->unk8))
            return n->unk8;
    {
        S_HNode *o = (S_HNode *)new S_HNode734(k);
        S_HNode *head = t->data[h];
        if (o->next && head)
            func_8001A864(head, o->next);
        o->next = head;
        t->data[h] = o;
    }
    return 0;
}

EXTERN_C int func_80022F64(S_80022F64 *p)
{
    return p->unk4;
}

EXTERN_C S_Vobj4 *func_80022F70(S_Vobj4 *p, int a)
{
    p->vtbl = D_80010178;
    p->unk4 = 0;
    p->vtbl = D_80010734;
    p->unk8 = a;
    return p;
}

EXTERN_C void func_80022F98(void *p, int a)
{
    func_8001A610(p, a);
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80022FB8);

EXTERN_C void func_800230E8(char *p, int a)
{
    void *t = 0;
    int ok = 0;
    if (!*(signed char *)(p + 0x9C) && !*(signed char *)(p + 0xC0)) {
        Holder *h = (Holder *)(p + 0x28);
        if (count_of(h)) {
            char *m = p + 0x28;
            Holder *h8 = m ? (Holder *)(p + 0x30) : 0;
            List *l = h8;
            t = S_first(l);
            if (t)
                ok = 1;
        }
    }
    if (ok) {
        unsigned int k = (*(unsigned int *)(p + 0x9C) >> 12) & 0xF;
        if (k >= 4 && (k < 6 || k == 7)) {
            S_C588n *o = new S_C588n(p, ~*(unsigned short *)(p + 0x9E));
            func_8001EFE4(t, new (func_8001CA10(0x14)) S_Evt2D0b(2, 4, o));
        }
    }
    func_80020984(p, a);
}

EXTERN_C int func_800232A0(char *p)
{
    void *t = 0;
    int r = func_800209F4(p);
    int ok = 0;
    if (!*(signed char *)(p + 0x9C) && !*(signed char *)(p + 0xC0)) {
        Holder *h = (Holder *)(p + 0x28);
        if (count_of(h)) {
            char *m = p + 0x28;
            Holder *h8 = m ? (Holder *)(p + 0x30) : 0;
            List *l = h8;
            t = S_first(l);
            if (t)
                ok = 1;
        }
    }
    if (ok) {
        unsigned int k = (*(unsigned int *)(p + 0x9C) >> 12) & 0xF;
        if (k >= 4 && (k < 6 || k == 7)) {
            S_C588m *o = new S_C588m(p, *(unsigned short *)(p + 0x9E));
            func_8001EFE4(t, new (func_8001CA10(0x14)) S_Evt2D0b(2, 4, o));
        }
    }
    return r;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80023450);

EXTERN_C void func_8002385C(char *p)
{
    Holder *h = (Holder *)(p + 0x28);
    if (count_of(h)) {
        void *e = func_80023450(p);
        if (e) {
            char *m = p + 0x28;
            Holder *h8 = m ? (Holder *)(p + 0x30) : 0;
            List *l = h8;
            void *tg = l->count ? *(void **)*(void ***)l : 0;
            if (tg)
                func_8001EFE4(tg, new (func_8001CA10(0x14)) S_Evt2D0b(2, 4, e));
            else if (e)
                VCALL(e, 1, Fn_vi, 3);
        }
    }
}

EXTERN_C void func_80023988(char *p, int a)
{
    func_8001A8F0(p + 0x108, a, 0x20);
}

EXTERN_C int func_800239AC(S_800239AC *p, int v)
{
    int old = p->unk104;
    p->unk104 = v;
    return old;
}

EXTERN_C void *func_800239B8(S_800239AC *p)
{
    return &p->unk108;
}

EXTERN_C int func_800239C0(S_800239C0 *p)
{
    int r = 0;
    if (!p->unk9C)
        r = p->unkC0 == 0;
    return r;
}

EXTERN_C int func_800239E4(S_800239AC *p)
{
    return p->unk106;
}

EXTERN_C int func_800239F0()
{
    return 0x24;
}

EXTERN_C void *func_800239F8(S_800239AC *p)
{
    return &p->unk9C;
}

EXTERN_C void func_80023A00(S_80023A24 *p)
{
    D_800B4C3C &= ~(1 << p->unk106);
}

EXTERN_C void func_80023A24(S_80023A24 *p)
{
    D_800B4C3C |= 1 << p->unk106;
}

EXTERN_C void func_80023A44()
{
    D_800B4C40 = func_800A1B9C() != 0;
}

EXTERN_C void func_80023A68()
{
    PadEnableCom(0);
}

EXTERN_C void func_80023A88()
{
    PadEnableCom(D_800B4C3C);
}

EXTERN_C void func_80023AAC()
{
    PadStopCom();
}

EXTERN_C void func_80023ACC()
{
    PadStartCom();
}

EXTERN_C void func_80023AEC(char *p, int flags)
{
    char *g;
    Holder *h;
    *(void ***)(p + 0x58) = D_8001075C;
    *(void ***)p = D_80010774;
    func_80023C40(p + 0x58, 0);
    *(void ***)p = D_800105B4;
    g = (char *)&D_800AC6C4;
    h = g ? (Holder *)(g + 8) : 0;
    func_80019CFC(h, p);
    func_80019920(*(List **)(p + 0x28), 0);
    func_80019920(*(List **)(p + 0x8), 0);
    func_800198AC(p, flags);
}

EXTERN_C S_80023B94 *func_80023B94(S_80023B94 *p, int a)
{
    p->unk24 = a;
    p->vtbl = D_8001079C;
    p->unk25 = 0;
    p->unk26 = 0;
    p->unk27 = 0;
    p->unk28 = p->data;
    func_800198E0(p->data, 2, 0);
    p->unk40 = 0;
    p->unk41 = 0;
    char *l = D_800A4544;
    func_8001D150(l, new S_Evt338(p, 0x80, 0));
    return p;
}

EXTERN_C void func_80023C40(char *p, int flags)
{
    *(void ***)p = D_8001079C;
    func_8001D324(D_800A4544, func_8001D25C(D_800A4544, p));
    func_80019920(*(List **)(p + 0x28), 0);
    func_8001D024(p, flags);
}

EXTERN_C int func_80023CB8(void *q, int idx, int a)
{
#define P ((S_Grp2 *)q)
#define H ((Holder *)P->unk28)
    int i;
    int r;
    if (!P->unk26) {
    if (count_of(H) == 0) {
        if (P->unk27 > 0) {
            unsigned char *b = P->unk4;
            unsigned char *c = P->unk14;
            for (i = 0; i < P->unk27; i++) {
                List *l;
                S_PadV *o = (S_PadV *)func_8002466C(operator new(0x1C), P->unk24, i);
                unsigned char *e;
                l = H;
                func_80019A6C(l, (int)o, l->count);
                e = o->f4(b);
                while (b < e) {
                    *b++ = 0;
                    *c++ = i;
                }
            }
        } else if (P->unk27 < 0) {
            List *l;
            S_PadV *o = (S_PadV *)func_80024870((S_80024870 *)operator new(0x20), P->unk24);
            l = H;
            func_80019A6C(l, (int)o, l->count);
            o->f4(P->unk4);
        }
    }
    if ((unsigned int)idx < (unsigned int)count_of(H)) {
        int j;
        r = ((S_ItemV *)func_80019F64(H, idx))->f2(a);
        P->unk25 = 0;
        for (j = 0; j < count_of(H); j++) {
            if (*(int *)((char *)func_80019F64(H, j) + 0x18))
                P->unk25 += ((S_ItemV *)func_80019F64(H, j))->f3();
        }
        return r;
    }
    }
    return 0;
#undef P
#undef H
}

EXTERN_C int func_80023F50(void *q, int a)
{
#define P ((S_Grp *)q)
    int r;
    int i;
    if (P->unk26)
        return 0;
    r = 0;
    P->unk25 = 0;
    if (P->unk27 < 0)
        r = func_80023CB8(q, 0, a);
    else {
        for (i = 0; i < P->unk27; i++) {
            Holder *h = (Holder *)P->unk28;
            if (((S_ItemV *)func_80019F64(h, i))->f2(a)) {
                P->unk25 += ((S_ItemV *)func_80019F64(h, i))->f3();
                r = 1;
            }
        }
    }
    if (!a) {
        for (i = 0; i < P->unk27; i++) {
            Holder *h = (Holder *)P->unk28;
            if ((unsigned int)func_80019F64(h, i) <= 0x8017FFFF) {
                P->unk40 = 2;
                break;
            }
        }
    }
    return r;
#undef P
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800240C0);

EXTERN_C void func_800244A4(S_800244A4 *p)
{
    Holder *h;
    func_80023F50(p, 0);
    h = &p->unk28;
    p->unk27 = 0;
    ((unsigned char *)p)[0x41] = 0;
    if (count_of(h)) {
        func_8001AA28(p->unk4, 4);
        memset(p->unk14, 0xFF, 0x10);
        func_80024594(h);
    }
}

EXTERN_C void func_80024524(S_80024524 *p)
{
    if (!p->unk26)
        func_80023F50(p, 0);
    p->unk26++;
}

EXTERN_C int func_8002456C(S_8002456C *p)
{
    return p->unk26 ? --p->unk26 == 0 : 1;
}

EXTERN_C void func_80024594(Holder *h)
{
    while (1) {
        int i = count_of(h);
        Item *it;
        if (!i)
            break;
        i--;
        it = func_80019F64(h, i);
        if (it)
            VCALL(it, 1, Fn_vi, 3);
        func_80019C68((List *)h, i);
    }
}

EXTERN_C int func_80024634(S_80024634 *p)
{
    return p->unk26 == 0;
}

EXTERN_C int func_80024640(S_80024634 *p)
{
    return p->unk25;
}

EXTERN_C int func_8002464C(S_80020B70 *p)
{
    return count_of(&p->unk28);
}

EXTERN_C void *func_8002466C(void *q, int a, int b)
{
    S_Pad *p = (S_Pad *)q;
    p->vtbl = D_800107C8;
    p->unk4 = a;
    p->unk8 = b;
    p->unkC = 0;
    p->unk14 = 0;
    p->unk18 = 0;
    p->unk10 = PadInfoAct(a, b, 4);
    return p;
}

EXTERN_C void func_800246C4(void *p, int a)
{
    ((S_Vobj *)p)->vtbl = D_800107C8;
    func_800198AC(p, a);
}

EXTERN_C int func_800246EC(S_800246EC *p, int a)
{
    int v;
    if (!p->unk10)
        p->unk10 = PadInfoAct(p->unk4, p->unk8, 4);
    p->unkC = a;
    v = PadInfoAct(p->unk4, p->unk8, 3);
    p->unk14 = v;
    if (!p->unk10 || v)
        return a + v;
    return a + 1;
}

EXTERN_C int func_80024770(S_PadLv *p, int x)
{
    int n;
    unsigned char *q;
    if (p->unk10) {
    if (p->unk14) {
        int d = 0xFFFF / ((1 << (p->unk14 * 8)) - 1);
        x = (x + d / 2) / d;
        p->unk18 = x;
        n = p->unk14;
    } else {
        x = x != 0;
        p->unk18 = x;
        n = 1;
    }
    q = p->unkC + n;
    do {
        *--q = x;
        n--;
        x >>= 8;
    } while (n);
    return p->unk18 != 0;
    }
    return 0;
}

EXTERN_C int func_80024858(S_80024858 *p)
{
    return p->unk10;
}

EXTERN_C int func_80024864(S_80024858 *p)
{
    return p->unk18 != 0;
}

EXTERN_C S_80024870 *func_80024870(S_80024870 *p, int a)
{
    return new (p) S_80024870(a);
}

EXTERN_C void func_800248BC(char *p, int flags)
{
    char *b;
    char *g;
    *(void ***)(p + 0x1C) = D_800107F0;
    *(void ***)p = D_80010800;
    b = p ? p + 0x1C : 0;
    Holder *h;
    g = D_800A4558;
    h = g ? (Holder *)(g + 8) : 0;
    func_80019CFC(h, b);
    func_800246C4(p, flags);
}

EXTERN_C int *func_80024940(char *p, int *q)
{
    *(int **)(p + 0xC) = q;
    func_8001AA28(q, 1);
    return q + 1;
}

EXTERN_C int func_80024974(S_PadLv *p, int v)
{
    void *b;
    char *g;
    p->unk14 = v;
    p->unk18 = v;
    b = p ? (char *)p + 0x1C : 0;
    g = D_800A4558;
    if (func_80019C24((Holder *)g, b)) {
        if (!v) {
            Holder *h8;
            b = p ? (char *)p + 0x1C : 0;
            h8 = g ? (Holder *)(g + 8) : 0;
            func_80019CFC(h8, b);
            p->unkC[0] = 0x40;
            p->unkC[1] = 0;
            PadSetAct(p->unk4, p->unkC, 2);
        }
    } else if (v) {
        List *l;
        b = p ? (char *)p + 0x1C : 0;
        l = (Holder *)g;
        func_80019A6C(l, (int)b, l->count);
    }
    return 1;
}

EXTERN_C void func_80024A80(S_Act *p)
{
    int v = p->unk14 + p->unk18;
    p->unk14 = v;
    if (v > 0xFFFF)
        p->unk14 = v - 0xFFFF;
    p->unkC[0] = 0x40;
    p->unkC[1] = p->unk14 > 0x7FFF;
    PadSetAct(p->unk4, p->unkC, 2);
}

EXTERN_C void func_80024AF0(void *q, int flags)
{
#define P ((S_80024CA0 *)q)
    *(void ***)((char *)q + 8) = D_80010888;
    *(void ***)q = D_800108A0;
    if (P->unk1E != 0xFFFF)
        func_80025714(&D_800B4C48, q);
    if (P->unk18 && P->unk1E != 0xFFFE)
        func_800A0D0C(P->unk18);
    if (P->unkC)
        VCALL(P->unkC, 1, Fn_vi, 3);
    func_8001A610(q, flags);
#undef P
}

EXTERN_C S_IdNode1E *func_80024BB0(S_IdNode1E *n, unsigned short id)
{
    S_IdNode1E *r;
    if (id == n->unk1E)
        return n;
    if (!n->next)
        return 0;
    r = func_80024BB0(n->next, id);
    return r;
}

EXTERN_C char *func_80024BF0(S_80024CA0 *p, char *buf, short w, short h)
{
    int n;
    int v;
    int sz;
    p->unk10.w = w;
    p->unk10.h = h;
    n = w * h;
    if (p->unkC) {
        if (p->unkC->f3())
            v = n >> 1;
        else
            v = n >> 2;
    } else
        v = n;
    sz = v * 2;
    p->unk18 = (short *)func_800A0D2C(sz);
    func_80025CE0(p->unk18, buf, sz);
    return buf + sz;
}

EXTERN_C short *func_80024CA0(S_80024CA0 *p, short *buf, short w, short h)
{
    int n;
    int v;
    p->unk10.w = w;
    p->unk10.h = h;
    n = w * h;
    if (p->unkC) {
        if (p->unkC->f3())
            v = n >> 1;
        else
            v = n >> 2;
    } else
        v = n;
    p->unk18 = buf;
    p->unk1E = 0xFFFE;
    return buf + v;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80024D40);

EXTERN_C void func_80024E44(S_80024CA0 *p, S_Rect8 *r)
{
    p->unk10 = *r;
    p->unk1C = GetTPage(p->unkC ? p->unkC->f3() != 0 : 2, 0, r->x, r->y);
    p->unk1E = 0xFFFF;
}

EXTERN_C void func_80024EE4(char *p)
{
    if (*(void **)(p + 0x18)) {
        S_118 *o = new S_118(p ? p + 8 : 0, 1);
        char *g = (char *)&D_800AC57C;
        char *l = g ? g + 0xF8 : 0;
        func_8001D150(l, new S_Evt338(o, 0x80, 1));
    }
}

EXTERN_C void func_80024FA8(S_80024FA8 *p)
{
    if (p->unk18) {
        func_800A0D0C(p->unk18);
        p->unk18 = 0;
    }
}

EXTERN_C void func_80024FE4()
{
}

EXTERN_C void func_80024FEC(S_Tex *p, void *o)
{
    p->unkC = o;
    p->unk1C = GetTPage(o ? VCALL(o, 3, Fn_i) != 0 : 2, 0, p->unk10, p->unk12);
}

EXTERN_C void func_80025050(char *p, int flags)
{
    char *b;
    char *l;
    void *o;
    *(void ***)(p + 0x8) = D_80010888;
    *(void ***)(p + 0x20) = D_80010840;
    *(void ***)p = D_80010858;
    o = *(void **)(p + 0x24);
    if (o)
        VCALL(o, 1, Fn_vi, 3);
    b = p ? p + 0x20 : 0;
    l = D_800A4544;
    func_8001D324(l, func_8001D25C(l, b));
    func_8001D024(p + 0x20, 0);
    func_80024AF0(p, flags);
}

EXTERN_C void func_8002510C(S_2510C *p, S_Pt4 pos, int abr)
{
    char *l;
    p->pos = pos;
    p->unk28 = p->unk24;
    p->unk30 = p->unk2C;
    ((S_AnimV *)p->unk28)->f2(pos, abr);
    p->unk1C = GetTPage(p->unkC ? p->unkC->f3() != 0 : 2, abr, pos.x, pos.y);
    l = D_800A4544;
    if (!func_8001D25C(l, p ? (char *)p + 0x20 : 0)) {
        char *b = p ? (char *)p + 0x20 : 0;
        func_8001D150(l, new S_Evt338(b, 0xC0, 0));
    }
}

EXTERN_C int func_80025268(S_80025268 *p)
{
    if (--p->unk30 <= 0) {
        p->unk30 = p->unk2C;
        if ((p->unk28 = p->unk28->next) != 0)
            p->unk28 = p->unk24;
        ((S_AnimV2 *)p->unk28)->f2(S_Pt4c(p->unk10, p->unk12), 0);
    }
    return 0;
}

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800107C8);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800107F0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80010800);

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_800252F8);

EXTERN_C int func_8002537C(char *p)
{
    void *o = operator new(0x20);
    S_RectPS r(((S_VramV2 *)D_800B4C54)->f4(S_Pt4c(0x40, 0x100)), S_Pt4c(0x40, 0x100));
    *(void **)(p + 4) = func_80026274(o, &r, 0);
    return 1;
}

INCLUDE_ASM("asm/main/nonmatchings/u_80020B70", func_80025444);

EXTERN_C void func_80025714(void *q, void *r)
{
#define P ((S_TexImg *)r)
    int s = P->getSize().x + P->getSize().y;
    if (s == 0)
        return;
    if (s <= 64 && ((S_TexImg *)q)->unk4->f5(P->getPos()))
        return;
    D_800B4C54->f5(P->getPos());
#undef P
}

EXTERN_C void func_80025808()
{
    func_8001DEB8(&D_800B4C48, 2);
}

EXTERN_C void func_80025830()
{
    func_800252F8(&D_800B4C48);
}

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80010840);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80010858);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80010888);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800108A0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800108C0);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800110C4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800110F4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011124);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011154);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001116C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800111A4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800111BC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800111FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011254);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001126C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800112D4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800112F4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011304);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001136C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011384);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011394);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001147C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800114CC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001151C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001162C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001167C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001178C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800117A4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800117BC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800117D4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001183C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800118DC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800118FC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001199C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011A44);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011AAC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011B14);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011B5C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011B8C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011BF4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011C44);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011CAC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011D04);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011D6C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011DBC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011E24);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011E74);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011E8C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011EF4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011F44);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011F5C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011F74);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80011FE4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001201C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80012034);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80012074);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001208C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800120B4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800120F4);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80012104);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_8001211C);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80012154);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_800121AC);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80012224);

INCLUDE_RODATA("asm/main/nonmatchings/u_80020B70", D_80012294);
