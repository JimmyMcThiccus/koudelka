# Static recompiler (`tools/recomp`)

Round 4, PC port, phase 1. `tools/recomp` turns each function that is still MIPS asm (`INCLUDE_ASM` in `src/`) into
C that runs natively in a 32-bit host build next to the decompiled C++. A port can then run before the decompilation
is finished, and a decompiled function replaces its recompiled twin one at a time.

**Short version**

- All **666** asm functions go through it: **656 translated, 10 stubbed** (an aborting stub with the reason). All
  666 output files compile with clang for `i686-pc-windows-msvc` (`-c`).
- The stubs are the three context-switch routines, four MOVIE routines that load `$gp` from BIOS memory, two
  "functions" that are really string data, and one libpress fragment that branches into the middle of another
  function. See "What it does not handle".
- **Differential tests**, over the original asm of functions that are already decompiled: **445 functions**
  (276 leaf, 169 calling native decompiled code), 1000 random trials each. **441 match on every trial, 0 fail.**
  In the other 4 the recompiled code follows the original asm and the decompiled C differs: a stack address stored
  into memory, and overlapping copies through random pointers. 287,925 trials returned in both builds with identical
  return values and memory.
- First real measurement of `docs/PORT_FEASIBILITY.md` item 1: with a 20-line `common.h` shim, **21 of the 53**
  `src/` files compile for the host as they are. The other 32 have 198 errors, mostly GCC 2.8's implicit function
  declarations in C++. Details under "Host compile of `src/`".
- The brief's toolchain recipe (`-isystem` for the MSVC and SDK headers) breaks every varargs call on i686. Let
  clang find Visual Studio itself. See "Toolchain".

Generated C is derived from the game's code, like `asm/`, so it is never committed: it goes to `build/recomp/`
and `build/recomp-test/`, both git-ignored.

---

## Running it

```bash
.venv/Scripts/python.exe -m tools.recomp --compile
```

writes `build/recomp/<target>/<func>.c` for every `INCLUDE_ASM` function, a header `recomp_<target>.h` per target
with all their prototypes, and `build/recomp/report.{md,json}` (stubs, notes, the functions that return a v0/v1 pair).
`--compile` also compiles every file with clang (`i686-pc-windows-msvc`, `-O2 -c`). About 20 s for everything.

Other options: `--target battle` (one target), `--funcs battle:func_800B8474,...` with `--matchings` (any function,
including decompiled ones, from its original asm), `--prefix recomp_` (rename the definitions, used by the tests),
`--static-rodata`, `--protos file.json` (prototype overrides, below).

```bash
.venv/Scripts/python.exe tools/recomp/test/difftest.py
```

runs the differential tests (about 10 minutes at the default 1000 trials; `--trials 300` takes 3–4). Results go
to `build/recomp-test/results.{md,json}`. Exit status 1 on any unexplained mismatch.

The set of functions follows `src/`: the recompiler reads the `INCLUDE_ASM` lines, so a function that gets
decompiled drops out of its output on the next run.

## Files

| File | What |
|---|---|
| `tools/recomp/asmfile.py` | Parses splat's `.s` files: functions (`glabel`), data blocks (`dlabel`), local labels, `%hi/%lo/%gp_rel` relocations. |
| `tools/recomp/mips.py` | Decodes MIPS I + GTE from the raw instruction word, and the registers each instruction reads and writes. |
| `tools/recomp/analyze.py` | The whole-program view (`Program`) and the per-function analysis. |
| `tools/recomp/emit.py` | C emission, and the prototype table (`Protos`). |
| `tools/recomp/cli.py` | The command line (`python -m tools.recomp`). |
| `tools/recomp/hostcc.py` | The clang command lines for the host. |
| `tools/recomp/runtime/recomp.h` | The header every generated file includes: types, memory macros, lwl/lwr, mult/div, GTE, call types, traps. |
| `tools/recomp/test/` | Differential tests: `difftest.py` (driver), `harness.c` (runner), `difftest.h`, `shim/common.h`. |

## How it works

