import sys, subprocess, re
# usage: var.py template func unit  -- template has @@ marker; variants separated by lines '----' in stdin
tpl = open(sys.argv[1]).read()
func = sys.argv[2]; unit = sys.argv[3] if len(sys.argv) > 3 else 'src/movie/movie.cpp'
vs = sys.stdin.read().split('\n----\n')
for i, v in enumerate(vs):
    import os
    tmpf = 'scratch_c/_v%d.cpp' % os.getpid()
    open(tmpf, 'w').write(tpl.replace('@@', v))
    r = subprocess.run([sys.executable, 'tools/try_compile.py', tmpf, func, '--unit', unit], capture_output=True, text=True)
    out = r.stdout + r.stderr
    m = re.search(r'(\d+) differing', out)
    print(i, m.group(0) if m else 'FAIL ' + ' | '.join(l for l in out.splitlines() if ':' in l and ('error' in l or re.search(r':\d+:', l)))[:300], '::', v.strip().replace('\n', ' ')[:150])
