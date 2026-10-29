"""Name PsyQ library functions in the EXE by matching them against the SDK's library objects.

Reads every .OBJ in the given directories (extract a .LIB's modules with `PSYLIB.EXE /x X.LIB` from
bin/psyq4.x; set MSYS_NO_PATHCONV=1 in Git Bash). The objects are Psy-Q LNK files; the format follows
PCSX-Redux's src/supportpsx/psyq-obj.cc. Each function's code (from its symbol to the next symbol in .text)
is matched against the EXE with every relocated field masked: the low 26 bits for REL26, the low 16 for
HI16/LO16/GPREL16, the whole word for REL32. Only exact, unique matches that start where splat starts a
function count.

  python tools/psyq_sigs.py <obj dir> [...] [--min-words 4] [--range 0x80094910 0x800A4514]

Prints one line per function in the range: name already right, newly named, conflicting, or unmatched.
With --write, it appends the new names to config/symbols/main.txt (as `name = 0x...; // type:func`).
"""
import argparse
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
EXE = ROOT / "extracted" / "disc1" / "SLUS_010.51"
MASKS = {74: 0xFC000000, 92: 0xFC000000, 82: 0xFFFF0000, 84: 0xFFFF0000, 96: 0xFFFF0000, 98: 0xFFFF0000,
         100: 0xFFFF0000, 30: 0xFFFF0000, 12: 0xFFFF0000, 16: 0x00000000, 8: 0x00000000}


class Reader:
    def __init__(self, data):
        self.d, self.p = data, 0

    def u8(self):
        self.p += 1
        return self.d[self.p - 1]

    def u16(self):
        self.p += 2
        return struct.unpack_from("<H", self.d, self.p - 2)[0]

    def u32(self):
        self.p += 4
        return struct.unpack_from("<I", self.d, self.p - 4)[0]

    def bytes(self, n):
        self.p += n
        return self.d[self.p - n:self.p]

    def string(self):
        return self.bytes(self.u8()).decode("latin-1")


def read_expr(r):
    """What a relocation expression points at: ("sym", symbol index), ("sec", section index, offset) for a
    place inside this object, or None for anything else. A constant added to either is folded in."""
    op = r.u8()
    if op == 0:
        return ("val", r.u32())
    if op == 2:
        return ("sym", r.u16())
    if op == 4:
        return ("sec", r.u16(), 0)
    if op in (12, 22):
        r.u16()
        return None
    if op in (44, 46, 50) or op >= 32:  # binary operators: two operands
        a, b = read_expr(r), read_expr(r)
        if op != 44:
            return None
        val = sum(x[1] for x in (a, b) if x and x[0] == "val")
        base = next((x for x in (a, b) if x and x[0] in ("sym", "sec")), None)
        return ("sec", base[1], base[2] + val) if base and base[0] == "sec" else base
    raise ValueError(f"expression opcode {op}")


def target_of(x, names, symnames):
    """A relocation's target: a symbol name, or (section name, offset) inside the object, or None."""
    if x and x[0] == "sym":
        return symnames.get(x[1])
    if x and x[0] == "sec":
        return (names.get(x[1], str(x[1])), x[2])
    return None


