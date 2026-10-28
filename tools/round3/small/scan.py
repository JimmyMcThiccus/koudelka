import re, subprocess, sys, glob
from pathlib import Path
units = {}
for f in glob.glob('src/**/*.cpp', recursive=True):
    for l in open(f):
        m = re.match(r'INCLUDE_ASM\([^,]+,\s*(\w+)\)', l)
        if m: units[m.group(1)] = f
areas = sys.argv[1:] or ['effect','capture','movie','gameend','sound','main_a']
for a in areas:
    for d in sorted(glob.glob(f'drafts/{a}/*.cpp')):
        fn = Path(d).stem
        if fn not in units: continue
        r = subprocess.run([sys.executable, 'tools/try_compile.py', d, fn, '--unit', units[fn], '-I', 'drafts/sound', '-I', 'drafts/' + a, '--quiet'], capture_output=True, text=True)
        l = (r.stdout.strip().splitlines() or [r.stderr.strip().splitlines()[-1] if r.stderr.strip() else 'err'])[-1]
        print(a, fn, l[-60:])
