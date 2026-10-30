"""addok.py <try.cpp> <func> <module>: verify with try_compile, then record the body (after the includes) in ok_manual.json"""
import sys, json, os, subprocess, re
f, name, mod = sys.argv[1:4]
r = subprocess.run([sys.executable, 'tools/try_compile.py', f, name, '--unit', f'src/bim/{mod}/{mod}.cpp'], capture_output=True, text=True)
last = (r.stdout + r.stderr).strip().splitlines()[-1]
print(last)
if ' 0 differing' not in last: sys.exit(1)
body = open(f).read().split('#include "bim/shared.h"', 1)[1].strip('\n')
body = re.sub(r'__X_c\b', '_t', body); body = re.sub(r'__X\b', '_t', body)
ok = json.load(open('scratch_c/ok_manual.json')) if os.path.exists('scratch_c/ok_manual.json') else {}
ok[f'asm/bim/{mod}/nonmatchings/{mod}/{name}.s'] = body
json.dump(ok, open('scratch_c/ok_manual.json', 'w'), indent=0)