def parse_obj(data):
    """{section name: bytearray}, [(section, offset, mask, symbol name or None)], [(section, offset, name)]"""
    r = Reader(data)
    if r.bytes(3) != b"LNK":
        raise ValueError("not a Psy-Q object")
    r.u8()
    names, code, relocs, syms, symnames = {}, {}, [], [], {}
    chunk = {}  # section -> where its latest BYTES chunk starts; relocation offsets count from there
    cur = None
    while True:
        op = r.u8()
        if op == 0:
            break
        if op == 2:
            n = r.u16()
            chunk[cur] = len(code.setdefault(cur, bytearray()))
            code[cur].extend(r.bytes(n))
        elif op == 6:
            cur = r.u16()
        elif op == 8:
            code.setdefault(cur, bytearray()).extend(b"\0" * r.u32())
        elif op == 10:
            t = r.u8()
            off = r.u16()
            relocs.append((cur, chunk.get(cur, 0) + off, MASKS.get(t, 0), read_expr(r)))
        elif op == 12:
            idx = r.u16()
            sec = r.u16()
            off = r.u32()
            symnames[idx] = r.string()
            syms.append((sec, off, symnames[idx]))
        elif op == 14:
            idx = r.u16()
            symnames[idx] = r.string()
        elif op == 16:
            idx = r.u16()
            r.u16()
            r.u8()
            names[idx] = r.string()
        elif op == 18:
            sec = r.u16()
            off = r.u32()
            syms.append((sec, off, r.string()))
        elif op == 28:
            r.u16()
            r.string()
        elif op == 46:
            r.u8()
        elif op == 48:
            r.u16(), r.u16(), r.u32()
            r.string()
        elif op == 50:
            r.u16()
        elif op == 52:
            r.u16(), r.u8()
        elif op == 54:
            r.u16(), r.u16()
        elif op == 56:
            r.u16(), r.u32()
        elif op == 58:
            r.u16(), r.u32(), r.u16()
        elif op == 60:
            r.u16()
        elif op == 74:
            r.u16(), r.u32(), r.u16(), r.u32(), r.u16(), r.u32(), r.u16(), r.u32(), r.u32()
            r.string()
        elif op in (76, 78, 80):
            r.u16(), r.u32(), r.u32()
        elif op == 82:
            r.u16(), r.u32(), r.u16(), r.u16(), r.u32()
            r.string()
        elif op == 84:
            r.u16(), r.u32(), r.u16(), r.u16(), r.u32()
            for _ in range(r.u16()):
                r.u16()
            r.string()
            r.string()
        elif op == 86:
            r.u16(), r.u32(), r.u16(), r.u32(), r.u16(), r.u32(), r.u16(), r.u32(), r.u32(), r.u32(), r.u32()
            r.string()
        else:
            raise ValueError(f"opcode {op} at {r.p - 1:#x}")
    return {names.get(k, str(k)): v for k, v in code.items()}, \
        [(names.get(s, str(s)), o, m, target_of(x, names, symnames)) for s, o, m, x in relocs], \
        [(names.get(s, str(s)), o, n) for s, o, n in syms]


