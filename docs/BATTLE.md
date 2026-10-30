# Koudelka battle system map

Phase 2 of `docs/SH_BATTLE_PATCH.md`: what Koudelka's battle code does and which functions a Shadow Hearts battle
replacement would touch. Read-only analysis; no source, header or config changed.

**Method.** Decompiled C in `src/battle/`, `src/main/u_*.cpp`, `src/bim_base/`, `src/bim/`, `src/effect/`; the asm in
`asm/` for the functions still `INCLUDE_ASM`; headers `include/battle/battle.h`, `include/bim/bim.h`,
`include/shared/exe.h`. Ghidra was not running. DuckStation was read (memory only, no pause) for a few object dumps early
on, then not used at all on the integrator's order; everything it would have settled is listed in section 11.

**Conventions.**
- Addresses are `func_XXXXXXXX` as in our sources; `battle_b.cpp:530` means the file in `src/battle/`.
- `[H]` read directly from code or asm, `[M]` inferred from several call sites, `[L]` guess.
- Names such as "scene", "mgr", "holder" are ours, not the game's.
- Object roles (all one run-time graph):
  - **scene** = the EXE singleton `*D_800AF470` (0x574 bytes, ctor `func_8007E684`). Owns the game mode.
  - **holder** = `scene+0x328`, the EXE party/actor holder (sub-object at `+0xB8`).
  - **mgr** = `scene+0x32C`, the BATTLE controller (0x958 bytes, ctor `func_800C56A8`). In `battle.h` it appears as
    `T_C6194`, `T_C5E1C`, `T_C9A4C` and others: successive views of the same object.
  - **fighter** = a party or monster object (EXE base class, ctor `func_80084130`, record stride 0x4A0 in the actor list).

## 0. One-page picture

```
FIELD  --func_80079918 (frame timer)--> func_8006B540 transition --> func_8007F89C --> func_8007A1F4(scene, 2)
        BATTLE.BIN read to 0x800B6DF0 (0x1EFBC), first 0xA000 B of the BIM.AR block to 0x800D5DAC
scene (EXE)  --func_8007908C(pad)-->  mgr: func_800CB174 (cursor states)
mgr: func_800C6194 (per-turn driver)  <--  func_800C65C8 (pop next actor from the tick timeline)
   player: menu (func_800CBA80 -> func_800D05C4 window)  -> func_800CBBB4 (command) -> cursor -> b4AD / b4AE
   monster: fighter->v16(&f4B0) (BIM module AI) -> b4AD / b4AE
   b4AD/b4AE -> func_800CACD8 / func_800CAD5C -> func_800CADDC (6-state action sequencer)
        2: load BIM block   3: load EFFECT.BIN over it   4/5: EFFECT controller runs the action presentation
        hit frame -> v03/v04 (func_8008A858 / func_8008A93C) -> event 0x1003/0x1004 -> func_800883A0 / func_80088794
                 -> func_80086B70 (HP) / func_80086CAC (MP)  -> popups (func_800C1E44)
   all monsters dead -> func_800C68D8 (victory)   party dead -> func_800C6DF4   flee -> func_800CF840 / func_800C7158
   end sequences -> func_8007F8BC -> func_80079C18 -> FIELD
```

## 1. Battle entry and exit

### 1.1 Entry [H unless marked]
- **Trigger.** In the FIELD player update (`src/main/u_80071A74.cpp:423-433`), while the moving flag `+0x5CC` is set a
  per-frame counter `+0x218` counts down; below 0 it calls `func_800745B0` (reload) and **`func_80079918`**
  (`u_80071A74.cpp:2083`). The reload is a uniform random frame count in `[0x2F0 + b, 0x42B + b)`, `b = +0x5CE`,
  via `func_8008B4B4`/`func_8008B444` (`u_80089024.cpp:660`); `b = 0x4B0` when item/flag 0x87 is set [M]. The rate is a
  frame timer, not a per-step roll.
- `func_80079918` checks `func_8006F630(holder)`, `scene+0x540 == 0`, `func_8007E658(holder)` (a block is available),
  increments the battle counter `D_800B4DD0+0x1F6`, freezes the player, snapshots position (`func_8007E214`), clears
  `scene+0x33C` (0 = random, nonzero = scripted) and calls **`func_8006B540(D_800B4ED8)`** (`u_80068770.cpp:721`): SE 0x13,
  camera state, transition effect `func_8006D344`, which on completion calls `func_8007F89C(scene)` ->
  **`func_8007A1F4(scene, 2)`**.
- Scripted battles reach the same `func_8006B540` / `func_8007F89C` with `scene+0x33C != 0` (event opcodes
  in `u_8006CBCC.cpp`, `func_80079ABC`). Scripted battles skip the 40% drop cancel (section 1.4).
- **Mode switch** `func_8007A1F4(scene, mode)` (asm, `u_80071A74.cpp:2305`): modes 0 MOVIE, 1 FIELD, **2 BATTLE**, 3 second
  movie, 4 CAPTURE, 5 GAMEEND. It destroys the old mode's `scene+0x32C/+0x330` objects, sets `+0x364 = 1`, `+0x368 = mode`
  and calls `func_80051930(OVLMGR, scene, overlayId)` (ids 0,1,2,0,3,4).

### 1.2 What is loaded where [H]
| What | Where | Size | How |
|---|---|---|---|
| EXE | 0x80010000..0x800B4EE8 (+ bss to 0x800B6DF0) | 675,560 + 7,944 | resident |
| BATTLE.BIN | 0x800B6DF0..0x800D5DAC | **0x1EFBC** | overlay table `D_800AE5F8` (LBA 1400, 0x1F000 on disc) + size table `D_800137A8[2]`, read by `func_800515F4`/`func_80048D64` |
| slot: BIM block image | 0x800D5DAC.. | first 0xA000 B of a BIM.AR block | `func_8007BE44` stream loader, `func_8007BEA8(.., 0x981C, 0x800D5DAC, 0, 1)`, `func_8007BF48(.., lba, 0xA000)` |
| slot: EFFECT.BIN | 0x800D5DAC..0x800E584C | 0xFAA0 | `func_800CEB5C(p, D_FAA0, D_800D5DAC, 0)`, LBA 0x640 = 1600 (`func_800CEBC4`) |
| unused pocket | 0x800E584C..0x800EA8A0 | 20,564 | never written (see 9) |
| heap | 0x800EA8A0..0x80200000 | 0x115760 | `operator new` |

- The rest of a monster's block (model, textures, motion) is read per monster later; `func_800CF080` -> `func_80042430`
  loads the model from `mgr+0x808[i]` (set in `func_800CEE18`).
- The scene object is permanent; the BATTLE objects are built in the mode-2 construct phase of `func_8007A434` (asm,
  jump table `jtbl_80016FF8`): `new 0x570` -> `func_800B881C` (grid highlighter, stored at `scene+0x384`, vtable
  `D_800B6EFC`), then `new 0x958` -> **`func_800C56A8`** (mgr, `scene+0x32C`). `func_800C56A8` clears the grid
  `+0x14[7][5]`, the turn list `+0xA4`, the reach maps `+0x2C8/+0x380/+0x3A3`, the cell lists `+0x2EC/+0x3D8`, stores
  `scene` in `+0x7D8` (**the correction to `docs/BIM_AR.md`: `mgr->f7D8` is the scene pointer, not a file id**; it is
  passed as the "id" argument to `func_800518A8` and `func_800D9928`), and sets `b954 = 3`.

### 1.3 Monster group and creation [H/M]
- Block choice: `func_8007B5F8` (asm, holder-sub `+0xB8`). Random encounter: index `rand() % func_8007E658(holder)` at
  `+0x50`; `(LBA, size)` = pairs at `holder + idx*8 + 0x1C0/0x1C4`. Scripted: from script variables `scene+0x498`
  entries 0x3C0/0x3E0. The 15-pair table (0x78 bytes) is copied into the holder from the FIELD map record by
  `func_8007DC00` (u_80071A74.cpp:3167).
- Phase 2 (`func_8007A434`, `+0x36C == 0`): **`func_800CED08(mgr)`** (battle_b.cpp:1695) copies the 44-byte formation
  record from image `+0x97F0` to `mgr+0x7DC`: `s7DC` monster count, `s7DE[7]` monster ids, `xy7EC[7]` grid cell per
  monster; `f934 = count + party size (D_800B4DD0+0x1FB)`.
- **`func_800CEE18(mgr, q, x, i)`** (battle_b.cpp:1699), called for each slot by `func_8007CA44`: world position
  `((x-2)*2400, 0, -((y-3)*2400))`, module factory via entry table slot 0 `D_800DA870[0]`, 1 `D_800DBB90[0]`, 2
  `D_800DCEB0[0]` `(scene, i+3, D_800B772C, pos, 0)`; `func_8007B1FC(holder+0xB8, mon, 2)`; `mon->b4BC = i + 3`;
  **`func_800DA400(mon, q, s7DE[i])`** (bim_base asm: init from monster id); `func_8001E848(D_800B4C18, mon)`.
- Grid placement: `func_800CF0B0` (asm) and `func_800C5B4C` (battle_b.cpp:462). `func_8007DEE8(holder, mode)` (EXE asm,
  `jtbl_800170C0`, 12 modes) is the holder's **phase driver** (not only commands): mode 0 builds the `func_800BE484`
  UI/BGM object at `+0x114`, 1 the MCTB reader `func_800D66B0` (table at 0x800DE1CC) or resumes a parked request, 2
  calls `func_800CF0B0`, 3 = intro (`func_800D6198`), 0xA = `func_800BE344` [M].
