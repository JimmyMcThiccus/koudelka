# add forward declarations for functions called before their definition in field.cpp
import re, subprocess, sys
from pathlib import Path
WT = Path(__file__).resolve().parent.parent
src = (WT / "src/field/field.cpp").read_text()
cp = WT / "scratch_c/tmp/fcopy.cpp"
cp.write_text(src + "\nint zzz = ;\n")
r = subprocess.run([str(WT / ".venv/Scripts/python.exe"), "tools/cc.py", "--psyq", "bin/psyq4.4", "--aspsx", "2.81", "--cflags", "-O2 -G8", "--as-G", "0", "--expand-div", "-Iinclude", "-o", "scratch_c/tmp/f.o", str(cp)], cwd=WT, capture_output=True, text=True)
names = sorted(set(re.findall(r"implicit declaration of function `[^`]*?(func_[0-9A-F]+|\w+)\(", r.stdout + r.stderr)))
h = (WT / "include/field/field.h").read_text()
add = []
for n in names:
    m = re.search(r"^EXTERN_C ([^\n]*?\b" + n + r"\([^)]*\))\s*\{", src, re.M)
    if m:
        d = "EXTERN_C " + m.group(1) + ";"
        if d not in h: add.append(d)
    else:
        print("no definition for", n)
if add:
    h = h.replace("\n#endif /* FIELD_FIELD_H */", "\n" + "\n".join(add) + "\n\n#endif /* FIELD_FIELD_H */")
    (WT / "include/field/field.h").write_text(h, newline="\n")
print("added:", *add, sep="\n")
