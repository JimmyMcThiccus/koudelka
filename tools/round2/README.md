# Round-2 session helpers (snapshot, unmaintained)

Scripts the round-2 sessions wrote in their git-ignored `scratch_c/`, saved before their worktrees were removed
(one folder per area; main_b's one-off `fix*.py` edits were dropped). They ran from `scratch_c/` inside a worktree,
against the round-2 layout (before the per-unit `$gp` lists and the six EXE jump-table splits). Adapt, don't run
as-is.

The useful ones, by job:

| Job | Scripts |
|---|---|
| Test a sectioned scratch file (shared prelude, one section per function) | `main-a1/multi.py`, `main-a2/multi.py`, `main-b/mb.py`, `field/batch.py`, `battle/battle-batch.py` |
| Land the matching sections over their `INCLUDE_ASM` lines | `main-a1/land.py`, `main-a2/land.py`, `main-b/land.py`, `main-b/landok.sh`, `field/apply.py`, `battle/battle-land.py`, `movie-gameend/land_all.py` |
| Print compact asm of the functions left, by size | `main-a1/dump.py`, `main-b/dump.py`, `field/sa.py`, `sound/a.sh` |
| Brute-force statement or store order | `sound/perm.py`, `main-b/perm.py`, `movie-gameend/var.py` |
| Check declarations against the headers | `main-a2/chk.py`, `main-a2/gendefs.py`, `main-b/decl.sh`, `field/fwd.py` |
| `$gp` versus `lui` scans (the evidence for per-unit `$gp`) | `main-b/gpscan.py`, `main-b/luiscan.py` |
| Build both modes and print a verdict | `main-a1/build.sh`, `main-a2/build.sh`, `battle/verify.sh`, `movie-gameend/build.sh` |
| Swap string literals for retail rodata symbols | `movie-gameend/fixstr.py` |
