/* func_800451A8: near miss. 37 differing: guard+do-while form is almost retail but GCC cross-jumps the first f401AC call into the loop bottom (retail keeps two call sites with a beqz after the first). Needs the a2b.h declarations plus this prelude. */
extern "C++" void *f401AC(void *p, int a) asm("func_800401AC");
extern "C++" void *f1A744(void *p, void *a) asm("func_8001A744");
EXTERN_C void func_800451A8(void *p, short a)
{
    void *s0;
    if (!AT(p, void *, 0x328))
        return;
    s0 = f401AC(AT(p, void *, 0x328), a);
    if (!s0)
        return;
    do {
        void *r = f1A744(AT(p, void *, 0x328), s0);
        if (s0 == AT(p, void *, 0x328))
            AT(p, void *, 0x328) = r;
        if (s0)
            ((A2VObj0 *)s0)->v00(3);
        s0 = 0;
        if (AT(p, void *, 0x328))
            s0 = f401AC(AT(p, void *, 0x328), a);
    } while (s0);
}