- Party members are not created by BATTLE; the EXE holder builds them from the save object (`func_8008A188`, section 6).

### 1.4 Exit [M]
- All driven from `func_800C6194` (section 2). `func_800C666C` (battle_b.cpp:625) handles dead monsters: SE 0x16, script
  ops 0x29/0x2C/0x2F, **`func_800CF2D0`** (battle_b.cpp:1728: `s7DC--`; drop roll `rand()%(b94D-b94C+1)+b94C` appended
  to `scene+0x34C[scene+0x348++]`, cancelled with probability 0x4CCC/0x8000 (about 40%) in random battles), removes it
  from grid and timeline, camera cut `func_800CFB08`.
- Victory: `s7DC == 0` -> **`func_800C68D8(mgr, -1)`** (asm, jump table `jtbl_800B75C0`, camera `func_800D6328`).
- Defeat: no party member with HP (`func_800C7528`) -> **`func_800C6DF4(mgr, 0)`** (battle_b.cpp:674;
  states 0..3, `f830 = 0`, `f824 = 2`, fade `func_8006BE4C`).
- Flee: command `func_800CBBB4` -> **`func_800CF840`** (battle_c.cpp:7; `func_8008A2A0` is the escape roll, comparing
  average speed `stat[2]` times `rand()` plus average luck `stat[7]` times `rand()` of the two sides, and returns 0 if
  any monster has `b948`; success sets every monster `s410 = 0`, clears drops, `f830 = 2`) -> **`func_800C7158`**
  (battle_b.cpp:744, `f824 = 3`). Failure shows `func_800D0CC0` ("You can't escape!!").
- After the fade `func_80067134` (u_800658E0, asm) calls `func_8007F8BC` (u_80071A74.cpp:3779), which dispatches on
  `mgr->f824`: 1 -> `func_800C68D8(o, 2)`, 2 -> `func_800C6DF4(o, 2)`, 3 -> `func_800C7158(o, 4)`. Their last states post
  a message to the scene; the event consumer `func_800792C8` calls `func_80079C18` (mode 1 = FIELD).
- Rewards: drops are in `scene+0x348/+0x34C` (consumed in FIELD). **EXP, money and level-up were not found** in
  BATTLE's decompiled part (`func_8008AE38` adds enemy EXP to the fighter's `+0x54C`; the call site was not traced).
  Which of the three end sequences is victory/defeat/flee is inferred from `f824` and callers.

## 2. Turn order and initiative

Koudelka runs a **tick timeline** (CT queue): no rounds, no ATB gauge.

- **Timeline object.** Inside mgr at `+0xA4`: `T_C5474` (`T_D019C`/`T_D0230`): 10 node slots of 0x18 bytes
  (`+0x130`), a clock `f12C` (`+0x12C`), and a 16-record preview ring (0x10 bytes each, at `+0x10`).
- **Insert: `func_800C51D0(timeline, actor, delay)`** (asm, 0x2A4): puts the actor in a free node with due tick
  `f10 = f12C + delay`, `f14 = actor`, kept ordered by due tick (ties by insertion order); shifts the preview ring.
  Negative delay inserts at the front. Remove: `func_800C54D8` (battle_b.cpp:376; used on death by `func_800C5A30`,
  `func_800C5D84_r`, `func_800C5E1C`); `func_800C5B18` re-inserts.
- **Pop: `func_800C65C8(mgr, delay)`** (battle_b.cpp:615): re-insert `fA0` with `delay`, then
  `while (!(fA0 = func_800C5474(timeline))) f12C++;` (`func_800C5474` returns the head if `f10 <= f12C`), then
  `func_800D94F4(fA0 + 0x400)` (bim_base asm, start-of-turn hook).
- **Wait values.** The fighter has a stat block at `+0x400` (section 6). `stat[2]` (effective speed, `b3E` in `BimMon`,
  fighter `+0x43E`) divides the wait; `s80` (fighter `+0x480`, `h480`) is the wait one action costs:
  - monsters: `func_800D8FF8` (bim_base.cpp:490) `s80 = 0x100 / b3E` per action; `func_800D8F98` `s80 = b7D * 0x100 / b3E` per move;
  - players: `v03`/`v04` set `s80 = rec[0] * 0x100 / stat[2]` from the attack record (`func_8008A858`, `func_8008A93C`).
  `f4B4` (`+0x4B4`) accumulates the wait owed this turn; `f4B0` (`+0x4B0`) holds the turn options (bit 0 may move,
  bit 1 may act; 3 at the start of a turn). Initial delay for everyone is `h480` (`c6050_reset`, battle.h:838 and
  `func_800C6050`, battle_b.cpp:519). No random initiative.
- **Per-turn driver `func_800C6194`** (battle_b.cpp:530), called after every pop/step:
  1. empty timeline, or `func_800C666C` (dead monsters, section 1.4) returns early;
  2. `s7DC == 0` -> `func_800C68D8(mgr, -1)`; `func_800C7528` (no living party) -> `func_800C6DF4(mgr, 0)`;
  3. loop on `fA0`: `b46D & 0x80` (stunned) -> `func_800D8FF8`, reschedule `f4B4 + h480`; `f4B0 == 0` (nothing left) ->
     end of turn, `f4B0 = 3`, reschedule `f4B4 (+ h480 if (s4B8 & 0x6B) == 0)`; `s410 == 0` (dead) -> reschedule 1;
  4. otherwise `c->v15()` (virtual, turn start), `func_800CA7D4` clears highlights, then
     - **an action is already pending** (`b4AD`, or `b4AE`): `f4B0 &= ~2`, call `func_800CACD8(mgr, 1)` / `func_800CAD5C(mgr)`
       (these start the sequencer and return 0 until it is finished); when finished clear the latches, `func_80085E14(c)`,
       ops 0x1A (and 0 for side 1), `func_80082E14`, and reschedule with `f4B4`;
     - **otherwise ask for a decision:**
       - **player** (`b4BC < 3`): `f3D0 = 1`; if `f4B0 & 1` `func_800C78EC` + `func_800CA75C` (any reachable cell?), if `f4B0 & 2`
         `func_800CA9D0` with the weapon shape `f550->b16/b17` + `func_800CA75C` (any target?); `func_800CBA80(mgr, f7D8, f4B0, mask)`
         shows the menu and the function returns (input now drives `func_800CB174`/`func_800CBBB4`);
       - **monster** (`b4BC >= 3`): script op 0x29, **`c->v16(&c->f4B0)`** (BIM AI), op 0x2A, `func_80082E14`; if the AI set `b4AD`
         then `f4B0 |= 2`, and the actor is rescheduled at once with `f4B4` (preceded by `-1` when `b4E5` is set: an extra
         turn goes to the front).
- **Teams.** `b4BC` 0..2 party slots, 3..5 monster slots; `b4BD` side 1 party / 2 monsters. Party: `D_800AFA64[3]`,
  monsters: `D_800AFA58[3]` (live dump confirmed team/side bytes). Max 3 + 3.
- **Preview.** The order strip is the preview ring (`func_800D0130` shifts it, `func_800C55C4` rebuilds it:
  `e110[i].b3 = team`, `.s0 = due tick`).
- **Log.** `scene+0x3B0` holds a 32-entry attack log of 4-byte records (`func_800C2ECC`, battle_b.cpp:37).
- Debug residue: `func_800C757C` prints "myActionWait=%d" for `mgr+0x2C4` (an action-wait counter) [M].

## 3. Command flow

1. **Input** is routed by the EXE: `func_8007908C(scene, pad)` (u_80071A74.cpp:2011) -> `func_800CB174(mgr, pad, 1)`;
   `func_800790BC` -> `func_800CB8EC` (camera-relative d-pad basis from `func_800BE09C/E0F8/E108`, yaw from
   `D_800B4DD0`/`func_80062118`; L1/R1/L2/R2 rotate/tilt the camera `func_800BE29C/E2EC`).
   Pad bits (PS1 layout): 0x10 up, 0x20 right, 0x40 down, 0x80 left, 0x100 L2, 0x200 R2, 0x400 L1, 0x800 R1,
   0x1000 triangle, **0x2000 circle = confirm**, **0x4000 cross = cancel**, 0x8000 square. Widgets get an event
   `T_D19F0_q` with pressed bits `h18` (after `func_8001FC78(q, 0, 0)`); the raw active-low word is `h1A`.
2. **Menu.** `func_800C6194` calls `func_800CBA80(mgr, f7D8, f4B0, s)` (battle_b.cpp:1298). It builds a disable mask:
   bit 0 (Move) when `f4B0 & 1` is clear or no reachable cell, bit 1 (Attack) when no target, bit 2 (the rest of the
   root list) when `f4B0 & 2` is clear; then `func_800D0440/func_800D05C4` on the menu holder `mgr+0x908`
   (`func_800D0404`). The window is **`func_800D0D1C`** (battle_c.cpp:167), one 0x5760-byte heap object with four
   command sub-windows selected through `f5754`: `4` +0x54FC code `0x106E` (**Move**), `5` +0x5574 `0x10D3`
   (**Attack**), `6` +0x55EC `0x119A`, `7` +0x5664 `0x11FE`, `8` item list `func_800D5328` (result `func_800D5740` =
   `(index << 16) | 0x10DC`), `9` list `func_800D20E0` (result `func_800D23C0` = `(id << 16) | 0x10E6`, or `0x10E7` for
   item types 12..15), `10` list `func_800D4BFC` (result `func_800D4E68` = `(f2280 << 16) | 0x10F0`). The root
   `func_800D1B68` switches on `f5754`; `func_800D119C` posts a type-7 event to the battle object with `f10 =` the
   command code (`mk_D119C`). Labels of 6, 7, 9, 10 are inferred; the four window codes and the item list are certain.
   Strings are nibble-obfuscated (byte = (c1-0x40) | ((c2-0x40) << 4)); decoded: "You can't escape!!", "You weren't able to
   run away!", "You can't get past the monster!", "HP", "MP", names Koudelka / Edward / James.
