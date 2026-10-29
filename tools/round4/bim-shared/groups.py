import re,glob,os,collections
g=collections.defaultdict(list)
for f in sorted(glob.glob('src/bim/w*/*.cpp')):
    m=os.path.basename(f)[:-4]
    for fn in re.findall(r'INCLUDE_ASM\("[^"]+", (func_[0-9A-F]+)\);',open(f).read()):
        sp=f'asm/bim/{m}/nonmatchings/{m}/{fn}.s'
        if not os.path.exists(sp): continue
        s=open(sp).read()
        ins=[]
        for l in s.splitlines():
            if '/*' not in l: continue
            i=re.sub(r'^\s*/\*.*?\*/\s*','',l).strip()
            i=re.sub(r'%(hi|lo)\([^)]*\)','%X',i)
            i=re.sub(r'(jal|j|b\w*)\s+\S+$',lambda mm: mm.group(1) if mm.group(1) in('jal','j') else mm.group(0),i)
            i=re.sub(r'\.L[0-9A-F]+','.L',i)
            ins.append(i)
        g[hash(tuple(ins))].append((m,fn,len(ins)))
out=sorted(g.values(),key=lambda v:-len(v))
for v in out[:25]: print(len(v),v[0][2]*4,v[0][0],v[0][1])
print(sum(1 for v in out if len(v)>1), 'groups>1 of', len(out))
print('---')
for v in out[:25]:
    m,fn,_=v[0]
    t=open(f'asm/bim/{m}/nonmatchings/{m}/{fn}.s').read()
    print(len(v), v[0][2]*4, m, fn, 'jtbl' if 'jtbl' in t else '', 'new' if '__builtin_new' in t else '', 'delete' if '__builtin_delete' in t else '', 'jalr' if 'jalr' in t else '')
