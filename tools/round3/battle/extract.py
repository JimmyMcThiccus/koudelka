import re,sys,glob,os
from pathlib import Path
out=[]
for f in sorted(glob.glob('../drafts/battle/func_*.cpp')):
    n=os.path.basename(f)[:-4]
    t=open(f).read()
    lines=t.split('\n')
    # find start of definition of n
    idx=None
    for i,l in enumerate(lines):
        if re.search(r'\b'+n+r'\s*\(',l) and not l.rstrip().endswith(';') and not l.startswith('//') and not l.startswith('#'):
            idx=i
    if idx is None: print(n,'NO DEF'); continue
    # walk braces
    depth=0;started=False;end=idx
    for j in range(idx,len(lines)):
        for ch in lines[j]:
            if ch=='{': depth+=1;started=True
            elif ch=='}': depth-=1
        if started and depth==0: end=j;break
    body='\n'.join(lines[idx:end+1])
    out.append(f'//@ {n}\n{body}\n')
Path('drafts_all.cpp').write_text('#include "common.h"\n#include "battle/battle.h"\n'+'\n'.join(out))
print(len(out))
