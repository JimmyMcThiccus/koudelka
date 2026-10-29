# r4b: BIM.AR shared functions (branch claude/bim-shared-a33f3d worktree r4b-main-a2b-d536dd)

Landed 27 shared functions (29 in src/bim/shared with the 2 existing), INCLUDE_ASM bimf_ lines 654 -> 337.
Both modes green (93x identical functional, 93x check: OK matching).

## Drafts (not in src/bim/shared; in drafts/bim/)
- bimf_dd77db6b (21 copies): 27 differing instrs. Retail copies `v1=v0` before `sw v1,0x9F0`; AC4 path jumps to a tail shared with the BB4 path.
- bimf_b4962b94 (21) 12 diff, bimf_a6f0c006 (14, same shape with 8E64(p,1)): retail puts `j end; v0=0` (return-0 block) in the middle with `bnez` into the success block; GCC keeps success inline.
- bimf_e310b46d (20) 17 diff (tail layout of the final two-bit clear). 9b3b5928 (14), 0ae2aad9 (14) are the +1 siblings, not tried.

## Blocked: calls to a sibling shared function with a per-module suffix
bimf_06b4d1a5 (50 copies) calls bimf_af99c5b3, but in the 50 modules the callee is _3 (38), _1 (4), _4 (6), plain (2).
A shared body can't name the right one; same for 29503d9b, 1d1122f5, cb8fde67, c744c68b (call 06b4d1a5/dd77db6b/... siblings), fddfe66d (calls 096f4279).
Needs tools support (e.g. bim_sync emitting `#define` aliases for callees per module) - not something I can do.

## Tricks that mattered
- `v != v / 2 * 2` (not `% 2`) for the signed mod-2 test (e32ca3a9).
- switch with identical case bodies written out per case (no fallthrough, no gotos) reproduces the unmerged compare tree (374ba601, d3d03f70).
- `return f & 1` style tails for flag handlers (db5f4bc4).
- Declarations all live in include/bim/shared.h (single place, so every shared file agrees; includes bim/bim.h).

## Batch 2 (46 shared files now; 337 -> 269 INCLUDE_ASM bimf_ lines)
Matching idioms learned:
- `ret = 1` assigned in each branch and one `return ret` (not several `return 1`) reproduces retail's shared-tail layout (22b1759c).
- Several `return 0` exits that GCC merges into one block: make two of them distinct with `if (p || flags) return 0; else return 0;` (permuter find; b4962b94, a6f0c006, 81cee1ab). 72fa68c8 needs the same dummy at the very end but with an unset local (`p || q`) - register allocation only.
- Uninitialised-local dummy test in 72fa68c8 is the one thing to eyeball; both arms return 0.
Still drafts (drafts/bim/): dd77db6b/e310b46d/9b3b5928/0ae2aad9 (the 69-copy flag-handler family), 7209819a (14 diffs), 38dc0e9d, 050d93e7 (2 diffs), and ~20 table initialisers (3e5937f3 ac9e0f11 17d53c09 62bd47cb 57069eeb 9ee8aced 2f8bc8bf ...): all stuck on the same tail scheduling (retail does `sll a1` early, `lw D_800B4D38` and `sra` after the 25+ stores; ours hoists both). gen_tbl.py in scratch_c/ writes the store list from the asm.

## Batch 3: per-module func_ functions (generators in r4b-generators/)
Generated C for 106 module functions (299->... func_ lines 415 -> 309), all byte-identical (clean rebuild both modes):
- 85 factories `new T(args)` (124 B, one per module): gen_factory.py
- 14 virtual-base dtors with module vtables (func_ names): gen_dtor2.py
- 7 three-way dispatchers (switch on f9F0 calling shared handlers, no jump table): gen_disp3.py
Blocked / needs your decision:
- JUMP-TABLE DISPATCHERS: groups of 27 (func_800DB3B4-like), 14 and 13 functions (+~15 smaller) are `switch (f9F0)` with a jump table calling bimf_ handlers.
  gen_disp1.py writes them and the C compiles to the same code, but every module comes out +4 bytes: the module's cpp rodata starts at the monster tail
  (0x800DA86C, 4 mod 8) with 12 bytes of D_800DA86C before the table at 0x800DA878; gcc's `.align 3` for the table then aligns the section to 8 and pads 4.
  Fix is in the generated configs (gen_bim_targets.py): start the cpp's rodata segment at the first jump table (as for the overlays), i.e. keep D_800DA86C in the header rodata.
  With that, ~70 more functions fall to the same generator.
- vbase constructors (6+3+3+3+3+2*... ~30 funcs, gen_ctor1.py): 2 instructions off (retail does `v0 = s0` and stores the last two fields via v0); permuter's zero was a C-mode artifact.

