// func_80027E30 (u_800278EC): heap alloc that reuses the space past the loaded overlay. Blocked on the overlay-end
// addresses (D_800E584C ...): retail loads them with an unsplit `la` macro (lui/addiu, never in a delay slot) and no
// $gp. GCC emits `la` only for small (<= 8 byte) externs, which tools/maspsx_extern.py then puts on $gp; anything
// else is split %hi/%lo and scheduled into delay slots. Logic below is complete (62 instructions differ, 356 vs 384).
EXTERN_C unsigned int ovl_header __attribute__((section(".data")));
EXTERN_C int D_800D5DAC __attribute__((section(".data")));
EXTERN_C char D_800EA8A0[];
EXTERN_C char D_800B7AA0[];
EXTERN_C char D_800C321C[];
EXTERN_C char D_800CCAA8[];
EXTERN_C char D_800E310C[];
EXTERN_C char D_800E584C[];
EXTERN_C char *func_80018C90(int size);
EXTERN_C char *func_80018D80(int size);
EXTERN_C char *func_80027E30(int size)
{
    char *end;
    if (D_800B4C60)
        return func_80018C90(size);
    switch (ovl_header) {
    case 5:
        switch (D_800D5DAC) {
        case 9:
            end = D_800E584C;
            break;
        case 10:
            end = D_800E310C;
            break;
        default:
            return func_80018D80(size);
        }
        break;
    case 6:
        end = D_800CCAA8;
        break;
    case 7:
        end = D_800C321C;
        break;
    case 8:
        end = D_800B7AA0;
        break;
    default:
        return func_80018D80(size);
    }
    D_800B4C60 = 0;
    int n = size - (D_800EA8A0 - end);
    if (n <= 0)
        n = 1;
    char *p = func_80018D80(n);
    if (!p)
        return 0;
    if (p - 8 == D_800EA8A0) {
        ((int *)end)[1] = ((size + 7) >> 3 << 3) + 8;
        D_800B4C60 = ((int *)p)[-1];
        return end + 8;
    }
    func_80018C1C(p);
    return 0;
}
