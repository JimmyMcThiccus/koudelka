"""Split a C/C++ source unit in two at a function start.

  python tools/split_unit.py <target> <segment> <address> <new_segment> [--ext c|cpp] [--dry-run]

For example `split_unit.py slus_010.51 main_b 0x8008B6A0 sound` moves every function of
src/main/main_b.cpp from 0x8008B6A0 on into src/main/sound.cpp, and updates
config/<target>.yaml:
- a new `[rom, cpp, sound]` code subsegment at that address
- if the tail owns any rodata, a matching `[rom, .rodata, sound]` subsegment

Rodata ownership comes from the INCLUDE_RODATA lines (by position in the source) and from
rodata that splat migrated into each function's .s file. The split is refused if the two sides'
rodata interleaves; that means the address is not a real file boundary.

The new file starts with "common.h" plus every #include the old file has. Declarations that the
moved code took from the old file's body have to be copied over by hand; the first build says
which. Run configure.py afterwards (it re-splits).
"""
import argparse
import glob
import re
import sys
from pathlib import Path

import yaml

ROOT = Path(__file__).resolve().parent.parent
ENTRY = re.compile(r'^INCLUDE_(ASM|RODATA)\("([^"]+)", (\w+)\);')
DEF = re.compile(r'^(?:EXTERN_C\s+|extern\s+"C"\s+|static\s+|inline\s+)*[\w\s\*&:<>,]*?\b(\w+)\s*\(')


