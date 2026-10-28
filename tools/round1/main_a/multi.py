"""Test several functions at once.
File format: shared prelude, then sections starting with a line `//// func_XXXXXXXX`.
Each section is compiled with the prelude and diffed with try_compile.
usage: multi.py file.cpp [-v] [names...]"""
import re, subprocess, sys
from pathlib import Path

path = Path(sys.argv[1])
verbose = '-v' in sys.argv
only = [a for a in sys.argv[2:] if a != '-v']
parts = re.split(r'^//// (func_[0-9A-F]{8})[^\n]*\n', path.read_text(), flags=re.M)
hdr = Path('scratch_c/game_pre.cpp').read_text() if Path('scratch_c/game_pre.cpp').exists() else ''
for h in sorted(Path('include/game/a').glob('*.h')):
    hdr += '\n'.join(l for l in h.read_text().splitlines() if not l.startswith('#')).replace('EXTERN_C', 'extern "C"') + '\n'
post = Path('scratch_c/game_post.cpp')
prelude = hdr + (post.read_text() if post.exists() else '') + parts[0]
ok = []
for name, body in zip(parts[1::2], parts[2::2]):
    if only and name not in only:
        continue
    f = Path('scratch_c/_m_' + name + '.cpp')
    f.write_text(re.sub(r'/\*.*?\*/|// [^\n]*', '', prelude + body, flags=re.S))
    r = subprocess.run([sys.executable, 'tools/try_compile.py', str(f), name, '--quiet'],
                       capture_output=True, text=True)
    last = (r.stdout.strip().splitlines() or ['compile error'])[-1]
    good = ' 0 differing' in last
    ok += [name] if good else []
    print(('OK  ' if good else 'BAD ') + last)
    if not good and verbose:
        print(r.stdout + r.stderr[-2000:])
print(f'{len(ok)} ok: ' + ' '.join(ok))
