/* func_800499D0: near miss. 6 differing: prologue save/move order only (s2=0 hoisted first in retail). Written via an asm-label alias because a2.h declares 2 args. Needs `EXTERN_C A2VObj<4> *D_800B4D04;`. Uses include/game/a2b/a2b.h + a2/a2.h. */
extern "C++" void *f499D0(char *p, char *src, int *out) asm("func_800499D0");
extern "C++" void *f499D0(char *p, char *src, int *out) asm("func_800499D0");
void *f499D0(char *p, char *src, int *out)
{
    int i = 0;
    short *s = (short *)src;
    *out = ((signed char *)src)[1];
    *(S_A2_Sv *)(p + 4) = *(S_A2_Sv *)(src + 8);
    do {
        *(int *)(p + 0xC) = D_800B4D04->v01(s[1]);
        s++; i++;
        p += 4;
    } while (i < 3);
    return src + 0x10;
}
