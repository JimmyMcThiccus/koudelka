import re, sys
from pathlib import Path
# usage: dump.py func_X [...]  or dump.py MIN MAX -> compact asm of todo functions
todo = [l.split() for l in open('scratch_c/todo.txt') if len(l.split()) == 2]
args = sys.argv[1:]
if args and args[0].isdigit():
    lo, hi = int(args[0]), int(args[1]); sel = [p for s, p in todo if lo <= int(s) <= hi]
else:
    sel = [p for s, p in todo if p.split('/')[-1] in args] or [p for s,p in todo if any(a in p for a in args)]
import os
for p in sel:
    if not os.path.exists(p + '.s'): continue
    t = open(p + '.s').read()
    ins = []
    for line in t.splitlines():
        x = re.match(r'\s*/\* \S+ (\S+) \S+ \*/\s+(.*)', line)
        if x: ins.append(re.sub(r'\s+', ' ', x.group(2)))
        elif line.strip().startswith('.L'): ins.append(line.strip())
    print(p.split('/')[-2] + '/' + p.split('/')[-1] + ': ' + ' | '.join(ins))
