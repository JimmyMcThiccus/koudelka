# PC port, phase 2: a host build of the EXE

Goal: a 32-bit Windows `koudelka.exe`, built from `src/main/*.cpp`, the recompiled EXE asm functions
(`tools/recomp`) and the EXE's asm data, linked against PsyCross, SDL2 and OpenAL, that runs until it first
loads an overlay or first touches something unimplemented, and logs which. Overlays and BIM modules come
later. Read `docs/PORT_FEASIBILITY.md` and `docs/RECOMP.md` first; this note only covers the decisions for
this phase.

Ground rules (from the brief): the PS1 build stays byte-identical; nothing in `src/` or `include/` changes;
port code lives in `port/` and `tools/port/`; generated files go to `build/port/` (git-ignored); third-party
code goes to `bin/port/` (git-ignored).

## Starting point (measured before any port code)

- With the recompiler's test shim (`tools/recomp/test/shim/common.h`), **9 of the 42** `src/main/*.cpp`
  compile for `i686-pc-windows-msvc`; the 33 others have **269 errors** (no error limit).
  - 137 `no matching function for call`: 132 against `include/shared/exe.h` prototypes. GCC 2.8 accepted
    `void *` → `T *` and `int` ↔ pointer conversions in C++ arguments; clang does not.
  - 95 `use of undeclared identifier`: a function called before its definition in the same unit. `exe.h`
    hides a unit's own functions from it (`#ifndef EXE_H_IN_<unit>`), and GCC 2.8 allowed the implicit
    declaration.
  - the rest: address of a temporary, `register ... asm("$2")` pins, `asm("label")` placement, a few
    assignments between pointer types.
- Dependencies are fetched by `tools/port/fetch_deps.py` into `bin/port/`, pinned by URL and SHA-256:
  PsyCross `e56e4cd`, SDL2 2.30.12 (VC), OpenAL Soft 1.23.1.

## 1. Build generator: `port/configure_port.py` → `build-port.ninja`

There is no CMake, and the repo already drives ninja from Python (`configure.py`), so the port does the same.
`port/configure_port.py` runs the generators below and writes `build-port.ninja` at the repo root; ninja
(`.venv/Scripts/ninja.exe -f build-port.ninja`) does the rest. Toolchain: `tools/recomp/hostcc.py`
(clang 23 for `i686-pc-windows-msvc`, lld, MSVC 14.51 libraries, SDK 10.0.26100.0; never `-isystem` the MSVC
headers, see `docs/RECOMP.md` "Toolchain").

Steps, all into `build/port/`:

| Step | Input | Output |
|---|---|---|
| hostify | `src/main/*.cpp`, `include/**` | `build/port/hsrc/`, `build/port/hinc/` (host view of the sources, below) |
| compile game | `build/port/hsrc/*.cpp` | `obj/game/*.obj` |
| recomp | `python -m tools.recomp --target main --static-rodata` | `build/recomp/main/*.c` → `obj/recomp/*.obj` |
| data | `asm/main/data/*.s` | `build/port/data/main_data.s` → `obj/data/main_data.obj` |
| psycross | `bin/port/psycross/src/**` | `obj/psycross/*.obj` |
| runtime | `port/*.c`, `port/*.cpp` | `obj/port/*.obj` |
| stubs | every object above (`llvm-nm`) | `build/port/stubs/stubs.s`, `link.rsp`, `stubs.txt` |
| link | all objects, `SDL2.lib`, `OpenAL32.lib` | `build/port/koudelka.exe` (+ `.pdb`, `.map`), DLLs copied next to it |

Game code is compiled with the flags `docs/RECOMP.md` found necessary: `-fno-strict-aliasing -fwrapv
-fno-delete-null-pointer-checks -fno-finite-loops -fno-exceptions -fno-rtti`, plus `-Dmain=game_main` and
`-g` (the crash log symbolises through the PDB).

## 2. Host view of the sources (`tools/port/hostify.py`) and the `common.h` shim

The PS1 sources stay the single source of truth. The port compiles a **generated host view** of them, made by
mechanical, documented rewrites, so nothing in `src/` or `include/` has to change and the matching build cannot
be affected:

- `port/include/common.h` comes first on the include path and replaces `include/common.h`:
  `INCLUDE_ASM`/`INCLUDE_RODATA` expand to nothing (asm functions come from the recompiler, asm data from the
  data step), `EXTERN_C` and `NULL` as before, plus the permissive argument types below (C++ only).
