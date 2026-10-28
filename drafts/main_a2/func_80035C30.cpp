/* func_80035C30: near miss. 3 differing: only the order of `sw s0` / `addu a3,a0` in the prologue (retail copies the masked arg to a3 before saving s0). Loop and everything else match. permuter (-j 6, 7 min) found nothing. Uses include/game/a2/a2.h. */
EXTERN_C int func_80035C30(int a)
{
    a = (a ^ 2) & 0x12;
    int m = (unsigned char)a;
    int na = a;
    int i;
    unsigned char v;
    for (i = 0; i < 3; i++) {
        v = (D_800B4D10[i] = D_800B4D10[i + 1]);
        m &= v;
    }
    D_800B4D10[3] = na;
    if (m) func_8003831C(&D_800AC86C, m);
    return m;
}
