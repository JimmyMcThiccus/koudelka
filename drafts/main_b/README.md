# main_b drafts: near misses and blocked functions

`func_8006B180.cpp` holds the one full draft. The rest are listed here with what differs.

## Close, not matched under PsyQ 4.4

| Function | Diff | What differs |
|---|---|---|
| func_8006B180 / func_8006B1C8 | 2 / 7 | Clamp of the short at +0x2A0. Register allocation: retail does the add in `$a1` (see the .cpp) |
| func_8005BF04 | 9 | Virtual call: retail loads the vptr before `self->0xC` |
| func_8006F10C | 10 | Retail loads the vptr (+0xA4) before the two global stores. The hand-read-vtable trick from func_8006F154 may fix it |
| func_8005C380 | 12 | Unscheduled virtual call (`this` computed before the pfn load, nop in the `jalr` slot) |
| func_8007768C / func_800786A0 | 8 | `while (self->0) f(self);` gets rotated differently (retail has a `j` back to the top) |
| func_8005C26C | 11 | Constructor: `$s0`/`$s1` allocation swapped |
| func_800853D8 | 7 | `b` lands in `$v1`, retail has `$v0` |
| func_80086670 | 5 | 10-byte struct return copied via `$s0`, retail uses `$v0` |
| func_80086E14 | 2 | `%hi(D_800AF470)` temp in `$v0`, retail `$a0` |
| func_8008640C | 6 | Matches only with `-fno-schedule-insns` |
| func_80091B38 | 10 | Divisor/quotient registers swapped |
| func_80063584, 80056B44, 80064884 | 17–24 | `bool` return / virtual base at +0x50 / reload of +0x44 |
| func_8008BE08, 8008C6B0 | 15 | List-walk register allocation, under both 4.4 and 4.1 |

## Blocked on the toolchain

- **Match only with PsyQ 4.1 (sound driver, GCC 2.7.2):**
  - func_8008E678
  - 8008C4B8, 8008C970, 8008D5A8, 8008FD04, 80093A40, 8008D950, 8008E024
  - 8008C928, 8008CD1C, 8008FD44, 8008FD94
  - 80091910, 80091FB4, 8009200C, 80092054, 8009209C, 800920E4, 800921C8, 80092210, 80092258, 8009212C, 80092178
  - 80093858, 800939A8
- **Need maspsx `--expand-div`:** func_80089A4C matches with it; 80089F10 is the same code with `signed char`.
- **Need small externs reached with `lui`, not `$gp`:** these match with plain maspsx and `EXTERN_C int D_x;`:
  - 80059790, 8005C77C, 8005C8B4, 8005C910, 8005EA9C
  - 800689E0, 800745B0, 8006C29C
- **Need ASPSX 2.80+ (`$gp`-relative `la`):** func_80065870 matches with `--aspsx 2.81`.
- **Embedded data in the .s:** func_800756F8. Its `.s` carries the vtable D_80016808, so decompiling it drops the data.

## Blocked on prototypes outside main_b

- func_80054C34 needs `func_80053964(void *self, int b)`. func_80053964 is in main_a's range.
- func_8005F698 needs `func_8005F47C(void)` and `func_8001D024(void *self, int b)`.
- func_8006BC98 returns 1 (`int`), but it is declared `void`.

# Round 2 (branch claude/r2-main-b-6e2409)

218 functions landed (552 -> 334 left). Best attempts that don't match yet:

- `r2_attempts.cpp`: the lead's attempts (one section per function, last variant tried).
- `r2_u_800658E0_near.cpp`, `r2_u_80071A74_near.cpp`, `r2_u_80082174_near.cpp`: helper attempts for those units.

None of these files is built.

## What is left, by cause (334)

| Cause | Count | Notes |
|---|---|---|
| Small global loaded/stored with the assembler-macro `lui $x; lw $x,%lo(sym)($x)` (or `lui $at; sw`) | 120 | Blocked by the toolchain. ASPSX used `$gp` only for symbols defined in the same source file; `tools/maspsx_extern.py` gp-registers every small `.extern`. See the round-2 finding below. |
| Virtual-base ctor/dtor (`in_chrg` tests, 0x50-byte vtable copied to the stack, deltas patched via `self->vbptr`) | 58 | Compiler-generated. Needs real `virtual` base classes, plus their vtable/ctor symbols mapped in `config/symbols/main_b.txt`. Some bases live in main_a's range (func_8001A610). |
| Jump table or data inside the .s | 28 | u_800658E0, u_80071A74 and u_80082174 have rodata segments. Not tried yet: rodata ordering risk. |
| Other | 127 | Mostly large functions, or near misses that are register-allocation only. |

## Closest near misses