- `include/**` → `build/port/hinc/` (second on the include path):
  - `__asm__(".set A, B")` aliases (GCC 2.8 vtable names such as `_vt.10C_800100F8`) are dropped. lld rejects
    them, and host code never uses the alias names.
  - `asm("func_X")` symbol renames become `asm("_func_X")`: on i686 COFF a C symbol is `_func_X`, so the
    rename has to carry the decoration to meet the recompiled or decompiled definition.
  - `register T x asm("$2")` pins lose the `asm(...)`.
  - **`shared/exe.h` is made permissive** for callers outside the owning unit. Each `/* unit.cpp */` section is
    emitted twice: `#ifdef EXE_H_IN_<unit>` the original text (the owner's definitions must agree with it),
    `#else` a version where every pointer parameter `T *` becomes `port_parg<T>` and every integer parameter
    becomes `port_iarg<T>`, and every pointer return becomes `port_pret`. These are 4-byte trivially copyable
    wrappers (`port/include/port_args.h`) that accept what GCC 2.8 accepted: any pointer or integer for a
    pointer, any pointer for an integer. A real conversion (`Holder *` → `List *`, a virtual-base adjustment)
    still wins: the "anything" constructor is disabled when the standard conversion exists. On i686 cdecl a
    4-byte struct argument and a 4-byte POD return are passed exactly like the pointer or `int` they replace,
    so callee and caller still agree across objects. The PsyQ section (no owner) is made permissive throughout.
- `src/main/*.cpp` → `build/port/hsrc/`: the same rewrites, plus forward declarations of the unit's own
  `EXTERN_C` functions that are called before their definition (GCC 2.8's implicit declarations), inserted
  after the last `#include` with the definition's own signature.

Whatever still fails after this is counted and reported per file (the running count below); a file that does
not compile is left out of the link and its functions become stubs (section 7), so one bad file does not
block the milestone.

## 3. How the recompiled functions plug in

`python -m tools.recomp --target main --static-rodata` writes one `.c` per `INCLUDE_ASM` function in
`src/main/`. The port compiles them with `tools/recomp/runtime/recomp.h` and these port definitions:

- `RECOMP_ICALL_TARGET(x)` → `port_icall_target(x)`: an indirect call whose target is a PS1 address
  (`>= 0x80000000`, from raw words in asm data or from overlay tables) or lies in the overlay area (section 5)
  is logged with the address and the nearest symbol, and stops. Host pointers pass through unchanged.
- The trap functions (`recomp_unsupported`, `recomp_break`, `recomp_bad_jump`, `recomp_stack_overflow`,
  `recomp_hw_address`) and `recomp_scratchpad` are defined in `port/recomp_rt.c`: log, then stop (break 6/7,
  the compiler's divide checks, log and continue, as on the PS1 with no handler installed).
- GTE: PsyCross's `MTC2`/`MFC2`/`CTC2`/`CFC2`/`doCOP2`, the recompiler's default.
- Calls between the two sides need no glue: both are cdecl with C names (`_func_X`), and the recompiled
  signature `u32 f(u32 a0..a3, u32 stk...)` reads the same stack image as the decompiled prototype.
- The recompiled set follows `src/`: a newly decompiled function drops out of `build/recomp/` and comes from
  `hsrc` instead, with no bookkeeping.
- `tools/recomp`'s prototype overrides (`--protos`) are not needed for this phase: the analysis-derived
  stack-argument counts are what the call sites use. Generating them from `exe.h` stays a later improvement.

**Not handled in this phase:** recompiled code calling a C++ member function by its GCC 2.8 mangled name
(`jal __10C_800E5FC4iP14Unk_800E5FC4_r`), and asm vtables naming such methods. With the MSVC ABI the
decompiled methods are `__thiscall` with MSVC names (clang refuses Itanium layout on the MSVC triple:
"Itanium-compatible layout for the Microsoft C++ ABI is not yet supported", and SDL2's package is MSVC). These
names stay undefined and get logging stubs (section 7). The fix is generated cdecl→thiscall thunks
(GCC 2.8 name → MSVC name), feasibility item 3.

## 4. The EXE's asm data: generated host assembly

**Decision: translate splat's data `.s` into i686 GNU-syntax assembly and assemble it with clang**, not C.

Why:
- **Layout.** The game indexes across symbol boundaries (`D_800B18FC + 0x14` is `D_800B1910`; the
  recompiler's `%hi/%lo` arithmetic and many `FIELD_AT` reads rely on it). Assembly keeps every block at its
  PS1 offset from the start of its section; C gives no ordering guarantee between globals.
- **Types.** Assembly needs none. A C generator would have to give each of 1,148 referenced symbols a type
  that agrees with every C++ declaration of it; the host code already declares them, and only the address
  matters at link time.
- **Fidelity.** It is a line-for-line copy of splat's output; `difftest.py`'s `globals.s` already proves the
  approach for the test harness.

`tools/port/gen_data.py` reads every `dlabel` block in `asm/main/data/*.s` (ctors, the unit rodata
segments, PsyQ rodata, `.data`, `.sdata`, `.bss`) with `tools/recomp/asmfile.py` and writes
`build/port/data/main_data.s`:

- three sections: `.rdata` (`0x80010000–0x800186B0`), `.data` (`.data` + `.sdata`, `0x800A4514–0x800B4EE8`,
  which are contiguous) and `.bss` (`0x800B4EE8–0x800B6DF0`), each block preceded by `.space` for any gap, so
  every symbol keeps its PS1 offset from its section start. Sections are 4 KB aligned, so `%lo` bit patterns
  within a page also agree.
- `.word sym` → `.long _sym` (C decoration; names with `$` or `.` are quoted). `.word sym + n` likewise.
- `.word .L8001xxxx` (jump tables of compiled functions) → `.long 0` and counted: decompiled code gets its
  jump tables from clang, recompiled code from its own `.c` (`--static-rodata`).
- `.word 0x80xxxxxx` raw values stay raw. They are unmapped in a 32-bit process without
  `/LARGEADDRESSAWARE`, so any use faults and is logged.
- `.ascii`/`.asciz`/`.byte`/`.short`/`.space`/`.align` are copied (byte-exact via the raw bytes splat prints).

## 5. Pointer width and the address map

32-bit (`i686`): `sizeof(void *) == 4`, so every `FIELD_AT` offset and struct layout that holds pointers
stays as on the PS1 (except for the C++ ABI points in feasibility §5, which are not this phase's problem).
The link does not set `/LARGEADDRESSAWARE`, which guarantees that every PS1 address `0x80000000+` is unmapped.

PS1 addresses the EXE uses that are not in its data:

| PS1 range | Host |
|---|---|
| `0x1F800000–0x1F8003FF` scratchpad (`D_1F800000`) | `recomp_scratchpad`, 1 KB, 4 KB aligned; `D_1F800000` and other scratchpad symbols are defined at their offsets in it |
| `0x800B6DF0–0x80200000` overlay slot (`ovl_header`), EFFECT, the large-block area `func_80027E30` hands out, and the game heap from `D_800EA8A0` | one host block `port_hiram` of the same size; every symbol the EXE names in this range (`ovl_header`, `D_800D5DAC`, `D_800EA8A0`, ...) is defined at its PS1 offset in it |
| other low-RAM/BIOS addresses (`D_80000004`, ...) | not defined: listed by the stub step, used only by `start` |

The heap: `start` calls `func_80018B88`, which builds the heap from `&D_800EA8A0` with the size
`(D_800B4C08 − 0x7FF80000 − (int)&D_800EA8A0) & ~7` (PS1: `D_800B4C08 = 0x180000`, so 0x115760 bytes, up to
`0x80200000`). The host entry stores the value that gives the same size for the host address of `D_800EA8A0`
before calling it. That is the only data patch, and the log says so.

## 6. Entry point (replaces `start` and the BIOS init)

`port/main.cpp` defines the host `main` (the game's is `game_main`, by `-Dmain=game_main`):

1. open `koudelka.log` (next to the exe), install an unhandled-exception filter that logs the fault (code,
   address, the faulting data address, the call stack symbolised with DbgHelp from the PDB) and exits;
2. `PsyX_Initialise("Koudelka", 640, 480, 0)` (SDL2 window, OpenGL, OpenAL); `PsyX_CDFS_Init(<disc 1 .bin>)`,
   the path from `--cd` or `KOUDELKA_CD`, else `Koudelka_Game_Data/Koudelka (USA) (Disc 1).bin` under the
   main checkout;
3. what `start` does: zero `.bss` (already zero on the host), set the heap size word, call `func_80018B88`;
4. what GCC's `__main` does at the top of `main`: call the 27 `.ctors` entries at `D_80010000`;
5. `game_main()`. If it returns, log that and exit (on the PS1, `start` executes `break` after `main`).

`$gp`, `$sp` and `$fp` set-up have no host meaning. `__main` itself is defined by the port (it also walks the
27 entries, guarded so it runs once, as the PsyQ one does).

## 7. Stubs: overlay loading, hardware, missing PsyQ calls, unresolved symbols

Every stop goes through one function, `port_stop(kind, what)`: it logs `STOP <kind>: <what>` with the caller's
stack and exits with a distinct code. The log's last `STOP` line is the milestone answer.

- **Overlay loading.** Overlays are loaded into `ovl_header` and entered through its header (an id word and
  GCC 2.x vtable entries). The host never has overlay code there: an indirect call into `port_hiram` (from
  recompiled code, via `port_icall_target`) stops with `STOP overlay`; a native call into it faults (the block
  is not executable) and the fault handler reports it as `STOP overlay` too. Direct calls from the EXE to
  overlay functions at fixed addresses (feasibility §3: 57 functions, mostly EFFECT) are undefined symbols in
  the overlay range and get `STOP overlay` stubs.
- **Hardware addresses.** `RECOMP_HW` (I/O area) → `STOP hardware`. Any other PS1 address faults → `STOP fault`
  with the address.
- **PsyQ calls PsyCross lacks.** `port/psyq_missing.c` defines each missing function the EXE references with
  the PsyQ signature; each logs `psyq stub: <name>` the first time and returns 0 (or does nothing), because
  most of them (`SetDrawOffset`, `CdStatus`, `SpuSetVoiceRRAttr`, `EnterCriticalSection`, ...) can be skipped
  without stopping the game. The ones that cannot be skipped stop instead. The list is the EXE subset of
  feasibility §1's "missing" table, confirmed by the link. PsyCross's own `PSYX_UNIMPLEMENTED` stubs log
  through PsyCross.
- **Everything else unresolved.** The stub step (`tools/port/gen_stubs.py`) runs `llvm-nm` over every object,
  takes undefined minus defined, and writes `stubs.s`:
  - a function name (recompiled-code or vtable reference to a GCC 2.8 method, an MSVC-mangled method still in
    asm, an asm function the recompiler stubbed under another name) → a stub that calls
    `port_stop("unimplemented", "<name>")`;
  - `asm("func_X")`-style references without the decoration, or MSVC-mangled names of plain C symbols → an
    `/alternatename` line in `link.rsp`;
  - a data name in the overlay or scratchpad range → its address in `port_hiram`/`recomp_scratchpad`;
  - any other data name → 64 zero bytes and a line in `stubs.txt` (it should not happen; the count is
    reported).

  `stubs.txt` lists every generated stub by kind; its counts are the "unresolved symbols" number.

## 8. Running count

Kept in the "Status" section below: files compiling, recompiled files compiling, unresolved symbols by kind,
stubs added, where it stops.

## Changes to the plan during implementation

Sections 1-7 are the plan as committed first. Implementing it changed these points (the code is the
reference; each rule is documented in the generator's docstring):

- **Permissive prototypes everywhere, not per owner (section 2).** The owner-guard scheme left 24 errors:
  calls inside the owning unit, and asm-label alias names. Now *every* one-line `EXTERN_C` declaration
  (`exe.h`, other headers, unit-local) is permissive (`void *` returns only become `port_pret`), and every
  `EXTERN_C` definition `T f(P) {` becomes `T port_def_f(P) asm("_f"); T port_def_f(P) {`: it still defines
  `_f`, while all calls, in the unit too, go through the permissive declaration, inserted before the first
  use. A definition of an asm-label alias name defines the label's symbol.
- **Implicit declarations** of functions defined in other units (23) come from a `clang -fsyntax-only` pass
  inside hostify: `EXTERN_C port_pret f(...);`. Non-const reference parameters become `const T &`
  (GCC 2.8 bound temporaries to them). GCC named return values (`T f(P) return r {`, 5) become locals.
- **Constructors with asm labels** (61) cannot be cdecl in the MSVC ABI (clang ignores the attribute:
  `this` stays in ECX, callee pops). hostify points them at `_port_thiscall<N>_<sym>`, and gen_stubs writes
  the thunks: thiscall→cdecl for constructors in asm or other units (14), cdecl→thiscall for constructors
  defined in the game's C++ and called by their C name from asm (10). Other labelled members get
  `__attribute__((cdecl))`.
- **The game's `printf`** (a retail no-op in `u_8001986C.cpp`) clashes with the UCRT's inline one: renamed
  `game_printf` (hostify for the C++, `-Dprintf=game_printf` for the recompiled code).
- **Primitives keep the PS1 layout (feasibility item 4, for this build).** PsyCross is built with
  `USE_EXTENDED_PRIM_POINTERS=0` (`P_TAG` `addr:24`, the game's own layout) and the exe is linked at a fixed
  base `0x400000` without ASLR. Every game primitive and OT entry lives in port RAM (the game heap, inside
  the exe image) or on the main-thread stack, so its host address fits in 24 bits and the game's
  `& 0x00FFFFFF` OT code works unchanged. `main.cpp` checks it at start-up. (With the default extended
  pointers, `DrawOTag` faulted on the game's first ordering table.) Limit: PGXP is off.
- **The GCC 2.x C++ ABI (feasibility item 3) had to be started**, because the boot path uses it at once.
  hostify (`devirtualize`, `virtual_bases`, `vcall_slots`):
  - each class with virtual functions gets an explicit `void *port_vptr` where GCC 2.x puts it (after the
    introducing class's own data members; MSVC puts it at offset 0), and each virtual function becomes an
    inline non-virtual dispatcher through the GCC vtable: entry k = `vt + 8k` (`{short delta; short index;
    pfn}`, entry 0 unused, base slots first, overrides reuse the slot), called as `pfn(this + delta, args)`,
    with a hidden return-buffer pointer first for a class returned by value (as GCC 2.8 MIPS does). 799
    functions, 150 vptr members. The `VObj<N>`/`VObj0` placeholder slots (varargs) become variadic templates
    with C's default promotions.
  - virtual bases (11 classes, `Holder : virtual List` above all): `struct X : A, virtual B { m }` becomes
    `struct X : A { B *port_vb; m B port_vb_obj; }` (GCC 2.x: pointer after the non-virtual bases, subobject
    at the end). Conversions to `B *` load `port_vb` (null check included) in permissive parameters,
    `B *x = e;` initialisations, assignments to such locals, and inline helpers taking `B *`; derived
    classes get forwarders for `B`'s virtual functions.
  - Not done: virtual destructors keep their slot but are dropped (a `delete` frees without running the
    game's destructor); data members of a virtual base read through the derived class need a fixup (1 file).
- **`SetSp`** (`func_800949B0`) is a logged no-op: the main task keeps the host stack; task stacks belong to
  the context switch (fibers, next steps).
- **Data (section 4).** `.data`, `.sdata`, `.bss` and the overlay/heap area are one contiguous block,
  `port_ram` (PS1 `0x800A4000–0x80200000`), so every address relation from `.data` through the heap holds.
  Any `D_XXXXXXXX` that host code names gets a label at its offset even without a splat block (512).
- **Fixups (`hostify.FIXUPS`): 3 sites** where only a cast or a member path the rules cannot infer is needed:
  `u_8001986C.cpp` (`?:` of a `void *` and 0), `u_8003852C.cpp` (`int` return to `void *`), `u_80029BBC.cpp`
  (`C_VD` reads `unk4` of its virtual base, 3 places). These are the places `src/` would need a change for a
  modern compiler; nothing in `src/` was changed.
- `tools/recomp` skipped `src/bim` (the BIM.AR modules are not a recompiler target; it crashed on them).

## Status

**Milestone reached.** `build/port/koudelka.exe` (32-bit, clang 23 / lld, MSVC ABI) links against PsyCross
`e56e4cd`, SDL2 2.30.12 and OpenAL Soft 1.23.1, opens the PsyCross window, mounts disc 1 and runs:

1. host entry: log, crash handler, `PsyX_Initialise`, `PsyX_CDFS_Init`
2. `start`: heap set-up (`func_80018B88`), the 27 `.ctors` (the game's static objects, `__main`)
3. `game_main` (`u_8001949C.cpp`): `func_8001B424` init, the graphics system object (`func_8001B46C`:
   `ResetGraph`, draw/display environments, the first ordering tables through `DrawOTag`, VRAM manager
   virtual calls, `PadInitDirect`, `SsUtReverbOff`)
4. `func_8001E360`: the scheduler's main task (`func_8001BE9C`, recompiled): `PadStartCom`, the interrupt
   holder (`Holder`/`List` virtual base), critical sections, `VSyncCallback`, then the first task creation

and stops with:

```
STOP unimplemented: func_80018F0C (recompiler stub: context switch (saves/restores the full register file incl. $sp/$gp/$k0/$k1))
  func_80018F0C <- func_8001E848 (u_8001DDF4.cpp:361) <- func_8001DACC <- func_8001D3A8 <- func_8001BE9C <- func_8001E360 <- game_main
```

`func_80018F0C` is the coroutine scheduler's context set-up (feasibility §3: with `func_80018FA8` and
`func_800190A0`, "needed by the scheduler from the first frame"). No overlay is loaded before it.

Counts (`port/configure_port.py`, `build/port/stubs/stubs.txt`):

| | Start of phase 2 | Now |
|---|---:|---:|
| `src/main/*.cpp` compiling on the host | 9 / 42 (269 errors) | **42 / 42** (0 errors, full `-O2` codegen) |
| recompiled EXE functions compiling | – | **357 / 357** (352 translated, 5 recompiler stubs) |
| PsyCross sources | – | 21 / 21 (`-D_WINDOWS -D__PRFCHWINTRIN_H`, `.C` as C++) |
| undefined symbols after the probe link | – | **186**: 162 function stubs, 0 data stubs, 24 thunks |
| | | stubs by kind: overlay 106, PsyQ 53 (library internals named only from PsyQ's own data, plus `start`), GCC names 2, method 1 (`~C_80010178`) |
| PsyQ functions added in `port/psyq_missing.c` | – | 37 (23 skipped with a log line, 12 small real implementations, 2 stop) |
| hostify rules applied | – | 401 asm labels, 1,834 permissive declarations, 2,858 definitions renamed, 23 implicit declarations, 61 labelled constructors, 799 virtual dispatchers, 11 virtual bases, 3 fixups |

The PS1 build is unchanged: `configure.py --mode matching`, 93× `check: OK`.

### Running it

```bash
.venv/Scripts/python.exe tools/port/fetch_deps.py
.venv/Scripts/python.exe port/configure_port.py
build/port/koudelka.exe
```

The log is `build/port/koudelka-port.log` (PsyCross writes its own `Koudelka.log` in the working
directory). `--cd <bin>` or `KOUDELKA_CD` picks the disc image; the default is
`Koudelka_Game_Data/Koudelka (USA) (Disc 1).bin` in the main checkout. `--no-window` skips PsyCross's
initialisation (only useful for the start-up path). Every stop is one `STOP <kind>: <what>` line plus a
symbolised stack (DbgHelp, from `koudelka.pdb`); faults on PS1 addresses are named from `ps1_syms.txt`.

### Next steps

1. **Context switch (feasibility item 6).** Replace the three recompiler stubs `func_80018F0C` (create:
   allocates the task stack, `[a1+8]*4` bytes, at `jb+0x88`), `func_80018FA8` (switch) and `func_800190A0`
   (start: a virtual call on the new stack) with Win32 fibers in `port/`, and exclude them from the
   recompiled set. That is the next stop, before any frame is drawn.
2. **Vtable/ABI follow-ups (item 3).** Virtual destructors (a dispatching `delete`); the one remaining
   `method` stub (`~C_80010178`, from a clang vftable); constructors defined in the game's C++ that the asm
   vtables name by GCC 2.8 mangled names (none hit yet; they will show as `gcc-name` stubs once overlays
   link). Check the dispatcher's vptr-placement rule against the PCSX2/DuckStation oracle on the first few
   classes with data and virtual functions.
3. **Overlays (item 5).** The 106 `overlay` stubs are EXE calls into the overlay area at fixed addresses
   (mostly EFFECT); the first overlay load will show as `STOP overlay` (an indirect call into `port_hiram`).
4. **PsyQ (items 7-9).** The 23 skipped calls in `port/psyq_missing.c` (SPU envelopes and noise/LFO, CD
   status/reset, `func_8009DDC0`/`func_8009F6D0`/`func_800A1B9C` unidentified) are logged on first use.
5. **Prototypes.** `tools/recomp --protos` from `exe.h` (struct-by-value and pair returns) is still open; no
   call on the boot path needed it.

## Phase 2b: scheduler, interrupts, CD, first overlay

After the phase 2 merge (`e5ef1e8`), the next three steps: fibers, the C++ ABI follow-ups, overlays.

**Where it stops now.** The exe boots, runs the scheduler (up to 11 task fibers and several hundred task
switches), plays the game's own CD loading, loads `MOVIE.BIN` from disc 1, installs MOVIE's host image and
runs MOVIE's code (host-compiled, `movie_` prefixed) until the movie player starts the MDEC:

```
overlay: MOVIE loaded, host image installed (89272 bytes at 800B6DF0)
STOP hardware: write of PS1 I/O/scratchpad address 1F801824 at ... movie_LIBPRESS_OBJ_2C0
  <- movie_DecDCTReset <- movie_func_800BD8E8 (movie.cpp) <- movie_func_800BA5C4 <- task_main
```

That is the intro FMV: libpress driving the MDEC registers (feasibility item 11).

**What was added, by step.**

1. *Fibers* (`port/fibers.cpp`): `func_80018F0C`/`FA8`/`190A0` replaced (`port/configure_port.py` drops a
   recompiled function that `port/` defines). A task is a fiber; `F0C` creates the new task's fiber, whose
   entry does what the PS1's first return from `F0C` does (`$s0` clobbered to the new task, so
   `func_8001E848` takes its `cur == s` branch: leave the critical section, run `f2`, end the task).
   Getting the scheduler to run also needed:
   - *interrupts on the game thread* (`port/intr.cpp`): PsyCross calls the VSync callback from its own
     thread, in parallel with the game; now its thread only counts vblanks and the callback runs on the
     game thread at interrupt points: `ExitCriticalSection`, `VSync`, task switches, and busy-wait loops.
     `EnterCriticalSection`/`ExitCriticalSection` mask them.
   - *two `$a0` fixups* (hostify `FIXUPS`): `func_8001E7C8` and `func_8001F598`/`F60C` call a function cast
     to take no arguments, relying on `$a0` still holding the argument. These are places where `src/` needs
     a change for any non-MIPS build.
   - *busy-wait loops* (hostify `busy_loops`, 17): an empty `while (c) {}` gets `port_interrupts()` as its body.
   - *a CD driver* (`port/cd.cpp`): PsyCross's libcd only streams with `CdlReadS`; the game drives `ReadN`,
     `Setloc`, `Pause` and `Setmode` itself, with a ready callback per sector (in `CdlModeSize1`, header
     first) and a sync callback per command. Implemented over the raw `.bin`, at 150 sectors/s.
   - *SPU transfers* (`port/spu.cpp`): `func_8009F6D0` is `SpuSetTransferCallback` (phase 2 skipped it as
     unidentified); the sound driver busy-waits on a flag its transfer-complete callback clears. The
     callback is raised as an interrupt after `SpuWrite`/`SpuRead`.
2. *C++ ABI*:
   - virtual destructors now work: `delete p` runs the game's destructor through the GCC vtable with flags 3
     (a class `operator delete` dispatcher, 35 classes). Without it, a `delete` of a list node freed the
     node but skipped the destructor, leaving a stale event that the next frame called through.
   - C-style casts to a virtual base (`(List *)&p->h`, 62) now go through `port_vb_conv`.
   - the `game/a2` placeholder slots (`A2_SLOTS`) are dispatched like `VCALL_SLOTS`.
   - empty-parameter declarations that disagree with the definition are dropped (`drop_empty_decls`).
   - Not done: checking the vptr-placement rule against DuckStation. Nothing has contradicted it yet, but
     that check needs the emulator paused, so I have not done it.
   - Two `method` stubs remain: `~C_80010178` and `~Unk800BF51CO`, destructors referenced by a clang
     vftable. Neither has been called.
3. *Overlays* (`tools/port/overlays.py`, `port/overlays.cpp`, `--overlays` in `configure_port.py`, default
   `movie`):
   - an overlay's functions are compiled with its prefix (`movie_func_800BA5C4`): hostify renames them in
     the overlay's source and own header, and a names header covers the shared ones; the recompiled
     functions get the same header.
   - its data becomes a host image of the PS1 bytes (`build/port/data/movie_image.s`): symbols relocated,
     the 333 raw EXE function addresses in MOVIE's vtables turned into EXE symbols. All overlays' data
     symbols are labels in `port_hiram`, since they share the slot as on the PS1.
   - the overlay table (LBA, size, image per overlay): when the CD driver delivers the last sector of a
     known overlay file into its load area, the host image replaces the raw bytes and the overlay becomes
     current. An overlay that is not linked stops with `STOP overlay: <NAME> loaded ... not linked`.
   - Not done: EXE calls into overlays by name (the 106 `overlay` stubs, mostly EFFECT) are still stubs. They
     need a dispatcher on the current overlay once EFFECT or FIELD is linked.

**Tools.** `tools/port/catch.py` runs the exe under a minimal Win32 debugger: it handles faults the exe cannot
report itself (corrupt stack pointer, recursive SEH), dumps the game thread on a timeout (busy-waits), and
`--watch ADDR` sets a hardware write watchpoint. It found the use-after-free and the SPU busy-wait.
`KOUDELKA_TRACE=1` logs every task switch; `KOUDELKA_SHOT=<s>` writes `shot.bmp` and `vram.bmp`; the log
has a heartbeat line every 5 s.

**Counts.** EXE 42/42 game files, MOVIE 1/1; recompiled: EXE 354 (+3 replaced by fibers), MOVIE 35 (5
recompiler stubs: four `$gp` wrappers, `BUILD_OBJ_AC`). Probe link: 199 undefined symbols: 175 stubs
(overlay 106, PsyQ 65 including MOVIE's `St*` streaming, `CdRead2`, the memory-card BIOS calls
`erase`/`firstfile`/`nextfile`; methods 2; GCC names 2), 24 thunks. hostify: 1,097 virtual dispatchers,
210 vptr members, 35 virtual destructors, 62 virtual-base casts, 5 fixups.

**Next steps.**
1. *FMV* (item 11): either a software MDEC behind `DecDCT*` and the `St*` streaming calls, or a skip.
   A skip could be stubbing `DecDCTReset`/`DecDCTin`/`DecDCTout` and ending the stream at its first
   `StGetNext`; the movie loop's exit condition still has to be read to decide which.
2. *Next overlays*: FIELD and EFFECT, after the movie, with the EXE→overlay dispatchers.
3. *vptr placement*: check against DuckStation (needs the emulator paused).
4. The rest of the PsyQ gaps (`St*`, memory card) as the game reaches them.

## Phase 2c: past the movies, title screen, NEW GAME

After the phase 2b merge (`55be1e2`), with the user's decisions: skip FMVs for now; DuckStation may be paused.

**Where it stops now.** The exe boots, plays (skips) the intro movie, shows the logos and the title screen
(drawn: the window now presents frames), cycles the attract movies, takes pad input, and with
`KOUDELKA_PRESS=1300:start,1450:cross` opens the menu and starts NEW GAME. NEW GAME (MOVIE state 99,
`movie_func_800C5B80`) loads the starting party (`MENU/PRTYTEST.BIN`), the item and name tables, a battle BGM
and Koudelka's model, and then EXE code that drives battle commands (`func_8007DEE8`, mode 3) calls into the
monster overlay slot without any overlay having been read:

```
STOP overlay: func_800D6198 (called from func_8007DEE8+0x319)
  <- func_8007C9A4 <- func_8007C0A8 (u_80071A74.cpp) <- func_800792C8 <- func_80078C50 <- task_main
```

`func_800D6198` is in the BIM.AR shared base (0x800D5DAC slot, docs/BIM_AR.md); the same function calls
`func_800CF0B0` (BATTLE) next. Whether the PS1 takes this path after NEW GAME too (and loads BATTLE and a
monster image first), or the port took a wrong branch earlier, is open: checking it in DuckStation needs
button presses on its title screen.

**What was added.**

1. *FMV skip* (`port/fmv.cpp`): the libpress streaming calls (`StSetRing`, `StGetNext`, ...) and MOVIE's
   `DecDCT*` are port functions. `StGetNext` hands the player two blank frames: the first starts it, the
   second has frame number 0x7FFF, past any movie's end, so the player stops itself through its normal end
   path. The MDEC is black (`DecDCTout` clears, its callback is raised as an interrupt).
2. *Zeroed allocations* (`port/cxx_rt.cpp`): `operator new`/`__builtin_new` zero what the game heap returns.
   MOVIE's logo fades fade out child objects whose colour channels nothing set; on the PS1 those hold halves
   of earlier heap pointers (0x801F/0xCxxx, negative as s16) and the fade ends at once, on the host the
   halves are positive (0x006B/0x4EFC), the fade outlives the objects and the per-frame list calls into a
   deleted one. Zero behaves like the PS1 values there.
3. *Presenting frames* (`port/gpu.cpp`): PsyCross only shows a frame in `PsyX_EndScene`, which its libgpu
   never calls in a frame; `PutDispEnv` (the game's flip, `func_8002D1E0`) now ends the scene. Before this the
   window stayed black whatever the game drew.
4. *Pads* (`port/pad.cpp`): port 1 reports a stable digital pad (PsyCross reports it disconnected), and
   `func_800A1B9C` is libpad's `PadChkVsync` (phase 2 had it as unidentified, returning 0): the poller
   (`func_80023450`) takes a frame's buttons only after a read. `KOUDELKA_PRESS=<vblank>:<button>,...`
   scripts buttons for unattended runs.
5. *Recompiler: jump tables whose base is set early* (`tools/recomp/analyze.py`, `table_by_dataflow`):
   `func_80046998` keeps `jtbl_80012A34` in `$s6` from its prologue, so the `jr` was taken for a tail call.
   The table is now found by following the `jr` register's data flow back to the `%lo(jtbl_*)`. Only
   `func_80046998` changes in the EXE.
6. *Scratchpad literals* (hostify `scratchpad`, 6): `(T *)0x1F8000xx` becomes `port_scratchpad + xx`, the
   array the `D_1F80xxxx` symbols already live in.
7. *Arguments passed through in a register* (hostify `PASSTHROUGH`): a callee reads an argument register
   its matching C caller never sets, because on the PS1 it still holds what the caller's caller passed.
   `func_80050E58(o, a, b)` leaves `$a3` (the task) for `func_80050EA4`; the `+0x6C` virtual functions
   (`func_8004DEDC`, ...) leave `$a2` (an out pointer) for `func_8004D0F4`, which stores through it, so on the
   host it wrote into a random stack slot and zeroed an object's vtable. The pass gives the caller the
   register as an extra parameter, passes it on, and repeats for that caller's own callers
   (`func_8004FDC8`). Like the `$a0` fixups, these are places `src/` would need a change for a non-MIPS build.
8. *Observation*: `KOUDELKA_SHOT=<s>,<s>,...` writes `shot-<s>.bmp`/`vram-<s>.bmp`; the heartbeat counts
   ordering tables and flips; `KOUDELKA_TRACE_CD=1` logs each read's LBA; `KOUDELKA_TRACE_AT=<s>` dumps every
   task, then traces 40 switches; a fault logs the per-frame handler lists and the registers with their PS1
   addresses. `catch.py` takes up to four `--watch` addresses (`--reads` for read watchpoints).

**Counts.** EXE 42/42 game files, MOVIE 1/1; recompiled: EXE 354 (+3 replaced), MOVIE 26 (+9 `DecDCT*`
replaced by `port/fmv.cpp`). hostify: 6 scratchpad rewrites, 7 passthrough calls, 5 fixups, 3 vtable
constructors. Runs: about 25 s from boot to the title screen (50 vblanks/s), NEW GAME at about 30 s.

**Next steps.**
1. Find out whether the PS1 reaches `func_8007DEE8` mode 3 after NEW GAME (DuckStation: a breakpoint there
   and on the overlay loader, after pressing START and NEW GAME on its title screen).
2. FIELD and EFFECT (and BATTLE/BIM if the PS1 path goes there) with the EXE→overlay dispatchers.
3. vptr placement against DuckStation.

### Phase 2c, continued: the NEW GAME path checked against DuckStation, FIELD linked

**Where it stops now.** After NEW GAME the port reads the same files as the PS1 (checked in DuckStation with a
breakpoint on `CdControl`: PRTYTEST, ITMTBL, NAME.TBL twice, BBGM0000, SHAPE_KO, SHADOW, LBA 93469, 93476,
FIELD.BIN), loads FIELD and runs it: FIELD's code (host-compiled, `field_` prefixed) reads four more files
and `BGM/G1/OMO_01.BGM`, then the game keeps that read going (the CD command count stops, sectors keep
coming) and the screen stays black. No STOP in a 60 s run.

**What was added.**

1. *`-fno-strict-return`* (hostify `GAME_FLAGS`). The battle-command detour after NEW GAME was not a game
   path: `func_8007C0A8` ends `switch (x3C) { case 1: break; case 2: return v02(); }` and falls off the end
   of an `int` function otherwise. clang treated that as unreachable and always took `v02()`. DuckStation
   showed the PS1 running the same chain (0xB, 0xE, 0x2012, `func_8007C070`) without reaching
   `func_8007DEE8`.
2. *EXE→overlay dispatchers* (`tools/port/gen_stubs.py`): an EXE call into the overlay area jumps to
   `<overlay>_func_X` of the resident overlay that defines it (`port_ovl_slot`, `port_ovl_effect`; EFFECT
   first, and `port/overlays.cpp` forgets EFFECT when a slot overlay loads over it), with the caller's
   arguments in place; it stops only when no resident overlay has it. 52 of the 106 overlay stubs dispatch
   with MOVIE and FIELD linked.
3. *FIELD in the build* (`--overlays` default `movie,field`): 2 source files, 117 recompiled functions.
   hostify needed:
   - permissive prototypes for declarations behind a forward declaration (`struct X; EXTERN_C ...`);
   - virtual-base casts of a qualified member (`(List *)a.B::m`);
   - `$gp` switches in FIELD's kernel event callbacks dropped;
   - FIELD's own placeholder slots (`VSLOTS`, `vf00`..`vf49`) dispatched through the GCC vtable like
     `vcall.h`'s, with `VAt<N>`'s vptr at offset N (they were real C++ virtuals: MSVC's vptr at 0);
   - constructors called from asm by their GCC 2.x mangled names (`__10C_800BF2C0P16Unk_800BF2C0_src`) get
     that name as a thiscall-thunk label (`gcc_ctor_labels`, 5).
4. `VectorNormal` (libgte) in `port/psyq_missing.c`. `KOUDELKA_CD_STOP=<lba>` stops a run when a read starts
   there.

**Counts.** Recompiled: EXE 354, MOVIE 26, FIELD 117. Probe link: 202 undefined symbols: 174 stubs (overlay
106, of which 52 dispatch; PsyQ 58; GCC names 9, mostly FIELD functions the recompiler did not emit; 1
method), 27 thunks. PS1 build 93× `check: OK`.

**Next steps.**
1. The read that never stops after `OMO_01.BGM` (the PS1 played `OMO_05.BGM` in a coarse poll, so the BGM
   choice may differ too), then the map files (`MDT/HAB/HAB00001.MDT` on the PS1).
2. EFFECT (and BATTLE) linked when the game reaches them; the remaining GCC-name stubs in FIELD.
3. vptr placement against DuckStation.

**The field stall, traced so far (DuckStation and port side by side).** The CD read that never stops is not
the problem: a reader's done handler (`func_80036110`) only starts the next queued reader, the Pause comes
from that reader's start-up, and with nothing queued after `OMO_01.BGM` the drive keeps reading on the PS1 as
well. The PS1's next load is MOVIE.BIN (the opening movie): FIELD gets message 6, which sets its "movie
pending" flag (+0x638) and starts a screen transition (`func_80066FB0` code 0x69); when that finishes,
`func_80067134` calls `func_8007A410` and the game object asks the overlay loader for MOVIE
(`func_8007A1F4(self, 3)` → `func_80051930(loader, …, 0)`). In the port FIELD's messages stop after 0xD
(BGM loaded): the 0x67 action posts 0x1002 to the game object, the party object handles it and Koudelka's
character gets kind 8 / 0xA, and nothing sends FIELD its 6. Next: find which step after the character's 0xA
differs (a DuckStation breakpoint on FIELD's message-6 case, 0x800BBD80, shows the sender).

Also: `D_FAA0`, an absolute linker symbol (EFFECT's size, used by the overlay loader's copy), is emitted as
an absolute symbol instead of a function stub (gen_stubs `absolute`). `KOUDELKA_TRACE_CD=1` now logs the
command, mode, the reader object, pauses, and the reader's state for the first sectors of each read.
