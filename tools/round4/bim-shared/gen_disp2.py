import re,glob,os,sys
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
variant=sys.argv[1]  # 'check3' or 'plain'
refmod,reffn={'check3':('w0_3f7b04fe0f','func_800DB2D0'),'plain':('w0_2966c8e7b8','func_800DB404')}[variant]
ref=sig(f'asm/bim/{refmod}/nonmatchings/{refmod}/{reffn}.s')
pre='''    if ((*flags & 3) == 3) {
        p->f9F0 = 0;
        return 0;
    }
''' if variant=='check3' else ''
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
        decl=''.join('EXTERN_C int %s_c(void *p, unsigned *flags) asm("%s");'%(c,c)+chr(10) for c in dict.fromkeys(names))
        body=''
        for k,(cv,mask) in enumerate([(1,'~2'),(2,'~2'),(4,'~2'),(8,'~1'),(16,None)]):
            body+='    case %d:'%cv+chr(10)+'        if (%s_c(p, flags)) {'%names[k]+chr(10)+'            p->f9F0 = 0;'+chr(10)
            if mask: body+='            *flags &= %s;'%mask+chr(10)
            body+='            return 1;'+chr(10)+'        }'+chr(10)+'        break;'+chr(10)
        return decl+f'''
EXTERN_C int {fn}(BimMon *p, unsigned *flags)
{{
{pre}    switch (p->f9F0) {{
{body}    }}
    if (p->f9F0)
        p->f9F0 = 0;
    return 0;
}}'''
    new=re.sub(r'INCLUDE_ASM\("[^"]+", (func_[0-9A-F]+)\);',repl,text)
    if new!=text:
        if '"bim/shared.h"' not in new: new=new.replace('#include "common.h"\n','#include "common.h"\n#include "bim/shared.h"\n',1)
        open(f,'w').write(new)
print(n,variant)
