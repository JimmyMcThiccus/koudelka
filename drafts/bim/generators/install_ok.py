"""install_ok.py <ok json>... [--desc "text"]: install matched bodies (path -> C body without includes).

bimf_<hash>: if every copy of the hash in asm/bim is in the json with the same body (name normalised), write
src/bim/shared/bimf_<hash>.cpp (bim_sync swaps it in); otherwise define it per module in place of its
INCLUDE_ASM line. func_: per module. Factory declarations are left alone (they don't name these).
"""
import collections, glob, json, os, re, sys

args = sys.argv[1:]
desc = 'selector: 7818 effect, then the f9C8/flag tests and the handler chain.'
if '--desc' in args:
    i = args.index('--desc'); desc = args[i + 1]; del args[i:i + 2]
ok = {}
for f in args:
    ok.update(json.load(open(f)))
byhash = collections.defaultdict(dict)
per = []
for path, body in ok.items():
    path = path.replace('\\', '/')
    mod = path.split('/')[2]
    name = os.path.basename(path)[:-2]
    if not re.search(r'INCLUDE_ASM\("[^"]+", %s\);' % name, open(f'src/bim/{mod}/{mod}.cpp').read()):
        continue
    m = re.match(r'(bimf_[0-9a-f]{8})(_\d+)?$', name)
    if m:
        byhash[m.group(1)][path] = (mod, name, body)
    else:
        per.append((mod, name, body))
nshared = 0
for h, d in byhash.items():
    allp = {p.replace('\\', '/') for p in glob.glob(f'asm/bim/*/nonmatchings/*/{h}.s') + glob.glob(f'asm/bim/*/nonmatchings/*/{h}_*.s')}
    norm = {re.sub(r'\b%s(_\d+)?\(' % h, h + '(', b) for (_, _, b) in d.values()}
    if allp <= set(d) and len(norm) == 1 and not os.path.exists(f'src/bim/shared/{h}.cpp'):
        open(f'src/bim/shared/{h}.cpp', 'w').write(
            f'// Shared by {len(allp)} BIM.AR modules: {desc}\n#include "common.h"\n#include "bim/shared.h"\n\n'
            + norm.pop().strip('\n') + '\n')
        nshared += len(allp)
    else:
        per += list(d.values())
for mod, name, body in per:
    f = f'src/bim/{mod}/{mod}.cpp'
    t = open(f).read()
    pat = re.compile(r'INCLUDE_ASM\("[^"]+", %s\);' % name)
    assert pat.search(t), (mod, name)
    t = pat.sub(lambda _: body.strip('\n'), t, 1)
    if '"bim/shared.h"' not in t:
        t = t.replace('#include "common.h"\n', '#include "common.h"\n#include "bim/shared.h"\n', 1)
    open(f, 'w').write(t)
print(nshared, 'shared copies,', len(per), 'per-module')
