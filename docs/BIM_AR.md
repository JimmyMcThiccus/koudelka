# MONSTER/BIM.AR

Findings from `tools/bim_ar.py` run over `extracted/disc1` (the file is byte-identical on discs 1–4). Nothing here
is game data; the extracted modules go to `build/bim_ar/`, which git ignores.

## Summary

- **BIM.AR is not an archive with an index.** It is 332 blocks back to back (21,115 sectors, 43,243,520 bytes).
  Each block is one monster's data, and its first 20 sectors (0xA000 bytes) are an **overlay image that loads at
  0x800D5DAC**, the EFFECT slot. Only about 31% of the file is image; the other 29.6 MB is models, textures and
  motion data with no code in it (no sector past the image in any block has a prologue or `jr $ra` density).
  The "410 code-like 64 KB chunks" and the 50,852 `jal`s in the first scan were data that happens to decode.
- **The 7 BATTLE call targets are real functions in every block.** `0x800D6328`, `0x800D68EC`, `0x800D7048`,
  `0x800D8F98`, `0x800D8FF8`, `0x800D94F4` and `0x800DA400` start with an `addiu $sp,$sp,-N` prologue in all 332
  blocks, and each is byte-identical in all 52 distinct W0 images. They sit in a **shared base** (below), not
  in any per-monster code. The other 8 of BATTLE's 15 calls are EFFECT functions: EFFECT.BIN and a monster image are
  never resident at the same time.
- **The code is much smaller than the file.** After removing duplicates there are 86 distinct modules (one shared
  base, 52 monster tails, 24 + 9 attachment modules), **about 356 KB of module bytes**, and **about 1,377 functions
  by exact match, or about 659 after masking `jal`/`j` targets**. That is about +12% (masked) to +25% (exact) on the
  project's ~5,500 functions, but only ~85 of those functions (the shared base) are needed by every monster.
- **Same toolchain** as the overlays: GCC 2.8.1 epilogues in 99% of the frame-restoring returns, the `break 7`/`break 6` divide
  guards, three PsyQ 4.1-style stragglers. Splat/maspsx/PsyQ 4.4 apply unchanged.

## 1. Archive format

There is no header in BIM.AR. The file's first word is `0x0000000A` because block 0's image starts with the overlay
id word, not because it counts anything.

### Block index

- A block starts at a sector whose first 20 bytes are `0a 00 00 00` + three zero words + `98 6b 0d 80`
  (`0x0000000A, 0, 0, 0, 0x800D6B98`). Scanning every sector finds **332** blocks and no other `0xA`-headed sector.
  A block runs to the next one: 37–94 sectors (mean 63.6).
- **`BIN/SECT.DAT`** (LBA 2200, 4096 bytes) is the id table: 512 slots of `(absolute LBA, byte size)`,
  little-endian. 96 slots are filled, ids 0..161, naming **95 distinct blocks** (ids 89 and 156 share one). Every
  LBA is `2203 + block start sector`, and the size equals the block's length to the sector. SECT.DAT is identical
  on all four discs.
- Ids come in triples with stride 48 (19/67/115, 11/59/107, 22/70/118, …): the three ids of a triple point at blocks
  whose W0 image is **identical**, with different data after it. 51 of the 52 W0 images are named by some id.
- The other 237 blocks have no SECT.DAT entry. A pair search (`(LBA, size)` as two words) finds them in the
  map files `MDT/*/*.MDT`: each map carries a list near its end (`AZU00000.MDT` at ~0x23E00, and so on) naming the
  blocks its encounters use; this accounts for 94 blocks, 170 with SECT.DAT. **162 blocks have no reference
  found yet**, probably a table in a file type that wasn't searched (MGS event scripts are the next guess).
- The disc has no filename for any of this: the EXE and the overlays contain no `BIM`, `MONSTER` or `SECT` string and no
  immediate 2200/2203. The game addresses files by absolute LBA from tables, like the overlay table at 0x800AE5F8
  (`(LBA, size)` pairs: 801/0x16000 MOVIE, 1200/0x34000 FIELD, 1400/0x1F000 BATTLE, 1000/0xC800 CAPTURE,
  2000/0x1000 GAMEEND).

### Compression

None. The image bytes disassemble directly (prologues, `jal`s into the EXE, vtable pointers into the image), and
`lw`/`sw` offsets in BATTLE line up with the raw data.

### Image layout (first 0xA000 bytes of every block)

