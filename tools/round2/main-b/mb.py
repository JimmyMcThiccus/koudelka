"""Test several main_b functions at once.
File: shared prelude, then sections starting `//// func_XXXXXXXX`.
usage: mb.py file.cpp [-v] [names...]"""
import re, subprocess, sys
from pathlib import Path
UNITS = ['main_b', 'u_80056E0C', 'u_8005F238', 'u_80062610', 'u_800658E0', 'u_80071A74', 'u_80082174']
def unit_of(name):
    for u in UNITS:
        p = Path(f'src/main/{u}.cpp')
        if f'{u}", {name});' in p.read_text():
            return p
    return None
HDR = '''#include "common.h"
#include "shared/vbase.h"
#include "game/b/field.h"
#include "game/b/globals.h"
#include "game/b/sound.h"
#include "game/b/vcall.h"
#include "game/b/decls_b.h"
'''
if __name__ == '__main__':
    path = Path(sys.argv[1])
    verbose = '-v' in sys.argv
    only = [a for a in sys.argv[2:] if not a.startswith('-')]
    parts = re.split(r'^//// (func_[0-9A-F]{8})[^\n]*\n', path.read_text(), flags=re.M)
    ok = []
    for name, body in zip(parts[1::2], parts[2::2]):
        if only and name not in only:
            continue
        u = unit_of(name)
        if not u:
            print('NOUNIT', name); continue
        f = Path('scratch_c/_m_' + name + '.cpp')
        f.write_text(HDR + parts[0] + body)
        r = subprocess.run([sys.executable, 'tools/try_compile.py', str(f), name, '--unit', u.as_posix()]
                           + ([] if verbose else ['--quiet']), capture_output=True, text=True)
        last = (r.stdout.strip().splitlines() or ['compile error: ' + r.stderr.strip()[-400:]])[-1]
        good = ' 0 differing' in last
        ok += [name] if good else []
        print(('OK  ' if good else 'BAD ') + name + ' ' + last)
        if not good and verbose:
            print(r.stdout[-8000:] + r.stderr[-3000:])
    print(f'{len(ok)} ok: ' + ' '.join(ok))