| Function | Diffs | What differs |
|---|---|---|
| func_8006C29C | 2 | final store `D_800B4D00 = ...` is the `lui $at; sw` macro (toolchain block) |
| func_8008A2A0 | 3 | final `(sa+sb) < (ta+tb)` sums in swapped v0/v1 |
| func_8007FD60 | 3 | `lui` of D_800AC86C scheduled before the s1=v0 move |
| func_8005717C | 3 | `c = A0 ? 0 : 0xFF` arg layout (a0 = self+0x5C computed in the branch delay slot) |
| func_80070038 | 6 | needs `register int result asm("$2")`; then i / &args[i] swapped |
| func_800766F8, func_800729E8, func_80089AC0 | 6 | prologue order / register allocation |
| func_8005C26C | 11 | constructor: s0/s1 swapped (same as round 1) |
| func_8006C4EC, func_80086578, func_8008A188 | 7 | register allocation |
| func_80057F20 | 7 | prologue: retail stores `self->0x13C` from `$a1`. Caller func_80054D48 needs the `unsigned short` prototype. |
| func_80054B98 / 80054A4C / 80054AF0 | 16+ | ctor with a member List: retail moves `this` to `$v0` right after func_800198E0 and stores through `$v0`; `r = self`, call_value cast and real ctor didn't reproduce it |
| func_800576F8 | 24 | struct return {short,short}; loop exact, tail register allocation |
| func_80061758 | 45 | structure exact. Retail hoists the 99 constant out of the case-4 loop but doesn't strength-reduce `p+0x2A4`. |
| copy ctors with array members (func_800595F8, 8005C968, 8005DFE8, 8005D754, 8005EF58, 80064478) | — | implicit copy ctor loops (`n = 1; ... while (--n != -1)`). Hand-written loops get unrolled. |

Each `r2_*_near.cpp` file starts with the helper's one-line reason per function.

# Round 3 (main_b1)

`r3_attempts.cpp` holds the near misses (one section per function, with what differs). Landed this round: 23 functions.
Things that worked and are reusable:
- `int y = x;` before an `if (x != 0)` call keeps the `addu a2,a1,zero` copy retail has (func_80056B44).
- Ctor returning `this`: type the object as a struct (not FIELD_AT) and cast the last callee to a value-returning type
  (func_80065A00, func_8005C26C). With a struct it hoists `addu v0,s0` to right after the call (func_80054B98 gets to 8 differing).
- Double-buffered prim lists: `idx + i` operand order, `(char*)self + (idx+i)*52` with no block-scope local keeps the rotated loop
  (func_8005E404); the OT insert is `S_OtB::add` (P_TAG bitfield), but in a loop write the mask form (func_8005B66C).
- Unaligned 8-byte struct copy -> `struct U8b { char c[8]; }` (lwl/lwr).
- Stack-passed small structs (`Pt4 {short x,y}`, `Col3 {short r,g,b}` = 6 bytes, 4-byte aligned) as by-value params.
- Virtual calls where retail loads the vptr first: read the vtable by hand (`VE_B *vt = FIELD_AT(self, VE_B *, 0x2C); vt[8].pfn(...)`).
- Virtual-base ctors/dtors skipped (in_chrg, 0x50-byte vtable copy): func_800593A0, 80059958, 8005A518, 8005A62C, 8005AFF0, 8005BC84, 8005CB88, 8005CF78, 8005D8C4, 8005DC44, 80062848, 80062C3C, 80062D60, 80062E9C, 80062FA4, 800630BC, 800637A0, 800639F8, 80064188, 800658E0, 80057214, 80057558, 8005BDA4, 80062A90, 8005652C, 80057C7C, 80068380.

Round 3, batch 3 (virtual-base ctors/dtors, found via tools/twins.py against func_8002C6D4):
- dtor: `p->vt2C=..; p->vb->vt = tab.e; if(!flags){ VTabB50 tmp=tab; p->vb->vt=tmp.e; adj via
  `tmp.e[1].d = tab.e[1].d + (adj = (char*)p - (q = (char*)p->vb - OFF))` (FIELD's expression form; the two-statement form
  swaps registers); base dtor(p,0); if(flags&2) func_8001A610(p->vb,0); if(flags&1) operator delete(p);`
- A derived dtor that inlines its base dtor repeats the vtable block for the base with NO `if(!flags)` (func_80062A90).
- ctor: same, preceded by `if (in_chrg) { p->vb = &p->vobj; vobj.vptr = D_80010178; unk4 = 0; vptr = D_800104A8; }` and the base ctor
  called with in_chrg 0; `VTabB50 tmp;` declared after the base call; returns p.
- Coll iterator (S_CollB{S_ArrB*vb; int idx}) at +0x30: `reset(); while((c=next())) ...` or, when the first next() is folded,
  `for (c = next(); c; c = next())`.
- A definition whose header prototype differs is written with `EXTERN_C void f_def(T *p, int n) asm("func_X")`.

Round 3, batch 4:
- Reading `self->8` back from memory (`if (c == 0) self->0xC = self->8`) reproduces retail's `addu v0,a1; sw v0` (func_80066FB0).
- Two-stage vb ctors (func_80056364/56198) and dtors (func_8005652C): the first, unconditional stage is an inlined sub-object ctor
  on `m = p+0x50` with its own tmp table (declare both `VTabB50`s at function scope so they get separate stack slots when retail does).
- Header prelude declarations can collide with another area's definitions (main_b2 includes decls_b.h): declare helpers as
  `f_v(...) asm("func_X")` aliases.
- func_80057214 / func_80057C7C (composite dtors with member dtors) are still open; Ghidra shows the shape but retail keeps the member
  pointer in a callee-saved register and reads member->vb through it, which GCC folds into p+const here.
