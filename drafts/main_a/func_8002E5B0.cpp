// func_8002E5B0 (and func_8002E5D0, same with D_800B4CF4): return a 4-byte byte-aligned struct held at
// $gp. Retail does `lwl/lwr $v1, %gp_rel(D_800B4CF8+3/+0)($gp)`; GCC here loads the address with
// `la` first (lui/addiu), 2 instructions longer.
typedef struct S_Rgb {
    unsigned char r, g, b, cd;
} S_Rgb;

EXTERN_C S_Rgb D_800B4CF8;

EXTERN_C S_Rgb func_8002E5B0()
{
    return D_800B4CF8;
}
