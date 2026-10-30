# Shadow Hearts battle patch: design (phase 3)

Phase 3 of [SH_BATTLE_PATCH.md](SH_BATTLE_PATCH.md). It fits Shadow Hearts' Judgment Ring and turn flow into Koudelka's
BATTLE overlay as a disc patch. Inputs:
- the Shadow Hearts ring rules: `Shadow_Hearts_2001_Decomp/project/docs/battle-logic.md` section 1, from `CCircle` and
  `CBattle`, 21 methods linked from C on `lane-a`
- Koudelka's battle map: [BATTLE.md](BATTLE.md), with the live probe in section 11.1

SH's turn order (its `battle-logic.md` section 2, task T28) is not written yet, so section 4 leaves its rule as a parameter.

Short version:
- **Code.** The new code lives in a grown BATTLE.BIN, in the 20 KB pocket after the EFFECT/BIM slot. It enters the game
  through four entry-point detours, and every other byte of BATTLE stays as retail.
- **Damage.** The ring's result reaches damage through one small hook in the EXE's HP and MP choke points, placed in dead
  EXE code.
- **Ring.** The ring runs between target confirmation and the action, ticked once per frame by a hook in the EXE's
  buffer swap. The BIM image is resident then, and no CD load is in flight (2.1, revised in phase 4).

## 1. Where the code goes

### 1.1 Constraints, from the map and the probe
- BATTLE.BIN fills 0x800B6DF0..0x800D5DAC exactly. 38 of its entry points are reached by absolute address from the EXE,
  EFFECT and the 86 BIM modules (`config/pins.txt`), and the modules are prebuilt images on the disc. So **no existing
  BATTLE function may move**. Today's functional build relinks freely and only *checks* pins, so it cannot be used as is.
- The EXE cannot grow: its BSS ends at the overlay slot. EXE code is also reached by absolute address from every
  overlay and module, so **EXE edits must be in place and address-preserving**.
- FIELD.BIN is 0x33AB0 bytes and loads at 0x800B6DF0, so the overlay loader already handles an overlay that reaches
  0x800EA8A0. In battle, the slot loads (EFFECT, BIM blocks) only write 0x800D5DAC..0x800E584C.
- The EXE has dead code. An unreferenced-function scan found 925 EXE functions referenced by no `jal`/`j`, no pointer word
  and no `%hi/%lo` pair in any image (EXE, all overlays, EFFECT, `bim_base`, the 85 module images). Each one sampled is
  also unreferenced in source. The largest are `func_80040C10` (1,252 bytes), `func_80034184` (1,156) and
  `func_80032504` (1,052).

### 1.2 Layout of the patch build

| Range | What | How it gets there |
|---|---|---|
| 0x800B6DF0-0x800D5DAC | BATTLE as retail, except 2-instruction detours at 4 entry points | retail bytes + patch |
| 0x800D5DAC-0x800E584C | slot: zero padding in BATTLE.BIN, overwritten by the BIM block load at battle start | as today |
| 0x800E5850-0x800EA8A0 | **`.shpatch`**: ring, turn flow, detour targets, tables (20,560 B available). **Not safe: effect actions load data here (phase 4 step 2); moving to EXE dead code** | new, in BATTLE.BIN |
| 0x80040C10-0x800410F4 | **`.shexe`**: HP/MP hook copies + ring context (1,252 B, was dead `func_80040C10`) | EXE patch |

- **BATTLE.BIN grows** from 0x1EFBC to 0x33AB0 bytes (62 -> 104 sectors). It sits at LBA 1400 and EFFECT at 1600, so it
  fits without moving any other file. The two EXE words that size it change: the bytes-read constant `D_800137A8[2]` and
  the overlay table entry `D_800AE5F8[4]`. The extra read costs about 85 KB per battle start, which is under 0.3 s at
  2x speed.
