"""Find original-file boundaries inside EXE units from how small globals are reached.

ASPSX reached a small global through $gp only in the source file that defines it; every other file
used lui (tools/maspsx_extern.py). So inside one original file a symbol is reached one way only.
For each unit (a `cpp` segment of config/slus_010.51.yaml) this walks the functions in address order,
from the retail asm (nonmatchings/ and matchings/), and reports where one symbol is reached both
ways: the unit then holds more than one file, and a boundary lies in the interval printed.

  python tools/gp_boundaries.py [unit ...]
"""
import re
import sys
from pathlib import Path

import yaml

ROOT = Path(__file__).resolve().parent.parent
ASM = ROOT / "asm" / "main"
GP = re.compile(r"%gp_rel\(([A-Za-z_]\w*)")
HILO = re.compile(r"%(?:hi|lo)\(([A-Za-z_]\w*)")
VRAM = re.compile(r"/\* [0-9A-F]+ ([0-9A-F]{8}) ")


def units():
    cfg = yaml.safe_load(open(ROOT / "config" / "slus_010.51.yaml"))
    for seg in cfg["segments"]:
        if isinstance(seg, dict) and seg.get("subsegments"):
            for sub in seg["subsegments"]:
                if isinstance(sub, list) and len(sub) >= 3 and sub[1] in ("cpp", "c"):
                    yield sub[2]


def functions(unit):
    out = []
    for kind in ("nonmatchings", "matchings"):
        for f in (ASM / kind / unit).glob("*.s"):
            text = f.read_text()
            if ".section .rodata" in text.split("glabel", 1)[0]:
                continue  # INCLUDE_RODATA files
            m = VRAM.search(text)
            if m:
                out.append((int(m.group(1), 16), f.stem, set(GP.findall(text)), set(HILO.findall(text))))
    return sorted(out)


def main():
    want = set(sys.argv[1:])
    fns = {u: functions(u) for u in units()}
    small = set().union(*(g for fs in fns.values() for _, _, g, _ in fs))  # reached via $gp somewhere
    found = 0
    for unit, fs in fns.items():
        if want and unit not in want:
            continue
        last = {}  # sym -> (mode, index of last function that reached it that way)
        for i, (addr, name, gp, hl) in enumerate(fs):
            modes = {s: "gp" for s in gp} | {s: "lui" for s in hl & small if s not in gp}
            clash = [(s, last[s][1]) for s, m in modes.items() if s in last and last[s][0] != m]
            if clash:
                j = max(k for _, k in clash)
                found += 1
                syms = ", ".join(sorted({s for s, _ in clash}))
                print(f"{unit}: boundary after {fs[j][1]} and at or before {name} "
                      f"(0x{fs[j][0]:08X} < cut <= 0x{addr:08X}; {syms})")
                # a new file starts somewhere in (j, i]: forget what came before it
                last = {s: v for s, v in last.items() if v[1] > j}
            for s, m in modes.items():
                last[s] = (m, i)
    print(f"{found} boundaries found" if found else "no $gp/lui clashes")


if __name__ == "__main__":
    main()
