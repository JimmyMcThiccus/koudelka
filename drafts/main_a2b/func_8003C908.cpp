/* func_8003C908: near miss. 4 differing: retail holds the null-checked base pointer in $a0 and copies it to $s0 (register choice only). Needs the a2b.h declarations plus this prelude. */
inline void *a2b_base(void *x) { return x ? (char *)x - 8 : 0; }
struct C_8003C5A8 { C_8003C5A8(void *a, int b, int c) asm("func_8003C5A8"); char pad[0x1C]; };
EXTERN_C int func_8003C908(void *p, void *n)
{
    void *s0;
    if (AT(p, int, 0x10) == AT(AT(n, void *, 8), int, 0x24)) {
        s0 = a2b_base(AT(p, void *, 8));
        if (AT(n, void *, 4) && s0)
            func_8001A864(s0, AT(n, void *, 4));
        AT(n, void *, 4) = s0;
        if (!n)
            AT(p, void *, 8) = 0;
        else
            AT(p, void *, 8) = (char *)n + 8;
    } else {
        if (AT(p, void *, 4)) {
            func_8003C908(AT(p, void *, 4), n);
        } else {
            s0 = new C_8003C5A8(n ? (char *)n + 8 : 0, 0, 0);
            if (AT(p, void *, 4) && s0)
                func_8001A864(s0, AT(p, void *, 4));
            AT(p, void *, 4) = s0;
        }
    }
    return 1;
}
