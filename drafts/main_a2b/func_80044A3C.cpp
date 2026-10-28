/* func_80044A3C: near miss. 28 differing: structure and instruction order match (clamp in each arm, ab<<4, message store order); only register naming differs (retail: c=$a0 neg=$a1 r=$a2, result sum in $v1). A declaration-order sweep gave no match. */
//// func_80044A3C
extern "C++" int f44A3C(int *p, void *q) asm("func_80044A3C");
int f44A3C(int *p, void *q)
{
    int r, c, x;
    unsigned ab;
    int neg;
    if (p[5] == 2) {
        p[5] = 0;
        p[4] = func_80041C18(p + 7);
    }
    r = func_80041C18(p + 7);
    c = p[3];
    if (r >= p[4] + c) {
        if (q != 0 && p[6] == 0) {
            void *m;
            p[6] = 1;
            m = func_8001CA10(0x14);
            AT(m, void **, 0) = D_80010178;
            AT(m, int, 4) = 0;
            AT(m, void **, 0) = D_80010300;
            AT(m, short, 8) = 2;
            AT(m, short, 0xA) = 8;
            AT(m, int, 0x10) = 10;
            AT(m, int, 0xC) = 0;
            AT(m, void **, 0) = D_800102D0;
            func_8001EFE4(q, m);
        }
        r = p[0] + p[1];
        if (r >= 0x1000)
            r -= 0x1000;
        else if (r < 0)
            r += 0x1000;
        return r;
    } else {
        neg = 0;
        ab = p[1];
        if ((int)ab < 0) {
            neg = 1;
            ab = ~ab + neg;
        }
        x = (ab << 4) * (r - p[4]);
        x = x / c >> 4;
        if (neg)
            x = ~x + 1;
        r = p[0] + x;
        if (r >= 0x1000)
            r -= 0x1000;
        else if (r < 0)
            r += 0x1000;
        return r;
    }
}
