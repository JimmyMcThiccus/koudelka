# usage: agentA_drop.py func_X:idx ...   (idx = 0-based occurrence among that func's sections) to drop
import re, sys
p = 'scratch_c/agentA.cpp'
s = open(p).read()
parts = re.split(r'(?=^//@ )', s, flags=re.M)
drop = set(sys.argv[1:])
cnt = {}
out = []
for x in parts:
    m = re.match(r'//@ (func_\w+)', x)
    if m:
        n = m.group(1); i = cnt.get(n, 0); cnt[n] = i + 1
        if f'{n}:{i}' in drop: continue
    out.append(x)
open(p, 'w').write(''.join(out))
