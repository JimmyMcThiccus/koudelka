// func_8001F048: right instructions, wrong layout. Retail loads D_800B4C1C into $v1, does
// `bnez` to the compare, and falls through to `return 0`; it also loads the two unk94s in the
// other order. Ternary, if/else and early-return forms all put `return 0` last.
EXTERN_C int func_8001F048()
{
    if (!D_800B4C1C)
        return 0;
    return D_800B4C18->unk94 < D_800B4C1C->unk94;
}
