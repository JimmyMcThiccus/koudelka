# Collect signatures of functions defined in my units (and other main units) into scratch_c/defs.h
import re
from pathlib import Path
out=[]
for u in [Path(f'src/main/{n}.cpp') for n in ['u_80032264','u_80033ECC','u_800372C0','u_8003852C','u_8003C510']]:
    t=u.read_text()
    for m in re.finditer(r'^EXTERN_C ([^\n;{]*\))\s*\n\{', t, flags=re.M):
        out.append('EXTERN_C '+m.group(1)+';')
Path('scratch_c/defs.h').write_text('\n'.join(out)+'\n')
print(len(out))
