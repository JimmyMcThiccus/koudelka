import sys,re,json
from pathlib import Path
fn=sys.argv[1]; unit=sys.argv[2]
p=Path('src/battle')/(unit+'.cpp'); t=p.read_text()
lines=t.split('\n')
idx=None
for i,l in enumerate(lines):
    if re.match(r'EXTERN_C .*\b'+fn+r'\(',l): idx=i;break
assert idx is not None
d=0;st=False;end=idx
for j in range(idx,len(lines)):
    for ch in lines[j]:
        if ch=='{': d+=1;st=True
        elif ch=='}': d-=1
    if st and d==0: end=j;break
body='\n'.join(lines[idx:end+1])
Path('scratch_c/saved_'+fn+'.txt').write_text(body)
lines[idx:end+1]=[f'INCLUDE_ASM("asm/battle/nonmatchings/{unit}", {fn});']
p.write_text('\n'.join(lines))
print('reverted',fn,end-idx+1,'lines')