3. **Result -> `func_800CBBB4(mgr, event)`** (asm, 0x55C; reached from the EXE event handler `func_80078C50`, jump
   table `jtbl_80016BE8`). `code = event->f10 & 0xFFF`, `index = event->f10 >> 16`:
   - `0x06E` Move: `func_800C78EC(mgr, 0)`, highlight (`func_800CA75C`, `func_800CA710`, `func_800CA7D4`), `f3D0 = 2`;
   - `0x0D3`..`0x0D5` Attack: `f4D4/f4D8 = fighter->f550->b16/b17` (weapon kind and range shape), `func_800CA9D0` builds the
     target area, `func_800CA1B4` selects the first target, `f3D0 = 4`;
   - `0x0DC` item (record from `D_800AEBD4[index]`, 140 bytes each), `0x0E6/0x0E7` item-on-member (`func_80061188`), `0x0F0`,
     `0x19A`, `0x1FE`, `0x262`: other target modes (`f3D0 = 6/7/8`) and `func_800CF8E4`/`func_800CF764` (camera, side flip),
     `func_800CF840` (escape, section 1.4), `func_800C7158`, `func_800D0CC0`.
4. **Cursor states** (`mgr+0x3D0`, `func_800CB174`, asm, 0x778): 2 move cursor, 4 target cursor, 6/7/8 other target
   modes. `func_800C9FFC(mgr, pad)` (battle_b.cpp:1116): cancel -> `func_800CF95C` (camera reset) returns 2, confirm
   returns 3, d-pad -> `c9ffc_dir` -> `func_800CA1B4` (move cursor, SFX 8 ok / 14 blocked). Confirm in state 2 ->
   `func_800C5CC4` (commit move, occupancy, `func_80085A60_b`), `b4AE = 1`; in 4/7/8 -> `func_800C0608` (set target cell, then
   `func_800C0694_t`: `func_800C9D6C` with mode, ops 0x13/0x14, `b4AD = 1`) or `func_800C12D0` (item/magic target,
   `s53C = s50C = 3`, `b4AE = 1`, `func_80085FD4`). Setting `b4AD`/`b4AE` is the hand-off to `func_800C6194`.
5. **Resolution hand-off.** `func_800C6194` sees `b4AD`/`b4AE` and calls `func_800CACD8` (battle_b.cpp:1202; weapon:
   `func_800C07F8` validates and queues ops 0x2F, 0x12, 0x21(0x2036)) or `func_800CAD5C` (item/magic via `func_800C13CC`:
   op 0x15), both then `func_800CADDC(mgr, 0)` with `f900 = s514 + 1` frames of delay.
6. **The sequencer `func_800CADDC(mgr, st)`** (battle_b.cpp:1222), state in `f904`:
   0. BGM (`func_8008EF40(0x17/0x18)`), `func_800CFB08` camera, `func_800CBB54` UI close;
   1. count `f900` down;
   2. `f938 = 1`, `func_800CEC70`: monsters `s214 = 1` (frozen), `func_8007A400`, `func_800518A8(OVLMGR, f7D8, 0x800D5DAC, 0)`
      (the slot is reloaded; see 1.2 and 11);
   3. `func_800CEB04`/`func_800CEB5C`/`func_800CEBC4`: stream **EFFECT.BIN** (0xFAA0) into 0x800D5DAC, `func_800CEC24` polls;
   4. `cf_D9928(new 0x188, f7D8)` (EFFECT controller), for each target `f918[i] = func_800E4434(new 0x18)`
      `{actor, target, ...}` (`func_800C9E58` reads the target list), `func_800DA84C(ctrl, a, b)` with the damage-table pair
      from `func_800C3E84/F14/F84` (weapon table `T_tab[kind].e[]`, `func_800C3D2C`);
   5. per target `func_800DAE98` (`func_800DABA8/AC88` choose slots), then `func_800DB978(kind, sub)` picks the camera from the
      shape `f4D8`; `func_80082E14` runs the actor's script; `func_8001E848(D_800B4C18, resolver)` makes the EFFECT
      controller a per-frame task. EFFECT posts message `0x2069` when it is done.
   Player and monster actions share this sequencer (monsters set the same `f4D0`, `f4D8`, `b4AD` from `v16`).

## 4. Action resolution

All presentation is separate from numbers. The animation script (below) tells the game *when* the hit lands; the
numbers come from the EXE.

- **Action script** (fighter `+0x2A0`, ctor `func_800827EC`): a motion command queue. `func_8008299C(seq, op, a, b, c, d, e)`
  (asm, u_80082174.cpp:285) appends a command (jump table `jtbl_80017768`, ops < 0x33), `func_80082C68(seq, 0x21, obj, msg, prio)`
  and `func_80082D44(seq, 0x22, obj, ...)` queue a **message post** (when the sequencer reaches it, `msg` goes to `obj`,
  usually mgr), `func_80082E14(seq, force)` starts it (`func_80083310` -> `func_800833F8`, asm, jump table `jtbl_80017838`).
  Ops seen from BATTLE: 0 idle; 0x12 weapon attack motion; 0x15 spell/item motion; 0x13/0x14/0x16 move start/end/variant;
  0x17/0x18 reactions; 0x19 pre-turn pose; 0x1A end of action; 0x1C guard on/off [M]; 0x1D set position; 0x1E turn to face;
  0x21/0x22 message post; 0x29/0x2A begin/end group; 0x2C effect/flash; 0x2D/0x2E damage numbers (BIM `func_800D8204/8260`);
  0x2F mode flag. Message ids 0x2023..0x2069 (0x2035 hit reaction from `func_800C2ECC..38FC`, 0x2036 attack/spell start,
  0x202A..0x2030 victory/defeat sequences, 0x2069 EFFECT done). The receiver of 0x2035/0x2036 was not found.
- **Hit entry.** When the animation reaches the hit, game code calls the attacker's stat-block vtable (`+0x49C`) **v03
  `func_8008A858`** (player spell: `MP -= cost << tier`, proficiency, `func_80086F94`) or **v04 `func_8008A93C`**
  (`func_800870E4`) with the attack record. They reset the per-hit queues, set hit count `+0x75`, set
  `s80 = rec[0] * 0x100 / stat[2]`, refresh stats (`func_8008687C`, `func_8008691C`) and **post an event to the target**:
  attack mask `stat+0x90` bit 0x80 -> 0x1002, 0x40 -> 0x1003, else 0x1004. The event handler `func_80088F34`
  (u_80085168.cpp:1428):

  | Event | Handler | Role |
  |---|---|---|
  | 0x1001 | v06 `func_80088DEC` | apply deferred per-hit values |
  | 0x1002 | `func_800D9970` (**BIM base**, asm) | monster-defender physical formula (uses `+0x7E` evade, `func_800D9170`) |
  | 0x1003 | **`func_800883A0`** (EXE asm, 0x3F4) | physical hit |
  | 0x1004 | **`func_80088794`** (EXE asm) | spell / fixed power, no roll |
  | 0x1005 | `func_800D9CB0` (BIM base) | monster-defender spell version |
  | 0x1006 / 0x1007 | `func_8008891C` / `func_80088C8C` | reflected / counter (set `0x6D` bit 1, non-lethal) |
- **Physical formula** (`func_800883A0`; A = attacker fighter, D = defender stat block) [H from asm, per fork]:

  ```
  dist = SquareRoot0(5 * ((ax-dx)^2 + (ay-dy)^2))                 // grid cells at +0x4C6/+0x4CA, about 2.2 per cell
  if (D.mask[0x62] & A.type) { reflect via func_80088280; return }
  for (hit = 0; hit < A.u8[0x475]; hit++) {                        // hit count; D.b76 is the hit index
      rolls = A.stat[5] - D.stat[5] / 2                            // effective stats at +0x3C
      if (rolls == 0) continue                                     // no hit
      p = clamp(A.rec[0x11] - (D.u8[0x7F] - 50), 0, 100)           // accuracy minus evade, func_80087284
      dmg = 0
      for (i = 0; i < rolls; i++)
          if (rand() < 328 * p)                                    // 15-bit rand
              dmg += max(0, A.stat[6] + (rand() * A.stat[7] >> 16) - dist
                              - (D.stat[4] + (rand() * D.stat[7] >> 15)) / 2)
      // first matching mask: absorb (heal) / nullify (0) / half / double / normal; HP vs MP type (type & 0x100)
  }
  ```
  Three `rand()` per roll. **No critical hits were found** (variance comes only from the two spreads; `func_8008A770`,
  `func_8008A96C`, `func_8008AE68` were not read). Spells (`func_80088794`): no hit test, no distance, no variance; power
  is the attack record's `s16` at `+8` (HP) and `+0xA` (MP), mask branches as above.
