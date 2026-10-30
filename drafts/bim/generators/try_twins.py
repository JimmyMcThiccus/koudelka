import sys, subprocess, json, os, re
sys.path.insert(0, 'scratch_c'); import twin_adapt
ok = {}
okf = 'scratch_c/ok_twins.json'
if os.path.exists(okf): ok = json.load(open(okf))
minr = float(sys.argv[1]) if len(sys.argv) > 1 else 0.5
for l in open('scratch_c/twins.txt'):
    r, n, tgt, twin = l.split()
    if float(r) < minr or twin == 'None': continue
    tgt = tgt.replace(chr(92), '/'); twin = twin.replace(chr(92), '/')
    mod = tgt.split('/')[2]
    if tgt in ok: continue
    try:
        name, cands = twin_adapt.gen(tgt, twin)
    except Exception as e:
        print(r, mod, os.path.basename(tgt), 'SKIP', repr(e)[:100]); continue
    best = None
    for k, c in enumerate(cands):
        out = f'scratch_c/try/{mod}_{name}.tw.cpp'
        open(out, 'w').write('#include "common.h"\n#include "bim/shared.h"\n\n' + c + '\n')
        p = subprocess.run([sys.executable, 'tools/try_compile.py', out, name, '--unit', f'src/bim/{mod}/{mod}.cpp'], capture_output=True, text=True)
        o = (p.stdout + p.stderr).strip().splitlines(); last = o[-1] if o else '?'
        if ' 0 differing' in last: ok[tgt] = c; best = 'OK'; break
        if best is None: best = last
    print(r, mod, name, best, flush=True)
    json.dump(ok, open(okf, 'w'), indent=0)
