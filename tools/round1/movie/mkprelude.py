import re
from pathlib import Path
t = Path("include/movie/movie.h").read_text()
t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
t = "\n".join(l for l in t.splitlines() if not l.startswith("#"))
t = t.replace("EXTERN_C", 'extern "C"')
Path("scratch_c/prelude.cpp").write_text(t + "\n")