def addr_of(name, named):
    m = re.search(r"_([0-9A-F]{8})$", name)
    return int(m.group(1), 16) if m else named.get(name)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("segment")
    ap.add_argument("address", type=lambda x: int(x, 0))
    ap.add_argument("new")
    ap.add_argument("--ext", choices=["c", "cpp"])
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()

    ypath = ROOT / "config" / f"{a.target}.yaml"
    ytext = ypath.read_text()
    cfg = yaml.safe_load(ytext)
    opt = cfg["options"]
    seg = [s for s in cfg["segments"] if isinstance(s, dict) and s.get("type") == "code"][0]
    vram, rom0 = seg["vram"], seg["start"]
    subs = seg["subsegments"]
    code = [s for s in subs if isinstance(s, list) and len(s) >= 3 and s[1] in ("c", "cpp") and s[2] == a.segment]
    if not code:
        sys.exit(f"no c/cpp subsegment named {a.segment} in {ypath}")
    ext = a.ext or code[0][1]
    named = {}
    for p in opt["symbol_addrs_path"]:
        for m in re.finditer(r"^(\w+)\s*=\s*0x([0-9A-Fa-f]+);", (ROOT / p).read_text(), re.M):
            named[m.group(1)] = int(m.group(2), 16)

    src = ROOT / opt["src_path"] / f"{a.segment}.{code[0][1]}"
    lines = src.read_text().split("\n")

    # Find the cut: just after the last line that belongs to an entry (INCLUDE_* or a function
    # definition's closing brace) whose function starts before the address.
    last_head_end, first_tail = -1, None
    i = 0
    while i < len(lines):
        line = lines[i]
        m = ENTRY.match(line)
        d = None
        if not m and not line.startswith((" ", "	", "#", "/", "}")) and not line.rstrip().endswith(";"):
            d = DEF.match(line)
        name = m.group(3) if m else (d.group(1) if d else None)
        end = i
        if d:
            # the definition runs until its braces balance
            depth, seen = 0, False
            for end in range(i, len(lines)):
                depth += lines[end].count("{") - lines[end].count("}")
                seen = seen or "{" in lines[end]
                if seen and depth <= 0:
                    break
        is_func = name is not None and (m is None or m.group(1) == "ASM")
        ad = addr_of(name, named) if is_func else None
        if ad is not None:
            if ad < a.address:
                last_head_end = end
            elif first_tail is None:
                first_tail = i
        i = end + 1
    if first_tail is None:
        sys.exit(f"no function at or after {a.address:#010x} in {src}")
    cut = last_head_end + 1
    head, tail = lines[:cut], lines[cut:]

    # Rodata ownership
    seg_dir = a.segment
    own_head, own_tail = set(), set()
    for d in ("nonmatchings", "matchings"):
        for f in glob.glob(str(ROOT / opt["asm_path"] / d / seg_dir / "*.s")):
            t = Path(f).read_text()
            m = re.search(r"glabel (\w+)\n\s*/\* [0-9A-F]+ ([0-9A-F]{8})", t)
            if not m:
                continue
            side = own_tail if int(m.group(2), 16) >= a.address else own_head
            for r in re.findall(r"dlabel \w+\n\s*/\* [0-9A-F]+ ([0-9A-F]{8})", t.split(".section .text")[0]):
                side.add(int(r, 16))
    for part, side in ((head, own_head), (tail, own_tail)):
        for line in part:
            m = ENTRY.match(line)
            if m and m.group(1) == "RODATA":
                ad = addr_of(m.group(3), named)
                if ad is not None:
                    side.add(ad)
    ro_line = None
    if own_tail:
        if own_head and max(own_head) > min(own_tail):
            bad = sorted(x for x in own_tail if x < max(own_head))[:5]
            sys.exit(f"rodata interleaves: the tail owns {[hex(x) for x in bad]} below the head's "
                     f"last {max(own_head):#010x}; {a.address:#010x} is not a file boundary")
        ro = min(own_tail)
        ro_line = f"      - [{ro - vram + rom0:#X}, .rodata, {a.new}]".replace("0X", "0x")
    code_line = f"      - [{a.address - vram + rom0:#X}, {ext}, {a.new}]".replace("0X", "0x")

    incs = []
    for line in head:
        if line.startswith("#include") and line not in incs:
            incs.append(line)
    if '#include "common.h"' not in incs:
        incs.insert(0, '#include "common.h"')
    old_dir = f'"{opt["asm_path"]}/nonmatchings/{seg_dir}"'
    new_dir = f'"{opt["asm_path"]}/nonmatchings/{a.new}"'
    tail_text = "\n".join(incs) + "\n\n" + "\n".join(tail).replace(old_dir, new_dir).lstrip("\n")
    new_src = src.with_name(f"{a.new}.{ext}")

    print(f"{src.name}: lines 1-{cut} stay; {len(tail)} lines move to {new_src.name}")
    print(f"  code:   {code_line.strip()}")
    print(f"  rodata: {ro_line.strip() if ro_line else '(the tail owns no rodata)'}")
    if a.dry_run:
        return

    # Insert the new subsegments into the yaml, keeping ROM order.
    ylines = ytext.split("\n")
    def rom_of(l):
        m = re.match(r"\s*- \[(0x[0-9A-Fa-f]+)", l)
        return int(m.group(1), 16) if m else None
    for new_line in filter(None, [ro_line, code_line]):
        r = rom_of(new_line)
        kind = ".rodata" if new_line is ro_line else None
        idx = None
        # The tail takes over the head's rodata start: the head then owns none, so replace its line.
        if kind:
            same = [j for j, l in enumerate(ylines) if rom_of(l) == r and ", .rodata, " in l]
            if same:
                ylines[same[0]] = new_line
                continue
        for j, l in enumerate(ylines):
            lr = rom_of(l)
            if lr is not None and lr > r and re.match(r"\s{6}- \[", l):
                idx = j
                break
        if idx is None:
            sys.exit("could not place the new subsegment in the yaml")
        while idx > 0 and ylines[idx - 1].strip().startswith("#"):
            idx -= 1
        ylines.insert(idx, new_line)
    ypath.write_text("\n".join(ylines))
    src.write_text("\n".join(head).rstrip("\n") + "\n")
    new_src.write_text(tail_text.rstrip("\n") + "\n")
    print(f"wrote {ypath.name}, {src.name}, {new_src.name}; now run configure.py")


if __name__ == "__main__":
    main()
