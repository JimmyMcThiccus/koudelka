# Round 4 plan

## Where round 3 left off

Master `060282e`: all 7 targets byte-identical in both modes. **666 functions are still `INCLUDE_ASM`, about 88%
decompiled** by count (round 3 started at 1,017, after round 2's 81%). Seven Sonnet sessions landed 351 in round 3.
The last batches fell to 1–5 functions each, so the round was ended.

| Area | Left | Notes |
|---|---|---|
| FIELD | 127 | most of the large functions; 38 drafts |
| main_a2b (`u_8003C510` … `u_80045850`) | 115 | 22 drafts; `func_80045EB8` is a vbase ctor still open |
| main_b2 (`u_80068770` … `u_80089024`) | 129 | `func_8007C6A8` needs the mid-run jump-table fix (see `docs/PARALLEL.md`) |
| small (effect, capture, movie, sound, main_a1) | ~117 | about 45 are not C: 28 Sony library (MOVIE), ~15 hand-written asm |
| main_b1 | 85 | |
| BATTLE | 78 | 64 drafts |
| main_a2 | 28 | |

What's left, by kind:
- **Large functions** (300+ instructions) nobody has attempted. Ghidra's decompile (now seeded with every
  function under our names) is the way in.
- **Near misses**: 214 drafts in `drafts/`, 27 of them 1–4 instructions off, almost all register allocation or
  scheduling. The permuter landed a handful; it rarely moves these.
- **Virtual-base ctors/dtors**: no longer blocked. The hand-written recipe in `docs/PARALLEL.md` works in every
  area.

Tools that now exist:
- `try_compile.py`: compares the named function
- `permute.py` (decomp-permuter)
- `twins.py`
- `gp_boundaries.py`
- `alias_report.py`
- Ghidra over MCP: read-only for sessions

## Tracks

**A. Prototype consolidation (first, alone).**
- **Problem:** `tools/alias_report.py` finds 604 functions declared with more than one prototype. Each area's
  headers declare the EXE functions with its own guessed types, plus about 300 `asm("func_X")` aliases. A PC port
  needs one prototype per function, and new work keeps adding aliases.
- **Approach:**
  1. Build `include/shared/exe.h` with one prototype per EXE function, taken from its decompiled definition
     where there is one, else from its asm and callers.
  2. Move each area over to it, one area per commit, rebuilding both modes each time. A caller whose code changes
     with the right prototype keeps a local alias, with a comment saying why.
- **Who and how long:** one session (Opus, because the type decisions need judgement), with no other session
  running, since it touches every header. About a day.

**B. Large functions, Ghidra first.**
- **Work:** 2–3 Sonnet sessions on the areas with the most unattempted large functions: FIELD, main_b2,
  main_a2b.
- **Batches:** 10 functions, not 25. Report after each.

**C. The 27 closest near misses.**
- **Work:** one Opus session, listed from the drafts' first lines, with a time box per function. Exact matches
  only, as always.
- **When:** in parallel with B, since it edits different functions in the same areas. Areas are split by
  function list.

The track C list: 28 functions still in asm, each with a draft 1–4 instructions off, or a little more where the
shape is right. Drafts are in `drafts/<area>/` (`func_X.cpp`, or a section of `r2_attempts.cpp`/`r3_attempts.cpp`),
and each `drafts/*/README.md` says what differs.

| Function | Unit (`src/`) | Off by |
|---|---|---|
| `func_800C56A8` | `battle/battle_b.cpp` | 2 |
| `func_800B881C` | `battle/battle.cpp` | 2 |
| `func_800C8D9C` | `battle/battle_b.cpp` | 3 |
| `func_800CFDE0` | `battle/battle_c.cpp` | 3 |
| `func_800BDEDC` | `battle/battle.cpp` | 4 |
| `func_800C666C` | `battle/battle_b.cpp` | 4 |
| `func_800BC394` | `field/field.cpp` | 4 |
| `func_800C0654` | `field/field.cpp` | 4 |
| `func_800E44D4` | `field/field_b.cpp` | 4 |
| `func_800E2C08` | `field/field_b.cpp` | 4 |
| `func_800BE264` | `field/field.cpp` | 4–5 |
| `func_800BDEA4` | `field/field.cpp` | 4–5 |
| `func_8003479C` | `main/u_80033ECC.cpp` | 3 |
| `func_80035C30` | `main/u_80033ECC.cpp` | 3 |
| `func_80032B2C` | `main/u_80032264.cpp` | small, register allocation |
| `func_800468D8` | `main/u_80045850.cpp` | 2 |
| `func_8004A89C` | `main/u_80045850.cpp` | 3 |
| `func_80054584` | `main/u_80045850.cpp` | 4 |
| `func_800499D0` | `main/u_80045850.cpp` | ~6, prologue order |
| `func_8004D0F4` | `main/u_80045850.cpp` | ~6, prologue order |
| `func_8003C908` | `main/u_8003C510.cpp` | 4 |
| `func_8006B180` | `main/u_80068770.cpp` | 2 |
| `func_8008623C` | `main/u_80085168.cpp` | 2 |
| `func_8008A2A0` | `main/u_80089024.cpp` | 3 |
| `func_8007FD60` | `main/u_80071A74.cpp` | 3 |
| `func_8005717C` | `main/u_80056E0C.cpp` | 3 |
| `func_80026558` | `main/u_80025854.cpp` | 2 |
| `func_8008D97C` | `main/sound.cpp` (PsyQ 4.1) | ~9, shape right |

**D. PC-port feasibility (optional, read-only, any time).**
- **What it measures:**
  - which PsyQ functions the game calls, compared with what PsyCross implements
  - how much `.data`/`.rodata` holds pointers
  - which asm routines would need rewriting
- **Output:** a sized estimate. It changes no source.

## Order

A, then B and C together. D can run any time because it changes nothing. The same rules and moderation as round
3: exact matches only, the integrator reviews and merges each batch, and master is pushed after every verified
merge.