- **Chokepoints.** Every HP change ends in **`func_80086B70(stat, v)`** (HP, u_80085168.cpp:748), every MP change in
  **`func_80086CAC(stat, v)`** (MP, :789): clamp to +-0x7FFF, status caps (`+0x14 & 0x200` halves and stops at 1 HP;
  `0x6D & 1` cannot die; `0x6D & 2` cannot be healed), append `v` to the per-hit queue (`stat+0x06` HP, `+0x16` MP), clamp to
  `0..max`. Afterwards `func_800890F0` (HP >= 1 unless monster, else `func_800D96F8` BIM) and `func_80087880` (event 0x1001).
- **Status.** `func_800872B8` by `rec[0x13]` (2 dispel, 3 stat-down + counter, 5 flag, 6 raise base stats); stat vectors
  `func_80089DB8/E14` (s8), `func_800898FC/954` (u8), `func_80089D80` clamps to 100. Upkeep `func_80086A20` (v01).
- **Popups.** `func_800C1E44` (battle_b.cpp:5) pops the three queues (HP, MP, status; 0x8000 = empty) and sets
  `b512/b513` (went negative). `func_800C666C` also reads `s50C` (1 kill, 2 hit) and calls `v18(s510, flags)`.
- **EFFECT is presentation only**: camera, effect slots, from/to positions; no damage there (checked in `effect.cpp`).

## 5. The grid

- **Size.** 5 columns (x 0..4) by 7 rows (y 0..6); occupancy `mgr->f14[7][5]` of fighter pointers
  (`func_800CFCC4`, `func_800CFD98`; `in_grid` = `func_800CFCFC`). World position (`func_800BAFEC`, `func_800C5B4C`,
  `func_800C0EB8`): `x = (gx - 2) * 2400`, `z = (3 - gy) * 2400`. Party spawns on row 6, monsters on rows 0-1 (dumps);
  side 1 faces `y - 1`, side 2 faces `y + 1` (`d = -1` for `b4BD == 1`, battle_b.cpp:1032). Camera follows the cursor
  cell (`func_800CF9CC/CFB08`: `(gx*2400-4800, y-200, 7200-gy*2400)`).
- **Fighter fields:** `s4C6` x, `s4CA` y, `s4C8` movement budget, `b4C5` move range (3 players, 2 monsters in dumps), `b4C4`
  placed flag.
- **Placement / move:** `func_800C5B4C` place, `func_800C5CC4` move (updates occupancy, `func_80085A60_b`), `func_800C5E1C`
  / `func_800C5D84_r` remove, `func_800C5EA0` clear, `func_800C5F08` cell contents (-1 off grid, 0 empty, 1 party, 2 monster).
- **Reachability:** `func_800C7D88` clears `b2C8[7][5]` to -1; `func_800C7DD0` (asm) fills it by distance from the actor
  using `s4C8` (reference form `func_800C7764_t`, 4-neighbour: tables `D_800D5D84/D5D94`); `func_800C8EE4` marks the enemy
  side's occupied rows -3 (impassable); `func_800C78EC(mgr, a)` is the entry (returns the number of reachable cells);
  `func_800CA75C` builds the highlight list `f864`; `func_800CA710/CA7D4/CA918` draw/clear highlights through
  `scene->f384` (`func_800B9268/B928C`).
- **Path:** `func_800C7A28` / `func_800CD354` -> `func_800C7B5C`: backtrack from the destination through strictly lower
  distance cells, preferring the neighbour nearest the straight line (`func_800C9EF4`), producing waypoint nodes
  (`func_80085AD4_s`); the actor walks them with ops 0x13/0x1D (`func_800BF76C`, `func_800BF414/F5FC`).
- **Attack shapes.** `func_800CA9D0(mgr, kind, shape)` -> `func_800C800C` (asm) builds `b2C8`; `func_800C9D6C(mgr, a, b, c,
  mode, x)` dispatches on the weapon's `f4D8` mode, each collector fills the target list `f84C[]`/`f848` and the area
  mask `b380[][]`: `1` `func_800C8F78` (asm), `2` `func_800C9284` (self), `3` `func_800C9374` (asm), `4` `func_800C9584`,
  `5` `func_800C9794` (two cells in front), `6` `func_800C98F0` (two behind), **`7` `func_800C9A4C` (every valid cell)**, `8`
  `func_800C9B04` (front row of three), `9` `func_800C9674` (single target with line-of-fire test `func_800C8A54`, flags
  `b3A3`), `11` `func_800C9BFC` (3 x 2 block). Shape 12 selects dead units (revive).
- **Do attacks depend on position?** Yes. Reach is decided by which cells the shape covers from the actor's cell, line of
  fire blocks mode 9, the physical formula subtracts about 2.2 damage per cell of distance, and group attacks hit by area.
- **AI helpers (BATTLE):** `func_800CC3DC` builds the candidate cell list `mgr+0x3D8` (`T_CE044`, 41 `T_CDD0C_e`: cell, fighter,
  flags `h8`, hit counts `fC/f10/f14`); `func_800CC7DC/CC98C/CCB98` score it; `func_800CE154` sorts via `func_800CE854`
  (HP, MP, hit counts); `func_800CCDCC/CCFC0` pick destination and path (`func_800CE4E4/E7A4` distance sorts, tie toggle
  `D_800D5DA8`); `func_800CD488/D790` signed-step and reach-set variants.
- The grid also positions every animation (script op 0x1D), so removing it is not a local change.

## 6. Character data

### 6.1 Fighter layout [H via live dump of one player and one monster, early in the session]
Fighter base ctor `func_80084130` (u_80083EB4.cpp:139); multiple inheritance with a virtual base.

| Offset | Size | Part |
|---|---|---|
| +0x000 | 0x2A0 | actor/model base (`func_80041E54`); `+0x1B8` skeleton ptr (world pos `->+0x34`); `+0x214` s16 freeze flag |
| +0x2A0 | 0x160 | action-script sequencer (`func_800827EC`), vptr at +0x3FC |
| +0x400 | 0xA0 | **stat block** (`func_80086740`), vptr at +0x49C |
| +0x4A0 | 0x0C | actor-list node (`func_80074E28`; BATTLE recovers the fighter as `node - 0x4A0`) |
| +0x4AC.. | | fighter fields (below) |
| +0x52C | 0x18 | list head, vptr `D_80017B94` at +0x538 |
| +0x544.. | | virtual base; **players** extension to +0x598 (`func_80089FD0`); **monsters** extension to >= +0x9F8 (BIM classes) |

Fighter fields: `4AD/4AE` move/action issued latches; `4B0` turn flags; `4B4` accumulated wait; `4B8` u16 status-change
bits (`& 0x6B` suppresses the post-action wait); `4BA/4BB` guard state wanted/applied; `4BC` team; `4BD` side; `4BE` s16
character/monster id; `4C4` placed; `4C5` move range; `4C6/4CA` grid x/y; `4C8` movement budget; `4D0` target ptr; `4D4`;
`4D8` action shape/kind 1..12; `4E2` s16 (2 on both dumps, "battle active"? [L]); `4E4..4E6` misc flags (`4E5` extra turn /
cannot act); `4F0` death handled; `4F6` s16[] per-hit status array; `500/502/504/506/508` total hit steps / current step /
counter flag / ? / counter; `50C` s16 last hit outcome; `50E` result pending; `510` s16 damage passed to `v18`; `512/513`
HP/MP went negative; `516/517` hit-reaction request / guard available; `518` spawn position (16 B); `528/52A` facing,
stance; `53C/53E/540` command phase, selected index, item/skill id; `548` u16 proficiency tier (shifts MP cost); `54A`
progress value; `54C` EXP (`func_8008AE38`); `550` pointer to the equipped weapon record in the save object (`kind =
p[0x1B]`, `uses = p[0x8C]`); `560` u16[12] weapon-skill proficiency (low 10 bits 0..999, rank in the top bits, cap
0xBE7, `func_8008B4E8`); `578` u16[16] spell proficiency; monsters: `948` blocks escape (`func_8008A2A0`), `94A`
occupancy role (1/2), `94C/94D` drop id range, `9C8..9F4` AI state.

Virtual table at `+0x49C` (players `D_80016310`, others `D_80017DFC`; pairs `{delta, fn}`, method N = pair N+1): v00 dtor,
v01 `func_80086A20` upkeep, v02 `func_8008A770`, v03 `func_8008A858`, v04 `func_8008A93C`, v05 `func_800D94A8` (BIM), v06
`func_80088DEC`, v07 `func_8008A96C`, v08 `func_8008AE68`, v09 `func_8008A188` (build stats from the character table), v10
`func_800C2ECC`, v11 `func_800C30F0`, v12..v14 `func_800C3374/35F8/38FC`, v15 `func_800C3CF4`, v16 `func_800C3CFC`, v17
`func_800C3D04`. v10..v17 live in BATTLE (reaction and log side); the numbers are EXE code.

