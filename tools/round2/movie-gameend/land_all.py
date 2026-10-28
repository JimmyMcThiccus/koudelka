"""Land helpers' finished functions: scratch_c/h*/done/func_X.cpp -> movie.cpp/movie.h/symbols.

Each file: header part, `//@func`, body. `//@sym` lines go to config/symbols/movie.txt.
Files with `//@note` lines are skipped (handled by hand). Verifies each with try_compile first.
Landed files move to scratch_c/hN/landed/. Prints what it did; the caller builds afterwards.
"""
import glob, os, re, shutil, subprocess, sys

UNIT, HDR, SYMS = 'src/movie/movie.cpp', 'include/movie/movie.h', 'config/symbols/movie.txt'
only = set(sys.argv[1:])

for path in sorted(glob.glob('scratch_c/h*/done/func_*.cpp') + glob.glob('scratch_c/j*/done/func_*.cpp') + glob.glob('scratch_c/k*/done/func_*.cpp')):
    func = os.path.basename(path)[:-4]
    if only and func not in only:
        continue
    text = open(path).read().replace(chr(13), '')
    if '//@unit gameend' in text:
        UNIT, HDR, SYMS = 'src/gameend/gameend.cpp', 'include/gameend/gameend.h', 'config/symbols/gameend.txt'
    else:
        UNIT, HDR, SYMS = 'src/movie/movie.cpp', 'include/movie/movie.h', 'config/symbols/movie.txt'
    for l in text.split(chr(10)):
        if l.startswith('//@note'):
            print('NOTE', func, l)
    src = open(UNIT).read()
    pat = re.compile(r'^INCLUDE_ASM\("[^"]+", %s\);$' % func, re.M)
    if len(pat.findall(src)) != 1:
        print('SKIP (no INCLUDE_ASM)', path)
        continue
    r = subprocess.run([sys.executable, 'tools/try_compile.py', path, func, '--unit', UNIT],
                       capture_output=True, text=True)
    m = re.search(r'(\d+) differing', r.stdout + r.stderr)
    if not m or m.group(1) != '0':
        print('SKIP (does not match now: %s)' % (m.group(0) if m else 'compile failed'), path)
        continue
    lines = [l for l in text.split('\n') if not l.startswith('#include')]
    i = lines.index('//@func')
    head, body = lines[:i], lines[i + 1:]
    syms = [l[len('//@sym'):].strip() for l in head if l.startswith('//@sym')]
    syms += ['%s = 0x%s; // force_not_migration:True' % (k, k[2:]) for k in (l[len('//@keep'):].strip() for l in head if l.startswith('//@keep'))]
    head = '\n'.join(l for l in head if not l.startswith('//@')).strip()
    body = '\n'.join(body).strip()
    open(UNIT, 'w').write(pat.sub(lambda _: body, src))
    if head:
        t = open(HDR).read()
        k = t.rindex('#endif')
        open(HDR, 'w').write(t[:k] + '/* %s */\n%s\n\n' % (func, head) + t[k:])
    _known = open(SYMS).read()
    syms = [x for x in syms if x.split(' =')[0] + ' = ' not in _known]
    if syms:
        with open(SYMS, 'a') as f:
            f.write('\n'.join(syms) + '\n')
    d = os.path.join(os.path.dirname(os.path.dirname(path)), 'landed')
    os.makedirs(d, exist_ok=True)
    shutil.move(path, os.path.join(d, os.path.basename(path)))
    print('LANDED', func, ('syms: ' + ', '.join(syms)) if syms else '')
