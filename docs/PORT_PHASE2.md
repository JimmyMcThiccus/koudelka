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

Kept in the "Status" section below as the work goes: files compiling, recompiled files compiling, unresolved
symbols by kind, stubs added, where it stops.

## Status

(filled in as the implementation proceeds)
