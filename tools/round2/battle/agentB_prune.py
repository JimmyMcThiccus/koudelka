"""prune: run batch, keep first matching section per func; for non-matching funcs keep only the last attempt
(the others dropped). Usage: agentB_prune.py [func ...]  (only prunes listed funcs if given)"""
import re, subprocess, sys
F='scratch_c/agentB.cpp'
only=sys.argv[1:]
for _try in range(6):
    r=subprocess.run([sys.executable,'scratch_c/battle-batch.py',F]+only,capture_output=True,text=True)
    if 'not found under' not in r.stdout: break
blocks=re.split(r'(?m)^(?=func_[0-9A-F]{8}: )', r.stdout)[1:]
lines=[]
for b in blocks:
    if ' differing' in b.splitlines()[0]: lines.append(b.splitlines()[0])
    elif 'not found under' in b: lines.append('X: missing')
    else: lines.append('X: 8888 differing')
s=open(F).read()
parts=re.split(r'(?m)^(?=//@ )',s)
pre,secs=parts[0],parts[1:]
names=[x.split()[1] for x in secs]
res={}
it=iter(lines)
idx=[i for i,n in enumerate(names) if not only or n in only]
for i,l in zip(idx,lines):
    import re as _r
    m=_r.search(r'(\d+) differing',l); res[i]=int(m.group(1)) if m else 9999
keep=[]
for i,n in enumerate(names):
    if i not in res: keep.append(i); continue
    group=[k for k in idx if names[k]==n]
    if any(res[k]==9999 for k in group): keep.append(i); continue
    best=min(group,key=lambda k:res[k])
    if i==best: keep.append(i)
open(F,'w').write(pre+''.join(secs[i] for i in keep))
print(r.stdout)
