// func_8001F048 (u_8001DDF4): right instructions, wrong layout. Retail does `bnez` to the compare and
// falls through to `return 0`; every form tried (if/else, ternary, &&, goto, bool, locals) puts return 0 last.
EXTERN_C int func_8001F048()
{
    if (D_800B4C1C == 0)
        return 0;
    return D_800B4C1C->unk94 > D_800B4C18->unk94;
}