**Input.** Every `.s` under `asm/` is parsed: the 666 nonmatching functions, the original asm of the 4,827
decompiled ones (`asm/*/matchings/`) and the 613 functions in `psyq.s`, 6,106 in all. The operation of each
instruction comes from its raw word, which the `.s` lines carry, so pseudo-ops (`beqz`, `negu`, `b`, `move`) need no
cases. The text is only read for relocations (`%hi(D_X+4)`, `%lo`, `%gp_rel`) and for branch and call targets.

**Whole-program facts.** Two facts about each function come from all 6,106, so call sites in the 666 can be typed:

- `stack_args`: how many incoming stack words it reads (loads at `sp_entry + 0x10` and up). 287 functions read
  some. The most is 12 for game code (`func_80070568`) and 22 for a PsyQ routine.
- `ret_pair`: whether any caller reads `$v1` after calling it (backward liveness at every call site; an `lwl/lwr`
  pair is a full write; calls to `exit` do not return). Then it returns v0/v1 as a `u64`. In the current set only
  `__udivmoddi4` does. A function that returns a pair makes its tail-call targets return pairs too.

**Per function.**

1. Instruction-level control flow. A branch's successor is its delay slot, and the delay slot carries the
   branch's transfer. A branch into a delay slot, a branch out of the function to something that is not a
   function, or a delay slot holding a branch is reported and stubbed. None of the 666 has the first or the last.
2. Forward dataflow of registers that hold `sp_entry + constant`. This gives the frame size, the incoming stack
   words read, and `$sp` at each call site (to size the outgoing area). A function that moves `$sp` by a run-time
   amount (`alloca`; only `func_80046998`) gets 16 KB of slack in its frame and a check after each `$sp` write.
3. Jump tables: a `jr` that is not `jr $ra` is matched to the `jtbl_*` whose `%lo` feeds it (searched back within
   its block). The table's entries are read from the function's own `.s` or from any `.s` in the target
   (`INCLUDE_RODATA`). Two functions have one table and a `jr` the search can't tie to it; the single table is
   assumed (noted in the report).

**Emission.** One C function per asm function. Registers are `u32` locals (zero-initialized). `hi`/`lo` are locals
too. Each asm line is kept as a comment. Labels are `L_<address>:`, and only branch and jump-table targets get one.

## The calling model

Recompiled code shares the address space and the calling convention with the native code, so either side can call
the other directly.

- **Signature.** `u32 func_X(u32 a0, u32 a1, u32 a2, u32 a3, u32 stk_10, u32 stk_14, ...)`. All four argument
  registers are always parameters, followed by one parameter per incoming stack word the function reads. The return
  type is `u64` (v0 low, v1 high) when `ret_pair`, else `u32`. Under cdecl on i686, returning `u64` in EDX:EAX is
  compatible with a caller that expects `int`, a pointer or `void`, and passing more arguments than a callee reads is
  harmless. That is why fixed `u32` signatures work against the real prototypes.
- **Frame.** A local `u8 frame[]` (8-aligned, zeroed) with `sp = frame + frame_lo`. The function's own
  `addiu $sp, $sp, -N` runs as written. The incoming stack parameters are stored at `sp + 0x10...` on entry, so code
  that reads its argument area, takes its address or walks it (`func_8008B150` walks `a1`, `a2`, `a3`, `stk_10`)
  sees the same layout. A function that takes the address of its incoming area also gets `a0`–`a3` copied to the
  home slots.
- **Direct calls** (`jal`, and `j`/branch to a function = tail call): `v0 = f(a0, a1, a2, a3, STK_U32(sp + 0x10), ...)`
  with as many stack words as the callee reads. A tail call is a call followed by `return`. The callee's
  declaration comes from the prototype table.
- **Indirect calls** (`jalr`, and `jr $reg` that is not a jump table): through `recomp_icall_t`,
  `u32 (*)(u32, u32, u32, u32, ...)`, with 12 stack words (the most any game function reads). The
  target goes through `RECOMP_ICALL_TARGET(x)`, a hook the port can define to map a PS1 address (from asm data
  vtables) to a host function until the tables are C data.
