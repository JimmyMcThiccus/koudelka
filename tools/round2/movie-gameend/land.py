import sys, re
# usage: land.py <func> <scratch.cpp> [unit.cpp] [header]
func, scr = sys.argv[1], sys.argv[2]
unit = sys.argv[3] if len(sys.argv) > 3 else 'src/movie/movie.cpp'
hdr = sys.argv[4] if len(sys.argv) > 4 else 'include/movie/movie.h'
lines = open(scr).read().split('\n')
lines = [l for l in lines if not l.startswith('#include')]
if '//@func' in lines:
    i = lines.index('//@func'); h, body = lines[:i], lines[i+1:]
else:
    h, body = [], lines
h = '\n'.join(h).strip(); body = '\n'.join(body).strip()
src = open(unit).read()
pat = re.compile(r'^INCLUDE_ASM\("[^"]+", %s\);$' % func, re.M)
assert len(pat.findall(src)) == 1, 'INCLUDE_ASM not found'
src = pat.sub(lambda m: body, src)
open(unit, 'w').write(src)
if h:
    t = open(hdr).read()
    k = t.rindex('#endif')
    t = t[:k] + h + '\n\n' + t[k:]
    open(hdr, 'w').write(t)
print('landed', func)
