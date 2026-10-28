# main_b2 drafts (round 3)

`r3_attempts.cpp` holds the best attempts that do not match yet (one `//// func_X` section each; not built).
Round 2's notes for these units are in `drafts/main_b/` (read-only).

| Function | Diff | What differs |
|---|---|---|
| func_8008623C | 2 | `MI_8008623C : VPad<0x400>, VObj<0x9C>` call gives the right two null-checks; retail holds the vtable entry address in `$a2`, we use `$a1` |
| func_8008640C | 6 | retail copies `c` to `$s1` before the first `jal`; we put the copy in the delay slot (also needs `-fno-schedule-insns` in round 1) |
| func_8006B180 / B1C8 | 2 / 7 | clamp of the short at +0x2A0; retail loads into `$v1` and adds `$v1 + $a1` |
| func_8006C95C | 33 | switch is right (one case per label gives the jump table); retail copies `b` into `$v1` before `sw a1,4` |
| func_8006CAF8 | 41 | retail tests `k == 0xC8` outside the 5-entry table; we cross-jump the two `return 1` blocks |
| func_80072534 | 43 | retail copies the `ushort` type into `$a0` (`t == 2` and `v == t`) and keeps `$v1` for the `== 0xC` test |
| func_80075788 | 37 | ctor: retail copies `a1` to `$a0` early for `sw a0,8(s0)` |
| func_80076CD0 | 18 | vtable-chain dtor; retail loads `D_80012104` before the first store |
| func_8007E5B0 | 20 | `D_800B4DD0` reload: retail's second `lw a2,%lo(a2)` is scheduled before the `0x170` store |
| func_80085578 | 36 | frame is 0x40 (8 more bytes than ours) around the 16-byte stack struct |
| func_8008687C | 39 | `&t1/&t2` address pseudos land in other saved registers (as in round 2) |

Round 2 near misses still open: func_80089AC0, func_80089B44, func_8008A770, func_80086578, func_8008A188,
func_800824C8 (the header prototype has one argument, the asm uses two).

## Second batch (this session)

| Function | Diff | What differs |
|---|---|---|
| func_8007C6A8 | 0 in try_compile | Does not land: its jump table `jtbl_80017048` sits in the unit's rodata cluster (between `jtbl_80017030` and `D_8001705C`); GCC would emit its own table after the whole cluster. Needs the integrator to split the unit rodata, or a place for this function after the cluster |
| func_8006EACC / func_8006EF84 / func_8006EE94 / func_80078FD4 | 40+ | register allocation (`self`/`m` swap between `$s` registers); permuter found nothing |
| func_8006D964 | 10 | three `return 1` blocks: retail keeps them separate, we cross-jump |
| func_8006F3DC | 8 | needs `xori` from `bool ok = !f()`; the last case (store + `return 1`) gets an extra `$a0` copy |
| func_8007DB04 | 49 | retail switch tests `k == 2` first, then `k < 3`, then `k == 1` (root of the case tree is 2) |
| func_80084C50 | 60 | table element is read through a pointer computed before the `D_800AF470` load |
| func_800846EC | small | retail keeps both params in `$a2`/`$a3` copies; permuter found nothing in 15 min |
| func_80075EC8 | 43 | `self` in `$s1`, constant 1 in `$s0` (we swap); `p + 4` is computed right after `new` |
| func_80081ED0 / func_8006AE68 | 50+ | loop and switch shape right, constants (`2`, vtables) hoisted differently |

Note for the integrator: `func_8006C95C`'s switch needs one `case` per jump-table entry (separate bodies) to get a table.

## Third batch

| Function | Diff | What differs |
|---|---|---|
| func_800766F8 | 6 | twin of func_80076848; retail loads the stack arg `lw s0,0x40(sp)` and `li a0,0x24` after the `0x1BC` store, we hoist them |
| func_8007698C | 18 | twin of func_80076848; retail computes `D_80012104`'s address early (before the `D_800120F4` store) and stores it late |
| func_80076CD0 | 18 | twin of func_80035A28 plus two more vtable stores; same early `D_80012104` address in retail |