| Window | Offsets | vram | Contents |
|---|---|---|---|
| W0 | 0x0000–0x5DE0 | 0x800D5DAC | overlay id `0x0A`, entry table and vtables to 0x3EC, then code. **Identical in all blocks up to 0x4AC0** (the shared base); the rest is the monster's tail (2,588–4,896 bytes), then `0x2A` ('*') fill |
| W1 | 0x5DE0–0x7100 | 0x800DBB8C | a second module: its own id word (0x4B–0x84), a pointer table, code; or all `*` (125 blocks) |
| W2 | 0x7100–0x8420 | 0x800DCEAC | a third, same shape, ids 0x91–0xC2; empty in 297 blocks |
| W3 | 0x8420–0x981C | 0x800DE1CC | data table whose first 4 bytes are the tag `MCTB`; 5,116 bytes; distinct in 306 of 332 blocks |
| pad | 0x981C–0xA000 | | `0x40` fill |

- Fill is `0x2A` between a window's last byte and its end; W1/W2 are only present when needed.
  Combinations: W0 only 125 blocks, W0+W1 172, W0+W1+W2 35.
- Block data after sector 20 starts with small records (`01 00 00 01`, `0a 09 0c 07`, …): model, motion and
  texture data, not examined.

### How the game uses it (what the EXE and BATTLE show)

- `func_800CEC70` (BATTLE) queues the load with `func_800518A8(D_800B4D40, p->f7D8, 0x800D5DAC, 0)`. The request
  state machine `func_800515F4` special-cases a destination of exactly 0x800D5DAC (it skips `func_80025CE0`).
- `func_800CED08` then copies **0x2C bytes from 0x800D5DAC + 0x97F0** into the battle object (+0x7DC). Image
  +0x97F0 is the last 44 bytes of W3 in every block (small counts and ids, then the `0xD800/0xC000` pair),
  so it is the per-monster record.