- **Detours.** For each hooked function F, the patch build compiles a modified copy `F_sh` into `.shpatch` and writes
  `j F_sh; nop` over F's first 8 bytes. All callers, including EXE and BIM code that use F's pinned address, then reach
  the new code. The original body is left in place, unreached. Where the new code needs F's original behaviour (the
  `func_800CB174` shim), it uses a trampoline: F's two displaced instructions, then `j F+8`. A trampoline only works if
  those two instructions are position-independent (a prologue `addiu sp`/`sw ra`), and the build checks that.
- **Build.** A new `configure.py --mode shpatch` builds the matching images, then compiles `src/shpatch/*.cpp`:
  - `.shpatch` is linked at 0x800E5850 against the BATTLE and EXE symbols.
  - `.shexe` is linked at 0x80040C10 against the EXE symbols.
  - `tools/patch/apply.py` writes the sections and detours into copies of `SLUS_010.51` and `BATTLE.BIN`.

  The matching and functional builds are untouched.

## 2. Judgment Ring

### 2.1 Where it runs: at target confirmation (revised in phase 4)
The first version of this design put the ring in `func_800CADDC`'s frame-delay state, on the belief that every action
goes through that sequencer. **Phase 4 step 1 disproved that.** With a counting detour on `func_800CADDC`, neither
Koudelka's melee nor the monster's melee entered it: `f904` stayed -1 throughout. Only effect-driven actions do (the
monster skill in BATTLE.md 11.1). For melee, the damage is applied **the moment the target is confirmed**. The
monster's HP had changed 0.27 s after the press, before the swing animation. Then `f3D0` goes 4 (targeting) -> 5
(animation) -> 1 (next menu).

So the ring sits where SH puts it: **between target confirmation and the action**.
- **Input shim (`func_800CB174_sh`).** Targeting's confirm press arrives through `func_8007908C` -> `func_800CB174`. When
  `f3D0` is a targeting state (4 for Attack; magic and items TBD) and the press is confirm, the shim does not pass it on.
  It starts the ring, keeps the pad word, and swallows further presses except the ring's own.
- **Frame hook.** In battle the game logic is event driven: counting detours on 30 BATTLE entry points and scene methods
  found none that runs every frame while a menu waits. The EXE's buffer swap `func_8002D1E0` runs once per game frame
  (the game runs at 30 fps). Its `.shexe` copy calls `g_shFrameHook` when that is non-null. BATTLE sets it to
  `ring_tick` while a ring is up and clears it when the ring ends. The hook runs in the main loop after the swap,
  outside any list traversal.
- **Finish.** When the ring ends, `ring_tick` publishes the result to the ring context (2.5), clears the frame hook and
  replays the kept confirm press into `func_800CB174_orig`. The original then resolves the action exactly as it would
  have, with the scale in force.

Consequences:
- **Every player action type confirms through targeting,** so one hook covers attack, magic and items, whatever path
  each takes afterwards.
- **The ring runs before anything loads.** During it the BIM image is resident, no CD request is in flight, and the
  target cursor stays on screen.
- `func_800CADDC` needs no detour. The `func_800C6194` detour stays for clearing the context and for turn flow.

### 2.2 Rules, taken from SH (`CCircle`)

| Rule | SH source | Koudelka version |
|---|---|---|
| Zone word `{start:9, end:9, strike:6, param:7}` in degrees, up to 3 zones | `_NRing` | same encoding, tables in `.shpatch` |
| Needle starts at 0 (top), sweeps clockwise once in `period` = 1.6 s | `GetRouDegSpd`, `UpdateBarRot` | 96 vsyncs at 60 Hz. The angle is in 1/16 degree, advanced by `5760 * dv / period_vs`, with `dv` from `VSync(-1)`, so frame skips don't change the speed |
| Press n is judged against zone n. Outside it: miss, ring ends. In the last `strike` degrees: strike | `HitCheckQ` | same |
| Ring ends after the last zone's press, a miss, or at 360. Never pressed = one miss | `HitCheckQ`, `UpdateBarRot` | same |
| Magic: every sub-zone must be hit. Main-zone power = `40 + param` at its start, rising to 100 % at 5/6 of the way to the strike area. A strike = 120 % | `CheckResult(0)`, `MakeSprite` | same formula, integer math |
| Status / accessory changes to width and speed (`speedDiv` 0.5..2) | `GetRouDegSpd` | v1: none (constant period, unscaled widths). The hook is kept in `ring_setup()` for later |
| Accel and analog modes, roulette item | `SetAccelRot`, TrigMode 3 | not ported (no SH battle caller traced) |

