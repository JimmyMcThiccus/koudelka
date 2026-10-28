# main_a2b drafts (round 3)

Near misses for the four `u_8003C510`..`u_80045850` units; each file's first line says what differs. None are built.
Two ctors with the same shape as func_800499D0 (func_8004D0F4: `lb 1(src)`, 4 iterations, `src+0xC`/`+0x14`) are
not saved; take func_800499D0 and change those constants.

Not attempted because the toolchain can't express them yet:
- `new T[n]` functions (func_800544AC, func_80054258, func_80053DDC): they need `__builtin_vec_new` named at
  0x800A0D2C in `config/symbols/main.txt`, but every caller of `func_800A0D2C` would then lose its name.
- virtual-base ctors: func_8005226C and func_80052100 landed with the hand-written in_chrg form; func_80045EB8 is an MI ctor (draft).

Round 3, batch 3:
- GTE-heavy functions (func_80049488, func_80049680, func_8004A16C-style prims) are skipped: the gte_* macros are
  inline asm.
- func_80052E40 and func_80054708 are skipped: string literals / number formatting with locals that need dtors.
- Ghidra-decompiled near misses: func_8003C764, func_8003FEF4, func_800540A8, func_8004BC14, func_80052FB8,
  func_800456F4, func_8004A89C (3 instructions: polarity of the last null test).
