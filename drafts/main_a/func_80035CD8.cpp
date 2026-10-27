// func_80035CD8: clears the 4 bytes D_800B4D10..D_800B4D13, last first. Retail counts with $v1 and walks
// a $gp pointer down from D_800B4D13 (`addiu $v0, $gp, ...`); this builds the address with lui/addiu
// and an extra instruction.
EXTERN_C unsigned char D_800B4D10[4];

EXTERN_C void func_80035CD8()
{
    int i;
    for (i = 3; i >= 0; i--)
        D_800B4D10[i] = 0;
}
