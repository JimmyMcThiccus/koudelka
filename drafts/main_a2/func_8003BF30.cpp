/* func_8003BF30: near miss. 7 instructions: order of s1=0 / s3=p->48 around the first new. Uses include/game/a2/a2.h (AT etc.). */
EXTERN_C void func_8003BF30(void *p, int a)
{
    AT(p, void **, 0) = D_80012724;
    if (AT(p, void *, 0x48)) {
        void *o = operator new(0xC);
        void *v48;
        char *g;
        void *t;
        AT(o, void **, 0) = D_80010160;
        v48 = AT(p, void *, 0x48);
        AT(o, int, 4) = 0;
        g = (char *)&D_800AC57C;
        t = g ? g + 0xF8 : 0;
        func_8001D150(t, new S_A2_X1(o));
        AT(o, void **, 0) = D_80010148;
        AT(o, void *, 8) = v48;
    }
    func_80039A88(p, a);
}
