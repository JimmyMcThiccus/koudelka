import sys, re, os, collections
sys.path.insert(0, 'scratch_c'); import gen_tbl2
shared = collections.defaultdict(list); permod = []
for path in open('scratch_c/tbl_list.txt').read().split():
    mod = path.split('/')[2]
    name, body, n, base = gen_tbl2.gen(path)
    m = re.match(r'(bimf_[0-9a-f]{8})(_\d+)?$', name)
    if m:
        shared[m.group(1)].append((mod, body.replace(name, m.group(1))))
    else:
        permod.append((mod, name, body))
DESC = ('fill the monster\'s (id, value) table at +0x{b:X} and register it as entry `slot` of '
        'D_800B4D38[0]\'s table at +0xF8.')
for h, lst in sorted(shared.items()):
    bodies = {b for _, b in lst}
    assert len(bodies) == 1, h
    base = int(re.search(r'q \+ (\d+)', lst[0][1]).group(1)) * 4
    if os.path.exists(f'src/bim/shared/{h}.cpp'): print('exists', h); continue
    open(f'src/bim/shared/{h}.cpp', 'w').write(
        f'// Shared by {len(lst)} BIM.AR modules: ' + DESC.format(b=base) + '\n'
        '#include "common.h"\n#include "bim/shared.h"\n\n' + lst[0][1])
for mod, name, body in permod:
    f = f'src/bim/{mod}/{mod}.cpp'
    t = open(f).read()
    pat = re.compile(r'INCLUDE_ASM\("[^"]+", %s\);' % name)
    assert pat.search(t), (mod, name)
    t = pat.sub(lambda _: body.rstrip('\n'), t, 1)
    if '"bim/shared.h"' not in t:
        t = t.replace('#include "common.h"\n', '#include "common.h"\n#include "bim/shared.h"\n', 1)
    open(f, 'w').write(t)
print(len(shared), 'shared hashes,', sum(len(v) for v in shared.values()), 'copies;', len(permod), 'per-module')
