/* func_80048C30: near miss. 61 differing: retail copies the 5th stack arg into $s7 early and saves 8 callee registers; mine saves fewer. Needs the a2b.h declarations plus this prelude. */
EXTERN_C void func_80049250(void *a, void *b, void *c);
EXTERN_C int func_8003FEF4(void *a, void *b, void *c, void *d, void *e, int f, int g, void *h, void *i);
struct S_A2B_48C30 { char pad6[6]; short s6, s8; char padA[4]; short sE; };
EXTERN_C int func_80048C30(void *a, void *bb, void *c, int d, int e)
{
    char buf[16];
    char *s5 = 0;
    S_A2B_48C30 *b = (S_A2B_48C30 *)bb;
    char *s0 = (char *)b + 0x10;
    char *s1;
    void *obj;
    if (b->sE) {
        s5 = s0;
        s0 = s5 + b->sE;
    }
    s1 = s0;
    s0 += b->s8 << 4;
    func_80049250(a, s0 + b->s8 * 12 * b->s6, buf);
    obj = operator new(0x38);
    return func_8003FEF4(obj, s0, s1, s5, b, (short)d, (short)e, obj, buf);
}
