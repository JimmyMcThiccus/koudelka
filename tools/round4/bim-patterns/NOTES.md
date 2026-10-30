# BIM.AR hard patterns (branch claude/bim-patterns-098fb6, worktree r3-main-a2-8fd3e3)

All three patterns from tools/round4/bim-shared/NOTES.md cracked; 204 module INCLUDE_ASM lines removed
(85 table initialisers + 85 vbase ctors + 34 e310/9b3b copies). Generators: r3-bim-patterns-generators/ here
(copies of the worktree's gitignored scratch_c/).

## 1. Table initialisers (85: 22 shared hashes x 50 copies, 35 per-module func_)
Two things:
- Use `D_800B4D38` as declared in include/bim/shared.h (`char *D_800B4D38[]`, an array of unknown size). A scalar
  `char *` extern gets the small-data treatment (lui/lw emitted as one macro), the array gives a separate HIGH insn
  that the scheduler hoists, as retail does.
- Shape (permuter find, confirmed with try_compile):
      int *q = (int *)p;
      int s = (short)slot;          // sign-extend at the top: combine splits sll16 (stays early) / sra14 (late)
      char **b = D_800B4D38;        // at the top
      ... stores in offset order ...
      int *v = q + BASE/4;          // table pointer into a local first
      int **t = (int **)(*b + 0xF8);
      t[s] = v;
gen_tbl2.py writes it from the asm (lui/ori/addiu/ori-from-zero constant tracking); tbl_install.py installs.

## 2. Virtual-base constructors (85 per-module func_: 6 via gen_ctor1, 73 via gen_ctor2, 6 branchy)
Tail: `register BimDtor *r asm("$2") = self; r->f9DC = 0; r->f9D8 = 0; return r;` (all tail stores through r).
Retail's `move v0, s0` before the stores is the pinned return value. gen_ctor2.py: prefix from parameters (vbase
offset 0xAE8/0xAEC/0xAF0, symbols, final func_800D8D64 args), tail translated from the asm into stores/calls
(stores before a call go through self, after the last call through r), tries store-order permutations until 0.
The register swap (self in s1) in some modules is just a constant 1 kept in s0 for the tail; same C.
6 branchy tails (func_800D8350 test) hand-written in ctor_branchy.py (two shapes, 3 modules each).
Callees are declared through asm("name") aliases (`name_c`) so they can't clash with definitions in the unit.

## 3. bimf_e310b46d / bimf_9b3b5928 (20 + 14 copies)
The final "clear bit 1 else bit 0" block has NO trailing return: with neither bit set the function falls off the
end, returning the `f & 1` test's 0 still in $v0. With a `return 0` (or `ret` variable) the last return's
(use $v0) lands before the return label and jump2 cross-jumps the bit-1 tail into the bit-0 one. Without it,
bit 1's `return 1` keeps its USE before its jump, the cross-jump compare fails on the first insn, nothing merges.
(Worth trying on other near misses whose retail tail returns a leftover test value with `beqz v0, END; nop`.)

## Tooling notes
- scratch_c/dump.sh src.cpp outdir: preprocess + CC1PLPSX -da: all RTL dumps. Pass order here:
  ... greg -> sched2 -> jump2 (cross-jumping) -> dbr. Epilogue is in RTL after the return label.
- tools/permute.py already compiles candidates as C++ (extern "C" wrapper).

## Still open (for after)
- 82 per-module func_ functions (long ones, misc).
- ~79 small bimf_ functions with 2-3 copies (~50 hashes): f35df0eb dbec461b d408bc6f b1674f83 51caf7a0 227ce542
  05f10258 (3 each), fe1739bb da437c5e b4ba168f a4898870 a25cce56 9421c4d7 8b808450 85fa9335 79606d43 73046ab9
  712088f5 6d10f24e 584a2d1f 54e42f42 4cfb86f6 38dc0e9d 35f30ee4 2df2c08d 2a027d19 227b9b39 ... (2 each).
