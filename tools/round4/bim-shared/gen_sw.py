import re,glob,os
n=0
for f in sorted(glob.glob('src/bim/w*/*.cpp')):
    m=os.path.basename(f)[:-4]
    text=open(f).read()
    def repl(mt):
        global n
        fn=mt.group(1)
        sp=f'asm/bim/{m}/nonmatchings/{m}/{fn}.s'
        if not os.path.exists(sp): return mt.group(0)
        t=open(sp).read()
        if 'jtbl' not in t or 'jalr' in t: return mt.group(0)
        calls=set(re.findall(r'jal\s+(\w+)',t))
        if calls!={'func_80082670','func_800D8E64'}: return mt.group(0)
        if not re.search(r'nonmatching %s, 0x([0-9A-F]+)'%fn,t): return mt.group(0)
        if len(re.findall(r'addu\s+\$s0, \$a0, \$zero',t))!=1: return mt.group(0)
        tab=re.findall(r'\.word (\.L[0-9A-F]+)',t)
        blocks={};cur=None;order=[]
        for l in t.split('\n'):
            mm=re.match(r'\s*(\.L[0-9A-F]+):',l)
            if mm: cur=mm.group(1); blocks[cur]=[]; order.append(cur); continue
            if cur and '/*' in l: blocks[cur].append(re.sub(r'^\s*/\*.*?\*/\s*','',l).strip())
        out={}
        for i,lab in enumerate(tab):
            consts=[]
            for ins in blocks.get(lab,[]):
                mm=re.match(r'addiu\s+\$a2, \$zero, (0x[0-9A-F]+|\d+)',ins)
                if mm: consts.append(mm.group(1))
                if re.match(r'addu\s+\$a2, \$a1, \$zero',ins): consts.append('A1')
            if len(consts)==2: out.setdefault(lab,[]).append(i+1)
            elif len(consts)!=0: return mt.group(0)
        if not out: return mt.group(0)
        body=''
        for lab in sorted(out,key=lambda l:order.index(l)):
            c=[x for x in blocks[lab] if 1]
            consts=[]
            for ins in blocks[lab]:
                mm=re.match(r'addiu\s+\$a2, \$zero, (0x[0-9A-F]+|\d+)',ins)
                if mm: consts.append(mm.group(1))
                if re.match(r'addu\s+\$a2, \$a1, \$zero',ins): consts.append('A1')
            a,b=consts
            if a=='A1': a='0x10'
            if b=='A1': b='0x11'
            for k in out[lab]: body+=f'    case {k}:\n'
            body+=f'        func_80082670(p + 0x2A4, 0x10, {a});\n        func_80082670(p + 0x2A4, 0x11, {b});\n        break;\n'
        n+=1
        return f'EXTERN_C int {fn}(char *p)\n{{\n    int r = func_800D8E64_a(p);\n    switch (r) {{\n{body}    }}\n    return r;\n}}'
    new=re.sub(r'INCLUDE_ASM\("[^"]+", (func_[0-9A-F]+)\);',repl,text)
    if new!=text:
        if '"bim/shared.h"' not in new: new=new.replace('#include "common.h"\n','#include "common.h"\n#include "bim/shared.h"\n',1)
        open(f,'w').write(new)
print(n,'switch fns')
