"""List the functions of a built image that differ from retail.

Walks the image's function symbols in address order and compares each one with
the retail bytes at its retail address. The retail address comes from the
func_XXXXXXXX name, or from the symbols files for renamed functions.
Immediates and jump targets are masked, since code after an earlier
difference may have moved. Opcodes and registers must agree, and so must
sizes. Differences in data (or only in immediates) need a raw byte diff.

Usage: python func_diff.py <target>     (e.g. battle, field, slus_010.51; run after a build)
"""
import re
import struct
import subprocess
import sys
from pathlib import Path

import yaml

ROOT = Path(__file__).resolve().parent.parent
NM = ROOT / "bin" / "binutils" / "mips-ps2-decompals-nm.exe"


def mask(w):
    op = w >> 26
    if op in (2, 3):
        return w & 0xFC000000          # j/jal target
    if op != 0 and op != 0x10 and op != 0x12:
        return w & 0xFFFF0000          # I-type immediate
    return w


def main():
    target = sys.argv[1]
    cfg = yaml.safe_load(open(ROOT / "config" / f"{target}.yaml"))
    opt = cfg["options"]
    seg = [s for s in cfg["segments"] if isinstance(s, dict) and s.get("type") == "code"][0]
    vram, rom0 = seg["vram"], seg["start"]
    retail = (ROOT / opt["target_path"]).read_bytes()
    built = (ROOT / opt["elf_path"].replace(".elf", ".bin")).read_bytes()

    named = {}
    for p in opt["symbol_addrs_path"]:
        for m in re.finditer(r"^(\w+)\s*=\s*0x([0-9A-Fa-f]+);", (ROOT / p).read_text(), re.M):
            named[m.group(1)] = int(m.group(2), 16)
    out = subprocess.run([str(NM), "-n", str(ROOT / opt["elf_path"])], capture_output=True, text=True).stdout
    starts = []
    for line in out.splitlines():
        parts = line.split()
        if (len(parts) == 3 and parts[1] in "Tt" and not parts[2].startswith("__maspsx")
                and not parts[2].endswith((".NON_MATCHING", "_START", "_END")) and "compiled" not in parts[2]):
            starts.append((int(parts[0], 16) & 0xFFFFFFFF, parts[2]))
    # GCC 2.8 emits no .size, so a function runs to the next function symbol.
    funcs = []
    for (addr, name), nxt in zip(starts, starts[1:]):
        if nxt[0] > addr:
            funcs.append((addr, nxt[0] - addr, name))
    bad = 0
    for addr, size, name in funcs:
        m = re.match(r"func_([0-9A-F]{8})$", name)
        raddr = int(m.group(1), 16) if m else named.get(name)
        if raddr is None:
            continue
        b = built[addr - vram + rom0: addr - vram + rom0 + size]
        r = retail[raddr - vram + rom0: raddr - vram + rom0 + size]
        if len(b) != len(r) or any(mask(x) != mask(y) for x, y in zip(
                struct.unpack(f"<{len(b)//4}I", b), struct.unpack(f"<{len(r)//4}I", r))):
            bad += 1
            print(f"{name}: differs (built {addr:#010x} size {size:#x}, retail {raddr:#010x})")
    print(f"{target}: {len(funcs)} functions checked, {bad} differ")


if __name__ == "__main__":
    main()
