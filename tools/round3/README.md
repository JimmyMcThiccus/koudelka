# Round-3 session helpers (snapshot, unmaintained)

Scripts from the `scratch_c/` folders of the seven round-3 sessions, saved before their worktrees were removed.
One-off variant scripts (`v_*`, `var*`, `gen*`, `perm*` variants) were dropped. They ran from `scratch_c/` in a
worktree; adapt them rather than running them as-is. The maintained tools (`try_compile.py`, `permute.py`,
`twins.py`, `gp_boundaries.py`) are in `tools/`.

Most do the same three jobs as round 2 (see `tools/round2/README.md`): test a sectioned scratch file
(`multi.py`, `mb.py`, `batch.py`, `battle-batch.py`), land its matching sections (`land.py`, `hland.py`,
`apply.py`, `battle-land.py`, `landagents.sh`), and dump compact asm (`dump.py`, `sa.py`, `show.sh`). New this
round:

| Script | What it did |
|---|---|
| `main-b1/vbinfo.py`, `main-b1/gen_dtor.py` | read a virtual-base ctor/dtor's vtable copies and deltas from its asm, and generate the hand-written form (`docs/PARALLEL.md`, "Virtual-base constructors and destructors") |
| `main-b1/classify.py` | sorted remaining functions by kind (vbase ctor/dtor, switch, leaf, ...) |
| `field/hb_gen.py`, `field/hl_mk.py`, `field/mkdraft.py` | handed batches of functions to helper agents and collected their drafts |
| `field/pairs.py` | the first version of `tools/twins.py` |
| `main-a2b/runperm.sh`, `battle/permrun.sh` | ran `tools/permute.py` over a list of drafts |
| `battle/revert_fn.py` | put a function back to `INCLUDE_ASM` |
| `small/ip.py` | compared a function inside its real unit's object (superseded by `try_compile.py`'s symbol lookup) |
