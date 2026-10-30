# Round-4 session helpers (snapshot, unmaintained)

From the `scratch_c/` folders of the round-4 track B (main_a2b) and track C sessions; the FIELD and main_b2 track B
sessions left none. Adapt rather than run as-is: they ran from `scratch_c/` in a worktree.

- `main-a2b/land.py`, `main-a2b/mk.sh`: land a matched scratch function into its unit; build both modes
- `near/mk.py`: test a near miss in its real unit with `try_compile.py`
- `bim-base/genhdr.py`: generated `include/bim/` declarations from the asm; `bim-base/perm49420.py`: statement-order permutations for one function
- `bim-shared/`: the BIM.AR module session's generators (`gen_*.py`: write the same function per module from its asm, by pattern; `groups.py`, `install.py`) and its `NOTES.md` (what matched, what is parked and why)
- `bim-patterns/`: the Opus pattern session's generators (table initialisers, the vbase ctors) and its `NOTES.md`
