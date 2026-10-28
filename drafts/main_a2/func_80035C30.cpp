/* func_80035C30: near miss. 16 differing (best of ~100 variants): retail loop is rotated with i in one reg (`addu a1,i,base; i++; addu v0,i,base`), loaded byte kept in a0 (so the store-after-loop value needs a3), `andi 0xFF` after the lbu (unsigned char temp declared outside the loop). Uses include/game/a2/a2.h. */
EXTERN_C int func_80035C30(int a)
{
    int na = (a ^ 2) & 0x12;
    int m = (unsigned char)na;
    int i; unsigned char v;
    for (i = 0; i < 3; i++) {
        v = D_800B4D10[i + 1];
        D_800B4D10[i] = v;
        m &= v;
    }
    D_800B4D10[3] = na;
    if (m) func_8003831C(&D_800AC86C, m);
    return m;
}