### 6.2 Stat block (offsets inside the +0x400 block)
`+0x06` s16[5] HP-change queue (0x8000 empty); **`+0x10` HP, `+0x12` max HP** (max HP = `stat[1]^2`); `+0x14` hit-type flags
(0x100 MP-type, 0x200 halve / cannot kill); `+0x16` s16[5] MP-change queue; **`+0x20` MP, `+0x22` max MP** (`stat[4]^2 / 10`);
`+0x24` u8[8] base stats; `+0x2C` s8[8] equipment bonus (`func_80086990`); `+0x34` s8[8] temporary modifiers; **`+0x3C` u8[8]
effective stats** = clamp(base + equip + mod, 1..0xB3) (`func_8008687C`); `+0x44/+0x4E/+0x58` three 10-byte resistance masks;
`+0x62..+0x6B` u16[5] combined masks (reflect, absorb, nullify, half, double); `+0x6C` cure mask; `+0x6D` status bits (0x80,
0x40, 0x20 timed with counters at `+0x78..+0x7A`; 0x08 reflect in progress; 0x02 cannot be healed; 0x01 cannot die);
`+0x70` s8[5] status-change queue; `+0x75/+0x76` hit count / index; `+0x7E/+0x7F` evade (BIM resolver / EXE resolver);
**`+0x80` s16 action wait**; `+0x84` 20-byte attack record; `+0x98` timing bytes pointer; `+0x9C` vptr.
**Stat names** (from the eight `ffFortify*` spell records in the EXE at 0x800AEC88.., 0x8C bytes apart, each with a
single `+3` at one index of its 8-byte delta vector): **`[0]` STR, `[1]` VIT, `[2]` AGL, `[3]` DEX, `[4]` PIE, `[5]` MND,
`[6]` INT, `[7]` LUC**. Roles: VIT -> HP (max HP = VIT^2), AGL -> speed (divides the wait), PIE -> MP and the defence term,
MND -> hit-roll count, INT -> attack base, LUC -> attack spread and luck. STR and DEX are unused by the resolvers read.
Live check (section 11): Koudelka 18/13/13/16/15/13/16/11 gives HP 169 = 13^2, MP 22 = 15^2/10, wait 19 = 256/13.

Attack record (20 bytes at `+0x84`, copied attacker -> defender by `func_80089804` for spells): `[0..7]` s8 stat delta
vector, `[8]` s16 HP power, `[0xA]` s16 MP power, `[0xC]` u16 element/type mask, `[0x11]` accuracy, `[0x13]` effect kind.
Spell definitions interpolate between a level-1 and a level-99 vector (`func_80089AC0`).

### 6.3 Persistent data and free space
- `D_800B4DD0` (game state / save object): items are 0x94-byte entries (`+0x18` used/type, `+0x1B` kind, `+0x1C` name, `+0x8B`
  bit 7, `+0x8C` uses), up to 0x30 (`func_80061188`, `func_800619F4`), a second list at `+0x1DE4`; `+0x1A4` 0x7C-byte block;
  `+0x1C4` play time; `+0x1F4` tutorial counter; `+0x1F6` battle counter / menu cursor; `+0x1F8..` flag bit array; `+0x1FB`
  party size; `+0x124..+0x220` checksummed region (`func_80060D9C` sums 0x80 + 0x7C bytes, compared with `+0x220`).
- Per-character save record, 0x60 bytes (`func_8008AFE4` write, `func_8008B084` read, u_80089024.cpp:557/580): stat snapshot
  (HP/max, MP/max, base stats, resist, cure), `+0x20` u8, `+0x22` s16, `+0x24` EXP, `+0x28` u16[12], `+0x40` u16[16]. Which
  `D_800B4DD0` slots hold them was **not located**.
- Sanity Points are out of scope (user decision), so free-space for a new per-character value was not searched.

## 7. Monster AI and the BIM interface

### 7.1 The module
BIM.AR block W0 image (0x800D5DAC..): `bim_base` (identical in all 332 blocks up to +0x4AC0, `src/bim_base`) + a 2.6-4.9 KB
monster tail (`src/bim/w0_*`); W1/W2 modules (ids 0x4B-0x84 and 0x91-0xC2) have their own factories. Entry table (first
0x3EC bytes) = vtables of the shared classes. A monster is a 0xAF0-0xAF8-byte object of one multi-inheritance class
(virtual bases at +0xAE8..+0xAF0): `+0x2A0` script sub-object, `+0x400` stat block (`BimMon`/`BimChar`, `T_C6194_d`),
`+0x4A0` actor-list node. AI state: `f988` chosen skill (1..8), `f990` total skill weight, `s994[8]` cumulative weights, skill
records at `obj + 0x4DC + (skill << 7)` (bytes +2/+3 range shape and distance fed to the grid), `f9F4` skill bitmask, `f9C8`
turn counter, `f9CC` per-turn counter, `f9D4` monster kind, `f9D8` leader flag, `f9E8/f9EC` group flags, **`f9F0` pending
sub-command** (bit values 1,2,4,8,16 set by the decide step and consumed by a handler). A per-module table initialiser writes
`(script id, delay)` pairs at `obj+0xA00..` and registers them in `D_800B4D38+0xF8[slot]`.

### 7.2 What BATTLE calls on a monster (all through virtual slots)
- On the `+0x400` sub-object (default vtable `D_800D5E58`): `v10` `func_800C2ECC` (hit reaction), `v11..v14` reactions,
  **`v15()` once per turn start** (`func_800C3CF4`, returns 1), **`v16(&c->f4B0)`** (default `func_800C3CFC` returns 1;
  **overridden by every module with the AI**, e.g. `func_800DB028` in `w0_2966c8e7b8.cpp:127`), `v17` `func_800C3D04` status hook,
  `v21(flags)` / `v22` module hooks.
- On the monster object: `v18(a1, flags)` (`func_800C666C`), `v10(s53E)` (`func_800C0694_t`), `v3` after death.
- **The 7 bim_base entry points BATTLE jumps to by absolute address:** `func_800D6328` (victory camera), `func_800D68EC`,
  `func_800D7048` (battle_b.cpp:937, builds a 0x24-byte `BimCtl` camera/attack-cut controller from six model pointers),
  `func_800D8F98` / `func_800D8FF8` (wait), `func_800D94F4` (turn start), `func_800DA400` (monster init). Plus `func_800D6198`
  (intro camera, from `func_8007DEE8` mode 3).

### 7.3 How a monster decides (example `func_800DB028`) [H code, M meaning]
`flags = c->f4B0` (bit 0 may move, bit 1 may act); returning 1 means something was issued (the handler cleared the bit it
used). Order: (1) `func_800D7818` setup; (2) if `f9C8 <= 0` and may move: approach (`func_800D8CC0`: target = party member
with the lowest HP fraction `maxHP/HP` via `func_800D8AE4`/`func_800D8854`, or `func_800D7ECC` when `f9D8` is clear; path
`func_800D7BB4` -> `func_800CCFC0`, commit `func_800C5CC4`); (3) `v21(flags)`; (4) group coordination `bimf_06b4d1a5`
(`func_800D8464`, `rand() & 1`, `(rand() & 7) == 7`); (5) HP below a third (`func_800D84C8`) -> half the time a special
attack (`bimf_131b36e3` sets `f9F0 = 0x10`); (6) default attack `bimf_db5f4bc4`.
- Skill pick `func_800D7914(p, n)` (bim_base asm): `n >= 9` weighted random (`r = rand() % f990`, first `i` with `r <
s994[i]`, skill = i+1), `n <= 8` forces skill `n`; then `func_800CC3DC(mgr, (x,y), rec[+2], rec[+3])` builds candidate cells.
- Target helpers (bim_base): `func_800D6584` (random living party member, slot weights {2,1,1}), `func_800D8634/8854` (lowest
  HP% party), `func_800D8524/8744` (same for monsters), `func_800D8464` (living leader), `func_800D8E64(p, n)` (skill id with
  `f9F4` mask test, then `func_80082670`).
- Execution: `func_800D7AC4` (reach cell via `func_800CCDCC`, turn/walk via the model sub-object, `func_800C5CC4`),
  `func_800D7C7C` (signed-step, `func_800CD488`), `func_800D8064` (`func_800CD790`); animations via `func_800D7818` and ops
  0x1D, 0x1E, 0x21, 0x29/0x2A, 0x2C, 0x2D/0x2E, 0x2F.
- Randomness is plain `rand()`. Skill weights come from the monster's data record (loaded in `func_800DA400`/`func_800DA5E0`,
  asm, not read), not from MCTB.

### 7.4 The interface a new turn flow must keep
The module code is in the BIM.AR blocks on the disc (332 pre-linked images). A patch *can* rewrite them but at huge cost, so
treat them as fixed. They need:
- Actor bookkeeping: `f4B0` flags (bit 0 move, bit 1 act), `f4B4`, `h480`, `b4AD`/`b4AE`, `b4E5`, `s214`, `s410`, `b4BC/b4BD`,
  `s4C6/s4CA`, `b4C5`, `s4C8`, `f4D0/f4D8`, `b94A/b94C/b94D`, and the 0x2A0 script object.
- `v15()` once per turn, `v16(&f4B0)` once per monster step (at most one move and one act, or return 0 with flags unchanged),
  `v18` after an action, `func_800D8F98/FF8` for the wait, `func_800D94F4` at turn start, `func_800DA400` at creation.
- The grid and target primitives they `jal` directly (signature-stable): `func_800C5CC4`, `func_800CCDCC`, `func_800CCFC0`,
  `func_800CD488`, `func_800CD790`, `func_800CC110/CC298/CC3DC`, `func_800C02C8`, `func_800C8D9C`, `func_800CFC50`,
  `func_800CDA8C/94`, reached via `D_800AF470->f32C`.
- Globals: `D_800AF470`, `D_800AFA58[3]`, `D_800AFA64[3]`, `D_800B4DD0` (`+0x1FB`), `D_800B4D38`, `D_800B4C18`.
- **While EFFECT is in the slot, no BIM code is resident** (section 1.2/3): monsters are frozen (`s214`) and driven only by
  script ops. Their vtable pointers point into 0x800D5DAC..0x800DE1CC, so nothing may call monster virtuals during
  EFFECT. A ring that needs the monster alive must run before state 2 of `func_800CADDC`.

## 8. Battle UI

