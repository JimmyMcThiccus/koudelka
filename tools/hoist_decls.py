"""Move the top-level declarations of a set of source units into one shared header.

After splitting a translation unit into per-file units, a declaration (an EXTERN_C
prototype, a struct, a typedef) written inline before its first user may now sit in a
different unit from later users. This hoists every top-level block that is not a function
definition, an #include or an INCLUDE_ASM/INCLUDE_RODATA line out of each unit, in unit
order, into one header, and includes that header from every unit. The relative order of
declarations is preserved, so anything that compiled before still compiles.

  python tools/hoist_decls.py <header> <unit.cpp> [<unit.cpp> ...]
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ENTRY = re.compile(r'^INCLUDE_(ASM|RODATA)\("[^"]+", \w+\);')
DEF = re.compile(r'^(?:EXTERN_C\s+|extern\s+"C"\s+|static\s+|inline\s+)*[\w\s\*&:<>,]*?\b\w+\s*\(')


def blocks(lines):
    """Split into blocks separated by blank lines. A block that has opened a brace runs on past
    blank lines until its braces balance, so a function body or struct stays whole."""
    out, cur, depth, opened = [], [], 0, False
    for line in lines:
        if line.strip() == "" and not (opened and depth > 0):
            if cur:
                out.append(cur)
            cur, depth, opened = [], 0, False
            continue
        cur.append(line)
        depth += line.count("{") - line.count("}")
        opened = opened or "{" in line
    if cur:
        out.append(cur)
    return out


def is_code(block):
    """True for blocks that stay in the unit: includes, INCLUDE_* lines, function definitions."""
    for line in block:
        if line.startswith("#include") or ENTRY.match(line):
            return True
    body = [l for l in block if not l.startswith(("//", "/*", " *"))]
    if not body:
        return False
    # A function definition: a DEF line that is not a prototype, with a body brace in the block.
    for line in body:
        if DEF.match(line) and not line.rstrip().endswith(";") and any("{" in l for l in block):
            return True
    return False


def main():
    header = ROOT / sys.argv[1]
    units = [ROOT / u for u in sys.argv[2:]]
    guard = re.sub(r"\W", "_", header.relative_to(ROOT / "include").as_posix()).upper()
    hoisted = []
    rel_header = header.relative_to(ROOT / "include").as_posix()
    for unit in units:
        lines = unit.read_text().split("\n")
        incs, code = [], []
        n = 0
        for b in blocks(lines):
            if all(l.startswith("#include") for l in b):
                for l in b:
                    if l not in incs:
                        incs.append(l)
            elif is_code(b):
                code.append(b)
            else:
                hoisted.append([f"/* from {unit.name} */"] + b)
                n += 1
        if f'#include "{rel_header}"' not in incs:
            incs.append(f'#include "{rel_header}"')
        text = "\n".join(incs) + "\n\n" + "\n\n".join("\n".join(b) for b in code) + "\n"
        unit.write_text(text)
        print(f"{unit.name}: {n} declaration blocks hoisted, {len(code)} code blocks kept")
    body = "\n\n".join("\n".join(b) for b in hoisted)
    header.parent.mkdir(parents=True, exist_ok=True)
    header.write_text(f"#ifndef {guard}\n#define {guard}\n\n/* Generated once by tools/hoist_decls.py from the units' inline "
                      f"declarations; edit freely. */\n\n{body}\n\n#endif /* {guard} */\n")
    print(f"{header.relative_to(ROOT)}: {len(hoisted)} blocks")


if __name__ == "__main__":
    main()
