import re, sys, collections, hashlib
def norm(path):
    out = []
    for l in open(path).read().splitlines():
        if '/*' not in l: continue
        i = re.sub(r'^\s*/\*.*?\*/\s*', '', l).strip()
        i = re.sub(r'\.L[0-9A-F]+', '.L', i)
        i = re.sub(r'(jal|j)\s+\S+$', r'\1', i)
        i = re.sub(r'%(hi|lo)\([^)]*\)', '%X', i)
        out.append(re.sub(r'\s+', ' ', i))
    # mask the 7818 args
    k = 0
    for n, i in enumerate(out):
        if i.startswith('jal'): break
        if re.match(r'(addiu \$a[123], \$zero, \S+|addu \$a[123], \$\w+, \$\w+)$', i): out[n] = 'ARG'
    return out
paths = [l.split()[0] for l in open(sys.argv[1]) if l.strip()]
G = collections.defaultdict(list)
for p in paths:
    G[tuple(norm(p))].append(p)
for k, (sh, l) in enumerate(sorted(G.items(), key=lambda x: -len(x[1]))):
    print(f'G{k} n={len(l)} len={len(sh)}', ' '.join(x.split('/')[2] + '/' + x.split('/')[-1][:-2] for x in l))
    open(f'scratch_c/G{k}.txt', 'w').write('\n'.join(l))
