# Working in parallel

Several sessions can decompile at once, each in its own git worktree and branch and each owning one **area**.
The areas don't overlap, so their branches merge cleanly.

## Areas (round 3)

The EXE's game code is split into 42 source units, one per original source file where the `.ctors` table, a
jump-table alignment change or a `$gp` clash (`tools/gp_boundaries.py`) marks one: `src/main/u_<start
address>.cpp`, plus `main_a.cpp`, `main_b.cpp` and `sound.cpp`. An area is a set of whole units, so two sessions
never edit the same file. The "Left" counts are as of the first round-3 merge.

| Area | Units (`src/...`) | Left | Your symbols | Your headers | Your drafts |
|---|---|---|---|---|---|
| `main_a2` | `main/u_80032264`, `u_80033ECC`, `u_800372C0`, `u_80037398`, `u_8003852C` | 49 | `main_a2.txt` | `include/game/a2/` | `drafts/main_a2/` |
| `main_a2b` | `main/u_8003C510`, `u_8003F7E8`, `u_80044BE4`, `u_80045850` (`0x8003C510`–`0x80054A2C`) | 143 | `main_a2b.txt` | `include/game/a2b/` | `drafts/main_a2b/` |
| `main_b1` | `main/main_b.cpp`, `u_80056E0C`, `u_80059A84`, `u_8005F238`, `u_80062610`, `u_800658E0`, `u_80067450` | 137 | `main_b.txt` | `include/game/b/` | `drafts/main_b/` |
| `main_b2` | `main/u_80068770`, `u_8006BFE4`, `u_8006CBCC`, `u_80071A74`, `u_80082174`, `u_80083EB4`, `u_80085168`, `u_80089024` | 150 | `main_b2.txt` | `include/game/b2/` | `drafts/main_b2/` |
| `field` | `field/field.cpp`, `field/field_b.cpp` | 192 | `field.txt` | `include/field/` | `drafts/field/` |
| `battle` | `battle/battle.cpp`, `battle_b.cpp`, `battle_c.cpp` | 115 | `battle.txt` | `include/battle/` | `drafts/battle/` |
| `small` | `effect/*`, `capture/*` (`capture.cpp` is PsyQ 4.1), `movie/movie.cpp` (game code only: leave its 28 Sony library functions), `gameend/gameend.cpp`, `main/sound.cpp` (PsyQ 4.1), `main/main_a.cpp` and `main/u_80018B88` … `u_8002ED44`, `u_8003148C` | ~102 | `main_a.txt`, `sound.txt`, `effect.txt`, `capture.txt`, `movie.txt`, `gameend.txt` | `include/game/a/`, `include/game/sound/`, `include/effect/`, `include/capture/`, `include/movie/`, `include/gameend/` | `drafts/<that area>/` |

Symbols files are in `config/symbols/`. Headers outside your folders are **read-only** for you, including ones your
units already include (`main_a2b` reads `include/game/a2/`, `main_b2` reads `include/game/b/`). Put new
declarations in your own folder and include that header from your units. If a read-only header has a declaration
that is wrong for your function, alias it (`EXTERN_C int f_alt(int) asm("func_X");`) and report it. Use `--unit`
with the unit file a function lives in (see "The loop"); the unit boundaries are the `[0x..., cpp, u_...]` lines
in `config/slus_010.51.yaml`.

## Setup (once per worktree)

```powershell
C:/Users/jamie/Documents/Koudelka/.venv/Scripts/python.exe tools/worktree_setup.py --configure
```

This copies the toolchain, virtualenv and retail files from the main checkout (about 45 MB), then splits and builds.
The last line must be `functional check: OK`.

## The loop

1. Pick an `INCLUDE_ASM` function in your range. Read its `.s` in `asm/<target>/nonmatchings/`, and Ghidra if it
   helps. Start with small leaf functions; callees first make callers easier.
2. Write it in a scratch file (`scratch_c/` is git-ignored) and iterate until it matches exactly:

   ```powershell
   .venv/Scripts/python.exe tools/try_compile.py scratch_c/f.cpp func_XXXXXXXX --unit src/field/field.cpp
   ```

   `--unit` is the source file the function lives in. It brings that file's exact build flags (compiler, ASPSX
   version, `-G`, divide checks) and its asm folder and retail binary.

   Done means `0 differing instructions`.
