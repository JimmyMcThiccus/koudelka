/* func_800540A8: near miss (inverse of func_80054258: nibble -> 0x40|nibble expansion). 113 differing: loop shape; logic from Ghidra. */
struct S_A2B_StrD { char pad[0x10]; S_A2_Ch *p; unsigned len; };
EXTERN_C S_A2_Ch D_800B4D68[];
//// func_800540A8
EXTERN_C void func_800540A8(S_A2B_StrD *s)
{
    int n1 = s->len - 1;
    int n2 = n1 * 2;
    int cnt = n2 + 1;
    S_A2_Ch *d = new S_A2_Ch[n2 + 2];
    unsigned u;
    unsigned char *pb;
    ((unsigned char *)d)[0] = ((unsigned char *)s->p)[0];
    ((unsigned char *)d)[1] = ((unsigned char *)s->p)[1];
    u = 1;
    pb = (unsigned char *)d;
    if (1 < s->len) {
        do {
            int i6 = u * 2;
            pb[2] = (((unsigned char *)s->p)[i6] & 0xF) | 0x40;
            pb[3] = (((signed char *)s->p)[i6] >> 4) | 0x40;
            pb[4] = (((unsigned char *)s->p)[i6 + 1] & 0xF) | 0x40;
            u++;
            pb[5] = (((signed char *)s->p)[i6 + 1] >> 4) | 0x40;
            pb += 4;
        } while (u < s->len);
    }
    if (((char *)s->p)[s->len * 2 - 1] == 0) {
        d[n1 * 2] = D_800B4D68[0];
        cnt = n2;
    }
    if (s->p)
        func_800A0D0C(s->p);
    s->len = cnt;
    s->p = d;
}
