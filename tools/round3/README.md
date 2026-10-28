# Round-3 session helpers (snapshot, unmaintained)

Scripts from the `scratch_c/` folders of the four round-3 sessions stopped after batch 3 (main_a2, main_b2,
battle, small). One-off variant scripts (`v_*`, `gen_*`, `perm_*`) were dropped. They ran from `scratch_c/` in
a worktree; adapt them rather than running them as-is. The maintained tools (`try_compile.py`, `permute.py`,
`twins.py`, `gp_boundaries.py`) are in `tools/`.

Most are the same three jobs as round 2 (see `tools/round2/README.md`): test a sectioned scratch file
(`multi.py`, `mb.py`, `battle-batch.py`), land its matching sections (`land.py`, `battle-land.py`,
`landagents.sh`), and dump compact asm (`dump.py`, `show.sh`). New this round:
- `small/ip.py`: compares a function inside its real unit's object (superseded by `try_compile.py`'s symbol lookup)
- `battle/permrun.sh`: runs `tools/permute.py` over a list of drafts
- `battle/revert_fn.py`: puts a function back to `INCLUDE_ASM`
