import re, subprocess
from pathlib import Path
WT = Path(__file__).resolve().parent.parent
for it in range(10):
    r = subprocess.run([str(WT/".venv/Scripts/python.exe"), "tools/cc.py", "--psyq", "bin/psyq4.4", "--aspsx", "2.81", "--cflags", "-O2 -G8", "--as-G", "0", "--expand-div", "-Iinclude", "-o", "scratch_c/tmp/f.o", "src/field/field.cpp"], cwd=WT, capture_output=True, text=True)
    out = r.stdout + r.stderr
    hits = re.findall(r"field\.cpp:\d+: declaration of C function `[^`]*?(func_[0-9A-F]+)\(.*?\n.*?field\.h:(\d+): previous declaration", out)
    if not hits:
        print("\n".join(l for l in out.splitlines() if "warning" not in l and "In function" not in l)[:1500]); break
    src = (WT/"src/field/field.cpp").read_text()
    hl = (WT/"include/field/field.h").read_text().split("\n")
    for name, line in hits:
        m = re.search(r"^EXTERN_C ([^\n]*?\b" + name + r"\(([^)]*)\))\s*\{", src, re.M)
        sig = m.group(1)
        structs = set(re.findall(r"\b(Unk_\w+)\s*\*", sig))
        fwd = "".join("struct %s; " % s for s in sorted(structs))
        hl[int(line)-1] = fwd + "EXTERN_C " + sig + ";"
        print("fixed", name, "->", hl[int(line)-1])
    (WT/"include/field/field.h").write_text("\n".join(hl), newline="\n")