- **Caller-saved registers** survive a call in the C translation (the callee cannot touch the caller's locals). That
  is safe because compiled code never relies on a call clobbering them.
- **Prototype table** (`emit.Protos`). It defaults to the analysis (stack words, pair return), and `--protos` takes
  JSON overrides `{name: {"stack_args": n, "ret": "u32"|"pair", "varargs": bool}}`. That is the plug-in point for
  `include/shared/exe.h` (track A): generate the JSON from clang's AST of the header.

## Memory and symbols

- **Accesses** are `MEM_U32(addr)` etc. over `may_alias` types, plus `-fno-strict-aliasing` (the game reads the same
  bytes as `u8`, `u16` and `u32`). Accesses whose base is `$sp` use `STK_*` and skip translation. `MEM_*` go through
  `RECOMP_ADDR(a)`: identity by default; with `-DRECOMP_CHECK_ADDR`, through `recomp_check_addr(u32)`, which the port
  supplies to trap PS1 addresses that leaked into host code. Leave `/LARGEADDRESSAWARE` off and every `0x80xxxxxx`
  address is guaranteed unmapped, so a leaked PS1 pointer faults at once.
- **`%hi`/`%lo`** compute the real relocation of the *host* address: `lui $a1, %hi(D_X)` → `a1 = RECOMP_HI((u32)&D_X)`,
  `lw $a1, %lo(D_X)($a1)` → `MEM_U32(a1 + RECOMP_LO((u32)&D_X))`. Any pairing the compiler made (index added between
  hi and lo, `%lo(D_X+4)` with `%hi(D_X)`, one `%hi` shared by several `%lo`) gives the right address. The cost is a
  few ALU ops per access. Folding the pairs into `&D_X` is a later optimization.
- **`%gp_rel(D_X)($gp)`** becomes `(u32)&D_X`. `$gp` is not otherwise read: a function that reads or writes `$gp`
  any other way is stubbed.
- **Externs.** A data symbol is declared `extern u8 D_X[];` (C linkage), a function with its prototype from the
  table. Data blocks a function's `.s` defines itself (strings, constant tables) are emitted in its `.c` as `const`
  arrays (`RECOMP_RODATA` storage class, global by default), with symbol words as `(u32)&sym`.
- **Jump tables** become a `static const u32 jtbl_X[]` in the function's file, holding small case numbers instead of
  addresses. The table load runs as written and the `jr` becomes `switch (jt) { case 0: goto L_...; ... }`, with
  `default:` calling `recomp_bad_jump`. The function does not depend on the table's PS1 data at all.
- **Scratchpad.** `lui $r, 0x1F80` becomes `RECOMP_SCRATCHPAD_BASE`, the host address of a 1 KB array
  (`recomp_scratchpad`, 4 KB-aligned so `ori` on the base still works). Offsets of `0x400` and up from such a register
  (the I/O area `0x1F801000...`, used by no game function) call `RECOMP_HW` → `recomp_hw_address`, which traps. 8
  translated functions use the scratchpad.
- **Raw PS1 addresses.** `lui` of `0x8001`–`0x801F` without a relocation is flagged in the report. Only one is left,
  `func_800240C0`, comparing with `0x8017FFFF` (the RAM limit). `0x80000000` is the sign-bit constant and is not
  flagged. No translated function reads low memory through `$zero`.

## Instructions

| MIPS | C |
|---|---|
| ALU, shifts, `slt(i)(u)` | plain C on `u32`; `sra`/`srav`/`slt` through `s32`. `add`/`addi`/`sub` do not trap on overflow. |
| `lb`/`lh`/`lbu`/`lhu`/`lw`, `sb`/`sh`/`sw` | `MEM_S8`... with sign/zero extension; writes to `$zero` are dropped |
| `lwl`/`lwr`/`swl`/`swr` | `recomp_lwl(rt, addr)` etc., the exact little-endian merge semantics (MIPS LE = x86 LE) |
| `mult(u)`, `div(u)` | `RECOMP_MULT/DIV` into `hi`/`lo`. Division by zero and `INT_MIN/-1` give the R3000 results instead of a host trap. |
| `break n` | `recomp_break(FN, n, vaddr)` (`break 6/7` are the compiler's divide checks) |
| `mtc2`/`mfc2`/`ctc2`/`cfc2` | `GTE_MTC2(v, reg)` ... (default: PsyCross's `MTC2`/`MFC2`/`CTC2`/`CFC2` from `INLINE_C.C`) |
| `lwc2`/`swc2` | `GTE_MTC2(MEM_U32(a), reg)` / `MEM_U32(a) = GTE_MFC2(reg)` |
| GTE commands (`rtps`, `mvmva`, ...) | `GTE_COP2(word & 0x1FFFFFF)` → PsyCross's `doCOP2(op)`, which decodes the command word |
| branches | `bc = cond; <delay slot>; if (bc) goto L;`: the condition is taken before the delay slot runs, so a delay slot that writes a branch operand is correct |
| `j`/`b` | `<delay slot>; goto L;` |
| `jal f` / `jalr` | `<delay slot>; v0 = f(...)` / `jt = rs; <delay slot>; v0 = RECOMP_ICALL(jt)(...)` |
| `jr $ra` | `<delay slot>; return v0;` |

MIPS I load-delay slots are ignored (the compiler's output respects them). The GTE interface names are the ones in
PsyCross `e56e4cd`. The game's asm uses 13 distinct GTE command words:

- `rtps`, `rtpt`, `nclip`
- `mvmva` (three variants), `sqr` (two)
- `ncs`, `nct`, `nccs`, `cc`, `gpf`

Each is exactly the constant PsyCross's own `gte_*` macro passes to `doCOP2`. That macro set is PsyCross's
counterpart of the SDK's `INLINE_C.H`, so the encoding agrees. (The PsyQ 4.4 SDK's `INLINE_C.H` has only DMPSX
placeholders, `.word 0x0000007f` for `gte_rtps()`, so the game's asm is the reference for the real words.
`Devrefs/Inlinref.pdf` and `Hardware.pdf` in the SDK document the semantics.) The PsyCross names can be swapped by predefining `GTE_MTC2` etc. 38 translated functions use
the GTE, 34 of them hand-written.

## What it does not handle

10 of the 666 get a stub that calls `recomp_unsupported("func_X", "<reason>")`:

| Function | Why |
|---|---|
| `main:func_80018F0C`, `func_80018FA8`, `func_800190A0` | The coroutine context switch: saves and restores the whole register file including `$sp`, `$gp`, `$k0`, `$k1`. Needs Win32 fibers or a hand-written swapcontext (`docs/PORT_FEASIBILITY.md` §3). |
| `movie:func_800C22E8`, `func_800C2360`, `func_800C23D8`, `func_800C2450` | Hand-written: load `$gp` from BIOS memory (`lw $v0, 0x110($zero)` → `$gp`), call, restore `$gp`. A port replaces them with plain calls. |
| `main:func_80019894`, `func_800198A4` | Not code: splat's `.word 0x72704F4E` "functions" are the strings `"NOprintf"`, `"NOputs  "` in the text section. Nothing to translate. |
| `movie:BUILD_OBJ_AC` | A libpress fragment that branches back into `DecDCTvlcBuild`. Sony library; the port replaces libpress (feasibility item 11). |

The report also notes, without stubbing:

- `func_80046998`: alloca, run-time checked.
- `func_8008B150`: walks its argument area. Handled.
- `func_80075B4C` and `func_80077A44`: jump table assumed.
- `func_800240C0`: compares with the PS1 RAM limit `0x8017FFFF`, which means nothing for host pointers.

Not handled in general, because none of the 666 needs it:

- `bltzal`/`bgezal`
- `syscall`
- `cop0`
- branches into delay slots
- real C varargs. A recompiled function has fixed parameters. A varargs *caller* is fine.

## Differential tests

The question is whether a recompiled function behaves like the original, and the tests answer it for functions
whose behaviour we already have in another form: the 4,827 decompiled ones. Each tested function is built twice
for the host, once from its decompiled C++ and once by recompiling its **original asm**
(`asm/<target>/matchings/`). The two run on identical random inputs and their results are compared.

### Method

- **Which functions.** A function is tested if all of these hold:
  - it is a free function with C linkage (`EXTERN_C`) in a `src/` file that compiles for the host
  - its parameters and return are integers or pointers (types from clang's AST of the decompiled source)
  - it uses no GTE and no inline asm
  - the recompiler translates it
  - it is a leaf, or every function it calls directly is in the native build too, so both builds call the same
    native callee. Indirect calls are allowed: their targets come from random memory and fault in both.
- **One runner per target** (`build/recomp-test/<target>/difftest_<target>.exe`) links:
  - the whole decompiled objects, built as C++ with the shim
  - the recompiled originals, renamed `recomp_func_X`
  - `globals.s`: every data symbol either side uses, laid out at its PS1 address offset, so that `D_800B18FC + 0x14`
    and `D_800B1910` are the same byte, as on the PS1
  - `harness.c`

  Unresolved symbols (functions still in asm) link as null with `/force:unresolved`. `asm("func_X")` labels, which
  COFF spells without the leading underscore, are aliased with `/alternatename`.
- **Each trial** works on random memory:
  - The random memory is a 64 KB arena and the whole globals area, filled with random words: arena pointers,
    small integers, zero, 16-bit values, small negatives, and values at or above `0x80000000`, which are never
    mapped in a 32-bit process that is not large-address-aware.
  - Arguments are drawn by parameter type. Pointer arguments get separate slices of the arena so two of them
    rarely overlap.
  - The run: snapshot, call the decompiled function, snapshot, restore, call the recompiled one.
  - The comparison covers the return value (at the C return type's width) and **every byte** of the arena and the
    globals area. The CRT's `rand` is reseeded before each call (native callees use it).
  - The arena sits in the middle of 64 MB of reserved, uncommitted address space, and the snapshots are
    write-protected during the calls. A wild store therefore faults instead of corrupting the harness.
- **Faults** are caught with SEH, and a watchdog thread turns a hang (150 ms) into an exception. Outcomes:

  | Outcome | Counts as |
  |---|---|
  | Both builds faulted | Agreement; memory is not compared. |
  | Only the decompiled build faulted, on a load or a divide | Reported apart, not a mismatch. Either compiler may drop a load whose value is dead; the R3000 does not trap on x/0; on a PS1 such a load reads RAM. |
  | Only the recompiled build faulted, on a load | Reported apart, not a mismatch. Same reason. |
  | One-sided fault on a store, or any other one-sided exception | Mismatch. |
  | The decompiled build hung | Trial skipped. |

  ```bash
  .venv/Scripts/python.exe tools/recomp/test/difftest.py --trials 1000 --seed 1
  ```

### Results (1000 trials per function, seed 1)

| | Functions | Pass | Fail | Known difference |
|---|---:|---:|---:|---:|
| Leaf | 276 | 272 | 0 | 4 |
| Non-leaf (calls native code) | 169 | 169 | 0 | 0 |
| **Total** | **445** | **441** | **0** | **4** |

438 are EXE functions and 7 are CAPTURE (`capture.cpp`); the other overlays' sources don't compile on the host yet.
Over the 445,000 trials:

| Outcome | Trials |
|---|---:|
| returned in both builds with identical return value and memory | 287,925 |
| faulted in both | 154,735 |
| faulted only in the decompiled build (a dead load or x/0) | 172 |
| faulted only in the recompiled build (a dead load) | 30 |
| skipped (the decompiled build hung) | 2,103 |
| mismatched, all in the 4 known differences | 35 |

Counts move by a few trials between runs, because a hang is a timeout. 58 passing functions returned normally in
under 10% of their trials (most trials faulted in both), so they are weakly tested.

**Translator features the passing functions exercise** (passing / tested):

| Feature | Functions |
|---|---:|
| a delay slot that writes the branch's own operand | 64/64 |
| direct calls into native code | 148/148 |
| indirect calls | 25/25 |
| outgoing stack arguments | 7/7 |
| incoming stack arguments | 9/9 |
| `lwl/lwr/swl/swr` | 13/13 |
| `mult` | 24/24 |
| `div` | 20/20 |
| `%gp_rel` | 10/10 |

Not exercised: jump tables, tail calls and v0/v1 pair returns. No tested function has them, because most
functions that do are in files that don't compile on the host yet, or in overlays. These paths are checked only by
compiling all 666 and by reading the output.

**Known differences** (run and reported, not failures). In all four the recompiled code does what the original asm
does:

- `func_80020368` stores the address of a stack temporary (its vtable copy) into the object, so that word differs
  between the two stacks (33 trials).
- `func_8008D5E8`: the decompiled C reads `e[6]` after its store to `v[0xA]`, while the original asm reads it
  before. They differ only when random pointers make `e` and `v` overlap: 0 trials in this run, 2 in an earlier one,
  before pointer arguments got separate arena slices.
- `func_800193AC` and `func_800627E8` copy a struct through a pointer loaded from memory. When the random source
  overlaps the destination, the asm's word-by-word copy and clang's `memcpy` give different bytes (1 trial each).

### What the tests found

In the recompiler:

- Data externs were emitted as `u8 D_X[];`, which in C is a tentative *definition*: every file defined its own copy
  of the globals. They are now `extern`.
- clang deleted a store through a null pointer as undefined behaviour. The recompiled code is now built with
  `-fno-delete-null-pointer-checks`.
- The `$v1`-after-call analysis took the first half of an `lwl/lwr` pair, and the fall-through after `jal exit`, as
  reads of `$v1`. That made `__builtin_new` and others look like they return a pair.
- `lui 0x1FFF` (the `0x1FFFFFFF` physical-address mask) was treated as an I/O address and would have trapped.

In the harness:

- CRT `rand` state
- overlapping pointer arguments
- wild stores into the snapshot buffers

In the host build of the decompiled C:

- the `-isystem` varargs break
- the C++ forward-progress rule
- `main` colliding with the runner's own
- `asm("func_X")` labels lacking the COFF underscore

## Host compile of `src/` (feasibility item 1, first measurement)

`tools/recomp/test/shim/common.h` (20 lines) replaces `include/common.h` by coming first on the include path. It
makes `INCLUDE_ASM`/`INCLUDE_RODATA` expand to nothing and keeps `EXTERN_C` and `NULL`. Nothing in `include/` or `src/`
is changed. Every `src/*.cpp` is compiled with:

```
clang --target=i686-pc-windows-msvc -x c++ -O2 -fno-strict-aliasing -fwrapv -fno-delete-null-pointer-checks
      -fno-finite-loops -fno-exceptions -fno-rtti -Dmain=game_main
```

**21 of 53 files compile.**

- Clean: `main_a.cpp`, `main_b.cpp`, `sound.cpp`, `gameend.cpp`, `capture.cpp`, and the units `u_80018B88`,
  `u_8001949C`, `u_8001DDF4`, `u_80020368`, `u_80025854`, `u_8003148C`, `u_80032264`, `u_800372C0`, `u_8003C510`,
  `u_80044BE4`, `u_80062610`, `u_800658E0`, `u_80067450`, `u_80082174`, `u_80083EB4`, `u_80089024`.
- The other 32 have **198 errors**:
  - FIELD 38, BATTLE 23, MOVIE 19, `u_8003852C` 17, EFFECT 16
  - the rest have 1–11 each

By kind:

| Errors | Kind | What it is |
|---:|---|---|
| 121 | use of undeclared identifier | GCC 2.8 accepted implicit function declarations in C++: a function called before any prototype. Fix: declare it (track A's `exe.h` removes most). |
| 30 | type mismatches (`cannot initialize a parameter`, `no matching function`, `conflicting types`) | Different prototypes for the same function in different headers: track A's problem exactly. |
| 23 | taking the address of a temporary | `&Type(args)` idioms GCC 2.8 allowed. |
| 19 | unknown register name `$2` in asm | `register T x asm("$2")` pins. Remove for the port. |
| 5 | expected function body after declarator | An `asm("label")` placed where clang does not accept it. |

Things that compile but break at link or run time:

- **`.set` aliases.** `include/game/a/h_u_8001DDF4.h` has top-level `__asm__(".set _vt.10C_800100F8, D_800100F8")`
  aliases. lld rejects the object ("should not refer to special section 0"). The tests leave that file out.
- **`asm("func_X")` labels.** On COFF they name `func_X` without the C underscore, so C callers (`_func_X`) and the
  label never meet. The tests alias them with `/alternatename`; the port must remove the renames (track A).
- **`main`.** The game's `main` collides with the host's.
- **Behaviour.** The C differs from the PS1 in three ways, and the port needs the matching flags:
  - x/0 traps on x86 (`func_80091B38`)
  - an intentional infinite loop is undefined in C++ (`func_8008C4F0`): `-fno-finite-loops`
  - a null store is undefined (`func_8008C3AC`): `-fno-delete-null-pointer-checks`
- **Member functions** compile but use MSVC's `__thiscall` and mangling (see "Next steps").

So item 1 looks like days rather than weeks: about 200 mostly mechanical errors, nearly all of them prototype
problems that track A is already fixing.

## Toolchain

`tools/recomp/hostcc.py`: `clang --target=i686-pc-windows-msvc` with `-fno-strict-aliasing -fwrapv
-fno-delete-null-pointer-checks`, linked with `-fuse-ld=lld`. clang 23 finds Visual Studio 14.51 and SDK
10.0.26100.0 by itself and puts its own resource headers first.

Do not pass the MSVC and SDK include folders with `-isystem`: that puts MSVC's `vadefs.h` ahead of clang's, and on
i686 every varargs function then reads garbage arguments. `printf("%d", 7)` printed `18587256` in a test program.
To point clang at another installation, set `RECOMP_VCTOOLS`, `RECOMP_WINSDK` and `RECOMP_WINSDK_VER` (passed as
`-Xmicrosoft-visualc-tools-root` etc.).

Flags the game's code needs on a modern compiler, found by the tests:

- `-fno-strict-aliasing`
- `-fwrapv`
- `-fno-delete-null-pointer-checks`: a store through a null pointer is not "unreachable". On a PS1, address 0 is
  RAM.
- for the decompiled C++, `-fno-finite-loops`: `func_8008C4F0` really loops forever on some inputs; under C++'s
  forward-progress rule clang made it return.

## Next steps for a port build

1. **Prototypes.** When track A lands `include/shared/exe.h`, generate the `--protos` JSON from clang's AST of it.
   That gives the real stack-argument counts and pair returns, and catches struct-by-value parameters, which the
   fixed `u32` model does not handle.
2. **Names and the C++ ABI.** Recompiled code calls GCC 2.8 names (`jal __10C_800E5FC4iP14Unk_800E5FC4_r`, `jal
   __builtin_new`). Decompiled member functions built by clang for MSVC get MSVC-mangled names and **`__thiscall`**
   (`this` in ECX), so a recompiled `jal` to a method cannot reach it as is. Either build the port with
   `i686-w64-windows-gnu` (MinGW: Itanium ABI, `this` on the stack, cdecl) or generate `extern "C"` cdecl thunks
   for every decompiled method that asm calls. The same table maps `__builtin_new`/`__builtin_delete` to the host's
   `operator new`/`delete`.
3. **Data (item 2).** Every `D_X` the recompiled code names must be defined by the port's data generator. The
   recompiled code only takes addresses (`extern u8 D_X[]`), so any type works.
4. **Indirect calls.** Define `RECOMP_ICALL_TARGET` to look PS1 addresses up in a table from the symbol files while
   vtables are still asm data (items 2–3), then drop it.
5. **Overlays (item 5).** Output is per target. 130 names repeat across overlays. Compile each overlay's
   recompiled files with `-Dfunc_X=ovl_func_X`-style renames from the same namespacing table as the decompiled code.
6. **The stubs.** Fibers for the context switch; plain calls for the four MOVIE `$gp` wrappers; libpress replaced.
7. **Replacing recompiled with decompiled.** Rerun the recompiler after each decompilation; its output follows
   `src/`'s `INCLUDE_ASM` lines, so the linked set changes with no bookkeeping.
8. **Performance**, once it runs:
   - fold `%hi/%lo` pairs into `&D_X`
   - drop the frame zeroing
   - type registers that hold only small values
   - compile with `-O2` and no `RECOMP_CHECK_ADDR`
9. **GTE tests.** The 38 GTE functions are compiled but not tested. Their decompiled counterparts use inline MIPS
   asm, so there is nothing native to compare with. The oracle for them is the running game: the DuckStation fork
   on `localhost:2346` (`tools/duckstation.py` on master `054c8fc`, see `docs/PARALLEL.md`). It covers registers,
   memory, GTE registers and an instruction trace. Break at a function's entry, snapshot the registers (CPU and
   GTE) and the memory it reads, step out, then run the recompiled function on the same inputs against PsyCross's
   GTE and compare. Pausing the emulator interrupts whoever is playing, so ask first. The same capture works as a
   ground truth for any recompiled function, not only GTE ones.
10. **More test coverage.** FIELD, BATTLE, MOVIE and EFFECT functions are not tested yet because their source files
    do not compile on the host (item 1). The harness picks them up as soon as they do.
