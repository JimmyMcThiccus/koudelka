import re,glob,collections
use=collections.defaultdict(lambda: {'gp':[], 'lui':[]})
for d in ['nonmatchings','matchings']:
    for f in glob.glob(f'asm/main/{d}/u_8003C510/*.s'):
        n=re.search(r'func_([0-9A-F]+)',f)
        if not n: continue
        a=int(n.group(1),16)
        t=open(f).read()
        for s in set(re.findall(r'%gp_rel\((\w+)\)',t)): use[s]['gp'].append(a)
        for s in set(re.findall(r'%hi\((D_\w+)\)',t)): use[s]['lui'].append(a)
for s,u in sorted(use.items()):
    if u['gp'] and u['lui']:
        print(s,'gp',hex(min(u['gp'])),hex(max(u['gp'])),len(u['gp']),'lui',hex(min(u['lui'])),hex(max(u['lui'])),len(u['lui']))
        print('   gp:',' '.join(f'{x:X}' for x in sorted(u['gp']))); print('   lui:',' '.join(f'{x:X}' for x in sorted(u['lui'])))
