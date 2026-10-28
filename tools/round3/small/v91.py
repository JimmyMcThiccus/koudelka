import subprocess, sys, itertools
head = '#include "pre.h"\nEXTERN_C unsigned char *func_80091B38(void *t, void *drv, unsigned char *p)\n{\n'
tail = '    return p + 2;\n}\n'
st = ['    FIELD_AT(t, short, 0x64) = a;\n','    FIELD_AT(t, short, 0x60) = b;\n','    FIELD_AT(t, short, 0x66) = b;\n','    FIELD_AT(t, short, 0x62) = q;\n','    FIELD_AT(t, short, 0x5E) = q;\n']
decl = '    short a = p[0];\n    short b = p[1];\n    short q = 0xC0 / a;\n'
best = 99
for perm in itertools.permutations(range(5)):
    open('scratch_c/v91.cpp', 'w').write(head + decl + ''.join(st[i] for i in perm) + tail)
    r = subprocess.run([sys.executable, 'tools/try_compile.py', 'scratch_c/v91.cpp', 'func_80091B38', '--unit', 'src/main/sound.cpp', '-I', 'scratch_c'], capture_output=True, text=True)
    l = (r.stdout.strip().splitlines() or ['err'])[-1]
    n = int(l.split()[-3]) if 'differing' in l else 99
    if n < best: best = n; print(perm, l)
    if n == 0: break
