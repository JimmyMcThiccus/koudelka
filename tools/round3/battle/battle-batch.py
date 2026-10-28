"""batch.py FILE [-v] [names]: FILE = shared prelude, then sections starting with '//@ func_XXXXXXXX [label]'.
Each section is compiled with the prelude and diffed against BATTLE retail. Runs sections in parallel."""
import re, subprocess, sys, tempfile, os
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
ROOT = Path(__file__).resolve().parent.parent
src = Path(sys.argv[1]).read_text()
verbose = "-v" in sys.argv
only = [a for a in sys.argv[2:] if a.startswith("func_")]
parts = re.split(r"^//@ (func_[0-9A-F]{8}[^\n]*)$", src, flags=re.M)
prelude = parts[0]
units = {}
def unit_of(name):
    if name in units: return units[name]
    for u in ("battle.cpp", "battle_b.cpp", "battle_c.cpp"):
        t = (ROOT / "src/battle" / u).read_text()
        if name + ")" in t or name + "(" in t:
            units[name] = "src/battle/" + u
            return units[name]
    units[name] = "src/battle/battle.cpp"
    return units[name]
def run(item):
    full, body = item
    name = full.split()[0]
    d = Path(tempfile.mkdtemp())
    raw = d / "raw.cpp"
    pre = prelude.replace('#include "battle/battle.h"', f'#define {name} {name}_hdr\n#include "battle/battle.h"\n#undef {name}')
    raw.write_text((pre + body).replace('#include "common.h"', '#define EXTERN_C extern "C"'))
    f = d / "f.cpp"
    cpp = subprocess.run([str(ROOT / "bin/psyq4.4/CPPPSX.EXE"), "-undef", "-D__GNUC__=2", "-D__OPTIMIZE__",
                          "-D_MIPSEL", "-D__mips", "-D__mips__", "-Dmips", "-D__psx", "-D__psx__", "-Dpsx",
                          "-lang-c++", "-D__cplusplus", "-D_LANGUAGE_C_PLUS_PLUS", f"-I{ROOT/'include'}",
                          str(raw), str(f)], capture_output=True, text=True, env={**os.environ, "TMPDIR": str(d)})
    if cpp.returncode:
        return full, False, "CPP ERROR " + cpp.stderr
    r = subprocess.run([sys.executable, str(ROOT / "tools/try_compile.py"), str(f), name, "--quiet",
                        "--unit", unit_of(name)], capture_output=True, text=True, cwd=ROOT)
    out = r.stdout + r.stderr
    last = [l for l in out.splitlines() if "differing" in l]
    msg = last[-1] if last else f"{name}: ERROR\n{out[-1500:]}"
    return full, bool(last and " 0 differing" in last[-1]), msg + ("\n" + out if verbose and not (last and " 0 differing" in last[-1]) else "")
items = [(parts[i].strip(), parts[i + 1]) for i in range(1, len(parts), 2)]
items = [it for it in items if not only or it[0] in only or it[0].split()[0] in only]
for u in set(it[0].split()[0] for it in items): unit_of(u)
ok = []
with ThreadPoolExecutor(4) as ex:
    for full, good, msg in ex.map(run, items):
        print(full, "->", msg)
        if good: ok.append(full)
print("OK:", " ".join(ok))