Input: the ring reacts to the menu's confirm bit, pad 0x2000 in code (Cross on the US disc), received by the
`func_800CB174` shim (2.1). The press is judged in the shim and consumed. All other pads are swallowed while the ring is up.

### 2.3 Drawing
The ring is a drawable modelled on `T_BC704` (`func_800BC704` / `func_800BC878`). It is registered in a holder
(`func_80019A6C`) and attached to the battle layer with `func_8002DA94(scene->f254, holder)`, as `func_800B92E0` does
for the full-screen fade. Its draw method adds that frame's primitives with `add_prim(z, prim)` from the buffer that
`D_800B4CF0[0]` selects.
- **Depth.** The battle OT is reverse ordered, length 0x2000, read live: index 0x1FFF draws first and index 0 last. The
  scene uses 5202..5717 and the backdrop 8181..8191. The ring goes at z = 2..4, in front of the scene. Phase 4 checks it
  against the command windows.
- **Geometry** (320 x 240 screen, top right, clear of the command windows at the bottom left and the status bar at the
  bottom): centre (248, 64), track radii 26..36.
  - 72 POLY_F4 track segments of 5 degrees
  - zone bands drawn over the track in 2.5-degree steps: orange for the zone, red for the strike area
  - the needle: a thin POLY_F4 from the centre to r = 38
  - one small mark per press: white for a hit, red for a strike, grey for a miss
- **Budget.** At most about 130 POLY_F4 (20 B each) x 2 buffers, about 5.2 KB on the heap from `operator new`; with one
  monster there were 437 KB free in one block. No textures and no VRAM. Trig uses a 91-entry quarter-wave s16 sine table
  (182 B) in `.shpatch`.
