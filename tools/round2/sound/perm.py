# usage: perm.py template.cpp func  -- template has lines marked "//P" to permute (all permutations)
import itertools, subprocess, sys
tpl, fn = sys.argv[1], sys.argv[2]
lines = open(tpl).read().splitlines(keepends=True)
idx = [i for i, l in enumerate(lines) if "//P" in l]
best = None
for perm in itertools.permutations([lines[i] for i in idx]):
    out = list(lines)
    for i, l in zip(idx, perm):
        out[i] = l
    open("perm_tmp.cpp", "w").write("".join(out))
    r = subprocess.run(["sh", "./t.sh", "scratch_c/perm_tmp.cpp", fn], capture_output=True, text=True).stdout.strip().splitlines()[-1]
    n = int(r.split(",")[-1].split()[0]) if "differing" in r else 999
    if best is None or n < best[0]:
        best = (n, "".join(out))
        print(n, r)
    if n == 0:
        break
open("perm_best.cpp", "w").write(best[1])
print("best", best[0])
