# apply.py <batch file>: for each OK section (first OK variant per function), the part before a
# "//--" line goes to field.h after "/* round 2 */", the rest replaces the INCLUDE_ASM in field.cpp.
# The batch prelude also goes to the header.
import re, sys
from pathlib import Path
WT = Path(__file__).resolve().parent.parent
srcs = [WT / "src/field/field.cpp", WT / "src/field/field_b.cpp"]; hdr = WT / "include/field/field.h"
text = Path(sys.argv[1]).read_text()
prelude, *parts = re.split(r"^### (\S+)\s*$", text, flags=re.M)
ok = Path(sys.argv[1]).with_suffix(".ok").read_text().split()
codes = [s.read_text() for s in srcs]; h = hdr.read_text()
done = set(); n = 0
hadd = prelude.strip() + "\n" if prelude.strip() else ""
for name, body in zip(parts[0::2], parts[1::2]):
    fn = name.split("@")[0]
    if name not in ok or fn in done:
        continue
    idx = None
    for k, (seg, c) in enumerate(zip(["field", "field_b"], codes)):
        line = f'INCLUDE_ASM("asm/field/nonmatchings/{seg}", {fn});'
        if line in c:
            idx = k; break
    if idx is None:
        print("not found:", fn); continue
    code = codes[idx]
    if "\n//--" in body:
        decl, fbody = body.split("\n//--", 1)
    else:
        decl, fbody = "", body
    decl = decl.strip(); fbody = fbody.strip().replace('extern "C"', "EXTERN_C")
    syms = [l[7:].strip() for l in decl.splitlines() if l.startswith("//@sym ")]
    decl = "\n".join(l for l in decl.splitlines() if not l.startswith("//@sym ")).strip()
    if syms:
        sf = WT / "config/symbols/field.txt"
        sf.write_text(sf.read_text().rstrip("\n") + "\n" + "\n".join(syms) + "\n", newline="\n")
    if decl:
        hadd += decl + "\n"
    code = code.replace(line, fbody, 1)
    codes[idx] = code
    done.add(fn); n += 1
if hadd:
    h = h.replace("\n#endif /* FIELD_FIELD_H */", hadd + "\n#endif /* FIELD_FIELD_H */", 1)
hdr.write_text(h, newline="\n")
for s, c in zip(srcs, codes):
    s.write_text(c, newline="\n")
print("applied", n, " ".join(sorted(done)))