- **Sequence** (cosmetic, from SH's `DoSequence`): 8-frame grow-in, the needle sweep, then 16 frames of ending: a green
  flash on success, a white crack on a perfect ring (all hits and all strikes), a plain fade on a miss.
- **Sound:** `func_8008EF40(id)`, the call the menus use. v1 reuses the menu cursor and confirm sounds for a hit or strike
  and the buzz `0xE` for a miss.

### 2.4 Ring data per action
Koudelka has no ring data, so `.shpatch` carries three tables of 12-byte `_NRing` triples:

| Action | Key | Default ring (degrees) | SH kind |
|---|---|---|---|
| Attack | weapon kind `f550->b1B` (12 kinds) | 3 zones: 50..100 (strike 94..100), 160..205 (strike 200..205), 265..305 (strike 301..305) | 0 |
| Magic | spell id (`f540`, the 0x8C-byte spell records) | 1 main zone 60..300, strike 290..300, `param` 0 | 2 |
| Item | none | 1 zone 45..315, no strike | 1 |

The defaults are placeholders with SH's shape. Phase 4 copies real widths from SH's `weapon_param + 0x10`,
`item_param + 0xC` and spell `+0x14` tables (retail addresses in `battle-logic.md` 1.1) and maps them onto Koudelka's
weapon kinds and spells by hand.

### 2.5 Applying the result

**Ring context** (`.shexe`, so EXE code can read it):
```c
struct ShRingCtx {
    int   active;        /* set when a ring finishes, cleared at the end of the action */
    int   scale;         /* Q8: 256 = 1.0 */
    void *caster;        /* attacker's stat block (fighter + 0x400) */
    void *targets[6];    /* stat blocks of mgr->f84C[0..f848) */
};
```

**Scale, from the ring result:**
- **Attack.** Hits h (0..3) with per-press strikes. SH plays h hits; the first does full damage, later ones half, and a
  strike adds x1.2. Koudelka resolves an attack as one formula run (`func_800883A0`), so the combo collapses to one
  factor, normalised so that three plain hits equal today's damage. That keeps Koudelka's balance; perfect strikes add 20 %.

  `scale = (sum over landed press i of w_i * (strike_i ? 1.2 : 1)) / 2`, with `w = (1, 0.5, 0.5)`

  | Result | Scale |
  |---|---|
  | 1 hit | 0.5 |
  | 2 hits | 0.75 |
  | 3 hits | 1.0 |
  | 3 strikes | 1.2 |
  | miss | 0 |

- **Magic.** `scale = power / 100`, so 0.4..1.0, or 1.2 on a strike. A missed sub-zone, or a miss in the main zone,
  gives 0.
- **Item.** Hit: 1.0. Miss: 0.

**Where it is applied: the EXE choke points.** Every HP change ends in `func_80086B70(stat, v)` and every MP change in
`func_80086CAC(stat, v)` (BATTLE.md section 4); both are C in `u_80085168.cpp`. Their scaled copies are compiled into
`.shexe` as `func_80086B70_sh` and `func_80086CAC_sh`, and detours replace the originals' first two instructions.
- **HP:** when `ctx.active` and `stat` is in `ctx.targets`, `v = v * scale >> 8`. A nonzero `v` with a nonzero scale
  stays at least 1 in magnitude. Heals are scaled too, as SH scales heals by power. Then the original body runs.
- **MP:** the same, but never for `stat == ctx.caster`, so the spell's own MP cost is unaffected.
- Outside battle, and in battle when no ring ran, `ctx.active` is 0 and the copies behave exactly like the originals. The
  hook therefore works the same in FIELD (item use from the menu) and costs nothing there.
- Counters and reflections hit the caster, who is not in `ctx.targets`, so they stay unscaled.

**Scale 0.** The attack plays and every hit deals 0. Two reasons not to do better in v1:
- SH's rule is that a failed ring loses the turn with no animation. That would mean cutting the action out of the
  sequencer between states 1 and 2 and faking the `func_800CF408` ending; that ending is asm and also drives the BIM
  read-back, so it isn't worth it.
- Forcing Koudelka's own miss (accuracy `rec[0x11] = 0`) would look native, but phase 4 must first confirm the attack
  record is not rebuilt in `v04` at the hit.

**Refunds on a failed ring,** as in SH:
- Magic: the MP cost is added back after the action, with `func_80086CAC(caster, +cost)` while `ctx.active` is 0.
- Item: the decrement is undone through the save object's item list (`func_80061188` / `func_800619F4`). Phase 4 must
  find where the decrement happens.

**Lifetime.** `ctx.active` is set when the ring finishes. It is cleared in the `func_800C6194_sh` detour at the point
where the per-turn driver clears `b4AD`/`b4AE` after the sequencer finishes. It is also cleared by any state-0 entry
without a ring, as a safety net for monster actions. So poison or upkeep at the next turn start (`v15` / `v01`) is never
scaled.

**Phase 4 must check:**
- Whether event 0x1001 (`v06`, "apply deferred per-hit values", `func_80088DEC`) feeds already-applied values back
  through `func_80086B70`, which would scale them twice.
- Whether the popup value (the HP queue at `stat+0x06`) matches the HP actually lost.

### 2.6 Monster actions
No ring. SH has none for enemy attacks, and the scope says "attacks, magic and items" for the player. The state-0 hook
leaves `ctx.active` at 0, so monster damage is unscaled. A defensive ring for incoming attacks could later reuse the same
state with the monster's targets.

## 3. Memory and size

| Piece | Estimate | Where |
|---|---|---|
| Ring logic (setup, update, press, result, scale) | 1.5 KB | `.shpatch` |
| Ring drawable (build prims, draw, sequence) | 1.2 KB | `.shpatch` |
| Tables: sine 182 B, rings 12 x 12 + spells + item, about 0.6 KB | 0.8 KB | `.shpatch` |
| `func_800CB174` shim (targeting confirm, ring input, replay) | 0.3 KB | `.shpatch` |
| `func_8002D1E0_sh` frame hook | 0.05 KB | `.shexe` |
| `func_800C6194_sh` (copy + context clear + turn flow, section 4) | 1.6 KB | `.shpatch` |
| Turn-flow extras (round order, menu, auto-approach) | 2-3 KB | `.shpatch` |
| **`.shpatch` total** | **about 9 KB of 20.5 KB** | |
| `func_80086B70_sh`, `func_80086CAC_sh`, ring context | about 0.7 KB of 1.25 KB | `.shexe` |
| Ring primitives | 5.2 KB | heap |

## 4. Turn order and command flow (waiting on SH T28)

The Koudelka side is ready; the SH rule is the missing input.

### 4.1 Order
Koudelka's timeline (`func_800C51D0` insert, `func_800C65C8` pop) is already speed ordered: the first turn is due at
`256 / AGL`, confirmed live. SH-style rounds fit it without touching the timeline code. In `func_800C6194_sh`, every
end-of-turn reschedule (`f4B4 + h480`, the `cf_65C8(p, ...)` calls, battle_b.cpp:549-607) becomes a constant round
length `ROUND`. With `ROUND` larger than any first-turn delay (> 256), each round repeats the speed order of the first.
- If T28 finds per-round re-sorting or random initiative, the round boundary is the turn of the last actor of the
  round. There, `func_800C6194_sh` re-inserts everyone with `256 / AGL (+ rand)` and then the round length. No new data
  structure is needed.
- Monsters still write `h480` through `func_800D8FF8` / `func_800D8F98` (BIM). BATTLE ignores the value under rounds,
  which the map confirms nothing reads back.
- `func_800C666C` (dead monsters) and `func_800C54D8` (remove on death) operate on the same timeline, so they stay in sync.

### 4.2 Command menu
SH's per-turn menu has Attack / Magic / Item / Defend / Escape and no Move:
- **Drop Move:** start player turns with `f4B0 = 2` (bit 0 clear). `func_800CBA80` already greys Move out then (mask
  bit 0), as the probe showed after a move.
- **Defend** = Koudelka's Wait, relabelled (data edit in the command window strings). Escape stays where it is (Circle /
  the Escape window).

