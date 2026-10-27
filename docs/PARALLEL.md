# Working in parallel

Several sessions can decompile at once, each in its own git worktree and branch and each owning one **area**.
The areas don't overlap, so their branches merge cleanly.

## Areas

| Area | Source | Range | Your symbols | Your headers |
|---|---|---|---|---|
| `main_a` | `src/main/game.cpp` | functions `0x800186B0`–`0x80054A2C` (1,712) | `config/symbols/main_a.txt` | `include/game/a/` |
| `main_b` | `src/main/game.cpp` | functions `0x80054A2C`–`0x80094910` (1,561) | `config/symbols/main_b.txt` | `include/game/b/` |
| `field` | `src/field/field.cpp` | all (930 entries) | `config/symbols/field.txt` | `include/field/` |
| `battle` | `src/battle/battle.cpp` | all (568) | `config/symbols/battle.txt` | `include/battle/` |
| `effect` | `src/effect/effect.cpp` | all (418) | `config/symbols/effect.txt` | `include/effect/` |
| `capture` | `src/capture/capture.cpp` | all (330) | `config/symbols/capture.txt` | `include/capture/` |
| `movie` | `src/movie/movie.cpp` | all (364) | `config/symbols/movie.txt` | `include/movie/` |
| `gameend` | `src/gameend/gameend.cpp` | all (16) | `config/symbols/gameend.txt` | `include/gameend/` |

The `main_a` / `main_b` split sits at a real source-file boundary: `func_80054A04` is a static constructor (the
last function of its file), and the next file starts at `0x80054A2C`.

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
   .venv/Scripts/python.exe tools/try_compile.py scratch_c/f.cpp func_XXXXXXXX
   # overlays: add --asm-dir asm/field --target extracted/disc1/BIN/FIELD.BIN --cflags "-O2 -G0"
   ```

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
