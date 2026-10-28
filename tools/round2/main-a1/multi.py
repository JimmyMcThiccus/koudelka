"""Test several functions at once (all in ONE unit).
File: shared prelude, then sections `//// func_XXXXXXXX`. Each section is compiled with the
unit's includes (incl. its own header include/game/a/h_<unit>.h if present) + prelude and
diffed with try_compile.
usage: multi.py file.cpp [-v] [names...]"""
import re, subprocess, sys, time
from pathlib import Path

def unit_of(name):
    for _ in range(90):  # asm/ is regenerated while the parent session re-splits
        for d in ('nonmatchings', 'matchings'):
            for s in Path('asm/main/' + d).glob('*/' + name + '.s'):
                return s.parent.name
        time.sleep(2)
    sys.exit('no unit for ' + name)

def unit_includes(unit):
    src = Path('src/main/%s.cpp' % unit).read_text()
    inc = ''.join(l + '\n' for l in src.splitlines() if l.startswith('#include'))
    h = 'game/a/h_%s.h' % unit
    if Path('include/' + h).exists() and h not in inc:
        inc += '#include "%s"\n' % h
    return inc

if __name__ == '__main__':
    path = Path(sys.argv[1])
    verbose = '-v' in sys.argv
    only = [a for a in sys.argv[2:] if a != '-v']
    parts = re.split(r'^//// ([A-Za-z0-9_]+)[^\n]*\n', path.read_text(), flags=re.M)
    ok = []
    for name, body in zip(parts[1::2], parts[2::2]):
        if only and name not in only:
            continue
        unit = unit_of(name)
        f = Path('scratch_c/_m_' + path.parent.name + '_' + path.stem + '_' + name + '.cpp')
        f.write_text(unit_includes(unit) + parts[0] + body)
        r = subprocess.run([sys.executable, 'tools/try_compile.py', str(f), name, '--unit', 'src/main/%s.cpp' % unit],
                           capture_output=True, text=True)
        last = (r.stdout.strip().splitlines() or ['compile error'])[-1]
        good = ' 0 differing' in last
        ok += [name] if good else []
        print(('OK  ' if good else 'BAD ') + last)
        if not good and verbose:
            print(r.stdout[-6000:] + r.stderr[-3000:])
    print(f'{len(ok)} ok: ' + ' '.join(ok))
