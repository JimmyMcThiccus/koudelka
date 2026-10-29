import re,glob,os
n=0
for f in sorted(glob.glob('src/bim/w*/*.cpp')):
    m=os.path.basename(f)[:-4]
    text=open(f).read()
    def repl(mt):
        global n
        h=mt.group(1)
        sp=f'asm/bim/{m}/nonmatchings/{m}/{h}.s'
        if not os.path.exists(sp): return mt.group(0)
        t=open(sp).read()
        if '__builtin_delete' not in t or 'func_800D76C8' not in t or '0x8C($s0)' not in t or 'nonmatching %s, 0x144'%h not in t: return mt.group(0)
        sy=re.findall(r'%hi\((\w+)',t)
        c=re.search(r'addiu\s+\$a0, \$a0, -(0x[0-9A-F]+)',t).group(1)
        if len(sy)!=10: return mt.group(0)
        v8c,_,v1e4,_,v49c,v4a8,v980,v0,vt,_=sy
        n+=1
        return f'''EXTERN_C const BimVTable10 {vt};
EXTERN_C char {v980}[], {v4a8}[], {v49c}[], {v1e4}[], {v8c}[], {v0}[];

EXTERN_C void {h}(BimDtor *self, int in_chrg)
{{
    self->vt8C = {v8c};
    self->vt1E0 = D_8001262C;
    self->vt1E4 = {v1e4};
    self->vt3FC = D_80017ADC;
    self->vt49C = {v49c};
    self->vt4A8 = {v4a8};
    self->vt980 = {v980};
    self->vt0 = {v0};
    self->vb1DC->vptr = (BimVTable10 *)&{vt};
    if (!in_chrg) {{
        BimVTable10 vt = {vt};
        self->vb1DC->vptr = &vt;
        char *full;
        int adj;
        vt.e[1].delta = {vt}.e[1].delta + (adj = (char *)self - (full = (char *)self->vb1DC - {c}));
        vt.e[6].delta = {vt}.e[6].delta + adj;
    }}
    func_800D76C8(self, 0);
    if (in_chrg & 2)
        func_8001A610(self->vb1DC, 0);
    if (in_chrg & 1)
        operator delete(self);
}}'''
    new=re.sub(r'INCLUDE_ASM\("[^"]+", (func_[0-9A-F]+)\);',repl,text)
    if new!=text:
        if '"bim/shared.h"' not in new: new=new.replace('#include "common.h"\n','#include "common.h"\n#include "bim/shared.h"\n',1)
        open(f,'w').write(new)
print(n,'dtors')
