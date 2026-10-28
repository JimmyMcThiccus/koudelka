/* func_8003572C: near miss. retail keeps a copy of the vbase pointer in v1; GCC folds it. Uses include/game/a2/a2.h (AT etc.). */
EXTERN_C void *func_8003572C(void *p, int vb, short c)
{
    if (vb) {
        char *b;
        AT(p, void *, 0x28) = (char *)p + 0x2C;
        AT(p, void *, 4) = AT(p, void *, 0x28);
        b = AT(p, char *, 4);
        AT(b, short, 0) = 16;
        AT(b, short, 2) = c;
        AT(b, int, 4) = -1;
    }
    AT(p, void **, 0) = D_80012154;
    AT(p, void **, 8) = D_8001201C;
    AT(p, void **, 0) = D_80012034;
    AT(p, void *, 0xC) = (char *)p + 0x10;
    ((int (*)(void *, int, int))func_800198E0)((char *)p + 0x10, 4, 0);
    AT(p, void **, 0x24) = D_800121AC;
    AT(p, void **, 8) = D_80012074;
    AT(p, void **, 0x24) = D_8001208C;
    AT(p, void **, 0) = D_800120B4;
    return p;
}
