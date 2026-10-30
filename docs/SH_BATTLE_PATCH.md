# Shadow Hearts battle system for Koudelka (disc patch)

Goal: replace Koudelka's battle logic with Shadow Hearts' (2001, Sacnoth's next game), shipped as an **xdelta
patch** against your own Koudelka disc 1 image, so it plays on hardware and in emulators. It is not part of the PC
port. Scope, as chosen:
- **the Judgment Ring:** attacks, magic and items resolve through the timing ring
- **Sanity Points:** SP drain per turn, berserk at 0
- **Shadow Hearts' turn order and command flow**, in place of Koudelka's grid initiative

Approach, as chosen: **decompile Shadow Hearts' battle code first**, then translate that C to the PS1 and
Koudelka's BATTLE overlay.

## Starting point

- **Shadow Hearts** (`C:/Users/jamie/Documents/Shadow_Hearts_2001_Decomp/project`; PS2, Metrowerks; 22% matched overall)
  names 271 battle-class functions (`CBattle`, the ring classes `CHugeRing`/`CLargeRing`, `CBtlEnd`, …). 48 are
  decompiled, and none of the ring's core logic (`Polling`, `Create`, `Draw`) is among them.
- **Koudelka's BATTLE overlay** is mostly decompiled, and the build has a functional mode that accepts changed
  code. But BATTLE must stay within 0x1EFBC bytes, because EFFECT and the BIM.AR monster modules load straight after
  it at 0x800D5DAC. Monster AI (86 BIM modules) acts through BATTLE's code.

## Phases

1. **Decompile Shadow Hearts' battle code** in the SH project, under its own process: the ring classes, the `CBattle`
   turn flow and command handling, and SP. Done means the logic is readable C, matched where the SH process requires.
2. **Map Koudelka's battle system** (in parallel with 1, in this repo). Map the turn order and initiative, action
   selection and resolution, damage, the grid and movement, how BIM modules hook in, the battle UI and its
   primitives, and the memory budget. Done means `docs/BATTLE.md` names each function that the replacement touches.
3. **Design the replacement,** fitting Shadow Hearts' rules into Koudelka:
   - how the ring is drawn with PS1 GPU primitives
   - where SP lives in character data
   - how SH turn flow coexists with the grid and the monster AI
   - what has to move to fit memory
4. **Implement** in the functional build behind a patch-build switch. The byte-identical build stays untouched, and
   the changed BATTLE (and EXE, if needed) is checked in DuckStation.
5. **Package:** rebuild the disc image with the changed files (`tools/patch/`), and produce the xdelta against an
   unmodified disc 1 image.

## Notes

- **Legal:** the patch will carry code derived from Shadow Hearts. Distributing it is the user's call.
- **Biggest risk: turn flow.** Shadow Hearts fights in free 3D space, while Koudelka's battles are grid-based with
  monster AI written for that. Expect phase 3 to propose a hybrid rather than a literal swap.
