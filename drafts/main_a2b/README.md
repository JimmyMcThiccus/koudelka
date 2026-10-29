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

Round 4, track B (Ghidra first). Landed: func_8004AC04, func_8003FAEC, func_80049420, func_800402E4, func_800404C8,
func_80042EF0, func_80042838, func_8003DEA8, func_8003DC54, func_80045EB8. Drafts saved with their diff counts:
- func_8003C5EC: 11 differing (retail computes `v = p8 - 8` before the base-ctor stores of the 0xC message).
- func_80048C30: 36 differing, register allocation only (needs func_80049250 returning void * and the prototype with short d/e).
- func_800451A8: 37 differing (guard + do-while is nearly retail; GCC cross-jumps the first call into the loop bottom).
- func_8003F3DC: 53 differing, register allocation only (p=s0, s=s1, q=s2, i=s3 in retail).
Tricks that mattered (also in the side-session notes): a typed struct for `p` changes alias decisions and scheduling;
`while (a && b)` is rotated like retail, `while (a) { if (!b) break; }` is not; `short n = D + 1; D = D + 1;` was
merged into one load but `p->f = (D + 1) * 5; D = D + 1;` gives retail's two loads; `switch` lists the case with the
fall-through body first; hoist `char *g = D_800A4544;` after the allocation that precedes the message.

Round 4, batch 2: landed func_8003CC78, func_800425A8. New drafts (diff counts): func_80044F18 (2), func_800459D4 (7),
func_8003C5EC (11), func_80048C30 (36), func_800451A8 (37), func_80042140 (34, virtual-base dtor in recipe form),
func_8005294C (44), func_8003F3DC (53), func_8003D3A0 (135).
More tricks:
- A polymorphic base at an offset: a real class (`struct Lnk : Pad8, A2VObj0`) and `((A2VObj0 *)lnk)->v09(a)` gives
  retail's null-checked `lnk ? lnk + 8 : 0`, evaluated twice (vptr and this). Casting a char * by hand does not.
- Wrap-up loop shapes: `if (x) do { ... x = next; } while (x);` rotated the walk in func_8003CC78.
- Messages built inside a ctor that posts itself (`new X1(this)` before the final vptr store) look like a copy of the
  object pointer in $v0; the draft in func_8003C5EC reproduces everything but the order of one load.
