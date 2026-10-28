"""Try many functions from one scratch file.

File layout: a preamble, then sections starting with `//== func_XXXXXXXX`.
Each section is compiled alone (preamble + section) via tools/try_compile.py.
`#include "x.h"` lines are inlined from include/ (common.h -> EXTERN_C only),
and EXTERN_C becomes extern "C", since CC1PLPSX doesn't preprocess.

  python scratch_c/batch.py scratch_c/f.cpp [func ...] [-v] [--land]

--land replaces each matching function's INCLUDE_ASM line in src/capture/capture.cpp
with the section text (preamble excluded).
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PY = str(ROOT / ".venv/Scripts/python.exe")
SRC = ROOT / "src/capture/capture.cpp"


def expand(text, seen=None):
    seen = seen or set()
    out = []
    for line in text.splitlines():
        m = re.match(r'\s*#include\s+"([^"]+)"', line)
        if m:
            if m.group(1) == "common.h" or m.group(1) in seen:
                continue
            seen.add(m.group(1))
            out.append(expand((ROOT / "include" / m.group(1)).read_text(), seen))
            continue
        if re.match(r"\s*#\s*(ifndef|define|endif|pragma)", line):
            continue
        out.append(line)
    text = "\n".join(out).replace("EXTERN_C", 'extern "C"')
    # no preprocessor, so comments must go too
    text = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), text, flags=re.S)
    return re.sub(r"//[^\n]*", "", text)


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("-")]
    verbose = "-v" in sys.argv
    land = "--land" in sys.argv
    path = Path(args[0])
    parts = re.split(r"^//== (func_[0-9A-F]{8}(?:#\w+)?)[^\n]*\n", path.read_text(), flags=re.M)
    pre, secs = parts[0], dict(zip(parts[1::2], parts[2::2]))
    want = args[1:] or list(secs)
    tmp = ROOT / "scratch_c" / "_one.cpp"
    matched = []
    for f in want:
        tmp.write_text(expand(pre + secs[f]) + "\n")
        r = subprocess.run([PY, str(ROOT / "tools/try_compile.py"), str(tmp), f.split("#")[0], "--quiet",
                            "--as-G", "0", "--asm-dir", "asm/capture", "--target", "extracted/disc1/BIN/CAPTURE.BIN"],
                           capture_output=True, text=True, cwd=ROOT)
        out = r.stdout + r.stderr
        last = out.strip().splitlines()[-1] if out.strip() else "?"
        ok = r.returncode == 0
        print(("OK  " if ok else "BAD ") + f + " " + (last.split(": ", 1)[-1] if "differing" in last else last))
        if verbose or (not ok and "differing" not in last):
            print(out if verbose else "\n".join(l for l in out.splitlines() if "_one.cpp:" in l))
        if ok:
            matched.append(f)
    if land:
        src = SRC.read_text()
        for f in matched:
            secs[f.split("#")[0]] = secs[f]
            f = f.split("#")[0]
            line = f'INCLUDE_ASM("asm/capture/nonmatchings/capture", {f});'
            if line not in src:
                print("not in capture.cpp:", f)
                continue
            src = src.replace(line, secs[f].strip())
        SRC.write_text(src)
        print("landed", len(matched))


if __name__ == "__main__":
    main()
