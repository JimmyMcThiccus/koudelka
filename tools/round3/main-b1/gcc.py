# usage: gcc.py file.cpp [cflags] -> prints cc1 output (after CPP), and maspsx output with -m
import sys, subprocess, tempfile, os
from pathlib import Path
sys.path.insert(0, 'tools')
import cc
src = sys.argv[1]; flags = (sys.argv[2] if len(sys.argv) > 2 and not sys.argv[2].startswith('-m') else '-O2 -G8').split()
psyq = Path('bin/psyq4.4')
with tempfile.TemporaryDirectory() as tmp:
    tmp = Path(tmp); env = {**os.environ, 'TMPDIR': str(tmp)}
    subprocess.run([str(psyq / 'CPPPSX.EXE'), *cc.CPP_DEFS, *cc.CPP_LANG['c++'], '-Iinclude', src, str(tmp / 'o.i')], env=env, check=True)
    subprocess.run([str(psyq / 'CC1PLPSX.EXE'), '-quiet', *flags, str(tmp / 'o.i'), '-o', str(tmp / 'o.s')], env=env, check=True)
    s = (tmp / 'o.s').read_text()
    if '-m' in sys.argv:
        s = subprocess.run([sys.executable, 'tools/maspsx_extern.py', '--aspsx-version=2.81', '-G8', '--expand-div'], input=s, capture_output=True, text=True).stdout
    print('\n'.join(l for l in s.splitlines() if not l.startswith('\t.') or l.startswith('\t.extern') or l.startswith('\t.set')))
