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
