/* func_800456F4: near miss. 48 differing: logic from Ghidra; retail reloads e->0x50 after the store (not forwarded) and loads e->0x18 late. */
EXTERN_C void func_80035EB4(void *p);
EXTERN_C void func_8004561C(void *p, void *e);
EXTERN_C int func_800468D8(void *a, int b, int c, void *d, int e);
//// func_800456F4
EXTERN_C void func_800456F4(void *p, void *q)
{
    char st[0x28];
    void *e;
    func_80048D54(st);
    e = AT(q, void *, 0xC);
    if (AT(e, short, 0x50)) {
        int a, b, c;
        unsigned *ptr;
        func_80035EB4(AT(e, void *, 0x48));
        if (AT(e, short, 8)) {
            a = AT(e, int, 0x18);
            c = AT(e, int, 0x14);
            b = *(unsigned *)(AT(e, short, 0xC) * 8 + AT(p, int, AT(e, short, 0xA) * 4 + 0xF8));
        } else {
            a = AT(e, int, 0x18);
            ptr = (unsigned *)(AT(e, short, 0xC) * 8 + AT(p, int, AT(e, short, 0xA) * 4 + 0xF8));
            b = ptr[0];
            c = ptr[1];
        }
        AT(e, short, 0x50) = func_800468D8(st, b, c, 0, a);
        if (AT(e, short, 0x50) == 0) {
            func_8004561C(p, e);
        } else {
            func_80035DE0(AT(e, void *, 0x48));
            AT(e, short, 0x10) = 0;
        }
    }
    func_80048D2C(st, 2);
}
