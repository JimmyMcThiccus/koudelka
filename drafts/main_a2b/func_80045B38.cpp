/* func_80045B38: near miss (dtor of the class built by func_800459D4). 52 differing: retail keeps the constants 8 and 2 in $s7/$s6 and the loop base unreduced (p, offset 0x1C); GCC strength-reduces here, same effect as func_80052FB8. */
EXTERN_C void *D_8001298C[];
extern "C++" void f1A610(void *p, int flags) asm("func_8001A610");
EXTERN_C void func_80036D8C(void *p);
//// func_80045B38
extern "C++" void f45B38(void *p, int flags) asm("func_80045B38");
void f45B38(void *p, int flags)
{
    int i;
    char *q;
    AT(p, void **, 0) = D_8001298C;
    q = (char *)p;
    for (i = 0; i < AT(p, short, 0x44); i++) {
        if (AT(q, void *, 0x1C)) {
            int cnt = AT(p, short, 0xC);
            void *m = func_8001CA10(0x14);
            AT(m, void **, 0) = D_80010178;
            AT(m, int, 4) = 0;
            AT(m, void **, 0) = D_80010300;
            AT(m, short, 8) = 2;
            AT(m, short, 0xA) = 8;
            AT(m, int, 0x10) = cnt + 0xF;
            AT(m, int, 0xC) = 0;
            AT(m, void **, 0) = D_800102D0;
            func_8001EFE4(AT(q, void *, 0x1C), m);
        }
        q += 4;
    }
    if (AT(p, void *, 0x4C))
        ((A2VObj0 *)((char *)AT(p, void *, 0x4C) + 8))->v00(3);
    operator delete(AT(p, void *, 0x48));
    func_80036D8C(AT(p, void *, 0x18));
    f1A610(p, flags);
}
