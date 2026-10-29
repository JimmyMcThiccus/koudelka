# PC port feasibility (32-bit Windows build against PsyCross)

Round 4, track D. Read-only measurement of master `32b33e5`; nothing in `src/`, `include/`, `config/` or `tools/` was
changed. Everything below was counted from `asm/`, `src/`, `config/symbols/*.txt`, the built `build/*.elf` and
`build/**/*.o`, and from PsyCross at commit `e56e4cd` (https://github.com/OpenDriver2/PsyCross, cloned read-only
outside the repo). The scripts and raw JSON are in the shared notes folder, `side-session-notes/<session>/port-feasibility/`;
they are not in the repo because `tools/` was off limits for this task.

**Short version**

- PsyQ API: of 179 PsyQ functions the game calls (732 call sites), PsyCross has 74 working (412 sites), 33
  as stubs or empty bodies (143 sites), 63 missing (154 sites), and 9 I could not identify. The missing ones
  cluster in libpress/MDEC (FMV), CD streaming, SPU voice envelopes, memory-card BIOS calls, and six small libgte routines.
- The big structural costs are not the PsyQ calls. They are: **all writable data and all vtables are still asm**
  (5,540 pointer words in asm data), **the overlay scheme** (six overlays sharing one address range), **24-bit
  ordering-table pointers** in the game's own OT code, **GCC 2.8 C++ ABI assumptions** (hand-walked vtables), and
  **666 functions still in asm**, 45 of which are not ordinary C.
- Rough total: 21–41 person-weeks (5–10 months) to something playable end to end, of which about 8–13 weeks
  get the EXE booting into its scheduler. These are judgement estimates, not measurements (see "What I could
  not measure").

---

## 1. PsyQ calls vs PsyCross

### Method

- **Game side:** every `jal X` and every tail `j X` to a non-local label in all 5,493 functions' asm (the
  `matchings/` copies are the original code of the decompiled functions; `nonmatchings/` is the 666 still in asm).
  This is the original binary's call set, so it equals the calls in `src/` plus the calls inside asm-only
  functions. Cross-check against `src/`: 123 of the 142 named callees also have a call expression in `src/`; the
  other 19 are only called from asm-only functions.
- **What counts as "PsyQ":** a callee whose address is in the linked-in library block `0x80094910–0x800A4514`
  (`asm/main/psyq.s`, 613 functions) or, for MOVIE, in libpress `0x800CAF80–0x800CBB00`. Of the 613, 245 have an
  API name in `config/symbols/main.txt`, 277 are `*_OBJ_*` internals, and 91 are unnamed.
- **Unnamed callees.** 36 of the called functions in the library block have no name in the symbol file (plus 17
  unnamed libpress internals in MOVIE). I identified 27 from their disassembly (e.g. `func_80094990` is
  `syscall 0` = `EnterCriticalSection`; `func_80098DF0` writes len 3 / code 0x60 = `SetTile`; `func_800A0D2C` is
  `operator new` wrapping `__builtin_new`); 4 of those are host functions. The identifications are in the notes
  below. 9 stay unknown.
- **PsyCross status**, read mechanically from its source (`src/psx/*.C`, `src/**/*.cpp`, `include/psx/*.h`):
  - *covered* = a definition with a real body
  - *partial* = a definition whose whole body is `PSYX_UNIMPLEMENTED()` or empty (links and runs, does nothing)
  - *missing* = declared in a header only, or absent. Either way it is a link error.

  I did not read each body for correctness. "Covered" means "exists", not "right for this game".
- **Host** = provided by the host C/C++ runtime, or a no-op on a PC (14 functions, 1,340 sites, plus
  `EnterCriticalSection`/`ExitCriticalSection`, 2 functions, 18 sites). Not counted below.

### Result

179 PsyQ functions, 732 call sites (excluding host/no-op):

| Class | Functions | Call sites |
|---|---:|---:|
| covered | 74 | 412 |
| partial (stub/empty) | 33 | 143 |
| missing | 63 | 154 |
| unknown (unidentified) | 9 | 23 |
| host / no-op (not counted above) | 16 | 1,358 |

By library (functions / call sites):

| Library | covered | partial | missing | unknown |
|---|---:|---:|---:|---:|
| libgpu | 21 / 141 | – | 2 / 7 | – |
| libgte | 20 / 173 | – | 6 / 18 | – |
| libcd + St* | 8 / 40 | 5 / 16 | 11 / 26 | 1 / 1 |
| libspu / libsnd | 12 / 34 | 7 / 36 | 12 / 33 | 4 / 7 |
| libpad (new API) | 5 / 12 | 5 / 12 | – | 1 / 2 |
| libetc / interrupts | 3 / 6 | 1 / 3 | 1 / 2 | 1 / 1 |
| libapi (root counters) | 4 / 4 | 1 / 9 | – | – |
| kernel/BIOS stubs, events, file API (incl. `firstfile`) | 1 / 2 | 8 / 49 | 7 / 28 | 2 / 12 |
| libcard (old pad/card) | – | 6 / 18 | – | – |
| libpress (MDEC), MOVIE only | – | – | 24 / 40 | – |
| libc / libgcc / crt | host: 14 functions, 1,340 sites | | | |

