/* func_80048C30: near miss. 36 differing (register allocation only). Needs a2b.h prototype changed to (void*,void*,void*,short,short) and func_80049250 returning void*. Retail: cur=s0 s1var=s1 r=s2 &buf=s3 b=s4 s5var=s5 d=s6 e=s7; mine swaps several. */
EXTERN_C void *func_80049250(void *a, void *b, void *c);
EXTERN_C int func_8003FEF4(void *a, void *b, void *c, void *d, void *e, int f, int g, void *h, void *i);
struct S_A2B_48C30 { char pad6[6]; short s6, s8; char padA[4]; short sE; };
EXTERN_C int func_80048C30(void *a, void *bb, void *c, short d, short e)
{
    char bufx[8]; char *buf = bufx;
    char *s5 = 0;
    S_A2B_48C30 *b = (S_A2B_48C30 *)bb;
    char *s0 = (char *)b + 0x10;
    char *s1;
    void *obj, *r;
    if (b->sE) {
        s5 = s0;
        s0 = s5 + b->sE;
    }
    s1 = s0;
    s0 += b->s8 << 4;
    r = func_80049250(a, s0 + b->s8 * 12 * b->s6, buf);
    obj = __builtin_new(0x38);
    return func_8003FEF4(obj, s0, s1, s5, b, d, e, r, buf);
}
