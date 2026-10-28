"""Replace string literals in movie.cpp with their retail rodata symbols (kept via force_not_migration)."""
import re, glob
U = 'src/movie/movie.cpp'
s = open(U).read()
STR = r'"((?:[^"\\]|\\.)*)"'
labels = {}
for f in glob.glob('asm/movie/*/movie/*.s'):
    t = open(f).read()
    for m in re.finditer(r'dlabel (D_[0-9A-F]+)\n\s*/\*[^*]*\*/ \.asciz ' + STR, t):
        labels.setdefault(m.group(2), []).append(m.group(1))
syms = []


def r(m):
    c = labels.get(m.group(1))
    if not c:
        print('NO LABEL for', m.group(1))
        return m.group(0)
    if len(c) > 1:
        print('AMBIGUOUS', m.group(1), c)
    syms.append(c[0])
    return c[0]


res = []
for l in s.split('\n'):
    if not (l.startswith('INCLUDE_') or l.startswith('#') or '/*' in l):
        l = re.sub(r"(?<![\w'])" + STR, r, l)
    res.append(l)
s = '\n'.join(res)
known = open('config/symbols/movie.txt').read()
for d in dict.fromkeys(syms):
    if 'EXTERN_C char %s[];' % d not in s:
        k = s.index(d)
        k = s.rindex('\nEXTERN_C', 0, k)
        s = s[:k] + '\nEXTERN_C char %s[];' % d + s[k:]
    if d + ' = ' not in known:
        open('config/symbols/movie.txt', 'a').write('%s = 0x%s; // force_not_migration:True\n' % (d, d[2:]))
open(U, 'w').write(s)
print('replaced', list(dict.fromkeys(syms)))
