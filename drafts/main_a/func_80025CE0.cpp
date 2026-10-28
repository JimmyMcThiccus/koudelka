// func_80025CE0 (u_80025854): memcpy (dst, src, n) returning dst; word copy with shift-merge when src/dst
// alignments differ. Control flow and instructions are right (816 vs 820 bytes); register allocation is not:
// retail keeps dst in $a0 and src in $a1 (s0 holds the -1 loop sentinel); here both params get copied to temps.
EXTERN_C void *func_80025CE0(void *dst, unsigned char *s, unsigned int n)
{
    unsigned char *d = (unsigned char *)dst;
    unsigned int *dw;
    unsigned int i;
    if (((unsigned int)dst | (unsigned int)s) & 3) {
        int k = ((unsigned int)d - (unsigned int)s) & 3;
        unsigned int carry = 0;
        if (k) {
            int rs = (4 - k) * 8;
            int ls = k * 8;
            unsigned int w0, w1, w2, w3;
            while (((unsigned int)d & 3) && n) {
                *d++ = *s++;
                n--;
            }
            while ((unsigned int)s & 3)
                carry = (carry >> 8) | (*s++ << 24);
            dw = (unsigned int *)d;
            i = n >> 4;
            while (i--) {
                w0 = ((unsigned int *)s)[0];
                w1 = ((unsigned int *)s)[1];
                w2 = ((unsigned int *)s)[2];
                w3 = ((unsigned int *)s)[3];
                s += 16;
                dw[0] = (carry >> rs) | (w0 << ls);
                dw[1] = (w0 >> rs) | (w1 << ls);
                dw[2] = (w1 >> rs) | (w2 << ls);
                dw[3] = (w2 >> rs) | (w3 << ls);
                carry = w3;
                dw += 4;
            }
            i = (n >> 2) & 3;
            while (i--) {
                w0 = *(unsigned int *)s;
                s += 4;
                *dw++ = (carry >> rs) | (w0 << ls);
                carry = w0;
            }
            s -= ls / 8;
            d = (unsigned char *)dw;
            for (i = n & 3; i; i--)
                *d++ = *s++;
            return dst;
        }
        while (((unsigned int)d & 3) && n--)
            *d++ = *s++;
    }
    {
        unsigned int w0, w1, w2, w3;
        dw = (unsigned int *)d;
        i = n >> 4;
        while (i--) {
            w0 = ((unsigned int *)s)[0];
            w1 = ((unsigned int *)s)[1];
            w2 = ((unsigned int *)s)[2];
            w3 = ((unsigned int *)s)[3];
            s += 16;
            dw[0] = w0;
            dw[1] = w1;
            dw[2] = w2;
            dw[3] = w3;
            dw += 4;
        }
        switch ((n >> 2) & 3) {
        case 1:
            *dw++ = *(unsigned int *)s;
            s += 4;
            break;
        case 2:
            w0 = ((unsigned int *)s)[0];
            w1 = ((unsigned int *)s)[1];
            s += 8;
            dw[0] = w0;
            dw[1] = w1;
            dw += 2;
            break;
        case 3:
            w0 = ((unsigned int *)s)[0];
            w1 = ((unsigned int *)s)[1];
            w2 = ((unsigned int *)s)[2];
            s += 12;
            dw[0] = w0;
            dw[1] = w1;
            dw[2] = w2;
            dw += 3;
            break;
        }
        d = (unsigned char *)dw;
        switch (n & 3) {
        case 1:
            *d = *s;
            break;
        case 2:
            *(unsigned short *)d = *(unsigned short *)s;
            break;
        case 3:
            w0 = *(unsigned int *)s;
            *(unsigned short *)d = w0;
            d[2] = w0 >> 16;
            break;
        }
    }
    return dst;
}