- BATTLE calls the entry points `D_800DA870`, `D_800DBB90`, `D_800DCEB0` for slots 0, 1, 2 (the function over `T_CEE18`, `src/battle/battle_b.cpp:1630`). Those
  are EFFECT.BIN functions (at 0x5DE4 etc. EFFECT.BIN is code, BIM's W1/W2 are headers), so the three
  entry points belong to EFFECT, and BIM images and EFFECT are exclusive in the slot.
- **Not located:** the code that turns an id into an LBA (reads SECT.DAT or an MDT list) and the size it reads.
  `func_800518A8`'s second argument turned out to be a queue/handle value, not a file id. To confirm, break on writes
  to 0x800D5DAC in DuckStation (`tools/duckstation.py`) during an encounter and walk back to the CD request.

## 2. The modules

Hashes below are of the window's bytes with trailing fill removed (`tools/bim_ar.py`).

| | Distinct contents | Bytes (distinct) | Functions (exact) | Functions (masked `jal`/`j`) |
|---|---:|---:|---:|---:|
| W0 shared base (0x0–0x4AC0) | 1 | 19,136 | 85 | 83 |
| W0 tails (0x4AC0–) | 52 | 208,492 | 656 | 311 |
| W1 | 24 | 93,440 | 458 | 168 |
| W2 | 9 | 35,352 | 178 | 97 |
| **Total** | **86** | **356,420** | **1,377** | **659** |

- **Shared base.** 19,136 bytes at 0x800D5DAC–0x800DA86C: 0x3EC bytes of header and vtables, then ~85 functions
  (109 `jr $ra`). The 7 BATTLE targets are among them (sizes 604, 200, 428, 96, 80, 508, 480 bytes). It calls
  66 distinct EXE functions and 15 BATTLE functions, and its vtable entries point at BATTLE methods
  (0x800C2ECC, 0x800C30F0, …) and at the EXE (0x8001FD00, …). The base is the monster class framework.
- **W0 tails.** 52 distinct monster kinds (one per id mod 48; many ids are variants with identical code). Tails are
  mutually dissimilar: grouping by shared masked-`jal` function bodies at ≥50% overlap gives 34 families,
  one of 13, one of 7 and 32 singletons, so most monsters have their own behaviour. 311 distinct masked bodies
  across all tails. Nearest-neighbour word equality at equal offsets is 0.88–0.99, but that figure is dominated
  by the shared 79%.
- **W1 / W2.** 24 and 9 distinct attachments, one id word each, apparently chosen per monster (W1 present in 207
  blocks, W2 in 35). They call the shared base 995 and 387 times (27 distinct targets each) and the EXE
  5 functions each; they never call a tail. No function is common to all W1 contents.
- **Duplicates.** Of 332 blocks, 308 are distinct as whole blocks, and only 52 / 24 / 9 as W0 / W1 / W2: blocks
  differ mostly in W3 and the data after the image. A few whole blocks occur two or three times (20 appear twice, 2 three
  times), which looks like duplication for CD seek time.
- **Are they per-monster AI?** Yes in the sense that each W0 tail is behaviour code selected by monster type
  (ids mod 48), reached through the base's vtables. SECT.DAT carries ids, not names; the monster name table was not
  searched. `DATA/NAME.TBL` (1,680 bytes) is the obvious next file.

## 3. Size of the work

| Item | Number |
|---|---:|
| Image bytes in the file | 13,598,720 (31%) |
| Distinct module bytes (all 86) | 356,420 |
| Distinct function bytes, exact / masked | 272,332 / ~190,000 |
| Functions, exact / masked | 1,377 / 659 |
| Shared base | 85 functions, 19 KB |
| `jr $ra` over distinct windows | 7,246 |

For scale, EFFECT.BIN is 64,160 bytes and `docs/ROUND4.md` puts the project at ~5,500 functions (666 left), so the
masked figure is about +12% of the function count and the exact one +25%. The shared base alone is a small overlay:
bigger than GAMEEND (3 KB), smaller than CAPTURE (50 KB). The tails are many but small, and 34 of them share nothing but the base.

**Toolchain.** Same as the overlays (`tools/epilogue_scan.py` fingerprints, applied to the raw bytes):

- 4,840 of the 4,894 returns that restore a stack frame (99%) fill the delay slot with the stack restore: GCC 2.8.1.
- `addiu $sp; jr $ra; nop` (the GCC 2.7.2/PsyQ 4.1 form) occurs at exactly three places: 0x800D8FF0 (the end of
  the 96-byte base function 0x800D8F98, a BATTLE target; it needs a PsyQ 4.1 override like CAPTURE's 14),
  0x800DB7AC (one tail) and 0x800DCACC (one W1 module).
- The divide guard is present: 420 `break 7` and 420 `break 6`, equal counts, over distinct windows.
- The 66 EXE functions the base calls and the 15 BATTLE ones are all at known addresses (`config/symbols/`).

## 4. Proposal: how to add build targets

Not done yet. Order and shape:

1. **`tools/bim_ar.py --extract` (exists)** writes `build/bim_ar/bim_base.bin`, `w0_<hash>.bin` (tails),
   `w1_<hash>.bin`, `w2_<hash>.bin` and `manifest.json` (name, vram, size, sha1, how many blocks use it, SECT ids).
   Run it from `configure.py` before generating the ninja file, like `extract_iso.py`. It needs
   `extracted/disc1/MONSTER/BIM.AR` and `BIN/SECT.DAT`, so BIM targets are skipped when absent.
2. **Target 1: `bim_base`.** Splat yaml with `target_path: build/bim_ar/bim_base.bin`, `vram: 0x800D5DAC`, 19,136
   bytes: `rodata` for the header and vtables to 0x3EC, then cpp from 0x3EC. `DEPENDS = ["slus_010.51", "battle"]`
   (the base calls both and BATTLE's methods are in its vtables), and treat its 7 BATTLE-called entry points as
   `config/pins.txt` entries so a functional build keeps them in place. Its symbol file,
   `config/symbols/bim_base.txt`, is read by every later BIM target.
3. **Targets 2…86: one per distinct tail / W1 / W2 content**, generated from a template by a `tools/gen_bim_yaml.py`
   (a loop over `manifest.json`). Each gets `base_path`, `vram`, the same symbol lists plus `bim_base.txt`,
   and `DEPENDS` on `bim_base`. Use `[0x0, rodata]` for the id word and pointer table of W1/W2.
4. **Shared source.** A function that appears in several tails or W1/W2 modules at different addresses should be
   written once. Splat names functions by address, so have the generator write a per-module symbol file that names
   every function by its **masked-body hash** (`bimf_<hash>`); the same function in different modules then has one
   name, one `src/bim/<family>.cpp` definition, and per-module differences are only link addresses. Modules
   are compared and linked one at a time, so equal names in different targets don't collide.
5. **Scope.** Start with `bim_base` plus the largest tail family (13 images, 311 masked bodies overall), which
   validates the generator and the shared-source scheme, then take the rest by family. Every target goes through the
   existing byte-identical gate (`sha1` per module in `manifest.json`); functional mode additionally needs the
   pins for each module's entry table (the first words of each window are vtable-style pointers into the module).

Risks and open questions:

- The 5 blocks of exactly 93 sectors have all three windows full (no `*` fill); `window()` trims correctly, but a
  full W1/W2 means its true end is the window edge, so check those against the linker's idea of size.
- Whether the loader reads the whole block or only the image decides how W3 and the data after sector 20 are consumed;
  the id→LBA code is still to be found (see §1).
- A tail's masked-body match is a lower bound on sharing: bodies with data-address operands (`lui`/`addiu` into
  the module's own rodata) differ if their rodata moved. Expect the real number between 659 and 1,377.
- The prototype (v0.906) has a different BIM.AR (46,548,992 bytes); not examined.

## Reproducing

```powershell
py -3.14 -I tools/bim_ar.py --disc extracted/disc1 --out build/bim_ar [--extract]
```

Prints and writes `summary.txt`, `blocks.csv` (one row per block) and `funcs.csv` (one row per distinct
`(address, body)` function), and with `--extract` the 86 module files and `manifest.json`.
