import re, os, sys
d = 'asm/main/nonmatchings/game'
out = []
for f in os.listdir(d):
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
    calls = len(re.findall(r'\bjal\b', t))
    jalr = len(re.findall(r'\bjalr\b', t))
    out.append((size, a, calls, jalr))
out.sort()
lo = int(sys.argv[2]) if len(sys.argv) > 2 else 0
for s, a, c, j in out[lo:int(sys.argv[1])]:
    print(f"{a:08X} {s:4d} j{c}{'r' if j else ''}")
print(len(out))
