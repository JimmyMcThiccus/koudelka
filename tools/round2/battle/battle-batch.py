"""batch.py FILE [-v]: FILE = shared prelude, then sections starting with '//@ func_XXXXXXXX'.
Each section is compiled with the prelude and diffed against BATTLE retail."""
import re, subprocess, sys, tempfile
from pathlib import Path
ROOT = Path(__file__).resolve().parent.parent
src = Path(sys.argv[1]).read_text()
verbose = "-v" in sys.argv
g0 = ["--as-G", "0"]
only = [a for a in sys.argv[2:] if a.startswith("func_")]
parts = re.split(r"^//@ (func_[0-9A-F]{8})\s*$", src, flags=re.M)
prelude = parts[0]
ok = []
def unit_of(name):
    for u in ("battle.cpp", "battle_b.cpp", "battle_c.cpp"):
        t = (ROOT / "src/battle" / u).read_text()
        if name + ")" in t or name + "(" in t:
            return "src/battle/" + u
    return "src/battle/battle.cpp"
for i in range(1, len(parts), 2):
    name, body = parts[i], parts[i + 1]
    if only and name not in only:
        continue
    d = Path(tempfile.mkdtemp())
    raw = d / "raw.cpp"
    raw.write_text((prelude + body).replace('#include "common.h"', '#define EXTERN_C extern "C"'))
    f = d / "f.cpp"
    cpp = subprocess.run([str(ROOT / "bin/psyq4.4/CPPPSX.EXE"), "-undef", "-D__GNUC__=2", "-D__OPTIMIZE__",
                          "-D_MIPSEL", "-D__mips", "-D__mips__", "-Dmips", "-D__psx", "-D__psx__", "-Dpsx",
                          "-lang-c++", "-D__cplusplus", "-D_LANGUAGE_C_PLUS_PLUS", f"-I{ROOT/'include'}",
                          str(raw), str(f)], capture_output=True, text=True, env={**__import__("os").environ, "TMPDIR": str(d)})
    if cpp.returncode:
        print(name, "CPP ERROR", cpp.stderr); continue
    r = subprocess.run([sys.executable, str(ROOT / "tools/try_compile.py"), str(f), name, "--quiet",
                        "--unit", unit_of(name)],
                       capture_output=True, text=True, cwd=ROOT)
    out = r.stdout + r.stderr
    last = [l for l in out.splitlines() if "differing" in l]
    print(last[-1] if last else f"{name}: ERROR\n{out[-1500:]}")
    if last and " 0 differing" in last[-1]:
        ok.append(name)
    elif verbose:
        print(out)
print("OK:", " ".join(ok))
