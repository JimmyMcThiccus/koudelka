# Round-1 session helpers (snapshot, unmaintained)

Scripts the round-1 decompile sessions wrote in their git-ignored `scratch_c/`, saved before their worktrees were
removed. They ran from `scratch_c/` inside a worktree and were written for the layout of the time: one
`src/main/game.cpp`, overlays built with `-G0`, `try_compile.py` without `--unit`. Several still say `game.cpp` or
`asm/main/nonmatchings/game`, and `battle/mkpre.sh` and `battle/show.sh` hard-code the old
`Koudelka-wt/battle` path. Treat them as starting points to adapt, not tools to run as-is.

The pattern most of them share is worth keeping: a **sectioned scratch file**, one shared prelude (types, externs)
followed by one section per function, which is tested function by function and then landed in bulk.

| Script | What it did |
|---|---|
| `main_a/gen.py` | Generated C++ for trivial accessor-style functions (getters, setters, constant returns) from their asm, by pattern; wrote a header plus a `{func: code}` JSON. Landed ~345 functions in round 1. |
| `main_a/apply.py` | Replaced `INCLUDE_ASM` lines with code from that JSON. |
| `main_a/multi.py` | Tested every `//// func_X` section of a scratch file (prelude + section) with `try_compile.py`. |
| `main_a/land.py` | Landed a sectioned scratch file: prelude into a header, each section over its `INCLUDE_ASM` line. |
| `main_a/fixdecl.py` | Reconciled declarations between `main_a.h` and the source. |
| `main_a/dump.py`, `list.py` | Listed functions by size and printed compact asm, to pick batches. |
| `main_a/wrappers.py` | Generated one-call wrapper functions from a pattern dump. |
| `battle/batch.py`, `battle/land.py` | Same sectioned test-then-land flow (`//@ func_X` sections) for BATTLE. |
| `battle/mkpre.sh`, `battle/show.sh` | Built the scratch prelude from `battle.h`; printed compact asm for addresses. |
| `capture/batch.py` | Sectioned tester (`//== func_X`) that inlines `#include`s from `include/`. |
| `capture/build.sh` | Ran both build modes and printed the two OK counts. |
| `capture/show.sh`, `movie/d.sh` | Compact asm of functions (nonmatchings or matchings). |
| `movie/run.sh`, `movie/mkprelude.py` | Compiled `scratch_c/b/<ADDR>.cpp` with a prelude generated from `movie.h`. |
| `movie/tv.sh` | Tried several bodies in a template and stopped at the first exact match. |
| `movie/land.py` | Landed matches into `movie.cpp` + `movie.h`, renaming placeholder locals. |
| `gameend/t.sh`, `gameend/offs.sh` | Compiled one function with a shared header; diffed struct-offset variants. |
