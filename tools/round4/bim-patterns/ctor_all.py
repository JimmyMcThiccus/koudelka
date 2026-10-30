import sys, subprocess, os, json
sys.path.insert(0, 'scratch_c'); import gen_ctor2
os.makedirs('scratch_c/ctor', exist_ok=True)
res = {}
paths = open('scratch_c/ctors.txt').read().split()
if len(sys.argv) > 1: paths = [p for p in paths if any(a in p for a in sys.argv[1:])]
for path in paths:
    mod = path.split('/')[2]
    try:
        name, decl, cands = gen_ctor2.gen(path)
    except Exception as e:
        print(mod, 'SKIP', type(e).__name__, e); continue
    best = None
    for k, c in enumerate(cands):
        out = f'scratch_c/ctor/{mod}_{name}.cpp'
        open(out, 'w').write('#include "common.h"\n#include "bim/shared.h"\n' + decl + '\n' + c)
        r = subprocess.run([sys.executable, 'tools/try_compile.py', out, name, '--unit', f'src/bim/{mod}/{mod}.cpp'],
                           capture_output=True, text=True)
        last = (r.stdout + r.stderr).strip().splitlines()[-1]
        if ' 0 differing' in last:
            best = (k, 0); res[mod + '/' + name] = k; break
        if best is None: best = (k, last)
        if k >= 30: break
    print(mod, name, len(cands), best)
json.dump(res, open('scratch_c/ctor_ok.json', 'w'))