**Covered, most-called first** (call sites): `ratan2` 58, `SetDrawMode` 56, `SquareRoot0` 44, `SetSemiTrans` 20,
`SpuSetKey` 12, `SetRotMatrix` 12, `CdControl` 11, `LoadImage` 11, `ApplyMatrixLV` 10, `SetLightMatrix` 9,
`CdReadyCallback` 9, `SetGeomScreen` 8, `CdControlB` 8, `SetTransMatrix` 7, `DrawOTag`/`SetDefDrawEnv`/
`SetDefDispEnv`/`SetDrawArea`/`ApplyRotMatrix`/`CdGetSector` 5 each, `ResetGraph`/`DrawSync`/`GetTPage` 4, and
about 45 more with 1–3 sites each. Includes most of libgpu/libgte, `ResetGraph`, `PutDispEnv`/`PutDrawEnv`, `VSync`,
`CdInit`, and `PadInitDirect`/`PadStartCom`/`PadSetAct`.

**Partial** (linked but does nothing in PsyCross):
- `SpuSetIRQ` 19 sites (16 in CAPTURE), `SpuSetIRQAddr` 7, `SpuSetIRQCallback` 2 (all stubs)
- `SpuSetCommonAttr`, `SpuSetReverbModeType`, `SpuReadDecodedData`
- `OpenEvent` 9, `EnableEvent` 10, `CloseEvent` 9, `DisableEvent` 9, `TestEvent` 8 (stubs)
- `StopRCnt` 9 (empty), `StopCallback` 3
- `_card_load`/`_card_clear`/`_card_info`/`_card_format`/`InitCARD`/`StartCARD`/`_bu_init`/`_96_init`/`LoadExec` (stubs)
- `PadEnableCom` 5, `PadInfoAct` 4, `PadInfoMode`, `PadSetActAlign`, `PadSetMainMode` (stub/empty, so no analog/vibration negotiation)
- `CdSyncCallback` 9, `CdReadCallback` 1, `CdSync` 1, `CdLastCom`/`CdMode` 5

**Missing** (link errors), by group:
- *libpress / MDEC (MOVIE overlay only):* `DecDCTReset`, `DecDCTin`, `DecDCTout`, `DecDCTinSync`,
  `DecDCToutCallback`, `DecDCTvlc2`, `DecDCTvlcBuild`, plus 17 unnamed internals (`LIBPRESS_OBJ_*`,
  `BUILD_OBJ_AC`, `func_800CBA80`) that the movie code calls directly (40 sites in all). PsyCross has `libpress.h` declarations and no
  implementation; its README lists "MDEC implementation in LibPress" as TODO.
- *CD streaming (MOVIE):* `StSetRing`, `StSetStream`, `StClearRing`, `StFreeRing`, `StGetNext`, `StCdInterrupt`,
  `CdRead2`, plus `CdReset` 6, `CdMix`, `CdStatus` 8, `CdFlush` 3 (declared only).
