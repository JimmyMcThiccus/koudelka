# Working in parallel

Several sessions can decompile at once, each in its own git worktree and branch and each owning one **area**.
The areas don't overlap, so their branches merge cleanly.

## Areas (round 2)

The EXE's game code is split into 29 source units, one per original source file where the `.ctors` table marks
one: `src/main/u_<start address>.cpp`, plus `main_a.cpp`, `main_b.cpp` and `sound.cpp`. An area is a set of whole
units, so two sessions never edit the same file.

| Area | Units (`src/...`) | Functions left | Your symbols | Your headers |
|---|---|---|---|---|
| `main_a1` | `main/main_a.cpp`, `main/u_80018B88` … `main/u_8002ED44.cpp` (16 units, `0x800186B0`–`0x80032264`) | 548 | `config/symbols/main_a.txt` | `include/game/a/` |
| `main_a2` | `main/u_80032264` … `main/u_8003C510.cpp` (5 units, `0x80032264`–`0x80054A2C`) | 549 | `config/symbols/main_a2.txt` | `include/game/a2/` |
| `main_b` | `main/main_b.cpp`, `main/u_80056E0C` … `main/u_80082174.cpp` (7 units, `0x80054A2C`–`0x8008B6B0`) | 552 | `config/symbols/main_b.txt` | `include/game/b/` |
| `sound` | `main/sound.cpp` (the sound driver: PsyQ 4.1, `0x8008B6B0`–`0x80094910`) | 180 | `config/symbols/sound.txt` | `include/game/sound/` |
| `field` | `field/field.cpp` | 468 | `config/symbols/field.txt` | `include/field/` |
| `battle` | `battle/battle.cpp` | 283 | `config/symbols/battle.txt` | `include/battle/` |
| `effect_capture` | `effect/effect.cpp`, `capture/capture.cpp` | 138 + 86 | `effect.txt`, `capture.txt` | `include/effect/`, `include/capture/` |
| `movie_gameend` | `movie/movie.cpp`, `gameend/gameend.cpp` | 135 (28 are Sony library code: leave them) + 1 | `movie.txt`, `gameend.txt` | `include/movie/`, `include/gameend/` |

Headers outside your folder are **read-only** for you, including ones your units already include: `main_a2`
reads `include/game/a/`, and `sound` reads `include/game/b/`. Put new declarations in your own folder and include
that header from your units. Use `--unit` with the unit file a function lives in (see "The loop"); the unit
boundaries are the `[0x..., cpp, u_...]` lines in `config/slus_010.51.yaml`.

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
- **Rodata the compiler emits** (a `switch` jump table, a string literal). It goes into your unit's `.rodata`. If
  that unit has no rodata segment in the yaml, or its rodata start isn't 8-aligned, the table lands in the wrong
  place and the matching check fails. Don't change the yaml: leave the function as a draft and say so in your
  report.

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

## Names and types

- Keep `func_XXXXXXXX` / `D_XXXXXXXX` unless you're confident of a name. Rename only through your symbols file
  (`name = 0x...; // type:func`), then re-split.
- Member functions compile to mangled names (`run__4Item`). Add the mangled name to your symbols file at the
  function's address.
- Put types in your header folder. If a type is clearly used outside your area (the `List`/`Item` classes in
  `func_800186E8`, say), still define it in your folder, and list it in your report so it can be moved into
  `include/shared/`.

## When you stop

End with a short report:
- how many functions landed, with their address range
- matching and functional status
- drafts left (with what differs)
- anything that needs a change outside your area
- types that look shared
