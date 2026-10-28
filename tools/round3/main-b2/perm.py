"""Brute-force statement order. usage: perm.py file.cpp func  (file section must contain lines marked  //P  to permute)"""
import itertools, re, subprocess, sys, tempfile, os
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
sys.path.insert(0, 'scratch_c')
from mb import unit_of, HDR
path = Path(sys.argv[1]); name = sys.argv[2]
parts = re.split(r'^//// (func_[0-9A-F]{8})[^\n]*\n', path.read_text(), flags=re.M)
body = dict(zip(parts[1::2], parts[2::2]))[name]
lines = body.split('\n')
idx = [i for i, l in enumerate(lines) if l.rstrip().endswith('//P')]
stmts = [lines[i] for i in idx]
u = unit_of(name)
def run(perm):
    ls = list(lines)
    for i, j in zip(idx, perm):
        ls[i] = stmts[j]
    fd, f = tempfile.mkstemp(suffix='.cpp', dir='scratch_c', prefix='_p_'); os.close(fd)
    Path(f).write_text(HDR + parts[0] + '\n'.join(ls))
    r = subprocess.run([sys.executable, 'tools/try_compile.py', f, name, '--unit', u.as_posix(), '--quiet'], capture_output=True, text=True)
    os.remove(f)
    last = (r.stdout.strip().splitlines() or ['err'])[-1]
    m = re.search(r'(\d+) differing', last)
    return (int(m.group(1)) if m else 999, perm)
perms = list(itertools.permutations(range(len(stmts))))
with ThreadPoolExecutor(6) as ex:
    res = sorted(ex.map(run, perms))
for d, p in res[:5]:
    print(d, p)
