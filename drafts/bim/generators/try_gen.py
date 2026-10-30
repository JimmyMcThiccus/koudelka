"""try_gen.py <genmodule> <listfile>: run gen(path) on each path, try candidates, record winners in scratch_c/ok_<gen>.json"""
import sys, subprocess, json, os, importlib
sys.path.insert(0, 'scratch_c')
g = importlib.import_module(sys.argv[1])
ok = {}
okf = f'scratch_c/ok_{sys.argv[1]}.json'
if os.path.exists(okf): ok = json.load(open(okf))
os.makedirs('scratch_c/try', exist_ok=True)
for path in open(sys.argv[2]).read().split():
    mod = path.split('/')[2]
    try:
        name, cands = g.gen(path)
    except Exception as e:
        print(mod, os.path.basename(path), 'SKIP', repr(e)[:150]); continue
    res = None
    best = (99999, -1)
    for k, c in enumerate(cands):
        out = f'scratch_c/try/{mod}_{name}.cpp'
        open(out, 'w').write('#include "common.h"\n#include "bim/shared.h"\n\n' + c + '\n')
        r = subprocess.run([sys.executable, 'tools/try_compile.py', out, name, '--unit', f'src/bim/{mod}/{mod}.cpp'], capture_output=True, text=True)
        o = (r.stdout + r.stderr).strip().splitlines()
        last = o[-1] if o else '?'
        if ' 0 differing' in last:
            ok[path] = c; res = 'OK %d' % k; break
        mm = __import__('re').search(r'(\d+) differing', last)
        d = int(mm.group(1)) if mm else 9999
        if res is None or d < best[0]:
            best = (d, k); res = last; open(f'scratch_c/try/{mod}_{name}.best.cpp', 'w').write(open(out).read())
    print(mod, name, res, 'cand', best[1], 'of', len(cands), flush=True)
json.dump(ok, open(okf, 'w'), indent=0)
