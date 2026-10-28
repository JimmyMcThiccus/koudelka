/* func_80052FB8: near miss. 6 differing: retail keeps the loop pointer = p with +0x48 offsets; GCC strength-reduces it to p+0x48. Logic from Ghidra. */
EXTERN_C void func_80024FEC(void *p, int a);
EXTERN_C void func_800215E8(void *a, void *b);
EXTERN_C void func_8005C088(void *p, int a, int b);
EXTERN_C void *D_800B4C38;
struct S_A2B_X48 { char pad[0x48]; void *v; };
struct C_8005F5F4 { C_8005F5F4(void *a, int b) asm("func_8005F5F4"); char pad[0x14]; };
//// func_80052FB8
EXTERN_C void func_80052FB8(void *p)
{
    if (AT(p, void *, 0x54)) {
        unsigned i;
        int *q;
        AT(p, int, 0x44) = 0;
        if (AT(p, int, 8))
            func_8005C088(p, ((A2VObj<0x2C> *)p)->v11(), 1);
        i = 0;
        q = (int *)p;
        do {
            i++;
            func_80024FEC((void *)q[18], 0);
            new C_8005F5F4((void *)q[18], 2);
            q[18] = 0;
            q++;
        } while (i < 3);
        func_800215E8(D_800B4C38, AT(p, void *, 0x54));
        if (AT(p, A2VObj0 *, 0x54))
            AT(p, A2VObj0 *, 0x54)->v00(3);
        AT(p, int, 0x54) = 0;
    }
}
