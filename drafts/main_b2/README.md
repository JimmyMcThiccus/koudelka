# main_b2 drafts (round 3)

`r3_attempts.cpp` holds the best attempts that do not match yet (one `//// func_X` section each; not built).
Round 2's notes for these units are in `drafts/main_b/` (read-only).

| Function | Diff | What differs |
|---|---|---|
| func_8008623C | 2 | `MI_8008623C : VPad<0x400>, VObj<0x9C>` call gives the right two null-checks; retail holds the vtable entry address in `$a2`, we use `$a1` |
| func_8008640C | 6 | retail copies `c` to `$s1` before the first `jal`; we put the copy in the delay slot (also needs `-fno-schedule-insns` in round 1) |
| func_8006B180 / B1C8 | 2 / 7 | clamp of the short at +0x2A0; retail loads into `$v1` and adds `$v1 + $a1` |
| func_8006C9F8 | 4 | `D_800B4ED8` is reached with the lui macro here, but it is `$gp` in this unit (`func_8006BF94`): the unit's `$gp` list can't give both. Needs a unit split between 0x8006BF94 and 0x8006C9F8 |
| func_8006C95C | 33 | switch is right (one case per label gives the jump table); retail copies `b` into `$v1` before `sw a1,4` |
| func_8006CAF8 | 41 | retail tests `k == 0xC8` outside the 5-entry table; we cross-jump the two `return 1` blocks |
| func_80072534 | 43 | retail copies the `ushort` type into `$a0` (`t == 2` and `v == t`) and keeps `$v1` for the `== 0xC` test |
| func_80075788 | 37 | ctor: retail copies `a1` to `$a0` early for `sw a0,8(s0)` |
| func_80076CD0 | 18 | vtable-chain dtor; retail loads `D_80012104` before the first store |
| func_8007E5B0 | 20 | `D_800B4DD0` reload: retail's second `lw a2,%lo(a2)` is scheduled before the `0x170` store |
| func_80085578 | 36 | frame is 0x40 (8 more bytes than ours) around the 16-byte stack struct |
| func_80085710 | 3 | `k` is held in two registers (`$v1`, `$a1`) in retail |
| func_8008687C | 39 | `&t1/&t2` address pseudos land in other saved registers (as in round 2) |

Round 2 near misses still open: func_80089AC0, func_80089B44, func_8008A770, func_80086578, func_8008A188,
func_800824C8 (the header prototype has one argument, the asm uses two).
