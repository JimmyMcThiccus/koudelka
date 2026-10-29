import re,sys
h,m=sys.argv[1],sys.argv[2]
t=open(f'asm/bim/{m}/nonmatchings/{m}/bimf_{h}.s').read().splitlines()
reg={};st={}
for l in t:
    mm=re.search(r'\*/\s+(\w+)\s+(.*)',l)
    if not mm: continue
    op,a=mm.group(1),mm.group(2)
    if op=='lui':
        r,v=a.split(', ',1);mv=re.match(r'\(0x([0-9A-F]+) >> 16\)',v)
        if mv: reg[r]=int(mv.group(1),16)
    elif op=='ori':
        r,r2,v=a.split(', ',2);mv=re.match(r'\(0x([0-9A-F]+) &',v)
        if mv: reg[r]=int(mv.group(1),16)
    elif op=='addiu':
        p=a.split(', ')
        if p[1]=='$zero': reg[p[0]]=int(p[2],0)
    elif op=='sw':
        mo=re.match(r'(\$\w+), (0x[0-9A-F]+)\(\$a0\)',a)
        if mo and mo.group(1) in reg: st[int(mo.group(2),16)]=reg[mo.group(1)]
for o in sorted(st): print(f'    p->w[{(o-0x9FC)//4}] = 0x{st[o]:X};  // +0x{o:X}')
