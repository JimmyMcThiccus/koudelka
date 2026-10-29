# Prototype v0.906 (`Prototype/`)

Findings from comparing the four-disc Koudelka "VER_0.906" images with retail disc 1 (`SLUS_010.51`).
Nothing here is game data; the prototype and its extraction (`extracted/proto_disc1/`, git-ignored) stay out of the repo.

**Bottom line: there are no symbols, no source-file names and no debug files.** What the prototype gives us is a *different, older
build of the same code* to compare against, plus the debug strings of a PsyQ library (libds) that retail doesn't contain.
It is a Japanese build (`SLPS_024.60`), not a US one, so the data and text differ throughout.

## 1. Disc layout (`tools/extract_iso.py`)

```
python tools/extract_iso.py Prototype/KOUDELKA_DISC_1_VER_0.906.BIN extracted/proto_disc1
python tools/extract_iso.py Prototype/KOUDELKA_DISC_N_VER_0.906.BIN <out> --list   # file lists for discs 2-4
```

| | retail disc 1 | prototype disc 1 |
|---|---|---|
| boot file (`SYSTEM.CNF`) | `SLUS_010.51` | `SLPS_024.60` (discs 2-4: `SLPS_024.61/.62/.63`, all 675,840 bytes) |
| region string in the EXE header | North America | Japan |
| files in the ISO | 2475 | 2350 |
| of those, same name and same size | 1764 | 1764 |
| same name, different size | 583 | 583 |

* **Only in the prototype:** `MONSTER/SC11_0.MCF`, `MOVIE/SC12_0.MCF` (on discs 2-4, `MOVIE/SC16_0.MCF` on disc 2), the boot EXE.
* **Only in retail:** the EXE, `_ZYXWVUT.ZYX` (a 28 MB filler file, not examined), `MENU/GETMAGIC.BIN`, and
  about 120 death/hide motions (`MOTION/GROUP*/NNN/DTH_NNN.MTN`, `DHID_NNN.MTN`, plus `IDVCM`/`VICTM` for the three party members),
  so those animations were added after 0.906.
* **No** `.SYM`, `.MAP`, `.ELF`, `.CPE`, `.TXT`, `.LOG` or other development files on any of the four discs. Extra names like
  `BIN/DISKNO1..4.BIN` and `BIN/SECT.DAT` exist in retail too. Discs 2-4 look the same as disc 1 here: 2354 files each,
  the same three proto-only names, ~585 size differences.
* The overlays have the same sizes on all four prototype discs (BATTLE 114,944, FIELD 203,388, ...). I didn't hash them.
* `MDT/*/*.MDT` field maps are ~5.4 KB (OMO), ~6 KB (HAB/WTA) smaller in the prototype than in retail; `MONSTER/BIM.AR` is 3.3 MB
  *larger*. That's data, not code, and I didn't look further.

## 2. Main EXE

| | retail `SLUS_010.51` | proto `SLPS_024.60` |
|---|---|---|
| file size | 677,888 | 675,840 |
| load address | 0x80010000 | 0x80010000 |
| entry (`pc0`) | 0x800A0A20 | 0x8009BEB8 |
| text size (header) | 0xA5000 | 0xA4800 |
| initial SP | 0x801FFFF0 | 0x801FFFF0 |
| gp | 0 | 0 |

The EXE is a straight relative of retail: same load address and stack, about 2 KB smaller. The kernel-side `$Id:` strings
(`sys.c 1.140`, `bios.c 1.86`, `intr.c 1.75`) are identical in both: the same PsyQ kernel library. Those are the only `.c` names in
either file, and we already have them from retail.

### How much code is the same

Method (approximate): take every function in `asm/` (sizes from the `nonmatching` headers, 3205 in the EXE), read its words from the
retail binary, mask relocations (`j`/`jal` targets, `lui` immediates, and `$gp`-/`lui`-based lo parts for load/store/`addiu`/`ori`
within 40 words of the `lui`), and search the identically masked prototype image for the same word sequence anywhere. "Prefix" =
no full match, but the first 8 words match somewhere (function exists but changed). "None" = neither; this includes real rewrites and
anything my masking got wrong, so treat it as an upper bound.

| target | functions | exact | prefix-8 only | none | exact % of code words |
|---|---:|---:|---:|---:|---:|
| EXE | 3205 | 2456 | 261 | 488 | 61% |
| FIELD | 711 | 480 | 119 | 112 | 48% |
| BATTLE | 478 | 219 | 107 | 152 | 21% |
| MOVIE | 270 | 171 | 28 | 71 | 38% |
| CAPTURE | 289 | 247 | 15 | 27 | 60% |
| GAMEEND | 9 | 6 | 2 | 1 | 44% |
| EFFECT | 346 | 297 | 12 | 37 | 75% |

