"""Report functions declared with more than one prototype across src/ and include/.

Sessions work around a wrong header prototype with an alias, `EXTERN_C int f_alt(int) asm("func_X");`, rather
than editing a header another area owns. This groups every declaration and definition by the symbol it names
(its asm label, else its own name) and lists the symbols whose prototypes disagree, sorted by how they
disagree: argument count, return type, or argument types only.

  python tools/alias_report.py [--all]   (--all also lists symbols whose aliases agree with each other)
"""
import re
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DECL = re.compile(r'^\s*(?:EXTERN_C|extern\s+"C(?:\+\+)?")\s+(?:const\s+)?([\w\s\*&:<>]+?)\s*\b(\w+)\s*\(([^;{)]*)\)\s*'
                  r'(?:(?:__asm__|asm)\s*\(\s*"(\w+)"\s*\))?\s*[;{]', re.M)


def norm_params(p):
    p = p.strip()
    if p in ("", "void"):
        return ()
    out = []
    for a in p.split(","):
        a = re.sub(r"\b[A-Za-z_]\w*\s*$", "", a.strip()) if re.search(r"[\w\*&]\s+\**\w+\s*$", a.strip()) else a
        out.append(re.sub(r"\s+", " ", a.replace(" *", "*").strip()))
    return tuple(out)


def main():
    sigs = defaultdict(set)
    where = defaultdict(set)
    for f in list((ROOT / "src").rglob("*.cpp")) + list((ROOT / "include").rglob("*.h")):
        for m in DECL.finditer(f.read_text(errors="replace")):
            ret, name, params, label = m.groups()
            sym = label or name
            if not re.match(r"func_[0-9A-F]{8}$", sym):
                continue
            sigs[sym].add((re.sub(r"\s+", " ", ret.strip()), norm_params(params)))
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
    print(f"{sum(map(len, kinds.values()))} functions declared with more than one prototype")


if __name__ == "__main__":
    main()
