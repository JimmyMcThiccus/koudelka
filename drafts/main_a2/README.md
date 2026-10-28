# main_a2 drafts (round 2)

Near misses; each file's first line says what differs. None of these are built.

Blocked by the toolchain rather than the source: functions that load a $gp-area global with the
assembler-macro `lui` form (D_800B4ED8, D_800B4D38, D_800B4CF0, D_800B4C18, D_800B4D04, stores to
D_800B4D0C through $at). tools/maspsx_extern.py registers every small `.extern` as $gp, but ASPSX only
used $gp inside the defining file (see the main_b r2 gp finding). Examples in this area: func_8003D384,
func_80043680, func_800436C0, func_80043700, func_80046948, func_800534F8, func_80053568, func_800535E0,
func_800382A4, func_800499D0, func_8004D0F4, func_80037440, func_80052FB8.

Also not landed: func_800544AC (uses `new T[n]`, which emits __builtin_vec_new; retail calls it as the
unnamed func_800A0D2C, so the link fails until that symbol is named in config/symbols/main.txt).

## Round 3 additions
The `$gp` problem above is gone (`tools/cc.py --gp-from` is per unit); D_800B4C18 / D_800B4D0C now come out right.
New near misses (first line of each file says what differs): func_8003A214, func_80038D34, func_8003B68C,
func_80035C30, func_80032B2C. func_8003B598 follows func_8003B68C. Other open ones: func_80036EC0, func_8003585C (load
order/registers), func_8003479C, func_8003572C, func_8003BF30.
