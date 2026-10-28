"""Move scratch_c/b/<ADDR>.cpp matches into src/movie/movie.cpp + include/movie/movie.h.
Local names A,B,R,T,H become Unk<ADDR>[suffix]. Lines defining func_<ADDR> go to the .cpp;
everything else (types, extern decls) goes to the header, deduplicated."""
import re, sys
from pathlib import Path
SRC = Path("src/movie/movie.cpp"); HDR = Path("include/movie/movie.h")
hdr = HDR.read_text() if HDR.exists() else ""
src = SRC.read_text()
END = "\n#endif /* MOVIE_H */\n"
body_h = hdr[:-len(END)] if hdr.endswith(END) else None
if body_h is None:
    body_h = ("#ifndef MOVIE_H\n#define MOVIE_H\n\n#include \"common.h\"\n\n"
              "typedef unsigned char u8;\ntypedef signed char s8;\ntypedef unsigned short u16;\n"
              "typedef short s16;\ntypedef unsigned int u32;\ntypedef int s32;\n")
have = set(body_h.splitlines())
import subprocess
for addr in sys.argv[1:]:
    out = subprocess.run(["sh", "scratch_c/run.sh", addr], capture_output=True, text=True).stdout
    if " 0 differing" not in out:
        sys.exit("not matching: " + out)
for addr in sys.argv[1:]:
    text = Path(f"scratch_c/b/{addr}.cpp").read_text().replace('extern "C"', "EXTERN_C")
    for loc in sorted(set(re.findall(r"^struct (\w+)", text, re.M)), key=len, reverse=True):
        if loc.startswith("Unk") or loc in ("RECT", "SPRT", "POLY_FT4", "Game", "Sys", "GameUnk8", "DIRENTRY"):
            continue
        text = re.sub(rf"\b{loc}\b", f"Unk{addr}" + ("" if loc == "A" else loc), text)
    fn, decl = [], []
    for line in text.splitlines():
        (fn if f"func_{addr}(" in line or (fn and not line.startswith(("struct", "EXTERN_C", "typedef")))
         else decl).append(line)
    new = [l for l in decl if l.strip() and l not in have]
    if new:
        body_h += "\n" + "\n".join(new) + "\n"; have.update(new)
    pat = f'INCLUDE_ASM("asm/movie/nonmatchings/movie", func_{addr});'
    assert pat in src, addr
    src = src.replace(pat, "\n".join(fn).rstrip())
    print("landed", addr)
if '#include "movie/movie.h"' not in src:
    src = src.replace('#include "common.h"\n', '#include "common.h"\n#include "movie/movie.h"\n', 1)
HDR.parent.mkdir(exist_ok=True); HDR.write_text(body_h + END); SRC.write_text(src)
