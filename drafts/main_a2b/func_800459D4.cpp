/* func_800459D4: near miss (ctor of the 0x60 object; returns this). 7 differing: loop counter lands in $t0 (retail $a0, pointer $v1) and one li/addiu pair order. Needs a2b.h. */
EXTERN_C void *D_800127FC[];
EXTERN_C void *D_8001298C[];
struct S_A2B_Cap { short cap; short x; int y; };
EXTERN_C void *func_800459D4(void *pv, void *a, short b, short c, int d)
{
    S_80045C88 *p = (S_80045C88 *)pv;
    int *q;
    int i;
    AT(p, void **, 0) = D_80010178;
    AT(p, int, 4) = 0;
    AT(p, void **, 0) = D_8001298C;
    AT(p, short, 0xA) = b;
    AT(p, short, 0xC) = c;
    AT(p, short, 0x10) = 0;
    AT(p, int, 0x18) = 0;
    AT(p, int, 0x4C) = 0;
    AT(p, void *, 0x5C) = a;
    AT(p, short, 8) = 0;
    p->unk44 = 0;
    q = (int *)p + 9;
    i = 9;
    do {
        q[7] = 0;
        i--;
        q--;
    } while (i >= 0);
    p->unk1C[p->unk44++] = d;
    {
        char *s = (char *)operator new(0x18);
        void *g = D_800B4D38;
        AT(s, void **, 0) = D_800127FC;
        AT(s, int, 8) = 5;
        AT(s, char, 0x14) = 0;
        AT(s, int, 0xC) = 3;
        AT(s, void *, 0x10) = p;
        AT(s, void *, 4) = g;
        AT(p, void *, 0x48) = s;
    }
    {
        char *t = (char *)operator new(0x44);
        S_A2B_Cap *r = (S_A2B_Cap *)(t + 0x3C);
        r->cap = 0x10;
        AT(t, void *, 4) = r;
        r->x = 1;
        r->y = -1;
        AT(t, void **, 0) = D_80012154;
        AT(t, void **, 8) = D_8001201C;
        AT(t, void **, 0) = D_80012034;
        AT(t, void *, 0xC) = t + 0x10;
        func_800198E0(t + 0x10, 4, 0);
        AT(t, void **, 8) = D_80012294;
        AT(t, void **, 0) = D_80012224;
        AT(t, int, 0x28) = 0;
        AT(t, int, 0x2C) = 0;
        AT(p, void *, 0x18) = t;
    }
    return p;
}
