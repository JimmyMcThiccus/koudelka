import sys, subprocess, os, re
sys.path.insert(0, 'scratch_c'); import gen_tbl2
res = {}
for path in open('scratch_c/tbl_list.txt').read().split():
    mod = path.split('/')[2]
    name, body, n, base = gen_tbl2.gen(path)
    out = f'scratch_c/tbl/{mod}_{name}.cpp'
    os.makedirs('scratch_c/tbl', exist_ok=True)
    open(out, 'w').write('#include "common.h"\n#include "bim/shared.h"\n\n' + body)
    r = subprocess.run([sys.executable, 'tools/try_compile.py', out, name, '--unit', f'src/bim/{mod}/{mod}.cpp'],
                       capture_output=True, text=True)
    last = (r.stdout + r.stderr).strip().splitlines()[-1]
    print(mod, name, n, hex(base), last.split(':', 1)[-1].strip())