3. Move it into your `.cpp`, replacing its `INCLUDE_ASM(...)` line. Follow the rules in the README ("Decompiling a
   function"):
   - Use `EXTERN_C` for free functions and for the asm functions they call.
   - Use existing retail names for globals; never define new storage.
   - Code must be the same size or smaller.
4. Rebuild after each batch. Both of these must pass before you commit:

   ```powershell
   .venv/Scripts/python.exe configure.py --mode matching   # 7 x "check: OK"
   .venv/Scripts/python.exe configure.py                   # "functional check: OK"
   ```

   `configure.py` re-splits, so decompiled functions' `.s` move to `matchings/`.
5. Commit to your branch in small batches, e.g. `field: decompile 12 functions (0x800BA800-0x800BB3C0)`. Never push.
   No AI attribution trailers.

**Only exact matches land.** An exact match is the only proof that a function behaves like retail; the build can't
check a non-matching one. If you get close but can't finish, leave the `INCLUDE_ASM` in place, save your best attempt
under `drafts/<area>/func_XXXXXXXX.cpp`, and add a one-line note on what differs. `drafts/` isn't built.

**Not allowed.** A branch with any of these is rejected whole at merge, because each one fakes a match:
- `asm`/`__asm__` statements that emit instructions. `asm("sym")` on a declaration, to give it a symbol name, is fine.
- Editing anything under `asm/`, or adding `.s` files.
- Defining new storage (globals, statics, string literals that land in new rodata).
- Editing files outside your area (see "What you may edit").
- Committing a function that doesn't match, or changing the build to make one fit.

**Skip for now:** constructors and destructors of classes with virtual bases. You can spot them by an `in_chrg`
test of `$a1`, a 0x50-byte vtable copied to the stack, and deltas patched through `self->vbptr`. They need shared
class modelling, which the integrator does. List the ones you meet in your report.

## What you may edit

- **Yours:** the `INCLUDE_ASM` lines in your range, your symbols file, your header folder, `drafts/<area>/`,
  `scratch_c/`.
- **Not yours: don't edit**
  - `configure.py`, `tools/`
  - `include/common.h`, `include/shared/`
  - `config/*.yaml`, `config/symbols/main.txt`, `config/pins.txt`, `config/toolchain.toml`
  - `README.md`, this file
  - other areas' lines and files

  If you need a change in one of these (a build fix, a flag override, a shared type), describe it in your final
  report. Don't make it yourself.
- **Generated, never edit:** `asm/`, `build/`, `build.ninja`.

## Rodata hazards

- **Data a decompiled function uses by name.** splat moves rodata that only one function uses into that function's
  `.s`. Once the function is decompiled its `.s` isn't built, so that data disappears and the link fails with
  `undefined reference to D_XXXXXXXX`. Fix it in **your** symbols file: `D_XXXXXXXX = 0xXXXXXXXX;
  // force_not_migration:True`, then re-split. (For the EXE, the existing ones are in
  `config/symbols/main_keep_rodata.txt`.)
- **Jump tables.** GCC puts `.align 3` before each one, aligning it to 8 *relative to its object's rodata*, so all
  tables of one original file share an address mod 8. `tools/jtbl_classes.py` lists the runs; a change of
  remainder is a file boundary, and every unit's rodata starts at its first table. If your function's table is
  4 bytes off in the full build, its unit is wrong: leave it as a draft and report it (don't change the yaml).
- **A jump table in the middle of the unit's rodata.** A decompiled function's table is emitted at the
  function's place in the source. Rodata comes out in source order: `INCLUDE_RODATA` lines, rodata that splat
  migrated into an `INCLUDE_ASM` function's `.s`, and compiled tables. So when the table's retail address falls
  inside a run of other rodata, do this:
  1. Move the `INCLUDE_RODATA` lines for everything above the table's address so they come after the function.
  2. Rodata that sits inside an earlier `INCLUDE_ASM` function's `.s` can't move. Give it
     `force_not_migration` in your symbols file and re-split, which turns it into its own `INCLUDE_RODATA`
     line; then move that line too.

  Keep the lines in address order. Check with the full build, not just `try_compile`, which can't see this.
  Example: `func_8007C6A8`'s `jtbl_80017048` (main_b2).
- **String literals and other const data written in C.** With `-G8` GCC emits a file's data before its
  functions, so a literal lands at the start of the unit's rodata instead of beside its function. Refer to the
  retail symbol instead (`EXTERN_C const char D_XXXXXXXX[];`) and keep it with `force_not_migration` in your
  symbols file. Data of 8 bytes or less would go to `.sdata` and break the link.

## Globals in the EXE

A small global uses `$gp` only in the unit that defines it, as with ASPSX. The build gives `$gp` exactly to the
symbols your unit's retail asm reaches through `%gp_rel` (`tools/cc.py --gp-from`, automatic with `--unit`). So
declare small globals plainly (`EXTERN_C int D_X;`): where retail uses `$gp` you get `$gp`, and where it uses
`lui` you get the assembler's `lui $dst; lw $dst, %lo(D_X)($dst)` macro. If a header already declares the
symbol with another type, alias it: `EXTERN_C int D_X_word asm("D_X");`. For GCC's split form (another register
as the temporary), use an incomplete array or a struct > 8 bytes, as in the overlays below.

Because a symbol is reached one way only inside one original file, a unit where retail reaches it both ways
holds two files. `tools/gp_boundaries.py` reports any such clash; there are none now. If a function of yours
only matches with the other form, report it. Don't work around it.

## Globals in overlays

Overlays were compiled with `-G8` and assembled with `-G0` (`{ cflags = "-O2 -G8", as_G = 0 }`), so `$gp` is never
used. How a global is declared decides which of two retail forms comes out:

| Declared as | Retail form | Example |
|---|---|---|
| a small object (≤ 8 bytes: `int`, a pointer) | assembler macro: `lui $dst; lw $dst, %lo(sym)($dst)` (the loaded register is the temporary) | CAPTURE `func_800B9E10` |
| an incomplete array (`int D_X[];`, used as `D_X[0]`) or a struct > 8 bytes | GCC splits the address itself: `lui $v0; lw $dst, %lo(sym)($v0)` (another register is the temporary) | BATTLE `func_800BE390` |

Try the other declaration whenever only the temporary register differs.

**Data you define** in an overlay `.cpp`: anything ≤ 8 bytes goes to `.sdata` under `-G8`, which moves it out of
place. Keep such data as `INCLUDE_RODATA`, or define it as part of an aggregate larger than 8 bytes (e.g. the whole
overlay header as one struct).

After a build, `tools/func_diff.py <target>` lists the functions that no longer match retail, which helps when the
matching check fails.

## Brute-forcing a near miss

For a draft a few instructions off on register allocation or instruction order, run
[decomp-permuter](https://github.com/simonlindholm/decomp-permuter) (`bin/decomp-permuter`, copied by
`worktree_setup.py`; rerun it if your worktree predates it). It rewrites the C at random, compiles each candidate
with your unit's real flags, and keeps whatever scores closer to retail:

```powershell
.venv/Scripts/python.exe tools/permute.py setup drafts/<area>/func_X.cpp func_X --unit src/<area>/<file>.cpp
.venv/Scripts/python.exe tools/permute.py run permuter/func_X -j 8 --stop-on-zero --best-only
```

- `tools/twins.py asm/<target>` lists functions still in asm that nearly match one already decompiled, which is often the same source with other constants. Check it before starting a function from scratch.
- Use at most `-j 8`: seven sessions share the machine's 40 threads, and each candidate takes about 0.7 s.
- Results land in `permuter/func_X/output-<score>-<n>/source.c` (`permuter/` is git-ignored). Score 0 is a
  match. Copy the function back into your scratch file and confirm with `try_compile.py` before landing it.
- The permuter parses C only. `setup` keeps the C parts of your headers and drops C++ classes (pointers to
  them still work), but the function itself must be plain C: no member functions, virtual calls, `this`,
  references or `new`/`delete`. If it isn't, `setup` says so.
- Read every result before you use it. The permuter will happily read uninitialised variables, put statements
  after `return`, or drop side effects to get a better score. Code like that is not a match, even when
  `try_compile` says 0. Keep only rewrites that do the same thing as the draft.
- Give it 20–60 minutes per function. If the score doesn't move, the difference is probably not one the
  permuter can reach.

## Names and types

- Keep `func_XXXXXXXX` / `D_XXXXXXXX` unless you're confident of a name. Rename only through your symbols file
  (`name = 0x...; // type:func`), then re-split.
- Member functions compile to mangled names (`run__4Item`). Add the mangled name to your symbols file at the
  function's address.
- Put types in your header folder. If a type is clearly used outside your area (the `List`/`Item` classes in
  `func_800186E8`, say), still define it in your folder, and list it in your report so it can be moved into
  `include/shared/`.

## When you stop

Stop and report after about 25 functions have landed and been committed, or when nothing easy is left. The
integrator merges your branch, and then asks you to `git merge master` and carry on. The report is short:
- how many functions landed, with their address range
- matching and functional status
- drafts left (with what differs)
- anything that needs a change outside your area
- types that look shared
