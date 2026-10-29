"""Report functions declared with more than one prototype across src/ and include/.

Sessions work around a wrong header prototype with an alias, `EXTERN_C int f_alt(int) asm("func_X");`, rather
than editing a header another area owns. This groups every declaration and definition by the symbol it names
(its asm label, else its own name) and lists the symbols whose prototypes disagree, sorted by how they
disagree: argument count, return type, or argument types only.

include/shared/exe.h writes pointers to area-specific types as void *, and the unit that defines a function
keeps its own types. So by default two prototypes agree when they differ only in what their pointers point
to; --strict compares pointer types too. The fixed-width typedefs (s32, u8, ...) count as the types they name.

  python tools/alias_report.py [--all] [--strict] [--exe]
    --all     also list symbols whose prototypes agree
    --strict  compare pointee types
    --exe     only EXE functions (below 0x800B5000)
"""
import re
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DECL = re.compile(r'^\s*(?:EXTERN_C|extern\s+"C(?:\+\+)?")\s+(?:const\s+)?([\w\s\*&:<>]+?)\s*\b(\w+)\s*\(([^;{)]*)\)\s*'
                  r'(?:return\s+\w+\s*)?(?:(?:__asm__|asm)\s*\(\s*"(\w+)"\s*\))?\s*[;{]', re.M)
FIXED = {"s8": "signed char", "u8": "unsigned char", "s16": "short", "u16": "unsigned short", "s32": "int",
         "u32": "unsigned int"}
STRICT = "--strict" in sys.argv


def strip_comments(t):
    t = re.sub(r"/\*.*?\*/", lambda m: re.sub(r"[^\n]", " ", m.group(0)), t, flags=re.S)
    return re.sub(r"//[^\n]*", "", t)


def norm_type(t):
    t = re.sub(r"\b(s8|u8|s16|u16|s32|u32)\b", lambda m: FIXED[m.group(1)], t)
    t = re.sub(r"\s+", " ", t.replace(" *", "*").strip())
    if not STRICT and "*" in t:
        t = ("const " if t.startswith("const ") else "") + "void" + "*"
    return t


def norm_params(p):
    p = p.strip()
    if p in ("", "void"):
        return ()
    out = []
    for a in p.split(","):
        a = re.sub(r"\b[A-Za-z_]\w*\s*$", "", a.strip()) if re.search(r"[\w\*&]\s+\**\w+\s*$", a.strip()) else a
        out.append(norm_type(a))
    return tuple(out)


def main():
    sigs = defaultdict(set)
    where = defaultdict(set)
    for f in list((ROOT / "src").rglob("*.cpp")) + list((ROOT / "include").rglob("*.h")):
        for m in DECL.finditer(strip_comments(f.read_text(errors="replace"))):
            ret, name, params, label = m.groups()
            sym = label or name
            if not re.match(r"func_[0-9A-F]{8}$", sym):
                continue
            if "--exe" in sys.argv and int(sym[5:], 16) >= 0x800B5000:
                continue
            sigs[sym].add((norm_type(ret), norm_params(params)))
            where[sym].add(f.relative_to(ROOT).as_posix())
    kinds = defaultdict(list)
    for sym, s in sorted(sigs.items()):
        if len(s) < 2 and "--all" not in sys.argv:
            continue
        arity = {len(p) for _, p in s}
        rets = {r for r, _ in s}
        kind = "argument count" if len(arity) > 1 else "return type" if len(rets) > 1 else "argument types"
        kinds[kind].append(sym)
    for kind in ("argument count", "return type", "argument types"):
        print(f"== {kind}: {len(kinds[kind])}")
        for sym in kinds[kind]:
            print(f"  {sym}: " + " | ".join(f"{r} ({', '.join(p)})" for r, p in sorted(sigs[sym]))
                  + f"   [{', '.join(sorted(where[sym]))}]")
    syms = [s for k in kinds.values() for s in k]
    exe = sum(1 for s in syms if int(s[5:], 16) < 0x800B5000)
    print(f"{len(syms)} functions declared with more than one prototype ({exe} EXE, {len(syms) - exe} overlay)")


if __name__ == "__main__":
    main()