- *SPU:* `SpuSetVoiceRRAttr` 6, `SpuSetVoiceLoopStartAddr` 6, `SpuSetVoiceARAttr` 3, `SpuSetVoiceSRAttr` 3
  (the envelope setters; PsyCross's README also lists SPU ADSR as TODO), `SpuSetNoiseVoice` 3, `SpuSetPitchLFOVoice` 3,
  `SpuSetNoiseClock` 2, `SpuSetReverbModeDelayTime`/`Feedback` 2 each, `SpuGetIRQ`, `SpuGetIRQAddr`, `SsUtReverbOff`.
- *libgte:* `SquareRoot12` 4, `ReadLightMatrix` 4, `TransRot_32` 3, `VectorNormal` 3, `VectorNormalS` 2,
  `OuterProduct0` 2. Small; each is a few lines over the existing GTE emulation.
- *libgpu:* `SetDrawOffset` 5 (header only), `SetLineF2` 2.
- *Memory card, BIOS level:* `open` 8, `close` 4, `read` 4, `write` 2, `erase` 4, `firstfile` 4, `nextfile` 2, all
  in FIELD and MOVIE (the same memory-card code is in both overlays). PsyCross's libmcrd is a different (high-level)
  API, so this needs a host save-file shim.
- *Other:* `DMACallback` 2.

**Host-provided (not gaps):** `__builtin_new` 813 sites, `__builtin_delete` 183, `operator new`/`delete` wrappers
119/111, `rand` 67, `memset` 19, `exit` 13, `__divdi3` 5, `strlen` 4, `strncmp` 2, `strcpy`/`memcmp`/`__main`/`start` 1 each.
**No-op on PC:** `EnterCriticalSection` 10, `ExitCriticalSection` 8 (in PsyCross they are commented out).

**Unidentified** (9, 23 sites): `func_80094A20` (8 sites, memory-card BIOS, FIELD/MOVIE), `func_800950A0`,
`func_8009F6D0`, `func_800A1B9C`, `func_8009EAE0`, `func_8009F5E0`, `func_800A0A10`, `func_8009DDC0`, `func_8009A470`.

**Notes on identifications** (from disassembly, not from symbols): `func_80099C60` = `SetGeomOffset`,
`func_80099C80` = `SetGeomScreen`; `func_80098DC0` = `SetSemiTrans`; `func_80098DA0` = `TermPrim`;
`func_80098E10` = `SetLineF2`; `func_8009CAC0`/`func_8009CAE0` = `CdSyncCallback`/`CdReadyCallback` (which is which is a
guess from data order); `func_8009C9C0` = `CdStatus`; `func_8009CA60` = `CdFlush`; `func_8009CA80` = `CdSync`;
`func_8009D000` = `CdDataCallback`; `func_8009D030` = `CdReadCallback`; `func_8009F700`/`func_8009EBC0`/`func_8009F0E0` =
`SpuSetNoiseVoice`/`SpuSetReverbVoice`/`SpuSetPitchLFOVoice` (via `_SpuSetAnyVoice` with command words 0xC8–0xCD);
`func_8009F2C0` = `SpuGetIRQ`; `func_800949B0` = `SetSp`.

### What this means

- **CD:** the game's `CdControl` commands, extracted from the constants passed at 19 call sites, are Nop (0x01),
  Setloc (0x02), ReadN (0x06), Stop (0x08), Pause (0x09), Setmode (0x0E), GetTN (0x13) and ReadS (0x1B). There is
  no Setfilter (0x0D) and no Play (0x03), so I found no XA ADPCM or CD-DA use. PsyCross has no XA or CD audio
  either, and the game does not seem to need it. Disc files are read with the ordinary `Cd*` calls PsyCross covers.
- **Audio:** the game has its own 5,412-line sound driver (`src/main/sound.cpp`, built with PsyQ 4.1) that drives
  SPU voices through libspu and does not touch SPU registers itself (0 game functions use `0x1F801xxx`, see §3).
  PsyCross's SPU layer is OpenAL with no ADSR, and the driver calls the envelope setters (declared only) and the IRQ
  setters (stubs). Audio is the least certain part of the port.
- **FMV:** MOVIE needs a real MDEC. Plan on replacing the libpress surface with a software decoder.

---

## 2. Pointers in data

### Method

Two views, because the build uses part of `asm/*/data/` and ignores the rest. The linker script takes `.rodata`
for game units from the *C objects*, which contain the 870 `INCLUDE_RODATA` blocks plus compiler-generated tables. It takes asm
data objects only for the overlay header/entry table (`0.rodata.s`), `*.data.s`, `.sdata`, `.bss`, and the EXE's
`ctors`/`psyq` rodata.

1. **Asm-resident data** = the linked asm data objects + the `INCLUDE_RODATA` blocks referenced from `src/`.
   Counts below are `.word` entries that are a symbol (`func_X`, `D_X`, a named function) or a raw `0x80xxxxxx`
   value that is a function entry (overlay tables point at EXE functions by raw address, so splat could not name them).
2. **Whole linked image**: every aligned word in the `.rodata`/`.data`/`.sdata` regions of the built ELFs whose value
   is in `0x80010000–0x80200000`, classed as function entry, inside a function (jump-table target) or other.

### Result: asm-resident data that must become C data

| Target | Asm data words | Function pointers | Data pointers | Blocks (with pointers / all) |
|---|---:|---:|---:|---:|
| EXE (`main`) | 22,654 | 2,849 | 69 | 393 / 968 |
| FIELD | 3,399 | 1,310 | 0 | 163 / 277 |
| BATTLE | 964 | 398 | 0 | 65 / 91 |
| MOVIE | 2,171 | 501 | 0 | 61 / 181 |
| CAPTURE | 396 | 145 | 0 | 39 / 68 |
| GAMEEND | 127 | 57 | 0 | 6 / 7 |
| EFFECT | 514 | 211 | 0 | 44 / 49 |
| **Total** | **30,225** | **5,471** | **69** | **771 / 1,641** |

- **5,540 pointer words** in total. They are vtables, handler tables and script/command tables.
- Their targets are function entries. Only 69 words point at data.
- The EXE's `.data` is 15,710 words, **67,304 bytes**, with only 172 function pointers and 53 data pointers.
  Plus `.sdata` 748 bytes and `.bss` 7,944 bytes.
- **No C object in the build defines any `.data`, `.sdata` or `.bss`** (`.data`/`.bss` size 0 in every
  `build/src/**/*.o`). Every writable global is defined only in asm and referenced from C as an absolute
  `extern`: 1,148 distinct `D_XXXXXXXX` symbols are referenced from `src/`+`include/` (572 in overlays, 419 in EXE
  rodata/text region, 94 in `.sdata`, 60 in `.data`, 3 in `.bss`). A port has to define each of them with a
  type.
- Overlay `.data`: FIELD 2,040 bytes, MOVIE 4,124, BATTLE 52, CAPTURE 64, EFFECT 16. Overlays have no `.bss`.
- Raw `0x80xxxxxx` words (unsymbolised) are included above. The overlay ones, 1,603 in all (FIELD 855, MOVIE 333,
  BATTLE 264, CAPTURE 62, GAMEEND 46, EFFECT 43), are all exact EXE function entries (the base-class methods in
  the overlay vtables). The EXE has 110: 58 point at overlay function entries (its overlay tables), 10 at overlay
  addresses that are not entries, and 42 `.data` words at EXE text that is not an entry (I did not resolve
  these; they may be data that looks like an address).
- **Jump tables for functions still in asm:** 1,269 entries in 51 functions (EXE 1,027 in 35; FIELD 68 in 8;
  BATTLE 28 in 4; MOVIE 127 in 2; CAPTURE 13 in 1; EFFECT 6 in 1). They disappear when those functions become
  C.

### Cross-check: whole linked image

| Target | Function-entry words | Jump-table words (compiler) | Other |
|---|---:|---:|---:|
| EXE | 2,849 | 1,155 | 56 |
| FIELD | 1,311 | 88 | 1 |
| BATTLE | 400 | 85 | 0 |
| MOVIE | 505 | 210 | 0 |
| CAPTURE | 145 | 13 | 1 |
| GAMEEND | 57 | 0 | 0 |
| EFFECT | 211 | 132 | 0 |
| **Total** | **5,478** | **1,683** | **58** |

5,478 function-entry words in the image against 5,471 in asm blocks: **essentially every function-pointer table in
the game is still asm** (all vtables sit in `INCLUDE_RODATA`, since they could not be matched from C). The
1,683 jump-table words are generated by the compiler (or belong to asm-only functions) and cost nothing in a port.

---

## 3. Hardware dependence

Counted over all 5,493 game functions (reference asm of the decompiled ones plus the asm-only ones). `psyq.s` is
counted separately because PsyCross replaces it.

| Dependence | Game functions | Of which now C / still asm | Notes |
|---|---:|---|---|
| Scratchpad `0x1F800000–0x1F8003FF` | **20** | 10 C / 10 asm | EXE 9, FIELD 1, BATTLE 3, EFFECT 7. In `src/`: `D_1F800000` appears on 43 lines in 6 files (mostly EFFECT's `effect_b.cpp`/`effect.cpp`) |
| I/O registers `0x1F801xxx` | **0** | – | The only users are 8 Sony functions in `psyq.s` (`C_011_OBJ_948/9C4/A20`, `func_800A2CC8/2EEC/3B78/3B98/3F20`: CD/DMA/SPU/interrupt code PsyCross replaces) |
| Overlay slot `0x800B6DF0` (`ovl_header`) | **2** (`func_80027E30`, `func_800515F4`), both asm | 0 C / 2 asm | plus `start` in `psyq.s`; see below for the wider coupling |
| GTE (`cop2`/`mtc2`/`mfc2`/`ctc2`/`cfc2`/`lwc2`/`swc2`) outside libgte | **55** (EXE 30, BATTLE 10, EFFECT 15) | 17 C / 38 asm | 780 instructions: `lwc2` 394, `swc2` 134, `mfc2` 121, `mtc2` 95, `ctc2` 21, `cfc2` 15. The C ones use inline `__asm__` (EXE 6, EFFECT 11) |
| Marked `/* Handwritten function */` | **58** (EXE 23, FIELD 4, BATTLE 10, MOVIE 6, EFFECT 15) | 17 C / 41 asm | 34 of the asm ones are GTE routines |
| `cop0` (`mtc0`/`mfc0`/`rfe`) | **0** | – | `psyq.s` has 2 |
| `syscall` | **0** | – | `psyq.s` has `func_80094990`/`func_800949A0` (`EnterCriticalSection`/`ExitCriticalSection`) |
| `jalr` (indirect calls, mostly virtual) | 933 | – | not hardware, but see §5 |

(80 game functions contain `break 6`/`break 7`. These are the compiler's divide-by-zero guards from the
`expand_div` build flag, not hardware dependence.)

**GTE.** libgte itself (25 functions in `psyq.s` use `cop2`) goes away with PsyCross's software GTE. The 55 functions
above do GTE work outside it:
- **Asm-only (38):** EXE `func_8003148C`, `func_800318A8`, `func_80031CE4`, `func_80032504`, `func_80032F80`,
  `func_80033404`, `func_800338A4`, `func_80034184`, `func_8003A7FC`, `func_8003AD78`, `func_80049488`,
  `func_80049680`, `func_80049FB8`, `func_8004A16C`, `func_8004AF54`, `func_8004B124`, `func_8004B408`,
  `func_8004B690`, `func_8004D798`, `func_8004D9AC`, `func_8004E2B0`, `func_8004E4FC`, `func_8004E834`,
  `func_8004EB28`; BATTLE `func_800B82C0`, `func_800B85B8`, `func_800BB354`, `func_800BB5EC`, `func_800BBF84`,
  `func_800BD328`, `func_800BD5C4`, `func_800BD9F4`, `func_800BDC28`, `func_800BE3B4`; EFFECT 4 more. The largest
  have 30–38 `cop2` instructions each (matrix/vertex transforms).
- **Already C with inline GTE (17):** EXE `func_8002F960`, `func_8002FD5C`, `func_80030358`, `func_80030714`,
  `func_80030B10`, `func_800311CC`; EFFECT 11 (`func_800D75D4` etc.). Those need their inline `__asm__` turned
  into PsyCross's `gte_*` macros.

**Scratchpad functions:**
- EXE: `func_80034EBC`, `func_800493A0`, `func_80049618`, `func_8004AE24` (C); `func_8003CB50`, `func_80046998`,
  `func_80049488`, `func_80049680`, `func_80050EA4` (asm)
- FIELD: `func_800BFED4` (asm)
- BATTLE: `func_800BA764`, `func_800BAE04`, `func_800BB8F8` (asm)
- EFFECT: `func_800D7524`, `func_800E1090`, `func_800E1304`, `func_800E1604`, `func_800E2704`, `func_800E2944` (C), `func_800E0E70` (asm)

On a PC, `D_1F800000` becomes a 1 KB static array; nothing else is needed.

**Setjmp-style hand-written functions.** `func_80018F0C`, `func_80018FA8` and `func_800190A0` (asm, `src/main/u_80018B88.cpp:137–141`)
save and restore the full register file, including `$sp`, `$k0`, `$k1`; `func_80018F0C` also calls `operator new`
(size `[a1+8]*4`) and stores the result at `jb+0x88`, `func_800190A0` makes a virtual call, and I did not trace what
the allocated buffer holds (it may be a stack snapshot, which would make this more than a fiber swap). They are the context switch of the coroutine scheduler in `src/main/u_8001DDF4.cpp`
(call sites at lines 269, 301, 339, so only three). On a PC they become Win32 fibers (or a hand-rolled swapcontext).
`SetSp` (`func_800949B0`, called twice from EXE code) also swaps the stack pointer.

**Overlay slot coupling (the wider picture).**
- Beyond the 2 `ovl_header` readers, **65 EXE functions (25 asm-only) hold absolute references to 130 distinct
  addresses in the overlay region**: 28 functions reference 70 addresses in the shared slot
  `0x800B6DF0–0x800D5DAC`; 44 functions reference 60 addresses at or above `0x800D5DAC` (EFFECT, which sits inside the shared slot's
  address range). 57 of them reference overlay *functions*, so the EXE calls overlay code (mostly EFFECT) at fixed addresses.
- Each overlay also begins with a header: an id word (FIELD 4, BATTLE 5, MOVIE 6, CAPTURE 7, GAMEEND 8) followed by GCC 2.x vtable
  entries, which the EXE indexes through `ovl_header`.
- **The overlays collide.** From the six overlay ELFs' symbol tables: 3,889 overlay-defined symbols, of which **130 are
  defined in more than one overlay** (115 in two, 9 in three, 2 each in four/five/six), e.g. `func_800B8210`
  exists in several overlays as different functions, because they share addresses. None collides with an EXE symbol.
- In the EXE there are also fixed buffer addresses outside the symbol scheme: `func_80027A60` loads to `0x80018000`/
  `0x8009D000`, and `func_80023F50`/`func_800240C0` compare against `0x8017FFFF` (the RAM limit). Only 3
  functions have raw `0x80xxxxxx` literals in asm (`src/` has 16 lines with such literals, most of them `0x80000000`
  flag/sentinel values).

---

## 4. Remaining asm (666 functions, 96,751 instructions)

| Class | Functions | Instructions | Where |
|---|---:|---:|---|
| Sony library (libpress/MDEC) | 28 | 698 | all MOVIE: 12 named (`DecDCT*`, `DecDCTvlc2`, `DecDCTvlcBuild`, `DecDCTvlcSize2` …) + 16 internals (`LIBPRESS_OBJ_*`, `BUILD_OBJ_AC`) |
| Hand-written, GTE (`/* Handwritten function */` + `cop2`) | 34 | 6,071 | EXE 20 (the `func_8003xxxx`/`func_8004xxxx` set), BATTLE 10, EFFECT 4 |
| Hand-written, other | 7 | 264 | `func_80018F0C`, `func_80018FA8`, `func_800190A0` (context switch); MOVIE `func_800C22E8`, `func_800C2360`, `func_800C23D8`, `func_800C2450` (30 insns each) |
| GTE, not flagged hand-written | 4 | 474 | EXE `func_8004B124`, `func_8004B690`, `func_8004E4FC`, `func_8004EB28` |
| Sound driver (Konami, PsyQ 4.1) | 6 | 519 | `func_8008BE08`, `8008BECC`, `8008BF78`, `8008C6B0`, `8008D97C`, `80090CF4` |
| **Ordinary game code** | **587** | **88,725** | EXE 364, FIELD 122, BATTLE 68, CAPTURE 17, EFFECT 12, MOVIE 3, GAMEEND 1 |
| **Total** | **666** | **96,751** | EXE 397, FIELD 122, BATTLE 78, MOVIE 35, CAPTURE 17, EFFECT 16, GAMEEND 1 |

(GTE-bearing asm in all: 38 functions, 6,545 instructions, 676 `cop2` instructions.)

So **45 of the 666 are not ordinary C** (34 + 7 + 4 hand-written/GTE), plus the 28 Sony ones, which a port
replaces rather than decompiles. The remaining **593 (587 + the 6 sound-driver ones) are ordinary compiler
output.** Their size distribution: median 114 instructions, 129 are 200 or more, 54 are 40 or fewer, largest 2,214.
For a port they need not match; they only need to behave.

**Drafts help.** 180 of the 666 have a C draft in `drafts/` (EXE 61, BATTLE 48, FIELD 38, EFFECT 16, CAPTURE 13, MOVIE 3,
GAMEEND 1; 21,349 of the 96,751 instructions). The drafts compile but do not match the bytes. I did not check whether
any of them behave correctly, so treat them as a head start, not as done.

### Needed at boot / the first scene

I could only partly answer this. Static reachability from `main` (direct calls, address-taken functions, and
function-pointer tables that live in asm data) reaches **340 of 3,283 EXE functions, 23 of the 397 asm-only ones**:
`func_80018D80`, `func_80018FA8` (context switch), `func_8001AF8C`, `func_8001BE9C`, `func_8001D150`, `func_80023450`,
`func_800240C0`, `func_80025CE0`, `func_80026558`, `func_8002673C`, `func_800269B8` (660 insns), `func_80027E30` (overlay
load), `func_8002900C`, `func_80029414`, `func_8002B9B4`, `func_8002D24C`, `func_8002F21C`, `func_8002F2A4`,
`func_80035384`, `func_8003556C`, `func_80035C30`, `func_80036850`, `func_80036EC0`.

This is a lower bound. `main` makes only seven direct calls and then enters the scheduler, whose objects are
reached through vtables. The C objects' vtables and the overlay entry tables were not followed, so overlay
reachability came out as zero and should be ignored. The reliable way to get the boot and first-scene set is a
coverage run under PCSX2 (the repo has the PCSX2 MCP), which this task did not do. Practical consequence:
**every asm-only function in the EXE is a candidate blocker**, and the context-switch routines (`func_80018F0C`/`FA8`,
`func_800190A0`) are needed by the scheduler from the first frame.

---

## 5. 32-bit assumptions

A 32-bit build keeps `sizeof(void*) == 4`, so what breaks on x64 does not break here. The measurements bound what a later 64-bit port would cost
and show where the 32-bit build still has risks of its own.

| Measure | Count |
|---|---|
| `FIELD_AT(p, type, off)` uses (raw byte offsets) | **5,043 uses in 1,137 functions** (EXE 900 + EFFECT 237, out of about 3,470 function bodies in those two areas; my brace-depth count, not an exact function count) |
| …with a pointer-typed field | **1,559 uses in 593 functions** (`void *` 851, `char *` 250, `int *` 61, `void **` 47, `VtEntry *` 43, others) |
| Where | EXE only: `u_80071A74` 1,058, `sound.cpp` 982, `u_80085168` 329, `u_80068770` 314, … ; EFFECT 1,187 (`effect.cpp` 643, `effect_b.cpp` 544). FIELD, BATTLE, MOVIE, CAPTURE, GAMEEND: **0** |
| Other raw-offset idiom `((char *)p + 0x..)` outside the macro | ~160 lines |
| Pointer-to-`int` casts `(int)&x`, `(int)p->…` (syntactic, imprecise) | ~62 lines (EXE 27, FIELD 11, EFFECT 8, BATTLE 7, CAPTURE 7, MOVIE 2) |
| `sizeof(void *)` in `src/`/`include/` | 0 |

- On a 64-bit build, all 1,559 pointer-typed `FIELD_AT` uses and every struct with a pointer would break
  (the offsets bake in 4-byte pointers). On the 32-bit build they are fine.
- **What a 32-bit build does not fix: the C++ ABI.** The code is GCC 2.8.1 C++. 296 `virtual` lines in 24 files, and
  **68 functions walk a vtable by hand** (`vt[n].pfn`, `.delta`, `struct VtEntry { short delta; short index; void (*pfn)(...); }`
  = the GCC 2.x 8-byte vtable entry). Overlay headers and the 5,471 asm function-pointer words are in that format.
  Any compiler other than GCC 2.x (MinGW/clang use the Itanium layout; MSVC differs again) lays vtables out
  differently and does multiple-inheritance `this` adjustment differently, so those 68 functions and the asm vtables
  cannot be used as they are. This is the largest 32-bit-specific risk. The repo's own notes on multiple-inheritance casts and
  virtual-base constructors point at the same area.
- **Ordering tables use 24-bit addresses.** The game has its own OT code with `struct P_TAG { unsigned addr : 24;
  unsigned len : 8; }` defined in four headers (`h_u_80028428.h`, `h_u_8002C90C.h`, `h_u_8002DED8.h`, `decls_b.h`),
  `tab[i] = (unsigned long)prim & 0x00ffffff`, and its own `POLY_F4`/`POLY_FT4` layouts. 7 `0xFFFFFF` masks in `src/`.
  PC heap pointers do not fit in 24 bits, so OT linking breaks even at 32 bits. PsyCross avoids this with
  `USE_EXTENDED_PRIM_POINTERS`: a `uintptr_t addr` tag, a `pgxp_index` field, and primitives larger than on a PS1. The game's
  hand-laid primitive structs and any fixed strides or offsets into them must move to PsyCross's primitive types.
  I did not measure how many prim-offset assumptions there are.
- 324 `asm("func_X")` symbol renames, 7 top-level `.set` aliases, 15 `register ... asm("$2")` pins and 58 other inline
  `asm` statements in `src/`+`include/` are GCC 2.8 / MIPS idioms that need removing or rewriting. Track A reduces the renames.

---

## 6. What I could not measure

- **Whether the source compiles on a host compiler.** No `gcc`, `clang` or `cl` is installed here, so I could not
  build one TU to count errors. Item 1 of the work list is therefore the least certain.
- **PsyCross correctness.** Coverage is by presence (regex over definitions); I did not read each body or run
  anything. Its headers are Psy-Q-compatible but I did not diff them against the 4.6 libraries the EXE links.
- **Indirect calls.** 933 functions use `jalr`; any PsyQ function reached only through a pointer is not in §1.
- **Boot and first-scene set** (see §4): lower bound only, no dynamic trace.
- **Prim/OT layout assumptions**, **`int`-held pointers**, **file-format structs containing pointers**: only
  syntactic counts.
- **Speed of non-matching decompilation.** The only measured rate is round 3 (351 matching functions, 7 sessions),
  which does not carry over. The effort for the 587 ordinary asm functions is a guess.
- **Unnamed PsyQ functions.** 27 were identified by reading disassembly, 9 were not; 3 of the identifications
  (the `CdSyncCallback`/`CdReadyCallback` pair, `CdLastCom`/`CdMode`, `SpuSetReverbDepth`) are guesses. The XA/CD-DA conclusion rests on
  `CdControl` constants found within 14 instructions before each of 19 call sites.
- **Runtime semantics** of the overlay loader (`func_80027E30`, `func_800515F4`) and the SPU IRQ use were not studied.

---

## 7. Work list, 32-bit Windows build against PsyCross

Effort is a judgement in person-weeks of focused work by one developer driving Claude sessions. It is not
a measurement, and the ranges are wide on purpose. Items are in dependency order.

| # | Item | Why / what | Effort |
|---|---|---|---:|
| 0 | **Prerequisites and decisions** | Finish track A (one prototype per function; the build must not carry 604 multi-prototype functions or ~300 aliases). Pick a toolchain: MinGW-w64 `i686` or clang for x86 (MSVC cannot take the GNU `asm("label")`/`.set` idioms; check symbol decoration, since i686-w64 mingw prefixes C symbols with `_` and `asm("name")` labels do not get it). Pin PsyCross `e56e4cd`. CMake project skeleton, SDL2/OpenAL. | 0.3–0.5 |
| 1 | **Compile the EXE game code on the host** | Turn off `INCLUDE_ASM`/`INCLUDE_RODATA` (asm-only functions become link-time stubs that abort), remove or replace the 324 renames, 7 `.set` aliases, 15 register pins, 58 inline asm, GCC-2.8-isms and `__attribute__((section))`. Link against PsyCross with a stub `main`. Size is unknown (§6): no host compile was possible. | 1–2 |
| 2 | **Asm data to C** | Generate C from `asm/*/data` and the 870 `INCLUDE_RODATA` blocks: 67 KB `.data`, `.sdata`, `.bss`, 30,225 words, 5,540 pointer words, 1,148 referenced `D_` symbols. Pointers become real addresses of real objects (`u32` slots on a 32-bit build), function tables become arrays of function pointers. The generator is quick; typing the globals and fixing initializers is the work. Remove the absolute-address linker scheme. | 1.5–3 |
| 3 | **Vtable/ABI layer** | Decide how to keep the GCC-2.x vtable semantics on a modern compiler: either emulate the 8-byte `{delta,index,pfn}` layout with explicit tables for the classes that are walked by hand (68 functions, 296 `virtual` lines in 24 files), or rewrite those classes with host virtuals. Fix multiple-inheritance and virtual-base constructors (repo notes already cover the GCC 2.x recipe). Then regenerate the 5,471 asm vtable words against the result. | 1–2 |
| 4 | **OT / primitive layout** | Replace the four `P_TAG` definitions, the 24-bit `addr`, the `& 0x00ffffff` masks and the private `POLY_*` structs with PsyCross's primitive types (`USE_EXTENDED_PRIM_POINTERS`). Find and fix hard-coded primitive offsets and strides. Untested risk: unknown count of such assumptions. | 1–2 |
| 5 | **Overlays in one executable** | Link six overlays plus EFFECT into one program: namespace the 130 colliding symbols, replace `ovl_header` and the overlay loader (`func_80027E30`, `func_800515F4`) with a table of per-overlay entry points, make the EXE's 65 absolute overlay references ordinary links, drop the CD-load-to-fixed-RAM step. | 1–2 |
| 6 | **Hand-written asm** | Three context-switch routines to Win32 fibers (2–4 days); 38 asm GTE functions (676 `cop2` instructions) and 17 inline-GTE C ones to PsyCross's `gte_*` macros/software GTE (1.5–2.5 weeks with checks against PCSX2 traces); 1 KB scratchpad array; `SetSp`. | 2–3.5 |
| 7 | **PsyCross quick fills** | Add the missing small functions: 6 libgte (`SquareRoot12`, `ReadLightMatrix`, `TransRot_32`, `VectorNormal(S)`, `OuterProduct0`), `SetDrawOffset`, `SetLineF2`, `Cd{Status,Flush,Mode,Reset,Mix}`, Enter/ExitCriticalSection no-ops, host `new`/`delete`/libc, real `OpenEvent`/`TestEvent`-family event stubs that fire (the game uses events for completion waits), the old-card and BIOS stubs behind a save-file shim, `Pad*` negotiation, `StopRCnt`/`StopCallback`, `DMACallback`. | 1.5–2.5 |
| 8 | **Memory card** | Host-file-backed implementation of the BIOS file API the game uses (`open`/`read`/`write`/`close`/`erase`/`firstfile`/`nextfile`, `_card_*`, `InitCARD`/`StartCARD`/`_bu_init`), used by the same code in FIELD and MOVIE. | 1 |
| 9 | **Audio** | SPU envelope support (the `SpuSetVoice{AR,SR,RR}Attr`, loop start, noise, LFO, reverb parameters), IRQ semantics for `SpuSetIRQ`/`IRQAddr`/`IRQCallback` (19+7+2 sites; the driver and CAPTURE depend on them), then tuning against the original. Highest uncertainty in the list. | 2–4 |
| 10 | **Remaining 587 ordinary asm functions** (+6 sound driver) | Decompile to C that behaves, not necessarily bytes. 180 have non-matching drafts to start from (21,349 of 96,751 instructions). The other ~75,000 instructions have no draft and include most of the large functions. No measured rate for non-matching work (§6); the range assumes about 25–50 functions per agent session with review. | 3–6 |
| 11 | **FMV (optional first)** | Replace libpress (28 Sony asm functions, 24 missing symbols) and the St*/CD streaming path with a software MDEC + STR demux behind the same calls. Can be stubbed to skip movies until later. | 2–4 (0.3 to stub) |
| 12 | **Integration and testing** | Boot, title, first scene, then each overlay. The only oracle is PCSX2 (traces, memory diffs; the repo has the PCSX2 MCP). Open-ended; the figure is for reaching the first scene and a full playthrough smoke test. | 4–8 |
| | **Total** | | **≈ 21–41** |

Milestones and an order that fails early:
1. Items 0–1, then 7 and 4: a window that opens and draws the GPU test pattern from game code. About 4–6 weeks.
2. Items 2, 3, 5: the EXE boots into the scheduler and loads overlays. Another 4–7 weeks.
3. Items 6, 8, 9, 10, 12: playable. The rest.

## 8. Risks

Ranked by how much each can move the estimate.

1. **GCC 2.x C++ ABI (item 3).** The vtable and multiple-inheritance layout is assumed by hand-written code in 68
   functions and by 5,471 data words. No host compiler reproduces it. If neither emulating the layout nor rewriting
   the classes is cheap, this item can dominate the whole port.
2. **Unknown host-compile surface (item 1).** I could not build anything, so the count of GCC-2.8-isms that a modern
   compiler rejects is unmeasured.
3. **Audio fidelity (item 9).** PsyCross's SPU has no ADSR and the game's own driver (5,412 lines) depends on envelope
   and IRQ behavior PsyCross lacks. Getting it to sound right is open-ended.
4. **OT/primitive layout (item 4).** 24-bit tag addresses break at any pointer width, and primitives change size under
   PsyCross's extended pointers. A hidden stride or offset shows up as corrupted geometry, not a crash.
5. **No dynamic oracle of the boot path (§4).** Without a coverage trace, the 587 ordinary asm functions cannot be
   ordered by need. They also have no tests: non-matching C that compiles but misbehaves is invisible until a scene
   renders wrong.
6. **Overlay and data-model rewrite (items 2, 5).** Replacing absolute-address data and fixed overlay addresses with
   linked objects touches nearly every file, and the two items interact. The generator is cheap, the debugging is not.
7. **MDEC/FMV (item 11).** A software MDEC is well understood, but PsyCross has none and the game's STR streaming
   code depends on ring-buffer and interrupt timing.
8. **PsyCross itself.** README says "95% compatible" and lists TODOs; I could not verify behavior. Its headers target a
   newer Psy-Q than the 4.6 libraries the EXE links, so struct layouts and some signatures may differ.
9. **Memory-card and events** (items 7–8) are small but gate saving and several load paths (the game waits on events).
