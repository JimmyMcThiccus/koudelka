import re, sys
from pathlib import Path
def entries(text):
    lines = text.split("\n"); out = []; i = 0
    while i < len(lines):
        l = lines[i]
        m = re.match(r'^INCLUDE_ASM\("[^"]+", (\w+)\);', l)
        if m:
            out.append((m.group(1), i, i)); i += 1; continue
        m = re.match(r'^(?!INCLUDE|#|struct|typedef|inline|template|static)\S.*?\b((?:func_|C_)[0-9A-F]{8})\w*(?:::\w+)?\s*\(', l)
        if m and not l.rstrip().endswith(";"):
            # find end by brace counting
            depth = 0; j = i; started = False
            while j < len(lines):
                depth += lines[j].count("{") - lines[j].count("}")
                if "{" in lines[j]: started = True
                if started and depth == 0: break
                j += 1
            key = m.group(1).replace("C_", "func_")
            out.append((key, i, j)); i = j + 1; continue
        i += 1
    return lines, out
ours_lines, oe = entries(Path(sys.argv[1]).read_text())
ours = {k: "\n".join(ours_lines[a:b+1]) for k, a, b in oe}
for f in sys.argv[2:]:
    lines, te = entries(Path(f).read_text())
    n = 0
    for k, a, b in reversed(te):
        if k in ours:
            new = ours[k]
            if "\n".join(lines[a:b+1]) != new:
                lines[a:b+1] = new.split("\n"); n += 1
    Path(f).write_text("\n".join(lines), newline="\n")
    print(f, "replaced", n)
