"""Write the facts tools/ghidra_scripts/KoudelkaFixRefs.java needs to fix Ghidra's cross-space references.

Five overlays share 0x800B6DF0 and EFFECT loads right after BATTLE, so Ghidra resolves any address in that range
to its empty default RAM block unless told which overlay is meant. splat knows:

  label <space> <hex address>                         every function and data label of each overlay
  ptr <space> <hex address> <space> <hex target>      every data word that holds a pointer (`.word sym`),
                                                      with the space its target lives in

<space> is "ram" for the EXE, else the overlay block name (FIELD, BATTLE, ...). A pointer from the EXE into the
overlay range is written only when exactly one overlay defines that symbol; the others are counted as ambiguous.

  python tools/ghidra_pointer_list.py [out file, default build/ghidra_pointers.txt]
"""
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SPACES = {"main": "ram", "field": "FIELD", "battle": "BATTLE", "movie": "MOVIE", "capture": "CAPTURE",
          "gameend": "GAMEEND", "effect": "EFFECT",
          "bim_base": "BIMBASE"}
LABEL = re.compile(r"^\s*(?:glabel|dlabel|jlabel)\s+(\S+)\s*\n\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ", re.M)
WORD = re.compile(r"/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/\s+\.word\s+([A-Za-z_.$][\w.$]*)")
SLOT, EFFECT_BASE = 0x800B6DF0, 0x800D5DAC


def main():
    out = Path(sys.argv[1] if len(sys.argv) > 1 else ROOT / "build" / "ghidra_pointers.txt")
    labels = {}  # space -> {name: address}
    words = []   # (space, address, value, symbol)
    for target, space in SPACES.items():
        names = labels.setdefault(space, {})
        for s in (ROOT / "asm" / target).rglob("*.s"):
            text = s.read_text()
            for m in LABEL.finditer(text):
                names[m.group(1)] = int(m.group(2), 16)
            for m in WORD.finditer(text):
                value = struct.unpack("<I", bytes.fromhex(m.group(2)))[0]
                words.append((space, int(m.group(1), 16), value, m.group(3)))
    ranges = {"BATTLE": (SLOT, EFFECT_BASE), "EFFECT": (EFFECT_BASE, 0x800E584C), "BIMBASE": (EFFECT_BASE, 0x800DA86C)}

    def space_of(src, value, sym):
        if value < SLOT:
            return "ram"
        if src != "ram":
            if sym in labels[src] or src not in ranges or ranges[src][0] <= value < ranges[src][1]:
                return src
            if src == "BATTLE":  # EFFECT and the BIM.AR modules load in the same place after BATTLE
                return next((o for o in ("EFFECT", "BIMBASE") if sym in labels[o]), None)
            return "BATTLE" if sym in labels["BATTLE"] else None
        owners = [sp for sp, names in labels.items() if sp != "ram" and names.get(sym) == value]
        return owners[0] if len(owners) == 1 else None

    lines, ambiguous = [], 0
    for space, names in labels.items():
        if space != "ram":
            lines += [f"label {space} {a:08x}" for a in sorted(set(names.values()))]
    for src, addr, value, sym in words:
        if not 0x80000000 <= value < 0x80200000:
            continue
        dst = space_of(src, value, sym)
        if dst is None:
            ambiguous += 1
            continue
        lines.append(f"ptr {src} {addr:08x} {dst} {value:08x}")
    out.parent.mkdir(exist_ok=True)
    out.write_text("\n".join(lines) + "\n")
    n = sum(1 for l in lines if l.startswith("ptr"))
    print(f"{n} pointers, {len(lines) - n} labels -> {out}; {ambiguous} EXE pointers into the overlay slot left out "
          "(more than one overlay defines the symbol)")


if __name__ == "__main__":
    main()