(Of the "exact" ones, about 515 in the EXE and 95 in FIELD are 4 words or fewer, which can match by chance.)

So the prototype is the same compiler and mostly the same source; large functions (battle logic, the field engine) were
the ones that changed. That's consistent with earlier notes ("86% of EXE functions byte-identical", which counts functions, not words).

## 3. Overlays

Overlay files start with the id word (4 FIELD, 5 BATTLE, 6 MOVIE, 7 CAPTURE, 8 GAMEEND, 9 EFFECT), same as retail, so the header scheme is
unchanged. **The load addresses differ**, because the EXE's BSS is bigger in the prototype. I found the base by finding which one
makes the most `jal` targets land on function prologues (retail reproduces 0x800B6DF0 and 0x800D5DAC; EFFECT follows BATTLE in both):

| overlay | retail size | proto size | retail base | proto base |
|---|---:|---:|---|---|
| FIELD | 211,632 | 203,388 | 0x800B6DF0 | **0x800B8518** |
| BATTLE | 126,908 | 114,944 | 0x800B6DF0 | **0x800B8518** |
| MOVIE | 89,272 | 67,888 | 0x800B6DF0 | **0x800B8518** |
| CAPTURE | 50,220 | 48,380 | 0x800B6DF0 | **0x800B8518** |
| GAMEEND | 3,248 | 3,228 | 0x800B6DF0 | 0x800B8518 (too few calls to confirm; entry-table words fit) |
| EFFECT | 64,160 | 66,100 | 0x800D5DAC | **0x800D4618** (= 0x800B8518 + BATTLE size) |

The shared slot is 0x1728 bytes higher in the prototype. Every absolute address (data, tables, calls to the EXE) therefore differs
between builds, and no 1:1 address map exists. Matching has to go by code content, as above.

## 4. Strings

Plain-ASCII strings were compared between the two EXEs and the six overlays. Result:

* **No** source-file names, no function-name strings, no asserts, no debug-menu text, no map/symbol blob. The only `.c` names are the three
  kernel `$Id:` lines above.
* Most "different" strings are game text. The game stores its dialogue and item names in an obfuscated two-characters-per-byte encoding that
  shows up as `@C`/`LKAOF`-looking runs. It's Japanese in the prototype and English in retail, so the diffs are not debug leftovers. Retail
  also has some plain English item names in MOVIE (e.g. `Cat Food`, `Gargoyle Killer`), and the memory-card save id
  (`BASLUS-01051` vs `BISLPS-02460`), which are the region-dependent strings.
* **The one real find: libds debug output** in the prototype EXE (rodata 0x80018294-0x80018484), absent from retail:

  ```
  DsSearchFile: searching %s...      DS_newmedia: Read error in ds_read(PVD)
  DS_cachefile: %d files found       DS_newmedia: %d dir entries found
  ```

  Three prototype functions print these: `DsSearchFile` at 0x8009ED34, `DS_newmedia` at 0x8009F034 and `DS_cachefile` at 0x8009F3A4
  (plus a `CD001` ISO-9660 check at 0x8009FE3C). `DsSearchFile` is never called from game code in the prototype (`DS_newmedia` is called only from
  inside the library), so it was linked in as part of a libds object. That is the **debug build of PsyQ libds** (libcd's higher-level
  layer). Retail links none of it: it has no `Ds*` strings and no function similar to these (best structural similarity to any retail
  function in the library region is about 0.4), so these names don't transfer to retail. They are useful only as a clue about the SDK
  the prototype was built with.

## 5. Symbol data and how it could map

There is none: no SN Systems `.SYM`, no `.MAP`, no embedded symbol table in either image, and nothing in the disc file lists.
There is nothing to map onto retail addresses.

## 6. What is useful

1. **Earlier revision of the same code.** About 77% of EXE functions and 46-86% of the overlays' functions (by count: FIELD 68%, BATTLE 46%, MOVIE 63%, CAPTURE 85%, EFFECT 86%) are byte-identical
   modulo relocations, so any function in the "prefix-8 only" or "none" bucket can be compared with an older version of itself
   (what was added or reordered). BATTLE and FIELD are the most different (BATTLE is 12 KB smaller). A script that builds a
   retail-address to proto-address map by masked-word search (as in section 2) would let `tools/func_diff.py`-style diffs work across the two.
2. **Region differences.** The Japanese EXE has different text and memory-card ids, which helps tell game-code changes
   from region changes.
3. **Not helpful:** names. Don't expect the prototype to name anything beyond libds' three functions, which retail doesn't have.
4. Everything else on the discs (motion, field maps, sound) is data that differs in size; not investigated.

## Reproducing

Extraction commands are in section 1. The comparison used the function list in `asm/*/{matchings,nonmatchings}/*/*.s` and the
masking rules in section 2; the script was a throwaway and is not in the repo.
