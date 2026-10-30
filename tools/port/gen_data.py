"""Generate the EXE's data for the PC port as i686 GNU assembly (docs/PORT_PHASE2.md section 4).

    .venv/Scripts/python.exe tools/port/gen_data.py [--out build/port/data/main_data.s]

Reads every dlabel block in asm/main/data/*.s (splat output) and lays the PS1 data out at its PS1 offsets:

  .rdata  0x80010000-0x800186B0  .ctors, game rodata, PsyQ rodata
  .data   0x800A4000-0x80200000  one contiguous block, "port RAM": .data and .sdata as in the EXE, .bss as
                                  zeros, then the overlay slot (ovl_header), EFFECT's area, the large-block
                                  area and the game heap, all zero (port_hiram = 0x800B6DF0)
  .data   recomp_scratchpad      0x1F800000-0x1F8003FF, 4 KB aligned

Each section starts at the page-aligned PS1 address below its first byte, so a host address and its PS1
address have the same low 12 bits. Every D_XXXXXXXX that the host code names (src/, include/, the recompiled
functions) and that falls inside one of these areas gets a global label at its offset, whether or not splat
made a block for it.

  .word sym [+ n]   -> .long "_sym" [+ n]   (C symbol decoration; undefined ones get stubs at link time)
  .word .L8001xxxx  -> .long 0              (jump tables of compiled code: clang and the recompiler make their own)
  .word 0x80xxxxxx  -> kept: an unmapped address in a 32-bit process, so a use faults and is logged
  .asciz            -> the bytes splat printed (padding included)
"""
import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

RODATA = (0x80010000, 0x800186B0)
RAM = (0x800A4000, 0x80200000)
HIRAM = 0x800B6DF0  # ovl_header: end of the EXE's .bss
SCRATCH = (0x1F800000, 0x1F800400)

ITEM_RE = re.compile(r"^\s*/\*\s*(?:[0-9A-F]+\s+)?([0-9A-F]{8})(?:\s+[0-9A-F]+)?\s*\*/\s+(\.\w+)\s*(.*?)\s*$")
RAW_RE = re.compile(r"^\s*/\*\s*([0-9A-F]+)\s*\*/\s*$")
DSYM_RE = re.compile(r"\bD_([0-9A-F]{8})\b")
SIZES = {".word": 4, ".short": 2, ".half": 2, ".byte": 1}


def parse(paths):
    """[(vaddr, size, kind, payload)], {name: vaddr} for every dlabel."""
    items, labels = [], {}
    for path in paths:
        pending = None
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            s = line.strip()
            if s.startswith("dlabel "):
                pending = s.split()[1]
                continue
            m = RAW_RE.match(line)
            if m and items and items[-1][2] == "str" and items[-1][3] is None:
                v, _, k, _ = items[-1]
                b = bytes.fromhex(m.group(1))
                items[-1] = (v, len(b), k, b)
                continue
            m = ITEM_RE.match(line)
            if not m:
                continue
            va, d, ops = int(m.group(1), 16), m.group(2), m.group(3)
            if pending:
                labels[pending] = va
                pending = None
            if d in SIZES:
                for op in [o.strip() for o in ops.split(",")]:
                    items.append((va, SIZES[d], "val", op))
                    va += SIZES[d]
            elif d == ".space":
                items.append((va, int(ops, 0), "zero", None))
            elif d in (".asciz", ".ascii"):
                items.append((va, 0, "str", None))
            else:
                sys.exit(f"gen_data: {path.name}: unknown directive {d}")
    for v, n, k, b in items:
        if k == "str" and b is None:
            sys.exit(f"gen_data: string at {v:08X} has no raw bytes")
    items.sort(key=lambda x: x[0])
    return items, labels


def sym(name):
    return f'"_{name}"'


def operand(op, stats):
    """A .word/.short/.byte operand as GNU as."""
    if re.fullmatch(r"-?(0x[0-9A-Fa-f]+|\d+)", op):
        return op
    if op.startswith(".L"):
        stats["jump_table_words"] += 1
        return "0"
    m = re.fullmatch(r"([A-Za-z_.$][\w.$]*)\s*(?:([+-])\s*(0x[0-9A-Fa-f]+|\d+))?", op)
    if not m:
        sys.exit(f"gen_data: cannot translate operand {op!r}")
    stats["symbol_words"] += 1
    return sym(m.group(1)) + (f" {m.group(2)} {m.group(3)}" if m.group(2) else "")


