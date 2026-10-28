/* func_80045EB8: near miss (multiple-inheritance ctor: sub-object at +8, no in_chrg despite the shape). 41 differing: store order matches; GCC hoists the stack-arg loads (retail loads the 5th arg last). Logic from Ghidra + asm. */
EXTERN_C void *D_80011FE4[];
EXTERN_C void *D_800100F8[];
EXTERN_C void *D_800101B0[];
EXTERN_C void *D_800129AC[];
EXTERN_C void *D_8001299C[];
EXTERN_C void *D_800129C4[];
struct S_A2B_Sub8 { void *vt; void *vt4; int x; short s0, s1, s2, s3; };
struct S_A2B_C45 { void *vt0; int pad4; S_A2B_Sub8 b; int u1C, u20, u24, u28, u2C, u30, u34, u38; };
extern "C++" S_A2B_C45 *f45EB8(S_A2B_C45 *p, int a, int b, int c, int d, short e, short f, short g, short h) asm("func_80045EB8");
//// func_80045EB8
S_A2B_C45 *f45EB8(S_A2B_C45 *p, int a, int b, int c, int d, short e, short f, short g, short h)
{
    S_A2B_Sub8 *s;
    p->vt0 = D_80011FE4;
    AT(p, void **, 8) = D_800100F8;
    AT(p, void **, 0xC) = D_80010198;
    s = &p->b;
    s->vt4 = D_800101C0;
    AT(p, void **, 8) = D_800101B0;
    s->x = a;
    s->s0 = f;
    s->s1 = g;
    s->s2 = h;
    s->s3 = e;
    AT(p, void **, 0xC) = D_800129AC;
    AT(p, void **, 8) = D_8001299C;
    p->vt0 = D_800129C4;
    p->u1C = a;
    p->u20 = h;
    p->u24 = f;
    p->u28 = g;
    p->u2C = c;
    p->u30 = b;
    p->u34 = 0;
    p->u38 = d;
    return p;
}