- **Layers.** (1) EXE tasks/scenes `S_Task` (`func_8001E40C`; `func_8001EFE4(target, event)` posts, `func_8001E848(cur, new)`
  pushes); events are `{vtbl D_800102D0, s8=2, sA=type, fC=source, f10=value}` from `func_8001CA10(0x14)`. (2) Widget framework
  (EXE: `func_800538CC` label, `func_80054AF0` window, `func_80054E18` add child, `func_80055020/54EB4` offset/size,
  `func_80054F30` slide, `func_80054FC0/FE0` show/hide, `func_80054094` enable, `func_80053BCC` text, manager `D_800B4D84`,
  `func_8005549C` push menu). (3) Prim objects (EXE base `func_8005F0E4` + BATTLE subclasses). (4) Layer/OT: `S_Lay`
  (vtbl `D_800117A4`, `func_8002E714`), each owning double-buffered ordering tables and a drawable list at `+0x64`.
- **Primitives seen** (code bytes): 0x74 SPRT_8 (damage digits, `func_800C4B70/4EC4`), 0x64 SPRT (bars, `func_800D43B0`),
  0x2C/0x2E POLY_FT4 (`func_800B7FFC`, 3D quad projected by asm `func_800B82C0/85B8`), **0x38 POLY_G4** (gradient quad +
  `DR_MODE`, semi-trans, `func_800BC704`, positions `func_800BCCEC`, colours `func_800BCDC0`, draw `func_800BC878`, depth up to
  0x1FFF). Floor cell highlights are world-space quads (`func_800BAFEC/BBAD4`, GTE asm `func_800BB354/B8F8`).
- **Ordering table.** Inline `add_prim(depth, prim)` (battle.h): layer pointer `D_800B4CFC` (top of the layer stack
  `D_800AC820`, set by `func_8002D94C`); `if (z && z < len) { prim->tag.addr = tbl[z]; tbl[z] = prim & 0xFFFFFF; }`; z = 0 is
  never drawn; smaller z is nearer. **Double buffering:** `D_800B4CF0` (0/1) flips per frame; objects keep `prims[2]`, `dm[2]` and
  write index `D_800B4CF0`, then copy changed words to `^1`.
- **Per-frame chain.** Engine task -> `func_8002F1DC/F464` -> `func_8002D94C(layer)`: inserts the layer's `DR_MODE`, sets
  `D_800B4CFC`, calls each drawable's **vtable slot 3** (`func_800BC878` for `D_800B71B4`, `func_800C48D8` for `D_800B7538`).
  Prim-object vtable: [1] dtor, [2] clone, [3] draw, [4..6] set position, [7+] type-specific. Draw returns primitive count;
  the owner's tick returns 1 (keep) or 0 (delete): see `func_800C41AC`, `func_800BC878`, `func_800B8474`. Attach/detach:
  `func_8002DA94(layerOwner, holder)` / `func_8002DC34(layer, obj, del)`; BATTLE's layer is `scene->f254` (`func_8006BF70/BF78`).
  Frame counter: `D_800A4534.fC`.
- **Menus.** Section 3 item 2. HP/MP gauge widgets `func_800D2D60` (class `func_800646FC`, `func_80064884(w, max, 0)`,
  `func_800648E8(w, cur)` animated), status strip `func_800D2778` (0xE0 x 0x12), floating per-actor bar `func_800D3ED0`
  (`operator new(0x64)`, anchored to joint 9 via `func_8003912C`/`func_8003A150`), banner `func_800C5020(new 0x78, str, 0x3C)`.
  Textures: `D_800AE640` texture-pack manager, id 0x40 = digit/bar page; `func_800600A4_i` CLUT, `func_80060154` tpage. Digits
  u = 0x80 + d*8, v = 8; colours `D_800B4CC0` (heal), `D_800B4C88` (damage), `D_800B4CB0`.
- **Best example to base a timing ring on: the damage-number popup.** Spawn `func_800BFB18(actor, value, kind)` ->
  `func_800C3FF4(new 0x60, 1, &pos, value, kind)` (ctor, asm 0x1B8, virtual-base class vtables `D_800B73D0/B7420/B7518`);
  attach `func_800C435C` (`func_8005C088`, `func_80019A6C`, `func_8002DA94`); sprite string `func_800C4510` (+ `func_800C4B70`);
  owner tick `func_800C41AC` (age from `D_800A4534.fC`, lifetime 0x3C frames, moves with vslot 11, `delete p` when done);
  draw `func_800C48D8` (asm 664 B, the only hand-written piece: `RotTransPers` of the anchor); destroy `func_800C46F0`. For a ring:
  copy spawn / attach / tick / destroy, replace the sprite string with a `T_BC704`-style POLY_G4 builder (C only:
  `func_800BC704` ctor, `func_800BCCEC` positions, `func_800BC878` draw with `prims[2]` indexed by `D_800B4CF0`), anchor in screen space
  (no GTE). Simplest existing C-only drawable to clone: `T_BC704` with `func_800B92E0` / `func_800B9530` (create two, push into
  the holder `x4E8`, `func_8002DA94(scene->f254, holder)`).
- **Free VRAM** at menu time: x 640-1023, y 256-511 (section 11.1). The OT length of the battle layer is unknown; a ring can avoid textures entirely.

## 9. Memory budget

| Range | Size | What |
|---|---|---|
| 0x80010000-0x800B4EE8 | 675,560 | EXE |
| 0x800B4EE8-0x800B6DF0 | 0x1F08 | EXE bss (zero slack) |
| 0x800B6DF0-0x800D5DAC | **0x1EFBC = 126,908** | BATTLE.BIN, resident the whole fight |
| 0x800D5DAC-0x800E584C | 0xFAA0 = 64,160 | slot: EFFECT.BIN **or** BIM block (0xA000 image + 0x5AA0 data) |
| 0x800E584C-0x800EA8A0 | **20,564** | unused pocket (neither EFFECT nor a slot load writes it) |
| 0x800EA8A0-0x80200000 | 0x115760 | heap (allocator `func_80018B88`, tiers in `func_8001B134`: big > 0xBFFF, mid best-fit from the high end, small < 0x400) |

- **BATTLE is exactly full**: 0 free bytes, no BSS (all battle state lives on the heap or in EXE objects). Text 122,236 bytes
  (502 functions: battle.cpp 0x9E48, battle_b 0xD920, battle_c 0x6614), rodata 0x120C, data 0x34.
- **What bounds the size** (all four must move together): (1) EFFECT and the 86 BIM modules are linked for 0x800D5DAC (EFFECT
  config, `D_800D5DAC` pin, 7 bim_base pins, `func_800515F4` special case); (2) EXE rodata `D_800137A8[2]` = 0x1EFBC (bytes
  read); (3) overlay table `D_800AE5F8` (LBA 1400, 0x1F000); (4) disc layout: BATTLE.BIN at LBA 1400 (62 sectors), EFFECT at
  1600, so **200 sectors are free** after it. `tools/functional_check.py` requires `len(built) <= len(retail)`.
  **38 BATTLE entry points are pinned by absolute address** (`config/pins.txt`; 36 from the EXE, one from EFFECT, `D_800D5D7C`).
- **Reclaimable inside BATTLE.** 98 of 502 functions have no reference anywhere (jal, vtable words, address pairs, scanned
  across EXE, BATTLE, EFFECT, bim_base, all 86 module images) = **6,296 bytes**: GTE-asm `func_800BB5EC` (616),
  `func_800BD5C4` (620), `func_800BDC28` (504); `func_800CE320` (404); `func_800BC440` (212); `func_800C5F84` (204);
  `func_800D168C` (204); `func_800D0230` (184); ... plus about 60 small getters. Debug strings "myActionWait" (about 0x60).
  34 functions are <= 8-byte stubs (272 B, empty vtable slots; removing needs vtable changes). Duplicated draw classes
  `T_BAD6C` / `T_BB860` (about 1 KB) could fold [M]. If the grid shape machinery were replaced (about 5 KB for the ten
  collectors + `func_800C9D6C`, 2.6 KB flood fill, 4 KB path sorter) it would break even in size; the monster AI calls into
  those, so they stay.
- **Room outside BATTLE.** Three options for ~20 KB of new code: (a) append a tail to BATTLE.BIN covering the pocket
  (0x800E5850-0x800EA89F) and patch `D_800137A8[2]`/`D_800AE5F8[4]` (reads about 0x10000 extra bytes per battle, harmless
  because BIM/EFFECT are loaded afterwards); (b) a separate file in the 200 free sectors loaded by a new request (the
  loader `func_800515F4` is table driven, idx 0-4 and 99); (c) move the slot base: re-link EFFECT and all 86 modules and
  regenerate 332 blocks (not recommended). A plain `jal` reaches the pocket from BATTLE. Anything called while a BIM
  image or EFFECT is resident must be in BATTLE, EXE or the pocket, never in the slot.
- **Heap users in battle** (measured from `operator new`): command menu 0x5760 (22,368), floating bars 0x64 x 3, banners 0x78,
  popups 0x60 + 0x3C, cell highlights 0xA4 x 2 + 0x18 + 0xBC, stream objects 0x1C8, EFFECT controller 0x188, monsters ~0xAF0
  each. Live: about 670 KB of the heap in use with one monster, stack near 0x801FB000 inside the heap (section 11.1).

## 10. Where Shadow Hearts' systems would plug in

Sanity Points are out of scope. The two systems below share one structural fact: **everything funnels through
`func_800C6194` (which actor, which menu) and `func_800CADDC` (what happens after a target is chosen).** Attack and
item/magic converge on `func_800CADDC`, and so does the monster AI.

### 10.1 Judgment Ring

