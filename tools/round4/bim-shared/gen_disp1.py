import re,glob,os,sys
sys.path.insert(0,'scratch_c')
def sig(sp):
    s=open(sp).read();ins=[]
    for l in s.splitlines():
        if '/*' not in l: continue
        i=re.sub(r'^\s*/\*.*?\*/\s*','',l).strip()
        i=re.sub(r'%(hi|lo)\([^)]*\)','%X',i)
        i=re.sub(r'(jal|j)\s+\S+$',lambda mm: mm.group(1),i)
        i=re.sub(r'(b\w+)\s+(.*), \.L[0-9A-F]+$',lambda mm: mm.group(1)+' '+mm.group(2),i)
        i=re.sub(r'\.L[0-9A-F]+','.L',i)
        ins.append(i)
    return tuple(ins)
refmod,reffn='w0_07230563b8','func_800DB3B4'
ref=sig(f'asm/bim/{refmod}/nonmatchings/{refmod}/{reffn}.s')
n=0
for f in sorted(glob.glob('src/bim/w*/*.cpp')):
    m=os.path.basename(f)[:-4]
    text=open(f).read()
    def repl(mt):
        global n
        fn=mt.group(1)
        sp=f'asm/bim/{m}/nonmatchings/{m}/{fn}.s'
        if not os.path.exists(sp) or sig(sp)!=ref: return mt.group(0)
        s=open(sp).read()
        names=re.findall(r'jal\s+(\w+)',s)
        assert len(names)==5,(m,fn,names)
        n+=1
        decl=''.join(f'EXTERN_C int {c}(void *p, unsigned *flags);\n' for c in dict.fromkeys(names))
        return decl+f'''
EXTERN_C int {fn}(BimMon *p, unsigned *flags)
{{
    if ((*flags & 3) == 3) {{
        p->f9F0 = 0;
        return 0;
    }}
    switch (p->f9F0) {{
    case 1:
        if (!{names[0]}(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 2:
        if (!{names[1]}(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 4:
        if (!{names[2]}(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~2;
        return 1;
    case 8:
        if (!{names[3]}(p, flags))
            return 0;
        p->f9F0 = 0;
        *flags &= ~1;
        return 1;
    case 16:
        if (!{names[4]}(p, flags))
            return 0;
        p->f9F0 = 0;
        return 1;
    }}
    return 0;
}}'''
    new=re.sub(r'INCLUDE_ASM\("[^"]+", (func_[0-9A-F]+)\);',repl,text)
    if new!=text:
        if '"bim/shared.h"' not in new: new=new.replace('#include "common.h"\n','#include "common.h"\n#include "bim/shared.h"\n',1)
        open(f,'w').write(new)
print(n,'dispatchers')
