import re, os, sys
# usage: dump.py MINSIZE MAXSIZE  -> prints compact instructions of functions in range with that size
d = 'asm/main/nonmatchings/game'
lo, hi = int(sys.argv[1]), int(sys.argv[2])
for f in sorted(os.listdir(d)):
    m = re.match(r'func_([0-9A-F]{8})\.s', f)
    if not m:
        continue
    a = int(m.group(1), 16)
    if not (0x800186B0 <= a < 0x80054A2C):
        continue
    t = open(os.path.join(d, f)).read()
    mm = re.search(r'nonmatching \S+, (0x[0-9A-F]+)', t)
    if not mm:
        continue
    size = int(mm.group(1), 16)
    if not (lo <= size <= hi):
        continue
    ins = []
    for line in t.splitlines():
        x = re.match(r'\s*/\* \S+ \S+ \S+ \*/\s+(.*)', line)
        if x:
            ins.append(re.sub(r'\s+', ' ', x.group(1)))
        elif line.strip().startswith('.L'):
            ins.append(line.strip())
    print(f"{a:08X}: " + ' | '.join(ins))