**Goal:** an action resolves through a timing ring; the result scales or cancels the hit.

**Hook functions**
1. **Start: `func_800CADDC` (battle_b.cpp:1222), new state between 0 and 2.** Today state 0 sets BGM/camera, state 1 counts
   `f900` frames, state 2 loads the BIM block and state 3 EFFECT. Insert a ring state before state 2 that: creates the ring
   object, waits for it to finish, stores the result in the mgr, then falls into state 2. All three callers (`func_800CACD8`
   weapon, `func_800CAD5C` item/magic, and the monster path) arrive at `func_800CADDC(mgr, 0)`, so one hook covers every
   action. It runs while BATTLE and the EXE are resident and before the slot is overwritten, so the ring code in BATTLE is
   always available and monster virtuals are still valid.
2. **Input:** the ring needs the pad. Either (a) a new `f3D0` cursor state in `func_800CB174` (asm, rewritten in C in the
   functional build) fed by `func_8007908C`, which already forwards the pad to mgr; or (b) a widget with a `T_D19F0_q` handler
   like `func_800D2598` (`h18 & 0x2000`, buzz `func_8008EF40(0xE)`). (a) is simpler: the pad word is already there. Use
   `h18 & 0x2000` confirm, `D_800A4534.fC` as the clock.
3. **Drawing:** clone the damage-popup chain (section 8): `func_800BFB18` spawn, `func_800C435C` attach, `func_800C41AC` owner tick
   (returns 1/0), `func_800C46F0` destroy, with `func_800BC704`-style POLY_G4 segments in place of `func_800C4510`'s
   sprites; screen-space anchor (no `func_800C48D8` asm). Layer: `scene->f254`, depth below 0x1FFF.
4. **Applying the result.** Two levels:
   - *Hit / miss and strength scalar:* store `ringMul` (e.g. 0, 1.0, 1.5) in a free mgr field (mgr is 0x958 bytes, heap
     allocated by `func_8007A434`; the object size is a literal `0x958` there, so growing it is a one-constant EXE change). Apply
     in the **attack record before the hit**: scale `rec[8]`/`rec[0xA]` (HP/MP power, spells) and, for physical hits,
     `stat[6]` or the `dmg` accumulation in `func_800883A0`. Because that function is EXE asm, the least invasive point is a
     wrapper at its caller `func_80088F34` (u_80085168.cpp:1428, event 0x1003/0x1004): multiply `dmg` after the call by
     scaling the value that reaches `func_80086B70`.
   - *Single chokepoint:* `func_80086B70(stat, v)` (HP) and `func_80086CAC(stat, v)` (MP) see every change, including heals
     and monster attacks; scale there only when `mgr->ringActive` and the attacker side matches, using the sign of `v` to leave
     healing alone. This is the one place a patch cannot miss, at the cost of needing a "ring active" flag.
   - *Miss:* skip the `v03`/`v04` call or force `rolls = 0` (set `rec[0x11]` accuracy to 0, `func_80087284` clamp). The hit
     reaction (`v10..v14` -> message 0x2035) must still run so the animation finishes.
5. **Per-hit rings.** The physical formula loops over `A.u8[0x475]` hits with hit index `D.b76`; a ring per hit would hook inside
   the `func_800883A0` loop (EXE asm); otherwise average the ring result over the whole action.
6. **Defensive ring** (SH rings on incoming attacks): the same state fires for monster actions (side 2 attacker), and the
   target's side can be read from `mgr->f84C[]`/`f4D0`. Whether to ring on defence is a design choice; the hook allows it.

**What has to change**
- `func_800CADDC`: new state, extra fields in mgr (state timer, ring result): enlarge the `0x958` allocation in `func_8007A434`
  and add fields beyond `+0x95C`.
- `func_800CB174` / `func_8007908C`: route pad to the ring while it is up (and keep `f3D0` handling intact for the other states).
- `func_80086B70` / `func_80088F34` (EXE): damage scaling, or write the scale into the attack record upstream.
- New ring classes: ~1.5-3 KB of code. BATTLE has 0 free bytes; free the 6.3 KB of dead functions (section 9) or use the pocket.
  Both need the pin list re-checked (38 pinned entry points must not move).
- `EFFECT` needs nothing: it does not compute damage. The ring result should be applied before EFFECT runs so the camera and
  popups already show it.
- **Open (section 11, item 1):** the hit event for a *monster* defender is handled by BIM base code (`func_800D9970`), which is not
  resident while EFFECT is. The code reads as if the BIM image is back before the hit lands, but the reload point was not found; the ring should apply its scalar to the attack record or `func_80086B70` (both EXE) to be independent of this.

### 10.2 Shadow Hearts turn order and command flow

**Koudelka facts that constrain it**
- Turn order is the tick timeline `func_800C51D0` / `func_800C65C8` with waits `256 / speed`. This is already speed-ordered and
  maps well onto an SH-style speed order.
- A Koudelka turn is an optional **move** plus **one action**, in any order (`f4B0` bits 0 and 1). Monster AI (`v16`) assumes the
  same two-step shape and walks on the grid to targets (`func_800CCDCC/CCFC0`, `func_800C5CC4`).
- Positions, shapes and line of fire come from the 5 x 7 grid, and every animation position is a grid cell (op 0x1D).
- 86 monster modules are fixed code in disc images; they `jal` BATTLE and bim_base entry points by absolute address.

**Hooks and changes**
1. **Order.**
   - *Keep the timeline but make it round-based:* in `func_800C6194` change the reschedule argument (`f4B4 + h480`, the
     `cf_65C8(p, ...)` calls at battle_b.cpp:549-607) to a constant round length, and in `c6050_reset` (battle.h:838) keep the
     initial delay `h480 = 256 / speed` so the first round is speed-ordered. Every later turn re-inserts at `+K`, so the
     relative order repeats each round. The BIM hooks `func_800D8FF8` and `func_800D94F4` still run and can write `h480`
     freely because BATTLE ignores the result.
   - *True per-round sort:* replace `func_800C65C8` with "pop next of a sorted array rebuilt at round start" (rebuild from
     `D_800AFA64`/`D_800AFA58`, using `stat[2]`); the preview ring `func_800C55C4` already rebuilds from a list. This is more
     code in a full BATTLE.
   Either way `func_800C666C` (dead monsters) and `func_800C54D8` (remove on death) must stay in sync with the structure.
2. **Command menu.** SH's per-turn menu (attack / magic / item / defend / escape, no move) maps onto `func_800D0D1C`. Easiest
   change: leave the window classes and drop the Move command by starting players with `f4B0 = 2` (bit 0 clear): `func_800CBA80`
   already disables the Move window then (`m` bit 0). The labels sit in obfuscated rodata (`D_800B7A98..`, and the command
   window strings in battle_c); relabelling is a data edit. New SH-only commands need a new `f5754` case in `func_800D1B68` /
   `func_800D119C` and a new code in `func_800CBBB4`.
3. **Targeting without a grid.** SH lets the player choose any enemy; the Koudelka equivalent is shape/mode 7 (`func_800C9A4C`,
   every valid cell) or mode 1 with unbounded range. Change `func_800CBBB4`'s attack case (`0x0D3..0x0D5`) to force mode 7 (set
   `f4D8 = 7` before `func_800CA9D0`), and let `func_800CA1B4` cycle enemies. Then add an **auto-approach**: before
   `func_800CACD8`, walk the player to the nearest free cell next to the target using the existing pathing
   (`func_800CCFC0` + `func_800C5CC4`, as the monster AI does) and play ops 0x13/0x1D. Actions then always reach, as in SH.
4. **Command resolution** stays `func_800CACD8` / `func_800CAD5C` -> `func_800CADDC` (section 10.1 hook), unchanged.

**Honest conflicts**
- **Grid vs SH's free space.** SH has no cells. The patch cannot remove the grid: monster modules read and write `s4C6/s4CA`,
  call `func_800C5CC4`, `func_800CCDCC` and the occupancy table directly, and every position goes through op 0x1D. The workable
  design is a **hybrid**: keep the grid as the hidden layout, hide cursors/highlights for players, widen reach (mode 7), auto-walk.
  The distance penalty in the damage formula (about 2.2 per cell, `func_800883A0`) will still apply; SH has none, so zero it
  there (that edit is in EXE asm) or accept it.
- **Monster AI vs SH turn flow.** `v16` is called once per monster step and expects `f4B0` bit 0 (move) and bit 1 (act). Under
  round-based turns it still works if BATTLE leaves `f4B0 = 3` for monsters (they keep moving on the grid). SH monsters do not
  walk, so monsters will keep walking (visible difference). AI decisions (lowest-HP-fraction target, skill weights, `f9F0`) are
  independent of the ring and turn order. They *cannot* be re-driven by SH's AI without rewriting the modules.
- **Wait/speed.** Monsters write their own wait through `func_800D8FF8`/`func_800D8F98` (BIM code), players through
  `v03`/`v04`. Round-based ordering must overwrite `h480` after those calls; nothing in the modules reads it back (sections 2, 7.4).
- **Moves cost time in Koudelka** (`func_800D8F98` adds `b7D*256/speed` to `f4B4`): under a round model that cost vanishes;
  fine, but it changes balance.
- **EFFECT/BIM slot sharing** makes any pause between presentation and the next turn a reload: a round-based model that
  interleaves a new menu while EFFECT is loaded must wait for `0x2069` (EFFECT done) and the BIM reload before calling monster
  virtuals. Keep all new logic out of the slot.
