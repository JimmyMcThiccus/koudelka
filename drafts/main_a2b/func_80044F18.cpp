/* func_80044F18: near miss. 2 differing: retail does `addu s0,v0` before `addu a0,s3` after func_8004007C; everything else matches (size 460). Needs a2b.h plus func_8004007C/func_800459D4/func_800468D8 aliases as below. */
EXTERN_C void *func_800459D4(void *p, void *a, int b, int c, int d);
extern "C++" void *f4007C(void *p, int a, int b, int c) asm("func_8004007C");
extern "C++" short f468D8(void *p, int a, int b, void *c, void *d) asm("func_800468D8");
extern "C++" void f1A678(void *a, void *b) asm("func_8001A678");
EXTERN_C void *func_80045CAC(void *p, short a, short b);
EXTERN_C void func_80045C88(void *p, int a);
// exe.h declares this with int parameters and result.
struct S_A2B_44F18 { char pad[0xF8]; int *tab[3]; char pad2[0x328 - 0x104]; void *p328; void *p32C; };
EXTERN_C void *func_80044F18_t(S_A2B_44F18 *p, short a, short b, int c, int d) asm("func_80044F18");
EXTERN_C void *func_80044F18_t(S_A2B_44F18 *p, short a, short b, int c, int d)
{
    char buf[0x28];
    func_80048D54(buf);
    if (b != -2) {
        void *r;
        if (p->p32C && (r = func_80045CAC(p->p32C, a, b)) && c) {
            func_80045C88(r, c);
        } else {
            void *o = (void *)func_800450E4(p, a, b);
            if (!o) {
                void *n = operator new(0x38);
                void *m;
                void *u;
                m = f4007C(n, a, b, d);
                func_80044C7C(p, m);
                u = operator new(0x60);
                o = func_800459D4(u, m, a, b, c);
                {
                    int *e = (int *)(b * 8 + (int)p->tab[a]);
                    short s = f468D8(buf, e[0], e[1], AT(o, void *, 0x48), AT(o, void *, 0x18));
                    AT(o, short, 0x50) = s;
                    if (!s)
                        func_8004561C(p, o);
                }
                if (!p->p32C)
                    p->p32C = o;
                else
                    f1A678(p->p32C, o);
            } else if (f40294(o, 0)) {
                func_80048D2C(buf, 2);
                return o;
            }
        }
    }
    func_80048D2C(buf, 2);
    return 0;
}
