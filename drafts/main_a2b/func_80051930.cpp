/* func_80051930: near miss. s0/s1 swapped for p and a. Uses include/game/a2/a2.h (AT etc.). */
EXTERN_C void func_80051930(void *p, void *a, short b)
{
    void *m;
    if (!AT(p, short, 0xF8)) {
        AT(p, void *, 0x110) = a;
        m = func_8001CA10(0x14);
        AT(m, void **, 0) = D_80010178;
        AT(m, int, 4) = 0;
        AT(m, void **, 0) = D_80010300;
        AT(m, short, 8) = 2;
        AT(m, short, 0xA) = 0x10;
        AT(m, int, 0x10) = 0;
        AT(m, int, 0xC) = 0;
        AT(m, void **, 0) = D_800102D0;
        func_8001EFE4(p, m);
        AT(p, short, 0x118) = b;
    } else {
        m = func_8001CA10(0x14);
        AT(m, void **, 0) = D_80010178;
        AT(m, int, 4) = 0;
        AT(m, void **, 0) = D_80010300;
        AT(m, short, 8) = 2;
        AT(m, short, 0xA) = 0x10;
        AT(m, int, 0x10) = 1;
        AT(m, int, 0xC) = 0;
        AT(m, void **, 0) = D_800102D0;
        func_8001EFE4(a, m);
    }
}
