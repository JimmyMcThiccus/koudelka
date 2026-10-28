// func_8002E5B0 (and func_8002E5D0 with D_800B4CF4; also func_80026190 in u_80025854): return a 4-byte unaligned
// struct held in .sdata. Retail is ASPSX's expansion of `ulw $3, D_800B4CF8` with $gp
// (`lwl $v1, %gp_rel(D+3)($gp); lwr $v1, %gp_rel(D)($gp)`). A packed struct makes GCC emit exactly that `ulw`
// (a plain byte struct gives a block move with `la` first), but GNU as expands `ulw reg, sym` through
// `lui/addiu $at` and maspsx doesn't rewrite ulw/usw for sdata symbols. Needs a tools change: maspsx should
// expand `ulw`/`usw` of a small-data symbol $gp-relative. Even then, check the `addu $v0, $a0` placement (retail:
// first instruction; the NRV form below puts it after the load).
struct S_U4 { int v; } __attribute__((packed));
EXTERN_C S_U4 D_800B4CF8;

EXTERN_C S_U4 func_8002E5B0() return r
{
    r.v = D_800B4CF8.v;
}
