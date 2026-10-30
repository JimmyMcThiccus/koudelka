import json, re, os, sys
ok = {}
for f in sys.argv[2:]: ok.update(json.load(open(f)))
hashes = sys.argv[1].split(',')
n = 0
for path, body in ok.items():
    path = path.replace(chr(92), '/'); mod = path.split('/')[2]; name = os.path.basename(path)[:-2]
    if not any(name.startswith(h) for h in hashes): continue
    f = f'src/bim/{mod}/{mod}.cpp'; t = open(f).read()
    b = body.strip('\n')
    if b in t:
        t = t.replace(b, f'INCLUDE_ASM("asm/bim/{mod}/nonmatchings/{mod}", {name});', 1); open(f, 'w').write(t); n += 1
print(n)
