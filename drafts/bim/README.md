# BIM.AR module functions still in asm

73 module functions are still `INCLUDE_ASM` in `src/bim/w*/`: 70 one-off `func_` functions and the 3 copies of
`bimf_d408bc6f`. The generators and notes that landed the rest are in `tools/round4/bim-shared/` and
`tools/round4/bim-patterns/` (their `NOTES.md`), and the tricks that cracked whole families are in `docs/PARALLEL.md`.

## Near misses (drafts here)

| Function | Copies | Off by | What differs |
|---|---|---|---|
| `bimf_d408bc6f` | 3 | 2 | In `case 2/3`, retail branches `beqz s0, <return 0>; j <D64>` after the 0x421 fallback; ours inverts it to `bnez s0, <D64>; j END; v0 = 0`. The `goto fail` to a final `return 0` that fixed `bimf_51caf7a0` swaps the blocks here instead. The permuter found nothing in 30 min. |
| `func_800DB624` (`w0_fb98fcc327`) | 1 | 8 | Like `bimf_06b4d1a5`, but two paths fall off the end with no `return` (retail returns whatever is left in `$v0`, as `bimf_e310b46d` does). Retail's `f9E4 == 0` `return 0` is an out-of-line `j END; v0 = 0` block after the handler call. The permuter's best was 200 after 30 min. |

`func_800DB378_draft.cpp` and `func_800DB634_draft.cpp` are from the earlier round and still apply.
The other files here have landed (kept for reference): `bimf_050d93e7`, `06b4d1a5`, `29503d9b`, `38dc0e9d`,
`3e5937f3`, `7209819a`, `b4962b94`, `dd77db6b`, `e310b46d` and `func_800DAB3C_ctor`.

## The 70 one-off `func_` functions: why they're parked

None of them fits one of the generated families any more. Each is a hand-written monster action handler or
selector, one copy per module, mixing `rand`, the 7ECC/7A4C/7A78/7D64 move calls, 81FC, 8064, 8634, 8854 and
module-local handlers in its own control flow. Batches 2 and 3 landed functions of this kind at about 5–20 min each
by hand, so they're tractable, just not in bulk. Notes for whoever picks them up:

- Start from the closest landed function (`generators/bimtwins.py` ranks them), then rewrite the
  control flow from the asm.
- `try_compile` masks `j`/`jal` targets. Always rebuild and look for `differs` or link errors: a wrong callee or a
  wrong jump target can still show 0 differing instructions.
- Matching idioms that came up again and again:
  - Write `&&` chains of calls as nested `if`s, or GCC computes a boolean in a saved register.
  - When a branch picks one argument of a call, write two separate calls in `if`/`else`.
  - Put the `!s` branch before the `else` with the 7A78 test.
  - Duplicate each success tail (`*flags &= ~2; return 1;`) instead of sharing it through a `goto`.
  - Use one function-scope `void *s`/`q` for every phase.
  - `switch` reproduces `beq 1 / blez / slti 4`.
  - `rand() * 99 >> 2` tested with `x != x / 2 * 2`.
  - A missing final `return` reproduces paths that branch to the epilogue without setting `$v0`.
- The selector generator (`generators/gen_sel2.py`) skips any function containing a call it doesn't know. Several of the 70
  are selectors with inline action code (for example `func_800DB040` and `func_800DB0A0`), written like
  `bimf_35f30ee4`.

## Round-2 scripts (`generators/`)

They import each other from `scratch_c/`, so copy them there first, then run them from the repository root.

- `try_gen.py <gen module> <list of .s paths>` tries each generator's candidates with `try_compile` and records the
  matches in `scratch_c/ok_<gen>.json`.
- `install_ok.py <json>...` installs the matches: a shared file when every copy of a hash matched with one body,
  otherwise per-module definitions.
- The generators:
  - `gen_sel2.py`: selectors.
  - `gen_cmd.py`: e310b46d/dd77db6b-style command handlers.
  - `gen_a6f0.py`, `gen_6d10.py`, `gen_227c.py`: one-off variants.
- `bimtwins.py` and `twin_adapt.py`: find a landed twin and adapt it.
- `scan_fall2.py` and `mr_try.py`: the missing-`return` sweep outside BIM (43 asm hits, none tractable).
