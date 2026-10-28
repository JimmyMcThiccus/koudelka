# main_a2b drafts (round 3)

Near misses for `src/main/u_8003C510.cpp`; each file's first line says what differs. None are built.

Blocked by the unit layout, not the source: the small globals below are reached with `$gp` in some functions
and with `lui` (assembler macro) in others of this one unit, so `--gp-from` (symbols the unit's retail asm reaches
through `%gp_rel`) can only be right for one group. The unit holds more than one original source file.
- `D_800B4D38`: `$gp` in `func_80044BE4`; `lui` in `func_8004297C`, `func_80043060`, `func_80043680`, `func_800436C0`,
  `func_80043700`, `func_80043DF0`, `func_80045850`, `func_800459D4`, `func_80046948`. So boundaries lie between
  `func_80043DF0` and `func_80044BE4`, and between `func_80044BE4` and `func_80045850`.
- `D_800B4D28` / `D_800B4D30`: `$gp` in `func_800419F4`, `func_80041B54` (and `D_800B4D30` in `func_80041B44`);
  `lui` in `func_8003DC54`, `func_8003DEA8`. So a boundary lies between `func_8003DEA8` and `func_800419F4`.
Affected, unlanded: func_80043680, func_800436C0, func_80043700, func_80046948 (tiny; lui form), and likely the
bigger users above.
