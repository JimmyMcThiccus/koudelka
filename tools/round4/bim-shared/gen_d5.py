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
refmod,reffn='w0_e43bb5c67a','func_800DB328'
ref=sig(f'asm/bim/{refmod}/nonmatchings/{refmod}/{reffn}.s')
NJ=3
BODY=open('scratch_c/body_gen_d5.txt').read()
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
        assert len(names)==NJ,(m,fn,names)
        n+=1
        decl=''.join('EXTERN_C int %s_c(void *p, unsigned *flags) asm("%s");'%(c,c)+chr(10) for c in dict.fromkeys(names))
        names=[c+'_c' for c in names]
        body=BODY.replace('FUNCNAME',fn)
        for k,c in enumerate(names): body=body.replace('@N%d@'%k,c)
        return decl+body
    new=re.sub(r'INCLUDE_ASM\("[^"]+", (func_[0-9A-F]+)\);',repl,text)
    if new!=text:
        if '"bim/shared.h"' not in new: new=new.replace('#include "common.h"\n','#include "common.h"\n#include "bim/shared.h"\n',1)
        open(f,'w').write(new)
print(n,'functions')