def referenced_dsyms():
    """Every D_XXXXXXXX address named by host code."""
    out = set()
    roots = [ROOT / "src" / "main", ROOT / "include", ROOT / "build" / "recomp" / "main", ROOT / "port"]
    for r in roots:
        for p in r.rglob("*"):
            if p.suffix in (".c", ".cpp", ".h"):
                out.update(int(x, 16) for x in DSYM_RE.findall(p.read_text(encoding="utf-8", errors="replace")))
    return out


def emit_area(out, name, lo, hi, items, labels, extra, stats, section):
    """Lay out [lo, hi) with labels at PS1 offsets. Items outside the area are skipped."""
    base = lo & ~0xFFF
    out += [f"    .section {section}", "    .p2align 12", f'    .globl "_{name}"', f'"_{name}":']
    marks = {}  # vaddr -> [label names]
    for n, v in labels.items():
        if lo <= v < hi:
            marks.setdefault(v, []).append(n)
    for v in extra:
        if lo <= v < hi:
            n = f"D_{v:08X}"
            if n not in labels:
                marks.setdefault(v, []).append(n)
                stats["extra_labels"] += 1
    pos = base
    area_items = [it for it in items if lo <= it[0] < hi]
    stops = sorted(set([it[0] for it in area_items] + list(marks)))
    by_addr = {}
    for it in area_items:
        by_addr.setdefault(it[0], []).append(it)
    for v in stops:
        if v < pos:
            if v in marks:  # a label inside an item already emitted (unaligned reference)
                for n in marks[v]:
                    out += [f"    .globl {sym(n)}", f"    {sym(n)} = . - {pos - v}"]
            continue
        if v > pos:
            out.append(f"    .space {v - pos}")
            pos = v
        for n in marks.get(v, []):
            out += [f"    .globl {sym(n)}", f"{sym(n)}:"]
        for va, size, kind, payload in by_addr.get(v, []):
            if va < pos:
                continue
            if kind == "val":
                d = {4: ".long", 2: ".short", 1: ".byte"}[size]
                out.append(f"    {d} {operand(payload, stats)}")
            elif kind == "zero":
                out.append(f"    .space {size}")
            else:
                out.append("    .byte " + ",".join(str(b) for b in payload))
            pos += size
            stats["items"] += 1
    if pos < hi:
        out.append(f"    .space {hi - pos}")
    out.append("")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", default=str(ROOT / "build" / "port" / "data" / "main_data.s"))
    a = ap.parse_args()
    paths = sorted((ROOT / "asm" / "main" / "data").glob("*.s"))
    items, labels = parse(paths)
    labels["ovl_header"] = HIRAM
    extra = referenced_dsyms()
    stats = {"items": 0, "symbol_words": 0, "jump_table_words": 0, "extra_labels": 0}
    out = ["# Generated by tools/port/gen_data.py from asm/main/data/*.s. Do not edit.", ""]
    emit_area(out, "port_rodata", *RODATA, items, labels, extra, stats, '.rdata,"dr"')
    emit_area(out, "port_ram", *RAM, items, labels, extra, stats, '.data,"dw"')
    out += ['    .globl "_port_hiram"', f'    "_port_hiram" = "_port_ram" + 0x{HIRAM - (RAM[0] & ~0xFFF):X}', ""]
    emit_area(out, "recomp_scratchpad", *SCRATCH, [], {}, extra, stats, '.data,"dw"')
    missing = sorted(v for v in extra if not any(lo <= v < hi for lo, hi in (RODATA, RAM, SCRATCH)))
    p = Path(a.out)
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text("\n".join(out) + "\n", encoding="utf-8", newline="\n")
    (p.parent / "outside.txt").write_text("".join(f"D_{v:08X}\n" for v in missing), encoding="utf-8")
    print(f"gen_data: {len(labels)} blocks, " + ", ".join(f"{k} {v}" for k, v in stats.items()) +
          f", {len(missing)} referenced D_ outside the data areas (outside.txt) -> {p}")


if __name__ == "__main__":
    main()
