"""The overlays as the PC port sees them (docs/PORT_PHASE2.md, "Overlays").

All six overlays load at fixed PS1 addresses: five share the slot at ovl_header (0x800B6DF0), EFFECT sits at
0x800D5DAC. The EXE loads one with its table D_800AE5F8 (disc LBA, size) through the CD. On the host each
linked overlay is compiled in (its functions prefixed `<name>_`, because overlays share addresses) and has a
host image of its PS1 bytes with host pointers; port/overlays.cpp installs the image when the CD delivers the
file into the overlay area.
"""
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

# name: (PS1 load address, disc 1 LBA, file size, index in the EXE's table D_800AE5F8 or None)
OVERLAYS = {
    "movie": (0x800B6DF0, 801, 89272, 0),
    "field": (0x800B6DF0, 1200, 211632, 1),
    "battle": (0x800B6DF0, 1400, 126908, 2),
    "capture": (0x800B6DF0, 1000, 50220, 3),
    "gameend": (0x800B6DF0, 2000, 3248, 4),
    "effect": (0x800D5DAC, 1600, 64160, None),
}


def span(name):
    base, _, size, _ = OVERLAYS[name]
    return base, base + size


def functions(name):
    """{PS1 symbol: address} for every function defined in the overlay (from its PS1 ELF)."""
    from tools.recomp import hostcc
    nm = hostcc.LLVM_BIN / "llvm-nm.exe"
    elf = ROOT / "build" / f"{name}.elf"
    lo, hi = span(name)
    out = {}
    r = subprocess.run([str(nm), "--defined-only", str(elf)], capture_output=True, text=True, check=True)
    for line in r.stdout.splitlines():
        parts = line.split()
        if len(parts) == 3 and parts[1] in "Tt" and not parts[2].startswith(".") and \
                lo <= int(parts[0], 16) < hi and not parts[2].endswith(".NON_MATCHING"):
            out[parts[2]] = int(parts[0], 16)
    return out


def rename_map(name):
    """PS1 function name -> host name for the overlay's own functions. Data names stay: they are addresses in
    the shared overlay area (port_hiram), the same in every overlay; some sit in .text and look like functions."""
    return {f: f"{name}_{f}" for f in functions(name) if not f.startswith(("D_", "jtbl_"))}


TOKEN_RE = re.compile(r"\b[A-Za-z_]\w*\b")


def rename_text(text, mapping):
    return TOKEN_RE.sub(lambda m: mapping.get(m.group(0), m.group(0)), text)


def exe_functions():
    """{address: name} of the EXE's function entries (raw addresses in data become symbols)."""
    from tools.recomp import hostcc
    nm = hostcc.LLVM_BIN / "llvm-nm.exe"
    r = subprocess.run([str(nm), "--defined-only", str(ROOT / "build" / "slus_010.51.elf")], capture_output=True,
                       text=True, check=True)
    out = {}
    for line in r.stdout.splitlines():
        parts = line.split()
        if len(parts) == 3 and parts[1] in "Tt" and not parts[2].startswith(".") and \
                not parts[2].endswith(".NON_MATCHING") and not parts[2].startswith("__maspsx"):
            out.setdefault(int(parts[0], 16), parts[2])
    return out
