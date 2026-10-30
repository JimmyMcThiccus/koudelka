"""Missing-return variants of a draft function.

mr_try.py <draft> <func> <unit> : variants
  A  drop the function's final `return X;`
  Bk send the k-th `return 0;` (or `return;`-able constant return) to a label at the end instead
  Ck both: drop final return and send k-th to the end
Prints each variant's try_compile result; writes the best to scratch_c/mr/<func>.cpp.
"""
import os, re, subprocess, sys

draft, fn, unit = sys.argv[1:4]
t = open(draft, errors='ignore').read()
m = re.search(r'^[^\n;/]*\b%s\s*\([^;{]*\)\s*\{' % fn, t, re.M)
if not m:
    sys.exit('no definition')
i = t.index('{', m.start())
d = 0
for j in range(i, len(t)):
    d += t[j] == '{'
    d -= t[j] == '}'
    if d == 0:
        break
head, body, tail = t[:i + 1], t[i + 1:j], t[j:]


def drop_final(b):
    mm = re.search(r'\n(\s*)return [^;]+;\s*$', b)
    return b[:mm.start()] + '\n' if mm else None


rets = [mm for mm in re.finditer(r'return [^;]+;', body)]
variants = []
a = drop_final(body)
if a is not None:
    variants.append(('A', a))
for k, mm in enumerate(rets):
    b = body[:mm.start()] + 'goto mr_end;' + body[mm.end():]
    variants.append((f'B{k}', b + 'mr_end:;\n'))
    fa = drop_final(b)
    if fa is not None:
        variants.append((f'C{k}', fa + 'mr_end:;\n'))
os.makedirs('scratch_c/mr', exist_ok=True)
best = None
for name, b in variants:
    out = f'scratch_c/mr/{fn}_{name}{os.path.splitext(draft)[1]}'
    open(out, 'w').write(head + b + tail)
    r = subprocess.run([sys.executable, 'tools/try_compile.py', out, fn, '--unit', unit], capture_output=True, text=True)
    o = (r.stdout + r.stderr).strip().splitlines()
    last = o[-1] if o else '?'
    mm = re.search(r'(\d+) differing', last)
    n = int(mm.group(1)) if mm else 9999
    print(name, last, flush=True)
    if best is None or n < best[0]:
        best = (n, out)
if best:
    print('BEST', best)