### 4.3 Targeting and auto-approach (the grid hybrid)
- **Targets:** the attack case of `func_800CBBB4` (codes 0x0D3..0x0D5) forces shape mode 7 (`f4D8 = 7`, every valid
  cell) before `func_800CA9D0`, so every living monster is selectable.
- **Approach:** before `func_800CACD8` starts the action, `func_800CBBB4_sh` walks the player to the nearest free cell
  next to the target. It uses the monster AI's pathing (`func_800CCFC0` + `func_800C5CC4`, ops 0x13/0x1D), and the
  walk costs no turn. Melee then always reaches, as in SH. Guns and spells keep their own ranges.
- The grid stays as the hidden layout. Monster modules read and write it, so it cannot go. The 2.2-damage-per-cell
  distance penalty in `func_800883A0` mostly disappears with auto-approach.

### 4.4 Not changed
Monster AI (`v16`) keeps moving on the grid with `f4B0 = 3`: rewriting 86 modules is out of scope. Victory, defeat and
flee are unchanged: `f824` 1/2/3 -> `func_800C68D8` / `func_800C6DF4` / `func_800C7158`.

## 5. Phase 4 order of work
1. **Tooling (done).**
   - `tools/patch/build.py` is a standalone step after a matching build, not a configure mode. It compiles and links
     `.shexe` and `.shpatch` against the retail symbols and splat's extern files, then writes the detours and
     trampolines from `src/shpatch/detours.txt`.
   - Safety check: it refuses a detour whose displaced instructions branch or jump, or a function something branches into
     at +4. It refused `func_800CEC68`, `func_800806EC` and `func_800814E8`.
   - `@count n` detours count calls in `g_shCount[n]`, for finding which entry points run when.
   - `--inject` writes the patch into a paused DuckStation and first restores any detour from an earlier injection.
   - The no-op patch (copies of the five functions, with trace counters) was injected mid-battle. It ran through moves,
     attacks and monster turns with identical behaviour, and the counters confirmed each detour runs. DuckStation's
     recompiler picks up the writes.
   - Still to do: hash the pocket across a full fight.