## Batch 4 (after the jump-table rodata fix)
- 27 group-1 jump-table dispatchers landed (gen_disp1.py): clean rebuild identical in both modes.
- gen_disp2.py (variants 'check3' = 14 fns, 'plain' = 13 fns): C compiles to the same size but the default tail differs in retail:
  retail `lw v0,f9F0; beqz v0,END; addu v0,0 (delay); sw zero,f9F0; END` (no second `v0=0`); we always get an extra `addu v0,zero` after the sw
  (5 / 12 differing instructions). Tried ~12 source forms and the permuter (15 min) - none. Parked; the 'check3' modules differed by sha in a CLEAN build only
  (functional-mode incremental builds print `differs` informationally and "functional check: OK" does not catch it - check with matching mode or grep differs).
- Handlers called from dispatchers are declared via `asm("name")` aliases (`name_c`) to avoid clashes with the shared definitions' parameter types.

## Batch 5
KEY FIX: the earlier 'check3'/'plain' dispatcher tails were wrong because failed cases must `break` to the shared `if (f9F0) f9F0 = 0; return 0;` tail, not `return 0` (gen_disp2.py now does that): +27 dispatchers.
More generated families: gen_d4..d7 (3-way/5-way dispatchers, 10 fns), gen_sw.py (jump-table `switch (func_800D8E64_a(p))` -> func_80082670 pairs, 5 fns).
Hand-written: ~25 small handlers (flags&2 + func_800D7818 effect + 0x421 action idioms; see git log).
Still parked: vbase ctors (~30, 2 instrs), func_800DB634/func_800DB378 drafts (drafts/bim), func_800DB794 (11 diffs), dd77db6b family, table initialisers.
Trap: `functional check: OK` does not detect same-size mismatches; use matching mode or look for `differs`.

## Batch 6 (INCLUDE_ASM 489 -> 443, 46 lines removed)
New idioms: (1) when a branch ends `ret=1; p->f9F0=ret` and another branch does the same job, write the branches with DUPLICATED tails and a branch-local `int r = 1` (bimf_dd77db6b, 0ae2aad9, func_800DB188); (2) per-branch duplicate of the "D64; clear; return 1" tail instead of one shared tail (bimf_050d93e7, 7209819a); (3) the `if (p || flags) return 0; else return 0;` dummy keeps an early `return 0` as its own block (7209819a, func_800DB794 with `ok = ` reuse).
Permuter caveat confirmed: its "zero" is only trusted when try_compile agrees (it compiles in C mode; ctor, e310 results were artifacts).
Open: bimf_e310b46d/9b3b5928 (34 copies, 17 diffs, tail layout), 38dc0e9d, func_800DB634/DB378, table initialisers (~80 fns), vbase ctors (~30).

## Batch 7 (INCLUDE_ASM 443 -> 387)
- bimf_06b4d1a5 (50 copies): the callee bimf_af99c5b3[_N] differs per module, so it is written PER MODULE by scratch gen_06b.py (definition named bimf_06b4d1a5[_N] directly in each module .cpp, callee through an asm("name") alias). No shared file; bim_sync leaves it alone. The same trick would work for 29503d9b (6), 1d1122f5 (9), cb8fde67 (4), c744c68b (3) once their body matches: 29503d9b is 8 bytes over (retail does `j end` with `addiu v0,1` in the delay slot after `f9F0 = 0x10`).
- bimf_096f4279: `switch (id) { case 1: case 2: case 3: break; case 4: return 0; }` reproduces blez/slti/beq.
- dummy `if (p) return 0; else return 0;` again (permuter find) in 06b4d1a5.

## Batch 8 (INCLUDE_ASM 387 -> 365, 22 removed)
- 29503d9b / 1d1122f5 / cb8fde67 / c744c68b (22 copies): selector with 7818 effect, vcall 21, handler chain. Per-module generation (gen_29.py). The permuter found `if (dd77 handler) { if (p || flags) return 1; else return 1; }` for the variant whose f9F0 store is `sw; j; addiu`; the other variants need no dummy; 1d1122f5 ends `handler(); return 1;`. For the permuter the virtual call must be written as explicit vtable loads (plain C): `((int(*)(void*,int))*(void**)(vt+0xB4))((char*)p + *(short*)(vt+0xB0), x)`.
- dummyscan.py tries the `p||flags` dummy at every `return` of a draft: no hit for bimf_e310b46d/9b3b5928 (their retail tail keeps a separate bit-1 clear block; ours merges it with the early `&= ~2` tail).
Remaining: 365 = 214 func_ (table inits ~80, vbase ctors ~30, misc) + e310 family 34 + small 2-3 copy functions.