def signatures(obj):
    sections, relocs, syms = parse_obj(obj.read_bytes())
    text = sections.get(".text")
    if not text:
        return []
    starts = sorted({(o, n) for s, o, n in syms if s == ".text"})
    masks, calls = {}, {}
    for s, o, m, sym in relocs:
        if s == ".text":
            masks[o & ~3] = m
            if m == 0xFC000000 and sym:  # j/jal: to a named symbol, or (section, offset) inside this object
                calls[o & ~3] = sym
    out = []
    for i, (off, name) in enumerate(starts):
        end = next((o for o, _ in starts[i + 1:] if o > off), len(text))
        words = [struct.unpack_from("<I", text, p)[0] for p in range(off, end - 3, 4)]
        mask = [masks.get(p, 0xFFFFFFFF) for p in range(off, end - 3, 4)]
        call = {(p - off) // 4: calls[p] for p in range(off, end - 3, 4) if p in calls}
        out.append((name, words, mask, call, (str(obj), off)))
    return out


def splat_functions(lo, hi):
    """{address: name} of every function splat knows in [lo, hi), from the EXE's asm."""
    out = {}
    for s in (ROOT / "asm" / "main").rglob("*.s"):
        for m in re.finditer(r"glabel (\S+)\n\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ", s.read_text()):
            a = int(m.group(2), 16)
            if lo <= a < hi:
                out[a] = m.group(1)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("dirs", nargs="+")
    ap.add_argument("--min-words", type=int, default=4)
    ap.add_argument("--range", nargs=2, type=lambda x: int(x, 0), default=(0x80094910, 0x800A4514))
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--prefix", action="store_true",
                    help="report library functions that match the start of an unnamed EXE function that is longer "
                         "(splat or Ghidra may have merged two functions); never written")
    a = ap.parse_args()

    exe = EXE.read_bytes()
    base = 0x80010000 - 0x800
    words = [struct.unpack_from("<I", exe, p)[0] for p in range(0x800, len(exe) - 3, 4)]
    funcs = splat_functions(*a.range)

    sigs = []
    for d in a.dirs:
        for obj in sorted(Path(d).glob("*.OBJ")):
            try:
                sigs += signatures(obj)
            except (ValueError, IndexError, struct.error) as e:
                print(f"# skip {obj}: {e}", file=sys.stderr)
    # A match must cover the whole EXE function (up to the next one, give or take trailing nop padding),
    # not just its first words. Calls are checked by name: where the library calls a symbol and the EXE's
    # jal/j lands on a function splat has named, the names must agree; a func_ target is named by the match.
    starts = sorted(funcs) + [a.range[1]]
    length = {s: (e - s) // 4 for s, e in zip(starts, starts[1:])}
    name_at = splat_functions(0x80010000, 0x800B5000)
    found = {}  # address -> {name: {callee address: callee name}}
    placed = {}  # address -> {(object, offset)} of the matches there
    for name, w, m, call, src in sigs:
        while w and w[-1] == 0:  # the library object's own trailing padding
            w, m = w[:-1], m[:-1]
        if len(w) < a.min_words or name.startswith(("$", ".")):
            continue
        for addr in funcs:
            i = (addr - 0x80010000) // 4
            pad = length[addr] - len(w)
            if i + len(w) > len(words) or pad < 0:
                continue
            if any(words[i + len(w) + k] for k in range(pad)):
                if not (a.prefix and funcs[addr].startswith("func_")):
                    continue
            if not all((words[i + k] & m[k]) == (w[k] & m[k]) for k in range(len(w))):
                continue
            callees, ok = {}, True
            for k, sym in call.items():
                pc = addr + 4 * k
                target = (pc & 0xF0000000) | ((words[i + k] & 0x03FFFFFF) << 2)
                if isinstance(sym, tuple):  # a call inside the object: same distance as in the object
                    if sym[0] != ".text" or target != addr - src[1] + sym[1]:
                        ok = False
                        break
                    continue
                have = name_at.get(target)
                if have is None or (not have.startswith("func_") and have != sym):
                    ok = False
                    break
                if have.startswith("func_"):
                    callees[target] = sym
            if ok:
                found.setdefault(addr, {})[name] = callees
                placed.setdefault(addr, set()).add(src)

    new = {}  # address -> name
    stats = {"right": 0, "new": 0, "callee": 0, "layout": 0, "conflict": 0, "ambiguous": 0, "none": 0}

    def name_new(addr, name, how):
        if addr in new:
            if new[addr] != name:
                print(f"clash      {addr:08X}: {new[addr]} or {name}")
            return
        new[addr] = name
        stats[how] += 1
        print(f"{how:10} {addr:08X} {name_at.get(addr, funcs.get(addr))} -> {name}")

    for addr, cur in sorted(funcs.items()):
        names = found.get(addr, {})
        if not names:
            stats["none"] += 1
            continue
        if cur in names:
            stats["right"] += 1
        elif len(names) > 1:
            stats["ambiguous"] += 1
            print(f"ambiguous  {addr:08X} {cur}: {', '.join(sorted(names))}")
            continue
        elif cur.startswith("func_"):
            name_new(addr, next(iter(names)), "new")
        else:
            stats["conflict"] += 1
            print(f"conflict   {addr:08X} {cur} vs {next(iter(names))}")
            continue
        # A unique match also names the unnamed functions it calls.
        for target, callee in names[cur if cur in names else next(iter(names))].items():
            name_new(target, callee, "callee")
    # Module layout: the linker keeps each object's .text in one piece, so once one of its functions is placed
    # uniquely, its siblings sit at the same distances from it. Name the unnamed ones whose code also matches.
    by_obj = {}
    for name, w, m, call, (obj, off) in sigs:
        by_obj.setdefault(obj, []).append((off, name, w, m))
    for addr, cur in sorted(funcs.items()):
        names = found.get(addr, {})
        if len(names) != 1 or not (cur in names or new.get(addr) in names):
            continue
        for obj, off in placed[addr]:
            if any(n == next(iter(names)) for o, n, _, _ in by_obj[obj] if o == off):
                for o2, n2, w2, m2 in by_obj[obj]:
                    t2 = addr + (o2 - off)
                    if t2 == addr or not funcs.get(t2, "").startswith("func_") or t2 in new:
                        continue
                    i2 = (t2 - 0x80010000) // 4
                    while w2 and w2[-1] == 0:
                        w2, m2 = w2[:-1], m2[:-1]
                    if w2 and all((words[i2 + k] & m2[k]) == (w2[k] & m2[k]) for k in range(len(w2))):
                        name_new(t2, n2, "layout")
    stats.setdefault("layout", 0)
    print(f"# {len(funcs)} functions in range; " + ", ".join(f"{k} {v}" for k, v in stats.items()))
    if a.write and new:
        with open(ROOT / "config" / "symbols" / "main.txt", "a") as f:
            f.write("// Named by tools/psyq_sigs.py (exact masked match against the PsyQ SDK library objects)\n")
            for addr, name in sorted(new.items()):
                if not a.range[0] <= addr < a.range[1]:
                    # A library call landing in game code: the game supplies that function itself (its own
                    # memcpy, free, InitHeap). Reported above, not named: the game's C defines it.
                    continue
                f.write(f"{name} = 0x{addr:08X}; // type:func\n")


if __name__ == "__main__":
    main()