2. **Ring (working for attacks, not yet shippable).** Built and tested by injection into a live battle (slot 10 state):
   - **Drawing.** The ring draws through the `func_8002E814` hook into the 3D battle OT, at depth 2. Three OTs are
     submitted per frame (the battle layer, 0x2000 entries, then two 5-entry tables), and `D_800B4CFC[0]` already
     points at the last of them by then, so the hook picks the battle layer by its length.
   - **Input and timing.** Targeting confirm arrives as an input event whose `h18` holds the new buttons: Up 0x10,
     Cross 0x2000. The needle swept 105 degrees in 28 frames, which is SH's 1.6 s.
   - **Results.** Three presses landed in the three zones gave scale 1.0 and a normal hit (113 -> 4 HP). One hit
     followed by a miss gave scale 0.5 and half damage (167 -> 113 HP).
   - **Replay.** The replayed confirm needs a copy of the input event, because the game reuses the original before the
     ring ends.
   - **Targets.** `mgr+0x848` holds a fighter pointer, not a target count, so the hooks now scale changes on the side
     opposite the caster instead of reading a target list.
   - **The pocket is not free.** During a monster turn, after its effect action, 0x800E5850.. held loaded data. The
     detours then jumped into it and the game hung.
   - **Relocated (done).** All patch code now lives in seven runs of dead EXE code (1,908 + 1,756 + 1,252 + 1,204 +
     1,132 + 904 + 828 = 8,984 bytes; 6.1 KB used). `build.py` packs object files into them largest first. The ring's
     primitives are on the heap, allocated by `ring_start` and freed by the turn driver. BATTLE.BIN keeps its retail
     size, and its only changes are two detours.
   - **Still to check:** that a monster's effect action no longer breaks anything with the relocated build.
   - **Texture (next).** The user suggested using Shadow Hearts' own ring art. Video memory right of x=640 below
     y=256 was empty in battle, so the patch can upload the SH ring texture there at ring start and draw textured
     quads in place of the flat ones.

3. **Scale:** `.shexe` hooks, the double-apply and popup checks (2.5), refunds.
4. **Ring tables** from SH data.
5. **Turn flow** (section 4), once T28 lands.
6. **Package:** the disc rebuild (BATTLE.BIN directory record size, EXE) and the xdelta against an unmodified disc 1.
   Downloading xdelta3 needs your approval.

## 6. Risks
- **Detour targets with delay-slot or `$gp` surprises.** All four are BATTLE C or asm functions with ordinary prologues.
  The writer refuses anything else.
- **An unreferenced EXE function that is reached by computed address.** No sign of this. Phase 4 runs a full battle and
  a field session with an execute breakpoint on `func_80040C10` before the region is reused; that is safe because no
  CD streaming happens there.
- **Pocket contents in battle** are stale FIELD data, meaning nothing loads there in battle. Phase 4 step 1 hashes it
  across a fight to confirm nothing writes there either.
- **Balance:** a normalised scale keeps Koudelka's damage curve. Without normalisation (SH's raw 2.0x for three hits),
  fights would get much shorter. The divisor is one constant.
- **Legal:** the patch carries rules and constants derived from Shadow Hearts. Distribution is your call.
