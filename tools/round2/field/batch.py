# usage: batch.py <file with "### func_X" sections> [-v] [func_X ...]
import re, subprocess, sys
from pathlib import Path
WT = Path(__file__).resolve().parent.parent
CPP = [str(WT / "bin/psyq4.4/CPPPSX.EXE"), "-undef", "-D__GNUC__=2", "-D__OPTIMIZE__", "-D_MIPSEL", "-D__mips",
       "-D__mips__", "-Dmips", "-D__psx", "-D__psx__", "-Dpsx", "-lang-c++", "-D__cplusplus",
       "-D_LANGUAGE_C_PLUS_PLUS", "-Iinclude"]
text = Path(sys.argv[1]).read_text()
prelude, *parts = re.split(r"^### (\S+)\s*$", text, flags=re.M)
only = [a for a in sys.argv[2:] if a.startswith("func_") or a.startswith("_")]
ok = []
def unit_of(fn):
    try:
        a = int(fn.split("_")[1][:8], 16)
    except Exception:
        return "src/field/field.cpp"
    return "src/field/field_b.cpp" if a >= 0x800DE3B8 else "src/field/field.cpp"
seen = {}
for name, body in zip(parts[0::2], parts[1::2]):
    if only and name not in only:
        continue
    fn = name.split("@")[0]
    s = WT / "scratch_c" / "tmp" / f"{name}.src.cpp"
    f = WT / "scratch_c" / "tmp" / f"{name}.cpp"
    s.parent.mkdir(exist_ok=True)
    s.write_text('#include "field/field.h"\n' + prelude + body)
    r = subprocess.run(CPP + [str(s), str(f)], cwd=WT, capture_output=True, text=True)
    if r.returncode:
        print("BAD cpp", name, r.stderr[-800:])
        continue
    f.write_text("\n".join(l for l in f.read_text().splitlines() if not l.startswith("# ") and not l.startswith("__asm__(\".include")))
    r = subprocess.run([str(WT / ".venv/Scripts/python.exe"), "tools/try_compile.py", str(f), fn, "--unit", unit_of(fn)]
                       + ([] if "-v" in sys.argv else ["--quiet"]),
                       cwd=WT, capture_output=True, text=True)
    last = (r.stdout.strip().splitlines() or [r.stderr.strip()[-600:]])[-1]
    good = re.search(r"bytes, 0 differing", last) is not None
    if good:
        ok.append(name)
    print(("OK  " if good else "BAD ") + name + ": " + last)
    if not good and "-v" in sys.argv:
        print("\n".join(l for l in r.stdout.splitlines() if re.match(r"^(!!| ) +[0-9a-f]{4}  ", l)) or r.stdout[-3000:], r.stderr[-2000:])
print("matched:", len(ok), " ".join(ok))
if not only:
    Path(sys.argv[1]).with_suffix(".ok").write_text("\n".join(ok))
