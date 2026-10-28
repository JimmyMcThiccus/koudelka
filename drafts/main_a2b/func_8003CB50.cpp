/* func_8003CB50: near miss. 35 differing: retail loads lhu 0x10($sp) after the other loads and keeps the char pair in $v1/$v0. Needs the a2b.h declarations plus this prelude. */
EXTERN_C void func_8003CAD0(void *p);
EXTERN_C void func_8003CB50(void *p)
{
    void *c = AT(p, void *, 0x18);
    void *d;
    if (c)
        ((A2VObj<4> *)c)->v02();
    if (AT(p, void *, 0x14)) {
        d = AT(p, void *, 0x14);
        struct { signed char a, b; } t;
        int v;
        if (AT(d, void *, 0xC) == 0) {
            v = AT(d, unsigned short, 0x10) & 0x3F;
        } else {
            if (((A2VObj0 *)AT(d, void *, 0xC))->v02()) {
                v = (AT(d, short, 0x10) << 1) & 0x7F;
            } else {
                v = AT(d, short, 0x10) << 2;
            }
        }
        t.a = v;
        t.b = AT(d, short, 0x12);
        *(unsigned short *)0x1F800002 = AT(AT(p, void *, 0x14), unsigned short, 0x1C);
        *(unsigned short *)0x1F800000 = *(unsigned short *)&t;
        *(unsigned short *)0x1F800004 = AT(AT(AT(p, void *, 0x14), void *, 0xC), unsigned short, 8);
    }
    func_8003CAD0(p);
    if (AT(p, void *, 4))
        func_8003CB50(AT(p, void *, 4));
}
