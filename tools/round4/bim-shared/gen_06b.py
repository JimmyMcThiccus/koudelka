import re,glob,os
n=0
for f in sorted(glob.glob('src/bim/w*/*.cpp')):
    m=os.path.basename(f)[:-4]
    text=open(f).read()
    def repl(mt):
        global n
        fn=mt.group(1)
        sp=f'asm/bim/{m}/nonmatchings/{m}/{fn}.s'
        t=open(sp).read()
        c=re.findall(r'jal\s+(bimf_af99c5b3(?:_\d+)?)',t)
        assert len(c)==1,(m,fn,c)
        c=c[0]
        n+=1
        return f'''EXTERN_C BimMon *func_800D8464();
EXTERN_C int {c}_c(void *p, int a) asm("{c}");

EXTERN_C int {fn}(BimMon *p, int a)
{{
    BimMon *o = func_800D8464();
    if (o && o != p) {{
        if (rand() & 1) {{
            if (!p->f9E4)
                return 0;
            if (!{c}_c(p, a)) {{
                if (p)
                    return 0;
                else
                    return 0;
            }}
            return 1;
        }}
        return 0;
    }}
    if (p->f9E8 && (rand() & 7) == 7)
        p->f9EC = 1;
    return 0;
}}'''
    new=re.sub(r'INCLUDE_ASM\("[^"]+", (bimf_06b4d1a5(?:_\d+)?)\);',repl,text)
    if new!=text:
        if '"bim/shared.h"' not in new: new=new.replace('#include "common.h"\n','#include "common.h"\n#include "bim/shared.h"\n',1)
        open(f,'w').write(new)
print(n)
