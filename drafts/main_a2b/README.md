# main_a2b drafts (round 3)

Near misses for the four `u_8003C510`..`u_80045850` units; each file's first line says what differs. None are built.
Two ctors with the same shape as func_800499D0 (func_8004D0F4: `lb 1(src)`, 4 iterations, `src+0xC`/`+0x14`) are
not saved; take func_800499D0 and change those constants.

Not attempted because the toolchain can't express them yet:
- `new T[n]` functions (func_800544AC, func_80054258, func_80053DDC): they need `__builtin_vec_new` named at
  0x800A0D2C in `config/symbols/main.txt`, but every caller of `func_800A0D2C` would then lose its name.
- virtual-base ctors: func_80045EB8, func_8005226C, func_80052100.
