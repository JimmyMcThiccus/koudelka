"""mk.py UNIT DRAFT OUT [--section func_X]: OUT = UNIT's leading #include/#define lines + DRAFT (minus its own #includes)."""
import sys, re
unit, draft, out = sys.argv[1:4]
u = open(unit).read().splitlines()
pre = []
for l in u:
    if l.startswith('#include') or l.startswith('#define') or not l.strip():
        pre.append(l)
    else:
        break
d = open(draft).read()
if '--section' in sys.argv:
    name = sys.argv[sys.argv.index('--section') + 1]
    parts = re.split(r'^(//@ \S+.*)$', d, flags=re.M)
    # keep prelude + matching section
    keep = parts[0]
    for i in range(1, len(parts), 2):
        if name in parts[i]:
            keep += parts[i + 1]
    d = keep
d = '\n'.join(l for l in d.splitlines() if not l.startswith('#include'))
open(out, 'w', newline='\n').write('\n'.join(pre) + '\n' + d + '\n')
