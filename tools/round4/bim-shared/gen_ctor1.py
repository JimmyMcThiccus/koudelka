import re,glob,os
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
refmod,reffn='w0_336e7778e2','func_800DAB3C'
ref=sig(f'asm/bim/{refmod}/nonmatchings/{refmod}/{reffn}.s')
n=0
for f in sorted(glob.glob('src/bim/w*/*.cpp')):
    m=os.path.basename(f)[:-4]
    text=open(f).read()
    done=[]
    def repl(mt):
        global n
        fn=mt.group(1)
        sp=f'asm/bim/{m}/nonmatchings/{m}/{fn}.s'
        if not os.path.exists(sp) or sig(sp)!=ref: return mt.group(0)
        t=open(sp).read()
        sy=re.findall(r'%hi\((\w+)',t)
        jals=re.findall(r'jal\s+(\w+)',t)
        c=re.search(r'addiu\s+\$a0, \$a0, -(0x[0-9A-F]+)',t).group(1)
        vb=re.search(r'addiu\s+\$v0, \$s0, (0x[0-9A-F]+)',t).group(1)
        assert len(sy)==12 and len(jals)==3,(m,fn,sy,jals)
        b1,b2,_,vt,_,v8c,_,v1e4,_,v49c,v4a8,v980=None,None,None,None,None,None,None,None,None,None,None,None
        # order of %hi: 80010178, 800104A8, vtable, vtable, v8c, 8001262C, v1e4, 80017ADC, v49c, v4a8, v980, v0
        sy=list(sy)
        d0178,d04a8,vt,_,v8c,_,v1e4,_,v49c,v4a8,v980,v0=sy
        ctor,tab,fin=jals
        n+=1
        done.append(fn)
        return f'''EXTERN_C char {d0178}[], {d04a8}[];
EXTERN_C const BimVTable10 {vt};
EXTERN_C char {v980}[], {v4a8}[], {v49c}[], {v1e4}[], {v8c}[], {v0}[];
EXTERN_C void {ctor}(void *self, int a, int b, int c, int d, int e, int f);
EXTERN_C void {tab}(void *self, int a);
EXTERN_C void {fin}(void *self, int a, int b, int c, int d, int e, int f, int g, int h);

EXTERN_C BimDtor *{fn}(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e)
{{
    BimDtor *r;
    if (in_chrg) {{
        BimVBase *vb = self->vb1DC = (BimVBase *)&self->vtAEC;
        vb->vptr = (BimVTable10 *){d0178};
        vb->f4 = 0;
        vb->vptr = (BimVTable10 *){d04a8};
    }}
    {ctor}(self, 0, a, b, c, d, e);
    self->vb1DC->vptr = (BimVTable10 *)&{vt};
    if (!in_chrg) {{
        BimVTable10 vt = {vt};
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = {vt}.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - {vb}));
        vt.e[6].delta = {vt}.e[6].delta + adj;
    }}
    self->vt8C = {v8c};
    self->vt1E0 = D_8001262C;
    self->vt1E4 = {v1e4};
    self->vt3FC = D_80017ADC;
    self->vt49C = {v49c};
    self->vt4A8 = {v4a8};
    self->vt980 = {v980};
    self->vt0 = {v0};
    {tab}(self, b);
    {fin}(self, 1, 0, 0, 0, 0, 0, 0, 0);
    self->f9DC = 0;
    (r = self)->f9D8 = 0;
    return r;
}}'''
    new=re.sub(r'INCLUDE_ASM\("[^"]+", (func_[0-9A-F]+)\);',repl,text)
    for fn in done:
        new=new.replace('EXTERN_C void *%s(void *self, int in_chrg, int a, int b, int c, int d, int e);'%fn,'EXTERN_C BimDtor *%s(BimDtor *self, int in_chrg, int a, short b, int c, int d, int e);'%fn)
        new=new.replace('return %s(operator new('%fn,'return %s((BimDtor *)operator new('%fn) if False else new
    if done:
        new=re.sub(r'return (func_[0-9A-F]+)\(operator new\(',lambda mm: mm.group(0) if mm.group(1) not in done else 'return %s((BimDtor *)operator new('%mm.group(1),new)
    if new!=text:
        if '"bim/shared.h"' not in new: new=new.replace('#include "common.h"\n','#include "common.h"\n#include "bim/shared.h"\n',1)
        open(f,'w').write(new)
print(n,'ctors')
