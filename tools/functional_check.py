"""Functional-build gate for Koudelka.

The build no longer has to match retail byte for byte; it has to behave the
same. This checks what can be checked statically:

  1. fit: every image fits the retail footprint. The EXE's BSS must end at or
     before the overlay slot (0x800B6DF0), and each overlay must be no larger
     than retail (so BATTLE still ends before EFFECT's load address).
  2. pins: addresses that other images reach by absolute address (the EXE
     calling into an overlay, EFFECT calling into BATTLE) must still hold a
     symbol (any name: renames are fine). config/pins.txt lists them.
  3. SHA-1: reported per image as "identical" or "differs". Information only.

Usage: python functional_check.py <nm.exe> <out_stamp>
"""
import hashlib
import subprocess
import sys

import yaml
from pathlib import Path

TARGETS = ["slus_010.51", "field", "battle", "movie", "capture", "gameend", "effect", "bim_base"]
TARGETS += sorted("bim/" + p.stem for p in Path("config/bim").glob("*.yaml"))  # BIM.AR monster modules
OVERLAY_SLOT = 0x800B6DF0


def symbols(nm, elf):
    res = subprocess.run([nm, elf], capture_output=True, text=True, check=True)
    out = {}
    for line in res.stdout.splitlines():
        parts = line.split()
        if len(parts) == 3:
            out[parts[2]] = int(parts[0], 16) & 0xFFFFFFFF  # nm sign-extends to 64 bits
    return out


def main():
    nm, stamp = sys.argv[1], sys.argv[2]
    fails = []
    syms = {}
    for t in TARGETS:
        cfg = yaml.safe_load(open(f"config/{t}.yaml"))
        opt = cfg["options"]
        elf = opt["elf_path"]
        syms[t] = symbols(nm, elf)
        built = open(elf.replace(".elf", ".bin"), "rb").read()
        retail = open(opt["target_path"], "rb").read()
        same = built.ljust(len(retail), b"\0") == retail
        sha = hashlib.sha1(built.ljust(len(retail), b"\0")).hexdigest()
        note = "identical" if same else "differs"
        if t == "slus_010.51":
            end = syms[t]["main_BSS_END"]
            fit = end <= OVERLAY_SLOT
            detail = f"BSS ends {end:#010x} (limit {OVERLAY_SLOT:#010x})"
        else:
            fit = len(built) <= len(retail)
            detail = f"{len(built):#x} bytes (limit {len(retail):#x})"
        print(f"{t:12s} fit {'OK' if fit else 'FAIL'}  {detail}  sha1 {sha[:12]} {note}")
        if not fit:
            fails.append(f"{t}: does not fit, {detail}")

    # Pins are checked by address, so renaming a pinned function is fine.
    for line in open("config/pins.txt"):
        line = line.split("#")[0].split()
        if not line:
            continue
        t, name, addr = line[0], line[1], int(line[2], 16)
        here = [s for s, a in syms[t].items() if a == addr and not s.endswith(("_START", "_END", "_SIZE"))]
        if not here:
            moved = syms[t].get(name)
            fails.append(f"pin {t}:{name} must stay at {addr:#010x}; no symbol there now"
                         + (f" ({name} is at {moved:#010x})" if moved is not None else ""))

    if fails:
        for f in fails:
            print("FAIL", f)
        print(f"functional check: FAIL ({len(fails)})")
        return 1
    print("functional check: OK")
    open(stamp, "w").write("ok")
    return 0


if __name__ == "__main__":
    sys.exit(main())