- **Memory:** both systems together need roughly 3-6 KB of code plus data. Free the dead functions first; use the pocket if more
  is needed (section 9). The 38 pinned entry points constrain what can move: add code at the end rather than reordering.
- **Not verifiable here:** SH's exact flow (the sibling decompilation owns it) and runtime behaviour (section 11).

## 11. Unconfirmed at runtime and open questions

### 11.1 Live probe (DuckStation, first battle of disc 1: Koudelka alone vs one monster)

Read from RAM at Koudelka's first menu (frame 52582) and through one monster move. Save state: slot 10.
- **Residency at menu time (Q1, partly):** overlay id at 0x800B6DF0 is 5 (BATTLE). The slot at 0x800D5DAC holds a BIM image,
  not EFFECT: `bim_base` byte-identical, plus module **`w0_411c2c52ef`** (SECT.DAT id 20) at 0x800DA86C. The monster's vptrs
  (`+0` 0x800DAA00, `+0x49C` 0x800DA930) point into that module. Residency during an action was **not observed** (below).
- **Turn order (Q4):** confirmed `delay = h480 = 256 / AGL`, truncated: Koudelka AGL 13 -> 19, monster AGL 12 -> 21. Timeline
  at the first menu: clock `f12C` 19, nodes (19, Koudelka), (21, monster); preview ring entries `{team, due}` in that order;
  `fA0` = Koudelka. After her turn ended without an action she was re-inserted at +19 (her `h480`). The monster moved two
  cells (`s4CA` 1 -> 3) and its `h480` became 42 = 2 * 256 / 12 (`func_800D8F98`, move cost per cell), so it was re-inserted
  at 21 + 42 = 63. Koudelka came up again at clock 38. Ticks are **not** frames: `func_800C65C8` advances the clock in a
  tight loop to the next due actor, so a turn costs no frames; real time is spent only in the menus and animations.
- **Fighters:** party `D_800AFA64[0]` 0x801D0FB8 (`b4BC` 0, `b4BD` 1, grid (2,6), move range 3), monster `D_800AFA58[0]`
  0x801CB8A8 (`b4BC` 3, `b4BD` 2, grid (2,1), move range 2, HP 256 = 16^2, MP 6). Monster AI weights: `f990` 1000,
  `s994` = {1000, 0, ...} (one skill). Game state object `*D_800B4DD0` = 0x801D92CC, party size `+0x1FB` 1.
- **mgr** `scene+0x32C` = 0x80171E18 (scene 0x801F1590, mode 2); `f900` 0, `f904` -1 at the menu; menu holder `+0x908` 0x801965DC.
- **Stat names (Q8):** solved from the EXE, section 6.2.
- **Memory (Q6):** heap free list (`D_800B4EE8`) has 11 free blocks, 449,168 bytes in total. The largest, 0x6ABA0, starts at
  the heap base 0x800EA8A0, so about 670 KB of the 1.1 MB heap is in use with one monster. `$sp` was 0x801FB124, inside a
  heap allocation just below the small-block pool `D_800B4C04` (0x801FBFF8). The stack lives near the top of RAM, in the heap.
  VRAM: framebuffers at (0,0) and (320,0), 320x240 each. Entirely zero at menu time: **x 640-1023, y 256-511** (384x256,
  six 64-wide texture pages) and x 960-1023, y 96-239. EFFECT was not loaded at that moment, so effects may claim part of it.
- **Battle menu and pad (US disc):** root list Action / Move / Wait / Status; **Cross confirms, Triangle cancels, Circle
  opens the Escape window** from anywhere in the root menu (Cross on Escape tries to flee; a failure ends the turn and
  costs `h480`). Action's submenu: Attack / Magic / Items / Weapon, with Attack hidden until a target is in reach. The pad
  bit names in section 3 come from code reading and may have Circle and Cross swapped relative to what players press.
- **Action costs:** Koudelka's attack set `h480` to 59 = 3 * 256 / 13, and the monster's to 64 = 3 * 256 / 12, so a plain
  attack is worth 3 units of 256/AGL. A turn's `f4B4` adds the move cost and the action cost (monster: 21 + 64 = 85).
  Wait after an attack in the same turn re-inserted Koudelka at +59 (155 -> 214).
- **One monster action, frame by frame (Q1).** Frame numbers are DuckStation's; the battle runs at 60 fps:

  | Frame | `f904` (state) | slot 0x800D5DAC | Event |
  |---|---|---|---|
  | 98174 | -1 | BIM image (0x0A) | monster turn popped at clock 190, AI chose (`h480` 21 -> 64) |
  | 98232 | 1 | BIM | `f900` = 3, counts down one per frame |
  | 98264 | 3 | BIM | state 2 passed (`f938` = 1), EFFECT load requested |
  | 98309 | 3 | **EFFECT (0x09)** | 45 frames to load EFFECT.BIN |
  | 98325 | 4 | EFFECT | EFFECT controller `f914` = 0x801ADFC0 created |
  | 98383 | 5 | EFFECT | animation and hit (about 380 frames) |
  | 98763 | 5 | EFFECT | `f914` freed (`func_800CF408`, the post-action handler) |
  | 98807 | 5 | **BIM image** | 44 frames to read the BIM block back |
  | 98907 | 5 | BIM | Koudelka's turn popped at clock 214 |

  So **EFFECT is resident during the whole hit**, and the BIM image is back before the next turn. The read-back comes
  from `func_800CF408`: the same handler that clears `f914` ends with `func_8007DEE8(scene->f328, 0xB)` (a loader request on
  the scene's stream holder). Not confirmed with a breakpoint (breakpoints during CD streaming hang the emulator).
  **Koudelka's melee attack loaded no EFFECT at all:** the slot held the BIM image throughout, and the whole attack took
  under 130 frames. So a ring that runs before state 2 always runs with the BIM image resident, and monster-defender
  code in `bim_base` is callable during player melee.
- **Victory (Q2):** at the killing blow monster HP 0 and Koudelka's EXP (`+0x54C`) 0 -> 62 at once; `f7DC` (monsters left)
  1 -> 0 about 4 s later; then `f824` = **1**, the code `func_8007F8BC` sends to **`func_800C68D8`, so that is victory**
  (and by elimination `func_800C6DF4` defeat, `func_800C7158` flee, matching `f824` 2 and 3). The mgr was freed 0.5 s
  later, the scene mode `+0x364/+0x368` went 2 -> 1, and the overlay at 0x800B6DF0 changed id 5 -> 4 (FIELD.BIN). The
  results screen ("You got items!", drops, "You learned the spell ...") is drawn by FIELD, not BATTLE.
- **Character records (Q8, second half):** the party fighter at 0x801D0FB8 is the same object before and after the
  battle, and its base-stat bytes occur nowhere else in RAM. At runtime the persistent character is the fighter object
  itself; the 0x60-byte record (`func_8008AFE4`) is presumably only a save-file form.
- **Still open:** Q3 (menu code receivers), Q5 (encounter timer), Q7 (criticals: two hits of 79 and 85 and one of 14, no
  visible critical), the OT length, and a monster *spell* versus a monster melee attack (this monster's action loaded EFFECT,
  so it may have been a skill).

Tooling notes: `tools/duckstation.py` must use 127.0.0.1, not `localhost` (on Windows that cost 2 s per call; fixed).
`frame_step` loops hung the client; `press_button` with `duration_frames` while the game runs works, with one process
talking to the server at a time.

### 11.2 Open questions

Needed from the port or a DuckStation session later. 11.1 answers Q1 (residency and the read-back, by timing), the
victory half of Q2, Q4, Q8 and most of Q6; the original text is kept below for reference.
1. **Is the BIM image or EFFECT resident at each moment of an action, and where is BIM read back?** `func_800CADDC` states 2 and 3
   overwrite the slot; the monster-defender hit code (`func_800D9970`, `func_800D9CB0`, `func_800D96F8`) lives in the BIM base. The reload
   point was not found (candidates: `func_8007DEE8`, `func_800CF408`, `func_8007B5F8`). Late reads of 0x800DE1CC and 0x800D6B98 returned
   non-code data, inconsistent with a resident image. This governs ring timing, monster virtual calls and the pocket's usefulness.
2. Which of `func_800C68D8`, `func_800C6DF4`, `func_800C7158` is victory/defeat/flee (inferred from `f824` and callers); the
   EXP/money reward path; the code-to-mode table in `func_800792C8`.
3. The receiver of menu codes 0x106E, 0x10D3, 0x119A, 0x11FE, 0x10DC, 0x10E6/0x10E7, 0x10F0 (`func_80078C50`/`func_800CBBB4` handle it,
   but the mapping of codes 6, 7, 9, 10 to labels is inferred); the receiver of messages 0x2035/0x2036; who calls `v03`/`v04` at the hit frame.
4. ~~The turn order at battle start and the timing constants~~ (confirmed, 11.1). Still open: action costs (`v03`/`v04` record values).
5. The encounter timer constants (`+0x5CE`, 0x2F0..0x42B, item 0x87).
6. The battle layer's ordering-table length (depth 0x1FFF is used, so it exceeds that), free VRAM rows, contents of texture id 0x40, stack
   location, live heap use.
7. Whether critical hits exist (none found in the physical or spell resolvers; three other virtuals were not read).
8. ~~The eight stat names~~ (solved, section 6.2); which `D_800B4DD0` slots hold the per-character save records.
9. How skill weights (`f990`, `s994[]`) and the module tables are loaded (`func_800DA400`, `func_800DA5E0`, asm, not read).
10. Ghidra cross-references were not used (no instance running); the function list comes from source and asm only.
